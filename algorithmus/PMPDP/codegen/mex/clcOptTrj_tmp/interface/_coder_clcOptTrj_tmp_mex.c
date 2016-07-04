/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcOptTrj_tmp_mex.c
 *
 * Code generation for function '_coder_clcOptTrj_tmp_mex'
 *
 */

/* Include files */
#include "clcOptTrj_tmp.h"
#include "_coder_clcOptTrj_tmp_mex.h"
#include "clcOptTrj_tmp_terminate.h"
#include "_coder_clcOptTrj_tmp_api.h"
#include "clcOptTrj_tmp_initialize.h"
#include "clcOptTrj_tmp_data.h"

/* Function Declarations */
static void clcOptTrj_tmp_mexFunction(int32_T nlhs, mxArray *plhs[7], int32_T
  nrhs, const mxArray *prhs[15]);

/* Function Definitions */
static void clcOptTrj_tmp_mexFunction(int32_T nlhs, mxArray *plhs[7], int32_T
  nrhs, const mxArray *prhs[15])
{
  int32_T n;
  const mxArray *inputs[15];
  const mxArray *outputs[7];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 15, 4,
                        13, "clcOptTrj_tmp");
  }

  if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "clcOptTrj_tmp");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  clcOptTrj_tmp_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  clcOptTrj_tmp_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(clcOptTrj_tmp_atexit);

  /* Module initialization. */
  clcOptTrj_tmp_initialize();

  /* Dispatch the entry-point. */
  clcOptTrj_tmp_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_clcOptTrj_tmp_mex.c) */
