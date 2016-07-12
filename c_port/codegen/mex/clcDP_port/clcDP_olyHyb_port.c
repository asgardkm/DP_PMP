/*
 * clcDP_olyHyb_port.c
 *
 * Code generation for function 'clcDP_olyHyb_port'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcDP_olyHyb_port.h"
#include "clcDP_port_emxutil.h"
#include "clcOptTrj_port.h"
#include "clcPMP_olyHyb_port.h"
#include "fprintf.h"
#include "clcDP_port_mexutil.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static real_T geaNum;
static boolean_T geaNum_not_empty;
static real_T vehMas;
static real_T vehAccMin;
static real_T vehAccMax;
static emlrtRSInfo f_emlrtRSI = { 317, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRSInfo g_emlrtRSI = { 381, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRSInfo h_emlrtRSI = { 411, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRSInfo r_emlrtRSI = { 16, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo s_emlrtRSI = { 41, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo t_emlrtRSI = { 39, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo u_emlrtRSI = { 71, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 7, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 121, 1, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 130, 1, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 138, 1, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 161, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 171, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 176, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 145, 1, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtBCInfo b_emlrtBCI = { 1, 800, 149, 11, "slpVec_wayInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { 1, 800, 181, 20, "engKinNumVec_wayInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { 1, 800, 187, 38, "engKinMat_engKinInx_wayInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtRTEInfo p_emlrtRTEI = { 195, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 203, 9, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 258, 13, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtBCInfo e_emlrtBCI = { 1, 11, 263, 29, "engKinPreVec_engKinInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtRTEInfo s_emlrtRTEI = { 276, 17, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 134, 14, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 134, 27, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 282, 43, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 282, 56, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 126, 14, "cos2goPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 126, 27, "cos2goPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 141, 14, "fulEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 141, 27, "fulEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 109, 14, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 109, 14, "fulEngOptTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 109, 27, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 109, 27, "fulEngOptTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 109, 34, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 109, 34, "fulEngOptTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 401, 22, "fulEngOptTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 401, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtBCInfo r_emlrtBCI = { -1, -1, 406, 22, "batFrcOptTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 406, 5, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m"
};

static emlrtDCInfo e_emlrtDCI = { 103, 22, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtDCInfo f_emlrtDCI = { 103, 22, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  4 };

static emlrtDCInfo g_emlrtDCI = { 103, 32, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtDCInfo h_emlrtDCI = { 103, 32, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  4 };

static emlrtDCInfo i_emlrtDCI = { 103, 39, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  1 };

static emlrtDCInfo j_emlrtDCI = { 103, 39, "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  4 };

static emlrtBCInfo s_emlrtBCI = { 1, 800, 182, 20, "engKinNumVec_wayInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { 1, 11, 199, 21, "engKinActVec_engKinInx",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 361, 30, "cos2goActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 361, 43, "cos2goActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 365, 30, "batEngActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 365, 43, "batEngActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 369, 30, "fulEngActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 369, 43, "fulEngActMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 375, 30, "batFrcOptMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 375, 43, "batFrcOptMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 380, 30, "optPreInxTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 380, 43, "optPreInxTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 380, 50, "optPreInxTn3",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 333, 40, "cos2goPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 333, 53, "cos2goPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 349, 42, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 349, 55, "batEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 353, 42, "fulEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 353, 55, "fulEngPreMat",
  "clcDP_olyHyb_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_olyHyb_port.m",
  0 };

/* Function Definitions */
void clcDP_olyHyb_port(const emlrtStack *sp, real_T disFlg, real_T wayStp,
  real_T batEngStp, real_T batEngBeg, real_T batPwrAux, real_T psiBatEng, real_T
  psiTim, real_T staChgPenCosVal, real_T wayInxBeg, real_T wayInxEnd, real_T
  engKinBegInx, real_T engKinNum, real_T staNum, real_T wayNum, real_T staBeg,
  const real_T engKinNumVec_wayInx[800], const real_T slpVec_wayInx[800], const
  real_T engKinMat_engKinInx_wayInx[8800], const struct2_T *fzg_scalar_struct,
  const struct4_T *fzg_array_struct, emxArray_real_T *optPreInxTn3,
  emxArray_real_T *batFrcOptTn3, emxArray_real_T *fulEngOptTn3, emxArray_real_T *
  cos2goActMat)
{
  int32_T i1;
  real_T vehAcc;
  real_T cosAct;
  real_T staChgPenCos;
  int32_T i;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  emxArray_real_T *cos2goPreMat;
  emxArray_real_T *batEngPreMat;
  emxArray_real_T *fulEngPreMat;
  int32_T wayInx;
  emxArray_real_T *batFrcOptMat;
  emxArray_real_T *batEngActMat;
  emxArray_real_T *fulEngActMat;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  real_T b_wayInx;
  real_T engKinNumPre;
  int32_T engKinActInx;
  real_T engKinAct;
  int32_T staAct;
  real_T cosHamMin;
  int32_T staPreOptInx;
  real_T engKinPreOptInx;
  real_T fulEngOpt;
  real_T batFrcOpt;
  real_T batEngOpt;
  int32_T staPreMin;
  real_T staPreMax;
  int32_T staPre;
  real_T b_staPre;
  real_T fulFrc;
  real_T batFrc;
  boolean_T b0;
  boolean_T b1;
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 30 };

  const mxArray *m1;
  char_T cv4[30];
  static const char_T cv5[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O',
    'f', 'R', 'a', 'n', 'g', 'e' };

  boolean_T b2;
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 30 };

  int32_T iv4[2];
  int32_T iv5[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*   --- Ausgangsgrößen: */
  /*  Tensor 3. Stufe f�r opt. Vorg�ngerkoordinaten */
  /*  Tensor 3. Stufe der Batteriekraft */
  /*  Tensor 3. Stufe f�r die Kraftstoffenergie */
  /*  Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  --- Eingangsgr��en: */
  /*  Skalar - Flag f�r Ausgabe in das Commandwindow */
  /*  Skalar f�r die Wegschrittweite in m */
  /*  Skalar der Batteriediskretisierung in J */
  /*  Skalar f�r die Batterieenergie am Beginn in Ws */
  /*  Skalar f�r die Nebenverbrauchlast in W */
  /*  Skalar f�r den Co-State der Batterieenergie */
  /*  Skalar f�r den Co-State der Zeit */
  /*  Skalar f�r die Strafkosten beim Zustandswechsel */
  /*  Skalar f�r Anfangsindex in den Eingangsdaten */
  /*  Skalar f�r Endindex in den Eingangsdaten */
  /*  Skalar f�r den Index der Anfangsgeschwindigkeit */
  /*  Skalar f�r die max. Anz. an engKin-St�tzstellen */
  /*  Skalar f�r die max. Anzahl an Zustandsst�tzstellen */
  /*  Skalar f�r die Stufe der Batteriekraftmax. Anzahl an Wegst�tzstellen */
  /*  Skalar f�r den Startzustand des Antriebsstrangs */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*  Vektor der Steigungen in rad */
  /*  Matrix der kinetischen Energien in J */
  /*  struct der Fahrzeugparameter - NUR SKALARS */
  /*  struct der Fahrzeugparameter - NUR ARRAYS */
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
    /*      geaNum    = zeros(1,1); */
    /*      vehMas    = zeros(1,1); */
    /*      vehAccMin = zeros(1,1); */
    /*      vehAccMax = zeros(1,1); */
    /*  Anzahl der Gänge */
    /*    number of gears */
    geaNum = staNum;
    geaNum_not_empty = true;

    /*  max number of state nodes */
    /*  Fahrzeugmasse; */
    vehMas = fzg_scalar_struct->vehMas;

    /*  minmiale und maximale Beschleunigung */
    /*    min and max accerlations (bounds) */
    vehAccMin = fzg_scalar_struct->vehAccMin;
    vehAccMax = fzg_scalar_struct->vehAccMax;

    /*  In dieser Version ist der Motor immer an */
  }

  /* % Initialisieren der Ausgabe der Funktion */
  /*    initialzing function output */
  /*  Tensor 3. Stufe für optimalen Vorgängerkoordinaten */
  /*    tensor3 for optimal previous coordinates/idx */
  i1 = optPreInxTn3->size[0] * optPreInxTn3->size[1] * optPreInxTn3->size[2];
  vehAcc = emlrtNonNegativeCheckFastR2012b(engKinNum, &f_emlrtDCI, sp);
  optPreInxTn3->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(vehAcc,
    &e_emlrtDCI, sp);
  vehAcc = emlrtNonNegativeCheckFastR2012b(staNum, &h_emlrtDCI, sp);
  optPreInxTn3->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(vehAcc,
    &g_emlrtDCI, sp);
  vehAcc = emlrtNonNegativeCheckFastR2012b(wayNum, &j_emlrtDCI, sp);
  optPreInxTn3->size[2] = (int32_T)emlrtIntegerCheckFastR2012b(vehAcc,
    &i_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)optPreInxTn3, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  vehAcc = emlrtNonNegativeCheckFastR2012b(engKinNum, &f_emlrtDCI, sp);
  cosAct = emlrtNonNegativeCheckFastR2012b(staNum, &h_emlrtDCI, sp);
  staChgPenCos = emlrtNonNegativeCheckFastR2012b(wayNum, &j_emlrtDCI, sp);
  i = (int32_T)emlrtIntegerCheckFastR2012b(vehAcc, &e_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(cosAct, &g_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(staChgPenCos, &i_emlrtDCI, sp);
  for (i1 = 0; i1 < i; i1++) {
    optPreInxTn3->data[i1] = 0.0;
  }

  /*  Tensor 3. Stufe für die Kraftstoffenergie */
  /*    tensor3 for fuel energy */
  i1 = fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * fulEngOptTn3->size[2];
  fulEngOptTn3->size[0] = (int32_T)engKinNum;
  fulEngOptTn3->size[1] = (int32_T)staNum;
  fulEngOptTn3->size[2] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngOptTn3, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum * (int32_T)wayNum;
  for (i1 = 0; i1 < i; i1++) {
    fulEngOptTn3->data[i1] = rtInf;
  }

  /*    set initial fuel energy level to 0 */
  i1 = (int32_T)engKinNum;
  i2 = (int32_T)emlrtIntegerCheckFastR2012b(engKinBegInx, &b_emlrtDCI, sp);
  i3 = (int32_T)staNum;
  i4 = (int32_T)emlrtIntegerCheckFastR2012b(staBeg, &c_emlrtDCI, sp);
  i5 = (int32_T)wayNum;
  i = (int32_T)emlrtIntegerCheckFastR2012b(wayInxBeg, &d_emlrtDCI, sp);
  fulEngOptTn3->data[((emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &n_emlrtBCI,
    sp) + fulEngOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
    &o_emlrtBCI, sp) - 1)) + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i, 1, i5, &p_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  Tensor 3. Stufe für die Batterienergie */
  /*    tensor3 for battery energy */
  i1 = batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * batFrcOptTn3->size[2];
  batFrcOptTn3->size[0] = (int32_T)engKinNum;
  batFrcOptTn3->size[1] = (int32_T)staNum;
  batFrcOptTn3->size[2] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)batFrcOptTn3, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum * (int32_T)wayNum;
  for (i1 = 0; i1 < i; i1++) {
    batFrcOptTn3->data[i1] = rtInf;
  }

  b_emxInit_real_T(sp, &cos2goPreMat, 2, &c_emlrtRTEI, true);

  /* % Berechnung der optimalen Vorg�nger */
  /*    calculating the optimal predecessors */
  /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten */
  /*  Wegschritt */
  /*    initialize the matrix for the cost to the points in the last wayidx */
  i1 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
  cos2goPreMat->size[0] = (int32_T)engKinNum;
  cos2goPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum;
  for (i1 = 0; i1 < i; i1++) {
    cos2goPreMat->data[i1] = rtInf;
  }

  i1 = cos2goActMat->size[0] * cos2goActMat->size[1];
  cos2goActMat->size[0] = (int32_T)engKinNum;
  cos2goActMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum;
  for (i1 = 0; i1 < i; i1++) {
    cos2goActMat->data[i1] = rtInf;
  }

  b_emxInit_real_T(sp, &batEngPreMat, 2, &d_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit 0 für alle Zustände(concluded) */
  /*    first, initialize the startidx to 0 for all states */
  i1 = (int32_T)engKinNum;
  i2 = (int32_T)engKinBegInx;
  i3 = (int32_T)staNum;
  i4 = (int32_T)staBeg;
  cos2goPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &j_emlrtBCI,
    sp) + cos2goPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
    &k_emlrtBCI, sp) - 1)) - 1] = 0.0;

  /*  Initialisierung der Matrix der Batterieenergien */
  /*    initialize the battery energy matrix */
  i1 = batEngPreMat->size[0] * batEngPreMat->size[1];
  batEngPreMat->size[0] = (int32_T)engKinNum;
  batEngPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)batEngPreMat, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum;
  for (i1 = 0; i1 < i; i1++) {
    batEngPreMat->data[i1] = rtInf;
  }

  b_emxInit_real_T(sp, &fulEngPreMat, 2, &e_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit Startladung für den Startzustand */
  /*    first, intialize start index of the starting charge for intial state */
  i1 = (int32_T)engKinNum;
  i2 = (int32_T)engKinBegInx;
  i3 = (int32_T)staNum;
  i4 = (int32_T)staBeg;
  batEngPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &f_emlrtBCI,
    sp) + batEngPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
    &g_emlrtBCI, sp) - 1)) - 1] = batEngBeg;

  /*  Initialisierung der Matrix der Kraftstoffenergien */
  /*    initialze the fuel energy matrix */
  i1 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
  fulEngPreMat->size[0] = (int32_T)engKinNum;
  fulEngPreMat->size[1] = (int32_T)staNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i1, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  i = (int32_T)engKinNum * (int32_T)staNum;
  for (i1 = 0; i1 < i; i1++) {
    fulEngPreMat->data[i1] = rtInf;
  }

  /*  Erste Initilisierung beim Startindex mit 0 für den Startzustand */
  /*    first, intialize the start idx for the intitial states to 0 */
  i1 = (int32_T)engKinNum;
  i2 = (int32_T)engKinBegInx;
  i3 = (int32_T)staNum;
  i4 = (int32_T)staBeg;
  fulEngPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &l_emlrtBCI,
    sp) + fulEngPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
    &m_emlrtBCI, sp) - 1)) - 1] = 0.0;

  /*  Schleife über alle Wegpunkte */
  /*    looping thorugh length of # of grid discretization/indeces (Weginputs) */
  i1 = (int32_T)(wayInxEnd + (1.0 - (wayInxBeg + 1.0)));
  emlrtForLoopVectorCheckR2012b(wayInxBeg + 1.0, 1.0, wayInxEnd, mxDOUBLE_CLASS,
    i1, &o_emlrtRTEI, sp);
  wayInx = 0;
  b_emxInit_real_T(sp, &batFrcOptMat, 2, &f_emlrtRTEI, true);
  b_emxInit_real_T(sp, &batEngActMat, 2, &g_emlrtRTEI, true);
  b_emxInit_real_T(sp, &fulEngActMat, 2, &h_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &b_emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 1, &b_emlrtRTEI, true);
  while (wayInx <= i1 - 1) {
    b_wayInx = (wayInxBeg + 1.0) + (real_T)wayInx;

    /*  PATH IDX LOOP */
    /*  mittlere Steigung im betrachteten Intervall  */
    /*    no longer doing mean, using previous gradiant instead */
    i2 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, 800, &b_emlrtBCI, sp);

    /*     %% Berechnung der kinetischen Energien im aktuellen Wegschritt */
    /*  Vorbereitung der FZGallen Schleife (verhindern von zu grossem */
    /*  Datentransfer und unnötigen Berechnungen) */
    /*    Calculating the KE for current index/waypoint. */
    /*    Preperation of FZGallel loop (prevent a too large data transfer, */
    /*    unnecessary computations).    */
    /*  Initialisieren der Matrix für die optimalen Batteriekrafter im */
    /*  Intervall */
    /*    initialize matrix for optimale battery force intervals (discreti.) */
    i2 = batFrcOptMat->size[0] * batFrcOptMat->size[1];
    batFrcOptMat->size[0] = (int32_T)engKinNum;
    batFrcOptMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)batFrcOptMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = (int32_T)engKinNum * (int32_T)staNum;
    for (i2 = 0; i2 < i; i2++) {
      batFrcOptMat->data[i2] = rtInf;
    }

    /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize cost matrix to points in current path steps (idxs?) */
    i2 = cos2goActMat->size[0] * cos2goActMat->size[1];
    cos2goActMat->size[0] = (int32_T)engKinNum;
    cos2goActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = (int32_T)engKinNum * (int32_T)staNum;
    for (i2 = 0; i2 < i; i2++) {
      cos2goActMat->data[i2] = rtInf;
    }

    /*  Initialisieren der Matrix für die Batterieenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for battery energy at points along current wayidx */
    i2 = batEngActMat->size[0] * batEngActMat->size[1];
    batEngActMat->size[0] = (int32_T)engKinNum;
    batEngActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)batEngActMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = (int32_T)engKinNum * (int32_T)staNum;
    for (i2 = 0; i2 < i; i2++) {
      batEngActMat->data[i2] = rtInf;
    }

    /*  Initialisieren der Matrix für die Krafstoffenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for fuel energie along current way idxs */
    i2 = fulEngActMat->size[0] * fulEngActMat->size[1];
    fulEngActMat->size[0] = (int32_T)engKinNum;
    fulEngActMat->size[1] = (int32_T)staNum;
    emxEnsureCapacity(sp, (emxArray__common *)fulEngActMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = (int32_T)engKinNum * (int32_T)staNum;
    for (i2 = 0; i2 < i; i2++) {
      fulEngActMat->data[i2] = rtInf;
    }

    /*  Anzahl der kinetischen Energien im aktuellen und im */
    /*  Vorgängerwegschritt */
    /*    number of kinetic energies in current and past path_idxs */
    i2 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, 800, &c_emlrtBCI, sp);

    /*  look at this loop's KE */
    i2 = (int32_T)b_wayInx - 1;
    engKinNumPre = engKinNumVec_wayInx[emlrtDynamicBoundsCheckFastR2012b(i2, 1,
      800, &s_emlrtBCI, sp) - 1];

    /*  and the previous idx KE */
    /*  Vektoren der kinetischen Energien im vorherigen Wegschritt */
    /*    vector of the KE in the previous idx */
    i2 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, 800, &d_emlrtBCI, sp);

    /*  Vektoren der kinetischen Energien im aktuellen Wegschritt */
    /*    KE vector of the current path_idx */
    /*  (FZGfor) Schleife �ber alle akutellen kinetischen Energien */
    /*    loop through all the current kinetic energies */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, engKinNumVec_wayInx[(int32_T)
      b_wayInx - 1], mxDOUBLE_CLASS, (int32_T)engKinNumVec_wayInx[(int32_T)
      b_wayInx - 1], &p_emlrtRTEI, sp);
    engKinActInx = 1;
    while (engKinActInx - 1 <= (int32_T)engKinNumVec_wayInx[(int32_T)b_wayInx -
           1] - 1) {
      /*  CURRENT KINETIC ENERGY LOOP */
      /*  akutelle kinetsiche Energie bestimmen */
      /*    determine the current kinetic energy */
      engKinAct = engKinMat_engKinInx_wayInx[(emlrtDynamicBoundsCheckFastR2012b
        (engKinActInx, 1, 11, &t_emlrtBCI, sp) + 11 * ((int32_T)b_wayInx - 1)) -
        1];

      /*  Schleife �ber alle m�glichen aktuellen Zust�nde des Antriesstrangs */
      /*    Loop over all possible current powertrain states/all the gears */
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, staNum, mxDOUBLE_CLASS, (int32_T)
        staNum, &q_emlrtRTEI, sp);
      staAct = 0;
      while (staAct <= (int32_T)staNum - 1) {
        /*  ALL GEARS LOOP */
        /*             %% Initialsiieren */
        /*    note-you are preallocating over each powertrain state loop */
        /*  Initialisieren der Ausgabegr��e der Schleife */
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
        /*  Vorg�ngerzust�nde des Antriebsstrangs beschränken */
        /*    determine gear possibilities - ie u(g)  */
        staPreMin = (int32_T)muDoubleScalarMax(1.0, (1.0 + (real_T)staAct) - 1.0);
        staPreMax = muDoubleScalarMin(geaNum, (1.0 + (real_T)staAct) + 1.0);

        /*             %% Schleife über alle kinetischen Energien (Vorgänger) */
        /*    loop through all the kinetic energies (previous state idxs) */
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, engKinNumPre, mxDOUBLE_CLASS,
          (int32_T)engKinNumPre, &r_emlrtRTEI, sp);
        i = 0;
        while (i <= (int32_T)engKinNumPre - 1) {
          /*  PREVIOUS KE LOOP */
          /*  kinetsiche Energie des betrachten(consider) Vorgängerspunkts */
          /*  bestimmen(determine) */
          /*    determine the kinetic energy of the previous path_idx */
          i2 = i + 1;
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, 11, &e_emlrtBCI, sp);

          /*  Prüfen(check), ob eine erlaubte Beschleunigung vorliegt. */
          /*  Ansonsten zum nächsten Schleifendurchlauf springen */
          /*    Check whether an allowable acceleration exists. */
          /*    Otherwise, jump to the next iteration */
          vehAcc = (engKinAct - engKinMat_engKinInx_wayInx[i + 11 * ((int32_T)
                     b_wayInx - 2)]) / vehMas / wayStp;
          if ((vehAcc < vehAccMin) || (vehAcc > vehAccMax)) {
          } else {
            /*  Schleife über allen Zustände (relativer Index) */
            /*    Loop through all the states (relative index) */
            i2 = (int32_T)(staPreMax + (1.0 - (real_T)staPreMin));
            emlrtForLoopVectorCheckR2012b(staPreMin, 1.0, staPreMax,
              mxDOUBLE_CLASS, i2, &s_emlrtRTEI, sp);
            staPre = 0;
            while (staPre <= i2 - 1) {
              b_staPre = (real_T)staPreMin + (real_T)staPre;

              /*  CURRENT GEAR CHANGE LOOP */
              /*                     %% Batterieenergie beim betrachteten Vorgänger */
              /*  battery energy when considering last path_idx */
              /*    note: batengPreMat has dims #_KE_states x #_gears */
              i3 = batEngPreMat->size[0];
              i4 = i + 1;
              emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &h_emlrtBCI, sp);
              i3 = batEngPreMat->size[1];
              i4 = (int32_T)b_staPre;
              emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3, &i_emlrtBCI, sp);

              /*  Sollte es keinen gültigen Vorgänger geben, wird zum */
              /*  nächsten Schleifendurchlauf gesprungen */
              /*    if there is no valid previous battery energy, jump */
              /*    to the next loop iteration */
              if (muDoubleScalarIsInf(batEngPreMat->data[i + batEngPreMat->size
                                      [0] * ((int32_T)b_staPre - 1)])) {
              } else {
                /*                     %% Antriebsstrangzustand und Strafkosten bestimmen    */
                /*    determine gear and penalty costs */
                /*  Kosten für Zustandswechsel setzen */
                /*    set costs for state changes */
                if (1.0 + (real_T)staAct == b_staPre) {
                  /*  Entspricht der Vorg�ngerzustand dem aktuellen  */
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
                st.site = &f_emlrtRSI;
                clcPMP_olyHyb_port(&st, engKinMat_engKinInx_wayInx[i + 11 *
                                   ((int32_T)b_wayInx - 2)], engKinAct, 1.0 +
                                   (real_T)staAct, slpVec_wayInx[(int32_T)
                                   b_wayInx - 2], batEngPreMat->data[i +
                                   batEngPreMat->size[0] * ((int32_T)b_staPre -
                  1)], psiBatEng, psiTim, batPwrAux, batEngStp, wayStp,
                                   fzg_scalar_struct, fzg_array_struct, &vehAcc,
                                   &batFrc, &fulFrc);

                /*                      % minimale Kosten der Hamiltonfunktion zum aktuellen */
                /*                      % Punkt bestimmen */
                /*                      [cosHamMin,optPreInx] ... */
                /*                          = min([cosHam... */
                /*                          + cos2goPreMat(engKinPreInx,staPre)... */
                /*                          + staChgPenCos... */
                /*                          ,cosHamMin]); %#ok<PFBNS> */
                /*  combine the min hamil. cost w/ previous costs and  */
                /*    gear penalty to get current cost */
                i3 = cos2goPreMat->size[0];
                i4 = cos2goPreMat->size[1];
                i5 = (int32_T)b_staPre;
                cosAct = (vehAcc + cos2goPreMat->data
                          [(emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i3,
                            &gb_emlrtBCI, sp) + cos2goPreMat->size[0] *
                            (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                  &hb_emlrtBCI, sp) - 1)) - 1]) + staChgPenCos / wayStp;

                /*  Wenn der aktuelle Punkt besser ist, als der in */
                /*  cosHamMin gespeicherte Wert, werden die Ausgabegr��en */
                /*  neu beschrieben. */
                /*    if current point is better than the cost value */
                /*    stored in CosHamMin, then rewrite the output */
                if (cosAct < cosHamMin) {
                  cosHamMin = cosAct;

                  /*  new hamil. cost */
                  staPreOptInx = (int32_T)b_staPre;

                  /*  new optimal gear idx */
                  engKinPreOptInx = 1.0 + (real_T)i;

                  /*  new optimal KEidx */
                  batFrcOpt = batFrc;

                  /*  new optimal battery force */
                  /*  new opt. battery energy = (batt. force * */
                  /*  displacement diff) + previous battery energy valu */
                  i3 = batEngPreMat->size[0];
                  i4 = batEngPreMat->size[1];
                  i5 = (int32_T)b_staPre;
                  batEngOpt = batFrc * wayStp + batEngPreMat->data
                    [(emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i3,
                       &ib_emlrtBCI, sp) + batEngPreMat->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &jb_emlrtBCI,
                        sp) - 1)) - 1];

                  /*  new opt. fuel energy = (fuel force * displacement */
                  /*  diff) + previous fuel energy value */
                  i3 = fulEngPreMat->size[0];
                  i4 = fulEngPreMat->size[1];
                  i5 = (int32_T)b_staPre;
                  fulEngOpt = fulFrc * wayStp + fulEngPreMat->data
                    [(emlrtDynamicBoundsCheckFastR2012b(i + 1, 1, i3,
                       &kb_emlrtBCI, sp) + fulEngPreMat->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &lb_emlrtBCI,
                        sp) - 1)) - 1];
                }
              }

              staPre++;
              emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
            }

            /*  end of gear changes loop */
          }

          i++;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        }

        /*  end of running through previous KE states loop */
        if (!muDoubleScalarIsInf(cosHamMin)) {
          /*  optimale Kosten zum aktuellen Punkt speichern */
          /*    save min hamilton value for current point */
          i2 = cos2goActMat->size[0];
          i3 = cos2goActMat->size[1];
          cos2goActMat->data[(emlrtDynamicBoundsCheckFastR2012b(engKinActInx, 1,
            i2, &u_emlrtBCI, sp) + cos2goActMat->size[0] *
                              (emlrtDynamicBoundsCheckFastR2012b(staAct + 1, 1,
            i3, &v_emlrtBCI, sp) - 1)) - 1] = cosHamMin;

          /*  optimale Batterieenergie zum aktuellen Punkt speichern */
          /*    save optimal battery energy for current point */
          i2 = batEngActMat->size[0];
          i3 = batEngActMat->size[1];
          batEngActMat->data[(emlrtDynamicBoundsCheckFastR2012b(engKinActInx, 1,
            i2, &w_emlrtBCI, sp) + batEngActMat->size[0] *
                              (emlrtDynamicBoundsCheckFastR2012b(staAct + 1, 1,
            i3, &x_emlrtBCI, sp) - 1)) - 1] = batEngOpt;

          /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
          /*    save optimal fuel energy for current point */
          i2 = fulEngActMat->size[0];
          i3 = fulEngActMat->size[1];
          fulEngActMat->data[(emlrtDynamicBoundsCheckFastR2012b(engKinActInx, 1,
            i2, &y_emlrtBCI, sp) + fulEngActMat->size[0] *
                              (emlrtDynamicBoundsCheckFastR2012b(staAct + 1, 1,
            i3, &ab_emlrtBCI, sp) - 1)) - 1] = fulEngOpt;

          /*  optimale Batterieenergie zum aktuellen Punkt */
          /*  Flussgröße gilt im Intervall */
          /*    populate optimal battery energy flux quantity at point  */
          /*    that's applicable to current interval */
          i2 = batFrcOptMat->size[0];
          i3 = batFrcOptMat->size[1];
          batFrcOptMat->data[(emlrtDynamicBoundsCheckFastR2012b(engKinActInx, 1,
            i2, &bb_emlrtBCI, sp) + batFrcOptMat->size[0] *
                              (emlrtDynamicBoundsCheckFastR2012b(staAct + 1, 1,
            i3, &cb_emlrtBCI, sp) - 1)) - 1] = batFrcOpt;

          /*  optimalen Vorgänger codieren über Funktion sub2ind */
          /*  und speichern im Tensor */
          /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
          st.site = &g_emlrtRSI;
          b_st.site = &r_emlrtRSI;
          if ((engKinPreOptInx >= 1.0) && ((int32_T)engKinNum >= engKinPreOptInx))
          {
            b0 = true;
          } else {
            b0 = false;
          }

          c_st.site = &s_emlrtRSI;
          if (!b0) {
            b1 = false;
          } else {
            b1 = true;
          }

          if (b1) {
          } else {
            y = NULL;
            m1 = emlrtCreateCharArray(2, iv2);
            for (i = 0; i < 30; i++) {
              cv4[i] = cv5[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 30, m1, cv4);
            emlrtAssign(&y, m1);
            d_st.site = &tb_emlrtRSI;
            error(&d_st, b_message(&d_st, y, &d_emlrtMCI), &d_emlrtMCI);
          }

          c_st.site = &t_emlrtRSI;
          d_st.site = &u_emlrtRSI;
          if ((staPreOptInx >= 1) && ((int32_T)staNum >= staPreOptInx)) {
            b0 = true;
          } else {
            b0 = false;
          }

          c_st.site = &s_emlrtRSI;
          if (!b0) {
            b2 = false;
          } else {
            b2 = true;
          }

          if (b2) {
          } else {
            b_y = NULL;
            m1 = emlrtCreateCharArray(2, iv3);
            for (i = 0; i < 30; i++) {
              cv4[i] = cv5[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 30, m1, cv4);
            emlrtAssign(&b_y, m1);
            d_st.site = &tb_emlrtRSI;
            error(&d_st, b_message(&d_st, b_y, &d_emlrtMCI), &d_emlrtMCI);
          }

          i2 = optPreInxTn3->size[0];
          i3 = optPreInxTn3->size[1];
          i4 = optPreInxTn3->size[2];
          i5 = (int32_T)b_wayInx;
          optPreInxTn3->data[((emlrtDynamicBoundsCheckFastR2012b(engKinActInx, 1,
            i2, &db_emlrtBCI, sp) + optPreInxTn3->size[0] *
                               (emlrtDynamicBoundsCheckFastR2012b(staAct + 1, 1,
            i3, &eb_emlrtBCI, sp) - 1)) + optPreInxTn3->size[0] *
                              optPreInxTn3->size[1] *
                              (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
            &fb_emlrtBCI, sp) - 1)) - 1] = (int32_T)engKinPreOptInx + (int32_T)
            engKinNum * (staPreOptInx - 1);
        }

        /*  end of ~inf(hamiltonian) if-statement */
        staAct++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      /*  end of looping through all gears */
      engKinActInx++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  end of looping through all the current kinetic energy states */
    /*  Speichern der Batterieenergie für den nächsten Schleifendurchlauf */
    /*    save battery energy value as previous path_idx val for next loop  */
    i2 = batEngPreMat->size[0] * batEngPreMat->size[1];
    batEngPreMat->size[0] = batEngActMat->size[0];
    batEngPreMat->size[1] = batEngActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)batEngPreMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = batEngActMat->size[0] * batEngActMat->size[1];
    for (i2 = 0; i2 < i; i2++) {
      batEngPreMat->data[i2] = batEngActMat->data[i2];
    }

    /*  Speichern der Krafstoffenergie für den nächsten Schleifendurchlauf */
    /*    save fuel energy value as previous path_idx value for the next loop */
    i2 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
    fulEngPreMat->size[0] = fulEngActMat->size[0];
    fulEngPreMat->size[1] = fulEngActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = fulEngActMat->size[0] * fulEngActMat->size[1];
    for (i2 = 0; i2 < i; i2++) {
      fulEngPreMat->data[i2] = fulEngActMat->data[i2];
    }

    /*  Speichern der Kosten für den nächsten Schleifendurchlauf */
    /*    save cost as previous path_idx value for the next loop */
    i2 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
    cos2goPreMat->size[0] = cos2goActMat->size[0];
    cos2goPreMat->size[1] = cos2goActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i2, (int32_T)sizeof
                      (real_T), &b_emlrtRTEI);
    i = cos2goActMat->size[0] * cos2goActMat->size[1];
    for (i2 = 0; i2 < i; i2++) {
      cos2goPreMat->data[i2] = cos2goActMat->data[i2];
    }

    /*  optimale Kraftstoffenergie zum aktuellen Punkt */
    /*    optimal fuel energy at current point - save current mat in tensor */
    i = fulEngOptTn3->size[0];
    i2 = r0->size[0];
    r0->size[0] = i;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i2, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    for (i2 = 0; i2 < i; i2++) {
      r0->data[i2] = i2;
    }

    i = fulEngOptTn3->size[1];
    i2 = r1->size[0];
    r1->size[0] = i;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i2, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    for (i2 = 0; i2 < i; i2++) {
      r1->data[i2] = i2;
    }

    i2 = fulEngOptTn3->size[2];
    i3 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &q_emlrtBCI, sp);
    iv4[0] = r0->size[0];
    iv4[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])fulEngActMat->size, 2,
      &emlrtECI, sp);
    i = fulEngActMat->size[1];
    for (i2 = 0; i2 < i; i2++) {
      staPreMin = fulEngActMat->size[0];
      for (i3 = 0; i3 < staPreMin; i3++) {
        fulEngOptTn3->data[(r0->data[i3] + fulEngOptTn3->size[0] * r1->data[i2])
          + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int32_T)b_wayInx -
          1)] = fulEngActMat->data[i3 + fulEngActMat->size[0] * i2];
      }
    }

    /*  optimale Batterieenergie zum aktuellen Punkt */
    /*    optimal battery force at current point - save current mat in tensor */
    /*  Flussgröße gilt im Intervall */
    /*    flux quantity applied over the interval */
    i = batFrcOptTn3->size[0];
    i2 = r0->size[0];
    r0->size[0] = i;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i2, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    for (i2 = 0; i2 < i; i2++) {
      r0->data[i2] = i2;
    }

    i = batFrcOptTn3->size[1];
    i2 = r1->size[0];
    r1->size[0] = i;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i2, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    for (i2 = 0; i2 < i; i2++) {
      r1->data[i2] = i2;
    }

    i2 = batFrcOptTn3->size[2];
    i3 = (int32_T)(b_wayInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &r_emlrtBCI, sp);
    iv5[0] = r0->size[0];
    iv5[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv5, 2, *(int32_T (*)[2])batFrcOptMat->size, 2,
      &b_emlrtECI, sp);
    i = batFrcOptMat->size[1];
    for (i2 = 0; i2 < i; i2++) {
      staPreMin = batFrcOptMat->size[0];
      for (i3 = 0; i3 < staPreMin; i3++) {
        batFrcOptTn3->data[(r0->data[i3] + batFrcOptTn3->size[0] * r1->data[i2])
          + batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * ((int32_T)b_wayInx -
          2)] = batFrcOptMat->data[i3 + batFrcOptMat->size[0] * i2];
      }
    }

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (disFlg != 0.0) {
      st.site = &h_emlrtRSI;
      d_fprintf(&st, b_wayInx - wayInxBeg, (b_wayInx - wayInxBeg) / (wayInxEnd -
                 wayInxBeg) * 100.0);
    }

    wayInx++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
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

void clcDP_olyHyb_port_init(void)
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

/* End of code generation (clcDP_olyHyb_port.c) */
