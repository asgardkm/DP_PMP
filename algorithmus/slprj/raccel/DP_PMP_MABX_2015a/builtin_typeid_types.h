#include "__cf_DP_PMP_MABX_2015a.h"
#ifndef __BUILTIN_TYPEID_TYPES_H__
#define __BUILTIN_TYPEID_TYPES_H__
#include "rtwtypes.h"
#ifndef __BUILTIN_TYPEID_TYPES__
#define __BUILTIN_TYPEID_TYPES__
typedef enum { SS_DOUBLE = 0 , SS_SINGLE = 1 , SS_INT8 = 2 , SS_UINT8 = 3 ,
SS_INT16 = 4 , SS_UINT16 = 5 , SS_INT32 = 6 , SS_UINT32 = 7 , SS_BOOLEAN = 8
} BuiltInDTypeId ;
#define SS_NUM_BUILT_IN_DTYPE          ((int_T)SS_BOOLEAN+1)
typedef int_T DTypeId ;
#endif
#endif
