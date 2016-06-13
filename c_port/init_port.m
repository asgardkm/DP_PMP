% addpath('../functions','../model_data','PMPDP')
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/RCP')

%% Laden der Modelldaten

% saved structure data from './model data'
load vehMdl 

% % Inhalt des Parameter-Structs par in den Workspace schreiben
%  -- Inahlt = Content

% parNms = fieldnames(par);
% 
% for nmeInx=1:length(parNms)
%     eval([parNms{nmeInx},' = par.(parNms{nmeInx});']);    
% end

FZG = par;
clear par

% input dummy engKinBegInx value for function
engKinBegInx = 1;

load tstDat800

%% Löschen von inf und NaN aus Modelldaten
% ^^ replace any infinities and Nans with zeros
% && löschen = delete
FZG.emoTrq_emoSpd_emoPwr(isinf(FZG.emoTrq_emoSpd_emoPwr)) = 0;

%% load in data from text file (if running model through matlab and are 
% ignoring simulink (mainConfig.txt)
inputparams = readConfig('mainConfig.txt');

% asign values from struct
disFlg          = inputparams.disFlg;
wayStp          = inputparams.wayStp;
batEngStp       = inputparams.batEngStp;
batEngBeg       = inputparams.batEngBeg;
batPwrAux       = inputparams.batPwrAux;
psiBatEng       = inputparams.psiBatEng;
psiTim          = inputparams.psiTim;
unused          = inputparams.unused;
staChgPenCosVal = inputparams.staChgPenCosVal;
wayInxBeg       = inputparams.wayInxBeg;
wayInxEnd       = inputparams.wayInxEnd;
staBeg          = inputparams.staBeg;
    