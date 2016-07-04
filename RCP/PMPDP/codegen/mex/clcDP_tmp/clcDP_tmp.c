/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_tmp.c
 *
 * Code generation for function 'clcDP_tmp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "clcDP_tmp_emxutil.h"
#include "fprintf.h"
#include "clcOptTrj_tmp.h"
#include "clcDP_olyHyb_tmp.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 32, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m" };

static emlrtRSInfo b_emlrtRSI = { 33, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m" };

static emlrtRSInfo c_emlrtRSI = { 65, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m" };

static emlrtRSInfo d_emlrtRSI = { 98, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m" };

static emlrtRTEInfo emlrtRTEI = { 10, 5, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m" };

static emlrtDCInfo emlrtDCI = { 61, 24, "clcDP_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m", 1 };

static emlrtBCInfo emlrtBCI = { 1, 800, 61, 24, "engKinNumVec_wayInx",
  "clcDP_tmp", "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_tmp.m",
  0 };

/* Function Definitions */
void clcDP_tmp(const emlrtStack *sp, real_T disFlg, real_T wayStp, real_T
               batEngStp, real_T batEngBeg, real_T batPwrAux, real_T psiBatEng,
               real_T psiTim, real_T staChgPenCosVal, real_T wayInxBeg, real_T
               wayInxEnd, real_T engKinNum, real_T staNum, real_T wayNum, real_T
               staBeg, const real_T engKinNumVec_wayInx[800], const real_T
               slpVec_wayInx[800], const real_T engKinMat_engKinInx_wayInx[8800],
               const struct0_T *FZG, emxArray_real_T *engKinOptVec,
               emxArray_real_T *batEngDltOptVec, emxArray_real_T
               *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T
               *psiEngKinOptVec, real_T *fulEngOpt, boolean_T *resVld)
{
  emxArray_real_T *optPreInxTn3;
  emxArray_real_T *batFrcOptTn3;
  emxArray_real_T *fulEngOptTn3;
  emxArray_real_T *cos2goActMat;
  int32_T i0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &optPreInxTn3, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &batFrcOptTn3, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngOptTn3, 3, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &cos2goActMat, 2, &emlrtRTEI, true);

  /*             --- Ausgangsgrößen: */
  /*        Vektor - Trajektorie der optimalen kin. Energien */
  /* Vektor - optimale Batterieenergieänderung */
  /*  Vektor - optimale Kraftstoffenergieänderung */
  /*           Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*  Vektor - costate für kinetische Energie */
  /*       Skalar - optimale Kraftstoffenergie */
  /*                --- Eingangsgrößen: */
  /*          Skalar - Flag für Ausgabe in das Commandwindow */
  /*           Skalar für die Wegschrittweite in m */
  /*        Skalar der Batteriediskretisierung in J */
  /*        Skalar für die Batterieenergie am Beginn in Ws */
  /*        Skalar für die Nebenverbrauchlast in W */
  /*        Skalar für den Co-State der Batterieenergie */
  /*           Skalar für den Co-State der Zeit */
  /*  Skalar für die Strafkosten beim Zustandswechsel */
  /*        Skalar für Anfangsindex in den Eingangsdaten */
  /*        Skalar für Endindex in den Eingangsdaten */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*           Skalar für die max. Anzahl an Wegstützstellen */
  /*           Skalar für den Startzustand des Antriebsstrangs */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*    Vektor der Steigungen in rad */
  /*  Matrix der kinetischen Energien in J%#codegen */
  /* % Calculating optimal predecessors with DP + PMP */
  st.site = &emlrtRSI;
  b_fprintf(&st);

  /*  --- Ausgangsgrößen: */
  /*    Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
  /*      FUNKTION */
  /*                --- Eingangsgrößen: */
  /*          Skalar - Flag für Ausgabe in das Commandwindow */
  /*           Skalar für die Wegschrittweite in m */
  /*        Skalar der Batteriediskretisierung in J */
  /*        Skalar für die Batterieenergie am Beginn in Ws */
  /*        Skalar für die Nebenverbrauchlast in W */
  /*        Skalar für den Co-State der Batterieenergie */
  /*           Skalar für den Co-State der Zeit */
  /*  Skalar für die Strafkosten beim Zustandswechsel */
  /*        Skalar für Anfangsindex in den Eingangsdaten */
  /*        Skalar für Endindex in den Eingangsdaten */
  /*                Skalar für den Index der Anfangsgeschwindigkeit */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*           Skalar für die max. Anzahl an Wegstützstellen */
  /*           Skalar für den Startzustand des Antriebsstrangs */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*    Vektor der Steigungen in rad */
  /*  Matrix der kinetischen Energien in J */
  /*               struct der Fahrzeugparameter */
  st.site = &b_emlrtRSI;
  clcDP_olyHyb_tmp(&st, disFlg, wayStp, batEngStp, batEngBeg, batPwrAux,
                   psiBatEng, psiTim, staChgPenCosVal, wayInxBeg, wayInxEnd,
                   engKinNum, staNum, wayNum, staBeg, engKinNumVec_wayInx,
                   slpVec_wayInx, engKinMat_engKinInx_wayInx, FZG, optPreInxTn3,
                   batFrcOptTn3, fulEngOptTn3, cos2goActMat);
  if (wayInxEnd == (int32_T)muDoubleScalarFloor(wayInxEnd)) {
    i0 = (int32_T)wayInxEnd;
  } else {
    i0 = (int32_T)emlrtIntegerCheckR2012b(wayInxEnd, &emlrtDCI, sp);
  }

  emlrtDynamicBoundsCheckR2012b(i0, 1, 800, &emlrtBCI, sp);

  /* % Calculating optimal trajectories for result of DP + PMP */
  /*        Vektor - Trajektorie der optimalen kin. Energien */
  /* Vektor - optimale Batterieenergieänderung */
  /*  Vektor - optimale Kraftstoffenergieänderung */
  /*           Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*  Vektor - costate für kinetische Energie */
  /*        Skalar - optimale Kraftstoffenergie */
  /*         FUNKTION */
  /*           Flag, ob Zielzustand genutzt werden muss */
  /*           Skalar für die Wegschrittweite in m */
  /*           Skalar für die max. Anzahl an Wegstützstellen */
  /*        Skalar für Anfangsindex in den Eingangsdaten */
  /*        Skalar für Endindex in den Eingangsdaten */
  /*           Skalar für den finalen Zustand */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*  Skalar für Zielindex der kinetischen Energie */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*  Matrix der kinetischen Energien in J */
  /*     Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
  st.site = &c_emlrtRSI;
  clcOptTrj_tmp(&st, wayStp, wayNum, wayInxBeg, wayInxEnd, engKinNum, staNum,
                engKinNumVec_wayInx, engKinMat_engKinInx_wayInx, optPreInxTn3,
                batFrcOptTn3, fulEngOptTn3, cos2goActMat, engKinOptVec,
                batEngDltOptVec, fulEngDltOptVec, staVec, psiEngKinOptVec,
                fulEngOpt);

  /*  engKinOptVec=0; */
  /*  batEngDltOptVec=0; */
  /*  fulEngDltOptVec=0; */
  /*  staVec=0; */
  /*  psiEngKinOptVec=0; */
  /*  fulEngOpt=0; */
  *resVld = true;
  st.site = &d_emlrtRSI;
  f_fprintf(&st);
  emxFree_real_T(&cos2goActMat);
  emxFree_real_T(&fulEngOptTn3);
  emxFree_real_T(&batFrcOptTn3);
  emxFree_real_T(&optPreInxTn3);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (clcDP_tmp.c) */
