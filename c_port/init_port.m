% addpath('../functions','../model_data','PMPDP')
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/RCP')

%% Laden der Modelldaten
datafile_dir = 'raw_data';      % defines raw data directorz
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

%% SAVING LOADED DATA INTO TEXT FILES 
%   c code will read in this data
%   needed bc MATLAB_CODER cannot process load() function
%   need to save all vectors and matrices - scalars can be read no prob w/
%       mainConfig.txt - just assign them to another group w/ new keyword
%
% make sure you load in these scalars first in mainConfig! They define dims
%   tstDat800.staNum    - DEFINES NUMBER OF GEARS (6)
%   tstDat800.wayNum    - DEFINES NUMBER OF PATH_IDX (800)
%   tstDat800.engKinNum - DEFINES NUMBER OF KINETIC ENERGY STATES (11)

% variables that neeed saving:
%   FZG.batOcvCof_batEng (1x2)
%   FZG.geaRat (1xstaNum)
%   FZG.iceSpdMgd (150x100)
%   FZG.iceTrqMgd (150x100)
%   FZG.iceFulPwr_iceSpd_iceTrq (150x100)
%   FZG.iceTrqMaxCof (1x3)
%   FZG.iceTrqMinCof (1x3)
%   FZG.emospdMgd (150x100)
%   FZG.emoTrqMgd (150x100)
%   FZG.emoPwr_emoSpd_emoTrq (150x100)
%   FZG.emoTrqMin_emoSpd (100x1)
%   FZG.emoTrqMax_emoSpd (100x1)
%   FZG.emoPwrMgd (150x100)
%   FZG.emoPwrMax_emoSpd (100x1)
%   FZG.emoPwrMin_emoSpd (100x1)
%   tstDat800.slpVec_wayInx (wayNum x 1)
%   tstDat800.engKinMat_engKinInx_wayInx (engKinNum x wayNum)
%   tstDat800.engKinNumVec_wayInx (wayNum x 1)
%
% if keeping the FZG structure in  c code, make sure to preallocate for
% space! FZG has 15 scalars, 8 vectors, and 6 matrices - 29 total
%% L�schen von inf und NaN aus Modelldaten
% ^^ replace any infinities and Nans with zeros
% && l�schen = delete
FZG.emoTrq_emoSpd_emoPwr(isinf(FZG.emoTrq_emoSpd_emoPwr)) = 0;

%% load in data from text file (if running model through matlab and are 
% ignoring simulink (mainConfig.txt)
inputparams = readConfig_port('mainConfig.txt');

% asign values from struct
disFlg          = inputparams.disFlg;
wayStp          = inputparams.wayStp;
batEngStp       = inputparams.batEngStp;
batEngBeg       = inputparams.batEngBeg;
batPwrAux       = inputparams.batPwrAux;
psiBatEng       = inputparams.psiBatEng;
psiTim          = inputparams.psiTim;
staChgPenCosVal = inputparams.staChgPenCosVal;
wayInxBeg       = inputparams.wayInxBeg;
wayInxEnd       = inputparams.wayInxEnd;
staBeg          = inputparams.staBeg;

%% write stuff to text files
exist_dir = exist(datafile_dir, 'dir');
if (~exist_dir)
    mkdir(datafile_dir);
end
%tstDat800 data
% tstDat800.slpVec_Inx[wayNum x 1]
dlmwrite(fullfile(datafile_dir, 'tstDat800.slpVec_Inx.txt'), tstDat800.slpVec_wayInx);
% tstDat800.engKinMat_engKinInx_wayInx[engKinNum x wayNum]
dlmwrite(fullfile(datafile_dir, 'tstDat800.engKinMat_engKinInx_wayInx.txt'), tstDat800.engKinMat_engKinInx_wayInx);
% tstDat800.engKinNumVec_wayInx[wayNum x 1]
dlmwrite(fullfile(datafile_dir, 'tstDat800.engKinNumVec_wayInx.txt'), tstDat800.engKinNumVec_wayInx);

% FZG data
% FZG.batOcvCof_batEng (1x2)
dlmwrite(fullfile(datafile_dir, 'FZG.batOcvCof_batEng.txt'), FZG.batOcvCof_batEng);
%   FZG.geaRat (1xstaNum)
dlmwrite(fullfile(datafile_dir, 'FZG.geaRat.txt'), FZG.geaRat);
%   FZG.iceSpdMgd (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.iceSpdMgd.txt'), FZG.iceSpdMgd);
%   FZG.iceTrqMgd (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.iceTrqMgd.txt'), FZG.iceTrqMgd);
%   FZG.iceFulPwr_iceSpd_iceTrq (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.iceFulPwr_iceSpd_iceTrq.txt'), FZG.iceFulPwr_iceSpd_iceTrq);
%   FZG.iceTrqMaxCof (1x3)
dlmwrite(fullfile(datafile_dir, 'FZG.iceTrqMaxCof.txt'), FZG.iceTrqMaxCof);
%   FZG.iceTrqMinCof (1x3)
dlmwrite(fullfile(datafile_dir, 'FZG.iceTrqMinCof.txt'), FZG.iceTrqMinCof);
%   FZG.emoSpdMgd (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.emoSpdMgd.txt'), FZG.emoSpdMgd);
%   FZG.emoTrqMgd (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.emoTrqMgd.txt'), FZG.emoTrqMgd);
%   FZG.emoPwr_emoSpd_emoTrq (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.emoPwr_emoSpd_emoTrq.txt'), FZG.emoPwr_emoSpd_emoTrq);
%   FZG.emoTrqMin_emoSpd (100x1)
dlmwrite(fullfile(datafile_dir, 'FZG.emoTrqMin_emoSpd.txt'), FZG.emoTrqMin_emoSpd);
%   FZG.emoTrqMax_emoSpd (100x1)
dlmwrite(fullfile(datafile_dir, 'FZG.emoTrqMax_emoSpd.txt'), FZG.emoTrqMax_emoSpd);
%   FZG.emoPwrMgd (150x100)
dlmwrite(fullfile(datafile_dir, 'FZG.emoPwrMgd.txt'), FZG.emoPwrMgd);
%   FZG.emoPwrMax_emoSpd (100x1)
dlmwrite(fullfile(datafile_dir, 'FZG.emoPwrMax_emoSpd.txt'), FZG.emoPwrMax_emoSpd);
%   FZG.emoPwrMin_emoSpd (100x1)
dlmwrite(fullfile(datafile_dir, 'FZG.emoPwrMin_emoSpd.txt'), FZG.emoPwrMin_emoSpd);