function ...            --- Ausgangsgrˆﬂen:
[engKinOptVec,      ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,... Vektor - optimale Batterieenergie‰nderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergie‰nderung
    staVec,         ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    fulEngOpt,      ... Skalar - optimale Kraftstoffenergie
    resVld          ...
    ] =             ...
    runAlgorithmusDP(       ...
    inputparams,            ...
    tst_scalar_struct,      ...
    fzg_scalar_struct,      ...
    tst_array_struct,       ...
    nedc_array_struct,      ...
    fzg_array_struct        ...
    )%#codegen
%% assign structure fields to variables
% inputparams - originally simulink inputs
disFlg          = inputparams.disFlg;
iceFlgBool      = inputparams.iceFlgBool;
timeStp         = inputparams.timeStp;
batEngStp       = inputparams.batEngStp;
batEngBegMinRat = inputparams.batEngBegMinRat;
batEngBegMaxRat = inputparams.batEngBegMaxRat;
batEngEndMinRat = inputparams.batEngEndMinRat;
batEngEndMaxRat = inputparams.batEngEndMaxRat;
batPwrAux       = inputparams.batPwrAux;
engBeg          = inputparams.engBeg;
engEnd          = inputparams.engEnd;
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
% slpVec_wayInx               = tst_array_struct.slpVec_wayInx;
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


% Pr√ºfen(check), ob eine erlaubte Beschleunigung vorliegt.
% Ansonsten zum n√§chsten Schleifendurchlauf springen
%   Check whether an allowable acceleration exists - if not, warn user
% vehAcc = (engKinAct-engKinPre)/vehMas/wayStp;
if any(accVec < fzg_scalar_struct.vehAccMin) || any(accVec > fzg_scalar_struct.vehAccMax)
    overdemandAcc = find(accVec<fzg_scalar_struct.vehAccMin || accVec>fzg_scalar_struct.vehAccMax);
    fprintf('NOTE: acceleration demanded from speed profile cannot be supplied by the set model bounds (see idx %i)\n', overdemandAcc(1));
    fprintf('Demanded acceleration: %4.3f\n', accVec(overdemandedAcc));
    fprintf('vehAccMin: %4.3\n', fzg_scalar_struct.vehAccMin);
    fprintf('vehAccMax: %4.3\n', fzg_scalar_struct.vehAccMax);
end

%% define battery engine value from input ratios
% make sure that the ratio SOC is discretized to given input energy steps
batEngBegMin    = floor(batEngMax*batEngBegMinRat/batEngStp) * batEngStp;
batEngBegMax    = ceil(batEngMax*batEngBegMaxRat/batEngStp) * batEngStp;

