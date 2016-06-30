/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcDP_tmp_mex.c
 *
 * Code generation for function '_coder_clcDP_tmp_mex'
 *
 */

/* Include files */
#include "clcDP_tmp.h"
#include "_coder_clcDP_tmp_mex.h"
#include "clcDP_tmp_terminate.h"
#include "_coder_clcDP_tmp_api.h"
#include "clcDP_tmp_initialize.h"
#include "clcDP_tmp_data.h"
#include <stdio.h>

/* Variable Definitions */
static clcDP_tmpStackData *clcDP_tmpStackDataGlobal = NULL;

/* Function Declarations */
static void clcDP_tmp_mexFunction(clcDP_tmpStackData *SD, int32_T nlhs, mxArray *
  plhs[7], int32_T nrhs, const mxArray *prhs[18]);

/* Function Definitions */
static void clcDP_tmp_mexFunction(clcDP_tmpStackData *SD, int32_T nlhs, mxArray *
  plhs[7], int32_T nrhs, const mxArray *prhs[18])
{
  int32_T n;
  const mxArray *inputs[18];
  const mxArray *outputs[7];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 18) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 18, 4,
                        9, "clcDP_tmp");
  }

  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "clcDP_tmp");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  clcDP_tmp_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  clcDP_tmp_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  clcDP_tmpStackDataGlobal = (clcDP_tmpStackData *)mxCalloc(1, sizeof
    (clcDP_tmpStackData));

  /* Initialize the memory manager. */
  mexAtExit(clcDP_tmp_atexit);

  /* Module initialization. */
  clcDP_tmp_initialize();

  /* Dispatch the entry-point. */
  clcDP_tmp_mexFunction(clcDP_tmpStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(clcDP_tmpStackDataGlobal);
}

/* End of code generation (_coder_clcDP_tmp_mex.c) */
