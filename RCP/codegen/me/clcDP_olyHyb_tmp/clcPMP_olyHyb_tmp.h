/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcPMP_olyHyb_tmp.h
 *
 * Code generation for function 'clcPMP_olyHyb_tmp'
 *
 */

#ifndef __CLCPMP_OLYHYB_TMP_H__
#define __CLCPMP_OLYHYB_TMP_H__

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
extern void clcPMP_olyHyb_tmp(const emlrtStack *sp, real_T engKinPre, real_T
  engKinAct, real_T gea, real_T slp, real_T batEng, real_T psiBatEng, real_T
  psiTim, real_T batPwrAux, real_T batEngStp, real_T wayStp, const struct0_T
  *par, real_T *cosHamMin, real_T *batFrcOut, real_T *fulFrcOut);
extern void crsSpdEmoMax_not_empty_init(void);
extern void crsSpdHybMax_not_empty_init(void);
extern void crsSpdHybMin_not_empty_init(void);

#endif

/* End of code generation (clcPMP_olyHyb_tmp.h) */
