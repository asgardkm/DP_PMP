/*
 * _coder_clcDP_port_mex.c
 *
 * Code generation for function 'clcDP_port'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_clcDP_port_api.h"
#include "clcDP_port_initialize.h"
#include "clcDP_port_terminate.h"

/* Function Declarations */
static void clcDP_port_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "clcDP_port", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void clcDP_port_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[7];
  const mxArray *inputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  clcDP_portStackData* clcDP_portStackDataLocal = (clcDP_portStackData*)mxCalloc(1,sizeof(clcDP_portStackData));
  /* Module initialization. */
  clcDP_port_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 5, mxCHAR_CLASS, 10, "clcDP_port");
  } else if (nlhs > 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 10, "clcDP_port");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  clcDP_port_api(clcDP_portStackDataLocal, inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  clcDP_port_terminate();
  mxFree(clcDP_portStackDataLocal);
}

void clcDP_port_atexit_wrapper(void)
{
   clcDP_port_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(clcDP_port_atexit_wrapper);
  /* Dispatch the entry-point. */
  clcDP_port_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_clcDP_port_mex.c) */
