/*
 * clcDP_focus.c
 *
 * Code generation for function 'clcDP_focus'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "clcDP_focus_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "optTrqSplit_focus.h"
#include "fprintf.h"
#include "clcDP_focus_mexutil.h"
#include "clcDP_focus_data.h"
#include <stdio.h>

/* Variable Definitions */
static real_T engNum;
static real_T engStaMin;
static real_T engStaMax;
static real_T geaNum;
static boolean_T geaNum_not_empty;
static real_T geaStaMin;
static real_T geaStaMax;
static real_T iceFlg;
static real_T batStaMin;
static real_T batStaStp;
static real_T batStaMax;
static real_T batNum;
static emlrtRSInfo emlrtRSI = { 214, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo b_emlrtRSI = { 279, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo c_emlrtRSI = { 280, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo d_emlrtRSI = { 389, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo e_emlrtRSI = { 448, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo f_emlrtRSI = { 562, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo g_emlrtRSI = { 648, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo h_emlrtRSI = { 649, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo i_emlrtRSI = { 650, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo j_emlrtRSI = { 702, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo k_emlrtRSI = { 707, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo l_emlrtRSI = { 710, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo m_emlrtRSI = { 752, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo n_emlrtRSI = { 21, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo o_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo p_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo q_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo r_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo s_emlrtRSI = { 16, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo t_emlrtRSI = { 18, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo u_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo v_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo w_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo x_emlrtRSI = { 16, "max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

static emlrtRSInfo gb_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo hb_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ib_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo jb_emlrtRSI = { 106, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo kb_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo lb_emlrtRSI = { 16, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo mb_emlrtRSI = { 41, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo nb_emlrtRSI = { 39, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo ob_emlrtRSI = { 71, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtMCInfo emlrtMCI = { 405, 5, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtMCInfo b_emlrtMCI = { 404, 15, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtMCInfo f_emlrtMCI = { 41, 9, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo g_emlrtMCI = { 38, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo h_emlrtMCI = { 82, 9, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo i_emlrtMCI = { 81, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo j_emlrtMCI = { 28, 19, "assert",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\assert.m"
};

static emlrtRTEInfo emlrtRTEI = { 10, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 284, 1, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo c_emlrtRTEI = { 91, 1, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 188, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 205, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 214, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 236, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 246, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 251, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 255, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 256, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 257, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 351, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 353, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 354, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 355, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 448, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtECInfo emlrtECI = { -1, 748, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 748, 24, "brkTrqOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 746, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 746, 24, "iceTrqOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 744, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 744, 24, "emoTrqOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 734, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 734, 24, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 174, 74, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo emlrtDCI = { 174, 74, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 174, 56, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 174, 56, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 174, 36, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 174, 36, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 174, 14, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 174, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtECInfo e_emlrtECI = { -1, 739, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo i_emlrtBCI = { -1, -1, 739, 24, "batPwrOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 636, 50, "brkTrqPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 636, 50, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 629, 42, "emoTrqPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 629, 42, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 667, 66, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 667, 50, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 667, 34, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 208, 56, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 208, 56, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 208, 36, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 208, 36, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 208, 14, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 208, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 652, 69, "colminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 652, 52, "colminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 651, 39, "matminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 623, 39, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 623, 39, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 634, 45, "batStaActInxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 625, 48, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 625, 48, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 193, 56, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 193, 56, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 193, 36, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 193, 36, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 193, 14, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 193, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo bb_emlrtBCI = { 1, 693, 555, 45, "batOcv", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 555, 45, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 538, 48, "batStaPreIdxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { 1, 1181, 501, 60, "iceTrqMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { 1, 1181, 500, 60, "iceTrqMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { 1, 1181, 495, 56, "emoPwrMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { 1, 1181, 494, 56, "emoPwrMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { 1, 1181, 491, 56, "emoTrqMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { 1, 1181, 490, 56, "emoTrqMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { 1, 1181, 488, 47, "crsTrqMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { 1, 6, 487, 57, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 487, 57, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo lb_emlrtBCI = { 1, 1181, 487, 47, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { 1, 1181, 414, 73, "batPwrMaxIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { 1, 693, 413, 83, "batPwrMinIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { 1, 1181, 413, 73, "batPwrMinIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo pb_emlrtBCI = { 1, 6, 329, 21, "crsSpdActVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 329, 21, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo qb_emlrtBCI = { 1, 6, 316, 21, "crsSpdActVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo r_emlrtDCI = { 316, 21, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtRTEInfo s_emlrtRTEI = { 306, 9, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo t_emlrtRTEI = { 302, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo rb_emlrtBCI = { 1, 1181, 280, 75, "batPwrMaxIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { 1, 1181, 279, 75, "batPwrMinIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { 1, 1181, 270, 30, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { 1, 1181, 260, 20, "engStaVec_timInx",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 260, 20, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtRTEInfo u_emlrtRTEI = { 223, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtDCInfo t_emlrtDCI = { 159, 22, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo u_emlrtDCI = { 159, 22, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo v_emlrtDCI = { 159, 30, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo w_emlrtDCI = { 159, 30, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo x_emlrtDCI = { 159, 38, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo y_emlrtDCI = { 159, 38, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo ab_emlrtDCI = { 159, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo bb_emlrtDCI = { 159, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtBCInfo vb_emlrtBCI = { 1, 1181, 265, 18, "velVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 265, 18, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo wb_emlrtBCI = { 1, 1181, 265, 35, "velVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 265, 35, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 345, 29, "batStaActInxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 671, 34, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 671, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 671, 46, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 671, 56, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 675, 34, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 675, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 675, 46, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 675, 56, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 679, 34, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 679, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 679, 46, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 679, 56, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 685, 34, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 685, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 685, 46, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 685, 56, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 689, 34, "emoTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 689, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 689, 46, "emoTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 689, 56, "emoTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 690, 38, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 690, 55, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 690, 72, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 692, 34, "iceTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 692, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 692, 46, "iceTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 692, 56, "iceTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 693, 38, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 693, 55, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 693, 72, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 695, 34, "brkTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 695, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 695, 46, "brkTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 695, 56, "brkTrqActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 696, 38, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 696, 55, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 696, 72, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 701, 34, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo lb_emlrtDCI = { 701, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 701, 46, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 701, 56, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 701, 69, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 454, 33, "engStaPreIdx",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 466, 37, "geaStaPreIdxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 623, 52, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 623, 63, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 623, 63, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 625, 61, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 625, 72, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 625, 72, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 629, 55, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 629, 65, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 636, 63, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 636, 74, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 588, 43, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo ob_emlrtDCI = { 588, 43, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 588, 56, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 588, 66, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 590, 52, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo pb_emlrtDCI = { 590, 52, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 590, 64, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 590, 75, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 594, 46, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo qb_emlrtDCI = { 594, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 594, 59, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 594, 69, "emoTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 595, 46, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo rb_emlrtDCI = { 595, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 595, 59, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 595, 69, "iceTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 596, 46, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo sb_emlrtDCI = { 596, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 596, 59, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 596, 69, "brkTrqPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtRSInfo qb_emlrtRSI = { 28, "assert",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\assert.m"
};

static emlrtRSInfo rb_emlrtRSI = { 81, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo sb_emlrtRSI = { 38, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo tb_emlrtRSI = { 404, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo wb_emlrtRSI = { 82, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo xb_emlrtRSI = { 41, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo yb_emlrtRSI = { 405, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

/* Function Declarations */
static int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator);
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);

/* Function Definitions */
static int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  if (numerator >= 0) {
    absNumerator = (uint32_T)numerator;
  } else {
    absNumerator = (uint32_T)-numerator;
  }

  if (denominator >= 0) {
    absDenominator = (uint32_T)denominator;
  } else {
    absDenominator = (uint32_T)-denominator;
  }

  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  if (quotientNeedsNegation) {
    absNumerator %= absDenominator;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
  }

  if (quotientNeedsNegation) {
    quotient = -(int32_T)tempAbsQuotient;
  } else {
    quotient = (int32_T)tempAbsQuotient;
  }

  return quotient;
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m10;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 1, &pArray, "message", true,
    location);
}

void batNum_not_empty_init(void)
{
}

void batStaMax_not_empty_init(void)
{
}

void batStaMin_not_empty_init(void)
{
}

void batStaStp_not_empty_init(void)
{
}

void clcDP_focus(const emlrtStack *sp, real_T batEngBeg, real_T timNum, const
                 real_T engStaVec_timInx[1181], const real_T batOcv[693], const
                 real_T velVec[1181], const real_T crsSpdMat[7086], const real_T
                 crsTrqMat[7086], const real_T emoTrqMinPosMat[7086], const
                 real_T emoTrqMaxPosMat[7086], const real_T emoPwrMinPosMat[7086],
                 const real_T emoPwrMaxPosMat[7086], const real_T
                 iceTrqMinPosMat[7086], const real_T iceTrqMaxPosMat[7086],
                 const real_T batPwrMinIdxTn3[4910598], const real_T
                 batPwrMaxIdxTn3[4910598], const real_T batPwrDemIdxTn3[4910598],
                 const struct0_T *inputparams, const struct1_T
                 *tst_scalar_struct, const struct2_T *fzg_scalar_struct, const
                 struct3_T *fzg_array_struct, emxArray_real_T *optPreInxTn4,
                 emxArray_real_T *batPwrOptTn4, emxArray_real_T *fulEngOptTn4,
                 emxArray_real_T *emoTrqOptTn4, emxArray_real_T *iceTrqOptTn4,
                 emxArray_real_T *brkTrqOptTn4, emxArray_real_T *cos2goActTn3)
{
  real_T crsSpdEmoMax;
  real_T crsSpdHybMax;
  real_T crsSpdHybMin;
  int32_T i0;
  real_T absa;
  real_T batEngInxBeg;
  real_T batStaPreIdx_noEmo;
  real_T batStaLimMax;
  int32_T iy;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T cindx;
  int32_T ix;
  int32_T i;
  int32_T npages;
  emxArray_real_T *cos2goPreTn3;
  emxArray_real_T *fulEngPreTn3;
  int32_T n;
  real_T geaStaPre;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  real_T absb;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 21 };

  const mxArray *m0;
  char_T cv0[21];
  static const char_T cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *batStaActInxVec;
  int32_T nm1d2;
  int32_T timInx;
  emxArray_real_T *batPwrOptTn3;
  emxArray_real_T *batEngActTn3;
  emxArray_real_T *fulEngActTn3;
  emxArray_real_T *emoTrqActTn3;
  emxArray_real_T *iceTrqActTn3;
  emxArray_real_T *brkTrqActTn3;
  emxArray_real_T *fulActTn3;
  emxArray_real_T *emoTrqPreTn3;
  emxArray_real_T *iceTrqPreTn3;
  emxArray_real_T *brkTrqPreTn3;
  emxArray_real_T *batStaPreIdxVec;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *b_y;
  emxArray_real_T *indx;
  emxArray_real_T *extremum;
  emxArray_int32_T *iindx;
  emxArray_real_T *b_indx;
  emxArray_real_T *b_extremum;
  emxArray_int32_T *b_iindx;
  real_T b_timInx;
  real_T vehVelVec[2];
  int32_T b_ix;
  boolean_T c_ix;
  boolean_T exitg5;
  boolean_T b_nm1d2;
  boolean_T d_ix;
  boolean_T exitg4;
  boolean_T c_nm1d2;
  real_T b_engStaMin;
  int32_T engStaAct;
  real_T b_engStaAct;
  real_T b_geaStaMin;
  int32_T geaStaAct;
  real_T b_geaStaAct;
  boolean_T guard1 = false;
  int32_T batStaActInx;
  real_T batStaAct;
  int32_T engStaPreIdx_size_idx_1;
  real_T engStaPreIdx_data[2];
  real_T dv0[2];
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 21 };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 21 };

  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T ixstop;
  const mxArray *e_y;
  static const int32_T iv3[2] = { 1, 36 };

  char_T cv2[36];
  static const char_T cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *f_y;
  static const int32_T iv4[2] = { 1, 39 };

  char_T cv4[39];
  static const char_T cv5[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  uint32_T outsz[3];
  uint32_T b_outsz;
  uint32_T c_outsz;
  boolean_T b0;
  boolean_T e_ix;
  boolean_T exitg3;
  boolean_T d_nm1d2;
  const mxArray *g_y;
  static const int32_T iv5[2] = { 1, 36 };

  const mxArray *h_y;
  static const int32_T iv6[2] = { 1, 39 };

  boolean_T b1;
  boolean_T f_ix;
  boolean_T exitg2;
  boolean_T e_nm1d2;
  const mxArray *i_y;
  static const int32_T iv7[2] = { 1, 36 };

  const mxArray *j_y;
  static const int32_T iv8[2] = { 1, 39 };

  boolean_T exitg1;
  boolean_T b_overflow;
  const mxArray *k_y;
  static const int32_T iv9[2] = { 1, 30 };

  char_T cv6[30];
  static const char_T cv7[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O',
    'f', 'R', 'a', 'n', 'g', 'e' };

  boolean_T c_overflow;
  const mxArray *l_y;
  static const int32_T iv10[2] = { 1, 30 };

  boolean_T d_overflow;
  const mxArray *m_y;
  static const int32_T iv11[2] = { 1, 30 };

  int32_T iv12[3];
  int32_T iv13[3];
  int32_T iv14[3];
  int32_T iv15[3];
  int32_T iv16[3];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &c_st;
  g_st.tls = c_st.tls;
  h_st.prev = &e_st;
  h_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*   --- AusgangsgrÃ¶ÃŸen: */
  /*  Tensor 3. Stufe fï¿½r opt. Vorgï¿½ngerkoordinaten */
  /*  Tensor 3. Stufe der Batteriekraft */
  /*  Tensor 3. Stufe fï¿½r die Kraftstoffenergie */
  /*  tensor - saves optimal emoTrq values */
  /*  tensor - saves optimal iceTrq values */
  /*  tensor - saves optimal brkTrq values */
  /*  Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  --- Eingangsgrï¿½ï¿½en: */
  /*  Skalar fï¿½r die Batterieenergie am Beginn in Ws */
  /*  Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen */
  /*  scalar - end engine state */
  /*  battery voltage vector w/ value for each SOC */
  /*  velocity vector contiaing input speed profile */
  /*  crankshaft speed demand for each gear */
  /*  crankshaft torque demand for each gear */
  /*  min emoTrq along speed profile for each gear */
  /*  max emoTrq along speed profile for each gear */
  /*  min emoPwr along speed profile for each gear */
  /*  max emoPwr along speed profile for each gear */
  /*  min iceTrq along speed profile for each gear */
  /*  max iceTrq along speed profile for each gear */
  /*  min indexes/steps that bat can change */
  /*  max indexes/steps that bat can change */
  /*  bat power demand if only EM is running */
  /*  struct w/ tst data state var params */
  /*  struct der Fahrzeugparameter - NUR SKALARS */
  /*  struct der Fahrzeugparameter - NUR ARRAYS */
  /*  */
  /*  01.07.2016 - asgard kaleb marroquin - creating new algorithm based solely  */
  /*  on DP for minimizing fuel use based on battery charge value with a given */
  /*  speed and slope profile wrt tim, not distance.  */
  /*  */
  /*  15.07.2016 - including E_bat as a state variable */
  /*  */
  /*  06.07.2016 - replacing KE state dimension with engine control */
  /*  Since engine control will be treated as a boolean 0-1 value, for indexing */
  /*  values with on-off possibilities, a value of 1 is added to the boolean */
  /*  value in order to create 'indexable numbers' (ie, 1 and 2 for off and on) */
  /*  */
  /*  Differences: */
  /*    - Kinetic energy is not a state/costate variable considered.  */
  /*    - The gear variable should be able to be toggled to be used */
  /*    (static,dynamic). */
  /*    - Algorithm here is wrt tim, not displacement (Time is not a state */
  /*    here). */
  /*    - B/c KE states (and possibly discrete gear states) are not considered,  */
  /*    DP is much more plausable for this algorithm. PMP will not be used for */
  /*    finding tim and battery energy costates. DP will be used to find  */
  /*    optimal battery energy and possibly gear states for optimal path. */
  /*  Similarities: */
  /*    - Want to find optimal battery electric energy path for given profile. */
  /*    - Optimal fuel minimization - engine on/off toggle from torque split. */
  /*  */
  /*  Algorithm: */
  /*    - Must be able to handle any length of tim/speed profile. */
  /*    - There is no energy loss penalty for turning engine on/off. */
  /*  */
  /* INIDP Calculating optimal predecessors with DP + PMP */
  /*  Erstellungsdatum der ersten Version 20.08.2015 - Stephan Uebel */
  /*  */
  /*  Diese Funktion berechnet die optimalen VorgÃ¤nger der Dynamischen */
  /*  Programmierung (DP). Diese subsitutiert die ZustÃ¤nde Zeit und */
  /*  Batterieenergie durch Co-States. Die Kosten werden mit dem */
  /*  Pontryaginschen Minimumsprinzip berechnet. */
  /*    This function calculates the optimum predecessor from dynamic */
  /*    programming (DP). Each state's tim and battery power costates are */
  /*    substituted from a Potryagin's Minimum Principle calculation. */
  /*  */
  /*  Variante olyHyb erlaubt nur hybridisches Fahren (Motor ist immer an) */
  /*    variation olyHyb permits only hybrid driving (motor is always on) */
  /*  */
  /*  Ã„nderung am 23.02.2016 - optimale Kosten nicht direkt aus Index von min() */
  /*  bestimmt. Das fÃ¤hrt zu einem anderen Schaltverhalten, da Gï¿½nge teilweise */
  /*  gleiche Kosten verursachen. In dem Fall wird jetzt der niedrigste Gang */
  /*  gewÃ¤hlt, wie in der DP. */
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
  /*  Mittelwerte, d.h. Flussgrößen wie KrÃ¤fte, Leistungen etc., stehen immmer */
  /*  am Anfang des Intervalls fÃ¼r das folgende Intervall. Diese */
  /*  Vektoren/Tensoren sind daher um einen gÃ¼ltigen Eintrag kÃ¼rzer. */
  /*    mean values (eg flow variables like forces, services) are always at the */
  /*    beginning of the interval for the next interval. Those vectors/tensors */
  /*    are therefore shorter by a valid entry (index?). */
  /*  */
  /* % Initialisieren der persistent Größen */
  /*  Diese werden die nur einmal für die Funktion berechnet */
  /*    assigning input structure values to function persistant variables */
  /*    - just once */
  /*  persistent geaNum vehMas vehAccMin vehAccMax iceFlg */
  if (!geaNum_not_empty) {
    /*      geaNum    = zeros(1,1); */
    /*      vehMas    = zeros(1,1); */
    /*      vehAccMin = zeros(1,1); */
    /*      vehAccMax = zeros(1,1); */
    /*  number of engine states possible (0 = OFF; 1 = ON); */
    engNum = tst_scalar_struct->engStaNum;
    engStaMin = tst_scalar_struct->engStaMin;
    engStaMax = tst_scalar_struct->engStaMax;

    /*  Anzahl der GÃ¤nge */
    /*    number of gears */
    geaNum = tst_scalar_struct->staNum;
    geaNum_not_empty = true;

    /*  max number of state nodes */
    geaStaMin = tst_scalar_struct->geaStaMin;
    geaStaMax = tst_scalar_struct->geaStaMax;

    /*  battery states */
    batStaMin = tst_scalar_struct->batEngMin;
    batStaStp = tst_scalar_struct->batEngStp;
    batStaMax = tst_scalar_struct->batEngMax;

    /*  need to add one so that the value 0 is included as well! */
    batNum = (batStaMax - batStaMin) / batStaStp + 1.0;

    /*  In dieser Version ist der Motor immer an */
    /*  not anymore - iceFlg is whatever is in mainConfig.txt */
    /*      iceFlg = true; */
    iceFlg = inputparams->iceFlgBool;
  }

  /*  maximale Drehzahl Elektrommotor */
  /*    maximum electric motor rotational speed */
  crsSpdEmoMax = fzg_array_struct->emoSpdMgd[72];

  /*  maximale Drehzahl der Kurbelwelle */
  /*    maximum crankshaft rotational speed */
  /*  12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY */
  /*  ARE WE SELECTING THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE */
  /*  EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER? */
  crsSpdHybMax = muDoubleScalarMin(fzg_array_struct->iceSpdMgd[34],
    fzg_array_struct->emoSpdMgd[72]);

  /*  minimale Drehzahl der Kurbelwelle */
  /*    minimum crankshaft rotational speed */
  crsSpdHybMin = fzg_array_struct->iceSpdMgd[0];

  /* % Initialisieren der Ausgabe der Funktion */
  /*    initialzing function output */
  /*  Tensor 3. Stufe fï¿½r optimalen VorgÃ¤ngerkoordinaten */
  /*    tensor3 for optimal previous coordinates/idx */
  /*  IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION */
  /*    - back to being a tensor - adding engine control dimension */
  i0 = optPreInxTn4->size[0] * optPreInxTn4->size[1] * optPreInxTn4->size[2] *
    optPreInxTn4->size[3];
  absa = emlrtNonNegativeCheckFastR2012b(engNum, &u_emlrtDCI, sp);
  optPreInxTn4->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(absa, &t_emlrtDCI,
    sp);
  absa = emlrtNonNegativeCheckFastR2012b(geaNum, &w_emlrtDCI, sp);
  optPreInxTn4->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(absa, &v_emlrtDCI,
    sp);
  absa = emlrtNonNegativeCheckFastR2012b(batNum, &y_emlrtDCI, sp);
  optPreInxTn4->size[2] = (int32_T)emlrtIntegerCheckFastR2012b(absa, &x_emlrtDCI,
    sp);
  absa = emlrtNonNegativeCheckFastR2012b(timNum, &bb_emlrtDCI, sp);
  optPreInxTn4->size[3] = (int32_T)emlrtIntegerCheckFastR2012b(absa,
    &ab_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)optPreInxTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  absa = emlrtNonNegativeCheckFastR2012b(engNum, &u_emlrtDCI, sp);
  batEngInxBeg = emlrtNonNegativeCheckFastR2012b(geaNum, &w_emlrtDCI, sp);
  batStaPreIdx_noEmo = emlrtNonNegativeCheckFastR2012b(batNum, &y_emlrtDCI, sp);
  batStaLimMax = emlrtNonNegativeCheckFastR2012b(timNum, &bb_emlrtDCI, sp);
  iy = (int32_T)emlrtIntegerCheckFastR2012b(absa, &t_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batEngInxBeg, &v_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batStaPreIdx_noEmo, &x_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batStaLimMax, &ab_emlrtDCI, sp);
  for (i0 = 0; i0 < iy; i0++) {
    optPreInxTn4->data[i0] = 0.0;
  }

  /*  Tensor 3. Stufe fï¿½r die Kraftstoffenergie */
  /*    tensor3 for fuel energy - now Tn4 */
  i0 = fulEngOptTn4->size[0] * fulEngOptTn4->size[1] * fulEngOptTn4->size[2] *
    fulEngOptTn4->size[3];
  fulEngOptTn4->size[0] = (int32_T)engNum;
  fulEngOptTn4->size[1] = (int32_T)geaNum;
  fulEngOptTn4->size[2] = (int32_T)batNum;
  fulEngOptTn4->size[3] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngOptTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < iy; i0++) {
    fulEngOptTn4->data[i0] = rtInf;
  }

  /*  tensors for saving optimal torque values */
  i0 = emoTrqOptTn4->size[0] * emoTrqOptTn4->size[1] * emoTrqOptTn4->size[2] *
    emoTrqOptTn4->size[3];
  emoTrqOptTn4->size[0] = (int32_T)engNum;
  emoTrqOptTn4->size[1] = (int32_T)geaNum;
  emoTrqOptTn4->size[2] = (int32_T)batNum;
  emoTrqOptTn4->size[3] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)emoTrqOptTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < iy; i0++) {
    emoTrqOptTn4->data[i0] = rtInf;
  }

  i0 = iceTrqOptTn4->size[0] * iceTrqOptTn4->size[1] * iceTrqOptTn4->size[2] *
    iceTrqOptTn4->size[3];
  iceTrqOptTn4->size[0] = (int32_T)engNum;
  iceTrqOptTn4->size[1] = (int32_T)geaNum;
  iceTrqOptTn4->size[2] = (int32_T)batNum;
  iceTrqOptTn4->size[3] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)iceTrqOptTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < iy; i0++) {
    iceTrqOptTn4->data[i0] = rtInf;
  }

  i0 = brkTrqOptTn4->size[0] * brkTrqOptTn4->size[1] * brkTrqOptTn4->size[2] *
    brkTrqOptTn4->size[3];
  brkTrqOptTn4->size[0] = (int32_T)engNum;
  brkTrqOptTn4->size[1] = (int32_T)geaNum;
  brkTrqOptTn4->size[2] = (int32_T)batNum;
  brkTrqOptTn4->size[3] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)brkTrqOptTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < iy; i0++) {
    brkTrqOptTn4->data[i0] = rtInf;
  }

  /*    set initial fuel energy level to 0 */
  /*    Note: batEngIdxBeg is a scaled down energy value index, NOT a vector */
  /*    index. Keep this in mind later when manipulating batEng index bounds. */
  batEngInxBeg = batEngBeg / batStaStp;
  i0 = (int32_T)timNum;
  absa = inputparams->timInxBeg;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &emlrtDCI, sp);
  i2 = (int32_T)batNum;
  i3 = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &b_emlrtDCI, sp);
  cindx = (int32_T)geaNum;
  absa = inputparams->staBeg;
  ix = (int32_T)emlrtIntegerCheckFastR2012b(absa, &c_emlrtDCI, sp);
  i = (int32_T)engNum;
  absa = inputparams->engBeg + 1.0;
  npages = (int32_T)emlrtIntegerCheckFastR2012b(absa, &d_emlrtDCI, sp);
  fulEngOptTn4->data[(((emlrtDynamicBoundsCheckFastR2012b(npages, 1, i,
    &h_emlrtBCI, sp) + fulEngOptTn4->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(ix, 1, cindx,
    &g_emlrtBCI, sp) - 1)) + fulEngOptTn4->size[0] * fulEngOptTn4->size[1] *
                       (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &f_emlrtBCI,
    sp) - 1)) + fulEngOptTn4->size[0] * fulEngOptTn4->size[1] *
                      fulEngOptTn4->size[2] * (emlrtDynamicBoundsCheckFastR2012b
                       (i1, 1, i0, &e_emlrtBCI, sp) - 1)) - 1] = 0.0;

  /*  Tensor 3. Stufe fï¿½r die Batterienergie */
  /*    tensor3 for battery energy - now Tn4 */
  i0 = batPwrOptTn4->size[0] * batPwrOptTn4->size[1] * batPwrOptTn4->size[2] *
    batPwrOptTn4->size[3];
  batPwrOptTn4->size[0] = (int32_T)engNum;
  batPwrOptTn4->size[1] = (int32_T)geaNum;
  batPwrOptTn4->size[2] = (int32_T)batNum;
  batPwrOptTn4->size[3] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)batPwrOptTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < iy; i0++) {
    batPwrOptTn4->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &cos2goPreTn3, 3, &d_emlrtRTEI, true);

  /* % Berechnung der optimalen Vorgäger */
  /*    calculating the optimal predecessors */
  /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten */
  /*  Wegschritt */
  /*    initialize the matrix for the cost to the points in the last wayidx */
  /*  NOW A VECTOR - REMOVED KE DIMENSION */
  /*  not anymore - added engine contorl dimension */
  i0 = cos2goPreTn3->size[0] * cos2goPreTn3->size[1] * cos2goPreTn3->size[2];
  cos2goPreTn3->size[0] = (int32_T)engNum;
  cos2goPreTn3->size[1] = (int32_T)geaNum;
  cos2goPreTn3->size[2] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goPreTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
  for (i0 = 0; i0 < iy; i0++) {
    cos2goPreTn3->data[i0] = rtInf;
  }

  i0 = cos2goActTn3->size[0] * cos2goActTn3->size[1] * cos2goActTn3->size[2];
  cos2goActTn3->size[0] = (int32_T)engNum;
  cos2goActTn3->size[1] = (int32_T)geaNum;
  cos2goActTn3->size[2] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goActTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
  for (i0 = 0; i0 < iy; i0++) {
    cos2goActTn3->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &fulEngPreTn3, 3, &e_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit 0 für alle Zustände (concluded) */
  /*    first, initialize the startidx to 0 for all states */
  i0 = (int32_T)batNum;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &l_emlrtDCI, sp);
  i2 = (int32_T)geaNum;
  absa = inputparams->staBeg;
  i3 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &m_emlrtDCI, sp);
  cindx = (int32_T)engNum;
  absa = inputparams->engBeg + 1.0;
  ix = (int32_T)emlrtIntegerCheckFastR2012b(absa, &n_emlrtDCI, sp);
  cos2goPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b(ix, 1, cindx,
    &ab_emlrtBCI, sp) + cos2goPreTn3->size[0] *
                       (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &y_emlrtBCI,
    sp) - 1)) + cos2goPreTn3->size[0] * cos2goPreTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &x_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  Initialisierung der Matrix der Batterieenergien */
  /*    initialize the battery energy matrix */
  /*  batEngPreTn3 = inf(engNum, geaNum, batNum); */
  /*  Erste Initilisierung beim Startindex mit Startladung für den Startzustand */
  /*    first, intialize start index of the starting charge for intial state */
  /*  batEngPreTn3(engBeg+1, staBeg, batEngIdxBeg) = batEngBeg; */
  /*  Initialisierung der Matrix der Kraftstoffenergien */
  /*    initialze the fuel energy matrix */
  i0 = fulEngPreTn3->size[0] * fulEngPreTn3->size[1] * fulEngPreTn3->size[2];
  fulEngPreTn3->size[0] = (int32_T)engNum;
  fulEngPreTn3->size[1] = (int32_T)geaNum;
  fulEngPreTn3->size[2] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngPreTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
  for (i0 = 0; i0 < iy; i0++) {
    fulEngPreTn3->data[i0] = rtInf;
  }

  /*  Erste Initilisierung beim Startindex mit 0 fï¿½r den Startzustand */
  /*    first, intialize the start idx for the intitial states to 0 */
  i0 = (int32_T)batNum;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &g_emlrtDCI, sp);
  i2 = (int32_T)geaNum;
  absa = inputparams->staBeg;
  i3 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &h_emlrtDCI, sp);
  cindx = (int32_T)engNum;
  absa = inputparams->engBeg + 1.0;
  ix = (int32_T)emlrtIntegerCheckFastR2012b(absa, &i_emlrtDCI, sp);
  fulEngPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b(ix, 1, cindx,
    &q_emlrtBCI, sp) + fulEngPreTn3->size[0] *
                       (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &p_emlrtBCI,
    sp) - 1)) + fulEngPreTn3->size[0] * fulEngPreTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &o_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  define a vector for containing the values of engine control off-on */
  /*  engStaMat_geaNum_timInx = zeros(1, timInxEnd); */
  /*  define battery vector to be used for looping */
  batEngInxBeg = batStaMin / batStaStp;
  batStaPreIdx_noEmo = batStaMax / batStaStp;
  st.site = &emlrtRSI;
  b_st.site = &n_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  if (muDoubleScalarIsNaN(batEngInxBeg) || muDoubleScalarIsNaN
      (batStaPreIdx_noEmo)) {
    n = 0;
    geaStaPre = rtNaN;
    apnd = batStaPreIdx_noEmo;
    overflow = false;
  } else if (batStaPreIdx_noEmo < batEngInxBeg) {
    n = -1;
    geaStaPre = batEngInxBeg;
    apnd = batStaPreIdx_noEmo;
    overflow = false;
  } else if (muDoubleScalarIsInf(batEngInxBeg) || muDoubleScalarIsInf
             (batStaPreIdx_noEmo)) {
    n = 0;
    geaStaPre = rtNaN;
    apnd = batStaPreIdx_noEmo;
    overflow = !(batEngInxBeg == batStaPreIdx_noEmo);
  } else {
    geaStaPre = batEngInxBeg;
    ndbl = muDoubleScalarFloor((batStaPreIdx_noEmo - batEngInxBeg) + 0.5);
    apnd = batEngInxBeg + ndbl;
    cdiff = apnd - batStaPreIdx_noEmo;
    absa = muDoubleScalarAbs(batEngInxBeg);
    absb = muDoubleScalarAbs(batStaPreIdx_noEmo);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
      apnd = batStaPreIdx_noEmo;
    } else if (cdiff > 0.0) {
      apnd = batEngInxBeg + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl - 1;
    } else {
      n = -1;
    }
  }

  d_st.site = &p_emlrtRSI;
  if (!overflow) {
  } else {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i = 0; i < 21; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
    emlrtAssign(&y, m0);
    e_st.site = &tb_emlrtRSI;
    f_st.site = &yb_emlrtRSI;
    error(&e_st, message(&f_st, y, &emlrtMCI), &b_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &batStaActInxVec, 2, &f_emlrtRTEI, true);
  i0 = batStaActInxVec->size[0] * batStaActInxVec->size[1];
  batStaActInxVec->size[0] = 1;
  batStaActInxVec->size[1] = n + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)batStaActInxVec, i0, (int32_T)
                    sizeof(real_T), &b_emlrtRTEI);
  if (n + 1 > 0) {
    batStaActInxVec->data[0] = geaStaPre;
    if (n + 1 > 1) {
      batStaActInxVec->data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        nm1d2 = (int32_T)((uint32_T)i0 >> 1);
      } else {
        nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
      }

      d_st.site = &q_emlrtRSI;
      for (iy = 1; iy < nm1d2; iy++) {
        batStaActInxVec->data[iy] = geaStaPre + (real_T)iy;
        batStaActInxVec->data[n - iy] = apnd - (real_T)iy;
      }

      if (nm1d2 << 1 == n) {
        batStaActInxVec->data[nm1d2] = (geaStaPre + apnd) / 2.0;
      } else {
        batStaActInxVec->data[nm1d2] = geaStaPre + (real_T)nm1d2;
        batStaActInxVec->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  /*  assign the starting batEng for controlling future batEngActs */
  /*  Schleife über alle Wegpunkte */
  /*    looping thorugh length of # of discretized tim vector */
  i0 = (int32_T)((inputparams->timInxEnd + (inputparams->timStp -
    (inputparams->timInxBeg + 1.0))) / inputparams->timStp);
  emlrtForLoopVectorCheckR2012b(inputparams->timInxBeg + 1.0,
    inputparams->timStp, inputparams->timInxEnd, mxDOUBLE_CLASS, i0,
    &u_emlrtRTEI, sp);
  timInx = 0;
  emxInit_real_T(sp, &batPwrOptTn3, 3, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &batEngActTn3, 3, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngActTn3, 3, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &emoTrqActTn3, 3, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &iceTrqActTn3, 3, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &brkTrqActTn3, 3, &l_emlrtRTEI, true);
  emxInit_real_T(sp, &fulActTn3, 3, &m_emlrtRTEI, true);
  emxInit_real_T(sp, &emoTrqPreTn3, 3, &n_emlrtRTEI, true);
  emxInit_real_T(sp, &iceTrqPreTn3, 3, &o_emlrtRTEI, true);
  emxInit_real_T(sp, &brkTrqPreTn3, 3, &p_emlrtRTEI, true);
  b_emxInit_real_T(sp, &batStaPreIdxVec, 2, &q_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 1, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_y, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &indx, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &extremum, 3, &emlrtRTEI, true);
  b_emxInit_int32_T(sp, &iindx, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_indx, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_extremum, 3, &emlrtRTEI, true);
  b_emxInit_int32_T(sp, &b_iindx, 3, &emlrtRTEI, true);
  while (timInx <= i0 - 1) {
    b_timInx = (inputparams->timInxBeg + 1.0) + (real_T)timInx *
      inputparams->timStp;

    /*  TIME IDX LOOP */
    /*     %% Berechnung der kinetischen Energien im aktuellen Wegschritt */
    /*  Vorbereitung der FZGallen Schleife (verhindern von zu grossem */
    /*  Datentransfer und unnï¿½tigen Berechnungen) */
    /*    Calculating the KE for current index/waypoint. */
    /*    Preperation of FZGallel loop (prevent a too large data transfer, */
    /*    unnecessary computations).    */
    /*  Initialisieren der Matrix fÃ¼r die optimalen Batteriekrafter im */
    /*  Intervall */
    /*    initialize matrix for optimale battery force intervals (discreti.) */
    /*  NOW A VECTOR - REMOVED KE STATE */
    /*  - 06.06.2016 - back to matrix, added engine state dimension */
    i1 = batPwrOptTn3->size[0] * batPwrOptTn3->size[1] * batPwrOptTn3->size[2];
    batPwrOptTn3->size[0] = (int32_T)engNum;
    batPwrOptTn3->size[1] = (int32_T)geaNum;
    batPwrOptTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)batPwrOptTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      batPwrOptTn3->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fï¿½r die Kosten bis zu den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize cost matrix to points in current path steps (idxs?) */
    i1 = cos2goActTn3->size[0] * cos2goActTn3->size[1] * cos2goActTn3->size[2];
    cos2goActTn3->size[0] = (int32_T)engNum;
    cos2goActTn3->size[1] = (int32_T)geaNum;
    cos2goActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)cos2goActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      cos2goActTn3->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fÃ¼r die Batterieenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for battery energy at points along current wayidx */
    i1 = batEngActTn3->size[0] * batEngActTn3->size[1] * batEngActTn3->size[2];
    batEngActTn3->size[0] = (int32_T)engNum;
    batEngActTn3->size[1] = (int32_T)geaNum;
    batEngActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)batEngActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      batEngActTn3->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fÃ¼r die Krafstoffenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for fuel energie along current way idxs */
    i1 = fulEngActTn3->size[0] * fulEngActTn3->size[1] * fulEngActTn3->size[2];
    fulEngActTn3->size[0] = (int32_T)engNum;
    fulEngActTn3->size[1] = (int32_T)geaNum;
    fulEngActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)fulEngActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      fulEngActTn3->data[i1] = rtInf;
    }

    /*  intiialiying matrices for saving torques for each state permutation */
    /*  for the given time interval */
    i1 = emoTrqActTn3->size[0] * emoTrqActTn3->size[1] * emoTrqActTn3->size[2];
    emoTrqActTn3->size[0] = (int32_T)engNum;
    emoTrqActTn3->size[1] = (int32_T)geaNum;
    emoTrqActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)emoTrqActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      emoTrqActTn3->data[i1] = 0.0;
    }

    i1 = iceTrqActTn3->size[0] * iceTrqActTn3->size[1] * iceTrqActTn3->size[2];
    iceTrqActTn3->size[0] = (int32_T)engNum;
    iceTrqActTn3->size[1] = (int32_T)geaNum;
    iceTrqActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)iceTrqActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      iceTrqActTn3->data[i1] = 0.0;
    }

    i1 = brkTrqActTn3->size[0] * brkTrqActTn3->size[1] * brkTrqActTn3->size[2];
    brkTrqActTn3->size[0] = (int32_T)engNum;
    brkTrqActTn3->size[1] = (int32_T)geaNum;
    brkTrqActTn3->size[2] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)brkTrqActTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
    for (i1 = 0; i1 < iy; i1++) {
      brkTrqActTn3->data[i1] = 0.0;
    }

    /*  possible engine state changes for current and past path_idxs */
    absa = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &s_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &ub_emlrtBCI, sp);

    /*  and the previous idx KE */
    /*      engStaNumAct = engStaVec_timInx(timInx);   % look at this loop's KE */
    /*  create vector storing current and previous velocity info */
    /*  check later if you can remove this */
    absa = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &cb_emlrtDCI, sp);
    vehVelVec[0] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &vb_emlrtBCI, sp) - 1];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_timInx, &db_emlrtDCI, sp);
    vehVelVec[1] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &wb_emlrtBCI, sp) - 1];

    /*  save current and previous crankshaft speed vectors for boundary */
    /*  checks when looping through gear states */
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &tb_emlrtBCI, sp);

    /*     %% PRE->ACT engBat CONTROL */
    /*  INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!! */
    /*  battery power max/min boundaries wrt max/min emo power */
    /*  boundaries as a function of crankshaft speed */
    /*      batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp; */
    /*      batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp; */
    st.site = &b_emlrtRSI;
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &sb_emlrtBCI, &st);
    b_st.site = &s_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    b_ix = 693;
    for (i = 0; i < 6; i++) {
      d_st.site = &u_emlrtRSI;
      nm1d2 = b_ix - 692;
      if (muDoubleScalarIsNaN(batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
             ((b_ix - 693) % 693)) + 818433 * div_nzp_s32_floor(b_ix - 693, 693))
           - 2])) {
        e_st.site = &w_emlrtRSI;
        if (b_ix - 691 > b_ix) {
          c_ix = false;
        } else {
          c_ix = (b_ix > 2147483646);
        }

        if (c_ix) {
          h_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        ix = b_ix - 691;
        exitg5 = false;
        while ((!exitg5) && (ix <= b_ix)) {
          nm1d2 = ix;
          if (!muDoubleScalarIsNaN(batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
                 ((ix - 1) % 693)) + 818433 * div_nzp_s32_floor(ix - 1, 693)) -
               2])) {
            exitg5 = true;
          } else {
            ix++;
          }
        }
      }

      if (nm1d2 < b_ix) {
        e_st.site = &v_emlrtRSI;
        if (nm1d2 + 1 > b_ix) {
          b_nm1d2 = false;
        } else {
          b_nm1d2 = (b_ix > 2147483646);
        }

        if (b_nm1d2) {
          h_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
      }

      b_ix += 693;
    }

    st.site = &c_emlrtRSI;
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &rb_emlrtBCI, &st);
    b_st.site = &x_emlrtRSI;
    c_st.site = &t_emlrtRSI;
    b_ix = 693;
    for (i = 0; i < 6; i++) {
      d_st.site = &u_emlrtRSI;
      nm1d2 = b_ix - 692;
      if (muDoubleScalarIsNaN(batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
             ((b_ix - 693) % 693)) + 818433 * div_nzp_s32_floor(b_ix - 693, 693))
           - 2])) {
        e_st.site = &w_emlrtRSI;
        if (b_ix - 691 > b_ix) {
          d_ix = false;
        } else {
          d_ix = (b_ix > 2147483646);
        }

        if (d_ix) {
          h_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        ix = b_ix - 691;
        exitg4 = false;
        while ((!exitg4) && (ix <= b_ix)) {
          nm1d2 = ix;
          if (!muDoubleScalarIsNaN(batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
                 ((ix - 1) % 693)) + 818433 * div_nzp_s32_floor(ix - 1, 693)) -
               2])) {
            exitg4 = true;
          } else {
            ix++;
          }
        }
      }

      if (nm1d2 < b_ix) {
        e_st.site = &v_emlrtRSI;
        if (nm1d2 + 1 > b_ix) {
          c_nm1d2 = false;
        } else {
          c_nm1d2 = (b_ix > 2147483646);
        }

        if (c_nm1d2) {
          h_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
      }

      b_ix += 693;
    }

    /*  battery power limits given by max/min battery power */
    /*  discharge (a given model input value) */
    /*      %   ie change in E cannot exceed bat power levels (P=E'/t') */
    /*      % find the most constraining change in batEng based on */
    /*      % previous limitations */
    /*  MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY */
    /*  STATE, NOT FROM SCRATCH!!! */
    /*  make vector of these batEng state steps for a loop */
    /*      batStaLimVec = batStaLimBot : batStaLimTop; */
    /* % ----- CURRENT STATE VARIBALE LOOP -------------------------------------- */
    /*   go through the possible engine state on-off possibilities */
    /*    checking if the engine can be off or on for this index */
    b_engStaMin = engStaMin;
    i1 = (int32_T)(engStaMax + (1.0 - engStaMin));
    emlrtForLoopVectorCheckR2012b(engStaMin, 1.0, engStaMax, mxDOUBLE_CLASS, i1,
      &t_emlrtRTEI, sp);
    engStaAct = 0;
    while (engStaAct <= i1 - 1) {
      b_engStaAct = b_engStaMin + (real_T)engStaAct;

      /*  CURRENT ENGINE STATE LOOP                 */
      /*  Schleife über alle moglichen aktuellen Zustände des Antriesstrangs */
      /*    Loop over all possible current powertrain states/all the gears */
      b_geaStaMin = geaStaMin;
      i2 = (int32_T)(geaStaMax + (1.0 - geaStaMin));
      emlrtForLoopVectorCheckR2012b(geaStaMin, 1.0, geaStaMax, mxDOUBLE_CLASS,
        i2, &s_emlrtRTEI, sp);
      geaStaAct = 0;
      while (geaStaAct <= i2 - 1) {
        b_geaStaAct = b_geaStaMin + (real_T)geaStaAct;

        /*  ALL GEARS LOOP */
        /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS --------------------------------- */
        /*  boundaries: since crsSpd is dependent on gear, check is performed */
        /*  within the gear state loop */
        /*  IF ENGINE IS ON: */
        guard1 = false;
        if (b_engStaAct != 0.0) {
          /*  Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen */
          /*  Modus */
          /*    stop if the crankshaft rotational speed is too high in hybrid mode */
          i3 = (int32_T)emlrtIntegerCheckFastR2012b(b_geaStaAct, &r_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &qb_emlrtBCI, sp);
          if ((crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)b_geaStaAct - 1))
               - 1] > crsSpdHybMax) || (crsSpdMat[((int32_T)b_timInx + 1181 *
                ((int32_T)b_geaStaAct - 1)) - 1] < crsSpdHybMin)) {
          } else {
            /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
            /*  Leerlaufdrehzahl ist, */
            /*    stop if crankhaft rotional speed is lower than the idling speed */
            /*  IF ENGINE IS OFF */
            guard1 = true;
          }
        } else {
          /*  Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
          /*    check if electric motor speed limit is maintained */
          i3 = (int32_T)emlrtIntegerCheckFastR2012b(b_geaStaAct, &q_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &pb_emlrtBCI, sp);
          if (crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)b_geaStaAct - 1))
              - 1] > crsSpdEmoMax) {
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          /*  ------------------------------------------------------------------------- */
          /*  loop over all possible current battery values */
          /*  05.05.2016 - instead of brute forcing all the current battery */
          /*  states, will try to limit boundaries based on possible */
          /*  predecessor battery levels instead */
          /*              for batStaActInx_counter = 1 : length(batStaLimVec) */
          batStaActInx = 0;
          while (batStaActInx <= batStaActInxVec->size[1] - 1) {
            /*                 %% Initialisieren */
            /*    note-you are preallocating over each state permutation */
            /*  convert batStaActInx back into actual batEng */
            i3 = batStaActInxVec->size[1];
            cindx = 1 + batStaActInx;
            batStaAct = batStaActInxVec->data[emlrtDynamicBoundsCheckFastR2012b
              (cindx, 1, i3, &xb_emlrtBCI, sp) - 1] * batStaStp;

            /*                  batStaActInx = batStaLimVec(batStaActInx_counter); */
            /*                  batStaAct   = batStaActInx * batStaStp; */
            /*  memoization variable for storing möglich fuel values */
            /*                  fulActTn3 = inf(length(batStaPreIdxVec), length(geaStaPreMin:geaStaPreMax), engNum); */
            i3 = fulActTn3->size[0] * fulActTn3->size[1] * fulActTn3->size[2];
            fulActTn3->size[0] = (int32_T)engNum;
            fulActTn3->size[1] = (int32_T)geaNum;
            fulActTn3->size[2] = (int32_T)batNum;
            emxEnsureCapacity(sp, (emxArray__common *)fulActTn3, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
            for (i3 = 0; i3 < iy; i3++) {
              fulActTn3->data[i3] = rtInf;
            }

            /*  memoiztaion variables for output torques */
            i3 = emoTrqPreTn3->size[0] * emoTrqPreTn3->size[1] *
              emoTrqPreTn3->size[2];
            emoTrqPreTn3->size[0] = (int32_T)engNum;
            emoTrqPreTn3->size[1] = (int32_T)geaNum;
            emoTrqPreTn3->size[2] = (int32_T)batNum;
            emxEnsureCapacity(sp, (emxArray__common *)emoTrqPreTn3, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
            for (i3 = 0; i3 < iy; i3++) {
              emoTrqPreTn3->data[i3] = 0.0;
            }

            i3 = iceTrqPreTn3->size[0] * iceTrqPreTn3->size[1] *
              iceTrqPreTn3->size[2];
            iceTrqPreTn3->size[0] = (int32_T)engNum;
            iceTrqPreTn3->size[1] = (int32_T)geaNum;
            iceTrqPreTn3->size[2] = (int32_T)batNum;
            emxEnsureCapacity(sp, (emxArray__common *)iceTrqPreTn3, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
            for (i3 = 0; i3 < iy; i3++) {
              iceTrqPreTn3->data[i3] = 0.0;
            }

            i3 = brkTrqPreTn3->size[0] * brkTrqPreTn3->size[1] *
              brkTrqPreTn3->size[2];
            brkTrqPreTn3->size[0] = (int32_T)engNum;
            brkTrqPreTn3->size[1] = (int32_T)geaNum;
            brkTrqPreTn3->size[2] = (int32_T)batNum;
            emxEnsureCapacity(sp, (emxArray__common *)brkTrqPreTn3, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = (int32_T)engNum * (int32_T)geaNum * (int32_T)batNum;
            for (i3 = 0; i3 < iy; i3++) {
              brkTrqPreTn3->data[i3] = 0.0;
            }

            /*  ----- DEFINING PREDECESSOR STATE VARIABLE LIMITATIONS ------------------ */
            /*                 %% defining previous engine state control w/ iceFlg */
            /*  if the engine state can toggle: one of two options */
            if (!(iceFlg != 0.0)) {
              if (engStaVec_timInx[(int32_T)b_timInx - 2] == 1.0) {
                /*  only one change possible-default switch to low val ie off */
                engStaPreIdx_size_idx_1 = 1;
                engStaPreIdx_data[0] = engStaMin;
              } else {
                /*  otherwise, either off or on are options - loop through */
                dv0[0] = engStaMin;
                dv0[1] = engStaMax;
                engStaPreIdx_size_idx_1 = 2;
                for (i3 = 0; i3 < 2; i3++) {
                  engStaPreIdx_data[i3] = dv0[i3];
                }
              }
            } else {
              /*  if the motor must always be on - loop only through same state */
              engStaPreIdx_size_idx_1 = 1;
              engStaPreIdx_data[0] = b_engStaAct;
            }

            /*                 %% Vorgängerzustände beschränken */
            /*    Restrictions on predecessor operation states */
            /*  Festlegen, welche Vorgänger möglich sind: */
            /*  Es sind im Maximum die Anzahl der Gänge +  1 als VorgÃ¤nger */
            /*  möglich, denn vom Segeln kann in jeden Gang im elektrischen */
            /*  Fahren und Segeln gewechselt werden */
            /*    Determine which predecessors are possible: */
            /*    There are at maximum 'number of gears'+1 possible for the */
            /*    predecessors, because from the sail in every Gear in */
            /*    electric travel and the sails will be changed (???) */
            /*  Vorgï¿½ngerzustï¿½nde des Antriebsstrangs beschrÃ¤nken */
            /*    determine gear possibilities - ie u(g)  */
            b_ix = (int32_T)muDoubleScalarMax(1.0, b_geaStaAct - 1.0);
            batEngInxBeg = muDoubleScalarMin(geaNum, b_geaStaAct + 1.0);
            st.site = &d_emlrtRSI;
            b_st.site = &n_emlrtRSI;
            c_st.site = &o_emlrtRSI;
            if (muDoubleScalarIsNaN(batEngInxBeg)) {
              n = 0;
              geaStaPre = rtNaN;
              apnd = batEngInxBeg;
              overflow = false;
            } else if (batEngInxBeg < b_ix) {
              n = -1;
              geaStaPre = b_ix;
              apnd = batEngInxBeg;
              overflow = false;
            } else if (muDoubleScalarIsInf(batEngInxBeg)) {
              n = 0;
              geaStaPre = rtNaN;
              apnd = batEngInxBeg;
              overflow = !(b_ix == batEngInxBeg);
            } else {
              geaStaPre = b_ix;
              ndbl = muDoubleScalarFloor((batEngInxBeg - (real_T)b_ix) + 0.5);
              apnd = (real_T)b_ix + ndbl;
              cdiff = apnd - batEngInxBeg;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                  muDoubleScalarMax(b_ix, batEngInxBeg)) {
                ndbl++;
                apnd = batEngInxBeg;
              } else if (cdiff > 0.0) {
                apnd = (real_T)b_ix + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              overflow = false;
              if (ndbl >= 0.0) {
                n = (int32_T)ndbl - 1;
              } else {
                n = -1;
              }
            }

            d_st.site = &p_emlrtRSI;
            if (!overflow) {
            } else {
              c_y = NULL;
              m0 = emlrtCreateCharArray(2, iv1);
              for (i = 0; i < 21; i++) {
                cv0[i] = cv1[i];
              }

              emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
              emlrtAssign(&c_y, m0);
              e_st.site = &tb_emlrtRSI;
              f_st.site = &yb_emlrtRSI;
              error(&e_st, message(&f_st, c_y, &emlrtMCI), &b_emlrtMCI);
            }

            i3 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = n + 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)b_y, i3, (int32_T)
                              sizeof(real_T), &b_emlrtRTEI);
            if (n + 1 > 0) {
              b_y->data[0] = geaStaPre;
              if (n + 1 > 1) {
                b_y->data[n] = apnd;
                i3 = n + (n < 0);
                if (i3 >= 0) {
                  nm1d2 = (int32_T)((uint32_T)i3 >> 1);
                } else {
                  nm1d2 = (int32_T)~(~(uint32_T)i3 >> 1);
                }

                d_st.site = &q_emlrtRSI;
                for (iy = 1; iy < nm1d2; iy++) {
                  b_y->data[iy] = geaStaPre + (real_T)iy;
                  b_y->data[n - iy] = apnd - (real_T)iy;
                }

                if (nm1d2 << 1 == n) {
                  b_y->data[nm1d2] = (geaStaPre + apnd) / 2.0;
                } else {
                  b_y->data[nm1d2] = geaStaPre + (real_T)nm1d2;
                  b_y->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
                }
              }
            }

            /*                 %% restricting predecessor bat level possibilities */
            /*  NOTE: WORKING WITH INDEXES HERE, NOT ENERGY VALUES */
            /*  */
            /*  BUT: */
            /*  do we want to work with the direct scaled down energy */
            /*  value indexes, or with the actual vector position */
            /*  indexes? */
            /*  If working with the direct scaled indexes, we will be */
            /*  getting zeros which makes referencing values later from  */
            /*  vectors impossible. */
            /*    -b/c an energy value of 0 will yield a scaled down */
            /*    value of 0 (-> 0/batEngStp = 0).  */
            /*  This does not allow for referencing values later from */
            /*  other vectors (like battery OCV). */
            /*  */
            /*  Solution: just add one to the scaled down battery value */
            /*  index? Using batStaActInx may also work, but not sure if */
            /*  there would be unintended consequences. */
            /*  */
            /*  INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!! */
            /*  battery power max/min boundaries wrt max/min emo power */
            /*  boundaries as a function of crankshaft speed */
            i3 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &ob_emlrtBCI, sp);
            i3 = batStaActInx + 1;
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 693, &nb_emlrtBCI, sp);
            i3 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &mb_emlrtBCI, sp);

            /*  battery power limits given by max/min battery power */
            /*  discharge (a given model input value) */
            /*    ie change in E cannot exceed bat power levels (P=E'/t') */
            /*  find the most constraining change in batEng based on */
            /*  previous limitations */
            /*  MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY */
            /*  STATE, NOT FROM SCRATCH!!! */
            /*  make vector of these batEng state steps for a loop */
            batEngInxBeg = muDoubleScalarMax(batStaMin / batStaStp + 1.0,
              muDoubleScalarMax((1.0 + (real_T)batStaActInx) +
                                fzg_scalar_struct->batPwrMin *
                                inputparams->timStp / batStaStp, (1.0 + (real_T)
              batStaActInx) + batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
              batStaActInx) + 818433 * ((int32_T)b_geaStaAct - 1)) - 2] *
                                inputparams->timStp));
            batStaLimMax = muDoubleScalarMin(batStaMax / batStaStp + 1.0,
              muDoubleScalarMin((1.0 + (real_T)batStaActInx) +
                                fzg_scalar_struct->batPwrMax *
                                inputparams->timStp / batStaStp, (1.0 + (real_T)
              batStaActInx) + batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
              batStaActInx) + 818433 * ((int32_T)b_geaStaAct - 1)) - 2] *
                                inputparams->timStp));

            /*  if the min limit exceeds the max limit, then set them */
            /*  equal. */
            if (batEngInxBeg > batStaLimMax) {
              batEngInxBeg = batStaLimMax;
            }

            /*  make alocal min and max for saving for a future total */
            /*  min-max vector */
            /*  Min-max - bounds for the current batEngPre */
            /*  Bot-top - local bounds for current batEngAct */
            st.site = &e_emlrtRSI;
            b_st.site = &n_emlrtRSI;
            c_st.site = &o_emlrtRSI;
            if (muDoubleScalarIsNaN(batEngInxBeg) || muDoubleScalarIsNaN
                (batStaLimMax)) {
              n = 0;
              geaStaPre = rtNaN;
              apnd = batStaLimMax;
              overflow = false;
            } else if (batStaLimMax < batEngInxBeg) {
              n = -1;
              geaStaPre = batEngInxBeg;
              apnd = batStaLimMax;
              overflow = false;
            } else if (muDoubleScalarIsInf(batEngInxBeg) || muDoubleScalarIsInf
                       (batStaLimMax)) {
              n = 0;
              geaStaPre = rtNaN;
              apnd = batStaLimMax;
              overflow = !(batEngInxBeg == batStaLimMax);
            } else {
              geaStaPre = batEngInxBeg;
              ndbl = muDoubleScalarFloor((batStaLimMax - batEngInxBeg) + 0.5);
              apnd = batEngInxBeg + ndbl;
              cdiff = apnd - batStaLimMax;
              absa = muDoubleScalarAbs(batEngInxBeg);
              absb = muDoubleScalarAbs(batStaLimMax);
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                  muDoubleScalarMax(absa, absb)) {
                ndbl++;
                apnd = batStaLimMax;
              } else if (cdiff > 0.0) {
                apnd = batEngInxBeg + (ndbl - 1.0);
              } else {
                ndbl++;
              }

              overflow = (2.147483647E+9 < ndbl);
              if (ndbl >= 0.0) {
                n = (int32_T)ndbl - 1;
              } else {
                n = -1;
              }
            }

            d_st.site = &p_emlrtRSI;
            if (!overflow) {
            } else {
              d_y = NULL;
              m0 = emlrtCreateCharArray(2, iv2);
              for (i = 0; i < 21; i++) {
                cv0[i] = cv1[i];
              }

              emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
              emlrtAssign(&d_y, m0);
              e_st.site = &tb_emlrtRSI;
              f_st.site = &yb_emlrtRSI;
              error(&e_st, message(&f_st, d_y, &emlrtMCI), &b_emlrtMCI);
            }

            i3 = batStaPreIdxVec->size[0] * batStaPreIdxVec->size[1];
            batStaPreIdxVec->size[0] = 1;
            batStaPreIdxVec->size[1] = n + 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)batStaPreIdxVec, i3,
                              (int32_T)sizeof(real_T), &b_emlrtRTEI);
            if (n + 1 > 0) {
              batStaPreIdxVec->data[0] = geaStaPre;
              if (n + 1 > 1) {
                batStaPreIdxVec->data[n] = apnd;
                i3 = n + (n < 0);
                if (i3 >= 0) {
                  nm1d2 = (int32_T)((uint32_T)i3 >> 1);
                } else {
                  nm1d2 = (int32_T)~(~(uint32_T)i3 >> 1);
                }

                d_st.site = &q_emlrtRSI;
                for (iy = 1; iy < nm1d2; iy++) {
                  batStaPreIdxVec->data[iy] = geaStaPre + (real_T)iy;
                  batStaPreIdxVec->data[n - iy] = apnd - (real_T)iy;
                }

                if (nm1d2 << 1 == n) {
                  batStaPreIdxVec->data[nm1d2] = (geaStaPre + apnd) / 2.0;
                } else {
                  batStaPreIdxVec->data[nm1d2] = geaStaPre + (real_T)nm1d2;
                  batStaPreIdxVec->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
                }
              }
            }

            /*  ------------------------------------------------------------------------- */
            /* % ----- PREDECESSOR STATE VARIBALE LOOP ---------------------------------- */
            /*  PREVIOUS gear state loop */
            nm1d2 = 0;
            while (nm1d2 <= engStaPreIdx_size_idx_1 - 1) {
              i3 = 1 + nm1d2;
              apnd = engStaPreIdx_data[emlrtDynamicBoundsCheckFastR2012b(i3, 1,
                engStaPreIdx_size_idx_1, &id_emlrtBCI, sp) - 1];

              /*  engine state penalty */
              if (b_engStaAct == engStaPreIdx_data[nm1d2]) {
                cdiff = 0.0;
              } else {
                cdiff = inputparams->staChgPenCosVal;
              }

              /*  penalty for changning battery level or no? */
              /*  Schleife über allen Zustände (relativer Index) */
              /*    Loop through all the gear states (relative index) */
              b_ix = 0;
              while (b_ix <= b_y->size[1] - 1) {
                /*  PREVIOUS GEAR CHANGE LOOP */
                i3 = b_y->size[1];
                cindx = 1 + b_ix;
                geaStaPre = b_y->data[emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                  i3, &jd_emlrtBCI, sp) - 1];

                /*  Kosten für Zustandswechsel setzen */
                /*    set costs for gear state changes */
                if (b_geaStaAct == b_y->data[b_ix]) {
                  /*  Entspricht der Vorgï¿½ngerzustand dem aktuellen  */
                  /*  Zustand werden keine Kosten gesetzt */
                  /*    staying in current state? set penalty cost to 0 */
                  ndbl = 0.0;
                } else {
                  /*  Ansonsten einfache Zustandswechselkosten */
                  /*  berechnen */
                  /*    otherwise apply a penalty cost to changing gear */
                  ndbl = inputparams->staChgPenCosVal;

                  /* <-penCos is input */
                }

                /*                         %% check if engStaPre == 0. */
                /*  if == 0 - ignore bat state loop bc emoTrq==crsTrq */
                /*    b/c anything else is not optimal (w/ brakes) */
                /*  if == 1 - then run through bat state loop */
                /*  pull out appropriate crankshaft speed and torque */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &lb_emlrtBCI, sp);
                absa = b_y->data[b_ix];
                i3 = (int32_T)emlrtIntegerCheckFastR2012b(absa, &p_emlrtDCI, sp);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &kb_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &jb_emlrtBCI, sp);

                /*  all EM torque boundaries for given gear */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &ib_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &hb_emlrtBCI, sp);

                /*                        % emoTrqMaxPosMat(:, geaStaPre); */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &gb_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &fb_emlrtBCI, sp);

                /*  IF ENGINE WAS ON */
                if (apnd != 0.0) {
                  /*  all ICE torque boundaries for given gear */
                  i3 = (int32_T)(b_timInx - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &eb_emlrtBCI,
                    sp);
                  i3 = (int32_T)(b_timInx - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &db_emlrtBCI,
                    sp);

                  /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS ------ */
                  /*  boundaries: since crsSpd is dependent on gear,  */
                  /*  check is performed within the gear state loop */
                  /*  IF ENGINE IS ON: */
                  /*  Abbruch, wenn die Drehzahlen der Kurbelwelle  */
                  /*  zu hoch im hybridischen */
                  /*  Modus */
                  /*    stop if the crankshaft rotational speed is  */
                  /*    too high in hybrid mode */
                  i3 = (int32_T)b_y->data[b_ix] - 1;
                  if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] >
                      crsSpdHybMax) {
                  } else {
                    /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
                    /*  Leerlaufdrehzahl ist, */
                    /*    stop if crankhaft rotional speed is lower than the idling speed */
                    i3 = (int32_T)b_y->data[b_ix] - 1;
                    if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] <
                        crsSpdHybMin) {
                    } else {
                      iy = 0;
                      while (iy <= batStaPreIdxVec->size[1] - 1) {
                        /*  value of previous idx engine control state */
                        /*   - unnecessary to assign - indexes represent bool values */
                        /*  loop through all possible previous battery levels */
                        /*  calculate index for bat state - can move */
                        /*  outside for loop for improving computation tim later */
                        /*  because batStaPreIdx is coming from an index vector from */
                        /*  the loop batStaPreIdx_counter, and because */
                        /*  we need batStaPreIdx to be used for */
                        /*  referencing vector indexes later on, the */
                        /*  variable batStaPreIdx will be used as an */
                        /*  index vector, and not as a scaled energy */
                        /*  level value index vector. */
                        /*  therefore, we subtract 1 from the index */
                        /*  when transforming batStaPreIdx into its */
                        /*  rescaled form batStaPre. */
                        i3 = batStaPreIdxVec->size[1];
                        cindx = iy + 1;
                        emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3,
                          &cb_emlrtBCI, sp);

                        /*  calculate E' */
                        absb = batStaAct - (batStaPreIdxVec->data[iy] - 1.0) *
                          batStaStp;

                        /*  calculate battery resistance */
                        /*  the code below is performing this code snippet across the vector */
                        /*  if batPwr < 0 */
                        /*      batRst = fzg_scalar_struct.batRstDch; */
                        /*  else */
                        /*      batRst = fzg_scalar_struct.batRstChr; */
                        /*  end */
                        /*  lookup previous bat state's voltage value */
                        absa = batStaPreIdxVec->data[iy];
                        i3 = (int32_T)emlrtIntegerCheckFastR2012b(absa,
                          &o_emlrtDCI, sp);
                        emlrtDynamicBoundsCheckFastR2012b(i3, 1, 693,
                          &bb_emlrtBCI, sp);

                        /*                                 %% Berechnung der optimalen Kosten zum aktuellen Punkt */
                        /*    calculating optimal cost to the current point */
                        /*  do it tim interval at a tim? will remove vector */
                        /*  aspects */
                        /*  % maximum crankshaft rotational speed */
                        /*  % minimum crankshaft rotational speed */
                        st.site = &f_emlrtRSI;
                        optTrqSplit_focus(&st, inputparams->brkBool, absb,
                                          batOcv[(int32_T)batStaPreIdxVec->
                                          data[iy] - 1], (real_T)(absb < 0.0) *
                                          fzg_scalar_struct->batRstDch + (real_T)
                                          (absb >= 0.0) *
                                          fzg_scalar_struct->batRstChr,
                                          crsSpdMat[((int32_T)b_timInx + 1181 *
                          ((int32_T)b_y->data[b_ix] - 1)) - 2], crsTrqMat
                                          [((int32_T)b_timInx + 1181 * ((int32_T)
                          b_y->data[b_ix] - 1)) - 2], emoTrqMinPosMat[((int32_T)
                          b_timInx + 1181 * ((int32_T)geaStaPre - 1)) - 2],
                                          emoTrqMaxPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)geaStaPre - 1)) - 2],
                                          emoPwrMinPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)geaStaPre - 1)) - 2],
                                          emoPwrMaxPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)geaStaPre - 1)) - 2],
                                          iceTrqMaxPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)geaStaPre - 1)) - 2],
                                          iceTrqMinPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)geaStaPre - 1)) - 2], crsSpdHybMax,
                                          crsSpdHybMin, inputparams->timStp,
                                          inputparams->batPwrAux, vehVelVec,
                                          fzg_scalar_struct, fzg_array_struct,
                                          &batEngInxBeg, &batStaPreIdx_noEmo,
                                          &batStaLimMax, &absa);

                        /*  combine the min hamil. cost w/ previous costs and  */
                        /*    gear penalty to get current cost */
                        i3 = fulActTn3->size[0];
                        cindx = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                          &ob_emlrtDCI, sp);
                        ix = fulActTn3->size[1];
                        i = (int32_T)geaStaPre;
                        npages = fulActTn3->size[2];
                        n = (int32_T)batStaPreIdxVec->data[iy];
                        i4 = cos2goPreTn3->size[0];
                        i5 = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                          &pb_emlrtDCI, sp);
                        i6 = cos2goPreTn3->size[1];
                        i7 = (int32_T)geaStaPre;
                        i8 = cos2goPreTn3->size[2];
                        ixstop = (int32_T)batStaPreIdxVec->data[iy];
                        fulActTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                                          (cindx, 1, i3, &sd_emlrtBCI, sp) +
                                          fulActTn3->size[0] *
                                          (emlrtDynamicBoundsCheckFastR2012b(i,
                          1, ix, &td_emlrtBCI, sp) - 1)) + fulActTn3->size[0] *
                                         fulActTn3->size[1] *
                                         (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                          npages, &ud_emlrtBCI, sp) - 1)) - 1] = ((batEngInxBeg
                          + cos2goPreTn3->data
                          [((emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                          &vd_emlrtBCI, sp) + cos2goPreTn3->size[0] *
                             (emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6,
                          &wd_emlrtBCI, sp) - 1)) + cos2goPreTn3->size[0] *
                            cos2goPreTn3->size[1] *
                            (emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i8,
                          &xd_emlrtBCI, sp) - 1)) - 1]) + ndbl /
                          inputparams->timStp) + cdiff / inputparams->timStp;
                        i3 = emoTrqPreTn3->size[0];
                        cindx = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                          &qb_emlrtDCI, sp);
                        ix = emoTrqPreTn3->size[1];
                        i = (int32_T)geaStaPre;
                        npages = emoTrqPreTn3->size[2];
                        n = (int32_T)batStaPreIdxVec->data[iy];
                        emoTrqPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                                             (cindx, 1, i3, &yd_emlrtBCI, sp) +
                                             emoTrqPreTn3->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (i, 1, ix, &ae_emlrtBCI, sp) - 1))
                                            + emoTrqPreTn3->size[0] *
                                            emoTrqPreTn3->size[1] *
                                            (emlrtDynamicBoundsCheckFastR2012b(n,
                          1, npages, &be_emlrtBCI, sp) - 1)) - 1] =
                          batStaPreIdx_noEmo;
                        i3 = iceTrqPreTn3->size[0];
                        cindx = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                          &rb_emlrtDCI, sp);
                        ix = iceTrqPreTn3->size[1];
                        i = (int32_T)geaStaPre;
                        npages = iceTrqPreTn3->size[2];
                        n = (int32_T)batStaPreIdxVec->data[iy];
                        iceTrqPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                                             (cindx, 1, i3, &ce_emlrtBCI, sp) +
                                             iceTrqPreTn3->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (i, 1, ix, &de_emlrtBCI, sp) - 1))
                                            + iceTrqPreTn3->size[0] *
                                            iceTrqPreTn3->size[1] *
                                            (emlrtDynamicBoundsCheckFastR2012b(n,
                          1, npages, &ee_emlrtBCI, sp) - 1)) - 1] = batStaLimMax;
                        i3 = brkTrqPreTn3->size[0];
                        cindx = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                          &sb_emlrtDCI, sp);
                        ix = brkTrqPreTn3->size[1];
                        i = (int32_T)geaStaPre;
                        npages = brkTrqPreTn3->size[2];
                        n = (int32_T)batStaPreIdxVec->data[iy];
                        brkTrqPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                                             (cindx, 1, i3, &fe_emlrtBCI, sp) +
                                             brkTrqPreTn3->size[0] *
                                             (emlrtDynamicBoundsCheckFastR2012b
                                              (i, 1, ix, &ge_emlrtBCI, sp) - 1))
                                            + brkTrqPreTn3->size[0] *
                                            brkTrqPreTn3->size[1] *
                                            (emlrtDynamicBoundsCheckFastR2012b(n,
                          1, npages, &he_emlrtBCI, sp) - 1)) - 1] = absa;
                        iy++;
                        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar,
                          sp);
                      }

                      /*  end of bat energy changing loop */
                      /*  end of engStaPre condition check */
                    }
                  }
                } else {
                  /*  ---- electric motor MUST satisfy crsTrq ----- */
                  /*  IF ENGINE IS OFF */
                  /*  Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
                  /*    check if electric motor speed limit is maintained */
                  i3 = (int32_T)b_y->data[b_ix] - 1;
                  if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] >
                      crsSpdEmoMax) {
                  } else {
                    /*  determine previous state if engine waas off */
                    /*  based on batPwrDemIdxTn3 (a preprocessed tn3 */
                    /*  containing amnt battery pwr needed to satisfy */
                    /*  a crankshaft power demand for all state */
                    /*  permutations) */
                    /*  - 1 */
                    batStaPreIdx_noEmo = (1.0 + (real_T)batStaActInx) +
                      batPwrDemIdxTn3[(((int32_T)b_timInx + 1181 * batStaActInx)
                                       + 818433 * ((int32_T)b_geaStaAct - 1)) -
                      1];

                    /*  check your bounds  */
                    if ((batStaPreIdx_noEmo < batStaMin / batStaStp + 1.0) ||
                        (batStaPreIdx_noEmo > batStaMax / batStaStp + 1.0)) {
                    } else {
                      /*  penalty to get current cost */
                      /*  minFul ... */
                      emlrtIntegerCheckFastR2012b(1.0, &j_emlrtDCI, sp);
                      i3 = fulActTn3->size[0];
                      emlrtDynamicBoundsCheckFastR2012b(1, 1, i3, &u_emlrtBCI,
                        sp);
                      emlrtIntegerCheckFastR2012b(1.0, &k_emlrtDCI, sp);
                      i3 = cos2goPreTn3->size[0];
                      emlrtDynamicBoundsCheckFastR2012b(1, 1, i3, &w_emlrtBCI,
                        sp);
                      i3 = fulActTn3->size[1];
                      cindx = (int32_T)b_y->data[b_ix];
                      ix = fulActTn3->size[2];
                      i = (int32_T)emlrtIntegerCheckFastR2012b
                        (batStaPreIdx_noEmo, &mb_emlrtDCI, sp);
                      npages = cos2goPreTn3->size[1];
                      n = (int32_T)b_y->data[b_ix];
                      i4 = cos2goPreTn3->size[2];
                      i5 = (int32_T)emlrtIntegerCheckFastR2012b
                        (batStaPreIdx_noEmo, &nb_emlrtDCI, sp);
                      fulActTn3->data[fulActTn3->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3,
                          &kd_emlrtBCI, sp) - 1) + fulActTn3->size[0] *
                        fulActTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b
                        (i, 1, ix, &ld_emlrtBCI, sp) - 1)] = (cos2goPreTn3->
                        data[cos2goPreTn3->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(n, 1, npages,
                        &md_emlrtBCI, sp) - 1) + cos2goPreTn3->size[0] *
                        cos2goPreTn3->size[1] *
                        (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                        &nd_emlrtBCI, sp) - 1)] + ndbl / inputparams->timStp) +
                        cdiff / inputparams->timStp;
                      emlrtIntegerCheckFastR2012b(1.0, &f_emlrtDCI, sp);
                      i3 = emoTrqPreTn3->size[0];
                      emlrtDynamicBoundsCheckFastR2012b(1, 1, i3, &k_emlrtBCI,
                        sp);
                      i3 = emoTrqPreTn3->size[1];
                      cindx = (int32_T)b_y->data[b_ix];
                      ix = emoTrqPreTn3->size[2];
                      i = (int32_T)batStaPreIdx_noEmo;
                      emoTrqPreTn3->data[emoTrqPreTn3->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3,
                          &od_emlrtBCI, sp) - 1) + emoTrqPreTn3->size[0] *
                        emoTrqPreTn3->size[1] *
                        (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                          &pd_emlrtBCI, sp) - 1)] = crsTrqMat[((int32_T)b_timInx
                        + 1181 * ((int32_T)geaStaPre - 1)) - 2];

                      /*  brake torque in case of torque overshoot */
                      if (inputparams->brkBool != 0.0) {
                        batEngInxBeg = crsTrqMat[((int32_T)b_timInx + 1181 *
                          ((int32_T)geaStaPre - 1)) - 2] * crsSpdMat[((int32_T)
                          b_timInx + 1181 * ((int32_T)geaStaPre - 1)) - 2];
                        i3 = batStaActInxVec->size[1];
                        cindx = (int32_T)batStaPreIdx_noEmo;
                        emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3,
                          &v_emlrtBCI, sp);
                        batStaLimMax = batStaActInxVec->data[(int32_T)
                          batStaPreIdx_noEmo - 1] * batStaStp /
                          inputparams->timStp;
                        if (batStaLimMax > batEngInxBeg) {
                          emlrtIntegerCheckFastR2012b(1.0, &e_emlrtDCI, sp);
                          i3 = brkTrqPreTn3->size[0];
                          emlrtDynamicBoundsCheckFastR2012b(1, 1, i3,
                            &j_emlrtBCI, sp);
                          i3 = brkTrqPreTn3->size[1];
                          cindx = (int32_T)b_y->data[b_ix];
                          ix = brkTrqPreTn3->size[2];
                          i = (int32_T)batStaPreIdx_noEmo;
                          brkTrqPreTn3->data[brkTrqPreTn3->size[0] *
                            (emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3,
                              &qd_emlrtBCI, sp) - 1) + brkTrqPreTn3->size[0] *
                            brkTrqPreTn3->size[1] *
                            (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                              &rd_emlrtBCI, sp) - 1)] = (batStaLimMax -
                            batEngInxBeg) / crsSpdMat[((int32_T)b_timInx + 1181 *
                            ((int32_T)b_y->data[b_ix] - 1)) - 2];
                        }
                      }

                      /*  end of engStaPre condition check */
                    }
                  }
                }

                b_ix++;
                emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
              }

              /*  end of gear changes loop */
              nm1d2++;
              emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
            }

            /*  end of running through previous engine state ctrl loop */
            /*  pull out the minimum value from fulActMat */
            st.site = &g_emlrtRSI;
            b_st.site = &gb_emlrtRSI;
            c_st.site = &hb_emlrtRSI;
            if (((fulActTn3->size[0] == 1) && (fulActTn3->size[1] == 1) &&
                 (fulActTn3->size[2] == 1)) || (fulActTn3->size[0] != 1)) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (overflow) {
            } else {
              e_y = NULL;
              m0 = emlrtCreateCharArray(2, iv3);
              for (i = 0; i < 36; i++) {
                cv2[i] = cv3[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 36, m0, cv2);
              emlrtAssign(&e_y, m0);
              d_st.site = &sb_emlrtRSI;
              g_st.site = &xb_emlrtRSI;
              error(&d_st, message(&g_st, e_y, &f_emlrtMCI), &g_emlrtMCI);
            }

            if (fulActTn3->size[0] > 0) {
            } else {
              f_y = NULL;
              m0 = emlrtCreateCharArray(2, iv4);
              for (i = 0; i < 39; i++) {
                cv4[i] = cv5[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 39, m0, cv4);
              emlrtAssign(&f_y, m0);
              d_st.site = &rb_emlrtRSI;
              g_st.site = &wb_emlrtRSI;
              error(&d_st, message(&g_st, f_y, &h_emlrtMCI), &i_emlrtMCI);
            }

            for (i3 = 0; i3 < 3; i3++) {
              outsz[i3] = (uint32_T)fulActTn3->size[i3];
            }

            i3 = extremum->size[0] * extremum->size[1] * extremum->size[2];
            extremum->size[0] = 1;
            extremum->size[1] = (int32_T)outsz[1];
            extremum->size[2] = (int32_T)outsz[2];
            emxEnsureCapacity(&c_st, (emxArray__common *)extremum, i3, (int32_T)
                              sizeof(real_T), &c_emlrtRTEI);
            b_outsz = outsz[1];
            c_outsz = outsz[2];
            i3 = iindx->size[0] * iindx->size[1] * iindx->size[2];
            iindx->size[0] = 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i3, (int32_T)
                              sizeof(int32_T), &emlrtRTEI);
            i3 = iindx->size[0] * iindx->size[1] * iindx->size[2];
            iindx->size[1] = (int32_T)outsz[1];
            emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i3, (int32_T)
                              sizeof(int32_T), &emlrtRTEI);
            i3 = iindx->size[0] * iindx->size[1] * iindx->size[2];
            iindx->size[2] = (int32_T)c_outsz;
            emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i3, (int32_T)
                              sizeof(int32_T), &emlrtRTEI);
            iy = (int32_T)b_outsz * (int32_T)c_outsz;
            for (i3 = 0; i3 < iy; i3++) {
              iindx->data[i3] = 1;
            }

            n = fulActTn3->size[0];
            npages = 1;
            iy = 3;
            while ((iy > 2) && (fulActTn3->size[2] == 1)) {
              iy = 2;
            }

            for (b_ix = 2; b_ix <= iy; b_ix++) {
              npages *= fulActTn3->size[b_ix - 1];
            }

            b_ix = 0;
            iy = -1;
            d_st.site = &ib_emlrtRSI;
            if (1 > npages) {
              b0 = false;
            } else {
              b0 = (npages > 2147483646);
            }

            if (b0) {
              e_st.site = &r_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (i = 1; i <= npages; i++) {
              d_st.site = &jb_emlrtRSI;
              d_st.site = &u_emlrtRSI;
              nm1d2 = b_ix;
              ixstop = b_ix + n;
              batEngInxBeg = fulActTn3->data[b_ix];
              engStaPreIdx_size_idx_1 = 1;
              if (n > 1) {
                cindx = 1;
                if (muDoubleScalarIsNaN(fulActTn3->data[b_ix])) {
                  e_st.site = &w_emlrtRSI;
                  if (b_ix + 2 > ixstop) {
                    e_ix = false;
                  } else {
                    e_ix = (ixstop > 2147483646);
                  }

                  if (e_ix) {
                    h_st.site = &r_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  ix = b_ix + 1;
                  exitg3 = false;
                  while ((!exitg3) && (ix + 1 <= ixstop)) {
                    cindx++;
                    nm1d2 = ix;
                    if (!muDoubleScalarIsNaN(fulActTn3->data[ix])) {
                      batEngInxBeg = fulActTn3->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                      exitg3 = true;
                    } else {
                      ix++;
                    }
                  }
                }

                if (nm1d2 + 1 < ixstop) {
                  e_st.site = &v_emlrtRSI;
                  if (nm1d2 + 2 > ixstop) {
                    d_nm1d2 = false;
                  } else {
                    d_nm1d2 = (ixstop > 2147483646);
                  }

                  if (d_nm1d2) {
                    h_st.site = &r_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (ix = nm1d2 + 1; ix + 1 <= ixstop; ix++) {
                    cindx++;
                    if (fulActTn3->data[ix] < batEngInxBeg) {
                      batEngInxBeg = fulActTn3->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                    }
                  }
                }
              }

              iy++;
              extremum->data[iy] = batEngInxBeg;
              iindx->data[iy] = engStaPreIdx_size_idx_1;
              b_ix += n;
            }

            i3 = indx->size[0] * indx->size[1] * indx->size[2];
            indx->size[0] = 1;
            indx->size[1] = iindx->size[1];
            indx->size[2] = iindx->size[2];
            emxEnsureCapacity(&b_st, (emxArray__common *)indx, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = iindx->size[0] * iindx->size[1] * iindx->size[2];
            for (i3 = 0; i3 < iy; i3++) {
              indx->data[i3] = iindx->data[i3];
            }

            st.site = &h_emlrtRSI;
            b_st.site = &gb_emlrtRSI;
            c_st.site = &hb_emlrtRSI;
            if (((extremum->size[1] == 1) && (extremum->size[2] == 1)) ||
                (extremum->size[1] != 1)) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (overflow) {
            } else {
              g_y = NULL;
              m0 = emlrtCreateCharArray(2, iv5);
              for (i = 0; i < 36; i++) {
                cv2[i] = cv3[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 36, m0, cv2);
              emlrtAssign(&g_y, m0);
              d_st.site = &sb_emlrtRSI;
              g_st.site = &xb_emlrtRSI;
              error(&d_st, message(&g_st, g_y, &f_emlrtMCI), &g_emlrtMCI);
            }

            if (extremum->size[1] > 0) {
            } else {
              h_y = NULL;
              m0 = emlrtCreateCharArray(2, iv6);
              for (i = 0; i < 39; i++) {
                cv4[i] = cv5[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 39, m0, cv4);
              emlrtAssign(&h_y, m0);
              d_st.site = &rb_emlrtRSI;
              g_st.site = &wb_emlrtRSI;
              error(&d_st, message(&g_st, h_y, &h_emlrtMCI), &i_emlrtMCI);
            }

            for (i3 = 0; i3 < 3; i3++) {
              outsz[i3] = (uint32_T)extremum->size[i3];
            }

            i3 = b_extremum->size[0] * b_extremum->size[1] * b_extremum->size[2];
            b_extremum->size[0] = 1;
            b_extremum->size[1] = 1;
            b_extremum->size[2] = (int32_T)outsz[2];
            emxEnsureCapacity(&c_st, (emxArray__common *)b_extremum, i3,
                              (int32_T)sizeof(real_T), &c_emlrtRTEI);
            i3 = b_iindx->size[0] * b_iindx->size[1] * b_iindx->size[2];
            b_iindx->size[0] = 1;
            b_iindx->size[1] = 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)b_iindx, i3, (int32_T)
                              sizeof(int32_T), &emlrtRTEI);
            i3 = b_iindx->size[0] * b_iindx->size[1] * b_iindx->size[2];
            b_iindx->size[2] = (int32_T)outsz[2];
            emxEnsureCapacity(&c_st, (emxArray__common *)b_iindx, i3, (int32_T)
                              sizeof(int32_T), &emlrtRTEI);
            iy = (int32_T)outsz[2];
            for (i3 = 0; i3 < iy; i3++) {
              b_iindx->data[i3] = 1;
            }

            n = extremum->size[1];
            npages = 1;
            iy = 3;
            while ((iy > 2) && (extremum->size[2] == 1)) {
              iy = 2;
            }

            b_ix = 3;
            while (b_ix <= iy) {
              npages *= extremum->size[2];
              b_ix = 4;
            }

            b_ix = 0;
            iy = -1;
            d_st.site = &ib_emlrtRSI;
            if (1 > npages) {
              b1 = false;
            } else {
              b1 = (npages > 2147483646);
            }

            if (b1) {
              e_st.site = &r_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (i = 1; i <= npages; i++) {
              d_st.site = &jb_emlrtRSI;
              d_st.site = &u_emlrtRSI;
              nm1d2 = b_ix;
              ixstop = b_ix + n;
              batEngInxBeg = extremum->data[b_ix];
              engStaPreIdx_size_idx_1 = 1;
              if (n > 1) {
                cindx = 1;
                if (muDoubleScalarIsNaN(extremum->data[b_ix])) {
                  e_st.site = &w_emlrtRSI;
                  if (b_ix + 2 > ixstop) {
                    f_ix = false;
                  } else {
                    f_ix = (ixstop > 2147483646);
                  }

                  if (f_ix) {
                    h_st.site = &r_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  ix = b_ix + 1;
                  exitg2 = false;
                  while ((!exitg2) && (ix + 1 <= ixstop)) {
                    cindx++;
                    nm1d2 = ix;
                    if (!muDoubleScalarIsNaN(extremum->data[ix])) {
                      batEngInxBeg = extremum->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                      exitg2 = true;
                    } else {
                      ix++;
                    }
                  }
                }

                if (nm1d2 + 1 < ixstop) {
                  e_st.site = &v_emlrtRSI;
                  if (nm1d2 + 2 > ixstop) {
                    e_nm1d2 = false;
                  } else {
                    e_nm1d2 = (ixstop > 2147483646);
                  }

                  if (e_nm1d2) {
                    h_st.site = &r_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (ix = nm1d2 + 1; ix + 1 <= ixstop; ix++) {
                    cindx++;
                    if (extremum->data[ix] < batEngInxBeg) {
                      batEngInxBeg = extremum->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                    }
                  }
                }
              }

              iy++;
              b_extremum->data[iy] = batEngInxBeg;
              b_iindx->data[iy] = engStaPreIdx_size_idx_1;
              b_ix += n;
            }

            i3 = b_indx->size[0] * b_indx->size[1] * b_indx->size[2];
            b_indx->size[0] = 1;
            b_indx->size[1] = 1;
            b_indx->size[2] = b_iindx->size[2];
            emxEnsureCapacity(&b_st, (emxArray__common *)b_indx, i3, (int32_T)
                              sizeof(real_T), &emlrtRTEI);
            iy = b_iindx->size[0] * b_iindx->size[1] * b_iindx->size[2];
            for (i3 = 0; i3 < iy; i3++) {
              b_indx->data[i3] = b_iindx->data[i3];
            }

            st.site = &i_emlrtRSI;
            b_st.site = &gb_emlrtRSI;
            c_st.site = &hb_emlrtRSI;
            if ((b_extremum->size[2] == 1) || (b_extremum->size[2] != 1)) {
              overflow = true;
            } else {
              overflow = false;
            }

            if (overflow) {
            } else {
              i_y = NULL;
              m0 = emlrtCreateCharArray(2, iv7);
              for (i = 0; i < 36; i++) {
                cv2[i] = cv3[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 36, m0, cv2);
              emlrtAssign(&i_y, m0);
              d_st.site = &sb_emlrtRSI;
              g_st.site = &xb_emlrtRSI;
              error(&d_st, message(&g_st, i_y, &f_emlrtMCI), &g_emlrtMCI);
            }

            if (b_extremum->size[2] > 0) {
            } else {
              j_y = NULL;
              m0 = emlrtCreateCharArray(2, iv8);
              for (i = 0; i < 39; i++) {
                cv4[i] = cv5[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 39, m0, cv4);
              emlrtAssign(&j_y, m0);
              d_st.site = &rb_emlrtRSI;
              g_st.site = &wb_emlrtRSI;
              error(&d_st, message(&g_st, j_y, &h_emlrtMCI), &i_emlrtMCI);
            }

            d_st.site = &kb_emlrtRSI;
            nm1d2 = 1;
            n = b_extremum->size[2];
            batEngInxBeg = b_extremum->data[0];
            engStaPreIdx_size_idx_1 = 0;
            if (b_extremum->size[2] > 1) {
              if (muDoubleScalarIsNaN(b_extremum->data[0])) {
                e_st.site = &w_emlrtRSI;
                overflow = (b_extremum->size[2] > 2147483646);
                if (overflow) {
                  h_st.site = &r_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                b_ix = 1;
                exitg1 = false;
                while ((!exitg1) && (b_ix + 1 <= n)) {
                  nm1d2 = b_ix + 1;
                  if (!muDoubleScalarIsNaN(b_extremum->data[b_ix])) {
                    batEngInxBeg = b_extremum->data[b_ix];
                    engStaPreIdx_size_idx_1 = b_ix;
                    exitg1 = true;
                  } else {
                    b_ix++;
                  }
                }
              }

              if (nm1d2 < b_extremum->size[2]) {
                e_st.site = &v_emlrtRSI;
                if (nm1d2 + 1 > b_extremum->size[2]) {
                  overflow = false;
                } else {
                  overflow = (b_extremum->size[2] > 2147483646);
                }

                if (overflow) {
                  h_st.site = &r_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                while (nm1d2 + 1 <= n) {
                  if (b_extremum->data[nm1d2] < batEngInxBeg) {
                    batEngInxBeg = b_extremum->data[nm1d2];
                    engStaPreIdx_size_idx_1 = nm1d2;
                  }

                  nm1d2++;
                }
              }
            }

            i3 = b_indx->size[2];
            cindx = engStaPreIdx_size_idx_1 + 1;
            emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &t_emlrtBCI, sp);
            i3 = indx->size[1];
            cindx = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
            emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &s_emlrtBCI, sp);
            i3 = indx->size[2];
            cindx = engStaPreIdx_size_idx_1 + 1;
            emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &r_emlrtBCI, sp);

            /*                  engStaPreOptInx = batStaPreIdxVec(engStaPreInx); */
            if (!muDoubleScalarIsInf(batEngInxBeg)) {
              /*  new opt. battery energy = (batt. force * */
              /*    tim diff) + previous battery energy valu */
              /*    - NOTE: batFrc*timStp calc is the same as the */
              /*        batFrc calculation in batFrcClc_a() */
              /*    -   why not output that calculation instead? */
              /*  + ... */
              /*                          batEngPreTn3(engStaPreOptInx,geaStaPreOptInx,batStaPreOptInx); */
              /*  new opt. fuel energy = (fuel force * tim diff) */
              /*    + previous fuel energy value */
              i3 = fulEngPreTn3->size[0];
              cindx = (int32_T)indx->data[indx->size[0] * ((int32_T)b_indx->
                data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] * indx->size
                [1] * engStaPreIdx_size_idx_1];
              emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &n_emlrtBCI, sp);
              i3 = fulEngPreTn3->size[1];
              cindx = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
              emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &m_emlrtBCI, sp);
              i3 = fulEngPreTn3->size[2];
              cindx = engStaPreIdx_size_idx_1 + 1;
              emlrtDynamicBoundsCheckFastR2012b(cindx, 1, i3, &l_emlrtBCI, sp);

              /* %#ok<PFBNS> */
              /*  optimale Kosten zum aktuellen Punkt speichern */
              /*    save min hamilton value for current point */
              i3 = cos2goActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &eb_emlrtDCI, sp);
              ix = cos2goActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = cos2goActTn3->size[2];
              n = 1 + batStaActInx;
              cos2goActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &yb_emlrtBCI, sp) + cos2goActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &ac_emlrtBCI, sp) - 1)) + cos2goActTn3->size[0] *
                                  cos2goActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &bc_emlrtBCI, sp) - 1)) - 1] = batEngInxBeg;

              /*  optimale Batterieenergie zum aktuellen Punkt speichern */
              /*    save optimal battery energy for current point */
              i3 = batEngActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &fb_emlrtDCI, sp);
              ix = batEngActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = batEngActTn3->size[2];
              n = 1 + batStaActInx;
              batEngActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &cc_emlrtBCI, sp) + batEngActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &dc_emlrtBCI, sp) - 1)) + batEngActTn3->size[0] *
                                  batEngActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &ec_emlrtBCI, sp) - 1)) - 1] = ((real_T)
                (engStaPreIdx_size_idx_1 + 1) - 1.0) * batStaStp;

              /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
              /*    save optimal fuel energy for current point */
              i3 = fulEngActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &gb_emlrtDCI, sp);
              ix = fulEngActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = fulEngActTn3->size[2];
              n = 1 + batStaActInx;
              fulEngActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &fc_emlrtBCI, sp) + fulEngActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &gc_emlrtBCI, sp) - 1)) + fulEngActTn3->size[0] *
                                  fulEngActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &hc_emlrtBCI, sp) - 1)) - 1] = batEngInxBeg +
                fulEngPreTn3->data[(((int32_T)indx->data[indx->size[0] *
                ((int32_T)b_indx->data[engStaPreIdx_size_idx_1] - 1) +
                indx->size[0] * indx->size[1] * engStaPreIdx_size_idx_1] +
                fulEngPreTn3->size[0] * ((int32_T)b_indx->
                data[engStaPreIdx_size_idx_1] - 1)) + fulEngPreTn3->size[0] *
                                    fulEngPreTn3->size[1] *
                                    engStaPreIdx_size_idx_1) - 1];

              /*  optimale Batterieenergie zum aktuellen Punkt */
              /*  Flussgrï¿½ï¿½e gilt im Intervall */
              /*    populate optimal battery energy flux quantity at point  */
              /*    that's applicable to current interval */
              i3 = batPwrOptTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &hb_emlrtDCI, sp);
              ix = batPwrOptTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = batPwrOptTn3->size[2];
              n = 1 + batStaActInx;
              batPwrOptTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &ic_emlrtBCI, sp) + batPwrOptTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &jc_emlrtBCI, sp) - 1)) + batPwrOptTn3->size[0] *
                                  batPwrOptTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &kc_emlrtBCI, sp) - 1)) - 1] = (1.0 + (real_T)
                batStaActInx) - (real_T)(engStaPreIdx_size_idx_1 + 1);

              /*  save optimal torque values for the given state */
              /*  emoTrq */
              i3 = emoTrqActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &ib_emlrtDCI, sp);
              ix = emoTrqActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = emoTrqActTn3->size[2];
              n = 1 + batStaActInx;
              i4 = emoTrqPreTn3->size[0];
              i5 = (int32_T)indx->data[indx->size[0] * ((int32_T)b_indx->
                data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] * indx->size
                [1] * engStaPreIdx_size_idx_1];
              i6 = emoTrqPreTn3->size[1];
              i7 = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
              i8 = emoTrqPreTn3->size[2];
              emoTrqActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &lc_emlrtBCI, sp) + emoTrqActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &mc_emlrtBCI, sp) - 1)) + emoTrqActTn3->size[0] *
                                  emoTrqActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &nc_emlrtBCI, sp) - 1)) - 1] = emoTrqPreTn3->data
                [((emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &oc_emlrtBCI, sp)
                   + emoTrqPreTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                    (i7, 1, i6, &pc_emlrtBCI, sp) - 1)) + emoTrqPreTn3->size[0] *
                  emoTrqPreTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b
                   (engStaPreIdx_size_idx_1 + 1, 1, i8, &qc_emlrtBCI, sp) - 1))
                - 1];

              /*  iceTrq */
              i3 = iceTrqActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &jb_emlrtDCI, sp);
              ix = iceTrqActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = iceTrqActTn3->size[2];
              n = 1 + batStaActInx;
              i4 = iceTrqPreTn3->size[0];
              i5 = (int32_T)indx->data[indx->size[0] * ((int32_T)b_indx->
                data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] * indx->size
                [1] * engStaPreIdx_size_idx_1];
              i6 = iceTrqPreTn3->size[1];
              i7 = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
              i8 = iceTrqPreTn3->size[2];
              iceTrqActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &rc_emlrtBCI, sp) + iceTrqActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &sc_emlrtBCI, sp) - 1)) + iceTrqActTn3->size[0] *
                                  iceTrqActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &tc_emlrtBCI, sp) - 1)) - 1] = iceTrqPreTn3->data
                [((emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &uc_emlrtBCI, sp)
                   + iceTrqPreTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                    (i7, 1, i6, &vc_emlrtBCI, sp) - 1)) + iceTrqPreTn3->size[0] *
                  iceTrqPreTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b
                   (engStaPreIdx_size_idx_1 + 1, 1, i8, &wc_emlrtBCI, sp) - 1))
                - 1];

              /*  brkTrq */
              i3 = brkTrqActTn3->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &kb_emlrtDCI, sp);
              ix = brkTrqActTn3->size[1];
              i = (int32_T)b_geaStaAct;
              npages = brkTrqActTn3->size[2];
              n = 1 + batStaActInx;
              i4 = brkTrqPreTn3->size[0];
              i5 = (int32_T)indx->data[indx->size[0] * ((int32_T)b_indx->
                data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] * indx->size
                [1] * engStaPreIdx_size_idx_1];
              i6 = brkTrqPreTn3->size[1];
              i7 = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
              i8 = brkTrqPreTn3->size[2];
              brkTrqActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &xc_emlrtBCI, sp) + brkTrqActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &yc_emlrtBCI, sp) - 1)) + brkTrqActTn3->size[0] *
                                  brkTrqActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &ad_emlrtBCI, sp) - 1)) - 1] = brkTrqPreTn3->data
                [((emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &bd_emlrtBCI, sp)
                   + brkTrqPreTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                    (i7, 1, i6, &cd_emlrtBCI, sp) - 1)) + brkTrqPreTn3->size[0] *
                  brkTrqPreTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b
                   (engStaPreIdx_size_idx_1 + 1, 1, i8, &dd_emlrtBCI, sp) - 1))
                - 1];

              /*  optimalen Vorgänger codieren über Funktion sub2ind */
              /*  und speichern im Tensor */
              /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
              st.site = &j_emlrtRSI;
              b_st.site = &lb_emlrtRSI;
              if ((indx->data[indx->size[0] * ((int32_T)b_indx->
                    data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] *
                   indx->size[1] * engStaPreIdx_size_idx_1] >= 1.0) && ((int32_T)
                   engNum >= (int32_T)indx->data[indx->size[0] * ((int32_T)
                    b_indx->data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] *
                   indx->size[1] * engStaPreIdx_size_idx_1])) {
                overflow = true;
              } else {
                overflow = false;
              }

              c_st.site = &mb_emlrtRSI;
              if (!overflow) {
                b_overflow = false;
              } else {
                b_overflow = true;
              }

              if (b_overflow) {
              } else {
                k_y = NULL;
                m0 = emlrtCreateCharArray(2, iv9);
                for (i = 0; i < 30; i++) {
                  cv6[i] = cv7[i];
                }

                emlrtInitCharArrayR2013a(&c_st, 30, m0, cv6);
                emlrtAssign(&k_y, m0);
                d_st.site = &qb_emlrtRSI;
                error(&d_st, message(&d_st, k_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              if ((b_indx->data[engStaPreIdx_size_idx_1] >= 1.0) && ((int32_T)
                   geaNum >= (int32_T)b_indx->data[engStaPreIdx_size_idx_1])) {
                overflow = true;
              } else {
                overflow = false;
              }

              c_st.site = &mb_emlrtRSI;
              if (!overflow) {
                c_overflow = false;
              } else {
                c_overflow = true;
              }

              if (c_overflow) {
              } else {
                l_y = NULL;
                m0 = emlrtCreateCharArray(2, iv10);
                for (i = 0; i < 30; i++) {
                  cv6[i] = cv7[i];
                }

                emlrtInitCharArrayR2013a(&c_st, 30, m0, cv6);
                emlrtAssign(&l_y, m0);
                d_st.site = &qb_emlrtRSI;
                error(&d_st, message(&d_st, l_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              c_st.site = &nb_emlrtRSI;
              d_st.site = &ob_emlrtRSI;
              if ((engStaPreIdx_size_idx_1 + 1 >= 1) && ((int32_T)batNum >=
                   engStaPreIdx_size_idx_1 + 1)) {
                overflow = true;
              } else {
                overflow = false;
              }

              c_st.site = &mb_emlrtRSI;
              if (!overflow) {
                d_overflow = false;
              } else {
                d_overflow = true;
              }

              if (d_overflow) {
              } else {
                m_y = NULL;
                m0 = emlrtCreateCharArray(2, iv11);
                for (i = 0; i < 30; i++) {
                  cv6[i] = cv7[i];
                }

                emlrtInitCharArrayR2013a(&c_st, 30, m0, cv6);
                emlrtAssign(&m_y, m0);
                d_st.site = &qb_emlrtRSI;
                error(&d_st, message(&d_st, m_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              i3 = optPreInxTn4->size[0];
              cindx = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &lb_emlrtDCI, sp);
              ix = optPreInxTn4->size[1];
              i = (int32_T)b_geaStaAct;
              npages = optPreInxTn4->size[2];
              n = 1 + batStaActInx;
              i4 = optPreInxTn4->size[3];
              i5 = (int32_T)b_timInx;
              optPreInxTn4->data[(((emlrtDynamicBoundsCheckFastR2012b(cindx, 1,
                i3, &ed_emlrtBCI, sp) + optPreInxTn4->size[0] *
                                    (emlrtDynamicBoundsCheckFastR2012b(i, 1, ix,
                &fd_emlrtBCI, sp) - 1)) + optPreInxTn4->size[0] *
                                   optPreInxTn4->size[1] *
                                   (emlrtDynamicBoundsCheckFastR2012b(n, 1,
                npages, &gd_emlrtBCI, sp) - 1)) + optPreInxTn4->size[0] *
                                  optPreInxTn4->size[1] * optPreInxTn4->size[2] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4,
                &hd_emlrtBCI, sp) - 1)) - 1] = ((int32_T)indx->data[indx->size[0]
                * ((int32_T)b_indx->data[engStaPreIdx_size_idx_1] - 1) +
                indx->size[0] * indx->size[1] * engStaPreIdx_size_idx_1] +
                (int32_T)engNum * ((int32_T)b_indx->data[engStaPreIdx_size_idx_1]
                                   - 1)) + (int32_T)engNum * (int32_T)geaNum *
                engStaPreIdx_size_idx_1;
            }

            /*  end of ~inf(hamiltonian) if-statement */
            batStaActInx++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }

          /* end of looping through all battery states */
          st.site = &k_emlrtRSI;
          h_fprintf(&st);
        }

        geaStaAct++;
        emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
      }

      /*  end of looping through all gears */
      engStaAct++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  end of looping through all the current engine control states */
    st.site = &l_emlrtRSI;
    j_fprintf(&st);

    /*  define new batEngPreInxVec for next time's batEngAct preliminary */
    /*  approximation */
    /*      batEngPreInxVec = batStaLimBot : batStaLimTop; */
    /*      % find bounds for approximating next time index's batEng bounds */
    /*      batStaIdxBounds = find(~isinf(min(min(cos2goActTn3)))); */
    /*      if length(batStaIdxBounds) < 1 */
    /*         fprintf('WARNING: batStaIdxBounds gone at time %i\n', timInx);  */
    /*      end */
    /*      batStaLimBot = min(batStaIdxBounds); */
    /*      batStaLimTop = max(batStaIdxBounds); */
    /*                   */
    /*  Speichern der Kosten für den nächsten Schleifendurchlauf */
    /*    save cost as previous path_idx value for the next loop */
    i1 = cos2goPreTn3->size[0] * cos2goPreTn3->size[1] * cos2goPreTn3->size[2];
    cos2goPreTn3->size[0] = cos2goActTn3->size[0];
    cos2goPreTn3->size[1] = cos2goActTn3->size[1];
    cos2goPreTn3->size[2] = cos2goActTn3->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)cos2goPreTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = cos2goActTn3->size[0] * cos2goActTn3->size[1] * cos2goActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      cos2goPreTn3->data[i1] = cos2goActTn3->data[i1];
    }

    /*  Speichern der Krafstoffenergie fï¿½r den nï¿½chsten Schleifendurchlauf */
    /*    save fuel energy value as previous path_idx value for the next loop */
    i1 = fulEngPreTn3->size[0] * fulEngPreTn3->size[1] * fulEngPreTn3->size[2];
    fulEngPreTn3->size[0] = fulEngActTn3->size[0];
    fulEngPreTn3->size[1] = fulEngActTn3->size[1];
    fulEngPreTn3->size[2] = fulEngActTn3->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)fulEngPreTn3, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = fulEngActTn3->size[0] * fulEngActTn3->size[1] * fulEngActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      fulEngPreTn3->data[i1] = fulEngActTn3->data[i1];
    }

    /*  optimale Kraftstoffenergie zum aktuellen Punkt */
    /*    optimal fuel energy at current point - save current mat in tensor */
    iy = fulEngOptTn4->size[0];
    i1 = r0->size[0];
    r0->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r0->data[i1] = i1;
    }

    iy = fulEngOptTn4->size[1];
    i1 = r1->size[0];
    r1->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r1->data[i1] = i1;
    }

    iy = fulEngOptTn4->size[2];
    i1 = r2->size[0];
    r2->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r2->data[i1] = i1;
    }

    i1 = fulEngOptTn4->size[3];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &d_emlrtBCI, sp);
    iv12[0] = r0->size[0];
    iv12[1] = r1->size[0];
    iv12[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv12, 3, *(int32_T (*)[3])fulEngActTn3->size,
      3, &d_emlrtECI, sp);
    iy = fulEngActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      b_ix = fulEngActTn3->size[1];
      for (i2 = 0; i2 < b_ix; i2++) {
        nm1d2 = fulEngActTn3->size[0];
        for (i3 = 0; i3 < nm1d2; i3++) {
          fulEngOptTn4->data[((r0->data[i3] + fulEngOptTn4->size[0] * r1->
                               data[i2]) + fulEngOptTn4->size[0] *
                              fulEngOptTn4->size[1] * r2->data[i1]) +
            fulEngOptTn4->size[0] * fulEngOptTn4->size[1] * fulEngOptTn4->size[2]
            * ((int32_T)b_timInx - 1)] = fulEngActTn3->data[(i3 +
            fulEngActTn3->size[0] * i2) + fulEngActTn3->size[0] *
            fulEngActTn3->size[1] * i1];
        }
      }
    }

    /*  optimale Batterieenergie zum aktuellen Punkt */
    /*    optimal battery force at current point - save current mat in tensor */
    /*  Flussgröße gilt im Intervall */
    /*    flux quantity applied over the interval */
    iy = batPwrOptTn4->size[0];
    i1 = r0->size[0];
    r0->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r0->data[i1] = i1;
    }

    iy = batPwrOptTn4->size[1];
    i1 = r1->size[0];
    r1->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r1->data[i1] = i1;
    }

    iy = batPwrOptTn4->size[2];
    i1 = r2->size[0];
    r2->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r2->data[i1] = i1;
    }

    i1 = batPwrOptTn4->size[3];
    i2 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &i_emlrtBCI, sp);
    iv13[0] = r0->size[0];
    iv13[1] = r1->size[0];
    iv13[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv13, 3, *(int32_T (*)[3])batPwrOptTn3->size,
      3, &e_emlrtECI, sp);
    iy = batPwrOptTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      b_ix = batPwrOptTn3->size[1];
      for (i2 = 0; i2 < b_ix; i2++) {
        nm1d2 = batPwrOptTn3->size[0];
        for (i3 = 0; i3 < nm1d2; i3++) {
          batPwrOptTn4->data[((r0->data[i3] + batPwrOptTn4->size[0] * r1->
                               data[i2]) + batPwrOptTn4->size[0] *
                              batPwrOptTn4->size[1] * r2->data[i1]) +
            batPwrOptTn4->size[0] * batPwrOptTn4->size[1] * batPwrOptTn4->size[2]
            * ((int32_T)b_timInx - 2)] = batPwrOptTn3->data[(i3 +
            batPwrOptTn3->size[0] * i2) + batPwrOptTn3->size[0] *
            batPwrOptTn3->size[1] * i1];
        }
      }
    }

    /*  save optimal torque tensors for each time interval */
    /*  emoTrq */
    iy = emoTrqOptTn4->size[0];
    i1 = r0->size[0];
    r0->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r0->data[i1] = i1;
    }

    iy = emoTrqOptTn4->size[1];
    i1 = r1->size[0];
    r1->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r1->data[i1] = i1;
    }

    iy = emoTrqOptTn4->size[2];
    i1 = r2->size[0];
    r2->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r2->data[i1] = i1;
    }

    i1 = emoTrqOptTn4->size[3];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &c_emlrtBCI, sp);
    iv14[0] = r0->size[0];
    iv14[1] = r1->size[0];
    iv14[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv14, 3, *(int32_T (*)[3])emoTrqActTn3->size,
      3, &c_emlrtECI, sp);
    iy = emoTrqActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      b_ix = emoTrqActTn3->size[1];
      for (i2 = 0; i2 < b_ix; i2++) {
        nm1d2 = emoTrqActTn3->size[0];
        for (i3 = 0; i3 < nm1d2; i3++) {
          emoTrqOptTn4->data[((r0->data[i3] + emoTrqOptTn4->size[0] * r1->
                               data[i2]) + emoTrqOptTn4->size[0] *
                              emoTrqOptTn4->size[1] * r2->data[i1]) +
            emoTrqOptTn4->size[0] * emoTrqOptTn4->size[1] * emoTrqOptTn4->size[2]
            * ((int32_T)b_timInx - 1)] = emoTrqActTn3->data[(i3 +
            emoTrqActTn3->size[0] * i2) + emoTrqActTn3->size[0] *
            emoTrqActTn3->size[1] * i1];
        }
      }
    }

    /*  iceTrq */
    iy = iceTrqOptTn4->size[0];
    i1 = r0->size[0];
    r0->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r0->data[i1] = i1;
    }

    iy = iceTrqOptTn4->size[1];
    i1 = r1->size[0];
    r1->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r1->data[i1] = i1;
    }

    iy = iceTrqOptTn4->size[2];
    i1 = r2->size[0];
    r2->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r2->data[i1] = i1;
    }

    i1 = iceTrqOptTn4->size[3];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &b_emlrtBCI, sp);
    iv15[0] = r0->size[0];
    iv15[1] = r1->size[0];
    iv15[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv15, 3, *(int32_T (*)[3])iceTrqActTn3->size,
      3, &b_emlrtECI, sp);
    iy = iceTrqActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      b_ix = iceTrqActTn3->size[1];
      for (i2 = 0; i2 < b_ix; i2++) {
        nm1d2 = iceTrqActTn3->size[0];
        for (i3 = 0; i3 < nm1d2; i3++) {
          iceTrqOptTn4->data[((r0->data[i3] + iceTrqOptTn4->size[0] * r1->
                               data[i2]) + iceTrqOptTn4->size[0] *
                              iceTrqOptTn4->size[1] * r2->data[i1]) +
            iceTrqOptTn4->size[0] * iceTrqOptTn4->size[1] * iceTrqOptTn4->size[2]
            * ((int32_T)b_timInx - 1)] = iceTrqActTn3->data[(i3 +
            iceTrqActTn3->size[0] * i2) + iceTrqActTn3->size[0] *
            iceTrqActTn3->size[1] * i1];
        }
      }
    }

    /*  brkTrq */
    iy = brkTrqOptTn4->size[0];
    i1 = r0->size[0];
    r0->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r0->data[i1] = i1;
    }

    iy = brkTrqOptTn4->size[1];
    i1 = r1->size[0];
    r1->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r1->data[i1] = i1;
    }

    iy = brkTrqOptTn4->size[2];
    i1 = r2->size[0];
    r2->size[0] = iy;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < iy; i1++) {
      r2->data[i1] = i1;
    }

    i1 = brkTrqOptTn4->size[3];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, sp);
    iv16[0] = r0->size[0];
    iv16[1] = r1->size[0];
    iv16[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv16, 3, *(int32_T (*)[3])brkTrqActTn3->size,
      3, &emlrtECI, sp);
    iy = brkTrqActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      b_ix = brkTrqActTn3->size[1];
      for (i2 = 0; i2 < b_ix; i2++) {
        nm1d2 = brkTrqActTn3->size[0];
        for (i3 = 0; i3 < nm1d2; i3++) {
          brkTrqOptTn4->data[((r0->data[i3] + brkTrqOptTn4->size[0] * r1->
                               data[i2]) + brkTrqOptTn4->size[0] *
                              brkTrqOptTn4->size[1] * r2->data[i1]) +
            brkTrqOptTn4->size[0] * brkTrqOptTn4->size[1] * brkTrqOptTn4->size[2]
            * ((int32_T)b_timInx - 1)] = brkTrqActTn3->data[(i3 +
            brkTrqActTn3->size[0] * i2) + brkTrqActTn3->size[0] *
            brkTrqActTn3->size[1] * i1];
        }
      }
    }

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (inputparams->disFlg != 0.0) {
      st.site = &m_emlrtRSI;
      l_fprintf(&st, b_timInx - inputparams->timInxBeg, (b_timInx -
                 inputparams->timInxBeg) / (inputparams->timInxEnd -
                 inputparams->timInxBeg) * 100.0);
    }

    timInx++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_int32_T(&b_iindx);
  emxFree_real_T(&b_extremum);
  emxFree_real_T(&b_indx);
  emxFree_int32_T(&iindx);
  emxFree_real_T(&extremum);
  emxFree_real_T(&indx);
  emxFree_real_T(&b_y);
  emxFree_int32_T(&r2);
  emxFree_int32_T(&r1);
  emxFree_int32_T(&r0);
  emxFree_real_T(&batStaPreIdxVec);
  emxFree_real_T(&brkTrqPreTn3);
  emxFree_real_T(&iceTrqPreTn3);
  emxFree_real_T(&emoTrqPreTn3);
  emxFree_real_T(&fulActTn3);
  emxFree_real_T(&brkTrqActTn3);
  emxFree_real_T(&iceTrqActTn3);
  emxFree_real_T(&emoTrqActTn3);
  emxFree_real_T(&fulEngActTn3);
  emxFree_real_T(&batEngActTn3);
  emxFree_real_T(&batPwrOptTn3);
  emxFree_real_T(&batStaActInxVec);
  emxFree_real_T(&fulEngPreTn3);
  emxFree_real_T(&cos2goPreTn3);

  /*  end of looping through all discretized path indexes */
  /*  END OF FUNCTION */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void crsSpdHybMax_not_empty_init(void)
{
}

void crsSpdHybMin_not_empty_init(void)
{
}

void engNum_not_empty_init(void)
{
}

void engStaMax_not_empty_init(void)
{
}

void engStaMin_not_empty_init(void)
{
}

void geaNum_not_empty_init(void)
{
  geaNum_not_empty = false;
}

void geaStaMax_not_empty_init(void)
{
}

void geaStaMin_not_empty_init(void)
{
}

void iceFlg_not_empty_init(void)
{
}

/* End of code generation (clcDP_focus.c) */
