function [fulEng, emoTrq, iceTrq, brkTrq] = ...
    optTrqSplit_focus(          ...
            engStaPre,          ...
            gea,                ...
            batStaDlt,          ...
            batStaPre,          ...
            batPwrAux,          ...
            timeStp,            ...
            vehVelVec,          ...
            whlTrqPre,          ...
            fzg_scalar_struct,  ...
            fzg_array_struct)
%#codegen
%CLCPMP Minimizing Hamiltonian: Co-States for soc and time
% Erstellungsdatum der ersten Version 19.08.2015 - Stephan Uebel
%
% Batterieleistungsgrenzen hinzugef√ºgt am 13.12.2015
% ^^added battery power limit
%
% Massenaufschlag durch Tr√§gheitsmoment herausgenommen
% ^^Mass increment removed by inertia
%
% % 06.07.2016 - replacing KE state dimension with engine control
% is not necessarily PMP anymore, function is just now an objective
% minimaztion function for each DP state permutation. No costates are
% calculated.
%% Inputdefinition
% engStaPre     - Double(1,1)  - engine state at start of interval (J)
% engStaAct     - Double(1,1)  - engine state at end of interval (J)
% gea           - Double(1,1)  - Gang
%                                ^^ gear
% slp           - Double(1,1)  - Steigung in rad
%                                ^^ slope in radians
% iceFlg        - Boolean(1,1) - Flag f√ºr Motorzustand-REMOVED 12.07.2016
%                                ^^ flag for motor condition
% batEng        - Double(1,1)  - Batterieenergie in J
%                                ^^ battery energy (J)
% batPwrAux     - Double(1,1)  - elektr. Nebenverbraucherleistung in W
%                                ^^ electric auxiliary power consumed (W)
% batEngStp     - Double(1,1)  - Drehmomentschritt
%                                ^^ torque step <- no, it's a battery step
% timeStp        - Double(1,1)  - Intervallschrittweite in m
%                                ^^ interval step distance - now [sec]
% fzg_scalar_struct    - Struct(1,1)  - Modelldaten - nur skalar
% fzg_array_struct     - Struct(1,1)  - Modelldaten - nur arrays                             

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

% old initialization
% % Ausgabewert des Minimums der Hamiltonfunktion
% %   output for minimizing the hamiltonian
% minFulLvl = inf;
% % Batterieladungs√§nderung im Wegschritt beir minimaler Hamiltonfunktion
% %   battery change in path_idx step with the minial hamiltonian
% batFrcOut = inf;
% % Kraftstoffkraft√§nderung im Wegschritt bei minimaler Hamiltonfunktion
% %   fuel change in path_idx step with the minimal hamiltonian
% fulFrcOut = 0;

% new initialization
% intializing fuel energy output
fulEng = inf;
% initializing state permutation's electric motor torque
emoTrq = inf;
% initializing state permutation's ice torque
iceTrq = inf;
% initializing state permutation's braking torque
brkTrq = 0;

%% Initialisieren der persistent Gr√∂√üen
%   initialize the persistance variables

% Diese werden die nur einmal f‹r die Funktion berechnet
%   only calculated once for the function

persistent crsSpdHybMax crsSpdHybMin crsSpdEmoMax

if isempty(crsSpdHybMax)
    
    % maximale Drehzahl Elektrommotor
    %   maximum electric motor rotational speed
    crsSpdEmoMax = fzg_array_struct.emoSpdMgd(1,end);
    
    % maximale Drehzahl der Kurbelwelle
    %   maximum crankshaft rotational speed
    % 12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY
    % ARE WE SECTNIG THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE
    % EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER?
    crsSpdHybMax = min(fzg_array_struct.iceSpdMgd(1,end),crsSpdEmoMax);
    
    % minimale Drehzahl der Kurbelwelle
    %   minimum crankshaft rotational speed
    crsSpdHybMin = fzg_array_struct.iceSpdMgd(1,1);
    
end

%% STEPS
% 1. calculate power demanded from this battery energy change
% 2. interpolate EM torque from this power demand
%   2a. in order to interpolate, need to find crankshaft velocity
% 3. use this EM torque to find ICE torque to satisfy rest of demand
%   3a. first find total crankshaft torque demand
% 4. find resultant fuel consumption to make this ICE torque happen

