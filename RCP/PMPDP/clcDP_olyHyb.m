function [...           --- Ausgangsgrößen:
    optPreInxTn3_old, ...   Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3_old, ...   Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3_old, ...   Tensor 3. Stufe für die Kraftstoffenergie 
    cos2goActMat_old ...    Matrix der optimalen Kosten der Hamiltonfunktion 
    ] = ...
    clcDP_olyHyb...
    ( ...               --- Eingangsgrößen:
    disFlg, ...         Skalar - Flag für Ausgabe in das Commandwindow
    wayStp,...          Skalar für die Wegschrittweite in m
    batEngStp,...       Skalar der Batteriediskretisierung in J
    batEngBeg,...       Skalar für die Batterieenergie am Beginn in Ws
    batPwrAux,...       Skalar für die Nebenverbrauchlast in W
    psiBatEng,...       Skalar für den Co-State der Batterieenergie
    psiTim,...          Skalar für den Co-State der Zeit
    staChgPenCosVal,... Skalar für die Strafkosten beim Zustandswechsel
    wayInxBeg,...       Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,...       Skalar für Endindex in den Eingangsdaten
    engKinBegInx,...    Skalar für den Index der Anfangsgeschwindigkeit
    engKinNum,...       Skalar für die max. Anz. an engKin-Stützstellen
    staNum,...          Skalar für die max. Anzahl an Zustandsstützstellen
    wayNum,...          Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen
    staBeg,...          Skalar für den Startzustand des Antriebsstrangs
    engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
    slpVec_wayInx,...   Vektor der Steigungen in rad
    engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J
    FZG...              struct der FahrzeugFZGameter
    )%#codegen
%
%INIDP Calculating optimal predecessors with DP + PMP
% Erstellungsdatum der ersten Version 20.08.2015 - Stephan Uebel
% Diese Funktion berechnet die optimalen Vorgänger der Dynamischen
% Programmierung (DP). Diese subsitutiert die Zustände Zeit und
% Batterieenergie durch Co-States. Die Kosten werden mit dem
% Pontryaginschen Minimumsprinzip berechnet.

% Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an)

% Änderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min()
% bestimmt. Das fährt zu einem anderen Schaltverhalten, da Gänge teilweise
% gleiche Kosten verursachen. In dem Fall wird jetzt der niedrigste Gang
% gew�hlt, wie in der DP.

% !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!!
% Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der
% jeweiligen Position des Vektors.
% Mittelwerte, d.h. Flussgr��en wie Kr�fte, Leistungen etc., stehen immmer
% am Anfang des Intervalls für das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen g�ltigen Eintrag kürzer.

%% Initialisieren der persistent Gr��en
% Diese werden die nur einmal für die Funktion berechnet
% assigning input structure values to function persistant variables - just
% once

persistent geaNum vehMas vehAccMin vehAccMax iceFlg

if isempty(geaNum)
    
    % Anzahl der Gänge
    % number of gears
    geaNum = staNum; % max number of state nodes
    
    % Fahrzeugmasse
    vehMas = FZG.vehMas; 
    
    % minmiale und maximale Beschleunigung
    % min and max accerlations (bounds)
    vehAccMin = FZG.vehAccMin;
    vehAccMax = FZG.vehAccMax;
    
    % In dieser Version ist der Motor immer an
    iceFlg = true;
    
end

%% Initialisieren der Ausgabe der Funktion

% Tensor 3. Stufe für optimalen Vorgängerkoordinaten
optPreInxTn3_old = zeros(engKinNum,staNum,wayNum);

% Tensor 3. Stufe für die Kraftstoffenergie
fulEngOptTn3_old = inf(engKinNum,staNum,wayNum);
% set initial fuel energy level to 0
fulEngOptTn3_old(engKinBegInx,staBeg,wayInxBeg) = 0; 

% Tenor 3. Stufe für die Batterienergie
batFrcOptTn3_old = inf(engKinNum,staNum,wayNum);

%% Berechnung der optimalen Vorgänger
% calculating the optimal predecessors

% Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten
% Wegschritt
% initialize the matrix for the cost to the points in the last wayidx
cos2goPreMat_old = inf(engKinNum,staNum);
cos2goActMat_old = inf(engKinNum,staNum);

% Erste Initilisierung beim Startindex mit 0 für alle Zustände(concluded)
% first, initialize the startidx to 0 for all states
cos2goPreMat_old(engKinBegInx,staBeg) = 0;

