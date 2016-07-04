function ...            --- Ausgangsgrößen:
[engKinOptVec,      ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,... Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergieänderung
    staVec,         ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate für kinetische Energie
    fulEngOpt,      ... Skalar - optimale Kraftstoffenergie
    resVld          ...
    ] =             ...
    runAlgorithmusDP(     ...
    inputparams,    ...
    tst_scalar_struct,     ...
    fzg_scalar_struct,     ...
    tst_array_struct,...
    nedc_array_struct,...
    fzg_array_struct...
    )%#codegen
%% assign structure fields to variables
% inputparams - originally simulink inputs
disFlg          = inputparams.disFlg;
iceFlg          = inputparams.iceFlg;
timeStp         = inputparams.timeStp;
batEngStp       = inputparams.batEngStp;
batEngBegMinRat = inputparams.batEngBegMinRat;
batEngBegMaxRat = inputparams.batEngBegMaxRat;
batEngEndMinRat = inputparams.batEngEndMinRat;
batEngEndMaxRat = inputparams.batEngEndMaxRat;
batPwrAux       = inputparams.batPwrAux;
psiBatEng       = inputparams.psiBatEng;
psiTim          = inputparams.psiTim;
staChgPenCosVal = inputparams.staChgPenCosVal;
wayInxBeg       = inputparams.wayInxBeg;
wayInxEnd       = inputparams.wayInxEnd;
staBeg          = inputparams.staBeg;

% get the max 100% battery energy value possible
batEngMax       = fzg_scalar_struct.batEngMax;

% tst_scalar_struct - originally tstDat800 structure
staNum          = tst_scalar_struct.staNum;
% wayNum          = tst_scalar_struct.wayNum;
% engKinNum       = tst_scalar_struct.engKinNum;
slpVec_wayInx               = tst_array_struct.slpVec_wayInx;
engKinMat_engKinInx_wayInx  = tst_array_struct.engKinMat_engKinInx_wayInx;
engKinNumVec_wayInx         = tst_array_struct.engKinNumVec_wayInx;

% nedc_array_struct - save vector values
timeVecRaw  = nedc_array_struct.vehVel(:,1);
velVecRaw   = nedc_array_struct.vehVel(:,2);
slopeVecRaw = nedc_array_struct.refSlpVec;
% acceleration : dV/dt
accVecRaw  = gradient(velVecRaw);

% discretize raw data wrt time interval step size
timeVec     = timeVecRaw(1) : timeStp : timeVecRaw(end);
[timeBool, timeIdx]= ismember(timeVecRaw, timeVec);
velVec      = velVecRaw(timeBool);
accVec      = accVecRaw(timeBool);
disVec      = velVec * timeStp;
slopeVec    = slopeVecRaw(timeBool);

% determine time length of interval
timeNum = length(timeVec);

%% define battery engine value from input ratios
% make sure that the ratio SOC is discretized to given input energy steps
batEngBegMin    = floor(batEngMax*batEngBegMinRat/batEngStp) * batEngStp;
batEngBegMax    = ceil(batEngMax*batEngBegMaxRat/batEngStp) * batEngStp;

