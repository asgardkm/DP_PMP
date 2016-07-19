function [ ] = runGlbDP_v5b_fulStaSpa( wayInxLstSetInp,...
    folNmeInp,clcFlgInp,timEndRefSet,batEngEndSet,engKinEndInxInp )
%RUNGLBDP_tst_timMat optimal control approach with DP + PMP
% Erstellungsdatum der ersten Version 04.09.2015 - Stephan Uebel
% Diese Funktion löst das Optimalsteuerungsproblem für einen P2-Hybrid mit
% DP.
% Diese Version rechnet mit einem Äquidistanten Zeitgitter. Index 1 ist
% immer die minimal erreichbare Zeit. (01.12.2015)

% Version 3f - Fehler in möglicher Ladung beseitigen

% Version 3g - Berechnung der costates anpassen

% Version 4 - Fehler bei Berechnung der Folgezeit (falsche Trapezoidal
%             Rule) korrigiert - nur noch Zero-Order-Hold!
% 25.05.16

% Version 5 - Berechnung von ICE on/off und Coasting (Erweiterung des
%             Zustandvektors)
% 26.05.16

% Version 5b - automatische Suche des letzten Wegpunkts
% 31.05.16


%% Suchpfade ergänzen

% Pfade der Modelldaten, der Streckendaten und der Subfunktionen
% addpath('../model data','../cycle','../functions')
cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\algorithmus\PMPDP\');
addpath('../model_data', '../functions', 'raw_data')

%% Behandlung der Inputs

if ~exist('wayInxLstSetInp','var') || wayInxLstSetInp == 1 
    
    wayInxLstSet = 1;
    
    if ~exist('folNmeInp','var')
        
        folNme = [datestr(now,'yymmdd_HHMMSS'),'_',mfilename,'_dat'];
        mkdir(folNme)
        save curFolNme folNme
        loaFlg = false;
    else
        folNme = folNmeInp;
        loaFlg = true;
        load([folNme,'/cfg.mat'])
        
        clear wayInxEnd
    end
    
else
    fstFlg = false;
    wayInxLstSet = wayInxLstSetInp;
    
    if ~exist('folNmeInp','var')
        load curFolNme
        loaFlg = true;
        load([folNme,'/cfg.mat'])
        
        clear wayInxEnd
    else
        folNme = folNmeInp;
        loaFlg = true;
        if exist([folNme,'/cfg.mat'],'file') == 1
        load([folNme,'/cfg.mat'])
        
        else
           fstFlg = true; 
        end
        
        clear wayInxEnd
    end
    
    % Wird inf übergeben, sucht die Funktion das letzte .mat-File, dass
    % erzeugt wurde, um den letzte Wegindex zu bestimmen
    if isinf(wayInxLstSet) && ~fstFlg

        filNms = dir(folNme);
        wayInxLstSet = 1;
        for inx = 1:length(filNms)
            
            filNme = filNms(inx).name;
            if length(filNme) > 10 && strcmp(filNme(1:10),'res_wayInx')
                % der letzte Wegindex steht ab Position 11 bis 4 vor dem Ende
                % des Strings (.mat sind die letzten 4 Zeichen)
                wayInx = str2double(filNme(11:length(filNme)-4));
                wayInxLstSet = max(wayInx,wayInxLstSet);
            end
            
        end
    elseif fstFlg
        
        wayInxLestSet = 1;
        loaFlg = false;
        save curFolNme folNme
        
    end
    
end

if ~exist('clcFlgInp','var')
    clcFlg = true;
else
    clcFlg = clcFlgInp;
end

%% Laden der Eingangsdaten
% Laden der Modelldaten
par = load('vehMdl.mat'); % enthält: par (struct)

% % Laden der Referenzdaten (Ausgangsbasis für Optimierung)
% load('refDat.mat') % enthält: refWayVec, refVelVec und refSlpVec
load('nefz.mat') % enthält: refWayVec, refVelVec und refSlpVec
load('nedc.mat')    % load input speed profile
% refWayVec = (0:10:1000)';
% refVelVec = 10*ones(size(refWayVec));
% refSlpVec = zeros(size(refWayVec));%0*.15*sin(refWayVec/1000);

if loaFlg
    par.batEngMax = batEngMax;
    par.vehAccMax = vehAccMax;
    if exist('batOcvCof_batEng','var')
        par.batOcvCof_batEng = batOcvCof_batEng;
    end
else
    par.batEngMax = par.batEngMax/2; %#ok<NODEF>
    par.batOcvCof_batEng = [0 97.188760127129020];
end

%% Initialisierung der Ausgabe der Funktion

