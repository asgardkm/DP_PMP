/*
 * clcDP_focus_mexutil.h
 *
 * Code generation for function 'clcDP_focus_mexutil'
 *
 */

#ifndef __CLCDP_FOCUS_MEXUTIL_H__
#define __CLCDP_FOCUS_MEXUTIL_H__

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
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

#ifdef __WATCOMC__

#pragma aux b_emlrt_marshallIn value [8087];

#endif

extern real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_feval,
  const char_T *identifier);

#ifdef __WATCOMC__

#pragma aux emlrt_marshallIn value [8087];

#endif

extern void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
extern real_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

#ifdef __WATCOMC__

#pragma aux fb_emlrt_marshallIn value [8087];

#endif
#endif

/* End of code generation (clcDP_focus_mexutil.h) */
