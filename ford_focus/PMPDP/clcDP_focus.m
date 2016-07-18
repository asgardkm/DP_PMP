function [          ...  --- AusgangsgrÃ¶ÃŸen:
    optPreInxTn3,   ... Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe für die Kraftstoffenergie 
    cos2goActMat    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    ] =             ...
    clcDP_focus     ...
    (               ... --- Eingangsgrößen:
    disFlg,         ... Skalar - Flag für Ausgabe in das Commandwindow
    iceFlgBool,     ... bool - define if engine off-on can be toggled
    timeStp,        ... Skalar für die Wegschrittweite in m
    batEngBeg,      ... Skalar für die Batterieenergie am Beginn in Ws
    batPwrAux,      ... Skalar für die Nebenverbrauchlast in W
    staChgPenCosVal,... Skalar für die Strafkosten beim Zustandswechsel
    wayInxBeg,      ... Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar für Endindex in den Eingangsdaten
    timeNum,        ... Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen
    engBeg,         ... scalar - beginnnig engine state
    engStaVec_wayInx,... scalar - end engine state
    staBeg,         ... Skalar für den Startzustand des Antriebsstrangs
    velVec,         ... velocity vector contiaing input speed profile
    whlTrq,         ... wheel torque demand vector for the speed profile
    batEngEndMin,   ... SOC lower limit
    batEngEndMax,   ... SOC upper limit
    tst_scalar_struct,     ... struct w/ tst data state var params
    fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct       ... struct der Fahrzeugparameter - NUR ARRAYS
    )%#codegen
%
% 01.07.2016 - asgard kaleb marroquin - creating new algorithm based solely 
% on DP for minimizing fuel use based on battery charge value with a given
% speed and slope profile wrt time, not distance. 
%
% 15.07.2016 - including E_bat as a state variable
%
% 06.07.2016 - replacing KE state dimension with engine control
% Since engine control will be treated as a boolean 0-1 value, for indexing
% values with on-off possibilities, a value of 1 is added to the boolean
% value in order to create 'indexable numbers' (ie, 1 and 2 for off and on)
%
% Differences:
%   - Kinetic energy is not a state/costate variable considered. 
%   - The gear variable should be able to be toggled to be used
%   (static,dynamic).
%   - Algorithm here is wrt time, not displacement (Time is not a state
%   here).
%   - B/c KE states (and possibly discrete gear states) are not considered, 
%   DP is much more plausable for this algorithm. PMP will not be used for
%   finding time and battery energy costates. DP will be used to find 
%   optimal battery energy and possibly gear states for optimal path.
% Similarities:
%   - Want to find optimal battery electric energy path for given profile.
%   - Optimal fuel minimization - engine on/off toggle from torque split.
%
% Algorithm:
%   - Must be able to handle any length of time/speed profile.
%   - There is no energy loss penalty for turning engine on/off.
%
%INIDP Calculating optimal predecessors with DP + PMP
% Erstellungsdatum der ersten Version 20.08.2015 - Stephan Uebel
%
% Diese Funktion berechnet die optimalen VorgÃ¤nger der Dynamischen
% Programmierung (DP). Diese subsitutiert die ZustÃ¤nde Zeit und
% Batterieenergie durch Co-States. Die Kosten werden mit dem
% Pontryaginschen Minimumsprinzip berechnet.
%   This function calculates the optimum predecessor from dynamic
%   programming (DP). Each state's time and battery power costates are
%   substituted from a Potryagin's Minimum Principle calculation.
%
% Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an)
%   variation olyHyb permits only hybrid driving (motor is always on)
%
% Ã„nderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min()
% bestimmt. Das fÃ¤hrt zu einem anderen Schaltverhalten, da Gänge teilweise
% gleiche Kosten verursachen. In dem Fall wird jetzt der niedrigste Gang
% gewÃ¤hlt, wie in der DP.
%   change on 23.02.2016 - optimal costs are not directly from the min()
%   index. The move to another switching behaviour is because the
%   transitions FZGtially caused the same costs. The lowester gear is now
%   selected in DP
%
% !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!!
% Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der
% jeweiligen Position des Vektors.
%   !!!! Please note, how vectors/tensors are read (??) !!!!
%   Values that are at the beginning and end of an interval are at their
%   respective indexes along the vector.
%
% Mittelwerte, d.h. FlussgrÃ¶ÃŸen wie KrÃ¤fte, Leistungen etc., stehen immmer
% am Anfang des Intervalls fÃ¼r das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen gÃ¼ltigen Eintrag kÃ¼rzer.
%   mean values (eg flow variables like forces, services) are always at the
%   beginning of the interval for the next interval. Those vectors/tensors
%   are therefore shorter by a valid entry (index?).
%
%% Initialisieren der persistent GrÃ¶ÃŸen
% Diese werden die nur einmal fÃ¼r die Funktion berechnet
%   assigning input structure values to function persistant variables
%   - just once
% persistent geaNum vehMas vehAccMin vehAccMax iceFlg
persistent engNum engStaMin engStaMax geaNum geaStaMin geaStaMax iceFlg batStaMin batStaStp batStaMax

