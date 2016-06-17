// mainScript.c
// created 15.June.2016 by Asgard Kaleb Marroquin
//
// step 1: include the readConfig_ctest.c function and get the vars
// into this environment and print
#include <stdio.h>
#include <stdlib.h>
#include "readConfig.h"
#include "findNumVars.h"

#define CONFIGFILE_DIR "mainConfig.txt"		// define mainConfig.txt file location

int main(void){
		int i;								// loop var
		
		char *configfile;					// define mainConfig.txt file location
		configfile = CONFIGFILE_DIR; 			
		
		// defining mainConfig.txt keywords
		char *params_keystart;
		char *params_keyend;
		char *tstdat_keystart;
		char *tstdat_keyend;
		char *fahrzg_keystart;
		char *fahrzg_keyend;
		
		params_keystart = "PARAMS_START";
		params_keyend 	= "PARAMS_END";
		tstdat_keystart = "TSTDAT_START";
		tstdat_keyend 	= "TSTDAT_END"; 
		fahrzg_keystart = "FAHRZEUG_START";
		fahrzg_keyend 	= "FAHRZEUG_END";
		
		// function call: find number of input parameters
		int numParams  	= findNumVars(configfile, params_keystart, params_keyend);
		int numTstdat	= findNumVars(configfile, tstdat_keystart, tstdat_keyend);
		int numFahrzg	= findNumVars(configfile, fahrzg_keystart, fahrzg_keyend);
		// quick test, making sure that correct numVars is calculated
		printf("numParams: %d\n", numParams);
		printf("numTstdat: %d\n", numTstdat);
		printf("numFahrzg: %d\n", numFahrzg);
		
		// define input_params struct - will populate w/ readConfig.c
		struct model_params *params_struct;
		struct model_params *tstdat_struct;
		struct model_params *fahrzg_struct;
		
		// function call: load in structure wiih all input parameters
		params_struct = readConfig(configfile, numParams, params_keystart, params_keyend);
		tstdat_struct = readConfig(configfile, numTstdat, tstdat_keystart, tstdat_keyend);
		fahrzg_struct = readConfig(configfile, numFahrzg, fahrzg_keystart, fahrzg_keyend);
		
		// test: output the structures stuff
		printf("param_struct:\n");
		for (i = 0; i < numParams; i++){
				printf("	%s: %4.4f\n", params_struct[i].name, params_struct[i].value);
		}
		
		printf("tstdat_struct:\n");
		for (i = 0; i < numTstdat; i++){
				printf("	%s: %4.4f\n", tstdat_struct[i].name, tstdat_struct[i].value);
		}
		
		printf("fahrzg_struct:\n");
		for (i = 0; i < numFahrzg; i++){
				printf("	%s: %4.4f\n", fahrzg_struct[i].name, fahrzg_struct[i].value);
		}
		
		// order in which to feed inputs to clc_DP_tmp.c
		// will do later - need to first bring in all the other inputs from more text files
		
		// free dynamically allocated structure
		free(params_struct);
		free(tstdat_struct);
		free(fahrzg_struct);

		// success!
		printf("no crashes :)\n");
		getchar();
		return 0;
}
