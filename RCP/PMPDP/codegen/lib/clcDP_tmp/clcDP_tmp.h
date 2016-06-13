/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_tmp.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

#ifndef __CLCDP_TMP_H__
#define __CLCDP_TMP_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_tmp_types.h"

/* Function Declarations */
extern void clcDP_tmp(double disFlg, double wayStp, double batEngStp, double
                      batEngBeg, double batPwrAux, double psiBatEng, double
                      psiTim, double staChgPenCosVal, double wayInxBeg, double
                      wayInxEnd, double engKinNum, double staNum, double wayNum,
                      double staBeg, const double engKinNumVec_wayInx[800],
                      const double slpVec_wayInx[800], const double
                      engKinMat_engKinInx_wayInx[8800], const struct0_T *FZG,
                      emxArray_real_T *engKinOptVec, emxArray_real_T
                      *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
                      emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
                      double *fulEngOpt, boolean_T *resVld);

#endif

/*
 * File trailer for clcDP_tmp.h
 *
 * [EOF]
 */
