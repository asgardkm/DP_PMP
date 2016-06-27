// loadScalarData.h
// header file for loadScalarData.c, the main input-reading function
// created on 27.06.2016 - asgard kaleb marroquin

#include "./codegen/lib/clcDP_port/clcDP_port_types.h"

#ifndef OUTPUT_TEST_STRUCTURE
#define OUTPUT_TEST_STRUCTURE
// declare output structure from init.c
struct outputScalarStruct{
		struct0_T *params_scalar_struct;
		struct1_T *tstdat_scalar_struct; 
	 	struct2_T *fahrzg_scalar_struct;
};
#endif

// function declaration
#ifndef INIT_DECLARATION
#define INIT_DECLARATION
struct outputScalarStruct loadScalarData(char *mainConfigDir);
#endif

