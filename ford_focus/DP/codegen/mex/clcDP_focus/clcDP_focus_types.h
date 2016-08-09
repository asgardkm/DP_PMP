/*
 * clcDP_focus_types.h
 *
 * Code generation for function 'clcDP_focus'
 *
 */

#ifndef __CLCDP_FOCUS_TYPES_H__
#define __CLCDP_FOCUS_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_int32_T*/
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /*typedef_emxArray_int32_T*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct
{
    real_T disFlg;
    real_T iceFlgBool;
    real_T brkBool;
    real_T iceExtBool;
    real_T timStp;
    real_T batEngBegMinRat;
    real_T batEngBegMaxRat;
    real_T batEngEndMinRat;
    real_T batEngEndMaxRat;
    real_T batPwrAux;
    real_T staChgPenCosVal;
    real_T timInxBeg;
    real_T timInxEnd;
    real_T engBeg;
    real_T engEnd;
    real_T staBeg;
} struct0_T;
#endif /*typedef_struct0_T*/
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct
{
    real_T useGeaSta;
    real_T staNum;
    real_T geaStaMin;
    real_T geaStaMax;
    real_T engStaNum;
    real_T engStaMin;
    real_T engStaMax;
    real_T batEngMin;
    real_T batEngStp;
    real_T batEngMax;
} struct1_T;
#endif /*typedef_struct1_T*/
#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct
{
    real_T vehVelMin;
    real_T vehVelMax;
    real_T vehVelThresh;
    real_T vehAccMax;
    real_T vehAccMin;
    real_T drgCof;
    real_T vehMas;
    real_T whlRosResCof;
    real_T whlDrr;
    real_T batRstChr;
    real_T batRstDch;
    real_T batPwrMax;
    real_T batPwrMin;
    real_T geaEfy;
    real_T fulDen;
    real_T fulLhv;
    real_T fuel_density;
    real_T fuel_lower_heating_value;
} struct2_T;
#endif /*typedef_struct2_T*/
#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct
{
    real_T batOcvCof_batEng[2];
    real_T geaRat[6];
    real_T iceSpdMgd[35];
    real_T iceTrqMgd[38];
    real_T iceFulPwr_iceSpd_iceTrq[1330];
    real_T iceTrqMaxCof[3];
    real_T iceTrqMinCof[3];
    real_T emoSpdMgd[73];
    real_T emoTrqMgd[95];
    real_T emoPwr_emoSpd_emoTrq[6650];
    real_T emoTrqMin_emoSpd[146];
    real_T emoTrqMax_emoSpd[146];
    real_T emoPwrMgd[66];
    real_T emoTrq_emoSpd_emoPwr[4620];
    real_T emoPwrMax_emoSpd[146];
    real_T emoPwrMin_emoSpd[146];
    real_T SOC_vs_OCV[22];
    real_T geaEfy[6];
    real_T iceTrqMax_emoSpd[70];
    real_T iceTrqMin_emoSpd[70];
} struct3_T;
#endif /*typedef_struct3_T*/

#endif
/* End of code generation (clcDP_focus_types.h) */
