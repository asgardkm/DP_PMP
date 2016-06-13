/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myMult_api.c
 *
 * Code generation for function '_coder_myMult_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myMult.h"
#include "_coder_myMult_api.h"
#include "myMult_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b, const
  char_T *identifier))[20];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[20];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[12];
static const mxArray *emlrt_marshallOut(const real_T u[15]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[20];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b,
  const char_T *identifier))[20]
{
  real_T (*y)[20];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(b), &thisId);
  emlrtDestroyArray(&b);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[20]
{
  real_T (*y)[20];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  real_T (*ret)[12];
  int32_T iv2[2];
  int32_T i3;
  for (i3 = 0; i3 < 2; i3++) {
    iv2[i3] = 3 + i3;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv2);
  ret = (real_T (*)[12])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[12]
{
  real_T (*y)[12];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a), &thisId);
  emlrtDestroyArray(&a);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[15])
{
  const mxArray *y;
  static const int32_T iv0[2] = { 0, 0 };

  const mxArray *m0;
  static const int32_T iv1[2] = { 3, 5 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u);
  emlrtSetDimensions((mxArray *)m0, iv1, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[20]
{
  real_T (*ret)[20];
  int32_T iv3[2];
  int32_T i4;
  for (i4 = 0; i4 < 2; i4++) {
    iv3[i4] = 4 + i4;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3);
  ret = (real_T (*)[20])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void myMult_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  real_T (*c)[15];
  real_T (*a)[12];
  real_T (*b)[20];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  c = (real_T (*)[15])mxMalloc(sizeof(real_T [15]));

  /* Marshall function inputs */
  a = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");
  b = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "b");

  /* Invoke the target function */
  myMult(*a, *b, *c);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*c);
}

/* End of code generation (_coder_myMult_api.c) */
