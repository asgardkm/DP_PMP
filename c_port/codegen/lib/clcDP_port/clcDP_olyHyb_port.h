/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_olyHyb_port.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

#ifndef __CLCDP_OLYHYB_PORT_H__
#define __CLCDP_OLYHYB_PORT_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern void clcDP_olyHyb_port(double disFlg, double wayStp, double batEngStp,
  double batEngBeg, double batPwrAux, double psiBatEng, double psiTim, double
  staChgPenCosVal, double wayInxBeg, double wayInxEnd, double engKinBegInx,
  double engKinNum, double staNum, double wayNum, double staBeg, const double
  engKinNumVec_wayInx[800], const double slpVec_wayInx[800], const double
  engKinMat_engKinInx_wayInx[8800], const struct2_T *fzg_scalar, const struct4_T
  *fzg_array, emxArray_real_T *optPreInxTn3, emxArray_real_T *batFrcOptTn3,
  emxArray_real_T *fulEngOptTn3, emxArray_real_T *cos2goActMat);
extern void geaNum_not_empty_init(void);

#endif

/*
 * File trailer for clcDP_olyHyb_port.h
 *
 * [EOF]
 */
