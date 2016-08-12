function                ... --- Ausgangsgrößen:
[                       ...
    batEngDltOptMat,    ... Vektor - optimale Batterieenergieänderung
    fulVolOptOptMat,    ... Vektor - optimale Kraftstoffenergieänderung
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
    batEngBeg,          ... Skalar für die Batterieenergie am Beginn in Ws
    timVec,             ... Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen
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
[                       ... --- Ausgangsgrößen:
    optPreInxTn4,       ...  Tensor 4. Stufe für opt. Vorgängerkoordinaten
    batPwrOptTn4,       ...  Tensor 4. Stufe der Batteriekraft
    fulEngOptTn4,       ...  Tensor 4. Stufe für die Kraftstoffenergie 
    emoTrqOptTn4,       ... tensor - saves optimal emoTrq values
    iceTrqOptTn4,       ... tensor - saves optimal iceTrq values
    brkTrqOptTn4,       ... tensor - saves optimal brkTrq values
    cos2goActTn3        ...  Tensor 4. der optimalen Kosten
] =                     ... 
    clcDP_focus_mex     ... FUNKTION
(                       ... --- Eingangsgrï¿½ï¿½en:
    batEngBeg,          ... Skalar fï¿½r die Batterieenergie am Beginn in Ws
    length(timVec),     ... Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen
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

else
% sample input gear input vector
  geaStaMat = load('geaStaMat');
  geaStaVec = geaStaMat.geaStaMat;

% DP that requires a gear input vector
[                       ... --- Ausgangsgrï¿½ï¿½en:
    optPreInxTn3,       ... Tensor 4. Stufe für opt. Vorgängerkoordinaten
    batPwrOptTn3,       ... Tensor 4. Stufe der Batteriekraft
    fulEngOptTn3,       ... Tensor 4. Stufe für die Kraftstoffenergie 
    emoTrqOptTn3,       ... tensor - saves optimal emoTrq values
    iceTrqOptTn3,       ... tensor - saves optimal iceTrq values
    brkTrqOptTn3,       ... tensor - saves optimal brkTrq values
    cos2goActMat        ... Tensor 4. der optimalen Kosten
] =                     ... 
    clcDP_focus_useGeaVec_mex... FUNKTION
(                       ... --- Eingangsgrï¿½ï¿½en:
    batEngBeg,          ... Skalar fï¿½r die Batterieenergie am Beginn in Ws
    length(timVec),     ... Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen
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
    emoTrqOptTn = emoTrqOptTn4;
    iceTrqOptTn = iceTrqOptTn4;
    brkTrqOptTn = brkTrqOptTn4;
else
    optPreInxTn = optPreInxTn3;
    batPwrOptTn = batPwrOptTn3;
    fulEngOptTn = fulEngOptTn3;
    emoTrqOptTn = emoTrqOptTn3;
    iceTrqOptTn = iceTrqOptTn3;
    brkTrqOptTn = brkTrqOptTn3;
    cos2goActTn = cos2goActMat;  
end

% convert fulEng to fulVol - units work out
% units are : J / (J/kg) / (kg/L)
fulVolOptTn = fulEngOptTn / fzg_scalar_struct.fuel_lower_heating_value / ...
                            fzg_scalar_struct.fulDen;
% function call
[   batEngDltOptMat,    ... Vektor - optimale Batterieenergieï¿½nderung
    fulVolOptOptMat,    ... Vektor - optimale Kraftstoffenergieï¿½nderung
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
    timVec,             ... time vector for speed profile
    velVec,             ... speed vector for speed profile
    engStaVec_timInx,   ... vector - displays number of possible eng states
    crsSpdMat,          ... matrix - predetermined crankshaft speed demand
    optPreInxTn,        ... Tensor . Stufe fï¿½r opt. Vorgï¿½ngerkoordinaten
    batPwrOptTn,        ... Tensor . Stufe der Batteriekraft
    fulVolOptTn,        ... Tensor . Stufe fï¿½r die Kraftstoffenergie
    cos2goActTn,        ... Tensor der optimalen Kosten
    emoTrqOptTn,        ... tensor containing optimal emoTrq values
    iceTrqOptTn,        ... 
    brkTrqOptTn,        ...
    inputparams,        ...
    tst_scalar_struct   ...
);

% if ~tst_scalar_struct.useGeaSta
%     save('geaStaMat', 'geaStaMat');
% end

end