function [              ...  --- Ausgangsgrößen:
    optPreInxTn4,       ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn4,       ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn4,       ... Tensor 3. Stufe f�r die Kraftstoffenergie
    emoTrqOpt1Tn4,       ... tensor - saves optimal emoTrq values
    emoTrqOpt2Tn4,      ...
    iceTrqOptTn4,       ... tensor - saves optimal iceTrq values
    brkTrqOptTn4,       ... tensor - saves optimal brkTrq values
    cos2goActTn3        ... Matrix der optimalen Kosten der Hamiltonfunktion 
] =                     ...
    clcDP_focus_emoPwrElectricOnly         ...
(                       ... --- Eingangsgr��en:
    batEngBeg,          ... Skalar f�r die Batterieenergie am Beginn in Ws
    timNum,             ... Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen
    engStaVec_timInx,   ... scalar - end engine state
    batOcv,             ... battery voltage vector w/ value for each SOC
    velVec,             ... velocity vector contiaing input speed profile
    crsSpdMat,          ... crankshaft speed demand for each gear
    crsTrqMat,          ... crankshaft torque demand for each gear
    emoTrqMinPosMat,    ... min emoTrq along speed profile for each gear
    emoTrqMaxPosMat,    ... max emoTrq along speed profile for each gear
    emoPwrMinPosMat,    ... min emoPwr along speed profile for each gear
    emoPwrMaxPosMat,    ... max emoPwr along speed profile for each gear
    iceTrqMinPosMat,    ... min iceTrq along speed profile for each gear
    iceTrqMaxPosMat,    ... max iceTrq along speed profile for each gear
    batPwrMinIdxTn3,    ... min indexes/steps that bat can change
    batPwrMaxIdxTn3,    ... max indexes/steps that bat can change
    batPwrDemIdxTn3,    ... bat power demand if only EM is running
    inputparams,       ...
    tst_scalar_struct, ... struct w/ tst data state var params
    fzg_scalar_struct, ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct   ... struct der Fahrzeugparameter - NUR ARRAYS
)%#codegen
%
% 12.08.2016 - note: this version does not interpolate the emoPwrElectric
% into a mechanical torque - which seems to be yielding better results for
% some reason.
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
% Diese Funktion berechnet die optimalen Vorgänger der Dynamischen
% Programmierung (DP). Diese subsitutiert die Zustände Zeit und
% Batterieenergie durch Co-States. Die Kosten werden mit dem
% Pontryaginschen Minimumsprinzip berechnet.
%   This function calculates the optimum predecessor from dynamic
%   programming (DP). Each state's tim and battery power costates are
%   substituted from a Potryagin's Minimum Principle calculation.
%
% Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an)
%   variation olyHyb permits only hybrid driving (motor is always on)
%
% Änderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min()
% bestimmt. Das fährt zu einem anderen Schaltverhalten, da G�nge teilweise
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
% Mittelwerte, d.h. Flussgr��en wie Kräfte, Leistungen etc., stehen immmer
% am Anfang des Intervalls für das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer.
%   mean values (eg flow variables like forces, services) are always at the
%   beginning of the interval for the next interval. Those vectors/tensors
%   are therefore shorter by a valid entry (index?).
%
%% Initialisieren der persistent Gr��en
% Diese werden die nur einmal f�r die Funktion berechnet
%   assigning input structure values to function persistant variables
%   - just once
% persistent geaNum vehMas vehAccMin vehAccMax iceFlg
persistent engNum engStaMin engStaMax geaNum geaStaMin geaStaMax iceFlg ...
            batStaMin batStaStp batStaMax batNum crsSpdHybMax crsSpdHybMin

if isempty(geaNum)
    
