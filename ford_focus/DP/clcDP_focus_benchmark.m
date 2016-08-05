% benchmark for running clcDP_focus.m

cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\ford_focus\DP\');
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/ford_focus/DP')

addpath('../model_data', '../functions')

%% define clcDP structure inputs
% define init_a() inputs

% define mainConfig.txt string location
config_filename = 'mainConfig_a.txt';
% define raw data directory
datafile_dir    = 'raw_data';
% bool for if user wishes to rewrite raw data
write_bool      = 1;

% call init_port() - outputs are input structures to clcDP_port()
[inputparams, tst_scalar_struct, fzg_scalar_struct, tst_array_struct, nedc_array_struct, fzg_array_struct]...
         = init_focus(config_filename, datafile_dir, write_bool);

disFlg          = inputparams.disFlg;
iceFlgBool      = inputparams.iceFlgBool;
brkBool         = inputparams.brkBool;
timStp          = inputparams.timStp;
batEngBegMinRat = inputparams.batEngBegMinRat;
batEngBegMaxRat = inputparams.batEngBegMaxRat;
batEngEndMinRat = inputparams.batEngEndMinRat;
batEngEndMaxRat = inputparams.batEngEndMaxRat;
batPwrAux       = inputparams.batPwrAux;
engBeg          = inputparams.engBeg;
engEnd          = inputparams.engEnd;
staChgPenCosVal = inputparams.staChgPenCosVal;
timInxBeg       = inputparams.timInxBeg;
timInxEnd       = inputparams.timInxEnd;
staBeg          = inputparams.staBeg;

% get the max 100% battery energy value possible
batEngStp       = tst_scalar_struct.batEngStp;
batEngMax       = tst_scalar_struct.batEngMax;

% tst_scalar_struct - originally tstDat800 structure
geaNum          = tst_scalar_struct.staNum;
engStaNum       = tst_scalar_struct.engStaNum;
% wayNum          = tst_scalar_struct.wayNum;
% engKinNum       = tst_scalar_struct.engKinNum;
% slpVec_timInx               = tst_array_struct.slpVec_timInx;
% engKinMat_engKinInx_timInx  = tst_array_struct.engKinMat_engKinInx_timInx;
% engKinNumVec_timInx         = tst_array_struct.engKinNumVec_timInx;

% nedc_array_struct - save vector values
timVecRaw  = nedc_array_struct.vehVel(:,1);
velVecRaw   = nedc_array_struct.vehVel(:,2);
slopeVecRaw = nedc_array_struct.refSlpVec;
% acceleration : dV/dt
accVecRaw   = gradient(velVecRaw);

% discretize raw data wrt tim interval step size
timVec     = timVecRaw(1) : timStp : timVecRaw(end);
[timBool, ~]= ismember(timVecRaw, timVec);
velVec      = velVecRaw(timBool);

% preprocess velVec
velVec(velVec < fzg_scalar_struct.vehVelThresh) = 0;

accVec      = accVecRaw(timBool);
% disVec      = velVec * timStp;
slopeVec    = slopeVecRaw(timBool);

% determine tim length of interval
timNum     = length(timVec);


% Prüfen(check), ob eine erlaubte Beschleunigung vorliegt.
% Ansonsten zum nächsten Schleifendurchlauf springen
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
batEngBegIdx_Possible    = 0 : batEngStp : batEngBegIdx_MaxPossible;
batEngBeg = batEngBegMin + batEngBegIdx_Possible(randi(numel(batEngBegIdx_Possible)));

% boundary conditions the end battery energy must be within bounds of
batEngEndMin = floor(batEngMax*batEngEndMinRat/batEngStp) * batEngStp;
batEngEndMax = ceil(batEngMax*batEngEndMaxRat/batEngStp) * batEngStp;

%% Längsdynamik berechnen
%   calculate longitundinal dynamics
% Es wird eine konstante Beschleunigung angenommen, die im Wegschritt
% wayStp das Fahrzeug von velPre auf velAct beschleunigt.
%   constant acceleration assumed when transitioning from velPre to velAct
%   for the selected wayStp path_idx step distance

% Berechnen der konstanten Beschleunigung
%   calculate the constant acceleration
% vehAcc = (engKinAct - engKinPre) / (fzg_scalar_struct.vehMas*wayStp);

