README c_port
 - created 29.06.2016 by asgard kaleb marroquin
 
This folder contains the ported MATLAB_CODER-generated C code for the DP_PMP algorithm, as well as the 
modified MATLAB code used to generate the C code.

The C code model is ran under mainScript.c, and the entire C environment is saved under modelProject.dev.
The C code will load in raw input data (scalar and array) and run the DP_PMP algorithm. However, due to 
differences in C and MATLAB index syntax, the current C output is not accurate - more time is needed to 
correct the ported MATLAB_CODER code.

The necessary scalar model data is saved under mainConfig.txt. Here, three types of scalar parameters are
defined: model input parameters, test data values, and fahrzeug variables.
Required raw array data required for C is saved under raw_data.

The MATLAB code can be run under clcDP_port_benchmark.m. The MEX/C port project can be loaded under 
clcDP_port.prj. Backend generated code is saved under the codegen directory.