% Initialisierung der Matrix der Batterieenergien
% initialize the battery energy matrix
batEngPreMat_old = inf(engKinNum,staNum);

% Erste Initilisierung beim Startindex mit Startladung für den Startzustand
% first, intialize the start index of the starting charge for intial state
batEngPreMat_old(engKinBegInx,staBeg) = batEngBeg;

% Initialisierung der Matrix der Kraftstoffenergien
% initialze the fuel energy matrix
fulEngPreMat_old = inf(engKinNum,staNum);
% Erste Initilisierung beim Startindex mit 0 für den Startzustand
% first, intialize the start idx for the intitial states to 0
fulEngPreMat_old(engKinBegInx,staBeg) = 0;

% Schleife über alle Wegpunkte
% looping thorugh length of # of grid discretization/indeces (Weginputs)
for wayInx = wayInxBeg+1:wayInxEnd      % PATH IDX LOOP
    
    % mittlere Steigung im betrachteten Intervall #<- no longer doing mean,
    % using previous gradiant instead
    slp_old = slpVec_wayInx(wayInx-1);
    
    %% Berechnung der kinetischen Energien im aktuellen Wegschritt
    % Vorbereitung der FZGallen Schleife (verhindern von zu grossem
    % Datentransfer und unnötigen Berechnungen)
    % Calculating the KE for current index/waypoint.
    % Preperation of FZGallel loop (prevent a too large data transfer,
    % unnecessary computations)    
   
    % Initialisieren der Matrix für die optimalen Batteriekrafter im
    % Intervall
    % initialize matrix for optimale battery force intervals (discreti.)
    batFrcOptMat_old = inf(engKinNum,staNum);
        
    % Initialisieren der Matrix für die Kosten bis zu den Punkten im
    % aktuellen Wegschritt
    % initialize cost matrix to points in current path steps (idxs?)
    cos2goActMat_old = inf(engKinNum,staNum);
    
    % Initialisieren der Matrix für die Batterieenergie an den Punkten im
    % aktuellen Wegschritt
    % initialize matrix for battery energy at points along current way idxs
    batEngActMat_old = inf(engKinNum,staNum);
    
    % Initialisieren der Matrix für die Krafstoffenergie an den Punkten im
    % aktuellen Wegschritt
    % initialize matrix for fuel energie along current way idxs
    fulEngActMat_old = inf(engKinNum,staNum);
    
    % Anzahl der kinetischen Energien im aktuellen und im
    % Vorgängerwegschritt
    % number of kinetic energies in current and past path_idxs
    engKinNumAct_old = engKinNumVec_wayInx(wayInx); % look at this loop's KE
    engKinNumPre_old = engKinNumVec_wayInx(wayInx-1); % and the previous idx KE
    
    % Vektoren der kinetischen Energien im vorherigen Wegschritt
    % ^^ vector of the KE in the previous idx
    engKinPreVec_engKinInx_old = ...
        engKinMat_engKinInx_wayInx(:,wayInx-1);
    % Vektoren der kinetischen Energien im aktuellen Wegschritt
    % KE vector of the current path_idx
    engKinActVec_engKinInx_old = ...
        engKinMat_engKinInx_wayInx(:,wayInx);
    
    % (FZGfor) Schleife über alle akutellen kinetischen Energien
    % loop through all the current kinetic energies
    for engKinActInx = 1:engKinNumAct_old   % CURRENT KINETIC ENERGY LOOP
        
        % akutelle kinetsiche Energie bestimmen
        % determine the current kinetic energy
        engKinAct_old = engKinActVec_engKinInx_old(engKinActInx);
        
        % Schleife über alle möglichen aktuellen Zustände des Antriesstrangs
        % Loop over all possible current powertrain states -- all the gears
        for staAct_old = 1:staNum           % ALL GEARS LOOP
            %% Initialsiieren
            % note - you are preallocating over each powertrain state loop
            
            % Initialisieren der Ausgabegröße der Schleife
            % preallocate the loop's output size
            % but this is the hamiltonian cost?
            cosHamMin_old = inf;
            
            % Initialisieren der Variable für den optimalen Zustandsindex
            % initializing variable for optimal state index
            staPreOptInx_old = 0;
            
            % Initialisieren der Variable für die Koordinaten des optimalen
            % Vorgängers
            % initializing variable for optimal coords/KE for prev. idx
            engKinPreOptInx_old = 0;
            
            % Initialisieren der optimalen Kraftstoffenergieänderung zum
            % betrachteten Punkt
            % preallocate the optimum fuel energy change to the point
            % considered
            fulEngOpt_old = inf;
            
            % Initialisieren der optimalen Batteriekraft zum
            % betrachteten Punkt
            % preallocate the optimal battery force to the point under
            % consideration
            batFrcOpt_old = inf;
            
            % Initialisieren der optimalen Batterieenergie zum
            % betrachteten Punkt
            % initialize the optimal battery power (up to boundry limits)
            batEngOpt_old = inf;
            
            %% Vorgängerzustände beschränken
            % Restrictions on predecessor operation states
            
            % Festlegen, welche Vorgänger möglich sind:
            % Es sind im Maximum die Anzahl der Gänge +  1 als Vorgänger
            % möglich, denn vom Segeln kann in jeden Gang im elektrischen
            % Fahren und Segeln gewechselt  werden
            %
            % Determine which predecessors are possible:
            % There are at maximum 'number of gears'+1 possible for the
            % predecessors, because from the sail in every Gear in electric
            % travel and the sails will be changed (???)
            
            % Vorgängerzustände des Antriebsstrangs beschränken
            % determine gear possibilities - ie u(g) 
            staPreMin_old = max(1,staAct_old-1);
            staPreMax_old = min(geaNum,staAct_old+1);
            gea_old = staAct_old;
            
            %% Schleife über alle kinetischen Energien (Vorgänger)
            %   loop through all the kinetic energies (previous state idxs)
            for engKinPreInx = 1:engKinNumPre_old % PREVIOUS KE LOOP
                
                % kinetsiche Energie des betrachten(consider) Vorgängerspunkts
                % bestimmen(determine)
                %   determine the kinetic energy of the previous path_idx
                engKinPre_old = engKinPreVec_engKinInx_old(engKinPreInx); %#ok<PFBNS>
                
                % Prüfen(check), ob eine erlaubte Beschleunigung vorliegt.
                % Ansonsten zum nächsten Schleifendurchlauf springen
                %   Check whether an allowable acceleration exists.
                %   Otherwise, jump to the next iteration
                vehAcc_old = (engKinAct_old-engKinPre_old)/vehMas/wayStp;
                if vehAcc_old < vehAccMin || vehAcc_old > vehAccMax
                    continue;
                end

                % Schleife über allen Zustände (relativer Index)
                %   Loop through all the states (relative index)
                for staPre = staPreMin_old:staPreMax_old % CURRENT GEAR CHANGE LOOP
                    
                   
                    %% Batterieenergie beim betrachteten Vorgänger
                    % battery energy when considering last path_idx
                    %   note: batengPreMat has dims #_KE_states x #_gears
                    batEng_old = batEngPreMat_old(engKinPreInx,staPre);  %#ok<PFBNS>
                    
                    % Sollte es keinen gültigen Vorgänger geben, wird zum
                    % nächsten Schleifendurchlauf gesprungen
                    %   if there is no valid previous battery energy, jump
                    %   to the next loop iteration
                    if isinf(batEng_old)
                        continue; % HOW TO OVERCOME INITIAL INFINITY VALUE?
                    end
                    
                    %% Antriebsstrangzustand und Strafkosten bestimmen   
                    % determine gear and penalty costs
                    
                    % Kosten für Zustandswechsel setzen
                    % set costs for state changes
                    if staAct_old == staPre
                        % Entspricht der Vorgängerzustand dem aktuellen 
                        % Zustand werden keine Kosten gesetzt
                        % staying in current state? set penalty cost to 0
                        staChgPenCos_old = 0;                       
                        
                    else
                        % Ansonsten einfache Zustandswechselkosten
                        % berechnen
                        % otherwise apply a penalty cost to changing gear
                        staChgPenCos_old = staChgPenCosVal; %<-penCos is input
                    end
                    
                                        
                    %% Berechnung der optimalen Kosten zum aktuellen Punkt
                    % calculating optimal cost to the current point
                    
                    % externe Funktion ausführen, die minimale Kosten der
                    % Hamiltonfunktion zurückgibt
                    % run the min-cost Hamiltonian finding function 
                    [cosHam_old,batFrc_old,fulFrc_old] = ...
                        clcPMP_olyHyb(engKinPre_old,engKinAct_old,gea_old,...
                        slp_old,iceFlg,batEng_old,psiBatEng,psiTim,batPwrAux,...
                        batEngStp,wayStp,FZG);
                    
