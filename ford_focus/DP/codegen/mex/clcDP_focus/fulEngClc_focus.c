/*
 * fulEngClc_focus.c
 *
 * Code generation for function 'fulEngClc_focus'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "fulEngClc_focus.h"
#include "clcDP_focus_mexutil.h"
#include "clcDP_focus_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 62, "fulEngClc_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\fulEngClc_focus.m"
};

static emlrtRSInfo gb_emlrtRSI = { 68, "interp2",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo hb_emlrtRSI = { 70, "interp2",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo ib_emlrtRSI = { 142, "interp2",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo jb_emlrtRSI = { 169, "interp2",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp2.m"
};

static emlrtRSInfo kb_emlrtRSI = { 24, "unmeshgrid",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\unmeshgrid.m"
};

/* Function Definitions */
real_T fulEngClc_focus(const emlrtStack *sp, real_T timeStp, real_T vel, real_T
  crsSpdPre, real_T iceTrq, real_T iceTrqMax, real_T
  fzg_scalar_struct_vehVelThresh, const emxArray_real_T *iceSpdMgd, const
  emxArray_real_T *iceTrqMgd, const emxArray_real_T *iceFulPwr_iceSpd_iceTrq)
{
  real_T fulEng;
  boolean_T cond;
  const mxArray *y;
  static const int32_T iv22[2] = { 1, 29 };

  const mxArray *m5;
  char_T cv24[29];
  int32_T i;
  static const char_T cv25[29] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'N', 'o', 't', 'E', 'n', 'o', 'u', 'g', 'h', 'P',
    'o', 'i', 'n', 't', 's' };

  const mxArray *b_y;
  static const int32_T iv23[2] = { 1, 40 };

  char_T cv26[40];
  static const char_T cv27[40] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'x', 'y',
    'z', 'c', 'h', 'k', ':', 'l', 'e', 'n', 'g', 't', 'h', 'X', 'A', 'n', 'd',
    'Y', 'D', 'o', 'N', 'o', 't', 'M', 'a', 't', 'c', 'h', 'S', 'i', 'z', 'e',
    'Z' };

  boolean_T guard2 = false;
  int32_T low_ip1;
  int32_T exitg2;
  const mxArray *c_y;
  static const int32_T iv24[2] = { 1, 27 };

  char_T cv28[27];
  static const char_T cv29[27] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'N', 'o', 'n', 'I', 'n', 'c', 'r', 'e', 'a', 's',
    'i', 'n', 'g' };

  boolean_T guard1 = false;
  int32_T exitg1;
  const mxArray *d_y;
  static const int32_T iv25[2] = { 1, 27 };

  int32_T high_i;
  int32_T b_i;
  int32_T b_high_i;
  int32_T mid_i;
  int32_T low_i;
  int32_T b_low_i;
  int32_T c_high_i;
  real_T rx;
  real_T qx1;
  real_T ry;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;

  /*  Skalar Kraftstoffkraft */
  /*  Skalar für die Wegschrittweite in m */
  /*  vehicular velocity */
  /*  Skalar - crankshaft speed at given path_idx */
  /*  Skalar - ice torque at given path_idx */
  /*  Skalar - max ICE torque */
  /*  struct - Fahrzeugparameter - nur skalar */
  /*  */
  /* FULENGCLC Calculating fuel consumption */
  /*  Erstellungsdatum der ersten Version 04.09.2015 - Stephan Uebel */
  /*  */
  /*  Diese Funktion berechnet den Kraftstoffverbrauch für einen gegebenen */
  /*  Wegschritt der kinetischen Energie, der Batterieenergie und des */
  /*  Antriebsstrangzustands über dem Weg. */
  /*    this function calculates fuel consumption for a given route step of */
  /*    KE, the battery energy, and drivetrain state of the current path_idx */
  /*  */
  /*  Version vom 17.02.2016 : Rotationsmassen vernachlässigt */
  /*                            ^^ neglected rotatary masses */
  /*  */
  /*  Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit) */
  /*  */
  /*  version from 1.06.2016 - removed crsTrq calculations - they are already */
  /*  done in parent function (clcPMP_olHyb_tmp) and do not change w/ each */
  /*  iteration, making the calculation here unnecessary */
  /*  */
  /*  % 06.07.2016 - replacing KE state dimension with engine control */
  /*  */
  /*  am using values from previous timeIdx (velocity, engine state), but I am */
  /*  not 100% sure why - will have to look into later. */
  /*  But older code used predecesor values as well */
  /*  */
  /*  15.05.2016 - refitting so that fuel calculations are for straight E' */
  /*  states - checks have been moved further up in loops outside this function */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing function output */
  /*    Skalar - fuel force intialization (N) */
  /* % Fuel energy calculation */
  /*  Wenn das Verbrennungsmotormoment kleiner als das minimale */
  /*  Moment ist, ist dieser in der Schubabschaltung. Das */
  /*  verbleibende Moment liefern die Bremsen */
  /*    If engine torque is less than the min torque, fuel is cut (or if */
  /*    vehicle is stationary). The remaining torque is delivered to brakes. */
  /*    - also calculate fuel force (Berechnen der Kraftstoffkraft) */
  /*        18.07.2016 - modified the less than min torque piece and moved it */
  /*        to parent function optTrqSplot_focus as part of boundary tests. */
  if (vel < muDoubleScalarAbs(fzg_scalar_struct_vehVelThresh)) {
    fulEng = 0.0;
  } else if (iceTrq > iceTrqMax) {
    fulEng = rtInf;
  } else {
    /*  calculate fuel power */
    st.site = &fb_emlrtRSI;
    b_st.site = &gb_emlrtRSI;
    if ((iceFulPwr_iceSpd_iceTrq->size[1] >= 2) &&
        (iceFulPwr_iceSpd_iceTrq->size[0] >= 2)) {
      cond = true;
    } else {
      cond = false;
    }

    c_st.site = &ib_emlrtRSI;
    if (cond) {
    } else {
      y = NULL;
      m5 = emlrtCreateCharArray(2, iv22);
      for (i = 0; i < 29; i++) {
        cv24[i] = cv25[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 29, m5, cv24);
      emlrtAssign(&y, m5);
      d_st.site = &ub_emlrtRSI;
      error(&d_st, message(&d_st, y, &f_emlrtMCI), &f_emlrtMCI);
    }

    if ((iceFulPwr_iceSpd_iceTrq->size[0] == iceTrqMgd->size[0]) &&
        (iceFulPwr_iceSpd_iceTrq->size[1] == iceSpdMgd->size[1])) {
      cond = true;
    } else {
      cond = false;
    }

    c_st.site = &jb_emlrtRSI;
    if (cond) {
    } else {
      b_y = NULL;
      m5 = emlrtCreateCharArray(2, iv23);
      for (i = 0; i < 40; i++) {
        cv26[i] = cv27[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 40, m5, cv26);
      emlrtAssign(&b_y, m5);
      d_st.site = &ub_emlrtRSI;
      error(&d_st, message(&d_st, b_y, &f_emlrtMCI), &f_emlrtMCI);
    }

    b_st.site = &hb_emlrtRSI;
    i = iceSpdMgd->size[1];
    guard2 = false;
    if (i >= 2) {
      low_ip1 = 0;
      do {
        exitg2 = 0;
        if (low_ip1 <= i - 2) {
          if (!(iceSpdMgd->data[low_ip1] < iceSpdMgd->data[1 + low_ip1])) {
            cond = false;
            exitg2 = 1;
          } else {
            low_ip1++;
          }
        } else {
          guard2 = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    } else {
      guard2 = true;
    }

    if (guard2) {
      cond = true;
    }

    c_st.site = &kb_emlrtRSI;
    if (cond) {
    } else {
      c_y = NULL;
      m5 = emlrtCreateCharArray(2, iv24);
      for (i = 0; i < 27; i++) {
        cv28[i] = cv29[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 27, m5, cv28);
      emlrtAssign(&c_y, m5);
      d_st.site = &ub_emlrtRSI;
      error(&d_st, message(&d_st, c_y, &f_emlrtMCI), &f_emlrtMCI);
    }

    b_st.site = &hb_emlrtRSI;
    i = iceTrqMgd->size[0];
    guard1 = false;
    if (i >= 2) {
      low_ip1 = 0;
      do {
        exitg1 = 0;
        if (low_ip1 <= i - 2) {
          if (!(iceTrqMgd->data[low_ip1] < iceTrqMgd->data[1 + low_ip1])) {
            cond = false;
            exitg1 = 1;
          } else {
            low_ip1++;
          }
        } else {
          guard1 = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    } else {
      guard1 = true;
    }

    if (guard1) {
      cond = true;
    }

    c_st.site = &kb_emlrtRSI;
    if (cond) {
    } else {
      d_y = NULL;
      m5 = emlrtCreateCharArray(2, iv25);
      for (i = 0; i < 27; i++) {
        cv28[i] = cv29[i];
      }

      emlrtInitCharArrayR2013a(&c_st, 27, m5, cv28);
      emlrtAssign(&d_y, m5);
      d_st.site = &ub_emlrtRSI;
      error(&d_st, message(&d_st, d_y, &f_emlrtMCI), &f_emlrtMCI);
    }

    if ((crsSpdPre >= iceSpdMgd->data[0]) && (crsSpdPre <= iceSpdMgd->
         data[iceSpdMgd->size[1] - 1]) && (iceTrq >= iceTrqMgd->data[0]) &&
        (iceTrq <= iceTrqMgd->data[iceTrqMgd->size[0] - 1])) {
      i = 1;
      low_ip1 = 2;
      high_i = iceSpdMgd->size[1];
      while (high_i > low_ip1) {
        if (i >= 0) {
          b_i = (int32_T)((uint32_T)i >> 1);
        } else {
          b_i = (int32_T)~(~(uint32_T)i >> 1);
        }

        if (high_i >= 0) {
          b_high_i = (int32_T)((uint32_T)high_i >> 1);
        } else {
          b_high_i = (int32_T)~(~(uint32_T)high_i >> 1);
        }

        mid_i = b_i + b_high_i;
        if (((i & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }

        if (crsSpdPre >= iceSpdMgd->data[mid_i - 1]) {
          i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }

      low_i = 1;
      low_ip1 = 2;
      high_i = iceTrqMgd->size[0];
      while (high_i > low_ip1) {
        if (low_i >= 0) {
          b_low_i = (int32_T)((uint32_T)low_i >> 1);
        } else {
          b_low_i = (int32_T)~(~(uint32_T)low_i >> 1);
        }

        if (high_i >= 0) {
          c_high_i = (int32_T)((uint32_T)high_i >> 1);
        } else {
          c_high_i = (int32_T)~(~(uint32_T)high_i >> 1);
        }

        mid_i = b_low_i + c_high_i;
        if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }

        if (iceTrq >= iceTrqMgd->data[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }

      rx = (crsSpdPre - iceSpdMgd->data[i - 1]) / (iceSpdMgd->data[i] -
        iceSpdMgd->data[i - 1]);
      if (iceFulPwr_iceSpd_iceTrq->data[(low_i + iceFulPwr_iceSpd_iceTrq->size[0]
           * (i - 1)) - 1] == iceFulPwr_iceSpd_iceTrq->data[(low_i +
           iceFulPwr_iceSpd_iceTrq->size[0] * i) - 1]) {
        qx1 = iceFulPwr_iceSpd_iceTrq->data[(low_i +
          iceFulPwr_iceSpd_iceTrq->size[0] * (i - 1)) - 1];
      } else {
        qx1 = (1.0 - rx) * iceFulPwr_iceSpd_iceTrq->data[(low_i +
          iceFulPwr_iceSpd_iceTrq->size[0] * (i - 1)) - 1] + rx *
          iceFulPwr_iceSpd_iceTrq->data[(low_i + iceFulPwr_iceSpd_iceTrq->size[0]
          * i) - 1];
      }

      if (iceFulPwr_iceSpd_iceTrq->data[low_i + iceFulPwr_iceSpd_iceTrq->size[0]
          * (i - 1)] == iceFulPwr_iceSpd_iceTrq->data[low_i +
          iceFulPwr_iceSpd_iceTrq->size[0] * i]) {
        rx = iceFulPwr_iceSpd_iceTrq->data[low_i + iceFulPwr_iceSpd_iceTrq->
          size[0] * (i - 1)];
      } else {
        rx = (1.0 - rx) * iceFulPwr_iceSpd_iceTrq->data[low_i +
          iceFulPwr_iceSpd_iceTrq->size[0] * (i - 1)] + rx *
          iceFulPwr_iceSpd_iceTrq->data[low_i + iceFulPwr_iceSpd_iceTrq->size[0]
          * i];
      }

      if (qx1 == rx) {
      } else {
        ry = (iceTrq - iceTrqMgd->data[low_i - 1]) / (iceTrqMgd->data[low_i] -
          iceTrqMgd->data[low_i - 1]);
        qx1 = (1.0 - ry) * qx1 + ry * rx;
      }
    } else {
      qx1 = rtNaN;
    }

    /*  since P = E/t, then E=P*t */
    fulEng = qx1 * timeStp;
  }

  /* % Ende der Funktion */
  return fulEng;
}

/* End of code generation (fulEngClc_focus.c) */