%     geaNum    = zeros(1,1);
%     vehMas    = zeros(1,1);
%     vehAccMin = zeros(1,1);
%     vehAccMax = zeros(1,1);
    
    % number of engine states possible (0 = OFF; 1 = ON);
    engNum      = tst_scalar_struct.engStaNum;
    engStaMin   = tst_scalar_struct.engStaMin;
    engStaMax   = tst_scalar_struct.engStaMax;
    % Anzahl der Gänge
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

    % In dieser Version ist der Motor immer an
    % not anymore - iceFlg is whatever is in mainConfig.txt
%     iceFlg = true;
    iceFlg = inputparams.iceFlgBool;
     
end
% maximale Drehzahl Elektrommotor
%   maximum electric motor rotational speed
crsSpdEmoMax = fzg_array_struct.emoSpdMgd(1,end);
tic
% maximale Drehzahl der Kurbelwelle
%   maximum crankshaft rotational speed
% 12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY
% ARE WE SELECTING THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE
% EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER?
crsSpdHybMax = min(fzg_array_struct.iceSpdMgd(1,end), crsSpdEmoMax);

% minimale Drehzahl der Kurbelwelle
%   minimum crankshaft rotational speed
crsSpdHybMin = fzg_array_struct.iceSpdMgd(1,1);
%% Initialisieren der Ausgabe der Funktion
%   initialzing function output

% Tensor 3. Stufe f�r optimalen Vorgängerkoordinaten
%   tensor3 for optimal previous coordinates/idx
% IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION
%   - back to being a tensor - adding engine control dimension
optPreInxTn4 = zeros(engNum, geaNum, batNum, timNum);

% Tensor 3. Stufe f�r die Kraftstoffenergie
%   tensor3 for fuel energy - now Tn4
fulEngOptTn4 = inf(engNum, geaNum, batNum, timNum);

% tensors for saving optimal torque values
emoTrqOpt1Tn4  = inf(engNum, geaNum, batNum, timNum);
emoTrqOpt2Tn4  = inf(engNum, geaNum, batNum, timNum);
iceTrqOptTn4  = inf(engNum, geaNum, batNum, timNum);
brkTrqOptTn4  = inf(engNum, geaNum, batNum, timNum);

%   set initial fuel energy level to 0
%   Note: batEngIdxBeg is a scaled down energy value index, NOT a vector
%   index. Keep this in mind later when manipulating batEng index bounds.
batEngInxBeg = batEngBeg/batStaStp;
fulEngOptTn4(inputparams.engBeg+1, inputparams.staBeg, batEngInxBeg + 1, inputparams.timInxBeg) = 0; 

% Tensor 3. Stufe f�r die Batterienergie
%   tensor3 for battery energy - now Tn4
batPwrOptTn4 = inf(engNum, geaNum, batNum, timNum);

%% Berechnung der optimalen Vorg�ger
%   calculating the optimal predecessors

% Initialisieren der Matrix f�r die Kosten bis zu den Punkten im letzten
% Wegschritt
%   initialize the matrix for the cost to the points in the last wayidx
% NOW A VECTOR - REMOVED KE DIMENSION
% not anymore - added engine contorl dimension
cos2goPreTn3 = inf(engNum, geaNum, batNum);
cos2goActTn3 = inf(engNum, geaNum, batNum);

% Erste Initilisierung beim Startindex mit 0 f�r alle Zust�nde (concluded)
%   first, initialize the startidx to 0 for all states
cos2goPreTn3(inputparams.engBeg+1, inputparams.staBeg, batEngInxBeg + 1) = 0;

% Initialisierung der Matrix der Batterieenergien
%   initialize the battery energy matrix
% batEngPreTn3 = inf(engNum, geaNum, batNum);

% Erste Initilisierung beim Startindex mit Startladung f�r den Startzustand
%   first, intialize start index of the starting charge for intial state
% batEngPreTn3(engBeg+1, staBeg, batEngIdxBeg) = batEngBeg;

