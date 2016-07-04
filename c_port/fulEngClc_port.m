function [...
    emoPwrEle, ...  Skalar f�r die Batterieleistung
    fulFrc ...      Skalar Kraftstoffkraft
    ] = ...
    fulEngClc_port...
    (wayStp,...     Skalar f�r die Wegschrittweite in m
    vel,...         vehicular velocity
    batPwrAux,...   Nebenverbraucherlast
    batOcv,...      Skalar - battery open circuit voltage
    batEngDlt, ...  Skalar - Batterieenergieänderung
    crsSpd,...      Skalar - crankshaft speed at given path_idx
    crsTrq,...      Skalar - crankshaft torque at given path_idx
    iceTrqMin,...   Skalar - min ICE torque allowed
    iceTrqMax,...   Skalar - max ICE torque
    fzg_scalar,...  struct - Fahrzeugparameter - nur skalar
    fzg_array...    struct - Fahrzeugparameter - nur array        
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

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

    emoPwrEle = inf;    %   Skalar - electric battery power (W)
    fulFrc    = inf;    %   Skalar - fuel force intialization (N)

%% Batterie

% Batterieenergieänderung über dem Weg (Batteriekraft)
%   Change in battery energy over the path_idx way (ie battery power)
batFrc = batEngDlt / wayStp;

% Fallunterscheidung, ob Batterie geladen oder entladen wird
%   Case analysis - check if battery is charging or discharging. Set
%   resistance accordingly
if batFrc < 0
    batRst = fzg_scalar.batRstDch;
else
    batRst = fzg_scalar.batRstChr;
end

% elektrische Leistung des Elektromotors
%   electric power from electric motor - DERIVATION? dunno
emoPwrEle = -batFrc * vel ... innere Batterieleistung / internal batt power
    - batFrc^2 * vel^2 / batOcv^2 * batRst...dissipat. Leist. / dissipated
    - batPwrAux; ...          Nebenverbrauchlast / auxiliary power
    
%% Elektromotor

% Ermitteln des Kurbelwellenmoments durch EM aus Batterieleistung
%   determine crankshaft torque cauesd by EM's battery power
%       switching out codegen_interp2 for lininterp2-just might work!
%
emoTrq = codegen_interp2(fzg_array.emoSpdMgd,fzg_array.emoPwrMgd,...
  fzg_array.emoTrq_emoSpd_emoPwr,crsSpd,emoPwrEle);
% emoTrq = lininterp2(par.emoSpdMgd(1,:), par.emoPwrMgd(:,1),...
%     par.emoTrq_emoSpd_emoPwr',crsSpd,emoPwrEle);

if isinf(emoTrq)
    return;
end

% Grenzen des Elektromotors müssen hier nicht überprüft werden, da die
% Ladungsdeltas schon so gewählt wurden, dass das maximale Motormoment
% nicht überstiegen wird.
%   Electric motor limits need not be checked here, since the charge deltas
%   have been chosen so that the max torque is not exceeded.

%% Verbrennungsmotor

% Ermitteln des Kurbelwellenmoments durch den Verbrennungsmotor
%   Determining the crankshaft moment from the ICE
iceTrq = crsTrq - emoTrq;

% Wenn das Verbrennungsmotormoment kleiner als das minimale
% Moment ist, ist dieser in der Schubabschaltung. Das
% verbleibende Moment liefern die Bremsen
%   If engine torque is less than the min torque, fuel is cut. The
%   remaining torque is deliver the brakes.
if iceTrq < iceTrqMin
    fulPwr = 0;
elseif iceTrq > iceTrqMax
    fulPwr = inf;
else   
    % replacing another coden_interp2 no just find fuel power as usual
    fulPwr = codegen_interp2(fzg_array.iceSpdMgd,fzg_array.iceTrqMgd,...
        fzg_array.iceFulPwr_iceSpd_iceTrq,crsSpd,iceTrq);
%     fulPwr = lininterp2(par.iceSpdMgd(1,:), par.iceTrqMgd(:,1), ...
%         par.iceFulPwr_iceSpd_iceTrq', crsSpd, iceTrq);
end

% Berechnen der Kraftstoffkraft
%   calculate fuel force
fulFrc = fulPwr/vel;

% Berechnen der Kraftstoffvolumenänderung
% caluclate change in fuel volume - energy, no?
fulEngDlt = fulFrc * wayStp;

%% Ende der Funktion
end
