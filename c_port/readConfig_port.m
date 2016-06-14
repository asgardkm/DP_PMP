function[fileparams] = readConfig(filename)
% function: read in data definined in an external text file
%
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
keywords = {'START', 'END'};

keyindex = zeros(length(keywords), 1);

% look for keywords inside of mat - regexp!
for i = 1 : length(keywords)
   tmp = regexp(mat, keywords{i}); 
   keyindex(i) = find(~cellfun(@isempty, tmp));
end

filevar_start   = keyindex(1) + 1;
filevar_stop    = keyindex(2) - 1;

%% FILE INPUTS
% loop through the skip and lines and read in the values
for k = filevar_start : filevar_stop
    tmp_string = strtrim(strsplit(mat{k}, ','));
    value{k - keyindex(1)} = tmp_string{1};
    name{k - keyindex(1)}  = tmp_string{2};
end

% save values from the looping above (all num values)
disFlg          = str2double(value{~cellfun(@isempty, regexp(name, 'disFlg'))}); 
wayStp          = str2double(value{~cellfun(@isempty, regexp(name, 'wayStp'))}); 
batEngStp       = str2double(value{~cellfun(@isempty, regexp(name, 'batEngStp'))}); 
batEngBeg       = str2double(value{~cellfun(@isempty, regexp(name, 'batEngBeg'))}); 
batPwrAux       = str2double(value{~cellfun(@isempty, regexp(name, 'batPwrAux'))});
psiBatEng       = str2double(value{~cellfun(@isempty, regexp(name, 'psiBatEng'))});
psiTim          = str2double(value{~cellfun(@isempty, regexp(name, 'psiTim'))});
unused          = str2double(value{~cellfun(@isempty, regexp(name, 'unused'))});
staChgPenCosVal = str2double(value{~cellfun(@isempty, regexp(name, 'staChgPenCosVal'))});
wayInxBeg       = str2double(value{~cellfun(@isempty, regexp(name, 'wayInxBeg'))});
wayInxEnd       = str2double(value{~cellfun(@isempty, regexp(name, 'wayInxEnd'))});
staBeg          = str2double(value{~cellfun(@isempty, regexp(name, 'staBeg'))});


% throw values into a structure
fileparams = struct('disFlg',           disFlg, ...
                    'wayStp',           wayStp, ...
                    'batEngStp',        batEngStp, ...
                    'batEngBeg',        batEngBeg, ...
                    'batPwrAux',        batPwrAux, ...
                    'psiBatEng',        psiBatEng, ...
                    'psiTim',           psiTim,...
                    'unused',           unused,...
                    'staChgPenCosVal',  staChgPenCosVal,...
                    'wayInxBeg',        wayInxBeg,...
                    'wayInxEnd',        wayInxEnd,...
                    'staBeg',           staBeg...
                );

% clear tmp variables to save memory
clear disFlg wayStp batEngStp batEngBeg batPwrAux psiBatEng psiTim...
    unused staChgPenCosVal wayInxBeg wayInxEnd staBeg


%% CLOSE FDATA - END
% and then close the connection now that the data is now in matlab as a var
fclose(fdata);

end 