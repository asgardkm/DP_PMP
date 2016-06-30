#include "__cf_DP_PMP_MABX_2015a.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "DP_PMP_MABX_2015a_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "DP_PMP_MABX_2015a.h"
#include "DP_PMP_MABX_2015a_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"DP_PMP_MABX_2015a/clcDP" ) , TARGET_STRING ( "fulEngOpt" ) , 5 , 0 , 0 , 0 ,
0 } , { 1 , 1 , TARGET_STRING ( "DP_PMP_MABX_2015a/clcDP" ) , TARGET_STRING (
"resVld" ) , 6 , 1 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"DP_PMP_MABX_2015a/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 3 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , {
4 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant1" ) , TARGET_STRING ( "Value"
) , 0 , 2 , 0 } , { 5 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant10" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 6 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant11" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 7 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant12" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 8 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant13" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 9 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant17" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant18" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } ,
{ 11 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant4" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
13 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
15 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"DP_PMP_MABX_2015a/Constant8" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
17 , TARGET_STRING ( "DP_PMP_MABX_2015a/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING ( "DP_PMP_MABX_2015a/Step" ) ,
TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
"DP_PMP_MABX_2015a/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 20
, TARGET_STRING ( "DP_PMP_MABX_2015a/Step" ) , TARGET_STRING ( "After" ) , 0
, 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ctauc4dyfo , & rtB . fylwekf5vd ,
& rtB . d5jctfz5jv , & rtP . Constant_Value [ 0 ] , & rtP . Constant1_Value [
0 ] , & rtP . Constant10_Value , & rtP . Constant11_Value , & rtP .
Constant12_Value , & rtP . Constant13_Value , & rtP . Constant17_Value , &
rtP . Constant18_Value [ 0 ] , & rtP . Constant3_Value , & rtP .
Constant4_Value , & rtP . Constant5_Value , & rtP . Constant6_Value , & rtP .
Constant7_Value , & rtP . Constant8_Value , & rtP . Constant9_Value , & rtP .
Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 800 , 1 , 11 , 800 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [
] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , -
1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 3 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 18 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 122533255U , 2387482475U , 1929481518U ,
1921104030U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
DP_PMP_MABX_2015a_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void DP_PMP_MABX_2015a_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void DP_PMP_MABX_2015a_host_InitializeDataMapInfo (
DP_PMP_MABX_2015a_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
