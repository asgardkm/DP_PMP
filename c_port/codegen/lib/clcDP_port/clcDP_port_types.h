/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_port_types.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

#ifndef __CLCDP_PORT_TYPES_H__
#define __CLCDP_PORT_TYPES_H__

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#include <stdio.h>
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double disFlg;
  double wayStp;
  double engKinBegInx;
  double batEngStp;
  double batEngBeg;
  double batPwrAux;
  double psiBatEng;
  double psiTim;
  double staChgPenCosVal;
  double wayInxBeg;
  double wayInxEnd;
  double staBeg;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double staNum;
  double wayNum;
  double engKinNum;
} struct1_T;

#endif                                 /*typedef_struct1_T*/




#ifndef typedef_struct1_test
#define typedef_struct1_test

struct struct1_test {
  double staNum;
  double wayNum;
  double engKinNum;
};

#endif                                 /*typedef_struct1_test*/




#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  double vehVelMin;
  double vehVelMax;
  double vehAccMax;
  double vehAccMin;
  double drgCof;
  double vehMas;
  double whlRosResCof;
  double whlDrr;
  double batRstChr;
  double batRstDch;
  double batEngMax;
  double batPwrMax;
  double batPwrMin;
  double geaEfy;
  double fulDen;
  double fulLhv;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  double slpVec_wayInx[800];
  double engKinMat_engKinInx_wayInx[8800];
  double engKinNumVec_wayInx[800];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  double batOcvCof_batEng[2];
  double geaRat[6];
  double iceSpdMgd[15000];
  double iceTrqMgd[15000];
  double iceFulPwr_iceSpd_iceTrq[15000];
  double iceTrqMaxCof[3];
  double iceTrqMinCof[3];
  double emoSpdMgd[15000];
  double emoTrqMgd[15000];
  double emoPwr_emoSpd_emoTrq[15000];
  double emoTrqMin_emoSpd[100];
  double emoTrqMax_emoSpd[100];
  double emoPwrMgd[15000];
  double emoTrq_emoSpd_emoPwr[15000];
  double emoPwrMax_emoSpd[100];
  double emoPwrMin_emoSpd[100];
} struct4_T;

#endif                                 /*typedef_struct4_T*/
#endif

/*
 * File trailer for clcDP_port_types.h
 *
 * [EOF]
 */
