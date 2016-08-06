function [          ...  --- AusgangsgrÃ¶ÃŸen:
    optPreInxTn4,   ... Tensor 3. Stufe fï¿½r opt. Vorgï¿½ngerkoordinaten
    batPwrOptTn4,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn4,   ... Tensor 3. Stufe fï¿½r die Kraftstoffenergie 
    cos2goActTn3    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    ] =             ...
    clcDP_focus     ...
    (               ... --- Eingangsgrï¿½ï¿½en:
    disFlg,         ... Skalar - Flag fï¿½r Ausgabe in das Commandwindow
    iceFlgBool,     ... bool - define if engine off-on can be toggled
    brkBool,        ... skalar - allow states requireing braking?
    timStp,         ... Skalar fï¿½r die Wegschrittweite in m
    batEngBeg,      ... Skalar fï¿½r die Batterieenergie am Beginn in Ws
    batPwrAux,      ... Skalar fï¿½r die Nebenverbrauchlast in W
    staChgPenCosVal,... Skalar fï¿½r die Strafkosten beim Zustandswechsel
    timInxBeg,      ... Skalar fï¿½r Anfangsindex in den Eingangsdaten
    timInxEnd,      ... Skalar fï¿½r Endindex in den Eingangsdaten
    timNum,         ... Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen
    engBeg,         ... scalar - beginnnig engine state
    engStaVec_timInx,... scalar - end engine state
    staBeg,         ... Skalar fï¿½r den Startzustand des Antriebsstrangs
    batOcv,         ... battery voltage vector w/ value for each SOC
    velVec,         ... velocity vector contiaing input speed profile
    crsSpdMat,      ... crankshaft speed demand for each gear
    crsTrqMat,      ... crankshaft torque demand for each gear
    emoTrqMinPosMat,... min emoTrq along speed profile for each gear
    emoTrqMaxPosMat,... max emoTrq along speed profile for each gear
    emoPwrMinPosMat,... min emoPwr along speed profile for each gear
    emoPwrMaxPosMat,... max emoPwr along speed profile for each gear
    iceTrqMinPosMat,... min iceTrq along speed profile for each gear
    iceTrqMaxPosMat,... max iceTrq along speed profile for each gear
    batPwrMinIdxTn3,... min indexes/steps that bat can change
    batPwrMaxIdxTn3,... max indexes/steps that bat can change
    batPwrDemIdxTn3,... bat power demand if only EM is running
    tst_scalar_struct,     ... struct w/ tst data state var params
    fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct       ... struct der Fahrzeugparameter - NUR ARRAYS
    )%#codegen
%
% 01.07.2016 - asgard kaleb marroquin - creating new algorithm based solely 
% on DP for minimizing fuel use based on battery charge value with a given
% speed and slope profile wrt tim, not distance. 
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
%   - Algorithm here is wrt tim, not displacement (Time is not a state
%   here).
%   - B/c KE states (and possibly discrete gear states) are not considered, 
%   DP is much more plausable for this algorithm. PMP will not be used for
%   finding tim and battery energy costates. DP will be used to find 
%   optimal battery energy and possibly gear states for optimal path.
% Similarities:
%   - Want to find optimal battery electric energy path for given profile.
%   - Optimal fuel minimization - engine on/off toggle from torque split.
%
% Algorithm:
%   - Must be able to handle any length of tim/speed profile.
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
%   programming (DP). Each state's tim and battery power costates are
%   substituted from a Potryagin's Minimum Principle calculation.
%
% Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an)
%   variation olyHyb permits only hybrid driving (motor is always on)
%
% Ã„nderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min()
% bestimmt. Das fÃ¤hrt zu einem anderen Schaltverhalten, da Gï¿½nge teilweise
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
%% Initialisieren der persistent Größen
% Diese werden die nur einmal für die Funktion berechnet
%   assigning input structure values to function persistant variables
%   - just once
% persistent geaNum vehMas vehAccMin vehAccMax iceFlg
persistent engNum engStaMin engStaMax geaNum geaStaMin geaStaMax iceFlg batStaMin batStaStp batStaMax batNum

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
    % need to add one so that the value 0 is included as well!
    batNum      = (batStaMax - batStaMin)/batStaStp + 1;

    % Fahrzeugmasse
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

