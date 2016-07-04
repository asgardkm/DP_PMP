/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_olyHyb_tmp_emxutil.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 08-Jun-2016 14:22:05
 */

#ifndef __CLCDP_OLYHYB_TMP_EMXUTIL_H__
#define __CLCDP_OLYHYB_TMP_EMXUTIL_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_olyHyb_tmp_types.h"

/* Function Declarations */
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFreeStruct_struct0_T(struct0_T *pStruct);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_struct0_T(struct0_T *pStruct);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for clcDP_olyHyb_tmp_emxutil.h
 *
 * [EOF]
 */
