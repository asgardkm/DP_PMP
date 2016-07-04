function [ ...
    engKinActInx_tim_engKin,...Matrix - erreichte v und t Zustände
    optPreInxTn4,... Tensor 4. Stufe - optimale Vorgänger
    cosActTn4... Tensor 4. Stufe - Kosten zu den aktuellen Punkten
    ] = ...
    clcOptInx_v4_fulStaSpa( ...
    slp,... Skalar - Steigung im Intervall
    batPwrAux,... Skalar - Nebenverbraucherlast
    batEngActMinInx,... Skalar - min. erreichbare Batterieenergieindex
    batEngActMaxInx,... Skalar - max. erreichbare Batterieenergieindex
    batEngPreClcMinInx,... Skalar - min. vorheriger Batterieenergieindex
    batEngPreClcMaxInx,... Skalar - max. vorheriger Batterieenergieindex
    engKinNumAct,... Skalar - Anzahl der aktuellen kinetischen Energien
    engKinNumPre,...
    wayStp,... Skalar - Wegschrittweite
    batEngStp,... Skalar - Schrittweite der Batterieenergie
    timStp,...
    batEngNum,...Skalar - Anzahl der Batterieenergiestützstellen
    timNum,... Skalar - Zeitstützstellen
    staNum,... Skalar - Zustandsstützstellen
    geaNum,...Skalar - Anzahl der Gänge
    engKinNum,... Skalar - Stützstellen der kinetischen Energie
    icePenCosVal,...Skalar - Strafkosten für einen Motorstart
    geaChgPenCosVal,...Skalar - Strafkosten für einen Zustandswechsel
    infVal,...
    timMinPre,...
    timMinAct,...
    timNumPre,...
    timNumAct,...
    engKinActVec_engKinInx,... Vektor der aktuellen kinetische Energien
    engKinPreVec_engKinInx,... Vektor der vorherigen kinetische Energien
    engKinPreInx_tim_engKin,...Matrix - erreichte v und t Zustände
    cosPreTn4,... Tensor der Kosten im Vorgängerpunkt
    par...struct der Fahrzeugparameter
    ) %#codegen
%CLCOPTINX_V4_FULSTASPA Parfor loop to calcualte optimal predecessors and costs
%   Im wesentlichen ist eine parfor-Schleife realisiert, die als
%   Mex-Function wesentlich schneller und mit mehr Kernen ausgeführt werden
%   kann.

% Diese Version arbeitet mit einem äquidistanten Zeitzustand.

