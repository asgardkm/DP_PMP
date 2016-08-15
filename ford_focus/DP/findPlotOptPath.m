function [              ...
    batEngDltOptMat,    ... Vektor - optimale Batterieenergie�nderung
    fulEngDltOptMat,    ... Vektor - optimale Kraftstoffenergie�nderung
    geaStaMat,          ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat,          ... vector showing optimal engine contorl w/ profile
    batPwrMat,          ... vector showing optimal battery level control
    batEngMat,          ... vector showing optimal battery levels
    emoTrqMat,          ...
    iceTrqMat,          ...
    brkTrqMat,          ...
    fulEngOptVec        ... Skalar - optimale Kraftstoffenergie
] =                     ...
    findPlotOptPath     ...
(                       ...
    timVec,             ... vector - time vector
    velVec,             ... vector - velocity 
    engStaVec_timInx,   ...
    crsSpdMat,          ...
    optPreInxTn,        ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn,        ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn,        ... Tensor 3. Stufe f�r die Kraftstoffenergie
    cos2goActTn,        ... Matrix der optimalen Kosten der Hamiltonfunktion
    emoTrqOptTn,        ...
    iceTrqOptTn,        ...
    brkTrqOptTn,        ...
    inputparams,        ...
    tst_scalar_struct   ...
)
%% end conditions 
% boundary conditions the end battery energy must be within bounds of
batEngEndMin = floor(tst_scalar_struct.batEngMax *  ...
                     inputparams.batEngEndMinRat /  ...
                     tst_scalar_struct.batEngStp) * ...
                     tst_scalar_struct.batEngStp;
                 
batEngEndMax = ceil(tst_scalar_struct.batEngMax *   ...
                    inputparams.batEngEndMaxRat /   ...
                    tst_scalar_struct.batEngStp) *  ...
                    tst_scalar_struct.batEngStp;

% end end engine state
engEndEnd = engStaVec_timInx(inputparams.timInxEnd) - 1;
% end gear condition
staEnd = inputparams.staBeg;
% end engine condition
engEnd = inputparams.engEnd;

% % selecting all end battery charge conditions
batEngEndMinIdx  = batEngEndMin / tst_scalar_struct.batEngStp + 1;
batEngEndMaxIdx  = batEngEndMax / tst_scalar_struct.batEngStp + 1;

batEndInxVec = batEngEndMinIdx : batEngEndMaxIdx;
% batEndInxVec = batEngBeg/tst_scalar_struct.batEngStp : batEngBeg/tst_scalar_struct.batEngStp;

batStaNum = (tst_scalar_struct.batEngMax - tst_scalar_struct.batEngMin) / ...
            tst_scalar_struct.batEngStp + 1;
        
%% Calculating optimal trajectories for result of DP + PMP
% preallocate matrices for holding all optimal combinations
batEngDltOptMat = inf(length(timVec), length(batEndInxVec));
fulEngDltOptMat = inf(length(timVec), length(batEndInxVec));
geaStaMat       = inf(length(timVec), length(batEndInxVec));
engStaMat       = inf(length(timVec), length(batEndInxVec));
batPwrMat       = inf(length(timVec), length(batEndInxVec));
batEngMat       = inf(length(timVec), length(batEndInxVec));
emoTrqMat       = inf(length(timVec), length(batEndInxVec));
iceTrqMat       = inf(length(timVec), length(batEndInxVec));
brkTrqMat       = inf(length(timVec), length(batEndInxVec));
fulEngOptVec    = inf(length(batEndInxVec), 1);
crsSpdOptMat    = inf(length(timVec), length(batEndInxVec));

fprintf('Generating all optimal paths from ending SOC levels %2.0f%% to %2.0f%%\n', ...
        inputparams.batEngEndMinRat*100, inputparams.batEngEndMaxRat*100);

if ~tst_scalar_struct.useGeaSta
    for batEndInx_counter = 1 : length(batEndInxVec)
        batEndInx = batEndInxVec(batEndInx_counter);
    [...
        batEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Batterieenergie�nderung
        fulEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Kraftstoffenergie�nderung
        geaStaMat(:, batEndInx_counter),        ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
        engStaMat(:, batEndInx_counter),        ... vector showing optimal engine contorl w/ profile
        batPwrMat(:, batEndInx_counter),        ... vector showing optimal battery level control
        batEngMat(:, batEndInx_counter),        ... vector showing optimal battery levels
        emoTrqMat(:, batEndInx_counter),        ...
        iceTrqMat(:, batEndInx_counter),        ...
        brkTrqMat(:, batEndInx_counter),        ...
        fulEngOptVec(batEndInx_counter)         ... Skalar - optimale Kraftstoffenergie
    ] =                             ...
        clcOptTrj_focus             ... FUNKTION
        (timVec,                    ... Skalar f�r die max. Anzahl an Wegst�tzstellen
        staEnd,                     ... Skalar f�r den finalen Zustand
        engEnd,                     ... scalar - final engine state
        engEndEnd,                  ... Skalar f�r Zielindex der kinetischen Energie
        batEndInx,                  ... scalar - final battery state
        batStaNum,                  ... scalar - for number of battery energy levels
        optPreInxTn,                ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
        batPwrOptTn,                ... Tensor 3. Stufe der Batteriekraft
        fulEngOptTn,                ... Tensor 3. Stufe f�r die Kraftstoffenergie
        cos2goActTn,                ... Matrix der optimalen Kosten der Hamiltonfunktion 
        emoTrqOptTn,                ...
        iceTrqOptTn,                ...
        brkTrqOptTn,                ...
        inputparams,                ...
        tst_scalar_struct           ...
        );

        if inputparams.disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(batEndInx_counter-1), double(((batEndInx_counter-1))) /...
                double(length(batEndInxVec)-1)*100);
        end
    end
