/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_tmp_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "clcDP_tmp_initialize.h"
#include "clcDP_olyHyb_tmp.h"
#include "clcPMP_olyHyb_tmp.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcDP_tmp_initialize(void)
{
  rt_InitInfAndNaN(8U);
  crsSpdHybMax_not_empty_init();
  geaNum_not_empty_init();
}

/*
 * File trailer for clcDP_tmp_initialize.c
 *
 * [EOF]
 */
