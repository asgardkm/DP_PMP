/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_myMult_api.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 07-Jun-2016 10:39:18
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_myMult_api.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "myMult", NULL,
  false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[12]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *b
 *                const char_T *identifier
 * Return Type  : real_T (*)[20]
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[20]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[20]
{
  real_T (*y)[20];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[12]
 */
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  real_T (*ret)[12];
  int32_T iv2[2];
  int32_T i0;
  for (i0 = 0; i0 < 2; i0++) {
    iv2[i0] = 3 + i0;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv2);
  ret = (real_T (*)[12])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *a
 *                const char_T *identifier
 * Return Type  : real_T (*)[12]
 */
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
/*
 * Arguments    : const real_T u[15]
 * Return Type  : const mxArray *
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[20]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[20]
{
  real_T (*ret)[20];
  int32_T iv3[2];
  int32_T i1;
  for (i1 = 0; i1 < 2; i1++) {
    iv3[i1] = 4 + i1;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3);
  ret = (real_T (*)[20])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray *prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
  void myMult_api(const mxArray *prhs[2], const mxArray *plhs[1])
{
  real_T (*c)[15];
  real_T (*a)[12];
  real_T (*b)[20];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  c = (real_T (*)[15])mxMalloc(sizeof(real_T [15]));
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, -1);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);

  /* Marshall function inputs */
  a = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");
  b = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "b");

  /* Invoke the target function */
  myMult(*a, *b, *c);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*c);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myMult_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  myMult_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myMult_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void myMult_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_myMult_api.c
 *
 * [EOF]
 */
