/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_clcDP_tmp_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

#ifndef ___CODER_CLCDP_TMP_API_H__
#define ___CODER_CLCDP_TMP_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_clcDP_tmp_api.h"

/* Type Definitions */
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
  real_T vehVelMin;
  real_T vehVelMax;
  real_T vehAccMax;
  real_T vehAccMin;
  real_T drgCof;
  real_T vehMas;
  real_T whlRolResCof;
  real_T whlDrr;
  real_T batRstChr;
  real_T batRstDch;
  real_T batOcvCof_batEng[2];
  real_T batEngMax;
  real_T batPwrMax;
  real_T batPwrMin;
  real_T geaRat[6];
  real_T geaEfy;
  real_T iceSpdMgd[15000];
  real_T iceTrqMgd[15000];
  real_T fulDen;
  real_T fulLhv;
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
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void clcDP_tmp(real_T disFlg, real_T wayStp, real_T batEngStp, real_T
                      batEngBeg, real_T batPwrAux, real_T psiBatEng, real_T
                      psiTim, real_T staChgPenCosVal, real_T wayInxBeg, real_T
                      wayInxEnd, real_T engKinNum, real_T staNum, real_T wayNum,
                      real_T staBeg, real_T engKinNumVec_wayInx[800], real_T
                      slpVec_wayInx[800], real_T engKinMat_engKinInx_wayInx[8800],
                      struct0_T *FZG, emxArray_real_T *engKinOptVec,
                      emxArray_real_T *batEngDltOptVec, emxArray_real_T
                      *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T
                      *psiEngKinOptVec, real_T *fulEngOpt, boolean_T *resVld);
extern void clcDP_tmp_api(const mxArray *prhs[18], const mxArray *plhs[7]);
extern void clcDP_tmp_atexit(void);
extern void clcDP_tmp_initialize(void);
extern void clcDP_tmp_terminate(void);
extern void clcDP_tmp_xil_terminate(void);

#endif

/*
 * File trailer for _coder_clcDP_tmp_api.h
 *
 * [EOF]
 */
