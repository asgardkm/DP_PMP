function [ ...
    batEngDltMin,...Skalar - änderung der minimalen Batterieenergieänderung
    batEngDltMax... Skalar - änderung der maximalen Batterieenergieänderung
    ] =         ...
    batEngDltClc_port...
    (           ...
    wayStp,     ... Skalar - Wegschrittweite
    vel,        ... Skalar - Geschwindigkeit im Intervall
    batPwrAux,  ... Skalar - Nebenverbraucherlast
    batEngAct,  ... Skalar - Batterieenergie
    fzg_scalar, ... struct - Fahrzeugparameter - nur skalar
    fzg_array,  ... struct - Fahrzeugparameter - nur array
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
    interp1q(fzg_array.emoSpdMgd(1,:)',fzg_array.emoTrqMin_emoSpd,crsSpd);

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

% Interpolation der benötigten Batterieklemmleistung f�r das
% EM-Moment. Stellen die nicht definiert sind, werden mit inf
% ausgegeben. Positive Werte entsprechen entladen der Batterie.
%   interpolating the required battery terminal power for the EM torque.
%   Assign undefined values to inf. Positive values coresspond with battery
%   discharge.
% batPwrMax = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),...
%     par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMax) + batPwrAux;
% 
% batPwrMin = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),...
%     par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMin) + batPwrAux;
batPwrMax = codegen_interp2(fzg_array.emoSpdMgd,fzg_array.emoTrqMgd,...
    fzg_array.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMax) + batPwrAux;

batPwrMin = codegen_interp2(fzg_array.emoSpdMgd,fzg_array.emoTrqMgd,...
    fzg_array.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMin) + batPwrAux;

% überprüfen, ob Batterieleistung möglich
%   make sure that current battery max power is not above bat max bounds
if batPwrMax > fzg_scalar.batPwrMax
    batPwrMax = fzg_scalar.batPwrMax;
end

% überprüfen, ob Batterieleistung möglich
%   make sure that current battery min power is not below bat min bounds

if batPwrMin > fzg_scalar.batPwrMax
    batPwrMin = fzg_scalar.batPwrMax;
end

% Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% m�glich ist.
%   double check that the max and min still remain within the other bounds
if batPwrMax < fzg_scalar.batPwrMin
    batPwrMax = fzg_scalar.batPwrMin;
end

if batPwrMin < fzg_scalar.batPwrMin
    batPwrMin = fzg_scalar.batPwrMin;
end

% Batteriespannung aus Kennkurve berechnen
%   calculating battery voltage of characteristic curve - eq?--------------
batOcv = batEngAct*fzg_array.batOcvCof_batEng(1,1) + fzg_array.batOcvCof_batEng(1,2);

batEngDltMin = batFrcClc_port(... FUNCTION CALL - min delta bat.energy
    batPwrMax,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar.batRstChr,...Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * wayStp; % <-multiply by delta_S

batEngDltMax = batFrcClc_port(... FUNCTION CALL - max delta bat.energy
    batPwrMin,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar.batRstChr,...Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * wayStp;

end