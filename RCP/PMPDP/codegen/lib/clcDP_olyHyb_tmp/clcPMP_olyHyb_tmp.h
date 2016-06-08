/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcPMP_olyHyb_tmp.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 08-Jun-2016 14:22:05
 */

#ifndef __CLCPMP_OLYHYB_TMP_H__
#define __CLCPMP_OLYHYB_TMP_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_olyHyb_tmp_types.h"

/* Function Declarations */
extern void clcPMP_olyHyb_tmp(double engKinPre, double engKinAct, double gea,
  double slp, double batEng, double psiBatEng, double psiTim, double batPwrAux,
  double batEngStp, double wayStp, const struct0_T *par, double *cosHamMin,
  double *batFrcOut, double *fulFrcOut);
extern void crsSpdHybMax_not_empty_init(void);

#endif

/*
 * File trailer for clcPMP_olyHyb_tmp.h
 *
 * [EOF]
 */
