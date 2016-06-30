#include "__cf_DP_PMP_MABX_2015a.h"
#ifndef RTW_HEADER_DP_PMP_MABX_2015a_h_
#define RTW_HEADER_DP_PMP_MABX_2015a_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef DP_PMP_MABX_2015a_COMMON_INCLUDES_
#define DP_PMP_MABX_2015a_COMMON_INCLUDES_
#include <stdlib.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "DP_PMP_MABX_2015a_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME DP_PMP_MABX_2015a
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (8) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { njrfqz0ws2 koj1jet31x ; real_T ashg15p1m3 [ 52800 ] ; real_T
k0kjnui1rd [ 52800 ] ; real_T a2wbwsciqx [ 52800 ] ; real_T owhshif5u0 [ 800
] ; real_T iqqaw4rdbk [ 800 ] ; real_T khatayx4gd [ 800 ] ; real_T aee4onh21k
[ 800 ] ; real_T idg13ttbrz [ 800 ] ; real_T d5jctfz5jv ; real_T ctauc4dyfo ;
boolean_T fylwekf5vd ; } B ; typedef struct { real_T joewxwm0m5 ; real_T
fbder3zpch ; struct { void * LoggedData ; } hkwzdlepko ; struct { void *
LoggedData ; } gzvuolh0vm ; int8_T cxjmyxwwya ; boolean_T n0e1c5dddi ; } DW ;
typedef struct { ZCSigState bfjundhlwu ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
Constant11_Value ; real_T Constant10_Value ; real_T Constant9_Value ; real_T
Constant5_Value ; real_T Constant3_Value ; real_T Constant6_Value ; real_T
Constant7_Value ; real_T Constant8_Value ; real_T Constant12_Value ; real_T
Constant4_Value ; real_T Constant13_Value ; real_T Constant17_Value ; real_T
Constant_Value [ 800 ] ; real_T Constant18_Value [ 800 ] ; real_T
Constant1_Value [ 8800 ] ; real_T Step_Time ; real_T Step_Y0 ; real_T
Step_YFinal ; } ; extern P rtP ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern PrevZCX
rtPrevZCX ; extern const rtwCAPI_ModelMappingStaticInfo *
DP_PMP_MABX_2015a_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
