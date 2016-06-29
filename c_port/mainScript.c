// mainScript.c
// 
// function: reads in text input and sends it to clcDP_port()
//
// input: char *configDir - string path to main Configuration textfile directory
//
// output:  batEngDltOptVec - 
//			fulEngDltOptVec - 
//			staVec			-
//			psiEngKinOptVec -
//			fulEngOpt		-
//			resVld			- 
//
// created on 27.06.2016 - asgard kaleb marroquin

#include <stdio.h>
#include "loadScalarData_params.h"
#include "loadScalarData_test.h"
#include "loadScalarData_fahr.h"
#include "loadArrayData_fzg.h"
#include "loadArrayData_test.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "./codegen/lib/clcDP_port/clcDP_port_initialize.h"
#include "./codegen/lib/clcDP_port/clcDP_port.h"

int main(void) {	
// ========================================================================
// ============ DEFINE INPUTS =============================================
		printf("-Loading model data and parameters...");
// 		define mainConfig.txt location
		char *configDir = "mainConfig.txt";

//	 	load in scalardata		
		struct0_T params_scalardata = loadScalarData_params(configDir);
		struct1_T tstdat_scalardata = loadScalarData_test(configDir);
		struct2_T fahrzg_scalardata = loadScalarData_fahr(configDir);
		
		// must point to structres as clcDP_port() takes in only structure pointers
		struct0_T *params_scalarpointer = &params_scalardata;
		struct1_T *tstdat_scalarpointer = &tstdat_scalardata;
		struct2_T *fahrzg_scalarpointer = &fahrzg_scalardata;

//		load in arraydata
		struct3_T tstdat_arraydata = loadArrayData_test(tstdat_scalardata);
		struct4_T fahrzg_arraydata = loadArrayData_fzg(tstdat_scalardata);
		
		struct3_T *tstdat_arraypointer  = &tstdat_arraydata;
		struct4_T *fahrzg_arraypointer  = &fahrzg_arraydata;
		printf("done!\n");    
		
		int k, m; 	// loop counters for testing
		
//      	for (k = 0; k < 15000; k++)
//      			printf("emoSpdMgd[%d]: %4.3f\n", k, fahrzg_arraypointer->emoSpdMgd[k]);
//      for (k = 0; k < 100; k++) {
////        b_fzg_array[k] = fahrzg_arraypointer->emoSpdMgd[150 * k];
//        printf("b_fzg_array[%d]: %4.3f\n", k, fahrzg_arraypointer->emoSpdMgd[100 * k + k]);
//      }
//		printf("tstdat_arraypointer address: %p\n", tstdat_arraypointer);
//		printf("tstdat_arraypointer->engKinMat_engKinInx_wayInx[1]: %4.4f\n", tstdat_arraypointer->engKinMat_engKinInx_wayInx[1]);
//		for (m = 0; m < 8800; m++)
//			printf("tstdat_pointer->engKinMat_engKinInx_wayInx[%d]: %4.4f\n", m, tstdat_arraypointer->engKinMat_engKinInx_wayInx[m]);
//			
//		printf("fahrzg_arraypointer address: %p\n", fahrzg_arraypointer);
//		for (m = 0; m < 15000; m++)
//			printf("fahrzg_arraypointer->emoPwr_emoSpd_emoTrq[%d]: %4.4f\n", m, fahrzg_arraypointer->emoPwr_emoSpd_emoTrq[m]);
//		

//		for (m = 0; m < 100; m++) {
//			printf("fahrzg_arraydata.emoTrqMax_emoSpd[%d]: %4.3f\n", m, fahrzg_arraydata.emoTrqMax_emoSpd[m]);
//
//		}
//		for (m = 0; m < 6; m++) {
//			printf("fahrzg_arraypointer->geaRat[%d]: %4.3f\n", m, fahrzg_arraypointer->geaRat[m]);
//		}
//		for (m = 0; m < 15000; m++) {
////			printf("fahrzg_arraypointer->iceSpdMgd[%d]: %4.3f\n", m, fahrzg_arraypointer->iceSpdMgd[m]);
//			printf("fahrzg_arraypointer->emoSpdMgd[%d]: %4.3f\n", m, fahrzg_arraypointer->emoSpdMgd[m]);
//		}
		// DEFINE OUTPUT STRUCTS
		struct emxArray_real_T *engKinOptVec;
		struct emxArray_real_T *batEngDltOptVec;
		struct emxArray_real_T *fulEngDltOptVec;
		struct emxArray_real_T *staVec;
		emxArray_real_T *psiEngKinOptVec;
		double *fulEngOpt;
		boolean_T *resVld;
		
// ========================================================================
// ============ RUN MODEL =================================================

		// RUN CODER!
		clcDP_port_initialize();
		
		clcDP_port(params_scalarpointer, 
			tstdat_scalarpointer,
			fahrzg_scalarpointer,
			tstdat_arraypointer, 
			fahrzg_arraypointer,
			engKinOptVec, 
			batEngDltOptVec,
			fulEngDltOptVec, 
			staVec,
			psiEngKinOptVec, 
			fulEngOpt, 
			resVld);	
				
		clcDP_port_terminate();
// ========================================================================

		printf("no crashes :)\n");				
		getchar();
		return 0;
}
