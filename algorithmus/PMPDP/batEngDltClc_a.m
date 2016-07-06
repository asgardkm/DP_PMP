function [ ...
    batEngDltMin,...Skalar - änderung der minimalen Batterieenergieänderung
    batEngDltMax... Skalar - änderung der maximalen Batterieenergieänderung
    ] =         ...
    batEngDltClc_a...
    (           ...
    timeStp,     ... Skalar - time step inteval
    vehVel,        ... Skalar - Geschwindigkeit im Intervall
    batPwrAux,  ... Skalar - Nebenverbraucherlast
    batEngAct,  ... Skalar - Batterieenergie
    fzg_scalar_struct, ... struct - Fahrzeugparameter - nur skalar
    fzg_array_struct,  ... struct - Fahrzeugparameter - nur array
    crsSpd,     ... Skalar - crankshaft rotational speed
    crsTrq,     ... Skalar - crankshaft torque
    iceTrqMin,  ... Skalar - min ICE torque allowed
    iceTrqMax,  ... Skalar - max ICE torque
    emoTrqMaxPos... Skalar - max EM torque possible
    )%#codegen
%BatEngDltClc Calculates the change in battery energy
%
% Erstellungsdatum der ersten Version 17.11.2015 - Stephan Uebel
%   Berechnung der Verluste des Elektromotors bei voller rein elektrischer
%   Fahrt (voller Lastpunktabsenkung) und bei voller Lastpunktanhebung
%       Calculations of loss of electric motor at purely full electric
%       Driving (full load point lowering) and at full load point raising
%
% Version vom 17.02.2016: Keine Einbeziehung von Rotationsmassen
%                         ^^ No inclusion of rotational masses
%
% Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit)
%                         ^^ Zero-Order-Hold (no average velocities)

%% Initialisieren der Ausgabe der Funktion
%   initializing the function output (delta battery_energy min and max)
batEngDltMin = inf;
batEngDltMax = inf;

%% Elektromotor

% minimales Moment, dass die E-Maschine liefern kann
%   minimum moment that the EM can provide (max is an input to function)
% emoTrqMinPos = ...
%     lininterp1(par.emoSpdMgd(1,:)',par.emoTrqMin_emoSpd,crsSpd);
emoTrqMinPos = ...
    interp1q(fzg_array_struct.emoSpdMgd(1,:)',fzg_array_struct.emoTrqMin_emoSpd,crsSpd);

%% Verbrennungsmotor berechnen

% Durch EM zu lieferndes Kurbelwellenmoment
%   crankshaft torque to be delivered by the electric motor (min and max)
emoTrqMax = crsTrq - iceTrqMin;
emoTrqMin = crsTrq - iceTrqMax;
% fprintf('emoTrqMax: %4.3f\n', emoTrqMax);
% fprintf('emoTrqMin: %4.3f\n', emoTrqMin);
%% Elektromotor berechnen
%   calculate the electric motor

if emoTrqMaxPos < emoTrqMax
    % Moment des Elektromotors bei maximaler Entladung der Batterie
    %   EM torque at max battery discharge
    emoTrqMax = emoTrqMaxPos;
end

if emoTrqMaxPos < emoTrqMin 
    % Moment des Elektromotors bei minimaler Entladung der Batterie
    %   EM torque at min battery discharge
    emoTrqMin = emoTrqMaxPos;
end

emoTrqMax = max(emoTrqMinPos,emoTrqMax);
emoTrqMin = max(emoTrqMinPos,emoTrqMin);

%% Berechnung der änderung der Batterieladung
%   calculating the change in battery charge

% Interpolation der ben�tigten Batterieklemmleistung f�r das
% EM-Moment. Stellen die nicht definiert sind, werden mit inf
% ausgegeben. Positive Werte entsprechen entladen der Batterie.
%   interpolating the required battery terminal power for the EM torque.
%   Assign undefined values to inf. Positive values coresspond with battery
%   discharge.
% note - since input crs velocity and EM torque values can be used as
% vectors in this algorithm, a for loop must go through each vector element
% by element since the function codegen_interp2 only works with scalars
% inputs
% batPwrMax = zeros(length(crsSpd), 1);
% batPwrMin = zeros(length(crsSpd), 1);
batPwrMax = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
    fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMax) + batPwrAux;

batPwrMin = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
    fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMin) + batPwrAux;


% überprüfen, ob Batterieleistung möglich
%   make sure that current battery max power is not above bat max bounds
if batPwrMax > fzg_scalar_struct.batPwrMax
    batPwrMax = fzg_scalar_struct.batPwrMax;
end
% batPwrMax(batPwrMax > fzg_scalar_struct.batPwrMax) = fzg_scalar_struct.batPwrMax;

% überprüfen, ob Batterieleistung möglich
%   make sure that current battery min power is not above bat max bounds
if batPwrMin > fzg_scalar_struct.batPwrMax
    batPwrMin = fzg_scalar_struct.batPwrMax;
end
% batPwrMin(batPwrMin > fzg_scalar_struct.batPwrMax) = fzg_scalar_struct.batPwrMax;

% Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% m�glich ist.
%   check that the max and min still remain within the min bounds
if batPwrMax < fzg_scalar_struct.batPwrMin
    batPwrMax = fzg_scalar_struct.batPwrMin;
end
% batPwrMax(batPwrMax < fzg_scalar_struct.batPwrMin) = fzg_scalar_struct.batPwrMin;

if batPwrMin < fzg_scalar_struct.batPwrMin
    batPwrMin = fzg_scalar_struct.batPwrMin;
end
% batPwrMin(batPwrMin < fzg_scalar_struct.batPwrMin) = fzg_scalar_struct.batPwrMin;

% Batteriespannung aus Kennkurve berechnen
%   calculating battery voltage of characteristic curve - eq?--------------
batOcv = batEngAct*fzg_array_struct.batOcvCof_batEng(1,1) + fzg_array_struct.batOcvCof_batEng(1,2);

batEngDltMin = batFrcClc_a(     ... FUNCTION CALL - min delta bat.energy
    batPwrMax,                  ...Skalar - Batterieklemmleistung
    vehVel,                     ...Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar_struct.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar_struct.batRstChr,...Skalar - Ladewiderstand
    batOcv                      ...Skalar - battery open-circuit voltage 
    ) * timeStp; % <-multiply by delta_time

batEngDltMax = batFrcClc_a(     ... FUNCTION CALL - max delta bat.energy
    batPwrMin,                  ...Skalar - Batterieklemmleistung
    vehVel,                     ...Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar_struct.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar_struct.batRstChr,...Skalar - Ladewiderstand
    batOcv                      ...Skalar - battery open-circuit voltage 
    ) * timeStp;

end