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
//---------------------------------------------------------------------------
// NOTE: POINTER ARITHMETIC WITH 2D ARRAYS:
// to call the [m][n] value from array with dims dataArray[m_all][n_all] (or [m_all*n_all]):
//			*((int *)dataArray+m * n_all+n));
//	OR
// can also assign a pointer *dataPointer, so that
//			dataPointer = &dataArray[0][0];
// and therefore call with
//			*(dataPointer+m * n_all+n);
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "loadScalarData_test.h"
#include "readConfig.h"
#include "findNumVars.h"
#include "readRawText.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"

//#define CONFIGFILE_DIR "mainConfig.txt"		// define mainConfig.txt file location

struct1_T loadScalarData_test(char *mainConfigDir){
//int main(void){

		int i, m, n;						// loop vars
		double i_value;
		char *i_name;
		
		char *configfile = mainConfigDir;					// define mainConfig.txt file location
//		char *configfile = CONFIGFILE_DIR;					// define mainConfig.txt file location

		// defining mainConfig.txt keywords
		char *tstdat_keystart;
		char *tstdat_keyend;
		
		tstdat_keystart = "TSTDAT_START";
		tstdat_keyend 	= "TSTDAT_END"; 
		
		// function call: find number of input parameters
		int numTstdat	= findNumVars(configfile, tstdat_keystart, tstdat_keyend);
						
		// 22.06.2016 - exending buffer portion so that it populates a structure
		struct1_T tstdat_scalar_struct; 
	 			
		// define input_params struct - will populate w/ readConfig.c
		struct model_params *tstdat_struct;
		
		// buffer for each struct data group - ensures that each struct have distinct pointer addresses from each other
		struct model_params tstdat_buffer[numTstdat];

		// function call: load in structure wiih all input parameters
		tstdat_struct = readConfig(configfile, numTstdat, tstdat_keystart, tstdat_keyend, tstdat_buffer);

	// 	MATCHING UP TSTDAT SCALAR DATA
		for (i = 0; i < numTstdat; i++) {
				i_name  = tstdat_struct[i].name;
				i_value = tstdat_struct[i].value;
				if (strcmp(i_name, 			"staNum") 	== 0) {
						tstdat_scalar_struct.staNum 	= i_value;
//						printf("Found 'staNum' at %d (value: %4.2f)\n", i, i_value);
				} else if (strcmp(i_name, 	"wayNum") 	== 0) {
						tstdat_scalar_struct.wayNum 	= i_value;
//						printf("Found 'wayNum' at %d (value: %4.2f)\n", i, i_value);
				} else if (strcmp(i_name, 	"engKinNum")== 0) {
						tstdat_scalar_struct.engKinNum 	= i_value;
//						printf("Found 'engKinNum' at %d (value: %4.2f)\n", i, i_value);
				} else {
						printf("no string match for tstdat_scalar_struct[%d].\nCheck struct fields and/or input strings\n", i);
				}
		}
		return tstdat_scalar_struct;
}
