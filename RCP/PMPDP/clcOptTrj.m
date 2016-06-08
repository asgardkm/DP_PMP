function [engKinOptVec,...  Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec, ...    Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,...     Vektor - optimale Kraftstoffenergieänderung
    staVec,...              Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,...     Vektor - costate für kinetische Energie
    fulEngOpt, ...          Skalar - optimale Kraftstoffenergie
    engKinEndInx...
    ] = ...
    clcOptTrj...
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

%% Initialisieren der Ausgabe der Funktion
%   initializing output function

% Trajektorie der optimalen kin. Energien
%   optimal kinetic energy trajectory initializaton
engKinOptVec = inf(wayNum,1);

% Trajektorie der optimalen Batterieenergieänderung im Intervall
batEngDltOptVec = inf(wayNum,1);

% Trajektorie des optimalen Antriebsstrangzustands im Intervall
staVec = zeros(wayNum,1);


%% Initialisieren des finalen Zustands

% Indexvektor der optimalen kinetischen Energien
engKinOptInxVec = zeros(wayNum,1);

% Suche des optimalen Gangs und der optimalen Geschwindigkeit,...
% falls Zielgang nicht festgelegt ist
if disFlg
    staVec(wayInxEnd-1) = staEnd;
    
    % Die finale kinetische Energie steht an Stelle 1 im Vektor
    engKinEndInx = engKinEndInxVal;
    
else
    [val,inx] = min(cos2goActMat);
    [~,staVec(wayInxEnd-1)] = min(val);
    engKinEndInx = inx(staVec(wayInxEnd-1));
end
engKinOptInxVec(wayInxEnd) = engKinEndInx;


% Zielzustand des Ausgabevektors f�r optimale kinetische Energie
% beschreiben
engKinOptVec(wayInxEnd,1) = ...
    engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInxEnd,1),wayInxEnd);

% Batterieenergie�nderung im letzten Intervall initialisieren
batEngDltOptVec(wayInxEnd-1,1) = ...
    batFrcOptTn3(engKinOptInxVec(wayInxEnd),staVec(wayInxEnd-1),wayInxEnd-1)...
    * wayStp;

% Beschreiben der Ausgabegr��e der optimalen Kraftstoffenergie
fulEngOpt = ...
    fulEngOptTn3(engKinOptInxVec(wayInxEnd),staVec(wayInxEnd-1),wayInxEnd);

% Initialisieren des Vektors der optimalen Kraftstoffenergie�nderung
fulEngDltOptVec = zeros(wayNum,1);

% Costate f�r die kinetische Energie initialisieren
psiEngKinOptVec = zeros(wayNum,1);

%% R�ckw�rtsrechnung �ber alle Wegpunkte 
% Rekonstruieren des optimalen Pfades aus

for wayInx = wayInxEnd:-1:wayInxBeg+1
    
    % optimalen Vorg�ngerindex aus Tensor auslesen
    optInx = optPreInxTn3(engKinOptInxVec(wayInx,1),...
        staVec(wayInx-1,1),wayInx);
    
    if optInx == 0
        error('Fehler beim Speichern der optimalen Vorgaenger.') % <- Vorgänger = predecessor
    end
    
    % optimalen Index dekodieren
    if wayInx > wayInxBeg+1
        [engKinOptInxVec(wayInx-1,1),staVec(wayInx-2,1)] = ...
            ind2sub([engKinNum,staNum],optInx);
        
        % Batterieenergie�nderung f�r Vorg�ngerintervall speichern
        % Flussgr��e (gilt im Intervall)
        batEngDltOptVec(wayInx-2,1) = ...
            batFrcOptTn3(engKinOptInxVec(wayInx-1),...
            staVec(wayInx-2),wayInx-2) * wayStp;
        
        % Krafstoffenergie�nderung f�r Intervall speichern
        % Flussgr��e (gilt im Intervall)
        % Beschreiben der Ausgabegr��e der optimalen Kraftstoffenergie
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engKinOptInxVec(wayInx),staVec(wayInx-1),wayInx) - ...
            fulEngOptTn3(engKinOptInxVec(wayInx-1),staVec(wayInx-2),wayInx-1);
        
        %% Bestimmung des costate f�r die kinetische Energie
        % Am jeweiligen Wegpunkt wird der Kraftstoffaufwand gegen�ber eine
        % �nderung der kinetischen Engergie an der Stelle der
        % optimalen Trajektorie berechnet.
        
        psiEngKinVec= diff(fulEngOptTn3(1:engKinNumVec_wayInx(wayInx-1),staVec(wayInx-2),wayInx-1)) ...
            ./ diff(engKinMat_engKinInx_wayInx(1:engKinNumVec_wayInx(wayInx-1),wayInx-1));
        psiEngKinVec = [0;psiEngKinVec];
        psiEngKinOptVec(wayInx-1) = psiEngKinVec(engKinOptInxVec(wayInx-1,1));
        
        % Potentialgr��en im ersten Punkt speichern
    else
        [engKinOptInxVec(wayInx-1,1),~] = ...
            ind2sub([engKinNum,staNum],optInx);
        
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engKinOptInxVec(wayInx),staVec(wayInx-1),wayInx);
    end
    

    
    % optimale kinetische Energie im Vorg�ngerpunkt
    engKinOptVec(wayInx-1,1) = ...
        engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInx-1,1),wayInx-1);

    
end


end