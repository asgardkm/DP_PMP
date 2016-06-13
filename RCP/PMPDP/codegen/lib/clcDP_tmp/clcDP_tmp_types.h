/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_tmp_types.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

#ifndef __CLCDP_TMP_TYPES_H__
#define __CLCDP_TMP_TYPES_H__

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
  double vehVelMin;
  double vehVelMax;
  double vehAccMax;
  double vehAccMin;
  double drgCof;
  double vehMas;
  double whlRolResCof;
  double whlDrr;
  double batRstChr;
  double batRstDch;
  double batOcvCof_batEng[2];
  double batEngMax;
  double batPwrMax;
  double batPwrMin;
  double geaRat[6];
  double geaEfy;
  double iceSpdMgd[15000];
  double iceTrqMgd[15000];
  double fulDen;
  double fulLhv;
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
} struct0_T;

#endif                                 /*typedef_struct0_T*/
#endif

/*
 * File trailer for clcDP_tmp_types.h
 *
 * [EOF]
 */