if isempty(geaNum)
    
%     geaNum    = zeros(1,1);
%     vehMas    = zeros(1,1);
%     vehAccMin = zeros(1,1);
%     vehAccMax = zeros(1,1);
    
    % number of engine states possible (0 = OFF; 1 = ON);
    engNum      = tst_scalar_struct.engStaNum;
    engStaMin   = tst_scalar_struct.engStaMin;
    engStaMax   = tst_scalar_struct.engStaMax;
    % Anzahl der GÃ¤nge
    %   number of gears
    geaNum      = tst_scalar_struct.staNum; % max number of state nodes
    geaStaMin   = tst_scalar_struct.geaStaMin;
    geaStaMax   = tst_scalar_struct.geaStaMax;

    % battery states
    batStaMin   = tst_scalar_struct.batEngMin;
    batStaStp   = tst_scalar_struct.batEngStp;
    batStaMax   = tst_scalar_struct.batEngMax;
    % Fahrzeugmasse;
%     vehMas = fzg_scalar_struct.vehMas;
 
    % minmiale und maximale Beschleunigung
    %   min and max accerlations (bounds)
%     vehAccMin = fzg_scalar_struct.vehAccMin;
%     vehAccMax = fzg_scalar_struct.vehAccMax;
    
    % In dieser Version ist der Motor immer an
    % not anymore - iceFlg is whatever is in mainConfig.txt
%     iceFlg = true;
    iceFlg = iceFlgBool;
end

%% Initialisieren der Ausgabe der Funktion
%   initialzing function output

% Tensor 3. Stufe für optimalen VorgÃ¤ngerkoordinaten
%   tensor3 for optimal previous coordinates/idx
% IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION
%   - back to being a tensor - adding engine control dimension
optPreInxTn3 = zeros(engNum, geaNum,timeNum);

% Tensor 3. Stufe für die Kraftstoffenergie
%   tensor3 for fuel energy
% NOW A MATRIX
fulEngOptTn3 = inf(engNum, geaNum,timeNum);
%   set initial fuel energy level to 0
fulEngOptTn3(engBeg+1, staBeg, wayInxBeg) = 0; 

% Tensor 3. Stufe für die Batterienergie
%   tensor3 for battery energy
batFrcOptTn3 = inf(engNum, geaNum,timeNum);

%% Berechnung der optimalen Vorgänger
%   calculating the optimal predecessors

% Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten
% Wegschritt
%   initialize the matrix for the cost to the points in the last wayidx
% NOW A VECTOR - REMOVED KE DIMENSION
% not anymore - added engine contorl dimension
cos2goPreMat = inf(engNum, geaNum);
cos2goActMat = inf(engNum, geaNum);

