function ...            --- Ausgangsgrößen:
[engKinOptVec,      ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,... Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergieänderung
    staVec,         ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate für kinetische Energie
    fulEngOpt,      ... Skalar - optimale Kraftstoffenergie
    resVld          ...
    ] =             ...
    clcDP_port(     ...
    disFlg,         ...
    wayStp,         ...
    batEngStp,      ...
    batEngBeg,      ...
    batPwrAux,      ...
    psiBatEng,      ...
    psiTim,         ...
    staChgPenCosVal,...
    wayInxBeg,      ...
    wayInxEnd,      ...
    staBeg          ...
    )%#codegen
%% Laden der Modelldaten
% cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\c_port');
fprintf('-Loading model data and parameters...');

% saved structure data from './model data'
FZG = load('vehMdl');
% % Inhalt des Parameter-Structs par in den Workspace schreiben
%  -- Inahlt = Content

% input dummy engKinBegInx value for function
engKinBegInx = zeros(1,1);
engKinBegInx = 1;

tstDat800 = load('tstDat800');
staNum = tstDat800.staNum;
wayNum = tstDat800.wayNum;
engKinNum = tstDat800.wayNum;
slpVec_wayInx = tstDat800.slpVec_wayInx;
engKinMat_engKinInx_wayInx = tstDat800.engKinMat_engKinInx_wayInx;
engKinNumVec_wayInx = tstDat800.engKinNumVec_wayInx;

% Löschen von inf und NaN aus Modelldaten
% ^^ replace any infinities and Nans with zeros
% && löschen = delete
FZG.emoTrq_emoSpd_emoPwr(isinf(FZG.emoTrq_emoSpd_emoPwr)) = 0;

% % load in data from text file (if running model through matlab and are 
% % ignoring simulink (mainConfig.txt)
% inputparams = readConfig_port('mainConfig.txt');
% inputparams = load('inputparams');
% % 
% % % asign values from struct
% disFlg          = inputparams.disFlg;
% wayStp          = inputparams.wayStp;
% batEngStp       = inputparams.batEngStp;
% batEngBeg       = inputparams.batEngBeg;
% batPwrAux       = inputparams.batPwrAux;
% psiBatEng       = inputparams.psiBatEng;
% psiTim          = inputparams.psiTim;
% staChgPenCosVal = inputparams.staChgPenCosVal;
% wayInxBeg       = inputparams.wayInxBeg;
% wayInxEnd       = inputparams.wayInxEnd;
% staBeg          = inputparams.staBeg;
fprintf('done!\n');
%% Calculating optimal predecessors with DP + PMP
fprintf('-Initializing model...\n');
[... --- Ausgangsgrößen:
    optPreInxTn3, ...   Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3, ...   Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3, ...   Tensor 3. Stufe für die Kraftstoffenergie 
    cos2goActMat ...    Matrix der optimalen Kosten der Hamiltonfunktion 
    ] = ... 
    clcDP_olyHyb_port...     FUNKTION
    ( ...               --- Eingangsgrößen:
    disFlg, ...         Skalar - Flag für Ausgabe in das Commandwindow
    wayStp,...          Skalar für die Wegschrittweite in m
    batEngStp,...       Skalar der Batteriediskretisierung in J
    batEngBeg,...       Skalar für die Batterieenergie am Beginn in Ws
    batPwrAux,...       Skalar für die Nebenverbrauchlast in W
    psiBatEng,...       Skalar für den Co-State der Batterieenergie
    psiTim,...          Skalar für den Co-State der Zeit
    staChgPenCosVal,... Skalar für die Strafkosten beim Zustandswechsel
    wayInxBeg,...       Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,...       Skalar für Endindex in den Eingangsdaten
    engKinBegInx,...    Skalar für den Index der Anfangsgeschwindigkeit
    engKinNum,...       Skalar für die max. Anz. an engKin-Stützstellen
    staNum,...          Skalar für die max. Anzahl an Zustandsstützstellen
    wayNum,...          Skalar für die max. Anzahl an Wegstützstellen
    staBeg,...          Skalar für den Startzustand des Antriebsstrangs
    engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
    slpVec_wayInx,...   Vektor der Steigungen in rad
    engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J
    FZG...              struct der Fahrzeugparameter
    );
engKinEndInxVal = ceil(engKinNumVec_wayInx(wayInxEnd)/2);
staEnd = staBeg;

%% Calculating optimal trajectories for result of DP + PMP
[engKinOptVec,...       Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec, ...Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergieänderung
    staVec,...          Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate für kinetische Energie
    fulEngOpt ...       Skalar - optimale Kraftstoffenergie
    ] = ...
    clcOptTrj_port...        FUNKTION
    (false,...          Flag, ob Zielzustand genutzt werden muss
    wayStp,...          Skalar für die Wegschrittweite in m
    wayNum,...          Skalar für die max. Anzahl an Wegstützstellen
    wayInxBeg,...       Skalar für Anfangsindex in den Eingangsdaten
    wayInxEnd,...       Skalar für Endindex in den Eingangsdaten
    staEnd,...          Skalar für den finalen Zustand
    engKinNum,...       Skalar für die max. Anz. an engKin-Stützstellen
    engKinEndInxVal,... Skalar für Zielindex der kinetischen Energie
    staNum,...          Skalar für die max. Anzahl an Zustandsstützstellen
    engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
    engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J
    optPreInxTn3,...    Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3, ...   Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3, ...   Tensor 3. Stufe für die Kraftstoffenergie
    cos2goActMat ...    Matrix der optimalen Kosten der Hamiltonfunktion 
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