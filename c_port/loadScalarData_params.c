// loadScalarData.c
// created 15.June.2016 by asgard kaleb marroquin (originally called main.c)
//
// step 1: include the readConfig_ctest.c function and get the vars
// into this environment and print - Done 20.06.2016!
// step 2: load in all the vector and matrix data from matlab b/c the loadin
// functions from matlab cannot be ported directly into c w/ matlab coder
// step 3: organize all the inputs as structures (respective structures?) _ necessary?
// step 4: feed inputs into generated DP_PMP algorithm code and see what happens
//
// 27.06.2016 - looks like its about finished!! now need to feed to clcDP_port

#include <stdio.h>
#include <stdlib.h>
#include "loadScalarData_params.h"
#include "readConfig.h"
#include "findNumVars.h"
#include "readRawText.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"

//#define CONFIGFILE_DIR "mainConfig.txt"		// define mainConfig.txt file location

struct0_T loadScalarData_params(char *mainConfigDir){

		int i, m, n;						// loop vars
		double i_value;
		char *i_name;
		
//		char *configfile = mainConfigDir;					// define mainConfig.txt file location
		char *configfile = mainConfigDir;					// define mainConfig.txt file location

		// defining mainConfig.txt keywords
		char *params_keystart;
		char *params_keyend;
		char *tstdat_keystart;
		char *tstdat_keyend;
		char *fahrzg_keystart;
		char *fahrzg_keyend;
		
		// define keywords
		params_keystart = "PARAMS_START";
		params_keyend 	= "PARAMS_END";
		tstdat_keystart = "TSTDAT_START";
		tstdat_keyend 	= "TSTDAT_END"; 
		fahrzg_keystart = "FAHRZEUG_START";
		fahrzg_keyend 	= "FAHRZEUG_END";
		
		// function call: find number of input parameters
		int numParams  	= findNumVars(configfile, params_keystart, params_keyend);
					
		// 22.06.2016 - exending buffer portion so that it populates a structure
		struct0_T params_scalar_struct;
 		
		// define input_params struct - will populate w/ readConfig.c
		struct model_params *params_struct;
	
		// buffer for each struct data group - ensures that each struct have distinct pointer addresses from each other
		struct model_params params_buffer[numParams];

		// function call: load in structure wiih all input parameters
		params_struct = readConfig(configfile, numParams, params_keystart, params_keyend, params_buffer);

	//	MATCHING UP PARAMS SCALAR DATA
	// loop through each params_struct field and assign it to its respective output struct field
		for (i = 0; i < numParams; i++) {
				i_name  = params_struct[i].name;
				i_value = params_struct[i].value;
				if (strcmp(i_name, 			"disFlg") 			== 0) {
						params_scalar_struct.disFlg 			= i_value;
				} else if (strcmp(i_name, 	"wayStp") 			== 0) {
						params_scalar_struct.wayStp 			= i_value;
				} else if (strcmp(i_name, 	"engKinBegInx")		== 0) {
						params_scalar_struct.engKinBegInx 		= i_value;
				} else if (strcmp(i_name, 	"batEngStp")		== 0) {
						params_scalar_struct.batEngStp 			= i_value;
				} else if (strcmp(i_name, 	"batEngBeg")		== 0) {
						params_scalar_struct.batEngBeg 			= i_value;
				} else if (strcmp(i_name, 	"batPwrAux")		== 0) {
						params_scalar_struct.batPwrAux 			= i_value;
				} else if (strcmp(i_name, 	"psiBatEng")		== 0) {
						params_scalar_struct.psiBatEng 			= i_value;
				} else if (strcmp(i_name, 	"psiTim") 			== 0) {
						params_scalar_struct.psiTim 			= i_value;
				} else if (strcmp(i_name, 	"staChgPenCosVal")	== 0) {
						params_scalar_struct.staChgPenCosVal 	= i_value;
				} else if (strcmp(i_name, 	"wayInxBeg")		==0) {
						params_scalar_struct.wayInxBeg 			= i_value;
				} else if (strcmp(i_name, 	"wayInxEnd")		==0) {
						params_scalar_struct.wayInxEnd 			= i_value;
				} else if (strcmp(i_name, 	"staBeg") 			== 0) {
						params_scalar_struct.staBeg 			= i_value;
				}
		}		
		return params_scalar_struct;
}