% Tensor 3. Stufe fï¿½r optimalen VorgÃ¤ngerkoordinaten
%   tensor3 for optimal previous coordinates/idx
% IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION
%   - back to being a tensor - adding engine control dimension
optPreInxTn4 = zeros(engNum, geaNum, batNum, timNum);

% Tensor 3. Stufe fï¿½r die Kraftstoffenergie
%   tensor3 for fuel energy - now Tn4
fulEngOptTn4 = inf(engNum, geaNum, batNum, timNum);

%   set initial fuel energy level to 0
%   Note: batEngIdxBeg is a scaled down energy value index, NOT a vector
%   index. Keep this in mind later when manipulating batEng index bounds.
batEngInxBeg = batEngBeg/batStaStp;
fulEngOptTn4(engBeg+1, staBeg, batEngInxBeg + 1, timInxBeg) = 0; 

% Tensor 3. Stufe fï¿½r die Batterienergie
%   tensor3 for battery energy - now Tn4
batPwrOptTn4 = inf(engNum, geaNum, batNum, timNum);

%% Berechnung der optimalen Vorgäger
%   calculating the optimal predecessors

% Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten
% Wegschritt
%   initialize the matrix for the cost to the points in the last wayidx
% NOW A VECTOR - REMOVED KE DIMENSION
% not anymore - added engine contorl dimension
cos2goPreTn3 = inf(engNum, geaNum, batNum);
cos2goActTn3 = inf(engNum, geaNum, batNum);

% Erste Initilisierung beim Startindex mit 0 für alle Zustände (concluded)
%   first, initialize the startidx to 0 for all states
cos2goPreTn3(engBeg+1, staBeg, batEngInxBeg + 1) = 0;

% Initialisierung der Matrix der Batterieenergien
%   initialize the battery energy matrix
% batEngPreTn3 = inf(engNum, geaNum, batNum);

% Erste Initilisierung beim Startindex mit Startladung für den Startzustand
%   first, intialize start index of the starting charge for intial state
% batEngPreTn3(engBeg+1, staBeg, batEngIdxBeg) = batEngBeg;

% Initialisierung der Matrix der Kraftstoffenergien
%   initialze the fuel energy matrix
fulEngPreTn3 = inf(engNum, geaNum, batNum);
% Erste Initilisierung beim Startindex mit 0 fï¿½r den Startzustand
%   first, intialize the start idx for the intitial states to 0
fulEngPreTn3(engBeg+1, staBeg, batEngInxBeg + 1) = 0;

% define a vector for containing the values of engine control off-on
% engStaMat_geaNum_timInx = zeros(1, timInxEnd);

% define battery vector to be used for looping
batStaActInxVec = batStaMin/batStaStp : batStaMax/batStaStp;
% Schleife über alle Wegpunkte
%   looping thorugh length of # of discretized tim vector

% % starting battery energy state - SWITCHING TO AN VECTOR INDEX BY ADDNIG 1
% % THIS MEANS WORK WITH VECTOR INDEXES LATER when defining batEng bounds
% batStaPreOptInx = batEngIdxBeg + 1;

% ----- Initialisieren der persistent Größen ------------------------------
%   initialize the persistance variables

% Diese werden die nur einmal fÜr die Funktion berechnet
%   only calculated once for the function

% persistent crsSpdHybMax crsSpdHybMin crsSpdEmoMax
% 
% if isempty(crsSpdHybMax)
%     
% maximale Drehzahl Elektrommotor
%   maximum electric motor rotational speed
crsSpdEmoMax = fzg_array_struct.emoSpdMgd(1,end);

% maximale Drehzahl der Kurbelwelle
%   maximum crankshaft rotational speed
% 12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY
% ARE WE SECTNIG THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE
% EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER?
crsSpdHybMax = min(fzg_array_struct.iceSpdMgd(1,end),crsSpdEmoMax);

% minimale Drehzahl der Kurbelwelle
%   minimum crankshaft rotational speed
crsSpdHybMin = fzg_array_struct.iceSpdMgd(1,1);
    
