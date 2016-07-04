/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcPMP_olyHyb_port.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

#ifndef __CLCPMP_OLYHYB_PORT_H__
#define __CLCPMP_OLYHYB_PORT_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern void clcPMP_olyHyb_port(double engKinPre, double engKinAct, double gea,
  double slp, double batEng, double psiBatEng, double psiTim, double batPwrAux,
  double batEngStp, double wayStp, const struct2_T *fzg_scalar, const struct4_T *
  fzg_array, double *cosHamMin, double *batFrcOut, double *fulFrcOut);
extern void crsSpdHybMax_not_empty_init(void);

#endif

/*
 * File trailer for clcPMP_olyHyb_port.h
 *
 * [EOF]
 */
