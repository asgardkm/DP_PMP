/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myMult.c
 *
 * Code generation for function 'myMult'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myMult.h"

/* Function Definitions */
void myMult(const real_T a[12], const real_T b[20], real_T c[15])
{
  int32_T i0;
  int32_T i1;
  int32_T i2;

  /*  multiply two inputs */
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 5; i1++) {
      c[i0 + 3 * i1] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        c[i0 + 3 * i1] += a[i0 + 3 * i2] * b[i2 + (i1 << 2)];
      }
    }
  }
}

/* End of code generation (myMult.c) */