% select a possible for stating battery energy (random discretized value
% between beg_min and beg_max battery energy values
batEngBegIdx_MaxPossible = (batEngBegMax - batEngBegMin);
batEngBegIdx_Possible = 0 : batEngStp: batEngBegIdx_MaxPossible;
batEngBeg = batEngBegMin + batEngBegIdx_Possible(randi(numel(batEngBegIdx_Possible)));

% boundary conditions the end battery energy must be within bounds of
batEngEndMin = floor(batEngMax*batEngEndMinRat/batEngStp) * batEngStp;
batEngEndMax = ceil(batEngMax*batEngEndMaxRat/batEngStp) * batEngStp;

%% manipulate speed profile - find crankshaft torque throughout profile
% crankshaft rotational velocity: gear_ratio*velocity/wheel_radius
% CURRENTLY ASSUME ONLY ONE GEAR - STARTING GEAR
% NOTE . THIS WOULD HAVE TO FALL UNDER A DP LOOP BECAUSE IT IS DEPENDENT ON
% CURRENT GEAR VALUE. but for now, can be a simple calculation
gea         = inputparams.staBeg;
crsSpdVec   = fzg_array_struct.geaRat(gea) * velVec / (fzg_scalar_struct.whlDrr);

% define boundaries for crankspeed
% maximale Drehzahl Elektrommotor
%   maximum electric motor rotational speed
crsSpdEmoMax = fzg_array_struct.emoSpdMgd(1,end);

% maximale Drehzahl der Kurbelwelle
%   maximum crankshaft rotational speed
crsSpdHybMax = min(fzg_array_struct.iceSpdMgd(1,end),crsSpdEmoMax);

% minimale Drehzahl der Kurbelwelle
%   minimum crankshaft rotational speed
crsSpdHybMin = fzg_array_struct.iceSpdMgd(1,1);
    
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

% once crankshaft velocity boundaries are satisfied, caculate wheel forces
% sum of forces = m*a
% vehicle slip from gradient
vehFrcSlp = fzg_scalar_struct.vehMas * 9.81 * sin(slopeVec);
% rolling resistance
vehFrcRol = fzg_scalar_struct.whlRosResCof*fzg_scalar_struct.vehMas * 9.81 * cos(slopeVec);
% air resistance
vehFrcDrg = fzg_scalar_struct.drgCof * velVec.^2;

% calculate force acting on wheel that auto must provide 
%   (acceleration*mass + gradient force + rolling resistance
%   + air resistance)    EQUATION 5
whlFrc  = accVec*fzg_scalar_struct.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;

 % side note: if vehicle velocity is zero, then set force at wheel to zero
whlFrc(velVec < 0.05) = 0;

% gear ratio and loss
%   the weel torque is obtained from the wheel radius of the rolling
%   resistance force (torque = force * distance (here, wheel radius))
whlTrq = whlFrc*fzg_scalar_struct.whlDrr;

%  - ALSO WOULD PLAY IN DP GEAR LOOP
%   it's important to determine sign of crankshaft torque (positive or
%   negative), since only a simple efficiency is used for the transmission
%   PART OF EQ4  <- perhaps reversed? not too sure
if whlTrq < 0
    crsTrq = whlTrq / fzg_array_struct.geaRat(gea) * fzg_scalar_struct.geaEfy;
else
    crsTrq = whlTrq / fzg_array_struct.geaRat(gea) / fzg_scalar_struct.geaEfy;
end

%% internal combustion engine max/min possible torque
% maximales Moment des Verbrennungsmotors berechnen
%   calculate max torque of the engine (quadratic based on rotation speed)
iceTrqMax = fzg_array_struct.iceTrqMaxCof(1) * crsSpdVec.^2 ...
    + fzg_array_struct.iceTrqMaxCof(2) * crsSpdVec ...
    + fzg_array_struct.iceTrqMaxCof(3);

% minimales Moment des Verbrennungsmotors berechnen
%   calculating mimimum ICE moment
iceTrqMin = fzg_array_struct.iceTrqMinCof(1) * crsSpdVec.^2 ...
    + fzg_array_struct.iceTrqMinCof(2) * crsSpdVec ...
    + fzg_array_struct.iceTrqMinCof(3);