else
    for batEndInx_counter = 1 : length(batEndInxVec)
        batEndInx = batEndInxVec(batEndInx_counter);
    [...
        batEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Batterieenergie�nderung
        fulEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Kraftstoffenergie�nderung
        engStaMat(:, batEndInx_counter),        ... vector showing optimal engine contorl w/ profile
        batPwrMat(:, batEndInx_counter),        ... vector showing optimal battery level control
        batEngMat(:, batEndInx_counter),        ... vector showing optimal battery levels
        emoTrqMat(:, batEndInx_counter),        ...
        iceTrqMat(:, batEndInx_counter),        ...
        brkTrqMat(:, batEndInx_counter),        ...
        fulEngOptVec(batEndInx_counter)         ... Skalar - optimale Kraftstoffenergie
    ] =                                         ...
        clcOptTrj_focus_useGeaVec               ... FUNKTION
    (                   ...
        timVec,         ... Skalar f�r die max. Anzahl an Wegstützstellen
        engEnd,         ... scalar - prefinal engine state
        engEndEnd,      ... Skalar f�r Zielindex der kinetischen Energie
        batEndInx,      ... scalar - final battery state
        batStaNum,      ... scalar - for number of battery states exist
        optPreInxTn,    ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
        batPwrOptTn,    ... Tensor 3. Stufe der Batteriekraft
        fulEngOptTn,    ... Tensor 3. Stufe f�r die Kraftstoffenergie
        cos2goActTn,    ... Matrix der optimalen Kosten der Hamiltonfunktion 
        emoTrqOptTn,    ...
        iceTrqOptTn,    ...
        brkTrqOptTn,    ...
        inputparams,    ...
        tst_scalar_struct...
        );

        if inputparams.disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(batEndInx_counter-1), double(((batEndInx_counter-1))) /...
                double(length(batEndInxVec)-1)*100);
        end
    end
    % sample input gear input vector
      geaStaMatAll = load('geaStaMat');
      geaStaMatAll = geaStaMatAll.geaStaMat;
      geaStaMat = geaStaMatAll(:, batEndInxVec);
end

fprintf('\n\ndone!\n');

%% determine the crankshaft demand
% populate the optimal crsSpd and torques demand
% batStaMatIdx = batEngMat/tst_scalar_struct.batEngStp + 1;
for tim = 1 : length(timVec)
   crsSpdOptMat(tim, :) = crsSpdMat(tim, geaStaMat(tim, :));
%    for bat = 1 : length(batEndInxVec)
%         emoTrqOptMat(tim, bat) = emoTrqMat(tim, batStaMatIdx(tim, bat));
%         iceTrqOptMat(tim, bat) = iceTrqMat(tim, batStaMatIdx(tim, bat));
%         brkTrqOptMat(tim, bat) = brkTrqMat(tim, batStaMatIdx(tim, bat));
%    end
end

%% PLOTS
% batEng trajectories for all ending SOC possibilities (currently 30%-90%)
xString = 'Time [sec]';
figure(1)
subplot(3,2,1)
batEngMatSOC = batEngMat / tst_scalar_struct.batEngMax;
titleString = 'batEng trajectories for optimal paths';
yString = 'SOC [%]';
plotGrad(timVec, batEngMatSOC, batEndInxVec, titleString, xString, yString);

% fuel trajectories for all ending SOC possibilities (currently 30%-90%)
subplot(3,2,2)
titleString = 'fuel trajectories for optimal paths';
yString = 'Fuel Use [L]';
plotGrad(timVec, fulEngDltOptMat, batEndInxVec, titleString, xString, yString);

% velocity vector
subplot(3,2,3)
titleString = 'Vehicle velocity profile';
yString = 'Velocity [m/sec]';
plot(timVec, velVec);
title(titleString);
xlabel(xString);
ylabel(yString);

% crankshaft demand
subplot(3,2,4)
titleString = 'Crankshaft speed demand profile';
yString = 'Rotational Speed []';
plotGrad(timVec, crsSpdOptMat, batEndInxVec, titleString, xString, yString);

% gear selection
subplot(3,2,5)
titleString = 'Optimum gear selection';
yString = 'Gear Number';
plotGrad(timVec, geaStaMat, batEndInxVec, titleString, xString, yString);

% engine on-off selection
subplot(3,2,6)
titleString = 'Optimum engine control';
yString = 'Bool On-Off';
plotGrad(timVec, engStaMat, batEndInxVec, titleString, xString, yString);

% torques:
% emoTrq
figure(2)
subplot(3,1,1)
titleString = 'EM torque profile';
yString = 'Torque [N*m]';
plotGrad(timVec, emoTrqMat, batEndInxVec, titleString, xString, yString);

% iceTrq
subplot(3,1,2)
titleString = 'ICE torque profile';
yString = 'Torque [N*m]';
plotGrad(timVec, iceTrqMat, batEndInxVec, titleString, xString, yString);

% brkTrq
subplot(3,1,3)
titleString = 'Braking torque profile';
yString = 'Torque [N*m]';
plotGrad(timVec, brkTrqMat, batEndInxVec, titleString, xString, yString);

%% start plotting figs for report
figure(3)
titleString = 'NEDC velocity profile';
yString = 'Velocity [km/h]';
% convert velocity into km/h
velVec_KMH = velVec * 60 * 60 / 1000;
plot(timVec, velVec_KMH);
title(titleString);
xlabel(xString);
ylabel(yString);

fzg_array_struct.batOcvCof_batEng
end