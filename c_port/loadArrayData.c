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
#include "loadArrayData.h"
#include "readConfig.h"

#define FZG_SIZE1 150
#define FZG_SIZE2 100
#define TRQ_COEF 3
#define BAT_COEF 2

//declare function for populating array structure 
double *populateArrayStruct(struct varStruct inputStruct, char *prefix);
double *emalloc(size_t amt);

void loadArrayData(struct1_T tstdat_scalar_struct){
	// read in vectors!
		
		// loop counters
		int m, n;
		
		// STRING DIRECTORY DEFINITION
		// define raw_data dir and struct prefixes
		char *raw_data_dir 	= "raw_data";
		char fzg_prefix[100];
		char tst_prefix[100];
		sprintf(fzg_prefix, "%s/FZG", raw_data_dir);
		sprintf(tst_prefix, "%s/tstDat800", raw_data_dir);

		// define structs for output that will go into cbArray (NECESSARY???)
		struct3_T tst_array_struct;		
		struct4_T fzg_array_struct;

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
		iceSpdMgd.row_num 					= FZG_SIZE1;
		iceSpdMgd.col_num 					= FZG_SIZE2;
		
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
		
//		// POINTERS TO TEST ARRAY STRUCTURES	 
		double *slpVec_wayInx_ptr;
		double *engKinMat_engKinInx_wayInx_ptr;
		double *engKinNumVec_wayInx_ptr;
		
		
		double *batOcvCof_batEng_ptr;
		double *geaRat_ptr;
		double *iceSpdMgd_ptr;
		double *iceTrqMgd_ptr;
		double *iceFulPwr_iceSpd_iceTrq_ptr;
		double *iceTrqMaxCof_ptr;
		double *iceTrqMinCof_ptr;
		double *emoSpdMgd_ptr;
		double *emoTrqMgd_ptr;
		double *emoPwr_emoSpd_emoTrq_ptr;
		double *emoTrqMin_emoSpd_ptr;
		double *emoTrqMax_emoSpd_ptr;
		double *emoPwrMgd_ptr;
		double *emoTrq_emoSpd_emoPwr_ptr;
		double *emoPwrMax_emoSpd_ptr;
		double *emoPwrMin_emoSpd_ptr;

	// ================ time to load in vectors! ====================================================
		
	// tstDat800.slpVec_wayInx
		slpVec_wayInx_ptr = populateArrayStruct(slpVec_wayInx, tst_prefix);
		for (m = 0; m < slpVec_wayInx.row_num; m++) {
				for (n = 0; n < slpVec_wayInx.col_num; n++) {
						tst_array_struct.slpVec_wayInx[m * slpVec_wayInx.col_num + n]
							= *(slpVec_wayInx_ptr + m * slpVec_wayInx.col_num + n);
				}
		}
		slpVec_wayInx_ptr = NULL;
		
	// tstDat800.engKinMat_engKinInx_wayInx
		engKinMat_engKinInx_wayInx_ptr = populateArrayStruct(engKinMat_engKinInx_wayInx, tst_prefix);
		for (m = 0; m < engKinMat_engKinInx_wayInx.row_num; m++) {
				for (n = 0; n < engKinMat_engKinInx_wayInx.col_num; n++) {
						tst_array_struct.engKinMat_engKinInx_wayInx[m * engKinMat_engKinInx_wayInx.col_num + n]
							= *(engKinMat_engKinInx_wayInx_ptr + m * engKinMat_engKinInx_wayInx.col_num + n);
				}
		}
		engKinMat_engKinInx_wayInx_ptr = NULL;
	
	// tstDat800.engKinNumVec_wayInx
		engKinNumVec_wayInx_ptr = populateArrayStruct(engKinNumVec_wayInx, tst_prefix);
		for (m = 0; m < engKinNumVec_wayInx.row_num; m++) {
				for (n = 0; n < engKinNumVec_wayInx.col_num; n++) {
						tst_array_struct.engKinNumVec_wayInx[m * engKinNumVec_wayInx.col_num + n]
							= *(engKinNumVec_wayInx_ptr + m * engKinNumVec_wayInx.col_num + n);
				}
		}
		engKinNumVec_wayInx_ptr = NULL;
		

/////////////////////////////////////////////////////////////////////
// POINTERS TO FAHRZEUG ARRAY STRUCTURES
	// FZG.batOcvCof_batEng(1x2)
		batOcvCof_batEng_ptr = populateArrayStruct(batOcvCof_batEng, fzg_prefix);
		for (m = 0; m < batOcvCof_batEng.row_num; m++) {
				for (n = 0; n < batOcvCof_batEng.col_num; n++) {
						fzg_array_struct.batOcvCof_batEng[m*batOcvCof_batEng.col_num+n] 
							= *(batOcvCof_batEng_ptr+m*batOcvCof_batEng.col_num+n);
				}
		}
		batOcvCof_batEng_ptr = NULL;	
				
	// FZG.geaRat(1xtstdat_scalar_struct.staNum)
		geaRat_ptr = populateArrayStruct(geaRat, fzg_prefix);
		for (m = 0; m < geaRat.row_num; m++) {
				for (n = 0; n < geaRat.col_num; n++) {
						fzg_array_struct.geaRat[m+geaRat.col_num+n] 
							= *(geaRat_ptr+m*geaRat.col_num+n);
				}
		}
		geaRat_ptr = NULL;
		
	// FZG.iceSpdMgd
		iceSpdMgd_ptr = populateArrayStruct(iceSpdMgd, fzg_prefix);
		for (m = 0; m < iceSpdMgd.row_num; m++) {
				for (n = 0; n < iceSpdMgd.col_num; n++) {
						fzg_array_struct.iceSpdMgd[m * iceSpdMgd.col_num + n] 		
							= *(iceSpdMgd_ptr + m * iceSpdMgd.col_num + n);
				}
		}
		iceSpdMgd_ptr = NULL;

	// FZG.iceTrqMgd	
		iceTrqMgd_ptr = populateArrayStruct(iceTrqMgd, fzg_prefix);	
		for (m = 0; m < iceTrqMgd.row_num; m++) {
				for (n = 0; n < iceTrqMgd.col_num; n++) {
						fzg_array_struct.iceTrqMgd[m * iceTrqMgd.col_num + n] 
							= *(iceTrqMgd_ptr + m * iceTrqMgd.col_num + n);
				}
		}	
		iceTrqMgd_ptr = NULL;

	// FZG.iceFulPwr_iceSpd_iceTrq
		iceFulPwr_iceSpd_iceTrq_ptr = populateArrayStruct(iceFulPwr_iceSpd_iceTrq, fzg_prefix);	
		for (m = 0; m < iceFulPwr_iceSpd_iceTrq.row_num; m++) {
				for (n = 0; n < iceFulPwr_iceSpd_iceTrq.col_num; n++) {
						fzg_array_struct.iceFulPwr_iceSpd_iceTrq[m * iceFulPwr_iceSpd_iceTrq.col_num + n] 
							= *(iceFulPwr_iceSpd_iceTrq_ptr + m * iceFulPwr_iceSpd_iceTrq.col_num + n);
				}
		}
		iceFulPwr_iceSpd_iceTrq_ptr = NULL;
		
		
	// FZG.iceTrqMaxCof.txt(1x3)
		iceTrqMaxCof_ptr = populateArrayStruct(iceTrqMaxCof, fzg_prefix);
		for (m = 0; m < iceTrqMaxCof.row_num; m++) {
				for (n = 0; n < iceTrqMaxCof.col_num; n++) {
						fzg_array_struct.iceTrqMaxCof[m * iceTrqMaxCof.col_num + n] 
							= *(iceTrqMaxCof_ptr + m * iceTrqMaxCof.col_num + n);
				}
		}			
		iceTrqMaxCof_ptr = NULL;	
	
		
	// FZG.iceTrqMinCof.txt(1x3)
		iceTrqMinCof_ptr = populateArrayStruct(iceTrqMinCof, fzg_prefix);	
		for (m = 0; m < iceTrqMinCof.row_num; m++) {
				for (n = 0; n < iceTrqMinCof.col_num; n++) {
						fzg_array_struct.iceTrqMinCof[m * iceTrqMinCof.col_num + n] 
							= *(iceTrqMinCof_ptr + m * iceTrqMinCof.col_num + n);
				}
		}				
		iceTrqMinCof_ptr = NULL;
			
		
	// FZG.emoSpdMgd.txt(1x3)
		emoSpdMgd_ptr = populateArrayStruct(emoSpdMgd, fzg_prefix);
		for (m = 0; m < iceTrqMaxCof.row_num; m++) {
				for (n = 0; n < iceTrqMaxCof.col_num; n++) {
						fzg_array_struct.emoSpdMgd[m * emoSpdMgd.col_num + n] 
							= *(emoSpdMgd_ptr + m * emoSpdMgd.col_num + n);
				}
		}			
		emoSpdMgd_ptr = NULL;	


	// FZG.emoTrqMgd
		emoTrqMgd_ptr = populateArrayStruct(emoTrqMgd, fzg_prefix);
		for (m = 0; m < emoTrqMgd.row_num; m++) {
				for (n = 0; n < emoTrqMgd.col_num; n++) {
						fzg_array_struct.emoTrqMgd[m * emoTrqMgd.col_num + n]
							= *(emoTrqMgd_ptr + m * emoTrqMgd.col_num + n);
				}
		}
		emoTrqMgd_ptr = NULL;
		
		
	// FZG.emoPwr_emoSpd_emoTrq
		emoPwr_emoSpd_emoTrq_ptr = populateArrayStruct(emoPwr_emoSpd_emoTrq, fzg_prefix);
		for (m = 0; m < emoPwr_emoSpd_emoTrq.row_num; m++) {
				for (n = 0; n < emoPwr_emoSpd_emoTrq.col_num; n++) {
						fzg_array_struct.emoPwr_emoSpd_emoTrq[m * emoPwr_emoSpd_emoTrq.col_num + n]
							= *(emoPwr_emoSpd_emoTrq_ptr + m * emoPwr_emoSpd_emoTrq.col_num + n);
				}
		}
		emoPwr_emoSpd_emoTrq_ptr = NULL;
			
		printf("emoTrqMin_emoSpd.string_name: %s\n", emoTrqMin_emoSpd.string_name);
		printf("emoTrqMin_emoSpd.row_num: %d\n", emoTrqMin_emoSpd.row_num);
		printf("emoTrqMin_emoSpd.col_num: %d\n", emoTrqMin_emoSpd.col_num);								
	 // FZG.emoTrqMin_emoSpd
		emoTrqMin_emoSpd_ptr = populateArrayStruct(emoTrqMin_emoSpd, fzg_prefix);
		for (m = 0; m < emoTrqMin_emoSpd.row_num; m++) {
				for (n = 0; n < emoTrqMin_emoSpd.col_num; n++) {
						fzg_array_struct.emoTrqMin_emoSpd[m * emoTrqMin_emoSpd.col_num + n]
							= *(emoTrqMin_emoSpd_ptr + m * emoTrqMin_emoSpd.col_num + n);
				}
		}
		emoTrqMin_emoSpd_ptr = NULL;

			
	// FZG.emoTrqMax_emoSpd
		emoTrqMax_emoSpd_ptr = populateArrayStruct(emoTrqMax_emoSpd, fzg_prefix);
		for (m = 0; m < emoTrqMax_emoSpd.row_num; m++) {
				for (n = 0; n < emoTrqMax_emoSpd.col_num; n++) {
						fzg_array_struct.emoTrqMax_emoSpd[m * emoTrqMax_emoSpd.col_num + n]
							= *(emoTrqMax_emoSpd_ptr + m * emoTrqMax_emoSpd.col_num + n);
				}
		}
		emoTrqMax_emoSpd_ptr = NULL;
		
		
	// FZG.emoPwrMgd
		emoPwrMgd_ptr  = populateArrayStruct(emoPwrMgd, fzg_prefix);
		for (m = 0; m < emoPwrMgd.row_num; m++) {
				for (n = 0; n > emoPwrMgd.col_num; n++) {
						fzg_array_struct.emoPwrMgd[m * emoPwrMgd.col_num + n]
							=  *(emoPwrMgd_ptr + m * emoPwrMgd.col_num + n);
				}
		}
		emoPwrMgd_ptr = NULL;
	
	
	// emoTrq_emoSpd_emoPwr
		emoTrq_emoSpd_emoPwr_ptr = populateArrayStruct(emoTrq_emoSpd_emoPwr, fzg_prefix);
		for (m = 0; m < emoTrq_emoSpd_emoPwr.row_num; m++) {
				for (n = 0; n < emoTrq_emoSpd_emoPwr.col_num; n++) {
						fzg_array_struct.emoTrq_emoSpd_emoPwr[m * emoTrq_emoSpd_emoPwr.col_num + n]
							= *(emoTrq_emoSpd_emoPwr_ptr + m * emoTrq_emoSpd_emoPwr.col_num + n);
				}
		}	
		emoTrq_emoSpd_emoPwr_ptr = NULL;
			
		// emoPwrMax_emoSpd
		emoPwrMax_emoSpd_ptr = populateArrayStruct(emoPwrMax_emoSpd, fzg_prefix);
		for (m = 0; m < emoPwrMax_emoSpd.row_num; m++) {
				for (n = 0; n < emoPwrMax_emoSpd.col_num; n++) {
						fzg_array_struct.emoPwrMax_emoSpd[m * emoPwrMax_emoSpd.col_num + n]
							= *(emoPwrMax_emoSpd_ptr + m * emoPwrMax_emoSpd.col_num + n);
				}
		}												
		emoPwrMax_emoSpd_ptr = NULL;	


	// emoPwrMin_emoSpd
		emoPwrMin_emoSpd_ptr = populateArrayStruct(emoPwrMin_emoSpd, fzg_prefix);
		for (m = 0; m < emoPwrMin_emoSpd.row_num; m++) {
				for (n = 0; n < emoPwrMin_emoSpd.col_num; n++) {
						fzg_array_struct.emoPwrMin_emoSpd[m * emoPwrMin_emoSpd.col_num + n]
							= *(emoPwrMin_emoSpd_ptr + m * emoPwrMin_emoSpd.col_num + n);
				}
		}																									
		emoPwrMin_emoSpd_ptr = NULL;			
		
}

// declare function here!!	
double *populateArrayStruct(struct varStruct inputStruct, char *prefix){
		double buffer_size[inputStruct.row_num * inputStruct.col_num];
		double *buffer = &buffer_size[0];
		return (double *)readRawText(prefix,	inputStruct.string_name, 	inputStruct.row_num,
									inputStruct.col_num, 		buffer);
}

// function for malloc
double *emalloc(size_t amt) {
	    double *v = malloc(amt);  
	    if(!v) {
		        fprintf(stderr, "out of mem - trying one more time\n");
		        v = malloc(amt*500);
				if(!v) {
						fprintf(stderr, "out of mem\n");
				        exit(EXIT_FAILURE);
		    	}
		}
	    return v;
}
