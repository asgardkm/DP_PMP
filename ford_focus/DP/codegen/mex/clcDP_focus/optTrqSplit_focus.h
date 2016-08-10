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
extern void optTrqSplit_focus(const emlrtStack *sp, real_T brkBool, real_T
  batPwr, real_T batOcvPre, real_T batRst, real_T crsSpdPre, real_T crsTrqPre,
  real_T emoTrqMinPos, real_T emoTrqMaxPos, real_T emoPwrMinPos, real_T
  emoPwrMaxPos, real_T iceTrqMaxPos, real_T iceTrqMinPos, real_T crsSpdHybMax,
  real_T crsSpdHybMin, real_T timStp, real_T batPwrAux, const real_T vehVelVec[2],
  const struct2_T *fzg_scalar_struct, const struct3_T *fzg_array_struct, real_T *
  fulEng, real_T *emoTrq, real_T *iceTrq, real_T *brkTrq);

#endif

/* End of code generation (optTrqSplit_focus.h) */
