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
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "loadArrayData.h"
#include "readConfig.h"

#define FZG_SIZE1 150
#define FZG_SIZE2 100
#define TRQ_COEF 3
#define BAT_COEF 2
void *loadArrayData(struct1_T tstdat_scalar_struct){
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
		slpVec_wayInx.row_num 				= tstdat_scalar_struct.wayNum;
		slpVec_wayInx.col_num 				= 1;
		
		// engKinMat_engKinInx_wayInx
		struct varStruct engKinMat_engKinInx_wayInx;
		engKinMat_engKinInx_wayInx.string_name = "engKinMat_engKinInx_wayInx";
		engKinMat_engKinInx_wayInx.row_num 	= tstdat_scalar_struct.engKinNum;
		engKinMat_engKinInx_wayInx.col_num 	= tstdat_scalar_struct.wayNum;
		
		// engKinNumVec_wayInx
		struct varStruct engKinNumVec_wayInx;
		engKinNumVec_wayInx.string_name 	= "engKinNumVec_wayInx";
		engKinNumVec_wayInx.row_num 		= tstdat_scalar_struct.wayNum;
		engKinNumVec_wayInx.row_num 		= 1;
		
		
		// DEFINE FZG ARRAY STRUCTURES
		// batOcvCof_batEng
		struct varStruct batOcvCof_batEng;
		batOcvCof_batEng.string_name 		= "batOcvCof_batEng";
		batOcvCof_batEng.row_num 			= 1;
		batOcvCof_batEng.col_num 			= BAT_COEF;
		
		// geaRat
		struct varStruct geaRat;
		geaRat.string_name 					= "geaRat";
		geaRat.row_num 						= 1;
		geaRat.col_num 						= tstdat_scalar_struct.staNum;
		
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
		
		// POINTERS TO TEST ARRAY STRUCTURES	 
		double *slpVec_wayInx_ptr;
		double *engKinMat_engKinInx_wayInx_ptr;
		double *engKinNumVec_wayInx_ptr;
		
		// POINTERS TO FAHRZEUG ARRAY STRUCTURES
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

//		// DEFINE TEST ARRAY BUFFER
		double slpVec_wayInx_buffer				[slpVec_wayInx.row_num][slpVec_wayInx.col_num];
//		double engKinMat_engKinInx_wayInx_buffer[engKinMat_engKinInx_wayInx.row_num][engKinMat_engKinInx_wayInx.col_num];
		double engKinNumVec_wayInx_buffer		[engKinNumVec_wayInx.row_num][engKinNumVec_wayInx.col_num];
//		// DEFINE FAHRZEUG ARRAY BUFFER
		double batOcvCof_batEng_buffer			[batOcvCof_batEng.row_num][batOcvCof_batEng.col_num];
		double geaRat_buffer					[geaRat.row_num][geaRat.col_num];
		double iceSpdMgd_buffer					[iceSpdMgd.row_num][iceSpdMgd.col_num];
		double iceTrqMgd_buffer					[iceTrqMgd.row_num][iceTrqMgd.col_num];
		double iceFulPwr_iceSpd_iceTrq_buffer	[iceFulPwr_iceSpd_iceTrq.row_num][iceFulPwr_iceSpd_iceTrq.col_num];
		double iceTrqMaxCof_buffer				[iceTrqMaxCof.row_num][iceTrqMaxCof.col_num];
		double iceTrqMinCof_buffer				[iceTrqMinCof.row_num][iceTrqMinCof.col_num];
		double emoSpdMgd_buffer					[emoSpdMgd.row_num][emoSpdMgd.col_num];
		double emoTrqMgd_buffer					[emoTrqMgd.row_num][emoTrqMgd.col_num];
		double emoPwr_emoSpd_emoTrq_buffer		[emoPwr_emoSpd_emoTrq.row_num][emoPwr_emoSpd_emoTrq.col_num];
		double emoTrqMin_emoSpd_buffer			[emoTrqMin_emoSpd.row_num][emoTrqMin_emoSpd.col_num];
		double emoTrqMax_emoSpd_buffer			[emoTrqMax_emoSpd.row_num][emoTrqMax_emoSpd.col_num];
		double emoPwrMgd_buffer					[emoPwrMgd.row_num][emoPwrMgd.col_num];
		
//		
		double emoTrq_emoSpd_emoPwr_buffer		[emoTrq_emoSpd_emoPwr.row_num][emoTrq_emoSpd_emoPwr.col_num];
//		
//		
		double emoPwrMax_emoSpd_buffer			[emoPwrMax_emoSpd.row_num][emoPwrMax_emoSpd.col_num];
		double emoPwrMin_emoSpd_buffer			[emoPwrMin_emoSpd.row_num][emoPwrMax_emoSpd.col_num];
//		
	
	printf("\n\n\ntstdat_scalar_struct.staNum: %d\n", tstdat_scalar_struct.staNum);
	printf("tstdat_scalar_struct.wayNum: %d\n", 	tstdat_scalar_struct.wayNum);
	printf("tstdat_scalar_struct.engKinNum: %d\n", 	tstdat_scalar_struct.engKinNum);


		// ================ time to load in vectors! ====================================================
//	// tstDat800.slpVec_wayInx
//		slpVec_wayInx_ptr 			= readRawText(tst_prefix,
//													slpVec_wayInx.string_name, 		slpVec_wayInx.row_num,
//													slpVec_wayInx.col_num,			slpVec_wayInx_buffer);
//	// tstDat800.engKinMat_engKinInx_wayInx
//		engKinMat_engKinInx_wayInx_ptr = readRawText(tst_prefix,
//													engKinMat_engKinInx_wayInx.string_name,engKinMat_engKinInx_wayInx.row_num,
//													engKinMat_engKinInx_wayInx.col_num,engKinMat_engKinInx_wayInx_buffer);
//	// tstDat800.engKinNumVec_wayInx
//		engKinNumVec_wayInx_ptr 	= readRawText(tst_prefix,
//													engKinNumVec_wayInx.string_name,engKinNumVec_wayInx.row_num,
//													engKinNumVec_wayInx.col_num, 	engKinNumVec_wayInx_buffer);
//																									
//	// FZG.batOcvCof_batEng(1x2)
//		batOcvCof_batEng_ptr 		= readRawText(fzg_prefix,
//													batOcvCof_batEng.string_name,	batOcvCof_batEng.row_num,
//													batOcvCof_batEng.col_num,		batOcvCof_batEng_buffer);		
//	// FZG.geaRat(1xtstdat_scalar_struct.staNum)
//		geaRat_ptr					= readRawText(fzg_prefix,
//													geaRat.string_name,				geaRat.row_num,
//													geaRat.col_num,					geaRat_buffer);													
//	// FZG.iceSpdMgd
//		iceSpdMgd_ptr 				= readRawText(fzg_prefix,
//													iceSpdMgd.string_name, 			iceSpdMgd.row_num,
//													iceSpdMgd.col_num, 				iceSpdMgd_buffer);	
//	// FZG.iceTrqMgd					
//		iceTrqMgd_ptr 				= readRawText(fzg_prefix,
//													iceTrqMgd.string_name, 			iceTrqMgd.row_num,
//													iceTrqMgd.col_num, 				iceTrqMgd_buffer);																			
//	// FZG.iceFulPwr_iceSpd_iceTrq
//		iceFulPwr_iceSpd_iceTrq_ptr	= readRawText(fzg_prefix,
//													iceFulPwr_iceSpd_iceTrq.string_name,iceFulPwr_iceSpd_iceTrq.row_num,
//													iceFulPwr_iceSpd_iceTrq.col_num,iceFulPwr_iceSpd_iceTrq_buffer);											
//	// FZG.iceTrqMaxCof.txt(1x3)
//		iceTrqMaxCof_ptr 			= readRawText(fzg_prefix, 					
//													iceTrqMaxCof.string_name, 		iceTrqMaxCof.row_num, 			
//													iceTrqMaxCof.col_num, 			iceTrqMaxCof_buffer);
//	// FZG.iceTrqMinCof
//		iceTrqMinCof_ptr 			= readRawText(fzg_prefix,
//													iceTrqMinCof.string_name, 		iceTrqMinCof.row_num,
//													iceTrqMinCof.col_num, 			iceTrqMinCof_buffer);								
//	// FZG.emoSpdMgd
//		emoSpdMgd_ptr 				= readRawText(fzg_prefix,
//													emoSpdMgd.string_name, 			emoSpdMgd.row_num,
//													emoSpdMgd.col_num, 				emoSpdMgd_buffer);
//	// FZG.emoTrqMgd
//		emoTrqMgd_ptr 				= readRawText(fzg_prefix,
//													emoTrqMgd.string_name, 			emoTrqMgd.row_num,
//													emoTrqMgd.col_num, 				emoTrqMgd_buffer);
//	// FZG.emoPwr_emoSpd_emoTrq
//		emoPwr_emoSpd_emoTrq_ptr 	= readRawText(fzg_prefix,
//													emoPwr_emoSpd_emoTrq.string_name,emoPwr_emoSpd_emoTrq.row_num,
//													emoPwr_emoSpd_emoTrq.col_num, 	emoPwr_emoSpd_emoTrq_buffer);
//	// FZG.emoTrqMin_emoSpd
//		emoTrqMin_emoSpd_ptr 		= readRawText(fzg_prefix,
//													emoTrqMin_emoSpd.string_name, 	emoTrqMin_emoSpd.row_num,
//													emoTrqMin_emoSpd.col_num, 		emoTrqMin_emoSpd_buffer);
//	// FZG.emoTrqMax_emoSpd
//		emoTrqMax_emoSpd_ptr 		= readRawText(fzg_prefix,
//													emoTrqMax_emoSpd.string_name, 	emoTrqMax_emoSpd.row_num,
//													emoTrqMax_emoSpd.col_num, 		emoTrqMax_emoSpd_buffer);
//	// FZG.emoPwrMgd
//		emoPwrMgd_ptr 				= readRawText(fzg_prefix,
//													emoPwrMgd.string_name, 			emoPwrMgd.row_num,
//													emoPwrMgd.col_num, 				emoPwrMgd_buffer);	
//													
//
////	// emoTrq_emoSpd_emoPwr
////		emoTrq_emoSpd_emoPwr_ptr 	= readRawText(fzg_prefix,
////													emoTrq_emoSpd_emoPwr.string_name,emoTrq_emoSpd_emoPwr.row_num,
////													emoTrq_emoSpd_emoPwr.col_num, 	 emoTrq_emoSpd_emoPwr_buffer);
//
//
//	// emoPwrMax_emoSpd
//		emoPwrMax_emoSpd_ptr 		= readRawText(fzg_prefix,
//													emoPwrMax_emoSpd.string_name, 	emoPwrMax_emoSpd.row_num,
//													emoPwrMax_emoSpd.col_num, 		emoPwrMax_emoSpd_buffer);													
//	// emoPwrMin_emoSpd
//		emoPwrMin_emoSpd_ptr 		= readRawText(fzg_prefix,
//													emoPwrMin_emoSpd.string_name, 	emoPwrMin_emoSpd.row_num,
//													emoPwrMin_emoSpd.col_num, 		emoPwrMin_emoSpd_buffer);																										
//					
//					
					
								
//		for (m = 0; m < iceTrqMaxCof.row_num; m++) {
//				for (n = 0; n < iceTrqMaxCof.col_num; n++) {
////						printf(" *(iceTrqMaxCof_ptr + (%d*3) + %d): %4.3f\n", m, n, *(iceTrqMaxCof_ptr+m*iceTrqMaxCof.col_num+n));
//						fzg_array_struct.iceTrqMaxCof[m * iceTrqMaxCof.col_num + n] 		
//							= *(iceTrqMaxCof_ptr + m * iceTrqMaxCof.col_num + n);
////						printf("fzg_array_struct.iceTrqMaxCof[%d]: %4.3f\n\n", m*3+n, fzg_array_struct.iceTrqMaxCof[m*iceTrqMaxCof.col_num+n]);
//				}
//		}
//		

////	FZG.emoPwr_emoSpd_emoTrq.txt() (150x100)	
//		for (m = 0; m < emoPwr_emoSpd_emoTrq.row_num; m++) {
//				for (n = 0; n < emoPwr_emoSpd_emoTrq.col_num; n++) {
////						printf(" *(emoPwr_emoSpd_emoTrq_ptr + (%d*150) + %d): %4.3f\n", m, n, *(emoPwr_emoSpd_emoTrq_ptr+m *emoPwr_emoSpd_emoTrq.col_num+n));
//						fzg_array_struct.emoPwr_emoSpd_emoTrq[m * emoPwr_emoSpd_emoTrq.col_num + n] 
//							= *(emoPwr_emoSpd_emoTrq_ptr + m * emoPwr_emoSpd_emoTrq.col_num + n);
////						printf("fzg_array_struct.emoPwr_emoSpd_emoTrq_ptr[%d]: %4.3f\n\n", m*3+n, fzg_array_struct.emoPwr_emoSpd_emoTrq[m*emoPwr_emoSpd_emoTrq.col_num+n]);
//				}
//		}
		

		 	
		
}	