%% Präzision des Ergebnisses
if ~loaFlg
    % Diskretisierung der Batterieenergie in J
    % Um Unterschiede von Gangwechseln beim elektrischen Fahren aufzulösen, ist
    % eine Diskretisierung von maximal 100 J nötig.
    batEngStp = 5000;
    
    % Diskretisierung der kinetischen Energie
    engKinStp = 5000;
    
    % Diskretisierung des Wegs
    % Beachten, dass es einen Zusammenhang zwischen Wegdiskretisierung und
    % Diskretisierung der kinetischen Energie gibt
    % Erste Untersuchungen (vom 01.09.15) zeigen, dass bei einer
    % Wegdiskreitisierung von 10 m die kinetische Energie mit 1000 bis 5000
    % Joule diskretisiert sein soll
    wayStp = 10;
    
    % % Diskretisierung der kinetischen Energie
    % engKinStp = 100;
    
    % Diskretisierung der Zeit
    timStp = 0.01; % s
end


%% Nebenbedingungen

% Startgeschwindigkeit / kinetische Energie
% ist standardmäßig durch die Referenzgeschwindigkeit definiert

% Zielgeschwindigkeit / kinetische Energie
% ist standardmäßig durch die Referenzgeschwindigkeit definiert
if ~loaFlg
    % Startzustand des Antriebsstrangs
    staBeg = 11;
    
    % Zielzustand des Antriebsstrangs
    staEnd = 5;
    
    % Startenergie der Batterie
    if batEngStp > 0
        batEngBegInx = round(par.batEngMax/2/batEngStp)+1;
    else
        batEngBegInx = 1;
    end
    batEngBeg = batEngStp*(batEngBegInx-1);
end


if ~exist('batEngEndSet','var')
    % Zielenergie der Batterie
    if batEngStp > 0
        batEngEndInx = round(par.batEngMax/2/batEngStp)+1;
    else
        batEngEndInx = 1;
    end
else
    % Zielenergie der Batterie
    if batEngStp > 0
        batEngEndInx = round(batEngEndSet/batEngStp)+1;
    else
        warning('Bei batEngStp = 0 ist eine Vorgabe der Endladung unsinnig.')
        batEngEndInx = 1;
    end
    
end
batEngEnd = batEngStp*(batEngEndInx-1);

% Startzeit
% Startzeit ist standardmäßig 0

% Zielzeit
% Die Zielzeit ist durch die Zeit des Referenzzyklus definiert

%% Straffaktoren

if ~loaFlg
    % Strafkosten für einen Motorstart
    icePenCosVal = 5e3;
    
    % Strafkosten beim Zustandswechsel
    geaChgPenCosVal = 200;
end

%% Nutzerangaben

% Ausgabe im Command Window über Fortschritt DP erlaubt?
disFlg = true;

% Ausgabe von plot erlaubt?
figFlg = true;

% MEX - Berechnung aktivieren
mexFlg = true;

infVal = 1e25;

% erlaubte Abweichung der kinetischen Energie von Referenz
engKinVar = 60000; % J % 8 km/h bei 50 km/h

% Anfangs- und Endindex der Nutzerdaten
refInxBeg = find(refWayVec >= 0,1,'first');
refInxEnd = find(refWayVec >= 8190,1,'first');

if ~loaFlg
    % Nebenverbrauchlast in W
    batPwrAux = 0;
    
    if batPwrAux < 0
        error('Nebenverbrauchlast muss größer 0 sein.')
    end
end

%% maximale Dimensionen des Zustandsraums

if ~loaFlg
    % maximal erlaubte Anzahl von Stützstellen für die Batterieenergie
    if batEngStp > 0
        batEngNum = ceil(par.batEngMax/batEngStp);
    else
        batEngNum = 1;
    end
    
    % maximal erlaubte Anzahl von Stützstellen für kinetische Energie
    engKinNum = 2*ceil(engKinVar/engKinStp);
    
    % Anzahl der Zustände (für 6 Gänge)
    geaNum = 6;
    % Jeden Gang gibt es zweimal
    % (der Segelzustand entspricht einem stromlosen Elektromotor)
    staNum = 2*geaNum;
    
    % maximal erlaubte Länge, die optimiert werden kann sind 100 km bei einer
    % Diskretisierung von 10 m
    wayNum = ceil(refWayVec(refInxEnd)/wayStp);
    
end


%% Initialisierung der DP

