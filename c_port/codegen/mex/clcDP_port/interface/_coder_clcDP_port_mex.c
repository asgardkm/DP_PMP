/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcDP_port_mex.c
 *
 * Code generation for function '_coder_clcDP_port_mex'
 *
 */

/* Include files */
#include "clcDP_port.h"
#include "_coder_clcDP_port_mex.h"
#include "clcDP_port_terminate.h"
#include "_coder_clcDP_port_api.h"
#include "clcDP_port_initialize.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static clcDP_portStackData *clcDP_portStackDataGlobal = NULL;

/* Function Declarations */
static void clcDP_port_mexFunction(clcDP_portStackData *SD, int32_T nlhs,
  mxArray *plhs[7], int32_T nrhs, const mxArray *prhs[11]);

/* Function Definitions */
static void clcDP_port_mexFunction(clcDP_portStackData *SD, int32_T nlhs,
  mxArray *plhs[7], int32_T nrhs, const mxArray *prhs[11])
{
  int32_T n;
  const mxArray *inputs[11];
  const mxArray *outputs[7];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        10, "clcDP_port");
  }

  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "clcDP_port");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  clcDP_port_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  clcDP_port_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  clcDP_portStackDataGlobal = (clcDP_portStackData *)mxCalloc(1, sizeof
    (clcDP_portStackData));

  /* Initialize the memory manager. */
  mexAtExit(clcDP_port_atexit);

  /* Module initialization. */
  clcDP_port_initialize();

  /* Dispatch the entry-point. */
  clcDP_port_mexFunction(clcDP_portStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(clcDP_portStackDataGlobal);
}

/* End of code generation (_coder_clcDP_port_mex.c) */