% Erste Initilisierung beim Startindex mit 0 für alle Zustände (concluded)
%   first, initialize the startidx to 0 for all states
cos2goPreMat(engBeg+1, staBeg) = 0;

% Initialisierung der Matrix der Batterieenergien
%   initialize the battery energy matrix
batEngPreMat = inf(engNum, geaNum);

% Erste Initilisierung beim Startindex mit Startladung für den Startzustand
%   first, intialize start index of the starting charge for intial state
batEngPreMat(engBeg+1, staBeg) = batEngBeg;

% Initialisierung der Matrix der Kraftstoffenergien
%   initialze the fuel energy matrix
fulEngPreMat = inf(engNum, geaNum);
% Erste Initilisierung beim Startindex mit 0 für den Startzustand
%   first, intialize the start idx for the intitial states to 0
fulEngPreMat(engBeg+1, staBeg) = 0;

% define a vector for containing the values of engine control off-on
% engStaMat_geaNum_wayInx = zeros(1, wayInxEnd);

% Schleife über alle Wegpunkte
%   looping thorugh length of # of discretized time vector
for wayInx = wayInxBeg+1 : timeStp : wayInxEnd      % TIME IDX LOOP
% for wayInx = wayInxBeg+1 : timeStp : 5
% for wayInx = wayInxBeg+1 : timeStp : 1159

    % mittlere Steigung im betrachteten Intervall 
    %   no longer doing mean, using previous gradiant instead
%     slp = slpVec_wayInx(wayInx-1);
    
    %% Berechnung der kinetischen Energien im aktuellen Wegschritt
    % Vorbereitung der FZGallen Schleife (verhindern von zu grossem
    % Datentransfer und unnötigen Berechnungen)
    %   Calculating the KE for current index/waypoint.
    %   Preperation of FZGallel loop (prevent a too large data transfer,
    %   unnecessary computations).   
   
    % Initialisieren der Matrix fÃ¼r die optimalen Batteriekrafter im
    % Intervall
    %   initialize matrix for optimale battery force intervals (discreti.)
    % NOW A VECTOR - REMOVED KE STATE
    % - 06.06.2016 - back to matrix, added engine state dimension
    batFrcOptMat = inf(engNum, geaNum);
        
    % Initialisieren der Matrix für die Kosten bis zu den Punkten im
    % aktuellen Wegschritt
    %   initialize cost matrix to points in current path steps (idxs?)
    cos2goActMat = inf(engNum, geaNum);
    
    % Initialisieren der Matrix fÃ¼r die Batterieenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for battery energy at points along current wayidx
    batEngActMat = inf(engNum, geaNum);
    
    % Initialisieren der Matrix fÃ¼r die Krafstoffenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for fuel energie along current way idxs
    fulEngActMat = inf(engNum, geaNum);
    
    
    % possible engine state changes for current and past path_idxs
    engStaNumPre = engStaVec_wayInx(wayInx-1); % and the previous idx KE
%     engStaNumAct = engStaVec_wayInx(wayInx);   % look at this loop's KE

    % define previous and actual engine status - VALUE (on-off)
%     engStaValPre = engStaMat_geaNum_wayInx(wayInx - 1);
%     engStaValAct = engStaMat_geaNum_wayInx(wayInx); % unnecessary bc 0-1

    % create vector storing current and previous velocity info
    vehVelVec = [velVec(wayInx-1) velVec(wayInx)];
    
    % fetch previous time idx wheel torque
    whlTrqPre = whlTrq(wayInx - 1);
    
