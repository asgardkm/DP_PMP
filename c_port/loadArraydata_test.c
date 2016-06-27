// loadArrayData.c

// first define them - sending them into a struct?
		// can this be made into a structure or something? - 21.06.2016
		// in a structre, make arrays of:
		//  - the pointer variable
		//  - variable buffer
		//  - string name of text folder value
		//	- row length of input value
		//	- col length of input value
		// and then rearrange similarly to how it was done with scalars?
		
		// output:
		//  - input structure from c code - and it's header 
		//		you want to return a pointer of this input structure once
		//		its been populated by the above pointer variable from buffer
		
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "loadArrayData_test.h"
#include "readConfig.h"

#define FZG_SIZE1 150
#define FZG_SIZE2 100
#define TRQ_COEF 3
#define BAT_COEF 2

//declare function for populating array structure 
double *populateArrayStruct_test(struct varStruct inputStruct, char *prefix);

struct3_T *loadArrayData_test(struct1_T tstdat_scalar_struct) {
//struct cbArrayStruct loadArrayData(struct1_T tstdat_scalar_struct) {

	// read in vectors!
		
		// loop counters
		int m, n;
		
		// STRING DIRECTORY DEFINITION
		// define raw_data dir and struct prefixes
		char *raw_data_dir 	= "raw_data";
		char tst_prefix[100];
		sprintf(tst_prefix, "%s/tstDat800", raw_data_dir);
		
		// define structs for output
		struct3_T *tst_array_struct;		
		
		// DEFINE TEST DATA ARRAY STRUCTURES
		// slpVec_wayInx
		struct varStruct slpVec_wayInx;
		slpVec_wayInx.string_name			= "slpVec_wayInx";
		slpVec_wayInx.row_num 				= (int)tstdat_scalar_struct.wayNum;
		slpVec_wayInx.col_num 				= 1;
		
		// engKinMat_engKinInx_wayInx
		struct varStruct engKinMat_engKinInx_wayInx;
		engKinMat_engKinInx_wayInx.string_name = "engKinMat_engKinInx_wayInx";
		engKinMat_engKinInx_wayInx.row_num 	= (int)tstdat_scalar_struct.engKinNum;
		engKinMat_engKinInx_wayInx.col_num 	= (int)tstdat_scalar_struct.wayNum;
		
		// engKinNumVec_wayInx
		struct varStruct engKinNumVec_wayInx;
		engKinNumVec_wayInx.string_name 	= "engKinNumVec_wayInx";
		engKinNumVec_wayInx.row_num 		= (int)tstdat_scalar_struct.wayNum;
		engKinNumVec_wayInx.col_num 		= 1;

		
		// POINTERS TO TEST ARRAY STRUCTURES	 
		double *slpVec_wayInx_ptr;
		double *engKinMat_engKinInx_wayInx_ptr;
		double *engKinNumVec_wayInx_ptr;

	// ================ time to load in vectors! ====================================================
		
	// tstDat800.slpVec_wayInx
		slpVec_wayInx_ptr = populateArrayStruct_test(slpVec_wayInx, tst_prefix);
		for (m = 0; m < slpVec_wayInx.row_num; m++) {
				for (n = 0; n < slpVec_wayInx.col_num; n++) {
						tst_array_struct->slpVec_wayInx[m * slpVec_wayInx.col_num + n]
							= *(slpVec_wayInx_ptr + m * slpVec_wayInx.col_num + n);
				}
		}
		slpVec_wayInx_ptr = NULL;
		
	// tstDat800.engKinMat_engKinInx_wayInx
		engKinMat_engKinInx_wayInx_ptr = populateArrayStruct_test(engKinMat_engKinInx_wayInx, tst_prefix);
		for (m = 0; m < engKinMat_engKinInx_wayInx.row_num; m++) {
				for (n = 0; n < engKinMat_engKinInx_wayInx.col_num; n++) {
						tst_array_struct->engKinMat_engKinInx_wayInx[m * engKinMat_engKinInx_wayInx.col_num + n]
							= *(engKinMat_engKinInx_wayInx_ptr + m * engKinMat_engKinInx_wayInx.col_num + n);
				}
		}
		engKinMat_engKinInx_wayInx_ptr = NULL;
	
	// tstDat800.engKinNumVec_wayInx
		engKinNumVec_wayInx_ptr = populateArrayStruct_test(engKinNumVec_wayInx, tst_prefix);
		for (m = 0; m < engKinNumVec_wayInx.row_num; m++) {
				for (n = 0; n < engKinNumVec_wayInx.col_num; n++) {
						tst_array_struct->engKinNumVec_wayInx[m * engKinNumVec_wayInx.col_num + n]
							= *(engKinNumVec_wayInx_ptr + m * engKinNumVec_wayInx.col_num + n);
				}
		}
		engKinNumVec_wayInx_ptr = NULL;	
		
		return tst_array_struct;
}

// declare function here!!	
double *populateArrayStruct_test(struct varStruct inputStruct, char *prefix){
		int product = inputStruct.row_num * inputStruct.col_num;
		double *malloc_test = malloc(sizeof *malloc_test * product);
		return (double *)readRawText(prefix, inputStruct.string_name, inputStruct.col_num, malloc_test);
}
