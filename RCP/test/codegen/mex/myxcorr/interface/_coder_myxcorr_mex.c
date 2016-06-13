/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myxcorr_mex.c
 *
 * Code generation for function '_coder_myxcorr_mex'
 *
 */

/* Include files */
#include "myxcorr.h"
#include "_coder_myxcorr_mex.h"
#include "myxcorr_terminate.h"
#include "_coder_myxcorr_api.h"
#include "myxcorr_initialize.h"
#include "myxcorr_data.h"

/* Function Declarations */
static void myxcorr_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[2]);

/* Function Definitions */
static void myxcorr_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 7,
                        "myxcorr");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "myxcorr");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  myxcorr_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  myxcorr_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(myxcorr_atexit);

  /* Module initialization. */
  myxcorr_initialize();

  /* Dispatch the entry-point. */
  myxcorr_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_myxcorr_mex.c) */
