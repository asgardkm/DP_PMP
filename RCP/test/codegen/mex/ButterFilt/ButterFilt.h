/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ButterFilt.h
 *
 * Code generation for function 'ButterFilt'
 *
 */

#ifndef __BUTTERFILT_H__
#define __BUTTERFILT_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "ButterFilt_types.h"

/* Function Declarations */
extern void ButterFilt(const emlrtStack *sp, const real_T input_data[10000],
  real_T output_data[10000]);

#endif

/* End of code generation (ButterFilt.h) */
