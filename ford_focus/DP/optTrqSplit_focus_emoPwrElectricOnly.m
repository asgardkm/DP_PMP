function [              ...
    fulEng,             ... skalar - state predecessor resultant fuel value
    emoTrq,             ... skalar - state predecessor resultant emoTrq
    iceTrq,             ... skalar - state predecessor resultant iceTrq
    brkTrq              ... skalar - state predecessor resultant brkTrq
] =                     ...
    optTrqSplit_focus_emoPwrElectricOnly   ...
(                       ...
    brkBool,            ... bool - allow states requireing braking?
    batPwr,             ... skalar - current battery power being analzyed
    batOcvPre,          ... skalar - battery predecessor OC voltage
    batRst,             ... skalar - battery resistance
    crsSpdPre,          ... skalar - predecessor crankshaft speed
    crsTrqPre,          ... skalar - predecessor crankshaft torque
    emoTrqMinPos,       ... skalar - min boundary for predecessor emoTrq 
    emoTrqMaxPos,       ... skalar - max boundary for predecessor emoTrq
    emoPwrMinPos,       ... skalar - min boundary for predecessor emoPwr
    emoPwrMaxPos,       ... skalar - max boundary for predecessor emoPwr
    iceTrqMaxPos,       ... skalar - min boundary for predecessor iceTrq
    iceTrqMinPos,       ... skalar - max boundary for predecessor iceTrq
    crsSpdHybMax,       ... skalar - maximum crankshaft rotational speed
    crsSpdHybMin,       ... skalar - minimum crankshaft rotational speed
    timStp,             ... skalar - time step size
    batPwrAux,          ... skalar - auxiiary power demanded from battery
    vehVelVec,          ... vector - predecessor and current vehicle speed
    fzg_scalar_struct,  ... struct - contains skalar vehicular parameters
    fzg_array_struct    ... struct - contains vector vehicular paarameters
)
%#codegen
%
% 12.08.2016 - note: this version does not interpolate the emoPwrElectric
% into a mechanical torque - which seems to be yielding better results for
% some reason.
%
%CLCPMP Minimizing Hamiltonian: Co-States for soc and time
% Erstellungsdatum der ersten Version 19.08.2015 - Stephan Uebel
%
% Batterieleistungsgrenzen hinzugefügt am 13.12.2015
% ^^added battery power limit
%
% Massenaufschlag durch Trägheitsmoment herausgenommen
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
% iceFlg        - Boolean(1,1) - Flag für Motorzustand-REMOVED 12.07.2016
%                                ^^ flag for motor condition
% batEng        - Double(1,1)  - Batterieenergie in J
%                                ^^ battery energy (J)
% batPwrAux     - Double(1,1)  - elektr. Nebenverbraucherleistung in W
%                                ^^ electric auxiliary power consumed (W)
% batEngStp     - Double(1,1)  - Drehmomentschritt
%                                ^^ torque step <- no, it's a battery step
% timStp        - Double(1,1)  - Intervallschrittweite in m
%                                ^^ interval step distance - now [sec]
% fzg_scalar_struct    - Struct(1,1)  - Modelldaten - nur skalar
% fzg_array_struct     - Struct(1,1)  - Modelldaten - nur arrays                             

%% Initialisieren der Ausgabe der Funktion
%   initializing function output

% old initialization
% % Ausgabewert des Minimums der Hamiltonfunktion
% %   output for minimizing the hamiltonian
% minFulLvl = inf;
% % Batterieladungsänderung im Wegschritt beir minimaler Hamiltonfunktion
% %   battery change in path_idx step with the minial hamiltonian
% batFrcOut = inf;
% % Kraftstoffkraftänderung im Wegschritt bei minimaler Hamiltonfunktion
% %   fuel change in path_idx step with the minimal hamiltonian
% fulFrcOut = 0;

% new initialization
% intializing fuel energy output
fulEng = inf;
emoTrq = 0;
iceTrq = 0;
brkTrq = 0;
% -------------------------------------------------------------------------

% ----- CRANKSHAFT SPEED BOUNDARY CHECKS ---------------------------------
% IS THERE A WAY TO BRING THE CHECKING OUT OF THIS FUNCTION?
% boundaries:
% Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen
% Modus
%   stop if the crankshaft rotational speed is too high in hybrid mode
if crsSpdPre > crsSpdHybMax
    return;
end

% Falls die Drehzahl des Verbrennungsmotors niedriger als die
% Leerlaufdrehzahl ist,
%   stop if crankhaft rotional speed is lower than the idling speed
if crsSpdPre < crsSpdHybMin
    return;
end
% -------------------------------------------------------------------------