%%  go through the possible engine state on-off possibilities
%   checking if the engine can be off or on for this index
    for engStaActInx = engStaMin:engStaMax   % CURRENT ENGINE STATE LOOP                
        % go through off and on version of engine 
        engStaAct = engStaActInx;     
        % Schleife über alle möglichen aktuellen Zustände des Antriesstrangs
        %   Loop over all possible current powertrain states/all the gears
        for geaStaAct = geaStaMin:geaStaMax           % ALL GEARS LOOP
            
            for batStaAct = batStaMin:batStaStp:batStaMax
                %% Initialisieren
                %   note-you are preallocating over each  state permutation

                % Initialisieren der Ausgabegröße der Schleife
                %   preallocate the loop's output size
                minFulMin = inf;

                % Initialisieren der Variable für den optimalen Zustandsindex
                %   initializing variable for optimal state index
                geaStaPreOptInx = 0;

                % initialize variable for optimal previous idx engine control
                engStaPreOptInx = 0;
                
                % initialize variable for optimal previous bat level
                batStaPreOptInx = 0;

                % Initialisieren der optimalen KraftstoffenergieÃ¤nderung zum
                % betrachteten Punkt
                %   preallocate the optimum fuel energy change to the point
                %   considered
                fulEngOpt = inf;

                
                % Initialisieren der optimalen Batteriekraft zum
                % betrachteten Punkt
                %   preallocate the optimal battery force to the point under
                %   consideration
                batFrcOpt = inf;

                % Initialisieren der optimalen Batterieenergie zum
                % betrachteten Punkt
                %   initialize the optimal battery energ< (up to boundry limits)
                batEngOpt = inf;

                %% defining previous engine state control w/ iceFlg
                % if the engine state can toggle: one of two options
                if ~iceFlg
                    if engStaNumPre == 1    
                    % only one change possible-default switch to low val ie off
                        engStaPreIdx = engStaMin;
                    else
                     % otherwise, either off or on are options - loop through
                        engStaPreIdx = [engStaMin engStaMax];
                    end
                else       
                % if the motor must always be on - loop only through same state
                    engStaPreIdx = engStaAct;
                end

                %% Vorgängerzustände beschrÃ¤nken
                %   Restrictions on predecessor operation states

                % Festlegen, welche Vorgänger möglich sind:
                % Es sind im Maximum die Anzahl der GÃ¤nge +  1 als VorgÃ¤nger
                % möglich, denn vom Segeln kann in jeden Gang im elektrischen
                % Fahren und Segeln gewechselt  werden
                %   Determine which predecessors are possible:
                %   There are at maximum 'number of gears'+1 possible for the
                %   predecessors, because from the sail in every Gear in
                %   electric travel and the sails will be changed (???)

                % VorgängerzustÃ¤nde des Antriebsstrangs beschrÃ¤nken
                %   determine gear possibilities - ie u(g) 
                geaStaPreMin = max(1,geaStaAct-1);
                geaStaPreMax = min(geaNum,geaStaAct+1);
                gea = geaStaAct;

                
                %% restricting predecessor bat level possibilities
                % change in E cannot exceed bat power levels (P=E'/t')
                batStaPreMin = max(batStaMin, batStaAct + fzg_scalar_struct.batPwrMin);
                batStaPreMax = min(batStaMax, batStaAct + fzg_scalar_struct.batPwrMax);
                
                %% loop through previous engine control
                for engStaPre = engStaPreIdx % PREVIOUS gear state loop
                    % value of previous idx engine control state
                    %   -unnecessary to assign - indexes represent bool values
                    %#ok<PFBNS>
                    % Schleife über allen Zustände (relativer Index)
                    %   Loop through all the gear states (relative index)
                    for geaStaPre = geaStaPreMin:geaStaPreMax % PREVIOUS GEAR CHANGE LOOP
                        % loop through all possible previous battery levels
                        for batStaPre = batStaPreMin : batStaStp : batStaPreMax

                            %% Batterieenergie beim betrachteten Vorgänger
                            % battery energy when considering last path_idx
                            %   note: batengPreMat has dims #_KE_states x #_gears
                            % batEng = batEngPreMat(engStaPre+1, geaStaPre);  %#ok<PFBNS>
                            % calculate E'
                            batStaDlt = batStaAct - batStaPre;
                            
                            % Sollte es keinen gültigen Vorgänger geben, wird zum
                            % nächsten Schleifendurchlauf gesprungen
                            %   if there is no valid previous battery energy, jump
                            %   to the next loop iteration
