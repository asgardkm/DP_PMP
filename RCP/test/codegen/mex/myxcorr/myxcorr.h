/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myxcorr.h
 *
 * Code generation for function 'myxcorr'
 *
 */

#ifndef __MYXCORR_H__
#define __MYXCORR_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "myxcorr_types.h"

/* Function Declarations */
extern void myxcorr(const emlrtStack *sp, const real_T x[512], const real_T y
                    [512], real_T C[51], real_T Lags[51]);

#endif

/* End of code generation (myxcorr.h) */
