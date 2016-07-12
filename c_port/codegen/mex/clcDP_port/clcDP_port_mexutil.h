/*
 * clcDP_port_mexutil.h
 *
 * Code generation for function 'clcDP_port_mexutil'
 *
 */

#ifndef __CLCDP_PORT_MEXUTIL_H__
#define __CLCDP_PORT_MEXUTIL_H__

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
#include "clcDP_port_types.h"

/* Function Declarations */
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

#ifdef __WATCOMC__

#pragma aux b_emlrt_marshallIn value [8087];

#endif

extern const mxArray *b_message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
extern const mxArray *emlrt_marshallOut(const real_T u);
extern void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
extern real_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#ifdef __WATCOMC__

#pragma aux t_emlrt_marshallIn value [8087];

#endif
#endif

/* End of code generation (clcDP_port_mexutil.h) */
