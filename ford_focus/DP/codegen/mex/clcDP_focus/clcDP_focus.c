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
#include "optTrqSplit_focus.h"
#include "eml_int_forloop_overflow_check.h"
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
static emlrtRSInfo emlrtRSI = { 208, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo b_emlrtRSI = { 407, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo c_emlrtRSI = { 457, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo d_emlrtRSI = { 573, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo e_emlrtRSI = { 722, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo f_emlrtRSI = { 723, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo g_emlrtRSI = { 728, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo h_emlrtRSI = { 769, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo i_emlrtRSI = { 774, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo j_emlrtRSI = { 777, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRSInfo k_emlrtRSI = { 804, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
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

static emlrtRSInfo x_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo y_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ab_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo bb_emlrtRSI = { 106, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo cb_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo db_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo eb_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo fb_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo gb_emlrtRSI = { 16, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo hb_emlrtRSI = { 41, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo ib_emlrtRSI = { 39, "sub2ind",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"
};

static emlrtRSInfo jb_emlrtRSI = { 71, "sub2ind",
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

static emlrtRTEInfo emlrtRTEI = { 7, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 284, 1, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo c_emlrtRTEI = { 91, 1, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 182, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 199, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 208, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 266, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 276, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 281, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 342, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 457, 17, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtECInfo emlrtECI = { -1, 794, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 794, 24, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 168, 50, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo emlrtDCI = { 168, 50, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 168, 32, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 168, 32, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 168, 24, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 168, 24, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 168, 14, "fulEngOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 168, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtECInfo b_emlrtECI = { -1, 799, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 799, 24, "batPwrOptTn4", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 745, 66, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 745, 50, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 745, 34, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 202, 32, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 202, 32, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 202, 24, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 202, 14, "fulEngPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 202, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 730, 66, "colminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 730, 50, "colminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 729, 35, "matminidx", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 711, 39, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 711, 39, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 713, 48, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 713, 48, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 187, 32, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 187, 32, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 187, 24, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 187, 14, "cos2goPreTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 187, 14, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo u_emlrtBCI = { 1, 693, 564, 45, "batOcv", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 564, 45, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 547, 48, "batStaPreIdxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { 1, 1181, 510, 60, "iceTrqMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { 1, 1181, 509, 60, "iceTrqMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { 1, 1181, 504, 56, "emoPwrMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { 1, 1181, 503, 56, "emoPwrMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { 1, 1181, 500, 56, "emoTrqMaxPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { 1, 1181, 499, 56, "emoTrqMinPosMat",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { 1, 1181, 497, 47, "crsTrqMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { 1, 6, 496, 57, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 496, 57, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo fb_emlrtBCI = { 1, 1181, 496, 47, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { 1, 1181, 433, 73, "batPwrMaxIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { 1, 693, 432, 83, "batPwrMinIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { 1, 1181, 432, 73, "batPwrMinIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { 1, 6, 326, 21, "crsSpdActVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 326, 21, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo kb_emlrtBCI = { 1, 6, 313, 21, "crsSpdActVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 313, 21, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtRTEInfo m_emlrtRTEI = { 303, 9, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 299, 5, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtBCInfo lb_emlrtBCI = { 1, 1181, 294, 30, "crsSpdMat", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { 1, 1181, 284, 20, "engStaVec_timInx",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 284, 20, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtRTEInfo o_emlrtRTEI = { 245, 1, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m"
};

static emlrtDCInfo p_emlrtDCI = { 158, 22, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo q_emlrtDCI = { 158, 22, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo r_emlrtDCI = { 158, 30, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo s_emlrtDCI = { 158, 30, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo t_emlrtDCI = { 158, 38, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo u_emlrtDCI = { 158, 38, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtDCInfo v_emlrtDCI = { 158, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtDCInfo w_emlrtDCI = { 158, 46, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  4 };

static emlrtBCInfo nb_emlrtBCI = { 1, 1181, 289, 18, "velVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo x_emlrtDCI = { 289, 18, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ob_emlrtBCI = { 1, 1181, 289, 35, "velVec", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo y_emlrtDCI = { 289, 35, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 338, 29, "batStaActInxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 749, 34, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo ab_emlrtDCI = { 749, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 749, 46, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 749, 56, "cos2goActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 753, 34, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo bb_emlrtDCI = { 753, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 753, 46, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 753, 56, "batEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 757, 34, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 757, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 757, 46, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 757, 56, "fulEngActTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 763, 34, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 763, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 763, 46, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 763, 56, "batPwrOptTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 768, 34, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 768, 34, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 768, 46, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 768, 56, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 768, 69, "optPreInxTn4",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 463, 33, "engStaPreIdx",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 475, 37, "geaStaPreIdxVec",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo jc_emlrtBCI = { 1, 1181, 652, 66, "batPwrDemIdxTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 711, 52, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 711, 66, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 711, 66, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 713, 61, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 713, 72, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 713, 72, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 595, 43, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 595, 43, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 595, 56, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 595, 69, "fulActTn3", "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 597, 52, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 597, 52, "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  1 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 597, 64, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 597, 75, "cos2goPreTn3",
  "clcDP_focus",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\ford_focus\\DP\\clcDP_focus.m",
  0 };

static emlrtRSInfo mb_emlrtRSI = { 28, "assert",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\assert.m"
};

static emlrtRSInfo nb_emlrtRSI = { 81, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ob_emlrtRSI = { 38, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo pb_emlrtRSI = { 404, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo rb_emlrtRSI = { 82, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo sb_emlrtRSI = { 41, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo tb_emlrtRSI = { 405, "colon",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

/* Function Declarations */
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);

/* Function Definitions */
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

void clcDP_focus(const emlrtStack *sp, real_T disFlg, real_T iceFlgBool, real_T
                 brkBool, real_T timStp, real_T batEngBeg, real_T batPwrAux,
                 real_T staChgPenCosVal, real_T timInxBeg, real_T timInxEnd,
                 real_T timNum, real_T engBeg, const real_T engStaVec_timInx
                 [1181], real_T staBeg, const real_T batOcv[693], const real_T
                 velVec[1181], const real_T crsSpdMat[7086], const real_T
                 crsTrqMat[7086], const real_T emoTrqMinPosMat[7086], const
                 real_T emoTrqMaxPosMat[7086], const real_T emoPwrMinPosMat[7086],
                 const real_T emoPwrMaxPosMat[7086], const real_T
                 iceTrqMinPosMat[7086], const real_T iceTrqMaxPosMat[7086],
                 const real_T batPwrMinIdxTn3[4910598], const real_T
                 batPwrMaxIdxTn3[4910598], const real_T batPwrDemIdxTn3[4910598],
                 const struct0_T *tst_scalar_struct, const struct1_T
                 *fzg_scalar_struct, const struct2_T *fzg_array_struct,
                 emxArray_real_T *optPreInxTn4, emxArray_real_T *batPwrOptTn4,
                 emxArray_real_T *fulEngOptTn4, emxArray_real_T *cos2goActTn3)
{
  int32_T i0;
  real_T ndbl;
  real_T batEngIdxBeg;
  real_T batStaLimMax;
  real_T absa;
  int32_T iy;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T npages;
  int32_T n;
  int32_T i4;
  int32_T i5;
  emxArray_real_T *cos2goPreTn3;
  emxArray_real_T *fulEngPreTn3;
  real_T geaStaChgPenCos;
  real_T apnd;
  boolean_T overflow;
  real_T cdiff;
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
  real_T crsSpdEmoMax;
  real_T b_crsSpdHybMax;
  real_T b_crsSpdHybMin;
  int32_T timInx;
  emxArray_real_T *batPwrOptTn3;
  emxArray_real_T *batEngActTn3;
  emxArray_real_T *fulEngActTn3;
  emxArray_real_T *fulActTn3;
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
  int32_T geaStaPreMin;
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 21 };

  const mxArray *d_y;
  static const int32_T iv2[2] = { 1, 21 };

  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T ixstop;
  int32_T cindx;
  int32_T ix;
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
  boolean_T b_geaStaPreMin;
  boolean_T exitg3;
  boolean_T b_nm1d2;
  const mxArray *g_y;
  static const int32_T iv5[2] = { 1, 36 };

  const mxArray *h_y;
  static const int32_T iv6[2] = { 1, 39 };

  boolean_T b1;
  boolean_T c_geaStaPreMin;
  boolean_T exitg2;
  boolean_T c_nm1d2;
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
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  (void)batPwrAux;
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
  /*  Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  --- Eingangsgrï¿½ï¿½en: */
  /*  Skalar - Flag fï¿½r Ausgabe in das Commandwindow */
  /*  bool - define if engine off-on can be toggled */
  /*  skalar - allow states requireing braking? */
  /*  Skalar fï¿½r die Wegschrittweite in m */
  /*  Skalar fï¿½r die Batterieenergie am Beginn in Ws */
  /*  Skalar fï¿½r die Nebenverbrauchlast in W */
  /*  Skalar fï¿½r die Strafkosten beim Zustandswechsel */
  /*  Skalar fï¿½r Anfangsindex in den Eingangsdaten */
  /*  Skalar fï¿½r Endindex in den Eingangsdaten */
  /*  Skalar fï¿½r die Stufe der Batteriekraftmax. Anzahl an Wegstï¿½tzstellen */
  /*  scalar - beginnnig engine state */
  /*  scalar - end engine state */
  /*  Skalar fï¿½r den Startzustand des Antriebsstrangs */
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
  /*  Mittelwerte, d.h. FlussgrÃ¶ÃŸen wie KrÃ¤fte, Leistungen etc., stehen immmer */
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

    /*  Fahrzeugmasse */
    /*      vehMas = fzg_scalar_struct.vehMas; */
    /*  minmiale und maximale Beschleunigung */
    /*    min and max accerlations (bounds) */
    /*      vehAccMin = fzg_scalar_struct.vehAccMin; */
    /*      vehAccMax = fzg_scalar_struct.vehAccMax; */
    /*  In dieser Version ist der Motor immer an */
    /*  not anymore - iceFlg is whatever is in mainConfig.txt */
    /*      iceFlg = true; */
    iceFlg = iceFlgBool;
  }

  /* % Initialisieren der Ausgabe der Funktion */
  /*    initialzing function output */
  /*  Tensor 3. Stufe fï¿½r optimalen VorgÃ¤ngerkoordinaten */
  /*    tensor3 for optimal previous coordinates/idx */
  /*  IS NOT MAT SINCE KE IS NO LONGER CONSIDERED - REDUCES A DIMENSION */
  /*    - back to being a tensor - adding engine control dimension */
  i0 = optPreInxTn4->size[0] * optPreInxTn4->size[1] * optPreInxTn4->size[2] *
    optPreInxTn4->size[3];
  ndbl = emlrtNonNegativeCheckFastR2012b(engNum, &q_emlrtDCI, sp);
  optPreInxTn4->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &p_emlrtDCI,
    sp);
  ndbl = emlrtNonNegativeCheckFastR2012b(geaNum, &s_emlrtDCI, sp);
  optPreInxTn4->size[1] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &r_emlrtDCI,
    sp);
  ndbl = emlrtNonNegativeCheckFastR2012b(batNum, &u_emlrtDCI, sp);
  optPreInxTn4->size[2] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &t_emlrtDCI,
    sp);
  ndbl = emlrtNonNegativeCheckFastR2012b(timNum, &w_emlrtDCI, sp);
  optPreInxTn4->size[3] = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &v_emlrtDCI,
    sp);
  emxEnsureCapacity(sp, (emxArray__common *)optPreInxTn4, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ndbl = emlrtNonNegativeCheckFastR2012b(engNum, &q_emlrtDCI, sp);
  batEngIdxBeg = emlrtNonNegativeCheckFastR2012b(geaNum, &s_emlrtDCI, sp);
  batStaLimMax = emlrtNonNegativeCheckFastR2012b(batNum, &u_emlrtDCI, sp);
  absa = emlrtNonNegativeCheckFastR2012b(timNum, &w_emlrtDCI, sp);
  iy = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &p_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batEngIdxBeg, &r_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(batStaLimMax, &t_emlrtDCI, sp) * (int32_T)
    emlrtIntegerCheckFastR2012b(absa, &v_emlrtDCI, sp);
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

  /*    set initial fuel energy level to 0 */
  /*    Note: batEngIdxBeg is a scaled down energy value index, NOT a vector */
  /*    index. Keep this in mind later when manipulating batEng index bounds. */
  batEngIdxBeg = batEngBeg / batStaStp;
  i0 = (int32_T)timNum;
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(timInxBeg, &emlrtDCI, sp);
  i2 = (int32_T)batNum;
  i3 = (int32_T)emlrtIntegerCheckFastR2012b(batEngIdxBeg + 1.0, &b_emlrtDCI, sp);
  npages = (int32_T)geaNum;
  n = (int32_T)emlrtIntegerCheckFastR2012b(staBeg, &c_emlrtDCI, sp);
  i4 = (int32_T)engNum;
  i5 = (int32_T)emlrtIntegerCheckFastR2012b(engBeg + 1.0, &d_emlrtDCI, sp);
  fulEngOptTn4->data[(((emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &e_emlrtBCI,
    sp) + fulEngOptTn4->size[0] * (emlrtDynamicBoundsCheckFastR2012b(n, 1,
    npages, &d_emlrtBCI, sp) - 1)) + fulEngOptTn4->size[0] * fulEngOptTn4->size
                       [1] * (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2,
    &c_emlrtBCI, sp) - 1)) + fulEngOptTn4->size[0] * fulEngOptTn4->size[1] *
                      fulEngOptTn4->size[2] * (emlrtDynamicBoundsCheckFastR2012b
                       (i1, 1, i0, &b_emlrtBCI, sp) - 1)) - 1] = 0.0;

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
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngIdxBeg + 1.0, &i_emlrtDCI, sp);
  i2 = (int32_T)geaNum;
  i3 = (int32_T)staBeg;
  npages = (int32_T)engNum;
  n = (int32_T)emlrtIntegerCheckFastR2012b(engBeg + 1.0, &j_emlrtDCI, sp);
  cos2goPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b(n, 1, npages,
    &t_emlrtBCI, sp) + cos2goPreTn3->size[0] *
                       (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &s_emlrtBCI,
    sp) - 1)) + cos2goPreTn3->size[0] * cos2goPreTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &r_emlrtBCI,
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
  i1 = (int32_T)emlrtIntegerCheckFastR2012b(batEngIdxBeg + 1.0, &e_emlrtDCI, sp);
  i2 = (int32_T)geaNum;
  i3 = (int32_T)staBeg;
  npages = (int32_T)engNum;
  n = (int32_T)emlrtIntegerCheckFastR2012b(engBeg + 1.0, &f_emlrtDCI, sp);
  fulEngPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b(n, 1, npages,
    &l_emlrtBCI, sp) + fulEngPreTn3->size[0] *
                       (emlrtDynamicBoundsCheckFastR2012b(i3, 1, i2, &k_emlrtBCI,
    sp) - 1)) + fulEngPreTn3->size[0] * fulEngPreTn3->size[1] *
                      (emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &j_emlrtBCI,
    sp) - 1)) - 1] = 0.0;

  /*  define a vector for containing the values of engine control off-on */
  /*  engStaMat_geaNum_timInx = zeros(1, timInxEnd); */
  /*  define battery vector to be used for looping */
  batEngIdxBeg = batStaMin / batStaStp;
  batStaLimMax = batStaMax / batStaStp;
  st.site = &emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (muDoubleScalarIsNaN(batEngIdxBeg) || muDoubleScalarIsNaN(batStaLimMax)) {
    n = 0;
    geaStaChgPenCos = rtNaN;
    apnd = batStaLimMax;
    overflow = false;
  } else if (batStaLimMax < batEngIdxBeg) {
    n = -1;
    geaStaChgPenCos = batEngIdxBeg;
    apnd = batStaLimMax;
    overflow = false;
  } else if (muDoubleScalarIsInf(batEngIdxBeg) || muDoubleScalarIsInf
             (batStaLimMax)) {
    n = 0;
    geaStaChgPenCos = rtNaN;
    apnd = batStaLimMax;
    overflow = !(batEngIdxBeg == batStaLimMax);
  } else {
    geaStaChgPenCos = batEngIdxBeg;
    ndbl = muDoubleScalarFloor((batStaLimMax - batEngIdxBeg) + 0.5);
    apnd = batEngIdxBeg + ndbl;
    cdiff = apnd - batStaLimMax;
    absa = muDoubleScalarAbs(batEngIdxBeg);
    absb = muDoubleScalarAbs(batStaLimMax);
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
        (absa, absb)) {
      ndbl++;
      apnd = batStaLimMax;
    } else if (cdiff > 0.0) {
      apnd = batEngIdxBeg + (ndbl - 1.0);
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
    e_st.site = &pb_emlrtRSI;
    f_st.site = &tb_emlrtRSI;
    error(&e_st, message(&f_st, y, &emlrtMCI), &b_emlrtMCI);
  }

  b_emxInit_real_T(&d_st, &batStaActInxVec, 2, &f_emlrtRTEI, true);
  i0 = batStaActInxVec->size[0] * batStaActInxVec->size[1];
  batStaActInxVec->size[0] = 1;
  batStaActInxVec->size[1] = n + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)batStaActInxVec, i0, (int32_T)
                    sizeof(real_T), &b_emlrtRTEI);
  if (n + 1 > 0) {
    batStaActInxVec->data[0] = geaStaChgPenCos;
    if (n + 1 > 1) {
      batStaActInxVec->data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        nm1d2 = (int32_T)((uint32_T)i0 >> 1);
      } else {
        nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
      }

      d_st.site = &o_emlrtRSI;
      for (iy = 1; iy < nm1d2; iy++) {
        batStaActInxVec->data[iy] = geaStaChgPenCos + (real_T)iy;
        batStaActInxVec->data[n - iy] = apnd - (real_T)iy;
      }

      if (nm1d2 << 1 == n) {
        batStaActInxVec->data[nm1d2] = (geaStaChgPenCos + apnd) / 2.0;
      } else {
        batStaActInxVec->data[nm1d2] = geaStaChgPenCos + (real_T)nm1d2;
        batStaActInxVec->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
      }
    }
  }

  /*  Schleife über alle Wegpunkte */
  /*    looping thorugh length of # of discretized tim vector */
  /*  % starting battery energy state - SWITCHING TO AN VECTOR INDEX BY ADDNIG 1 */
  /*  % THIS MEANS WORK WITH VECTOR INDEXES LATER when defining batEng bounds */
  /*  batStaPreOptInx = batEngIdxBeg + 1; */
  /*  ----- Initialisieren der persistent Größen ------------------------------ */
  /*    initialize the persistance variables */
  /*  Diese werden die nur einmal fÜr die Funktion berechnet */
  /*    only calculated once for the function */
  /*  persistent crsSpdHybMax crsSpdHybMin crsSpdEmoMax */
  /*   */
  /*  if isempty(crsSpdHybMax) */
  /*       */
  /*  maximale Drehzahl Elektrommotor */
  /*    maximum electric motor rotational speed */
  crsSpdEmoMax = fzg_array_struct->emoSpdMgd[72];

  /*  maximale Drehzahl der Kurbelwelle */
  /*    maximum crankshaft rotational speed */
  /*  12.07.2016 - IF THIS IS FINDING THE HYBRID MAX CRS SPEED, THEN WHY */
  /*  ARE WE SECTNIG THE MINIMUM RATHER THAN THE MAXIMUM? IS IT BECAUSE THE */
  /*  EM CAN ONLY ROTATE SO FAST?? OTHERWISE WHY NOT LET THE ICE TAKE OVER? */
  b_crsSpdHybMax = muDoubleScalarMin(fzg_array_struct->iceSpdMgd[23],
    fzg_array_struct->emoSpdMgd[72]);

  /*  minimale Drehzahl der Kurbelwelle */
  /*    minimum crankshaft rotational speed */
  b_crsSpdHybMin = fzg_array_struct->iceSpdMgd[0];

  /*  end */
  /*  ------------------------------------------------------------------------- */
  /*  for timInx = timInxBeg+1 : timStp : 60      % TIME IDX LOOP */
  i0 = (int32_T)((timInxEnd + (timStp - (timInxBeg + 1.0))) / timStp);
  emlrtForLoopVectorCheckR2012b(timInxBeg + 1.0, timStp, timInxEnd,
    mxDOUBLE_CLASS, i0, &o_emlrtRTEI, sp);
  timInx = 0;
  emxInit_real_T(sp, &batPwrOptTn3, 3, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &batEngActTn3, 3, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngActTn3, 3, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &fulActTn3, 3, &j_emlrtRTEI, true);
  b_emxInit_real_T(sp, &batStaPreIdxVec, 2, &k_emlrtRTEI, true);
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
    b_timInx = (timInxBeg + 1.0) + (real_T)timInx * timStp;

    /*  TIME IDX LOOP */
    /*       */
    /*  for timInx = timInxBeg+1 : timStp : 5 */
    /*  for timInx = timInxBeg+1 : timStp : 1159 */
    /*  mittlere Steigung im betrachteten Intervall  */
    /*    no longer doing mean, using previous gradiant instead */
    /*      slp = slpVec_timInx(timInx-1); */
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

    /*  possible engine state changes for current and past path_idxs */
    ndbl = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &o_emlrtDCI, sp);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &mb_emlrtBCI, sp);

    /*  and the previous idx KE */
    /*      engStaNumAct = engStaVec_timInx(timInx);   % look at this loop's KE */
    /*  create vector storing current and previous velocity info */
    /*  check later if you can remove this */
    ndbl = b_timInx - 1.0;
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &x_emlrtDCI, sp);
    vehVelVec[0] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &nb_emlrtBCI, sp) - 1];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_timInx, &y_emlrtDCI, sp);
    vehVelVec[1] = velVec[emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181,
      &ob_emlrtBCI, sp) - 1];

    /*  save current and previous crankshaft speed vectors for boundary */
    /*  checks when looping through gear states */
    i1 = (int32_T)(b_timInx - 1.0);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1181, &lb_emlrtBCI, sp);

    /* % ----- CURRENT STATE VARIBALE LOOP -------------------------------------- */
    /*   go through the possible engine state on-off possibilities */
    /*    checking if the engine can be off or on for this index */
    b_engStaMin = engStaMin;
    i1 = (int32_T)(engStaMax + (1.0 - engStaMin));
    emlrtForLoopVectorCheckR2012b(engStaMin, 1.0, engStaMax, mxDOUBLE_CLASS, i1,
      &n_emlrtRTEI, sp);
    engStaAct = 0;
    while (engStaAct <= i1 - 1) {
      b_engStaAct = b_engStaMin + (real_T)engStaAct;

      /*  CURRENT ENGINE STATE LOOP                 */
      /*  Schleife über alle moglichen aktuellen Zustände des Antriesstrangs */
      /*    Loop over all possible current powertrain states/all the gears */
      b_geaStaMin = geaStaMin;
      i2 = (int32_T)(geaStaMax + (1.0 - geaStaMin));
      emlrtForLoopVectorCheckR2012b(geaStaMin, 1.0, geaStaMax, mxDOUBLE_CLASS,
        i2, &m_emlrtRTEI, sp);
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
          i3 = (int32_T)emlrtIntegerCheckFastR2012b(b_geaStaAct, &n_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &kb_emlrtBCI, sp);
          if ((crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)b_geaStaAct - 1))
               - 1] > b_crsSpdHybMax) || (crsSpdMat[((int32_T)b_timInx + 1181 *
                ((int32_T)b_geaStaAct - 1)) - 1] < b_crsSpdHybMin)) {
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
          i3 = (int32_T)emlrtIntegerCheckFastR2012b(b_geaStaAct, &m_emlrtDCI, sp);
          emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &jb_emlrtBCI, sp);
          if (crsSpdMat[((int32_T)b_timInx + 1181 * ((int32_T)b_geaStaAct - 1))
              - 1] > crsSpdEmoMax) {
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          /*  ------------------------------------------------------------------------- */
          /*  loop over all possible current battery values */
          batStaActInx = 0;
          while (batStaActInx <= batStaActInxVec->size[1] - 1) {
            /*                 %% Initialisieren */
            /*    note-you are preallocating over each state permutation */
            /*  convert batStaActInx back into actual batEng */
            i3 = batStaActInxVec->size[1];
            npages = 1 + batStaActInx;
            batStaAct = batStaActInxVec->data[emlrtDynamicBoundsCheckFastR2012b
              (npages, 1, i3, &pb_emlrtBCI, sp) - 1] * batStaStp;

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

            /*  Initialisieren der Ausgabegröße der Schleife */
            /*                  %   preallocate the loop's output size */
            /*                  minFul = inf; */
            /*  %  */
            /*  %                 % Initialisieren der Variable für den optimalen Zustandsindex */
            /*  %                 %   initializing variable for optimal state index */
            /*                  geaStaPreOptInx = 0; */
            /*  %  */
            /*  %                 % initialize variable for optimal previous idx engine control */
            /*                  engStaPreOptInx = 0; */
            /*  %                  */
            /*  %                 % initialize variable for optimal previous bat level */
            /*  %                 batStaPreInx = 0; */
            /*  %                 % Initialisieren der optimalen Kraftstoffenergieänderung zum */
            /*  %                 % betrachteten Punkt */
            /*  %                 %   preallocate the optimum fuel energy change to the point */
            /*  %                 %   considered */
            /*                  fulEngOpt = inf; */
            /*  %                  */
            /*  %                 % Initialisieren der optimalen Batterieenergie zum */
            /*  %                 % betrachteten Punkt */
            /*  %                 %   initialize the optimal battery energy (up to boundry limits) */
            /*                  batEngOpt = inf; */
            /*                   */
            /*  initialize optimal torques */
            /*                  emoTrqOpt = inf; */
            /*                  iceTrqOpt = inf; */
            /*                  brkTrqOpt = inf; */
            /*  */
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

            /*                 %% Vorgï¿½ngerzustï¿½nde beschrÃ¤nken */
            /*    Restrictions on predecessor operation states */
            /*  Festlegen, welche Vorgänger möglich sind: */
            /*  Es sind im Maximum die Anzahl der Gänge +  1 als VorgÃ¤nger */
            /*  möglich, denn vom Segeln kann in jeden Gang im elektrischen */
            /*  Fahren und Segeln gewechselt  werden */
            /*    Determine which predecessors are possible: */
            /*    There are at maximum 'number of gears'+1 possible for the */
            /*    predecessors, because from the sail in every Gear in */
            /*    electric travel and the sails will be changed (???) */
            /*  Vorgï¿½ngerzustï¿½nde des Antriebsstrangs beschrÃ¤nken */
            /*    determine gear possibilities - ie u(g)  */
            geaStaPreMin = (int32_T)muDoubleScalarMax(1.0, b_geaStaAct - 1.0);
            batEngIdxBeg = muDoubleScalarMin(geaNum, b_geaStaAct + 1.0);
            st.site = &b_emlrtRSI;
            b_st.site = &l_emlrtRSI;
            c_st.site = &m_emlrtRSI;
            if (muDoubleScalarIsNaN(batEngIdxBeg)) {
              n = 0;
              geaStaChgPenCos = rtNaN;
              apnd = batEngIdxBeg;
              overflow = false;
            } else if (batEngIdxBeg < geaStaPreMin) {
              n = -1;
              geaStaChgPenCos = geaStaPreMin;
              apnd = batEngIdxBeg;
              overflow = false;
            } else if (muDoubleScalarIsInf(batEngIdxBeg)) {
              n = 0;
              geaStaChgPenCos = rtNaN;
              apnd = batEngIdxBeg;
              overflow = !(geaStaPreMin == batEngIdxBeg);
            } else {
              geaStaChgPenCos = geaStaPreMin;
              ndbl = muDoubleScalarFloor((batEngIdxBeg - (real_T)geaStaPreMin) +
                0.5);
              apnd = (real_T)geaStaPreMin + ndbl;
              cdiff = apnd - batEngIdxBeg;
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                  muDoubleScalarMax(geaStaPreMin, batEngIdxBeg)) {
                ndbl++;
                apnd = batEngIdxBeg;
              } else if (cdiff > 0.0) {
                apnd = (real_T)geaStaPreMin + (ndbl - 1.0);
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

            d_st.site = &n_emlrtRSI;
            if (!overflow) {
            } else {
              c_y = NULL;
              m0 = emlrtCreateCharArray(2, iv1);
              for (i = 0; i < 21; i++) {
                cv0[i] = cv1[i];
              }

              emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
              emlrtAssign(&c_y, m0);
              e_st.site = &pb_emlrtRSI;
              f_st.site = &tb_emlrtRSI;
              error(&e_st, message(&f_st, c_y, &emlrtMCI), &b_emlrtMCI);
            }

            i3 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = 1;
            b_y->size[1] = n + 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)b_y, i3, (int32_T)
                              sizeof(real_T), &b_emlrtRTEI);
            if (n + 1 > 0) {
              b_y->data[0] = geaStaChgPenCos;
              if (n + 1 > 1) {
                b_y->data[n] = apnd;
                i3 = n + (n < 0);
                if (i3 >= 0) {
                  nm1d2 = (int32_T)((uint32_T)i3 >> 1);
                } else {
                  nm1d2 = (int32_T)~(~(uint32_T)i3 >> 1);
                }

                d_st.site = &o_emlrtRSI;
                for (iy = 1; iy < nm1d2; iy++) {
                  b_y->data[iy] = geaStaChgPenCos + (real_T)iy;
                  b_y->data[n - iy] = apnd - (real_T)iy;
                }

                if (nm1d2 << 1 == n) {
                  b_y->data[nm1d2] = (geaStaChgPenCos + apnd) / 2.0;
                } else {
                  b_y->data[nm1d2] = geaStaChgPenCos + (real_T)nm1d2;
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
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &ib_emlrtBCI, sp);
            i3 = batStaActInx + 1;
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 693, &hb_emlrtBCI, sp);
            i3 = (int32_T)(b_timInx - 1.0);
            emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &gb_emlrtBCI, sp);

            /*  battery power limits given by max/min battery power */
            /*  discharge (a given model input value) */
            /*    ie change in E cannot exceed bat power levels (P=E'/t') */
            /*  find the most constraining change in batEng based on */
            /*  previous limitations */
            /*  MAKE IT SO THAT ZOU ARE WORKING FROM CURRENT BATTERY */
            /*  STATE, NOT FROM SCRATCH!!! */
            /*  make vector of these batEng state steps for a loop */
            batEngIdxBeg = muDoubleScalarMax(batStaMin / batStaStp + 1.0,
              muDoubleScalarMax((1.0 + (real_T)batStaActInx) +
                                fzg_scalar_struct->batPwrMin * timStp /
                                batStaStp, (1.0 + (real_T)batStaActInx) +
                                batPwrMinIdxTn3[(((int32_T)b_timInx + 1181 *
              batStaActInx) + 818433 * ((int32_T)b_geaStaAct - 1)) - 2]));
            batStaLimMax = muDoubleScalarMin(batStaMax / batStaStp + 1.0,
              muDoubleScalarMin((1.0 + (real_T)batStaActInx) +
                                fzg_scalar_struct->batPwrMax * timStp /
                                batStaStp, (1.0 + (real_T)batStaActInx) +
                                batPwrMaxIdxTn3[(((int32_T)b_timInx + 1181 *
              batStaActInx) + 818433 * ((int32_T)b_geaStaAct - 1)) - 2]));

            /*  if the min limit exceeds the max limit, then set them */
            /*  equal. */
            if (batEngIdxBeg > batStaLimMax) {
              batEngIdxBeg = batStaLimMax;
            }

            st.site = &c_emlrtRSI;
            b_st.site = &l_emlrtRSI;
            c_st.site = &m_emlrtRSI;
            if (muDoubleScalarIsNaN(batEngIdxBeg) || muDoubleScalarIsNaN
                (batStaLimMax)) {
              n = 0;
              geaStaChgPenCos = rtNaN;
              apnd = batStaLimMax;
              overflow = false;
            } else if (batStaLimMax < batEngIdxBeg) {
              n = -1;
              geaStaChgPenCos = batEngIdxBeg;
              apnd = batStaLimMax;
              overflow = false;
            } else if (muDoubleScalarIsInf(batEngIdxBeg) || muDoubleScalarIsInf
                       (batStaLimMax)) {
              n = 0;
              geaStaChgPenCos = rtNaN;
              apnd = batStaLimMax;
              overflow = !(batEngIdxBeg == batStaLimMax);
            } else {
              geaStaChgPenCos = batEngIdxBeg;
              ndbl = muDoubleScalarFloor((batStaLimMax - batEngIdxBeg) + 0.5);
              apnd = batEngIdxBeg + ndbl;
              cdiff = apnd - batStaLimMax;
              absa = muDoubleScalarAbs(batEngIdxBeg);
              absb = muDoubleScalarAbs(batStaLimMax);
              if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                  muDoubleScalarMax(absa, absb)) {
                ndbl++;
                apnd = batStaLimMax;
              } else if (cdiff > 0.0) {
                apnd = batEngIdxBeg + (ndbl - 1.0);
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
              d_y = NULL;
              m0 = emlrtCreateCharArray(2, iv2);
              for (i = 0; i < 21; i++) {
                cv0[i] = cv1[i];
              }

              emlrtInitCharArrayR2013a(&d_st, 21, m0, cv0);
              emlrtAssign(&d_y, m0);
              e_st.site = &pb_emlrtRSI;
              f_st.site = &tb_emlrtRSI;
              error(&e_st, message(&f_st, d_y, &emlrtMCI), &b_emlrtMCI);
            }

            i3 = batStaPreIdxVec->size[0] * batStaPreIdxVec->size[1];
            batStaPreIdxVec->size[0] = 1;
            batStaPreIdxVec->size[1] = n + 1;
            emxEnsureCapacity(&c_st, (emxArray__common *)batStaPreIdxVec, i3,
                              (int32_T)sizeof(real_T), &b_emlrtRTEI);
            if (n + 1 > 0) {
              batStaPreIdxVec->data[0] = geaStaChgPenCos;
              if (n + 1 > 1) {
                batStaPreIdxVec->data[n] = apnd;
                i3 = n + (n < 0);
                if (i3 >= 0) {
                  nm1d2 = (int32_T)((uint32_T)i3 >> 1);
                } else {
                  nm1d2 = (int32_T)~(~(uint32_T)i3 >> 1);
                }

                d_st.site = &o_emlrtRSI;
                for (iy = 1; iy < nm1d2; iy++) {
                  batStaPreIdxVec->data[iy] = geaStaChgPenCos + (real_T)iy;
                  batStaPreIdxVec->data[n - iy] = apnd - (real_T)iy;
                }

                if (nm1d2 << 1 == n) {
                  batStaPreIdxVec->data[nm1d2] = (geaStaChgPenCos + apnd) / 2.0;
                } else {
                  batStaPreIdxVec->data[nm1d2] = geaStaChgPenCos + (real_T)nm1d2;
                  batStaPreIdxVec->data[nm1d2 + 1] = apnd - (real_T)nm1d2;
                }
              }
            }

            /*  ------------------------------------------------------------------------- */
            /* % ----- PREDECESSOR STATE VARIBALE LOOP ---------------------------------- */
            /*  PREVIOUS gear state loop */
            geaStaPreMin = 0;
            while (geaStaPreMin <= engStaPreIdx_size_idx_1 - 1) {
              i3 = 1 + geaStaPreMin;
              batStaLimMax = engStaPreIdx_data[emlrtDynamicBoundsCheckFastR2012b
                (i3, 1, engStaPreIdx_size_idx_1, &hc_emlrtBCI, sp) - 1];

              /*  engine state penalty */
              if (b_engStaAct == engStaPreIdx_data[geaStaPreMin]) {
                absb = 0.0;
              } else {
                absb = staChgPenCosVal;
              }

              /*  penalty for changning battery level or no? */
              /*  Schleife über allen Zustände (relativer Index) */
              /*    Loop through all the gear states (relative index) */
              nm1d2 = 0;
              while (nm1d2 <= b_y->size[1] - 1) {
                /*  PREVIOUS GEAR CHANGE LOOP */
                i3 = b_y->size[1];
                npages = 1 + nm1d2;
                absa = b_y->data[emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3,
                  &ic_emlrtBCI, sp) - 1];

                /*  Kosten für Zustandswechsel setzen */
                /*    set costs for gear state changes */
                if (b_geaStaAct == b_y->data[nm1d2]) {
                  /*  Entspricht der Vorgï¿½ngerzustand dem aktuellen  */
                  /*  Zustand werden keine Kosten gesetzt */
                  /*    staying in current state? set penalty cost to 0 */
                  geaStaChgPenCos = 0.0;
                } else {
                  /*  Ansonsten einfache Zustandswechselkosten */
                  /*  berechnen */
                  /*    otherwise apply a penalty cost to changing gear */
                  geaStaChgPenCos = staChgPenCosVal;

                  /* <-penCos is input */
                }

                /*                         %% check if engStaPre == 0. */
                /*  if == 0 - ignore bat state loop bc emoTrq==crsTrq */
                /*    b/c anything else is not optimal (w/ brakes) */
                /*  if == 1 - then run through bat state loop */
                /*  pull out appropriate crankshaft speed and torque */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &fb_emlrtBCI, sp);
                ndbl = b_y->data[nm1d2];
                i3 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl, &l_emlrtDCI, sp);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 6, &eb_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &db_emlrtBCI, sp);

                /*  all EM torque boundaries for given gear */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &cb_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &bb_emlrtBCI, sp);

                /*                        % emoTrqMaxPosMat(:, geaStaPre); */
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &ab_emlrtBCI, sp);
                i3 = (int32_T)(b_timInx - 1.0);
                emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &y_emlrtBCI, sp);

                /*  IF ENGINE WAS ON */
                if (batStaLimMax != 0.0) {
                  /*  all ICE torque boundaries for given gear */
                  i3 = (int32_T)(b_timInx - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &x_emlrtBCI, sp);
                  i3 = (int32_T)(b_timInx - 1.0);
                  emlrtDynamicBoundsCheckFastR2012b(i3, 1, 1181, &w_emlrtBCI, sp);

                  /*  ----- CRANKSHAFT SPEED BOUNDARY CHECKS ------ */
                  /*  boundaries: since crsSpd is dependent on gear,  */
                  /*  check is performed within the gear state loop */
                  /*  IF ENGINE IS ON: */
                  /*  Abbruch, wenn die Drehzahlen der Kurbelwelle  */
                  /*  zu hoch im hybridischen */
                  /*  Modus */
                  /*    stop if the crankshaft rotational speed is  */
                  /*    too high in hybrid mode */
                  i3 = (int32_T)b_y->data[nm1d2] - 1;
                  if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] >
                      b_crsSpdHybMax) {
                  } else {
                    /*  Falls die Drehzahl des Verbrennungsmotors niedriger als die */
                    /*  Leerlaufdrehzahl ist, */
                    /*    stop if crankhaft rotional speed is lower than the idling speed */
                    i3 = (int32_T)b_y->data[nm1d2] - 1;
                    if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] <
                        b_crsSpdHybMin) {
                    } else {
                      iy = 0;
                      while (iy <= batStaPreIdxVec->size[1] - 1) {
                        /*  value of previous idx engine control state */
                        /*   - unnecessary to assign - indexes represent bool values */
                        /*  loop through all possible previous battery levels */
                        /*  calculate index for bat state - can move */
                        /*  outside for loop for improving computation tim later */
                        /*  because batSTaPreIdx is coming from an index vector from */
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
                        npages = iy + 1;
                        emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3,
                          &v_emlrtBCI, sp);

                        /*  calculate E' */
                        batEngIdxBeg = batStaAct - (batStaPreIdxVec->data[iy] -
                          1.0) * batStaStp;

                        /*  calculate battery resistance */
                        /*  the code below is performing this code snippet across the vector */
                        /*  if batPwr < 0 */
                        /*      batRst = fzg_scalar_struct.batRstDch; */
                        /*  else */
                        /*      batRst = fzg_scalar_struct.batRstChr; */
                        /*  end */
                        /*  lookup previous bat state's voltage value */
                        ndbl = batStaPreIdxVec->data[iy];
                        i3 = (int32_T)emlrtIntegerCheckFastR2012b(ndbl,
                          &k_emlrtDCI, sp);
                        emlrtDynamicBoundsCheckFastR2012b(i3, 1, 693,
                          &u_emlrtBCI, sp);

                        /*                                 %% Berechnung der optimalen Kosten zum aktuellen Punkt */
                        /*    calculating optimal cost to the current point */
                        /*  do it tim interval at a tim? will remove vector */
                        /*  aspects */
                        /*                              [minFul, emoTrq, iceTrq, brkTrq] =... */
                        st.site = &d_emlrtRSI;
                        batEngIdxBeg = optTrqSplit_focus(&st, brkBool,
                          batEngIdxBeg, batOcv[(int32_T)batStaPreIdxVec->data[iy]
                          - 1], (real_T)(batEngIdxBeg < 0.0) *
                          fzg_scalar_struct->batRstDch + (real_T)(batEngIdxBeg >=
                          0.0) * fzg_scalar_struct->batRstChr, crsSpdMat
                          [((int32_T)b_timInx + 1181 * ((int32_T)absa - 1)) - 2],
                          crsTrqMat[((int32_T)b_timInx + 1181 * ((int32_T)absa -
                          1)) - 2], emoTrqMinPosMat[((int32_T)b_timInx + 1181 *
                          ((int32_T)absa - 1)) - 2], emoTrqMaxPosMat[((int32_T)
                          b_timInx + 1181 * ((int32_T)absa - 1)) - 2],
                          emoPwrMinPosMat[((int32_T)b_timInx + 1181 * ((int32_T)
                          absa - 1)) - 2], emoPwrMaxPosMat[((int32_T)b_timInx +
                          1181 * ((int32_T)absa - 1)) - 2], iceTrqMaxPosMat
                          [((int32_T)b_timInx + 1181 * ((int32_T)absa - 1)) - 2],
                          iceTrqMinPosMat[((int32_T)b_timInx + 1181 * ((int32_T)
                          absa - 1)) - 2], timStp, vehVelVec,
                          fzg_scalar_struct->vehVelThresh, fzg_array_struct);

                        /*  combine the min hamil. cost w/ previous costs and  */
                        /*    gear penalty to get current cost */
                        i3 = fulActTn3->size[0];
                        npages = (int32_T)emlrtIntegerCheckFastR2012b
                          (batStaLimMax + 1.0, &hb_emlrtDCI, sp);
                        n = fulActTn3->size[1];
                        i4 = 1 + nm1d2;
                        i5 = fulActTn3->size[2];
                        i6 = (int32_T)batStaPreIdxVec->data[iy];
                        i7 = cos2goPreTn3->size[0];
                        i8 = (int32_T)emlrtIntegerCheckFastR2012b(batStaLimMax +
                          1.0, &ib_emlrtDCI, sp);
                        ixstop = cos2goPreTn3->size[1];
                        cindx = (int32_T)absa;
                        ix = cos2goPreTn3->size[2];
                        i = (int32_T)batStaPreIdxVec->data[iy];
                        fulActTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                                          (npages, 1, i3, &oc_emlrtBCI, sp) +
                                          fulActTn3->size[0] *
                                          (emlrtDynamicBoundsCheckFastR2012b(i4,
                          1, n, &pc_emlrtBCI, sp) - 1)) + fulActTn3->size[0] *
                                         fulActTn3->size[1] *
                                         (emlrtDynamicBoundsCheckFastR2012b(i6,
                          1, i5, &qc_emlrtBCI, sp) - 1)) - 1] = ((batEngIdxBeg +
                          cos2goPreTn3->data[((emlrtDynamicBoundsCheckFastR2012b
                          (i8, 1, i7, &rc_emlrtBCI, sp) + cos2goPreTn3->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(cindx, 1, ixstop,
                          &sc_emlrtBCI, sp) - 1)) + cos2goPreTn3->size[0] *
                                              cos2goPreTn3->size[1] *
                                              (emlrtDynamicBoundsCheckFastR2012b
                          (i, 1, ix, &tc_emlrtBCI, sp) - 1)) - 1]) +
                          geaStaChgPenCos / timStp) + absb / timStp;
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
                  /*  need to convert batPwr to emoPwr to emoTrq */
                  /*  also, need to make sure that resultant torque */
                  /*  will lie within bounds - find bounds outside? */
                  /*  eq: batPwr - batPwrLoss = emoPwr */
                  /*  eq: emoPwr = crsSpd * emoTrq */
                  /*  eq: emoTrq = crsTrq */
                  /*  -- GIVEN : */
                  /*  crsSpd,  */
                  /*  crsTrq (therefore emoTrq->therefore emoPwr), */
                  /*  -- NEEDED : */
                  /*  batPwrLoss */
                  /*  batPwr */
                  /*  */
                  /*  before calculating batPwr stuff, make sure */
                  /*  that emoTrq remains within bounds when */
                  /*  setting it equal to crsTrq */
                  /*  */
                  /*  also make sure that emoPwr also remains */
                  /*  within bounds */
                  /*  */
                  /*  calculating batPwr stuff: */
                  /*  batPwrLoss = ((V-sqrt(V^2 - 4*R*emoPwr))^2) / (4*R) */
                  /*  batPwr = emoPwr + batPwrLoss */
                  /*                              if (crsSpdPreVec(geaStaPreIdx) > crsSpdEmoMax); continue; */
                  /*                              end */
                  /*   */
                  /*                              % --- crsTrq -> emoTrq BOUNDARY CHECK --------- */
                  /*                              if emoTrqMinPos > crsTrqPre || emoTrqMaxPos < crsTrqPre */
                  /*                                  continue; */
                  /*                              else */
                  /*                                  emoTrq = crsTrqPre; */
                  /*                              end */
                  /*                              % --------------------------------------------- */
                  /*  IF ENGINE IS OFF */
                  /*  Prüfen, ob die Drehzahlgrenze des Elektromotors eingehalten wird */
                  /*    check if electric motor speed limit is maintained */
                  i3 = (int32_T)b_y->data[nm1d2] - 1;
                  if (crsSpdMat[((int32_T)b_timInx + 1181 * i3) - 2] >
                      crsSpdEmoMax) {
                  } else {
                    /*  determine previous state if engine waas off */
                    /*  based on batPwrDemIdxTn3 (a preprocessed tn3 */
                    /*  containing amnt battery pwr needed to satisfy */
                    /*  a crankshaft power demand for all state */
                    /*  permutations) */
                    /*  - 1 */
                    i3 = (int32_T)b_timInx - 1;
                    batEngIdxBeg = (1.0 + (real_T)batStaActInx) +
                      batPwrDemIdxTn3[((emlrtDynamicBoundsCheckFastR2012b(i3, 1,
                      1181, &jc_emlrtBCI, sp) + 1181 * batStaActInx) + 818433 *
                                       ((int32_T)b_geaStaAct - 1)) - 1];

                    /*  check your bounds  */
                    if ((batEngIdxBeg < batStaMin / batStaStp + 1.0) ||
                        (batEngIdxBeg > batStaMax / batStaStp + 1.0)) {
                    } else {
                      /*  --- emoPwr BOUNDARY CHECK ------------------- */
                      /*                              emoPwr = crsSpdPre * emoTrq; */
                      /*                              if (emoPwrMinPos > emoPwr || emoPwrMaxPos < emoPwr); continue;  */
                      /*                              end */
                      /*                              % --------------------------------------------- */
                      /*                      */
                      /*                               */
                      /*                              % --- CALCULATE batPwrLoss AND batPwr --------- */
                      /*                              % bat voltage - from previous bat state - need */
                      /*                              % to determine how to move up the amount that */
                      /*                              % is being dropped (beforehand??) */
                      /*                              batOcvPre = batOcv(batStaPreOptInx); */
                      /*                               */
                      /*                              % usually, resistance is based on batPwr. Since batPwr is unkown, will be */
                      /*                              % using emoPwr as a benchmark instead */
                      /*                              %   b/c batPwr-batPwrLoss=emoPwr, both batPwr and emoPwr will generally */
                      /*                              %   have the same sign, unless batPwr<batPwrLoss (which seems unlikely?) */
                      /*                              %       may need to check this assumption later */
                      /*                              if emoPwr < 0 */
                      /*                                  batRst = fzg_scalar_struct.batRstDch; */
                      /*                              else */
                      /*                                  batRst = fzg_scalar_struct.batRstChr; */
                      /*                              end */
                      /*   */
                      /*                              % battery power losses */
                      /*                              batPwrLoss = ((batOcvPre-sqrt(batOcvPre.^2 - ... */
                      /*                                          4*batRst * emoPwr)).^2) / (4*batRst); */
                      /*  resultant battery power for satisfying crsTrq */
                      /*  negative because of batPwr sign assignment */
                      /*  earlier, where  */
                      /*    - : discharge */
                      /*    + : charge */
                      /*  because it is wrt to the current battery */
                      /*  state */
                      /*  WILL CHECK IF CORRECT LATER */
                      /*  but need to make sure it is disrectized */
                      /*                              batPwr = (ceil((emoPwr + batPwrLoss)/batStaStp))*batStaStp; */
                      /*                              batStaPr = batStaPreOptInx - batPwr; */
                      /*  ---------------------------------------------                          */
                      /*                              % bc of indexing, send actual battery index to */
                      /*                              % a local one for indexing out of fulActTn3 */
                      /*                              [~, batStaPreInx_Inx] = ... */
                      /*                                      find(batStaPreIdxVec == batStaPreOptInx); */
                      /*  since engine is off, no fuel is consumed */
                      /*  penalty to get current cost */
                      emlrtIntegerCheckFastR2012b(1.0, &g_emlrtDCI, sp);
                      i3 = fulActTn3->size[0];
                      emlrtDynamicBoundsCheckFastR2012b(1, 1, i3, &p_emlrtBCI,
                        sp);
                      emlrtIntegerCheckFastR2012b(1.0, &h_emlrtDCI, sp);
                      i3 = cos2goPreTn3->size[0];
                      emlrtDynamicBoundsCheckFastR2012b(1, 1, i3, &q_emlrtBCI,
                        sp);
                      i3 = fulActTn3->size[1];
                      npages = 1 + nm1d2;
                      n = fulActTn3->size[2];
                      i4 = (int32_T)emlrtIntegerCheckFastR2012b(batEngIdxBeg,
                        &fb_emlrtDCI, sp);
                      i5 = cos2goPreTn3->size[1];
                      i6 = (int32_T)b_y->data[nm1d2];
                      i7 = cos2goPreTn3->size[2];
                      i8 = (int32_T)emlrtIntegerCheckFastR2012b(batEngIdxBeg,
                        &gb_emlrtDCI, sp);
                      fulActTn3->data[fulActTn3->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3,
                          &kc_emlrtBCI, sp) - 1) + fulActTn3->size[0] *
                        fulActTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b
                        (i4, 1, n, &lc_emlrtBCI, sp) - 1)] = (cos2goPreTn3->
                        data[cos2goPreTn3->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                        &mc_emlrtBCI, sp) - 1) + cos2goPreTn3->size[0] *
                        cos2goPreTn3->size[1] *
                        (emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7,
                        &nc_emlrtBCI, sp) - 1)] + geaStaChgPenCos / timStp) +
                        absb / timStp;

                      /*  end of engStaPre condition check */
                    }
                  }
                }

                nm1d2++;
                emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
              }

              /*  end of gear changes loop */
              geaStaPreMin++;
              emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
            }

            /*  end of running through previous engine state ctrl loop */
            /*  pull out the minimum value from fulActMat */
            st.site = &e_emlrtRSI;
            b_st.site = &x_emlrtRSI;
            c_st.site = &y_emlrtRSI;
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
              d_st.site = &ob_emlrtRSI;
              g_st.site = &sb_emlrtRSI;
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
              d_st.site = &nb_emlrtRSI;
              g_st.site = &rb_emlrtRSI;
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

            for (geaStaPreMin = 2; geaStaPreMin <= iy; geaStaPreMin++) {
              npages *= fulActTn3->size[geaStaPreMin - 1];
            }

            geaStaPreMin = 0;
            iy = -1;
            d_st.site = &ab_emlrtRSI;
            if (1 > npages) {
              b0 = false;
            } else {
              b0 = (npages > 2147483646);
            }

            if (b0) {
              e_st.site = &p_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (i = 1; i <= npages; i++) {
              d_st.site = &bb_emlrtRSI;
              d_st.site = &cb_emlrtRSI;
              nm1d2 = geaStaPreMin;
              ixstop = geaStaPreMin + n;
              batEngIdxBeg = fulActTn3->data[geaStaPreMin];
              engStaPreIdx_size_idx_1 = 1;
              if (n > 1) {
                cindx = 1;
                if (muDoubleScalarIsNaN(fulActTn3->data[geaStaPreMin])) {
                  e_st.site = &eb_emlrtRSI;
                  if (geaStaPreMin + 2 > ixstop) {
                    b_geaStaPreMin = false;
                  } else {
                    b_geaStaPreMin = (ixstop > 2147483646);
                  }

                  if (b_geaStaPreMin) {
                    h_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  ix = geaStaPreMin + 1;
                  exitg3 = false;
                  while ((!exitg3) && (ix + 1 <= ixstop)) {
                    cindx++;
                    nm1d2 = ix;
                    if (!muDoubleScalarIsNaN(fulActTn3->data[ix])) {
                      batEngIdxBeg = fulActTn3->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                      exitg3 = true;
                    } else {
                      ix++;
                    }
                  }
                }

                if (nm1d2 + 1 < ixstop) {
                  e_st.site = &db_emlrtRSI;
                  if (nm1d2 + 2 > ixstop) {
                    b_nm1d2 = false;
                  } else {
                    b_nm1d2 = (ixstop > 2147483646);
                  }

                  if (b_nm1d2) {
                    h_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (ix = nm1d2 + 1; ix + 1 <= ixstop; ix++) {
                    cindx++;
                    if (fulActTn3->data[ix] < batEngIdxBeg) {
                      batEngIdxBeg = fulActTn3->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                    }
                  }
                }
              }

              iy++;
              extremum->data[iy] = batEngIdxBeg;
              iindx->data[iy] = engStaPreIdx_size_idx_1;
              geaStaPreMin += n;
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

            st.site = &f_emlrtRSI;
            b_st.site = &x_emlrtRSI;
            c_st.site = &y_emlrtRSI;
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
              d_st.site = &ob_emlrtRSI;
              g_st.site = &sb_emlrtRSI;
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
              d_st.site = &nb_emlrtRSI;
              g_st.site = &rb_emlrtRSI;
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

            geaStaPreMin = 3;
            while (geaStaPreMin <= iy) {
              npages *= extremum->size[2];
              geaStaPreMin = 4;
            }

            geaStaPreMin = 0;
            iy = -1;
            d_st.site = &ab_emlrtRSI;
            if (1 > npages) {
              b1 = false;
            } else {
              b1 = (npages > 2147483646);
            }

            if (b1) {
              e_st.site = &p_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (i = 1; i <= npages; i++) {
              d_st.site = &bb_emlrtRSI;
              d_st.site = &cb_emlrtRSI;
              nm1d2 = geaStaPreMin;
              ixstop = geaStaPreMin + n;
              batEngIdxBeg = extremum->data[geaStaPreMin];
              engStaPreIdx_size_idx_1 = 1;
              if (n > 1) {
                cindx = 1;
                if (muDoubleScalarIsNaN(extremum->data[geaStaPreMin])) {
                  e_st.site = &eb_emlrtRSI;
                  if (geaStaPreMin + 2 > ixstop) {
                    c_geaStaPreMin = false;
                  } else {
                    c_geaStaPreMin = (ixstop > 2147483646);
                  }

                  if (c_geaStaPreMin) {
                    h_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  ix = geaStaPreMin + 1;
                  exitg2 = false;
                  while ((!exitg2) && (ix + 1 <= ixstop)) {
                    cindx++;
                    nm1d2 = ix;
                    if (!muDoubleScalarIsNaN(extremum->data[ix])) {
                      batEngIdxBeg = extremum->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                      exitg2 = true;
                    } else {
                      ix++;
                    }
                  }
                }

                if (nm1d2 + 1 < ixstop) {
                  e_st.site = &db_emlrtRSI;
                  if (nm1d2 + 2 > ixstop) {
                    c_nm1d2 = false;
                  } else {
                    c_nm1d2 = (ixstop > 2147483646);
                  }

                  if (c_nm1d2) {
                    h_st.site = &p_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (ix = nm1d2 + 1; ix + 1 <= ixstop; ix++) {
                    cindx++;
                    if (extremum->data[ix] < batEngIdxBeg) {
                      batEngIdxBeg = extremum->data[ix];
                      engStaPreIdx_size_idx_1 = cindx;
                    }
                  }
                }
              }

              iy++;
              b_extremum->data[iy] = batEngIdxBeg;
              b_iindx->data[iy] = engStaPreIdx_size_idx_1;
              geaStaPreMin += n;
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

            /*                  [minFulMin, engStaPreOptInx] = min(matmin); */
            /*                  geaStaPreOptInx = matminidx(engStaPreOptInx); */
            /*                  batStaPreInx    = colminidx(:,geaStaPreOptInx,engStaPreOptInx); */
            /*                  batStaPreOptInx = batStaPreIdxVec(batStaPreInx); */
            st.site = &g_emlrtRSI;
            b_st.site = &x_emlrtRSI;
            c_st.site = &y_emlrtRSI;
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
              d_st.site = &ob_emlrtRSI;
              g_st.site = &sb_emlrtRSI;
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
              d_st.site = &nb_emlrtRSI;
              g_st.site = &rb_emlrtRSI;
              error(&d_st, message(&g_st, j_y, &h_emlrtMCI), &i_emlrtMCI);
            }

            d_st.site = &fb_emlrtRSI;
            nm1d2 = 1;
            n = b_extremum->size[2];
            batEngIdxBeg = b_extremum->data[0];
            engStaPreIdx_size_idx_1 = 0;
            if (b_extremum->size[2] > 1) {
              if (muDoubleScalarIsNaN(b_extremum->data[0])) {
                e_st.site = &eb_emlrtRSI;
                overflow = (b_extremum->size[2] > 2147483646);
                if (overflow) {
                  h_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                geaStaPreMin = 1;
                exitg1 = false;
                while ((!exitg1) && (geaStaPreMin + 1 <= n)) {
                  nm1d2 = geaStaPreMin + 1;
                  if (!muDoubleScalarIsNaN(b_extremum->data[geaStaPreMin])) {
                    batEngIdxBeg = b_extremum->data[geaStaPreMin];
                    engStaPreIdx_size_idx_1 = geaStaPreMin;
                    exitg1 = true;
                  } else {
                    geaStaPreMin++;
                  }
                }
              }

              if (nm1d2 < b_extremum->size[2]) {
                e_st.site = &db_emlrtRSI;
                if (nm1d2 + 1 > b_extremum->size[2]) {
                  overflow = false;
                } else {
                  overflow = (b_extremum->size[2] > 2147483646);
                }

                if (overflow) {
                  h_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }

                while (nm1d2 + 1 <= n) {
                  if (b_extremum->data[nm1d2] < batEngIdxBeg) {
                    batEngIdxBeg = b_extremum->data[nm1d2];
                    engStaPreIdx_size_idx_1 = nm1d2;
                  }

                  nm1d2++;
                }
              }
            }

            i3 = b_indx->size[2];
            npages = engStaPreIdx_size_idx_1 + 1;
            emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &o_emlrtBCI, sp);
            i3 = indx->size[1];
            npages = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
            emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &n_emlrtBCI, sp);
            i3 = indx->size[2];
            npages = engStaPreIdx_size_idx_1 + 1;
            emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &m_emlrtBCI, sp);

            /*                  engStaPreOptInx = batStaPreIdxVec(engStaPreInx); */
            if (!muDoubleScalarIsInf(batEngIdxBeg)) {
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
              npages = (int32_T)indx->data[indx->size[0] * ((int32_T)
                b_indx->data[engStaPreIdx_size_idx_1] - 1) + indx->size[0] *
                indx->size[1] * engStaPreIdx_size_idx_1];
              emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &i_emlrtBCI, sp);
              i3 = fulEngPreTn3->size[1];
              npages = (int32_T)b_indx->data[engStaPreIdx_size_idx_1];
              emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &h_emlrtBCI, sp);
              i3 = fulEngPreTn3->size[2];
              npages = engStaPreIdx_size_idx_1 + 1;
              emlrtDynamicBoundsCheckFastR2012b(npages, 1, i3, &g_emlrtBCI, sp);

              /* %#ok<PFBNS> */
              /*  optimale Kosten zum aktuellen Punkt speichern */
              /*    save min hamilton value for current point */
              i3 = cos2goActTn3->size[0];
              npages = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &ab_emlrtDCI, sp);
              n = cos2goActTn3->size[1];
              i4 = (int32_T)b_geaStaAct;
              i5 = cos2goActTn3->size[2];
              i6 = 1 + batStaActInx;
              cos2goActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(npages, 1,
                i3, &qb_emlrtBCI, sp) + cos2goActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i4, 1, n,
                &rb_emlrtBCI, sp) - 1)) + cos2goActTn3->size[0] *
                                  cos2goActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                &sb_emlrtBCI, sp) - 1)) - 1] = batEngIdxBeg;

              /*  optimale Batterieenergie zum aktuellen Punkt speichern */
              /*    save optimal battery energy for current point */
              i3 = batEngActTn3->size[0];
              npages = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &bb_emlrtDCI, sp);
              n = batEngActTn3->size[1];
              i4 = (int32_T)b_geaStaAct;
              i5 = batEngActTn3->size[2];
              i6 = 1 + batStaActInx;
              batEngActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(npages, 1,
                i3, &tb_emlrtBCI, sp) + batEngActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i4, 1, n,
                &ub_emlrtBCI, sp) - 1)) + batEngActTn3->size[0] *
                                  batEngActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                &vb_emlrtBCI, sp) - 1)) - 1] = ((real_T)(engStaPreIdx_size_idx_1
                + 1) - 1.0) * batStaStp;

              /*  optimale Krafstoffenergie zum aktuellen Punkt speichern */
              /*    save optimal fuel energy for current point */
              i3 = fulEngActTn3->size[0];
              npages = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &cb_emlrtDCI, sp);
              n = fulEngActTn3->size[1];
              i4 = (int32_T)b_geaStaAct;
              i5 = fulEngActTn3->size[2];
              i6 = 1 + batStaActInx;
              fulEngActTn3->data[((emlrtDynamicBoundsCheckFastR2012b(npages, 1,
                i3, &wb_emlrtBCI, sp) + fulEngActTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i4, 1, n,
                &xb_emlrtBCI, sp) - 1)) + fulEngActTn3->size[0] *
                                  fulEngActTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                &yb_emlrtBCI, sp) - 1)) - 1] = batEngIdxBeg + fulEngPreTn3->
                data[(((int32_T)indx->data[indx->size[0] * ((int32_T)
                        b_indx->data[engStaPreIdx_size_idx_1] - 1) + indx->size
                       [0] * indx->size[1] * engStaPreIdx_size_idx_1] +
                       fulEngPreTn3->size[0] * ((int32_T)b_indx->
                        data[engStaPreIdx_size_idx_1] - 1)) + fulEngPreTn3->
                      size[0] * fulEngPreTn3->size[1] * engStaPreIdx_size_idx_1)
                - 1];

              /*  optimale Batterieenergie zum aktuellen Punkt */
              /*  Flussgrï¿½ï¿½e gilt im Intervall */
              /*    populate optimal battery energy flux quantity at point  */
              /*    that's applicable to current interval */
              i3 = batPwrOptTn3->size[0];
              npages = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &db_emlrtDCI, sp);
              n = batPwrOptTn3->size[1];
              i4 = (int32_T)b_geaStaAct;
              i5 = batPwrOptTn3->size[2];
              i6 = 1 + batStaActInx;
              batPwrOptTn3->data[((emlrtDynamicBoundsCheckFastR2012b(npages, 1,
                i3, &ac_emlrtBCI, sp) + batPwrOptTn3->size[0] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i4, 1, n,
                &bc_emlrtBCI, sp) - 1)) + batPwrOptTn3->size[0] *
                                  batPwrOptTn3->size[1] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                &cc_emlrtBCI, sp) - 1)) - 1] = (1.0 + (real_T)batStaActInx) -
                (real_T)(engStaPreIdx_size_idx_1 + 1);

              /*  optimalen Vorgï¿½nger codieren ï¿½ber Funktion sub2ind */
              /*  und speichern im Tensor */
              /*    opt. predecessor idx encoding w/ sub2ind, store in Tn3 */
              st.site = &h_emlrtRSI;
              b_st.site = &gb_emlrtRSI;
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

              c_st.site = &hb_emlrtRSI;
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
                d_st.site = &mb_emlrtRSI;
                error(&d_st, message(&d_st, k_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              if ((b_indx->data[engStaPreIdx_size_idx_1] >= 1.0) && ((int32_T)
                   geaNum >= (int32_T)b_indx->data[engStaPreIdx_size_idx_1])) {
                overflow = true;
              } else {
                overflow = false;
              }

              c_st.site = &hb_emlrtRSI;
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
                d_st.site = &mb_emlrtRSI;
                error(&d_st, message(&d_st, l_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              c_st.site = &ib_emlrtRSI;
              d_st.site = &jb_emlrtRSI;
              if ((engStaPreIdx_size_idx_1 + 1 >= 1) && ((int32_T)batNum >=
                   engStaPreIdx_size_idx_1 + 1)) {
                overflow = true;
              } else {
                overflow = false;
              }

              c_st.site = &hb_emlrtRSI;
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
                d_st.site = &mb_emlrtRSI;
                error(&d_st, message(&d_st, m_y, &j_emlrtMCI), &j_emlrtMCI);
              }

              i3 = optPreInxTn4->size[0];
              npages = (int32_T)emlrtIntegerCheckFastR2012b(b_engStaAct + 1.0,
                &eb_emlrtDCI, sp);
              n = optPreInxTn4->size[1];
              i4 = (int32_T)b_geaStaAct;
              i5 = optPreInxTn4->size[2];
              i6 = 1 + batStaActInx;
              i7 = optPreInxTn4->size[3];
              i8 = (int32_T)b_timInx;
              optPreInxTn4->data[(((emlrtDynamicBoundsCheckFastR2012b(npages, 1,
                i3, &dc_emlrtBCI, sp) + optPreInxTn4->size[0] *
                                    (emlrtDynamicBoundsCheckFastR2012b(i4, 1, n,
                &ec_emlrtBCI, sp) - 1)) + optPreInxTn4->size[0] *
                                   optPreInxTn4->size[1] *
                                   (emlrtDynamicBoundsCheckFastR2012b(i6, 1, i5,
                &fc_emlrtBCI, sp) - 1)) + optPreInxTn4->size[0] *
                                  optPreInxTn4->size[1] * optPreInxTn4->size[2] *
                                  (emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7,
                &gc_emlrtBCI, sp) - 1)) - 1] = ((int32_T)indx->data[indx->size[0]
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
          st.site = &i_emlrtRSI;
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
    st.site = &j_emlrtRSI;
    j_fprintf(&st);

    /*      fprintf('##################################\n\n'); */
    /*  Speichern der Kosten fï¿½r den nï¿½chsten Schleifendurchlauf */
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

    /*  Speichern der Batterieenergie fï¿½r den nï¿½chsten Schleifendurchlauf */
    /*    save battery energy value as previous path_idx val for next loop  */
    /*      batEngPreTn3 = batEngActTn3; */
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
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, sp);
    iv12[0] = r0->size[0];
    iv12[1] = r1->size[0];
    iv12[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv12, 3, *(int32_T (*)[3])fulEngActTn3->size,
      3, &emlrtECI, sp);
    iy = fulEngActTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      geaStaPreMin = fulEngActTn3->size[1];
      for (i2 = 0; i2 < geaStaPreMin; i2++) {
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
    /*  Flussgrï¿½ï¿½e gilt im Intervall */
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
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &f_emlrtBCI, sp);
    iv13[0] = r0->size[0];
    iv13[1] = r1->size[0];
    iv13[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv13, 3, *(int32_T (*)[3])batPwrOptTn3->size,
      3, &b_emlrtECI, sp);
    iy = batPwrOptTn3->size[2];
    for (i1 = 0; i1 < iy; i1++) {
      geaStaPreMin = batPwrOptTn3->size[1];
      for (i2 = 0; i2 < geaStaPreMin; i2++) {
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

    /*  Ausgabe des aktuellen Schleifendurchlaufs */
    /*    output for current loop - print to terminal */
    if (disFlg != 0.0) {
      st.site = &k_emlrtRSI;
      l_fprintf(&st, b_timInx - timInxBeg, (b_timInx - timInxBeg) / (timInxEnd -
                 timInxBeg) * 100.0);
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
  emxFree_real_T(&fulActTn3);
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
