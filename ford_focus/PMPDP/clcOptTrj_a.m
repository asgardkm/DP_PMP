function [          ...
    batEngDltOptVec,... Vektor - optimale BatterieenergieÃ¤nderung
    fulEngDltOptVec,... Vektor - optimale KraftstoffenergieÃ¤nderung
    geaStaOptVec,   ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaOptVec,   ... vector showing optimal engine contorl w/ profile
    fulEngOpt       ... Skalar - optimale Kraftstoffenergie
    ] =             ...
    clcOptTrj_a     ...
    (disFlg,        ... Flag, ob Zielzustand genutzt werden muss
    timeStp,        ... Skalar für die Wegschrittweite in m
    timeNum,        ... Skalar für die max. Anzahl an WegstÃ¼tzstellen
    wayInxBeg,      ... Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar für Endindex in den Eingangsdaten
    staEnd,         ... Skalar für den finalen Zustand
    engEnd,         ... scalar - final engine state
    engStaEndInxVal,...
    staNum,         ... Skalar für die max. Anzahl an Zustandsstützstellen
    engStaNum,      ... scalar - for number of states engine can take
    optPreInxTn3,   ... Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe für die Kraftstoffenergie
    cos2goActMat    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    ) %#codegen
%
%CLCOPTTRJ Calculating optimal trajectories for result of DP + PMP
% Erstellungsdatum der ersten Version 24.08.2015 - Stephan Uebel
% 13.07.2016 - modified to work with engine on-off control instead of KE
% costate calculation and optimization - asgard kaleb marroquin
%
% Diese Funktion berechnet die optimalen Trajketorien der kinetischen
% Energie und Anstriebsstrangzustands. AuÃŸerdem wird ein Verlauf fÃ¼r einen
% costate fÃ¼r die kinetische Energie aus den Ergebnissen der DP berechnet.
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
% Mittelwerte, d.h. FlussgrÃ¶ÃŸen wie KrÃ¤fte, Leistungen etc., stehen immmer
% am Anfang des Intervalls fÃ¼r das folgende Intervall. Diese
% Vektoren/Tensoren sind daher um einen gÃ¼ltigen Eintrag kÃ¼rzer.
%   mean values (eg flow variables like forces, services) are always at the
%   beginning of the interval for the next interval. Those vectors/tensors
%   are therefore shorter by a valid entry (index?).

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

% Trajektorie der optimalen kin. Energien
%   optimal kinetic energy trajectory initializaton
engStaOptVec    = inf(timeNum,1);

% Trajektorie der optimalen BatterieenergieÃ¤nderung im Intervall
%   optimal battery energy change trajectories for the interval
batEngDltOptVec = inf(timeNum,1);

% Trajektorie des optimalen Antriebsstrangzustands im Intervall
%   optimal powertrain state trajectories for the interval
geaStaOptVec    = zeros(timeNum,1);


%% Initialisieren des finalen Zustands
%   intializing the final state

% Indexvektor der optimalen kinetischen Energien
%   index vector for the optimal kinetic energies
% engKinOptInxVec = zeros(wayNum,1);

% Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls 
% Zielgang nicht festgelegt ist
%   find the optimal gear and speed if the target gear isn't fixed
if disFlg
    geaStaOptVec(wayInxEnd-1) = staEnd;
    
    engStaOptVec(wayInxEnd-1) = engEnd;
    
    % Die finale kinetische Energie steht an Stelle 1 im Vektor
    %   the final kinetic energy is at the first index in the vector
    engStaEndInx = engStaEndInxVal;
    
else
    [val,inx] = min(cos2goActMat);
    [~,geaStaOptVec(wayInxEnd-1)] = min(val);
    engStaEndInx = inx(geaStaOptVec(wayInxEnd-1));
end

% assign the last value in the optimatal KE INDEX vector as the last KE idx
% how to set a boundary between batEngEndMin and Max??
engStaOptVec(wayInxEnd) = engStaEndInx;

% Zielzustand des Ausgabevektors fÃ¼r optimale kinetische Energie
% beschreiben
%   describe the target state of the output vector for the optimal KE

% engKinOptVec(wayInxEnd,1) = ...
%     engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInxEnd,1),wayInxEnd);
 
% BatterieenergieÃ¤nderung im letzten Intervall initialisieren
%   initialize battery engery change's last interval
batEngDltOptVec(wayInxEnd-1,1) = ...
    batFrcOptTn3(engStaOptVec(wayInxEnd)+1,geaStaOptVec(wayInxEnd-1),wayInxEnd-1)...
    * timeStp;

% Beschreiben der AusgabegrÃ¶ÃŸe der optimalen Kraftstoffenergie
%   writing the output for the optimal fuel energy
fulEngOpt = ...
    fulEngOptTn3(engStaOptVec(wayInxEnd)+1,geaStaOptVec(wayInxEnd-1),wayInxEnd);

