/*
 * batFrcClc_port.c
 *
 * Code generation for function 'batFrcClc_port'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "batFrcClc_port.h"
#include <stdio.h>

/* Function Definitions */
real_T batFrcClc_port(real_T batPwr, real_T vel, real_T batRstDch, real_T
                      batRstChr, real_T batOcv)
{
  real_T batFrc;
  real_T batRst;
  real_T batFrcCpl_re;
  real_T yr;
  real_T yi;

  /*    Skalar - Batteriekraft (E') */
  /*           Skalar - Batterieklemmleistung */
  /*              Skalar - mittlere Geschwindigkeit im Intervall */
  /*        Skalar - Entladewiderstand */
  /*        Skalar - Ladewiderstand */
  /*            Skalar - battery open-circuit voltage */
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
  /*    calculate battery power change for path_idx. Formula derivation can be  */
  /*    found from other papers (for example, Chalmers paper) */
  batFrcCpl_re = 1.0 - 4.0 * batRst / (batOcv * batOcv) * batPwr;
  if (batFrcCpl_re < 0.0) {
    yr = 0.0;
    yi = muDoubleScalarSqrt(muDoubleScalarAbs(batFrcCpl_re));
  } else {
    yr = muDoubleScalarSqrt(batFrcCpl_re);
    yi = 0.0;
  }

  batFrcCpl_re = batOcv * batOcv * (yr - 1.0);
  yi *= batOcv * batOcv;
  yr = 2.0 * batRst * vel;
  if (yi == 0.0) {
    batFrcCpl_re /= yr;
    yr = 0.0;
  } else if (batFrcCpl_re == 0.0) {
    batFrcCpl_re = 0.0;
    yr = yi / yr;
  } else {
    batFrcCpl_re /= yr;
    yr = yi / yr;
  }

  /*  Sollte die physikalisch mögliche Batterieleistung überschritten werden, */
  /*  wird der Term unter der Wurzel negativ. In diesem Fall wird die Ausgabe */
  /*  ungültig geschrieben. */
  /*    check to make sure that the battery capacity is not exceeded (when the */
  /*    root becomes negative, the output is no longer valid) (must be on real axis) */
  if (yr != 0.0) {
  } else {
    batFrc = batFrcCpl_re;
  }

  return batFrc;
}

/* End of code generation (batFrcClc_port.c) */
