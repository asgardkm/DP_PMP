/*
 * _coder_clcDP_focus_useGeaVec_mex.c
 *
 * Code generation for function 'clcDP_focus_useGeaVec'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_clcDP_focus_useGeaVec_api.h"
#include "clcDP_focus_useGeaVec_initialize.h"
#include "clcDP_focus_useGeaVec_terminate.h"

/* Function Declarations */
static void clcDP_focus_useGeaVec_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "clcDP_focus_useGeaVec", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void clcDP_focus_useGeaVec_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[7];
  const mxArray *inputs[21];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  clcDP_focus_useGeaVec_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 21) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 21, mxCHAR_CLASS, 21, "clcDP_focus_useGeaVec");
  } else if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 21, "clcDP_focus_useGeaVec");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  clcDP_focus_useGeaVec_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  clcDP_focus_useGeaVec_terminate();
}

void clcDP_focus_useGeaVec_atexit_wrapper(void)
{
   clcDP_focus_useGeaVec_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(clcDP_focus_useGeaVec_atexit_wrapper);
  /* Dispatch the entry-point. */
  clcDP_focus_useGeaVec_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_clcDP_focus_useGeaVec_mex.c) */