if ~loaFlg
    
    [... --- Ausgangsgrößen:
        wayInxBeg,... Skalar für Anfangsindex in den Eingangsdaten
        wayInxEnd,... Skalar für Endindex in den Eingangsdaten
        engKinEndInx,...Skalar - Index der kinetischen Energie im Ziel
        ~,...Skalar Zielzeit der Referenzgeschwindigkeit
        engKinNumVec_wayInx,... Vektor der Anzahl der kinetischen Energien
        slpVec_wayInx,... Vektor der Steigungen in rad
        engKinMat_engKinInx_wayInx,... Matrix der kinetischen Energien in J
        ~...Matrix der Segelvorgänger
        ] = ...
        iniEngKinMat...
        (... --- Eingangsgrößen:
        [],...Flag - Umschaltung zwischen Segeln und norm. Diskretisierung
        engKinStp,...Skalar für die Schrittweite der kinetischen Energie
        engKinVar,...Skalar für die erlaubte Abweichung der kinetischen Energie
        engKinNum,... Skalar für die max. Anz. an engKin-Stützstellen
        wayStp,...Skalar für die Wegschrittweite in den Ausgangsdaten
        wayNum,... Skalar für die max. Anzahl an Wegstützstellen
        refInxBeg,...Skalar - Startindex in den Referenzdaten
        refInxEnd,...Skalar - Zielindex in den Referenzdaten
        refWayVec,...Vektor der Positionen der Referenzdaten in m
        refVelVec,...Vektor der Referenzgeschwindigkeit in m/s
        refSlpVec,...Vektor der Steigung der Referenz in %!!!!
        par... struct der Fahrzeugparameter
        );
    
end
wayInxEndCyc = wayNum;

if exist('engKinEndInxInp','var')
    engKinEndInx = engKinEndInxInp;
end

if exist('timEndRefSet','var')
    timEndRef = timEndRefSet;
end


%% Ermittlung der Zeitgrenzen und Zeitschrittweite

timMinVec = zeros(wayNum,1);
timNumVec = ones(wayNum,1);
velMinPre = sqrt(2*engKinMat_engKinInx_wayInx(1,wayInxBeg)/par.vehMas);
velMaxPre = velMinPre;
timMaxPre = 0;

for wayInx = wayInxBeg+1:wayInxEndCyc
    
    % minimale maximale Geschwindigkeiten im aktuellen Wegpunkt
    velMinAct = sqrt(2*engKinMat_engKinInx_wayInx(1,wayInx)/par.vehMas);
    velMaxAct = sqrt(2*engKinMat_engKinInx_wayInx(...
        engKinNumVec_wayInx(wayInx),wayInx)/par.vehMas);
    
    % Zeiten werden aus der Geschwindigkeit (Zero-Order-Hold) bestimmt
    timMinVec(wayInx) = wayStp / velMaxPre  + timMinVec(wayInx-1);
    % Die maximale Zeit im aktuellen Zeitschritt muss um die
    % Diskretisierung (den maximalen Fehler im Wegschritt) erhöht werden.
    timMaxAct = wayStp / velMinPre + timMaxPre + timStp;
    
    timNumVec(wayInx) = ceil((timMaxAct-timMinVec(wayInx))/timStp)+1;
    
    %% Für nächsten Schleifendurchlauf
    velMinPre = velMinAct;
    velMaxPre = velMaxAct;
    timMaxPre = timMaxAct;
    
end

if ~loaFlg
    timNum = max(timNumVec);
end

%% Konfiguration speichern

if ~loaFlg
    
    batEngMax = par.batEngMax;
    vehAccMax = par.vehAccMax;
    batOcvCof_batEng = par.batOcvCof_batEng;
    
    save([folNme,'/cfg'],'batEngStp','wayStp','timStp','batEngMax','staBeg','staEnd',...
        'batEngBeg','icePenCosVal','geaChgPenCosVal','batPwrAux',...
        'batEngNum','staNum','engKinMat_engKinInx_wayInx','wayNum','vehAccMax',...
        'timNum','engKinNum','engKinStp','geaNum','batOcvCof_batEng',...
        'wayInxBeg','slpVec_wayInx','engKinNumVec_wayInx')
    
end


%% Um die Berechnung an einer bestimmten Stelle fortzusetzen, bzw. bis zu
% einer bestimmten Stelle auszuwerten kann ein Index übergeben werden. Wird
% er nicht übergeben, wird automatisch von Beginn an gerechnet. Eine
% Auswertung ist dann erst nach einer Berechnung möglich.
if isempty(wayInxLstSet) || wayInxLstSet == wayInxBeg || fstFlg
    
    wayInxLst = wayInxBeg;
    
else
    
    wayInxLst = wayInxLstSet;
    
end


%% Initialisieren der Kostenberechnung
% Der Zustandsraum der DP wäre ein Tensor 4. Stufe (Motor-Start-Stopp und
% Gang sind zusammengefasst) über dem Weg. Zum besseren Handling werden die
% Daten in einem Vektor gespreichert, aber so behandelt, als stünden sie in
% dem Tensor. Dadurch lassen sich die gültigen Vorgänger besser sortieren

% Kantenlänge des Vektors für die Vorgängerkosten bestimmen
numRow = engKinNum*timNum*batEngNum*staNum;

