function [cosHamMin,batFrcOut,fulFrcOut] = ...
    clcPMP_olyHyb_port(engKinPre,engKinAct,gea,slp,iceFlg,batEng,psiBatEng,...
                  psiTim, batPwrAux,batEngStp,wayStp,fzg_scalar,fzg_array)
%#codegen
%CLCPMP Minimizing Hamiltonian: Co-States for soc and time
% Erstellungsdatum der ersten Version 19.08.2015 - Stephan Uebel
%
% Batterieleistungsgrenzen hinzugefügt am 13.12.2015
% ^^added battery power limit
%
% Massenaufschlag durch Trägheitsmoment herausgenommen
% ^^Mass increment removed by inertia
%
%% Inputdefinition
%
% engKinPre     - Double(1,1)  - kinetische Energie am Intervallanfang in J
%                                ^^ kinetic energy at start of interval (J)
% engKinAct     - Double(1,1)  - kinetische Energie am Intervallende in J
%                                ^^ kinetic energe at end of interval (J)
% gea           - Double(1,1)  - Gang
%                                ^^ gear
% slp           - Double(1,1)  - Steigung in rad
%                                ^^ slope in radians
% iceFlg        - Boolean(1,1) - Flag für Motorzustand
%                                ^^ flag for motor condition
% batEng        - Double(1,1)  - Batterieenergie in J
%                                ^^ battery energy (J)
% psibatEng     - Double(1,1)  - Costate für Batterieenergie ohne Einheit
%                                ^^ costate for battery energy w/o unity
% psiTim        - Double(1,1)  - Costate für die Zeit ohne Einheit
%                                ^^ costate for time without unity
% batPwrAux     - Double(1,1)  - elektr. Nebenverbraucherleistung in W
%                                ^^ electric auxiliary power consumed (W)
% batEngStp     - Double(1,1)  - Drehmomentschritt
%                                ^^ torque step <- no, it's a battery step
% wayStp        - Double(1,1)  - Intervallschrittweite in m
%                                ^^ interval step distance (m)
% fzg_scalar    - Struct(1,1)  - Modelldaten - nur skalar
% fzg_array     - Struct(1,1)  - Modelldaten _ nur arrays                             

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

% Ausgabewert des Minimums der Hamiltonfunktion
%   output for minimizing the hamiltonian
cosHamMin = inf;
% Batterieladungsänderung im Wegschritt beir minimaler Hamiltonfunktion
%   battery change in path_idx step with the minial hamiltonian
batFrcOut = inf;
% Kraftstoffkraftänderung im Wegschritt bei minimaler Hamiltonfunktion
%   fuel change in path_idx step with the minimal hamiltonian
fulFrcOut = 0;

%% Initialisieren der persistent Größen
%   initialize the persistance variables

% Diese werden die nur einmal für die Funktion berechnet
%   only calculated once for the function

persistent crsSpdHybMax crsSpdHybMin crsSpdEmoMax

if isempty(crsSpdHybMax)
    
    % maximale Drehzahl Elektrommotor
    %   maximum electric motor rotational speed
    crsSpdEmoMax = fzg_array.emoSpdMgd(1,end);
    
    % maximale Drehzahl der Kurbelwelle
    %   maximum crankshaft rotational speed
    crsSpdHybMax = min(fzg_array.iceSpdMgd(1,end),crsSpdEmoMax);
    
    % minimale Drehzahl der Kurbelwelle
    %   minimum crankshaft rotational speed
    crsSpdHybMin = fzg_array.iceSpdMgd(1,1);
    
end

%% Initialisieren der allgemein benötigten Kenngrößen
%   initializing the commonly required parameters

% mittlere kinetische Energie im Wegschritt berechnen
%   define the average kinetic energy at path_idx step - is just previous KE
engKin = engKinPre;
% mittlere Geschwindigkeit im Wegschritt berechnen
%   define the average speed at path_idx step
vehVel = sqrt( 2 * engKin / fzg_scalar.vehMas );

%% vorzeitiger Funktionsabbruch?
%   premature function termination?
% Drehzahl der Kurbelwelle und Grenzen
%   crankshaft speed and limits

