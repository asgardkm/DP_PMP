/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1q.c
 *
 * Code generation for function 'interp1q'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "interp1q.h"
#include <stdio.h>

/* Function Definitions */
real_T interp1q(const real_T x[100], const real_T y[100], real_T xi)
{
  real_T yi;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  real_T r;
  yi = rtNaN;
  if ((xi >= x[0]) && (xi <= x[99])) {
    low_i = 1;
    low_ip1 = 2;
    high_i = 100;
    while (high_i > low_ip1) {
      mid_i = low_i + high_i;
      if (mid_i >= 0) {
        mid_i = (int32_T)((uint32_T)mid_i >> 1);
      } else {
        mid_i = (int32_T)~(~(uint32_T)mid_i >> 1);
      }

      if (xi >= x[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    r = (xi - x[low_i - 1]) / (x[low_i] - x[low_i - 1]);
    if (y[low_i - 1] == y[low_i]) {
      yi = y[low_i - 1];
    } else {
      yi = (1.0 - r) * y[low_i - 1] + r * y[low_i];
    }
  }

  return yi;
}

/* End of code generation (interp1q.c) */