% ----- DERIVE emoPwr FROM batPwr STATE -----------------------------------
% from the given batPwr, derive emoPwr from equation:
%   emoPwr = batPwr - batPwrLoss,
% where
%   batPwr      = batOcv * I, and
%   batPwrLoss  = I^2 * batRst. 

% lookup battery voltage for the given battery state - batOcvPre
% therefore, current I = batPwr/batOcvPre
batCur      = batPwr / batOcvPre;

% can now caculate battery losses:
batPwrLoss  = batCur.^2 * batRst;

% find emoPwr
emoPwrElectric      = batPwr - batPwrLoss - batPwrAux;
% -------------------------------------------------------------------------


% ----- DERIVE emoTrq FROM emoPwr ----------------------------------------
% Power = Torque * rotational vel.
% therefore,
% Torque = Power / Vel
% INCLUDE LOOK UP TABLE HERE
% cannot go from electric power and work with mechanical crsSpd
% convert electric emoPwr to mechanical emoPwr with lookup table
% emoPwr = codegen_interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoPwrMgd', ...
%                                 fzg_array_struct.emoTrq_emoSpd_emoPwr, crsSpdPre, emoPwrElectric);
emoPwr = emoPwrElectric;
% emoPwr bound checking
if emoPwrMinPos > emoPwr || emoPwrMaxPos < emoPwr
    return;
end



emoTrq = emoPwr / crsSpdPre;

% emoTrq bound checking
if emoTrqMinPos > emoTrq || emoTrqMaxPos < emoTrq
    return;
end
% -------------------------------------------------------------------------


% ----- CALCUALTE crsTrq --------------------------------------------------
% check that the demanded crsTrq is not above max possible torque that
% can be generated between the ice and the em
if crsTrqPre > iceTrqMaxPos + emoTrq;
    return;
end

% torque split
iceTrq = crsTrqPre - emoTrq;

% iceTrq boundary check
% check if iceTrq is too high or low based on iceTrqMax/MinPos
if iceTrq > iceTrqMaxPos || iceTrq < iceTrqMinPos
    return
end
% HOW TO DEAL WITH BREAK BOOL?
% BRAKE WHEEL SIDE - WHEELS ARE RECEIVING TOO MUCH TORQUE FROM ICE
% if the iceTrq being delivered exceeds crsTrq demands plus the limit that
% the EM can experience while charging, discharge the iceTrq through brkTrq
if iceTrq > (crsTrqPre - emoTrqMinPos)
   if brkBool
       brkTrq = iceTrq - (crsTrqPre - emoTrqMinPos);
        fprintf('NOTE: engine braking is occuring - this is not optimal!\n');
        fprintf('   brkTrq: %4.3f\n', brkTrq);
        fprintf('   iceTrq: %4.3f\n', iceTrq);
        fprintf('   crsTrqPre: %4.3f\n', crsTrqPre);
        fprintf('   emoTrqMinPos: %4.2f\n', emoTrqMinPos);
   else
       return;
   end
end

% if brkBool is true - allow for braking to reduce 
% BRAKE ENGINE SIDE - ENGINE CANNOT RUN IN REVERSE
if iceTrq < 0
    % if iceTrq is negative (which it can't be in this case), don't
    % brake with with engine! Rather, brake with the brakes.
    % BUT! this shouldn't trigger, as this is not optimal!
%     if brkBool
        brkTrq = iceTrq;
        iceTrq = iceTrqMinPos;
        fprintf('NOTE: engine braking is occuring - this is not optimal!\n');
        fprintf('   brkTrq: %4.3f\n', brkTrq);
        fprintf('   adjusted iceTrq: %4.3f\n', iceTrq);
%     else
        fulEng = 0;
        return;
%     end
end
% -------------------------------------------------------------------------


% ----- CALCULATE fulEng USE ----------------------------------------------
fulEng =                                ... Skalar Krafstoffkraft in N
fulEngClc_focus                         ... FUNCTION CALL
(                                       ...
timStp,                                 ... Skalar f�r die Wegschrittweite in m,
vehVelVec(1),                           ... Skalar - vehicular velocity
crsSpdPre,                              ... Skalar - crankshaft speed at given time
iceTrq,                                 ... Skalar - ice torque at given time
iceTrqMaxPos,                           ... Skalar - max ICE torque
fzg_scalar_struct,                      ... Fahrzeugparameter - nur skalar
fzg_array_struct.iceSpdMgd,             ... Fahrzeugparameter - iceSpd      
fzg_array_struct.iceTrqMgd,             ... Fahrzeugparameter - iceTrq    
fzg_array_struct.iceFulPwr_iceSpd_iceTrq... Fahrzeugparameter - icePwr
);
% -------------------------------------------------------------------------

% END OF optTrqSplit_focus()
end % end of function