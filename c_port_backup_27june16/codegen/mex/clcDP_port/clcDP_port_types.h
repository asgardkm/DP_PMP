/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_port_types.h
 *
 * Code generation for function 'clcDP_port'
 *
 */

#ifndef __CLCDP_PORT_TYPES_H__
#define __CLCDP_PORT_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T batOcvCof_batEng[2];
  real_T geaRat[6];
  real_T iceSpdMgd[15000];
  real_T iceTrqMgd[15000];
  real_T iceFulPwr_iceSpd_iceTrq[15000];
  real_T iceTrqMaxCof[3];
  real_T iceTrqMinCof[3];
  real_T emoSpdMgd[15000];
  real_T emoTrqMgd[15000];
  real_T emoPwr_emoSpd_emoTrq[15000];
  real_T emoTrqMin_emoSpd[100];
  real_T emoTrqMax_emoSpd[100];
  real_T emoPwrMgd[15000];
  real_T emoTrq_emoSpd_emoPwr[15000];
  real_T emoPwrMax_emoSpd[100];
  real_T emoPwrMin_emoSpd[100];
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_clcDP_portStackData
#define typedef_clcDP_portStackData

typedef struct {
  struct {
    struct4_T fzg_array_struct;
  } f0;
} clcDP_portStackData;

#endif                                 /*typedef_clcDP_portStackData*/

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

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

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

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

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

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T disFlg;
  real_T wayStp;
  real_T engKinBegInx;
  real_T batEngStp;
  real_T batEngBeg;
  real_T batPwrAux;
  real_T psiBatEng;
  real_T psiTim;
  real_T staChgPenCosVal;
  real_T wayInxBeg;
  real_T wayInxEnd;
  real_T staBeg;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T staNum;
  real_T wayNum;
  real_T engKinNum;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T vehVelMin;
  real_T vehVelMax;
  real_T vehAccMax;
  real_T vehAccMin;
  real_T drgCof;
  real_T vehMas;
  real_T whlRosResCof;
  real_T whlDrr;
  real_T batRstChr;
  real_T batRstDch;
  real_T batEngMax;
  real_T batPwrMax;
  real_T batPwrMin;
  real_T geaEfy;
  real_T fulDen;
  real_T fulLhv;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T slpVec_wayInx[800];
  real_T engKinMat_engKinInx_wayInx[8800];
  real_T engKinNumVec_wayInx[800];
} struct3_T;

#endif                                 /*typedef_struct3_T*/
#endif

/* End of code generation (clcDP_port_types.h) */
