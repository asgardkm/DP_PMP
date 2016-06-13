/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myxcorr_initialize.c
 *
 * Code generation for function 'myxcorr_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myxcorr.h"
#include "myxcorr_initialize.h"
#include "myxcorr_data.h"

/* Function Definitions */
void myxcorr_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Signal_Toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (myxcorr_initialize.c) */
