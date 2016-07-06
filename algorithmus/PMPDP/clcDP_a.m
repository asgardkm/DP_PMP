function [          ...  --- Ausgangsgrößen:
    optPreInxTn3,   ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
    batFrcOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe f�r die Kraftstoffenergie 
    cos2goActMat    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    ] =             ...
    clcDP_a         ...
    (               ... --- Eingangsgr��en:
    disFlg,         ... Skalar - Flag f�r Ausgabe in das Commandwindow
    iceFlgBool,     ...skalar - is engine toggle on/off allowed?
    wayStp,         ... Skalar f�r die Wegschrittweite in m
    batEngStp,      ... Skalar der Batteriediskretisierung in J
    batEngBeg,      ... Skalar f�r die Batterieenergie am Beginn in Ws
    batPwrAux,      ... Skalar f�r die Nebenverbrauchlast in W
    staChgPenCosVal,... Skalar f�r die Strafkosten beim Zustandswechsel
    wayInxBeg,      ... Skalar f�r Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar f�r Endindex in den Eingangsdaten
    engKinNum,      ... Skalar f�r die max. Anz. an engKin-St�tzstellen
    staNum,         ... Skalar f�r die max. Anzahl an Zustandsst�tzstellen
    timeNum,        ... Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen
    engBeg,         ... scalar - beginnnig engine state
    engEnd,         ... scalar - end engine state
    staBeg,         ... Skalar f�r den Startzustand des Antriebsstrangs
    slpVec_wayInx,  ... Vektor der Steigungen in rad
    vehVec,         ...
    fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array       ... struct der Fahrzeugparameter - NUR ARRAYS
    )%#codegen
%
% 01.07.2016 - asgard kaleb marroquin - creating new algorithm based solely 
% on DP for minimizing fuel use based on battery charge value with a given
% speed and slope profile wrt time, not distance. 
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
% Diese Funktion berechnet die optimalen Vorgänger der Dynamischen
% Programmierung (DP). Diese subsitutiert die Zustände Zeit und
% Batterieenergie durch Co-States. Die Kosten werden mit dem
% Pontryaginschen Minimumsprinzip berechnet.
%   This function calculates the optimum predecessor from dynamic
%   programming (DP). Each state's time and battery power costates are
%   substituted from a Potryagin's Minimum Principle calculation.
%
% Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an)
%   variation olyHyb permits only hybrid driving (motor is always on)
%
% Änderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min()
% bestimmt. Das fährt zu einem anderen Schaltverhalten, da Gänge teilweise
% gleiche Kosten verursachen. In dem Fall wird jetzt der niedrigste Gang
% gewählt, wie in der DP.
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
% Mittelwerte, d.h. Flussgrößen wie Kräfte, Leistungen etc., stehen immmer
% am Anfang des Intervalls für das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer.
%   mean values (eg flow variables like forces, services) are always at the
%   beginning of the interval for the next interval. Those vectors/tensors
%   are therefore shorter by a valid entry (index?).
%
%% Initialisieren der persistent Größen
% Diese werden die nur einmal für die Funktion berechnet
%   assigning input structure values to function persistant variables
%   - just once
% persistent geaNum vehMas vehAccMin vehAccMax iceFlg
persistent geaNum iceFlg engNum

if isempty(geaNum)
    
%     geaNum    = zeros(1,1);
%     vehMas    = zeros(1,1);
%     vehAccMin = zeros(1,1);
%     vehAccMax = zeros(1,1);
    
    % number of engine states possible (1 = OFF; 2 = ON);
    engNum = 2;
    % Anzahl der Gänge
    %   number of gears
    geaNum = staNum; % max number of state nodes
    
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

% Tensor 3. Stufe f�r optimalen Vorgängerkoordinaten
%   tensor3 for optimal previous coordinates/idx
% IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION
%   - back to being a tensor - adding engine control dimension
optPreInxTn3 = zeros(engNum, staNum,timeNum);

% Tensor 3. Stufe f�r die Kraftstoffenergie
%   tensor3 for fuel energy
% NOW A MATRIX
fulEngOptTn3 = inf(engNum, staNum,timeNum);
%   set initial fuel energy level to 0
fulEngOptTn3(engBeg, staBeg, wayInxBeg) = 0; 

