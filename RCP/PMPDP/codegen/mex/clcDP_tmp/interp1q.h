/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1q.h
 *
 * Code generation for function 'interp1q'
 *
 */

#ifndef __INTERP1Q_H__
#define __INTERP1Q_H__

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
#include "clcDP_tmp_types.h"

/* Function Declarations */
extern real_T interp1q(const real_T x[100], const real_T y[100], real_T xi);

#ifdef __WATCOMC__

#pragma aux interp1q value [8087];

#endif
#endif

/* End of code generation (interp1q.h) */
