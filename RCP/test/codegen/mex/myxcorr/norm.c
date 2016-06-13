/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myxcorr.h"
#include "norm.h"

/* Function Definitions */
real_T norm(const real_T x[512])
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  n_t = (ptrdiff_t)512;
  incx_t = (ptrdiff_t)1;
  return dnrm2(&n_t, &x[0], &incx_t);
}

/* End of code generation (norm.c) */
