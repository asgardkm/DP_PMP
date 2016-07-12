/*
 * eml_error.c
 *
 * Code generation for function 'eml_error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "eml_error.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = { 20, 5, "eml_error",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_error.m"
};

/* Function Definitions */
void eml_error(const emlrtStack *sp)
{
  static const char_T varargin_1[4] = { 's', 'q', 'r', 't' };

  emlrtErrorWithMessageIdR2012b(sp, &u_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, varargin_1);
}

/* End of code generation (eml_error.c) */