%% 1. calculate battery power demand
% calculate power required by battery for E'
% P = E/t = E'/t'
batPwr = batStaDlt / timeStp;

%% 2. interpolate batttery/EM torque
%   2a. find crsSpd

% vorzeitiger Funktionsabbruch?
%   premature function termination?
% Drehzahl der Kurbelwelle und Grenzen
%   crankshaft speed and limits

% Aus den kinetischen Energien des Fahrzeugs wird √ºber die Raddrehzahl
% und die √ºbersetzung vom Getriebe die Kurbelwellendrehzahl berechnet.
% Zeilenrichtung entspricht den G√§ngen. (Zeilenvektor)
%   from the vehicle's kinetic energy, the crankshaft speed is calculated
%   by the speed and gearbox translation. Line direction corresponding to
%   the aisles (row rector). EQUATION 1
%
% since a speed profile is being provided and velocity does not have to be
% calculated for every KE state (they do not exist here), velocity for the
% crs can be calculated vector style for each gear, as vehVel can be
% inputted as a vector
%
% but may need to do this time index by time index instead
crsSpdVec  = fzg_array_struct.geaRat(gea) * vehVelVec / (fzg_scalar_struct.whlDrr);


% boundaries:
% Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen
% Modus
%   stop if the crankshaft rotational speed is too high in hybrid mode
if engStaPre && any(crsSpdVec > crsSpdHybMax)
    return;
end

% Falls die Drehzahl des Verbrennungsmotors niedriger als die
% Leerlaufdrehzahl ist,
%   stop if crankhaft rotional speed is lower than the idling speed
if engStaPre && any(crsSpdVec < crsSpdHybMin)
    return;
end

% Pr¸fen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
%   check if electric motor speed limit is maintained
if ~engStaPre && any(crsSpdVec > crsSpdEmoMax)
    return;
end


% use previous time idx's crankshaft rotational speed for calculations
crsSpd = crsSpdVec(1);
% use previous vehicle velocity time index for calculations
vehVel = vehVelVec(1);

%   2b. interpolate
%       - in order to interpolate, need the following:
%       - battery resistance
%       - OCV lookup based on current SOC
%       - bat_Pwr -> emo_Pwr conversion

% resistance calulation
% BUT - is batPwr == emoPwr?? Or do we need a conversion??
% if so, include conversion below
if batPwr < 0
    batRst = fzg_scalar_struct.batRstDch;
else
    batRst = fzg_scalar_struct.batRstChr;
end

% ocv lookup
% calculate SOC value
batSoc = batStaPre / tst_scalar_struct.batEngMax;
batOcv = interp1q(fzg_array_struct.SOC_vs_OCV(:,1), fzg_array_struct.SOC_vs_OCV(:,2), batSoc);

% elektrische Leistung des Elektromotors
%   electric power from electric motor - DERIVATION? dunno
emoPwrEle = -batPwr * vehVel ... innere Batterieleistung / internal batt power
    - batPwr^2 * vehVel^2 / batOcv^2 * batRst...dissipat. Leist. / dissipated
    - batPwrAux; ...          Nebenverbrauchlast / auxiliary power
% if just assuming the same:   
% emoPwrEle = batPwr

%% 3. find emoTrq from power calculations
% interpolation
emoTrq = interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoPwrMgd,...
                fzg_array_struct.emoTrq_emoSpd_emoPwr, crsSpd, emoPwrEle);

%% 4. find complementary ICE torque
    %4a. find total demanded crankshaft torque  

% Getriebe¸bersetzung und -verlust
%   gear ratio and loss

% Berechnung des Kurbelwellenmoments
% Hier muss unterschieden werden, ob das Radmoment positiv oder
% negativ ist, da nur ein einfacher Wirkungsgrad f¸r das Getriebe
% genutzt wird
%   it's important to determine sign of crankshaft torque (positive or
%   negative), since only a simple efficiency is used for the transmission
%   PART OF EQ4  <- perhaps reversed? not too sure
if whlTrqPre < 0
    crsTrq = whlTrqPre / fzg_array_struct.geaRat(gea) * fzg_array_struct.geaEfy(gea);
else
    crsTrq = whlTrqPre / fzg_array_struct.geaRat(gea) / fzg_array_struct.geaEfy(gea);
end

% NEED SOME CHECKS
% - max/min torque boundaries
% - condition that iceTrq must be zero if engStaPre=0