% end
% -------------------------------------------------------------------------
% assign the starting batEng for controlling future batEngActs
batStaLimBot = batEngInxBeg + 1;
batStaLimTop = batStaLimBot;
% for timInx = timInxBeg+1 : timStp : 200      % TIME IDX LOOP
for timInx = timInxBeg+1 : timStp : timInxEnd      % TIME IDX LOOP
%     
% for timInx = timInxBeg+1 : timStp : 5
% for timInx = timInxBeg+1 : timStp : 1159

    % mittlere Steigung im betrachteten Intervall 
    %   no longer doing mean, using previous gradiant instead
%     slp = slpVec_timInx(timInx-1);
    
    %% Berechnung der kinetischen Energien im aktuellen Wegschritt
    % Vorbereitung der FZGallen Schleife (verhindern von zu grossem
    % Datentransfer und unnï¿½tigen Berechnungen)
    %   Calculating the KE for current index/waypoint.
    %   Preperation of FZGallel loop (prevent a too large data transfer,
    %   unnecessary computations).   
   
    % Initialisieren der Matrix fÃ¼r die optimalen Batteriekrafter im
    % Intervall
    %   initialize matrix for optimale battery force intervals (discreti.)
    % NOW A VECTOR - REMOVED KE STATE
    % - 06.06.2016 - back to matrix, added engine state dimension
    batPwrOptTn3 = inf(engNum, geaNum, batNum);
        
    % Initialisieren der Matrix fï¿½r die Kosten bis zu den Punkten im
    % aktuellen Wegschritt
    %   initialize cost matrix to points in current path steps (idxs?)
    cos2goActTn3 = inf(engNum, geaNum, batNum);
    
    % Initialisieren der Matrix fÃ¼r die Batterieenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for battery energy at points along current wayidx
    batEngActTn3 = inf(engNum, geaNum, batNum);
    
    % Initialisieren der Matrix fÃ¼r die Krafstoffenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for fuel energie along current way idxs
    fulEngActTn3 = inf(engNum, geaNum, batNum);
    
    % possible engine state changes for current and past path_idxs
    engStaNumPre = engStaVec_timInx(timInx-1); % and the previous idx KE
%     engStaNumAct = engStaVec_timInx(timInx);   % look at this loop's KE

    % create vector storing current and previous velocity info
        % check later if you can remove this
    vehVelVec = [velVec(timInx-1) velVec(timInx)];
    
    % save current and previous crankshaft speed vectors for boundary
    % checks when looping through gear states
    crsSpdActVec = crsSpdMat(timInx, :);
    crsSpdPreVec = crsSpdMat(timInx-1, :);

    %% PRE->ACT engBAT CONTROL
    % INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!!
    % battery power max/min boundaries wrt max/min emo power
    % boundaries as a function of crankshaft speed
 
%     batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
%     batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
    batPwrTopIdx_crsSpdApprox    = batStaLimTop - min(min(batPwrMinIdxTn3(timInx-1, :, :)))*timStp;
    batPwrBotIdx_crsSpdApprox    = batStaLimBot - max(max(batPwrMaxIdxTn3(timInx-1, :, :)))*timStp;
    % battery power limits given by max/min battery power
    % discharge (a given model input value)
%     %   ie change in E cannot exceed bat power levels (P=E'/t')
    batPwrTopIdx_batPwrApprox = batStaLimTop - fzg_scalar_struct.batPwrMin*timStp/batStaStp;
    batPwrBotIdx_batPwrApprox = batStaLimBot - fzg_scalar_struct.batPwrMax*timStp/batStaStp;

%     % find the most constraining change in batEng based on
%     % previous limitations
    batStaStpTop_approx = min(batPwrTopIdx_crsSpdApprox, batPwrTopIdx_batPwrApprox);
    batStaStpBot_approx = max(batPwrBotIdx_crsSpdApprox, batPwrBotIdx_batPwrApprox);

    % MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY
    % STATE, NOT FROM SCRATCH!!!
    % make vector of these batEng state steps for a loop
    batStaLimBot = max(batStaMin/batStaStp + 1, batStaStpBot_approx);
    batStaLimTop = min(batStaMax/batStaStp + 1, batStaStpTop_approx);
    
