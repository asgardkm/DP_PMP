/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ButterFilt.c
 *
 * Code generation for function 'ButterFilt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ButterFilt.h"

/* Function Definitions */
void ButterFilt(const emlrtStack *sp, const real_T input_data[10000], real_T
                output_data[10000])
{
  real_T dbuffer[5];
  int32_T k;
  int32_T j;
  static const real_T dv0[5] = { 0.010209480791203129, 0.040837923164812516,
    0.061256884747218771, 0.040837923164812516, 0.010209480791203129 };

  static const real_T dv1[5] = { 1.0, -1.9684277869385174, 1.7358607092088851,
    -0.72447082950736208, 0.1203895998962444 };

  (void)sp;
  for (k = 0; k < 4; k++) {
    dbuffer[k + 1] = 0.0;
  }

  for (j = 0; j < 10000; j++) {
    for (k = 0; k < 4; k++) {
      dbuffer[k] = dbuffer[k + 1];
    }

    dbuffer[4] = 0.0;
    for (k = 0; k < 5; k++) {
      dbuffer[k] += input_data[j] * dv0[k];
    }

    for (k = 0; k < 4; k++) {
      dbuffer[k + 1] -= dbuffer[0] * dv1[k + 1];
    }

    output_data[j] = dbuffer[0];
  }
}

/* End of code generation (ButterFilt.c) */
