function ...            --- Ausgangsgrößen:
[engKinOptVec,...       Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec, ...Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,... Vektor - optimale Kraftstoffenergieänderung
    staVec,...          Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,... Vektor - costate für kinetische Energie
    fulEngOpt, ...      Skalar - optimale Kraftstoffenergie
    resVld...
    ] = ...
    clcDP_tmp...
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
    engKinNum,...       Skalar für die max. Anz. an engKin-Stützstellen
    staNum,...          Skalar für die max. Anzahl an Zustandsstützstellen
    wayNum,...          Skalar für die max. Anzahl an Wegstützstellen
    staBeg,...          Skalar für den Startzustand des Antriebsstrangs
    engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
    slpVec_wayInx,...   Vektor der Steigungen in rad
    engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J%#codegen
    FZG) %#codegen

%% Calculating optimal predecessors with DP + PMP
fprintf('Start\n');
[... --- Ausgangsgrößen:
    optPreInxTn3, ...   Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batFrcOptTn3, ...   Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3, ...   Tensor 3. Stufe für die Kraftstoffenergie 
    cos2goActMat ...    Matrix der optimalen Kosten der Hamiltonfunktion 
    ] = ... 
    clcDP_olyHyb_tmp...     FUNKTION
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
    1,...               Skalar für den Index der Anfangsgeschwindigkeit
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
    clcOptTrj_tmp...        FUNKTION
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

fprintf('\n\nStop\n');
   
end