%     batStaLimVec = batStaLimBot : batStaLimTop;
%% ----- CURRENT STATE VARIBALE LOOP --------------------------------------
%  go through the possible engine state on-off possibilities
%   checking if the engine can be off or on for this index
    for engStaAct = engStaMin:engStaMax     % CURRENT ENGINE STATE LOOP                
        
        % Schleife über alle moglichen aktuellen Zustände des Antriesstrangs
        %   Loop over all possible current powertrain states/all the gears
        for geaStaAct = geaStaMin:geaStaMax % ALL GEARS LOOP
            
            % ----- CRANKSHAFT SPEED BOUNDARY CHECKS ---------------------------------
            % boundaries: since crsSpd is dependent on gear, check is performed
            % within the gear state loop
            % IF ENGINE IS ON:
            if engStaAct
                % Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen
                % Modus
                %   stop if the crankshaft rotational speed is too high in hybrid mode
                if (crsSpdActVec(geaStaAct) > crsSpdHybMax); continue;
                end

                % Falls die Drehzahl des Verbrennungsmotors niedriger als die
                % Leerlaufdrehzahl ist,
                %   stop if crankhaft rotional speed is lower than the idling speed
                if (crsSpdActVec(geaStaAct) < crsSpdHybMin); continue;
                end
                
            % IF ENGINE IS OFF
            else
                % Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
                %   check if electric motor speed limit is maintained
                if (crsSpdActVec(geaStaAct) > crsSpdEmoMax); continue;
                end
                
            end
            % -------------------------------------------------------------------------
 
            % loop over all possible current battery values
            % 05.05.2016 - instead of brute forcing all the current battery
            % states, will try to limit boundaries based on possible
            % predecessor battery levels instead
%             for batStaActInx_counter = 1 : length(batStaLimVec)
            for batStaActInx = 1 : length(batStaActInxVec)
                %% Initialisieren
                %   note-you are preallocating over each state permutation

                % convert batStaActInx back into actual batEng
                batStaAct = batStaActInxVec(batStaActInx) * batStaStp;
%                 batStaActInx = batStaLimVec(batStaActInx_counter);
%                 batStaAct   = batStaActInx * batStaStp;
                
                % memoization variable for storing möglich fuel values
%                 fulActTn3 = inf(length(batStaPreIdxVec), length(geaStaPreMin:geaStaPreMax), engNum);
                fulActTn3 = inf(engNum, geaNum, batNum);
                
                % Initialisieren der Ausgabegröße der Schleife
%                 %   preallocate the loop's output size
%                 minFul = inf;
% % 
% %                 % Initialisieren der Variable für den optimalen Zustandsindex
% %                 %   initializing variable for optimal state index
%                 geaStaPreOptInx = 0;
% % 
% %                 % initialize variable for optimal previous idx engine control
%                 engStaPreOptInx = 0;
% %                 
% %                 % initialize variable for optimal previous bat level
% %                 batStaPreInx = 0;
% %                 % Initialisieren der optimalen Kraftstoffenergieänderung zum
% %                 % betrachteten Punkt
% %                 %   preallocate the optimum fuel energy change to the point
% %                 %   considered
%                 fulEngOpt = inf;
% %                 
% %                 % Initialisieren der optimalen Batterieenergie zum
% %                 % betrachteten Punkt
% %                 %   initialize the optimal battery energy (up to boundry limits)
%                 batEngOpt = inf;
%                 
                
                % initialize optimal torques