% Prüfen, ob die maximale Anzahl an Zuständen eingehalten wird. Diese
% werden in unsigned Integerwerten (uint32) gespeichert.
% Bei Übergabe an die Mex-Funktion wird mit Integerwerten gerechnet. Um
% einen Überlauf zu verhindern, wird hier geprüft, ob alle Zustandsräume
% durch diese Integerwerte vollständig abgedeckt werden können.
assert(numRow < 2^32-1,...
    ['Zu feine Diskretisierung in kinetischer Energie, ',...
    'Zeit, Batterieenergie gewählt.'])



%% Kostenberechnung

% Wenn Berechnung gewünscht ist
if clcFlg
    
    if wayInxLst == wayInxBeg
        
        % Initialisieren des Vektors der Indize eines Tensors 4. Stufe
        % entsprechend den Einträge im Vektor der Vorgängerkosten
        cosPreTn4 = inf(engKinNum,timNum,batEngNum,staNum,'single');
        % Startindex in den Vektor schreiben
        cosPreTn4(sub2ind([engKinNum,timNum,batEngNum,staNum],1,1,...
            batEngBegInx,staBeg)) = 0;
        
        % Werte für maximale und minimale Batterieenergie, die im letzten Wegpunkt
        % erreicht wurden.
        % Damit lässt sich die Anzahl der zu untersuchenden Punkte im aktuellen
        % Wegschritt auf tatsächlich erreichbare Ladungspunkte beschränken.
        batEngMinPre = (batEngBegInx-1)*batEngStp;
        batEngMaxPre = (batEngBegInx-1)*batEngStp;
        
        batEngPreClcMinInx = batEngBegInx; %#ok<*NASGU>
        batEngPreClcMaxInx = batEngBegInx;
        
        engKinPreInx_tim_engKin = false(timNum,engKinNum);
        engKinPreInx_tim_engKin(1,1) = true;
        
        % Ausgabe des aktuellen Schleifendurchlaufs
        if disFlg
            fprintf('Berechnung der ersten Schleife. \r');
        end
        
        
    else
        
        % Daten des letzten Wegpunkts laden
        filNme = [folNme,'/res_wayInx',num2str(wayInxLst)];
        load(filNme)
        
        %% Werte für den nächsten Schleifendurchlauf vorbereiten
        
        batEngMinPre = (batEngActMinInx-1)*batEngStp; %#ok<NODEF>
        batEngMaxPre = (batEngActMaxInx-1)*batEngStp; %#ok<NODEF>
        
        batEngPreClcMinInx = batEngActMinInx;
        batEngPreClcMaxInx = batEngActMaxInx;
        
        engKinPreInx_tim_engKin = engKinActInx_tim_engKin;
        
        cosPreTn4 = cosActTn4; %#ok<NODEF>
        
        % Ausgabe des aktuellen Schleifendurchlaufs
        if disFlg
            fprintf('Daten geladen! Es wird der Wegpunkt %1.0f berechnet. \r',...
                double(wayInxLst+1));
        end
        
    end
    
    
    
    %% MEX Erzeugung
    clcFilNme = 'clcOptInx_v4_fulStaSpa';
    if mexFlg && clcFlg
        
        setenv OMP_NUM_THREADS 11
        
        numCPU = getenv('OMP_NUM_THREADS');
        
        if isempty(numCPU)
            error('Angabe der Kernanzahl fehlt!')
        end
        
        MexFilNme = [clcFilNme,'_'...
            num2str(engKinNum),'_',...
            num2str(timNum),'_',...
            num2str(batEngNum),'_',...
            num2str(staNum),'_',...
            num2str(round(par.batOcvCof_batEng(1)*1e10)),'_',...
            num2str(geaChgPenCosVal),'_',...
            num2str(numCPU),...
            '_mex'];
        
        if ~exist(MexFilNme,'file')
            
            % Ausgabe des aktuellen Schleifendurchlaufs
            if disFlg
                fprintf('Mexfile wird erzeugt. \r');
            end
            
            % Falls nötig
            % Definition der Input-Types von fct_calcCtgAct
            argTypes = {
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.Constant(wayStp)
                coder.Constant(batEngStp)
                coder.Constant(timStp)
                coder.Constant(batEngNum)
                coder.Constant(timNum)
                coder.Constant(staNum)
                coder.Constant(geaNum)
                coder.Constant(engKinNum)
                coder.Constant(icePenCosVal)
                coder.Constant(geaChgPenCosVal)
                coder.Constant(infVal)
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',1,0) % Definition skalare Variable
                coder.newtype('double',[engKinNum,1],[0 0])
                coder.newtype('double',[engKinNum,1],[0 0])
                coder.newtype('logical',[timNum,engKinNum],[0 0])
                coder.typeof(cosPreTn4)
                coder.typeof(par)
                };
            
            % Mex Konfigurieren
            mexCfg = coder.config('mex');
            mexCfg.IntegrityChecks = false;
            mexCfg.ResponsivenessChecks = false;
            mexCfg.EnableAutoExtrinsicCalls = false;
            mexCfg.ExtrinsicCalls = false;
            mexCfg.EnableVariableSizing = false;
            mexCfg.StackUsageMax = 1e6;
            % Codegenerierung
            codegen(clcFilNme,'-args','argTypes',...
                '-config','mexCfg','-O','enable:openmp','-o',MexFilNme)
        end
    end
    
    % Schleife über alle Wegpunkte
    for wayInx = wayInxLst+1:wayInxEndCyc
        
        %% Initialisierung der Berechnung
        % Vorbereitung der parallen Schleife (verhindern von zu großem
        % Datentransfer und unnötigen Berechnungen)
        
        % Steigung im betrachteten Intervall per Zero-Order-Hold
        slp = slpVec_wayInx(wayInx-1);
        
        % Vektoren der kinetischen Energien im vorherigen Wegschritt
        engKinPreVec_engKinInx = ...
            engKinMat_engKinInx_wayInx(:,wayInx-1);
        % Vektoren der kinetischen Energien im aktuellen Wegschritt
        engKinActVec_engKinInx = ...
            engKinMat_engKinInx_wayInx(:,wayInx);
        
        % Anzahl der kinetischen Energien im aktuellen Wegschritt
        engKinNumAct = engKinNumVec_wayInx(wayInx);
        engKinNumPre = engKinNumVec_wayInx(wayInx-1);
        
        timMinPre = timMinVec(wayInx-1);
        timMinAct = timMinVec(wayInx);
        timNumPre = timNumVec(wayInx-1);
        timNumAct = timNumVec(wayInx);
        
        %% Berechnung des aktuellen Batterieenergiedeltas
        % Durch Funktion in clcOptInx für jede Geschwindigkeit ersetzen
        
        % Die höchsten Ladungsdifferenzen treten bei den langsamsten
        % Geschwindigkeiten auf, da dort die Maximal- und Minimalleistung am
        % längsten anliegt
        timDltMax = wayStp / velMinPre;
        
        % Indexe der niedrigsten und höchsten erreichbaren Batterieladung
        % Grobaschätzung für höchste Intervalldauer
        if batEngStp > 0
            batEngActMinInx = max(1,...
                ceil((batEngMinPre - par.batPwrMax*timDltMax)/batEngStp)+1);
            batEngActMaxInx = min(batEngNum,...
                floor((batEngMaxPre - par.batPwrMin*timDltMax)/batEngStp)+1);
        else
            batEngActMaxInx = batEngBegInx;
            batEngActMinInx = batEngBegInx;
            
        end
        
        
        
        %% Berechnung der Indize der optimalen Vorgänger und der Kosten
        
        if mexFlg
            exeFilNme = MexFilNme;
        else
            exeFilNme = clcFilNme; %#ok<*UNRCH>
        end
        
        eval(['[engKinActInx_tim_engKin,',...Matrix - erreichte v und t Zustände
            'optPreInxTn4,',... Tensor 4. Stufe - optimale Vorgänger
            'cosActTn4] = ',... Tensor 4. Stufe - Kosten zu den aktuellen Punkten
            exeFilNme,'(', ...
            'slp,',... Skalar - Steigung im Intervall
            'batPwrAux,',... Skalar - Nebenverbraucherlast
            '(batEngActMinInx),',... Skalar - min. erreichbare Batterieenergieindex
            '(batEngActMaxInx),',... Skalar - max. erreichbare Batterieenergieindex
            '(batEngPreClcMinInx),',... Skalar - min. vorheriger Batterieenergieindex
            '(batEngPreClcMaxInx),',... Skalar - max. vorheriger Batterieenergieindex
            '(engKinNumAct),',... Skalar - Anzahl der aktuellen kinetischen Energien
            'engKinNumPre,',...
            'wayStp,',... Skalar - Wegschrittweite
            'batEngStp,',... Skalar - Schrittweite der Batterieenergie
            'timStp,',...
            '(batEngNum),',...Skalar - Anzahl der Batterieenergiestützstellen
            '(timNum),',... Skalar - Zeitstützstellen
            '(staNum),',... Skalar - Zustandsstützstellen
            '(geaNum),',...Skalar - Anzahl der Gänge
            '(engKinNum),',... Skalar - Stützstellen der kinetischen Energie
            'icePenCosVal,',...Skalar - Strafkosten für einen Motorstart
            'geaChgPenCosVal,',...Skalar - Strafkosten für einen Zustandswechsel
            'infVal,',...
            'timMinPre,',...
            'timMinAct,',...
            'timNumPre,',...
            'timNumAct,',...
            'engKinActVec_engKinInx,',... Vektor der aktuellen kinetische Energien
            'engKinPreVec_engKinInx,',... Vektor der vorherigen kinetische Energien
            'engKinPreInx_tim_engKin,',...Matrix - erreichte v und t Zustände
            'cosPreTn4,',... Tensor der Kosten im Vorgängerpunkt
            'par',...struct der Fahrzeugparameter
            ');']);
        
        cosActMat = zeros(engKinNum,timNum);
        cosActMat(:,:) = cosActTn4(:,:,batEngEndInx,5);
        if all(all(isinf(cosActTn4)))
            error('Fehler in Kostenberechnung!')
        end
        
        %% Ausgabe des aktuellen Schleifendurchlaufs
        if disFlg
            fprintf('Schleife %1.0f berechnet. %1.0f %% geschafft. \r', ...
                double(wayInx-wayInxBeg), double(((wayInx-wayInxBeg)))/...
                double(wayInxEndCyc-wayInxBeg)*100);
        end
        
        %% Speichern der Ergebnisse für aktuellen Wegpunkt
        
        filNme = [folNme,'/res_wayInx',num2str(wayInx)];
        save(filNme,'optPreInxTn4','cosActTn4',...
            'batEngActMinInx','batEngActMaxInx','engKinActInx_tim_engKin','-v7.3')
        
        %% Werte für den nächsten Schleifendurchlauf sichern
        
        batEngMinPre = (batEngActMinInx-1)*batEngStp;
        batEngMaxPre = (batEngActMaxInx-1)*batEngStp;
        
        batEngPreClcMinInx = batEngActMinInx;
        batEngPreClcMaxInx = batEngActMaxInx;
        
        engKinPreInx_tim_engKin = engKinActInx_tim_engKin;
        
        cosPreTn4 = cosActTn4;
        
        wayInxLst = wayInx;
        wayInxEnd = wayInx;
        
    end
