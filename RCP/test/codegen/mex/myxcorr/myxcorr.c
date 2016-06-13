/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myxcorr.c
 *
 * Code generation for function 'myxcorr'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myxcorr.h"
#include "norm.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 2, "myxcorr",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\test\\myxcorr.m" };

static emlrtRSInfo b_emlrtRSI = { 52, "xcorr",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\signal\\eml\\xcorr.m" };

static emlrtRSInfo c_emlrtRSI = { 94, "xcorr",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\signal\\eml\\xcorr.m" };

static emlrtBCInfo emlrtBCI = { 1, 512, 181, 48, "", "xcorr",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\signal\\eml\\xcorr.m", 0 };

static emlrtBCInfo b_emlrtBCI = { 1, 512, 181, 35, "", "xcorr",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\signal\\eml\\xcorr.m", 0 };

/* Function Definitions */
void myxcorr(const emlrtStack *sp, const real_T x[512], const real_T y[512],
             real_T C[51], real_T Lags[51])
{
  real_T b_C[101];
  int32_T i;
  real_T s;
  int32_T jstart;
  int32_T i0;
  int32_T j;
  int32_T b_j;
  int32_T i1;
  int32_T i2;
  real_T a;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &b_emlrtRSI;
  c_st.site = &c_emlrtRSI;
  for (i = 0; i < 101; i++) {
    s = 0.0;
    if (i - 50 > 0) {
      jstart = i - 49;
    } else {
      jstart = 1;
    }

    i0 = (int32_T)muDoubleScalarMin((1.0 + (real_T)i) - -461.0, 512.0) - jstart;
    for (j = 0; j <= i0; j++) {
      b_j = jstart + j;
      i1 = (b_j - i) + 50;
      if ((i1 >= 1) && (i1 < 512)) {
        i2 = i1;
      } else {
        i2 = emlrtDynamicBoundsCheckR2012b(i1, 1, 512, &b_emlrtBCI, &c_st);
      }

      a = y[i2 - 1];
      emlrtDynamicBoundsCheckR2012b(b_j, 1, 512, &emlrtBCI, &c_st);
      s += a * x[b_j - 1];
    }

    b_C[i] = s;
  }

  s = norm(x) * norm(y);
  for (i0 = 0; i0 < 101; i0++) {
    b_C[i0] /= s;
  }

  for (i = 0; i < 51; i++) {
    C[i] = b_C[i + 50];
    Lags[i] = i;
  }
}

/* End of code generation (myxcorr.c) */
