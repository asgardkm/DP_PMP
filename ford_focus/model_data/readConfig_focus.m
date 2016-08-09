function[fileparams, testparams, fahrparams] = readConfig_focus(filename)
% function: read in data definined in an external text file
%
% note - function maz need maintainance, only is useful for matlub runs
% data for c_port must be saved and read from text files directly; c cannot
% port matlab functions like cell functions, regexp, fopen, etc
% created 31mai2016 by asgard kaleb marroquin

%% READING IN mainConfig.txt
% read in filename :
fdata = fopen(filename, 'r');

% read in the file
a = ' ';
i = 1;

% save all raw text in as mat
while ischar(a)
        a  = fgets(fdata);
        % add data while text still exists
        if ischar(a)
                mat{i} = a;
                i = i + 1;
        % once at end of text file, break out of loop
        else
                break
        end
end

%% DEFINING AND FINDING KEY WORDS
% define key words for finding the data we want
keywords = {'PARAMS_START',     'PARAMS_END', ...
            'TSTDAT_START',     'TSTDAT_END', ...
            'FAHRZEUG_START',   'FAHRZEUG_END'};

keyindex = zeros(length(keywords), 1);

% look for keywords inside of mat - regexp!
for i = 1 : length(keywords)
   tmp = regexp(mat, keywords{i}); 
   keyindex(i) = find(~cellfun(@isempty, tmp));
end

filevar_start   = keyindex(1) + 1;
filevar_stop    = keyindex(2) - 1;
testvar_start   = keyindex(3) + 1;
testvar_stop    = keyindex(4) - 1;
fahrvar_start   = keyindex(5) + 1;
fahrvar_stop    = keyindex(6) - 1;

%% FILE INPUTS 1 & 2 - PARAMS
% loop through the skip and lines and read in the values
for k = filevar_start : filevar_stop
    tmp_string = strtrim(strsplit(mat{k}, ','));
    value{k - keyindex(1)} = tmp_string{1};
    name{k - keyindex(1)}  = tmp_string{2};
end

% save values from the looping above (all num values)
disFlg          = str2double(value{~cellfun(@isempty, regexp(name, 'disFlg'))}); 
iceFlgBool      = str2double(value{~cellfun(@isempty, regexp(name, 'iceFlgBool'))});
brkBool         = str2double(value{~cellfun(@isempty, regexp(name, 'brkBool'))}); 
iceExtBool      = str2double(value{~cellfun(@isempty, regexp(name, 'iceExtBool'))});
timStp          = str2double(value{~cellfun(@isempty, regexp(name, 'timStp'))}); 
batEngBegMinRat = str2double(value{~cellfun(@isempty, regexp(name, 'batEngBegMinRat'))}); 
batEngBegMaxRat = str2double(value{~cellfun(@isempty, regexp(name, 'batEngBegMaxRat'))}); 
batEngEndMinRat = str2double(value{~cellfun(@isempty, regexp(name, 'batEngEndMinRat'))}); 
batEngEndMaxRat = str2double(value{~cellfun(@isempty, regexp(name, 'batEngEndMaxRat'))}); 
batPwrAux       = str2double(value{~cellfun(@isempty, regexp(name, 'batPwrAux'))});
staChgPenCosVal = str2double(value{~cellfun(@isempty, regexp(name, 'staChgPenCosVal'))});
timInxBeg       = str2double(value{~cellfun(@isempty, regexp(name, 'timInxBeg'))});
timInxEnd       = str2double(value{~cellfun(@isempty, regexp(name, 'timInxEnd'))});
engBeg          = str2double(value{~cellfun(@isempty, regexp(name, 'engBeg'))});
engEnd          = str2double(value{~cellfun(@isempty, regexp(name, 'engEnd'))});
staBeg          = str2double(value{~cellfun(@isempty, regexp(name, 'staBeg'))});


% throw values into a structure
fileparams = struct('disFlg',           disFlg,             ...
                    'iceFlgBool',       iceFlgBool,         ...
                    'brkBool',          brkBool,            ...
                    'iceExtBool',       iceExtBool,         ...
                    'timStp',           timStp,             ...
                    'batEngBegMinRat',  batEngBegMinRat,    ...
                    'batEngBegMaxRat',  batEngBegMaxRat,    ...
                    'batEngEndMinRat',  batEngEndMinRat,    ...
                    'batEngEndMaxRat',  batEngEndMaxRat,    ...
                    'batPwrAux',        batPwrAux,          ...
                    'staChgPenCosVal',  staChgPenCosVal,    ...
                    'timInxBeg',        timInxBeg,          ...
                    'timInxEnd',        timInxEnd,          ...
                    'engBeg',           engBeg,             ...
                    'engEnd',           engEnd,             ...
                    'staBeg',           staBeg              ...
                );

% clear tmp variables to save memory
clear disFlg iceFlgBool brkBool iceExtBool timStp batEngStp batEngBegMinRat ...
        batEngBegMaxRat batEngEndMinRat batEngEndMaxRat batPwrAux           ...
        staChgPenCosVal timInxBeg timInxEnd engBeg engEnd staBeg
    
%% FILE INPUTS 3 & 4 - TESTDAT800
% loop through the skip and lines and read in the values
for k = testvar_start : testvar_stop
    tmp_string = strtrim(strsplit(mat{k}, ','));
    value{k - keyindex(1)} = tmp_string{1};
    name{k - keyindex(1)}  = tmp_string{2};