% Tensor 3. Stufe f�r die Batterienergie
%   tensor3 for battery energy
batFrcOptTn3 = inf(engNum, staNum,timeNum);

%% Berechnung der optimalen Vorgänger
%   calculating the optimal predecessors

% Initialisieren der Matrix f�r die Kosten bis zu den Punkten im letzten
% Wegschritt
%   initialize the matrix for the cost to the points in the last wayidx
% NOW A VECTOR - REMOVED KE DIMENSION
% not anymore - added engine contorl dimension
cos2goPreMat = inf(engNum, staNum);
cos2goActMat = inf(engNum, staNum);

% Erste Initilisierung beim Startindex mit 0 für alle Zustände(concluded)
%   first, initialize the startidx to 0 for all states
cos2goPreMat(engBeg, staBeg) = 0;

% Initialisierung der Matrix der Batterieenergien
%   initialize the battery energy matrix
batEngPreMat = inf(engNum, staNum);

% Erste Initilisierung beim Startindex mit Startladung für den Startzustand
%   first, intialize start index of the starting charge for intial state
batEngPreMat(engBeg, staBeg) = batEngBeg;

% Initialisierung der Matrix der Kraftstoffenergien
%   initialze the fuel energy matrix
fulEngPreMat = inf(engNum, staNum);
% Erste Initilisierung beim Startindex mit 0 für den Startzustand
%   first, intialize the start idx for the intitial states to 0
fulEngPreMat(engBeg, staBeg) = 0;

% define vector for possibilities of engine state on-off values
%   2 = can toggle (two states, on-of)
%   1 = cannot toggle, must stay in current state for idx (most likely off)
engStaVec_wayInx = ones(wayInxEnd, 1)*2;
engStaVec_wayInx(wayInxBeg) = engBeg;
engStaVec_wayInx(wayInxEnd) = engEnd;

% define a vector for containing the values of engine control off-on
engStaMat_staNum_wayInx = zeros(length(staNum), wayInxEnd);
% Schleife �ber alle Wegpunkte
%   looping thorugh length of # of discretized time vector
for wayInx = wayInxBeg+1 : timeStp : wayInxEnd      % TIME IDX LOOP
    
    % mittlere Steigung im betrachteten Intervall 
    %   no longer doing mean, using previous gradiant instead
    slp = slpVec_wayInx(wayInx-1);
    
    %% Berechnung der kinetischen Energien im aktuellen Wegschritt
    % Vorbereitung der FZGallen Schleife (verhindern von zu grossem
    % Datentransfer und unnötigen Berechnungen)
    %   Calculating the KE for current index/waypoint.
    %   Preperation of FZGallel loop (prevent a too large data transfer,
    %   unnecessary computations).   
   
    % Initialisieren der Matrix für die optimalen Batteriekrafter im
    % Intervall
    %   initialize matrix for optimale battery force intervals (discreti.)
    % NOW A VECTOR - REMOVED KE STATE
    batFrcOptMat = inf(engNum, staNum);
        
    % Initialisieren der Matrix f�r die Kosten bis zu den Punkten im
    % aktuellen Wegschritt
    %   initialize cost matrix to points in current path steps (idxs?)
    cos2goActMat = inf(engNum, staNum);
    
    % Initialisieren der Matrix für die Batterieenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for battery energy at points along current wayidx
    batEngActMat = inf(engNum, staNum);
    
    % Initialisieren der Matrix für die Krafstoffenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for fuel energie along current way idxs
    fulEngActMat = inf(engNum, staNum);
    
    % Anzahl der kinetischen Energien im aktuellen und im
    % Vorgängerwegschritt
    %   number of kinetic energies in current and past path_idxs
    engStaNumAct = engStaVec_wayInx(wayInx); % look at this loop's KE
    engStaNumPre = engStaVec_wayInx(wayInx-1); % and the previous idx KE
    
    % define previous and actual engine status (on-off)
    engStaValPre = engStaMat_staNum_wayInx(:, wayInx - 1);
    engStaValAct = engStaMat_staNum_wayInx(:, wayInx); 