% Initialisierung der Matrix der Kraftstoffenergien
%   initialze the fuel energy matrix
fulEngPreTn3 = inf(engNum, geaNum, batNum);
% Erste Initilisierung beim Startindex mit 0 f�r den Startzustand
%   first, intialize the start idx for the intitial states to 0
fulEngPreTn3(inputparams.engBeg+1, inputparams.staBeg, batEngInxBeg + 1) = 0;

% define a vector for containing the values of engine control off-on
% engStaMat_geaNum_timInx = zeros(1, timInxEnd);

% define battery vector to be used for looping
batStaActInxVec = batStaMin/batStaStp : batStaMax/batStaStp;

% assign the starting batEng for controlling future batEngActs
batStaLimBot = batEngInxBeg + 1;
batStaLimTop = batStaLimBot;

% Schleife �ber alle Wegpunkte
%   looping thorugh length of # of discretized tim vector

for timInx = inputparams.timInxBeg+1 : inputparams.timStp : inputparams.timInxEnd      % TIME IDX LOOP
    %% Berechnung der kinetischen Energien im aktuellen Wegschritt
    % Vorbereitung der FZGallen Schleife (verhindern von zu grossem
    % Datentransfer und unn�tigen Berechnungen)
    %   Calculating the KE for current index/waypoint.
    %   Preperation of FZGallel loop (prevent a too large data transfer,
    %   unnecessary computations).   
   
    % Initialisieren der Matrix für die optimalen Batteriekrafter im
    % Intervall
    %   initialize matrix for optimale battery force intervals (discreti.)
    % NOW A VECTOR - REMOVED KE STATE
    % - 06.06.2016 - back to matrix, added engine state dimension
    batPwrOptTn3 = inf(engNum, geaNum, batNum);
        
    % Initialisieren der Matrix f�r die Kosten bis zu den Punkten im
    % aktuellen Wegschritt
    %   initialize cost matrix to points in current path steps (idxs?)
    cos2goActTn3 = inf(engNum, geaNum, batNum);
    
    % Initialisieren der Matrix für die Batterieenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for battery energy at points along current wayidx
    batEngActTn3 = inf(engNum, geaNum, batNum);
    
    % Initialisieren der Matrix für die Krafstoffenergie an den Punkten im
    % aktuellen Wegschritt
    %   initialize matrix for fuel energie along current way idxs
    fulEngActTn3 = inf(engNum, geaNum, batNum);
    
    % intiialiying matrices for saving torques for each state permutation
    % for the given time interval
    emoTrqAct1Tn3 = zeros(engNum, geaNum, batNum);
    emoTrqAct2Tn3 = zeros(engNum, geaNum, batNum);
    iceTrqActTn3 = zeros(engNum, geaNum, batNum);
    brkTrqActTn3 = zeros(engNum, geaNum, batNum);
    
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

    %% PRE->ACT engBat CONTROL
    % INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!!
    % battery power max/min boundaries wrt max/min emo power
    % boundaries as a function of crankshaft speed
 
%     batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
%     batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp;
    batPwrTopIdx_crsSpdApprox    = batStaLimTop - min(min(batPwrMinIdxTn3(timInx-1, :, :)))*inputparams.timStp;
    batPwrBotIdx_crsSpdApprox    = batStaLimBot - max(max(batPwrMaxIdxTn3(timInx-1, :, :)))*inputparams.timStp;
    % battery power limits given by max/min battery power
    % discharge (a given model input value)
%     %   ie change in E cannot exceed bat power levels (P=E'/t')
    batPwrTopIdx_batPwrApprox = batStaLimTop - fzg_scalar_struct.batPwrMin*inputparams.timStp/batStaStp;
    batPwrBotIdx_batPwrApprox = batStaLimBot - fzg_scalar_struct.batPwrMax*inputparams.timStp/batStaStp;

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
        
        % Schleife �ber alle moglichen aktuellen Zust�nde des Antriesstrangs
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
                % Pr�fen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
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
                
                % memoization variable for storing m�glich fuel values
