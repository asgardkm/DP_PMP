/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ButterFilt_api.c
 *
 * Code generation for function '_coder_ButterFilt_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ButterFilt.h"
#include "_coder_ButterFilt_api.h"
#include "ButterFilt_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[10000];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10000];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *input_data,
  const char_T *identifier))[10000];
static const mxArray *emlrt_marshallOut(const real_T u[10000]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[10000]
{
  real_T (*y)[10000];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10000]
{
  real_T (*ret)[10000];
  int32_T iv2[1];
  iv2[0] = 10000;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv2);
  ret = (real_T (*)[10000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *input_data,
  const char_T *identifier))[10000]
{
  real_T (*y)[10000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(input_data), &thisId);
  emlrtDestroyArray(&input_data);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[10000])
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  static const int32_T iv1[1] = { 10000 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

void ButterFilt_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  real_T (*output_data)[10000];
  real_T (*input_data)[10000];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  output_data = (real_T (*)[10000])mxMalloc(sizeof(real_T [10000]));

  /* Marshall function inputs */
  input_data = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "input_data");

  /* Invoke the target function */
  ButterFilt(&st, *input_data, *output_data);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*output_data);
}

/* End of code generation (_coder_ButterFilt_api.c) */
