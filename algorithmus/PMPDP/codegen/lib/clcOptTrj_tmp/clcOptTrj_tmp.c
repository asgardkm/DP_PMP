/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcOptTrj_tmp.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 09:35:30
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcOptTrj_tmp.h"
#include "diff.h"
#include "clcOptTrj_tmp_emxutil.h"

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
 * Arguments    : double disFlg
 *                double wayStp
 *                double wayNum
 *                double wayInxBeg
 *                double wayInxEnd
 *                double staEnd
 *                double engKinNum
 *                double engKinEndInxVal
 *                double staNum
 *                const emxArray_real_T *engKinNumVec_wayInx
 *                const emxArray_real_T *engKinMat_engKinInx_wayInx
 *                const double optPreInxTn3[52800]
 *                const double batFrcOptTn3[52800]
 *                const double fulEngOptTn3[52800]
 *                const double cos2goActMat[66]
 *                emxArray_real_T *engKinOptVec
 *                emxArray_real_T *batEngDltOptVec
 *                emxArray_real_T *fulEngDltOptVec
 *                emxArray_real_T *staVec
 *                emxArray_real_T *psiEngKinOptVec
 *                double *fulEngOpt
 *                double *engKinEndInx
 * Return Type  : void
 */
void clcOptTrj_tmp(double disFlg, double wayStp, double wayNum, double wayInxBeg,
                   double wayInxEnd, double staEnd, double engKinNum, double
                   engKinEndInxVal, double staNum, const emxArray_real_T
                   *engKinNumVec_wayInx, const emxArray_real_T
                   *engKinMat_engKinInx_wayInx, const double optPreInxTn3[52800],
                   const double batFrcOptTn3[52800], const double fulEngOptTn3
                   [52800], const double cos2goActMat[66], emxArray_real_T
                   *engKinOptVec, emxArray_real_T *batEngDltOptVec,
                   emxArray_real_T *fulEngDltOptVec, emxArray_real_T *staVec,
                   emxArray_real_T *psiEngKinOptVec, double *fulEngOpt, double
                   *engKinEndInx)
{
  int ix;
  int loop_ub;
  emxArray_real_T *engKinOptInxVec;
  double extremum[6];
  int iindx[6];
  int b_ix;
  int iy;
  double mtmp;
  int itmp;
  int cindx;
  int c_ix;
  boolean_T exitg2;
  boolean_T exitg1;
  emxArray_real_T *y;
  emxArray_real_T *b_engKinMat_engKinInx_wayInx;
  double wayInx;
  double fulEngOptTn3_data[11];
  int fulEngOptTn3_size[1];
  emxArray_real_T b_fulEngOptTn3_data;
  double x_data[10];
  double psiEngKinVec_data[11];
  (void)staNum;

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
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    engKinOptVec->data[ix] = rtInf;
  }

  /*  Trajektorie der optimalen Batterieenergieänderung im Intervall */
  /*    optimal battery energy change trajectories for the interval */
  ix = batEngDltOptVec->size[0];
  batEngDltOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)batEngDltOptVec, ix, (int)sizeof(double));
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    batEngDltOptVec->data[ix] = rtInf;
  }

  /*  Trajektorie des optimalen Antriebsstrangzustands im Intervall */
  /*    optimal powertrain state trajectories for the interval */
  ix = staVec->size[0];
  staVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)staVec, ix, (int)sizeof(double));
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    staVec->data[ix] = 0.0;
  }

  emxInit_real_T(&engKinOptInxVec, 1);

  /* % Initialisieren des finalen Zustands */
  /*    intializing the final state */
  /*  Indexvektor der optimalen kinetischen Energien */
  /*    index vector for the optimal kinetic energies */
  ix = engKinOptInxVec->size[0];
  engKinOptInxVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)engKinOptInxVec, ix, (int)sizeof(double));
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    engKinOptInxVec->data[ix] = 0.0;
  }

  /*  Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls  */
  /*  Zielgang nicht festgelegt ist */
  /*    find the optimal gear and speed if the target gear isn't fixed */
  if (disFlg != 0.0) {
    staVec->data[(int)(wayInxEnd - 1.0) - 1] = staEnd;

    /*  Die finale kinetische Energie steht an Stelle 1 im Vektor */
    /*    the final kinetic energy is at the first index in the vector */
    *engKinEndInx = engKinEndInxVal;
  } else {
    for (ix = 0; ix < 6; ix++) {
      iindx[ix] = 1;
    }

    b_ix = 0;
    iy = -1;
    for (loop_ub = 0; loop_ub < 6; loop_ub++) {
      b_ix += 11;
      ix = b_ix - 10;
      mtmp = cos2goActMat[b_ix - 11];
      itmp = 1;
      cindx = 1;
      if (rtIsNaN(cos2goActMat[b_ix - 11])) {
        c_ix = b_ix - 9;
        exitg2 = false;
        while ((!exitg2) && (c_ix <= b_ix)) {
          cindx++;
          ix = c_ix;
          if (!rtIsNaN(cos2goActMat[c_ix - 1])) {
            mtmp = cos2goActMat[c_ix - 1];
            itmp = cindx;
            exitg2 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (ix < b_ix) {
        while (ix + 1 <= b_ix) {
          cindx++;
          if (cos2goActMat[ix] < mtmp) {
            mtmp = cos2goActMat[ix];
            itmp = cindx;
          }

          ix++;
        }
      }

      iy++;
      extremum[iy] = mtmp;
      iindx[iy] = itmp;
    }

    iy = 1;
    mtmp = extremum[0];
    itmp = 1;
    if (rtIsNaN(extremum[0])) {
      b_ix = 2;
      exitg1 = false;
      while ((!exitg1) && (b_ix < 7)) {
        iy = b_ix;
        if (!rtIsNaN(extremum[b_ix - 1])) {
          mtmp = extremum[b_ix - 1];
          itmp = b_ix;
          exitg1 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (iy < 6) {
      while (iy + 1 < 7) {
        if (extremum[iy] < mtmp) {
          mtmp = extremum[iy];
          itmp = iy + 1;
        }

        iy++;
      }
    }

    staVec->data[(int)(wayInxEnd - 1.0) - 1] = itmp;
    *engKinEndInx = iindx[(int)staVec->data[(int)(wayInxEnd - 1.0) - 1] - 1];
  }

  /*  assign the last value in the optimatal KE INDEX vector as the last KE idx */
  engKinOptInxVec->data[(int)wayInxEnd - 1] = *engKinEndInx;

  /*  Zielzustand des Ausgabevektors für optimale kinetische Energie */
  /*  beschreiben */
  /*    describe the target state of the output vector for the optimal KE */
  engKinOptVec->data[(int)wayInxEnd - 1] = engKinMat_engKinInx_wayInx->data
    [((int)engKinOptInxVec->data[(int)wayInxEnd - 1] +
      engKinMat_engKinInx_wayInx->size[0] * ((int)wayInxEnd - 1)) - 1];

  /*  Batterieenergieänderung im letzten Intervall initialisieren */
  /*    initialize battery engery change's last interval */
  batEngDltOptVec->data[(int)wayInxEnd - 2] = batFrcOptTn3[(((int)
    engKinOptInxVec->data[(int)wayInxEnd - 1] + 11 * ((int)staVec->data[(int)
    wayInxEnd - 2] - 1)) + 66 * ((int)wayInxEnd - 2)) - 1] * wayStp;

  /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
  /*    writing the output for the optimal fuel energy */
  *fulEngOpt = fulEngOptTn3[(((int)engKinOptInxVec->data[(int)wayInxEnd - 1] +
    11 * ((int)staVec->data[(int)wayInxEnd - 2] - 1)) + 66 * ((int)wayInxEnd - 1))
    - 1];

  /*  Initialisieren des Vektors der optimalen Kraftstoffenergieänderung */
  /*    intializing the optimum fuel energy change vector */
  ix = fulEngDltOptVec->size[0];
  fulEngDltOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)fulEngDltOptVec, ix, (int)sizeof(double));
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    fulEngDltOptVec->data[ix] = 0.0;
  }

  /*  Costate für die kinetische Energie initialisieren */
  /*    intializing the kinetic energy's costate */
  ix = psiEngKinOptVec->size[0];
  psiEngKinOptVec->size[0] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)psiEngKinOptVec, ix, (int)sizeof(double));
  loop_ub = (int)wayNum;
  for (ix = 0; ix < loop_ub; ix++) {
    psiEngKinOptVec->data[ix] = 0.0;
  }

  /* % Rückwärtsrechnung über alle Wegpunkte  */
  /*    reverse calculation of all the path indexes */
  /*  Rekonstruieren des optimalen Pfades aus */
  /*    rebuilding the optimale path */
  ix = (int)-((wayInxBeg + 1.0) + (-1.0 - wayInxEnd));
  b_ix = 0;
  emxInit_real_T(&y, 1);
  emxInit_real_T(&b_engKinMat_engKinInx_wayInx, 1);
  while (b_ix <= ix - 1) {
    wayInx = wayInxEnd + -(double)b_ix;

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
      iy = div_s32((int)optPreInxTn3[(((int)engKinOptInxVec->data[(int)wayInx -
        1] + 11 * ((int)staVec->data[(int)wayInx - 2] - 1)) + 66 * ((int)wayInx
        - 1)) - 1] - 1, (int)engKinNum);
      engKinOptInxVec->data[(int)wayInx - 2] = (int)optPreInxTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + 11 * ((int)staVec->data[(int)
        wayInx - 2] - 1)) + 66 * ((int)wayInx - 1)) - 1] - iy * (int)engKinNum;
      staVec->data[(int)wayInx - 3] = iy + 1;

      /*  Batterieenergieänderung für Vorgängerintervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*    storing the previous interval's battery energy change's flow */
      /*    amount */
      batEngDltOptVec->data[(int)wayInx - 3] = batFrcOptTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 2] + 11 * ((int)staVec->data[(int)
        wayInx - 3] - 1)) + 66 * ((int)wayInx - 3)) - 1] * wayStp;

      /*  Krafstoffenergieänderung für Intervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
      /*    storing the interval's fuel energy change flow amount */
      /*    describing the output size of the optimal fuel energy */
      fulEngDltOptVec->data[(int)wayInx - 2] = fulEngOptTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + 11 * ((int)staVec->data[(int)
        wayInx - 2] - 1)) + 66 * ((int)wayInx - 1)) - 1] - fulEngOptTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 2] + 11 * ((int)staVec->data[(int)
        wayInx - 3] - 1)) + 66 * ((int)wayInx - 2)) - 1];

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
      if (1.0 > engKinNumVec_wayInx->data[(int)wayInx - 2]) {
        loop_ub = 0;
      } else {
        loop_ub = (int)engKinNumVec_wayInx->data[(int)wayInx - 2];
      }

      if (1.0 > engKinNumVec_wayInx->data[(int)wayInx - 2]) {
        cindx = 0;
      } else {
        cindx = (int)engKinNumVec_wayInx->data[(int)wayInx - 2];
      }

      iy = (int)staVec->data[(int)wayInx - 3];
      fulEngOptTn3_size[0] = loop_ub;
      for (c_ix = 0; c_ix < loop_ub; c_ix++) {
        fulEngOptTn3_data[c_ix] = fulEngOptTn3[(c_ix + 11 * (iy - 1)) + 66 *
          ((int)wayInx - 2)];
      }

      b_fulEngOptTn3_data.data = (double *)&fulEngOptTn3_data;
      b_fulEngOptTn3_data.size = (int *)&fulEngOptTn3_size;
      b_fulEngOptTn3_data.allocatedSize = 11;
      b_fulEngOptTn3_data.numDimensions = 1;
      b_fulEngOptTn3_data.canFreeData = false;
      diff(&b_fulEngOptTn3_data, y);
      iy = y->size[0];
      loop_ub = y->size[0];
      for (c_ix = 0; c_ix < loop_ub; c_ix++) {
        x_data[c_ix] = y->data[c_ix];
      }

      c_ix = b_engKinMat_engKinInx_wayInx->size[0];
      b_engKinMat_engKinInx_wayInx->size[0] = cindx;
      emxEnsureCapacity((emxArray__common *)b_engKinMat_engKinInx_wayInx, c_ix,
                        (int)sizeof(double));
      for (c_ix = 0; c_ix < cindx; c_ix++) {
        b_engKinMat_engKinInx_wayInx->data[c_ix] =
          engKinMat_engKinInx_wayInx->data[c_ix +
          engKinMat_engKinInx_wayInx->size[0] * ((int)wayInx - 2)];
      }

      diff(b_engKinMat_engKinInx_wayInx, y);

      /*  <-fast immer 5000; */
      psiEngKinVec_data[0] = 0.0;
      for (c_ix = 0; c_ix < iy; c_ix++) {
        psiEngKinVec_data[c_ix + 1] = x_data[c_ix] / y->data[c_ix];
      }

      /*  what is the point of adding 0 */
      psiEngKinOptVec->data[(int)wayInx - 2] = psiEngKinVec_data[(int)
        engKinOptInxVec->data[(int)wayInx - 2] - 1];

      /*  Potentialgrößen im ersten Punkt speichern */
      /*    save potetial variables in the first point/index */
    } else {
      /*  if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1) */
      engKinOptInxVec->data[(int)wayInx - 2] = (int)optPreInxTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + 11 * ((int)staVec->data[(int)
        wayInx - 2] - 1)) + 66 * ((int)wayInx - 1)) - 1] - div_s32((int)
        optPreInxTn3[(((int)engKinOptInxVec->data[(int)wayInx - 1] + 11 * ((int)
        staVec->data[(int)wayInx - 2] - 1)) + 66 * ((int)wayInx - 1)) - 1] - 1,
        (int)engKinNum) * (int)engKinNum;
      fulEngDltOptVec->data[(int)wayInx - 2] = fulEngOptTn3[(((int)
        engKinOptInxVec->data[(int)wayInx - 1] + 11 * ((int)staVec->data[(int)
        wayInx - 2] - 1)) + 66 * ((int)wayInx - 1)) - 1];
    }

    /*  optimale kinetische Energie im Vorgängerpunkt */
    /*    optimal KE from previous point / path_idx */
    engKinOptVec->data[(int)wayInx - 2] = engKinMat_engKinInx_wayInx->data[((int)
      engKinOptInxVec->data[(int)wayInx - 2] + engKinMat_engKinInx_wayInx->size
      [0] * ((int)wayInx - 2)) - 1];
    b_ix++;
  }

  emxFree_real_T(&b_engKinMat_engKinInx_wayInx);
  emxFree_real_T(&y);
  emxFree_real_T(&engKinOptInxVec);

  /*  end of path_idx loop */
  /*  end of function */
}

/*
 * File trailer for clcOptTrj_tmp.c
 *
 * [EOF]
 */