%                             if isinf(batStaDlt)
%         %                          fprintf('batEng engine %i gear %i: INFINITY\n', engStaPre, geaStaPre);
%                                 continue;
%                             end

                            %% Antriebsstrangzustand und Strafkosten bestimmen   
                            %   determine gear and engine penalty costs

                            % Kosten für Zustandswechsel setzen
                            %   set costs for state changes
                            if geaStaAct == geaStaPre
                                % Entspricht der Vorgängerzustand dem aktuellen 
                                % Zustand werden keine Kosten gesetzt
                                %   staying in current state? set penalty cost to 0
                                geaStaChgPenCos = 0;                       

                            else
                                % Ansonsten einfache Zustandswechselkosten
                                % berechnen
                                %   otherwise apply a penalty cost to changing gear
                                geaStaChgPenCos = staChgPenCosVal; %<-penCos is input
                            end

                            if engStaAct == engStaPre
                                engStaChgPenCos = 0;
                            else 
                                engStaChgPenCos = staChgPenCosVal;
                            end

                            % penalty for changning battery level or no?
                            
                            %% Berechnung der optimalen Kosten zum aktuellen Punkt
                            %   calculating optimal cost to the current point

                            % externe Funktion ausführen, die minimale Kosten der
                            % Hamiltonfunktion zurückgibt
                            %   run the min-cost Hamiltonian finding function 
                            %
                            % ADD ENGINE STATE VARIABLES (ACT AND PRE)!
                            %
                            % do it time interval at a time? will remove vector
                            % aspects
                            % LOOK INTO WHY ONLY USING PREVIOUS IDX FOR FUEL CALC
                            [fulEng, emoTrq, iceTrq, brkTrq] =...
                                optTrqSplit_focus   ...
                                (                   ...
                                engStaPre,          ...  
                                gea,                ...
                                batStaDlt,          ...
                                batStaPre,          ...
                                batPwrAux,          ...
                                timeStp,            ...
                                vehVelVec,          ...
                                whlTrqPre,          ... use prev idx whlTrq
                                fzg_scalar_struct,  ...
                                fzg_array_struct    ...
                                );

        %                     % minimale Kosten der Hamiltonfunktion zum aktuellen
        %                     % Punkt bestimmen
        %                     [cosHamMin,optPreInx] ...
        %                         = min([cosHam...
        %                         + cos2goPreMat(engKinPreInx,geaStaPre)...
        %                         + staChgPenCos...
        %                         ,cosHamMin]); %#ok<PFBNS>

                            % combine the min hamil. cost w/ previous costs and 
                            %   gear penalty to get current cost
                            fulAct = minFul...
                                + cos2goPreMat(engStaPre+1,geaStaPre)...
                                + geaStaChgPenCos/timeStp + engStaChgPenCos/timeStp;

        %                     fprintf('minFul engine %i gear %i: %4.3f\n', engStaPre, geaStaPre, minFul);
        %                     fprintf('fulAct engine %i gear %i: %4.3f\n\n', engStaPre, geaStaPre, fulAct);
        %                     fprintf('minFulMin_old: %4.3f\n', minFulMin);
                            % Wenn der aktuelle Punkt besser ist, als der in
                            % cosHamMin gespeicherte Wert, werden die Ausgabegrüßen
                            % neu beschrieben.
                            %   if current point is better than the cost value
                            %   stored in CosHamMin, then rewrite the output
                            % 
                            %   WHAT IF - WE INCLUDED <= ? WHY NOT? BOTH OPTIONS
                            %   WOULD BE EQUALLY OPTIMAL
                            %   - will implement as of 06.07.2016
                            if fulAct < minFulMin
                                minFulMin = fulAct;             % new hamil. cost
                                geaStaPreOptInx = geaStaPre;    % new opt gear idx
                                engStaPreOptInx = engStaPre;    % new opt eng state
                                batFrcOpt = batFrc;             % new opt bat force
                                % new opt. battery energy = (batt. force *
                                %   time diff) + previous battery energy valu
                                %   - NOTE: batFrc*timeStp calc is the same as the
                                %       batFrc calculation in batFrcClc_a()
                                %   -   why not output that calculation instead?
                                batEngOpt = batFrc * timeStp + ...
                                    batEngPreMat(engStaPre+1,geaStaPre);
                                % new opt. fuel energy = (fuel force * time diff)
                                %   + previous fuel energy value
                                fulEngOpt = fulFrc * timeStp + ...
                                    fulEngPreMat(engStaPre+1,geaStaPre);%#ok<PFBNS>
                            end
                        end
    %                     fprintf('minFulMin_new: %4.3f\n\n', minFulMin);
                    end % end of gear changes loop
                end % end of running through previous engine state ctrl loop

                if ~isinf(minFulMin)
                    % optimale Kosten zum aktuellen Punkt speichern
                    %   save min hamilton value for current point
                    cos2goActMat(engStaActInx+1,geaStaAct) = minFulMin;

                    % optimale Batterieenergie zum aktuellen Punkt speichern
                    %   save optimal battery energy for current point
                    batEngActMat(engStaActInx+1,geaStaAct) = batEngOpt;

                    % optimale Krafstoffenergie zum aktuellen Punkt speichern
                    %   save optimal fuel energy for current point
                    fulEngActMat(engStaActInx+1,geaStaAct) = fulEngOpt;

                    % optimale Batterieenergie zum aktuellen Punkt
                    % Flussgröße gilt im Intervall
                    %   populate optimal battery energy flux quantity at point 
                    %   that's applicable to current interval
                    batFrcOptMat(engStaActInx+1,geaStaAct) = batFrcOpt;

                    % optimalen Vorgänger codieren über Funktion sub2ind
                    % und speichern im Tensor
                    %   opt. predecessor idx encoding w/ sub2ind, store in Tn3
                    optPreInxTn3(engStaActInx+1,geaStaAct,wayInx) = ...
                        sub2ind([engNum,geaNum],...
                        engStaPreOptInx+1,geaStaPreOptInx);
                end % end of ~inf(hamiltonian) if-statement
            end %end of looping through all battery states
        end % end of looping through all gears