% Aus den kinetischen Energien des Fahrzeugs wird über die Raddrehzahl
% und die übersetzung vom Getriebe die Kurbelwellendrehzahl berechnet.
% Zeilenrichtung entspricht den Gängen. (Zeilenvektor)
%   from the vehicle's kinetic energy, the crankshaft speed is calculated
%   by the speed and gearbox translation. Line direction corresponding to
%   the aisles (row rector). EQUATION 1
crsSpdVec = fzg_array.geaRat(gea) * ...
    sqrt(2*[engKinPre,engKinAct]/fzg_scalar.vehMas) / (fzg_scalar.whlDrr);

% Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen
% Modus
%   stop if the crankshaft rotatoinal speed is too high in hybrid mode
if iceFlg && any(crsSpdVec > crsSpdHybMax)
    return;
end

% Falls die Drehzahl des Verbrennungsmotors niedriger als die
% Leerlaufdrehzahl ist,
%   stop if crankhaft rotional speed is lower than the idling speed
if iceFlg && any(crsSpdVec < crsSpdHybMin)
    return;
end

% Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
%   check if electric motor speed limit is maintained
if ~iceFlg && any(crsSpdVec > crsSpdEmoMax)
    return;
end

% mittlere Kurbelwellendrehzahlen berechnen
%   calculate average crankshaft rotational speed
%   - really just selecting the previous path_idx KE crankshaft speed
crsSpd = crsSpdVec(1);

%% Längsdynamik berechnen
%   calculate longitundinal dynamics
% Es wird eine konstante Beschleunigung angenommen, die im Wegschritt
% wayStp das Fahrzeug von velPre auf velAct beschleunigt.
%   constant acceleration assumed when transitioning from velPre to velAct
%   for the selected wayStp path_idx step distance

% Berechnen der konstanten Beschleunigung
%   calculate the constant acceleration
vehAcc = (engKinAct - engKinPre) / (fzg_scalar.vehMas*wayStp);

% Aus der mittleren kinetischen Energie im Intervall, der mittleren
% Steigung und dem Gang lässt sich über die Fahrwiderstandsgleichung
% die nötige Fahrwiderstandskraft berechnen, die aufgebracht werden
% muss, um diese zu realisieren.
%   from the (avg) kinetic energy in the interval, the (avg) slope and
%   transition can calculate the necessary traction force on the driving
%   resistance equation (PART OF EQUATION 5)

% Steigungskraft aus der mittleren Steigung berechnen (Skalar)
%   gradiant force from the calculated (average) gradient
vehFrcSlp = fzg_scalar.vehMas * 9.81 * sin(slp);

% Rollreibungskraft berechnen (Skalar)
%   calculated rolling friction force - not included in EQ 5???
vehFrcRol = fzg_scalar.whlRosResCof*fzg_scalar.vehMas * 9.81 * cos(slp);

% Luftwiderstandskraft berechnen (2*c_a/m * E_kin) (Skalar) 
%   calculated air resistance force 
vehFrcDrg = 2*fzg_scalar.drgCof/fzg_scalar.vehMas*engKin;

%% Berechnung der minimalen kosten der Hamiltonfunktion
%   Calculating the minimum cost of the Hamiltonian

%% Berechnen der Kraft am Rad für Antriebsstrangmodus
%   calculate the force on the wheel for the drivetrain mode

% % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das
% % heißt es werden Trägheitsmoment von Verbrennungsmotor,
% % Elektromotor und Rädern mit einbezogen.
%   calculate dynamic vehicle mass with the vehicle engine (with the moment
%   of intertia of the ICE, electric motor, and wheels)
% vehMasDyn = (par.iceMoi_geaRat(gea) +...
%     par.emoGeaMoi_geaRat(gea) + par.whlMoi)/par.whlDrr^2 ...
%     + par.vehMas;

% Radkraft berechnen (Beschleunigungskraft + Steigungskraft +
% Rollwiderstandskraft + Luftwiderstandskraft)
%   caluclating wheel forces (accerlation force + gradient force + rolling
%   resistance + air resistance)    EQUATION 5
whlFrc  = vehAcc*fzg_scalar.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;

%% Getriebeübersetzung und -verlust
%   gear ratio and loss

