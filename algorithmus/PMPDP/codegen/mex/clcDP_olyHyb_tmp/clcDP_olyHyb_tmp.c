/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_olyHyb_tmp.c
 *
 * Code generation for function 'clcDP_olyHyb_tmp'
 *
 */

// hi
/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_olyHyb_tmp.h"
#include "clcDP_olyHyb_tmp_emxutil.h"
#include "clcPMP_olyHyb_tmp.h"
#include "fprintf.h"
#include "clcDP_olyHyb_tmp_data.h"
#include <stdio.h>

/* Variable Definitions */
static real_T geaNum;
static boolean_T geaNum_not_empty;
static real_T vehMas;
static real_T vehAccMin;
static real_T vehAccMax;
static emlrtRSInfo emlrtRSI = { 312, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRSInfo b_emlrtRSI = { 376, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRSInfo c_emlrtRSI = { 406, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRSInfo m_emlrtRSI = { 16, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRTEInfo emlrtRTEI = { 7, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo b_emlrtRTEI = { 116, 1, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo c_emlrtRTEI = { 125, 1, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo d_emlrtRTEI = { 133, 1, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo e_emlrtRTEI = { 156, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo f_emlrtRTEI = { 166, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo g_emlrtRTEI = { 171, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo i_emlrtRTEI = { 41, 27, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtECInfo emlrtECI = { -1, 396, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 396, 22, "fulEngOptTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 104, 34, "fulEngOptTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtDCInfo emlrtDCI = { 104, 34, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 104, 27, "fulEngOptTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 104, 27, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 104, 14, "fulEngOptTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 104, 14, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtECInfo b_emlrtECI = { -1, 401, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 401, 22, "batFrcOptTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 136, 27, "fulEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 136, 14, "fulEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 121, 27, "cos2goPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 121, 14, "cos2goPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 277, 56, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 277, 43, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 129, 27, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 129, 14, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtRTEInfo j_emlrtRTEI = { 271, 17, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 258, 29, "engKinPreVec_engKinInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtRTEInfo k_emlrtRTEI = { 253, 13, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtRTEInfo l_emlrtRTEI = { 198, 9, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 194, 21, "engKinActVec_engKinInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtRTEInfo m_emlrtRTEI = { 190, 5, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 186, 38, "engKinMat_engKinInx_wayInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 182, 38, "engKinMat_engKinInx_wayInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 176, 20, "engKinNumVec_wayInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 144, 11, "slpVec_wayInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtRTEInfo n_emlrtRTEI = { 140, 1, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m" };

static emlrtDCInfo d_emlrtDCI = { 98, 22, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtDCInfo e_emlrtDCI = { 98, 22, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 4 };

static emlrtDCInfo f_emlrtDCI = { 98, 32, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtDCInfo g_emlrtDCI = { 98, 32, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 4 };

static emlrtDCInfo h_emlrtDCI = { 98, 39, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 1 };

static emlrtDCInfo i_emlrtDCI = { 98, 39, "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 4 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 177, 20, "engKinNumVec_wayInx",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 356, 30, "cos2goActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 356, 43, "cos2goActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 360, 30, "batEngActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 360, 43, "batEngActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 364, 30, "fulEngActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 364, 43, "fulEngActMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 370, 30, "batFrcOptMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 370, 43, "batFrcOptMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 375, 30, "optPreInxTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 375, 43, "optPreInxTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 375, 50, "optPreInxTn3",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 328, 40, "cos2goPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 328, 53, "cos2goPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 344, 42, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 344, 55, "batEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 348, 42, "fulEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 348, 55, "fulEngPreMat",
  "clcDP_olyHyb_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcDP_olyHyb_tmp.m", 0 };

/* Function Definitions */
void clcDP_olyHyb_tmp(const emlrtStack *sp, real_T disFlg, real_T wayStp, real_T
                      batEngStp, real_T batEngBeg, real_T batPwrAux, real_T
                      psiBatEng, real_T psiTim, real_T staChgPenCosVal, real_T
                      wayInxBeg, real_T wayInxEnd, real_T engKinBegInx, real_T
                      engKinNum, real_T staNum, real_T wayNum, real_T staBeg,
                      const emxArray_real_T *engKinNumVec_wayInx, const
                      emxArray_real_T *slpVec_wayInx, const emxArray_real_T
                      *engKinMat_engKinInx_wayInx, const struct0_T *FZG,
                      emxArray_real_T *optPreInxTn3, emxArray_real_T
                      *batFrcOptTn3, emxArray_real_T *fulEngOptTn3,
                      emxArray_real_T *cos2goActMat)
{
  int32_T i0;
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  int32_T loop_ub;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T b_loop_ub;
  int32_T i5;
  int32_T i6;
  emxArray_real_T *cos2goPreMat;
  emxArray_real_T *batEngPreMat;
  int32_T i7;
  int32_T i8;
  emxArray_real_T *fulEngPreMat;
  int32_T i9;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T wayInx;
  emxArray_real_T *batFrcOptMat;
  emxArray_real_T *batEngActMat;
  emxArray_real_T *fulEngActMat;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  real_T b_wayInx;
  int32_T i13;
  real_T engKinNumPre;
  real_T engKinAct;
  int32_T c_loop_ub;
  real_T cosHamMin;
  int32_T staPreOptInx;
  real_T engKinPreOptInx;
  real_T fulEngOpt;
  real_T batFrcOpt;
  real_T batEngOpt;
  int32_T staPreMin;
  real_T staPreMax;
  int32_T engKinPreInx;
  real_T engKinPre;
  real_T vehAcc;
  int32_T staPre;
  real_T b_staPre;
  real_T staChgPenCos;
  real_T fulFrc;
  real_T batFrc;
  real_T cosHam;
  int32_T b_engKinPreInx;
  int32_T i14;
  real_T cosAct;
  int32_T c_engKinPreInx;
  int32_T i15;
  int32_T d_engKinPreInx;
  int32_T i16;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T f_loop_ub;
  int32_T g_loop_ub;
  int32_T h_loop_ub;
  int32_T i_loop_ub;
  int32_T j_loop_ub;
  int32_T k_loop_ub;
  boolean_T b0;
  int32_T l_loop_ub;
  int32_T m_loop_ub;
  int32_T i17;
  int32_T iv0[2];
  int32_T iv1[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*            --- Ausgangsgrößen: */
  /*    Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
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
  /*     Skalar für den Index der Anfangsgeschwindigkeit */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*           Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen */
  /*           Skalar für den Startzustand des Antriebsstrangs */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*    Vektor der Steigungen in rad */
  /*  Matrix der kinetischen Energien in J */
  /*               struct der FahrzeugFZGameter */
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
  if (engKinNum >= 0.0) {
    d0 = engKinNum;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(engKinNum, &e_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    optPreInxTn3->size[0] = (int32_T)d0;
  } else {
    optPreInxTn3->size[0] = (int32_T)emlrtIntegerCheckR2012b(d0, &d_emlrtDCI, sp);
  }

  if (staNum >= 0.0) {
    d0 = staNum;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(staNum, &g_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    optPreInxTn3->size[1] = (int32_T)d0;
  } else {
    optPreInxTn3->size[1] = (int32_T)emlrtIntegerCheckR2012b(d0, &f_emlrtDCI, sp);
  }

  if (wayNum >= 0.0) {
    d0 = wayNum;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(wayNum, &i_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    optPreInxTn3->size[2] = (int32_T)d0;
  } else {
    optPreInxTn3->size[2] = (int32_T)emlrtIntegerCheckR2012b(d0, &h_emlrtDCI, sp);
  }

  emxEnsureCapacity(sp, (emxArray__common *)optPreInxTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (engKinNum >= 0.0) {
    d0 = engKinNum;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(engKinNum, &e_emlrtDCI, sp);
  }

  if (staNum >= 0.0) {
    d1 = staNum;
  } else {
    d1 = emlrtNonNegativeCheckR2012b(staNum, &g_emlrtDCI, sp);
  }

  if (wayNum >= 0.0) {
    d2 = wayNum;
  } else {
    d2 = emlrtNonNegativeCheckR2012b(wayNum, &i_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    d3 = d0;
  } else {
    d3 = emlrtIntegerCheckR2012b(d0, &d_emlrtDCI, sp);
  }

  if (d1 == (int32_T)muDoubleScalarFloor(d1)) {
    d4 = d1;
  } else {
    d4 = emlrtIntegerCheckR2012b(d1, &f_emlrtDCI, sp);
  }

  if (d2 == (int32_T)muDoubleScalarFloor(d2)) {
    d5 = d2;
  } else {
    d5 = emlrtIntegerCheckR2012b(d2, &h_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d3 * (int32_T)d4 * (int32_T)d5;
  for (i0 = 0; i0 < loop_ub; i0++) {
    optPreInxTn3->data[i0] = 0.0;
  }

  /*  Tensor 3. Stufe für die Kraftstoffenergie */
  /*    tensor3 for fuel energy */
  i0 = fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * fulEngOptTn3->size[2];
  fulEngOptTn3->size[0] = (int32_T)engKinNum;
  fulEngOptTn3->size[1] = (int32_T)staNum;
  fulEngOptTn3->size[2] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum * (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fulEngOptTn3->data[i0] = rtInf;
  }

  /*    set initial fuel energy level to 0 */
  i0 = (int32_T)wayNum;
  if (wayInxBeg == (int32_T)muDoubleScalarFloor(wayInxBeg)) {
    i1 = (int32_T)wayInxBeg;
  } else {
    i1 = (int32_T)emlrtIntegerCheckR2012b(wayInxBeg, &emlrtDCI, sp);
  }

  i2 = (int32_T)staNum;
  if (staBeg == (int32_T)muDoubleScalarFloor(staBeg)) {
    i3 = (int32_T)staBeg;
  } else {
    i3 = (int32_T)emlrtIntegerCheckR2012b(staBeg, &b_emlrtDCI, sp);
  }

  i4 = (int32_T)engKinNum;
  if (engKinBegInx == (int32_T)muDoubleScalarFloor(engKinBegInx)) {
    loop_ub = (int32_T)engKinBegInx;
  } else {
    loop_ub = (int32_T)emlrtIntegerCheckR2012b(engKinBegInx, &c_emlrtDCI, sp);
  }

  if ((loop_ub >= 1) && (loop_ub < i4)) {
    b_loop_ub = loop_ub;
  } else {
    b_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &d_emlrtBCI, sp);
  }

  if ((i3 >= 1) && (i3 < i2)) {
    i5 = i3;
  } else {
    i5 = emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &c_emlrtBCI, sp);
  }

  if ((i1 >= 1) && (i1 < i0)) {
    i6 = i1;
  } else {
    i6 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, sp);
  }

  fulEngOptTn3->data[((b_loop_ub + fulEngOptTn3->size[0] * (i5 - 1)) +
                      fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * (i6 - 1))
    - 1] = 0.0;

  /*  Tensor 3. Stufe für die Batterienergie */
  /*    tensor3 for battery energy */
  i0 = batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * batFrcOptTn3->size[2];
  batFrcOptTn3->size[0] = (int32_T)engKinNum;
  batFrcOptTn3->size[1] = (int32_T)staNum;
  batFrcOptTn3->size[2] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)batFrcOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum * (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    batFrcOptTn3->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &cos2goPreMat, 2, &b_emlrtRTEI, true);

  /* % Berechnung der optimalen Vorgänger */
  /*    calculating the optimal predecessors */
  /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten */
  /*  Wegschritt */
  /*    initialize the matrix for the cost to the points in the last wayidx */
  i0 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
  cos2goPreMat->size[0] = (int32_T)engKinNum;
  cos2goPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    cos2goPreMat->data[i0] = rtInf;
  }

  i0 = cos2goActMat->size[0] * cos2goActMat->size[1];
  cos2goActMat->size[0] = (int32_T)engKinNum;
  cos2goActMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    cos2goActMat->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &batEngPreMat, 2, &c_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit 0 für alle Zustände(concluded) */
  /*    first, initialize the startidx to 0 for all states */
  i0 = (int32_T)staNum;
  i1 = (int32_T)staBeg;
  i2 = (int32_T)engKinNum;
  i3 = (int32_T)engKinBegInx;
  if ((i3 >= 1) && (i3 < i2)) {
    i7 = i3;
  } else {
    i7 = emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &i_emlrtBCI, sp);
  }

  if ((i1 >= 1) && (i1 < i0)) {
    i8 = i1;
  } else {
    i8 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &h_emlrtBCI, sp);
  }

  cos2goPreMat->data[(i7 + cos2goPreMat->size[0] * (i8 - 1)) - 1] = 0.0;

  /*  Initialisierung der Matrix der Batterieenergien */
  /*    initialize the battery energy matrix */
  i0 = batEngPreMat->size[0] * batEngPreMat->size[1];
  batEngPreMat->size[0] = (int32_T)engKinNum;
  batEngPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)batEngPreMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    batEngPreMat->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &fulEngPreMat, 2, &d_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit Startladung für den Startzustand */
  /*    first, intialize start index of the starting charge for intial state */
  i0 = (int32_T)staNum;
  i1 = (int32_T)staBeg;
  i2 = (int32_T)engKinNum;
  i3 = (int32_T)engKinBegInx;
  if ((i3 >= 1) && (i3 < i2)) {
    i9 = i3;
  } else {
    i9 = emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &m_emlrtBCI, sp);
  }

  if ((i1 >= 1) && (i1 < i0)) {
    i10 = i1;
  } else {
    i10 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &l_emlrtBCI, sp);
  }

  batEngPreMat->data[(i9 + batEngPreMat->size[0] * (i10 - 1)) - 1] = batEngBeg;

  /*  Initialisierung der Matrix der Kraftstoffenergien */
  /*    initialze the fuel energy matrix */
  i0 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
  fulEngPreMat->size[0] = (int32_T)engKinNum;
  fulEngPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)engKinNum * (int32_T)staNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fulEngPreMat->data[i0] = rtInf;
  }

  /*  Erste Initilisierung beim Startindex mit 0 für den Startzustand */
  /*    first, intialize the start idx for the intitial states to 0 */
  i0 = (int32_T)staNum;
  i1 = (int32_T)staBeg;
  i2 = (int32_T)engKinNum;
  i3 = (int32_T)engKinBegInx;
  if ((i3 >= 1) && (i3 < i2)) {
    i11 = i3;
  } else {
    i11 = emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &g_emlrtBCI, sp);
  }

  if ((i1 >= 1) && (i1 < i0)) {
    i12 = i1;
  } else {
    i12 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, sp);
  }

  fulEngPreMat->data[(i11 + fulEngPreMat->size[0] * (i12 - 1)) - 1] = 0.0;

  /*  Schleife über alle Wegpunkte */
  /*    looping thorugh length of # of grid discretization/indeces (Weginputs) */
  i0 = (int32_T)(wayInxEnd + (1.0 - (wayInxBeg + 1.0)));
  emlrtForLoopVectorCheckR2012b(wayInxBeg + 1.0, 1.0, wayInxEnd, mxDOUBLE_CLASS,
    i0, &n_emlrtRTEI, sp);
  wayInx = 0;
  emxInit_real_T(sp, &batFrcOptMat, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &batEngActMat, 2, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngActMat, 2, &g_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 1, &emlrtRTEI, true);
  while (wayInx <= i0 - 1) {
    b_wayInx = (wayInxBeg + 1.0) + (real_T)wayInx;

    /*  PATH IDX LOOP */
    /*  mittlere Steigung im betrachteten Intervall  */
    /*    no longer doing mean, using previous gradiant instead */
    i1 = slpVec_wayInx->size[0];
    i2 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &s_emlrtBCI, sp);

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
    batFrcOptMat->size[0] = (int32_T)engKinNum;
    batFrcOptMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)batFrcOptMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = (int32_T)engKinNum * (int32_T)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      batFrcOptMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize cost matrix to points in current path steps (idxs?) */
    i1 = cos2goActMat->size[0] * cos2goActMat->size[1];
    cos2goActMat->size[0] = (int32_T)engKinNum;
    cos2goActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = (int32_T)engKinNum * (int32_T)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      cos2goActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Batterieenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for battery energy at points along current wayidx */
    i1 = batEngActMat->size[0] * batEngActMat->size[1];
    batEngActMat->size[0] = (int32_T)engKinNum;
    batEngActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)batEngActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = (int32_T)engKinNum * (int32_T)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      batEngActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix für die Krafstoffenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for fuel energie along current way idxs */
    i1 = fulEngActMat->size[0] * fulEngActMat->size[1];
    fulEngActMat->size[0] = (int32_T)engKinNum;
    fulEngActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)fulEngActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = (int32_T)engKinNum * (int32_T)staNum;
    for (i1 = 0; i1 < loop_ub; i1++) {
      fulEngActMat->data[i1] = rtInf;
    }

    /*  Anzahl der kinetischen Energien im aktuellen und im */
    /*  Vorgängerwegschritt */
    /*    number of kinetic energies in current and past path_idxs */
    i1 = engKinNumVec_wayInx->size[0];
    i2 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &r_emlrtBCI, sp);

    /*  look at this loop's KE */
    i1 = engKinNumVec_wayInx->size[0];
    i2 = (int32_T)b_wayInx - 1;
    if ((i2 >= 1) && (i2 < i1)) {
      i13 = i2;
    } else {
      i13 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &t_emlrtBCI, sp);
    }

    engKinNumPre = engKinNumVec_wayInx->data[i13 - 1];

    /*  and the previous idx KE */
    /*  Vektoren der kinetischen Energien im vorherigen Wegschritt */
    /*    vector of the KE in the previous idx */
    i1 = engKinMat_engKinInx_wayInx->size[1];
    i2 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &q_emlrtBCI, sp);

    /*  Vektoren der kinetischen Energien im aktuellen Wegschritt */
    /*    KE vector of the current path_idx */
    i1 = engKinMat_engKinInx_wayInx->size[1];
    i2 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &p_emlrtBCI, sp);

    /*  (FZGfor) Schleife über alle akutellen kinetischen Energien */
    /*    loop through all the current kinetic energies */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, engKinNumVec_wayInx->data[(int32_T)
      b_wayInx - 1], mxDOUBLE_CLASS, (int32_T)engKinNumVec_wayInx->data[(int32_T)
      b_wayInx - 1], &m_emlrtRTEI, sp);
    loop_ub = 1;
    while (loop_ub - 1 <= (int32_T)engKinNumVec_wayInx->data[(int32_T)b_wayInx -
           1] - 1) {
      /*  CURRENT KINETIC ENERGY LOOP */
      /*  akutelle kinetsiche Energie bestimmen */
      /*    determine the current kinetic energy */
      i1 = engKinMat_engKinInx_wayInx->size[0];
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &o_emlrtBCI, sp);
      engKinAct = engKinMat_engKinInx_wayInx->data[(loop_ub +
        engKinMat_engKinInx_wayInx->size[0] * ((int32_T)b_wayInx - 1)) - 1];

      /*  Schleife über alle möglichen aktuellen Zustände des Antriesstrangs */
      /*    Loop over all possible current powertrain states/all the gears */
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, staNum, mxDOUBLE_CLASS, (int32_T)
        staNum, &l_emlrtRTEI, sp);
      c_loop_ub = 0;
      while (c_loop_ub <= (int32_T)staNum - 1) {
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
        staPreMin = (int32_T)muDoubleScalarMax(1.0, (1.0 + (real_T)c_loop_ub) -
          1.0);
        staPreMax = muDoubleScalarMin(geaNum, (1.0 + (real_T)c_loop_ub) + 1.0);

        /*             %% Schleife über alle kinetischen Energien (Vorgänger) */
        /*    loop through all the kinetic energies (previous state idxs) */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, engKinNumPre, mxDOUBLE_CLASS,
          (int32_T)engKinNumPre, &k_emlrtRTEI, sp);
        engKinPreInx = 0;
        while (engKinPreInx <= (int32_T)engKinNumPre - 1) {
          /*  PREVIOUS KE LOOP */
          /*  kinetsiche Energie des betrachten(consider) Vorgängerspunkts */
          /*  bestimmen(determine) */
          /*    determine the kinetic energy of the previous path_idx */
          i1 = engKinMat_engKinInx_wayInx->size[0];
          emlrtDynamicBoundsCheckR2012b(engKinPreInx + 1, 1, i1, &n_emlrtBCI, sp);
          engKinPre = engKinMat_engKinInx_wayInx->data[engKinPreInx +
            engKinMat_engKinInx_wayInx->size[0] * ((int32_T)b_wayInx - 2)];

          /*  Prüfen(check), ob eine erlaubte Beschleunigung vorliegt. */
          /*  Ansonsten zum nächsten Schleifendurchlauf springen */
          /*    Check whether an allowable acceleration exists. */
          /*    Otherwise, jump to the next iteration */
          vehAcc = (engKinAct - engKinMat_engKinInx_wayInx->data[engKinPreInx +
                    engKinMat_engKinInx_wayInx->size[0] * ((int32_T)b_wayInx - 2)])
            / vehMas / wayStp;
          if ((vehAcc < vehAccMin) || (vehAcc > vehAccMax)) {
          } else {
            /*  Schleife über allen Zustände (relativer Index) */
            /*    Loop through all the states (relative index) */
            i1 = (int32_T)(staPreMax + (1.0 - (real_T)staPreMin));
            emlrtForLoopVectorCheckR2012b(staPreMin, 1.0, staPreMax,
              mxDOUBLE_CLASS, i1, &j_emlrtRTEI, sp);
            staPre = 0;
            while (staPre <= i1 - 1) {
              b_staPre = (real_T)staPreMin + (real_T)staPre;

              /*  CURRENT GEAR CHANGE LOOP */
              /*                     %% Batterieenergie beim betrachteten Vorgänger */
              /*  battery energy when considering last path_idx */
              /*    note: batengPreMat has dims #_KE_states x #_gears */
              i2 = batEngPreMat->size[0];
              i3 = engKinPreInx + 1;
              emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &k_emlrtBCI, sp);
              i2 = batEngPreMat->size[1];
              i3 = (int32_T)b_staPre;
              emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &j_emlrtBCI, sp);

              /*  Sollte es keinen gültigen Vorgänger geben, wird zum */
              /*  nächsten Schleifendurchlauf gesprungen */
              /*    if there is no valid previous battery energy, jump */
              /*    to the next loop iteration */
              if (muDoubleScalarIsInf(batEngPreMat->data[engKinPreInx +
                                      batEngPreMat->size[0] * ((int32_T)b_staPre
                    - 1)])) {
              } else {
                /*                     %% Antriebsstrangzustand und Strafkosten bestimmen    */
                /*    determine gear and penalty costs */
                /*  Kosten für Zustandswechsel setzen */
                /*    set costs for state changes */
                if (1.0 + (real_T)c_loop_ub == b_staPre) {
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
                st.site = &emlrtRSI;
                clcPMP_olyHyb_tmp(&st, engKinPre, engKinAct, 1.0 + (real_T)
                                  c_loop_ub, slpVec_wayInx->data[(int32_T)
                                  b_wayInx - 2], batEngPreMat->data[engKinPreInx
                                  + batEngPreMat->size[0] * ((int32_T)b_staPre -
                  1)], psiBatEng, psiTim, batPwrAux, batEngStp, wayStp, FZG,
                                  &cosHam, &batFrc, &fulFrc);

                /*                      % minimale Kosten der Hamiltonfunktion zum aktuellen */
                /*                      % Punkt bestimmen */
                /*                      [cosHamMin,optPreInx] ... */
                /*                          = min([cosHam... */
                /*                          + cos2goPreMat(engKinPreInx,staPre)... */
                /*                          + staChgPenCos... */
                /*                          ,cosHamMin]); %#ok<PFBNS> */
                /*  combine the min hamil. cost w/ previous costs and  */
                /*    gear penalty to get current cost */
                i2 = cos2goPreMat->size[0];
                i3 = cos2goPreMat->size[1];
                i4 = (int32_T)b_staPre;
                if ((engKinPreInx + 1 >= 1) && (engKinPreInx + 1 < i2)) {
                  b_engKinPreInx = engKinPreInx + 1;
                } else {
                  b_engKinPreInx = emlrtDynamicBoundsCheckR2012b(engKinPreInx +
                    1, 1, i2, &gb_emlrtBCI, sp);
                }

                if ((i4 >= 1) && (i4 < i3)) {
                  i14 = i4;
                } else {
                  i14 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &hb_emlrtBCI,
                    sp);
                }

                cosAct = (cosHam + cos2goPreMat->data[(b_engKinPreInx +
                           cos2goPreMat->size[0] * (i14 - 1)) - 1]) +
                  staChgPenCos / wayStp;

                /*  Wenn der aktuelle Punkt besser ist, als der in */
                /*  cosHamMin gespeicherte Wert, werden die Ausgabegrößen */
                /*  neu beschrieben. */
                /*    if current point is better than the cost value */
                /*    stored in CosHamMin, then rewrite the output */
                if (cosAct < cosHamMin) {
                  cosHamMin = cosAct;

                  /*  new hamil. cost */
                  staPreOptInx = (int32_T)b_staPre;

                  /*  new optimal gear idx */
                  engKinPreOptInx = 1.0 + (real_T)engKinPreInx;

                  /*  new optimal KEidx */
                  batFrcOpt = batFrc;

                  /*  new optimal battery force */
                  /*  new opt. battery energy = (batt. force * */
                  /*  displacement diff) + previous battery energy valu */
                  i2 = batEngPreMat->size[0];
                  i3 = batEngPreMat->size[1];
                  i4 = (int32_T)b_staPre;
                  if ((engKinPreInx + 1 >= 1) && (engKinPreInx + 1 < i2)) {
                    c_engKinPreInx = engKinPreInx + 1;
                  } else {
                    c_engKinPreInx = emlrtDynamicBoundsCheckR2012b(engKinPreInx
                      + 1, 1, i2, &ib_emlrtBCI, sp);
                  }

                  if ((i4 >= 1) && (i4 < i3)) {
                    i15 = i4;
                  } else {
                    i15 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &jb_emlrtBCI,
                      sp);
                  }

                  batEngOpt = batFrc * wayStp + batEngPreMat->data
                    [(c_engKinPreInx + batEngPreMat->size[0] * (i15 - 1)) - 1];

                  /*  new opt. fuel energy = (fuel force * displacement */
                  /*  diff) + previous fuel energy value */
                  i2 = fulEngPreMat->size[0];
                  i3 = fulEngPreMat->size[1];
                  i4 = (int32_T)b_staPre;
                  if ((engKinPreInx + 1 >= 1) && (engKinPreInx + 1 < i2)) {
                    d_engKinPreInx = engKinPreInx + 1;
                  } else {
                    d_engKinPreInx = emlrtDynamicBoundsCheckR2012b(engKinPreInx
                      + 1, 1, i2, &kb_emlrtBCI, sp);
                  }

                  if ((i4 >= 1) && (i4 < i3)) {
                    i16 = i4;
                  } else {
                    i16 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &lb_emlrtBCI,
                      sp);
                  }

                  fulEngOpt = fulFrc * wayStp + fulEngPreMat->data
                    [(d_engKinPreInx + fulEngPreMat->size[0] * (i16 - 1)) - 1];
                }
              }

              staPre++;
              if (*emlrtBreakCheckR2012bFlagVar != 0) {
                emlrtBreakCheckR2012b(sp);
              }
            }

            /*  end of gear changes loop */
          }

          engKinPreInx++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        /*  end of running through previous KE states loop */
        if (!muDoubleScalarIsInf(cosHamMin)) {
          /*  optimale Kosten zum aktuellen Punkt speichern */
          /*    save min hamilton value for current point */
          i1 = cos2goActMat->size[0];
          i2 = cos2goActMat->size[1];
          if ((loop_ub >= 1) && (loop_ub < i1)) {
            d_loop_ub = loop_ub;
          } else {
            d_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1,
              &u_emlrtBCI, sp);
          }

          if ((c_loop_ub + 1 >= 1) && (c_loop_ub + 1 < i2)) {
            e_loop_ub = c_loop_ub + 1;
          } else {
            e_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub + 1, 1, i2,
              &v_emlrtBCI, sp);
          }

          cos2goActMat->data[(d_loop_ub + cos2goActMat->size[0] * (e_loop_ub - 1))
            - 1] = cosHamMin;

          /*  optimale Batterieenergie zum aktuellen Punkt speichern */
          /*    save optimal battery energy for current point */
          i1 = batEngActMat->size[0];
          i2 = batEngActMat->size[1];
          if ((loop_ub >= 1) && (loop_ub < i1)) {
            f_loop_ub = loop_ub;
          } else {
            f_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1,
              &w_emlrtBCI, sp);
          }

          if ((c_loop_ub + 1 >= 1) && (c_loop_ub + 1 < i2)) {
            g_loop_ub = c_loop_ub + 1;
          } else {
            g_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub + 1, 1, i2,
              &x_emlrtBCI, sp);
          }

          batEngActMat->data[(f_loop_ub + batEngActMat->size[0] * (g_loop_ub - 1))
            - 1] = batEngOpt;

          /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
          /*    save optimal fuel energy for current point */
          i1 = fulEngActMat->size[0];
          i2 = fulEngActMat->size[1];
          if ((loop_ub >= 1) && (loop_ub < i1)) {
            h_loop_ub = loop_ub;
          } else {
            h_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1,
              &y_emlrtBCI, sp);
          }

          if ((c_loop_ub + 1 >= 1) && (c_loop_ub + 1 < i2)) {
            i_loop_ub = c_loop_ub + 1;
          } else {
            i_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub + 1, 1, i2,
              &ab_emlrtBCI, sp);
          }

          fulEngActMat->data[(h_loop_ub + fulEngActMat->size[0] * (i_loop_ub - 1))
            - 1] = fulEngOpt;

          /*  optimale Batterieenergie zum aktuellen Punkt */
          /*  Flussgröße gilt im Intervall */
          /*    populate optimal battery energy flux quantity at point  */
          /*    that's applicable to current interval */
          i1 = batFrcOptMat->size[0];
          i2 = batFrcOptMat->size[1];
          if ((loop_ub >= 1) && (loop_ub < i1)) {
            j_loop_ub = loop_ub;
          } else {
            j_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1,
              &bb_emlrtBCI, sp);
          }

          if ((c_loop_ub + 1 >= 1) && (c_loop_ub + 1 < i2)) {
            k_loop_ub = c_loop_ub + 1;
          } else {
            k_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub + 1, 1, i2,
              &cb_emlrtBCI, sp);
          }

          batFrcOptMat->data[(j_loop_ub + batFrcOptMat->size[0] * (k_loop_ub - 1))
            - 1] = batFrcOpt;

          /*  optimalen Vorgänger codieren über Funktion sub2ind */
          /*  und speichern im Tensor */
          /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
          st.site = &b_emlrtRSI;
          b_st.site = &m_emlrtRSI;
          if ((engKinPreOptInx >= 1.0) && ((int32_T)engKinNum >= engKinPreOptInx))
          {
            b0 = true;
          } else {
            b0 = false;
          }

          if (!!b0) {
          } else {
            emlrtErrorWithMessageIdR2012b(&b_st, &i_emlrtRTEI,
              "MATLAB:sub2ind:IndexOutOfRange", 0);
          }

          if ((staPreOptInx >= 1) && ((int32_T)staNum >= staPreOptInx)) {
            b0 = true;
          } else {
            b0 = false;
          }

          if (!!b0) {
          } else {
            emlrtErrorWithMessageIdR2012b(&b_st, &i_emlrtRTEI,
              "MATLAB:sub2ind:IndexOutOfRange", 0);
          }

          i1 = optPreInxTn3->size[0];
          i2 = optPreInxTn3->size[1];
          i3 = optPreInxTn3->size[2];
          i4 = (int32_T)b_wayInx;
          if ((loop_ub >= 1) && (loop_ub < i1)) {
            l_loop_ub = loop_ub;
          } else {
            l_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1,
              &db_emlrtBCI, sp);
          }

          if ((c_loop_ub + 1 >= 1) && (c_loop_ub + 1 < i2)) {
            m_loop_ub = c_loop_ub + 1;
          } else {
            m_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub + 1, 1, i2,
              &eb_emlrtBCI, sp);
          }

          if ((i4 >= 1) && (i4 < i3)) {
            i17 = i4;
          } else {
            i17 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &fb_emlrtBCI, sp);
          }

          optPreInxTn3->data[((l_loop_ub + optPreInxTn3->size[0] * (m_loop_ub -
            1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] * (i17 - 1)) - 1]
            = (int32_T)engKinPreOptInx + (int32_T)engKinNum * (staPreOptInx - 1);
        }

        /*  end of ~inf(hamiltonian) if-statement */
        c_loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /*  end of looping through all gears */
      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  end of looping through all the current kinetic energy states */
    /*  Speichern der Batterieenergie für den nächsten Schleifendurchlauf */
    /*    save battery energy value as previous path_idx val for next loop  */
    i1 = batEngPreMat->size[0] * batEngPreMat->size[1];
    batEngPreMat->size[0] = batEngActMat->size[0];
    batEngPreMat->size[1] = batEngActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)batEngPreMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = batEngActMat->size[0] * batEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      batEngPreMat->data[i1] = batEngActMat->data[i1];
    }

    /*  Speichern der Krafstoffenergie für den nächsten Schleifendurchlauf */
    /*    save fuel energy value as previous path_idx value for the next loop */
    i1 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
    fulEngPreMat->size[0] = fulEngActMat->size[0];
    fulEngPreMat->size[1] = fulEngActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = fulEngActMat->size[0] * fulEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      fulEngPreMat->data[i1] = fulEngActMat->data[i1];
    }

    /*  Speichern der Kosten für den nächsten Schleifendurchlauf */
    /*    save cost as previous path_idx value for the next loop */
    i1 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
    cos2goPreMat->size[0] = cos2goActMat->size[0];
    cos2goPreMat->size[1] = cos2goActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = cos2goActMat->size[0] * cos2goActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      cos2goPreMat->data[i1] = cos2goActMat->data[i1];
    }

    /*  optimale Kraftstoffenergie zum aktuellen Punkt */
    /*    optimal fuel energy at current point - save current mat in tensor */
    loop_ub = fulEngOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = fulEngOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = i1;
    }

    i1 = fulEngOptTn3->size[2];
    i2 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &emlrtBCI, sp);
    iv0[0] = r0->size[0];
    iv0[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 2, *(int32_T (*)[2])fulEngActMat->size, 2,
      &emlrtECI, sp);
    loop_ub = fulEngActMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_loop_ub = fulEngActMat->size[0];
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        fulEngOptTn3->data[(r0->data[i2] + fulEngOptTn3->size[0] * r1->data[i1])
          + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int32_T)b_wayInx -
          1)] = fulEngActMat->data[i2 + fulEngActMat->size[0] * i1];
      }
    }

    /*  optimale Batterieenergie zum aktuellen Punkt */
    /*    optimal battery force at current point - save current mat in tensor */
    /*  Flussgröße gilt im Intervall */
    /*    flux quantity applied over the interval */
    loop_ub = batFrcOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    loop_ub = batFrcOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = i1;
    }

    i1 = batFrcOptTn3->size[2];
    i2 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &e_emlrtBCI, sp);
    iv1[0] = r0->size[0];
    iv1[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv1, 2, *(int32_T (*)[2])batFrcOptMat->size, 2,
      &b_emlrtECI, sp);
    loop_ub = batFrcOptMat->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_loop_ub = batFrcOptMat->size[0];
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        batFrcOptTn3->data[(r0->data[i2] + batFrcOptTn3->size[0] * r1->data[i1])
          + batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * ((int32_T)b_wayInx -
          2)] = batFrcOptMat->data[i2 + batFrcOptMat->size[0] * i1];
      }
    }

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (disFlg != 0.0) {
      st.site = &c_emlrtRSI;
      b_fprintf(&st, b_wayInx - wayInxBeg, (b_wayInx - wayInxBeg) / (wayInxEnd -
                 wayInxBeg) * 100.0);
    }

    wayInx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r1);
  emxFree_int32_T(&r0);
  emxFree_real_T(&fulEngActMat);
  emxFree_real_T(&batEngActMat);
  emxFree_real_T(&batFrcOptMat);
  emxFree_real_T(&fulEngPreMat);
  emxFree_real_T(&batEngPreMat);
  emxFree_real_T(&cos2goPreMat);

  /*  end of looping through all discretized path indexes */
  /*  END OF FUNCTION */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void clcDP_olyHyb_tmp_init(void)
{
}

void geaNum_not_empty_init(void)
{
  geaNum_not_empty = false;
}

void iceFlg_not_empty_init(void)
{
}

void vehAccMax_not_empty_init(void)
{
}

void vehAccMin_not_empty_init(void)
{
}

void vehMas_not_empty_init(void)
{
}

/* End of code generation (clcDP_olyHyb_tmp.c) */
