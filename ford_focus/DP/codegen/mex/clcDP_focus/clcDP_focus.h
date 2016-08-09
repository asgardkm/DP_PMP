/*
 * clcDP_focus.h
 *
 * Code generation for function 'clcDP_focus'
 *
 */

#ifndef __CLCDP_FOCUS_H__
#define __CLCDP_FOCUS_H__

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
#include "clcDP_focus_types.h"

/* Function Declarations */
extern void batNum_not_empty_init(void);
extern void batStaMax_not_empty_init(void);
extern void batStaMin_not_empty_init(void);
extern void batStaStp_not_empty_init(void);
extern void clcDP_focus(const emlrtStack *sp, real_T disFlg, real_T iceFlgBool,
  real_T brkBool, real_T timStp, real_T batEngBeg, real_T batPwrAux, real_T
  staChgPenCosVal, real_T timInxBeg, real_T timInxEnd, real_T timNum, real_T
  engBeg, const real_T engStaVec_timInx[1181], real_T staBeg, const real_T
  batOcv[693], const real_T velVec[1181], const real_T crsSpdMat[7086], const
  real_T crsTrqMat[7086], const real_T emoTrqMinPosMat[7086], const real_T
  emoTrqMaxPosMat[7086], const real_T emoPwrMinPosMat[7086], const real_T
  emoPwrMaxPosMat[7086], const real_T iceTrqMinPosMat[7086], const real_T
  iceTrqMaxPosMat[7086], const real_T batPwrMinIdxTn3[4910598], const real_T
  batPwrMaxIdxTn3[4910598], const real_T batPwrDemIdxTn3[4910598], const
  struct0_T *tst_scalar_struct, const struct1_T *fzg_scalar_struct, const
  struct2_T *fzg_array_struct, emxArray_real_T *optPreInxTn4, emxArray_real_T
  *batPwrOptTn4, emxArray_real_T *fulEngOptTn4, emxArray_real_T *cos2goActTn3);
extern void crsSpdHybMax_not_empty_init(void);
extern void crsSpdHybMin_not_empty_init(void);
extern void engNum_not_empty_init(void);
extern void engStaMax_not_empty_init(void);
extern void engStaMin_not_empty_init(void);
extern void geaNum_not_empty_init(void);
extern void geaStaMax_not_empty_init(void);
extern void geaStaMin_not_empty_init(void);
extern void iceFlg_not_empty_init(void);

#endif

/* End of code generation (clcDP_focus.h) */
