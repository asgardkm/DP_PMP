/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcOptTrj_tmp.c
 *
 * Code generation for function 'clcOptTrj_tmp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcOptTrj_tmp.h"
#include "clcOptTrj_tmp_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "diff.h"
#include "clcOptTrj_tmp_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 86, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo b_emlrtRSI = { 131, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo c_emlrtRSI = { 143, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo d_emlrtRSI = { 175, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo e_emlrtRSI = { 176, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo f_emlrtRSI = { 183, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo g_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo h_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo i_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo j_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo k_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo m_emlrtRSI = { 19, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

static emlrtRTEInfo emlrtRTEI = { 10, 5, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRTEInfo b_emlrtRTEI = { 73, 1, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtDCInfo emlrtDCI = { 79, 5, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo emlrtBCI = { -1, -1, 79, 5, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 87, 8, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 87, 8, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 91, 1, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 91, 1, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtRTEInfo e_emlrtRTEI = { 123, 1, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtDCInfo d_emlrtDCI = { 127, 27, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo d_emlrtBCI = { 1, 11, 127, 27, "optPreInxTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 128, 9, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo e_emlrtBCI = { 1, 6, 128, 9, "optPreInxTn3", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo f_emlrtBCI = { 1, 800, 128, 28, "optPreInxTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 175, 43, "engKinNumVec_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 175, 41, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo h_emlrtBCI = { 1, 11, 175, 41, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 175, 73, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo i_emlrtBCI = { 1, 6, 175, 73, "fulEngOptTn3", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo j_emlrtBCI = { 1, 800, 175, 90, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 176, 50, "engKinNumVec_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 176, 48, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 176, 48, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 176, 80, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtRTEInfo f_emlrtRTEI = { 38, 23, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 13, 15, "rdivide",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtDCInfo i_emlrtDCI = { 57, 23, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtDCInfo j_emlrtDCI = { 57, 23, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 4 };

static emlrtBCInfo n_emlrtBCI = { 1, 6, 88, 20, "inx", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 88, 24, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 88, 24, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 96, 14, "engKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 97, 32, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 97, 32, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 97, 48, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 97, 61, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 101, 17, "batEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo u_emlrtBCI = { 1, 11, 102, 18, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 102, 18, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 102, 18, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo w_emlrtBCI = { 1, 6, 102, 45, "batFrcOptTn3", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 102, 45, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 102, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo y_emlrtBCI = { 1, 800, 102, 65, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { 1, 11, 108, 18, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 108, 18, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 108, 18, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { 1, 6, 108, 45, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 108, 45, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 108, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { 1, 800, 108, 65, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 127, 43, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 128, 16, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 183, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 186, 25, "fulEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { 1, 11, 187, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 187, 26, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 187, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { 1, 6, 187, 50, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 187, 50, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 187, 50, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 143, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 143, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 150, 25, "batEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { 1, 11, 151, 26, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 151, 26, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 151, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { 1, 6, 152, 13, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 152, 13, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 152, 13, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { 1, 800, 152, 30, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 159, 25, "fulEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { 1, 11, 160, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 160, 26, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 160, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { 1, 6, 160, 50, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 160, 50, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 160, 50, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { 1, 11, 161, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 161, 26, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 161, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { 1, 6, 161, 52, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 161, 52, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 161, 52, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { 1, 800, 161, 69, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 175, 73, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 178, 9, "psiEngKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 178, 37, "psiEngKinVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 178, 37, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 178, 66, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 192, 18, "engKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 193, 36, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 193, 36, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 193, 52, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 193, 64, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtRSInfo o_emlrtRSI = { 18, "indexDivide",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\indexDivide.m"
};

static emlrtRSInfo p_emlrtRSI = { 20, "error",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
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
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void clcOptTrj_tmp(const emlrtStack *sp, real_T disFlg, real_T wayStp, real_T
                   wayNum, real_T wayInxBeg, real_T wayInxEnd, real_T staEnd,
                   real_T engKinNum, real_T engKinEndInxVal, real_T staNum,
                   const emxArray_real_T *engKinNumVec_wayInx, const
                   emxArray_real_T *engKinMat_engKinInx_wayInx, const real_T
                   optPreInxTn3[52800], const real_T batFrcOptTn3[52800], const
                   real_T fulEngOptTn3[52800], const real_T cos2goActMat[66],
                   emxArray_real_T *engKinOptVec, emxArray_real_T
                   *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
                   emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
                   real_T *fulEngOpt, real_T *engKinEndInx)
{
  int32_T i0;
  real_T mtmp;
  int32_T loop_ub;
  emxArray_real_T *engKinOptInxVec;
  int32_T i1;
  int32_T i2;
  real_T extremum[6];
  int32_T iindx[6];
  int32_T ix;
  int32_T iy;
  int32_T b_ix;
  int32_T itmp;
  int32_T cindx;
  boolean_T c_ix;
  int32_T d_ix;
  boolean_T exitg3;
  boolean_T e_ix;
  boolean_T exitg2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T b_cindx;
  int32_T i7;
  int32_T b_iy;
  int32_T f_ix;
  int32_T c_iy;
  int32_T c_cindx;
  int32_T i8;
  int32_T b_itmp;
  int32_T d_iy;
  int32_T d_cindx;
  int32_T i9;
  int32_T c_itmp;
  int32_T i10;
  int32_T i11;
  int32_T d_itmp;
  int32_T wayInx;
  emxArray_real_T *y;
  emxArray_real_T *b_engKinMat_engKinInx_wayInx;
  real_T b_wayInx;
  int32_T e_itmp;
  int32_T f_itmp;
  static const char_T varargin_1[47] = { 'F', 'e', 'h', 'l', 'e', 'r', ' ', 'b',
    'e', 'i', 'm', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n', ' ', 'd',
    'e', 'r', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l', 'e', 'n', ' ', 'V', 'o',
    'r', 'g', 'a', 'e', 'n', 'g', 'e', 'r', '.' };

  char_T u[47];
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 47 };

  const mxArray *m0;
  boolean_T p;
  int32_T g_itmp;
  int32_T h_itmp;
  int32_T e_cindx;
  int32_T g_ix;
  int32_T i_itmp;
  int32_T e_iy;
  int32_T f_cindx;
  int32_T h_ix;
  int32_T g_cindx;
  int32_T i_ix;
  int32_T j_ix;
  int32_T k_ix;
  int32_T j_itmp;
  int32_T f_iy;
  int32_T h_cindx;
  int32_T l_ix;
  int32_T m_ix;
  int32_T n_ix;
  real_T fulEngOptTn3_data[11];
  int32_T k_itmp;
  int32_T fulEngOptTn3_size[1];
  emxArray_real_T b_fulEngOptTn3_data;
  real_T x_data[10];
  int32_T siz[2];
  uint32_T varargin_2[2];
  boolean_T b_p;
  boolean_T exitg1;
  real_T psiEngKinVec_data[11];
  int32_T o_ix;
  int32_T l_itmp;
  int32_T i_cindx;
  int32_T m_itmp;
  int32_T j_cindx;
  int32_T p_ix;
  int32_T n_itmp;
  int32_T g_iy;
  int32_T k_cindx;
  int32_T q_ix;
  int32_T o_itmp;
  int32_T l_cindx;
  int32_T r_ix;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*   Vektor - Trajektorie der optimalen kin. Energien */
  /*     Vektor - optimale Batterieenergieänderung */
  /*      Vektor - optimale Kraftstoffenergieänderung */
  /*               Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*      Vektor - costate für kinetische Energie */
  /*           Skalar - optimale Kraftstoffenergie */
  /*              Flag, ob Zielzustand genutzt werden muss */
  /*               Skalar für die Wegschrittweite in m */
  /*               Skalar für die max. Anzahl an Wegstützstellen */
  /*            Skalar für Anfangsindex in den Eingangsdaten */
  /*            Skalar für Endindex in den Eingangsdaten */
  /*               Skalar für den finalen Zustand */
  /*            Skalar für die max. Anz. an engKin-Stützstellen */
  /*      Skalar für Zielindex der kinetischen Energie */
  /*               Skalar für die max. Anzahl an Zustandsstützstellen */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*  Matrix der kinetischen Energien in J */
  /*         Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*        Tensor 3. Stufe der Batteriekraft */
  /*        Tensor 3. Stufe für die Kraftstoffenergie */
  /*         Matrix der optimalen Kosten der Hamiltonfunktion */
  /*  */
  /* CLCOPTTRJ Calculating optimal trajectories for result of DP + PMP */
  /*  Erstellungsdatum der ersten Version 24.08.2015 - Stephan Uebel */
  /*  */
  /*  Diese Funktion berechnet die optimalen Trajketorien der kinetischen */
  /*  Energie und Anstriebsstrangzustands. Außerdem wird ein Verlauf für einen */
  /*  costate für die kinetische Energie aus den Ergebnissen der DP berechnet. */
  /*    this function calulates the optimal trajectory for kinetic energy and */
  /*    powertrain states. In addition, a course is calculated for a costate */
  /*    for the kinetic energy from the DP results. */
  /*  */
  /*  !!!! Generelle Festlegung, wie Vektoren/Tensoren zu lesen sind !!!! */
  /*  Werte, die am Anfang und am Ende eines Intervalls gelten, stehen an der */
  /*  jeweiligen Position des Vektors. */
  /*    !!!! Please note, how vectors/tensors are read !!!! */
  /*    Values that are at the beginning and end of an interval are at their */
  /*    respective indexes along the vector. */
  /*  */
  /*  Mittelwerte, d.h. Flussgrößen wie Kräfte, Leistungen etc., stehen immmer */
  /*  am Anfang des Intervalls für das folgende Intervall. Diese */
  /*  Vektoren/Tensoren sind daher um einen gültigen Eintrag kürzer. */
  /*    mean values (eg flow variables like forces, services) are always at the */
  /*    beginning of the interval for the next interval. Those vectors/tensors */
  /*    are therefore shorter by a valid entry (index?). */
  /* % Initialisieren der Ausgabe der Funktion */
  /*    initializing function output */
  /*  Trajektorie der optimalen kin. Energien */
  /*    optimal kinetic energy trajectory initializaton */
  i0 = engKinOptVec->size[0];
  if (wayNum >= 0.0) {
    mtmp = wayNum;
  } else {
    mtmp = emlrtNonNegativeCheckR2012b(wayNum, &j_emlrtDCI, sp);
  }

  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    engKinOptVec->size[0] = (int32_T)mtmp;
  } else {
    engKinOptVec->size[0] = (int32_T)emlrtIntegerCheckR2012b(mtmp, &i_emlrtDCI,
      sp);
  }

  emxEnsureCapacity(sp, (emxArray__common *)engKinOptVec, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (wayNum >= 0.0) {
    mtmp = wayNum;
  } else {
    mtmp = emlrtNonNegativeCheckR2012b(wayNum, &j_emlrtDCI, sp);
  }

  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    loop_ub = (int32_T)mtmp;
  } else {
    loop_ub = (int32_T)emlrtIntegerCheckR2012b(mtmp, &i_emlrtDCI, sp);
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    engKinOptVec->data[i0] = rtInf;
  }

  /*  Trajektorie der optimalen Batterieenergieänderung im Intervall */
  /*    optimal battery energy change trajectories for the interval */
  i0 = batEngDltOptVec->size[0];
  batEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)batEngDltOptVec, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    batEngDltOptVec->data[i0] = rtInf;
  }

  /*  Trajektorie des optimalen Antriebsstrangzustands im Intervall */
  /*    optimal powertrain state trajectories for the interval */
  i0 = staVec->size[0];
  staVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)staVec, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    staVec->data[i0] = 0.0;
  }

  emxInit_real_T(sp, &engKinOptInxVec, 1, &b_emlrtRTEI, true);

  /* % Initialisieren des finalen Zustands */
  /*    intializing the final state */
  /*  Indexvektor der optimalen kinetischen Energien */
  /*    index vector for the optimal kinetic energies */
  i0 = engKinOptInxVec->size[0];
  engKinOptInxVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)engKinOptInxVec, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    engKinOptInxVec->data[i0] = 0.0;
  }

  /*  Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls  */
  /*  Zielgang nicht festgelegt ist */
  /*    find the optimal gear and speed if the target gear isn't fixed */
  if (disFlg != 0.0) {
    mtmp = wayInxEnd - 1.0;
    i0 = (int32_T)wayNum;
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      i1 = (int32_T)mtmp;
    } else {
      i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &emlrtDCI, sp);
    }

    if ((i1 >= 1) && (i1 < i0)) {
      i2 = i1;
    } else {
      i2 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, sp);
    }

    staVec->data[i2 - 1] = staEnd;

    /*  Die finale kinetische Energie steht an Stelle 1 im Vektor */
    /*    the final kinetic energy is at the first index in the vector */
    *engKinEndInx = engKinEndInxVal;
  } else {
    st.site = &emlrtRSI;
    b_st.site = &g_emlrtRSI;
    c_st.site = &h_emlrtRSI;
    for (i0 = 0; i0 < 6; i0++) {
      iindx[i0] = 1;
    }

    ix = 0;
    iy = -1;
    for (loop_ub = 0; loop_ub < 6; loop_ub++) {
      ix += 11;
      d_st.site = &i_emlrtRSI;
      b_ix = ix - 10;
      mtmp = cos2goActMat[ix - 11];
      itmp = 1;
      cindx = 1;
      if (muDoubleScalarIsNaN(cos2goActMat[ix - 11])) {
        e_st.site = &k_emlrtRSI;
        if (ix - 9 > ix) {
          c_ix = false;
        } else {
          c_ix = (ix > 2147483646);
        }

        if (c_ix) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        d_ix = ix - 9;
        exitg3 = false;
        while ((!exitg3) && (d_ix <= ix)) {
          cindx++;
          b_ix = d_ix;
          if (!muDoubleScalarIsNaN(cos2goActMat[d_ix - 1])) {
            mtmp = cos2goActMat[d_ix - 1];
            itmp = cindx;
            exitg3 = true;
          } else {
            d_ix++;
          }
        }
      }

      if (b_ix < ix) {
        e_st.site = &j_emlrtRSI;
        if (b_ix + 1 > ix) {
          e_ix = false;
        } else {
          e_ix = (ix > 2147483646);
        }

        if (e_ix) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (b_ix + 1 <= ix) {
          cindx++;
          if (cos2goActMat[b_ix] < mtmp) {
            mtmp = cos2goActMat[b_ix];
            itmp = cindx;
          }

          b_ix++;
        }
      }

      iy++;
      extremum[iy] = mtmp;
      iindx[iy] = itmp;
    }

    iy = 1;
    mtmp = extremum[0];
    itmp = 1;
    if (muDoubleScalarIsNaN(extremum[0])) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix < 7)) {
        iy = ix;
        if (!muDoubleScalarIsNaN(extremum[ix - 1])) {
          mtmp = extremum[ix - 1];
          itmp = ix;
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (iy < 6) {
      while (iy + 1 < 7) {
        if (extremum[iy] < mtmp) {
          mtmp = extremum[iy];
          itmp = iy + 1;
        }

        iy++;
      }
    }

    mtmp = wayInxEnd - 1.0;
    i0 = (int32_T)wayNum;
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      i1 = (int32_T)mtmp;
    } else {
      i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &b_emlrtDCI, sp);
    }

    if ((i1 >= 1) && (i1 < i0)) {
      i3 = i1;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, sp);
    }

    staVec->data[i3 - 1] = itmp;
    i0 = staVec->size[0];
    mtmp = wayInxEnd - 1.0;
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      i1 = (int32_T)mtmp;
    } else {
      i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &k_emlrtDCI, sp);
    }

    if ((i1 >= 1) && (i1 < i0)) {
      i4 = i1;
    } else {
      i4 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, sp);
    }

    i0 = (int32_T)staVec->data[i4 - 1];
    if ((i0 >= 1) && (i0 < 6)) {
      i5 = i0;
    } else {
      i5 = emlrtDynamicBoundsCheckR2012b(i0, 1, 6, &n_emlrtBCI, sp);
    }

    *engKinEndInx = iindx[i5 - 1];
  }

  /*  assign the last value in the optimatal KE INDEX vector as the last KE idx */
  i0 = (int32_T)wayNum;
  if (wayInxEnd == (int32_T)muDoubleScalarFloor(wayInxEnd)) {
    i1 = (int32_T)wayInxEnd;
  } else {
    i1 = (int32_T)emlrtIntegerCheckR2012b(wayInxEnd, &c_emlrtDCI, sp);
  }

  if ((i1 >= 1) && (i1 < i0)) {
    i6 = i1;
  } else {
    i6 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, sp);
  }

  engKinOptInxVec->data[i6 - 1] = *engKinEndInx;

  /*  Zielzustand des Ausgabevektors für optimale kinetische Energie */
  /*  beschreiben */
  /*    describe the target state of the output vector for the optimal KE */
  i0 = (int32_T)wayNum;
  i1 = (int32_T)wayInxEnd;
  itmp = engKinMat_engKinInx_wayInx->size[0];
  iy = engKinOptInxVec->size[0];
  cindx = (int32_T)wayInxEnd;
  if ((cindx >= 1) && (cindx < iy)) {
    b_cindx = cindx;
  } else {
    b_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &r_emlrtBCI, sp);
  }

  mtmp = engKinOptInxVec->data[b_cindx - 1];
  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    iy = (int32_T)mtmp;
  } else {
    iy = (int32_T)emlrtIntegerCheckR2012b(mtmp, &l_emlrtDCI, sp);
  }

  cindx = engKinMat_engKinInx_wayInx->size[1];
  d_ix = (int32_T)wayInxEnd;
  if ((i1 >= 1) && (i1 < i0)) {
    i7 = i1;
  } else {
    i7 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &p_emlrtBCI, sp);
  }

  if ((iy >= 1) && (iy < itmp)) {
    b_iy = iy;
  } else {
    b_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &q_emlrtBCI, sp);
  }

  if ((d_ix >= 1) && (d_ix < cindx)) {
    f_ix = d_ix;
  } else {
    f_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &s_emlrtBCI, sp);
  }

  engKinOptVec->data[i7 - 1] = engKinMat_engKinInx_wayInx->data[(b_iy +
    engKinMat_engKinInx_wayInx->size[0] * (f_ix - 1)) - 1];

  /*  Batterieenergieänderung im letzten Intervall initialisieren */
  /*    initialize battery engery change's last interval */
  i0 = (int32_T)wayNum;
  i1 = (int32_T)wayInxEnd - 1;
  itmp = engKinOptInxVec->size[0];
  iy = (int32_T)wayInxEnd;
  if ((iy >= 1) && (iy < itmp)) {
    c_iy = iy;
  } else {
    c_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, itmp, &v_emlrtBCI, sp);
  }

  mtmp = engKinOptInxVec->data[c_iy - 1];
  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    itmp = (int32_T)mtmp;
  } else {
    itmp = (int32_T)emlrtIntegerCheckR2012b(mtmp, &m_emlrtDCI, sp);
  }

  iy = staVec->size[0];
  cindx = (int32_T)wayInxEnd - 1;
  if ((cindx >= 1) && (cindx < iy)) {
    c_cindx = cindx;
  } else {
    c_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &x_emlrtBCI, sp);
  }

  mtmp = staVec->data[c_cindx - 1];
  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    iy = (int32_T)mtmp;
  } else {
    iy = (int32_T)emlrtIntegerCheckR2012b(mtmp, &n_emlrtDCI, sp);
  }

  cindx = (int32_T)wayInxEnd - 1;
  if ((i1 >= 1) && (i1 < i0)) {
    i8 = i1;
  } else {
    i8 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &t_emlrtBCI, sp);
  }

  if ((itmp >= 1) && (itmp < 11)) {
    b_itmp = itmp;
  } else {
    b_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, 11, &u_emlrtBCI, sp);
  }

  if ((iy >= 1) && (iy < 6)) {
    d_iy = iy;
  } else {
    d_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, 6, &w_emlrtBCI, sp);
  }

  if ((cindx >= 1) && (cindx < 800)) {
    d_cindx = cindx;
  } else {
    d_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, 800, &y_emlrtBCI, sp);
  }

  batEngDltOptVec->data[i8 - 1] = batFrcOptTn3[((b_itmp + 11 * (d_iy - 1)) + 66 *
    (d_cindx - 1)) - 1] * wayStp;

  /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
  /*    writing the output for the optimal fuel energy */
  i0 = engKinOptInxVec->size[0];
  i1 = (int32_T)wayInxEnd;
  if ((i1 >= 1) && (i1 < i0)) {
    i9 = i1;
  } else {
    i9 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &bb_emlrtBCI, sp);
  }

  mtmp = engKinOptInxVec->data[i9 - 1];
  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    i0 = (int32_T)mtmp;
  } else {
    i0 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &o_emlrtDCI, sp);
  }

  i1 = staVec->size[0];
  itmp = (int32_T)wayInxEnd - 1;
  if ((itmp >= 1) && (itmp < i1)) {
    c_itmp = itmp;
  } else {
    c_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &db_emlrtBCI, sp);
  }

  mtmp = staVec->data[c_itmp - 1];
  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    i1 = (int32_T)mtmp;
  } else {
    i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &p_emlrtDCI, sp);
  }

  itmp = (int32_T)wayInxEnd;
  if ((i0 >= 1) && (i0 < 11)) {
    i10 = i0;
  } else {
    i10 = emlrtDynamicBoundsCheckR2012b(i0, 1, 11, &ab_emlrtBCI, sp);
  }

  if ((i1 >= 1) && (i1 < 6)) {
    i11 = i1;
  } else {
    i11 = emlrtDynamicBoundsCheckR2012b(i1, 1, 6, &cb_emlrtBCI, sp);
  }

  if ((itmp >= 1) && (itmp < 800)) {
    d_itmp = itmp;
  } else {
    d_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, 800, &eb_emlrtBCI, sp);
  }

  *fulEngOpt = fulEngOptTn3[((i10 + 11 * (i11 - 1)) + 66 * (d_itmp - 1)) - 1];

  /*  Initialisieren des Vektors der optimalen Kraftstoffenergieänderung */
  /*    intializing the optimum fuel energy change vector */
  i0 = fulEngDltOptVec->size[0];
  fulEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngDltOptVec, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    fulEngDltOptVec->data[i0] = 0.0;
  }

  /*  Costate für die kinetische Energie initialisieren */
  /*    intializing the kinetic energy's costate */
  i0 = psiEngKinOptVec->size[0];
  psiEngKinOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)psiEngKinOptVec, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i0 = 0; i0 < loop_ub; i0++) {
    psiEngKinOptVec->data[i0] = 0.0;
  }

  /* % Rückwärtsrechnung über alle Wegpunkte  */
  /*    reverse calculation of all the path indexes */
  /*  Rekonstruieren des optimalen Pfades aus */
  /*    rebuilding the optimale path */
  i0 = (int32_T)-((wayInxBeg + 1.0) + (-1.0 - wayInxEnd));
  emlrtForLoopVectorCheckR2012b(wayInxEnd, -1.0, wayInxBeg + 1.0, mxDOUBLE_CLASS,
    i0, &e_emlrtRTEI, sp);
  wayInx = 0;
  emxInit_real_T(sp, &y, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_engKinMat_engKinInx_wayInx, 1, &emlrtRTEI, true);
  while (wayInx <= i0 - 1) {
    b_wayInx = wayInxEnd + -(real_T)wayInx;

    /*  optimalen Vorgängerindex aus Tensor auslesen */
    /*    reading the tensor's optimum previous index  */
    i1 = engKinOptInxVec->size[0];
    itmp = (int32_T)b_wayInx;
    if ((itmp >= 1) && (itmp < i1)) {
      e_itmp = itmp;
    } else {
      e_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &fb_emlrtBCI, sp);
    }

    mtmp = engKinOptInxVec->data[e_itmp - 1];
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      i1 = (int32_T)mtmp;
    } else {
      i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &d_emlrtDCI, sp);
    }

    emlrtDynamicBoundsCheckR2012b(i1, 1, 11, &d_emlrtBCI, sp);
    i1 = staVec->size[0];
    itmp = (int32_T)(b_wayInx - 1.0);
    if ((itmp >= 1) && (itmp < i1)) {
      f_itmp = itmp;
    } else {
      f_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &gb_emlrtBCI, sp);
    }

    mtmp = staVec->data[f_itmp - 1];
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      i1 = (int32_T)mtmp;
    } else {
      i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &e_emlrtDCI, sp);
    }

    emlrtDynamicBoundsCheckR2012b(i1, 1, 6, &e_emlrtBCI, sp);
    i1 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckR2012b(i1, 1, 800, &f_emlrtBCI, sp);
    if (optPreInxTn3[(((int32_T)engKinOptInxVec->data[(int32_T)b_wayInx - 1] +
                       11 * ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1))
                      + 66 * ((int32_T)b_wayInx - 1)) - 1] == 0.0) {
      /*  <- Vorgänger = predecessor */
      st.site = &b_emlrtRSI;
      for (i1 = 0; i1 < 47; i1++) {
        u[i1] = varargin_1[i1];
      }

      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(&st, 47, m0, &u[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &p_emlrtRSI;
      error(&b_st, b_y, &emlrtMCI);
    }

    /*  optimalen Index dekodieren */
    /*    decoding the optimal index */
    if (b_wayInx > wayInxBeg + 1.0) {
      /*  what does this do? - assigns index values, that's for sure */
      /*  - its repopulating the vectors (previously assigned to 0) by */
      /*    looping through all the path states and selecting all the  */
      /*    optimum state variables in each of the mats based on the */
      /*    generated optimum indexes */
      st.site = &c_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      if (((int32_T)optPreInxTn3[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + 11 * ((int32_T)staVec->data[(int32_T)b_wayInx - 2]
              - 1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] >= 1) && ((int32_T)
           optPreInxTn3[(((int32_T)engKinOptInxVec->data[(int32_T)b_wayInx - 1]
                          + 11 * ((int32_T)staVec->data[(int32_T)b_wayInx - 2] -
              1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] <= (int32_T)engKinNum *
           (int32_T)staNum)) {
        p = true;
      } else {
        p = false;
      }

      if (!!p) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &f_emlrtRTEI,
          "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      }

      c_st.site = &o_emlrtRSI;
      iy = div_s32(&c_st, (int32_T)optPreInxTn3[(((int32_T)engKinOptInxVec->
        data[(int32_T)b_wayInx - 1] + 11 * ((int32_T)staVec->data[(int32_T)
        b_wayInx - 2] - 1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] - 1, (int32_T)
                   engKinNum);
      i1 = engKinOptInxVec->size[0];
      itmp = (int32_T)b_wayInx - 1;
      if ((itmp >= 1) && (itmp < i1)) {
        g_itmp = itmp;
      } else {
        g_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &nb_emlrtBCI, sp);
      }

      engKinOptInxVec->data[g_itmp - 1] = (int32_T)optPreInxTn3[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + 11 * ((int32_T)
        staVec->data[(int32_T)b_wayInx - 2] - 1)) + 66 * ((int32_T)b_wayInx - 1))
        - 1] - iy * (int32_T)engKinNum;
      i1 = staVec->size[0];
      itmp = (int32_T)b_wayInx - 2;
      if ((itmp >= 1) && (itmp < i1)) {
        h_itmp = itmp;
      } else {
        h_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &ob_emlrtBCI, sp);
      }

      staVec->data[h_itmp - 1] = iy + 1;

      /*  Batterieenergieänderung für Vorgängerintervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*    storing the previous interval's battery energy change's flow */
      /*    amount */
      i1 = batEngDltOptVec->size[0];
      itmp = (int32_T)b_wayInx - 2;
      iy = engKinOptInxVec->size[0];
      cindx = (int32_T)b_wayInx - 1;
      if ((cindx >= 1) && (cindx < iy)) {
        e_cindx = cindx;
      } else {
        e_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &rb_emlrtBCI, sp);
      }

      mtmp = engKinOptInxVec->data[e_cindx - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        iy = (int32_T)mtmp;
      } else {
        iy = (int32_T)emlrtIntegerCheckR2012b(mtmp, &s_emlrtDCI, sp);
      }

      cindx = staVec->size[0];
      d_ix = (int32_T)b_wayInx - 2;
      if ((d_ix >= 1) && (d_ix < cindx)) {
        g_ix = d_ix;
      } else {
        g_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &tb_emlrtBCI, sp);
      }

      mtmp = staVec->data[g_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        cindx = (int32_T)mtmp;
      } else {
        cindx = (int32_T)emlrtIntegerCheckR2012b(mtmp, &t_emlrtDCI, sp);
      }

      d_ix = (int32_T)b_wayInx - 2;
      if ((itmp >= 1) && (itmp < i1)) {
        i_itmp = itmp;
      } else {
        i_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &pb_emlrtBCI, sp);
      }

      if ((iy >= 1) && (iy < 11)) {
        e_iy = iy;
      } else {
        e_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, 11, &qb_emlrtBCI, sp);
      }

      if ((cindx >= 1) && (cindx < 6)) {
        f_cindx = cindx;
      } else {
        f_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, 6, &sb_emlrtBCI, sp);
      }

      if ((d_ix >= 1) && (d_ix < 800)) {
        h_ix = d_ix;
      } else {
        h_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, 800, &ub_emlrtBCI, sp);
      }

      batEngDltOptVec->data[i_itmp - 1] = batFrcOptTn3[((e_iy + 11 * (f_cindx -
        1)) + 66 * (h_ix - 1)) - 1] * wayStp;

      /*  Krafstoffenergieänderung für Intervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
      /*    storing the interval's fuel energy change flow amount */
      /*    describing the output size of the optimal fuel energy */
      i1 = fulEngDltOptVec->size[0];
      itmp = (int32_T)b_wayInx - 1;
      iy = engKinOptInxVec->size[0];
      cindx = (int32_T)b_wayInx;
      if ((cindx >= 1) && (cindx < iy)) {
        g_cindx = cindx;
      } else {
        g_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &xb_emlrtBCI, sp);
      }

      mtmp = engKinOptInxVec->data[g_cindx - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        iy = (int32_T)mtmp;
      } else {
        iy = (int32_T)emlrtIntegerCheckR2012b(mtmp, &u_emlrtDCI, sp);
      }

      cindx = staVec->size[0];
      d_ix = (int32_T)b_wayInx - 1;
      if ((d_ix >= 1) && (d_ix < cindx)) {
        i_ix = d_ix;
      } else {
        i_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &ac_emlrtBCI, sp);
      }

      mtmp = staVec->data[i_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        cindx = (int32_T)mtmp;
      } else {
        cindx = (int32_T)emlrtIntegerCheckR2012b(mtmp, &v_emlrtDCI, sp);
      }

      d_ix = engKinOptInxVec->size[0];
      b_ix = (int32_T)b_wayInx - 1;
      if ((b_ix >= 1) && (b_ix < d_ix)) {
        j_ix = b_ix;
      } else {
        j_ix = emlrtDynamicBoundsCheckR2012b(b_ix, 1, d_ix, &cc_emlrtBCI, sp);
      }

      mtmp = engKinOptInxVec->data[j_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        d_ix = (int32_T)mtmp;
      } else {
        d_ix = (int32_T)emlrtIntegerCheckR2012b(mtmp, &w_emlrtDCI, sp);
      }

      b_ix = staVec->size[0];
      ix = (int32_T)b_wayInx - 2;
      if ((ix >= 1) && (ix < b_ix)) {
        k_ix = ix;
      } else {
        k_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, b_ix, &ec_emlrtBCI, sp);
      }

      mtmp = staVec->data[k_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        b_ix = (int32_T)mtmp;
      } else {
        b_ix = (int32_T)emlrtIntegerCheckR2012b(mtmp, &x_emlrtDCI, sp);
      }

      ix = (int32_T)b_wayInx - 1;
      if ((itmp >= 1) && (itmp < i1)) {
        j_itmp = itmp;
      } else {
        j_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &vb_emlrtBCI, sp);
      }

      if ((iy >= 1) && (iy < 11)) {
        f_iy = iy;
      } else {
        f_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, 11, &wb_emlrtBCI, sp);
      }

      if ((cindx >= 1) && (cindx < 6)) {
        h_cindx = cindx;
      } else {
        h_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, 6, &yb_emlrtBCI, sp);
      }

      if ((d_ix >= 1) && (d_ix < 11)) {
        l_ix = d_ix;
      } else {
        l_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, 11, &bc_emlrtBCI, sp);
      }

      if ((b_ix >= 1) && (b_ix < 6)) {
        m_ix = b_ix;
      } else {
        m_ix = emlrtDynamicBoundsCheckR2012b(b_ix, 1, 6, &dc_emlrtBCI, sp);
      }

      if ((ix >= 1) && (ix < 800)) {
        n_ix = ix;
      } else {
        n_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, 800, &fc_emlrtBCI, sp);
      }

      fulEngDltOptVec->data[j_itmp - 1] = fulEngOptTn3[((f_iy + 11 * (h_cindx -
        1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] - fulEngOptTn3[((l_ix + 11 *
        (m_ix - 1)) + 66 * (n_ix - 1)) - 1];

      /*         %% Bestimmung des costate für die kinetische Energie */
      /*    determining the kinetic energy costate */
      /*  */
      /*  Am jeweiligen Wegpunkt wird der Kraftstoffaufwand gegenüber eine */
      /*  änderung der kinetischen Engergie an der Stelle der */
      /*  optimalen Trajektorie berechnet. */
      /*    at each path_idx the fuel is calculated towards a change in the */
      /*    KE at the location of optimal trajectory. (doesn't make much */
      /*    sense) */
      /*    calculating the KE costate vec by diving the delta optimum fuel  */
      /*    energy tensor by the delta kinetic energy mat for each wayInx. */
      i1 = engKinNumVec_wayInx->size[0];
      itmp = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &g_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx->data[(int32_T)b_wayInx - 2]) {
        loop_ub = 0;
      } else {
        mtmp = engKinNumVec_wayInx->data[(int32_T)b_wayInx - 2];
        if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
          i1 = (int32_T)mtmp;
        } else {
          i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &f_emlrtDCI, sp);
        }

        if ((i1 >= 1) && (i1 < 11)) {
          loop_ub = i1;
        } else {
          loop_ub = emlrtDynamicBoundsCheckR2012b(i1, 1, 11, &h_emlrtBCI, sp);
        }
      }

      i1 = engKinNumVec_wayInx->size[0];
      itmp = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &k_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx->data[(int32_T)b_wayInx - 2]) {
        cindx = 0;
      } else {
        i1 = engKinMat_engKinInx_wayInx->size[0];
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, &l_emlrtBCI, sp);
        mtmp = engKinNumVec_wayInx->data[(int32_T)b_wayInx - 2];
        i1 = engKinMat_engKinInx_wayInx->size[0];
        if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
          itmp = (int32_T)mtmp;
        } else {
          itmp = (int32_T)emlrtIntegerCheckR2012b(mtmp, &h_emlrtDCI, sp);
        }

        if ((itmp >= 1) && (itmp < i1)) {
          cindx = itmp;
        } else {
          cindx = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &l_emlrtBCI, sp);
        }
      }

      i1 = (int32_T)b_wayInx - 1;
      if ((i1 >= 1) && (i1 < 800)) {
        d_ix = i1;
      } else {
        d_ix = emlrtDynamicBoundsCheckR2012b(i1, 1, 800, &j_emlrtBCI, sp);
      }

      i1 = staVec->size[0];
      itmp = (int32_T)b_wayInx - 2;
      if ((itmp >= 1) && (itmp < i1)) {
        k_itmp = itmp;
      } else {
        k_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &gc_emlrtBCI, sp);
      }

      mtmp = staVec->data[k_itmp - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        i1 = (int32_T)mtmp;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &g_emlrtDCI, sp);
      }

      if ((i1 >= 1) && (i1 < 6)) {
        iy = i1;
      } else {
        iy = emlrtDynamicBoundsCheckR2012b(i1, 1, 6, &i_emlrtBCI, sp);
      }

      fulEngOptTn3_size[0] = loop_ub;
      for (i1 = 0; i1 < loop_ub; i1++) {
        fulEngOptTn3_data[i1] = fulEngOptTn3[(i1 + 11 * (iy - 1)) + 66 * (d_ix -
          1)];
      }

      b_fulEngOptTn3_data.data = (real_T *)&fulEngOptTn3_data;
      b_fulEngOptTn3_data.size = (int32_T *)&fulEngOptTn3_size;
      b_fulEngOptTn3_data.allocatedSize = 11;
      b_fulEngOptTn3_data.numDimensions = 1;
      b_fulEngOptTn3_data.canFreeData = false;
      st.site = &d_emlrtRSI;
      diff(&st, &b_fulEngOptTn3_data, y);
      b_ix = y->size[0];
      loop_ub = y->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x_data[i1] = y->data[i1];
      }

      i1 = engKinMat_engKinInx_wayInx->size[1];
      itmp = (int32_T)b_wayInx - 1;
      if ((itmp >= 1) && (itmp < i1)) {
        d_ix = itmp;
      } else {
        d_ix = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &m_emlrtBCI, sp);
      }

      i1 = b_engKinMat_engKinInx_wayInx->size[0];
      b_engKinMat_engKinInx_wayInx->size[0] = cindx;
      emxEnsureCapacity(sp, (emxArray__common *)b_engKinMat_engKinInx_wayInx, i1,
                        (int32_T)sizeof(real_T), &emlrtRTEI);
      for (i1 = 0; i1 < cindx; i1++) {
        b_engKinMat_engKinInx_wayInx->data[i1] =
          engKinMat_engKinInx_wayInx->data[i1 + engKinMat_engKinInx_wayInx->
          size[0] * (d_ix - 1)];
      }

      st.site = &e_emlrtRSI;
      diff(&st, b_engKinMat_engKinInx_wayInx, y);
      st.site = &d_emlrtRSI;
      siz[0] = b_ix;
      siz[1] = 1;
      varargin_2[0] = (uint32_T)y->size[0];
      varargin_2[1] = 1U;
      p = false;
      b_p = true;
      iy = 0;
      exitg1 = false;
      while ((!exitg1) && (iy < 2)) {
        if (!((int8_T)siz[iy] == (int32_T)varargin_2[iy])) {
          b_p = false;
          exitg1 = true;
        } else {
          iy++;
        }
      }

      if (!b_p) {
      } else {
        p = true;
      }

      if (p) {
      } else {
        emlrtErrorWithMessageIdR2012b(&st, &g_emlrtRTEI, "MATLAB:dimagree", 0);
      }

      /*  <-fast immer 5000; */
      psiEngKinVec_data[0] = 0.0;
      for (i1 = 0; i1 < b_ix; i1++) {
        psiEngKinVec_data[i1 + 1] = x_data[i1] / y->data[i1];
      }

      /*  what is the point of adding 0 */
      i1 = psiEngKinOptVec->size[0];
      itmp = (int32_T)b_wayInx - 1;
      iy = 1 + b_ix;
      cindx = engKinOptInxVec->size[0];
      d_ix = (int32_T)b_wayInx - 1;
      if ((d_ix >= 1) && (d_ix < cindx)) {
        o_ix = d_ix;
      } else {
        o_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &jc_emlrtBCI, sp);
      }

      mtmp = engKinOptInxVec->data[o_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        cindx = (int32_T)mtmp;
      } else {
        cindx = (int32_T)emlrtIntegerCheckR2012b(mtmp, &y_emlrtDCI, sp);
      }

      if ((itmp >= 1) && (itmp < i1)) {
        l_itmp = itmp;
      } else {
        l_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &hc_emlrtBCI, sp);
      }

      if ((cindx >= 1) && (cindx < iy)) {
        i_cindx = cindx;
      } else {
        i_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &ic_emlrtBCI, sp);
      }

      psiEngKinOptVec->data[l_itmp - 1] = psiEngKinVec_data[i_cindx - 1];

      /*  Potentialgrößen im ersten Punkt speichern */
      /*    save potetial variables in the first point/index */
    } else {
      /*  if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1) */
      st.site = &f_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      if (((int32_T)optPreInxTn3[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + 11 * ((int32_T)staVec->data[(int32_T)b_wayInx - 2]
              - 1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] >= 1) && ((int32_T)
           optPreInxTn3[(((int32_T)engKinOptInxVec->data[(int32_T)b_wayInx - 1]
                          + 11 * ((int32_T)staVec->data[(int32_T)b_wayInx - 2] -
              1)) + 66 * ((int32_T)b_wayInx - 1)) - 1] <= (int32_T)engKinNum *
           (int32_T)staNum)) {
        p = true;
      } else {
        p = false;
      }

      if (!!p) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &f_emlrtRTEI,
          "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      }

      i1 = engKinOptInxVec->size[0];
      itmp = (int32_T)b_wayInx - 1;
      if ((itmp >= 1) && (itmp < i1)) {
        m_itmp = itmp;
      } else {
        m_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &hb_emlrtBCI, sp);
      }

      st.site = &o_emlrtRSI;
      engKinOptInxVec->data[m_itmp - 1] = (int32_T)optPreInxTn3[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + 11 * ((int32_T)
        staVec->data[(int32_T)b_wayInx - 2] - 1)) + 66 * ((int32_T)b_wayInx - 1))
        - 1] - div_s32(&st, (int32_T)optPreInxTn3[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + 11 * ((int32_T)
        staVec->data[(int32_T)b_wayInx - 2] - 1)) + 66 * ((int32_T)b_wayInx - 1))
                       - 1] - 1, (int32_T)engKinNum) * (int32_T)engKinNum;
      i1 = fulEngDltOptVec->size[0];
      itmp = (int32_T)b_wayInx - 1;
      iy = engKinOptInxVec->size[0];
      cindx = (int32_T)b_wayInx;
      if ((cindx >= 1) && (cindx < iy)) {
        j_cindx = cindx;
      } else {
        j_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &kb_emlrtBCI, sp);
      }

      mtmp = engKinOptInxVec->data[j_cindx - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        iy = (int32_T)mtmp;
      } else {
        iy = (int32_T)emlrtIntegerCheckR2012b(mtmp, &q_emlrtDCI, sp);
      }

      cindx = staVec->size[0];
      d_ix = (int32_T)b_wayInx - 1;
      if ((d_ix >= 1) && (d_ix < cindx)) {
        p_ix = d_ix;
      } else {
        p_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &mb_emlrtBCI, sp);
      }

      mtmp = staVec->data[p_ix - 1];
      if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
        cindx = (int32_T)mtmp;
      } else {
        cindx = (int32_T)emlrtIntegerCheckR2012b(mtmp, &r_emlrtDCI, sp);
      }

      if ((itmp >= 1) && (itmp < i1)) {
        n_itmp = itmp;
      } else {
        n_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &ib_emlrtBCI, sp);
      }

      if ((iy >= 1) && (iy < 11)) {
        g_iy = iy;
      } else {
        g_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, 11, &jb_emlrtBCI, sp);
      }

      if ((cindx >= 1) && (cindx < 6)) {
        k_cindx = cindx;
      } else {
        k_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, 6, &lb_emlrtBCI, sp);
      }

      fulEngDltOptVec->data[n_itmp - 1] = fulEngOptTn3[((g_iy + 11 * (k_cindx -
        1)) + 66 * ((int32_T)b_wayInx - 1)) - 1];
    }

    /*  optimale kinetische Energie im Vorgängerpunkt */
    /*    optimal KE from previous point / path_idx */
    i1 = engKinOptVec->size[0];
    itmp = (int32_T)b_wayInx - 1;
    iy = engKinMat_engKinInx_wayInx->size[0];
    cindx = engKinOptInxVec->size[0];
    d_ix = (int32_T)b_wayInx - 1;
    if ((d_ix >= 1) && (d_ix < cindx)) {
      q_ix = d_ix;
    } else {
      q_ix = emlrtDynamicBoundsCheckR2012b(d_ix, 1, cindx, &mc_emlrtBCI, sp);
    }

    mtmp = engKinOptInxVec->data[q_ix - 1];
    if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
      cindx = (int32_T)mtmp;
    } else {
      cindx = (int32_T)emlrtIntegerCheckR2012b(mtmp, &ab_emlrtDCI, sp);
    }

    d_ix = engKinMat_engKinInx_wayInx->size[1];
    b_ix = (int32_T)b_wayInx - 1;
    if ((itmp >= 1) && (itmp < i1)) {
      o_itmp = itmp;
    } else {
      o_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, i1, &kc_emlrtBCI, sp);
    }

    if ((cindx >= 1) && (cindx < iy)) {
      l_cindx = cindx;
    } else {
      l_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, iy, &lc_emlrtBCI, sp);
    }

    if ((b_ix >= 1) && (b_ix < d_ix)) {
      r_ix = b_ix;
    } else {
      r_ix = emlrtDynamicBoundsCheckR2012b(b_ix, 1, d_ix, &nc_emlrtBCI, sp);
    }

    engKinOptVec->data[o_itmp - 1] = engKinMat_engKinInx_wayInx->data[(l_cindx +
      engKinMat_engKinInx_wayInx->size[0] * (r_ix - 1)) - 1];
    wayInx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_engKinMat_engKinInx_wayInx);
  emxFree_real_T(&y);
  emxFree_real_T(&engKinOptInxVec);

  /*  end of path_idx loop */
  /*  end of function */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (clcOptTrj_tmp.c) */
