function [...
    fulEng          ... Skalar Kraftstoffkraft
    ] =             ...
    fulEngClc_focus     ...
    (timeStp,       ... Skalar für die Wegschrittweite in m
    vel,            ... vehicular velocity
    batPwrAux,      ... Nebenverbraucherlast
    batOcv,         ... Skalar - battery open circuit voltage
    batEngDlt,      ... Skalar - Batterieenergieänderung
    engStaPre,      ... previous state of engine (off-on)
    crsSpd,         ... Skalar - crankshaft speed at given path_idx
    iceTrq,         ... Skalar - ice torque at given path_idx
    iceTrqMin,      ... Skalar - min ICE torque allowed
    iceTrqMax,      ... Skalar - max ICE torque
    fzg_scalar_struct,     ... struct - Fahrzeugparameter - nur skalar
    fzg_array_struct       ... struct - Fahrzeugparameter - nur array        
    ) %#codegen
%
%FULENGCLC Calculating fuel consumption
% Erstellungsdatum der ersten Version 04.09.2015 - Stephan Uebel
%
% Diese Funktion berechnet den Kraftstoffverbrauch für einen gegebenen
% Wegschritt der kinetischen Energie, der Batterieenergie und des
% Antriebsstrangzustands über dem Weg.
%   this function calculates fuel consumption for a given route step of
%   KE, the battery energy, and drivetrain state of the current path_idx
%
% Version vom 17.02.2016 : Rotationsmassen vernachlässigt
%                           ^^ neglected rotatary masses
%
% Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit)
%
% version from 1.06.2016 - removed crsTrq calculations - they are already
% done in parent function (clcPMP_olHyb_tmp) and do not change w/ each
% iteration, making the calculation here unnecessary
%
% % 06.07.2016 - replacing KE state dimension with engine control
%
% am using values from previous timeIdx (velocity, engine state), but I am
% not 100% sure why - will have to look into later.
% But older code used predecesor values as well
%
% 15.05.2016 - refitting so that fuel calculations are for straight E'
% states - checks have been moved further up in loops outside this function

%% Initialisieren der Ausgabe der Funktion
%   initializing function output
fulEng    = inf;    %   Skalar - fuel force intialization (N)

%% Batterie
% 
% % BatterieenergieÃ¤nderung Ã¼ber dem Weg (Batteriekraft)
% %   Change in battery energy over the path_idx way (ie battery power)
% batPwr = batEngDlt / timeStp;
% 
% % Fallunterscheidung, ob Batterie geladen oder entladen wird
% %   Case analysis - check if battery is charging or discharging. Set
% %   resistance accordingly
% if batEngDlt < 0
%     batRst = fzg_scalar_struct.batRstDch;
% else
%     batRst = fzg_scalar_struct.batRstChr;
% end
% 
% % elektrische Leistung des Elektromotors
% %   electric power from electric motor - DERIVATION? dunno
% emoPwrEle = -batPwr * vel ... innere Batterieleistung / internal batt power
%     - batPwr^2 * vel^2 / batOcv^2 * batRst...dissipat. Leist. / dissipated
%     - batPwrAux; ...          Nebenverbrauchlast / auxiliary power
% 
% %% Verbrennungsmotor
% 
% % Ermitteln des Kurbelwellenmoments durch den Verbrennungsmotor
% %   Determining the crankshaft moment from the ICE
% iceTrq = crsTrq - emoTrq;

% Wenn das Verbrennungsmotormoment kleiner als das minimale
% Moment ist, ist dieser in der Schubabschaltung. Das
% verbleibende Moment liefern die Bremsen
%   If engine torque is less than the min torque, fuel is cut ( or if
%   vehicle is stationary). The  remaining torque is deliver the brakes.
%   - also calculate fuel force (Berechnen der Kraftstoffkraft)
if iceTrq < iceTrqMin || vel < abs(fzg_scalar_struct.vehVelThresh) || ~engStaPre
%     fulPwr = 0;
    fulEng = 0;
elseif iceTrq > iceTrqMax
%     fulPwr = inf;
    fulEng = inf;
else   
    % replacing another coden_interp2 no just find fuel power as usual
    fulPwr = codegen_interp2(fzg_array_struct.iceSpdMgd,fzg_array_struct.iceTrqMgd,...
        fzg_array_struct.iceFulPwr_iceSpd_iceTrq,crsSpd,iceTrq);
    fulEng = fulPwr/vel;
end

% Berechnen der KraftstoffvolumenÃ¤nderung
% caluclate change in fuel volume - energy, no?
fulEngDlt = fulEng * timeStp; % necessay? is just normalizing jump

%% Ende der Funktion
end