%                     % minimale Kosten der Hamiltonfunktion zum aktuellen
%                     % Punkt bestimmen
%                     [cosHamMin,optPreInx] ...
%                         = min([cosHam...
%                         + cos2goPreMat(engKinPreInx,staPre)...
%                         + staChgPenCos...
%                         ,cosHamMin]); %#ok<PFBNS>
                    
                    % combine the min hamil. cost w/ previous costs and 
                    % gear penalty to get current cost
                    cosAct_old = cosHam_old...
                        + cos2goPreMat_old(engKinPreInx,staPre)...
                        + staChgPenCos_old/wayStp;
                    
                    % Wenn der aktuelle Punkt besser ist, als der in
                    % cosHamMin gespeicherte Wert, werden die Ausgabegrößen
                    % neu beschrieben.
                    % if current point is better than the cost value stored
                    % in CosHamMin, then rewrite the output
                    if cosAct_old < cosHamMin_old
                        cosHamMin_old = cosAct_old;             % new hamil. cost
                        staPreOptInx_old = staPre;          % new optimal gear idx
                        engKinPreOptInx_old = engKinPreInx; % new optimal KEidx
                        batFrcOpt_old = batFrc_old;             % new optimal battery force
                        % new opt. battery energy = (batt. force *
                        % displacement diff) + previous battery energy valu
                        batEngOpt_old = batFrc_old * wayStp + ...
                            batEngPreMat_old(engKinPreInx,staPre);
                        % new opt. fuel energy = (fuel force * displacement
                        % diff) + previous fuel energy value
                        fulEngOpt_old = fulFrc_old * wayStp + ...
                            fulEngPreMat_old(engKinPreInx,staPre); %#ok<PFBNS>
                    end
                end % end of gear changes loop
            end % end of running through previous KE states loop
            
            if ~isinf(cosHamMin_old)
                % optimale Kosten zum aktuellen Punkt speichern
                % save min hamilton value for current point
                cos2goActMat_old(engKinActInx,staAct_old) = cosHamMin_old;
                
                % optimale Batterieenergie zum aktuellen Punkt speichern
                % save optimal battery energy for current point
                batEngActMat_old(engKinActInx,staAct_old) = batEngOpt_old;
                
                % optimale Krafstoffenergie zum aktuellen Punkt speichern
                % save optimal fuel energy for current point
                fulEngActMat_old(engKinActInx,staAct_old) = fulEngOpt_old;

                % optimale Batterieenergie zum aktuellen Punkt
                % Flussgröße gilt im Intervall
                % populate optimal battery energy flux quantity at point 
                % that's applicable to current interval
                batFrcOptMat_old(engKinActInx,staAct_old) = batFrcOpt_old;
                
                % optimalen Vorgänger codieren über Funktion sub2ind
                % und speichern im Tensor
                % opt. predecessor idx encoding w/ sub2ind, store in tensor
                optPreInxTn3_old(engKinActInx,staAct_old,wayInx) = ...
                    sub2ind([engKinNum,staNum],...
                    engKinPreOptInx_old,staPreOptInx_old);
            end % end of ~inf(hamiltonian) if-statement
        end % end of looping through all gears
    end % end of looping through all the current kinetic energy states
    
    % Speichern der Batterieenergie für den nächsten Schleifendurchlauf
    % save battery energy value as previous path_idx val for the next loop 
    batEngPreMat_old = batEngActMat_old;
    
    % Speichern der Krafstoffenergie für den nächsten Schleifendurchlauf
    % save fuel energy value as previous path_idx value for the next loop
    fulEngPreMat_old = fulEngActMat_old;
    
    % Speichern der Kosten für den nächsten Schleifendurchlauf
    % save cost as previous path_idx value for the next loop
    cos2goPreMat_old = cos2goActMat_old; 
    
    % optimale Kraftstoffenergie zum aktuellen Punkt
    % optimal fuel energy at current point - save current mat in tensor
    fulEngOptTn3_old(:,:,wayInx) = fulEngActMat_old;
    % optimale Batterieenergie zum aktuellen Punkt
    % optimal battery force at current point - save current mat in tensor
    % Flussgröße gilt im Intervall
    % flux quantity applied over the interval
    batFrcOptTn3_old(:,:,wayInx-1) = batFrcOptMat_old;
    
    % Ausgabe des aktuellen Schleifendurchlaufs
    % output for current loop - print to terminal
    if disFlg
        fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
            double(wayInx-wayInxBeg), double(((wayInx-wayInxBeg)))/...
            double(wayInxEnd-wayInxBeg)*100);
    end

end % end of looping through all discretized path indexes

end % END OF FUNCTION

