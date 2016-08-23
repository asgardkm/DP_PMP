function                ... --- Ausgangsgr��en:
[                       ...
    batEngDltOptMat,    ... Vektor - optimale Batterieenergie�nderung
    fulVolOptOptMat,    ... Vektor - optimale Kraftstoffenergie�nderung
    geaStaMat,          ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat,          ... vector showing optimal engine contorl w/ profile
    batPwrMat,          ... vector showing optimal battery level control
    batEngMat,          ... vector showing optimal battery levels
    emoTrqMat,          ...
    iceTrqMat,          ...
    brkTrqMat,          ...
    fulEngOptVec        ... Skalar - optimale Kraftstoffenergie
] =                     ...
    runFocusDP          ...
(                       ...
    inputparams,        ...
    tst_scalar_struct,  ...
    fzg_scalar_struct,  ...
    nedc_array_struct,  ...
    fzg_array_struct    ...
)%#codegen
% function: run preprocessing, DP algorithm, find optimal paths for given
% ending SOC level, and create result figures

%% run data preprocessing
fprintf('Beginning data preprocessing...\n');
[                       ...
    batEngBeg,          ... Skalar f�r die Batterieenergie am Beginn in Ws
    timVec,             ... Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen
    engStaVec_timInx,   ... scalar - end engine state
    batOcv,             ... battery voltage vector w/ value for each SOC
    velVec,             ... velocity vector contiaing input speed profile
    crsSpdMat,          ... crankshaft speed demand for each gear
    crsTrqMat,          ... crankshaft torque demand for each gear
    emoTrqMinPosMat,    ... min emoTrq along speed profile for each gear
    emoTrqMaxPosMat,    ... max emoTrq along speed profile for each gear
    emoPwrMinPosMat,    ... min emoPwr along speed profile for each gear
    emoPwrMaxPosMat,    ... max emoPwr along speed profile for each gear
    iceTrqMinPosMat,    ... min iceTrq along speed profile for each gear
    iceTrqMaxPosMat,    ... max iceTrq along speed profile for each gear
    batPwrMinIdxTn3,    ... min indexes/steps that bat can change
    batPwrMaxIdxTn3,    ... max indexes/steps that bat can change
    batPwrDemIdxTn3,    ... bat power demand if only EM is running
    inputparams,        ...
    tst_scalar_struct,  ... struct w/ tst data state var params
    fzg_scalar_struct,  ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct    ... struct der Fahrzeugparameter - NUR ARRAYS] = ...
] =                     ...
    runDP_preProcessing ...
(                       ...
    inputparams,        ...
    tst_scalar_struct,  ...
    fzg_scalar_struct,  ...
    nedc_array_struct,  ...
    fzg_array_struct    ...
);
fprintf('Done preprocessing!\n');
%% Calculating optimal predecessors with DP
% two functions: one finding optimal gear state and one with input gea vals
fprintf('-Initializing model...\n'); 
tic
% DP that is calculating optimal gear state
if ~tst_scalar_struct.useGeaSta
    tic
[                       ... --- Ausgangsgr��en:
    optPreInxTn4,       ...  Tensor 4. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn4,       ...  Tensor 4. Stufe der Batteriekraft
    fulEngOptTn4,       ...  Tensor 4. Stufe f�r die Kraftstoffenergie 
    emoTrqOpt1Tn4,      ...  tensor - saves optimal emoTrq values
    emoTrqOpt2Tn4,      ...
    iceTrqOptTn4,       ...  tensor - saves optimal iceTrq values
    brkTrqOptTn4,       ...  tensor - saves optimal brkTrq values
    cos2goActTn3        ...  Tensor 4. der optimalen Kosten
] =                     ... 
    clcDP_focus_emoPwrElectricOnly         ... FUNKTION
(                       ... --- Eingangsgr��en:
    batEngBeg,          ... Skalar f�r die Batterieenergie am Beginn in Ws
    length(timVec),     ... Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen
    engStaVec_timInx,   ... scalar - end engine state
    batOcv,             ... battery voltage vector w/ value for each SOC
    velVec,             ... velocity vector contiaing input speed profile
    crsSpdMat,          ... crankshaft speed demand for each gear
    crsTrqMat,          ... crankshaft torque demand for each gear
    emoTrqMinPosMat,    ... min emoTrq along speed profile for each gear
    emoTrqMaxPosMat,    ... max emoTrq along speed profile for each gear
    emoPwrMinPosMat,    ... min emoPwr along speed profile for each gear
    emoPwrMaxPosMat,    ... max emoPwr along speed profile for each gear
    iceTrqMinPosMat,    ... min iceTrq along speed profile for each gear
    iceTrqMaxPosMat,    ... max iceTrq along speed profile for each gear
    batPwrMinIdxTn3,    ... min indexes/steps that bat can change
    batPwrMaxIdxTn3,    ... max indexes/steps that bat can change
    batPwrDemIdxTn3,    ... bat power demand if only EM is running
    inputparams,        ... struct for input model parameters
    tst_scalar_struct,  ... struct w/ tst data state var params
    fzg_scalar_struct,  ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct    ... struct der Fahrzeugparameter - NUR ARRAYS
);
toc

else
% sample input gear input vector
  geaStaMat = load('geaStaMat');
  geaStaVec = geaStaMat.geaStaMat;