% Das Drehmoment des Rades ergibt sich über den Radhalbmesser aus
% der Fahrwiderstandskraft.
%   the weel torque is obtained from the wheel radius of the rolling
%   resistance force (torque = force * distance (in this case, radius)
whlTrq = whlFrc*fzg_scalar.whlDrr;

% Berechnung des Kurbelwellenmoments
% Hier muss unterschieden werden, ob das Radmoment positiv oder
% negativ ist, da nur ein einfacher Wirkungsgrad für das Getriebe
% genutzt wird
%   it's important to determine sign of crankshaft torque (positive or
%   negative), since only a simple efficiency is used for the transmission
%   PART OF EQ4  <- perhaps reversed? not too sure
if whlTrq < 0
    crsTrq = whlTrq / fzg_array.geaRat(gea) * fzg_scalar.geaEfy;
else
    crsTrq = whlTrq / fzg_array.geaRat(gea) / fzg_scalar.geaEfy;
end

%% Verbrennungsmotor
%   internal combustion engine

% maximales Moment des Verbrennungsmotors berechnen
%   calculate max torque of the engine (quadratic based on rotation speed)
iceTrqMax = fzg_array.iceTrqMaxCof(1) * crsSpd^2 ...
    + fzg_array.iceTrqMaxCof(2) * crsSpd ...
    + fzg_array.iceTrqMaxCof(3);

% minimales Moment des Verbrennungsmotors berechnen
%   calculating mimimum ICE moment
iceTrqMin = fzg_array.iceTrqMinCof(1) * crsSpd^2 ...
    + fzg_array.iceTrqMinCof(2) * crsSpd ...
    + fzg_array.iceTrqMinCof(3);

%% Elektromotor
%   electric motor

