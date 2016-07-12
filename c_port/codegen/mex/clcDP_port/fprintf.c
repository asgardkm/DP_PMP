/*
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
static emlrtRSInfo e_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo w_emlrtRSI = { 38, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo qb_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp);

/* Function Definitions */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[5];
  const mxArray *m13;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m13, 5, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *m0;
  char_T cv0[7];
  int32_T i;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 24 };

  char_T cv2[24];
  static const char_T cv3[24] = { '-', 'I', 'n', 'i', 't', 'i', 'a', 'l', 'i',
    'z', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', 'l', '.', '.', '.', '\\', 'n' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  for (i = 0; i < 7; i++) {
    cv0[i] = cv1[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m0, cv0);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  for (i = 0; i < 24; i++) {
    cv2[i] = cv3[i];
  }

  emlrtInitCharArrayR2013a(sp, 24, m0, cv2);
  emlrtAssign(&b_y, m0);
  st.site = &qb_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2)
{
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *m3;
  char_T cv10[7];
  int32_T i;
  static const char_T cv11[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 48 };

  char_T cv12[48];
  static const char_T cv13[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e', ' ',
    '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e', 't',
    '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's', 'c',
    'h', 'a', 'f', 'f', 't', '.', ' ', '\\', 'r' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m3 = emlrtCreateCharArray(2, iv8);
  for (i = 0; i < 7; i++) {
    cv10[i] = cv11[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m3, cv10);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv9);
  for (i = 0; i < 48; i++) {
    cv12[i] = cv13[i];
  }

  emlrtInitCharArrayR2013a(sp, 48, m3, cv12);
  emlrtAssign(&b_y, m3);
  st.site = &qb_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, emlrt_marshallOut(1.0), b_y,
    emlrt_marshallOut(varargin_1), emlrt_marshallOut(varargin_2), &emlrtMCI),
    "feval");
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c_feval), &thisId);
  emlrtDestroyArray(&c_feval);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv19[2] = { 1, 7 };

  const mxArray *m6;
  char_T cv25[7];
  int32_T i;
  static const char_T cv26[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  static const int32_T iv20[2] = { 1, 11 };

  char_T cv27[11];
  static const char_T cv28[11] = { '\\', 'n', '\\', 'n', 'd', 'o', 'n', 'e', '!',
    '\\', 'n' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m6 = emlrtCreateCharArray(2, iv19);
  for (i = 0; i < 7; i++) {
    cv25[i] = cv26[i];
  }

  emlrtInitCharArrayR2013a(sp, 7, m6, cv25);
  emlrtAssign(&y, m6);
  b_y = NULL;
  m6 = emlrtCreateCharArray(2, iv20);
  for (i = 0; i < 11; i++) {
    cv27[i] = cv28[i];
  }

  emlrtInitCharArrayR2013a(sp, 11, m6, cv27);
  emlrtAssign(&b_y, m6);
  st.site = &qb_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &emlrtMCI), "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  c_fprintf(&st);
}

void d_fprintf(const emlrtStack *sp, real_T formatSpec, real_T varargin_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  e_fprintf(&st, formatSpec, varargin_1);
}

void f_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  g_fprintf(&st);
}

/* End of code generation (fprintf.c) */
