/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: codegen_interp2.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 11:59:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "codegen_interp2.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const double X[15000]
 *                const double Y[15000]
 *                const double Z[15000]
 *                double xi
 *                double yi
 * Return Type  : double
 */
double codegen_interp2(const double X[15000], const double Y[15000], const
  double Z[15000], double xi, double yi)
{
  double Zi;
  double idyi;
  double idxi;

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
      rtIsNaN(xi) || rtIsNaN(yi)) {
    Zi = rtInf;
  } else if ((idxi / ceil(idxi) != 1.0) && (idyi / ceil(idyi) != 1.0)) {
    Zi = ((Z[((int)(double)(ceil(idxi) - 1.0) + 150 * ((int)(double)(ceil(idyi)
              - 1.0) - 1)) - 1] * (ceil(idxi) - idxi) * (ceil(idyi) - idyi) + Z
           [((int)(double)(ceil(idxi) - 1.0) + 150 * ((int)ceil(idyi) - 1)) - 1]
           * (ceil(idxi) - idxi) * (1.0 - (ceil(idyi) - idyi))) + Z[((int)ceil
           (idxi) + 150 * ((int)(double)(ceil(idyi) - 1.0) - 1)) - 1] * (1.0 -
           (ceil(idxi) - idxi)) * (ceil(idyi) - idyi)) + Z[((int)ceil(idxi) +
      150 * ((int)ceil(idyi) - 1)) - 1] * (1.0 - (ceil(idxi) - idxi)) * (1.0 -
      (ceil(idyi) - idyi));
  } else if ((idxi / ceil(idxi) != 1.0) && (idyi / ceil(idyi) == 1.0)) {
    Zi = Z[((int)(double)(ceil(idxi) - 1.0) + 150 * ((int)idyi - 1)) - 1] *
      (ceil(idxi) - idxi) + Z[((int)ceil(idxi) + 150 * ((int)idyi - 1)) - 1] *
      (1.0 - (ceil(idxi) - idxi));
  } else if ((idxi / ceil(idxi) == 1.0) && (idyi / ceil(idyi) != 1.0)) {
    Zi = Z[((int)idxi + 150 * ((int)(double)(ceil(idyi) - 1.0) - 1)) - 1] *
      (ceil(idyi) - idyi) + Z[((int)idxi + 150 * ((int)ceil(idyi) - 1)) - 1] *
      (1.0 - (ceil(idyi) - idyi));
  } else {
    Zi = Z[((int)idxi + 150 * ((int)idyi - 1)) - 1];
  }

  return Zi;
}

/*
 * File trailer for codegen_interp2.c
 *
 * [EOF]
 */
