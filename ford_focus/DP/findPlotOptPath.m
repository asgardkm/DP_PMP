function [              ...
    batEngDltOptMat,    ... Vektor - optimale Batterieenergie�nderung
    fulEngDltOptMat,    ... Vektor - optimale Kraftstoffenergie�nderung
    geaStaMat,          ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat,          ... vector showing optimal engine contorl w/ profile
    batPwrMat,          ... vector showing optimal battery level control
    batEngMat,          ... vector showing optimal battery levels
    fulEngOptVec        ... Skalar - optimale Kraftstoffenergie] =           ...
] = findPlotOptPath(    ...
    timVec,             ...
    engStaVec_timInx,   ...
    optPreInxTn4,       ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn4,       ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn4,       ... Tensor 3. Stufe f�r die Kraftstoffenergie
    cos2goActTn3,       ... Matrix der optimalen Kosten der Hamiltonfunktion
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
fulEngOptVec    = inf(length(batEndInxVec), 1);

fprintf('Generating all optimal paths from ending SOC levels %2.0f%% to %2.0f%%\n', ...
        inputparams.batEngEndMinRat*100, inputparams.batEngEndMaxRat*100);

for batEndInx_counter = 1 : length(batEndInxVec)
    batEndInx = batEndInxVec(batEndInx_counter);
[...
    batEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Batterieenergie�nderung
    fulEngDltOptMat(:, batEndInx_counter),  ... Vektor - optimale Kraftstoffenergie�nderung
    geaStaMat(:, batEndInx_counter),        ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    engStaMat(:, batEndInx_counter),        ... vector showing optimal engine contorl w/ profile
    batPwrMat(:, batEndInx_counter),        ... vector showing optimal battery level control
    batEngMat(:, batEndInx_counter),        ... vector showing optimal battery levels
    fulEngOptVec(batEndInx_counter)         ... Skalar - optimale Kraftstoffenergie
    ] =                         ...
    clcOptTrj_focus             ... FUNKTION
    (inputparams.disFlg,        ... Flag, ob Zielzustand genutzt werden muss - CHANGE VAR NAME ITS THE SAME VAR FOR 2 DIFFERENT USES IN 2 FUNCTIONS
    inputparams.timStp,         ... Skalar f�r die Wegschrittweite in m
    tst_scalar_struct.batEngStp,... scalar - bat energy discretization step
    length(timVec),             ... Skalar f�r die max. Anzahl an Wegst�tzstellen
    inputparams.timInxBeg,      ... Skalar f�r Anfangsindex in den Eingangsdaten
    inputparams.timInxEnd,      ... Skalar f�r Endindex in den Eingangsdaten
    staEnd,                     ... Skalar f�r den finalen Zustand
    engEnd,                     ... scalar - final engine state
    engEndEnd,                  ... Skalar f�r Zielindex der kinetischen Energie
    batEndInx,                  ... scalar - final battery state
    tst_scalar_struct.staNum,... Skalar f�r die max. Anzahl an Zustandsst�tzstellen
    tst_scalar_struct.engStaNum,... scalar - for number of states engine can take
    batStaNum,... scalar - for number of battery energy levels
    optPreInxTn4,   ... Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten
    batPwrOptTn4,   ... Tensor 3. Stufe der Batteriekraft
    fulEngOptTn4,   ... Tensor 3. Stufe f�r die Kraftstoffenergie
    cos2goActTn3    ... Matrix der optimalen Kosten der Hamiltonfunktion 
    );
    if disFlg
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
batEngMatSOC = batEngMat / batEngMax;
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