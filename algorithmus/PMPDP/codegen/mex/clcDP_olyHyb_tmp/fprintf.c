/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_olyHyb_tmp.h"
#include "fprintf.h"
#include "clcDP_olyHyb_tmp_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 38, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo o_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Declarations */
static real_T c_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location);

/* Function Definitions */
static real_T c_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2)
{
  int32_T i20;
  static const char_T cv0[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e',
    ' ', '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e',
    't', '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's',
    'c', 'h', 'a', 'f', 'f', 't', '.', ' ', '\\', 'r' };

  char_T b_u[48];
  const mxArray *c_y;
  static const int32_T iv3[2] = { 1, 48 };

  const mxArray *d_y;
  const mxArray *e_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i20 = 0; i20 < 7; i20++) {
    u[i20] = cv0[i20];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i20 = 0; i20 < 48; i20++) {
    b_u[i20] = formatSpec[i20];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 48, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  d_y = NULL;
  m0 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m0);
  e_y = NULL;
  m0 = emlrtCreateDoubleScalar(varargin_2);
  emlrtAssign(&e_y, m0);
  st.site = &o_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, d_y, e_y, &emlrtMCI),
    "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[5];
  const mxArray *m3;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m3, 5, pArrays, "feval", true, location);
}

void b_fprintf(const emlrtStack *sp, real_T formatSpec, real_T varargin_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  c_fprintf(&st, formatSpec, varargin_1);
}

/* End of code generation (fprintf.c) */
