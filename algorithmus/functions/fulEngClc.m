function [ fulEngDlt, ...Skalar - Kraftstoffverbrauch in J
    crsSpd, ...     Skalar f�r die mittlere Kurbelwellendrehzahl
    emoTrq, ...     Skalar f�r das Drehmoment des Elektromotors
    iceTrq, ...     Skalar f�r das Drehmoment des Verbrennungsmotors
    emoPwrEle, ...  Skalar f�r die Batterieleistung
    fulFrc ...      Skalar Kraftstoffkraft
    ] = ...
    fulEngClc...
    (wayStp,...     Skalar f�r die Wegschrittweite in m
    batPwrAux,...   Nebenverbraucherlast
    slp,...         Steigung der Fahrbahn in rad
    engKinPre,...   Skalar - kin. Energie am Anfang
    engKinAct,...   Skalar - kin. Energie am Ende
    batEngAct,...   Skalar - aktuelle Energie der Batterie
    batEngDlt, ...  Skalar - Batterieenergie�nderung
    gea,...         Skalar - aktueller Gang
    par...          struct der Fahrzeugparameter
    ) %#codegen
%
%FULENGCLC Calculating fuel consumption
% Erstellungsdatum der ersten Version 04.09.2015 - Stephan Uebel
% Diese Funktion berechnet den Kraftstoffverbrauch f�r einen gegebenen
% Wegschritt der kinetischen Energie, der Batterieenergie und des
% Antriebsstrangzustands �ber dem Weg.

% Version vom 17.02.2016 : Rotationsmassen vernachl�ssigt

% Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit)

%% Initialisieren der Ausgabe der Funktion

% Initialisieren der Krafstoffenergie�nderung
fulEngDlt = inf;

% Initialisieren mittlere Kurbelwellendrehzahl
crsSpd = inf;

% Initialisieren Drehmoment des Elektromotors
emoTrq = inf;

% Initialisieren Drehmoment des Verbrennungsmotors
iceTrq = inf;

% Initialisieren Batterieleistung
emoPwrEle = inf;

% Initialisieren Kraftstoffkraft
fulFrc = inf;

%% Initialisieren der persistent Gr��en
% Diese werden die nur einmal f�r die Funktion berechnet

persistent crsSpdHybMax crsSpdHybMin

if isempty(crsSpdHybMax)
    
    % maximale Drehzahl der Kurbelwelle
    crsSpdHybMax = min(par.iceSpdMgd(1,end),par.emoSpdMgd(1,end));
    
    % minimale Drehzahl der Kurbelwelle
    crsSpdHybMin = par.iceSpdMgd(1,1);
    
end

%% vorzeitiger Funktionsabbruch?
% Drehzahl der Kurbelwelle und Grenzen

% Aus den kinetischen Energien des Fahrzeugs wird �ber die Raddrehzahl
% und die �bersetzung vom Getriebe die Kurbelwellendrehzahl berechnet.
% Zeilenrichtung entspricht den G�ngen. (Zeilenvektor)
crsSpdVec = par.geaRat(gea) * ...
    sqrt(2*[engKinPre,engKinAct]/par.vehMas) / (par.whlDrr);

% Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen
% Modus
if any(crsSpdVec > crsSpdHybMax)
    return;
end

% Falls die Drehzahl des Verbrennungsmotors niedriger als die
% Leerlaufdrehzahl ist,
if any(crsSpdVec < crsSpdHybMin)
    return;
    %         % wird sie auf die Leerlaufdrehzahl gesetzt
    %         % Das ist eine einfache Weise eine schlupfende Kupplung zu
    %         %simulieren
    %         if crsSpdVec(1) < crsSpdHybMin
    %             crsSpdVec(1) = crsSpdHybMin;
    %         end
    %         if crsSpdVec(2) < crsSpdHybMin
    %             crsSpdVec(2) = crsSpdHybMin;
    %         end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% mittlere Kurbelwellendrehzahlen berechnen
% crsSpd = mean(crsSpdVec);
crsSpd = crsSpdVec(1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% L�ngsdynamik berechnen
% Es wird eine konstante Beschleunigung angenommen, die im
% Wegschritt wayStpOut das Fahrzeug beschleunigt.

% Geschwindigkeit im Wegschritt berechnen
vel = sqrt( 2 * engKinPre / par.vehMas );

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

% % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das
% % hei�t es werden Tr�gheitsmoment von Verbrennungsmotor,
% % Elektromotor und R�dern mit einbezogen.
% vehMasDyn = (par.iceMoi_geaRat(gea) +...
%     par.emoGeaMoi_geaRat(gea) + par.whlMoi)/par.whlDrr^2 ...
%     + par.vehMas;

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

%% Batterie

% Batterieenergie�nderung �ber dem Weg (Batteriekraft)
batFrc = batEngDlt / wayStp;
% Batteriespannung aus Kennkurve berechnen
batOcv = batEngAct*par.batOcvCof_batEng(1,1) ...
    + par.batOcvCof_batEng(1,2);
% Fallunterscheidung, ob Batterie geladen oder entladen wird
if batFrc < 0
    batRst = par.batRstDch;
else
    batRst = par.batRstChr;
end
% elektrische Leistung des Elektromotors
emoPwrEle = -batFrc * vel ... innere Batterieleistung
    - batFrc^2 * vel^2 / batOcv^2 * batRst...dissipat. Leist.
    - batPwrAux; ... Nebenverbrauchlast
    
%% Elektromotor

% Ermitteln des Kurbelwellenmoments durch EM aus Batterieleistung
emoTrq = codegen_interp2(par.emoSpdMgd,par.emoPwrMgd,...
    par.emoTrq_emoSpd_emoPwr,crsSpd,emoPwrEle);

if isinf(emoTrq)
    return;
end

% Grenzen des Elektromotors m�ssen hier nicht �berpr�ft werden, da die
% Ladungsdeltas schon so gew�hlt wurden, dass das maximale Motormoment
% nicht �berstiegen wird.


%% Verbrennungsmotor

% Ermitteln des Kurbelwellenmoments durch den Verbrennungsmotor
iceTrq = crsTrq - emoTrq;

% minimales Moment des Verbrennungsmotors berechnen
iceTrqMin = par.iceTrqMinCof(1) * crsSpd^2 ...
    + par.iceTrqMinCof(2) * crsSpd ...
    + par.iceTrqMinCof(3);

% maximales Moment des Verbrennungsmotors berechnen
iceTrqMax = par.iceTrqMaxCof(1) * crsSpd^2 ...
    + par.iceTrqMaxCof(2) * crsSpd ...
    + par.iceTrqMaxCof(3);

% Wenn das Verbrennungsmotormoment kleiner als das minimale
% Moment ist, ist dieser in der Schubabschaltung. Das
% verbleibende Moment liefern die Bremsen
if iceTrq < iceTrqMin
    fulPwr = 0;
elseif iceTrq > iceTrqMax
    fulPwr = inf;
else
    fulPwr = codegen_interp2(par.iceSpdMgd,par.iceTrqMgd,...
        par.iceFulPwr_iceSpd_iceTrq,crsSpd,iceTrq);
end

% Berechnen der Kraftstoffkraft
fulFrc = fulPwr/vel;

% Berechnen der Kraftstoffvolumen�nderung
fulEngDlt = fulFrc * wayStp;





%% Ende der Funktion
end

