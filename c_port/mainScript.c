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
		
		int  numVars;						// number of inputs in mainConfig.txt#
		
		char *configfile;					// define mainConfig.txt file location
		configfile = CONFIGFILE_DIR; 			
		
		// function call: find number of input parameters
		numVars    = findNumVars(configfile);
		
		// quick test, making sure that correct numVars is calculated
		printf("numVars: %d\n", numVars);
		
		// define input_params struct - will populate w/ readConfig.c
		struct model_params *input_struct;
		
		// function call: load in structure wiih all input parameters
		input_struct = readConfig(configfile);
		
		// test: output the structures stuff
		for (i = 0; i < numVars; i++)
			printf("%s: %4.2f\n", input_struct[i].name, input_struct[i].value);

		// order in which to feed inputs to clc_DP_tmp.c
// will do later - need to first bring in all the other inputs from more text files


		
		// free dynamically allocated structure
		free(input_struct);

		// success!
		printf("no crashes :)\n");
		getchar();
		return 0;
}
