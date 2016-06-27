// mainScript.c
// 
// function: reads in text input and seds it to clcDP_port()
//
// created on 27.06.2016

#include <stdio.h>
#include "loadScalarData.h"
#include "loadArrayData_fzg.h"
#include "loadArrayData_test.h"
#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "./codegen/lib/clcDP_port/clcDP_port_initialize.h"
#include "./codegen/lib/clcDP_port/clcDP_port.h"

int main(void) {
//	
//	// call init.c and get the structures
//	// but first define mainConfig.txt location
		char *configDir = "mainConfig.txt";
		struct outputScalarStruct scalardata_struct = loadScalarData(configDir);
	
////		test: output the structures stuff
//		printf("output_params_test:\n");
//		printf("	disFlg: %4.4f\n", params_scalardata.disFlg);
//		printf("	wayStp: %4.4f\n", params_scalardata.wayStp);
//		printf("	engKinBegInx: %4.4f\n", params_scalardata.engKinBegInx);
//		printf("	wayInxEnd: %4.4f\n", params_scalardata.wayInxEnd);

		// load in arraydata
		struct3_T *tstdat_arraydata = loadArrayData_test(*scalardata_struct.tstdat_scalar_struct);
//		struct4_T *fahrzg_arraydata = loadArrayData_fzg(*scalardata_struct.tstdat_scalar_struct);
		
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
		
//		clcDP_port(scalardata_struct.params_scalar_struct, 
//			scalardata_struct.tstdat_scalar_struct,
//			scalardata_struct.fahrzg_scalar_struct,
//			tstdat_arraydata, 
//			fahrzg_arraydata,
//			engKinOptVec, 
//			batEngDltOptVec,
//			fulEngDltOptVec, 
//			staVec,
//			psiEngKinOptVec, 
//			fulEngOpt, 
//			resVld);	
				
		clcDP_port_terminate();
									
		getchar();
		return 0;
}