%                 emoTrqOpt = inf;
%                 iceTrqOpt = inf;
%                 brkTrqOpt = inf;
%
% ----- DEFINING PREDECESSOR STATE VARIABLE LIMITATIONS ------------------
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

                %% Vorgï¿½ngerzustï¿½nde beschrÃ¤nken
                %   Restrictions on predecessor operation states

                % Festlegen, welche Vorgänger möglich sind:
                % Es sind im Maximum die Anzahl der Gänge +  1 als VorgÃ¤nger
                % möglich, denn vom Segeln kann in jeden Gang im elektrischen
                % Fahren und Segeln gewechselt  werden
                %   Determine which predecessors are possible:
                %   There are at maximum 'number of gears'+1 possible for the
                %   predecessors, because from the sail in every Gear in
                %   electric travel and the sails will be changed (???)

                % Vorgï¿½ngerzustï¿½nde des Antriebsstrangs beschrÃ¤nken
                %   determine gear possibilities - ie u(g) 
                geaStaPreMin = max(1,geaStaAct-1);
                geaStaPreMax = min(geaNum,geaStaAct+1);
                
                geaStaPreIdxVec = geaStaPreMin : geaStaPreMax;
                
                %% restricting predecessor bat level possibilities
                % NOTE: WORKING WITH INDEXES HERE, NOT ENERGY VALUES
                %
                % BUT:
                % do we want to work with the direct scaled down energy
                % value indexes, or with the actual vector position
                % indexes?
                % If working with the direct scaled indexes, we will be
                % getting zeros which makes referencing values later from 
                % vectors impossible.
                %   -b/c an energy value of 0 will yield a scaled down
                %   value of 0 (-> 0/batEngStp = 0). 
                % This does not allow for referencing values later from
                % other vectors (like battery OCV).
                %
                % Solution: just add one to the scaled down battery value
                % index? Using batStaActInx may also work, but not sure if
                % there would be unintended consequences.
                %
                % INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!!
                % battery power max/min boundaries wrt max/min emo power
                % boundaries as a function of crankshaft speed
                
                batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
                batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
                % battery power limits given by max/min battery power
                % discharge (a given model input value)
                %   ie change in E cannot exceed bat power levels (P=E'/t')
                batPwrMinIdx_batPwrLim = batStaActInx + fzg_scalar_struct.batPwrMin*timStp/batStaStp;
                batPwrMaxIdx_batPwrLim = batStaActInx + fzg_scalar_struct.batPwrMax*timStp/batStaStp;
                
                % find the most constraining change in batEng based on
                % previous limitations
                batStaStpPreMin = max(batPwrMinIdx_batPwrLim, batPwrMinIdx_crsSpd);
                batStaStpPreMax = min(batPwrMaxIdx_batPwrLim, batPwrMaxIdx_crsSpd);
                
                % MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY
                % STATE, NOT FROM SCRATCH!!!
                % make vector of these batEng state steps for a loop
                batStaLimMin = max(batStaMin/batStaStp + 1, batStaStpPreMin);
                batStaLimMax = min(batStaMax/batStaStp + 1, batStaStpPreMax);
                
                % if the min limit exceeds the max limit, then set them
                % equal.
                if batStaLimMin > batStaLimMax
                    batStaLimMin = batStaLimMax;
                end
                
                % make alocal min and max for saving for a future total
                % min-max vector
                % Min-max - bounds for the current batEngPre
                % Bot-top - local bounds for current batEngAct
                if batStaLimMin < batStaLimBot
                    batStaLimBot = batStaLimMin;
                end
                if batStaLimMax > batStaLimTop;
                    batStaLimTop = batStaLimMax;
                end               
                batStaPreIdxVec = batStaLimMin : batStaLimMax;
% -------------------------------------------------------------------------
                
