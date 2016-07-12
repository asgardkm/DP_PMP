/*
 * clcOptTrj_port.h
 *
 * Code generation for function 'clcOptTrj_port'
 *
 */

#ifndef __CLCOPTTRJ_PORT_H__
#define __CLCOPTTRJ_PORT_H__

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
extern void clcOptTrj_port(const emlrtStack *sp, real_T wayStp, real_T wayNum,
  real_T wayInxBeg, real_T wayInxEnd, real_T engKinNum, real_T staNum, const
  real_T engKinNumVec_wayInx[800], const real_T engKinMat_engKinInx_wayInx[8800],
  const emxArray_real_T *optPreInxTn3, const emxArray_real_T *batFrcOptTn3,
  const emxArray_real_T *fulEngOptTn3, const emxArray_real_T *cos2goActMat,
  emxArray_real_T *engKinOptVec, emxArray_real_T *batEngDltOptVec,
  emxArray_real_T *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T
  *psiEngKinOptVec, real_T *fulEngOpt);

#endif

/* End of code generation (clcOptTrj_port.h) */
