/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_port.h
 *
 * Code generation for function 'clcDP_port'
 *
 */

#ifndef __CLCDP_PORT_H__
#define __CLCDP_PORT_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern void clcDP_port(const emlrtStack *sp, const struct0_T *inputparams, const
  struct1_T *testparams, const struct2_T *fahrparams, const struct3_T
  *tst_array_struct, const struct4_T *fzg_array_struct, emxArray_real_T
  *engKinOptVec, emxArray_real_T *batEngDltOptVec, emxArray_real_T
  *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
  real_T *fulEngOpt, boolean_T *resVld);

#endif

/* End of code generation (clcDP_port.h) */