%% ----- PREDECESSOR STATE VARIBALE LOOP ----------------------------------
                % PREVIOUS gear state loop
                for engStaPre_counter = 1:length(engStaPreIdx) 
                    engStaPre = engStaPreIdx(engStaPre_counter);
                    % engine state penalty
                    if engStaAct == engStaPre
                        engStaChgPenCos = 0;
                    else 
                        engStaChgPenCos = staChgPenCosVal;
                    end
                    % penalty for changning battery level or no?
                        
                    % Schleife über allen Zustände (relativer Index)
                    %   Loop through all the gear states (relative index)
                    for geaStaPre_counter = 1 : length(geaStaPreIdxVec) % PREVIOUS GEAR CHANGE LOOP
                        geaStaPre = geaStaPreIdxVec(geaStaPre_counter);
                        % Kosten für Zustandswechsel setzen
                        %   set costs for gear state changes
                        if geaStaAct == geaStaPre
                            % Entspricht der Vorgï¿½ngerzustand dem aktuellen 
                            % Zustand werden keine Kosten gesetzt
                            %   staying in current state? set penalty cost to 0
                            geaStaChgPenCos = 0;                       
                        else
                            % Ansonsten einfache Zustandswechselkosten
                            % berechnen
                            %   otherwise apply a penalty cost to changing gear
                            geaStaChgPenCos = staChgPenCosVal; %<-penCos is input
                        end
                            
                        %% check if engStaPre == 0.
                        % if == 0 - ignore bat state loop bc emoTrq==crsTrq
                        %   b/c anything else is not optimal (w/ brakes)
                        % if == 1 - then run through bat state loop
                        
                        % pull out appropriate crankshaft speed and torque
                        crsSpdPre = crsSpdMat(timInx-1, geaStaPre);
                        crsTrqPre = crsTrqMat(timInx-1, geaStaPre);
                        % all EM torque boundaries for given gear
                        emoTrqMinPos = emoTrqMinPosMat(timInx-1, geaStaPre);
                        emoTrqMaxPos = emoTrqMaxPosMat(timInx-1, geaStaPre);
                        