% Aus der mittleren kinetischen Energie im Intervall, der mittleren
% Steigung und dem Gang lässt sich über die Fahrwiderstandsgleichung
% die n�tige Fahrwiderstandskraft berechnen, die aufgebracht werden
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

%% Berechnen der Kraft am Rad für Antriebsstrangmodus
%   calculate the force on the wheel for the drivetrain mode

% % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das
% % heißt es werden Trägheitsmoment von Verbrennungsmotor,
% % Elektromotor und Rädern mit einbezogen.
%   calculate dynamic vehicle mass with the vehicle engine (with the moment
%   of intertia of the ICE, electric motor, and wheels)
% vehMasDyn = (par.iceMoi_geaRat(gea) +...
%     par.emoGeaMoi_geaRat(gea) + par.whlMoi)/par.whlDrr^2 + par.vehMas;

% Radkraft berechnen (Beschleunigungskraft + Steigungskraft +
% Rollwiderstandskraft + Luftwiderstandskraft)
%   caluclating wheel forces (accerlation force + gradient force + rolling
%   resistance + air resistance)    EQUATION 5
whlFrc  = accVec*fzg_scalar_struct.vehMas + vehFrcSlp + vehFrcRol + vehFrcDrg;
% side note: if vehicle velocity is zero, then set force at wheel to zero
whlFrc(velVec < 0.05) = 0;