%% electric motor max torque
%   max torque that the electric motor can provide - from interpolation
emoTrqMaxPos = ...
    interp1q(fzg_array_struct.emoSpdMgd(1,:)',fzg_array_struct.emoTrqMax_emoSpd,crsSpdVec);
%   a valid crankshaft moments must be less than the total moment of the
%   electric motor and the ICE. Otherwise, leave the function.
emoTrqMinPos = ...
    interp1q(fzg_array_struct.emoSpdMgd(1,:)',fzg_array_struct.emoTrqMin_emoSpd,crsSpdVec);

% make sure that the ice and em can satisfy torque demanded required by the
% input velocity profile
if any(crsTrq > iceTrqMax + emoTrqMaxPos); 
    overdemandTrq = find(crsTrq > iceTrqMaxVec + emoTrqMaxPos);
    fprintf('NOTE: torque demanded from speed profile cannot be supplied by the ICE and EM (see idx %i)\n', overdemandTrq(1));
    return;
end

 %% check min/max boundaries, make sure they are within physical limits
% Durch EM zu lieferndes Kurbelwellenmoment
%   crankshaft torque to be delivered by the electric motor (min and max)
emoTrqMax = crsTrq - iceTrqMin;
emoTrqMin = crsTrq - iceTrqMax;

%% Elektromotor berechnen
%   calculate the electric motor
if any(emoTrqMaxPos < emoTrqMax)
    % Moment des Elektromotors bei maximaler Entladung der Batterie
    %   EM torque at max battery discharge
    emoTrqMax(emoTrqMaxPos < emoTrqMax) = emoTrqMaxPos(emoTrqMaxPos < emoTrqMax);
end

if any(emoTrqMaxPos < emoTrqMin)
    % Moment des Elektromotors bei minimaler Entladung der Batterie
    %   EM torque at min battery discharge
    emoTrqMin(emoTrqMaxPos < emoTrqMin) = emoTrqMaxPos(emoTrqMaxPos < emoTrqMax);
end

emoTrqMax = max(emoTrqMinPos,emoTrqMax);
emoTrqMin = max(emoTrqMinPos,emoTrqMin);

%% Berechnung der Ã¤nderung der Batterieladung
%   calculating the change in battery charge

% Interpolation der benÃ¶tigten Batterieklemmleistung für das
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
batPwrMax = zeros(length(crsSpdVec), 1);
batPwrMin = zeros(length(crsSpdVec), 1);
for i = 1 : length(batPwrMax)
    batPwrMax(i) = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
        fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpdVec(i),emoTrqMax(i)) + batPwrAux;
end

for i = 1 : length(batPwrMin)
    batPwrMin(i) = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
        fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpdVec(i),emoTrqMin(i)) + batPwrAux;
end

% Ã¼berprÃ¼fen, ob Batterieleistung mÃ¶glich
%   make sure that current battery max power is not above bat max bounds
if batPwrMax > fzg_scalar_struct.batPwrMax
    batPwrMax = fzg_scalar_struct.batPwrMax;
end

% Ã¼berprÃ¼fen, ob Batterieleistung mÃ¶glich
%   make sure that current battery min power is not above bat max bounds

if batPwrMin > fzg_scalar_struct.batPwrMax
    batPwrMin = fzg_scalar_struct.batPwrMax;
end

% Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% möglich ist.
%   check that the max and min still remain within the min bounds
if batPwrMax < fzg_scalar_struct.batPwrMin
    batPwrMax = fzg_scalar_struct.batPwrMin;
end

if batPwrMin < fzg_scalar_struct.batPwrMin
    batPwrMin = fzg_scalar_struct.batPwrMin;
end


