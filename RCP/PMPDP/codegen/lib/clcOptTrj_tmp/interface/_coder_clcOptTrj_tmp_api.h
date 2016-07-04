/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_clcOptTrj_tmp_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 09:35:30
 */

#ifndef ___CODER_CLCOPTTRJ_TMP_API_H__
#define ___CODER_CLCOPTTRJ_TMP_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_clcOptTrj_tmp_api.h"

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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void clcOptTrj_tmp(real_T disFlg, real_T wayStp, real_T wayNum, real_T
  wayInxBeg, real_T wayInxEnd, real_T staEnd, real_T engKinNum, real_T
  engKinEndInxVal, real_T staNum, emxArray_real_T *engKinNumVec_wayInx,
  emxArray_real_T *engKinMat_engKinInx_wayInx, real_T optPreInxTn3[52800],
  real_T batFrcOptTn3[52800], real_T fulEngOptTn3[52800], real_T cos2goActMat[66],
  emxArray_real_T *engKinOptVec, emxArray_real_T *batEngDltOptVec,
  emxArray_real_T *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T
  *psiEngKinOptVec, real_T *fulEngOpt, real_T *engKinEndInx);
extern void clcOptTrj_tmp_api(const mxArray *prhs[15], const mxArray *plhs[7]);
extern void clcOptTrj_tmp_atexit(void);
extern void clcOptTrj_tmp_initialize(void);
extern void clcOptTrj_tmp_terminate(void);
extern void clcOptTrj_tmp_xil_terminate(void);

#endif

/*
 * File trailer for _coder_clcOptTrj_tmp_api.h
 *
 * [EOF]
 */
