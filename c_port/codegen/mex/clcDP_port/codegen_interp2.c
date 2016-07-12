/*
 * codegen_interp2.c
 *
 * Code generation for function 'codegen_interp2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "codegen_interp2.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtDCInfo k_emlrtDCI = { 42, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo nb_emlrtBCI = { 1, 100, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo l_emlrtDCI = { 41, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo m_emlrtDCI = { 41, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo n_emlrtDCI = { 36, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo o_emlrtDCI = { 35, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo ob_emlrtBCI = { 1, 150, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo p_emlrtDCI = { 35, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo q_emlrtDCI = { 27, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo r_emlrtDCI = { 27, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo pb_emlrtBCI = { 1, 100, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo s_emlrtDCI = { 26, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo t_emlrtDCI = { 26, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo u_emlrtDCI = { 25, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo qb_emlrtBCI = { 1, 150, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo v_emlrtDCI = { 25, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo rb_emlrtBCI = { 1, 100, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo w_emlrtDCI = { 24, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtBCInfo sb_emlrtBCI = { 1, 150, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 0
};

static emlrtDCInfo x_emlrtDCI = { 24, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo y_emlrtDCI = { 46, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

static emlrtDCInfo ab_emlrtDCI = { 46, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\codegen_interp2.m", 1
};

/* Function Definitions */
real_T codegen_interp2(const emlrtStack *sp, const real_T X[15000], const real_T
  Y[15000], const real_T Z[15000], real_T xi, real_T yi)
{
  real_T Zi;
  real_T idyi;
  real_T idxi;
  real_T d1;
  int32_T i6;

  /*  zi = codegen_interp2(X,Y,Z,xi,yi) gives the same result as */
  /*  interp2(X,Y,Z,xi,yi) */
  /*  Unlike interp2, codegen_interp2 is compatible with code generation */
  /*  Only linear interpolation is available */
  /*  Usage restrictions */
  /*    X and Y must have the same size as Z */
  /*    e.g.,  [X,Y] = meshgrid(x,y); */
  idyi = (xi - X[0]) * (1.0 / (X[150] - X[0])) + 1.0;
  idxi = (yi - Y[0]) * (1.0 / (Y[1] - Y[0])) + 1.0;
  if ((idxi <= 1.0) || (idyi <= 1.0) || (idxi > 150.0) || (idyi > 100.0) ||
      muDoubleScalarIsNaN(xi) || muDoubleScalarIsNaN(yi)) {
    Zi = rtInf;
  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
              muDoubleScalarCeil(idyi) != 1.0)) {
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &x_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 150, &sb_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &w_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 100, &rb_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &v_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 150, &qb_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idyi);
    emlrtIntegerCheckFastR2012b(d1, &u_emlrtDCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &t_emlrtDCI, sp);
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &s_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 100, &pb_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &r_emlrtDCI, sp);
    d1 = muDoubleScalarCeil(idyi);
    emlrtIntegerCheckFastR2012b(d1, &q_emlrtDCI, sp);
    Zi = ((Z[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)
             (muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] * (muDoubleScalarCeil
            (idxi) - idxi) * (muDoubleScalarCeil(idyi) - idyi) + Z[((int32_T)
            (muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)
             muDoubleScalarCeil(idyi) - 1)) - 1] * (muDoubleScalarCeil(idxi) -
            idxi) * (1.0 - (muDoubleScalarCeil(idyi) - idyi))) + Z[((int32_T)
           muDoubleScalarCeil(idxi) + 150 * ((int32_T)(muDoubleScalarCeil(idyi)
             - 1.0) - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) - idxi)) *
          (muDoubleScalarCeil(idyi) - idyi)) + Z[((int32_T)muDoubleScalarCeil
      (idxi) + 150 * ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 -
      (muDoubleScalarCeil(idxi) - idxi)) * (1.0 - (muDoubleScalarCeil(idyi) -
      idyi));
  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
              muDoubleScalarCeil(idyi) == 1.0)) {
    d1 = muDoubleScalarCeil(idxi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &p_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 150, &ob_emlrtBCI, sp);
    emlrtIntegerCheckFastR2012b(idyi, &o_emlrtDCI, sp);
    d1 = muDoubleScalarCeil(idxi);
    emlrtIntegerCheckFastR2012b(d1, &n_emlrtDCI, sp);
    Zi = Z[((int32_T)(muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)idyi - 1))
      - 1] * (muDoubleScalarCeil(idxi) - idxi) + Z[((int32_T)muDoubleScalarCeil
      (idxi) + 150 * ((int32_T)idyi - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi)
      - idxi));
  } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (idyi /
              muDoubleScalarCeil(idyi) != 1.0)) {
    emlrtIntegerCheckFastR2012b(idxi, &m_emlrtDCI, sp);
    d1 = muDoubleScalarCeil(idyi) - 1.0;
    i6 = (int32_T)emlrtIntegerCheckFastR2012b(d1, &l_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, 100, &nb_emlrtBCI, sp);
    d1 = muDoubleScalarCeil(idyi);
    emlrtIntegerCheckFastR2012b(d1, &k_emlrtDCI, sp);
    Zi = Z[((int32_T)idxi + 150 * ((int32_T)(muDoubleScalarCeil(idyi) - 1.0) - 1))
      - 1] * (muDoubleScalarCeil(idyi) - idyi) + Z[((int32_T)idxi + 150 *
      ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 - (muDoubleScalarCeil
      (idyi) - idyi));
  } else {
    Zi = Z[((int32_T)emlrtIntegerCheckFastR2012b(idxi, &y_emlrtDCI, sp) + 150 *
            ((int32_T)emlrtIntegerCheckFastR2012b(idyi, &ab_emlrtDCI, sp) - 1))
      - 1];
  }

  return Zi;
}

/* End of code generation (codegen_interp2.c) */