%                 fulActTn3 = inf(length(batStaPreIdxVec), length(geaStaPreMin:geaStaPreMax), engNum);
                fulActTn3 = inf(engNum, geaNum, batNum);
                % memoiztaion variables for output torques
                emoTrqPre1Tn3 = zeros(engNum, geaNum, batNum);
                emoTrqPre2Tn3 = zeros(engNum, geaNum, batNum);
                iceTrqPreTn3 = zeros(engNum, geaNum, batNum);
                brkTrqPreTn3 = zeros(engNum, geaNum, batNum);
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

                %% Vorg�ngerzust�nde beschr�nken
                %   Restrictions on predecessor operation states

                % Festlegen, welche Vorg�nger m�glich sind:
                % Es sind im Maximum die Anzahl der G�nge +  1 als Vorgänger
                % m�glich, denn vom Segeln kann in jeden Gang im elektrischen
                % Fahren und Segeln gewechselt werden
                %   Determine which predecessors are possible:
                %   There are at maximum 'number of gears'+1 possible for the
                %   predecessors, because from the sail in every Gear in
                %   electric travel and the sails will be changed (???)

                % Vorg�ngerzust�nde des Antriebsstrangs beschränken
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
                batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*inputparams.timStp;
                batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*inputparams.timStp;
                % battery power limits given by max/min battery power
                % discharge (a given model input value)
                %   ie change in E cannot exceed bat power levels (P=E'/t')
                batPwrMinIdx_batPwrLim = batStaActInx + fzg_scalar_struct.batPwrMin*inputparams.timStp/batStaStp;
                batPwrMaxIdx_batPwrLim = batStaActInx + fzg_scalar_struct.batPwrMax*inputparams.timStp/batStaStp;
                
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
                        engStaChgPenCos = inputparams.staChgPenCosVal;
                    end
                    % penalty for changning battery level or no?
                        
                    % Schleife �ber allen Zust�nde (relativer Index)
                    %   Loop through all the gear states (relative index)
                    for geaStaPre_counter = 1 : length(geaStaPreIdxVec) % PREVIOUS GEAR CHANGE LOOP
                        geaStaPre = geaStaPreIdxVec(geaStaPre_counter);
                        % Kosten f�r Zustandswechsel setzen
                        %   set costs for gear state changes
                        if geaStaAct == geaStaPre
                            % Entspricht der Vorg�ngerzustand dem aktuellen 
                            % Zustand werden keine Kosten gesetzt
                            %   staying in current state? set penalty cost to 0
                            geaStaChgPenCos = 0;                       
                        else
                            % Ansonsten einfache Zustandswechselkosten
                            % berechnen
                            %   otherwise apply a penalty cost to changing gear
                            geaStaChgPenCos = inputparams.staChgPenCosVal; %<-penCos is input
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
                                
                                % because batStaPreIdx is coming from an index vector from
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
                                [minFul, emoTrq, iceTrq, brkTrq] =...
                                    optTrqSplit_focus_emoPwrElectricOnly   ...
                                    (                   ...
                                    inputparams.brkBool,...
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
                                    crsSpdHybMax,       ... % maximum crankshaft rotational speed
                                    crsSpdHybMin,       ... % minimum crankshaft rotational speed
                                    inputparams.timStp, ...
                                    inputparams.batPwrAux,...
                                    vehVelVec,          ...
                                    fzg_scalar_struct,  ...
                                    fzg_array_struct    ...
                                    );

                                % combine the min hamil. cost w/ previous costs and 
                                %   gear penalty to get current cost
                                fulActTn3(engStaPre+1, geaStaPre,batStaPreIdx) ...
                                    = minFul...
                                    + cos2goPreTn3(engStaPre+1,geaStaPre, batStaPreIdx)...
                                    + geaStaChgPenCos/inputparams.timStp  ...
                                    + engStaChgPenCos/inputparams.timStp;
                                
                                emoTrqPre1Tn3(engStaPre+1, geaStaPre,batStaPreIdx) = emoTrq;
                                emoTrqPre2Tn3(engStaPre+1, geaStaPre,batStaPreIdx) = emoTrq;
                                iceTrqPreTn3(engStaPre+1, geaStaPre,batStaPreIdx) = iceTrq;
                                brkTrqPreTn3(engStaPre+1, geaStaPre,batStaPreIdx) = brkTrq;

                            end % end of bat energy changing loop
                                
                        else
                            % ---- electric motor MUST satisfy crsTrq -----
                            % IF ENGINE IS OFF
                            % Pr�fen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
                            %   check if electric motor speed limit is maintained
                            if (crsSpdPreVec(geaStaPre) > crsSpdEmoMax); continue;
                            end
                            
                            % determine previous state if engine waas off
                            % based on batPwrDemIdxTn3 (a preprocessed tn3
                            % containing amnt battery pwr needed to satisfy
                            % a crankshaft power demand for all state
                            % permutations)
                            batStaPreIdx_noEmo = batStaActInx + ... - 1
                                                 batPwrDemIdxTn3(timInx, batStaActInx, geaStaPre);

                            % check your bounds 
                            if (batStaPreIdx_noEmo < batStaMin/batStaStp + 1) || ...
                                (batStaPreIdx_noEmo > batStaMax/batStaStp + 1)
                                continue;
                            end
                            
                            batPwrPre = -((batStaActInxVec(batStaActInx) -      ...
                                        batStaActInxVec(batStaPreIdx_noEmo)) *  ...
                                        batStaStp / inputparams.timStp);
                                    
                            if abs(crsSpdPre) > fzg_scalar_struct.vehVelThresh *100
                                batTrqPre1 = batPwrPre / crsSpdPre;
                            else
                                batTrqPre1 = 0;
                            end

                            emoTrqPre2 = codegen_interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoPwrMgd', ...
                                fzg_array_struct.emoTrq_emoSpd_emoPwr, crsSpdPre, batPwrPre);
                            
                            if abs(crsSpdPre) < (fzg_scalar_struct.vehVelThresh *100)
                                emoTrqPre2 = 0;
                            elseif isinf(emoTrqPre2)
                                continue;
                            elseif emoTrqPre2 > emoTrqMaxPos || emoTrqPre2 < emoTrqMinPos
                                continue;
                            end
                            % penalty to get current cost
                            fulActTn3(engStaPre+1, geaStaPre, batStaPreIdx_noEmo)           ...
                                = ... minFul ...
                                + cos2goPreTn3(engStaPre+1, geaStaPre, batStaPreIdx_noEmo)  ...
                                + geaStaChgPenCos / inputparams.timStp                      ...
                                + engStaChgPenCos / inputparams.timStp;

