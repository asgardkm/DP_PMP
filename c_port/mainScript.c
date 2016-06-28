// mainScript.c
// 
// function: reads in text input and seds it to clcDP_port()
//
// created on 27.06.2016

#include <stdio.h>
//#include "loadScalarData.h"
#include "loadScalarData_params.h"
#include "loadScalarData_test.h"
#include "loadScalarData_fahr.h"
#include "loadArrayData_fzg.h"
#include "loadArrayData_test.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "./codegen/lib/clcDP_port/clcDP_port_initialize.h"
#include "./codegen/lib/clcDP_port/clcDP_port.h"

int main(void) {	
//	// call init.c and get the structures
//
//	// but first define mainConfig.txt location
		int m;

		// save scalardata
		printf("-Loading model data and parameters...");
		char *configDir = "mainConfig.txt";
//		struct outputScalarStruct scalardata_struct = loadScalarData(configDir);
		
		struct0_T params_scalardata = loadScalarData_params(configDir);
		struct1_T tstdat_scalardata = loadScalarData_test(configDir);
		struct2_T fahrzg_scalardata = loadScalarData_fahr(configDir);
		
		struct0_T *params_scalarpointer  	= &params_scalardata;
		struct1_T *tstdat_scalarpointer 	= &tstdat_scalardata;
		struct2_T *fahrzg_scalarpointer 	= &fahrzg_scalardata;
		
		// test: output the structures stuff
//		printf("params_scalarpointer: %p\n", params_scalarpointer);
//		printf("params_scalardata.batEngStp: %4.4f\n", params_scalardata.batEngStp);
		printf("\n\nparams_scalarpointer->wayInxBeg: %4.4f\n", params_scalarpointer->wayInxBeg);
		printf("params_scalarpointer->wayInxEnd: %4.4f\n\n", params_scalarpointer->wayInxEnd);
//		printf("	disFlg: %4.4f\n", params_scalardata.disFlg);
//		printf("	wayStp: %4.4f\n", params_scalardata.wayStp);
//		printf("	engKinBegInx: %4.4f\n", params_scalardata.engKinBegInx);
//		printf("	wayInxEnd: %4.4f\n", params_scalardata.wayInxEnd);
//
//		printf("\ntstdat_scalarpointer: %p\n", tstdat_scalarpointer);
//		printf("tstdat_scalardata.engKinNum: %4.4f\n", tstdat_scalardata.engKinNum);
//		printf("tstdat_scalarpointer->engKinNum: %4.4f\n", tstdat_scalarpointer->engKinNum);
//	
//		printf("\nfahrzg_scalarpointer: %p\n", fahrzg_scalarpointer);
//		printf("fahrzg_scalardata.batPwrMax: %4.4f\n", fahrzg_scalardata.batPwrMax);
//		printf("fahrzg_scalarpointer->batPwrMax: %4.4f\n", fahrzg_scalarpointer->batPwrMax);
//		
//		 load in arraydata
		struct3_T tstdat_arraydata = loadArrayData_test(tstdat_scalardata);
		struct3_T *tstdat_arraypointer  = &tstdat_arraydata;
		struct4_T fahrzg_arraydata = loadArrayData_fzg(tstdat_scalardata);
		struct4_T *fahrzg_arraypointer  = &fahrzg_arraydata;
		printf("done!\n");    

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
		for (m = 0; m < 14850; m++) {
//			printf("fahrzg_arraypointer->iceSpdMgd[%d]: %4.3f\n", m, fahrzg_arraypointer->iceSpdMgd[m]);
			printf("fahrzg_arraypointer->emoSpdMgd[%d]: %4.3f\n", m, fahrzg_arraypointer->emoSpdMgd[m]);
		}
		// DEFINE OUTPUT STRUCTS
		struct emxArray_real_T *engKinOptVec;
		struct emxArray_real_T *batEngDltOptVec;
		struct emxArray_real_T *fulEngDltOptVec;
		struct emxArray_real_T *staVec;
		emxArray_real_T *psiEngKinOptVec;
		double *fulEngOpt;
		boolean_T *resVld;
		
		// RUN CODER!
		clcDP_port_initialize();
//		
//		clcDP_port(params_scalarpointer, 
//			tstdat_scalarpointer,
//			fahrzg_scalarpointer,
//			tstdat_arraypointer, 
//			fahrzg_arraypointer,
//			engKinOptVec, 
//			batEngDltOptVec,
//			fulEngDltOptVec, 
//			staVec,
//			psiEngKinOptVec, 
//			fulEngOpt, 
//			resVld);	
				
		clcDP_port_terminate();
					
		printf("no crashes :)\n");				
		getchar();
		return 0;
}
