// structArrayTypes.h
// 
// header file defines structure size for tst_array_struct (array data originally 
// under tstDat800) and fzg_array_struct(array data originally under FZG)
//
// created 22.06.2016
#ifndef STRUCT_TYPES
#define STRUCT_TYPES
// define tst_array_struct
struct tst_array_struct{
		char name[300];
		double value;
};
#endif


//#ifndef CBSCALARSTRUCT
//#define CBSCALARSTRUCT
//// NOTE - DO I NEED TO DECLARE A TYPE AFTER SETTING UP cbScalarArray STRUCT? (see above)
//struct cbScalarStruct {
//		struct0_T input_scalar_struct;
//		struct1_T tstdat_scalar_struct; 
//		struct2_T fahrzg_scalar_struct;
//};
//#endif
