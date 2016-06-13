/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcOptTrj_tmp.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 09:35:30
 */

#ifndef __CLCOPTTRJ_TMP_H__
#define __CLCOPTTRJ_TMP_H__

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcOptTrj_tmp_types.h"

/* Function Declarations */
extern void clcOptTrj_tmp(double disFlg, double wayStp, double wayNum, double
  wayInxBeg, double wayInxEnd, double staEnd, double engKinNum, double
  engKinEndInxVal, double staNum, const emxArray_real_T *engKinNumVec_wayInx,
  const emxArray_real_T *engKinMat_engKinInx_wayInx, const double optPreInxTn3
  [52800], const double batFrcOptTn3[52800], const double fulEngOptTn3[52800],
  const double cos2goActMat[66], emxArray_real_T *engKinOptVec, emxArray_real_T *
  batEngDltOptVec, emxArray_real_T *fulEngDltOptVec, emxArray_real_T *staVec,
  emxArray_real_T *psiEngKinOptVec, double *fulEngOpt, double *engKinEndInx);

#endif

/*
 * File trailer for clcOptTrj_tmp.h
 *
 * [EOF]
 */
