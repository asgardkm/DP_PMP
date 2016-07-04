/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_clcDP_olyHyb_tmp_mex.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 08-Jun-2016 14:22:05
 */

/* Include Files */
#include "_coder_clcDP_olyHyb_tmp_api.h"
#include "_coder_clcDP_olyHyb_tmp_mex.h"
#include <stdio.h>

/* Function Declarations */
static void clcDP_olyHyb_tmp_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T
  nrhs, const mxArray *prhs[19]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[4]
 *                int32_T nrhs
 *                const mxArray *prhs[19]
 * Return Type  : void
 */
static void clcDP_olyHyb_tmp_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T
  nrhs, const mxArray *prhs[19])
{
  int32_T n;
  const mxArray *inputs[19];
  const mxArray *outputs[4];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 19) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 19, 4,
                        16, "clcDP_olyHyb_tmp");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "clcDP_olyHyb_tmp");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  clcDP_olyHyb_tmp_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  clcDP_olyHyb_tmp_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(clcDP_olyHyb_tmp_atexit);

  /* Module initialization. */
  clcDP_olyHyb_tmp_initialize();

  /* Dispatch the entry-point. */
  clcDP_olyHyb_tmp_mexFunction(nlhs, plhs, nrhs, prhs);
}

/*
 * File trailer for _coder_clcDP_olyHyb_tmp_mex.c
 *
 * [EOF]
 */
