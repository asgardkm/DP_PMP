// mainScript.c
// created 15.June.2016 by Asgard Kaleb Marroquin
//
// step 1: include the readConfig_ctest.c function and get the vars
// into this environment and print
#include <stdio.h>
#include <stdlib.h>
#include "readConfig.h"
#include "findNumVars.h"

#define CONFIGFILE_DIR "mainConfig.txt"			// define mainConfig.txt file location

int main(void){
		int i;	// loop var
		
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
		struct model_params *input_struct;
		
		input_struct = readConfig(configfile);
		
		// test: output the structures stuff
		for (i = 0; i < numVars; i++)
			printf("input_structure.%s: %4.2f\n", input_struct[i].name, input_struct[i].value);
		
		
		
		
		free(input_struct);

		printf("no crashes :)\n");
		getchar();
		return 0;
}