% Änderung am 17.02.16 - Fehler in Berechnung der Ladungsvorgänger behoben.
% Dieser Fehler führte dazu, dass der Motor nicht im Schubbetrieb betrieben
% werden konnte und konventionelles Bremsen nicht möglich war. Mit weiterer
% Korrektur am 18.02.16, die am 19.02. (Version 3i) wieder rückgängig
% gemacht wurde. :(
% Weiterer Fehler enthalten (konventionelles Bremsen ausgeschlossen),
% korrigiert am 23.02.2016 (Version 3j)

% Änderung 25.02.16 - Fehler mit vehAccMax beseitigt.

% Änderung 25.05.16 (neuer Version 3l) - Zero Order Hold (keine mittlere
% Geschwindigkeit)

% Änderung 26.05.16 (neue Version 4) - ICE on/off


%% Ausgabe der Funktion initialisieren

% % Initialisieren des Vektors der optimalen Vorgänger
% % Dieser Vektor wird für jeden Wegpunkt gespeichert, um zu große
% % Variablen zu vermeiden

optPreInxTn4 = zeros(engKinNum,timNum,batEngNum,staNum,'uint32');
cosActTn4 = inf+zeros(engKinNum,timNum,batEngNum,staNum,'single');

%% Initialisieren der persistent Größen
% Diese werden die nur einmal für die Funktion berechnet
persistent engKinNumXtimNum engKinNumXtimNumXbatEngNum
%
if isempty(engKinNumXtimNum)

% Diese Größen müssen zur Berechnung des absoluten Index ständig
% berechnet werden
engKinNumXtimNum = engKinNum * timNum;
engKinNumXtimNumXbatEngNum  = engKinNum * timNum * batEngNum;

end

%% Berechnung der möglichen aktuellen Zeitpunkte mit Geschwindigkeiten

% Matrix bestimmen, die für jeden Zeitzustand den Index der möglichen
% Geschwindigkeiten enthält
engKinActInx_tim_engKin = false(timNum,engKinNum);

for timPreInx = 1:timNumPre
    
    timPre = timMinPre + (timPreInx-1) * timStp;
    
    for engKinPreInx = 1:engKinNumPre
        
        % Prüfen, ob es einen Vorgänger gibt
        if engKinPreInx_tim_engKin(timPreInx,engKinPreInx);
            
            engKinPre = engKinPreVec_engKinInx(engKinPreInx);
            velPre = sqrt(2*engKinPre/par.vehMas);
            timDlt = wayStp / velPre;
            
            for engKinActInx = 1:engKinNumAct
                
                engKinAct = engKinActVec_engKinInx(engKinActInx);
                
                % Berechnen der konstanten Beschleunigung
                vehAcc = (engKinAct - engKinPre) / (par.vehMas*wayStp);
                
                if abs(vehAcc) > par.vehAccMax
                    continue
                end
                
                % aktuellen Index berechnen
                % Die -1e-9 schließen numerische Fehler aus
                timActInx = ceil((timPre+timDlt-timMinAct+timStp-1e-9)/timStp);
                engKinActInx_tim_engKin(timActInx,engKinActInx) = true;
            end
        else
            continue;
        end
    end
end

%% Berechnung der Kosten

%% Schleife über aktuellen (Punkt: k+1) kinetischen Energien
parfor engKinActInx = 1:engKinNumAct
    
    engKinAct = engKinActVec_engKinInx(engKinActInx); %#ok<*PFBNS>
    
    %% Schleife über alle möglichen Zeitpunkte
    for timActInx = 1:timNumAct
        
        if ~engKinActInx_tim_engKin(timActInx,engKinActInx)
            continue
        end
        
        % aktuellen Zeitindex ermitteln
        timAct = timMinAct + (timActInx-1)*timStp;
        
        %% Schleife über alle Batteriezustände
        for batEngActInx = batEngActMinInx:batEngActMaxInx
            
            % Energie der Batterie für betrachteten Punkt
            batEngAct = double(batEngActInx-1) * batEngStp;
            
            %% Schleife über alle Antriebsstrangszustände (Gänge + ICE on/off)
            for staAct = 1:staNum
                
                if staAct <= geaNum
                    geaAct = staAct;
                    edrAct = false;
                else
                    geaAct = staAct - geaNum;
                    edrAct = true;
                end
                
                % Vorgängerzustände des Antriebsstrangs beschränken
                geaPreMin = max(1,geaAct-1);
                geaPreMax = min(geaNum,geaAct+1);
                
                
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                %% Berechnung der Vorgänger
                
                cosActOpt = inf;
                optPreInx = 0;
                
                
                %% Schleife über Vorgänger kinetischen Energien
                for engKinPreInx = 1:engKinNumPre
                    
                    
                    %% Berechnung des Zeitvorgängers
                    engKinPre = engKinPreVec_engKinInx(engKinPreInx);
                    
                    % Abbruch bei zu Verletzung der Beschleunigungsgrenzen
                    if abs((engKinAct - engKinPre) / (par.vehMas*wayStp)) > par.vehAccMax
                        continue;
                    end
                    
                    velPre = sqrt(2*engKinPre/par.vehMas);
                    timDlt = wayStp / velPre;
                    
                    % Prüfen ob für die aktuelle Zeit und das
                    % Geschwindigkeitsdelta Vorgänger existieren
                    % Die 1e-9 sollen numerische Fehler ausschließen
                    timPreInx = floor((timAct-timDlt-timMinPre+timStp+1e-9)/timStp);
                    
                    if timPreInx < 1 || ...
                            all(all(cosPreTn4(engKinPreInx,timPreInx,:,:) > infVal))
                        continue;
                    end
                    
                    
                    %% mögliche Batterieladungsänderung bestimmen
                    
                    % Hybridfall
                    if ~edrAct
                    
                    % Es wird hier gegenüber der Berechnung im PMP die
                    % aktuelle Batterieenergie als Zustand der Batterie
                    % genutzt und nicht die im vorherigen Wegschritt.
                    % Durch die große Batterie dürfte der Fehler aber
                    % vernachlässigbar sein.
                    [ ...
                        batEngDltMin,...Skalar - Änderung der Batterieenergie
                        batEngDltMax...Skalar - Änderung der Batterieenergie
                        ] = ...
                        batEngDltClc...
                        (...
                        engKinPre,...Skalar - kin. Energie der Vorgängers
                        engKinAct,...Skalar - kin. Energie
                        wayStp,...Skalar - Wegschrittweite
                        geaAct,...Skalar - Gang
                        slp,...Skalar - Steigung
                        velPre,...Skalar - Geschwindigkeit im Intervall
                        batPwrAux,...Skalar - Nebenverbraucherlast
                        batEngAct,...Skalar - Batterieenergie
                        par...struct - Fahrzeugparameter
                        );
                    
                        % Hier muss zwischen Laden und Entladen
                        % unterschieden werden! Sonst werden Zustände
                        % vernachlässigt, wie konventionelles Bremsen bei
                        % zu voller Batterie etc.
                        
                        % Der minimale Vorgängerindex bestimmt sich
                        % durch maximales Laden (Das ceil verhindert, dass
                        % die Batteriegrenzen verletzt werden. Eine erneute
                        % Überprüfung findet nicht statt.)
                        batEngPreMinInx = max(...
                            ceil((batEngAct - batEngDltMax)/batEngStp)+1,...
                            batEngPreClcMinInx);
                        
                        %% Berechnung Vorgängerindize
                        % Es werden 2 Fälle unterschieden:
                        if batEngDltMin > 0 && batEngDltMax > 0
                            
                            %% konventionelles Bremsen + Rekuperieren
                            % nur der Zustand der am meisten lädt
                            % soll genutzt werden
                            % Es hat keinen Sinn Zustände zu untersuchen,
                            % die einem Entladen der Batterie entsprechen.
                            % Daher kann der minimale Ladungspunkt nur die
                            % aktuelle Ladung sein
                            
                            % Der maximale Vorgängerindex ist beim Laden
                            % der aktuell betrachtete Index. Dadurch werden
                            % auch Zustandswechsel untersucht, bei dem
                            % konventionell gebremst wird. Dabei ändert
                            % sich die Batterieladung nicht.
                            batEngPreMaxInx = batEngActInx;
                            
                        else
                            
                            %% Lastpunktanhebung und Lastpunktabsenkung möglich
                            % hier ist der Fall eingeschlossen, dass die
                            % Leistung nicht gestellt werden kann.
                            % batEngDltMin < 0 && batEngDltMax < 0
                            
                            % Der maximale Vorgängerindex bestimmt sich
                            % durch maximales Entladen (Das floor verhindert, dass
                            % die Batteriegrenzen verletzt werden. Eine erneute
                            % Überprüfung findet nicht statt.)
                            batEngPreMaxInx = min(...
                                floor((batEngAct - batEngDltMin)/batEngStp)+1,...
                                batEngPreClcMaxInx);
                        end
                        
                        % Wenn bei maximalen Entladen der Vorgänger
                        % unterhalb des minimalen Index liegt, gibt es
                        % keine Vorgänger
                        if batEngPreMaxInx < batEngPreMinInx
                            continue;
                        end
                    
                        % E-Fahrt
                    else
                        
                        % Es wird hier gegenüber der Berechnung im PMP die
                        % aktuelle Batterieenergie als Zustand der Batterie
                        % genutzt und nicht die im vorherigen Wegschritt.
                        % Durch die große Batterie dürfte der Fehler aber
                        % vernachlässigbar sein.
                        [ ...
                            batEngDlt,...Skalar - Änderung der Batterieenergie
                            ] = ...
                            batEngDltEmoClc...
                            (...
                            engKinPre,...Skalar - kin. Energie der Vorgängers
                            engKinAct,...Skalar - kin. Energie
                            wayStp,...Skalar - Wegschrittweite
                            geaAct,...Skalar - Gang
                            slp,...Skalar - Steigung
                            velPre,...Skalar - Geschwindigkeit im Intervall
                            batPwrAux,...Skalar - Nebenverbraucherlast
                            batEngAct,...Skalar - Batterieenergie
                            infVal,...
                            par...struct - Fahrzeugparameter
                            );
                        
                        %% Leistet der Elektromotor Vortrieb...
                        % d.h. er benötigt Batterieenergie
                        if batEngDlt < 0 % neg. batEngDlt entspr. Entladen 
                            
                            % Wird die Batterie entladen, muss noch einmal überprüft werden, dass das
                            % nächst höhere Batterieenergiedelta immer noch die Batterieleistungsrenzen
                            % einhält
                            batEngDltGrd = floor(batEngDlt/batEngStp)*batEngStp;
                            
                            % Batterieenergieänderung über dem Weg (Batteriekraft)
                            batFrc = batEngDltGrd / wayStp;
                            % Batteriespannung aus Kennkurve berechnen
                            batOcv = batEngAct*par.batOcvCof_batEng(1,1) ...
                                + par.batOcvCof_batEng(1,2);
                            batRst = par.batRstDch;

                            % elektrische Leistung des Elektromotors
                            emoPwrEle = -batFrc * velPre ... innere Batterieleistung
                                - batFrc^2 * velPre^2 / batOcv^2 * batRst...dissipat. Leist.
                                - batPwrAux; ... Nebenverbrauchlast
                                
                            if emoPwrEle > par.batPwrMax
                                continue;
                            end                            
                            
                            % Es wird mehr Energie aus der Batterie
                            % entnommen (Diskretisierungsfehler)
                            batEngPreMaxInx = ...
                                ceil((batEngAct - batEngDlt)/batEngStp)+1;
                            batEngPreMinInx = batEngPreMaxInx;
                            
                            if batEngPreMaxInx > batEngPreClcMaxInx ||...
                                    batEngPreMaxInx < batEngPreClcMinInx
                                continue;
                            end
                           
                        %% Rekuperation
                        % d.h. Energie wird zurückgespeist
                        elseif batEngDlt < infVal && batEngDlt >= 0
                            % Es wird weniger Energie zurückgespeist als
                            % möglich (Diskretisierungsfehler)
                            batEngPreMinInx = ...
                                ceil((batEngAct - batEngDlt)/batEngStp)+1;                            
                           
                            % Es ist ebenfalls möglich konventionell zu
                            % bremsen, wodurch sich die maximale Vorgänger-
                            % batterenergie aus der Auxiliary Power ergibt
                            if batPwrAux ~= 0

                                batEngDlt_batPwrAux = batFrcClc(...
                                batEngAct,...Skalar - Batterieenergie
                                batPwrAux,...Skalar - Batterieklemmleistung
                                velPre,...Skalar - mittlere Geschwindigkeit im Intervall
                                par.batRstDch,...Skalar - Entladewiderstand
                                par.batRstChr,...Skalar - Ladewiderstand
                                par.batOcvCof_batEng...Vektor - Koeffizienten für Ruhespannung der Bat
                                ) * wayStp;
                            
                            else
                                batEngDlt_batPwrAux = 0;
                            end
                            % Es wird weniger Energie zurückgespeist als
                            % möglich (Diskretisierungsfehler)
                            batEngPreMaxInx = ...
                                floor((batEngAct - batEngDlt_batPwrAux)/batEngStp)+1;
                            
                            % Prüfen, ob minimaler Vorgängerindex existiert
                            if batEngPreMinInx < batEngPreClcMinInx
                                if batEngPreMaxInx >= batEngPreClcMinInx
                                    batEngPreMinInx = batEngPreClcMinInx;
                                else
                                    continue;
                                end
                            end
                            
                           
                            
                        else
                            % Elektrisches Fahren kann nicht dargestellt
                            % werden, batEngDlt == infVal
                            continue;                            
                        end
                        

                        

                    end
                    
                    %% Schleife über Batterieladungen
                    for batEngPreInx = batEngPreMinInx:batEngPreMaxInx
                        
                        % Energie der Batterie für betrachteten Vorgängerpunkt
                        batEngPre = (batEngPreInx-1) * batEngStp;
                        
                        % Batterieenergieänderung
                        batEngDlt = batEngAct - batEngPre;
                        
                        %% Schleifen über alle Vorgängergänge
                        for geaPre = geaPreMin:geaPreMax
                            
                            %% Schleife über Vorgängermotorzustände
                            for edrPre = 0:1
                                
                                staPre = geaPre + edrPre*geaNum;
                                
                                % absoluten Index des Vorgängergs bestimmen
                                % Berechnung ersetzt die Funktion:
                                % preInx = sub2ind([engKinNum,timNum,batEngNum,staNum],...
                                %   engKinPreInx,timPreInx,batEngPreInx,staPre);
                                % sub2ind kann in mex - parfor - Schleifen zu
                                % Problemen führen
                                preInx = engKinPreInx ...
                                    + (timPreInx-1) * engKinNum ...
                                    + (batEngPreInx-1) * engKinNumXtimNum ...
                                    + (staPre-1) * engKinNumXtimNumXbatEngNum;
                                
                                % Kosten im Vorgängerpunkt bestimmen
                                cosPre = cosPreTn4(preInx);
                                
                                % Prüfen ob gültiger Vorgänger exisitiert, sonst fortfahren
                                if cosPre > infVal
                                    continue
                                end
                                
                                %% Strafkosten bestimmen
                                
                                % Kosten für Zustandswechsel setzen
                                if geaPre ~= geaAct
                                    % Zustandswechselkosten setzen
                                    geaChgPenCos = geaChgPenCosVal;
                                else
                                    % Entspricht der Vorgängerzustand dem aktuellen
                                    % Zustand oder sind die Kosten 0,
                                    % werden keine Kosten gesetzt
                                    geaChgPenCos = 0;
                                end
                                
                                if ~edrAct && edrPre
                                    icePenCos = icePenCosVal;
                                else
                                    icePenCos = 0;
                                end
                                
                                %% Berechnung der Kosten zum aktuellen Punkt
                                
                                if ~edrAct
                                    
                                    % Wenn der Motor an ist, werden die
                                    % Krafstoffkosten berechnet
                                    [ fulEngDlt ...Skalar - Kraftstoffverbrauch in J
                                        ] = ...
                                        fulEngClc_v2...
                                        (wayStp,... Skalar für die Wegschrittweite in m
                                        batPwrAux,... Nebenverbraucherlast
                                        slp,... Steigung der Fahrbahn in rad
                                        engKinPre,...Skalar - kin. Energie am Anfang
                                        engKinAct,...Skalar - kin. Energie am Ende
                                        batEngAct,... Skalar - aktuelle Energie der Batterie
                                        batEngDlt, ... Skalar - Batterieenergieänderung
                                        geaAct,...Skalar - aktueller Gang
                                        ~edrAct,...Skalar - Motorzustand
                                        par...struct der Fahrzeugparameter
                                        );
                                    
                                else
                                    fulEngDlt = 0;
                                end

                                cosAct = icePenCos + geaChgPenCos + fulEngDlt...
                                    + double(cosPre);
                                
                                if cosAct < cosActOpt
                                    optPreInx = preInx;
                                    cosActOpt = cosAct;
%                                     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                     %% Einschub Überprüfung des Zustands
%                                     if edrAct
%                                         
%                                         [ ~, ...Skalar - Kraftstoffverbrauch in J
%                                             crsSpd, ...Skalar für die mittlere Kurbelwellendrehzahl
%                                             crsTrq, ...skalar für das Kurbelwellenmoment
%                                             emoTrq, ...Skalar für das Drehmoment des Elektromotors
%                                             ~, ...Skalar für das Drehmoment des Verbrennungsmotors
%                                             batPwr ...Skalar für die Batterieleistung
%                                             ] = ...
%                                             fulEngClc_v2...
%                                             (wayStp,... Skalar für die Wegschrittweite in m
%                                             batPwrAux,... Nebenverbraucherlast
%                                             slp,... Steigung der Fahrbahn in rad
%                                             engKinPre,...Skalar - kin. Energie am Anfang
%                                             engKinAct,...Skalar - kin. Energie am Ende
%                                             batEngAct,... Skalar - aktuelle Energie der Batterie
%                                             batEngDlt, ... Skalar - Batterieenergieänderung
%                                             geaAct,...Skalar - aktueller Gang
%                                             ~edrAct,...Skalar - Flag für Verbrennungsmotorzustand
%                                             par...struct der Fahrzeugparameter
%                                             );
%                                         
%                                         
%                                         assert(crsTrq < emoTrq,...
%                                             'Fehler in der Berechnung des Elektromotormoments')
%                                         
%                                         %% Grenzen des Elektromotors
%                                         % minimales Moment, dass die E-Maschine liefern kann
%                                         emoTrqMin = ...
%                                             interp1q(par.emoSpdMgd(1,:)',par.emoTrqMin_emoSpd,crsSpd);
%                                         assert(emoTrq >= emoTrqMin*1.01,'Zu niedrige E-Motormomente treten auf!')
%                                         
%                                         % maximales Moment, dass die E-Maschine liefern kann
%                                         emoTrqMax = ...
%                                             interp1q(par.emoSpdMgd(1,:)',par.emoTrqMax_emoSpd,crsSpd);
%                                         assert(emoTrq <= emoTrqMax*1.01,'Zu hohe E-Motormomente treten auf!')
%                                         
%                                         %% Grenzen der Batterie
%                                         assert(batPwr >= par.batPwrMin*1.01,...
%                                             'Zu niedrige Batterieleistungen treten auf!')
%                                         
%                                         assert(batPwr <= par.batPwrMax*1.01,...
%                                             'Zu hohe Batterieleistungen treten auf!')
% 
%                                         
%                                     end
                                    
                                    
                                end
                                
                            end
                        end
                    end
                end
                
                % Speichern der Ergebnisse in dem Tensor der optimalen Vorgänger
                optPreInxTn4(engKinActInx,timActInx,batEngActInx,staAct)...
                    = uint32(optPreInx);
                cosActTn4(engKinActInx,timActInx,batEngActInx,staAct)...
                    = single(cosActOpt);
                
            end
        end
    end
    
end
end