end


%% Auswertung
%--------------------------------------------------------------------------

%% Optimale Pfade rekonstruieren
% Für jede Zielzeit bei gewünschter Zielgeschwindigkeit, Zielladung und
% Antriebsstrangzustand wird eine Trajektorie rekonstruiert

if ~exist('wayInxEnd','var')
    
    % wayInxEnd muss angepasst werden
    wayInxEnd = wayInxLstSet;
    
end

% Zielgeschwindigkeit bestimmen, wenn nicht gegeben
if ~exist('engKinEndInx','var')
    
    % Bei fehlender Vorgabe ist die finale kinetische Energie diejenige mit
    % der geringsten Abweichung zur kinetischen Energie am Start
    [~,engKinEndInx] = min(abs(...
        engKinMat_engKinInx_wayInx(:,wayInxEnd) ...
        - engKinMat_engKinInx_wayInx(1,wayInxBeg)));
    
end


%% Laden des letzten Tensors der optimalen Vorgänger
disp(['Laden der Daten am letzten Wegpunkt (',num2str(wayInxEnd),').'])
filNme = [folNme,'/res_wayInx',num2str(wayInxEnd)];
load(filNme)

% Anzahl der Trajektorieren um die gesuchte Zielladung
batTrjNum = 5;

% Initialisieren der Zeitkoordinaten
timInxMat = zeros(timNum,batTrjNum);
timNumEndVec = zeros(batTrjNum,1);
% gültige Zeitzustände suchen
for batInx = 1:batTrjNum
    
    batInxRel = batInx - ceil(batTrjNum/2);
    
    for timInx = 1:timNumVec(wayInxEnd)
        if ~isinf(cosActTn4(engKinEndInx,timInx,batEngEndInx+batInxRel,staEnd))
            timNumEndVec(batInx ) = timNumEndVec(batInx ) + 1;
            timInxMat(timNumEndVec(batInx ),batInx) = timInx;
        end
    end
