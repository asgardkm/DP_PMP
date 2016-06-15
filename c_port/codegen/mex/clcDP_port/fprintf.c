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
#include "clcDP_port.h"
#include "fprintf.h"
#include "clcDP_port_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo x_emlrtRSI = { 38, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo c_emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo qb_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp);
static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2);
static real_T k_fprintf(const emlrtStack *sp);

/* Function Definitions */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[5];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m12, 5, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i0;
  static const char_T cv0[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *m1;
  static const char_T formatSpec[37] = { '-', 'L', 'o', 'a', 'd', 'i', 'n', 'g',
    ' ', 'm', 'o', 'd', 'e', 'l', ' ', 'd', 'a', 't', 'a', ' ', 'a', 'n', 'd',
    ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', '.', '.', '.' };

  char_T b_u[37];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 37 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i0 = 0; i0 < 7; i0++) {
    u[i0] = cv0[i0];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i0 = 0; i0 < 37; i0++) {
    b_u[i0] = formatSpec[i0];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 37, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  st.site = &qb_emlrtRSI;
  return m_emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &c_emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp)
{
  int32_T i1;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *m2;
  static const char_T formatSpec[7] = { 'd', 'o', 'n', 'e', '!', '\\', 'n' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 7 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i1 = 0; i1 < 7; i1++) {
    u[i1] = cv1[i1];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  for (i1 = 0; i1 < 7; i1++) {
    b_u[i1] = formatSpec[i1];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  st.site = &qb_emlrtRSI;
  return m_emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &c_emlrtMCI), "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m11, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp)
{
  int32_T i2;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 7 };

  const mxArray *m3;
  static const char_T formatSpec[24] = { '-', 'I', 'n', 'i', 't', 'i', 'a', 'l',
    'i', 'z', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', 'l', '.', '.', '.', '\\',
    'n' };

  char_T b_u[24];
  const mxArray *b_y;
  static const int32_T iv5[2] = { 1, 24 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 7; i2++) {
    u[i2] = cv2[i2];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  for (i2 = 0; i2 < 24; i2++) {
    b_u[i2] = formatSpec[i2];
  }

  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 24, m3, &b_u[0]);
  emlrtAssign(&b_y, m3);
  st.site = &qb_emlrtRSI;
  return m_emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &c_emlrtMCI), "feval");
}

static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2)
{
  int32_T i17;
  static const char_T cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *m4;
  static const char_T formatSpec[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e',
    ' ', '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e',
    't', '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's',
    'c', 'h', 'a', 'f', 'f', 't', '.', ' ', '\\', 'r' };

  char_T b_u[48];
  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 48 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i17 = 0; i17 < 7; i17++) {
    u[i17] = cv4[i17];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  for (i17 = 0; i17 < 48; i17++) {
    b_u[i17] = formatSpec[i17];
  }

  b_y = NULL;
  m4 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 48, m4, &b_u[0]);
  emlrtAssign(&b_y, m4);
  st.site = &qb_emlrtRSI;
  return m_emlrt_marshallIn(&st, b_feval(&st, y, emlrt_marshallOut(1.0), b_y,
    emlrt_marshallOut(varargin_1), emlrt_marshallOut(varargin_2), &c_emlrtMCI),
    "feval");
}

static real_T k_fprintf(const emlrtStack *sp)
{
  int32_T i57;
  static const char_T cv5[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 7 };

  const mxArray *m6;
  static const char_T formatSpec[11] = { '\\', 'n', '\\', 'n', 'd', 'o', 'n',
    'e', '!', '\\', 'n' };

  char_T b_u[11];
  const mxArray *b_y;
  static const int32_T iv12[2] = { 1, 11 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i57 = 0; i57 < 7; i57++) {
    u[i57] = cv5[i57];
  }

  y = NULL;
  m6 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 7, m6, &u[0]);
  emlrtAssign(&y, m6);
  for (i57 = 0; i57 < 11; i57++) {
    b_u[i57] = formatSpec[i57];
  }

  b_y = NULL;
  m6 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 11, m6, &b_u[0]);
  emlrtAssign(&b_y, m6);
  st.site = &qb_emlrtRSI;
  return m_emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &c_emlrtMCI), "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  c_fprintf(&st);
}

void d_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  e_fprintf(&st);
}

void f_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  g_fprintf(&st);
}

void h_fprintf(const emlrtStack *sp, real_T formatSpec, real_T varargin_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  i_fprintf(&st, formatSpec, varargin_1);
}

void j_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  k_fprintf(&st);
}

/* End of code generation (fprintf.c) */