%         fprintf('##################################\n');
    end % end of looping through all the current engine control states
%     fprintf('##################################\n\n');

    % Speichern der Batterieenergie für den nächsten Schleifendurchlauf
    %   save battery energy value as previous path_idx val for next loop 
    batEngPreMat = batEngActMat;
    
    % Speichern der Krafstoffenergie für den nächsten Schleifendurchlauf
    %   save fuel energy value as previous path_idx value for the next loop
    fulEngPreMat = fulEngActMat;
    
    % Speichern der Kosten für den nächsten Schleifendurchlauf
    %   save cost as previous path_idx value for the next loop
    cos2goPreMat = cos2goActMat; 
    
    % optimale Kraftstoffenergie zum aktuellen Punkt
    %   optimal fuel energy at current point - save current mat in tensor
    fulEngOptTn3(:,:,wayInx) = fulEngActMat;
    % optimale Batterieenergie zum aktuellen Punkt
    %   optimal battery force at current point - save current mat in tensor
    % Flussgröße gilt im Intervall
    %   flux quantity applied over the interval
    batFrcOptTn3(:,:,wayInx-1) = batFrcOptMat;
    
    % Ausgabe des aktuellen Schleifendurchlaufs
    %   output for current loop - print to terminal
    if disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(wayInx-wayInxBeg), double(((wayInx-wayInxBeg))) /...
                double(wayInxEnd-wayInxBeg)*100);
    end

end % end of looping through all discretized path indexes

end % END OF FUNCTION
