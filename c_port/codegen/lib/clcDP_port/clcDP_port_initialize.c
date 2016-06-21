/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_port_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcDP_port_initialize.h"
#include "clcDP_olyHyb_port.h"
#include "clcPMP_olyHyb_port.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcDP_port_initialize(void)
{
  rt_InitInfAndNaN(8U);
  crsSpdHybMax_not_empty_init();
  geaNum_not_empty_init();
}

/*
 * File trailer for clcDP_port_initialize.c
 *
 * [EOF]
 */