%                       % emoTrqMaxPosMat(:, geaStaPre);
                        emoPwrMinPos = emoPwrMinPosMat(timInx-1, geaStaPre);
                        emoPwrMaxPos = emoPwrMaxPosMat(timInx-1, geaStaPre);
                        
                        % IF ENGINE WAS ON
                        if engStaPre
                            % all ICE torque boundaries for given gear
                            iceTrqMinPos = iceTrqMinPosMat(timInx-1, geaStaPre);
                            iceTrqMaxPos = iceTrqMaxPosMat(timInx-1, geaStaPre);
                            
                            % ----- CRANKSHAFT SPEED BOUNDARY CHECKS ------
                            % boundaries: since crsSpd is dependent on gear, 
                            % check is performed within the gear state loop
                            % IF ENGINE IS ON:
                            % Abbruch, wenn die Drehzahlen der Kurbelwelle 
                            % zu hoch im hybridischen
                            % Modus
                            %   stop if the crankshaft rotational speed is 
                            %   too high in hybrid mode
                            if (crsSpdPreVec(geaStaPre) > crsSpdHybMax); continue;
                            end

                            % Falls die Drehzahl des Verbrennungsmotors niedriger als die
                            % Leerlaufdrehzahl ist,
                            %   stop if crankhaft rotional speed is lower than the idling speed
                            if (crsSpdPreVec(geaStaPre) < crsSpdHybMin); continue;
                            end
            
                            for batStaPreIdx_counter = 1 : length(batStaPreIdxVec)                            
                                % value of previous idx engine control state
                                %  - unnecessary to assign - indexes represent bool values
                                   % loop through all possible previous battery levels
                                % calculate index for bat state - can move
                                % outside for loop for improving computation tim later
                                
                                % because batSTaPreIdx is coming from an index vector from
                                % the loop batStaPreIdx_counter, and because
                                % we need batStaPreIdx to be used for
                                % referencing vector indexes later on, the
                                % variable batStaPreIdx will be used as an
                                % index vector, and not as a scaled energy
                                % level value index vector.
                                % therefore, we subtract 1 from the index
                                % when transforming batStaPreIdx into its
                                % rescaled form batStaPre.
                                batStaPreIdx = batStaPreIdxVec(batStaPreIdx_counter);
                                batStaPre    = (batStaPreIdx-1) * batStaStp;
                                
                                % calculate E'
                                batPwr = batStaAct - batStaPre;

                                % calculate battery resistance
                                % the code below is performing this code snippet across the vector
                                % if batPwr < 0
                                %     batRst = fzg_scalar_struct.batRstDch;
                                % else
                                %     batRst = fzg_scalar_struct.batRstChr;
                                % end
                                batRst = (batPwr < 0) * fzg_scalar_struct.batRstDch ...
                                      + (batPwr >= 0) * fzg_scalar_struct.batRstChr;
                                    
                                % lookup previous bat state's voltage value
                                batOcvPre = batOcv(batStaPreIdx);
                                
                                %% Berechnung der optimalen Kosten zum aktuellen Punkt
                                %   calculating optimal cost to the current point

                                % do it tim interval at a tim? will remove vector
                                % aspects
    %                             [minFul, emoTrq, iceTrq, brkTrq] =...
                                minFul =...
                                    optTrqSplit_focus   ...
                                    (                   ...
                                    brkBool,            ...
                                    batPwr,             ...
                                    batOcvPre,          ...
                                    batRst,             ...
                                    crsSpdPre,          ...
                                    crsTrqPre,          ...
                                    emoTrqMinPos,       ...
                                    emoTrqMaxPos,       ...
                                    emoPwrMinPos,       ...
                                    emoPwrMaxPos,       ...
                                    iceTrqMaxPos,       ...
                                    iceTrqMinPos,       ...
                                    timStp,             ...
                                    vehVelVec,          ...
                                    fzg_scalar_struct,  ...
                                    fzg_array_struct    ...
                                    );

                                % combine the min hamil. cost w/ previous costs and 
                                %   gear penalty to get current cost
                                fulActTn3(engStaPre+1, geaStaPre,batStaPreIdx) ...
                                    = minFul...
                                    + cos2goPreTn3(engStaPre+1,geaStaPre, batStaPreIdx)...
                                    + geaStaChgPenCos/timStp  ...
                                    + engStaChgPenCos/timStp;

                            end % end of bat energy changing loop
                                
                        else
                            % ---- electric motor MUST satisfy crsTrq -----
                            % IF ENGINE IS OFF
                            % Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
                            %   check if electric motor speed limit is maintained
                            if (crsSpdPreVec(geaStaPre) > crsSpdEmoMax); continue;
                            end
                            
                            % determine previous state if engine waas off
                            % based on batPwrDemIdxTn3 (a preprocessed tn3
                            % containing amnt battery pwr needed to satisfy
                            % a crankshaft power demand for all state
                            % permutations)
                            batStaPreIdx_noEmo = batStaActInx + ... - 1
                                                 batPwrDemIdxTn3(timInx, batStaActInx, geaStaAct);
                                             
                            % check your bounds 
                            if (batStaPreIdx_noEmo < batStaMin/batStaStp + 1) || ...
                                (batStaPreIdx_noEmo > batStaMax/batStaStp + 1)
                                continue;
                            end
                            
                            % penalty to get current cost
                            fulActTn3(engStaPre+1, geaStaPre, batStaPreIdx_noEmo) ...
                                = ... minFul ...
                                + cos2goPreTn3(engStaPre+1, geaStaPre, batStaPreIdx_noEmo) ...
                                + geaStaChgPenCos / timStp ...
                                + engStaChgPenCos / timStp;
                        end % end of engStaPre condition check
                        
                    end % end of gear changes loop
                end % end of running through previous engine state ctrl loop

                
                % pull out the minimum value from fulActMat
                [colmin, colminidx] = min(fulActTn3);
                [matmin, matminidx] = min(colmin);
%                 [minFulMin, engStaPreOptInx] = min(matmin);
%                 geaStaPreOptInx = matminidx(engStaPreOptInx);
%                 batStaPreInx    = colminidx(:,geaStaPreOptInx,engStaPreOptInx);
%                 batStaPreOptInx = batStaPreIdxVec(batStaPreInx);
                [minFulMin, batStaPreOptInx] = min(matmin);
                geaStaPreOptInx = matminidx(batStaPreOptInx);
                engStaPreOptInx    = colminidx(:,geaStaPreOptInx,batStaPreOptInx);
%                 engStaPreOptInx = batStaPreIdxVec(engStaPreInx);
                
                if ~isinf(minFulMin)
                    % new opt. battery energy = (batt. force *
                    %   tim diff) + previous battery energy valu
                    %   - NOTE: batFrc*timStp calc is the same as the
                    %       batFrc calculation in batFrcClc_a()
                    %   -   why not output that calculation instead?
                    batEngOpt = (batStaPreOptInx-1) * batStaStp; % + ...
