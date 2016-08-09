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
#include "fulEngClc_focus.h"
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

static emlrtRSInfo cb_emlrtRSI = { 168, "optTrqSplit_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\optTrqSplit_focus.m"
};

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
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

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
            /*  struct - Fahrzeugparameter - nur array */
            st.site = &cb_emlrtRSI;
            fulEng = fulEngClc_focus(&st, timStp, vehVelVec[0], crsSpdPre,
              iceTrq, iceTrqMaxPos, fzg_scalar_struct->vehVelThresh,
              fzg_array_struct->iceSpdMgd, fzg_array_struct->iceTrqMgd,
              fzg_array_struct->iceFulPwr_iceSpd_iceTrq);

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
