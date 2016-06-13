/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcOptTrj_tmp.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 10:26:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "clcOptTrj_tmp.h"
#include "diff.h"
#include "clcDP_tmp_emxutil.h"
#include <stdio.h>

/* Function Declarations */
static int div_s32(int numerator, int denominator);

/* Function Definitions */

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator >= 0) {
      absNumerator = (unsigned int)numerator;
    } else {
      absNumerator = (unsigned int)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (unsigned int)denominator;
    } else {
      absDenominator = (unsigned int)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int)absNumerator;
    } else {
      quotient = (int)absNumerator;
    }
  }

  return quotient;
}

/*
 * Flag, ob Zielzustand genutzt werden muss
 *               Skalar für die Wegschrittweite in m
 *               Skalar für die max. Anzahl an Wegstützstellen
 *            Skalar für Anfangsindex in den Eingangsdaten
 *            Skalar für Endindex in den Eingangsdaten
 *               Skalar für den finalen Zustand
 *            Skalar für die max. Anz. an engKin-Stützstellen
 *      Skalar für Zielindex der kinetischen Energie
 *               Skalar für die max. Anzahl an Zustandsstützstellen
 *  Vektor der Anzahl der kinetischen Energien
 *  Matrix der kinetischen Energien in J
 *         Tensor 3. Stufe für opt. Vorgängerkoordinaten
 *        Tensor 3. Stufe der Batteriekraft
 *        Tensor 3. Stufe für die Kraftstoffenergie
 *         Matrix der optimalen Kosten der Hamiltonfunktion
 * Arguments    : double wayStp
 *                double wayNum
 *                double wayInxBeg
 *                double wayInxEnd
 *                double engKinNum
 *                const double engKinNumVec_wayInx[800]
 *                const double engKinMat_engKinInx_wayInx[8800]
 *                const emxArray_real_T *optPreInxTn3
 *                const emxArray_real_T *batFrcOptTn3
 *                const emxArray_real_T *fulEngOptTn3
 *                const emxArray_real_T *cos2goActMat
 *                emxArray_real_T *engKinOptVec
 *                emxArray_real_T *batEngDltOptVec
 *                emxArray_real_T *fulEngDltOptVec
 *                emxArray_real_T *staVec
 *                emxArray_real_T *psiEngKinOptVec
 *                double *fulEngOpt
 * Return Type  : void
 */
