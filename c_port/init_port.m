% notes:
%   c code will read in array data
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
%% directory assignment scripts
% addpath('../functions','../model_data','PMPDP')
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/RCP')

%% String values for raw data directory and saved .mat array datafiles
datafile_dir = 'raw_data';          % defines raw data directory
tst_array_dir = fullfile(datafile_dir,'tst_array.mat');    % location of tst_array .mat saved file
fzg_array_dir = fullfile(datafile_dir, 'fzg_array.mat');    % location of fzg_array .mat saved file
%% Laden der Modelldaten
% load in data from text file (if running model through matlab and are 
% ignoring simulink (mainConfig.txt)
% - saving SCALAR values
[inputparams, testparams, fahrparams] = readConfig_port('mainConfig.txt');
 
%% SAVING LOADED ARRAY DATA INTO TEXT FILES 
% first check if array data has already been parsed and saved 
% if so, simply load it up
if ((exist(tst_array_dir, 'file') == 2) && (exist(fzg_array_dir, 'file') == 2))
    tst_array_struct = load(tst_array_dir);
    fzg_array_struct = load(fzg_array_dir);
else % otherwise, proceed to generate array data and save it 
    [tst_array_struct, fzg_array_struct] = saveArrayData(datafile_dir);
end
