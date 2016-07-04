/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcOptTrj_tmp.h
 *
 * Code generation for function 'clcOptTrj_tmp'
 *
 */

#ifndef __CLCOPTTRJ_TMP_H__
#define __CLCOPTTRJ_TMP_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "clcOptTrj_tmp_types.h"

/* Function Declarations */
extern void clcOptTrj_tmp(const emlrtStack *sp, real_T disFlg, real_T wayStp,
  real_T wayNum, real_T wayInxBeg, real_T wayInxEnd, real_T staEnd, real_T
  engKinNum, real_T engKinEndInxVal, real_T staNum, const emxArray_real_T
  *engKinNumVec_wayInx, const emxArray_real_T *engKinMat_engKinInx_wayInx, const
  real_T optPreInxTn3[52800], const real_T batFrcOptTn3[52800], const real_T
  fulEngOptTn3[52800], const real_T cos2goActMat[66], emxArray_real_T
  *engKinOptVec, emxArray_real_T *batEngDltOptVec, emxArray_real_T
  *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
  real_T *fulEngOpt, real_T *engKinEndInx);

#endif

/* End of code generation (clcOptTrj_tmp.h) */
