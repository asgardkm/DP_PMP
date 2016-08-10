function [          ...
    batPwrOptVec,   ... Vektor - optimale BatterieenergieÃ¤nderung
    fulEngDltOptVec,... Vektor - optimale KraftstoffenergieÃ¤nderung
    engStaOptVec,   ... vector showing optimal engine contorl w/ profile
    batStaOptVec,   ... vector showing optimal battery level control
    batEngOptVec,   ... vector showing optimal battery levels
    emoTrqOptVec,   ...
    iceTrqOptVec,   ...
    brkTrqOptVec,   ...
    fulEngOpt       ... Skalar - optimale Kraftstoffenergie
    ] =             ...
    clcOptTrj_focus_useGeaVec ...
       (timVec,         ... Skalar für die max. Anzahl an WegstÃ¼tzstellen
        engEnd,         ... scalar - prefinal engine state
        engEndEnd,      ... Skalar fï¿½r Zielindex der kinetischen Energie
        batEndInx,      ... scalar - final battery state
        batStaNum,      ... scalar - for number of battery states exist
        optPreInxTn3,   ... Tensor 3. Stufe für opt. Vorgängerkoordinaten
        batPwrOptTn3,   ... Tensor 3. Stufe der Batteriekraft
        fulEngOptTn3,   ... Tensor 3. Stufe für die Kraftstoffenergie
        cos2goActMat,   ... Matrix der optimalen Kosten der Hamiltonfunktion 
        emoTrqOptTn3,   ...
        iceTrqOptTn3,   ...
        brkTrqOptTn3,   ...
        inputparams,    ...
        tst_scalar_struct...
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
timNum = length(timVec);

% Trajektorie der optimalen kin. Energien
%   optimal kinetic energy trajectory initializaton
engStaOptVec    = inf(timNum,1);

% Trajektorie der optimalen BatterieenergieÃ¤nderung im Intervall
%   optimal battery energy change trajectories for the interval
batPwrOptVec    = inf(timNum,1);

batStaOptVec    = zeros(timNum, 1);

% define timInxEnd because it is invoked so often
timInxEnd = inputparams.timInxEnd;
%% Initialisieren des finalen Zustands
%   intializing the final state

% Indexvektor der optimalen kinetischen Energien
%   index vector for the optimal kinetic energies
% engKinOptInxVec = zeros(wayNum,1);

% Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls 
% Zielgang nicht festgelegt ist
%   find the optimal gear and speed if the target gear isn't fixed
if inputparams.disFlg    
    engStaOptVec(timInxEnd-1) = engEnd;
    
    batStaOptVec(timInxEnd-1) = batEndInx;
    
    % Die finale kinetische Energie steht an Stelle 1 im Vektor
    %   the final kinetic energy is at the first index in the vector
    engStaEndInx = engEndEnd;
    
else
    % what is this again? because disFlg is used to display to screen. IS
    % it being used to ensure target trajectory as well? How so?
%     [val,inx] = min(cos2goActTn3);
%     [~,geaStaEndInx] = min(val);
%     engStaEndInx = inx(geaStaEndInx);
%     geaStaOptVec(timInxEnd-1) = geaStaEndInx;

    % switching fuel values to positive so that min eq here works. Albeit that
    % this is not the best place to do so - would be optimal to do when
    % cos2goActTn3 is being populated in clcDP. 
    cos2goActMat(~isinf(cos2goActMat)) = -cos2goActMat(~isinf(cos2goActMat));
    
    [colmin, colminidx] = min(cos2goActMat);
    [~, batStaEndInx] = min(colmin);
    engStaEndInx    = colminidx(batStaEndInx);
    
    engStaOptVec(timInxEnd-1) = engStaEndInx;
    batStaOptVec(timInxEnd-1) = batStaEndInx;

end

% assign the last value in the optimatal KE INDEX vector as the last KE idx
% how to set a boundary between batEngEndMin and Max??
% engStaOptVec(timInxEnd) = engStaEndInx;
engStaOptVec(timInxEnd) = engStaEndInx;

% Zielzustand des Ausgabevektors für optimale kinetische Energie
% beschreiben
%   describe the target state of the output vector for the optimal KE

% Batterieenergieänderung im letzten Intervall initialisieren
%   initialize battery energy change's last interval
batPwrOptVec(timInxEnd-1,1) = ...
    batPwrOptTn3(engStaOptVec(timInxEnd)+1, batStaOptVec(timInxEnd-1), ...
                timInxEnd-1) * inputparams.timStp;

% Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie
%   writing the output for the optimal fuel energy
fulEngOpt = ...
    fulEngOptTn3(engStaOptVec(timInxEnd)+1, batStaOptVec(timInxEnd-1), ...
                timInxEnd);

% Initialisieren des Vektors der optimalen Kraftstoffenergieänderung
%   intializing the optimum fuel energy change vector
fulEngDltOptVec = zeros(timNum,1);
emoTrqOptVec    = zeros(timNum, 1);
iceTrqOptVec    = zeros(timNum, 1);
brkTrqOptVec    = zeros(timNum, 1);
%% Rückwärtsrechnung über alle Wegpunkte 
%   reverse calculation of all the path indexes

% Rekonstruieren des optimalen Pfades aus
%   rebuilding the optimale path
for timInx = timInxEnd:-1:inputparams.timInxBeg+1
    
    % optimalen Vorgängerindex aus Tensor auslesen
    %   reading the tensor's optimum previous index 
    optInx = optPreInxTn3(engStaOptVec(timInx,1)+1,batStaOptVec(timInx-1,1), timInx);
    
    % <- Vorgänger = predecessor
    if optInx == 0
        error('Fehler beim Speichern der optimalen Vorgaenger.') 
    end
    
    % optimalen Index dekodieren
    %   decoding the optimal index
    if timInx > inputparams.timInxBeg+1
        % what does this do? - assigns index values, that's for sure
        % - its repopulating the vectors (previously assigned to 0) by
        %   looping through all the path states and selecting all the 
        %   optimum state variables in each of the mats based on the
        %   generated optimum indexes

        [engStaOptVec(timInx-1,1), batStaOptVec(timInx-2,1)] = ...
            ind2sub([tst_scalar_struct.engStaNum, batStaNum],optInx);
        % revert engStaOptVec from index value to boolean
        engStaOptVec(timInx-1,1) = engStaOptVec(timInx-1,1)-1;
        % 2 - because of number of engine states - send to mainConfig!!
        
        % Batterieenergieänderung für Vorgängerintervall speichern
        % Flussgröße (gilt im Intervall)
        %   storing the previous interval's battery energy change's flow
        %   amount
        batPwrOptVec(timInx-2,1) = ...
            batPwrOptTn3(engStaOptVec(timInx-1)+1,...
                         batStaOptVec(timInxEnd-2), timInx-2) * inputparams.timStp;
        
        % KrafstoffenergieÃ¤nderung fÃ¼r Intervall speichern
        % FlussgrÃ¶ÃŸe (gilt im Intervall)
        % Beschreiben der AusgabegrÃ¶ÃŸe der optimalen Kraftstoffenergie
        %   storing the interval's fuel energy change flow amount
        %   describing the output size of the optimal fuel energy
        fulEngDltOptVec(timInx-1,1) = ...
            fulEngOptTn3(engStaOptVec(timInx)+1, batStaOptVec(timInx-1), timInx) - ...
            fulEngOptTn3(engStaOptVec(timInx-1)+1,batStaOptVec(timInx-2), timInx-1);
        
   
        %   save potetial variables in the first point/index
    else % if timInx == timInxBeg ( == 1 if wayOInxBeg = 1)
        [engStaOptVec(timInx-1,1), batStaOptVec(timInx-1,1)] = ...
            ind2sub([tst_scalar_struct.engStaNum, batStaNum], optInx);
        
        fulEngDltOptVec(timInx-1,1) = ...
            fulEngOptTn3(engStaOptVec(timInx)+1, batStaOptVec(timInx-1), timInx);
        
%         engStaOptVec(timInx-1,1) = engStaOptVec(timInx,1);
    end
%     % save optimal torque values 
% emoTrq
emoTrqOptVec(timInx) = ...
    emoTrqOptTn3(engStaOptVec(timInx,1)+1, ...
                  batStaOptVec(timInx,1), ...
                  timInx);
% iceTrq
iceTrqOptVec(timInx) = ...
    iceTrqOptTn3(engStaOptVec(timInx,1)+1, ...
                  batStaOptVec(timInx,1), ...
                  timInx);
% brkTrq
brkTrqOptVec(timInx) = ...
    brkTrqOptTn3(engStaOptVec(timInx,1)+1, ...
                  batStaOptVec(timInx,1), ...
                  timInx);
                            
%                   
end % end of path_idx loop

% derive battery energy based on the battery power
batEngOptVec = [(batStaOptVec(1:end-1)-1) * tst_scalar_struct.batEngStp; (batEndInx-1)*tst_scalar_struct.batEngStp];

end % end of function