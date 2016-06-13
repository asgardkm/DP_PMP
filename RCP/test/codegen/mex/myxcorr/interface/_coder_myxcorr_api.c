/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myxcorr_api.c
 *
 * Code generation for function '_coder_myxcorr_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myxcorr.h"
#include "_coder_myxcorr_api.h"
#include "myxcorr_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[512];
static const mxArray *b_emlrt_marshallOut(const real_T u[51]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[512];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[512];
static const mxArray *emlrt_marshallOut(const real_T u[51]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[512]
{
  real_T (*y)[512];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[51])
{
  const mxArray *y;
  static const int32_T iv2[2] = { 0, 0 };

  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 51 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u);
  emlrtSetDimensions((mxArray *)m1, iv3, 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[512]
{
  real_T (*ret)[512];
  int32_T iv4[1];
  iv4[0] = 512;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv4);
  ret = (real_T (*)[512])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[512]
{
  real_T (*y)[512];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[51])
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  static const int32_T iv1[1] = { 51 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

void myxcorr_api(const mxArray * const prhs[2], const mxArray *plhs[2])
{
  real_T (*C)[51];
  real_T (*Lags)[51];
  real_T (*x)[512];
  real_T (*y)[512];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  C = (real_T (*)[51])mxMalloc(sizeof(real_T [51]));
  Lags = (real_T (*)[51])mxMalloc(sizeof(real_T [51]));

  /* Marshall function inputs */
  x = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x");
  y = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y");

  /* Invoke the target function */
  myxcorr(&st, *x, *y, *C, *Lags);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*C);
  plhs[1] = b_emlrt_marshallOut(*Lags);
}

/* End of code generation (_coder_myxcorr_api.c) */
