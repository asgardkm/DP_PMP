/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcOptTrj_tmp_terminate.c
 *
 * Code generation for function 'clcOptTrj_tmp_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcOptTrj_tmp.h"
#include "clcOptTrj_tmp_terminate.h"
#include "clcOptTrj_tmp_data.h"

/* Function Definitions */
void clcOptTrj_tmp_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void clcOptTrj_tmp_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (clcOptTrj_tmp_terminate.c) */
