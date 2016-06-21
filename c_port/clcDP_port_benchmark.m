% clcDP_port_benchmark.m script
% for matlab_coder purposes - translating clcDP_port into c code

%% define work directory
cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\c_port');
% cd('/home/kaulef/Documents/DAAD/TUD/4Kaleb/RCP')

%% define clcDP_port structure inputs
% define init_port() inputs

% define mainConfig.txt string location
config_filename = 'mainConfig.txt';
% define raw data directory
datafile_dir    = 'raw_data';
% bool for if user wishes to rewrite raw data
write_bool      = 1;

% call init_port() - outputs are input structures to clcDP_port()
[inputparams, testparams, fahrparams, tst_array_struct, fzg_array_struct]...
         = init_port(config_filename, datafile_dir, write_bool);
%% call clcDP_port()
[engKinOptVec,          ... Vektor - Trajektorie der optimalen kin. Energien
    batEngDltOptVec,    ... Vektor - optimale Batterieenergieänderung
    fulEngDltOptVec,    ... Vektor - optimale Kraftstoffenergieänderung
    staVec,             ... Vektor - Trajektorie des optimalen Antriebsstrangzustands
    psiEngKinOptVec,    ... Vektor - costate für kinetische Energie
    fulEngOpt,          ... Skalar - optimale Kraftstoffenergie
    resVld]             ...
    = clcDP_port(       ...
    inputparams,        ...
    testparams,         ...
    fahrparams,         ...
    tst_array_struct,   ...
    fzg_array_struct    ...
    );