end
timNumEnd = max(timNumEndVec);


% Indexvektor der optimalen Zeit
timOptInxTn3_timNumEnd_batEngEnd_wayInx = zeros(timNumEnd,batTrjNum,wayInxEnd);
% Trajektorie der optimalen Zeit
timOptTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);

% Indexvektor der optimalen Batterieenergie
batEngOptInxTn3_timNumEnd_batEngEnd_wayInx = zeros(timNumEnd,batTrjNum,wayInxEnd);
% Trajektorie der optimalen Batterienergie
batEngOptTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);

% Indexvektor der optimalen kinetischen Energien
engKinOptInxTn3_timNumEnd_batEngEnd_wayInx = zeros(timNumEnd,batTrjNum,wayInxEnd);
% Trajektorie der optimalen kin. Energien
engKinOptTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);

% Vektor der optimalen Antriebsstrangzustands
staTn3_timNumEnd_batEngEnd_wayInx = zeros(timNumEnd,batTrjNum,wayInxEnd);

% Costategrenzen für die Zeit
psiTimMinTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);
psiTimMaxTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);
% Costategrenzen für die Batterienergie
psiBatEngMinTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);
psiBatEngMaxTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);
% Costategrenzen für die kinetische Energie
psiEngKinMinTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);
psiEngKinMaxTn3_timNumEnd_batEngEnd_wayInx = inf(timNumEnd,batTrjNum,wayInxEnd);

