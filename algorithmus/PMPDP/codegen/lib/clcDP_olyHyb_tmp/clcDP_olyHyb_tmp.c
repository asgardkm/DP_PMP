/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: clcDP_olyHyb_tmp.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 08-Jun-2016 14:22:05
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_olyHyb_tmp.h"
#include "clcPMP_olyHyb_tmp.h"
#include "fprintf.h"
#include "clcDP_olyHyb_tmp_emxutil.h"
#include <stdio.h>

/* Variable Definitions */
static double geaNum;
static boolean_T geaNum_not_empty;
static double vehMas;
static double vehAccMin;
static double vehAccMax;

/* Function Definitions */

/*
 * --- Eingangsgrößen:
 *          Skalar - Flag für Ausgabe in das Commandwindow
 *           Skalar für die Wegschrittweite in m
 *        Skalar der Batteriediskretisierung in J
 *        Skalar für die Batterieenergie am Beginn in Ws
 *        Skalar für die Nebenverbrauchlast in W
 *        Skalar für den Co-State der Batterieenergie
 *           Skalar für den Co-State der Zeit
 *  Skalar für die Strafkosten beim Zustandswechsel
 *        Skalar für Anfangsindex in den Eingangsdaten
 *        Skalar für Endindex in den Eingangsdaten
 *     Skalar für den Index der Anfangsgeschwindigkeit
 *        Skalar für die max. Anz. an engKin-Stützstellen
 *           Skalar für die max. Anzahl an Zustandsstützstellen
 *           Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen
 *           Skalar für den Startzustand des Antriebsstrangs
 *  Vektor der Anzahl der kinetischen Energien
 *    Vektor der Steigungen in rad
 *  Matrix der kinetischen Energien in J
 *               struct der FahrzeugFZGameter
 * Arguments    : double disFlg
 *                double wayStp
 *                double batEngStp
 *                double batEngBeg
 *                double batPwrAux
 *                double psiBatEng
 *                double psiTim
 *                double staChgPenCosVal
 *                double wayInxBeg
 *                double wayInxEnd
 *                double engKinBegInx
 *                double engKinNum
 *                double staNum
 *                double wayNum
 *                double staBeg
 *                const emxArray_real_T *engKinNumVec_wayInx
 *                const emxArray_real_T *slpVec_wayInx
 *                const emxArray_real_T *engKinMat_engKinInx_wayInx
 *                const struct0_T *FZG
 *                emxArray_real_T *optPreInxTn3
 *                emxArray_real_T *batFrcOptTn3
 *                emxArray_real_T *fulEngOptTn3
 *                emxArray_real_T *cos2goActMat
 * Return Type  : void
 */
