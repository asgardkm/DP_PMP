/*
 * fulEngClc_focus.h
 *
 * Code generation for function 'fulEngClc_focus'
 *
 */

#ifndef __FULENGCLC_FOCUS_H__
#define __FULENGCLC_FOCUS_H__

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
#include "clcDP_focus_types.h"

/* Function Declarations */
extern real_T fulEngClc_focus(const emlrtStack *sp, real_T timeStp, real_T vel,
  real_T crsSpdPre, real_T iceTrq, real_T iceTrqMax, real_T
  fzg_scalar_struct_vehVelThresh, const emxArray_real_T *iceSpdMgd, const
  emxArray_real_T *iceTrqMgd, const emxArray_real_T *iceFulPwr_iceSpd_iceTrq);

#ifdef __WATCOMC__

#pragma aux fulEngClc_focus value [8087];

#endif
#endif

/* End of code generation (fulEngClc_focus.h) */
