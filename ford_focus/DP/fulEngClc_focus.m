function [...
    fulEng              ... Skalar Kraftstoffkraft
    ] =                 ...
    fulEngClc_focus     ...
    (timeStp,           ... Skalar für die Wegschrittweite in m
    vel,                ... vehicular velocity
    crsSpdPre,             ... Skalar - crankshaft speed at given path_idx
    iceTrq,             ... Skalar - ice torque at given path_idx
    iceTrqMax,          ... Skalar - max ICE torque
    fzg_scalar_struct,  ... struct - Fahrzeugparameter - nur skalar
    iceSpdMgd, ...
    iceTrqMgd, ...
    iceFulPwr_iceSpd_iceTrq...
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

%% Fuel energy calculation
% Wenn das Verbrennungsmotormoment kleiner als das minimale
% Moment ist, ist dieser in der Schubabschaltung. Das
% verbleibende Moment liefern die Bremsen
%   If engine torque is less than the min torque, fuel is cut (or if
%   vehicle is stationary). The remaining torque is delivered to brakes.
%   - also calculate fuel force (Berechnen der Kraftstoffkraft)
%       18.07.2016 - modified the less than min torque piece and moved it
%       to parent function optTrqSplot_focus as part of boundary tests.
if vel < abs(fzg_scalar_struct.vehVelThresh)
    fulEng = 0;
elseif iceTrq > iceTrqMax
    fulEng = inf;
else
    % calculate fuel power
    fulPwr = codegen_interp2(iceSpdMgd, ...
                     iceTrqMgd, ...
                     iceFulPwr_iceSpd_iceTrq, ...
                     crsSpdPre, ...
                     iceTrq);
    % since P = E/t, then E=P*t
    fulEng = fulPwr * timeStp;
end

%% Ende der Funktion
end
