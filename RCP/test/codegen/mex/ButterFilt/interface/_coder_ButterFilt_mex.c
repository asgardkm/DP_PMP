/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ButterFilt_mex.c
 *
 * Code generation for function '_coder_ButterFilt_mex'
 *
 */

/* Include files */
#include "ButterFilt.h"
#include "_coder_ButterFilt_mex.h"
#include "ButterFilt_terminate.h"
#include "_coder_ButterFilt_api.h"
#include "ButterFilt_initialize.h"
#include "ButterFilt_data.h"

/* Function Declarations */
static void ButterFilt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[1]);

/* Function Definitions */
static void ButterFilt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        10, "ButterFilt");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "ButterFilt");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  ButterFilt_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  ButterFilt_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(ButterFilt_atexit);

  /* Module initialization. */
  ButterFilt_initialize();

  /* Dispatch the entry-point. */
  ButterFilt_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_ButterFilt_mex.c) */