void clcDP_olyHyb_tmp(double disFlg, double wayStp, double batEngStp, double
                      batEngBeg, double batPwrAux, double psiBatEng, double
                      psiTim, double staChgPenCosVal, double wayInxBeg, double
                      wayInxEnd, double engKinBegInx, double engKinNum, double
                      staNum, double wayNum, double staBeg, const
                      emxArray_real_T *engKinNumVec_wayInx, const
                      emxArray_real_T *slpVec_wayInx, const emxArray_real_T
                      *engKinMat_engKinInx_wayInx, const struct0_T *FZG,
                      emxArray_real_T *optPreInxTn3, emxArray_real_T
                      *batFrcOptTn3, emxArray_real_T *fulEngOptTn3,
                      emxArray_real_T *cos2goActMat)
{
  int i0;
  int loop_ub;
  emxArray_real_T *cos2goPreMat;
  emxArray_real_T *batEngPreMat;
  emxArray_real_T *fulEngPreMat;
  int wayInx;
  emxArray_real_T *batFrcOptMat;
  emxArray_real_T *batEngActMat;
  emxArray_real_T *fulEngActMat;
  double b_wayInx;
  int i1;
  double engKinAct;
  int b_loop_ub;
  double cosHamMin;
  int staPreOptInx;
  double engKinPreOptInx;
  double fulEngOpt;
  double batFrcOpt;
  double batEngOpt;
  int staPreMin;
  double staPreMax;
  int engKinPreInx;
  double engKinPre;
  double vehAcc;
  int staPre;
  double b_staPre;
  double staChgPenCos;
  double fulFrc;
  double batFrc;
  double cosHam;
  double cosAct;

  /*            --- Ausgangsgrößen: */
  /*    Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  */
  /* INIDP Calculating optimal predecessors with DP + PMP */
  /*  Erstellungsdatum der ersten Version 20.08.2015 - Stephan Uebel */
  /*  */
  /*  Diese Funktion berechnet die optimalen Vorgänger der Dynamischen */
  /*  Programmierung (DP). Diese subsitutiert die Zustände Zeit und */
  /*  Batterieenergie durch Co-States. Die Kosten werden mit dem */
  /*  Pontryaginschen Minimumsprinzip berechnet. */
  /*    This function calculates the optimum predecessor from dynamic */
  /*    programming (DP). Each state's time and battery power costates are */
  /*    substituted from a Potryagin's Minimum Principle calculation. */
  /*  */
  /*  Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an) */
  /*    variation olyHyb permits only hybrid driving (motor is always on) */
  /*  */
  /*  Änderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min() */
  /*  bestimmt. Das fährt zu einem anderen Schaltverhalten, da Gänge teilweise */
  /*  gleiche Kosten verursachen. In dem Fall wird jetzt der niedrigste Gang */
  /*  gewählt, wie in der DP. */
  /*    change on 23.02.2016 - optimal costs are not directly from the min() */
  /*    index. The move to another switching behaviour is because the */
  /*    transitions FZGtially caused the same costs. The lowester gear is now */
  /*    selected in DP */
  /*  */
  /*  !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!! */
  /*  Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der */
  /*  jeweiligen Position des Vektors. */
  /*    !!!! Please note, how vectors/tensors are read (??) !!!! */
  /*    Values that are at the beginning and end of an interval are at their */
  /*    respective indexes along the vector. */
  /*  */
  /*  Mittelwerte, d.h. Flussgrößen wie Kräfte, Leistungen etc., stehen immmer */
  /*  am Anfang des Intervalls für das folgende Intervall. Diese */
  /*  Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer. */
  /*    mean values (eg flow variables like forces, services) are always at the */
  /*    beginning of the interval for the next interval. Those vectors/tensors */
  /*    are therefore shorter by a valid entry (index?). */
  /* % Initialisieren der persistent Größen */
  /*  Diese werden die nur einmal für die Funktion berechnet */
  /*    assigning input structure values to function persistant variables */
  /*    - just once */
  if (!geaNum_not_empty) {
    /*  Anzahl der Gänge */
    /*    number of gears */
    geaNum = staNum;
    geaNum_not_empty = true;

    /*  max number of state nodes */
    /*  Fahrzeugmasse */
    vehMas = FZG->vehMas;

    /*  minmiale und maximale Beschleunigung */
    /*    min and max accerlations (bounds) */
    vehAccMin = FZG->vehAccMin;
    vehAccMax = FZG->vehAccMax;

    /*  In dieser Version ist der Motor immer an */
  }

  /* % Initialisieren der Ausgabe der Funktion */
  /*    initialzing function output */
  /*  Tensor 3. Stufe für optimalen Vorgängerkoordinaten */
  /*    tensor3 for optimal previous coordinates/idx */
  i0 = optPreInxTn3->size[0] * optPreInxTn3->size[1] * optPreInxTn3->size[2];
  optPreInxTn3->size[0] = (int)engKinNum;
  optPreInxTn3->size[1] = (int)staNum;
  optPreInxTn3->size[2] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)optPreInxTn3, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum * (int)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    optPreInxTn3->data[i0] = 0.0;
  }

  /*  Tensor 3. Stufe für die Kraftstoffenergie */
  /*    tensor3 for fuel energy */
  i0 = fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * fulEngOptTn3->size[2];
  fulEngOptTn3->size[0] = (int)engKinNum;
  fulEngOptTn3->size[1] = (int)staNum;
  fulEngOptTn3->size[2] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)fulEngOptTn3, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum * (int)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fulEngOptTn3->data[i0] = rtInf;
  }

  /*    set initial fuel energy level to 0 */
  fulEngOptTn3->data[(((int)engKinBegInx + fulEngOptTn3->size[0] * ((int)staBeg
    - 1)) + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int)wayInxBeg - 1))
    - 1] = 0.0;

  /*  Tensor 3. Stufe für die Batterienergie */
  /*    tensor3 for battery energy */
  i0 = batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * batFrcOptTn3->size[2];
  batFrcOptTn3->size[0] = (int)engKinNum;
  batFrcOptTn3->size[1] = (int)staNum;
  batFrcOptTn3->size[2] = (int)wayNum;
  emxEnsureCapacity((emxArray__common *)batFrcOptTn3, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum * (int)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    batFrcOptTn3->data[i0] = rtInf;
  }

  emxInit_real_T(&cos2goPreMat, 2);

  /* % Berechnung der optimalen Vorgänger */
  /*    calculating the optimal predecessors */
  /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten */
  /*  Wegschritt */
  /*    initialize the matrix for the cost to the points in the last wayidx */
  i0 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
  cos2goPreMat->size[0] = (int)engKinNum;
  cos2goPreMat->size[1] = (int)staNum;
  emxEnsureCapacity((emxArray__common *)cos2goPreMat, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    cos2goPreMat->data[i0] = rtInf;
  }

  i0 = cos2goActMat->size[0] * cos2goActMat->size[1];
  cos2goActMat->size[0] = (int)engKinNum;
  cos2goActMat->size[1] = (int)staNum;
  emxEnsureCapacity((emxArray__common *)cos2goActMat, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    cos2goActMat->data[i0] = rtInf;
  }

  emxInit_real_T(&batEngPreMat, 2);

  /*  Erste Initilisierung beim Startindex mit 0 für alle Zustände(concluded) */
  /*    first, initialize the startidx to 0 for all states */
  cos2goPreMat->data[((int)engKinBegInx + cos2goPreMat->size[0] * ((int)staBeg -
    1)) - 1] = 0.0;

  /*  Initialisierung der Matrix der Batterieenergien */
  /*    initialize the battery energy matrix */
  i0 = batEngPreMat->size[0] * batEngPreMat->size[1];
  batEngPreMat->size[0] = (int)engKinNum;
  batEngPreMat->size[1] = (int)staNum;
  emxEnsureCapacity((emxArray__common *)batEngPreMat, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    batEngPreMat->data[i0] = rtInf;
  }

  emxInit_real_T(&fulEngPreMat, 2);

  /*  Erste Initilisierung beim Startindex mit Startladung für den Startzustand */
  /*    first, intialize start index of the starting charge for intial state */
  batEngPreMat->data[((int)engKinBegInx + batEngPreMat->size[0] * ((int)staBeg -
    1)) - 1] = batEngBeg;

  /*  Initialisierung der Matrix der Kraftstoffenergien */
  /*    initialze the fuel energy matrix */
  i0 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
  fulEngPreMat->size[0] = (int)engKinNum;
  fulEngPreMat->size[1] = (int)staNum;
  emxEnsureCapacity((emxArray__common *)fulEngPreMat, i0, (int)sizeof(double));
  loop_ub = (int)engKinNum * (int)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fulEngPreMat->data[i0] = rtInf;
  }

  /*  Erste Initilisierung beim Startindex mit 0 für den Startzustand */
  /*    first, intialize the start idx for the intitial states to 0 */
  fulEngPreMat->data[((int)engKinBegInx + fulEngPreMat->size[0] * ((int)staBeg -
    1)) - 1] = 0.0;

  /*  Schleife über alle Wegpunkte */
  /*    looping thorugh length of # of grid discretization/indeces (Weginputs) */
  i0 = (int)(wayInxEnd + (1.0 - (wayInxBeg + 1.0)));
  wayInx = 0;
  emxInit_real_T(&batFrcOptMat, 2);
  emxInit_real_T(&batEngActMat, 2);
  emxInit_real_T(&fulEngActMat, 2);
  while (wayInx <= i0 - 1) {
    b_wayInx = (wayInxBeg + 1.0) + (double)wayInx;

    /*  PATH IDX LOOP */
    /*  mittlere Steigung im betrachteten Intervall  */
    /*    no longer doing mean, using previous gradiant instead */
    /*     %% Berechnung der kinetischen Energien im aktuellen Wegschritt */
    /*  Vorbereitung der FZGallen Schleife (verhindern von zu grossem */
    /*  Datentransfer und unnötigen Berechnungen) */
    /*    Calculating the KE for current index/waypoint. */
    /*    Preperation of FZGallel loop (prevent a too large data transfer, */
    /*    unnecessary computations).    */
    /*  Initialisieren der Matrix für die optimalen Batteriekrafter im */
    /*  Intervall */
    /*    initialize matrix for optimale battery force intervals (discreti.) */
    i1 = batFrcOptMat->size[0] * batFrcOptMat->size[1];
    batFrcOptMat->size[0] = (int)engKinNum;
    batFrcOptMat->size[1] = (int)staNum;
    emxEnsureCapacity((emxArray__common *)batFrcOptMat, i1, (int)sizeof(double));
    loop_ub = (int)engKinNum * (int)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      batFrcOptMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize cost matrix to points in current path steps (idxs?) */
    i1 = cos2goActMat->size[0] * cos2goActMat->size[1];
    cos2goActMat->size[0] = (int)engKinNum;
    cos2goActMat->size[1] = (int)staNum;
    emxEnsureCapacity((emxArray__common *)cos2goActMat, i1, (int)sizeof(double));
    loop_ub = (int)engKinNum * (int)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      cos2goActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Batterieenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for battery energy at points along current wayidx */
    i1 = batEngActMat->size[0] * batEngActMat->size[1];
    batEngActMat->size[0] = (int)engKinNum;
    batEngActMat->size[1] = (int)staNum;
    emxEnsureCapacity((emxArray__common *)batEngActMat, i1, (int)sizeof(double));
    loop_ub = (int)engKinNum * (int)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      batEngActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Krafstoffenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for fuel energie along current way idxs */
    i1 = fulEngActMat->size[0] * fulEngActMat->size[1];
    fulEngActMat->size[0] = (int)engKinNum;
    fulEngActMat->size[1] = (int)staNum;
    emxEnsureCapacity((emxArray__common *)fulEngActMat, i1, (int)sizeof(double));
    loop_ub = (int)engKinNum * (int)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      fulEngActMat->data[i1] = rtInf;
    }

    /*  Anzahl der kinetischen Energien im aktuellen und im */
    /*  Vorgängerwegschritt */
    /*    number of kinetic energies in current and past path_idxs */
    /*  look at this loop's KE */
    /*  and the previous idx KE */
    /*  Vektoren der kinetischen Energien im vorherigen Wegschritt */
    /*    vector of the KE in the previous idx */
    /*  Vektoren der kinetischen Energien im aktuellen Wegschritt */
    /*    KE vector of the current path_idx */
    /*  (FZGfor) Schleife über alle akutellen kinetischen Energien */
    /*    loop through all the current kinetic energies */
    for (loop_ub = 0; loop_ub < (int)engKinNumVec_wayInx->data[(int)b_wayInx - 1];
         loop_ub++) {
      /*  CURRENT KINETIC ENERGY LOOP */
      /*  akutelle kinetsiche Energie bestimmen */
      /*    determine the current kinetic energy */
      engKinAct = engKinMat_engKinInx_wayInx->data[loop_ub +
        engKinMat_engKinInx_wayInx->size[0] * ((int)b_wayInx - 1)];

      /*  Schleife über alle möglichen aktuellen Zustände des Antriesstrangs */
      /*    Loop over all possible current powertrain states/all the gears */
      for (b_loop_ub = 0; b_loop_ub < (int)staNum; b_loop_ub++) {
        /*  ALL GEARS LOOP */
        /*             %% Initialsiieren */
        /*    note-you are preallocating over each powertrain state loop */
        /*  Initialisieren der Ausgabegröße der Schleife */
        /*    preallocate the loop's output size */
        /*    but this is the hamiltonian cost? */
        cosHamMin = rtInf;

        /*  Initialisieren der Variable für den optimalen Zustandsindex */
        /*    initializing variable for optimal state index */
        staPreOptInx = 0;

        /*  Initialisieren der Variable für die Koordinaten des optimalen */
        /*  Vorgängers */
        /*    initializing variable for optimal coords/KE for prev. idx */
        engKinPreOptInx = 0.0;

        /*  Initialisieren der optimalen Kraftstoffenergieänderung zum */
        /*  betrachteten Punkt */
        /*    preallocate the optimum fuel energy change to the point */
        /*    considered */
        fulEngOpt = rtInf;

        /*  Initialisieren der optimalen Batteriekraft zum */
        /*  betrachteten Punkt */
        /*    preallocate the optimal battery force to the point under */
        /*    consideration */
        batFrcOpt = rtInf;

        /*  Initialisieren der optimalen Batterieenergie zum */
        /*  betrachteten Punkt */
        /*    initialize the optimal battery power (up to boundry limits) */
        batEngOpt = rtInf;

        /*             %% Vorgängerzustände beschränken */
        /*    Restrictions on predecessor operation states */
        /*  Festlegen, welche Vorgänger möglich sind: */
        /*  Es sind im Maximum die Anzahl der Gänge +  1 als Vorgänger */
        /*  möglich, denn vom Segeln kann in jeden Gang im elektrischen */
        /*  Fahren und Segeln gewechselt  werden */
        /*    Determine which predecessors are possible: */
        /*    There are at maximum 'number of gears'+1 possible for the */
        /*    predecessors, because from the sail in every Gear in */
        /*    electric travel and the sails will be changed (???) */
        /*  Vorgängerzustände des Antriebsstrangs beschränken */
        /*    determine gear possibilities - ie u(g)  */
        if (1.0 >= (1.0 + (double)b_loop_ub) - 1.0) {
          staPreMin = 1;
        } else {
          staPreMin = (int)((1.0 + (double)b_loop_ub) - 1.0);
        }

        if (geaNum <= (1.0 + (double)b_loop_ub) + 1.0) {
          staPreMax = geaNum;
        } else {
          staPreMax = (1.0 + (double)b_loop_ub) + 1.0;
        }

        /*             %% Schleife über alle kinetischen Energien (Vorgänger) */
        /*    loop through all the kinetic energies (previous state idxs) */
        for (engKinPreInx = 0; engKinPreInx < (int)engKinNumVec_wayInx->data
             [(int)b_wayInx - 2]; engKinPreInx++) {
          /*  PREVIOUS KE LOOP */
          /*  kinetsiche Energie des betrachten(consider) Vorgängerspunkts */
          /*  bestimmen(determine) */
          /*    determine the kinetic energy of the previous path_idx */
          engKinPre = engKinMat_engKinInx_wayInx->data[engKinPreInx +
            engKinMat_engKinInx_wayInx->size[0] * ((int)b_wayInx - 2)];

          /*  Prüfen(check), ob eine erlaubte Beschleunigung vorliegt. */
          /*  Ansonsten zum nächsten Schleifendurchlauf springen */
          /*    Check whether an allowable acceleration exists. */
          /*    Otherwise, jump to the next iteration */
          vehAcc = (engKinAct - engKinMat_engKinInx_wayInx->data[engKinPreInx +
                    engKinMat_engKinInx_wayInx->size[0] * ((int)b_wayInx - 2)]) /
            vehMas / wayStp;
          if ((vehAcc < vehAccMin) || (vehAcc > vehAccMax)) {
          } else {
            /*  Schleife über allen Zustände (relativer Index) */
            /*    Loop through all the states (relative index) */
            i1 = (int)(staPreMax + (1.0 - (double)staPreMin));
            for (staPre = 0; staPre < i1; staPre++) {
              b_staPre = (double)staPreMin + (double)staPre;

              /*  CURRENT GEAR CHANGE LOOP */
              /*                     %% Batterieenergie beim betrachteten Vorgänger */
              /*  battery energy when considering last path_idx */
              /*    note: batengPreMat has dims #_KE_states x #_gears */
              /*  Sollte es keinen gültigen Vorgänger geben, wird zum */
              /*  nächsten Schleifendurchlauf gesprungen */
              /*    if there is no valid previous battery energy, jump */
              /*    to the next loop iteration */
              if (rtIsInf(batEngPreMat->data[engKinPreInx + batEngPreMat->size[0]
                          * ((int)b_staPre - 1)])) {
              } else {
                /*                     %% Antriebsstrangzustand und Strafkosten bestimmen    */
                /*    determine gear and penalty costs */
                /*  Kosten für Zustandswechsel setzen */
                /*    set costs for state changes */
                if (1.0 + (double)b_loop_ub == b_staPre) {
                  /*  Entspricht der Vorgängerzustand dem aktuellen  */
                  /*  Zustand werden keine Kosten gesetzt */
                  /*    staying in current state? set penalty cost to 0 */
                  staChgPenCos = 0.0;
                } else {
                  /*  Ansonsten einfache Zustandswechselkosten */
                  /*  berechnen */
                  /*    otherwise apply a penalty cost to changing gear */
                  staChgPenCos = staChgPenCosVal;

                  /* <-penCos is input */
                }

                /*                     %% Berechnung der optimalen Kosten zum aktuellen Punkt */
                /*    calculating optimal cost to the current point */
                /*  externe Funktion ausführen, die minimale Kosten der */
                /*  Hamiltonfunktion zurückgibt */
                /*    run the min-cost Hamiltonian finding function  */
                clcPMP_olyHyb_tmp(engKinPre, engKinAct, 1.0 + (double)b_loop_ub,
                                  slpVec_wayInx->data[(int)b_wayInx - 2],
                                  batEngPreMat->data[engKinPreInx +
                                  batEngPreMat->size[0] * ((int)b_staPre - 1)],
                                  psiBatEng, psiTim, batPwrAux, batEngStp,
                                  wayStp, FZG, &cosHam, &batFrc, &fulFrc);

                /*                      % minimale Kosten der Hamiltonfunktion zum aktuellen */
                /*                      % Punkt bestimmen */
                /*                      [cosHamMin,optPreInx] ... */
                /*                          = min([cosHam... */
                /*                          + cos2goPreMat(engKinPreInx,staPre)... */
                /*                          + staChgPenCos... */
                /*                          ,cosHamMin]); %#ok<PFBNS> */
                /*  combine the min hamil. cost w/ previous costs and  */
                /*    gear penalty to get current cost */
                cosAct = (cosHam + cos2goPreMat->data[engKinPreInx +
                          cos2goPreMat->size[0] * ((int)b_staPre - 1)]) +
                  staChgPenCos / wayStp;

                /*  Wenn der aktuelle Punkt besser ist, als der in */
                /*  cosHamMin gespeicherte Wert, werden die Ausgabegrößen */
                /*  neu beschrieben. */
                /*    if current point is better than the cost value */
                /*    stored in CosHamMin, then rewrite the output */
                if (cosAct < cosHamMin) {
                  cosHamMin = cosAct;

                  /*  new hamil. cost */
                  staPreOptInx = (int)b_staPre;

                  /*  new optimal gear idx */
                  engKinPreOptInx = 1.0 + (double)engKinPreInx;

                  /*  new optimal KEidx */
                  batFrcOpt = batFrc;

                  /*  new optimal battery force */
                  /*  new opt. battery energy = (batt. force * */
                  /*  displacement diff) + previous battery energy valu */
                  batEngOpt = batFrc * wayStp + batEngPreMat->data[engKinPreInx
                    + batEngPreMat->size[0] * ((int)b_staPre - 1)];

                  /*  new opt. fuel energy = (fuel force * displacement */
                  /*  diff) + previous fuel energy value */
                  fulEngOpt = fulFrc * wayStp + fulEngPreMat->data[engKinPreInx
                    + fulEngPreMat->size[0] * ((int)b_staPre - 1)];
                }
              }
            }

            /*  end of gear changes loop */
          }
        }

        /*  end of running through previous KE states loop */
        if (!rtIsInf(cosHamMin)) {
          /*  optimale Kosten zum aktuellen Punkt speichern */
          /*    save min hamilton value for current point */
          cos2goActMat->data[loop_ub + cos2goActMat->size[0] * b_loop_ub] =
            cosHamMin;

          /*  optimale Batterieenergie zum aktuellen Punkt speichern */
          /*    save optimal battery energy for current point */
          batEngActMat->data[loop_ub + batEngActMat->size[0] * b_loop_ub] =
            batEngOpt;

          /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
          /*    save optimal fuel energy for current point */
          fulEngActMat->data[loop_ub + fulEngActMat->size[0] * b_loop_ub] =
            fulEngOpt;

          /*  optimale Batterieenergie zum aktuellen Punkt */
          /*  Flussgröße gilt im Intervall */
          /*    populate optimal battery energy flux quantity at point  */
          /*    that's applicable to current interval */
          batFrcOptMat->data[loop_ub + batFrcOptMat->size[0] * b_loop_ub] =
            batFrcOpt;

          /*  optimalen Vorgänger codieren über Funktion sub2ind */
          /*  und speichern im Tensor */
          /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
          optPreInxTn3->data[(loop_ub + optPreInxTn3->size[0] * b_loop_ub) +
            optPreInxTn3->size[0] * optPreInxTn3->size[1] * ((int)b_wayInx - 1)]
            = (int)engKinPreOptInx + (int)engKinNum * (staPreOptInx - 1);
        }

        /*  end of ~inf(hamiltonian) if-statement */
      }

      /*  end of looping through all gears */
    }

    /*  end of looping through all the current kinetic energy states */
    /*  Speichern der Batterieenergie für den nächsten Schleifendurchlauf */
    /*    save battery energy value as previous path_idx val for next loop  */
    i1 = batEngPreMat->size[0] * batEngPreMat->size[1];
    batEngPreMat->size[0] = batEngActMat->size[0];
    batEngPreMat->size[1] = batEngActMat->size[1];
    emxEnsureCapacity((emxArray__common *)batEngPreMat, i1, (int)sizeof(double));
    loop_ub = batEngActMat->size[0] * batEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      batEngPreMat->data[i1] = batEngActMat->data[i1];
    }

    /*  Speichern der Krafstoffenergie für den nächsten Schleifendurchlauf */
    /*    save fuel energy value as previous path_idx value for the next loop */
    i1 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
    fulEngPreMat->size[0] = fulEngActMat->size[0];
    fulEngPreMat->size[1] = fulEngActMat->size[1];
    emxEnsureCapacity((emxArray__common *)fulEngPreMat, i1, (int)sizeof(double));
    loop_ub = fulEngActMat->size[0] * fulEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      fulEngPreMat->data[i1] = fulEngActMat->data[i1];
    }

    /*  Speichern der Kosten für den nächsten Schleifendurchlauf */
    /*    save cost as previous path_idx value for the next loop */
    i1 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
    cos2goPreMat->size[0] = cos2goActMat->size[0];
    cos2goPreMat->size[1] = cos2goActMat->size[1];
    emxEnsureCapacity((emxArray__common *)cos2goPreMat, i1, (int)sizeof(double));
    loop_ub = cos2goActMat->size[0] * cos2goActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      cos2goPreMat->data[i1] = cos2goActMat->data[i1];
    }

    /*  optimale Kraftstoffenergie zum aktuellen Punkt */
    /*    optimal fuel energy at current point - save current mat in tensor */
    loop_ub = fulEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = fulEngActMat->size[0];
      for (engKinPreInx = 0; engKinPreInx < b_loop_ub; engKinPreInx++) {
        fulEngOptTn3->data[(engKinPreInx + fulEngOptTn3->size[0] * i1) +
          fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int)b_wayInx - 1)] =
          fulEngActMat->data[engKinPreInx + fulEngActMat->size[0] * i1];
      }
    }

    /*  optimale Batterieenergie zum aktuellen Punkt */
    /*    optimal battery force at current point - save current mat in tensor */
    /*  Flussgröße gilt im Intervall */
    /*    flux quantity applied over the interval */
    loop_ub = batFrcOptMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = batFrcOptMat->size[0];
      for (engKinPreInx = 0; engKinPreInx < b_loop_ub; engKinPreInx++) {
        batFrcOptTn3->data[(engKinPreInx + batFrcOptTn3->size[0] * i1) +
          batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * ((int)b_wayInx - 2)] =
          batFrcOptMat->data[engKinPreInx + batFrcOptMat->size[0] * i1];
      }
    }

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (disFlg != 0.0) {
      b_fprintf(b_wayInx - wayInxBeg, (b_wayInx - wayInxBeg) / (wayInxEnd -
                 wayInxBeg) * 100.0);
    }

    wayInx++;
  }

  emxFree_real_T(&fulEngActMat);
  emxFree_real_T(&batEngActMat);
  emxFree_real_T(&batFrcOptMat);
  emxFree_real_T(&fulEngPreMat);
  emxFree_real_T(&batEngPreMat);
  emxFree_real_T(&cos2goPreMat);

  /*  end of looping through all discretized path indexes */
  /*  END OF FUNCTION */
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void geaNum_not_empty_init(void)
{
  geaNum_not_empty = false;
}

/*
 * File trailer for clcDP_olyHyb_tmp.c
 *
 * [EOF]
 */