%% Zielzustände bestimmen

engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(:,:,wayInxEnd) = engKinEndInx;

% Die finale Batterieenergie ist gegeben
batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(:,:,wayInxEnd) = ...
    ones(timNumEnd,1)*(batEngEndInx+(-floor(batTrjNum/2):floor(batTrjNum/2)));

% Es werden alle möglichen Zeitzustände ausgewertet
timOptInxTn3_timNumEnd_batEngEnd_wayInx(:,:,wayInxEnd) = timInxMat(1:timNumEnd,:);

% Der finale Antriebsstrangszustand (dieser ist eine Flussgröße und
% gilt daher im gesamten Intervall). Das heißt, dieser Vektor ist
% um eine Stelle kürzer als die Anzahl der Wegpunkte
staTn3_timNumEnd_batEngEnd_wayInx(:,:,wayInxEnd-1) = staEnd;

%% Rekonstruieren der optimalen Pfade für alle möglichen Zielzustände

for wayInx = wayInxEnd:-1:wayInxBeg
    
    for timTrjInx = 1:timNumEnd
        
        for batTrjInx = 1:batTrjNum
            
            if isinf(engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInxEnd))
                continue
            end
            
            
            if wayInx == wayInxEnd
                
                if isinf(...
                        cosActTn4(...
                        engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                        timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                        batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                        staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)))
                    
                    engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = inf;
                    timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = inf;
                    batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = inf;
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1) = inf;
                    
                    continue
                end
                
            end
            
            
            if wayInx > wayInxBeg
                
                %% Bestimmen der Costates
                
                % Costate für die kinetische Energie
                % Vektor der kinetischen Energie
                
                engKinVec = engKinMat_engKinInx_wayInx(:,wayInx);
                % Kraftstoffenergievektor für jede kinetische Energie
                cosVec_engKin = zeros(engKinNum,1);
                cosVec_engKin(:) = double(...
                    cosActTn4(:,...
                    timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)))';
                % Costate bestimmen
                [psiEngKinMinTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1),...
                    psiEngKinMaxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)] = ...
                    psiClc(cosVec_engKin,...
                    engKinVec,engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx,1));
                
                % Costate für die Zeit
                % Zeitvektor
                timVec = timMinVec(wayInx) + (0:timNum-1)'*timStp;
                % Kraftstoffenergievektor für jede Zeit
                cos_tim = zeros(timNum,1);
                cos_tim(:) = double(...
                    cosActTn4(engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    :,...
                    batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)));
                % Costate bestimmen
                [psiTimMinTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1),...
                    psiTimMaxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)] = ...
                    psiClc(cos_tim,timVec,timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx,1));
                
                % Costate für die Batterienergie
                % Batterieenergievektor
                batEngVec = (0:batEngNum-1)'*batEngStp;
                % Kraftstoffenergievektor für jede Batterieladung
                cos_bat = zeros(batEngNum,1);
                cos_bat(:) = double(cosActTn4(engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    :,...
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)));
                % Costate bestimmen
                [psiBatEngMinTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1),...
                    psiBatEngMaxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1)] = ...
                    psiClc(cos_bat,batEngVec,batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx,1));
                
                %% optimalen Vorgängerindize bestimmen
                
                % für nächsten Schleifendurchlauf
                optInx = optPreInxTn4(engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),...
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1));
                if optInx == 0
                    error('Fehler beim Speichern der optimalen Vorgänger.')
                end
                
                % Bestimmen der optimalen Vorgängerindize
                [engKinPreOptInx,timPreOptInx,batEngPreOptInx,staPreOptInx] = ...
                    ind2sub([engKinNum,timNum,batEngNum,staNum],optInx);
                
                engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1) = engKinPreOptInx;
                timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1) = timPreOptInx;
                batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-1) = batEngPreOptInx;
                
                if wayInx > 2
                    staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx-2) = staPreOptInx;
                end
                
            end
            %% Bestimmen der Optimaltrajektorien
            
            % Ausgabevektors für optimale kinetische Energie beschreiben
            engKinOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = ...
                engKinMat_engKinInx_wayInx(engKinOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx),wayInx);
            
            % Ausgabevektor für die optimale Zeit
            timOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = timMinVec(wayInx) ...
                + (timOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx)-1) * timStp;
            
            % Ausgabevektor für optimale Batterieenergie beschreiben
            batEngOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx) = ...
                (batEngOptInxTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInx,1) - 1) * batEngStp;
            
        end
    end
    if wayInx > wayInxBeg+1
        
        disp(['Lade Wegschritt ',num2str(wayInx-1),'!'])
        filNme = [folNme,'/res_wayInx',num2str(wayInx-1)];
        load(filNme)
        
    end
    