tic
% DP that requires a gear input vector
[                       ... --- Ausgangsgr��en:
    optPreInxTn3,       ... Tensor 4. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn3,       ... Tensor 4. Stufe der Batteriekraft
    fulEngOptTn3,       ... Tensor 4. Stufe f�r die Kraftstoffenergie 
    emoTrqOptTn3,       ... tensor - saves optimal em  oTrq values
    iceTrqOptTn3,       ... tensor - saves optimal iceTrq values
    brkTrqOptTn3,       ... tensor - saves optimal brkTrq values
    cos2goActMat        ... Tensor 4. der optimalen Kosten
] =                     ... 
    clcDP_focus_useGeaVec_emoPwrElectricOnly... FUNKTION
(                       ... --- Eingangsgr��en:
    batEngBeg,          ... Skalar f�r die Batterieenergie am Beginn in Ws
    length(timVec),     ... Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen
    engStaVec_timInx,   ... scalar - end engine state
    batOcv,             ... battery voltage vector w/ value for each SOC
    velVec,             ... velocity vector contiaing input speed profile
    geaStaVec,          ... gear state input vector
    crsSpdMat,          ... crankshaft speed demand for each gear
    crsTrqMat,          ... crankshaft torque demand for each gear
    emoTrqMinPosMat,    ... min emoTrq along speed profile for each gear
    emoTrqMaxPosMat,    ... max emoTrq along speed profile for each gear
    emoPwrMinPosMat,    ... min emoPwr along speed profile for each gear
    emoPwrMaxPosMat,    ... max emoPwr along speed profile for each gear
    iceTrqMinPosMat,    ... min iceTrq along speed profile for each gear
    iceTrqMaxPosMat,    ... max iceTrq along speed profile for each gear
    batPwrMinIdxTn3,    ... min indexes/steps that bat can change
    batPwrMaxIdxTn3,    ... max indexes/steps that bat can change
    batPwrDemIdxTn3,    ... bat power demand if only EM is running
    inputparams,        ... struct for input model parameters
    tst_scalar_struct,  ... struct w/ tst data state var params
    fzg_scalar_struct,  ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct    ... struct der Fahrzeugparameter - NUR ARRAYS
);
toc
end

%% optimal path and plot function

% note: if you wish to overwrite the SOC min and max end bounds previously
% set in ../model_data/mainConfig_focus.txt for the following function, you
% may do so here
inputparams.batEngEndMinRat = 0;
inputparams.batEngEndMaxRat = 1;

% prepare inputs to findPlotOptPath, depending if gear is considered as
% a state variable
if ~tst_scalar_struct.useGeaSta
    optPreInxTn = optPreInxTn4;
    batPwrOptTn = batPwrOptTn4;
    fulEngOptTn = fulEngOptTn4;
    cos2goActTn = cos2goActTn3;  
    emoTrqOpt1Tn = emoTrqOpt1Tn4;
    emoTrqOpt2Tn = emoTrqOpt2Tn4;
    iceTrqOptTn = iceTrqOptTn4;
    brkTrqOptTn = brkTrqOptTn4;
else
    optPreInxTn = optPreInxTn3;
    batPwrOptTn = batPwrOptTn3;
    fulEngOptTn = fulEngOptTn3;
    emoTrqOpt1Tn = emoTrqOptTn3;
    emoTrqOpt2Tn = emoTrqOpt2Tn3;
    iceTrqOptTn = iceTrqOptTn3;
    brkTrqOptTn = brkTrqOptTn3;
    cos2goActTn = cos2goActMat;  
end


iceSpdMin =  fzg_array_struct.iceSpdMgd(1,1);
% function call
[   batEngDltOptMat,    ... Vektor - optimale Batterieenergie�nderung
    fulVolOptOptMat,    ... Vektor - optimale Kraftstoffenergie�nderung
    geaStaMat,          ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat,          ... vector showing optimal engine contorl w/ profile
    batPwrMat,          ... vector showing optimal battery level control
    batEngMat,          ... vector showing optimal battery levels
    emoTrq1Mat,         ...
    emoTrq2Mat,         ...,          ...
    iceTrqMat,          ...
    brkTrqMat,          ...
    fulEngOptVec        ... Skalar - optimale Kraftstoffenergie
] =                     ...
    findPlotOptPath     ...
(                       ...
    timVec,             ... time vector for speed profile
    velVec,             ... speed vector for speed profile
    engStaVec_timInx,   ... vector - displays number of possible eng states
    crsSpdMat,          ... matrix - predetermined crankshaft speed demand
    crsTrqMat,          ...
    optPreInxTn,        ... Tensor . Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn,        ... Tensor . Stufe der Batteriekraft
    fulVolOptTn,        ... Tensor . Stufe f�r die Kraftstoffenergie
    cos2goActTn,        ... Tensor der optimalen Kosten
    emoTrqOpt1Tn,       ... tensor containing optimal emoTrq values
    emoTrqOpt2Tn,       ...
    iceTrqOptTn,        ... 
    brkTrqOptTn,        ...
    inputparams,        ...
    tst_scalar_struct,  ...
    iceSpdMin...
);

if ~tst_scalar_struct.useGeaSta
    save('geaStaMat', 'geaStaMat');
end

end