% Das Drehmoment des Rades ergibt sich über den Radhalbmesser aus
% der Fahrwiderstandskraft.
%   the weel torque is obtained from the wheel radius of the rolling
%   resistance force (torque = force * distance (in this case, radius)
whlTrq = whlFrc*fzg_scalar_struct.whlDrr;

%% create equidistant speed-torque boundary ranges
% define a bool for always finding and using equidistant bounds
%   incorporate into mainConfig.txt later
useEqiDis = 1;
if useEqiDis 
    % for ICE
    iceSpdDif = diff(fzg_array_struct.iceSpdMgd);

    if any(abs(diff(iceSpdDif)) > 0.005)

        % equidistant interpolation
        iceExtBool = 1;
        if iceExtBool
            iceSpdInterp    = iceSpdDif(2) : iceSpdDif(2) : fzg_array_struct.iceSpdMgd(end);
            fprintf('NOTE: ICE boundaries have been extrapolated to crsSpd = 0\n');
        else
            iceSpdInterp    = fzg_array_struct.iceSpdMgd(1) : iceSpdDif(1) : fzg_array_struct.iceSpdMgd(end);
        end
        
        iceTrqMaxInterp = interp1(fzg_array_struct.iceSpdMgd, fzg_array_struct.iceTrqMax_emoSpd(:,2), iceSpdInterp, 'linear', 'extrap');
        iceTrqMinInterp = interp1(fzg_array_struct.iceSpdMgd, fzg_array_struct.iceTrqMin_emoSpd(:,2), iceSpdInterp, 'linear', 'extrap');
        
        % save equidistant interpolation values into the parameter structure
        fzg_array_struct.iceSpdMgd          = iceSpdInterp;
        fzg_array_struct.iceTrqMax_emoSpd   = [iceSpdInterp' iceTrqMaxInterp'];
        fzg_array_struct.iceTrqMin_emoSpd   = [iceSpdInterp' iceTrqMinInterp'];
        fprintf('NOTE: Interpolated ICE boundaries to be equidistant\n');
    end

    % for EM
    emoSpdDif = diff(fzg_array_struct.emoSpdMgd);

    if any(abs(diff(emoSpdDif)) > 0.005)

        % equidistant interpolation+ extrapolation
        % will be artifically capping min/max bounds @emoTrqMax/Min_emoSpd(1,2) to
        % all crankshaft indexes between 0 and emoTrqMax/Min_emoSpd(1,1)
        emoSpdInterp    = fzg_array_struct.emoSpdMgd(1) : emoSpdDif(2) : fzg_array_struct.emoSpdMgd(end);
        emoTrqMaxInterp = interp1(fzg_array_struct.emoTrqMax_emoSpd(:,1), fzg_array_struct.emoTrqMax_emoSpd(:,2), emoSpdInterp, 'linear', 'extrap');
        emoTrqMinInterp = interp1(fzg_array_struct.emoTrqMin_emoSpd(:,1), fzg_array_struct.emoTrqMin_emoSpd(:,2), emoSpdInterp, 'linear', 'extrap');
        emoPwrMaxInterp = interp1(fzg_array_struct.emoPwrMax_emoSpd(:,1), fzg_array_struct.emoPwrMax_emoSpd(:,2), emoSpdInterp, 'linear', 'extrap');
        emoPwrMinInterp = interp1(fzg_array_struct.emoPwrMin_emoSpd(:,1), fzg_array_struct.emoPwrMin_emoSpd(:,2), emoSpdInterp, 'linear', 'extrap');

        % IGNOREING emoTrq->emoPwr boundareis for the moment - too many NaNs for
        % the interpolated data to make sense, will need to talk about over again
        % later
        % % derive the emoPwr needed by emoTrq limits - leave NaNs as NaNs
        % %   is not efficient, but it's just a one tim preprocessing deal
        % % emoPwrNanDerive = inpaint_nans(fzg_array_struct.emoPwr_emoSpd_emoTrq);
        % emoPwrNanDerive = inpaint_nans(fzg_array_struct.emoPwr_emoSpd_emoTrq, 3);
        % 
        % emoPwrMinDerive = zeros(size(fzg_array_struct.emoPwr_emoSpd_emoTrq));
        % emoPwrMaxDerive1 = interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoTrqMgd, ...
        %                 fzg_array_struct.emoPwr_emoSpd_emoTrq, emoSpdInterp, emoTrqMaxInterp, 'linear');
        % 
        % emoPwrMaxDerive2 = interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoTrqMgd,...
        %                 emoPwrNanDerive, emoSpdInterp, emoTrqMaxInterp, 'linear');
        %             
        % % emoPwrMinDerive = zeros(size(fzg_array_struct.emoPwr_emoSpd_emoTrq));
        % emoPwrMinDerive1 = interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoTrqMgd, ...
        %                 fzg_array_struct.emoPwr_emoSpd_emoTrq, emoSpdInterp, emoTrqMinInterp, 'linear');
        % 
        % emoPwrMinDerive2 = interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoTrqMgd,...
        %                 emoPwrNanDerive, emoSpdInterp, emoTrqMinInterp, 'linear');
        % 
        % emoPwrMax
        %             
        % for i = 1 : length(fzg_array_struct.emoPwr_emoSpd_emoTrq(1,:)) % spd loop
        %     for j = 1 : length(fzg_array_struct.emoPwr_emoSpd_emoTrq(:,1))%trq loop
        %         if ~isnan(fzg_array_struct.emoPwr_emoSpd_emoTrq(j,i))
        %             emoPwrMinDerive(j,i) = interp2(fzg_array_struct.emoSpdMgd, fzg_array_struct.emoTrqMgd, ...
        %                 fzg_array_struct.emoPwr_emoSpd_emoTrq, emoSpdInterp(i), emoTrqMaxInterp(j), 'linear');
        %         else
        %             emoPwrMinDerive(j,i) = NaN;
        %         end
        %     end
        % end

        % fzg_array_struct.emoTrqMgd, fzg_array_struct.emoSpdMgd(1,:)', ...
        %                     fzg_array_struct.emoPwr_emoSpd_emoTrq
        % 
        % fzg_array_struct.emoPwr_emoSpd_emoTrq

        % artifical min/max cap from speed values from 0:emoTrq_emoSpd(1,1)
        emoSpdCapIdx = (fzg_array_struct.emoSpdMgd(1)/emoSpdDif(2) : fzg_array_struct.emoTrqMax_emoSpd(:,1)/emoSpdDif(2))+1;
        emoTrqMaxInterp(emoSpdCapIdx) = fzg_array_struct.emoTrqMax_emoSpd(1,2);
        emoTrqMinInterp(emoSpdCapIdx) = fzg_array_struct.emoTrqMin_emoSpd(1,2);
        emoPwrMaxInterp(emoSpdCapIdx) = fzg_array_struct.emoPwrMax_emoSpd(1,2);
        emoPwrMinInterp(emoSpdCapIdx) = fzg_array_struct.emoPwrMin_emoSpd(1,2);

        % save equidistant interpolation values into the parameter structure
        fzg_array_struct.emoSpdMgd          = emoSpdInterp;
        fzg_array_struct.emoTrqMax_emoSpd   = [emoSpdInterp', emoTrqMaxInterp'];
        fzg_array_struct.emoTrqMin_emoSpd   = [emoSpdInterp', emoTrqMinInterp'];
        fzg_array_struct.emoPwrMax_emoSpd   = [emoSpdInterp', emoPwrMaxInterp'];
        fzg_array_struct.emoPwrMin_emoSpd   = [emoSpdInterp', emoPwrMinInterp'];
        fprintf('NOTE: Interpolated EM boundaries to be equidistant\n');
    end 