% select a possible for stating battery energy (random discretized value
% between beg_min and beg_max battery energy values
batEngBegIdx_MaxPossible = (batEngBegMax - batEngBegMin);
batEngBegIdx_Possible = 0 : batEngStp : batEngBegIdx_MaxPossible;
batEngBeg = batEngBegMin + batEngBegIdx_Possible(randi(numel(batEngBegIdx_Possible)));

% boundary conditions the end battery energy must be within bounds of
batEngEndMin = floor(batEngMax*batEngEndMinRat/batEngStp) * batEngStp;
batEngEndMax = ceil(batEngMax*batEngEndMaxRat/batEngStp) * batEngStp;




%% L√§ngsdynamik berechnen
%   calculate longitundinal dynamics
% Es wird eine konstante Beschleunigung angenommen, die im Wegschritt
% wayStp das Fahrzeug von velPre auf velAct beschleunigt.
%   constant acceleration assumed when transitioning from velPre to velAct
%   for the selected wayStp path_idx step distance

% Berechnen der konstanten Beschleunigung
%   calculate the constant acceleration
% vehAcc = (engKinAct - engKinPre) / (fzg_scalar_struct.vehMas*wayStp);

% Aus der mittleren kinetischen Energie im Intervall, der mittleren
% Steigung und dem Gang l√§sst sich √ºber die Fahrwiderstandsgleichung
% die n√∂tige Fahrwiderstandskraft berechnen, die aufgebracht werden
% muss, um diese zu realisieren.
%   from the (avg) kinetic energy in the interval, the (avg) slope and
%   transition can calculate the necessary traction force on the driving
%   resistance equation (PART OF EQUATION 5)

% Steigungskraft aus der mittleren Steigung berechnen (Skalar)
%   gradiant force from the calculated (average) gradient
vehFrcSlp = fzg_scalar_struct.vehMas * 9.81 * sin(slopeVec);

% Rollreibungskraft berechnen (Skalar)
%   calculated rolling friction force - not included in EQ 5???
vehFrcRol = fzg_scalar_struct.whlRosResCof*fzg_scalar_struct.vehMas * 9.81 * cos(slopeVec);

% Luftwiderstandskraft berechnen (2*c_a/m * E_kin) (Skalar) 
%   calculated air resistance force 
vehFrcDrg = fzg_scalar_struct.drgCof * velVec.^2;

%% Berechnung der minimalen kosten der Hamiltonfunktion
%   Calculating the minimum cost of the Hamiltonian

%% Berechnen der Kraft am Rad f√ºr Antriebsstrangmodus
%   calculate the force on the wheel for the drivetrain mode

% % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das
% % hei√üt es werden Tr√§gheitsmoment von Verbrennungsmotor,
% % Elektromotor und R√§dern mit einbezogen.
%   calculate dynamic vehicle mass with the vehicle engine (with the moment
%   of intertia of the ICE, electric motor, and wheels)
% vehMasDyn = (par.iceMoi_geaRat(gea) +...
%     par.emoGeaMoi_geaRat(gea) + par.whlMoi)/par.whlDrr^2 ...
%     + par.vehMas;

% Radkraft berechnen (Beschleunigungskraft + Steigungskraft +
% Rollwiderstandskraft + Luftwiderstandskraft)
%   caluclating wheel forces (accerlation force + gradient force + rolling
%   resistance + air resistance)    EQUATION 5
whlFrc  = accVec*fzg_scalar_struct.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;
% side note: if vehicle velocity is zero, then set force at wheel to zero
whlFrc(velVec < 0.05) = 0;


% Das Drehmoment des Rades ergibt sich √ºber den Radhalbmesser aus
% der Fahrwiderstandskraft.
%   the weel torque is obtained from the wheel radius of the rolling
%   resistance force (torque = force * distance (in this case, radius)
whlTrq = whlFrc*fzg_scalar_struct.whlDrr;






% %% manipulate speed profile - find crankshaft torque throughout profile
% % crankshaft rotational velocity: gear_ratio*velocity/wheel_radius
% % CURRENTLY ASSUME ONLY ONE GEAR - STARTING GEAR
% % NOTE . THIS WOULD HAVE TO FALL UNDER A DP LOOP BECAUSE IT IS DEPENDENT ON
% % CURRENT GEAR VALUE. but for now, can be a simple calculation
% % gea         = inputparams.staBeg;
% crsSpdVec   = fzg_array_struct.geaRat(gea) * velVec / (fzg_scalar_struct.whlDrr);
% 
% % define boundaries for crankspeed
% % maximale Drehzahl Elektrommotor
% %   maximum electric motor rotational speed
% crsSpdEmoMax = fzg_array_struct.emoSpdMgd(1,end);
% 
% % maximale Drehzahl der Kurbelwelle
% %   maximum crankshaft rotational speed
% crsSpdHybMax = min(fzg_array_struct.iceSpdMgd(1,end),crsSpdEmoMax);
% 
% % minimale Drehzahl der Kurbelwelle
% %   minimum crankshaft rotational speed
% crsSpdHybMin = fzg_array_struct.iceSpdMgd(1,1);
%     
% %   stop if the crankshaft rotatoinal speed is too high in hybrid mode
% if iceFlg && any(crsSpdVec > crsSpdHybMax)
%     return;
% end
% 
% % Falls die Drehzahl des Verbrennungsmotors niedriger als die
% % Leerlaufdrehzahl ist,
% %   stop if crankhaft rotional speed is lower than the idling speed
% if iceFlg && any(crsSpdVec < crsSpdHybMin)
%     return;
% end
% 
% % Pr¸fen, ob die Drehzahlgrenze des Elektromotors eingehalten wird
% %   check if electric motor speed limit is maintained
% if ~iceFlg && any(crsSpdVec > crsSpdEmoMax)
%     return;
% end
% 
% % once crankshaft velocity boundaries are satisfied, caculate wheel forces
% % sum of forces = m*a
% % vehicle slip from gradient
% vehFrcSlp = fzg_scalar_struct.vehMas * 9.81 * sin(slopeVec);
% % rolling resistance
% vehFrcRol = fzg_scalar_struct.whlRosResCof*fzg_scalar_struct.vehMas * 9.81 * cos(slopeVec);
% % air resistance
% vehFrcDrg = fzg_scalar_struct.drgCof * velVec.^2;
% 
% % calculate force acting on wheel that auto must provide 
% %   (acceleration*mass + gradient force + rolling resistance
% %   + air resistance)    EQUATION 5
% whlFrc  = accVec*fzg_scalar_struct.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;
% 
%  % side note: if vehicle velocity is zero, then set force at wheel to zero
% whlFrc(velVec < 0.05) = 0;
% 
% % gear ratio and loss
% %   the weel torque is obtained from the wheel radius of the rolling
% %   resistance force (torque = force * distance (here, wheel radius))
% whlTrq = whlFrc*fzg_scalar_struct.whlDrr;
% 
% %  - ALSO WOULD PLAY IN DP GEAR LOOP
% %   it's important to determine sign of crankshaft torque (positive or
% %   negative), since only a simple efficiency is used for the transmission
% %   PART OF EQ4  <- perhaps reversed? not too sure
% if whlTrq < 0
%     crsTrq = whlTrq / fzg_array_struct.geaRat(gea) * fzg_scalar_struct.geaEfy;
% else
%     crsTrq = whlTrq / fzg_array_struct.geaRat(gea) / fzg_scalar_struct.geaEfy;
% end
% 
% %% internal combustion engine max/min possible torque
% % maximales Moment des Verbrennungsmotors berechnen
% %   calculate max torque of the engine (quadratic based on rotation speed)
% iceTrqMax = fzg_array_struct.iceTrqMaxCof(1) * crsSpdVec.^2 ...
%     + fzg_array_struct.iceTrqMaxCof(2) * crsSpdVec ...
%     + fzg_array_struct.iceTrqMaxCof(3);
% 
% % minimales Moment des Verbrennungsmotors berechnen
% %   calculating mimimum ICE moment
% iceTrqMin = fzg_array_struct.iceTrqMinCof(1) * crsSpdVec.^2 ...
%     + fzg_array_struct.iceTrqMinCof(2) * crsSpdVec ...
%     + fzg_array_struct.iceTrqMinCof(3);
% 
% %% electric motor max torque
% %   max torque that the electric motor can provide - from interpolation
% emoTrqMaxPos = ...
%     interp1q(fzg_array_struct.emoSpdMgd(1,:)',fzg_array_struct.emoTrqMax_emoSpd,crsSpdVec);
% %   a valid crankshaft moments must be less than the total moment of the
% %   electric motor and the ICE. Otherwise, leave the function.
% emoTrqMinPos = ...
%     interp1q(fzg_array_struct.emoSpdMgd(1,:)',fzg_array_struct.emoTrqMin_emoSpd,crsSpdVec);
% 
% % make sure that the ice and em can satisfy torque demanded required by the
% % input velocity profile
% if any(crsTrq > iceTrqMax + emoTrqMaxPos); 
%     overdemandTrq = find(crsTrq > iceTrqMaxVec + emoTrqMaxPos);
%     fprintf('NOTE: torque demanded from speed profile cannot be supplied by the ICE and EM (see idx %i)\n', overdemandTrq(1));
%     fprintf('Demanded torque: %4.3f\n', crsTrq(overdemandedTrq));
%     fprintf('(iceTrqMax) + (emoTrqMaxPos) =(maxTrq): %4.3f + %4.3f = %4.3\n', iceTrqMax, emoTrqMaxPos, iceTrqMax+emoTrqMaxPos);
%     return;
% end
% 
%  %% check min/max boundaries, make sure they are within physical limits
% % Durch EM zu lieferndes Kurbelwellenmoment
% %   crankshaft torque to be delivered by the electric motor (min and max)
% emoTrqMax = crsTrq - iceTrqMin;
% emoTrqMin = crsTrq - iceTrqMax;
% 
% %% Elektromotor berechnen
% %   calculate the electric motor
% if any(emoTrqMaxPos < emoTrqMax)
%     % Moment des Elektromotors bei maximaler Entladung der Batterie
%     %   EM torque at max battery discharge
%     emoTrqMax(emoTrqMaxPos < emoTrqMax) = emoTrqMaxPos(emoTrqMaxPos < emoTrqMax);
% end
% 
% if any(emoTrqMaxPos < emoTrqMin)
%     % Moment des Elektromotors bei minimaler Entladung der Batterie
%     %   EM torque at min battery discharge
%     emoTrqMin(emoTrqMaxPos < emoTrqMin) = emoTrqMaxPos(emoTrqMaxPos < emoTrqMax);
% end
% 
% emoTrqMax = max(emoTrqMinPos,emoTrqMax);
% emoTrqMin = max(emoTrqMinPos,emoTrqMin);
% 
% %% Berechnung der √§nderung der Batterieladung
% %   calculating the change in battery charge
% 
% % Interpolation der ben√∂tigten Batterieklemmleistung f¸r das
% % EM-Moment. Stellen die nicht definiert sind, werden mit inf
% % ausgegeben. Positive Werte entsprechen entladen der Batterie.
% %   interpolating the required battery terminal power for the EM torque.
% %   Assign undefined values to inf. Positive values coresspond with battery
% %   discharge.
% % batPwrMax = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),...
% %     par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMax) + batPwrAux;
% % 
% % batPwrMin = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),...
% %     par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMin) + batPwrAux;
% batPwrMax = zeros(length(crsSpdVec), 1);
% batPwrMin = zeros(length(crsSpdVec), 1);
% for i = 1 : length(batPwrMax)
%     batPwrMax(i) = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
%         fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpdVec(i),emoTrqMax(i)) + batPwrAux;
% end
% 
% for i = 1 : length(batPwrMin)
%     batPwrMin(i) = codegen_interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoTrqMgd,...
%         fzg_array_struct.emoPwr_emoSpd_emoTrq,crsSpdVec(i),emoTrqMin(i)) + batPwrAux;
% end
% 
% % √ºberpr√ºfen, ob Batterieleistung m√∂glich
% %   make sure that current battery max power is not above bat max bounds
% if batPwrMax > fzg_scalar_struct.batPwrMax
%     batPwrMax = fzg_scalar_struct.batPwrMax;
% end
% 
% % √ºberpr√ºfen, ob Batterieleistung m√∂glich
% %   make sure that current battery min power is not above bat max bounds
% 
% if batPwrMin > fzg_scalar_struct.batPwrMax
%     batPwrMin = fzg_scalar_struct.batPwrMax;
% end
% 
% % Es kann vorkommen, dass mehr Leistung gespeist werden soll, als
% % mˆglich ist.
% %   check that the max and min still remain within the min bounds
% if batPwrMax < fzg_scalar_struct.batPwrMin
%     batPwrMax = fzg_scalar_struct.batPwrMin;
% end
% 
% if batPwrMin < fzg_scalar_struct.batPwrMin
%     batPwrMin = fzg_scalar_struct.batPwrMin;
% end
% 
% 
% 
% 
% %% build looping here! loop through time indexes
% for timeIdx = inputparams.wayInxBeg : inputparams.timeStp : inputparams.wayInxEnd
%    
%     % Batteriespannung aus Kennkurve berechnen
%     %   calculating battery voltage of characteristic curve - eq?--------------
%     batOcv = batEngAct*fzg_array_struct.batOcvCof_batEng(1,1) + fzg_array_struct.batOcvCof_batEng(1,2);
%     
%     % calculate the max and min change in battery energy possible
%     % this calculation relies on the battery's voltage , which changes
%     % depending on the current battery energy (see above code)
%     batEngDltMin = batFrcClc_port(... FUNCTION CALL - min delta bat.energy
%     batPwrMax,...           Skalar - Batterieklemmleistung
%     vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
%     fzg_scalar.batRstDch,...Skalar - Entladewiderstand
%     fzg_scalar.batRstChr,...Skalar - Ladewiderstand
%     batOcv...               Skalar - battery open-circuit voltage 
%     ) * timeStp; % <-multiply by CHANGE IN TIME
% 
% batEngDltMax = batFrcClc_port(... FUNCTION CALL - max delta bat.energy
%     batPwrMin,...           Skalar - Batterieklemmleistung
%     vel,...                 Skalar - mittlere Geschwindigkeit im Intervall
%     fzg_scalar.batRstDch,...Skalar - Entladewiderstand
%     fzg_scalar.batRstChr,...Skalar - Ladewiderstand
%     batOcv...               Skalar - battery open-circuit voltage 
%     ) * timeStp;
% end
% 