%%  go through the possible engine state one-off possibilities
    for engStaActInx = 1:engStaNumAct   % CURRENT ENGINE STATE LOOP
        
        % go through off and on version of engine 
        engStaAct = engStaValAct(engStaActInx);
        
        % Schleife über alle möglichen aktuellen Zustände des Antriesstrangs
        %   Loop over all possible current powertrain states/all the gears
        for staAct = 1:staNum           % ALL GEARS LOOP
            %% Initialsiieren
            %   note-you are preallocating over each powertrain state loop
            
            % Initialisieren der Ausgabegröße der Schleife
            %   preallocate the loop's output size
            %   but this is the hamiltonian cost?
%             cosHamMin = inf;
            
            % Initialisieren der Variable für den optimalen Zustandsindex
            %   initializing variable for optimal state index
            staPreOptInx = 0;
            
            % Initialisieren der Variable für die Koordinaten des optimalen
            % Vorg�ngers
            %   initializing variable for optimal coords/KE for prev. idx
%             engKinPreOptInx = 0;
            
            % initialize variable for optimal previous idx engine control
            engStaPreOptInx = 0;
            
            % Initialisieren der optimalen Kraftstoffenergieänderung zum
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
            %   initialize the optimal battery power (up to boundry limits)
            batEngOpt = inf;
            
            %% Vorgängerzustände beschränken
            %   Restrictions on predecessor operation states
            
            % Festlegen, welche Vorgänger möglich sind:
            % Es sind im Maximum die Anzahl der Gänge +  1 als Vorgänger
            % möglich, denn vom Segeln kann in jeden Gang im elektrischen
            % Fahren und Segeln gewechselt  werden
            %   Determine which predecessors are possible:
            %   There are at maximum 'number of gears'+1 possible for the
            %   predecessors, because from the sail in every Gear in
            %   electric travel and the sails will be changed (???)
            
            % Vorgängerzustände des Antriebsstrangs beschränken
            %   determine gear possibilities - ie u(g) 
            staPreMin = max(1,staAct-1);
            staPreMax = min(geaNum,staAct+1);
            gea = staAct;
            
            %% Schleife über alle kinetischen Energien (Vorgänger)
            %   loop through all the kinetic energies (previous state idxs)
            %
            % new - loop through previous engine control
            for engStaPreInx = 1:engStaNumPre % PREVIOUS gear state loop
                
                % kinetsiche Energie des betrachten(consider) Vorgängerspunkts
                % bestimmen(determine)
                %   determine the kinetic energy of the previous path_idx
                %
                % value of previous idx engine control state
                engKinPre = engStaValPre(engStaPreInx); %#ok<PFBNS>
                
                % Prüfen(check), ob eine erlaubte Beschleunigung vorliegt.
                % Ansonsten zum nächsten Schleifendurchlauf springen
                %   Check whether an allowable acceleration exists.
                %   Otherwise, jump to the next iteration
%                 vehAcc = (engKinAct-engKinPre)/vehMas/wayStp;
%                 if ((vehAcc < vehAccMin) || (vehAcc > vehAccMax))
%                     continue;
%                 end

                % Schleife über allen Zustände (relativer Index)
                %   Loop through all the states (relative index)
                for staPre = staPreMin:staPreMax % CURRENT GEAR CHANGE LOOP
                    
                   
                    %% Batterieenergie beim betrachteten Vorgänger
                    % battery energy when considering last path_idx
                    %   note: batengPreMat has dims #_KE_states x #_gears
                    batEng = batEngPreMat(staPre);  %#ok<PFBNS>
                    
                    % Sollte es keinen gültigen Vorgänger geben, wird zum
                    % nächsten Schleifendurchlauf gesprungen
                    %   if there is no valid previous battery energy, jump
                    %   to the next loop iteration
                    if isinf(batEng)
                        continue; % HOW TO OVERCOME INITIAL INFINITY VALUE?
                    end
                    
                    %% Antriebsstrangzustand und Strafkosten bestimmen   
                    %   determine gear and penalty costs
                    
                    % Kosten für Zustandswechsel setzen
                    %   set costs for state changes
                    if staAct == staPre
                        % Entspricht der Vorgängerzustand dem aktuellen 
                        % Zustand werden keine Kosten gesetzt
                        %   staying in current state? set penalty cost to 0
                        staChgPenCos = 0;                       
                        
                    else
                        % Ansonsten einfache Zustandswechselkosten
                        % berechnen
                        %   otherwise apply a penalty cost to changing gear
                        staChgPenCos = staChgPenCosVal; %<-penCos is input
                    end
                    
                                        
                    %% Berechnung der optimalen Kosten zum aktuellen Punkt
                    %   calculating optimal cost to the current point
                    
                    % externe Funktion ausführen, die minimale Kosten der
                    % Hamiltonfunktion zurückgibt
                    %   run the min-cost Hamiltonian finding function 
                    [cosHam,batFrc,fulFrc] = ...
                        clcPMP_a(gea,...
                        slp,iceFlg,batEng,batPwrAux,...
                        batEngStp,wayStp, vehVel, fzg_scalar_struct, fzg_array);
                    
