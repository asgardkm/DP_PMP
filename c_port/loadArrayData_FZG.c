// loadArrayData_fzg.c

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
#include "loadArrayData_fzg.h"
#include "readConfig.h"

#define FZG_SIZE1 150
#define FZG_SIZE2 100
#define TRQ_COEF 3
#define BAT_COEF 2


//declare function for populating array structure 
double *populateArrayStruct(struct varStruct inputStruct, char *prefix);

//void loadArrayData(struct1_T tstdat_scalar_struct) {
//struct cbArrayStruct loadArrayData(struct1_T tstdat_scalar_struct) {

struct4_T *loadArrayData_fzg(struct1_T tstdat_scalar_struct) {
	// read in vectors!
		
		// loop counters
		int m, n;
		
		// STRING DIRECTORY DEFINITION
		// define raw_data dir and struct prefixes
		char *raw_data_dir 	= "raw_data";
		char fzg_prefix[200];
		sprintf(fzg_prefix, "%s/FZG", raw_data_dir);
		
		// define structs for output that will go into cbArray (NECESSARY???)
		struct4_T *fzg_array_struct;
		
//		// DEFINE FZG ARRAY STRUCTURES
		// batOcvCof_batEng
		struct varStruct batOcvCof_batEng;
		batOcvCof_batEng.string_name 		= "batOcvCof_batEng";
		batOcvCof_batEng.row_num 			= 1;
		batOcvCof_batEng.col_num 			= BAT_COEF;
		
		// geaRat
		struct varStruct geaRat;
		geaRat.string_name 					= "geaRat";
		geaRat.row_num 						= 1;
		geaRat.col_num 						= (int)tstdat_scalar_struct.staNum;
		
		// iceSpdMgd
		struct varStruct iceSpdMgd;
		iceSpdMgd.string_name 				= "iceSpdMgd";
		iceSpdMgd.row_num 					= 150;
		iceSpdMgd.col_num 					= 100;
		
		// iceTrqMgd
		struct varStruct iceTrqMgd;
		iceTrqMgd.string_name 				= "iceTrqMgd";
		iceTrqMgd.row_num 					= FZG_SIZE1;
		iceTrqMgd.col_num 					= FZG_SIZE2;
		
		// iceFulPwr_iceSpd_iceTrq
		struct varStruct iceFulPwr_iceSpd_iceTrq;
		iceFulPwr_iceSpd_iceTrq.string_name	= "iceFulPwr_iceSpd_iceTrq";
		iceFulPwr_iceSpd_iceTrq.row_num 	= FZG_SIZE1;
		iceFulPwr_iceSpd_iceTrq.col_num 	= FZG_SIZE2;
				
		// iceTrqMaxCof
		struct varStruct iceTrqMaxCof;
		iceTrqMaxCof.string_name 			= "iceTrqMaxCof";
		iceTrqMaxCof.row_num		 		= 1;
		iceTrqMaxCof.col_num	 			= TRQ_COEF;
		
		// iceTrqMinCof
		struct varStruct iceTrqMinCof;
		iceTrqMinCof.string_name 			= "iceTrqMinCof";
		iceTrqMinCof.row_num 				= 1;
		iceTrqMinCof.col_num 				= TRQ_COEF;
		
		// emoSpdMgd
		struct varStruct emoSpdMgd;
		emoSpdMgd.string_name 				= "emoSpdMgd";
		emoSpdMgd.row_num					= FZG_SIZE1;
		emoSpdMgd.col_num 					= FZG_SIZE2;
		
		// emoTrqMgd
		struct varStruct emoTrqMgd;
		emoTrqMgd.string_name 				= "emoTrqMgd";
		emoTrqMgd.row_num 					= FZG_SIZE1;
		emoTrqMgd.col_num 					= FZG_SIZE2;

		// emoPwr_emoSpd_emoTrq
		struct varStruct emoPwr_emoSpd_emoTrq;
		emoPwr_emoSpd_emoTrq.string_name 	= "emoPwr_emoSpd_emoTrq";
		emoPwr_emoSpd_emoTrq.row_num 		= FZG_SIZE1;
		emoPwr_emoSpd_emoTrq.col_num 		= FZG_SIZE2;
		
		// emoTrqMin_emoSpd
		struct varStruct emoTrqMin_emoSpd;
		emoTrqMin_emoSpd.string_name 		= "emoTrqMin_emoSpd";
		emoTrqMin_emoSpd.row_num		 	= FZG_SIZE2;
		emoTrqMin_emoSpd.col_num 			= 1;
		
		// emoTrqMax_emoSpd
		struct varStruct emoTrqMax_emoSpd;
		emoTrqMax_emoSpd.string_name 		= "emoTrqMax_emoSpd";
		emoTrqMax_emoSpd.row_num 			= FZG_SIZE2;
		emoTrqMax_emoSpd.col_num 			= 1;
		
		// emoPwrMgd
		struct varStruct emoPwrMgd;
		emoPwrMgd.string_name 				= "emoPwrMgd";
		emoPwrMgd.row_num 					= FZG_SIZE1;
		emoPwrMgd.col_num 					= FZG_SIZE2;
		
		// emoTrq_emoSpd_emoPwr
		struct varStruct emoTrq_emoSpd_emoPwr;
		emoTrq_emoSpd_emoPwr.string_name 	= "emoTrq_emoSpd_emoPwr";
		emoTrq_emoSpd_emoPwr.row_num 		= FZG_SIZE1;
		emoTrq_emoSpd_emoPwr.col_num 		= FZG_SIZE2;
		
		// emoPwrMax_emoSpd
		struct varStruct emoPwrMax_emoSpd;
		emoPwrMax_emoSpd.string_name 		= "emoPwrMax_emoSpd";
		emoPwrMax_emoSpd.row_num 			= FZG_SIZE2;
		emoPwrMax_emoSpd.col_num 			= 1;
		
		// emoPwrMin_emoSpd
		struct varStruct emoPwrMin_emoSpd;
		emoPwrMin_emoSpd.string_name 		= "emoPwrMin_emoSpd";
		emoPwrMin_emoSpd.row_num 			= FZG_SIZE2;
		emoPwrMin_emoSpd.col_num 			= 1;
		
		static double *batOcvCof_batEng_ptr;
		static double *geaRat_ptr;
		static double *iceSpdMgd_ptr;
		static double *iceTrqMgd_ptr;
		static double *iceFulPwr_iceSpd_iceTrq_ptr;
		static double *iceTrqMaxCof_ptr;
		static double *iceTrqMinCof_ptr;
		static double *emoSpdMgd_ptr;
		static double *emoTrqMgd_ptr;
		static double *emoPwr_emoSpd_emoTrq_ptr;
		static double *emoTrqMin_emoSpd_ptr;
		static double *emoTrqMax_emoSpd_ptr;
		static double *emoPwrMgd_ptr;
		static double *emoTrq_emoSpd_emoPwr_ptr;
		static double *emoPwrMax_emoSpd_ptr;
		static double *emoPwrMin_emoSpd_ptr;

	// ================ time to load in vectors! ====================================================

// POINTERS TO FAHRZEUG ARRAY STRUCTURES
//	 FZG.batOcvCof_batEng(1x2)
		batOcvCof_batEng_ptr = populateArrayStruct(batOcvCof_batEng, fzg_prefix);
		for (m = 0; m < batOcvCof_batEng.row_num; m++) {
				for (n = 0; n < batOcvCof_batEng.col_num; n++) {
						fzg_array_struct->batOcvCof_batEng[m*batOcvCof_batEng.col_num+n] 
							= *(batOcvCof_batEng_ptr+m*batOcvCof_batEng.col_num+n);
				}
		}
//		batOcvCof_batEng_ptr = NULL;	
				
//	 FZG.geaRat(1xtstdat_scalar_struct.staNum)
		geaRat_ptr = populateArrayStruct(geaRat, fzg_prefix);
		for (m = 0; m < geaRat.row_num; m++) {
				for (n = 0; n < geaRat.col_num; n++) {
						fzg_array_struct->geaRat[m+geaRat.col_num+n] 
							= *(geaRat_ptr+m*geaRat.col_num+n);
				}
		}
//		geaRat_ptr = NULL;


	// FZG.iceSpdMgd
		iceSpdMgd_ptr = populateArrayStruct(iceSpdMgd, fzg_prefix);
		for (m = 0; m < iceSpdMgd.row_num; m++) {
				for (n = 0; n < iceSpdMgd.col_num; n++) {
						fzg_array_struct->iceSpdMgd[m * iceSpdMgd.col_num + n] 		
							= *(iceSpdMgd_ptr + m * iceSpdMgd.col_num + n);
				}
		}
//		iceSpdMgd_ptr = NULL;

//	 FZG.iceTrqMgd	
		iceTrqMgd_ptr = populateArrayStruct(iceTrqMgd, fzg_prefix);	
		for (m = 0; m < iceTrqMgd.row_num; m++) {
				for (n = 0; n < iceTrqMgd.col_num; n++) {
						fzg_array_struct->iceTrqMgd[m * iceTrqMgd.col_num + n] 
							= *(iceTrqMgd_ptr + m * iceTrqMgd.col_num + n);
				}
		}	
//		iceTrqMgd_ptr = NULL;

	// FZG.iceFulPwr_iceSpd_iceTrq
		iceFulPwr_iceSpd_iceTrq_ptr = populateArrayStruct(iceFulPwr_iceSpd_iceTrq, fzg_prefix);	
		for (m = 0; m < iceFulPwr_iceSpd_iceTrq.row_num; m++) {
				for (n = 0; n < iceFulPwr_iceSpd_iceTrq.col_num; n++) {
						fzg_array_struct->iceFulPwr_iceSpd_iceTrq[m * iceFulPwr_iceSpd_iceTrq.col_num + n] 
							= *(iceFulPwr_iceSpd_iceTrq_ptr + m * iceFulPwr_iceSpd_iceTrq.col_num + n);
				}
		}
//		iceFulPwr_iceSpd_iceTrq_ptr = NULL;
		
		
	// FZG.iceTrqMaxCof.txt(1x3)
		iceTrqMaxCof_ptr = populateArrayStruct(iceTrqMaxCof, fzg_prefix);
		for (m = 0; m < iceTrqMaxCof.row_num; m++) {
				for (n = 0; n < iceTrqMaxCof.col_num; n++) {
						fzg_array_struct->iceTrqMaxCof[m * iceTrqMaxCof.col_num + n] 
							= *(iceTrqMaxCof_ptr + m * iceTrqMaxCof.col_num + n);
				}
		}			
//		iceTrqMaxCof_ptr = NULL;	
	
		
	// FZG.iceTrqMinCof.txt(1x3)
		iceTrqMinCof_ptr = populateArrayStruct(iceTrqMinCof, fzg_prefix);	
		for (m = 0; m < iceTrqMinCof.row_num; m++) {
				for (n = 0; n < iceTrqMinCof.col_num; n++) {
						fzg_array_struct->iceTrqMinCof[m * iceTrqMinCof.col_num + n] 
							= *(iceTrqMinCof_ptr + m * iceTrqMinCof.col_num + n);
				}
		}				
//		iceTrqMinCof_ptr = NULL;
			
		
	// FZG.emoSpdMgd.txt
		emoSpdMgd_ptr = populateArrayStruct(emoSpdMgd, fzg_prefix);
		for (m = 0; m < iceTrqMaxCof.row_num; m++) {
				for (n = 0; n < iceTrqMaxCof.col_num; n++) {
						fzg_array_struct->emoSpdMgd[m * emoSpdMgd.col_num + n] 
							= *(emoSpdMgd_ptr + m * emoSpdMgd.col_num + n);
				}
		}			
//		emoSpdMgd_ptr = NULL;	


	// FZG.emoTrqMgd
		emoTrqMgd_ptr = populateArrayStruct(emoTrqMgd, fzg_prefix);
		for (m = 0; m < emoTrqMgd.row_num; m++) {
				for (n = 0; n < emoTrqMgd.col_num; n++) {
						fzg_array_struct->emoTrqMgd[m * emoTrqMgd.col_num + n]
							= *(emoTrqMgd_ptr + m * emoTrqMgd.col_num + n);
				}
		}
//		emoTrqMgd_ptr = NULL;
		
		
	// FZG.emoPwr_emoSpd_emoTrq
		emoPwr_emoSpd_emoTrq_ptr = populateArrayStruct(emoPwr_emoSpd_emoTrq, fzg_prefix);
		for (m = 0; m < emoPwr_emoSpd_emoTrq.row_num; m++) {
				for (n = 0; n < emoPwr_emoSpd_emoTrq.col_num; n++) {
						fzg_array_struct->emoPwr_emoSpd_emoTrq[m * emoPwr_emoSpd_emoTrq.col_num + n]
							= *(emoPwr_emoSpd_emoTrq_ptr + m * emoPwr_emoSpd_emoTrq.col_num + n);
				}
		}
//		emoPwr_emoSpd_emoTrq_ptr = NULL;
										
	// FZG.emoTrqMin_emoSpd
		emoTrqMin_emoSpd_ptr = populateArrayStruct(emoTrqMin_emoSpd, fzg_prefix);
		for (m = 0; m < emoTrqMin_emoSpd.row_num; m++) {
				for (n = 0; n < emoTrqMin_emoSpd.col_num; n++) {
						fzg_array_struct->emoTrqMin_emoSpd[m * emoTrqMin_emoSpd.col_num + n]
							= *(emoTrqMin_emoSpd_ptr + m * emoTrqMin_emoSpd.col_num + n);
				}
		}
//		emoTrqMin_emoSpd_ptr = NULL;

			
	// FZG.emoTrqMax_emoSpd
		emoTrqMax_emoSpd_ptr = populateArrayStruct(emoTrqMax_emoSpd, fzg_prefix);
		for (m = 0; m < emoTrqMax_emoSpd.row_num; m++) {
				for (n = 0; n < emoTrqMax_emoSpd.col_num; n++) {
						fzg_array_struct->emoTrqMax_emoSpd[m * emoTrqMax_emoSpd.col_num + n]
							= *(emoTrqMax_emoSpd_ptr + m * emoTrqMax_emoSpd.col_num + n);
				}
		}
//		emoTrqMax_emoSpd_ptr = NULL;
		
		
	// FZG.emoPwrMgd
		emoPwrMgd_ptr  = populateArrayStruct(emoPwrMgd, fzg_prefix);
		for (m = 0; m < emoPwrMgd.row_num; m++) {
				for (n = 0; n < emoPwrMgd.col_num; n++) {
						fzg_array_struct->emoPwrMgd[m * emoPwrMgd.col_num + n]
							=  *(emoPwrMgd_ptr + m * emoPwrMgd.col_num + n);
				}
		}
//		emoPwrMgd_ptr = NULL;
	
	
	// emoTrq_emoSpd_emoPwr
		emoTrq_emoSpd_emoPwr_ptr = populateArrayStruct(emoTrq_emoSpd_emoPwr, fzg_prefix);
		for (m = 0; m < emoTrq_emoSpd_emoPwr.row_num; m++) {
				for (n = 0; n < emoTrq_emoSpd_emoPwr.col_num; n++) {
						fzg_array_struct->emoTrq_emoSpd_emoPwr[m * emoTrq_emoSpd_emoPwr.col_num + n]
							= *(emoTrq_emoSpd_emoPwr_ptr + m * emoTrq_emoSpd_emoPwr.col_num + n);
				}
		}	
//		emoTrq_emoSpd_emoPwr_ptr = NULL;
			
				
	// emoPwrMax_emoSpd
		emoPwrMax_emoSpd_ptr = populateArrayStruct(emoPwrMax_emoSpd, fzg_prefix);
		for (m = 0; m < emoPwrMax_emoSpd.row_num; m++) {
				for (n = 0; n < emoPwrMax_emoSpd.col_num; n++) {
						fzg_array_struct->emoPwrMax_emoSpd[m * emoPwrMax_emoSpd.col_num + n]
							= *(emoPwrMax_emoSpd_ptr + m * emoPwrMax_emoSpd.col_num + n);
				}
		}												
//		emoPwrMax_emoSpd_ptr = NULL;	

		return fzg_array_struct;
}
// declare function here!!	
double *populateArrayStruct(struct varStruct inputStruct, char *prefix) {
//		printf("inputStruct.row_num: %d\n", inputStruct.row_num);
//		printf("inputStruct.col_num: %d\n", inputStruct.col_num);
		int product = inputStruct.row_num * inputStruct.col_num;
//		printf("product: %d\n", product);
//		printf("product2: %d\n", inputStruct.row_num * inputStruct.col_num);
//		double buffer_size [7776];
		double *malloc_test = malloc(sizeof *malloc_test * product);
//		printf("sizeof malloc_test: %d\n", sizeof(malloc_test));
//		double buffer_size[inputStruct.row_num * inputStruct.col_num];
//		double *buffer = &buffer_size[0];
//		return buffer;
		return (double *)readRawText(prefix, inputStruct.string_name, inputStruct.col_num, malloc_test);
}