end

%% Berechnung des streckenbezogenen Kraftstoffverbrauchs und der genauen Zielzeit

fulVolPerWayMat = inf(timNumEnd,batTrjNum);
timEndClcMat = inf(timNumEnd,batTrjNum);
cou = 0;
timErr = 0;

for timTrjInx = 1:timNumEnd
    for batTrjInx = 1:batTrjNum
        if ~isinf(engKinOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInxEnd))
            
            [ fulVolPerWayMat(timTrjInx,batTrjInx),timEndClcMat(timTrjInx,batTrjInx) ] ...
                = clcFulVolPerWay( ...
                wayInxBeg,...
                wayInxEnd,...
                wayStp,...
                batPwrAux,...
                slpVec_wayInx,...
                staTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,:),...
                batEngOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,:),...
                engKinOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,:)...
                );
            
            timErr = ...
                timOptTn3_timNumEnd_batEngEnd_wayInx(timTrjInx,batTrjInx,wayInxEnd)...
                -timEndClcMat(timTrjInx,batTrjInx) + timErr;
            cou = cou + 1;
            
        end
    end
end

%% Ausgabe und Speichern
disp('Trajektorien validiert, Grenzen wurden eingehalten')
timErrMen = timErr / cou;

disp(['Der durchschnittliche Fehler im Zeitzustand beträgt ',...
    num2str(timErrMen),' s.'])

save([folNme,'/res',num2str(wayInxEnd),'_',num2str(batEngEnd)],...
    'engKinOptTn3_timNumEnd_batEngEnd_wayInx',...
    'timOptTn3_timNumEnd_batEngEnd_wayInx',...
    'batEngOptTn3_timNumEnd_batEngEnd_wayInx',...
    'staTn3_timNumEnd_batEngEnd_wayInx',...
    'fulVolPerWayMat',...
    'timEndClcMat',...
    'engKinEndInx',...
    'timErrMen',...
    'batEngEndInx',...
    'psiBatEngMinTn3_timNumEnd_batEngEnd_wayInx',...
    'psiBatEngMaxTn3_timNumEnd_batEngEnd_wayInx',...
    'psiTimMinTn3_timNumEnd_batEngEnd_wayInx',...
    'psiTimMaxTn3_timNumEnd_batEngEnd_wayInx',...
    'psiEngKinMinTn3_timNumEnd_batEngEnd_wayInx',...
    'psiEngKinMaxTn3_timNumEnd_batEngEnd_wayInx');

%% Plot
if figFlg
    plotDPres(folNme,wayInxEnd,batEngEnd);
end


%% Ende der Funktion
end


function [psiMax,psiMin] = psiClc( cosVec,staVec,inx )
%PSICLC Calculated the mean Difference Quotient in the cost vector
%   Detailed explanation goes here

wrnFlg = false;

% gültige Indize finden zur Bestimmung der Steigung
inxMen = inx;
inxMin = inf;
for staInx = inxMen-1:-1:1
    if  ~isinf(cosVec(staInx))
        inxMin = staInx;
        break;
    end
end

inxMax = inf;
for staInx = inxMen+1:length(cosVec)
    if  ~isinf(cosVec(staInx))
        inxMax = staInx;
        break;
    end
end

if ~isinf(inxMin)
    % Formel zur Berechnung siehe Paper
    psiMax = (cosVec(inxMin) - cosVec(inxMen)) / ...
        (staVec(inxMin) - staVec(inxMen));
else
    psiMax = NaN;
end

if ~isinf(inxMax)
    % Formel zur Berechnung siehe Paper
    psiMin = (cosVec(inxMen) - cosVec(inxMax)) / ...
        (staVec(inxMen) - staVec(inxMax));
else
    psiMin = NaN;
end

% if isnan(psiMax) && ~isnan(psiMin)
%     psi = psiMin;
%     wrnFlg = true;
% elseif ~isnan(psiMax) && isnan(psiMin)
%     psi = psiMax;
%     wrnFlg = true;
% elseif ~isnan(psiMax) && ~isnan(psiMin)
%     psi = (psiMax + psiMin) / 2;
% else
%     psi = NaN;
% end

end

