% mainScript_a.m
% this script will be for running DP fuel-minimizing optimization algorithm
%% define work directory
cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\algorithmus\PMPDP\');
addpath('../model_data', '../functions')
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/RCP')

%% define clcDP structure inputs
% define init_a() inputs

% define mainConfig.txt string location
config_filename = 'mainConfig_a.txt';
% define raw data directory
datafile_dir    = 'raw_data';
% bool for if user wishes to rewrite raw data
write_bool      = 1;

% call init_port() - outputs are input structures to clcDP_port()
[inputparams, tst_scalar_struct, fzg_scalar_struct, tst_array_struct, nedc_array_struct, fzg_array_struct]...
         = init_a(config_filename, datafile_dir, write_bool);
%% call clcDP_port()
[engKinOptVec,          ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,    ... Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,    ... Vektor - optimale Kraftstoffenergieänderung
    staVec,             ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,    ... Vektor - costate für kinetische Energie
    fulEngOpt,          ... Skalar - optimale Kraftstoffenergie
    resVld]             ...
    = runAlgorithmusDP( ...
    inputparams,        ...
    tst_scalar_struct,  ...
    fzg_scalar_struct,  ...
    tst_array_struct,   ...
    nedc_array_struct,  ...
    fzg_array_struct    ...
    );