/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_tmp_mexutil.h
 *
 * Code generation for function 'clcDP_tmp_mexutil'
 *
 */

#ifndef __CLCDP_TMP_MEXUTIL_H__
#define __CLCDP_TMP_MEXUTIL_H__

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
#include "clcDP_tmp_types.h"

/* Function Declarations */
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

#ifdef __WATCOMC__

#pragma aux b_emlrt_marshallIn value [8087];

#endif

extern real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier);

#ifdef __WATCOMC__

#pragma aux emlrt_marshallIn value [8087];

#endif

extern const mxArray *emlrt_marshallOut(const real_T u);
extern real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#ifdef __WATCOMC__

#pragma aux n_emlrt_marshallIn value [8087];

#endif
#endif

/* End of code generation (clcDP_tmp_mexutil.h) */
