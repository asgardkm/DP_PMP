/*
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "eml_int_forloop_overflow_check.h"
#include "clcOptTrj_port.h"
#include "clcDP_port_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 87, 9, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo c_emlrtMCI = { 86, 15, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo xb_emlrtRSI = { 86, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo yb_emlrtRSI = { 87, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

/* Function Declarations */
static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m11, 2, pArrays, "message", true,
    location);
}

void check_forloop_overflow_error(const emlrtStack *sp)
{
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 34 };

  const mxArray *m2;
  char_T cv6[34];
  int32_T i;
  static const char_T cv7[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 5 };

  char_T cv8[5];
  static const char_T cv9[5] = { 'i', 'n', 't', '3', '2' };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  y = NULL;
  m2 = emlrtCreateCharArray(2, iv6);
  for (i = 0; i < 34; i++) {
    cv6[i] = cv7[i];
  }

  emlrtInitCharArrayR2013a(sp, 34, m2, cv6);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv7);
  for (i = 0; i < 5; i++) {
    cv8[i] = cv9[i];
  }

  emlrtInitCharArrayR2013a(sp, 5, m2, cv8);
  emlrtAssign(&b_y, m2);
  st.site = &xb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  error(&st, message(&b_st, y, b_y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
