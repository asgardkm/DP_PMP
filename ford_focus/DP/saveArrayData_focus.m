function[               ...
    tst_array_struct,   ... structure with array data only from tst model
    nedc_array_struct,  ... structure with input speed profile model data
    fzg_array_struct    ... structure with array data onlz from fahrzeug  
] =                     ...
    saveArrayData_focus ...
(                       ...
    datafile_dir,       ... string containing directory to raw data
    tst_array_dir,      ... directory location of raw tst data
    nedc_array_dir,     ... directory location of raw speed profile data
    fzg_array_dir       ... directory location of raw vehicle param data
)
% function : find, write, and save array data from testData model runs and
%   from fahrzeug parameters. Reason being is because array data must be
%   parsed differently in the c code port than the scalars, requiring a 
%   seperation between the two when calling clcDP_port() with MATLAB_CODER
%   - this code is being ported for own DP algorithm (01.07.2016)
%
% created 01.07.2016 - asgard kaleb marroquin
%% load all data
% load in old saved data - this contains mix of scalar and array data
tstDat800   = load(fullfile(datafile_dir, 'tstDat800'));
nedc        = load(fullfile(datafile_dir, 'nedc'));
FZG         = load(fullfile(datafile_dir, 'vehMdl'));

%% filter array data
% seperate nonscalar and scalar tstDat800 field values
% pull struct field indeces whos values are scalar (will filter these out)
tst_scalar_bool     = structfun(@(x) length(x) == 1, tstDat800);
% get fieldnames of these indexes
tst_names           = fieldnames(tstDat800);
tst_scalar_names    = tst_names(tst_scalar_bool);
tst_array_names     = tst_names(~tst_scalar_bool);
% remove fields which are scalars - only array data remains (and viceversa)
tst_array_struct    = rmfield(tstDat800, tst_scalar_names);


% seperate nonscalar and scalar nedc field values
% pull struct field indeces whos values are scalar (will filter these out)
nedc_scalar_bool     = structfun(@(x) length(x) == 1, nedc);
% get fieldnames of these indexes
nedc_names           = fieldnames(nedc);
nedc_scalar_names    = nedc_names(nedc_scalar_bool);
nedc_array_names     = nedc_names(~nedc_scalar_bool);
% remove fields which are scalars - only array data remains (and viceversa)
nedc_array_struct    = rmfield(nedc, nedc_scalar_names);


% seperate nonscalar fahrzeug field values
% --------------------------------------------
% Löschen von inf und NaN aus Modelldaten
% ^^ replace any infinities and Nans with zeros
% && löschen = delete
FZG.emoTrq_emoSpd_emoPwr(isinf(FZG.emoTrq_emoSpd_emoPwr)) = 0;
% --------------------------------------------
% pull struct field indeces whos values are scalar (will filter these out)
fzg_scalar_bool     = structfun(@(x) length(x) == 1, FZG);
% get fieldnames of these indexes
fzg_names           = fieldnames(FZG);
fzg_scalar_names    = fzg_names(fzg_scalar_bool);
fzg_array_names     = fzg_names(~fzg_scalar_bool);
% remove fields which are scalars - only array data remains
fzg_array_struct    = rmfield(FZG, fzg_scalar_names);

%% write array data to text files
% datafile_dir = 'raw_data';      % defines raw data directory
exist_dir = exist(datafile_dir, 'dir');
if (~exist_dir)
    mkdir(datafile_dir);
end

% write tstDat800 array data
for i = 1 : length(tst_array_names)
    i_name = tst_array_names{i};
    dlmwrite(fullfile(datafile_dir, sprintf('tst.%s.txt', i_name)), tst_array_struct.(i_name), ' '); 
end

% write nedc array data
for i = 1 : length(nedc_array_names)
    i_name = nedc_array_names{i};
    dlmwrite(fullfile(datafile_dir, sprintf('nedc.%s.txt', i_name)), nedc_array_struct.(i_name), ' '); 
end

% write fzg_array data
for i = 1 : length(fzg_array_names)
    i_name = fzg_array_names{i};
    dlmwrite(fullfile(datafile_dir, sprintf('FZG.%s.txt', i_name)), fzg_array_struct.(i_name), ' ');
end

%% write array data to .mat files
save(tst_array_dir, 'tst_array_struct');
save(nedc_array_dir, 'nedc_array_struct');
save(fzg_array_dir, 'fzg_array_struct');

end