end

% save values from the looping above (all num values)
useGeaSta   = str2double(value{~cellfun(@isempty, regexp(name, 'useGeaSta'))}); 
staNum      = str2double(value{~cellfun(@isempty, regexp(name, 'staNum'))}); 
geaStaMin   = str2double(value{~cellfun(@isempty, regexp(name, 'geaStaMin'))}); 
geaStaMax   = str2double(value{~cellfun(@isempty, regexp(name, 'geaStaMax'))}); 
engStaNum   = str2double(value{~cellfun(@isempty, regexp(name, 'engStaNum'))}); 
engStaMin   = str2double(value{~cellfun(@isempty, regexp(name, 'engStaMin'))}); 
engStaMax   = str2double(value{~cellfun(@isempty, regexp(name, 'engStaMax'))}); 
batEngMin   = str2double(value{~cellfun(@isempty, regexp(name, 'batEngMin'))});
batEngStp   = str2double(value{~cellfun(@isempty, regexp(name, 'batEngStp'))}); 
batEngMax   = str2double(value{~cellfun(@isempty, regexp(name, 'batEngMax'))});

% throw values into a structure
testparams = struct('useGeaSta',        useGeaSta,  ...
                    'staNum',           staNum,     ...
                    'geaStaMin',        geaStaMin,  ...
                    'geaStaMax',        geaStaMax,  ...
                    'engStaNum',        engStaNum,  ...
                    'engStaMin',        engStaMin,  ...
                    'engStaMax',        engStaMax,  ...
                    'batEngMin',        batEngMin,  ...
                    'batEngStp',        batEngStp,  ...
                    'batEngMax',        batEngMax   ...
                    );

% clear tmp variables to save memory
clear useGeaSta staNum geaStaMin geaStaMax engStaNum engStaMin engStaMax...
        batEngMin batEngStp batEngMax

%% FILE INPUTS 5 & 6 - FAHRZEUG
% loop through the skip and lines and read in the values
for k = fahrvar_start : fahrvar_stop
    tmp_string = strtrim(strsplit(mat{k}, ','));
    value{k - keyindex(1)} = tmp_string{1};
    name{k - keyindex(1)}  = tmp_string{2};
end

% save values from the looping above (all num values)
vehVelMin       = str2double(value{~cellfun(@isempty, regexp(name, 'vehVelMin'))}); 
vehVelMax       = str2double(value{~cellfun(@isempty, regexp(name, 'vehVelMax'))}); 
vehVelThresh    = str2double(value{~cellfun(@isempty, regexp(name, 'vehVelThresh'))}); 
vehAccMax       = str2double(value{~cellfun(@isempty, regexp(name, 'vehAccMax'))}); 
vehAccMin       = str2double(value{~cellfun(@isempty, regexp(name, 'vehAccMin'))}); 
drgCof          = str2double(value{~cellfun(@isempty, regexp(name, 'drgCof'))}); 
vehMas          = str2double(value{~cellfun(@isempty, regexp(name, 'vehMas'))});
whlRosResCof    = str2double(value{~cellfun(@isempty, regexp(name, 'whlRosResCof'))});
whlDrr          = str2double(value{~cellfun(@isempty, regexp(name, 'whlDrr'))});
batRstChr       = str2double(value{~cellfun(@isempty, regexp(name, 'batRstChr'))});
batRstDch       = str2double(value{~cellfun(@isempty, regexp(name, 'batRstDch'))});
batPwrMax       = str2double(value{~cellfun(@isempty, regexp(name, 'batPwrMax'))});
batPwrMin       = str2double(value{~cellfun(@isempty, regexp(name, 'batPwrMin'))});
geaEfy          = str2double(value{~cellfun(@isempty, regexp(name, 'geaEfy'))});
fulDen          = str2double(value{~cellfun(@isempty, regexp(name, 'fulDen'))});
fulLhv          = str2double(value{~cellfun(@isempty, regexp(name, 'fulLhv'))});

% throw values into a structure
fahrparams = struct('vehVelMin',        vehVelMin,      ...
                    'vehVelMax',        vehVelMax,      ...
                    'vehVelThresh',     vehVelThresh,   ...
                    'vehAccMax',        vehAccMax,      ...
                    'vehAccMin',        vehAccMin,      ...
                    'drgCof',           drgCof,         ...
                    'vehMas',           vehMas,         ...
                    'whlRosResCof',     whlRosResCof,   ...
                    'whlDrr',           whlDrr,         ...
                    'batRstChr',        batRstChr,      ...
                    'batRstDch',        batRstDch,      ...
                    'batPwrMax',        batPwrMax,      ...
                    'batPwrMin',        batPwrMin,      ...
                    'geaEfy',           geaEfy,         ...
                    'fulDen',           fulDen,         ...
                    'fulLhv',           fulLhv          ...
                    );

% clear tmp variables to save memory
clear vehVelMin vehVelMax vehVelThresh vehAccMax vehAccMin drgCof vehMas...
        whlRosResCof whlDrr batRstChr batRstDch batPwrMax batPwrMin ...
        geaEfy fulDen fulLhv

%% CLOSE FDATA - END
% and then close the connection now that the data is now in matlab as a var
fclose(fdata);

end 