%                     % minimale Kosten der Hamiltonfunktion zum aktuellen
%                     % Punkt bestimmen
%                     [cosHamMin,optPreInx] ...
%                         = min([cosHam...
%                         + cos2goPreMat(engKinPreInx,staPre)...
%                         + staChgPenCos...
%                         ,cosHamMin]); %#ok<PFBNS>
                    
                    % combine the min hamil. cost w/ previous costs and 
                    %   gear penalty to get current cost
                    cosAct = cosHam...
                        + cos2goPreMat(engKinPreInx,staPre)...
                        + staChgPenCos/wayStp;
                    
                    % Wenn der aktuelle Punkt besser ist, als der in
                    % cosHamMin gespeicherte Wert, werden die Ausgabegrößen
                    % neu beschrieben.
                    %   if current point is better than the cost value
                    %   stored in CosHamMin, then rewrite the output
                    if cosAct < cosHamMin
                        cosHamMin = cosAct;             % new hamil. cost
                        staPreOptInx = staPre;          % new optimal gear idx
                        engKinPreOptInx = engKinPreInx; % new optimal KEidx
                        batFrcOpt = batFrc;             % new optimal battery force
                        % new opt. battery energy = (batt. force *
                        % displacement diff) + previous battery energy valu
                        batEngOpt = batFrc * wayStp + ...
                            batEngPreMat(engKinPreInx,staPre);
                        % new opt. fuel energy = (fuel force * displacement
                        % diff) + previous fuel energy value
                        fulEngOpt = fulFrc * wayStp + ...
                            fulEngPreMat(engKinPreInx,staPre); %#ok<PFBNS>
                    end
                end % end of gear changes loop
            end % end of running through previous engine state ctrl loop
            
            if ~isinf(cosHamMin)
                % optimale Kosten zum aktuellen Punkt speichern
                %   save min hamilton value for current point
                cos2goActMat(engKinActInx,staAct) = cosHamMin;
                
                % optimale Batterieenergie zum aktuellen Punkt speichern
                %   save optimal battery energy for current point
                batEngActMat(engKinActInx,staAct) = batEngOpt;
                
                % optimale Krafstoffenergie zum aktuellen Punkt speichern
                %   save optimal fuel energy for current point
                fulEngActMat(engKinActInx,staAct) = fulEngOpt;

                % optimale Batterieenergie zum aktuellen Punkt
                % Flussgröße gilt im Intervall
                %   populate optimal battery energy flux quantity at point 
                %   that's applicable to current interval
                batFrcOptMat(engKinActInx,staAct) = batFrcOpt;
                
                % optimalen Vorgänger codieren über Funktion sub2ind
                % und speichern im Tensor
                %   opt. predecessor idx encoding w/ sub2ind, store in Tn3
                optPreInxTn3(engKinActInx,staAct,wayInx) = ...
                    sub2ind([engKinNum,staNum],...
                    engKinPreOptInx,staPreOptInx);
            end % end of ~inf(hamiltonian) if-statement
        end % end of looping through all gears
    end % end of looping through all the current engine control states
    
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
    batFrcOptTn3(:,wayInx-1) = batFrcOptMat;
    
    % Ausgabe des aktuellen Schleifendurchlaufs
    %   output for current loop - print to terminal
    if disFlg
        fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
            double(wayInx-wayInxBeg), double(((wayInx-wayInxBeg)))/...
            double(wayInxEnd-wayInxBeg)*100);
    end

end % end of looping through all discretized path indexes

end % END OF FUNCTION
