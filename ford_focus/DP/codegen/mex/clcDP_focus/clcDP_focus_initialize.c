/*
 * clcDP_focus_initialize.c
 *
 * Code generation for function 'clcDP_focus_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "clcDP_focus_initialize.h"
#include "clcDP_focus_data.h"
#include <stdio.h>

/* Function Declarations */
static void clcDP_focus_once(void);

/* Function Definitions */
static void clcDP_focus_once(void)
{
  crsSpdHybMin_not_empty_init();
  crsSpdHybMax_not_empty_init();
  batNum_not_empty_init();
  batStaMax_not_empty_init();
  batStaStp_not_empty_init();
  batStaMin_not_empty_init();
  iceFlg_not_empty_init();
  geaStaMax_not_empty_init();
  geaStaMin_not_empty_init();
  geaNum_not_empty_init();
  engStaMax_not_empty_init();
  engStaMin_not_empty_init();
  engNum_not_empty_init();
}

void clcDP_focus_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    clcDP_focus_once();
  }
}

/* End of code generation (clcDP_focus_initialize.c) */