end

%% DEFINE ICE/EM BOUNDARIES BASED ON CRANKSHAFT SPEED
% The ICE and EM can provide a max and min torque for a given crankshaft
%   speed due to physical limitations.
% These physical boundaries are already given as vector inputs accross 
%   various intermittant crankshaft speeds.
% Therefore, this snippet of code interpolates this torque boundary vector
%   accross the entirty of the crankshaft speed vector demanded by the speed 
%   profile accross all gear states.
% These interpolations are done in a loop going through all possible
%   crankshaft speeds defined per gear state variable.
% The above process is also done for EM power boundaries.

% preallocation
crsSpdMat       = zeros(length(velVec), geaNum);
crsTrqMat       = repmat(whlTrq, 1, geaNum);
iceTrqMaxPosMat = zeros(length(velVec), geaNum);
iceTrqMinPosMat = zeros(length(velVec), geaNum);
emoTrqMaxPosMat = zeros(length(velVec), geaNum);
emoTrqMinPosMat = zeros(length(velVec), geaNum);
emoPwrMinPosMat = zeros(length(velVec), geaNum);
emoPwrMaxPosMat = zeros(length(velVec), geaNum);
% emoPwrMinMat    = zeros(length(velVec), geaNum);
% emoPwrMaxMat    = zeros(length(velVec), geaNum);

