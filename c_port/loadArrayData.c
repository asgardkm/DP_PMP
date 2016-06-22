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
		
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "loadArrayData.h"
#include "readConfig.h"

//struct cbArray *loadArrayData(struct1_T tstdat_scalar_pointer){
void *loadArrayData(struct1_T tstdat_scalar_struct){
	
		int m, n;
		printf("test: tstdat_scalar_struct.staNum\n", tstdat_scalar_struct.staNum);
		
		// define structures for each array#s information
		struct varStruct iceTrqMaxCof;
		iceTrqMaxCof.string_name = "iceTrqMaxCof";
		iceTrqMaxCof.row_num	 = 1;
		iceTrqMaxCof.col_num	 = 3;
		
		// define structs for output that will go into cbArray (NECESSARY???)
		struct3_T tst_array_struct;		
		struct4_T fzg_array_struct;
		
		double *emoPwr_emoSpd_emoTrq_ptr;
		double emoPwr_emoSpd_emoTrq_buffer[150][100];
		double **iceTrqMaxCof_ptr;
		double iceTrqMaxCof_buffer[1][3];
		iceTrqMaxCof_ptr = &iceTrqMaxCof_buffer[0][0];

//		// order in which to feed inputs to clc_DP_tmp.c ??
		
		// read in vectors!
		// define raw_data dor
		char *raw_data_dir 	= "raw_data";
		// define struct prefixes
		char *fzg_prefix	= "FZG";
		char *tst_prefix	= "tstDat800";
		
		// time to load in vectors!
		// FZG.iceTrqMaxCof.txt(1x3)
		iceTrqMaxCof_ptr = readRawText(raw_data_dir, fzg_prefix, iceTrqMaxCof.string_name,  
										iceTrqMaxCof.row_num, iceTrqMaxCof.col_num, iceTrqMaxCof.buffer);
//iceTrqMaxCof_buffer
//		for (m = 0; m < 1; m++){
//			for (n = 0; n < 3; n++){
//				printf(" *(iceTrqMaxCof + (%d*3) + %d): %4.3f\n", m, n, *(iceTrqMaxCof_ptr+m * 3+n));
//				fzg_array_struct.iceTrqMaxCof[m*3+n] = *(iceTrqMaxCof_ptr+m * 3+n);
//				printf("fzg_array_struct.iceTrqMaxCof[%d]: %4.3f\n\n", m*3+n, fzg_array_struct.iceTrqMaxCof[m*3+n]);
//			}
//		}
//		FZG.emoPwr_emoSpd_emoTrq.txt() (150x100)
//		emoPwr_emoSpd_emoTrq = &emoPwr_emoSpd_emoTrq_buffer[0][0];
//		emoPwr_emoSpd_emoTrq_ptr = readRawText(raw_data_dir, fzg_prefix, "emoPwr_emoSpd_emoTrq", 150, 100, emoPwr_emoSpd_emoTrq_buffer);
		
//		return 0;
}	
