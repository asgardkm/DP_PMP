/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_olyHyb_tmp.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 11:59:29
 */

#ifndef __CLCDP_OLYHYB_TMP_H__
#define __CLCDP_OLYHYB_TMP_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_tmp_types.h"

/* Function Declarations */
extern void clcDP_olyHyb_tmp(double disFlg, double wayStp, double batEngStp,
  double batEngBeg, double batPwrAux, double psiBatEng, double psiTim, double
  staChgPenCosVal, double wayInxBeg, double wayInxEnd, double engKinNum, double
  staNum, double wayNum, double staBeg, const double engKinNumVec_wayInx[800],
  const double slpVec_wayInx[800], const double engKinMat_engKinInx_wayInx[8800],
  const struct0_T *FZG, emxArray_real_T *optPreInxTn3, emxArray_real_T
  *batFrcOptTn3, emxArray_real_T *fulEngOptTn3, emxArray_real_T *cos2goActMat);
extern void geaNum_not_empty_init(void);

#endif

/*
 * File trailer for clcDP_olyHyb_tmp.h
 *
 * [EOF]
 */
