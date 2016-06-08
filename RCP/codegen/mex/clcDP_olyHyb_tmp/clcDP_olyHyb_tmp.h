/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_olyHyb_tmp.h
 *
 * Code generation for function 'clcDP_olyHyb_tmp'
 *
 */

#ifndef __CLCDP_OLYHYB_TMP_H__
#define __CLCDP_OLYHYB_TMP_H__

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
#include "clcDP_olyHyb_tmp_types.h"

/* Function Declarations */
extern void clcDP_olyHyb_tmp(const emlrtStack *sp, real_T disFlg, real_T wayStp,
  real_T batEngStp, real_T batEngBeg, real_T batPwrAux, real_T psiBatEng, real_T
  psiTim, real_T staChgPenCosVal, real_T wayInxBeg, real_T wayInxEnd, real_T
  engKinBegInx, real_T engKinNum, real_T staNum, real_T wayNum, real_T staBeg,
  const emxArray_real_T *engKinNumVec_wayInx, const emxArray_real_T
  *slpVec_wayInx, const emxArray_real_T *engKinMat_engKinInx_wayInx, const
  struct0_T *FZG, emxArray_real_T *optPreInxTn3, emxArray_real_T *batFrcOptTn3,
  emxArray_real_T *fulEngOptTn3, emxArray_real_T *cos2goActMat);
extern void clcDP_olyHyb_tmp_init(void);
extern void geaNum_not_empty_init(void);
extern void iceFlg_not_empty_init(void);
extern void vehAccMax_not_empty_init(void);
extern void vehAccMin_not_empty_init(void);
extern void vehMas_not_empty_init(void);

#endif

/* End of code generation (clcDP_olyHyb_tmp.h) */