void clcOptTrj_tmp(double wayStp, double wayNum, double wayInxBeg, double
                   wayInxEnd, double engKinNum, const double
                   engKinNumVec_wayInx[800], const double
                   engKinMat_engKinInx_wayInx[8800], const emxArray_real_T
                   *optPreInxTn3, const emxArray_real_T *batFrcOptTn3, const
                   emxArray_real_T *fulEngOptTn3, const emxArray_real_T
                   *cos2goActMat, emxArray_real_T *engKinOptVec, emxArray_real_T
                   *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
                   emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
                   double *fulEngOpt)
{
  int ix;
  int iy;
  emxArray_real_T *engKinOptInxVec;
  int outsz[2];
  emxArray_real_T *extremum;
  emxArray_int32_T *iindx;
  int n;
  int b_ix;
  int i;
  int ixstop;
  double mtmp;
  int itmp;
  int cindx;
  int c_ix;
  boolean_T exitg2;
  emxArray_real_T *indx;
  boolean_T exitg1;
  emxArray_real_T *x;
  emxArray_real_T *r0;
  emxArray_real_T *b_fulEngOptTn3;
  double wayInx;
  double engKinMat_engKinInx_wayInx_data[11];
  int engKinMat_engKinInx_wayInx_size[1];
  emxArray_real_T b_engKinMat_engKinInx_wayInx_da;
  double y_data[10];
  double psiEngKinVec_data[11];

  /*   Vektor - Trajektorie der optimalen kin. Energien */
  /*     Vektor - optimale Batterieenergieänderung */
  /*      Vektor - optimale Kraftstoffenergieänderung */
  /*               Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*      Vektor - costate für kinetische Energie */
  /*           Skalar - optimale Kraftstoffenergie */
  /*  */
  /* CLCOPTTRJ Calculating optimal trajectories for result of DP + PMP */
  /*  Erstellungsdatum der ersten Version 24.08.2015 - Stephan Uebel */
  /*  */
  /*  Diese Funktion berechnet die optimalen Trajketorien der kinetischen */
  /*  Energie und Anstriebsstrangzustands. Außerdem wird ein Verlauf für einen */
  /*  costate für die kinetische Energie aus den Ergebnissen der DP berechnet. */
  /*    this function calulates the optimal trajectory for kinetic energy and */
  /*    powertrain states. In addition, a course is calculated for a costate */
  /*    for the kinetic energy from the DP results. */
  /*  */
  /*  !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!! */
  /*  Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der */
  /*  jeweiligen Position des Vektors. */
  /*    !!!! Please note, how vectors/tensors are read !!!! */
  /*    Values that are at the beginning and end of an interval are at their */
  /*    respective indexes along the vector. */
  /*  */
  /*  Mittelwerte, d.h. Flussgrößen wie Kräfte, Leistungen etc., stehen immmer */
  /*  am Anfang des Intervalls für das folgende Intervall. Diese */
  /*  Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer. */
  /*    mean values (eg flow variables like forces, services) are always at the */
  /*    beginning of the interval for the next interval. Those vectors/tensors */
  /*    are therefore shorter by a valid entry (index?). */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing function output */
  /*  Trajektorie der optimalen kin. Energien */
  /*    optimal kinetic energy trajectory initializaton */
  ix = engKinOptVec->size[0];
  engKinOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)engKinOptVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  for (ix = 0; ix < iy; ix++) {
    engKinOptVec->data[ix] = rtInf;
  }

  /*  Trajektorie der optimalen Batterieenergieänderung im Intervall */
  /*    optimal battery energy change trajectories for the interval */
  ix = batEngDltOptVec->size[0];
  batEngDltOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)batEngDltOptVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  for (ix = 0; ix < iy; ix++) {
    batEngDltOptVec->data[ix] = rtInf;
  }

  /*  Trajektorie des optimalen Antriebsstrangzustands im Intervall */
  /*    optimal powertrain state trajectories for the interval */
  ix = staVec->size[0];
  staVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)staVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  for (ix = 0; ix < iy; ix++) {
    staVec->data[ix] = 0.0;
  }

  c_emxInit_real_T(&engKinOptInxVec, 1);

  /* % Initialisieren des finalen Zustands */
  /*    intializing the final state */
  /*  Indexvektor der optimalen kinetischen Energien */
  /*    index vector for the optimal kinetic energies */
  ix = engKinOptInxVec->size[0];
  engKinOptInxVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)engKinOptInxVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  for (ix = 0; ix < iy; ix++) {
    engKinOptInxVec->data[ix] = 0.0;
  }

  /*  Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls  */
  /*  Zielgang nicht festgelegt ist */
  /*    find the optimal gear and speed if the target gear isn't fixed */
  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = cos2goActMat->size[ix];
  }

  b_emxInit_real_T(&extremum, 2);
  emxInit_int32_T(&iindx, 2);
  ix = extremum->size[0] * extremum->size[1];
  extremum->size[0] = 1;
  extremum->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)extremum, ix, (int)sizeof(double));
  iy = outsz[1];
  ix = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  ix = iindx->size[0] * iindx->size[1];
  iindx->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)iindx, ix, (int)sizeof(int));
  for (ix = 0; ix < iy; ix++) {
    iindx->data[ix] = 1;
  }

  n = cos2goActMat->size[0];
  b_ix = 0;
  iy = -1;
  for (i = 1; i <= cos2goActMat->size[1]; i++) {
    ix = b_ix + 1;
    ixstop = b_ix + n;
    mtmp = cos2goActMat->data[b_ix];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (rtIsNaN(cos2goActMat->data[b_ix])) {
        c_ix = b_ix + 1;
        exitg2 = false;
        while ((!exitg2) && (c_ix + 1 <= ixstop)) {
          cindx++;
          ix = c_ix + 1;
          if (!rtIsNaN(cos2goActMat->data[c_ix])) {
            mtmp = cos2goActMat->data[c_ix];
            itmp = cindx;
            exitg2 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (ix < ixstop) {
        while (ix + 1 <= ixstop) {
          cindx++;
          if (cos2goActMat->data[ix] < mtmp) {
            mtmp = cos2goActMat->data[ix];
            itmp = cindx;
          }

          ix++;
        }
      }
    }

    iy++;
    extremum->data[iy] = mtmp;
    iindx->data[iy] = itmp;
    b_ix += n;
  }

  b_emxInit_real_T(&indx, 2);
  ix = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = iindx->size[1];
  emxEnsureCapacity((emxArray__common *)indx, ix, (int)sizeof(double));
  iy = iindx->size[0] * iindx->size[1];
  for (ix = 0; ix < iy; ix++) {
    indx->data[ix] = iindx->data[ix];
  }

  emxFree_int32_T(&iindx);
  iy = 1;
  n = extremum->size[1];
  mtmp = extremum->data[0];
  itmp = 1;
  if (extremum->size[1] > 1) {
    if (rtIsNaN(extremum->data[0])) {
      b_ix = 2;
      exitg1 = false;
      while ((!exitg1) && (b_ix <= n)) {
        iy = b_ix;
        if (!rtIsNaN(extremum->data[b_ix - 1])) {
          mtmp = extremum->data[b_ix - 1];
          itmp = b_ix;
          exitg1 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (iy < extremum->size[1]) {
      while (iy + 1 <= n) {
        if (extremum->data[iy] < mtmp) {
          mtmp = extremum->data[iy];
          itmp = iy + 1;
        }

        iy++;
      }
    }
  }

  emxFree_real_T(&extremum);
  staVec->data[(int)(wayInxEnd - 1.0) - 1] = itmp;

  /*  assign the last value in the optimatal KE INDEX vector as the last KE idx */
  engKinOptInxVec->data[(int)wayInxEnd - 1] = indx->data[(int)staVec->data[(int)
    (wayInxEnd - 1.0) - 1] - 1];

  /*  Zielzustand des Ausgabevektors für optimale kinetische Energie */
  /*  beschreiben */
  /*    describe the target state of the output vector for the optimal KE */
  engKinOptVec->data[(int)wayInxEnd - 1] = engKinMat_engKinInx_wayInx[((int)
    engKinOptInxVec->data[(int)wayInxEnd - 1] + 11 * ((int)wayInxEnd - 1)) - 1];

  /*  Batterieenergieänderung im letzten Intervall initialisieren */
  /*    initialize battery engery change's last interval */
  batEngDltOptVec->data[(int)wayInxEnd - 2] = batFrcOptTn3->data[(((int)
    engKinOptInxVec->data[(int)wayInxEnd - 1] + batFrcOptTn3->size[0] * ((int)
    staVec->data[(int)wayInxEnd - 2] - 1)) + batFrcOptTn3->size[0] *
    batFrcOptTn3->size[1] * ((int)wayInxEnd - 2)) - 1] * wayStp;

  /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
  /*    writing the output for the optimal fuel energy */
  *fulEngOpt = fulEngOptTn3->data[(((int)engKinOptInxVec->data[(int)wayInxEnd -
    1] + fulEngOptTn3->size[0] * ((int)staVec->data[(int)wayInxEnd - 2] - 1)) +
    fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int)wayInxEnd - 1)) - 1];

  /*  Initialisieren des Vektors der optimalen Kraftstoffenergieänderung */
  /*    intializing the optimum fuel energy change vector */
  ix = fulEngDltOptVec->size[0];
  fulEngDltOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)fulEngDltOptVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  emxFree_real_T(&indx);
  for (ix = 0; ix < iy; ix++) {
    fulEngDltOptVec->data[ix] = 0.0;
  }

  /*  Costate für die kinetische Energie initialisieren */
  /*    intializing the kinetic energy's costate */
  ix = psiEngKinOptVec->size[0];
  psiEngKinOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)psiEngKinOptVec, ix, (int)sizeof(double));
  iy = (int)wayNum;
  for (ix = 0; ix < iy; ix++) {
    psiEngKinOptVec->data[ix] = 0.0;
  }

  /* % Rückwärtsrechnung über alle Wegpunkte  */
  /*    reverse calculation of all the path indexes */
  /*  Rekonstruieren des optimalen Pfades aus */
  /*    rebuilding the optimale path */
  ix = (int)-((wayInxBeg + 1.0) + (-1.0 - wayInxEnd));
  c_ix = 0;
  c_emxInit_real_T(&x, 1);
  c_emxInit_real_T(&r0, 1);
  c_emxInit_real_T(&b_fulEngOptTn3, 1);
  while (c_ix <= ix - 1) {
    wayInx = wayInxEnd + -(double)c_ix;

    /*  optimalen Vorgängerindex aus Tensor auslesen */
    /*    reading the tensor's optimum previous index  */
    /*  optimalen Index dekodieren */
    /*    decoding the optimal index */
    if (wayInx > wayInxBeg + 1.0) {
      /*  what does this do? - assigns index values, that's for sure */
      /*  - its repopulating the vectors (previously assigned to 0) by */
      /*    looping through all the path states and selecting all the  */
      /*    optimum state variables in each of the mats based on the */
      /*    generated optimum indexes */
      iy = div_s32((int)optPreInxTn3->data[(((int)engKinOptInxVec->data[(int)
        wayInx - 1] + optPreInxTn3->size[0] * ((int)staVec->data[(int)wayInx - 2]
        - 1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] * ((int)wayInx - 1))
                   - 1] - 1, (int)engKinNum);
      engKinOptInxVec->data[(int)wayInx - 2] = (int)optPreInxTn3->data[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + optPreInxTn3->size[0] * ((int)
        staVec->data[(int)wayInx - 2] - 1)) + optPreInxTn3->size[0] *
        optPreInxTn3->size[1] * ((int)wayInx - 1)) - 1] - iy * (int)engKinNum;
      staVec->data[(int)wayInx - 3] = iy + 1;

      /*  Batterieenergieänderung für Vorgängerintervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*    storing the previous interval's battery energy change's flow */
      /*    amount */
      batEngDltOptVec->data[(int)wayInx - 3] = batFrcOptTn3->data[(((int)
        engKinOptInxVec->data[(int)wayInx - 2] + batFrcOptTn3->size[0] * ((int)
        staVec->data[(int)wayInx - 3] - 1)) + batFrcOptTn3->size[0] *
        batFrcOptTn3->size[1] * ((int)wayInx - 3)) - 1] * wayStp;

      /*  Krafstoffenergieänderung für Intervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
      /*    storing the interval's fuel energy change flow amount */
      /*    describing the output size of the optimal fuel energy */
      fulEngDltOptVec->data[(int)wayInx - 2] = fulEngOptTn3->data[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + fulEngOptTn3->size[0] * ((int)
        staVec->data[(int)wayInx - 2] - 1)) + fulEngOptTn3->size[0] *
        fulEngOptTn3->size[1] * ((int)wayInx - 1)) - 1] - fulEngOptTn3->data
        [(((int)engKinOptInxVec->data[(int)wayInx - 2] + fulEngOptTn3->size[0] *
           ((int)staVec->data[(int)wayInx - 3] - 1)) + fulEngOptTn3->size[0] *
          fulEngOptTn3->size[1] * ((int)wayInx - 2)) - 1];

      /*         %% Bestimmung des costate für die kinetische Energie */
      /*    determining the kinetic energy costate */
      /*  */
      /*  Am jeweiligen Wegpunkt wird der Kraftstoffaufwand gegenüber eine */
      /*  änderung der kinetischen Engergie an der Stelle der */
      /*  optimalen Trajektorie berechnet. */
      /*    at each path_idx the fuel is calculated towards a change in the */
      /*    KE at the location of optimal trajectory. (doesn't make much */
      /*    sense) */
      /*    calculating the KE costate vec by diving the delta optimum fuel  */
      /*    energy tensor by the delta kinetic energy mat for each wayInx. */
      if (1.0 > engKinNumVec_wayInx[(int)wayInx - 2]) {
        iy = 0;
      } else {
        iy = (int)engKinNumVec_wayInx[(int)wayInx - 2];
      }

      if (1.0 > engKinNumVec_wayInx[(int)wayInx - 2]) {
        i = 0;
      } else {
        i = (int)engKinNumVec_wayInx[(int)wayInx - 2];
      }

      ixstop = (int)staVec->data[(int)wayInx - 3];
      cindx = b_fulEngOptTn3->size[0];
      b_fulEngOptTn3->size[0] = iy;
      emxEnsureCapacity((emxArray__common *)b_fulEngOptTn3, cindx, (int)sizeof
                        (double));
      for (cindx = 0; cindx < iy; cindx++) {
        b_fulEngOptTn3->data[cindx] = fulEngOptTn3->data[(cindx +
          fulEngOptTn3->size[0] * (ixstop - 1)) + fulEngOptTn3->size[0] *
          fulEngOptTn3->size[1] * ((int)wayInx - 2)];
      }

      diff(b_fulEngOptTn3, x);
      engKinMat_engKinInx_wayInx_size[0] = i;
      for (cindx = 0; cindx < i; cindx++) {
        engKinMat_engKinInx_wayInx_data[cindx] =
          engKinMat_engKinInx_wayInx[cindx + 11 * ((int)wayInx - 2)];
      }

      b_engKinMat_engKinInx_wayInx_da.data = (double *)
        &engKinMat_engKinInx_wayInx_data;
      b_engKinMat_engKinInx_wayInx_da.size = (int *)
        &engKinMat_engKinInx_wayInx_size;
      b_engKinMat_engKinInx_wayInx_da.allocatedSize = 11;
      b_engKinMat_engKinInx_wayInx_da.numDimensions = 1;
      b_engKinMat_engKinInx_wayInx_da.canFreeData = false;
      diff(&b_engKinMat_engKinInx_wayInx_da, r0);
      iy = r0->size[0];
      for (cindx = 0; cindx < iy; cindx++) {
        y_data[cindx] = r0->data[cindx];
      }

      /*  <-fast immer 5000; */
      psiEngKinVec_data[0] = 0.0;
      iy = x->size[0];
      for (cindx = 0; cindx < iy; cindx++) {
        psiEngKinVec_data[cindx + 1] = x->data[cindx] / y_data[cindx];
      }

      /*  what is the point of adding 0 */
      psiEngKinOptVec->data[(int)wayInx - 2] = psiEngKinVec_data[(int)
        engKinOptInxVec->data[(int)wayInx - 2] - 1];

      /*  Potentialgrößen im ersten Punkt speichern */
      /*    save potetial variables in the first point/index */
    } else {
      /*  if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1) */
      engKinOptInxVec->data[(int)wayInx - 2] = (int)optPreInxTn3->data[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + optPreInxTn3->size[0] * ((int)
        staVec->data[(int)wayInx - 2] - 1)) + optPreInxTn3->size[0] *
        optPreInxTn3->size[1] * ((int)wayInx - 1)) - 1] - div_s32((int)
        optPreInxTn3->data[(((int)engKinOptInxVec->data[(int)wayInx - 1] +
        optPreInxTn3->size[0] * ((int)staVec->data[(int)wayInx - 2] - 1)) +
                            optPreInxTn3->size[0] * optPreInxTn3->size[1] *
                            ((int)wayInx - 1)) - 1] - 1, (int)engKinNum) * (int)
        engKinNum;
      fulEngDltOptVec->data[(int)wayInx - 2] = fulEngOptTn3->data[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + fulEngOptTn3->size[0] * ((int)
        staVec->data[(int)wayInx - 2] - 1)) + fulEngOptTn3->size[0] *
        fulEngOptTn3->size[1] * ((int)wayInx - 1)) - 1];
    }

    /*  optimale kinetische Energie im Vorgängerpunkt */
    /*    optimal KE from previous point / path_idx */
    engKinOptVec->data[(int)wayInx - 2] = engKinMat_engKinInx_wayInx[((int)
      engKinOptInxVec->data[(int)wayInx - 2] + 11 * ((int)wayInx - 2)) - 1];
    c_ix++;
  }

  emxFree_real_T(&b_fulEngOptTn3);
  emxFree_real_T(&r0);
  emxFree_real_T(&x);
  emxFree_real_T(&engKinOptInxVec);

  /*  end of path_idx loop */
  /*  end of function */
}

/*
 * File trailer for clcOptTrj_tmp.c
 *
 * [EOF]
 */
