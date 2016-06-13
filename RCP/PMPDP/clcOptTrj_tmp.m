function [...
    engKinOptVec,...  Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec, ...    Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,...     Vektor - optimale Kraftstoffenergieänderung
    staVec,...              Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,...     Vektor - costate für kinetische Energie
    fulEngOpt, ...          Skalar - optimale Kraftstoffenergie
    engKinEndInx...
    ] = ...
    clcOptTrj_tmp...
    (disFlg,...             Flag, ob Zielzustand genutzt werden muss
    wayStp,...              Skalar für die Wegschrittweite in m
    wayNum,...              Skalar für die max. Anzahl an Wegstützstellen
    wayInxBeg,...           Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,...           Skalar für Endindex in den Eingangsdaten
    staEnd,...              Skalar für den finalen Zustand
    engKinNum,...           Skalar für die max. Anz. an engKin-Stützstellen
    engKinEndInxVal,...     Skalar für Zielindex der kinetischen Energie
    staNum,...              Skalar für die max. Anzahl an Zustandsstützstellen
    engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
    engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J
    optPreInxTn3,...        Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3, ...       Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3, ...       Tensor 3. Stufe für die Kraftstoffenergie
    cos2goActMat ...        Matrix der optimalen Kosten der Hamiltonfunktion 
    ) %#codegen
%
%CLCOPTTRJ Calculating optimal trajectories for result of DP + PMP
% Erstellungsdatum der ersten Version 24.08.2015 - Stephan Uebel
%
% Diese Funktion berechnet die optimalen Trajketorien der kinetischen
% Energie und Anstriebsstrangzustands. Außerdem wird ein Verlauf für einen
% costate für die kinetische Energie aus den Ergebnissen der DP berechnet.
%   this function calulates the optimal trajectory for kinetic energy and
%   powertrain states. In addition, a course is calculated for a costate
%   for the kinetic energy from the DP results.
%
% !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!!
% Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der
% jeweiligen Position des Vektors.
%   !!!! Please note, how vectors/tensors are read !!!!
%   Values that are at the beginning and end of an interval are at their
%   respective indexes along the vector.
%
% Mittelwerte, d.h. Flussgrößen wie Kräfte, Leistungen etc., stehen immmer
% am Anfang des Intervalls für das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer.
%   mean values (eg flow variables like forces, services) are always at the
%   beginning of the interval for the next interval. Those vectors/tensors
%   are therefore shorter by a valid entry (index?).

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

% Trajektorie der optimalen kin. Energien
%   optimal kinetic energy trajectory initializaton
engKinOptVec    = inf(wayNum,1);

% Trajektorie der optimalen Batterieenergieänderung im Intervall
%   optimal battery energy change trajectories for the interval
batEngDltOptVec = inf(wayNum,1);

% Trajektorie des optimalen Antriebsstrangzustands im Intervall
%   optimal powertrain state trajectories for the interval
staVec          = zeros(wayNum,1);


%% Initialisieren des finalen Zustands
%   intializing the final state

% Indexvektor der optimalen kinetischen Energien
%   index vector for the optimal kinetic energies
engKinOptInxVec = zeros(wayNum,1);

% Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls 
% Zielgang nicht festgelegt ist
%   find the optimal gear and speed if the target gear isn't fixed
if disFlg
    staVec(wayInxEnd-1) = staEnd;
    
    % Die finale kinetische Energie steht an Stelle 1 im Vektor
    %   the final kinetic energy is at the first index in the vector
    engKinEndInx = engKinEndInxVal;
    
else
    [val,inx] = min(cos2goActMat);
    [~,staVec(wayInxEnd-1)] = min(val);
    engKinEndInx = inx(staVec(wayInxEnd-1));
end
% assign the last value in the optimatal KE INDEX vector as the last KE idx
engKinOptInxVec(wayInxEnd) = engKinEndInx;

% Zielzustand des Ausgabevektors für optimale kinetische Energie
% beschreiben
%   describe the target state of the output vector for the optimal KE
engKinOptVec(wayInxEnd,1) = ...
    engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInxEnd,1),wayInxEnd);

% Batterieenergieänderung im letzten Intervall initialisieren
%   initialize battery engery change's last interval
batEngDltOptVec(wayInxEnd-1,1) = ...
    batFrcOptTn3(engKinOptInxVec(wayInxEnd),staVec(wayInxEnd-1),wayInxEnd-1)...
    * wayStp;

% Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie
%   writing the output for the optimal fuel energy
fulEngOpt = ...
    fulEngOptTn3(engKinOptInxVec(wayInxEnd),staVec(wayInxEnd-1),wayInxEnd);

% Initialisieren des Vektors der optimalen Kraftstoffenergieänderung
%   intializing the optimum fuel energy change vector
fulEngDltOptVec = zeros(wayNum,1);

% Costate für die kinetische Energie initialisieren
%   intializing the kinetic energy's costate
psiEngKinOptVec = zeros(wayNum,1);

%% Rückwärtsrechnung über alle Wegpunkte 
%   reverse calculation of all the path indexes

% Rekonstruieren des optimalen Pfades aus
%   rebuilding the optimale path
for wayInx = wayInxEnd:-1:wayInxBeg+1
    
    % optimalen Vorgängerindex aus Tensor auslesen
    %   reading the tensor's optimum previous index 
    optInx = optPreInxTn3(engKinOptInxVec(wayInx,1),...
        staVec(wayInx-1,1),wayInx);
    
    if optInx == 0
        error('Fehler beim Speichern der optimalen Vorgaenger.') % <- Vorgänger = predecessor
    end
    
    % optimalen Index dekodieren
    %   decoding the optimal index
    if wayInx > wayInxBeg+1
        % what does this do? - assigns index values, that's for sure
        % - its repopulating the vectors (previously assigned to 0) by
        %   looping through all the path states and selecting all the 
        %   optimum state variables in each of the mats based on the
        %   generated optimum indexes

        [engKinOptInxVec(wayInx-1,1),staVec(wayInx-2,1)] = ...
            ind2sub([engKinNum,staNum],optInx);
        
        % Batterieenergieänderung für Vorgängerintervall speichern
        % Flussgröße (gilt im Intervall)
        %   storing the previous interval's battery energy change's flow
        %   amount
        batEngDltOptVec(wayInx-2,1) = ...
            batFrcOptTn3(engKinOptInxVec(wayInx-1),...
            staVec(wayInx-2),wayInx-2) * wayStp;
        
        % Krafstoffenergieänderung für Intervall speichern
        % Flussgröße (gilt im Intervall)
        % Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie
        %   storing the interval's fuel energy change flow amount
        %   describing the output size of the optimal fuel energy
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engKinOptInxVec(wayInx),staVec(wayInx-1),wayInx) - ...
            fulEngOptTn3(engKinOptInxVec(wayInx-1),staVec(wayInx-2),wayInx-1);
        
        %% Bestimmung des costate für die kinetische Energie
        %   determining the kinetic energy costate
        %
        % Am jeweiligen Wegpunkt wird der Kraftstoffaufwand gegenüber eine
        % änderung der kinetischen Engergie an der Stelle der
        % optimalen Trajektorie berechnet.
        %   at each path_idx the fuel is calculated towards a change in the
        %   KE at the location of optimal trajectory. (doesn't make much
        %   sense)
        
        %   calculating the KE costate vec by diving the delta optimum fuel 
        %   energy tensor by the delta kinetic energy mat for each wayInx.
        psiEngKinVec= diff(fulEngOptTn3(1:engKinNumVec_wayInx(wayInx-1),staVec(wayInx-2),wayInx-1)) ...
            ./ diff(engKinMat_engKinInx_wayInx(1:engKinNumVec_wayInx(wayInx-1),wayInx-1));% <-fast immer 5000;
        psiEngKinVec = [0;psiEngKinVec];    % what is the point of adding 0
        psiEngKinOptVec(wayInx-1) = psiEngKinVec(engKinOptInxVec(wayInx-1,1));
        
        % Potentialgrößen im ersten Punkt speichern
        %   save potetial variables in the first point/index
    else % if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1)
        [engKinOptInxVec(wayInx-1,1),~] = ...
            ind2sub([engKinNum,staNum],optInx);
        
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engKinOptInxVec(wayInx),staVec(wayInx-1),wayInx);
    end
        
    % optimale kinetische Energie im Vorgängerpunkt
    %   optimal KE from previous point / path_idx
    engKinOptVec(wayInx-1,1) = ...
        engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInx-1,1),wayInx-1);

    
end % end of path_idx loop

end % end of function