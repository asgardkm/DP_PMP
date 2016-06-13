/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: myMult.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 07-Jun-2016 10:39:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "myMult.h"

/* Function Definitions */

/*
 * multiply two inputs
 * Arguments    : const double a[12]
 *                const double b[20]
 *                double c[15]
 * Return Type  : void
 */
void myMult(const double a[12], const double b[20], double c[15])
{
  int i0;
  int i1;
  int i2;
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 5; i1++) {
      c[i0 + 3 * i1] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        c[i0 + 3 * i1] += a[i0 + 3 * i2] * b[i2 + (i1 << 2)];
      }
    }
  }
}

/*
 * File trailer for myMult.c
 *
 * [EOF]
 */
