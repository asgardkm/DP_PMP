/*
 * _coder_clcDP_focus_mex.c
 *
 * Code generation for function 'clcDP_focus'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_clcDP_focus_api.h"
#include "clcDP_focus_initialize.h"
#include "clcDP_focus_terminate.h"

/* Function Declarations */
static void clcDP_focus_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "clcDP_focus", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void clcDP_focus_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[4];
  const mxArray *inputs[29];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  clcDP_focusStackData* clcDP_focusStackDataLocal = (clcDP_focusStackData*)mxCalloc(1,sizeof(clcDP_focusStackData));
  /* Module initialization. */
  clcDP_focus_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 29) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 29, mxCHAR_CLASS, 11, "clcDP_focus");
  } else if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 11, "clcDP_focus");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  clcDP_focus_api(clcDP_focusStackDataLocal, inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  clcDP_focus_terminate();
  mxFree(clcDP_focusStackDataLocal);
}

void clcDP_focus_atexit_wrapper(void)
{
   clcDP_focus_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(clcDP_focus_atexit_wrapper);
  /* Dispatch the entry-point. */
  clcDP_focus_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_clcDP_focus_mex.c) */
