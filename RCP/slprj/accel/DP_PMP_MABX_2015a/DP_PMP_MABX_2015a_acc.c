#include "__cf_DP_PMP_MABX_2015a.h"
#include <math.h>
#include "DP_PMP_MABX_2015a_acc.h"
#include "DP_PMP_MABX_2015a_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T currentTime ;
ZCEventType zcEvent ; int32_T i ; djphhfyfds * _rtB ; pdju3cb4ye * _rtP ;
jwgutf0v23 * _rtZCE ; a1erqlu5rm * _rtDW ; _rtDW = ( ( a1erqlu5rm * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( jwgutf0v23 * ) _ssGetPrevZCSigState ( S
) ) ; _rtP = ( ( pdju3cb4ye * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
djphhfyfds * ) _ssGetBlockIO ( S ) ) ; _rtB -> agfwnaqkyt = _rtP -> P_0 ;
_rtB -> ha3mxmhehb = _rtP -> P_1 ; _rtB -> hc33jlyzei = _rtP -> P_2 ; _rtB ->
bt3gmhygcb = _rtP -> P_3 ; _rtB -> bcjpncmorz = _rtP -> P_4 ; _rtB ->
fz44eul4nk = _rtP -> P_5 ; _rtB -> nq5n4npraq = _rtP -> P_6 ; _rtB ->
cmdk43pnm5 = _rtP -> P_7 ; _rtB -> iunwevvncr = _rtP -> P_8 ; _rtB ->
daykjxlqyn = _rtP -> P_9 ; _rtB -> pd4r4d1zdd = _rtP -> P_10 ; _rtB ->
g0wyowtqh2 = _rtP -> P_11 ; for ( i = 0 ; i < 800 ; i ++ ) { _rtB ->
lpgb0cz3ec [ i ] = _rtP -> P_12 [ i ] ; _rtB -> miabla1zgi [ i ] = _rtP ->
P_13 [ i ] ; } memcpy ( & _rtB -> gjpuo1dfse [ 0 ] , & _rtP -> P_14 [ 0 ] ,
8800U * sizeof ( real_T ) ) ; currentTime = ssGetTaskTime ( S , 0 ) ; if (
currentTime < _rtP -> P_15 ) { _rtB -> genrlqr1r3 = _rtP -> P_16 ; } else {
_rtB -> genrlqr1r3 = _rtP -> P_17 ; } zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> bfjundhlwu , ( _rtB -> genrlqr1r3 ) ) ; if
( zcEvent != NO_ZCEVENT ) { _rtB -> bm55rmnbad = ( int8_T ) zcEvent ;
ssCallAccelRunBlock ( S , 0 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtDW -> cxjmyxwwya
= 4 ; } ssCallAccelRunBlock ( S , 1 , 17 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 18 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S
, 0 , 2203014085U ) ; ssSetChecksumVal ( S , 1 , 4239382885U ) ;
ssSetChecksumVal ( S , 2 , 2747594994U ) ; ssSetChecksumVal ( S , 3 ,
249472122U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
a1erqlu5rm ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( djphhfyfds ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
pdju3cb4ye ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & grzeqpqxts ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