%% Calculating optimal predecessors with DP + PMP
fprintf('-Initializing model...\n');
[... --- Ausgangsgrˆﬂen:
    optPreInxTn3,   ...  Tensor 3. Stufe f¸r opt. Vorg‰ngerkoordinaten
    batFrcOptTn3,   ...  Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ...  Tensor 3. Stufe f¸r die Kraftstoffenergie 
    cos2goActMat    ...  Matrix der optimalen Kosten der Hamiltonfunktion 
    ] =             ... 
    clcDP_a         ... FUNKTION
    (               ... --- Eingangsgrˆﬂen:
    disFlg,         ... Skalar - Flag f¸r Ausgabe in das Commandwindow
    iceFlgBool,     ... skalar - is engine toggle on/off allowed?
    wayStp,         ... Skalar f¸r die Wegschrittweite in m
    batEngStp,      ... Skalar der Batteriediskretisierung in J 
    batEngBeg,      ... Skalar f¸r die Batterieenergie am Beginn in Ws
    batPwrAux,      ... Skalar f¸r die Nebenverbrauchlast in W
    staChgPenCosVal,... Skalar f¸r die Strafkosten beim Zustandswechsel
    wayInxBeg,      ... Skalar f¸r Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar f¸r Endindex in den Eingangsdaten
    staNum,         ... Skalar f¸r die max. Anzahl an Zustandsst¸tzstellen
    timeNum,        ... Skalar f¸r die max. Anzahl an Wegst¸tzstellen
    engBeg,         ... scalar - beginnnig engine state
    engEnd,         ... scalar - end engine state
    staBeg,         ... Skalar f¸r den Startzustand des Antriebsstrangs
    velVec,         ... velocity vector contiaing input speed profile
    whlTrq,         ... wheel torque demand vector for the speed profile
...%     slpVec_wayInx,  ... Vektor der Steigungen in rad
    fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct... struct der Fahrzeugparameter - NUR ARRAYS
    );
