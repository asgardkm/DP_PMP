/*
 * clcDP_port_mexutil.c
 *
 * Code generation for function 'clcDP_port_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcDP_port_mexutil.h"
#include "fprintf.h"
#include <stdio.h>

/* Function Definitions */
real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

const mxArray *b_message(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m12;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m12, 1, &pArray, "message", true,
    location);
}

const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m7;
  y = NULL;
  m7 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m7);
  return y;
}

void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

real_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/* End of code generation (clcDP_port_mexutil.c) */
