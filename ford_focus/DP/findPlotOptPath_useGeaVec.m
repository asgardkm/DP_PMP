function [              ...
    batEngDltOptMat,    ... Vektor - optimale Batterieenergieï¿½nderung
    fulEngDltOptMat,    ... Vektor - optimale Kraftstoffenergieï¿½nderung
    engStaMat,          ... vector showing optimal engine contorl w/ profile
    batPwrMat,          ... vector showing optimal battery level control
    batEngMat,          ... vector showing optimal battery levels
    fulEngOptVec        ... Skalar - optimale Kraftstoffenergie] =           ...
] = findPlotOptPath_useGeaVec(    ...
    timVec,             ...
    engStaVec_timInx,   ...
    optPreInxTn3,       ... Tensor 3. Stufe fï¿½r opt. Vorgï¿½ngerkoordinaten
    batPwrOptTn3,       ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,       ... Tensor 3. Stufe fï¿½r die Kraftstoffenergie
    cos2goActMat,       ... Matrix der optimalen Kosten der Hamiltonfunktion
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

% batEngActInxVec = tst_scalar_struct.batEngMin / tst_scalar_struct.batEngStp : ...
%                   tst_scalar_struct.batEngMax / tst_scalar_struct.batEngStp;
% 

% end end engine state
engEndEnd = engStaVec_timInx(inputparams.timInxEnd) - 1;

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
engStaMat       = inf(length(timVec), length(batEndInxVec));
batPwrMat       = inf(length(timVec), length(batEndInxVec));
batEngMat       = inf(length(timVec), length(batEndInxVec));
fulEngOptVec    = inf(length(batEndInxVec), 1);

fprintf('Generating all optimal paths from ending SOC levels %2.0f%% to %2.0f%%\n', ...
        inputparams.batEngEndMinRat*100, inputparams.batEngEndMaxRat*100);

for batEndInx_counter = 1 : length(batEndInxVec)
    batEndInx = batEndInxVec(batEndInx_counter);
[...
    batEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Batterieenergieï¿½nderung
    fulEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Kraftstoffenergieï¿½nderung
    engStaMat(:, batEndInx_counter),        ... vector showing optimal engine contorl w/ profile
    batPwrMat(:, batEndInx_counter),        ... vector showing optimal battery level control
    batEngMat(:, batEndInx_counter),        ... vector showing optimal battery levels
    fulEngOptVec(batEndInx_counter)         ... Skalar - optimale Kraftstoffenergie
    ] =                                     ...
    clcOptTrj_focus_useGeaVec               ... FUNKTION
    (inputparams.disFlg,        ... Flag, ob Zielzustand genutzt werden muss - CHANGE VAR NAME ITS THE SAME VAR FOR 2 DIFFERENT USES IN 2 FUNCTIONS
    inputparams.timStp,         ... Skalar fï¿½r die Wegschrittweite in m
    tst_scalar_struct.batEngStp,... scalar - bat energy discretization step
    length(timVec),             ... Skalar fï¿½r die max. Anzahl an Wegstï¿½tzstellen
    inputparams.timInxBeg,      ... Skalar fï¿½r Anfangsindex in den Eingangsdaten
    inputparams.timInxEnd,      ... Skalar fï¿½r Endindex in den Eingangsdaten
    engEnd,                     ... scalar - final engine state
    engEndEnd,                  ... Skalar fï¿½r Zielindex der kinetischen Energie
    batEndInx,                  ... scalar - final battery state
    tst_scalar_struct.engStaNum,...
    batStaNum,      ... scalar - for number of battery energy levels
    optPreInxTn3,   ... Tensor 3. Stufe für opt. Vorgängerkoordinaten
    batPwrOptTn3,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn3,   ... Tensor 3. Stufe für die Kraftstoffenergie
    cos2goActMat    ... Matrix der optimalen Kosten der Hamiltonfunktion  
    );
    if inputparams.disFlg
        fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
            double(batEndInx_counter-1), double(((batEndInx_counter-1))) /...
            double(length(batEndInxVec)-1)*100);
    end
end
fprintf('\n\ndone!\n');

%% some plotting
% batEng trajectories for all ending SOC possibilities (currently 30%-90%)
figure(1)
bluVal = 1;
redVal = 0;
batEngMatSOC = batEngMat / tst_scalar_struct.batEngMax;
plot(timVec, batEngMatSOC(:, 1), 'Color', [redVal 0 bluVal]); 
hold on;
% titleString = sprintf('batEng trajectories for all optimal paths from ending SOC levels %2.0f%% : %2.0f%%\n', batEngEndMinRat*100, batEngEndMaxRat*100);
titleString = 'batEng trajectories for optimal paths';

title(titleString);
xlabel('Time [sec]');
ylabel('SOC [%]');
for batEndInx_counter = 2 : length(batEndInxVec)
    scaVal = double(((batEndInx_counter-1))) / double(length(batEndInxVec)-1);
    plot(timVec, batEngMatSOC(:, batEndInx_counter), 'Color', [redVal+scaVal 0 bluVal-scaVal]); 
end

% fuel trajectories for all ending SOC possibilities (currently 30%-90%)

figure(2)
plot(timVec(1:end-1), fulEngDltOptMat(1:end-1, 1), 'Color', [redVal 0 bluVal]); 
hold on;
titleString = 'fuel trajectories for optimal paths';
title(titleString);
xlabel('Time [sec]');
ylabel('Fuel Use [J]');
for fulEngInx_counter = 2 : length(batEndInxVec)
    scaVal = double(((fulEngInx_counter-1))) / double(length(batEndInxVec)-1);
    plot(timVec(1:end-1), fulEngDltOptMat(1:end-1, fulEngInx_counter), 'Color', [redVal+scaVal 0 bluVal-scaVal]); 
end

end