%   QUESTION : CAN ICE RUN UNDER THE LOWEST CRSSPD GIVEN (HERE 89.0118) OR
%   IS THIS A CUTOFF THAT THE ICE CANNOT RUN?
%       - solved: can't run under 89
if engStaPre
    % max torque that ice can provide at current crsSpd - from interpolation
    iceTrqMaxPos = interp1q(fzg_array_struct.iceSpdMgd(1,:)',fzg_array_struct.iceTrqMax_emoSpd(:,2),crsSpd);
    % min torque that ice can provide at current crsSpd - from interpolation
    iceTrqMinPos = interp1q(fzg_array_struct.iceSpdMgd(1,:)',fzg_array_struct.iceTrqMin_emoSpd(:,2),crsSpd);

    % check that the demanded crsTrq is not above max possible torque that
    % can be generated between the ice and the em
    if crsTrq > iceTrqMaxPos + emoTrq; 
        return;
    end

    % torque split
    iceTrq = crsTrq - emoTrq;

    % check if iceTrq is too high or low based on iceTrqMax/MinPos
    if iceTrq > iceTrqMaxPos 
        return
    end

    % if iceTrq is negative (which it can't be in this case), don't
    % brake with with engine! Rather, brake with the brakes.
    if iceTrq < 0
        brkTrq = iceTrq;
        iceTrq = iceTrqMinPos;
    % does this mean that the state of the engine has changed??
    % so that engStaPre is now 0?! - most likely not, just set
        % current iceTrq to respective iceTrqMinPos value
    end
    %% 5. find resultant fuel consumed for this iceTrq
    fulEng          ... Skalar Krafstoffkraft in N
        =           ...
        fulEngClc_focus ... FUNCTION CALL
        (           ...
        timeStp,    ... Skalar f¸r die Wegschrittweite in m,
        vehVel,     ... Skalar - vehicular velocity
        crsSpd,     ... Skalar - crankshaft speed at given path_idx
        iceTrq,     ... Skalar - ice torque at given path_idx
        iceTrqMax,  ... Skalar - max ICE torque
        fzg_scalar_struct,  ... struct - Fahrzeugparameter - nur skalar
        fzg_array_struct    ... struct - Fahrzeugparameter - nur array        
        );
else 
    % if engine is considered off - no torque is coming from the ice
    iceTrq = 0;
    fulEng = 0;
end   

%% OLD CODE
% NOTE: if the engine is off, the EM cannot fluctuate how much torque to 
% assign to the crankshaft, since it must satisfy ALL the demanded torque
% - there is no partial split.
% as a result, the same batEngDlt value will be used for min and max. But,
% the max value of the two must be used, since undershooting the minimum
% needed torque will not do.
% if ~engStaPre
%     batEngDltTmpVec     = [batEngDltMinInx batEngDltMaxInx];
%    [~, batEngDltTmpInx] = max(abs(batEngDltTmpVec));
%    batEngDltMinInx      = batEngDltTmpVec(batEngDltTmpInx);
%    batEngDltMaxInx      = batEngDltMinInx;
% end

% % %     % calculate the battery force required for specified fuel energy level
% % % %     batFrc = batFrcClc_a(...      FUNCTION CALL
% % % %         batPwr,...          Skalar - Batterieklemmleistung
% % % %         vehVel,...          Skalar - mittlere Geschwindigkeit im Intervall
% % % %         fzg_scalar_struct.batRstDch,...   Skalar - Entladewiderstand
% % % %         fzg_scalar_struct.batRstChr,...   Skalar - Ladewiderstand
% % % %         fzg_scalar_struct.vehVelThresh,...
% % % %         batOcv...           Skalar - battery open circuit voltage
% % % %         );    
    

% %% Hamiltonfunktion bestimmen
% %   determine the hamiltonian
% % Eq (29b)
% [minFulLvl,optPreInx] = min([fulEng,minFulLvl]);
% 
% % Wenn der aktuelle Punkt besser ist, als der in cosHamMin
% % gespeicherte Wert, werden die Ausgabegrˆﬂen neu beschrieben.
% %   if the current point is better than the stored cosHamMin value,
% %   then the output values are rewritten (selected prev. value is = 2)
% if optPreInx == 1
%     fulFrcOut = fulEng;
% end
    
end % end of function