engKinEndInxVal = ceil(engKinNumVec_wayInx(wayInxEnd)/2);
staEnd = staBeg;


%% Calculating optimal trajectories for result of DP + PMP
[engKinOptVec,      ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,... Vektor - optimale Batterieenergie‰nderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergie‰nderung
    staVec,         ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate f¸r kinetische Energie
    fulEngOpt       ... Skalar - optimale Kraftstoffenergie
    ] =             ...
    clcOptTrj_port  ... FUNKTION
    (false,         ... Flag, ob Zielzustand genutzt werden muss
    wayStp,         ... Skalar f¸r die Wegschrittweite in m
    wayNum,         ... Skalar f¸r die max. Anzahl an Wegst¸tzstellen
    wayInxBeg,      ... Skalar f¸r Anfangsindex in den Eingangsdaten
    wayInxEnd,      ... Skalar f¸r Endindex in den Eingangsdaten
    staEnd,         ... Skalar f¸r den finalen Zustand
    engKinNum,      ... Skalar f¸r die max. Anz. an engKin-St¸tzstellen
    engKinEndInxVal,... Skalar f¸r Zielindex der kinetischen Energie
    staNum,         ... Skalar f¸r die max. Anzahl an Zustandsst¸tzstellen
    engKinNumVec_wayInx,        ... Vektor der Anzahl der kinetischen Energien
    engKinMat_engKinInx_wayInx, ... Matrix der kinetischen Energien in J
    optPreInxTn3,   ... Tensor 3. Stufe f¸r opt. Vorg‰ngerkoordinaten
    batFrcOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe f¸r die Kraftstoffenergie
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