% ---- LOOP THROUGH GEAR STATES -----------------
for gea = 1 : geaNum
    % CALCULATE CRANKSHAFT SPEEDS
    % In order to calculate crsSpd-based boundaries, crsSpd must be found first
    % calc crsSpd matrix along speed profile - a speed column for each gear
    crsSpdMat(:, gea)       = fzg_array_struct.geaRat(gea) * velVec / (fzg_scalar_struct.whlDrr);
    
    % CALCULATE ICE MAX/MIN TORQUE BOUNDARIES
    % max torque that ice can provide at current crsSpd - from interpolation
    iceTrqMaxPosMat(:, gea) = interp1q(fzg_array_struct.iceSpdMgd(1,:)',        ...
                                        fzg_array_struct.iceTrqMax_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
    % min torque that ice can provide at current crsSpd - from interpolation
    iceTrqMinPosMat(:, gea) = interp1q(fzg_array_struct.iceSpdMgd(1,:)',        ...
                                        fzg_array_struct.iceTrqMin_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
                                    
    % CALCULATE EM MAX/MIN TORQUE BOUNDARIES                                
    % max torque that the electric motor can provide - from interpolation
    emoTrqMaxPosMat(:, gea) = interp1q(fzg_array_struct.emoSpdMgd(1,:)',        ...
                                        fzg_array_struct.emoTrqMax_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
    emoTrqMinPosMat(:, gea) = interp1q(fzg_array_struct.emoSpdMgd(1,:)',        ...
                                        fzg_array_struct.emoTrqMin_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
                                    
    % CALCULATE EM PWR MIN/MAX BOUNDARIES                                
    emoPwrMinPosMat(:, gea) = interp1q(fzg_array_struct.emoSpdMgd(1,:)',        ...
                                        fzg_array_struct.emoPwrMin_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
    emoPwrMaxPosMat(:, gea) = interp1q(fzg_array_struct.emoSpdMgd(1,:)',        ...
                                        fzg_array_struct.emoPwrMax_emoSpd(:,2), ...
                                        crsSpdMat(:, gea));
                                    
    % CALCULATE CRANKSHAFT TORQUE
    % Also calculate crsTrq which is based on crsSpd
    % calc torque matrix - a torque column for each gear
    % take into account if torque is + or - : they have diff eqs
    crsTrqTmp = crsTrqMat(:, gea);
    crsTrqTmp(crsTrqTmp<0)  = whlTrq(crsTrqTmp<0) / fzg_array_struct.geaRat(gea) * fzg_array_struct.geaEfy(gea);
    crsTrqTmp(crsTrqTmp>=0) = whlTrq(crsTrqTmp>=0) / fzg_array_struct.geaRat(gea) / fzg_array_struct.geaEfy(gea);
    crsTrqMat(:, gea) = crsTrqTmp;
end
% -----------------------------------------------

%% GENERATE POWER DEMAND PROFILE THAT MUST BE SATISFIED
% crsTrq * crsSpd = crsPwr <- demand must be satisfied to complete profile
crsPwrMat = crsTrqMat .* crsSpdMat;

% % %% set emo power bounds
% % % These power lookups are based on both speed AND torque - given vector
% % % boundary input for the model.
% % % Is not related to the boudaries set by max/min crankshaft speed above.
% % % This matrix defines the torque-speed curve for EM power.
% % %
% % % Since the entire crankshaft speed and torque values for the speed profile 
% % % across all gears have been calculated in the previous code snippet, can
% % % the 
% % % first derive emoPwr based on emoTrq bounds
% NOTE: THIS IS A LOOKUP TABLE, NOT A BOUDNARY CALCULATION!- abort?
% % emoPwrMin = interp2(fzg_array_struct.emoTrqMgd, fzg_array_struct.emoSpdMgd(1,:)', ...
% %                     fzg_array_struct.emoPwr_emoSpd_emoTrq, ...
% %                     emoTrqMinPosMat(:, gea), crsSpdMat(:, gea));

%% calculating max/min batPwr demanded wrt emoPwrMax/MinPos above
% this batPwr will help minimize which batEng states to loop through in DP
% note: boundaries have been discretized to the tim index step size in the
% previous code snippet.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% EQUATION
%       batPwr - batPwrLoss = emoPwr
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% where,
%       emoPwr is given (min/max boundary vectors above - emoPwrMax/Min_emoSpd)
%       batPwrLoss = I^2*batRst,
%       batPwr     = V*I, and
%       Voltage V is a function of batEng (will be looped through)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% rearranging the above equations, batPwrLoss can be found as:
%       batPwrLoss = ((V-sqrt(V^2 - 4*R*emoPwr))^2)/(4*R)
% from which then batPwr can then be easily found (rearranging EQUATION):
%       batPwr = emoPwr + batPwrLoss
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% also calculating the battery power needed at each possible crankshaft 
% power occurance (ie the electric battery energy difference that must 
% occur if the battery supplies all the power to satisfy each crankshaft 
% power demand)
%
% ----- CALCULATE BATTERY VOLTAGE ----------------
% define all possible batEng values - convert them into SOCs
batSoc = (tst_scalar_struct.batEngMin : tst_scalar_struct.batEngStp : ...
            tst_scalar_struct.batEngMax) / tst_scalar_struct.batEngMax;
% interpolate voltage value for each SOC 
%   discretization level: # of possible batEng steps
batOcv = interp1(fzg_array_struct.SOC_vs_OCV(:,1), ...
                 fzg_array_struct.SOC_vs_OCV(:,2), ...
                 batSoc);
% -----------------------------------------------

% ----- DEFINE batRst ---------------------------
% usually, resistance is based on batPwr. Since batPwr is unkown, will be
% using emoPwr as a benchmark instead
%   b/c batPwr-batPwrLoss=emoPwr, both batPwr and emoPwr will generally
%   have the same sign, unless batPwr<batPwrLoss (which seems unlikely?)
%       may need to check this assumption later
batRstMax = zeros(length(emoPwrMaxPosMat), geaNum);
batRstMin = zeros(length(emoPwrMinPosMat), geaNum);

% the code below is performing this code snippet across the vector
% if batPwr < 0
%     batRst = fzg_scalar_struct.batRstDch;
% else
%     batRst = fzg_scalar_struct.batRstChr;
% end
batRstMax(emoPwrMaxPosMat<0)    = fzg_scalar_struct.batRstDch;
batRstMax(emoPwrMaxPosMat>=0)   = fzg_scalar_struct.batRstChr;
batRstMin(emoPwrMinPosMat<0)    = fzg_scalar_struct.batRstDch;
batRstMin(emoPwrMinPosMat>=0)   = fzg_scalar_struct.batRstChr;
% -----------------------------------------------


% ----- CALCULATE batPwrLoss AND batPwr ---------
% % preallocate matrix with dims (timNim x (# of bat steps) x geaNum)
% batPwrMinLossTn3 = zeros(length(batRstMin), length(batOcv), geaNum);
% batPwrMaxLossTn3 = zeros(length(batRstMax), length(batOcv), geaNum);
batPwrMinTn3     = zeros(length(batRstMin), length(batOcv), geaNum); 
batPwrMaxTn3     = zeros(length(batRstMax), length(batOcv), geaNum);
batPwrDemTn3     = zeros(timNum,            length(batOcv), geaNum);
% NOTE: this preprocessing is a bit slow because of lack of vectorization.
% may be able to speed up later, but since it is in preprocessing, it is
% low priority at the moment

% run battery power limitations for the entire speed profile timelength
for tim = 1 : timNum
    % bat index is for varying battery voltage levels
    for bat = 1 : length(batOcv)
        % gear is for looping through diff resistance and emoPwr bound values
        for gea = 1 : geaNum 
            % internal battery power losses: quadratic equation derived from
            %   batPwrLoss = I^2*batRst,
            %   batPwr     = V*I, and
            %   batPwr - batPwrLoss = emoPwr (where emoPwr is given).
            %   
            % batPwrMin/MaxLossMat calculated in two combined steps:
            %   1. substituting batPwr and batPwrLoss into 3rd equation and solving
            %       for current I.
            %   2. plugging the found current I back into the batPwrLoss eq and
            %       solving for batPwrLoss (batRst was already preprocessed above).
            batPwrMinLoss = ((batOcv(bat)-sqrt(batOcv(bat).^2 - 4*batRstMin(tim, gea) * ...
                                        emoPwrMinPosMat(tim,gea))).^2) / ...
                                        (4*batRstMin(tim, gea));
            batPwrMaxLoss = ((batOcv(bat)-sqrt(batOcv(bat).^2 - 4*batRstMax(tim, gea) * ...
                                        emoPwrMaxPosMat(tim,gea))).^2) / ...
                                        (4*batRstMax(tim, gea));
                                    
            batPwrDemLoss = ((batOcv(bat)-sqrt(batOcv(bat).^2 - 4*batRstMax(tim, gea) * ...
                                        crsPwrMat(tim,gea))).^2) / ...
                                        (4*batRstMax(tim, gea));

            % calculate boundaries that battery can (dis)charge at
            %   in other words, calculate all possible batPwr values across emoSpd
            %   indexes for EQUATION:
            %       batPwr = emoPwr + batPwrLoss
            batPwrMinTn3(tim, bat, gea)   = batPwrMinLoss + emoPwrMinPosMat(tim, gea);
            batPwrMaxTn3(tim, bat, gea)   = batPwrMaxLoss + emoPwrMaxPosMat(tim, gea);  
            batPwrDemTn3(tim, bat, gea)   = batPwrDemLoss + crsPwrMat(tim, gea);
        end
    end
end
% -----------------------------------------------

% ----- DISCRETIZE batPwrMin/Mat's --------------
% discretize the batPwrMin/Mat matrices to the batEngStp value
batPwrStp = tst_scalar_struct.batEngStp / timStp;
batPwrMaxIdxTn3 = floor(batPwrMaxTn3 ./ batPwrStp);
batPwrMinIdxTn3 = ceil(batPwrMinTn3 ./ batPwrStp);
batPwrDemIdxTn3 = ceil(batPwrDemTn3 ./ batPwrStp);
% -----------------------------------------------

%% define vector for possibilities of engine state on-off values
%   2 = can toggle (two states, on-of)
%   1 = cannot toggle, must stay in current state for idx (most likely off)
engStaVec_timInx = ones(timInxEnd, 1)*2;
engStaVec_timInx(timInxBeg) = engBeg+1;
engStaVec_timInx(timInxEnd) = engEnd+1;

%% define battery looping vector
% make sure that the max/min electric power values are discretized right
if mod(fzg_scalar_struct.batPwrMax, tst_scalar_struct.batEngStp)
    fprintf('Note: E'' limits weren''t discretized to E'' step size.\n');
    fprintf('   Old max E'': %i\n',   fzg_scalar_struct.batPwrMax);
    fprintf('   Old min E'': %i\n',   fzg_scalar_struct.batPwrMin);
    fzg_scalar_struct.batPwrMax=floor(fzg_scalar_struct.batPwrMax / tst_scalar_struct.batEngStp)...
                                    * tst_scalar_struct.batEngStp;
    fzg_scalar_struct.batPwrMin=ceil( fzg_scalar_struct.batPwrMin / tst_scalar_struct.batEngStp) ...
                                    * tst_scalar_struct.batEngStp;
    fprintf('   New max E'': %i\n',   fzg_scalar_struct.batPwrMax);
    fprintf('   New min E'': %i\n',   fzg_scalar_struct.batPwrMin);
    fprintf('   E'' step size used: %i\n', tst_scalar_struct.batEngStp);
end

%% Calculating optimal predecessors with DP
% two functions: one finding optimal gear state and one with input gea vals
fprintf('-Initializing model...\n');
% if tst_scalar_struct.useGeaSta
        [               ... --- Ausgangsgr��en:
        optPreInxTn3,   ...  Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
        batFrcOptTn3,   ...  Tensor 3. Stufe der Batteriekraft
        fulEngOptTn3,   ...  Tensor 3. Stufe f�r die Kraftstoffenergie 
        cos2goActMat    ...  Matrix der optimalen Kosten der Hamiltonfunktion 
        ] =             ... 
        clcDP_focus     ... FUNKTION
        (               ... --- Eingangsgr��en:
        disFlg,         ... Skalar - Flag f�r Ausgabe in das Commandwindow
        iceFlgBool,     ... skalar - is engine toggle on/off allowed?
        brkBool,        ... skalar - allow states requireing braking?
        timStp,         ... Skalar f�r die Wegschrittweite in m
        batEngBeg,      ... Skalar f�r die Batterieenergie am Beginn in Ws
        batPwrAux,      ... Skalar f�r die Nebenverbrauchlast in W
        staChgPenCosVal,... Skalar f�r die Strafkosten beim Zustandswechsel
        timInxBeg,      ... Skalar f�r Anfangsindex in den Eingangsdaten
        timInxEnd,      ... Skalar f�r Endindex in den Eingangsdaten
        timNum,         ... Skalar f�r die max. Anzahl an Wegst�tzstellen
        engBeg,         ... scalar - beginnnig engine state
        engStaVec_timInx,...
        staBeg,         ... Skalar f�r den Startzustand des Antriebsstrangs
        batOcv,         ... battery voltage vector w/ value for each SOC
        velVec,         ... velocity vector contiaing input speed profile
        crsSpdMat,      ... crankshaft speed demand for each gear
        crsTrqMat,      ... crankshaft torque demand for each gear
        emoTrqMinPosMat,... min emoTrq along speed profile for each gear
        emoTrqMaxPosMat,... max emoTrq along speed profile for each gear
        emoPwrMinPosMat,... min emoPwr along speed profile for each gear
        emoPwrMaxPosMat,... max emoPwr along speed profile for each gear
        iceTrqMinPosMat,... min iceTrq along speed profile for each gear
        iceTrqMaxPosMat,... max iceTrq along speed profile for each gear
        batPwrMinIdxTn3,... min indexes/steps that bat can change
        batPwrMaxIdxTn3,... max indexes/steps that bat can change
        batPwrDemIdxTn3,... power demand by bat if only EM is running
        tst_scalar_struct,     ... struct w/ tst data state var params
        fzg_scalar_struct,     ... struct der Fahrzeugparameter - NUR SKALARS
        fzg_array_struct       ... struct der Fahrzeugparameter - NUR ARRAYS
        );