/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: batFrcClc_tmp.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 11:59:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "batFrcClc_tmp.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Skalar - Batterieklemmleistung
 *              Skalar - mittlere Geschwindigkeit im Intervall
 *        Skalar - Entladewiderstand
 *        Skalar - Ladewiderstand
 *            Skalar - battery open-circuit voltage
 * Arguments    : double batPwr
 *                double vel
 *                double batRstDch
 *                double batRstChr
 *                double batOcv
 * Return Type  : double
 */
double batFrcClc_tmp(double batPwr, double vel, double batRstDch, double
                     batRstChr, double batOcv)
{
  double batFrc;
  double batRst;
  double batFrcCpl_re;
  double yr;
  double yi;
  double ar;
  double ai;
  double br;
  double batFrcCpl_im;

  /*    Skalar - Batteriekraft (E') */
  /* BATFRCCLC Calculating losses in battery */
  /*    Batteriekraft (E') aus Verlusten in der Batterie berechnen */
  /*        Calucluate battery power losses (E') */
  /*  */
  /*  Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit) */
  /*                            Zero-Order-Hold (average velocity is NOT used) */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing the function output */
  batFrc = rtInf;

  /* % Berechnung der Verluste in der Batterie */
  /*    calculating battery losses */
  /*  Berechnung der Batterieenergienderung im Wegschritt in externer Funktion */
  /*  Fallunterscheidung, ob Batterie geladen oder entladen wird */
  /*     */
  /*    calculate the change in battery energy along path_idx in exterior func,   */
  /*    distinguished whether battery is charging or discharging. */
  /*    Assining battery resistance value */
  if (batPwr > 0.0) {
    batRst = batRstDch;
  } else {
    batRst = batRstChr;
  }

  /*  Batterieenergieänderung über dem Weg berechnen. Herleitung der Formel */
  /*  kann zum Beispiel dem Paper mit Chalmers entnommen werden */
  /*    calculate battery power charge for path_idx. Formula derivation can be  */
  /*    found from other papers (for example, Chalmers paper) */
  batFrcCpl_re = 1.0 - 4.0 * batRst / (batOcv * batOcv) * batPwr;
  if (batFrcCpl_re < 0.0) {
    yr = 0.0;
    yi = sqrt(fabs(batFrcCpl_re));
  } else {
    yr = sqrt(batFrcCpl_re);
    yi = 0.0;
  }

  ar = batOcv * batOcv * (yr - 1.0);
  ai = batOcv * batOcv * yi;
  br = 2.0 * batRst * vel;
  if (ai == 0.0) {
    batFrcCpl_re = ar / br;
    batFrcCpl_im = 0.0;
  } else if (ar == 0.0) {
    batFrcCpl_re = 0.0;
    batFrcCpl_im = ai / br;
  } else {
    batFrcCpl_re = ar / br;
    batFrcCpl_im = ai / br;
  }

  /*  Sollte die physikalisch mögliche Batterieleistung überschritten werden, */
  /*  wird der Term unter der Wurzel negativ. In diesem Fall wird die Ausgabe */
  /*  ungültig geschrieben. */
  /*    check to make sure that the battery capacity is not exceeded (when the */
  /*    root becomes negative, the output is no longer valid) (Quadrants 3, 4) */
  if (batFrcCpl_im != 0.0) {
  } else {
    batFrc = batFrcCpl_re;
  }

  return batFrc;
}

/*
 * File trailer for batFrcClc_tmp.c
 *
 * [EOF]
 */
