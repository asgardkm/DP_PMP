/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myMult_mex.c
 *
 * Code generation for function '_coder_myMult_mex'
 *
 */

/* Include files */
#include "myMult.h"
#include "_coder_myMult_mex.h"
#include "myMult_terminate.h"
#include "_coder_myMult_api.h"
#include "myMult_initialize.h"
#include "myMult_data.h"

/* Function Declarations */
static void myMult_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[2]);

/* Function Definitions */
static void myMult_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 6,
                        "myMult");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "myMult");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  myMult_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  myMult_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(myMult_atexit);

  /* Module initialization. */
  myMult_initialize();

  /* Dispatch the entry-point. */
  myMult_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_myMult_mex.c) */
