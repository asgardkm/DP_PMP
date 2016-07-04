/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_port.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

#ifndef __CLCDP_PORT_H__
#define __CLCDP_PORT_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern void clcDP_port(const struct0_T *inputparams, const struct1_T *testparams,
  const struct2_T *fahrparams, const struct3_T *tst_array_struct, const
  struct4_T *fzg_array_struct, emxArray_real_T *engKinOptVec, emxArray_real_T
  *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec, emxArray_real_T *staVec,
  emxArray_real_T *psiEngKinOptVec, double *fulEngOpt, boolean_T *resVld);

#endif

/*
 * File trailer for clcDP_port.h
 *
 * [EOF]
 */
