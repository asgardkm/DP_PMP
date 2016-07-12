/*
 * clcDP_port_initialize.c
 *
 * Code generation for function 'clcDP_port_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcDP_port_initialize.h"
#include "clcPMP_olyHyb_port.h"
#include "clcDP_olyHyb_port.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Function Declarations */
static void clcDP_port_once(void);

/* Function Definitions */
static void clcDP_port_once(void)
{
  crsSpdEmoMax_not_empty_init();
  crsSpdHybMin_not_empty_init();
  crsSpdHybMax_not_empty_init();
  iceFlg_not_empty_init();
  vehAccMax_not_empty_init();
  vehAccMin_not_empty_init();
  vehMas_not_empty_init();
  geaNum_not_empty_init();
  clcDP_olyHyb_port_init();
}

void clcDP_port_initialize(emlrtContext *aContext)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    clcDP_port_once();
  }
}

/* End of code generation (clcDP_port_initialize.c) */