%% build looping here! loop through time indexes
for timeIdx = inputparams.wayInxBeg : inputparams.timeStp : inputparams.wayInxEnd
   
    % Batteriespannung aus Kennkurve berechnen
    %   calculating battery voltage of characteristic curve - eq?--------------
    batOcv = batEngAct*fzg_array_struct.batOcvCof_batEng(1,1) + fzg_array_struct.batOcvCof_batEng(1,2);
    
    % calculate the max and min change in battery energy possible
    % this calculation relies on the battery's voltage , which changes
    % depending on the current battery energy (see above code)
    batEngDltMin = batFrcClc_port(... FUNCTION CALL - min delta bat.energy
    batPwrMax,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar.batRstChr,...Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * timeStp; % <-multiply by CHANGE IN TIME

batEngDltMax = batFrcClc_port(... FUNCTION CALL - max delta bat.energy
    batPwrMin,...           Skalar - Batterieklemmleistung
    vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
    fzg_scalar.batRstDch,...Skalar - Entladewiderstand
    fzg_scalar.batRstChr,...Skalar - Ladewiderstand
    batOcv...               Skalar - battery open-circuit voltage 
    ) * timeStp;
end


%% Calculating optimal predecessors with DP + PMP
fprintf('-Initializing model...\n');
[... --- Ausgangsgrößen:
    optPreInxTn3,   ...  Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3,   ...  Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ...  Tensor 3. Stufe für die Kraftstoffenergie 
    cos2goActMat    ...  Matrix der optimalen Kosten der Hamiltonfunktion 
    ] =             ... 
    clcDP_a  ... FUNKTION
    (               ... --- Eingangsgrößen:
    disFlg,         ... Skalar - Flag für Ausgabe in das Commandwindow
    wayStp,         ... Skalar für die Wegschrittweite in m
    batEngStp,      ... Skalar der Batteriediskretisierung in J 
    batEngBeg,      ... Skalar für die Batterieenergie am Beginn in Ws
    batPwrAux,      ... Skalar für die Nebenverbrauchlast in W
    psiBatEng,      ... Skalar für den Co-State der Batterieenergie
    psiTim,         ... Skalar für den Co-State der Zeit
    staChgPenCosVal,... Skalar für die Strafkosten beim Zustandswechsel
    wayInxBeg,      ... Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar für Endindex in den Eingangsdaten
    engKinNum,      ... Skalar für die max. Anz. an engKin-Stützstellen
    staNum,         ... Skalar für die max. Anzahl an Zustandsstützstellen
    timeNum,         ... Skalar für die max. Anzahl an Wegstützstellen
    staBeg,         ... Skalar für den Startzustand des Antriebsstrangs
    engKinNumVec_wayInx,        ... Vektor der Anzahl der kinetischen Energien
    slpVec_wayInx,              ... Vektor der Steigungen in rad
    engKinMat_engKinInx_wayInx, ... Matrix der kinetischen Energien in J
    fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct... struct der Fahrzeugparameter - NUR ARRAYS
    );
engKinEndInxVal = ceil(engKinNumVec_wayInx(wayInxEnd)/2);
staEnd = staBeg;

%% Calculating optimal trajectories for result of DP + PMP
[engKinOptVec,      ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,... Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergieänderung
    staVec,         ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate für kinetische Energie
    fulEngOpt       ... Skalar - optimale Kraftstoffenergie
    ] =             ...
    clcOptTrj_port  ... FUNKTION
    (false,         ... Flag, ob Zielzustand genutzt werden muss
    wayStp,         ... Skalar für die Wegschrittweite in m
    wayNum,         ... Skalar für die max. Anzahl an Wegstützstellen
    wayInxBeg,      ... Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar für Endindex in den Eingangsdaten
    staEnd,         ... Skalar für den finalen Zustand
    engKinNum,      ... Skalar für die max. Anz. an engKin-Stützstellen
    engKinEndInxVal,... Skalar für Zielindex der kinetischen Energie
    staNum,         ... Skalar für die max. Anzahl an Zustandsstützstellen
    engKinNumVec_wayInx,        ... Vektor der Anzahl der kinetischen Energien
    engKinMat_engKinInx_wayInx, ... Matrix der kinetischen Energien in J
    optPreInxTn3,   ... Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe für die Kraftstoffenergie
    cos2goActMat    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    );

% engKinOptVec=0;
% batEngDltOptVec=0;
% fulEngDltOptVec=0;
% staVec=0;
% psiEngKinOptVec=0;
% fulEngOpt=0;
resVld = true;

fprintf('\n\ndone!\n');
   
end