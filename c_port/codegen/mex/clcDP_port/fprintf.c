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
static emlrtRSInfo e_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo v_emlrtRSI = { 38, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo ob_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
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
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m8, 5, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i1;
  static const char_T cv0[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *m0;
  static const char_T formatSpec[24] = { '-', 'I', 'n', 'i', 't', 'i', 'a', 'l',
    'i', 'z', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', 'l', '.', '.', '.', '\\',
    'n' };

  char_T b_u[24];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 24 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i1 = 0; i1 < 7; i1++) {
    u[i1] = cv0[i1];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i1 = 0; i1 < 24; i1++) {
    b_u[i1] = formatSpec[i1];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 24, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  st.site = &ob_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2)
{
  int32_T i21;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 7 };

  const mxArray *m1;
  static const char_T formatSpec[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e',
    ' ', '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e',
    't', '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's',
    'c', 'h', 'a', 'f', 'f', 't', '.', ' ', '\\', 'r' };

  char_T b_u[48];
  const mxArray *b_y;
  static const int32_T iv5[2] = { 1, 48 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i21 = 0; i21 < 7; i21++) {
    u[i21] = cv2[i21];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i21 = 0; i21 < 48; i21++) {
    b_u[i21] = formatSpec[i21];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 48, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  st.site = &ob_emlrtRSI;
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
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp)
{
  int32_T i61;
  static const char_T cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv7[2] = { 1, 7 };

  const mxArray *m3;
  static const char_T formatSpec[11] = { '\\', 'n', '\\', 'n', 'd', 'o', 'n',
    'e', '!', '\\', 'n' };

  char_T b_u[11];
  const mxArray *b_y;
  static const int32_T iv8[2] = { 1, 11 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i61 = 0; i61 < 7; i61++) {
    u[i61] = cv3[i61];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  for (i61 = 0; i61 < 11; i61++) {
    b_u[i61] = formatSpec[i61];
  }

  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 11, m3, &b_u[0]);
  emlrtAssign(&b_y, m3);
  st.site = &ob_emlrtRSI;
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
  st.site = &v_emlrtRSI;
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
