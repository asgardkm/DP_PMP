/*
 * codegen_interp2.c
 *
 * Code generation for function 'codegen_interp2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus_useGeaVec.h"
#include "codegen_interp2.h"
#include "clcDP_focus_useGeaVec_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtBCInfo od_emlrtBCI = { -1, -1, 42, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 36, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 35, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { 1, 66, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 27, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 25, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo wd_emlrtBCI = { 1, 66, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { 1, 66, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 46, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

/* Function Definitions */
real_T codegen_interp2(const emlrtStack *sp, const real_T X[73], const real_T Y
  [66], const emxArray_real_T *Z, real_T xi, real_T yi)
{
  real_T Zi;
  real_T idyi;
  real_T idxi;
  real_T d1;
  int32_T i5;
  int32_T i6;

  /*  zi = codegen_interp2(X,Y,Z,xi,yi) gives the same result as */
  /*  interp2(X,Y,Z,xi,yi) */
  /*  Unlike interp2, codegen_interp2 is compatible with code generation */
  /*  Only linear interpolation is available */
  /*  Usage restrictions */
  /*    X and Y must have the same size as Z */
  /*    e.g.,  [X,Y] = meshgrid(x,y); */
  idyi = (xi - X[0]) * (1.0 / (X[1] - X[0])) + 1.0;
  idxi = (yi - Y[0]) * (1.0 / (Y[1] - Y[0])) + 1.0;
  if ((idxi <= 1.0) || (idyi <= 1.0) || (idxi > 66.0) || (idyi > 73.0) ||
      muDoubleScalarIsNaN(xi) || muDoubleScalarIsNaN(yi)) {
    Zi = rtInf;
  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
              muDoubleScalarCeil(idyi) != 1.0)) {
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i5 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &bc_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, 66, &yd_emlrtBCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &ac_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &xd_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i5 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &yb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, 66, &wd_emlrtBCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &xb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &vd_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &wb_emlrtDCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &vb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &ud_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &ub_emlrtDCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &tb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &td_emlrtBCI, sp);
    Zi = ((Z->data[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + Z->size[0] *
                    ((int32_T)(muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] *
           (muDoubleScalarCeil(idxi) - idxi) * (muDoubleScalarCeil(idyi) - idyi)
           + Z->data[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + Z->size[0] *
                      ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] *
           (muDoubleScalarCeil(idxi) - idxi) * (1.0 - (muDoubleScalarCeil(idyi)
             - idyi))) + Z->data[((int32_T)muDoubleScalarCeil(idxi) + Z->size[0]
           * ((int32_T)(muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] * (1.0 -
           (muDoubleScalarCeil(idxi) - idxi)) * (muDoubleScalarCeil(idyi) - idyi))
      + Z->data[((int32_T)muDoubleScalarCeil(idxi) + Z->size[0] * ((int32_T)
      muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) -
      idxi)) * (1.0 - (muDoubleScalarCeil(idyi) - idyi));
  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
              muDoubleScalarCeil(idyi) == 1.0)) {
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i5 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &sb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, 66, &sd_emlrtBCI, sp);
    i5 = Z->size[1];
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(idyi, &rb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &rd_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &qb_emlrtDCI, sp);
    i5 = Z->size[1];
    i6 = (int32_T)idyi;
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &qd_emlrtBCI, sp);
    Zi = Z->data[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + Z->size[0] *
                  ((int32_T)idyi - 1)) - 1] * (muDoubleScalarCeil(idxi) - idxi)
      + Z->data[((int32_T)muDoubleScalarCeil(idxi) + Z->size[0] * ((int32_T)idyi
      - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) - idxi));
  } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (idyi /
              muDoubleScalarCeil(idyi) != 1.0)) {
    emlrtIntegerCheckFastR2012b(idxi, &pb_emlrtDCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &ob_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &pd_emlrtBCI, sp);
    i5 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &nb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5, &od_emlrtBCI, sp);
    Zi = Z->data[((int32_T)idxi + Z->size[0] * ((int32_T)(muDoubleScalarCeil
      (idyi) - 1.0) - 1)) - 1] * (muDoubleScalarCeil(idyi) - idyi) + Z->data
      [((int32_T)idxi + Z->size[0] * ((int32_T)muDoubleScalarCeil(idyi) - 1)) -
      1] * (1.0 - (muDoubleScalarCeil(idyi) - idyi));
  } else {
    i5 = Z->size[1];
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(idyi, &dc_emlrtDCI, sp);
    Zi = Z->data[((int32_T)emlrtIntegerCheckFastR2012b(idxi, &cc_emlrtDCI, sp) +
                  Z->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
      &ae_emlrtBCI, sp) - 1)) - 1];
  }

  return Zi;
}

/* End of code generation (codegen_interp2.c) */
