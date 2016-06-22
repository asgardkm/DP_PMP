// mainScript.c
// created 15.June.2016 by Asgard Kaleb Marroquin
//
// step 1: include the readConfig_ctest.c function and get the vars
// into this environment and print - Done 20.06.2016!
// step 2: load in all the vector and matrix data from matlab b/c the loadin
// functions from matlab cannot be ported directly into c w/ matlab coder
// step 3: organize all the inputs as structures (respective structures?) _ necessary?
// step 4: feed inputs into generated DP_PMP algorithm code and see what happens

//---------------------------------------------------------------------------
// NOTE: POINTER ARITHMETIC WITH 2D ARRAYS:
// to call the [m][n] value from array with dims dataArray[m_all][n_all]:
//			*((int *)dataArray+m * n_all+n));
//	OR
// can also assign a pointer *dataPointer, so that
//			dataPointer = &dataArray[0][0];
// and therefore call with
//			*(dataPointer+m * n_all+n);
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "readConfig.h"
#include "findNumVars.h"
#include "readRawText.h"
#include "loadArrayData.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"

#define CONFIGFILE_DIR "mainConfig.txt"		// define mainConfig.txt file location

int main(void){
		int i, m, n;								// loop vars
		
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
		
		// buffer for each struct data group - ensures that each struct have distinct pointer addresses from each other
		struct model_params params_buffer[numParams];
		struct model_params tstdat_buffer[numTstdat];
		struct model_params fahrzg_buffer[numFahrzg];
				
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// function call: load in structure wiih all input parameters
		params_struct = readConfig(configfile, numParams, params_keystart, params_keyend, params_buffer);
		tstdat_struct = readConfig(configfile, numTstdat, tstdat_keystart, tstdat_keyend, tstdat_buffer);
		fahrzg_struct = readConfig(configfile, numFahrzg, fahrzg_keystart, fahrzg_keyend, fahrzg_buffer);
		
		// test: output the structures stuff
		printf("param_struct:\n");
		for (i = 0; i < numParams; i++){
				printf("	%s: %4.4f\n", params_struct[i].name, params_struct[i].value);
		}
		
		printf("tstdat_struct:\n");
		for (i = 0; i < numTstdat; i++){
				printf("	%s: %4.4f\n", tstdat_struct[i].name, tstdat_struct[i].value);
		}
//		
		printf("fahrzg_struct:\n");
		for (i = 0; i < numFahrzg; i++){
				printf("	%s: %4.4f\n", fahrzg_struct[i].name, fahrzg_struct[i].value);
		}
				
		// 22.06.2016 - exending buffer portion so that it populates a structure
		struct0_T params_scalar_struct;
//		struct0_T *params_scalar_pointer;
		struct1_T tstdat_scalar_struct; 
//		struct1_T *tstdat_scalar_pointer;
	 	struct2_T fahrzg_scalar_struct;
		
		float i_value;
		char *i_name;
	//	MATCHING UP PARAMS SCALAR DATA
		for (i = 0; i < numParams; i++){
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

	// 	MATCHING UP TSTDAT SCALAR DATA
		for (i = 0; i < numTstdat; i++){
				i_name  = tstdat_struct[i].name;
				i_value = tstdat_struct[i].value;
				if (strcmp(i_name, 			"staNum") 	== 0) {
						tstdat_scalar_struct.staNum 	= i_value;
				} else if (strcmp(i_name, 	"wayNum") 	== 0) {
						tstdat_scalar_struct.wayNum 	= i_value;
				} else if (strcmp(i_name, 	"engKinNum")== 0) {
						tstdat_scalar_struct.engKinNum 	= i_value;
				} else {
						printf("no string match for tstdat_scalar_struct[%d].\nCheck struct fields and/or input strings\n", i);
				}
		}		

	//	MATCHING UP FAHRZEUG SCALAR DATA
		for (i = 0; i < numFahrzg; i++){
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


		// first define them - sending them into a struct?
		// can this be made into a structure or something? - 21.06.2016
		// in a structre, make arrays of:
		//  - the pointer variable
		//  - variable buffer
		//  - string name of text folder value
		//	- row length of input value
		//	- col length of input value
		//  - input structure from c code - and it's header
//		struct struct3_T *tst_array_struct;
//		struct4_T fzg_array_struct;
//		double *emoPwr_emoSpd_emoTrq;
//		double emoPwr_emoSpd_emoTrq_buffer[150][100];
//		double*iceTrqMaxCof;
//		double iceTrqMaxCof_buffer[1][3];

		loadArrayData(tstdat_scalar_struct);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
//		// order in which to feed inputs to clc_DP_tmp.c
//		// will do later - need to first bring in all the other inputs from more text files
		
		// read in vectors!
		// define raw_data dor
//		char raw_data_dir[] = "raw_data";
//		// define struct prefix
//		char fzg_prefix[] = "FZG";
//		
//		// time to load in vectors!
//		// FZG.iceTrqMaxCof.txt(1x3)
//		
////		iceTrqMaxCof = readRawText(raw_data_dir, fzg_prefix, "iceTrqMaxCof",  1, 3, iceTrqMaxCof_buffer);
//		iceTrqMaxCof = readRawText(raw_data_dir, fzg_prefix, "iceTrqMaxCof",  1, 3, iceTrqMaxCof_buffer);
////		iceTrqMaxCof = &fzg_array_struct.iceTrqMaxCof[0];
//
//		for (m = 0; m < 1; m++){
//			for (n = 0; n < 3; n++){
//				printf(" *(iceTrqMaxCof + (%d*3) + %d): %4.3f\n", m, n, *(iceTrqMaxCof+m * 3+n));
//				fzg_array_struct.iceTrqMaxCof[m*3+n] = *(iceTrqMaxCof+m * 3+n);
//				printf("fzg_array_struct.iceTrqMaxCof[%d]: %4.3f\n\n", m*3+n, fzg_array_struct.iceTrqMaxCof[m*3+n]);
//			}
//		}
//		//FZG.emoPwr_emoSpd_emoTrq.txt() (150x100)
//		emoPwr_emoSpd_emoTrq = &emoPwr_emoSpd_emoTrq_buffer[0][0];
//		emoPwr_emoSpd_emoTrq = readRawText(raw_data_dir, fzg_prefix, "emoPwr_emoSpd_emoTrq", 150, 100, emoPwr_emoSpd_emoTrq_buffer);
//		
//		for (m = 0; m < 150; m++){
//				for (n = 0; n < 100; n++){
//						printf("emoPwr_emoSpd_emoTrq[%d][%d]: %4.2f\n", m, n, *(emoPwr_emoSpd_emoTrq+m * 100 + n));
//				}
//		}
		

		// success!
		printf("no crashes :)\n");
		getchar();
		return 0;
}