%                         batEngPreTn3(engStaPreOptInx,geaStaPreOptInx,batStaPreOptInx);
                    
                    % new opt. fuel energy = (fuel force * tim diff)
                    %   + previous fuel energy value
                    fulEngOpt = minFulMin + ...
                    fulEngPreTn3(engStaPreOptInx,geaStaPreOptInx,batStaPreOptInx);%%#ok<PFBNS>
                
                    % optimale Kosten zum aktuellen Punkt speichern
                    %   save min hamilton value for current point
                    cos2goActTn3(engStaAct+1,geaStaAct,batStaActInx) = minFulMin;
            
                    % optimale Batterieenergie zum aktuellen Punkt speichern
                    %   save optimal battery energy for current point
                    batEngActTn3(engStaAct+1,geaStaAct,batStaActInx) = batEngOpt;

                    % optimale Krafstoffenergie zum aktuellen Punkt speichern
                    %   save optimal fuel energy for current point
                    fulEngActTn3(engStaAct+1,geaStaAct,batStaActInx) = fulEngOpt;

                    % optimale Batterieenergie zum aktuellen Punkt
                    % Flussgrï¿½ï¿½e gilt im Intervall
                    %   populate optimal battery energy flux quantity at point 
                    %   that's applicable to current interval
                    batPwrOptTn3(engStaAct+1,geaStaAct,batStaActInx) = batStaActInx - batStaPreOptInx;
                    
                    % optimalen Vorgï¿½nger codieren ï¿½ber Funktion sub2ind
                    % und speichern im Tensor
                    %   opt. predecessor idx encoding w/ sub2ind, store in Tn3
                    optPreInxTn4(engStaAct+1,geaStaAct,batStaActInx,timInx) = ...
                        sub2ind([engNum,geaNum, batNum],...
                        engStaPreOptInx,geaStaPreOptInx, batStaPreOptInx);
                end % end of ~inf(hamiltonian) if-statement
            end %end of looping through all battery states
            
            fprintf('.');
        end % end of looping through all gears
    end % end of looping through all the current engine control states
    fprintf('\n');
    
    % define new batengPreInxVec for next time's batEngAct preliminary
    % approximation
%     batEngPreInxVec = batStaLimBot : batStaLimTop;
    
%     fprintf('##################################\n\n');
    
%     % find bounds for approximating next time index's batEng bounds
%     batStaIdxBounds = find(~isinf(min(min(cos2goActTn3))));
%     if length(batStaIdxBounds) < 1
%        fprintf('WARNING: batSTaIdxBounds gone at time %i\n', timInx); 
%     end
%     batStaLimBot = min(batStaIdxBounds);
%     batStaLimTop = max(batStaIdxBounds);
%                 
    % Speichern der Kosten fï¿½r den nï¿½chsten Schleifendurchlauf
    %   save cost as previous path_idx value for the next loop
    cos2goPreTn3 = cos2goActTn3; 
    

    % Speichern der Batterieenergie fï¿½r den nï¿½chsten Schleifendurchlauf
    %   save battery energy value as previous path_idx val for next loop 
%     batEngPreTn3 = batEngActTn3;
    
    % Speichern der Krafstoffenergie fï¿½r den nï¿½chsten Schleifendurchlauf
    %   save fuel energy value as previous path_idx value for the next loop
    fulEngPreTn3 = fulEngActTn3;

    % optimale Kraftstoffenergie zum aktuellen Punkt
    %   optimal fuel energy at current point - save current mat in tensor
    fulEngOptTn4(:,:,:,timInx) = fulEngActTn3;
    % optimale Batterieenergie zum aktuellen Punkt
    %   optimal battery force at current point - save current mat in tensor
    % Flussgrï¿½ï¿½e gilt im Intervall
    %   flux quantity applied over the interval
    batPwrOptTn4(:,:,:,timInx-1) = batPwrOptTn3;
    
    % Ausgabe des aktuellen Schleifendurchlaufs
    %   output for current loop - print to terminal
    if disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(timInx-timInxBeg), double(((timInx-timInxBeg))) /...
                double(timInxEnd-timInxBeg)*100);
    end

end % end of looping through all discretized path indexes

end % END OF FUNCTION