%                             emoTrqPreTn3(engStaPre+1, geaStaPre,batStaPreIdx_noEmo) = emoTrqPre;
                            emoTrqPre1Tn3(engStaPre+1, geaStaPre,batStaPreIdx_noEmo) = batTrqPre1;
                            emoTrqPre2Tn3(engStaPre+1, geaStaPre,batStaPreIdx_noEmo) = emoTrqPre2;

                            % brake torque in case of torque overshoot
                            if inputparams.brkBool

                                if emoTrqPre2 > crsTrqPre
                                    brkTrqPreTn3(engStaPre+1, geaStaPre, batStaPreIdx_noEmo) = ...
                                        emoTrqPre2 - crsTrqPre;
                                end
                            end
                            
                        end % end of engStaPre condition check
                        
                    end % end of gear changes loop
                end % end of running through previous engine state ctrl loop

                
                % pull out the minimum value from fulActMat
                [colmin, colminidx] = min(fulActTn3);
                [matmin, matminidx] = min(colmin);
                [minFulMin, batStaPreOptInx] = min(matmin);
                geaStaPreOptInx     = matminidx(batStaPreOptInx);
                engStaPreOptInx     = colminidx(:, geaStaPreOptInx, batStaPreOptInx);
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
                    % Flussgr��e gilt im Intervall
                    %   populate optimal battery energy flux quantity at point 
                    %   that's applicable to current interval
                    batPwrOptTn3(engStaAct+1,geaStaAct,batStaActInx) = batStaActInx - batStaPreOptInx;
                    
                    % save optimal torque values for the given state
                    % emoTrq
                    emoTrqAct1Tn3(engStaAct+1,geaStaAct,batStaActInx) = ...
                        emoTrqPre1Tn3(engStaPreOptInx, geaStaPreOptInx, batStaPreOptInx);
                    
                     emoTrqAct2Tn3(engStaAct+1,geaStaAct,batStaActInx) = ...
                        emoTrqPre2Tn3(engStaPreOptInx, geaStaPreOptInx, batStaPreOptInx);
                     
                    % iceTrq
                    iceTrqActTn3(engStaAct+1,geaStaAct,batStaActInx) = ...
                        iceTrqPreTn3(engStaPreOptInx, geaStaPreOptInx, batStaPreOptInx);
                    % brkTrq
                    brkTrqActTn3(engStaAct+1,geaStaAct,batStaActInx) = ...
                        brkTrqPreTn3(engStaPreOptInx, geaStaPreOptInx, batStaPreOptInx);
                    
                    % optimalen Vorg�nger codieren �ber Funktion sub2ind
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
    
    % define new batEngPreInxVec for next time's batEngAct preliminary
    % approximation
