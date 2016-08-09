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
static emlrtRSInfo y_emlrtRSI = { 155, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo ab_emlrtRSI = { 156, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo bb_emlrtRSI = { 157, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo cb_emlrtRSI = { 167, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo fb_emlrtRSI = { 62, "fulEngClc_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\fulEngClc_focus.m"
};

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 42, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 42, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 42, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 41, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 41, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo lb_emlrtDCI = { 41, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 36, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 36, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 36, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 35, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 35, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo ob_emlrtDCI = { 35, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 27, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo pb_emlrtDCI = { 27, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 27, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo qb_emlrtDCI = { 27, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo rb_emlrtDCI = { 26, 21, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 26, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo sb_emlrtDCI = { 26, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 25, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo tb_emlrtDCI = { 25, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo ub_emlrtDCI = { 25, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo vb_emlrtDCI = { 24, 23, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo wb_emlrtDCI = { 24, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 15, 46, "Y", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 15, 16, "X", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 13, 51, "Y", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 13, 44, "Y", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 13, 21, "X", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 13, 14, "X", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 46, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo xb_emlrtDCI = { 46, 10, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 46, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtDCInfo yb_emlrtDCI = { 46, 15, "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  1 };

/* Function Definitions */
real_T optTrqSplit_focus(const emlrtStack *sp, real_T brkBool, real_T batPwr,
  real_T batOcvPre, real_T batRst, real_T crsSpdPre, real_T crsTrqPre, real_T
  emoTrqMinPos, real_T emoTrqMaxPos, real_T emoPwrMinPos, real_T emoPwrMaxPos,
  real_T iceTrqMaxPos, real_T iceTrqMinPos, real_T crsSpdHybMax, real_T
  crsSpdHybMin, real_T timStp, const real_T vehVelVec[2], const struct1_T
  *fzg_scalar_struct, const struct2_T *fzg_array_struct)
{
  real_T fulEng;
  real_T batCur;
  real_T iceTrq;
  boolean_T guard1 = false;
  int32_T i9;
  real_T idyi;
  real_T idxi;
  boolean_T guard2 = false;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  skalar - allow states requireing braking? */
  /*  % maximum crankshaft rotational speed */
  /*  % minimum crankshaft rotational speed */
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
        /*  ----- CALCUALTE crsTrq -------------------------------------------------- */
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
          if (iceTrq < 0.0) {
            /*  if iceTrq is negative (which it can't be in this case), don't */
            /*  brake with with engine! Rather, brake with the brakes. */
            /*  BUT! this shouldn't trigger, as this is not optimal! */
            if (brkBool != 0.0) {
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
            /*  struct - Fahrzeugparameter - nur array */
            st.site = &cb_emlrtRSI;

            /*  Skalar Kraftstoffkraft */
            /*  Skalar f¸r die Wegschrittweite in m */
            /*  vehicular velocity */
            /*  Skalar - crankshaft speed at given path_idx */
            /*  Skalar - ice torque at given path_idx */
            /*  Skalar - max ICE torque */
            /*  struct - Fahrzeugparameter - nur skalar */
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
            if (vehVelVec[0] < muDoubleScalarAbs(fzg_scalar_struct->vehVelThresh))
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
              i9 = fzg_array_struct->iceSpdMgd->size[1];
              emlrtDynamicBoundsCheckFastR2012b(2, 1, i9, &td_emlrtBCI, &b_st);
              i9 = fzg_array_struct->iceSpdMgd->size[1];
              emlrtDynamicBoundsCheckFastR2012b(1, 1, i9, &sd_emlrtBCI, &b_st);
              i9 = fzg_array_struct->iceTrqMgd->size[0];
              emlrtDynamicBoundsCheckFastR2012b(2, 1, i9, &rd_emlrtBCI, &b_st);
              i9 = fzg_array_struct->iceTrqMgd->size[0];
              emlrtDynamicBoundsCheckFastR2012b(1, 1, i9, &qd_emlrtBCI, &b_st);
              i9 = fzg_array_struct->iceSpdMgd->size[1];
              emlrtDynamicBoundsCheckFastR2012b(1, 1, i9, &pd_emlrtBCI, &b_st);
              idyi = (crsSpdPre - fzg_array_struct->iceSpdMgd->data[0]) * (1.0 /
                (fzg_array_struct->iceSpdMgd->data[fzg_array_struct->
                 iceSpdMgd->size[0]] - fzg_array_struct->iceSpdMgd->data[0])) +
                1.0;
              i9 = fzg_array_struct->iceTrqMgd->size[0];
              emlrtDynamicBoundsCheckFastR2012b(1, 1, i9, &od_emlrtBCI, &b_st);
              idxi = (iceTrq - fzg_array_struct->iceTrqMgd->data[0]) * (1.0 /
                (fzg_array_struct->iceTrqMgd->data[1] -
                 fzg_array_struct->iceTrqMgd->data[0])) + 1.0;
              guard2 = false;
              if ((idxi <= 1.0) || (idyi <= 1.0)) {
                guard2 = true;
              } else {
                i9 = fzg_array_struct->iceTrqMgd->size[0];
                if (idxi > i9) {
                  guard2 = true;
                } else {
                  i9 = fzg_array_struct->iceSpdMgd->size[1];
                  if ((idyi > i9) || muDoubleScalarIsNaN(crsSpdPre) ||
                      muDoubleScalarIsNaN(iceTrq)) {
                    guard2 = true;
                  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
                              muDoubleScalarCeil(idyi) != 1.0)) {
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &wb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &nd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &vb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &md_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &ub_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &ld_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &tb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &kd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &sb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &jd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &rb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &id_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &qb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &hd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &pb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &gd_emlrtBCI,
                      &b_st);
                    batCur = ((fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                               [((int32_T)(muDoubleScalarCeil(idxi) - 1.0) +
                                 fzg_array_struct->iceFulPwr_iceSpd_iceTrq->
                                 size[0] * ((int32_T)(muDoubleScalarCeil(idyi) -
                      1.0) - 1)) - 1] * (muDoubleScalarCeil(idxi) - idxi) *
                               (muDoubleScalarCeil(idyi) - idyi) +
                               fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                               [((int32_T)(muDoubleScalarCeil(idxi) - 1.0) +
                                 fzg_array_struct->iceFulPwr_iceSpd_iceTrq->
                                 size[0] * ((int32_T)muDoubleScalarCeil(idyi) -
                      1)) - 1] * (muDoubleScalarCeil(idxi) - idxi) * (1.0 -
                                (muDoubleScalarCeil(idyi) - idyi))) +
                              fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                              [((int32_T)muDoubleScalarCeil(idxi) +
                                fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size
                                [0] * ((int32_T)(muDoubleScalarCeil(idyi) - 1.0)
                                       - 1)) - 1] * (1.0 - (muDoubleScalarCeil
                                (idxi) - idxi)) * (muDoubleScalarCeil(idyi) -
                               idyi)) +
                      fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data[((int32_T)
                      muDoubleScalarCeil(idxi) +
                      fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                      ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 -
                      (muDoubleScalarCeil(idxi) - idxi)) * (1.0 -
                      (muDoubleScalarCeil(idyi) - idyi));
                  } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (idyi /
                              muDoubleScalarCeil(idyi) == 1.0)) {
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &ob_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &fd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(idyi,
                      &nb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &ed_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    batCur = muDoubleScalarCeil(idxi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &mb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &dd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    i10 = (int32_T)idyi;
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &cd_emlrtBCI,
                      &b_st);
                    batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                      [((int32_T)(muDoubleScalarCeil(idxi) - 1.0) +
                        fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                        ((int32_T)idyi - 1)) - 1] * (muDoubleScalarCeil(idxi) -
                      idxi) + fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                      [((int32_T)muDoubleScalarCeil(idxi) +
                        fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                        ((int32_T)idyi - 1)) - 1] * (1.0 - (muDoubleScalarCeil
                      (idxi) - idxi));
                  } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (idyi /
                              muDoubleScalarCeil(idyi) != 1.0)) {
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(idxi,
                      &lb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &bd_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi) - 1.0;
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &kb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &ad_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    i10 = (int32_T)idxi;
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &yc_emlrtBCI,
                      &b_st);
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    batCur = muDoubleScalarCeil(idyi);
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(batCur,
                      &jb_emlrtDCI, &b_st);
                    emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &xc_emlrtBCI,
                      &b_st);
                    batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                      [((int32_T)idxi +
                        fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                        ((int32_T)(muDoubleScalarCeil(idyi) - 1.0) - 1)) - 1] *
                      (muDoubleScalarCeil(idyi) - idyi) +
                      fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data[((int32_T)
                      idxi + fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                      ((int32_T)muDoubleScalarCeil(idyi) - 1)) - 1] * (1.0 -
                      (muDoubleScalarCeil(idyi) - idyi));
                  } else {
                    i9 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0];
                    i10 = (int32_T)emlrtIntegerCheckFastR2012b(idxi,
                      &xb_emlrtDCI, &b_st);
                    i11 = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[1];
                    i12 = (int32_T)emlrtIntegerCheckFastR2012b(idyi,
                      &yb_emlrtDCI, &b_st);
                    batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq->data
                      [(emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9,
                         &ud_emlrtBCI, &b_st) +
                        fzg_array_struct->iceFulPwr_iceSpd_iceTrq->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(i12, 1, i11,
                          &vd_emlrtBCI, &b_st) - 1)) - 1];
                  }
                }
              }

              if (guard2) {
                batCur = rtInf;
              }

              /*  since P = E/t, then E=P*t */
              fulEng = batCur * timStp;
            }

            /* % Ende der Funktion */
            /*  ------------------------------------------------------------------------- */
            /*  END OF optTrqSplit_focus() */
          }
        }
      }
    }
  }

  /*  end of function */
  return fulEng;
}

/* End of code generation (optTrqSplit_focus.c) */