% Initialisieren des Vektors der optimalen KraftstoffenergieÃ¤nderung
%   intializing the optimum fuel energy change vector
fulEngDltOptVec = zeros(timeNum,1);

% Costate fÃ¼r die kinetische Energie initialisieren
%   intializing the kinetic energy's costate
% psiEngKinOptVec = zeros(wayNum,1);

%% Rückwärtsrechnung über alle Wegpunkte 
%   reverse calculation of all the path indexes

% Rekonstruieren des optimalen Pfades aus
%   rebuilding the optimale path
for wayInx = wayInxEnd:-1:wayInxBeg+1
    
    % optimalen Vorgängerindex aus Tensor auslesen
    %   reading the tensor's optimum previous index 
    optInx = optPreInxTn3(engStaOptVec(wayInx,1)+1,...
        geaStaOptVec(wayInx-1,1),wayInx);
    
    % <- Vorgänger = predecessor
    if optInx == 0
        error('Fehler beim Speichern der optimalen Vorgaenger.') 
    end
    
    % optimalen Index dekodieren
    %   decoding the optimal index
    if wayInx > wayInxBeg+1
        % what does this do? - assigns index values, that's for sure
        % - its repopulating the vectors (previously assigned to 0) by
        %   looping through all the path states and selecting all the 
        %   optimum state variables in each of the mats based on the
        %   generated optimum indexes

        [engStaOptVec(wayInx-1,1),geaStaOptVec(wayInx-2,1)] = ...
            ind2sub([engStaNum,staNum],optInx);
        % revert engStaOptVec from index value to boolean
        engStaOptVec(wayInx-1,1) = engStaOptVec(wayInx-1,1)-1;
        % 2 - because of number of engine states - send to mainConfig!!
        
        % Batterieenergieänderung für Vorgängerintervall speichern
        % Flussgröße (gilt im Intervall)
        %   storing the previous interval's battery energy change's flow
        %   amount
        batEngDltOptVec(wayInx-2,1) = ...
            batFrcOptTn3(engStaOptVec(wayInx-1)+1,...
            geaStaOptVec(wayInx-2),wayInx-2) * timeStp;
        
        % KrafstoffenergieÃ¤nderung fÃ¼r Intervall speichern
        % FlussgrÃ¶ÃŸe (gilt im Intervall)
        % Beschreiben der AusgabegrÃ¶ÃŸe der optimalen Kraftstoffenergie
        %   storing the interval's fuel energy change flow amount
        %   describing the output size of the optimal fuel energy
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engStaOptVec(wayInx)+1,geaStaOptVec(wayInx-1),wayInx) - ...
            fulEngOptTn3(engStaOptVec(wayInx-1)+1,geaStaOptVec(wayInx-2),wayInx-1);
        
        %% Bestimmung des costate fÃ¼r die kinetische Energie
        %   determining the kinetic energy costate
        %
        % Am jeweiligen Wegpunkt wird der Kraftstoffaufwand gegenÃ¼ber eine
        % Ã¤nderung der kinetischen Engergie an der Stelle der
        % optimalen Trajektorie berechnet.
        %   at each path_idx the fuel is calculated towards a change in the
        %   KE at the location of optimal trajectory. (doesn't make much
        %   sense)
        
        %   calculating the KE costate vec by diving the delta optimum fuel 
        %   energy tensor by the delta kinetic energy mat for each wayInx.
%         psiEngKinVec= diff(fulEngOptTn3(1:engKinNumVec_wayInx(wayInx-1),staVec(wayInx-2),wayInx-1)) ...
%             ./ diff(engKinMat_engKinInx_wayInx(1:engKinNumVec_wayInx(wayInx-1),wayInx-1));% <-fast immer 5000;
%         psiEngKinVec = [0;psiEngKinVec];    % what is the point of adding 0
%         psiEngKinOptVec(wayInx-1) = psiEngKinVec(engKinOptInxVec(wayInx-1,1));
        
        % PotentialgrÃ¶ÃŸen im ersten Punkt speichern
        %   save potetial variables in the first point/index
    else % if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1)
        [engStaOptVec(wayInx-1,1),~] = ...
            ind2sub([engStaNum,staNum],optInx);
        fulEngDltOptVec(wayInx-1,1) = ...
            fulEngOptTn3(engStaOptVec(wayInx)+1,geaStaOptVec(wayInx-1),wayInx);
        engStaOptVec(wayInx-1,1) = engStaOptVec(wayInx-1,1)-1;
    end
        
    % optimale kinetische Energie im VorgÃ¤ngerpunkt
    %   optimal KE from previous point / path_idx
%     engKinOptVec(wayInx-1,1) = ...
%         engKinMat_engKinInx_wayInx(engKinOptInxVec(wayInx-1,1),wayInx-1);

    
end % end of path_idx loop

end % end of function