/*
 * clcPMP_olyHyb_port.c
 *
 * Code generation for function 'clcPMP_olyHyb_port'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcPMP_olyHyb_port.h"
#include "eml_error.h"
#include "batFrcClc_port.h"
#include "codegen_interp2.h"
#include "interp1q.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static real_T crsSpdHybMax;
static boolean_T crsSpdHybMax_not_empty;
static real_T crsSpdHybMin;
static emlrtRSInfo i_emlrtRSI = { 324, "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m"
};

static emlrtRSInfo j_emlrtRSI = { 258, "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m"
};

static emlrtRSInfo k_emlrtRSI = { 100, "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m"
};

static emlrtRSInfo l_emlrtRSI = { 86, "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m"
};

static emlrtRSInfo m_emlrtRSI = { 14, "sqrt",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"
};

static emlrtRSInfo n_emlrtRSI = { 87, "batEngDltClc_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\batEngDltClc_port.m"
};

static emlrtRSInfo o_emlrtRSI = { 90, "batEngDltClc_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\batEngDltClc_port.m"
};

static emlrtRSInfo p_emlrtRSI = { 70, "fulEngClc_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\fulEngClc_port.m" };

static emlrtRSInfo q_emlrtRSI = { 102, "fulEngClc_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\fulEngClc_port.m" };

static emlrtBCInfo mb_emlrtBCI = { 1, 6, 99, 13, "fzg_array.geaRat",
  "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m",
  0 };

static emlrtRTEInfo t_emlrtRTEI = { 318, 1, "clcPMP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcPMP_olyHyb_port.m"
};

/* Function Definitions */
void clcPMP_olyHyb_port(const emlrtStack *sp, real_T engKinPre, real_T engKinAct,
  real_T gea, real_T slp, real_T batEng, real_T psiBatEng, real_T psiTim, real_T
  batPwrAux, real_T batEngStp, real_T wayStp, const struct2_T *fzg_scalar, const
  struct4_T *fzg_array, real_T *cosHamMin, real_T *batFrcOut, real_T *fulFrcOut)
{
  real_T whlTrq;
  real_T vehVel;
  real_T b_engKinPre[2];
  real_T crsSpdVec[2];
  int32_T k;
  boolean_T y;
  boolean_T exitg3;
  boolean_T exitg2;
  real_T crsSpd;
  real_T crsTrq;
  real_T iceTrqMax;
  real_T iceTrqMin;
  real_T b_fzg_array[100];
  real_T emoTrqMinPos;
  real_T emoTrqMax;
  real_T batEngDltMinInx;
  real_T batOcv;
  int32_T batEngDltInx;
  real_T b_emoTrqMinPos;
  int32_T ixstart;
  int32_T itmp;
  int32_T ix;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* CLCPMP Minimizing Hamiltonian: Co-States for soc and time */
  /*  Erstellungsdatum der ersten Version 19.08.2015 - Stephan Uebel */
  /*  */
  /*  Batterieleistungsgrenzen hinzugefügt am 13.12.2015 */
  /*  ^^added battery power limit */
  /*  */
  /*  Massenaufschlag durch Trägheitsmoment herausgenommen */
  /*  ^^Mass increment removed by inertia */
  /*  */
  /* % Inputdefinition */
  /*  */
  /*  engKinPre     - Double(1,1)  - kinetische Energie am Intervallanfang in J */
  /*                                 ^^ kinetic energy at start of interval (J) */
  /*  engKinAct     - Double(1,1)  - kinetische Energie am Intervallende in J */
  /*                                 ^^ kinetic energe at end of interval (J) */
  /*  gea           - Double(1,1)  - Gang */
  /*                                 ^^ gear */
  /*  slp           - Double(1,1)  - Steigung in rad */
  /*                                 ^^ slope in radians */
  /*  iceFlg        - Boolean(1,1) - Flag für Motorzustand */
  /*                                 ^^ flag for motor condition */
  /*  batEng        - Double(1,1)  - Batterieenergie in J */
  /*                                 ^^ battery energy (J) */
  /*  psibatEng     - Double(1,1)  - Costate für Batterieenergie ohne Einheit */
  /*                                 ^^ costate for battery energy w/o unity */
  /*  psiTim        - Double(1,1)  - Costate für die Zeit ohne Einheit */
  /*                                 ^^ costate for time without unity */
  /*  batPwrAux     - Double(1,1)  - elektr. Nebenverbraucherleistung in W */
  /*                                 ^^ electric auxiliary power consumed (W) */
  /*  batEngStp     - Double(1,1)  - Drehmomentschritt */
  /*                                 ^^ torque step <- no, it's a battery step */
  /*  wayStp        - Double(1,1)  - Intervallschrittweite in m */
  /*                                 ^^ interval step distance (m) */
  /*  fzg_scalar    - Struct(1,1)  - Modelldaten - nur skalar */
  /*  fzg_array     - Struct(1,1)  - Modelldaten _ nur arrays                              */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing function output */
  /*  Ausgabewert des Minimums der Hamiltonfunktion */
  /*    output for minimizing the hamiltonian */
  *cosHamMin = rtInf;

  /*  Batterieladungsänderung im Wegschritt beir minimaler Hamiltonfunktion */
  /*    battery change in path_idx step with the minial hamiltonian */
  *batFrcOut = rtInf;

  /*  Kraftstoffkraftänderung im Wegschritt bei minimaler Hamiltonfunktion */
  /*    fuel change in path_idx step with the minimal hamiltonian */
  *fulFrcOut = 0.0;

  /* % Initialisieren der persistent Größen */
  /*    initialize the persistance variables */
  /*  Diese werden die nur einmal für die Funktion berechnet */
  /*    only calculated once for the function */
  if (!crsSpdHybMax_not_empty) {
    /*  maximale Drehzahl Elektrommotor */
    /*    maximum electric motor rotational speed */
    /*  maximale Drehzahl der Kurbelwelle */
    /*    maximum crankshaft rotational speed */
    crsSpdHybMax = muDoubleScalarMin(fzg_array->iceSpdMgd[14850],
      fzg_array->emoSpdMgd[14850]);
    crsSpdHybMax_not_empty = true;

    /*  minimale Drehzahl der Kurbelwelle */
    /*    minimum crankshaft rotational speed */
    crsSpdHybMin = fzg_array->iceSpdMgd[0];
  }

  /* % Initialisieren der allgemein benötigten Kenngrößen */
  /*    initializing the commonly required parameters */
  /*  mittlere kinetische Energie im Wegschritt berechnen */
  /*    define the average kinetic energy at path_idx step-is just previous KE */
  /*  mittlere Geschwindigkeit im Wegschritt berechnen */
  /*    define the average speed at path_idx step */
  whlTrq = 2.0 * engKinPre / fzg_scalar->vehMas;
  st.site = &l_emlrtRSI;
  if (whlTrq < 0.0) {
    b_st.site = &m_emlrtRSI;
    eml_error(&b_st);
  }

  vehVel = muDoubleScalarSqrt(whlTrq);

  /* % vorzeitiger Funktionsabbruch? */
  /*    premature function termination? */
  /*  Drehzahl der Kurbelwelle und Grenzen */
  /*    crankshaft speed and limits */
  /*  Aus den kinetischen Energien des Fahrzeugs wird über die Raddrehzahl */
  /*  und die übersetzung vom Getriebe die Kurbelwellendrehzahl berechnet. */
  /*  Zeilenrichtung entspricht den Gängen. (Zeilenvektor) */
  /*    from the vehicle's kinetic energy, the crankshaft speed is calculated */
  /*    by the speed and gearbox translation. Line direction corresponding to */
  /*    the aisles (row rector). EQUATION 1 */
  b_engKinPre[0] = engKinPre;
  b_engKinPre[1] = engKinAct;
  for (k = 0; k < 2; k++) {
    crsSpdVec[k] = 2.0 * b_engKinPre[k] / fzg_scalar->vehMas;
  }

  st.site = &k_emlrtRSI;
  for (k = 0; k < 2; k++) {
    if (crsSpdVec[k] < 0.0) {
      b_st.site = &m_emlrtRSI;
      eml_error(&b_st);
    }
  }

  for (k = 0; k < 2; k++) {
    crsSpdVec[k] = muDoubleScalarSqrt(crsSpdVec[k]);
  }

  k = (int32_T)gea;
  emlrtDynamicBoundsCheckFastR2012b(k, 1, 6, &mb_emlrtBCI, sp);
  for (k = 0; k < 2; k++) {
    crsSpdVec[k] = fzg_array->geaRat[(int32_T)gea - 1] * crsSpdVec[k] /
      fzg_scalar->whlDrr;
  }

  /*  Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen */
  /*  Modus */
  /*    stop if the crankshaft rotatoinal speed is too high in hybrid mode */
  y = false;
  k = 0;
  exitg3 = false;
  while ((!exitg3) && (k < 2)) {
    if (!((crsSpdVec[k] > crsSpdHybMax) == 0)) {
      y = true;
      exitg3 = true;
    } else {
      k++;
    }
  }

  if (y) {
  } else {
    /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
    /*  Leerlaufdrehzahl ist, */
    /*    stop if crankshaft rotional speed is lower than the idling speed */
    y = false;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 2)) {
      if (!((crsSpdVec[k] < crsSpdHybMin) == 0)) {
        y = true;
        exitg2 = true;
      } else {
        k++;
      }
    }

    if (y) {
    } else {
      /*  Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
      /*    check if electric motor speed limit is maintained */
      /*  mittlere Kurbelwellendrehzahlen berechnen */
      /*    calculate average crankshaft rotational speed */
      /*    - really just selecting the previous path_idx KE crankshaft speed */
      crsSpd = crsSpdVec[0];

      /* % Längsdynamik berechnen */
      /*    calculate longitundinal dynamics */
      /*  Es wird eine konstante Beschleunigung angenommen, die im Wegschritt */
      /*  wayStp das Fahrzeug von velPre auf velAct beschleunigt. */
      /*    constant acceleration assumed when transitioning from velPre to velAct */
      /*    for the selected wayStp path_idx step distance */
      /*  Berechnen der konstanten Beschleunigung */
      /*    calculate the constant acceleration */
      /*  Aus der mittleren kinetischen Energie im Intervall, der mittleren */
      /*  Steigung und dem Gang lässt sich über die Fahrwiderstandsgleichung */
      /*  die nötige Fahrwiderstandskraft berechnen, die aufgebracht werden */
      /*  muss, um diese zu realisieren. */
      /*    from the (avg) kinetic energy in the interval, the (avg) slope and */
      /*    transition can calculate the necessary traction force on the driving */
      /*    resistance equation (PART OF EQUATION 5) */
      /*  Steigungskraft aus der mittleren Steigung berechnen (Skalar) */
      /*    gradiant force from the calculated (average) gradient */
      /*  Rollreibungskraft berechnen (Skalar) */
      /*    calculated rolling friction force - not included in EQ 5??? */
      /*  Luftwiderstandskraft berechnen (2*c_a/m * E_kin) (Skalar)  */
      /*    calculated air resistance force  */
      /* % Berechnung der minimalen kosten der Hamiltonfunktion */
      /*    Calculating the minimum cost of the Hamiltonian */
      /* % Berechnen der Kraft am Rad für Antriebsstrangmodus */
      /*    calculate the force on the wheel for the drivetrain mode */
      /*  % dynamische Fahrzeugmasse bei Fahrzeugmotor an berechnen. Das */
      /*  % heißt es werden Trägheitsmoment von Verbrennungsmotor, */
      /*  % Elektromotor und Rädern mit einbezogen. */
      /*    calculate dynamic vehicle mass with the vehicle engine (with the moment */
      /*    of intertia of the ICE, electric motor, and wheels) */
      /*  vehMasDyn = (par.iceMoi_geaRat(gea) +... */
      /*      par.emoGeaMoi_geaRat(gea) + par.whlMoi)/par.whlDrr^2 ... */
      /*      + par.vehMas; */
      /*  Radkraft berechnen (Beschleunigungskraft + Steigungskraft + */
      /*  Rollwiderstandskraft + Luftwiderstandskraft) */
      /*    caluclating wheel forces (accerlation force + gradient force + rolling */
      /*    resistance + air resistance)    EQUATION 5 */
      /* % Getriebeübersetzung und -verlust */
      /*    gear ratio and loss */
      /*  Das Drehmoment des Rades ergibt sich über den Radhalbmesser aus */
      /*  der Fahrwiderstandskraft. */
      /*    the weel torque is obtained from the wheel radius of the rolling */
      /*    resistance force (torque = force * distance (in this case, radius) */
      whlTrq = ((((engKinAct - engKinPre) / (fzg_scalar->vehMas * wayStp) *
                  fzg_scalar->vehMas + fzg_scalar->vehMas * 9.81 *
                  muDoubleScalarSin(slp)) + fzg_scalar->whlRosResCof *
                 fzg_scalar->vehMas * 9.81 * muDoubleScalarCos(slp)) + 2.0 *
                fzg_scalar->drgCof / fzg_scalar->vehMas * engKinPre) *
        fzg_scalar->whlDrr;

      /*  Berechnung des Kurbelwellenmoments */
      /*  Hier muss unterschieden werden, ob das Radmoment positiv oder */
      /*  negativ ist, da nur ein einfacher Wirkungsgrad für das Getriebe */
      /*  genutzt wird */
      /*    it's important to determine sign of crankshaft torque (positive or */
      /*    negative), since only a simple efficiency is used for the transmission */
      /*    PART OF EQ4  <- perhaps reversed? not too sure */
      if (whlTrq < 0.0) {
        crsTrq = whlTrq / fzg_array->geaRat[(int32_T)gea - 1] *
          fzg_scalar->geaEfy;
      } else {
        crsTrq = whlTrq / fzg_array->geaRat[(int32_T)gea - 1] /
          fzg_scalar->geaEfy;
      }

      /* % Verbrennungsmotor */
      /*    internal combustion engine */
      /*  maximales Moment des Verbrennungsmotors berechnen */
      /*    calculate max torque of the engine (quadratic based on rotation speed) */
      iceTrqMax = (fzg_array->iceTrqMaxCof[0] * (crsSpdVec[0] * crsSpdVec[0]) +
                   fzg_array->iceTrqMaxCof[1] * crsSpdVec[0]) +
        fzg_array->iceTrqMaxCof[2];

      /*  minimales Moment des Verbrennungsmotors berechnen */
      /*    calculating mimimum ICE moment */
      iceTrqMin = (fzg_array->iceTrqMinCof[0] * (crsSpdVec[0] * crsSpdVec[0]) +
                   fzg_array->iceTrqMinCof[1] * crsSpdVec[0]) +
        fzg_array->iceTrqMinCof[2];

      /* % Elektromotor */
      /*    electric motor */
      /*  maximales Moment, dass die E-Maschine liefern kann */
      /*    max torque that the electric motor can provide - from interpolation */
      /*  emoTrqMaxPos = ... */
      /*      lininterp1(par.emoSpdMgd(1,:)',par.emoTrqMax_emoSpd,crsSpd); */
      for (k = 0; k < 100; k++) {
        b_fzg_array[k] = fzg_array->emoSpdMgd[150 * k];
      }

      whlTrq = interp1q(b_fzg_array, fzg_array->emoTrqMax_emoSpd, crsSpdVec[0]);

      /*  Die gültigen Kurbelwellenmomente müssen kleiner sein als das */
      /*  Gesamtmoment von E-Motor und Verbrennungsmotor */
      /*    The valid crankshaft moments must be less than the total moment of the */
      /*    electric motor and the ICE.Otherwise, leave the function */
      if (crsTrq > iceTrqMax + whlTrq) {
      } else {
        /* % %% Optimaler Momentensplit - Minimierung der Hamiltonfunktion */
        /*        optimum torque split - minimizing the Hamiltonian */
        /*  Die Vorgehensweise ist ähnlich wie bei der ECMS. Es wird ein Vektor der */
        /*  möglichen Batterieenergieänderungen aufgestellt. Aus diesen lässt sich  */
        /*  eine Batterieklemmleistung berechnen. Aus der über das */
        /*  Kurbelwellenmoment, ein Elektromotormoment berechnet werden kann. */
        /*  Über das geforderte Kurbelwellenmoment, kann für jedes Moment des  */
        /*  Elektromotors ein Moment des Verbrennungsmotors gefunden werden. Für  */
        /*  jedes Momentenpaar kann die Hamiltonfunktion berechnet werden. */
        /*  Ausgegeben wird der minimale Wert der Hamiltonfunktion und die */
        /*  durch das dabei verwendete Elektromotormoment verursachte */
        /*  Batterieladungs�nderung. */
        /*    The procedure is similar to ECMS. It's based on a vector of possible */
        /*    battery energy changes, from which a battery terminal power can be */
        /*    calculated. */
        /*    From the crankshaft torque, an electric motor torque can be */
        /*    calculated, and an engine torque can be found for every electric motor */
        /*    moment.  */
        /*    For every moment-pair the Hamiltonian can be calculated. It */
        /*    outputs the minimum Hamilotnian value and the battery charge change */
        /*    caused by the electric motor torque used. */
        /* % Elektromotor - Aufstellen des Batterienergievektors */
        /*    electric motor - positioning the battery energy vectors */
        if (batEngStp > 0.0) {
          /* Skalar - änderung der minimalen Batterieenergieänderung */
          /*  Skalar - änderung der maximalen Batterieenergieänderung */
          /*  FUNCTION CALL */
          /*       Skalar - Wegschrittweite */
          /*       Skalar - mittlere Geschwindigkeit im Intervall */
          /*    Skalar - Nebenverbraucherlast */
          /*       Skalar - Batterieenergie */
          /*   struct - Fahrzeugparameter - nur skalar */
          /*    struct - Fahrzeugparameter - nur array */
          /*       Skalar - crankshaft rotational speed */
          /*       Skalar - crankshaft torque */
          /*    Skalar - min ICE torque allowed */
          /*    Skalar - max ICE torque allowed */
          /*  Skalar - max EM torque possible */
          st.site = &j_emlrtRSI;

          /* Skalar - änderung der minimalen Batterieenergieänderung */
          /*  Skalar - änderung der maximalen Batterieenergieänderung */
          /*  Skalar - Wegschrittweite */
          /*  Skalar - Geschwindigkeit im Intervall */
          /*  Skalar - Nebenverbraucherlast */
          /*  Skalar - Batterieenergie */
          /*  struct - Fahrzeugparameter - nur skalar */
          /*  struct - Fahrzeugparameter - nur array */
          /*  Skalar - crankshaft rotational speed */
          /*  Skalar - crankshaft torque */
          /*  Skalar - min ICE torque allowed */
          /*  Skalar - max ICE torque */
          /*  Skalar - max EM torque possible */
          /* BatEngDltClc Calculates the change in battery energy */
          /*  */
          /*  Erstellungsdatum der ersten Version 17.11.2015 - Stephan Uebel */
          /*    Berechnung der Verluste des Elektromotors bei voller rein elektrischer */
          /*    Fahrt (voller Lastpunktabsenkung) und bei voller Lastpunktanhebung */
          /*        Calculations of loss of electric motor at purely full electric */
          /*        Driving (full load point lowering) and at full load point raising */
          /*  */
          /*  Version vom 17.02.2016: Keine Einbeziehung von Rotationsmassen */
          /*                          ^^ No inclusion of rotational masses */
          /*  */
          /*  Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit) */
          /*                          ^^ Zero-Order-Hold (no average velocities) */
          /* % Initialisieren der Ausgabe der Funktion */
          /*    initializing the function output (delta battery_energy min and max) */
          /* % Elektromotor */
          /*  minimales Moment, dass die E-Maschine liefern kann */
          /*    minimum moment that the EM can provide (max is an input to function) */
          /*  emoTrqMinPos = ... */
          /*      lininterp1(par.emoSpdMgd(1,:)',par.emoTrqMin_emoSpd,crsSpd); */
          for (k = 0; k < 100; k++) {
            b_fzg_array[k] = fzg_array->emoSpdMgd[150 * k];
          }

          emoTrqMinPos = interp1q(b_fzg_array, fzg_array->emoTrqMin_emoSpd,
            crsSpdVec[0]);

          /* % Verbrennungsmotor berechnen */
          /*  Durch EM zu lieferndes Kurbelwellenmoment */
          /*    crankshaft torque to be delivered by the electric motor (min and max) */
          emoTrqMax = crsTrq - iceTrqMin;
          batEngDltMinInx = crsTrq - iceTrqMax;

          /*  fprintf('emoTrqMax: %4.3f\n', emoTrqMax); */
          /*  fprintf('emoTrqMin: %4.3f\n', emoTrqMin); */
          /* % Elektromotor berechnen */
          /*    calculate the electric motor */
          if (whlTrq < emoTrqMax) {
            /*  Moment des Elektromotors bei maximaler Entladung der Batterie */
            /*    EM torque at max battery discharge */
            emoTrqMax = whlTrq;
          }

          if (whlTrq < batEngDltMinInx) {
            /*  Moment des Elektromotors bei minimaler Entladung der Batterie */
            /*    EM torque at min battery discharge */
            batEngDltMinInx = whlTrq;
          }

          emoTrqMax = muDoubleScalarMax(emoTrqMinPos, emoTrqMax);
          batEngDltMinInx = muDoubleScalarMax(emoTrqMinPos, batEngDltMinInx);

          /* % Berechnung der änderung der Batterieladung */
          /*    calculating the change in battery charge */
          /*  Interpolation der benötigten Batterieklemmleistung f�r das */
          /*  EM-Moment. Stellen die nicht definiert sind, werden mit inf */
          /*  ausgegeben. Positive Werte entsprechen entladen der Batterie. */
          /*    interpolating the required battery terminal power for the EM torque. */
          /*    Assign undefined values to inf. Positive values coresspond with battery */
          /*    discharge. */
          /*  batPwrMax = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),... */
          /*      par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMax) + batPwrAux; */
          /*   */
          /*  batPwrMin = lininterp2(par.emoSpdMgd(1,:),par.emoTrqMgd(:,1),... */
          /*      par.emoPwr_emoSpd_emoTrq',crsSpd,emoTrqMin) + batPwrAux; */
          b_st.site = &n_emlrtRSI;
          whlTrq = codegen_interp2(&b_st, fzg_array->emoSpdMgd,
            fzg_array->emoTrqMgd, fzg_array->emoPwr_emoSpd_emoTrq, crsSpdVec[0],
            emoTrqMax) + batPwrAux;
          b_st.site = &o_emlrtRSI;
          emoTrqMinPos = codegen_interp2(&b_st, fzg_array->emoSpdMgd,
            fzg_array->emoTrqMgd, fzg_array->emoPwr_emoSpd_emoTrq, crsSpdVec[0],
            batEngDltMinInx) + batPwrAux;

          /*  überprüfen, ob Batterieleistung möglich */
          /*    make sure that current battery max power is not above bat max bounds */
          if (whlTrq > fzg_scalar->batPwrMax) {
            whlTrq = fzg_scalar->batPwrMax;
          }

          /*  überprüfen, ob Batterieleistung möglich */
          /*    make sure that current battery min power is not above bat max bounds */
          if (emoTrqMinPos > fzg_scalar->batPwrMax) {
            emoTrqMinPos = fzg_scalar->batPwrMax;
          }

          /*  Es kann vorkommen, dass mehr Leistung gespeist werden soll, als */
          /*  m�glich ist. */
          /*    check that the max and min still remain within the min bounds */
          if (whlTrq < fzg_scalar->batPwrMin) {
            whlTrq = fzg_scalar->batPwrMin;
          }

          if (emoTrqMinPos < fzg_scalar->batPwrMin) {
            emoTrqMinPos = fzg_scalar->batPwrMin;
          }

          /*  Batteriespannung aus Kennkurve berechnen */
          /*    calculating battery voltage of characteristic curve - eq?-------------- */
          batOcv = batEng * fzg_array->batOcvCof_batEng[0] +
            fzg_array->batOcvCof_batEng[1];

          /*  FUNCTION CALL - min delta bat.energy */
          /*            Skalar - Batterieklemmleistung */
          /*                  Skalar - mittlere Geschwindigkeit im Intervall */
          /* Skalar - Entladewiderstand */
          /* Skalar - Ladewiderstand */
          /*                Skalar - battery open-circuit voltage */
          emoTrqMax = batFrcClc_port(whlTrq, vehVel, fzg_scalar->batRstDch,
            fzg_scalar->batRstChr, batOcv) * wayStp;

          /*  <-multiply by delta_S */
          /*  FUNCTION CALL - max delta bat.energy */
          /*            Skalar - Batterieklemmleistung */
          /*                  Skalar - mittlere Geschwindigkeit im Intervall */
          /* Skalar - Entladewiderstand */
          /* Skalar - Ladewiderstand */
          /*                Skalar - battery open-circuit voltage */
          whlTrq = batFrcClc_port(emoTrqMinPos, vehVel, fzg_scalar->batRstDch,
            fzg_scalar->batRstChr, batOcv) * wayStp;

          /*  Es werden 2 Fälle unterschieden: */
          /*    there are 2 different cases */
          if ((emoTrqMax > 0.0) && (whlTrq > 0.0)) {
            /*  battery will discharge */
            /*         %% konventionelles Bremsen + Rekuperieren */
            /*    conventional brakes + recuperation */
            /*  */
            /*  set change in energy to discretized integer values w/ ceil and */
            /*  floor. This also helps for easy looping */
            /*  Konventionelles Bremsen wird ebenfalls untersucht. */
            /*  Hier liegt eventuell noch Beschleunigungspotential, da diese */
            /*  Zustandswechsel u.U. ausgeschlossen werden können. */
            /*  NOTE: u.U. = unter Ümständen = circumstances permitting */
            /*    convetional breaks also investigated. An accelerating potential */
            /*    is still possible, as these states can be excluded */
            /*    (circumstances permitting)  <- ??? not sure what above means */
            /*  */
            /*    so if both min and max changes in battery energy are */
            /*    increasing, then set the delta min to zero */
            batEngDltMinInx = 0.0;
            whlTrq = muDoubleScalarFloor(whlTrq / batEngStp);
          } else {
            batEngDltMinInx = muDoubleScalarCeil(emoTrqMax / batEngStp);
            whlTrq = muDoubleScalarFloor(whlTrq / batEngStp);
          }
        } else {
          batEngDltMinInx = 0.0;
          whlTrq = 0.0;
        }

        /*  you got a larger min change than a max change-you're out of bounds. Leave */
        /*  the function */
        if (whlTrq < batEngDltMinInx) {
        } else {
          /* % Schleife über alle Elektromotormomente */
          /*    now loop through all the electric-motor torques */
          /*  why isn't batEngDltInx discretized wrt batEngStp?? */
          k = (int32_T)(whlTrq + (1.0 - batEngDltMinInx));
          emlrtForLoopVectorCheckR2012b(batEngDltMinInx, 1.0, whlTrq,
            mxDOUBLE_CLASS, k, &t_emlrtRTEI, sp);
          batEngDltInx = 0;
          while (batEngDltInx <= k - 1) {
            whlTrq = (batEngDltMinInx + (real_T)batEngDltInx) * batEngStp;

            /*  open circuit voltage over each iteration */
            batOcv = (batEng + whlTrq) * fzg_array->batOcvCof_batEng[0] +
              fzg_array->batOcvCof_batEng[1];

            /*           Skalar für die Batterieleistung in W */
            /*           Skalar Krafstoffkraft in N */
            /*             FUNCTION CALL */
            /*          Skalar für die Wegschrittweite in m, */
            /*           Skalar - vehicular velocity */
            /*        Nebenverbraucherlast */
            /*           Skalar - battery open circuit voltage */
            /*       Skalar - Batterieenergie�nderung, */
            /*           Skalar - crankshaft speed at given path_idx */
            /*           Skalar - crankshaft torque at given path_idx */
            /*        Skalar - min ICE torque allowed */
            /*        Skalar - max ICE torque */
            /*       struct - Fahrzeugparameter - nur skalar */
            /*         struct - Fahrzeugparameter - nur array */
            st.site = &i_emlrtRSI;

            /*   Skalar f�r die Batterieleistung */
            /*       Skalar Kraftstoffkraft */
            /*      Skalar f�r die Wegschrittweite in m */
            /*          vehicular velocity */
            /*    Nebenverbraucherlast */
            /*       Skalar - battery open circuit voltage */
            /*   Skalar - Batterieenergieänderung */
            /*       Skalar - crankshaft speed at given path_idx */
            /*       Skalar - crankshaft torque at given path_idx */
            /*    Skalar - min ICE torque allowed */
            /*    Skalar - max ICE torque */
            /*   struct - Fahrzeugparameter - nur skalar */
            /*     struct - Fahrzeugparameter - nur array */
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
            /* % Initialisieren der Ausgabe der Funktion */
            /*    initializing function output */
            /*    Skalar - electric battery power (W) */
            emoTrqMax = rtInf;

            /*    Skalar - fuel force intialization (N) */
            /* % Batterie */
            /*  Batterieenergieänderung über dem Weg (Batteriekraft) */
            /*    Change in battery energy over the path_idx way (ie battery power) */
            emoTrqMinPos = whlTrq / wayStp;

            /*  Fallunterscheidung, ob Batterie geladen oder entladen wird */
            /*    Case analysis - check if battery is charging or discharging. Set */
            /*    resistance accordingly */
            /*  elektrische Leistung des Elektromotors */
            /*    electric power from electric motor - DERIVATION? dunno */
            /*  innere Batterieleistung / internal batt power */
            /* dissipat. Leist. / dissipated */
            if (emoTrqMinPos < 0.0) {
              b_emoTrqMinPos = fzg_scalar->batRstDch;
            } else {
              b_emoTrqMinPos = fzg_scalar->batRstChr;
            }

            emoTrqMinPos = (-emoTrqMinPos * vehVel - emoTrqMinPos * emoTrqMinPos
                            * (vehVel * vehVel) / (batOcv * batOcv) *
                            b_emoTrqMinPos) - batPwrAux;

            /*           Nebenverbrauchlast / auxiliary power */
            /* % Elektromotor */
            /*  Ermitteln des Kurbelwellenmoments durch EM aus Batterieleistung */
            /*    determine crankshaft torque cauesd by EM's battery power */
            /*        switching out codegen_interp2 for lininterp2-just might work! */
            /*  */
            b_st.site = &p_emlrtRSI;
            whlTrq = codegen_interp2(&b_st, fzg_array->emoSpdMgd,
              fzg_array->emoPwrMgd, fzg_array->emoTrq_emoSpd_emoPwr, crsSpd,
              emoTrqMinPos);

            /*  emoTrq = lininterp2(par.emoSpdMgd(1,:), par.emoPwrMgd(:,1),... */
            /*      par.emoTrq_emoSpd_emoPwr',crsSpd,emoPwrEle); */
            if (muDoubleScalarIsInf(whlTrq)) {
            } else {
              /*  Grenzen des Elektromotors müssen hier nicht überprüft werden, da die */
              /*  Ladungsdeltas schon so gewählt wurden, dass das maximale Motormoment */
              /*  nicht überstiegen wird. */
              /*    Electric motor limits need not be checked here, since the charge deltas */
              /*    have been chosen so that the max torque is not exceeded. */
              /* % Verbrennungsmotor */
              /*  Ermitteln des Kurbelwellenmoments durch den Verbrennungsmotor */
              /*    Determining the crankshaft moment from the ICE */
              whlTrq = crsTrq - whlTrq;

              /*  Wenn das Verbrennungsmotormoment kleiner als das minimale */
              /*  Moment ist, ist dieser in der Schubabschaltung. Das */
              /*  verbleibende Moment liefern die Bremsen */
              /*    If engine torque is less than the min torque, fuel is cut. The */
              /*    remaining torque is deliver the brakes. */
              if (whlTrq < iceTrqMin) {
                whlTrq = 0.0;
              } else if (whlTrq > iceTrqMax) {
                whlTrq = rtInf;
              } else {
                /*  replacing another coden_interp2 no just find fuel power as usual */
                b_st.site = &q_emlrtRSI;
                whlTrq = codegen_interp2(&b_st, fzg_array->iceSpdMgd,
                  fzg_array->iceTrqMgd, fzg_array->iceFulPwr_iceSpd_iceTrq,
                  crsSpd, whlTrq);

                /*      fulPwr = lininterp2(par.iceSpdMgd(1,:), par.iceTrqMgd(:,1), ... */
                /*          par.iceFulPwr_iceSpd_iceTrq', crsSpd, iceTrq); */
              }

              /*  Berechnen der Kraftstoffkraft */
              /*    calculate fuel force */
              emoTrqMax = whlTrq / vehVel;

              /*  Berechnen der Kraftstoffvolumenänderung */
              /*  caluclate change in fuel volume - energy, no? */
              /* % Ende der Funktion */
            }

            /*       FUNCTION CALL */
            /*           Skalar - Batterieklemmleistung */
            /*           Skalar - mittlere Geschwindigkeit im Intervall */
            /*    Skalar - Entladewiderstand */
            /*    Skalar - Ladewiderstand */
            /*            Skalar - battery open circuit voltage */
            emoTrqMinPos = batFrcClc_port(emoTrqMinPos, vehVel,
              fzg_scalar->batRstDch, fzg_scalar->batRstChr, batOcv);

            /*     %% Hamiltonfunktion bestimmen */
            /*    determine the hamiltonian */
            /*  Eq (29b) */
            crsSpdVec[0] = (emoTrqMax + psiBatEng * emoTrqMinPos) + psiTim /
              vehVel;
            ixstart = 1;
            whlTrq = crsSpdVec[0];
            itmp = 1;
            if (muDoubleScalarIsNaN(crsSpdVec[0])) {
              ix = 2;
              exitg1 = false;
              while ((!exitg1) && (ix < 3)) {
                ixstart = 2;
                if (!muDoubleScalarIsNaN(*cosHamMin)) {
                  whlTrq = *cosHamMin;
                  itmp = 2;
                  exitg1 = true;
                } else {
                  ix = 3;
                }
              }
            }

            if ((ixstart < 2) && (*cosHamMin < whlTrq)) {
              whlTrq = *cosHamMin;
              itmp = 2;
            }

            *cosHamMin = whlTrq;

            /*  Wenn der aktuelle Punkt besser ist, als der in cosHamMin */
            /*  gespeicherte Wert, werden die Ausgabegrößen neu beschrieben. */
            /*    if the current point is better than the stored cosHamMin value, */
            /*    then the output values are rewritten (selected prev. value is = 2) */
            if (itmp == 1) {
              *batFrcOut = emoTrqMinPos;
              *fulFrcOut = emoTrqMax;
            }

            batEngDltInx++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }
        }
      }
    }
  }

  /*  end of function */
}

void crsSpdEmoMax_not_empty_init(void)
{
}

void crsSpdHybMax_not_empty_init(void)
{
  crsSpdHybMax_not_empty = false;
}

void crsSpdHybMin_not_empty_init(void)
{
}

/* End of code generation (clcPMP_olyHyb_port.c) */
