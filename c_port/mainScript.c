// mainScript.c
// created 15.June.2016 by Asgard Kaleb Marroquin
//
// step 1: include the readConfig_ctest.c function and get the vars
// into this environment and print
#include <stdio.h>
#include "readConfig.h"
#include "findNumVars.h"

#define CONFIGFILE_DIR "mainConfig.txt"			// define mainConfig.txt file location

int main(void){

		int  numVars;							// number of inputs in mainConfig.txt#
		char *configfile;
		
		configfile = CONFIGFILE_DIR; 			// define mainConfig.txt file location
		numVars    = findNumVars(configfile);
		
		printf("numVars: %d\n", numVars);
		
		// THIS ALSO WORKS BELOW! :)
//		int numVars;							// number of inputs in mainConfig.txt#
//		char configfile[] = "mainConfig.txt"; 	// define mainConfig.txt file location
//		numVars = findNumVars(&configfile[0]);
//		printf("numVars: %d\n", numVars);
		
		// define input_params struct - will populate w/ readConfig.c
		struct model_params input_params[numVars];
		
		input_params[numVars] = readConfig(configfile);
		printf("no crashes :)\n");
		getchar();
		return 0;
}
