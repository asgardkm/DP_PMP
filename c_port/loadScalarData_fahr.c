// loadScalarData_fahr.c
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
#include "loadScalarData_fahr.h"
#include "readConfig.h"
#include "findNumVars.h"
#include "readRawText.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"

//#define CONFIGFILE_DIR "mainConfig.txt"		// define mainConfig.txt file location

struct2_T loadScalarData_fahr(char *mainConfigDir){
//int main(void){

		int i, m, n;						// loop vars
		double i_value;
		char *i_name;
		
		char *configfile = mainConfigDir;					// define mainConfig.txt file location
//		char *configfile = CONFIGFILE_DIR;					// define mainConfig.txt file location

		char *fahrzg_keystart;
		char *fahrzg_keyend;

		fahrzg_keystart = "FAHRZEUG_START";
		fahrzg_keyend 	= "FAHRZEUG_END";
		
		// function call: find number of input parameters

		int numFahrzg	= findNumVars(configfile, fahrzg_keystart, fahrzg_keyend);			
						
		// 22.06.2016 - exending buffer portion so that it populates a structure
	 	struct2_T fahrzg_scalar_struct;
	 	
		// define input_params struct - will populate w/ readConfig.c
		struct model_params *fahrzg_struct;
		
		// buffer for each struct data group - ensures that each struct have distinct pointer addresses from each other
		struct model_params fahrzg_buffer[numFahrzg];

		// function call: load in structure wiih all input parameters
		fahrzg_struct = readConfig(configfile, numFahrzg, fahrzg_keystart, fahrzg_keyend, fahrzg_buffer);
	
	//	MATCHING UP FAHRZEUG SCALAR DATA
		for (i = 0; i < numFahrzg; i++) {
				i_name  = fahrzg_struct[i].name;
				i_value = fahrzg_struct[i].value;
				if (strcmp(i_name, 			"vehVelMin") 	== 0) {
						fahrzg_scalar_struct.vehVelMin 		= i_value;
				} else if (strcmp(i_name, 	"vehVelMax")	== 0) {
						fahrzg_scalar_struct.vehVelMax 		= i_value;
				} else if (strcmp(i_name, 	"vehAccMax")	== 0) {
						fahrzg_scalar_struct.vehAccMax 		= i_value;
				} else if (strcmp(i_name, 	"vehAccMin")	== 0) {
						fahrzg_scalar_struct.vehAccMin 		= i_value;
				} else if (strcmp(i_name, 	"drgCof")		== 0) {
						fahrzg_scalar_struct.drgCof 		= i_value;
				} else if (strcmp(i_name, 	"vehMas")		== 0) {
						fahrzg_scalar_struct.vehMas 		= i_value;
				} else if (strcmp(i_name, 	"whlRosResCof")	== 0) {
						fahrzg_scalar_struct.whlRosResCof	= i_value;
				} else if (strcmp(i_name, 	"whlDrr") 		== 0) {
						fahrzg_scalar_struct.whlDrr 		= i_value;
				} else if (strcmp(i_name, 	"batRstChr")	== 0) {
						fahrzg_scalar_struct.batRstChr 		= i_value;
				} else if (strcmp(i_name, 	"batRstDch")	== 0) {
						fahrzg_scalar_struct.batRstDch 		= i_value;
				} else if (strcmp(i_name, 	"batEngMax")	== 0) {
						fahrzg_scalar_struct.batEngMax 		= i_value;
				} else if (strcmp(i_name, 	"batPwrMax") 	== 0) {
						fahrzg_scalar_struct.batPwrMax 		= i_value;
				} else if (strcmp(i_name, 	"batPwrMin") 	== 0) {
						fahrzg_scalar_struct.batPwrMin 		= i_value;
				} else if (strcmp(i_name, 	"geaEfy") 		== 0) {
						fahrzg_scalar_struct.geaEfy 		= i_value;
				} else if (strcmp(i_name, 	"fulDen") 		== 0) {
						fahrzg_scalar_struct.fulDen 		= i_value;
				} else if (strcmp(i_name, 	"fulLhv") 		== 0) {
						fahrzg_scalar_struct.fulLhv 		= i_value;
				}
		}	
		return fahrzg_scalar_struct;
}
