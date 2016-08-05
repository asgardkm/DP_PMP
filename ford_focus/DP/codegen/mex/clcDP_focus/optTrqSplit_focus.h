/*
 * optTrqSplit_focus.h
 *
 * Code generation for function 'optTrqSplit_focus'
 *
 */

#ifndef __OPTTRQSPLIT_FOCUS_H__
#define __OPTTRQSPLIT_FOCUS_H__

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
extern void crsSpdHybMax_not_empty_init(void);
extern void crsSpdHybMin_not_empty_init(void);
extern real_T optTrqSplit_focus(const emlrtStack *sp, real_T brkBool, real_T
  batPwr, real_T batOcvPre, real_T batRst, real_T crsSpdPre, real_T crsTrqPre,
  real_T emoTrqMinPos, real_T emoTrqMaxPos, real_T emoPwrMinPos, real_T
  emoPwrMaxPos, real_T iceTrqMaxPos, real_T iceTrqMinPos, real_T timeStp, const
  real_T vehVelVec[2], real_T fzg_scalar_struct_vehVelThresh, const struct2_T
  *fzg_array_struct);

#ifdef __WATCOMC__

#pragma aux optTrqSplit_focus value [8087];

#endif
#endif

/* End of code generation (optTrqSplit_focus.h) */
