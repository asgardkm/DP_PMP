/*
 * clcDP_focus_useGeaVec.h
 *
 * Code generation for function 'clcDP_focus_useGeaVec'
 *
 */

#ifndef __CLCDP_FOCUS_USEGEAVEC_H__
#define __CLCDP_FOCUS_USEGEAVEC_H__

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
#include "clcDP_focus_useGeaVec_types.h"

/* Function Declarations */
extern void batNum_not_empty_init(void);
extern void batStaMax_not_empty_init(void);
extern void batStaMin_not_empty_init(void);
extern void batStaStp_not_empty_init(void);
extern void clcDP_focus_useGeaVec(const emlrtStack *sp, real_T batEngBeg, real_T
  timNum, const real_T engStaVec_timInx[1181], const real_T batOcv[693], const
  real_T velVec[1181], const emxArray_real_T *geaStaVec, const real_T crsSpdMat
  [7086], const real_T crsTrqMat[7086], const real_T emoTrqMinPosMat[7086],
  const real_T emoTrqMaxPosMat[7086], const real_T emoPwrMinPosMat[7086], const
  real_T emoPwrMaxPosMat[7086], const real_T iceTrqMinPosMat[7086], const real_T
  iceTrqMaxPosMat[7086], const real_T batPwrMinIdxTn3[4910598], const real_T
  batPwrMaxIdxTn3[4910598], const real_T batPwrDemIdxTn3[4910598], const
  struct0_T *inputparams, const struct1_T *tst_scalar_struct, const struct2_T
  *fzg_scalar_struct, const struct3_T *fzg_array_struct, emxArray_real_T
  *optPreInxTn3, emxArray_real_T *batPwrOptTn3, emxArray_real_T *fulEngOptTn3,
  emxArray_real_T *emoTrqOptTn3, emxArray_real_T *iceTrqOptTn3, emxArray_real_T *
  brkTrqOptTn3, emxArray_real_T *cos2goActMat);
extern void crsSpdHybMax_not_empty_init(void);
extern void crsSpdHybMin_not_empty_init(void);
extern void engNum_not_empty_init(void);
extern void engStaMax_not_empty_init(void);
extern void engStaMin_not_empty_init(void);
extern void iceFlg_not_empty_init(void);

#endif

/* End of code generation (clcDP_focus_useGeaVec.h) */
