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
#include "codegen_interp2.h"
#include "clcDP_focus_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 130, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo bb_emlrtRSI = { 185, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo cb_emlrtRSI = { 186, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo db_emlrtRSI = { 187, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo eb_emlrtRSI = { 198, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

static emlrtRSInfo hb_emlrtRSI = { 63, "fulEngClc_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\fulEngClc_focus.m"
};

static emlrtBCInfo ie_emlrtBCI = { 1, 35, 41, 15, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo je_emlrtBCI = { 1, 38, 35, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ke_emlrtBCI = { 1, 35, 26, 21, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo le_emlrtBCI = { 1, 38, 25, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo me_emlrtBCI = { 1, 35, 24, 23, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

static emlrtBCInfo ne_emlrtBCI = { 1, 38, 24, 10, "Z", "codegen_interp2",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\codegen_interp2.m",
  0 };

/* Function Definitions */
void optTrqSplit_focus(const emlrtStack *sp, real_T brkBool, real_T batPwr,
  real_T batOcvPre, real_T batRst, real_T crsSpdPre, real_T crsTrqPre, real_T
  emoTrqMinPos, real_T emoTrqMaxPos, real_T emoPwrMinPos, real_T emoPwrMaxPos,
  real_T iceTrqMaxPos, real_T iceTrqMinPos, real_T crsSpdHybMax, real_T
  crsSpdHybMin, real_T timStp, real_T batPwrAux, const real_T vehVelVec[2],
  const struct2_T *fzg_scalar_struct, const struct3_T *fzg_array_struct, real_T *
  fulEng, real_T *emoTrq, real_T *iceTrq, real_T *brkTrq)
{
  real_T batCur;
  boolean_T guard1 = false;
  real_T idxi;
  real_T d0;
  int32_T i9;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  skalar - state predecessor resultant fuel value */
  /*  skalar - state predecessor resultant emoTrq */
  /*  skalar - state predecessor resultant iceTrq */
  /*  skalar - state predecessor resultant brkTrq */
  /*  bool - allow states requireing braking? */
  /*  skalar - current battery power being analzyed */
  /*  skalar - battery predecessor OC voltage */
  /*  skalar - battery resistance */
  /*  skalar - predecessor crankshaft speed */
  /*  skalar - predecessor crankshaft torque */
  /*  skalar - min boundary for predecessor emoTrq */
  /*  skalar - max boundary for predecessor emoTrq */
  /*  skalar - min boundary for predecessor emoPwr */
  /*  skalar - max boundary for predecessor emoPwr */
  /*  skalar - min boundary for predecessor iceTrq */
  /*  skalar - max boundary for predecessor iceTrq */
  /*  skalar - maximum crankshaft rotational speed */
  /*  skalar - minimum crankshaft rotational speed */
  /*  skalar - time step size */
  /*  skalar - auxiiary power demanded from battery */
  /*  vector - predecessor and current vehicle speed */
  /*  struct - contains skalar vehicular parameters */
  /*  struct - contains vector vehicular paarameters */
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
  *fulEng = rtInf;
  *emoTrq = 0.0;
  *iceTrq = 0.0;
  *brkTrq = 0.0;

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
    /*  ------------------------------------------------------------------------- */
    /*  ----- DERIVE emoTrq FROM emoPwr ---------------------------------------- */
    /*  Power = Torque * rotational vel. */
    /*  therefore, */
    /*  Torque = Power / Vel */
    /*  INCLUDE LOOK UP TABLE HERE */
    /*  cannot go from electric power and work with mechanical crsSpd */
    /*  convert electric emoPwr to mechanical emoPwr with lookup table */
    st.site = &ab_emlrtRSI;
    batCur = codegen_interp2(&st, fzg_array_struct->emoSpdMgd,
      fzg_array_struct->emoPwrMgd, fzg_array_struct->emoTrq_emoSpd_emoPwr,
      crsSpdPre, (batPwr - batCur * batCur * batRst) - batPwrAux);

    /*  emoPwr bound checking */
    if ((emoPwrMinPos > batCur) || (emoPwrMaxPos < batCur)) {
    } else {
      *emoTrq = batCur / crsSpdPre;

      /*  emoTrq bound checking */
      if ((emoTrqMinPos > *emoTrq) || (emoTrqMaxPos < *emoTrq) || (crsTrqPre >
           iceTrqMaxPos + *emoTrq)) {
      } else {
        /*  ------------------------------------------------------------------------- */
        /*  ----- CALCUALTE crsTrq -------------------------------------------------- */
        /*  check that the demanded crsTrq is not above max possible torque that */
        /*  can be generated between the ice and the em */
        /*  torque split */
        *iceTrq = crsTrqPre - *emoTrq;

        /*  iceTrq boundary check */
        /*  check if iceTrq is too high or low based on iceTrqMax/MinPos */
        if ((*iceTrq > iceTrqMaxPos) || (*iceTrq < iceTrqMinPos)) {
        } else {
          /*  HOW TO DEAL WITH BREAK BOOL? */
          /*  BRAKE WHEEL SIDE - WHEELS ARE RECEIVING TOO MUCH TORQUE FROM ICE */
          /*  if the iceTrq being delivered exceeds crsTrq demands plus the limit that */
          /*  the EM can experience while charging, discharge the iceTrq through brkTrq */
          guard1 = false;
          if (*iceTrq > crsTrqPre - emoTrqMinPos) {
            if (brkBool != 0.0) {
              *brkTrq = *iceTrq - (crsTrqPre - emoTrqMinPos);
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            /*  if brkBool is true - allow for braking to reduce  */
            /*  BRAKE ENGINE SIDE - ENGINE CANNOT RUN IN REVERSE */
            if (*iceTrq < 0.0) {
              /*  if iceTrq is negative (which it can't be in this case), don't */
              /*  brake with with engine! Rather, brake with the brakes. */
              /*  BUT! this shouldn't trigger, as this is not optimal! */
              /*      if brkBool */
              *brkTrq = *iceTrq;
              *iceTrq = iceTrqMinPos;
              st.site = &bb_emlrtRSI;
              b_fprintf(&st);
              st.site = &cb_emlrtRSI;
              d_fprintf(&st, *brkTrq);
              st.site = &db_emlrtRSI;
              f_fprintf(&st, iceTrqMinPos);

              /*      else */
              *fulEng = 0.0;
            } else {
              /*  ------------------------------------------------------------------------- */
              /*  ----- CALCULATE fulEng USE ---------------------------------------------- */
              /*  Skalar Krafstoffkraft in N */
              /*  FUNCTION CALL */
              /*  Skalar f¸r die Wegschrittweite in m, */
              /*  Skalar - vehicular velocity */
              /*  Skalar - crankshaft speed at given time */
              /*  Skalar - ice torque at given time */
              /*  Skalar - max ICE torque */
              /*  Fahrzeugparameter - nur skalar */
              /*  Fahrzeugparameter - iceSpd */
              /*  Fahrzeugparameter - iceTrq */
              /*  Fahrzeugparameter - icePwr */
              st.site = &eb_emlrtRSI;

              /*  Skalar Kraftstoffkraft */
              /*  Skalar f¸r die Wegschrittweite in m */
              /*  vehicular velocity */
              /*  Skalar - crankshaft speed at given path_idx */
              /*  Skalar - ice torque at given path_idx */
              /*  Skalar - max ICE torque */
              /*  struct - Fahrzeugparameter - nur skalar */
              /*  input ICE speed value */
              /*  input ICE torque value */
              /*  lookup ICE power table */
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
              if (vehVelVec[0] < muDoubleScalarAbs
                  (fzg_scalar_struct->vehVelThresh)) {
                *fulEng = 0.0;
              } else if (*iceTrq > iceTrqMaxPos) {
              } else {
                /*  calculate fuel power */
                b_st.site = &hb_emlrtRSI;

                /*  zi = codegen_interp2(X,Y,Z,xi,yi) gives the same result as */
                /*  interp2(X,Y,Z,xi,yi) */
                /*  Unlike interp2, codegen_interp2 is compatible with code generation */
                /*  Only linear interpolation is available */
                /*  Usage restrictions */
                /*    X and Y must have the same size as Z */
                /*    e.g.,  [X,Y] = meshgrid(x,y); */
                batCur = (crsSpdPre - fzg_array_struct->iceSpdMgd[0]) * (1.0 /
                  (fzg_array_struct->iceSpdMgd[1] - fzg_array_struct->iceSpdMgd
                   [0])) + 1.0;
                idxi = (*iceTrq - fzg_array_struct->iceTrqMgd[0]) * (1.0 /
                  (fzg_array_struct->iceTrqMgd[1] - fzg_array_struct->iceTrqMgd
                   [0])) + 1.0;
                if ((idxi <= 1.0) || (batCur <= 1.0) || (idxi > 38.0) || (batCur
                     > 35.0) || muDoubleScalarIsNaN(crsSpdPre) ||
                    muDoubleScalarIsNaN(*iceTrq)) {
                  batCur = rtInf;
                } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (batCur /
                            muDoubleScalarCeil(batCur) != 1.0)) {
                  d0 = muDoubleScalarCeil(idxi) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &gc_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 38, &ne_emlrtBCI,
                    &b_st);
                  d0 = muDoubleScalarCeil(batCur) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &fc_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 35, &me_emlrtBCI,
                    &b_st);
                  d0 = muDoubleScalarCeil(idxi) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &ec_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 38, &le_emlrtBCI,
                    &b_st);
                  d0 = muDoubleScalarCeil(batCur);
                  emlrtIntegerCheckFastR2012b(d0, &dc_emlrtDCI, &b_st);
                  d0 = muDoubleScalarCeil(idxi);
                  emlrtIntegerCheckFastR2012b(d0, &cc_emlrtDCI, &b_st);
                  d0 = muDoubleScalarCeil(batCur) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &bc_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 35, &ke_emlrtBCI,
                    &b_st);
                  d0 = muDoubleScalarCeil(idxi);
                  emlrtIntegerCheckFastR2012b(d0, &ac_emlrtDCI, &b_st);
                  d0 = muDoubleScalarCeil(batCur);
                  emlrtIntegerCheckFastR2012b(d0, &yb_emlrtDCI, &b_st);
                  batCur = ((fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                              (muDoubleScalarCeil(idxi) - 1.0) + 38 * ((int32_T)
                               (muDoubleScalarCeil(batCur) - 1.0) - 1)) - 1] *
                             (muDoubleScalarCeil(idxi) - idxi) *
                             (muDoubleScalarCeil(batCur) - batCur) +
                             fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                              (muDoubleScalarCeil(idxi) - 1.0) + 38 * ((int32_T)
                    muDoubleScalarCeil(batCur) - 1)) - 1] * (muDoubleScalarCeil
                              (idxi) - idxi) * (1.0 - (muDoubleScalarCeil(batCur)
                    - batCur))) + fzg_array_struct->iceFulPwr_iceSpd_iceTrq
                            [((int32_T)muDoubleScalarCeil(idxi) + 38 * ((int32_T)
                              (muDoubleScalarCeil(batCur) - 1.0) - 1)) - 1] *
                            (1.0 - (muDoubleScalarCeil(idxi) - idxi)) *
                            (muDoubleScalarCeil(batCur) - batCur)) +
                    fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                    muDoubleScalarCeil(idxi) + 38 * ((int32_T)muDoubleScalarCeil
                    (batCur) - 1)) - 1] * (1.0 - (muDoubleScalarCeil(idxi) -
                    idxi)) * (1.0 - (muDoubleScalarCeil(batCur) - batCur));
                } else if ((idxi / muDoubleScalarCeil(idxi) != 1.0) && (batCur /
                            muDoubleScalarCeil(batCur) == 1.0)) {
                  d0 = muDoubleScalarCeil(idxi) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &xb_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 38, &je_emlrtBCI,
                    &b_st);
                  emlrtIntegerCheckFastR2012b(batCur, &wb_emlrtDCI, &b_st);
                  d0 = muDoubleScalarCeil(idxi);
                  emlrtIntegerCheckFastR2012b(d0, &vb_emlrtDCI, &b_st);
                  batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                    (muDoubleScalarCeil(idxi) - 1.0) + 38 * ((int32_T)batCur - 1))
                    - 1] * (muDoubleScalarCeil(idxi) - idxi) +
                    fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                    muDoubleScalarCeil(idxi) + 38 * ((int32_T)batCur - 1)) - 1] *
                    (1.0 - (muDoubleScalarCeil(idxi) - idxi));
                } else if ((idxi / muDoubleScalarCeil(idxi) == 1.0) && (batCur /
                            muDoubleScalarCeil(batCur) != 1.0)) {
                  emlrtIntegerCheckFastR2012b(idxi, &ub_emlrtDCI, &b_st);
                  d0 = muDoubleScalarCeil(batCur) - 1.0;
                  i9 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &tb_emlrtDCI,
                    &b_st);
                  emlrtDynamicBoundsCheckFastR2012b(i9, 1, 35, &ie_emlrtBCI,
                    &b_st);
                  d0 = muDoubleScalarCeil(batCur);
                  emlrtIntegerCheckFastR2012b(d0, &sb_emlrtDCI, &b_st);
                  batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                    idxi + 38 * ((int32_T)(muDoubleScalarCeil(batCur) - 1.0) - 1))
                    - 1] * (muDoubleScalarCeil(batCur) - batCur) +
                    fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)idxi +
                    38 * ((int32_T)muDoubleScalarCeil(batCur) - 1)) - 1] * (1.0
                    - (muDoubleScalarCeil(batCur) - batCur));
                } else {
                  batCur = fzg_array_struct->iceFulPwr_iceSpd_iceTrq[((int32_T)
                    emlrtIntegerCheckFastR2012b(idxi, &hc_emlrtDCI, &b_st) + 38 *
                    ((int32_T)emlrtIntegerCheckFastR2012b(batCur, &ic_emlrtDCI,
                    &b_st) - 1)) - 1];
                }

                /*  since P = E/t, then E=P*t */
                *fulEng = batCur * timStp;
              }

              /* % Ende der Funktion */
              /*  ------------------------------------------------------------------------- */
              /*  END OF optTrqSplit_focus() */
            }
          }
        }
      }
    }
  }

  /*  end of function */
}

/* End of code generation (optTrqSplit_focus.c) */
