/*
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus_useGeaVec.h"
#include "fprintf.h"
#include "clcDP_focus_useGeaVec_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo eb_emlrtRSI = { 38, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo e_emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo ub_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1);
static real_T i_fprintf(const emlrtStack *sp);
static real_T k_fprintf(const emlrtStack *sp);
static real_T m_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2);

/* Function Definitions */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m13;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m13, 4, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[5];
  const mxArray *m14;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m14, 5, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv15[2] = { 1, 7 };

  const mxArray *m2;
  char_T cv12[7];
  int32_T i;
  static const char_T cv13[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 57 };

  char_T cv14[57];
  static const char_T cv15[57] = { 'N', 'O', 'T', 'E', ':', ' ', 'e', 'n', 'g',
    'i', 'n', 'e', ' ', 'b', 'r', 'a', 'k', 'i', 'n', 'g', ' ', 'i', 's', ' ',
    'o', 'c', 'c', 'u', 'r', 'i', 'n', 'g', ' ', '-', ' ', 't', 'h', 'i', 's',
    ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l',
    '!', '\\', 'n' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv15);
  for (i = 0; i < 7; i++) {
    cv12[i] = cv13[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m2, cv12);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m2);
  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv16);
  for (i = 0; i < 57; i++) {
    cv14[i] = cv15[i];
  }

  emlrtInitCharArrayR2013a(sp, 57, m2, cv14);
  emlrtAssign(&c_y, m2);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &e_emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  const mxArray *y;
  static const int32_T iv17[2] = { 1, 7 };

  const mxArray *m3;
  char_T cv16[7];
  int32_T i;
  static const char_T cv17[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv18[2] = { 1, 18 };

  char_T cv18[18];
  static const char_T cv19[18] = { ' ', ' ', ' ', 'b', 'r', 'k', 'T', 'r', 'q',
    ':', ' ', '%', '4', '.', '3', 'f', '\\', 'n' };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m3 = emlrtCreateCharArray(2, iv17);
  for (i = 0; i < 7; i++) {
    cv16[i] = cv17[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m3, cv16);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv18);
  for (i = 0; i < 18; i++) {
    cv18[i] = cv19[i];
  }

  emlrtInitCharArrayR2013a(sp, 18, m3, cv18);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m3);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &e_emlrtMCI),
    "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m12, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  const mxArray *y;
  static const int32_T iv19[2] = { 1, 7 };

  const mxArray *m4;
  char_T cv20[7];
  int32_T i;
  static const char_T cv21[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv20[2] = { 1, 27 };

  char_T cv22[27];
  static const char_T cv23[27] = { ' ', ' ', ' ', 'a', 'd', 'j', 'u', 's', 't',
    'e', 'd', ' ', 'i', 'c', 'e', 'T', 'r', 'q', ':', ' ', '%', '4', '.', '3',
    'f', '\\', 'n' };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m4 = emlrtCreateCharArray(2, iv19);
  for (i = 0; i < 7; i++) {
    cv20[i] = cv21[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m4, cv20);
  emlrtAssign(&y, m4);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m4);
  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv20);
  for (i = 0; i < 27; i++) {
    cv22[i] = cv23[i];
  }

  emlrtInitCharArrayR2013a(sp, 27, m4, cv22);
  emlrtAssign(&c_y, m4);
  d_y = NULL;
  m4 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m4);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &e_emlrtMCI),
    "feval");
}

static real_T i_fprintf(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv21[2] = { 1, 7 };

  const mxArray *m5;
  char_T cv24[7];
  int32_T i;
  static const char_T cv25[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m5 = emlrtCreateCharArray(2, iv21);
  for (i = 0; i < 7; i++) {
    cv24[i] = cv25[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m5, cv24);
  emlrtAssign(&y, m5);
  b_y = NULL;
  m5 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m5);
  c_y = NULL;
  m5 = emlrtCreateString1('.');
  emlrtAssign(&c_y, m5);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &e_emlrtMCI), "feval");
}

static real_T k_fprintf(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv22[2] = { 1, 7 };

  const mxArray *m6;
  char_T cv26[7];
  int32_T i;
  static const char_T cv27[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv23[2] = { 1, 2 };

  char_T cv28[2];
  static const char_T cv29[2] = { '\\', 'n' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m6 = emlrtCreateCharArray(2, iv22);
  for (i = 0; i < 7; i++) {
    cv26[i] = cv27[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m6, cv26);
  emlrtAssign(&y, m6);
  b_y = NULL;
  m6 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m6);
  c_y = NULL;
  m6 = emlrtCreateCharArray(2, iv23);
  for (i = 0; i < 2; i++) {
    cv28[i] = cv29[i];
  }

  emlrtInitCharArrayR2013a(sp, 2, m6, cv28);
  emlrtAssign(&c_y, m6);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &e_emlrtMCI), "feval");
}

static real_T m_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2)
{
  const mxArray *y;
  static const int32_T iv24[2] = { 1, 7 };

  const mxArray *m7;
  char_T cv30[7];
  int32_T i;
  static const char_T cv31[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv25[2] = { 1, 48 };

  char_T cv32[48];
  static const char_T cv33[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e', ' ',
    '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e', 't',
    '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's', 'c',
    'h', 'a', 'f', 'f', 't', '.', ' ', '\\', 'r' };

  const mxArray *d_y;
  const mxArray *e_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m7 = emlrtCreateCharArray(2, iv24);
  for (i = 0; i < 7; i++) {
    cv30[i] = cv31[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m7, cv30);
  emlrtAssign(&y, m7);
  b_y = NULL;
  m7 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m7);
  c_y = NULL;
  m7 = emlrtCreateCharArray(2, iv25);
  for (i = 0; i < 48; i++) {
    cv32[i] = cv33[i];
  }

  emlrtInitCharArrayR2013a(sp, 48, m7, cv32);
  emlrtAssign(&c_y, m7);
  d_y = NULL;
  m7 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m7);
  e_y = NULL;
  m7 = emlrtCreateDoubleScalar(varargin_2);
  emlrtAssign(&e_y, m7);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, c_feval(&st, y, b_y, c_y, d_y, e_y, &e_emlrtMCI),
    "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  c_fprintf(&st);
}

void d_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  e_fprintf(&st, formatSpec);
}

void f_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  g_fprintf(&st, formatSpec);
}

void h_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  i_fprintf(&st);
}

void j_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  k_fprintf(&st);
}

void l_fprintf(const emlrtStack *sp, real_T formatSpec, real_T varargin_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  m_fprintf(&st, formatSpec, varargin_1);
}

/* End of code generation (fprintf.c) */
