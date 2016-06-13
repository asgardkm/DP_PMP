/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_myMult_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 07-Jun-2016 10:39:18
 */

#ifndef ___CODER_MYMULT_API_H__
#define ___CODER_MYMULT_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_myMult_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void myMult(real_T a[12], real_T b[20], real_T c[15]);
extern void myMult_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void myMult_atexit(void);
extern void myMult_initialize(void);
extern void myMult_terminate(void);
extern void myMult_xil_terminate(void);

#endif

/*
 * File trailer for _coder_myMult_api.h
 *
 * [EOF]
 */