%     batEngPreInxVec = batStaLimBot : batStaLimTop;

%     % find bounds for approximating next time index's batEng bounds
%     batStaIdxBounds = find(~isinf(min(min(cos2goActTn3))));
%     if length(batStaIdxBounds) < 1
%        fprintf('WARNING: batStaIdxBounds gone at time %i\n', timInx); 
%     end
%     batStaLimBot = min(batStaIdxBounds);
%     batStaLimTop = max(batStaIdxBounds);
%                 
    % Speichern der Kosten f�r den n�chsten Schleifendurchlauf
    %   save cost as previous path_idx value for the next loop
    cos2goPreTn3 = cos2goActTn3; 
    
    % Speichern der Krafstoffenergie f�r den n�chsten Schleifendurchlauf
    %   save fuel energy value as previous path_idx value for the next loop
    fulEngPreTn3 = fulEngActTn3;

    % optimale Kraftstoffenergie zum aktuellen Punkt
    %   optimal fuel energy at current point - save current mat in tensor
    fulEngOptTn4(:,:,:,timInx) = fulEngActTn3;
    % optimale Batterieenergie zum aktuellen Punkt
    %   optimal battery force at current point - save current mat in tensor
    % Flussgr��e gilt im Intervall
    %   flux quantity applied over the interval
    batPwrOptTn4(:,:,:,timInx-1) = batPwrOptTn3;
    
    
    % save optimal torque tensors for each time interval
    % emoTrq
    emoTrqOpt1Tn4(:,:,:,timInx) = emoTrqAct1Tn3;
    emoTrqOpt2Tn4(:,:,:,timInx) = emoTrqAct2Tn3;
    % iceTrq
    iceTrqOptTn4(:,:,:,timInx) = iceTrqActTn3;
    % brkTrq
    brkTrqOptTn4(:,:,:,timInx) = brkTrqActTn3;
    % Ausgabe des aktuellen Schleifendurchlaufs
    %   output for current loop - print to terminal
    if inputparams.disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(timInx-inputparams.timInxBeg), double(((timInx-inputparams.timInxBeg))) /...
                double(inputparams.timInxEnd-inputparams.timInxBeg)*100);
    end

end % end of looping through all discretized path indexes
toc
end % END OF FUNCTION
