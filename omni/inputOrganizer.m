% function for reading in xls omni file and organizing it

%% read in input

cd('~/Documents/omni/')
% this will change based on ext and on conc_output (possbile : 1-4)
[~, txt_all, data_all] = xlsread('Proj_list_3_15_16.xlsx', 2);

%% analyze input

% txt_all is what we want to use - interested in third column
%   want to extract number combination, usually 8-9 characters long

number_name   = txt_all(:,3);
morenum_name  = txt_all(:,4);
% split up data based on spaces
all_split   = regexp(number_name, ' ', 'split');
all_split2  = regexp(morenum_name, ' ', 'split');

select_dash   = cell(length(all_split), 1);
select_dash2  = select_dash;
select_nodash = select_dash;
good_idx    = select_dash;
num_check   = select_dash;
num_check2  = select_dash;
name_check  = select_dash;
proj_number = select_dash;
proj_name   = select_dash;
size_tmp    = select_dash;


% get the ones that have dashes
for i = 1 : length(all_split)
    select_dash{i} = regexp(all_split{i}, '\d-\d', 'match'); 
    select_dash2{i} = regexp(all_split2{i}, '\d-\d', 'match'); 
    select_nodash{i} = cellfun(@(x) isempty(x), select_dash{i});
    %good_idx{i}    = which(isempty(select_dash{i}));
end

% if one - its not empty - use this idx (for num and name)
for i = 1 : length(select_dash)
   num_check{i} = ~cellfun('isempty', select_dash{i}); 
   num_check2{i} = ~cellfun('isempty', select_dash2{i}); 
   name_check{i} = select_nodash{i};
   
   if (any(num_check{i}) || any(num_check2{i}))     % if either col has num
       if (any(num_check{i}) && any(num_check2{i})) % if both col has num
           if strcmp(all_split{i}(num_check{i}), all_split2{i}(num_check2{i}))      % if are the same num
               proj_number{i} = strjoin(all_split{i}(num_check{i})); % TADA! GOT PROJ NUMBER!
           else 
               proj_number{i} = strjoin([all_split{i}(num_check{i}), all_split2{i}(num_check2{i})]);
           end
       elseif ~any(num_check2{i}) % if theres nothing in the second col
           proj_number{i} = strjoin(all_split{i}(num_check{i})); % TADA! GOT PROJ NUMBER!
       elseif ~any(num_check{i})  % if theres nothing in the first col
           proj_number{i} = strjoin(all_split2{i}(num_check2{i})); % TADA! GOT PROJ NUMBER!
       end
   end
   
   if any(name_check{i})
       proj_name{i} = strjoin(all_split{i}(name_check{i})); % GOT PROJ NAME
   end
end

%% set up output cellframe to write to excel - add one column
output_txt = cell(length(txt_all), length(txt_all(1,:)) + 1);

% send input column 4 to output column 5
output_txt(:,5) = txt_all(:,4);

% send proj_name to output column 4
output_txt(:,4) =  proj_name;

% send proj_number to output column 3
output_txt(:,3) = proj_number;

% send input column 2 (client) to output column 2
output_txt(:,2) = txt_all(:,2);

% send input column 1 to output column 1
output_txt(:,1) = txt_all(:,1);

%% write to excel

% %test
% test = cell(length(all_split), 1);
% 
% for i = 1 : length(output_txt);
%     for j = 1 : length(output_txt(1,:));
%     test{i,j} = strcat(output_txt(i,j), ',');
%     end
% end
% out_test = cellfun(@(x) x(:), test);

cell2csv('processed_projlist_3_15_16.csv', output_txt, ',', 2013);
cell2csv('processed_projlist2_3_15_16.csv', output_txt);

