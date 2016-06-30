function [ ...
    batEngDltMin,...Skalar - änderung der minimalen Batterieenergieänderung
    batEngDltMax... Skalar - änderung der maximalen Batterieenergieänderung
    ] = ...
    batEngDltClc...
    (...
    engKinPre,...   Skalar - kin. Energie der Vorg�ngers
    engKinAct,...   Skalar - kin. Energie
    wayStp,...      Skalar - Wegschrittweite
    gea,...         Skalar - Gang
    slp,...         Skalar - Steigung
    vel,...         Skalar - Geschwindigkeit im Intervall
    batPwrAux,...   Skalar - Nebenverbraucherlast
    batEngAct,...   Skalar - Batterieenergie
    par...          struct - Fahrzeugparameter
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

%% Initialisieren der persistent Größen
%   initializing the persisting sizes
% Diese werden die nur einmal für die Funktion berechnet
%   these are only calculated once for the function

persistent crsSpdEmoMax

if isempty(crsSpdEmoMax)
    
    % maximale Drehzahl Elektrommotor
    % maximum electric motor number of revolutions
    crsSpdEmoMax = par.emoSpdMgd(1,end);
    
end


%% vorzeitiger Funktionsabbruch?
%   prematrue function termination?
% Drehzahl der Kurbelwelle und Grenzen
%   Crankshaft speed and limits

% Aus den kinetischen Energien des Fahrzeugs wird über die Raddrehzahl
% und die übersetzung vom Getriebe die Kurbelwellendrehzahl berechnet.
% Zeilenrichtung entspricht den Gängen. (Zeilenvektor)
%   the crankshaft speed can be calculated from the vehicle's kinetic
%   energy (from the translational speed) and the gear.
%   row direction corresponding to gears (row vector)
crsSpdVec = par.geaRat(gea) * ...
    sqrt(2*[engKinPre,engKinAct]/par.vehMas) / (par.whlDrr); % rad/s

% Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
if any(crsSpdVec > crsSpdEmoMax)
    return;
end

% mittlere Kurbelwellendrehzahlen berechnen
crsSpd = crsSpdVec(1);

%% L�ngsdynamik berechnen
% Es wird eine konstante Beschleunigung angenommen, die im Wegschritt
% wayStp das Fahrzeug von velPre auf velAct beschleunigt.

% Berechnen der konstanten Beschleunigung
vehAcc = (engKinAct - engKinPre) / (par.vehMas*wayStp);

% Aus der mittleren kinetischen Energie im Intervall, der mittleren
% Steigung und dem Gang l�sst sich �ber die Fahrwiderstandsgleichung
% die n�tige Fahrwiderstandskraft berecnen, die aufgebracht werden
% muss, um diese zu realisieren.

% Steigungskraft aus der mittleren Steigung berechnen (Skalar)
vehFrcSlp = par.vehMas * 9.81 * sin(slp);

% Rollreibungskraft berechnen (Skalar)
vehFrcRol = par.whlRolResCof*par.vehMas * 9.81 * cos(slp);

% Luftwiderstandskraft berechnen (2*c_a/m * E_kin) (Skalar)
vehFrcDrg = 2*par.drgCof/par.vehMas*engKinPre;


%% Elektromotor

% minimales Moment, dass die E-Maschine liefern kann
emoTrqMinPos = ...
    interp1q(par.emoSpdMgd(1,:)',par.emoTrqMin_emoSpd,crsSpd);

% maximales Moment, dass die E-Maschine liefern kann
emoTrqMaxPos = ...
    interp1q(par.emoSpdMgd(1,:)',par.emoTrqMax_emoSpd,crsSpd);

%% Berechnen der Kraft am Rad f�r Antriebsstrangmodus

% % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das
% % hei�t es werden Tr�gheitsmoment von Verbrennungsmotor,
% % Elektromotor und R�dern mit einbezogen.
% vehMasDyn = (par.emoGeaMoi_geaRat(gea) + par.whlMoi)...
%     /par.whlDrr^2 + par.vehMas;

% Radkraft berechnen (Beschleunigungskraft + Steigungskraft +
% Rollwiderstandskraft + Luftwiderstandskraft)
whlFrc  = vehAcc*par.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;

%% Getriebe�bersetzung und -verlust

% Das Drehmoment des Rades ergibt sich �ber den Radhalbmesser aus
% der Fahrwiderstandskraft.
whlTrq = whlFrc*par.whlDrr;

% Berechnung des Kurbelwellenmoments
% Hier muss unterschieden werden, ob das Radmoment positiv oder
% negativ ist, da nur ein einfacher Wirkungsgrad f�r das Getriebe
% genutzt wird
if whlTrq < 0
    crsTrq = whlTrq / par.geaRat(gea) * par.geaEfy;
else
    crsTrq = whlTrq / par.geaRat(gea) / par.geaEfy;
end


%% Verbrennungsmotor berechnen

% maximales Moment des Verbrennungsmotors berechnen
iceTrqMax = par.iceTrqMaxCof(1) * crsSpd^2 ...
    + par.iceTrqMaxCof(2) * crsSpd ...
    + par.iceTrqMaxCof(3);

% minimales Moment des Verbrennungsmotors berechnen
iceTrqMin = par.iceTrqMinCof(1) * crsSpd^2 ...
    + par.iceTrqMinCof(2) * crsSpd ...
    + par.iceTrqMinCof(3);

% Durch EM zu lieferndes Kurbelwellenmoment
emoTrqMax = crsTrq - iceTrqMin;
emoTrqMin = crsTrq - iceTrqMax;

%% Elektromotor berechnen

if emoTrqMaxPos < emoTrqMax
    % Moment des Elektromotors bei maximaler Entladung der Batterie
    emoTrqMax = emoTrqMaxPos;
end

if emoTrqMaxPos < emoTrqMin
    % Moment des Elektromotors bei maximaler Entladung der Batterie
    emoTrqMin = emoTrqMaxPos;
end

% Moment des Elektromotors bei minimaler Entladung der Batterie
emoTrqMax = max(emoTrqMinPos,emoTrqMax);
emoTrqMin = max(emoTrqMinPos,emoTrqMin);


%% Berechnung der �nderung der Batterieladung

% Interpolation der ben�tigten Batterieklemmleistung f�r das
% EM-Moment. Stellen die nicht definiert sind, werden mit inf
% ausgegeben. Positive Werte entsprechen entladen der Batterie.
batPwrMax = codegen_interp2(par.emoSpdMgd,par.emoTrqMgd,...
    par.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMax) + batPwrAux;

batPwrMin = codegen_interp2(par.emoSpdMgd,par.emoTrqMgd,...
    par.emoPwr_emoSpd_emoTrq,crsSpd,emoTrqMin) + batPwrAux;

% �berpr�fen, ob Batterieleistung m�glich
if batPwrMax > par.batPwrMax
    batPwrMax = par.batPwrMax;
end

% �berpr�fen, ob Batterieleistung m�glich
if batPwrMin > par.batPwrMax
    batPwrMin = par.batPwrMax;
end

% Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% m�glich ist.
if batPwrMax < par.batPwrMin
    batPwrMax = par.batPwrMin;
end

if batPwrMin < par.batPwrMin
    batPwrMin = par.batPwrMin;
end

batEngDltMin = batFrcClc(...
    batEngAct,...Skalar - Batterieenergie
    batPwrMax,...Skalar - Batterieklemmleistung
    vel,...Skalar - mittlere Geschwindigkeit im Intervall
    par.batRstDch,...Skalar - Entladewiderstand
    par.batRstChr,...Skalar - Ladewiderstand
    par.batOcvCof_batEng...Vektor - Koeffizienten f�r Ruhespannung der Bat
    ) * wayStp;

batEngDltMax = batFrcClc(...
    batEngAct,...Skalar - Batterieenergie
    batPwrMin,...Skalar - Batterieklemmleistung
    vel,...Skalar - mittlere Geschwindigkeit im Intervall
    par.batRstDch,...Skalar - Entladewiderstand
    par.batRstChr,...Skalar - Ladewiderstand
    par.batOcvCof_batEng...Vektor - Koeffizienten f�r Ruhespannung der Bat
    ) * wayStp;

end