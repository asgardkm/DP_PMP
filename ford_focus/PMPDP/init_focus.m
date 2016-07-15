function[inputparams, tst_scalar_struct, fzg_scalar_struct, ...
         tst_array_struct, nedc_array_struct, fzg_array_struct] ...
         = init_focus(config_filename, datafile_dir, write_bool)
% function : initialze structure variables for inputs to clcDP_port()
%
% input  :
%
% output : 
%
% created 01.07.2016 - asgard kaleb marroquin
%% String values for saved .mat array datafiles
fprintf('-Loading model data and parameters...');
% location of tst_array .mat saved file
tst_array_dir   = fullfile(datafile_dir, 'tst_array.mat');   
% location of fzg_array .mat saved file
fzg_array_dir   = fullfile(datafile_dir, 'fzg_array.mat');  

nedc_array_dir  = fullfile(datafile_dir, 'nedc_array.mat');   

focus_data = load(fullfile(datafile_dir, 'MODEL_DATA_IAM'));
          
%% Laden der Modelldaten - SCALAR DATA
% load in data from text file (if running model through matlab and are 
% ignoring simulink (mainConfig.txt)
% - saving SCALAR values
[inputparams, tst_scalar_struct, fzg_scalar_struct] = readConfig_focus(config_filename);
 
%% SAVE & WRITE / LOAD ARRAY DATA
% first check if array data has already been parsed and saved 
%   OR, user simply wishes to rewrite data w/ write_bool
% if so, simply load it up
if ( (exist(tst_array_dir, 'file') == 2) ...
    && (exist(fzg_array_dir, 'file') == 2) ...
    && (~write_bool) )
        tst_array_struct = load(tst_array_dir);
        fzg_array_struct = load(fzg_array_dir);
else % otherwise, proceed to generate array data and save it 
        [tst_array_struct, nedc_array_struct, fzg_array_struct] = ...
            saveArrayData_a(datafile_dir, tst_array_dir, nedc_array_dir, fzg_array_dir);
end
fprintf('done!\n');    


%% rewrite some parameters from focus_data into the other structs
% drag coefficient
fzg_scalar_struct.drgCof        = focus_data.Drag_coeff;
% vehicle mass
fzg_scalar_struct.vehMas        = focus_data.Vehicle_mass;
%rolling resistance
fzg_scalar_struct.whlRosResCof  = focus_data.Rolling_resistance_coeff;
% Dynmaic Rolling Radius (Wheel)
fzg_scalar_struct.whlDrr        = focus_data.Dynamic_rolling_radius_of_wheels;
% Battery Resistance
fzg_scalar_struct.batRstChr     = focus_data.Battery_resistance;
fzg_scalar_struct.batRstDch     = focus_data.Battery_resistance;

% OCV wrt SOC
fzg_scalar_struct.SOC_vs_OCV    = focus_data.OCV_vs_SOC;
% Battery Power Limits
fzg_scalar_struct.batPwrMax     = focus_data.Battery_Power_limit;
fzg_scalar_struct.batPwrMin     = -focus_data.Battery_Power_limit;
% Max Battery Energy
tst_scalar_struct.batEngMax     = focus_data.Battery_Maximal_energy;
% Gear Ratios (ignore the '0' gear)
fzg_array_struct.geaRat         = focus_data.Gear_box_value_eff(2:end,2);
% Gear Efficiency - now a vector, not a scalar anymore
fzg_array_struct.geaEfy         = focus_data.Gear_box_value_eff(2:end,3);
% Fuel Density
fzg_scalar_struct.fuel_density  = focus_data.fuel_density;
% Fuel Lower Heating Value
fzg_scalar_struct.fuel_lower_heating_value = focus_data.fuel_lower_heating_value;
% Fuel Power wrt ICE speed and torque (rad/s)
fzg_array_struct.icePwr_emoSpd_emoTrq = focus_data.ICE_fuel_power_data;
% ICE speed meshgrid/vector (N*m)
fzg_array_struct.iceSpdMgd      = focus_data.ICE_fuel_speed_axis;
% ICE torque meshgird/vector
fzg_array_struct.iceTrqMgd      = focus_data.ICE_fuel_torque_axis;
% boundaries of ICE torque wrt ICE speed(rad/s)
fzg_array_struct.iceTrqMax_emoSpd = focus_data.ICE_TQ_max_vs_Speed;
fzg_array_struct.iceTrqMin_emoSpd = focus_data.ICE_TQ_min_vs_Speed;

% Electric power EM speed and torque
fzg_array_struct.emoPwr_emoSpd_emoTrq = focus_data.MOT_elec_power_data;
% EM speed meshgrid/vector
fzg_array_struct.emoSpdMgd      = focus_data.MOT_elec_speed_axis;
% EM torque meshgrid/vector
fzg_array_struct.emoTrqMgd  	= focus_data.MOT_elec_torque_axis;
% boundaries of EM torque wrt EM speed (rad/s)
fzg_array_struct.emoTrqMax_emoSpd = focus_data.MOT_TQ_max_vs_Speed;
fzg_array_struct.emoTrqMin_emoSpd = focus_data.MOT_TQ_min_vs_Speed;
% EM torque wrt EM speed and power
fzg_array_struct.emoTrq_emoSpd_emoPwr = focus_data.MOT_elec_torque_data;
% EM power meshgrid/vector
fzg_array_struct.emoPwrMgd      = focus_data.MOT_elec_power_axis;
% EM power boundaries
fzg_array_struct.emoPwrMax_emoSpd = focus_data.MOT_Power_limits_vs_Speed(:,2);
fzg_array_struct.emoPwrMin_emoSpd = focus_data.MOT_Power_limits_vs_Speed(:,1);
%% notes:
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
end