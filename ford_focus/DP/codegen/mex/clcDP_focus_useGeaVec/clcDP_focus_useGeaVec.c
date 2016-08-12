/*
 * clcDP_focus_useGeaVec.c
 *
 * Code generation for function 'clcDP_focus_useGeaVec'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus_useGeaVec.h"
#include "clcDP_focus_useGeaVec_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "optTrqSplit_focus.h"
#include "fprintf.h"
#include "clcDP_focus_useGeaVec_mexutil.h"
#include "clcDP_focus_useGeaVec_data.h"
#include <stdio.h>

/* Variable Definitions */
static real_T engNum;
static boolean_T engNum_not_empty;
static real_T engStaMin;
static real_T engStaMax;
static real_T iceFlg;
static real_T batStaMin;
static real_T batStaStp;
static real_T batStaMax;
static real_T batNum;
static emlrtRSInfo emlrtRSI = { 219, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo b_emlrtRSI = { 283, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo c_emlrtRSI = { 284, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo d_emlrtRSI = { 436, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo e_emlrtRSI = { 546, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo f_emlrtRSI = { 628, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo g_emlrtRSI = { 629, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo h_emlrtRSI = { 683, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo i_emlrtRSI = { 688, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo j_emlrtRSI = { 690, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo k_emlrtRSI = { 727, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRSInfo l_emlrtRSI = { 21, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo m_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo n_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo o_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo p_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo q_emlrtRSI = { 16, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo r_emlrtRSI = { 18, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo s_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo t_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo u_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo v_emlrtRSI = { 16, "max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"
};

static emlrtRSInfo eb_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo fb_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo gb_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo hb_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ib_emlrtRSI = { 16, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo jb_emlrtRSI = { 41, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo kb_emlrtRSI = { 39, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo lb_emlrtRSI = { 71, "sub2ind",
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

static emlrtRTEInfo emlrtRTEI = { 10, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 284, 1, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo c_emlrtRTEI = { 91, 1, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 193, 1, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 210, 1, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 219, 1, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 241, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 251, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 256, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 259, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 260, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 261, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 353, 13, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 356, 13, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 357, 13, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 358, 13, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 436, 13, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtECInfo emlrtECI = { -1, 723, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 723, 22, "brkTrqOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 722, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 722, 22, "iceTrqOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 721, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 721, 22, "emoTrqOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 714, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 714, 22, "fulEngOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 174, 54, "fulEngOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo emlrtDCI = { 174, 54, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 174, 36, "fulEngOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 174, 36, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 174, 14, "fulEngOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 174, 14, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtECInfo e_emlrtECI = { -1, 719, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo h_emlrtBCI = { -1, -1, 719, 22, "batPwrOptTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 619, 42, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 619, 42, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 613, 34, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 613, 34, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 647, 46, "fulEngPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 647, 30, "fulEngPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 213, 36, "fulEngPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 213, 36, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 213, 14, "fulEngPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 213, 14, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 631, 35, "colminidx",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 607, 31, "fulActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 607, 31, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 617, 37, "batStaActInxVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 609, 40, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 609, 40, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 198, 36, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 198, 36, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 198, 14, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 198, 14, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo u_emlrtBCI = { 1, 693, 539, 37, "batOcv",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 539, 37, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 522, 40, "batStaPreIdxVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { 1, 1181, 485, 52, "iceTrqMaxPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { 1, 1181, 484, 52, "iceTrqMinPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { 1, 1181, 479, 48, "emoPwrMaxPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { 1, 1181, 478, 48, "emoPwrMinPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { 1, 1181, 475, 48, "emoTrqMaxPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { 1, 1181, 474, 48, "emoTrqMinPosMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { 1, 1181, 472, 39, "crsTrqMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { 1, 6, 471, 49, "crsSpdMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 471, 49, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo fb_emlrtBCI = { 1, 1181, 471, 39, "crsSpdMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { 1, 1181, 402, 69, "batPwrMaxIdxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { 1, 693, 401, 79, "batPwrMinIdxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { 1, 1181, 401, 69, "batPwrMinIdxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { 1, 6, 332, 17, "crsSpdActVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 332, 17, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo kb_emlrtBCI = { 1, 6, 319, 17, "crsSpdActVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 319, 17, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtRTEInfo s_emlrtRTEI = { 309, 5, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtBCInfo lb_emlrtBCI = { 1, 1181, 284, 75, "batPwrMaxIdxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { 1, 1181, 283, 75, "batPwrMinIdxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { 1, 1181, 274, 30, "crsSpdMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { 1, 1181, 264, 20, "engStaVec_timInx",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 264, 20, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtRTEInfo t_emlrtRTEI = { 228, 1, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m"
};

static emlrtDCInfo q_emlrtDCI = { 164, 22, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtDCInfo r_emlrtDCI = { 164, 22, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  4 };

static emlrtDCInfo s_emlrtDCI = { 164, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtDCInfo t_emlrtDCI = { 164, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  4 };

static emlrtDCInfo u_emlrtDCI = { 164, 38, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtDCInfo v_emlrtDCI = { 164, 38, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  4 };

static emlrtBCInfo pb_emlrtBCI = { 1, 1181, 269, 18, "velVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo w_emlrtDCI = { 269, 18, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo qb_emlrtBCI = { 1, 1181, 269, 35, "velVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo x_emlrtDCI = { 269, 35, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo rb_emlrtBCI = { 1, 492477, 304, 17, "geaStaVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 348, 25, "batStaActInxVec",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 651, 30, "cos2goActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo y_emlrtDCI = { 651, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 651, 42, "cos2goActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 655, 30, "batEngActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo ab_emlrtDCI = { 655, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 655, 42, "batEngActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 659, 30, "fulEngActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo bb_emlrtDCI = { 659, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 659, 42, "fulEngActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 665, 30, "batPwrActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 665, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 665, 42, "batPwrActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 670, 30, "emoTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 670, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 670, 42, "emoTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 671, 34, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 671, 51, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 673, 30, "iceTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 673, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 673, 42, "iceTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 674, 34, "iceTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 674, 51, "iceTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 676, 30, "brkTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 676, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 676, 42, "brkTrqActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 677, 34, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 677, 51, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 682, 30, "optPreInxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 682, 30, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 682, 42, "optPreInxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 682, 55, "optPreInxTn3",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 442, 29, "engStaPreIdx",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 607, 44, "fulActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 607, 44, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 609, 53, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 609, 53, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 613, 47, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 619, 55, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 572, 35, "fulActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 572, 35, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 572, 47, "fulActMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 574, 44, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 574, 44, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 574, 57, "cos2goPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 578, 38, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo lb_emlrtDCI = { 578, 38, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 578, 51, "emoTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 579, 38, "iceTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 579, 38, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 579, 51, "iceTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 580, 38, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 580, 38, "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  1 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 580, 51, "brkTrqPreMat",
  "clcDP_focus_useGeaVec",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus_useGeaVec.m",
  0 };

static emlrtRSInfo nb_emlrtRSI = { 28, "assert",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\assert.m"
};

static emlrtRSInfo ob_emlrtRSI = { 81, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo pb_emlrtRSI = { 38, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo qb_emlrtRSI = { 404, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo tb_emlrtRSI = { 82, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ub_emlrtRSI = { 41, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo vb_emlrtRSI = { 405, "colon",
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

void clcDP_focus_useGeaVec(const emlrtStack *sp, real_T batEngBeg, real_T timNum,
  const real_T engStaVec_timInx[1181], const real_T batOcv[693], const real_T
  velVec[1181], const real_T geaStaVec[492477], const real_T crsSpdMat[7086],
  const real_T crsTrqMat[7086], const real_T emoTrqMinPosMat[7086], const real_T
  emoTrqMaxPosMat[7086], const real_T emoPwrMinPosMat[7086], const real_T
  emoPwrMaxPosMat[7086], const real_T iceTrqMinPosMat[7086], const real_T
  iceTrqMaxPosMat[7086], const real_T batPwrMinIdxTn3[4910598], const real_T
  batPwrMaxIdxTn3[4910598], const real_T batPwrDemIdxTn3[4910598], const
  struct0_T *inputparams, const struct1_T *tst_scalar_struct, const struct2_T
  *fzg_scalar_struct, const struct3_T *fzg_array_struct, emxArray_real_T
  *optPreInxTn3, emxArray_real_T *batPwrOptTn3, emxArray_real_T *fulEngOptTn3,
  emxArray_real_T *emoTrqOptTn3, emxArray_real_T *iceTrqOptTn3, emxArray_real_T *
  brkTrqOptTn3, emxArray_real_T *cos2goActMat)
{
  real_T crsSpdEmoMax;
  real_T crsSpdHybMax;
  real_T crsSpdHybMin;
  int32_T i0;
  real_T ndbl;
  real_T batEngInxBeg;
  real_T batStaLimMax;
  int32_T ix;
  int32_T i1;
  int32_T i2;
  int32_T ixstop;
  int32_T cindx;
  int32_T b_ix;
  emxArray_real_T *cos2goPreMat;
  emxArray_real_T *fulEngPreMat;
  int32_T n;
  real_T batStaPreIdx_noEmo;
  real_T apnd;
  boolean_T overflow;
  real_T cdiff;
  real_T absa;
  real_T absb;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 21 };

  const mxArray *m0;
  char_T cv0[21];
  int32_T i;
  static const char_T cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *batStaActInxVec;
  int32_T nm1d2;
  int32_T timInx;
  emxArray_real_T *batPwrActMat;
  emxArray_real_T *batEngActMat;
  emxArray_real_T *fulEngActMat;
  emxArray_real_T *emoTrqActMat;
  emxArray_real_T *iceTrqActMat;
  emxArray_real_T *brkTrqActMat;
  emxArray_real_T *fulActMat;
  emxArray_real_T *emoTrqPreMat;
  emxArray_real_T *iceTrqPreMat;
  emxArray_real_T *brkTrqPreMat;
  emxArray_real_T *batStaPreIdxVec;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  emxArray_real_T *indx;
  emxArray_int32_T *iindx;
  real_T b_timInx;
  real_T vehVelVec[2];
  int32_T ixstart;
  boolean_T c_ix;
  boolean_T exitg4;
  boolean_T b_ixstart;
  boolean_T d_ix;
  boolean_T exitg3;
  boolean_T c_ixstart;
  real_T geaStaAct;
  real_T geaStaPre;
  real_T b_engStaMin;
  int32_T engStaAct;
  real_T b_engStaAct;
  boolean_T guard1 = false;
  int32_T batStaActInx;
  real_T batStaAct;
  int32_T engStaPreIdx_size_idx_1;
  real_T engStaPreIdx_data[2];
  real_T dv0[2];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 21 };

  int32_T i3;
  const mxArray *c_y;
  static const int32_T iv2[2] = { 1, 36 };

  char_T cv2[36];
  static const char_T cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *d_y;
  static const int32_T iv3[2] = { 1, 39 };

  char_T cv4[39];
  static const char_T cv5[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  uint32_T outsz[2];
  uint32_T b_outsz;
  boolean_T e_ix;
  boolean_T exitg2;
  boolean_T d_ixstart;
  const mxArray *e_y;
  static const int32_T iv4[2] = { 1, 36 };

  const mxArray *f_y;
  static const int32_T iv5[2] = { 1, 39 };

  boolean_T exitg1;
  boolean_T b_overflow;
  const mxArray *g_y;
  static const int32_T iv6[2] = { 1, 30 };

  char_T cv6[30];
  static const char_T cv7[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O',
    'f', 'R', 'a', 'n', 'g', 'e' };

  boolean_T c_overflow;
  const mxArray *h_y;
  static const int32_T iv7[2] = { 1, 30 };

  int32_T iv8[2];
  int32_T iv9[2];
  int32_T iv10[2];
  int32_T iv11[2];
  int32_T iv12[2];
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

  /*   --- Ausgangsgrößen: */
  /*  Tensor 3. Stufe für opt. Vorgï¿½ngerkoordinaten */
  /*  Tensor 3. Stufe der Batteriekraft */
  /*  Tensor 3. Stufe für die Kraftstoffenergie */
  /*  tensor - saves optimal emoTrq values */
  /*  tensor - saves optimal iceTrq values */
  /*  tensor - saves optimal brkTrq values */
  /*  Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  --- Eingangsgrößen: */
  /*  Skalar für die Batterieenergie am Beginn in Ws */
  /*  Skalar für die Stufe der Batteriekraftmax. Anzahl an Wegstützstellen */
  /*  scalar - end engine state */
  /*  battery voltage vector w/ value for each SOC */
  /*  velocity vector contiaing input speed profile */
  /*  gear state input vector */
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
  /*  struct w/ input model parameters */
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
  /*    optimal battery energy and gear states for optimal path. */
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
  /*  bestimmt. Das fährt zu einem anderen Schaltverhalten, da Gänge teilweise */
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
  if (!engNum_not_empty) {
    /*      geaNum    = zeros(1,1); */
    /*      vehMas    = zeros(1,1); */
    /*      vehAccMin = zeros(1,1); */
    /*      vehAccMax = zeros(1,1); */
    /*  number of engine states possible (0 = OFF; 1 = ON); */
    engNum = tst_scalar_struct->engStaNum;
    engNum_not_empty = true;
    engStaMin = tst_scalar_struct->engStaMin;
    engStaMax = tst_scalar_struct->engStaMax;

    /*  Anzahl der GÃ¤nge */
    /*    number of gears */
    /*      geaNum      = tst_scalar_struct.staNum; % max number of state nodes */
    /*      geaStaMin   = tst_scalar_struct.geaStaMin; */
    /*      geaStaMax   = tst_scalar_struct.geaStaMax; */
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
  /*    - doesn't work like that - the crankshaft can turn only as fast as the */
  /*    slowest machine can support. If it matches the higher boundary, the */
  /*    other machine cannot physically support and may fail */
  crsSpdHybMax = muDoubleScalarMin(fzg_array_struct->iceSpdMgd[34],
    fzg_array_struct->emoSpdMgd[72]);

  /*  minimale Drehzahl der Kurbelwelle */
  /*    minimum crankshaft rotational speed */
  crsSpdHybMin = fzg_array_struct->iceSpdMgd[0];

  /* % Initialisieren der Ausgabe der Funktion */
  /*    initialzing function output */
  /*  Tensor 3. Stufe für optimalen VorgÃ¤ngerkoordinaten */
  /*    tensor3 for optimal previous coordinates/idx */
  /*  IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION */
  /*    - back to being a tensor - adding engine control dimension */
  i0 = optPreInxTn3->size[0] * optPreInxTn3->size[1] * optPreInxTn3->size[2];
  ndbl = emlrtNonNegativeCheckFastR2012b(engNum, &r_emlrtDCI, sp);
  optPreInxTn3->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &q_emlrtDCI,
    sp);
  ndbl = emlrtNonNegativeCheckFastR2012b(batNum, &t_emlrtDCI, sp);
  optPreInxTn3->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &s_emlrtDCI,
    sp);
  ndbl = emlrtNonNegativeCheckFastR2012b(timNum, &v_emlrtDCI, sp);
  optPreInxTn3->size[2] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &u_emlrtDCI,
    sp);
  emxEnsureCapacity(sp, (emxArray__common *)optPreInxTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ndbl = emlrtNonNegativeCheckFastR2012b(engNum, &r_emlrtDCI, sp);
  batEngInxBeg = emlrtNonNegativeCheckFastR2012b(batNum, &t_emlrtDCI, sp);
  batStaLimMax = emlrtNonNegativeCheckFastR2012b(timNum, &v_emlrtDCI, sp);
  ix = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &q_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batEngInxBeg, &s_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batStaLimMax, &u_emlrtDCI, sp);
  for (i0 = 0; i0 < ix; i0++) {
    optPreInxTn3->data[i0] = 0.0;
  }

  /*  Tensor 3. Stufe fï¿½r die Kraftstoffenergie */
  /*    tensor3 for fuel energy - now Tn4 */
  i0 = fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * fulEngOptTn3->size[2];
  fulEngOptTn3->size[0] = (int32_T)engNum;
  fulEngOptTn3->size[1] = (int32_T)batNum;
  fulEngOptTn3->size[2] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < ix; i0++) {
    fulEngOptTn3->data[i0] = rtInf;
  }

  /*    set initial fuel energy level to 0 */
  /*    Note: batEngIdxBeg is a scaled down energy value index, NOT a vector */
  /*    index. Keep this in mind later when manipulating batEng index bounds. */
  batEngInxBeg = batEngBeg / batStaStp;
  i0 = (int32_T)timNum;
  ndbl = inputparams->timInxBeg;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &emlrtDCI, sp);
  i2 = (int32_T)batNum;
  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &b_emlrtDCI,
    sp);
  cindx = (int32_T)engNum;
  ndbl = inputparams->engBeg + 1.0;
  b_ix = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &c_emlrtDCI, sp);
  fulEngOptTn3->data[((emlrtDynamicBoundsCheckFastR2012b(b_ix, 1, cindx,
    &g_emlrtBCI, sp) + fulEngOptTn3->size[0] *
                       (emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
    &f_emlrtBCI, sp) - 1)) + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &e_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  Tensor 3. Stufe für die Batterienergie */
  /*    tensor3 for battery energy - now Tn4 */
  i0 = batPwrOptTn3->size[0] * batPwrOptTn3->size[1] * batPwrOptTn3->size[2];
  batPwrOptTn3->size[0] = (int32_T)engNum;
  batPwrOptTn3->size[1] = (int32_T)batNum;
  batPwrOptTn3->size[2] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)batPwrOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < ix; i0++) {
    batPwrOptTn3->data[i0] = rtInf;
  }

  /*  tensors for storing optimal torque values for all time indexes */
  i0 = emoTrqOptTn3->size[0] * emoTrqOptTn3->size[1] * emoTrqOptTn3->size[2];
  emoTrqOptTn3->size[0] = (int32_T)engNum;
  emoTrqOptTn3->size[1] = (int32_T)batNum;
  emoTrqOptTn3->size[2] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)emoTrqOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < ix; i0++) {
    emoTrqOptTn3->data[i0] = 0.0;
  }

  i0 = iceTrqOptTn3->size[0] * iceTrqOptTn3->size[1] * iceTrqOptTn3->size[2];
  iceTrqOptTn3->size[0] = (int32_T)engNum;
  iceTrqOptTn3->size[1] = (int32_T)batNum;
  iceTrqOptTn3->size[2] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)iceTrqOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < ix; i0++) {
    iceTrqOptTn3->data[i0] = 0.0;
  }

  i0 = brkTrqOptTn3->size[0] * brkTrqOptTn3->size[1] * brkTrqOptTn3->size[2];
  brkTrqOptTn3->size[0] = (int32_T)engNum;
  brkTrqOptTn3->size[1] = (int32_T)batNum;
  brkTrqOptTn3->size[2] = (int32_T)timNum;
  emxEnsureCapacity(sp, (emxArray__common *)brkTrqOptTn3, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum * (int32_T)timNum;
  for (i0 = 0; i0 < ix; i0++) {
    brkTrqOptTn3->data[i0] = 0.0;
  }

  emxInit_real_T(sp, &cos2goPreMat, 2, &d_emlrtRTEI, true);

  /* % Berechnung der optimalen Vorgäger */
  /*    calculating the optimal predecessors */
  /*  Initialisieren der Matrix für die Kosten bis zu den Punkten im letzten */
  /*  Wegschritt */
  /*    initialize the matrix for the cost to the points in the last wayidx */
  /*  NOW A VECTOR - REMOVED KE DIMENSION */
  /*  not anymore - added engine contorl dimension */
  i0 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
  cos2goPreMat->size[0] = (int32_T)engNum;
  cos2goPreMat->size[1] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum;
  for (i0 = 0; i0 < ix; i0++) {
    cos2goPreMat->data[i0] = rtInf;
  }

  i0 = cos2goActMat->size[0] * cos2goActMat->size[1];
  cos2goActMat->size[0] = (int32_T)engNum;
  cos2goActMat->size[1] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum;
  for (i0 = 0; i0 < ix; i0++) {
    cos2goActMat->data[i0] = rtInf;
  }

  emxInit_real_T(sp, &fulEngPreMat, 2, &e_emlrtRTEI, true);

  /*  Erste Initilisierung beim Startindex mit 0 für alle Zustände (concluded) */
  /*    first, initialize the startidx to 0 for all states */
  i0 = (int32_T)batNum;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &j_emlrtDCI, sp);
  i2 = (int32_T)engNum;
  ndbl = inputparams->engBeg + 1.0;
  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &k_emlrtDCI, sp);
  cos2goPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
    &t_emlrtBCI, sp) + cos2goPreMat->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &s_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  Initialisierung der Matrix der Batterieenergien */
  /*    initialize the battery energy matrix */
  /*  batEngPreTn3 = inf(engNum, geaNum, batNum); */
  /*  Erste Initilisierung beim Startindex mit Startladung für den Startzustand */
  /*    first, intialize start index of the starting charge for intial state */
  /*  batEngPreTn3(engBeg+1, staBeg, batEngIdxBeg) = batEngBeg; */
  /*  Initialisierung der Matrix der Kraftstoffenergien */
  /*    initialze the fuel energy matrix */
  i0 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
  fulEngPreMat->size[0] = (int32_T)engNum;
  fulEngPreMat->size[1] = (int32_T)batNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ix = (int32_T)engNum * (int32_T)batNum;
  for (i0 = 0; i0 < ix; i0++) {
    fulEngPreMat->data[i0] = rtInf;
  }

  /*  Erste Initilisierung beim Startindex mit 0 fï¿½r den Startzustand */
  /*    first, intialize the start idx for the intitial states to 0 */
  i0 = (int32_T)batNum;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngInxBeg + 1.0, &f_emlrtDCI, sp);
  i2 = (int32_T)engNum;
  ndbl = inputparams->engBeg + 1.0;
  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &g_emlrtDCI, sp);
  fulEngPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
    &n_emlrtBCI, sp) + fulEngPreMat->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &m_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  define a vector for containing the values of engine control off-on */
  /*  engStaMat_geaNum_timInx = zeros(1, timInxEnd); */
  /*  define battery vector to be used for looping */
  batEngInxBeg = batStaMin / batStaStp;
  batStaLimMax = batStaMax / batStaStp;
  st.site = &emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (muDoubleScalarIsNaN(batEngInxBeg) || muDoubleScalarIsNaN(batStaLimMax)) {
    n = 0;
    batStaPreIdx_noEmo = rtNaN;
    apnd = batStaLimMax;
    overflow = false;
  } else if (batStaLimMax < batEngInxBeg) {
    n = -1;
    batStaPreIdx_noEmo = batEngInxBeg;
    apnd = batStaLimMax;
    overflow = false;
  } else if (muDoubleScalarIsInf(batEngInxBeg) || muDoubleScalarIsInf
             (batStaLimMax)) {
    n = 0;
    batStaPreIdx_noEmo = rtNaN;
    apnd = batStaLimMax;
    overflow = !(batEngInxBeg == batStaLimMax);
  } else {
    batStaPreIdx_noEmo = batEngInxBeg;
    ndbl = muDoubleScalarFloor((batStaLimMax - batEngInxBeg) + 0.5);
    apnd = batEngInxBeg + ndbl;
    cdiff = apnd - batStaLimMax;
    absa = muDoubleScalarAbs(batEngInxBeg);
    absb = muDoubleScalarAbs(batStaLimMax);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (absa, absb)) {
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

  d_st.site = &n_emlrtRSI;
  if (!overflow) {
  } else {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i = 0; i < 21; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
    emlrtAssign(&y, m0);
    e_st.site = &qb_emlrtRSI;
    f_st.site = &vb_emlrtRSI;
    error(&e_st, message(&f_st, y, &emlrtMCI), &b_emlrtMCI);
  }

  emxInit_real_T(&d_st, &batStaActInxVec, 2, &f_emlrtRTEI, true);
  i0 = batStaActInxVec->size[0] * batStaActInxVec->size[1];
  batStaActInxVec->size[0] = 1;
  batStaActInxVec->size[1] = n + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)batStaActInxVec, i0, (int32_T)
                    sizeof(real_T), &b_emlrtRTEI);
  if (n + 1 > 0) {
    batStaActInxVec->data[0] = batStaPreIdx_noEmo;
    if (n + 1 > 1) {
      batStaActInxVec->data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        nm1d2 = (int32_T)((uint32_T)i0 >> 1);
      } else {
        nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
      }

      d_st.site = &o_emlrtRSI;
      for (ix = 1; ix < nm1d2; ix++) {
        batStaActInxVec->data[ix] = batStaPreIdx_noEmo + (real_T)ix;
        batStaActInxVec->data[n - ix] = apnd - (real_T)ix;
      }

      if (nm1d2 << 1 == n) {
        batStaActInxVec->data[nm1d2] = (batStaPreIdx_noEmo + apnd) / 2.0;
      } else {
        batStaActInxVec->data[nm1d2] = batStaPreIdx_noEmo + (real_T)nm1d2;
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
    &t_emlrtRTEI, sp);
  timInx = 0;
  emxInit_real_T(sp, &batPwrActMat, 2, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &batEngActMat, 2, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngActMat, 2, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &emoTrqActMat, 2, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &iceTrqActMat, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &brkTrqActMat, 2, &l_emlrtRTEI, true);
  emxInit_real_T(sp, &fulActMat, 2, &m_emlrtRTEI, true);
  emxInit_real_T(sp, &emoTrqPreMat, 2, &n_emlrtRTEI, true);
  emxInit_real_T(sp, &iceTrqPreMat, 2, &o_emlrtRTEI, true);
  emxInit_real_T(sp, &brkTrqPreMat, 2, &p_emlrtRTEI, true);
  emxInit_real_T(sp, &batStaPreIdxVec, 2, &q_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &indx, 2, &emlrtRTEI, true);
  b_emxInit_int32_T(sp, &iindx, 2, &emlrtRTEI, true);
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
    i1 = batPwrActMat->size[0] * batPwrActMat->size[1];
    batPwrActMat->size[0] = (int32_T)engNum;
    batPwrActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)batPwrActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      batPwrActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fï¿½r die Kosten bis zu den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize cost matrix to points in current path steps (idxs?) */
    i1 = cos2goActMat->size[0] * cos2goActMat->size[1];
    cos2goActMat->size[0] = (int32_T)engNum;
    cos2goActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)cos2goActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      cos2goActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fÃ¼r die Batterieenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for battery energy at points along current wayidx */
    i1 = batEngActMat->size[0] * batEngActMat->size[1];
    batEngActMat->size[0] = (int32_T)engNum;
    batEngActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)batEngActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      batEngActMat->data[i1] = rtInf;
    }

    /*  Initialisieren der Matrix fÃ¼r die Krafstoffenergie an den Punkten im */
    /*  aktuellen Wegschritt */
    /*    initialize matrix for fuel energie along current way idxs */
    i1 = fulEngActMat->size[0] * fulEngActMat->size[1];
    fulEngActMat->size[0] = (int32_T)engNum;
    fulEngActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)fulEngActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      fulEngActMat->data[i1] = rtInf;
    }

    /*  intialize matrix for saving a time interval's optimal torque values */
    i1 = emoTrqActMat->size[0] * emoTrqActMat->size[1];
    emoTrqActMat->size[0] = (int32_T)engNum;
    emoTrqActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)emoTrqActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      emoTrqActMat->data[i1] = rtInf;
    }

    i1 = iceTrqActMat->size[0] * iceTrqActMat->size[1];
    iceTrqActMat->size[0] = (int32_T)engNum;
    iceTrqActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)iceTrqActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      iceTrqActMat->data[i1] = rtInf;
    }

    i1 = brkTrqActMat->size[0] * brkTrqActMat->size[1];
    brkTrqActMat->size[0] = (int32_T)engNum;
    brkTrqActMat->size[1] = (int32_T)batNum;
    emxEnsureCapacity(sp, (emxArray__common *)brkTrqActMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = (int32_T)engNum * (int32_T)batNum;
    for (i1 = 0; i1 < ix; i1++) {
      brkTrqActMat->data[i1] = rtInf;
    }

    /*  possible engine state changes for current and past path_idxs */
    ndbl = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &p_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &ob_emlrtBCI, sp);

    /*  and the previous idx KE */
    /*      engStaNumAct = engStaVec_timInx(timInx);   % look at this loop's KE */
    /*  create vector storing current and previous velocity info */
    /*  check later if you can remove this */
    ndbl = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &w_emlrtDCI, sp);
    vehVelVec[0] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &pb_emlrtBCI, sp) - 1];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_timInx, &x_emlrtDCI, sp);
    vehVelVec[1] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &qb_emlrtBCI, sp) - 1];

    /*  save current and previous crankshaft speed vectors for boundary */
    /*  checks when looping through gear states */
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &nb_emlrtBCI, sp);

    /*     %% PRE->ACT engBat CONTROL */
    /*  INPUT BATTERY BOUNDARIES FROM PREPROCESSING HERE!! */
    /*  battery power max/min boundaries wrt max/min emo power */
    /*  boundaries as a function of crankshaft speed */
    /*      batPwrMinIdx_crsSpd    = batStaActInx + batPwrMinIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp; */
    /*      batPwrMaxIdx_crsSpd    = batStaActInx + batPwrMaxIdxTn3(timInx-1, batStaActInx, geaStaAct)*timStp; */
    st.site = &b_emlrtRSI;
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &mb_emlrtBCI, &st);
    b_st.site = &q_emlrtRSI;
    c_st.site = &r_emlrtRSI;
    ix = 693;
    for (i = 0; i < 6; i++) {
      d_st.site = &s_emlrtRSI;
      ixstart = ix - 692;
      if (muDoubleScalarIsNaN(batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 * ((ix
               - 693) % 693)) + 818433 * div_nzp_s32_floor(ix - 693, 693)) - 2]))
      {
        e_st.site = &u_emlrtRSI;
        if (ix - 691 > ix) {
          c_ix = false;
        } else {
          c_ix = (ix > 2147483646);
        }

        if (c_ix) {
          h_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        b_ix = ix - 691;
        exitg4 = false;
        while ((!exitg4) && (b_ix <= ix)) {
          ixstart = b_ix;
          if (!muDoubleScalarIsNaN(batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
                 ((b_ix - 1) % 693)) + 818433 * div_nzp_s32_floor(b_ix - 1, 693))
               - 2])) {
            exitg4 = true;
          } else {
            b_ix++;
          }
        }
      }

      if (ixstart < ix) {
        e_st.site = &t_emlrtRSI;
        if (ixstart + 1 > ix) {
          b_ixstart = false;
        } else {
          b_ixstart = (ix > 2147483646);
        }

        if (b_ixstart) {
          h_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
      }

      ix += 693;
    }

    st.site = &c_emlrtRSI;
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &lb_emlrtBCI, &st);
    b_st.site = &v_emlrtRSI;
    c_st.site = &r_emlrtRSI;
    ix = 693;
    for (i = 0; i < 6; i++) {
      d_st.site = &s_emlrtRSI;
      ixstart = ix - 692;
      if (muDoubleScalarIsNaN(batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 * ((ix
               - 693) % 693)) + 818433 * div_nzp_s32_floor(ix - 693, 693)) - 2]))
      {
        e_st.site = &u_emlrtRSI;
        if (ix - 691 > ix) {
          d_ix = false;
        } else {
          d_ix = (ix > 2147483646);
        }

        if (d_ix) {
          h_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        b_ix = ix - 691;
        exitg3 = false;
        while ((!exitg3) && (b_ix <= ix)) {
          ixstart = b_ix;
          if (!muDoubleScalarIsNaN(batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
                 ((b_ix - 1) % 693)) + 818433 * div_nzp_s32_floor(b_ix - 1, 693))
               - 2])) {
            exitg3 = true;
          } else {
            b_ix++;
          }
        }
      }

      if (ixstart < ix) {
        e_st.site = &t_emlrtRSI;
        if (ixstart + 1 > ix) {
          c_ixstart = false;
        } else {
          c_ixstart = (ix > 2147483646);
        }

        if (c_ixstart) {
          h_st.site = &p_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
      }

      ix += 693;
    }

    /*  battery power limits given by max/min battery power */
    /*  discharge (a given model input value) */
    /*      %   ie change in E cannot exceed bat power levels (P=E'/t') */
    /*      % find the most constraining change in batEng based on */
    /*      % previous limitations */
    /*  MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY */
    /*  STATE, NOT FROM SCRATCH!!! */
    /*  make vector of these batEng state steps for a loop */
    /*  define gear for the given time index */
    geaStaAct = geaStaVec[(int32_T)b_timInx - 1];
    i1 = (int32_T)b_timInx - 1;
    geaStaPre = geaStaVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 492477,
      &rb_emlrtBCI, sp) - 1];

    /*      batStaLimVec = batStaLimBot : batStaLimTop; */
    /* % ----- CURRENT STATE VARIBALE LOOP -------------------------------------- */
    /*   go through the possible engine state on-off possibilities */
    /*    checking if the engine can be off or on for this index */
    b_engStaMin = engStaMin;
    i1 = (int32_T)(engStaMax + (1.0 - engStaMin));
    emlrtForLoopVectorCheckR2012b(engStaMin, 1.0, engStaMax, mxDOUBLE_CLASS, i1,
      &s_emlrtRTEI, sp);
    engStaAct = 0;
    while (engStaAct <= i1 - 1) {
      b_engStaAct = b_engStaMin + (real_T)engStaAct;

      /*  CURRENT ENGINE STATE LOOP                 */
      /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS --------------------------------- */
      /*  boundaries: since crsSpd is dependent on gear, check is performed */
      /*  within the gear state loop */
      /*  IF ENGINE IS ON: */
      guard1 = false;
      if (b_engStaAct != 0.0) {
        /*  Abbruch, wenn die Drehzahlen der Kurbelwelle zu hoch im hybridischen */
        /*  Modus */
        /*    stop if the crankshaft rotational speed is too high in hybrid mode */
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(geaStaAct, &o_emlrtDCI, sp);
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, 6, &kb_emlrtBCI, sp);
        if ((crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)geaStaAct - 1)) - 1]
             > crsSpdHybMax) || (crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)
               geaStaAct - 1)) - 1] < crsSpdHybMin)) {
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
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(geaStaAct, &n_emlrtDCI, sp);
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, 6, &jb_emlrtBCI, sp);
        if (crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)geaStaAct - 1)) - 1]
            > crsSpdEmoMax) {
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
          /*             %% Initialisieren */
          /*    note-you are preallocating over each state permutation */
          /*  convert batStaActInx back into actual batEng */
          i2 = batStaActInxVec->size[1];
          ixstop = 1 + batStaActInx;
          batStaAct = batStaActInxVec->data[emlrtDynamicBoundsCheckFastR2012b
            (ixstop, 1, i2, &sb_emlrtBCI, sp) - 1] * batStaStp;

          /*                  batStaActInx = batStaLimVec(batStaActInx_counter); */
          /*                  batStaAct   = batStaActInx * batStaStp; */
          /*  memoization variable for storing möglich fuel values */
          i2 = fulActMat->size[0] * fulActMat->size[1];
          fulActMat->size[0] = (int32_T)engNum;
          fulActMat->size[1] = (int32_T)batNum;
          emxEnsureCapacity(sp, (emxArray__common *)fulActMat, i2, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          ix = (int32_T)engNum * (int32_T)batNum;
          for (i2 = 0; i2 < ix; i2++) {
            fulActMat->data[i2] = rtInf;
          }

          /*  memoiztaion variables for optimal torque predecessor values */
          i2 = emoTrqPreMat->size[0] * emoTrqPreMat->size[1];
          emoTrqPreMat->size[0] = (int32_T)engNum;
          emoTrqPreMat->size[1] = (int32_T)batNum;
          emxEnsureCapacity(sp, (emxArray__common *)emoTrqPreMat, i2, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          ix = (int32_T)engNum * (int32_T)batNum;
          for (i2 = 0; i2 < ix; i2++) {
            emoTrqPreMat->data[i2] = 0.0;
          }

          i2 = iceTrqPreMat->size[0] * iceTrqPreMat->size[1];
          iceTrqPreMat->size[0] = (int32_T)engNum;
          iceTrqPreMat->size[1] = (int32_T)batNum;
          emxEnsureCapacity(sp, (emxArray__common *)iceTrqPreMat, i2, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          ix = (int32_T)engNum * (int32_T)batNum;
          for (i2 = 0; i2 < ix; i2++) {
            iceTrqPreMat->data[i2] = 0.0;
          }

          i2 = brkTrqPreMat->size[0] * brkTrqPreMat->size[1];
          brkTrqPreMat->size[0] = (int32_T)engNum;
          brkTrqPreMat->size[1] = (int32_T)batNum;
          emxEnsureCapacity(sp, (emxArray__common *)brkTrqPreMat, i2, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          ix = (int32_T)engNum * (int32_T)batNum;
          for (i2 = 0; i2 < ix; i2++) {
            brkTrqPreMat->data[i2] = 0.0;
          }

          /*  ----- DEFINING PREDECESSOR STATE VARIABLE LIMITATIONS ------------------ */
          /*             %% defining previous engine state control w/ iceFlg */
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
              for (i2 = 0; i2 < 2; i2++) {
                engStaPreIdx_data[i2] = dv0[i2];
              }
            }
          } else {
            /*  if the motor must always be on - loop only through same state */
            engStaPreIdx_size_idx_1 = 1;
            engStaPreIdx_data[0] = b_engStaAct;
          }

          /*             %% Vorgängerzustände beschränken */
          /*    Restrictions on predecessor operation states */
          /*  restricting predecessor bat level possibilities */
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
          i2 = (int32_T)(b_timInx - 1.0);
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &ib_emlrtBCI, sp);
          i2 = batStaActInx + 1;
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, 693, &hb_emlrtBCI, sp);
          i2 = (int32_T)(b_timInx - 1.0);
          emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &gb_emlrtBCI, sp);

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
                              fzg_scalar_struct->batPwrMin * inputparams->timStp
                              / batStaStp, (1.0 + (real_T)batStaActInx) +
                              batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
            batStaActInx) + 818433 * ((int32_T)geaStaAct - 1)) - 2] *
                              inputparams->timStp));
          batStaLimMax = muDoubleScalarMin(batStaMax / batStaStp + 1.0,
            muDoubleScalarMin((1.0 + (real_T)batStaActInx) +
                              fzg_scalar_struct->batPwrMax * inputparams->timStp
                              / batStaStp, (1.0 + (real_T)batStaActInx) +
                              batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
            batStaActInx) + 818433 * ((int32_T)geaStaAct - 1)) - 2] *
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
          st.site = &d_emlrtRSI;
          b_st.site = &l_emlrtRSI;
          c_st.site = &m_emlrtRSI;
          if (muDoubleScalarIsNaN(batEngInxBeg) || muDoubleScalarIsNaN
              (batStaLimMax)) {
            n = 0;
            batStaPreIdx_noEmo = rtNaN;
            apnd = batStaLimMax;
            overflow = false;
          } else if (batStaLimMax < batEngInxBeg) {
            n = -1;
            batStaPreIdx_noEmo = batEngInxBeg;
            apnd = batStaLimMax;
            overflow = false;
          } else if (muDoubleScalarIsInf(batEngInxBeg) || muDoubleScalarIsInf
                     (batStaLimMax)) {
            n = 0;
            batStaPreIdx_noEmo = rtNaN;
            apnd = batStaLimMax;
            overflow = !(batEngInxBeg == batStaLimMax);
          } else {
            batStaPreIdx_noEmo = batEngInxBeg;
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

          d_st.site = &n_emlrtRSI;
          if (!overflow) {
          } else {
            b_y = NULL;
            m0 = emlrtCreateCharArray(2, iv1);
            for (i = 0; i < 21; i++) {
              cv0[i] = cv1[i];
            }

            emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
            emlrtAssign(&b_y, m0);
            e_st.site = &qb_emlrtRSI;
            f_st.site = &vb_emlrtRSI;
            error(&e_st, message(&f_st, b_y, &emlrtMCI), &b_emlrtMCI);
          }

          i2 = batStaPreIdxVec->size[0] * batStaPreIdxVec->size[1];
          batStaPreIdxVec->size[0] = 1;
          batStaPreIdxVec->size[1] = n + 1;
          emxEnsureCapacity(&c_st, (emxArray__common *)batStaPreIdxVec, i2,
                            (int32_T)sizeof(real_T), &b_emlrtRTEI);
          if (n + 1 > 0) {
            batStaPreIdxVec->data[0] = batStaPreIdx_noEmo;
            if (n + 1 > 1) {
              batStaPreIdxVec->data[n] = apnd;
              i2 = n + (n < 0);
              if (i2 >= 0) {
                nm1d2 = (int32_T)((uint32_T)i2 >> 1);
              } else {
                nm1d2 = (int32_T)~(~(uint32_T)i2 >> 1);
              }

              d_st.site = &o_emlrtRSI;
              for (ix = 1; ix < nm1d2; ix++) {
                batStaPreIdxVec->data[ix] = batStaPreIdx_noEmo + (real_T)ix;
                batStaPreIdxVec->data[n - ix] = apnd - (real_T)ix;
              }

              if (nm1d2 << 1 == n) {
                batStaPreIdxVec->data[nm1d2] = (batStaPreIdx_noEmo + apnd) / 2.0;
              } else {
                batStaPreIdxVec->data[nm1d2] = batStaPreIdx_noEmo + (real_T)
                  nm1d2;
                batStaPreIdxVec->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }

          /*  ------------------------------------------------------------------------- */
          /* % ----- PREDECESSOR STATE VARIBALE LOOP ---------------------------------- */
          /*  PREVIOUS gear state loop */
          nm1d2 = 0;
          while (nm1d2 <= engStaPreIdx_size_idx_1 - 1) {
            i2 = 1 + nm1d2;
            apnd = engStaPreIdx_data[emlrtDynamicBoundsCheckFastR2012b(i2, 1,
              engStaPreIdx_size_idx_1, &rc_emlrtBCI, sp) - 1];

            /*  engine state penalty */
            if (b_engStaAct == engStaPreIdx_data[nm1d2]) {
              absa = 0.0;
            } else {
              absa = inputparams->staChgPenCosVal;
            }

            /*  penalty for changning battery level or no? */
            /*  Kosten für Zustandswechsel setzen */
            /*    set costs for gear state changes */
            if (geaStaAct == geaStaPre) {
              /*  Entspricht der Vorgï¿½ngerzustand dem aktuellen  */
              /*  Zustand werden keine Kosten gesetzt */
              /*    staying in current state? set penalty cost to 0 */
              absb = 0.0;
            } else {
              /*  Ansonsten einfache Zustandswechselkosten */
              /*  berechnen */
              /*    otherwise apply a penalty cost to changing gear */
              absb = inputparams->staChgPenCosVal;

              /* <-penCos is input */
            }

            /*                 %% check if engStaPre == 0. */
            /*  if == 0 - ignore bat state loop bc emoTrq==crsTrq */
            /*    b/c anything else is not optimal (w/ brakes) */
            /*  if == 1 - then run through bat state loop */
            /*  pull out appropriate crankshaft speed and torque */
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &fb_emlrtBCI, sp);
            i2 = (int32_T)emlrtIntegerCheckFastR2012b(geaStaPre, &m_emlrtDCI, sp);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 6, &eb_emlrtBCI, sp);
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &db_emlrtBCI, sp);

            /*  all EM torque boundaries for given gear */
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &cb_emlrtBCI, sp);
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &bb_emlrtBCI, sp);

            /*                        % emoTrqMaxPosMat(:, geaStaPre); */
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &ab_emlrtBCI, sp);
            i2 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &y_emlrtBCI, sp);

            /*  IF ENGINE WAS ON */
            if (engStaPreIdx_data[nm1d2] != 0.0) {
              /*  all ICE torque boundaries for given gear */
              i2 = (int32_T)(b_timInx - 1.0);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &x_emlrtBCI, sp);
              i2 = (int32_T)(b_timInx - 1.0);
              emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1181, &w_emlrtBCI, sp);

              /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS ------ */
              /*  boundaries: since crsSpd is dependent on gear,  */
              /*  check is performed within the gear state loop */
              /*  IF ENGINE IS ON: */
              /*  Abbruch, wenn die Drehzahlen der Kurbelwelle  */
              /*  zu hoch im hybridischen */
              /*  Modus */
              /*    stop if the crankshaft rotational speed is  */
              /*    too high in hybrid mode */
              if ((crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)geaStaPre - 1))
                   - 2] > crsSpdHybMax) || (crsSpdMat[((int32_T)b_timInx + 1181 *
                    ((int32_T)geaStaPre - 1)) - 2] < crsSpdHybMin)) {
              } else {
                /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
                /*  Leerlaufdrehzahl ist, */
                /*    stop if crankhaft rotional speed is lower than the idling speed */
                ix = 0;
                while (ix <= batStaPreIdxVec->size[1] - 1) {
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
                  i2 = batStaPreIdxVec->size[1];
                  ixstop = ix + 1;
                  emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &v_emlrtBCI,
                    sp);

                  /*  calculate E' */
                  cdiff = batStaAct - (batStaPreIdxVec->data[ix] - 1.0) *
                    batStaStp;

                  /*  calculate battery resistance */
                  /*  the code below is performing this code snippet across the vector */
                  /*  if batPwr < 0 */
                  /*      batRst = fzg_scalar_struct.batRstDch; */
                  /*  else */
                  /*      batRst = fzg_scalar_struct.batRstChr; */
                  /*  end */
                  /*  lookup previous bat state's voltage value */
                  ndbl = batStaPreIdxVec->data[ix];
                  i2 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &l_emlrtDCI,
                    sp);
                  emlrtDynamicBoundsCheckFastR2012b(i2, 1, 693, &u_emlrtBCI, sp);

                  /*                         %% Berechnung der optimalen Kosten zum aktuellen Punkt */
                  /*    calculating optimal cost to the current point */
                  /*  do it tim interval at a tim? will remove vector */
                  /*  aspects */
                  /*  % maximum crankshaft rotational speed */
                  /*  % minimum crankshaft rotational speed */
                  st.site = &e_emlrtRSI;
                  optTrqSplit_focus(&st, inputparams->brkBool, cdiff, batOcv
                                    [(int32_T)batStaPreIdxVec->data[ix] - 1],
                                    (real_T)(cdiff < 0.0) *
                                    fzg_scalar_struct->batRstDch + (real_T)
                                    (cdiff >= 0.0) *
                                    fzg_scalar_struct->batRstChr, crsSpdMat
                                    [((int32_T)b_timInx + 1181 * ((int32_T)
                    geaStaPre - 1)) - 2], crsTrqMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    emoTrqMinPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    emoTrqMaxPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    emoPwrMinPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    emoPwrMaxPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    iceTrqMaxPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    iceTrqMinPosMat[((int32_T)b_timInx + 1181 *
                                     ((int32_T)geaStaPre - 1)) - 2],
                                    crsSpdHybMax, crsSpdHybMin,
                                    inputparams->timStp, inputparams->batPwrAux,
                                    vehVelVec, fzg_scalar_struct,
                                    fzg_array_struct, &batEngInxBeg,
                                    &batStaPreIdx_noEmo, &batStaLimMax, &ndbl);

                  /*  combine the min hamil. cost w/ previous costs and  */
                  /*    gear penalty to get current cost */
                  i2 = fulActMat->size[0];
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                    &jb_emlrtDCI, sp);
                  cindx = fulActMat->size[1];
                  b_ix = (int32_T)batStaPreIdxVec->data[ix];
                  i = cos2goPreMat->size[0];
                  n = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                    &kb_emlrtDCI, sp);
                  i3 = cos2goPreMat->size[1];
                  ixstart = (int32_T)batStaPreIdxVec->data[ix];
                  fulActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1,
                    i2, &wc_emlrtBCI, sp) + fulActMat->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
                    cindx, &xc_emlrtBCI, sp) - 1)) - 1] = ((batEngInxBeg +
                    cos2goPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(n, 1,
                    i, &yc_emlrtBCI, sp) + cos2goPreMat->size[0] *
                                        (emlrtDynamicBoundsCheckFastR2012b
                    (ixstart, 1, i3, &ad_emlrtBCI, sp) - 1)) - 1]) + absb /
                    inputparams->timStp) + absa / inputparams->timStp;
                  i2 = emoTrqPreMat->size[0];
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                    &lb_emlrtDCI, sp);
                  cindx = emoTrqPreMat->size[1];
                  b_ix = (int32_T)batStaPreIdxVec->data[ix];
                  emoTrqPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop,
                    1, i2, &bd_emlrtBCI, sp) + emoTrqPreMat->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
                    cindx, &cd_emlrtBCI, sp) - 1)) - 1] = batStaPreIdx_noEmo;
                  i2 = iceTrqPreMat->size[0];
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                    &mb_emlrtDCI, sp);
                  cindx = iceTrqPreMat->size[1];
                  b_ix = (int32_T)batStaPreIdxVec->data[ix];
                  iceTrqPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop,
                    1, i2, &dd_emlrtBCI, sp) + iceTrqPreMat->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
                    cindx, &ed_emlrtBCI, sp) - 1)) - 1] = batStaLimMax;
                  i2 = brkTrqPreMat->size[0];
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(apnd + 1.0,
                    &nb_emlrtDCI, sp);
                  cindx = brkTrqPreMat->size[1];
                  b_ix = (int32_T)batStaPreIdxVec->data[ix];
                  brkTrqPreMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop,
                    1, i2, &fd_emlrtBCI, sp) + brkTrqPreMat->size[0] *
                                      (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
                    cindx, &gd_emlrtBCI, sp) - 1)) - 1] = ndbl;
                  ix++;
                  emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
                }

                /*  end of bat energy changing loop */
                /*  end of engStaPre condition check */
              }
            } else {
              /*  ---- electric motor MUST satisfy crsTrq ----- */
              /*  IF ENGINE IS OFF */
              /*  Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
              /*    check if electric motor speed limit is maintained */
              if (crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)geaStaPre - 1))
                  - 2] > crsSpdEmoMax) {
              } else {
                /*  determine previous state if engine waas off */
                /*  based on batPwrDemIdxTn3 (a preprocessed tn3 */
                /*  containing amnt battery pwr needed to satisfy */
                /*  a crankshaft power demand for all state */
                /*  permutations) */
                /*  - 1 */
                batStaPreIdx_noEmo = (1.0 + (real_T)batStaActInx) +
                  batPwrDemIdxTn3[(((int32_T)b_timInx + 1181 * batStaActInx) +
                                   818433 * ((int32_T)geaStaAct - 1)) - 1];

                /*  check your bounds  */
                if ((batStaPreIdx_noEmo < batStaMin / batStaStp + 1.0) ||
                    (batStaPreIdx_noEmo > batStaMax / batStaStp + 1.0)) {
                } else {
                  /*  penalty to get current cost */
                  /*  minFul ... */
                  i2 = fulActMat->size[0];
                  ndbl = engStaPreIdx_data[nm1d2] + 1.0;
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl,
                    &h_emlrtDCI, sp);
                  emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &p_emlrtBCI,
                    sp);
                  i2 = cos2goPreMat->size[0];
                  ndbl = engStaPreIdx_data[nm1d2] + 1.0;
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl,
                    &i_emlrtDCI, sp);
                  emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &r_emlrtBCI,
                    sp);
                  i2 = fulActMat->size[1];
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b
                    (batStaPreIdx_noEmo, &hb_emlrtDCI, sp);
                  cindx = cos2goPreMat->size[1];
                  b_ix = (int32_T)emlrtIntegerCheckFastR2012b(batStaPreIdx_noEmo,
                    &ib_emlrtDCI, sp);
                  fulActMat->data[fulActMat->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
                      &sc_emlrtBCI, sp) - 1)] = (cos2goPreMat->data
                    [cos2goPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                    (b_ix, 1, cindx, &tc_emlrtBCI, sp) - 1)] + absb /
                    inputparams->timStp) + absa / inputparams->timStp;
                  i2 = emoTrqPreMat->size[0];
                  ndbl = engStaPreIdx_data[nm1d2] + 1.0;
                  ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl,
                    &e_emlrtDCI, sp);
                  emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &j_emlrtBCI,
                    sp);
                  i2 = emoTrqPreMat->size[1];
                  ixstop = (int32_T)batStaPreIdx_noEmo;
                  emoTrqPreMat->data[emoTrqPreMat->size[0] *
                    (emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
                      &uc_emlrtBCI, sp) - 1)] = crsTrqMat[((int32_T)b_timInx +
                    1181 * ((int32_T)geaStaPre - 1)) - 2];

                  /*  brake torque in case of torque overshoot */
                  if (inputparams->brkBool != 0.0) {
                    batEngInxBeg = crsTrqMat[((int32_T)b_timInx + 1181 *
                      ((int32_T)geaStaPre - 1)) - 2] * crsSpdMat[((int32_T)
                      b_timInx + 1181 * ((int32_T)geaStaPre - 1)) - 2];
                    i2 = batStaActInxVec->size[1];
                    ixstop = (int32_T)batStaPreIdx_noEmo;
                    emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &q_emlrtBCI,
                      sp);
                    batStaLimMax = batStaActInxVec->data[(int32_T)
                      batStaPreIdx_noEmo - 1] * batStaStp / inputparams->timStp;
                    if (batStaLimMax > batEngInxBeg) {
                      i2 = brkTrqPreMat->size[0];
                      ndbl = engStaPreIdx_data[nm1d2] + 1.0;
                      ixstop = (int32_T)emlrtIntegerCheckFastR2012b(ndbl,
                        &d_emlrtDCI, sp);
                      emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
                        &i_emlrtBCI, sp);
                      i2 = brkTrqPreMat->size[1];
                      ixstop = (int32_T)batStaPreIdx_noEmo;
                      brkTrqPreMat->data[brkTrqPreMat->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
                          &vc_emlrtBCI, sp) - 1)] = (batStaLimMax - batEngInxBeg)
                        / crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)
                        geaStaPre - 1)) - 2];
                    }
                  }

                  /*  end of engStaPre condition check */
                }
              }
            }

            nm1d2++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
          }

          /*  end of running through previous engine state ctrl loop */
          /*  pull out the minimum value from fulActMat */
          st.site = &f_emlrtRSI;
          b_st.site = &eb_emlrtRSI;
          c_st.site = &fb_emlrtRSI;
          if (((fulActMat->size[0] == 1) && (fulActMat->size[1] == 1)) ||
              (fulActMat->size[0] != 1)) {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
          } else {
            c_y = NULL;
            m0 = emlrtCreateCharArray(2, iv2);
            for (i = 0; i < 36; i++) {
              cv2[i] = cv3[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 36, m0, cv2);
            emlrtAssign(&c_y, m0);
            d_st.site = &pb_emlrtRSI;
            g_st.site = &ub_emlrtRSI;
            error(&d_st, message(&g_st, c_y, &f_emlrtMCI), &g_emlrtMCI);
          }

          if (fulActMat->size[0] > 0) {
          } else {
            d_y = NULL;
            m0 = emlrtCreateCharArray(2, iv3);
            for (i = 0; i < 39; i++) {
              cv4[i] = cv5[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 39, m0, cv4);
            emlrtAssign(&d_y, m0);
            d_st.site = &ob_emlrtRSI;
            g_st.site = &tb_emlrtRSI;
            error(&d_st, message(&g_st, d_y, &h_emlrtMCI), &i_emlrtMCI);
          }

          for (i2 = 0; i2 < 2; i2++) {
            outsz[i2] = (uint32_T)fulActMat->size[i2];
          }

          i2 = batStaPreIdxVec->size[0] * batStaPreIdxVec->size[1];
          batStaPreIdxVec->size[0] = 1;
          batStaPreIdxVec->size[1] = (int32_T)outsz[1];
          emxEnsureCapacity(&c_st, (emxArray__common *)batStaPreIdxVec, i2,
                            (int32_T)sizeof(real_T), &c_emlrtRTEI);
          b_outsz = outsz[1];
          i2 = iindx->size[0] * iindx->size[1];
          iindx->size[0] = 1;
          emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i2, (int32_T)
                            sizeof(int32_T), &emlrtRTEI);
          i2 = iindx->size[0] * iindx->size[1];
          iindx->size[1] = (int32_T)outsz[1];
          emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i2, (int32_T)
                            sizeof(int32_T), &emlrtRTEI);
          ix = (int32_T)b_outsz;
          for (i2 = 0; i2 < ix; i2++) {
            iindx->data[i2] = 1;
          }

          n = fulActMat->size[0];
          ix = 0;
          nm1d2 = -1;
          d_st.site = &gb_emlrtRSI;
          if (1 > fulActMat->size[1]) {
            overflow = false;
          } else {
            overflow = (fulActMat->size[1] > 2147483646);
          }

          if (overflow) {
            e_st.site = &p_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }

          for (i = 1; i <= fulActMat->size[1]; i++) {
            d_st.site = &s_emlrtRSI;
            ixstart = ix;
            ixstop = ix + n;
            batEngInxBeg = fulActMat->data[ix];
            engStaPreIdx_size_idx_1 = 1;
            if (n > 1) {
              cindx = 1;
              if (muDoubleScalarIsNaN(fulActMat->data[ix])) {
                e_st.site = &u_emlrtRSI;
                if (ix + 2 > ixstop) {
                  e_ix = false;
                } else {
                  e_ix = (ixstop > 2147483646);
                }

                if (e_ix) {
                  h_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                b_ix = ix + 1;
                exitg2 = false;
                while ((!exitg2) && (b_ix + 1 <= ixstop)) {
                  cindx++;
                  ixstart = b_ix;
                  if (!muDoubleScalarIsNaN(fulActMat->data[b_ix])) {
                    batEngInxBeg = fulActMat->data[b_ix];
                    engStaPreIdx_size_idx_1 = cindx;
                    exitg2 = true;
                  } else {
                    b_ix++;
                  }
                }
              }

              if (ixstart + 1 < ixstop) {
                e_st.site = &t_emlrtRSI;
                if (ixstart + 2 > ixstop) {
                  d_ixstart = false;
                } else {
                  d_ixstart = (ixstop > 2147483646);
                }

                if (d_ixstart) {
                  h_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                for (b_ix = ixstart + 1; b_ix + 1 <= ixstop; b_ix++) {
                  cindx++;
                  if (fulActMat->data[b_ix] < batEngInxBeg) {
                    batEngInxBeg = fulActMat->data[b_ix];
                    engStaPreIdx_size_idx_1 = cindx;
                  }
                }
              }
            }

            nm1d2++;
            batStaPreIdxVec->data[nm1d2] = batEngInxBeg;
            iindx->data[nm1d2] = engStaPreIdx_size_idx_1;
            ix += n;
          }

          i2 = indx->size[0] * indx->size[1];
          indx->size[0] = 1;
          indx->size[1] = iindx->size[1];
          emxEnsureCapacity(&b_st, (emxArray__common *)indx, i2, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          ix = iindx->size[0] * iindx->size[1];
          for (i2 = 0; i2 < ix; i2++) {
            indx->data[i2] = iindx->data[i2];
          }

          st.site = &g_emlrtRSI;
          b_st.site = &eb_emlrtRSI;
          c_st.site = &fb_emlrtRSI;
          if ((batStaPreIdxVec->size[1] == 1) || (batStaPreIdxVec->size[1] != 1))
          {
            overflow = true;
          } else {
            overflow = false;
          }

          if (overflow) {
          } else {
            e_y = NULL;
            m0 = emlrtCreateCharArray(2, iv4);
            for (i = 0; i < 36; i++) {
              cv2[i] = cv3[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 36, m0, cv2);
            emlrtAssign(&e_y, m0);
            d_st.site = &pb_emlrtRSI;
            g_st.site = &ub_emlrtRSI;
            error(&d_st, message(&g_st, e_y, &f_emlrtMCI), &g_emlrtMCI);
          }

          if (batStaPreIdxVec->size[1] > 0) {
          } else {
            f_y = NULL;
            m0 = emlrtCreateCharArray(2, iv5);
            for (i = 0; i < 39; i++) {
              cv4[i] = cv5[i];
            }

            emlrtInitCharArrayR2013a(&c_st, 39, m0, cv4);
            emlrtAssign(&f_y, m0);
            d_st.site = &ob_emlrtRSI;
            g_st.site = &tb_emlrtRSI;
            error(&d_st, message(&g_st, f_y, &h_emlrtMCI), &i_emlrtMCI);
          }

          d_st.site = &hb_emlrtRSI;
          ixstart = 1;
          n = batStaPreIdxVec->size[1];
          batEngInxBeg = batStaPreIdxVec->data[0];
          engStaPreIdx_size_idx_1 = 0;
          if (batStaPreIdxVec->size[1] > 1) {
            if (muDoubleScalarIsNaN(batStaPreIdxVec->data[0])) {
              e_st.site = &u_emlrtRSI;
              overflow = (batStaPreIdxVec->size[1] > 2147483646);
              if (overflow) {
                h_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&h_st);
              }

              ix = 2;
              exitg1 = false;
              while ((!exitg1) && (ix <= n)) {
                ixstart = ix;
                if (!muDoubleScalarIsNaN(batStaPreIdxVec->data[ix - 1])) {
                  batEngInxBeg = batStaPreIdxVec->data[ix - 1];
                  engStaPreIdx_size_idx_1 = ix - 1;
                  exitg1 = true;
                } else {
                  ix++;
                }
              }
            }

            if (ixstart < batStaPreIdxVec->size[1]) {
              e_st.site = &t_emlrtRSI;
              if (ixstart + 1 > batStaPreIdxVec->size[1]) {
                overflow = false;
              } else {
                overflow = (batStaPreIdxVec->size[1] > 2147483646);
              }

              if (overflow) {
                h_st.site = &p_emlrtRSI;
                check_forloop_overflow_error(&h_st);
              }

              while (ixstart + 1 <= n) {
                if (batStaPreIdxVec->data[ixstart] < batEngInxBeg) {
                  batEngInxBeg = batStaPreIdxVec->data[ixstart];
                  engStaPreIdx_size_idx_1 = ixstart;
                }

                ixstart++;
              }
            }
          }

          /*              [minFulMin, batStaPreOptInx] = min(matmin); */
          i2 = indx->size[1];
          ixstop = engStaPreIdx_size_idx_1 + 1;
          emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &o_emlrtBCI, sp);

          /*              engStaPreOptInx     = colminidx(:, geaStaPreOptInx, batStaPreOptInx); */
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
            i2 = fulEngPreMat->size[0];
            ixstop = (int32_T)indx->data[engStaPreIdx_size_idx_1];
            emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &l_emlrtBCI, sp);
            i2 = fulEngPreMat->size[1];
            ixstop = engStaPreIdx_size_idx_1 + 1;
            emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2, &k_emlrtBCI, sp);

            /* %#ok<PFBNS> */
            /*  optimale Kosten zum aktuellen Punkt speichern */
            /*    save min hamilton value for current point */
            i2 = cos2goActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &y_emlrtDCI, sp);
            cindx = cos2goActMat->size[1];
            b_ix = 1 + batStaActInx;
            cos2goActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &tb_emlrtBCI, sp) + cos2goActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &ub_emlrtBCI, sp) - 1)) - 1] = batEngInxBeg;

            /*  optimale Batterieenergie zum aktuellen Punkt speichern */
            /*    save optimal battery energy for current point */
            i2 = batEngActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &ab_emlrtDCI, sp);
            cindx = batEngActMat->size[1];
            b_ix = 1 + batStaActInx;
            batEngActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &vb_emlrtBCI, sp) + batEngActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &wb_emlrtBCI, sp) - 1)) - 1] = ((real_T)
              (engStaPreIdx_size_idx_1 + 1) - 1.0) * batStaStp;

            /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
            /*    save optimal fuel energy for current point */
            i2 = fulEngActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &bb_emlrtDCI, sp);
            cindx = fulEngActMat->size[1];
            b_ix = 1 + batStaActInx;
            fulEngActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &xb_emlrtBCI, sp) + fulEngActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &yb_emlrtBCI, sp) - 1)) - 1] = batEngInxBeg +
              fulEngPreMat->data[((int32_T)indx->data[engStaPreIdx_size_idx_1] +
                                  fulEngPreMat->size[0] *
                                  engStaPreIdx_size_idx_1) - 1];

            /*  optimale Batterieenergie zum aktuellen Punkt */
            /*  Flussgrï¿½ï¿½e gilt im Intervall */
            /*    populate optimal battery energy flux quantity at point  */
            /*    that's applicable to current interval */
            i2 = batPwrActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &cb_emlrtDCI, sp);
            cindx = batPwrActMat->size[1];
            b_ix = 1 + batStaActInx;
            batPwrActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &ac_emlrtBCI, sp) + batPwrActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &bc_emlrtBCI, sp) - 1)) - 1] = (1.0 + (real_T)batStaActInx)
              - (real_T)(engStaPreIdx_size_idx_1 + 1);

            /*  save optimal torque values for the given time index */
            /*  emoTrq */
            i2 = emoTrqActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &db_emlrtDCI, sp);
            cindx = emoTrqActMat->size[1];
            b_ix = 1 + batStaActInx;
            i = emoTrqPreMat->size[0];
            n = (int32_T)indx->data[engStaPreIdx_size_idx_1];
            i3 = emoTrqPreMat->size[1];
            emoTrqActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &cc_emlrtBCI, sp) + emoTrqActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &dc_emlrtBCI, sp) - 1)) - 1] = emoTrqPreMat->data
              [(emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &ec_emlrtBCI, sp) +
                emoTrqPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                 (engStaPreIdx_size_idx_1 + 1, 1, i3, &fc_emlrtBCI, sp) - 1)) -
              1];

            /*  iceTrq */
            i2 = iceTrqActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &eb_emlrtDCI, sp);
            cindx = iceTrqActMat->size[1];
            b_ix = 1 + batStaActInx;
            i = iceTrqPreMat->size[0];
            n = (int32_T)indx->data[engStaPreIdx_size_idx_1];
            i3 = iceTrqPreMat->size[1];
            iceTrqActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &gc_emlrtBCI, sp) + iceTrqActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &hc_emlrtBCI, sp) - 1)) - 1] = iceTrqPreMat->data
              [(emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &ic_emlrtBCI, sp) +
                iceTrqPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                 (engStaPreIdx_size_idx_1 + 1, 1, i3, &jc_emlrtBCI, sp) - 1)) -
              1];

            /*  brkTrq */
            i2 = brkTrqActMat->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &fb_emlrtDCI, sp);
            cindx = brkTrqActMat->size[1];
            b_ix = 1 + batStaActInx;
            i = brkTrqPreMat->size[0];
            n = (int32_T)indx->data[engStaPreIdx_size_idx_1];
            i3 = brkTrqPreMat->size[1];
            brkTrqActMat->data[(emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &kc_emlrtBCI, sp) + brkTrqActMat->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &lc_emlrtBCI, sp) - 1)) - 1] = brkTrqPreMat->data
              [(emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &mc_emlrtBCI, sp) +
                brkTrqPreMat->size[0] * (emlrtDynamicBoundsCheckFastR2012b
                 (engStaPreIdx_size_idx_1 + 1, 1, i3, &nc_emlrtBCI, sp) - 1)) -
              1];

            /*  optimalen Vorgänger codieren über Funktion sub2ind */
            /*  und speichern im Tensor */
            /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
            st.site = &h_emlrtRSI;
            b_st.site = &ib_emlrtRSI;
            if ((indx->data[engStaPreIdx_size_idx_1] >= 1.0) && ((int32_T)engNum
                 >= (int32_T)indx->data[engStaPreIdx_size_idx_1])) {
              overflow = true;
            } else {
              overflow = false;
            }

            c_st.site = &jb_emlrtRSI;
            if (!overflow) {
              b_overflow = false;
            } else {
              b_overflow = true;
            }

            if (b_overflow) {
            } else {
              g_y = NULL;
              m0 = emlrtCreateCharArray(2, iv6);
              for (i = 0; i < 30; i++) {
                cv6[i] = cv7[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 30, m0, cv6);
              emlrtAssign(&g_y, m0);
              d_st.site = &nb_emlrtRSI;
              error(&d_st, message(&d_st, g_y, &j_emlrtMCI), &j_emlrtMCI);
            }

            c_st.site = &kb_emlrtRSI;
            d_st.site = &lb_emlrtRSI;
            if ((engStaPreIdx_size_idx_1 + 1 >= 1) && ((int32_T)batNum >=
                 engStaPreIdx_size_idx_1 + 1)) {
              overflow = true;
            } else {
              overflow = false;
            }

            c_st.site = &jb_emlrtRSI;
            if (!overflow) {
              c_overflow = false;
            } else {
              c_overflow = true;
            }

            if (c_overflow) {
            } else {
              h_y = NULL;
              m0 = emlrtCreateCharArray(2, iv7);
              for (i = 0; i < 30; i++) {
                cv6[i] = cv7[i];
              }

              emlrtInitCharArrayR2013a(&c_st, 30, m0, cv6);
              emlrtAssign(&h_y, m0);
              d_st.site = &nb_emlrtRSI;
              error(&d_st, message(&d_st, h_y, &j_emlrtMCI), &j_emlrtMCI);
            }

            i2 = optPreInxTn3->size[0];
            ixstop = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
              &gb_emlrtDCI, sp);
            cindx = optPreInxTn3->size[1];
            b_ix = 1 + batStaActInx;
            i = optPreInxTn3->size[2];
            n = (int32_T)b_timInx;
            optPreInxTn3->data[((emlrtDynamicBoundsCheckFastR2012b(ixstop, 1, i2,
              &oc_emlrtBCI, sp) + optPreInxTn3->size[0] *
                                 (emlrtDynamicBoundsCheckFastR2012b(b_ix, 1,
              cindx, &pc_emlrtBCI, sp) - 1)) + optPreInxTn3->size[0] *
                                optPreInxTn3->size[1] *
                                (emlrtDynamicBoundsCheckFastR2012b(n, 1, i,
              &qc_emlrtBCI, sp) - 1)) - 1] = (int32_T)indx->
              data[engStaPreIdx_size_idx_1] + (int32_T)engNum *
              engStaPreIdx_size_idx_1;
          }

          /*  end of ~inf(hamiltonian) if-statement */
          batStaActInx++;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
        }

        /* end of looping through all battery states */
        st.site = &i_emlrtRSI;
        h_fprintf(&st);
      }

      engStaAct++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
    }

    /*  end of looping through all the current engine control states */
    st.site = &j_emlrtRSI;
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
    i1 = cos2goPreMat->size[0] * cos2goPreMat->size[1];
    cos2goPreMat->size[0] = cos2goActMat->size[0];
    cos2goPreMat->size[1] = cos2goActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)cos2goPreMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = cos2goActMat->size[0] * cos2goActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      cos2goPreMat->data[i1] = cos2goActMat->data[i1];
    }

    /*  Speichern der Krafstoffenergie fï¿½r den nï¿½chsten Schleifendurchlauf */
    /*    save fuel energy value as previous path_idx value for the next loop */
    i1 = fulEngPreMat->size[0] * fulEngPreMat->size[1];
    fulEngPreMat->size[0] = fulEngActMat->size[0];
    fulEngPreMat->size[1] = fulEngActMat->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)fulEngPreMat, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ix = fulEngActMat->size[0] * fulEngActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      fulEngPreMat->data[i1] = fulEngActMat->data[i1];
    }

    /*  optimale Kraftstoffenergie zum aktuellen Punkt */
    /*    optimal fuel energy at current point - save current mat in tensor */
    ix = fulEngOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    ix = fulEngOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r1->data[i1] = i1;
    }

    i1 = fulEngOptTn3->size[2];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &d_emlrtBCI, sp);
    iv8[0] = r0->size[0];
    iv8[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv8, 2, *(int32_T (*)[2])fulEngActMat->size, 2,
      &d_emlrtECI, sp);
    ix = fulEngActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      nm1d2 = fulEngActMat->size[0];
      for (i2 = 0; i2 < nm1d2; i2++) {
        fulEngOptTn3->data[(r0->data[i2] + fulEngOptTn3->size[0] * r1->data[i1])
          + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * ((int32_T)b_timInx -
          1)] = fulEngActMat->data[i2 + fulEngActMat->size[0] * i1];
      }
    }

    /*  optimale Batterieenergie zum aktuellen Punkt */
    /*    optimal battery force at current point - save current mat in tensor */
    /*  Flussgröße gilt im Intervall */
    /*    flux quantity applied over the interval */
    ix = batPwrOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    ix = batPwrOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r1->data[i1] = i1;
    }

    i1 = batPwrOptTn3->size[2];
    i2 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &h_emlrtBCI, sp);
    iv9[0] = r0->size[0];
    iv9[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv9, 2, *(int32_T (*)[2])batPwrActMat->size, 2,
      &e_emlrtECI, sp);
    ix = batPwrActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      nm1d2 = batPwrActMat->size[0];
      for (i2 = 0; i2 < nm1d2; i2++) {
        batPwrOptTn3->data[(r0->data[i2] + batPwrOptTn3->size[0] * r1->data[i1])
          + batPwrOptTn3->size[0] * batPwrOptTn3->size[1] * ((int32_T)b_timInx -
          2)] = batPwrActMat->data[i2 + batPwrActMat->size[0] * i1];
      }
    }

    ix = emoTrqOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    ix = emoTrqOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r1->data[i1] = i1;
    }

    i1 = emoTrqOptTn3->size[2];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &c_emlrtBCI, sp);
    iv10[0] = r0->size[0];
    iv10[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv10, 2, *(int32_T (*)[2])emoTrqActMat->size,
      2, &c_emlrtECI, sp);
    ix = emoTrqActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      nm1d2 = emoTrqActMat->size[0];
      for (i2 = 0; i2 < nm1d2; i2++) {
        emoTrqOptTn3->data[(r0->data[i2] + emoTrqOptTn3->size[0] * r1->data[i1])
          + emoTrqOptTn3->size[0] * emoTrqOptTn3->size[1] * ((int32_T)b_timInx -
          1)] = emoTrqActMat->data[i2 + emoTrqActMat->size[0] * i1];
      }
    }

    ix = iceTrqOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    ix = iceTrqOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r1->data[i1] = i1;
    }

    i1 = iceTrqOptTn3->size[2];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &b_emlrtBCI, sp);
    iv11[0] = r0->size[0];
    iv11[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv11, 2, *(int32_T (*)[2])iceTrqActMat->size,
      2, &b_emlrtECI, sp);
    ix = iceTrqActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      nm1d2 = iceTrqActMat->size[0];
      for (i2 = 0; i2 < nm1d2; i2++) {
        iceTrqOptTn3->data[(r0->data[i2] + iceTrqOptTn3->size[0] * r1->data[i1])
          + iceTrqOptTn3->size[0] * iceTrqOptTn3->size[1] * ((int32_T)b_timInx -
          1)] = iceTrqActMat->data[i2 + iceTrqActMat->size[0] * i1];
      }
    }

    ix = brkTrqOptTn3->size[0];
    i1 = r0->size[0];
    r0->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r0->data[i1] = i1;
    }

    ix = brkTrqOptTn3->size[1];
    i1 = r1->size[0];
    r1->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i1 = 0; i1 < ix; i1++) {
      r1->data[i1] = i1;
    }

    i1 = brkTrqOptTn3->size[2];
    i2 = (int32_T)b_timInx;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, sp);
    iv12[0] = r0->size[0];
    iv12[1] = r1->size[0];
    emlrtSubAssignSizeCheckR2012b(iv12, 2, *(int32_T (*)[2])brkTrqActMat->size,
      2, &emlrtECI, sp);
    ix = brkTrqActMat->size[1];
    for (i1 = 0; i1 < ix; i1++) {
      nm1d2 = brkTrqActMat->size[0];
      for (i2 = 0; i2 < nm1d2; i2++) {
        brkTrqOptTn3->data[(r0->data[i2] + brkTrqOptTn3->size[0] * r1->data[i1])
          + brkTrqOptTn3->size[0] * brkTrqOptTn3->size[1] * ((int32_T)b_timInx -
          1)] = brkTrqActMat->data[i2 + brkTrqActMat->size[0] * i1];
      }
    }

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (inputparams->disFlg != 0.0) {
      st.site = &k_emlrtRSI;
      l_fprintf(&st, b_timInx - inputparams->timInxBeg, (b_timInx -
                 inputparams->timInxBeg) / (inputparams->timInxEnd -
                 inputparams->timInxBeg) * 100.0);
    }

    timInx++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_int32_T(&iindx);
  emxFree_real_T(&indx);
  emxFree_int32_T(&r1);
  emxFree_int32_T(&r0);
  emxFree_real_T(&batStaPreIdxVec);
  emxFree_real_T(&brkTrqPreMat);
  emxFree_real_T(&iceTrqPreMat);
  emxFree_real_T(&emoTrqPreMat);
  emxFree_real_T(&fulActMat);
  emxFree_real_T(&brkTrqActMat);
  emxFree_real_T(&iceTrqActMat);
  emxFree_real_T(&emoTrqActMat);
  emxFree_real_T(&fulEngActMat);
  emxFree_real_T(&batEngActMat);
  emxFree_real_T(&batPwrActMat);
  emxFree_real_T(&batStaActInxVec);
  emxFree_real_T(&fulEngPreMat);
  emxFree_real_T(&cos2goPreMat);

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
  engNum_not_empty = false;
}

void engStaMax_not_empty_init(void)
{
}

void engStaMin_not_empty_init(void)
{
}

void iceFlg_not_empty_init(void)
{
}

/* End of code generation (clcDP_focus_useGeaVec.c) */
