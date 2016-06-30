/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_olyHyb_tmp_initialize.c
 *
 * Code generation for function 'clcDP_olyHyb_tmp_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_olyHyb_tmp.h"
#include "clcDP_olyHyb_tmp_initialize.h"
#include "clcPMP_olyHyb_tmp.h"
#include "clcDP_olyHyb_tmp_data.h"
#include <stdio.h>

/* Function Declarations */
static void clcDP_olyHyb_tmp_once(void);

/* Function Definitions */
static void clcDP_olyHyb_tmp_once(void)    
{
  crsSpdEmoMax_not_empty_init();
  crsSpdHybMin_not_empty_init();
  crsSpdHybMax_not_empty_init();
  iceFlg_not_empty_init();
  vehAccMax_not_empty_init();
  vehAccMin_not_empty_init();
  vehMas_not_empty_init();
  geaNum_not_empty_init();
  clcDP_olyHyb_tmp_init();
}

void clcDP_olyHyb_tmp_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    clcDP_olyHyb_tmp_once();
  }
}

/* End of code generation (clcDP_olyHyb_tmp_initialize.c) */
