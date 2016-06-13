/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: interp1q.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "interp1q.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const double x[100]
 *                const double y[100]
 *                double xi
 * Return Type  : double
 */
double interp1q(const double x[100], const double y[100], double xi)
{
  double yi;
  int low_i;
  int low_ip1;
  int high_i;
  int mid_i;
  double r;
  yi = rtNaN;
  if ((xi >= x[0]) && (xi <= x[99])) {
    low_i = 1;
    low_ip1 = 2;
    high_i = 100;
    while (high_i > low_ip1) {
      mid_i = (low_i + high_i) >> 1;
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

/*
 * File trailer for interp1q.c
 *
 * [EOF]
 */