% maximales Moment, dass die E-Maschine liefern kann
%   max torque that the electric motor can provide - from interpolation
% emoTrqMaxPos = ...
%     lininterp1(par.emoSpdMgd(1,:)',par.emoTrqMax_emoSpd,crsSpd);
emoTrqMaxPos = ...
    interp1q(fzg_array.emoSpdMgd(1,:)',fzg_array.emoTrqMax_emoSpd,crsSpd);

% Die gültigen Kurbelwellenmomente müssen kleiner sein als das
% Gesamtmoment von E-Motor und Verbrennungsmotor
%   The valid crankshaft moments must be less than the total moment of the
%   electric motor and the ICE.Otherwise, leave the function
if crsTrq > iceTrqMax + emoTrqMaxPos; 
    return;
end

%% %% Optimaler Momentensplit - Minimierung der Hamiltonfunktion
%       optimum torque split - minimizing the Hamiltonian
% Die Vorgehensweise ist ähnlich wie bei der ECMS. Es wird ein Vektor der
% möglichen Batterieenergieänderungen aufgestellt. Aus diesen lässt sich 
% eine Batterieklemmleistung berechnen. Aus der über das
% Kurbelwellenmoment, ein Elektromotormoment berechnet werden kann.
% Über das geforderte Kurbelwellenmoment, kann für jedes Moment des 
% Elektromotors ein Moment des Verbrennungsmotors gefunden werden. Für 
% jedes Momentenpaar kann die Hamiltonfunktion berechnet werden.
% Ausgegeben wird der minimale Wert der Hamiltonfunktion und die
% durch das dabei verwendete Elektromotormoment verursachte
% Batterieladungsänderung.
%   The procedure is similar to ECMS. It's based on a vector of possible
%   battery energy changes, from which a battery terminal power can be
%   calculated.
%   From the crankshaft torque, an electric motor torque can be
%   calculated, and an engine torque can be found for every electric motor
%   moment. 
%   For every moment-pair the Hamiltonian can be calculated. It
%   outputs the minimum Hamilotnian value and the battery charge change
%   caused by the electric motor torque used.


%% Elektromotor - Aufstellen des Batterienergievektors
%   electric motor - positioning the battery energy vectors

if batEngStp > 0
    [ ...
        batEngDltMin,...Skalar - änderung der minimalen Batterieenergieänderung
        batEngDltMax... Skalar - änderung der maximalen Batterieenergieänderung
        ] = ...
        batEngDltClc_port... FUNCTION CALL
        (...
        wayStp,...      Skalar - Wegschrittweite
        vehVel,...      Skalar - mittlere Geschwindigkeit im Intervall
        batPwrAux,...   Skalar - Nebenverbraucherlast
        batEng,...      Skalar - Batterieenergie
        fzg_scalar,...  struct - Fahrzeugparameter - nur skalar
        fzg_array,...   struct - Fahrzeugparameter - nur array
        crsSpd,...      Skalar - crankshaft rotational speed
        crsTrq,...      Skalar - crankshaft torque
        iceTrqMin,...   Skalar - min ICE torque allowed
        iceTrqMax,...   Skalar - max ICE torque allowed
        emoTrqMaxPos... Skalar - max EM torque possible
        );
    
    % Es werden 2 Fälle unterschieden:
    %   there are 2 different cases
    if batEngDltMin > 0 && batEngDltMax > 0 % battery will discharge
        
        %% konventionelles Bremsen + Rekuperieren
        %   conventional brakes + recuperation
        %
        % set change in energy to discretized integer values w/ ceil and
        % floor. This also helps for easy looping

        % Konventionelles Bremsen wird ebenfalls untersucht.
        % Hier liegt eventuell noch Beschleunigungspotential, da diese
        % Zustandswechsel u.U. ausgeschlossen werden können.
        % NOTE: u.U. = unter Ümständen = circumstances permitting
        %   convetional breaks also investigated. An accelerating potential
        %   is still possible, as these states can be excluded
        %   (circumstances permitting)  <- ??? not sure what above means
        %
        %   so if both min and max changes in battery energy are
        %   increasing, then set the delta min to zero
        batEngDltMinInx = 0;
        batEngDltMaxInx = floor(batEngDltMax/batEngStp);

    else        
        batEngDltMinInx = ceil(batEngDltMin/batEngStp);
        batEngDltMaxInx = floor(batEngDltMax/batEngStp);
    end
else
    batEngDltMinInx = 0;
    batEngDltMaxInx = 0;
end

% you got a larger min change than a max change-you're out of bounds. Leave
% the function
if batEngDltMaxInx < batEngDltMinInx
    return;
end

%% Schleife über alle Elektromotormomente
%   now loop through all the electric-motor torques
% why isn't batEngDltInx discretized wrt batEngStp??
for batEngDltInx = batEngDltMinInx:batEngDltMaxInx 
    batEngDlt = batEngDltInx * batEngStp;
    batEngAct = batEng + batEngDlt;
    % open circuit voltage over each iteration
    batOcv = batEngAct*fzg_array.batOcvCof_batEng(1,1)+fzg_array.batOcvCof_batEng(1,2);
    
    [ ...
        batPwr,...          Skalar für die Batterieleistung in W
        fulFrc ...          Skalar Krafstoffkraft in N
        ] = ...
        fulEngClc_port...            FUNCTION CALL
        (wayStp,...         Skalar für die Wegschrittweite in m,
        vehVel,...          Skalar - vehicular velocity
        batPwrAux,...       Nebenverbraucherlast
        batOcv,...          Skalar - battery open circuit voltage
        batEngDlt, ...      Skalar - Batterieenergie�nderung,
        crsSpd,...          Skalar - crankshaft speed at given path_idx
        crsTrq,...          Skalar - crankshaft torque at given path_idx
        iceTrqMin,...       Skalar - min ICE torque allowed
        iceTrqMax,...       Skalar - max ICE torque
        fzg_scalar,...      struct - Fahrzeugparameter - nur skalar
        fzg_array...        struct - Fahrzeugparameter - nur array        
        );
    
    batFrc = batFrcClc_port(...      FUNCTION CALL
        batPwr,...          Skalar - Batterieklemmleistung
        vehVel,...          Skalar - mittlere Geschwindigkeit im Intervall
        fzg_scalar.batRstDch,...   Skalar - Entladewiderstand
        fzg_scalar.batRstChr,...   Skalar - Ladewiderstand
        batOcv...           Skalar - battery open circuit voltage
        );    
    
    %% Hamiltonfunktion bestimmen
    %   determine the hamiltonian
    % Eq (29b)
    [cosHamMin,optPreInx] = min([fulFrc ...
        + psiBatEng * batFrc...
        + psiTim / vehVel,cosHamMin]);
    
    % Wenn der aktuelle Punkt besser ist, als der in cosHamMin
    % gespeicherte Wert, werden die Ausgabegrößen neu beschrieben.
    %   if the current point is better than the stored cosHamMin value,
    %   then the output values are rewritten (selected prev. value is = 2)
    if optPreInx == 1
        batFrcOut = batFrc;
        fulFrcOut = fulFrc;
    end
    
end

end % end of function