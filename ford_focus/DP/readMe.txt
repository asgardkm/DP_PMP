readMe.txt

This is a quick readMe for running the DP code.
Created 12.08.2016 by asgard kaleb marroquin
					mail : kmarroquin@mail.usf.edu

----- Main Script --------------------------------------------------
The main script to run is called mainScript_focus.m, located in the 'DP' directory 
along with most of the code's other functions.

mainScript_focus consists of three parts: 
	1. Defining your work directory (set it to wherever you place the DP directory), 
	2. data loading (init_focus.m), and 
	3. running the actual algorithm(runFocusDP.m), where the most of the code is located.
----------------------------------------------------------------------


----- Input Readin Code (init_focus.m) -------------------------------
This function reads in both scalar and array input values for DP.
	- Scalar data is saved under '../model_data/mainConfig_focus.txt'.
	- Array data is saved raw under '/raw_data/'.
	
Note that not all values here will be carried over; some outside data for
the vehicle overwrite some fields shown above. To see which fields are 
overwritten, please see init_focus.m.
----------------------------------------------------------------------


----- Functional Code - (runFocusDP.m) -------------------------------
runFocusDP.m is the function which does the DP calculations for the given input parameters
defined in init_focus.m above.

runFocusDP.m is also divided up into three pieces:
	1. Data preprocessing (runDP_preProcessing.m), 
	2. dynamic programming code (clcDP_focus.m / clcDP_focus_useGeaVec.m), and
	3. selecting optimal results from DP calculations + plots(findPlotOptPath.m).
	
Step 2 - There are two versions of the DP code: one version which calculates the optimal gear  the dynamic programming code - has had MEX files created for them and therefore also
have corresponding .proj files.

Also, when running the mex files, if the original parameters are chagned, the mex file
may return a dimension error. If so, simply open the mex project and change the input's
dimensions and rebuilt - this will resolve the issue.

Also included are two clcDP functions that are emoPWrElectricOnly. These are the original pieces
of code that did not interpolate electric power to mechanical power through a lookup table.
Although it sounds off, this returned better results than with interpolation.
----------------------------------------------------------------------


----- Optimization Code - (findPlotOptPath.m) ------------------------
This part of the code finds the optimal path and resultant characteristics for a given
set of ending SOC values. The SOC values are defined in mainConfig_focus.txt, but they can
be overwritten here in the findPlotOptPath() function call as well.

Please note that trying to run every single SOC end at once (0-100%) may result in an error, due 
to the way time indexes are selected in reverse for optimization. Although I am sure there is a 
way around this, I did not do so in this code.
----------------------------------------------------------------------

----------------------------------------------------------------------
Viel Glück!
----------------------------------------------------------------------