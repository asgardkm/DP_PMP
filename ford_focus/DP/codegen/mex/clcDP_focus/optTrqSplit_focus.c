/*
 * optTrqSplit_focus.c
 *
 * Code generation for function 'optTrqSplit_focus'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "optTrqSplit_focus.h"
#include "fprintf.h"
#include <stdio.h>

/* Variable Definitions */
static real_T crsSpdHybMax;
static boolean_T crsSpdHybMax_not_empty;
static real_T crsSpdHybMin;
static emlrtRSInfo y_emlrtRSI = { 181, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo ab_emlrtRSI = { 182, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo bb_emlrtRSI = { 183, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo cb_emlrtRSI = { 194, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo fb_emlrtRSI = { 60, "fulEngClc_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\fulEngClc_focus.m"
};

static emlrtDCInfo jb_emlrtDCI = { 42, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo vc_emlrtBCI = { 1, 100, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 41, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo lb_emlrtDCI = { 41, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo mb_emlrtDCI = { 36, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo nb_emlrtDCI = { 35, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo wc_emlrtBCI = { 1, 150, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo ob_emlrtDCI = { 35, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo pb_emlrtDCI = { 27, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo qb_emlrtDCI = { 27, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo xc_emlrtBCI = { 1, 100, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo rb_emlrtDCI = { 26, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo sb_emlrtDCI = { 26, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo tb_emlrtDCI = { 25, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo yc_emlrtBCI = { 1, 150, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo ub_emlrtDCI = { 25, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo ad_emlrtBCI = { 1, 100, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo vb_emlrtDCI = { 24, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo bd_emlrtBCI = { 1, 150, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo wb_emlrtDCI = { 24, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo xb_emlrtDCI = { 46, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtDCInfo yb_emlrtDCI = { 46, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

/* Function Definitions */
void crsSpdHybMax_not_empty_init(void)
{
  crsSpdHybMax_not_empty = false;
}

void crsSpdHybMin_not_empty_init(void)
{
}

real_T optTrqSplit_focus(const emlrtStack *sp, real_T brkBool, real_T batPwr,
  real_T batOcvPre, real_T batRst, real_T crsSpdPre, real_T crsTrqPre, real_T
  emoTrqMinPos, real_T emoTrqMaxPos, real_T emoPwrMinPos, real_T emoPwrMaxPos,
  real_T iceTrqMaxPos, real_T iceTrqMinPos, real_T timStp, const real_T
  vehVelVec[2], real_T fzg_scalar_struct_vehVelThresh, const struct2_T
  *fzg_array_struct)
{
  real_T fulEng;
  real_T batCur;
  real_T iceTrq;
  boolean_T guard1 = false;
  real_T idyi;
  real_T idxi;
  int32_T i9;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  skalar - allow states requireing braking? */
  /* CLCPMP Minimizing Hamiltonian: Co-States for soc and time */
  /*  Erstellungsdatum der ersten Version 19.08.2015 - Stephan Uebel */
  /*  */
  /*  Batterieleistungsgrenzen hinzugef√ºgt am 13.12.2015 */
  /*  ^^added battery power limit */
  /*  */
  /*  Massenaufschlag durch Tr√§gheitsmoment herausgenommen */
  /*  ^^Mass increment removed by inertia */
  /*  */
  /*  % 06.07.2016 - replacing KE state dimension with engine control */
  /*  is not necessarily PMP anymore, function is just now an objective */
  /*  minimaztion function for each DP state permutation. No costates are */
  /*  calculated. */
  /* % Inputdefinition */
  /*  engStaPre     - Double(1,1)  - engine state at start of interval (J) */
  /*  engStaAct     - Double(1,1)  - engine state at end of interval (J) */
  /*  gea           - Double(1,1)  - Gang */
  /*                                 ^^ gear */
  /*  slp           - Double(1,1)  - Steigung in rad */
  /*                                 ^^ slope in radians */
  /*  iceFlg        - Boolean(1,1) - Flag f√ºr Motorzustand-REMOVED 12.07.2016 */
  /*                                 ^^ flag for motor condition */
  /*  batEng        - Double(1,1)  - Batterieenergie in J */
  /*                                 ^^ battery energy (J) */
  /*  batPwrAux     - Double(1,1)  - elektr. Nebenverbraucherleistung in W */
  /*                                 ^^ electric auxiliary power consumed (W) */
  /*  batEngStp     - Double(1,1)  - Drehmomentschritt */
  /*                                 ^^ torque step <- no, it's a battery step */
  /*  timStp        - Double(1,1)  - Intervallschrittweite in m */
  /*                                 ^^ interval step distance - now [sec] */
  /*  fzg_scalar_struct    - Struct(1,1)  - Modelldaten - nur skalar */
  /*  fzg_array_struct     - Struct(1,1)  - Modelldaten - nur arrays                              */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing function output */
  /*  old initialization */
  /*  % Ausgabewert des Minimums der Hamiltonfunktion */
  /*  %   output for minimizing the hamiltonian */
  /*  minFulLvl = inf; */
  /*  % Batterieladungs√§nderung im Wegschritt beir minimaler Hamiltonfunktion */
  /*  %   battery change in path_idx step with the minial hamiltonian */
  /*  batFrcOut = inf; */
  /*  % Kraftstoffkraft√§nderung im Wegschritt bei minimaler Hamiltonfunktion */
  /*  %   fuel change in path_idx step with the minimal hamiltonian */
  /*  fulFrcOut = 0; */
  /*  new initialization */
  /*  intializing fuel energy output */
  fulEng = rtInf;

  /*  ------------------------------------------------------------------------- */
  /*  ----- Initialisieren der persistent Grˆﬂen ------------------------------ */
  /*    initialize the persistance variables */
  /*  Diese werden die nur einmal f‹r die Funktion berechnet */
  /*    only calculated once for the function */
  if (!crsSpdHybMax_not_empty) {
    /*  maximale Drehzahl Elektrommotor */
    /*    maximum electric motor rotational speed */
    /*  maximale Drehzahl der Kurbelwelle */
    /*    maximum crankshaft rotational speed */
    /*  12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY */
    /*  ARE WE SECTNIG THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE */
    /*  EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER? */
    crsSpdHybMax = muDoubleScalarMin(fzg_array_struct->iceSpdMgd[23],
      fzg_array_struct->emoSpdMgd[72]);
    crsSpdHybMax_not_empty = true;

    /*  minimale Drehzahl der Kurbelwelle */
    /*    minimum crankshaft rotational speed */
    crsSpdHybMin = fzg_array_struct->iceSpdMgd[0];
  }

  /*  ------------------------------------------------------------------------- */
  /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS --------------------------------- */
  /*  IS THERE A WAY TO BRING THE CHECKING OUT OF THIS FUNCTION? */
  /*  boundaries: */
  /*  Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen */
  /*  Modus */
  /*    stop if the crankshaft rotational speed is too high in hybrid mode */
  if ((crsSpdPre > crsSpdHybMax) || (crsSpdPre < crsSpdHybMin)) {
  } else {
    /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
    /*  Leerlaufdrehzahl ist, */
    /*    stop if crankhaft rotional speed is lower than the idling speed */
    /*  ------------------------------------------------------------------------- */
    /*  ----- DERIVE emoPwr FROM batPwr STATE ----------------------------------- */
    /*  from the given batPwr, derive emoPwr from equation: */
    /*    emoPwr = batPwr - batPwrLoss, */
    /*  where */
    /*    batPwr      = batOcv * I, and */
    /*    batPwrLoss  = I^2 * batRst.  */
    /*  lookup battery voltage for the given battery state - batOcvPre */
    /*  therefore, current I = batPwr/batOcvPre */
    batCur = batPwr / batOcvPre;

    /*  can now caculate battery losses: */
    /*  find emoPwr */
    batCur = batPwr - batCur * batCur * batRst;

    /*  emoPwr bound checking */
    if ((emoPwrMinPos > batCur) || (emoPwrMaxPos < batCur)) {
    } else {
      /*  ------------------------------------------------------------------------- */
      /*  ----- DERIVE emoTrq FROM emoPwr ---------------------------------------- */
      /*  Power = Torque * rotational vel. */
      /*  therefore, */
      /*  Torque = Power / Vel */
      batCur /= crsSpdPre;

      /*  emoTrq bound checking */
      if ((emoTrqMinPos > batCur) || (emoTrqMaxPos < batCur) || (crsTrqPre >
           iceTrqMaxPos + batCur)) {
      } else {
        /*  ------------------------------------------------------------------------- */
        /*  ----- CALCUALTE  crsTrq ------------------------------------------------- */
        /*  check that the demanded crsTrq is not above max possible torque that */
        /*  can be generated between the ice and the em */
        /*  torque split */
        iceTrq = crsTrqPre - batCur;

        /*  iceTrq boundary check */
        /*  check if iceTrq is too high or low based on iceTrqMax/MinPos */
        if ((iceTrq > iceTrqMaxPos) || (iceTrq < iceTrqMinPos)) {
        } else {
          /*  HOW TO DEAL WITH BREAK BOOL? */
          /*  if brkBool is true - allow for braking to reduce  */
          guard1 = false;
          if (brkBool != 0.0) {
            /*  if iceTrq is negative (which it can't be in this case), don't */
            /*  brake with with engine! Rather, brake with the brakes. */
            /*  BUT! this shouldn't trigger, as this is not optimal! */
            if (iceTrq < 0.0) {
              batCur = iceTrq;
              iceTrq = iceTrqMinPos;
              st.site = &y_emlrtRSI;
              b_fprintf(&st);
              st.site = &ab_emlrtRSI;
              d_fprintf(&st, batCur);
              st.site = &bb_emlrtRSI;
              f_fprintf(&st, iceTrqMinPos);
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            /*  ------------------------------------------------------------------------- */
            /*  ----- CALCULATE fulEng USE ---------------------------------------------- */
            /*  Skalar Krafstoffkraft in N */
            /*  FUNCTION CALL */
            /*  Skalar f¸r die Wegschrittweite in m, */
            /*  Skalar - vehicular velocity */
            /*  Skalar - crankshaft speed at given path_idx */
            /*  Skalar - ice torque at given path_idx */
            /*  Skalar - max ICE torque */
            /*  struct - Fahrzeugparameter - nur skalar */
            /*  struct - Fahrzeugparameter - nur array */
            st.site = &cb_emlrtRSI;

            /*  Skalar Kraftstoffkraft */
            /*  Skalar f¸r die Wegschrittweite in m */
            /*  vehicular velocity */
            /*  Skalar - crankshaft speed at given path_idx */
            /*  Skalar - ice torque at given path_idx */
            /*  Skalar - max ICE torque */
            /*  struct - Fahrzeugparameter - nur skalar */
            /*  struct - Fahrzeugparameter - nur array */
            /*  */
            /* FULENGCLC Calculating fuel consumption */
            /*  Erstellungsdatum der ersten Version 04.09.2015 - Stephan Uebel */
            /*  */
            /*  Diese Funktion berechnet den Kraftstoffverbrauch f¸r einen gegebenen */
            /*  Wegschritt der kinetischen Energie, der Batterieenergie und des */
            /*  Antriebsstrangzustands ¸ber dem Weg. */
            /*    this function calculates fuel consumption for a given route step of */
            /*    KE, the battery energy, and drivetrain state of the current path_idx */
            /*  */
            /*  Version vom 17.02.2016 : Rotationsmassen vernachl‰ssigt */
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
            if (vehVelVec[0] < muDoubleScalarAbs(fzg_scalar_struct_vehVelThresh))
            {
              fulEng = 0.0;
            } else if (iceTrq > iceTrqMaxPos) {
            } else {
              /*  calculate fuel power */
              b_st.site = &fb_emlrtRSI;

              /*  zi = codegen_interp2(X,Y,Z,xi,yi) gives the same result as */
              /*  interp2(X,Y,Z,xi,yi) */
              /*  Unlike interp2, codegen_interp2 is compatible with code generation */
              /*  Only linear interpolation is available */
              /*  Usage restrictions */
              /*    X and Y must have the same size as Z */
              /*    e.g.,  [X,Y] = meshgrid(x,y); */
              idyi = (crsSpdPre - fzg_array_struct->iceSpdMgd[0]) * (1.0 /
                (fzg_array_struct->iceSpdMgd[1] - fzg_array_struct->iceSpdMgd[0]))
                + 1.0;
              idxi = (iceTrq - fzg_array_struct->iceTrqMgd[0]) * (1.0 /
                (fzg_array_struct->iceTrqMgd[1] - fzg_array_struct->iceTrqMgd[0]))
                + 1.0;
              if ((idxi <= 1.0) || (idyi <= 1.0) || (idxi > 38.0) || (idyi >
                   24.0) || muDoubleScalarIsNaN(crsSpdPre) ||
                  muDoubleScalarIsNaN(iceTrq)) {
                batCur = rtInf;
              } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
                          muDoubleScalarCeil(idyi) != 1.0)) {
                batCur = muDoubleScalarCeil(idxi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &wb_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 150, &bd_emlrtBCI,
                  &b_st);
                batCur = muDoubleScalarCeil(idyi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &vb_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 100, &ad_emlrtBCI,
                  &b_st);
                batCur = muDoubleScalarCeil(idxi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &ub_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 150, &yc_emlrtBCI,
                  &b_st);
                batCur = muDoubleScalarCeil(idyi);
                emlrtIntegerCheckFastR2012b(batCur, &tb_emlrtDCI, &b_st);
                batCur = muDoubleScalarCeil(idxi);
                emlrtIntegerCheckFastR2012b(batCur, &sb_emlrtDCI, &b_st);
                batCur = muDoubleScalarCeil(idyi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &rb_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 100, &xc_emlrtBCI,
                  &b_st);
                batCur = muDoubleScalarCeil(idxi);
                emlrtIntegerCheckFastR2012b(batCur, &qb_emlrtDCI, &b_st);
                batCur = muDoubleScalarCeil(idyi);
                emlrtIntegerCheckFastR2012b(batCur, &pb_emlrtDCI, &b_st);
                batCur = ((fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                            (muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)
                  (muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] *
                           (muDoubleScalarCeil(idxi) - idxi) *
                           (muDoubleScalarCeil(idyi) - idyi) +
                           fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                            (muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)
                  muDoubleScalarCeil(idyi) - 1)) - 1] * (muDoubleScalarCeil(idxi)
                            - idxi) * (1.0 - (muDoubleScalarCeil(idyi) - idyi)))
                          + fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                           muDoubleScalarCeil(idxi) + 150 * ((int32_T)
                            (muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] * (1.0 -
                           (muDoubleScalarCeil(idxi) - idxi)) *
                          (muDoubleScalarCeil(idyi) - idyi)) +
                  fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                  muDoubleScalarCeil(idxi) + 150 * ((int32_T)muDoubleScalarCeil
                  (idyi) - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) - idxi)) *
                  (1.0 - (muDoubleScalarCeil(idyi) - idyi));
              } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
                          muDoubleScalarCeil(idyi) == 1.0)) {
                batCur = muDoubleScalarCeil(idxi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &ob_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 150, &wc_emlrtBCI,
                  &b_st);
                emlrtIntegerCheckFastR2012b(idyi, &nb_emlrtDCI, &b_st);
                batCur = muDoubleScalarCeil(idxi);
                emlrtIntegerCheckFastR2012b(batCur, &mb_emlrtDCI, &b_st);
                batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                  (muDoubleScalarCeil(idxi) - 1.0) + 150 * ((int32_T)idyi - 1))
                  - 1] * (muDoubleScalarCeil(idxi) - idxi) +
                  fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                  muDoubleScalarCeil(idxi) + 150 * ((int32_T)idyi - 1)) - 1] *
                  (1.0 - (muDoubleScalarCeil(idxi) - idxi));
              } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (idyi /
                          muDoubleScalarCeil(idyi) != 1.0)) {
                emlrtIntegerCheckFastR2012b(idxi, &lb_emlrtDCI, &b_st);
                batCur = muDoubleScalarCeil(idyi) - 1.0;
                i9 = (int32_T)emlrtIntegerCheckFastR2012b(batCur, &kb_emlrtDCI,
                  &b_st);
                emlrtDynamicBoundsCheckFastR2012b(i9, 1, 100, &vc_emlrtBCI,
                  &b_st);
                batCur = muDoubleScalarCeil(idyi);
                emlrtIntegerCheckFastR2012b(batCur, &jb_emlrtDCI, &b_st);
                batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                  idxi + 150 * ((int32_T)(muDoubleScalarCeil(idyi) - 1.0) - 1))
                  - 1] * (muDoubleScalarCeil(idyi) - idyi) +
                  fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)idxi + 150
                  * ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 -
                  (muDoubleScalarCeil(idyi) - idyi));
              } else {
                batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                  emlrtIntegerCheckFastR2012b(idxi, &xb_emlrtDCI, &b_st) + 150 *
                  ((int32_T)emlrtIntegerCheckFastR2012b(idyi, &yb_emlrtDCI,
                  &b_st) - 1)) - 1];
              }

              /*  since P = E/t, then E=P*t */
              fulEng = batCur * timStp;
            }

            /* % Ende der Funktion */
            /*  ------------------------------------------------------------------------- */
            /*  else  */
            /*      % if engine is considered off - no torque is coming from the ice */
            /*      iceTrq = 0; */
            /*      fulEng = 0; */
            /*  end    */
            /*  END OF optTrqSplit_focus() */
            /* % OLD CODE */
            /*  %% STEPS */
            /*  % 1. calculate power demanded from this battery energy change */
            /*  % 2. interpolate EM torque from this power demand */
            /*  %   2a. in order to interpolate, need to find crankshaft velocity */
            /*  % 3. use this EM torque to find ICE torque to satisfy rest of demand */
            /*  %   3a. first find total crankshaft torque demand */
            /*  % 4. find resultant fuel consumption to make this ICE torque happen */
            /*   */
            /*  %% 1. calculate battery power demand */
            /*  % calculate power required by battery for E' */
            /*  % P = E/t = E'/t' */
            /*  % batPwr = batStaDlt / timStp; */
            /*   */
            /*  %% 2. interpolate batttery/EM torque */
            /*  %   2a. find crsSpdPre */
            /*   */
            /*  % vorzeitiger Funktionsabbruch? */
            /*  %   premature function termination? */
            /*  % Drehzahl der Kurbelwelle und Grenzen */
            /*  %   crankshaft speed and limits */
            /*   */
            /*  % Aus den kinetischen Energien des Fahrzeugs wird √ºber die Raddrehzahl */
            /*  % und die √ºbersetzung vom Getriebe die Kurbelwellendrehzahl berechnet. */
            /*  % Zeilenrichtung entspricht den G√§ngen. (Zeilenvektor) */
            /*  %   from the vehicle's kinetic energy, the crankshaft speed is calculated */
            /*  %   by the speed and gearbox translation. Line direction corresponding to */
            /*  %   the aisles (row rector). EQUATION 1 */
            /*  % */
            /*  % since a speed profile is being provided and velocity does not have to be */
            /*  % calculated for every KE state (they do not exist here), velocity for the */
            /*  % crs can be calculated vector style for each gear, as vehVel can be */
            /*  % inputted as a vector */
            /*  % */
            /*  % but may need to do this time index by time index instead */
            /*  % crsSpdVec  = fzg_array_struct.geaRat(gea) * vehVelVec / (fzg_scalar_struct.whlDrr); */
            /*   */
            /*  % IS THERE A WAY TO BRING THE CHECKING OUT OF THIS FUNCTION? */
            /*  % boundaries: */
            /*  % Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen */
            /*  % Modus */
            /*  %   stop if the crankshaft rotational speed is too high in hybrid mode */
            /*  if engStaPre && any(crsSpdVec > crsSpdHybMax) */
            /*      return; */
            /*  end */
            /*   */
            /*  % Falls die Drehzahl des Verbrennungsmotors niedriger als die */
            /*  % Leerlaufdrehzahl ist, */
            /*  %   stop if crankhaft rotional speed is lower than the idling speed */
            /*  if engStaPre && any(crsSpdVec < crsSpdHybMin) */
            /*      return; */
            /*  end */
            /*   */
            /*  % Pr¸fen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
            /*  %   check if electric motor speed limit is maintained */
            /*  if ~engStaPre && any(crsSpdVec > crsSpdEmoMax) */
            /*      return; */
            /*  end */
            /*   */
            /*  % NEED THE FOLLOWING INPUTS */
            /*  % crsSpdPre */
            /*  % crsTrq */
            /*  % vehicle velocity (?) */
            /*  % emoTrq */
            /*  % iceTrqBounds */
            /*   */
            /*  % use previous time idx's crankshaft rotational speed for calculations */
            /*  % crsSpdPre = crsSpdVec(1); */
            /*  % use previous vehicle velocity time index for calculations */
            /*  % vehVel = vehVelVec(1); */
            /*   */
            /*  %   2b. interpolate */
            /*  %       - in order to interpolate, need the following: */
            /*  %       - battery resistance */
            /*  %       - OCV lookup based on current SOC */
            /*  %       - bat_Pwr -> emo_Pwr conversion */
            /*   */
            /*  % % resistance calulation */
            /*  % % BUT - is batPwr == emoPwr?? Or do we need a conversion?? */
            /*  % % if so, include conversion below */
            /*  % if batPwr < 0 */
            /*  %     batRst = fzg_scalar_struct.batRstDch; */
            /*  % else */
            /*  %     batRst = fzg_scalar_struct.batRstChr; */
            /*  % end */
            /*  %  */
            /*  % % ocv lookup */
            /*  % % calculate SOC value */
            /*  % batSoc = batStaPre / batEngMax; */
            /*  % batOcv = interp1q(fzg_array_struct.SOC_vs_OCV(:,1), fzg_array_struct.SOC_vs_OCV(:,2), batSoc); */
            /*   */
            /*  % elektrische Leistung des Elektromotors */
            /*  %   electric power from electric motor - DERIVATION? dunno */
            /*  % emoPwrEle = -batPwr * vehVel ... innere Batterieleistung / internal batt power */
            /*  %     - batPwr^2 * vehVel^2 / batOcv^2 * batRst...dissipat. Leist. / dissipated */
            /*  %     - batPwrAux; ...          Nebenverbrauchlast / auxiliary power */
            /*  % if just assuming the same:    */
            /*  % emoPwrEle = batPwr */
            /*  % */
            /*  % NEW POWER CALCULATION */
            /*  % emoPwr = batPwr - batPwrLosses */
            /*   */
            /*  % %% 3. find emoTrq from power calculations */
            /*  % % interpolation */
            /*  % emoTrq = interp2(fzg_array_struct.emoSpdMgd,fzg_array_struct.emoPwrMgd,... */
            /*  %                 fzg_array_struct.emoTrq_emoSpd_emoPwr, crsSpdPre, emoPwrEle); */
            /*   */
            /*  %% 4. find complementary ICE torque */
            /*      %4a. find total demanded crankshaft torque   */
            /*   */
            /*  % Getriebe¸bersetzung und -verlust */
            /*  %   gear ratio and loss */
            /*   */
            /*  % Berechnung des Kurbelwellenmoments */
            /*  % Hier muss unterschieden werden, ob das Radmoment positiv oder */
            /*  % negativ ist, da nur ein einfacher Wirkungsgrad f¸r das Getriebe */
            /*  % genutzt wird */
            /*  %   it's important to determine sign of crankshaft torque (positive or */
            /*  %   negative), since only a simple efficiency is used for the transmission */
            /*  %   PART OF EQ4  <- perhaps reversed? not too sure */
            /*  % if whlTrqPre < 0 */
            /*  %     crsTrq = whlTrqPre / fzg_array_struct.geaRat(gea) * fzg_array_struct.geaEfy(gea); */
            /*  % else */
            /*  %     crsTrq = whlTrqPre / fzg_array_struct.geaRat(gea) / fzg_array_struct.geaEfy(gea); */
            /*  % end */
            /*   */
            /*  % NEED SOME CHECKS */
            /*  % - max/min torque boundaries */
            /*  % - condition that iceTrq must be zero if engStaPre=0 */
            /*   */
            /*  %   QUESTION : CAN ICE RUN UNDER THE LOWEST CRSSPD GIVEN (HERE 89.0118) OR */
            /*  %   IS THIS A CUTOFF THAT THE ICE CANNOT RUN? */
            /*  %       - solved: can't run under 89 */
            /*  % if engStaPre */
            /*  %     % max torque that ice can provide at current crsSpdPre - from interpolation */
            /*  %     iceTrqMaxPos = interp1q(fzg_array_struct.iceSpdMgd(1,:)',fzg_array_struct.iceTrqMax_emoSpd(:,2),crsSpdPre); */
            /*  %     % min torque that ice can provide at current crsSpdPre - from interpolation */
            /*  %     iceTrqMinPos = interp1q(fzg_array_struct.iceSpdMgd(1,:)',fzg_array_struct.iceTrqMin_emoSpd(:,2),crsSpdPre); */
            /* % OLD OLD CODE */
            /*  NOTE: if the engine is off, the EM cannot fluctuate how much torque to  */
            /*  assign to the crankshaft, since it must satisfy ALL the demanded torque */
            /*  - there is no partial split. */
            /*  as a result, the same batEngDlt value will be used for min and max. But, */
            /*  the max value of the two must be used, since undershooting the minimum */
            /*  needed torque will not do. */
            /*  if ~engStaPre */
            /*      batEngDltTmpVec     = [batEngDltMinInx batEngDltMaxInx]; */
            /*     [~, batEngDltTmpInx] = max(abs(batEngDltTmpVec)); */
            /*     batEngDltMinInx      = batEngDltTmpVec(batEngDltTmpInx); */
            /*     batEngDltMaxInx      = batEngDltMinInx; */
            /*  end */
            /*  % %     % calculate the battery force required for specified fuel energy level */
            /*  % % %     batFrc = batFrcClc_a(...      FUNCTION CALL */
            /*  % % %         batPwr,...          Skalar - Batterieklemmleistung */
            /*  % % %         vehVel,...          Skalar - mittlere Geschwindigkeit im Intervall */
            /*  % % %         fzg_scalar_struct.batRstDch,...   Skalar - Entladewiderstand */
            /*  % % %         fzg_scalar_struct.batRstChr,...   Skalar - Ladewiderstand */
            /*  % % %         fzg_scalar_struct.vehVelThresh,... */
            /*  % % %         batOcv...           Skalar - battery open circuit voltage */
            /*  % % %         );     */
            /*  %% Hamiltonfunktion bestimmen */
            /*  %   determine the hamiltonian */
            /*  % Eq (29b) */
            /*  [minFulLvl,optPreInx] = min([fulEng,minFulLvl]); */
            /*   */
            /*  % Wenn der aktuelle Punkt besser ist, als der in cosHamMin */
            /*  % gespeicherte Wert, werden die Ausgabegrˆﬂen neu beschrieben. */
            /*  %   if the current point is better than the stored cosHamMin value, */
            /*  %   then the output values are rewritten (selected prev. value is = 2) */
            /*  if optPreInx == 1 */
            /*      fulFrcOut = fulEng; */
            /*  end */
          }
        }
      }
    }
  }

  /*  end of function */
  return fulEng;
}

/* End of code generation (optTrqSplit_focus.c) */
