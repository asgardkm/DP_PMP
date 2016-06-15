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
extern void clcDP_port(clcDP_portStackData *SD, const emlrtStack *sp, real_T
  disFlg, real_T wayStp, real_T batEngStp, real_T batEngBeg, real_T batPwrAux,
  real_T psiBatEng, real_T psiTim, real_T staChgPenCosVal, real_T wayInxBeg,
  real_T wayInxEnd, real_T staBeg, emxArray_real_T *engKinOptVec,
  emxArray_real_T *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
  emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec, real_T *fulEngOpt,
  boolean_T *resVld);

#endif

/* End of code generation (clcDP_port.h) */
