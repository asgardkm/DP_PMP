function [ ...
    batEngDltMin,...Skalar - änderung der minimalen Batterieenergieänderung
    batEngDltMax... Skalar - änderung der maximalen Batterieenergieänderung
    ] = ...
    batEngDltClc_port...
    (...
    wayStp,...      Skalar - Wegschrittweite
    vel,...         Skalar - Geschwindigkeit im Intervall
    batPwrAux,...   Skalar - Nebenverbraucherlast
    batEngAct,...   Skalar - Batterieenergie
    par,...         struct - Fahrzeugparameter
    crsSpd,...      Skalar - crankshaft rotational speed
    crsTrq,...      Skalar - crankshaft torque
    iceTrqMin,...   Skalar - min ICE torque allowed
    iceTrqMax,...   Skalar - max ICE torque
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
    interp1q(par.emoSpdMgd(1,:)',par.emoTrqMin_emoSpd,crsSpd);

%% Verbrennungsmotor berechnen

% Durch EM zu lieferndes Kurbelwellenmoment
%   crankshaft torque to be delivered by the electric motor (min and max)
emoTrqMax = crsTrq - iceTrqMin;
emoTrqMin = crsTrq - iceTrqMax;

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

% Interpolation der benötigten Batterieklemmleistung für das
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
batPwrMax = codegen_interp2(par.emoSpdMgd,par.emoTrqMgd,...
    par.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMax) + batPwrAux;

batPwrMin = codegen_interp2(par.emoSpdMgd,par.emoTrqMgd,...
    par.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMin) + batPwrAux;

% überprüfen, ob Batterieleistung möglich
%   make sure that current battery max power is not above bat max bounds
if batPwrMax > par.batPwrMax
    batPwrMax = par.batPwrMax;
end

% überprüfen, ob Batterieleistung möglich
%   make sure that current battery min power is not below bat min bounds

if batPwrMin > par.batPwrMax
    batPwrMin = par.batPwrMax;
end

% Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% möglich ist.
%   double check that the max and min still remain within the other bounds
if batPwrMax < par.batPwrMin
    batPwrMax = par.batPwrMin;
end

if batPwrMin < par.batPwrMin
    batPwrMin = par.batPwrMin;
end

% Batteriespannung aus Kennkurve berechnen
%   calculating battery voltage of characteristic curve - eq?--------------
batOcv = batEngAct*par.batOcvCof_batEng(1,1) + par.batOcvCof_batEng(1,2);

batEngDltMin = batFrcClc_port(... FUNCTION CALL - min delta bat.energy
    batPwrMax,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    par.batRstDch,...       Skalar - Entladewiderstand
    par.batRstChr,...       Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * wayStp; % <-multiply by delta_S

batEngDltMax = batFrcClc_port(... FUNCTION CALL - max delta bat.energy
    batPwrMin,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    par.batRstDch,...       Skalar - Entladewiderstand
    par.batRstChr,...       Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * wayStp;

end