/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcOptTrj_port.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

#ifndef __CLCOPTTRJ_PORT_H__
#define __CLCOPTTRJ_PORT_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern void clcOptTrj_port(double wayStp, double wayNum, double wayInxBeg,
  double wayInxEnd, double engKinNum, const double engKinNumVec_wayInx[800],
  const double engKinMat_engKinInx_wayInx[8800], const emxArray_real_T
  *optPreInxTn3, const emxArray_real_T *batFrcOptTn3, const emxArray_real_T
  *fulEngOptTn3, const emxArray_real_T *cos2goActMat, emxArray_real_T
  *engKinOptVec, emxArray_real_T *batEngDltOptVec, emxArray_real_T
  *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
  double *fulEngOpt);

#endif

/*
 * File trailer for clcOptTrj_port.h
 *
 * [EOF]
 */
