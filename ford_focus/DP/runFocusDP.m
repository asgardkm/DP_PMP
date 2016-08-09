function ...            --- Ausgangsgrößen:
[   batEngDltOptMat,  ... Vektor - optimale Batterieenergieänderung
    fulEngDltOptMat,  ... Vektor - optimale Kraftstoffenergieänderung
    geaStaMat,        ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat,        ... vector showing optimal engine contorl w/ profile
    batPwrMat,        ... vector showing optimal battery level control
    batEngMat,        ... vector showing optimal battery levels
    fulEngOptVec      ... Skalar - optimale Kraftstoffenergie
    ] =               ...
    runFocusDP(       ...
    inputparams,      ...
    tst_scalar_struct,...
    fzg_scalar_struct,...
    nedc_array_struct,...
    fzg_array_struct  ...
    )%#codegen
% function: run preprocessing, DP algorithm, and optimal bath for given
% ending SOC level(s) (plus figures)

%% run data preprocessing
[   batEngBeg,          ... Skalar für die Batterieenergie am Beginn in Ws
    timNum,             ... Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen
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
] = runDP_preProcessing(...
    inputparams,        ...
    tst_scalar_struct,  ...
    fzg_scalar_struct,  ...
    nedc_array_struct,  ...
    fzg_array_struct    ...
);

%% Calculating optimal predecessors with DP
% two functions: one finding optimal gear state and one with input gea vals
fprintf('-Initializing model...\n'); 
tic
% DP that is calculating optimal gear state
if ~tst_scalar_struct.useGeaSta
    [                   ... --- Ausgangsgrößen:
    optPreInxTn4,       ...  Tensor 4. Stufe für opt. Vorgängerkoordinaten
    batPwrOptTn4,       ...  Tensor 4. Stufe der Batteriekraft
    fulEngOptTn4,       ...  Tensor 4. Stufe für die Kraftstoffenergie 
    cos2goActTn3        ...  Tensor 4. der optimalen Kosten
    ] =                 ... 
    clcDP_focus_mex         ... FUNKTION
    (                   ... --- Eingangsgrï¿½ï¿½en:
    batEngBeg,          ... Skalar fï¿½r die Batterieenergie am Beginn in Ws
    timNum,             ... Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen
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
    fzg_array_struct    ... struct der Fahrzeugparameter - NUR ARRAYS
    );
else
% sample input gear input vector:
%   geaStaVec = [geaStaMat(1:end-1); geaStaMat(end-1)]; 

% DP that requires a gear input vector
    [                   ... --- Ausgangsgrï¿½ï¿½en:
    optPreInxTn3,       ...  Tensor 4. Stufe für opt. Vorgängerkoordinaten
    batPwrOptTn3,       ...  Tensor 4. Stufe der Batteriekraft
    fulEngOptTn3,       ...  Tensor 4. Stufe für die Kraftstoffenergie 
    cos2goActMat        ...  Tensor 4. der optimalen Kosten
    ] =                 ... 
    clcDP_focus_useGeaVec     ... FUNKTION
    (                   ... --- Eingangsgrï¿½ï¿½en:
    batEngBeg,          ... Skalar fï¿½r die Batterieenergie am Beginn in Ws
    timNum,             ... Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen
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
    inputparams,        ...
    tst_scalar_struct,  ... struct w/ tst data state var params
    fzg_scalar_struct,  ... struct der Fahrzeugparameter - NUR SKALARS
    fzg_array_struct    ... struct der Fahrzeugparameter - NUR ARRAYS
    );
end

%% optimal path and plot function

% note: if you wish to overwrite the SOC min and max end bounds previously
% set in ../model_data/mainConfig_focus.txt for the following function, you
% may do so here
inputparams.batEngEndMinRat = 0.3;
inputparams.batEngEndMaxRat = 0.9;

if ~tst_scalar_struct.useGeaSta
    % function call
    [   batEngDltOptMat,    ... Vektor - optimale Batterieenergieï¿½nderung
        fulEngDltOptMat,    ... Vektor - optimale Kraftstoffenergieï¿½nderung
        geaStaMat,          ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
        engStaMat,          ... vector showing optimal engine contorl w/ profile
        batPwrMat,          ... vector showing optimal battery level control
        batEngMat,          ... vector showing optimal battery levels
        fulEngOptVec        ... Skalar - optimale Kraftstoffenergie
    ] = findPlotOptPath(    ...
        timVec,             ...
        engStaVec_timInx,   ...
        optPreInxTn4,       ... Tensor 3. Stufe fï¿½r opt. Vorgï¿½ngerkoordinaten
        batPwrOptTn4,       ... Tensor 3. Stufe der Batteriekraft
        fulEngOptTn4,       ... Tensor 3. Stufe fï¿½r die Kraftstoffenergie
        cos2goActTn3,       ... Matrix der optimalen Kosten der Hamiltonfunktion
        inputparams,        ...
        tst_scalar_struct   ...
    );
else
    [   batEngDltOptMat,    ... Vektor - optimale Batterieenergieï¿½nderung
        fulEngDltOptMat,    ... Vektor - optimale Kraftstoffenergieï¿½nderung
        engStaMat,          ... vector showing optimal engine contorl w/ profile
        batPwrMat,          ... vector showing optimal battery level control
        batEngMat,          ... vector showing optimal battery levels
        fulEngOptVec        ... Skalar - optimale Kraftstoffenergie] =           ...
    ] = findPlotOptPath_useGeaVec(    ...
        timVec,             ...
        engStaVec_timInx,   ...
        optPreInxTn3,      ...  Tensor 4. Stufe für opt. Vorgängerkoordinaten
        batPwrOptTn3,       ...  Tensor 4. Stufe der Batteriekraft
        fulEngOptTn3,       ...  Tensor 4. Stufe für die Kraftstoffenergie 
        cos2goActMat,       ...  Tensor 4. der optimalen Kosten
        inputparams,        ...
        tst_scalar_struct   ...
    );    
end

end