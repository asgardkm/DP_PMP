/*
 * codegen_interp2.c
 *
 * Code generation for function 'codegen_interp2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "codegen_interp2.h"
#include "clcDP_focus_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtBCInfo oe_emlrtBCI = { -1, -1, 42, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 36, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 35, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo se_emlrtBCI = { 1, 66, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 27, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 25, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo we_emlrtBCI = { 1, 66, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ye_emlrtBCI = { 1, 66, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 46, 15, "Z", "codegen_interp2",
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
  int32_T i10;
  int32_T i11;

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
    i10 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &gc_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i10, 1, 66, &ye_emlrtBCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &fc_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &xe_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i10 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &ec_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i10, 1, 66, &we_emlrtBCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &dc_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &ve_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &cc_emlrtDCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &bc_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &ue_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &ac_emlrtDCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &yb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &te_emlrtBCI, sp);
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
    i10 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &xb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i10, 1, 66, &se_emlrtBCI, sp);
    i10 = Z->size[1];
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(idyi, &wb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &re_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &vb_emlrtDCI, sp);
    i10 = Z->size[1];
    i11 = (int32_T)idyi;
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &qe_emlrtBCI, sp);
    Zi = Z->data[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + Z->size[0] *
                  ((int32_T)idyi - 1)) - 1] * (muDoubleScalarCeil(idxi) - idxi)
      + Z->data[((int32_T)muDoubleScalarCeil(idxi) + Z->size[0] * ((int32_T)idyi
      - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) - idxi));
  } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (idyi /
              muDoubleScalarCeil(idyi) != 1.0)) {
    emlrtIntegerCheckFastR2012b(idxi, &ub_emlrtDCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &tb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &pe_emlrtBCI, sp);
    i10 = Z->size[1];
    d1 = muDoubleScalarCeil(idyi);
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &sb_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &oe_emlrtBCI, sp);
    Zi = Z->data[((int32_T)idxi + Z->size[0] * ((int32_T)(muDoubleScalarCeil
      (idyi) - 1.0) - 1)) - 1] * (muDoubleScalarCeil(idyi) - idyi) + Z->data
      [((int32_T)idxi + Z->size[0] * ((int32_T)muDoubleScalarCeil(idyi) - 1)) -
      1] * (1.0 - (muDoubleScalarCeil(idyi) - idyi));
  } else {
    i10 = Z->size[1];
    i11 = (int32_T)emlrtIntegerCheckFastR2012b(idyi, &ic_emlrtDCI, sp);
    Zi = Z->data[((int32_T)emlrtIntegerCheckFastR2012b(idxi, &hc_emlrtDCI, sp) +
                  Z->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10,
      &af_emlrtBCI, sp) - 1)) - 1];
  }

  return Zi;
}

/* End of code generation (codegen_interp2.c) */
