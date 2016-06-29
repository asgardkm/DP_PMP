// loadArrayData.h
//
// trying to make a structure that contains both array structures that
// loadArrayData can output no problem. The structure can be parsed out
// in mainScript afterwards
//
// created 22.06.2016

#include "./codegen/lib/clcDP_port/clcDP_port_types.h"
#include "readConfig.h"


#ifndef LOADARRAY		// header guard for loadArrayData()
#define LOADARRAY
//struct cbArray *loadArrayData(struct1_T tstdat_scalar_struct));
void loadArrayData(struct1_T tstdat_scalar_struct);
//struct cbArrayStruct loadArrayData(struct1_T tstdat_scalar_struct);

#endif


#ifndef CBARRAYSTRUCT 	// header guard for cbArrayStruct
#define CBARRAYSTRUCT
struct cbArrayStruct {
		struct3_T *tst_pointer;
		struct4_T *fzg_pointer;
};
#endif


#ifndef VARSTRUCT		// header guard for varStruct
#define VARSTRUCT
struct varStruct {
	char *string_name;
	int row_num;
	int col_num;
};
#endif

