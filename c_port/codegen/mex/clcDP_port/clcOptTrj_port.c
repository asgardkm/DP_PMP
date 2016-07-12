/*
 * clcOptTrj_port.c
 *
 * Code generation for function 'clcOptTrj_port'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcOptTrj_port.h"
#include "clcDP_port_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "diff.h"
#include "clcDP_port_mexutil.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 86, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo y_emlrtRSI = { 87, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo ab_emlrtRSI = { 131, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo bb_emlrtRSI = { 143, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo cb_emlrtRSI = { 175, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo db_emlrtRSI = { 176, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo eb_emlrtRSI = { 183, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRSInfo fb_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo gb_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo hb_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ib_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo jb_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo kb_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo lb_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo mb_emlrtRSI = { 19, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRSInfo nb_emlrtRSI = { 38, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtMCInfo e_emlrtMCI = { 41, 9, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo f_emlrtMCI = { 38, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo g_emlrtMCI = { 82, 9, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo h_emlrtMCI = { 81, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtMCInfo i_emlrtMCI = { 16, 1, "error",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

static emlrtMCInfo l_emlrtMCI = { 14, 5, "rdivide",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtMCInfo m_emlrtMCI = { 13, 15, "rdivide",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 10, 5, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtRTEInfo j_emlrtRTEI = { 91, 1, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 73, 1, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtBCInfo tb_emlrtBCI = { 1, 800, 176, 80, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ub_emlrtBCI = { 1, 11, 176, 48, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtDCInfo bb_emlrtDCI = { 176, 48, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 1
};

static emlrtBCInfo vb_emlrtBCI = { 1, 800, 176, 50, "engKinNumVec_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 175, 90, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 175, 73, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 175, 41, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtDCInfo cb_emlrtDCI = { 175, 41, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 1
};

static emlrtBCInfo ac_emlrtBCI = { 1, 800, 175, 43, "engKinNumVec_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 128, 28, "optPreInxTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 128, 9, "optPreInxTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 127, 27, "optPreInxTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtRTEInfo v_emlrtRTEI = { 123, 1, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m" };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 88, 20, "inx", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 87, 8, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtDCInfo db_emlrtDCI = { 57, 23, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 1
};

static emlrtDCInfo eb_emlrtDCI = { 57, 23, "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 4
};

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 88, 24, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 91, 1, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 96, 14, "engKinOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo jc_emlrtBCI = { 1, 11, 97, 32, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 97, 48, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 101, 17, "batEngDltOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 102, 18, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 102, 18, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 102, 45, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 102, 45, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 102, 65, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 108, 18, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 108, 18, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 108, 45, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 108, 45, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 108, 65, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 127, 43, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 128, 16, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 183, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 186, 25, "fulEngDltOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 187, 26, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 187, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 187, 50, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 187, 50, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 187, 67, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 143, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 143, 45, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo id_emlrtBCI = { -1, -1, 150, 25, "batEngDltOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 151, 26, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 151, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 152, 13, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo md_emlrtBCI = { -1, -1, 152, 13, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 152, 30, "batFrcOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo od_emlrtBCI = { -1, -1, 159, 25, "fulEngDltOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 160, 26, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 160, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 160, 50, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 160, 50, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo td_emlrtBCI = { -1, -1, 160, 67, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 161, 26, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 161, 26, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 161, 52, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 161, 52, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 161, 69, "fulEngOptTn3",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 175, 73, "staVec", "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo be_emlrtBCI = { -1, -1, 178, 9, "psiEngKinOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 178, 37, "psiEngKinVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo de_emlrtBCI = { -1, -1, 178, 66, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 192, 18, "engKinOptVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo fe_emlrtBCI = { 1, 11, 193, 36, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 193, 52, "engKinOptInxVec",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtBCInfo he_emlrtBCI = { 1, 800, 193, 64, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcOptTrj_port.m", 0
};

static emlrtRSInfo sb_emlrtRSI = { 13, "rdivide",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtRSInfo ub_emlrtRSI = { 16, "error",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

static emlrtRSInfo vb_emlrtRSI = { 81, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo wb_emlrtRSI = { 38, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo bc_emlrtRSI = { 14, "rdivide",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtRSInfo cc_emlrtRSI = { 82, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo dc_emlrtRSI = { 41, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ec_emlrtRSI = { 18, "indexDivide",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\indexDivide.m"
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

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

void clcOptTrj_port(const emlrtStack *sp, real_T wayStp, real_T wayNum, real_T
                    wayInxBeg, real_T wayInxEnd, real_T engKinNum, real_T staNum,
                    const real_T engKinNumVec_wayInx[800], const real_T
                    engKinMat_engKinInx_wayInx[8800], const emxArray_real_T
                    *optPreInxTn3, const emxArray_real_T *batFrcOptTn3, const
                    emxArray_real_T *fulEngOptTn3, const emxArray_real_T
                    *cos2goActMat, emxArray_real_T *engKinOptVec,
                    emxArray_real_T *batEngDltOptVec, emxArray_real_T
                    *fulEngDltOptVec, emxArray_real_T *staVec, emxArray_real_T
                    *psiEngKinOptVec, real_T *fulEngOpt)
{
  int32_T i7;
  real_T mtmp;
  int32_T ixstart;
  emxArray_real_T *engKinOptInxVec;
  boolean_T overflow;
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 36 };

  const mxArray *m4;
  char_T cv14[36];
  int32_T i;
  static const char_T cv15[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 39 };

  char_T cv16[39];
  static const char_T cv17[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r',
    '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T outsz[2];
  emxArray_real_T *extremum;
  emxArray_int32_T *iindx;
  int32_T n;
  int32_T ix;
  int32_T iy;
  int32_T ixstop;
  int32_T itmp;
  int32_T cindx;
  boolean_T b_ix;
  int32_T c_ix;
  boolean_T exitg3;
  boolean_T b_ixstart;
  emxArray_real_T *indx;
  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 36 };

  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 39 };

  boolean_T exitg2;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  int32_T i11;
  int32_T wayInx;
  emxArray_real_T *x;
  emxArray_real_T *r2;
  emxArray_real_T *b_fulEngOptTn3;
  real_T b_wayInx;
  const mxArray *e_y;
  static const int32_T iv14[2] = { 1, 47 };

  char_T cv18[47];
  static const char_T cv19[47] = { 'F', 'e', 'h', 'l', 'e', 'r', ' ', 'b', 'e',
    'i', 'm', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n', ' ', 'd', 'e',
    'r', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l', 'e', 'n', ' ', 'V', 'o', 'r',
    'g', 'a', 'e', 'n', 'g', 'e', 'r', '.' };

  boolean_T b_overflow;
  const mxArray *f_y;
  static const int32_T iv15[2] = { 1, 36 };

  static const char_T cv20[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'd', '2', 's', 'u', 'b', '_', 'I', 'n', 'd',
    'e', 'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  int32_T i12;
  real_T engKinMat_engKinInx_wayInx_data[11];
  int32_T engKinMat_engKinInx_wayInx_size[1];
  emxArray_real_T b_engKinMat_engKinInx_wayInx_da;
  real_T y_data[10];
  int8_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  const mxArray *g_y;
  static const int32_T iv16[2] = { 1, 15 };

  char_T cv21[15];
  static const char_T cv22[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i',
    'm', 'a', 'g', 'r', 'e', 'e' };

  real_T psiEngKinVec_data[11];
  boolean_T c_overflow;
  const mxArray *h_y;
  static const int32_T iv17[2] = { 1, 36 };

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
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &st;
  h_st.tls = st.tls;
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
  i7 = engKinOptVec->size[0];
  mtmp = emlrtNonNegativeCheckFastR2012b(wayNum, &eb_emlrtDCI, sp);
  engKinOptVec->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(mtmp,
    &db_emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)engKinOptVec, i7, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  mtmp = emlrtNonNegativeCheckFastR2012b(wayNum, &eb_emlrtDCI, sp);
  ixstart = (int32_T)emlrtIntegerCheckFastR2012b(mtmp, &db_emlrtDCI, sp);
  for (i7 = 0; i7 < ixstart; i7++) {
    engKinOptVec->data[i7] = rtInf;
  }

  /*  Trajektorie der optimalen Batterieenergieänderung im Intervall */
  /*    optimal battery energy change trajectories for the interval */
  i7 = batEngDltOptVec->size[0];
  batEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)batEngDltOptVec, i7, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  ixstart = (int32_T)wayNum;
  for (i7 = 0; i7 < ixstart; i7++) {
    batEngDltOptVec->data[i7] = rtInf;
  }

  /*  Trajektorie des optimalen Antriebsstrangzustands im Intervall */
  /*    optimal powertrain state trajectories for the interval */
  i7 = staVec->size[0];
  staVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)staVec, i7, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  ixstart = (int32_T)wayNum;
  for (i7 = 0; i7 < ixstart; i7++) {
    staVec->data[i7] = 0.0;
  }

  c_emxInit_real_T(sp, &engKinOptInxVec, 1, &k_emlrtRTEI, true);

  /* % Initialisieren des finalen Zustands */
  /*    intializing the final state */
  /*  Indexvektor der optimalen kinetischen Energien */
  /*    index vector for the optimal kinetic energies */
  i7 = engKinOptInxVec->size[0];
  engKinOptInxVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)engKinOptInxVec, i7, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  ixstart = (int32_T)wayNum;
  for (i7 = 0; i7 < ixstart; i7++) {
    engKinOptInxVec->data[i7] = 0.0;
  }

  /*  Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls  */
  /*  Zielgang nicht festgelegt ist */
  /*    find the optimal gear and speed if the target gear isn't fixed */
  st.site = &x_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  if (((cos2goActMat->size[0] == 1) && (cos2goActMat->size[1] == 1)) ||
      (cos2goActMat->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    y = NULL;
    m4 = emlrtCreateCharArray(2, iv10);
    for (i = 0; i < 36; i++) {
      cv14[i] = cv15[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m4, cv14);
    emlrtAssign(&y, m4);
    d_st.site = &wb_emlrtRSI;
    e_st.site = &dc_emlrtRSI;
    error(&d_st, b_message(&e_st, y, &e_emlrtMCI), &f_emlrtMCI);
  }

  if (cos2goActMat->size[0] > 0) {
  } else {
    b_y = NULL;
    m4 = emlrtCreateCharArray(2, iv11);
    for (i = 0; i < 39; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m4, cv16);
    emlrtAssign(&b_y, m4);
    d_st.site = &vb_emlrtRSI;
    e_st.site = &cc_emlrtRSI;
    error(&d_st, b_message(&e_st, b_y, &g_emlrtMCI), &h_emlrtMCI);
  }

  for (i7 = 0; i7 < 2; i7++) {
    outsz[i7] = cos2goActMat->size[i7];
  }

  b_emxInit_real_T(&c_st, &extremum, 2, &i_emlrtRTEI, true);
  b_emxInit_int32_T(&c_st, &iindx, 2, &i_emlrtRTEI, true);
  i7 = extremum->size[0] * extremum->size[1];
  extremum->size[0] = 1;
  extremum->size[1] = outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)extremum, i7, (int32_T)sizeof
                    (real_T), &j_emlrtRTEI);
  n = outsz[1];
  i7 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i7, (int32_T)sizeof
                    (int32_T), &i_emlrtRTEI);
  i7 = iindx->size[0] * iindx->size[1];
  iindx->size[1] = outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i7, (int32_T)sizeof
                    (int32_T), &i_emlrtRTEI);
  for (i7 = 0; i7 < n; i7++) {
    iindx->data[i7] = 1;
  }

  n = cos2goActMat->size[0];
  ix = 0;
  iy = -1;
  d_st.site = &hb_emlrtRSI;
  if (1 > cos2goActMat->size[1]) {
    overflow = false;
  } else {
    overflow = (cos2goActMat->size[1] > 2147483646);
  }

  if (overflow) {
    f_st.site = &v_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (i = 1; i <= cos2goActMat->size[1]; i++) {
    d_st.site = &ib_emlrtRSI;
    ixstart = ix;
    ixstop = ix + n;
    mtmp = cos2goActMat->data[ix];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(cos2goActMat->data[ix])) {
        f_st.site = &kb_emlrtRSI;
        if (ix + 2 > ixstop) {
          b_ix = false;
        } else {
          b_ix = (ixstop > 2147483646);
        }

        if (b_ix) {
          g_st.site = &v_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        c_ix = ix + 1;
        exitg3 = false;
        while ((!exitg3) && (c_ix + 1 <= ixstop)) {
          cindx++;
          ixstart = c_ix;
          if (!muDoubleScalarIsNaN(cos2goActMat->data[c_ix])) {
            mtmp = cos2goActMat->data[c_ix];
            itmp = cindx;
            exitg3 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (ixstart + 1 < ixstop) {
        f_st.site = &jb_emlrtRSI;
        if (ixstart + 2 > ixstop) {
          b_ixstart = false;
        } else {
          b_ixstart = (ixstop > 2147483646);
        }

        if (b_ixstart) {
          g_st.site = &v_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        for (c_ix = ixstart + 1; c_ix + 1 <= ixstop; c_ix++) {
          cindx++;
          if (cos2goActMat->data[c_ix] < mtmp) {
            mtmp = cos2goActMat->data[c_ix];
            itmp = cindx;
          }
        }
      }
    }

    iy++;
    extremum->data[iy] = mtmp;
    iindx->data[iy] = itmp;
    ix += n;
  }

  b_emxInit_real_T(&c_st, &indx, 2, &i_emlrtRTEI, true);
  i7 = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)indx, i7, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  ixstart = iindx->size[0] * iindx->size[1];
  for (i7 = 0; i7 < ixstart; i7++) {
    indx->data[i7] = iindx->data[i7];
  }

  emxFree_int32_T(&iindx);
  st.site = &y_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  if ((extremum->size[1] == 1) || (extremum->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    c_y = NULL;
    m4 = emlrtCreateCharArray(2, iv12);
    for (i = 0; i < 36; i++) {
      cv14[i] = cv15[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 36, m4, cv14);
    emlrtAssign(&c_y, m4);
    d_st.site = &wb_emlrtRSI;
    e_st.site = &dc_emlrtRSI;
    error(&d_st, b_message(&e_st, c_y, &e_emlrtMCI), &f_emlrtMCI);
  }

  if (extremum->size[1] > 0) {
  } else {
    d_y = NULL;
    m4 = emlrtCreateCharArray(2, iv13);
    for (i = 0; i < 39; i++) {
      cv16[i] = cv17[i];
    }

    emlrtInitCharArrayR2013a(&c_st, 39, m4, cv16);
    emlrtAssign(&d_y, m4);
    d_st.site = &vb_emlrtRSI;
    e_st.site = &cc_emlrtRSI;
    error(&d_st, b_message(&e_st, d_y, &g_emlrtMCI), &h_emlrtMCI);
  }

  d_st.site = &lb_emlrtRSI;
  ixstart = 1;
  n = extremum->size[1];
  mtmp = extremum->data[0];
  itmp = 1;
  if (extremum->size[1] > 1) {
    if (muDoubleScalarIsNaN(extremum->data[0])) {
      f_st.site = &kb_emlrtRSI;
      overflow = (extremum->size[1] > 2147483646);
      if (overflow) {
        g_st.site = &v_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix <= n)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(extremum->data[ix - 1])) {
          mtmp = extremum->data[ix - 1];
          itmp = ix;
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < extremum->size[1]) {
      f_st.site = &jb_emlrtRSI;
      if (ixstart + 1 > extremum->size[1]) {
        overflow = false;
      } else {
        overflow = (extremum->size[1] > 2147483646);
      }

      if (overflow) {
        g_st.site = &v_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      while (ixstart + 1 <= n) {
        if (extremum->data[ixstart] < mtmp) {
          mtmp = extremum->data[ixstart];
          itmp = ixstart + 1;
        }

        ixstart++;
      }
    }
  }

  emxFree_real_T(&extremum);
  i7 = (int32_T)wayNum;
  i8 = (int32_T)(wayInxEnd - 1.0);
  staVec->data[emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7, &fc_emlrtBCI, sp) -
    1] = itmp;
  i7 = indx->size[1];
  i8 = staVec->size[0];
  i9 = (int32_T)(wayInxEnd - 1.0);
  i8 = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
    &gc_emlrtBCI, sp) - 1];
  emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7, &ec_emlrtBCI, sp);

  /*  assign the last value in the optimatal KE INDEX vector as the last KE idx */
  i7 = (int32_T)wayNum;
  i8 = (int32_T)wayInxEnd;
  engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7,
    &hc_emlrtBCI, sp) - 1] = indx->data[(int32_T)staVec->data[(int32_T)
    (wayInxEnd - 1.0) - 1] - 1];

  /*  Zielzustand des Ausgabevektors für optimale kinetische Energie */
  /*  beschreiben */
  /*    describe the target state of the output vector for the optimal KE */
  i7 = (int32_T)wayNum;
  i8 = (int32_T)wayInxEnd;
  i9 = engKinOptInxVec->size[0];
  i10 = (int32_T)wayInxEnd;
  i9 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i10, 1,
    i9, &kc_emlrtBCI, sp) - 1];
  engKinOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7, &ic_emlrtBCI,
    sp) - 1] = engKinMat_engKinInx_wayInx[(emlrtDynamicBoundsCheckFastR2012b(i9,
    1, 11, &jc_emlrtBCI, sp) + 11 * ((int32_T)wayInxEnd - 1)) - 1];

  /*  Batterieenergieänderung im letzten Intervall initialisieren */
  /*    initialize battery engery change's last interval */
  i7 = (int32_T)wayNum;
  i8 = (int32_T)wayInxEnd - 1;
  i9 = batFrcOptTn3->size[0];
  i10 = engKinOptInxVec->size[0];
  i11 = (int32_T)wayInxEnd;
  i10 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i11, 1,
    i10, &nc_emlrtBCI, sp) - 1];
  i11 = batFrcOptTn3->size[1];
  n = staVec->size[0];
  ix = (int32_T)wayInxEnd - 1;
  n = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(ix, 1, n,
    &pc_emlrtBCI, sp) - 1];
  ix = batFrcOptTn3->size[2];
  iy = (int32_T)wayInxEnd - 1;
  batEngDltOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7,
    &lc_emlrtBCI, sp) - 1] = batFrcOptTn3->data
    [((emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &mc_emlrtBCI, sp) +
       batFrcOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(n, 1, i11,
         &oc_emlrtBCI, sp) - 1)) + batFrcOptTn3->size[0] * batFrcOptTn3->size[1]
      * (emlrtDynamicBoundsCheckFastR2012b(iy, 1, ix, &qc_emlrtBCI, sp) - 1)) -
    1] * wayStp;

  /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
  /*    writing the output for the optimal fuel energy */
  i7 = fulEngOptTn3->size[0];
  i8 = engKinOptInxVec->size[0];
  i9 = (int32_T)wayInxEnd;
  i8 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1,
    i8, &sc_emlrtBCI, sp) - 1];
  i9 = fulEngOptTn3->size[1];
  i10 = staVec->size[0];
  i11 = (int32_T)wayInxEnd - 1;
  i10 = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10,
    &uc_emlrtBCI, sp) - 1];
  i11 = fulEngOptTn3->size[2];
  n = (int32_T)wayInxEnd;
  *fulEngOpt = fulEngOptTn3->data[((emlrtDynamicBoundsCheckFastR2012b(i8, 1, i7,
    &rc_emlrtBCI, sp) + fulEngOptTn3->size[0] *
    (emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9, &tc_emlrtBCI, sp) - 1)) +
    fulEngOptTn3->size[0] * fulEngOptTn3->size[1] *
    (emlrtDynamicBoundsCheckFastR2012b(n, 1, i11, &vc_emlrtBCI, sp) - 1)) - 1];

  /*  Initialisieren des Vektors der optimalen Kraftstoffenergieänderung */
  /*    intializing the optimum fuel energy change vector */
  i7 = fulEngDltOptVec->size[0];
  fulEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngDltOptVec, i7, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  ixstart = (int32_T)wayNum;
  emxFree_real_T(&indx);
  for (i7 = 0; i7 < ixstart; i7++) {
    fulEngDltOptVec->data[i7] = 0.0;
  }

  /*  Costate für die kinetische Energie initialisieren */
  /*    intializing the kinetic energy's costate */
  i7 = psiEngKinOptVec->size[0];
  psiEngKinOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)psiEngKinOptVec, i7, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  ixstart = (int32_T)wayNum;
  for (i7 = 0; i7 < ixstart; i7++) {
    psiEngKinOptVec->data[i7] = 0.0;
  }

  /* % Rückwärtsrechnung über alle Wegpunkte  */
  /*    reverse calculation of all the path indexes */
  /*  Rekonstruieren des optimalen Pfades aus */
  /*    rebuilding the optimale path */
  i7 = (int32_T)-((wayInxBeg + 1.0) + (-1.0 - wayInxEnd));
  emlrtForLoopVectorCheckR2012b(wayInxEnd, -1.0, wayInxBeg + 1.0, mxDOUBLE_CLASS,
    i7, &v_emlrtRTEI, sp);
  wayInx = 0;
  c_emxInit_real_T(sp, &x, 1, &i_emlrtRTEI, true);
  c_emxInit_real_T(sp, &r2, 1, &i_emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_fulEngOptTn3, 1, &i_emlrtRTEI, true);
  while (wayInx <= i7 - 1) {
    b_wayInx = wayInxEnd + -(real_T)wayInx;

    /*  optimalen Vorgängerindex aus Tensor auslesen */
    /*    reading the tensor's optimum previous index  */
    i8 = optPreInxTn3->size[0];
    i9 = engKinOptInxVec->size[0];
    i10 = (int32_T)b_wayInx;
    i9 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i10, 1,
      i9, &wc_emlrtBCI, sp) - 1];
    emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &dc_emlrtBCI, sp);
    i8 = optPreInxTn3->size[1];
    i9 = staVec->size[0];
    i10 = (int32_T)(b_wayInx - 1.0);
    i9 = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9,
      &xc_emlrtBCI, sp) - 1];
    emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &cc_emlrtBCI, sp);
    i8 = optPreInxTn3->size[2];
    i9 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &bc_emlrtBCI, sp);
    if (optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)b_wayInx -
          1] + optPreInxTn3->size[0] * ((int32_T)staVec->data[(int32_T)b_wayInx
           - 2] - 1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] *
                            ((int32_T)b_wayInx - 1)) - 1] == 0.0) {
      /*  <- Vorgänger = predecessor */
      st.site = &ab_emlrtRSI;
      e_y = NULL;
      m4 = emlrtCreateCharArray(2, iv14);
      for (i = 0; i < 47; i++) {
        cv18[i] = cv19[i];
      }

      emlrtInitCharArrayR2013a(&st, 47, m4, cv18);
      emlrtAssign(&e_y, m4);
      b_st.site = &ub_emlrtRSI;
      error(&b_st, e_y, &i_emlrtMCI);
    }

    /*  optimalen Index dekodieren */
    /*    decoding the optimal index */
    if (b_wayInx > wayInxBeg + 1.0) {
      /*  what does this do? - assigns index values, that's for sure */
      /*  - its repopulating the vectors (previously assigned to 0) by */
      /*    looping through all the path states and selecting all the  */
      /*    optimum state variables in each of the mats based on the */
      /*    generated optimum indexes */
      st.site = &bb_emlrtRSI;
      b_st.site = &mb_emlrtRSI;
      if (((int32_T)optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + optPreInxTn3->size[0] * ((int32_T)staVec->data
              [(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->size[0] *
            optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] >= 1) &&
          ((int32_T)optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + optPreInxTn3->size[0] * ((int32_T)staVec->data
              [(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->size[0] *
            optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] <= (int32_T)
           engKinNum * (int32_T)staNum)) {
        overflow = true;
      } else {
        overflow = false;
      }

      c_st.site = &nb_emlrtRSI;
      if (!overflow) {
        b_overflow = false;
      } else {
        b_overflow = true;
      }

      if (b_overflow) {
      } else {
        f_y = NULL;
        m4 = emlrtCreateCharArray(2, iv15);
        for (i = 0; i < 36; i++) {
          cv14[i] = cv20[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 36, m4, cv14);
        emlrtAssign(&f_y, m4);
        d_st.site = &tb_emlrtRSI;
        error(&d_st, b_message(&d_st, f_y, &d_emlrtMCI), &d_emlrtMCI);
      }

      c_st.site = &ec_emlrtRSI;
      n = div_s32(&c_st, (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
                    ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) +
        optPreInxTn3->size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1))
                  - 1] - 1, (int32_T)engKinNum);
      i8 = engKinOptInxVec->size[0];
      i9 = (int32_T)b_wayInx - 1;
      engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &gd_emlrtBCI, sp) - 1] = (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
        ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->
        size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] - n *
        (int32_T)engKinNum;
      i8 = staVec->size[0];
      i9 = (int32_T)b_wayInx - 2;
      staVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &hd_emlrtBCI, sp)
        - 1] = n + 1;

      /*  Batterieenergieänderung für Vorgängerintervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*    storing the previous interval's battery energy change's flow */
      /*    amount */
      i8 = batEngDltOptVec->size[0];
      i9 = (int32_T)b_wayInx - 2;
      i10 = batFrcOptTn3->size[0];
      i11 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx - 1;
      i11 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(n,
        1, i11, &kd_emlrtBCI, sp) - 1];
      n = batFrcOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 2;
      ix = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(iy, 1, ix,
        &md_emlrtBCI, sp) - 1];
      iy = batFrcOptTn3->size[2];
      ixstart = (int32_T)b_wayInx - 2;
      batEngDltOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &id_emlrtBCI, sp) - 1] = batFrcOptTn3->data
        [((emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &jd_emlrtBCI, sp) +
           batFrcOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(ix, 1, n,
             &ld_emlrtBCI, sp) - 1)) + batFrcOptTn3->size[0] *
          batFrcOptTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
            iy, &nd_emlrtBCI, sp) - 1)) - 1] * wayStp;

      /*  Krafstoffenergieänderung für Intervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
      /*    storing the interval's fuel energy change flow amount */
      /*    describing the output size of the optimal fuel energy */
      i8 = fulEngDltOptVec->size[0];
      i9 = (int32_T)b_wayInx - 1;
      i10 = fulEngOptTn3->size[0];
      i11 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx;
      i11 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(n,
        1, i11, &qd_emlrtBCI, sp) - 1];
      n = fulEngOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 1;
      ix = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(iy, 1, ix,
        &sd_emlrtBCI, sp) - 1];
      iy = fulEngOptTn3->size[2];
      ixstart = (int32_T)b_wayInx;
      ixstop = fulEngOptTn3->size[0];
      cindx = engKinOptInxVec->size[0];
      c_ix = (int32_T)b_wayInx - 1;
      cindx = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b
        (c_ix, 1, cindx, &vd_emlrtBCI, sp) - 1];
      c_ix = fulEngOptTn3->size[1];
      i = staVec->size[0];
      itmp = (int32_T)b_wayInx - 2;
      i = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(itmp, 1, i,
        &xd_emlrtBCI, sp) - 1];
      itmp = fulEngOptTn3->size[2];
      i12 = (int32_T)b_wayInx - 1;
      fulEngDltOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &od_emlrtBCI, sp) - 1] = fulEngOptTn3->data
        [((emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &pd_emlrtBCI, sp) +
           fulEngOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(ix, 1, n,
             &rd_emlrtBCI, sp) - 1)) + fulEngOptTn3->size[0] *
          fulEngOptTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
            iy, &td_emlrtBCI, sp) - 1)) - 1] - fulEngOptTn3->data
        [((emlrtDynamicBoundsCheckFastR2012b(cindx, 1, ixstop, &ud_emlrtBCI, sp)
           + fulEngOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(i, 1,
             c_ix, &wd_emlrtBCI, sp) - 1)) + fulEngOptTn3->size[0] *
          fulEngOptTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b(i12, 1,
            itmp, &yd_emlrtBCI, sp) - 1)) - 1];

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
      i8 = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i8, 1, 800, &ac_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx[(int32_T)b_wayInx - 2]) {
        ixstart = 0;
      } else {
        i8 = fulEngOptTn3->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i8, &yb_emlrtBCI, sp);
        i8 = fulEngOptTn3->size[0];
        mtmp = engKinNumVec_wayInx[(int32_T)b_wayInx - 2];
        i9 = (int32_T)emlrtIntegerCheckFastR2012b(mtmp, &cb_emlrtDCI, sp);
        ixstart = emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &yb_emlrtBCI, sp);
      }

      i8 = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i8, 1, 800, &vb_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx[(int32_T)b_wayInx - 2]) {
        ix = 0;
      } else {
        mtmp = engKinNumVec_wayInx[(int32_T)b_wayInx - 2];
        i8 = (int32_T)emlrtIntegerCheckFastR2012b(mtmp, &bb_emlrtDCI, sp);
        ix = emlrtDynamicBoundsCheckFastR2012b(i8, 1, 11, &ub_emlrtBCI, sp);
      }

      i8 = fulEngOptTn3->size[2];
      i9 = (int32_T)b_wayInx - 1;
      iy = emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &wb_emlrtBCI, sp);
      i8 = fulEngOptTn3->size[1];
      i9 = staVec->size[0];
      i10 = (int32_T)b_wayInx - 2;
      i9 = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(i10, 1, i9,
        &ae_emlrtBCI, sp) - 1];
      n = emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &xb_emlrtBCI, sp);
      i8 = b_fulEngOptTn3->size[0];
      b_fulEngOptTn3->size[0] = ixstart;
      emxEnsureCapacity(sp, (emxArray__common *)b_fulEngOptTn3, i8, (int32_T)
                        sizeof(real_T), &i_emlrtRTEI);
      for (i8 = 0; i8 < ixstart; i8++) {
        b_fulEngOptTn3->data[i8] = fulEngOptTn3->data[(i8 + fulEngOptTn3->size[0]
          * (n - 1)) + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * (iy - 1)];
      }

      st.site = &cb_emlrtRSI;
      diff(&st, b_fulEngOptTn3, x);
      i8 = (int32_T)b_wayInx - 1;
      iy = emlrtDynamicBoundsCheckFastR2012b(i8, 1, 800, &tb_emlrtBCI, sp);
      engKinMat_engKinInx_wayInx_size[0] = ix;
      for (i8 = 0; i8 < ix; i8++) {
        engKinMat_engKinInx_wayInx_data[i8] = engKinMat_engKinInx_wayInx[i8 + 11
          * (iy - 1)];
      }

      b_engKinMat_engKinInx_wayInx_da.data = (real_T *)
        &engKinMat_engKinInx_wayInx_data;
      b_engKinMat_engKinInx_wayInx_da.size = (int32_T *)
        &engKinMat_engKinInx_wayInx_size;
      b_engKinMat_engKinInx_wayInx_da.allocatedSize = 11;
      b_engKinMat_engKinInx_wayInx_da.numDimensions = 1;
      b_engKinMat_engKinInx_wayInx_da.canFreeData = false;
      st.site = &db_emlrtRSI;
      diff(&st, &b_engKinMat_engKinInx_wayInx_da, r2);
      n = r2->size[0];
      ixstart = r2->size[0];
      for (i8 = 0; i8 < ixstart; i8++) {
        y_data[i8] = r2->data[i8];
      }

      st.site = &cb_emlrtRSI;
      outsz[0] = x->size[0];
      outsz[1] = 1;
      varargin_2[0] = (int8_T)n;
      varargin_2[1] = 1;
      overflow = false;
      p = true;
      n = 0;
      exitg1 = false;
      while ((!exitg1) && (n < 2)) {
        if (!(outsz[n] == varargin_2[n])) {
          p = false;
          exitg1 = true;
        } else {
          n++;
        }
      }

      if (!p) {
      } else {
        overflow = true;
      }

      if (overflow) {
      } else {
        g_y = NULL;
        m4 = emlrtCreateCharArray(2, iv16);
        for (i = 0; i < 15; i++) {
          cv21[i] = cv22[i];
        }

        emlrtInitCharArrayR2013a(&st, 15, m4, cv21);
        emlrtAssign(&g_y, m4);
        b_st.site = &sb_emlrtRSI;
        h_st.site = &bc_emlrtRSI;
        error(&b_st, b_message(&h_st, g_y, &l_emlrtMCI), &m_emlrtMCI);
      }

      /*  <-fast immer 5000; */
      n = 1 + x->size[0];
      psiEngKinVec_data[0] = 0.0;
      ixstart = x->size[0];
      for (i8 = 0; i8 < ixstart; i8++) {
        psiEngKinVec_data[i8 + 1] = x->data[i8] / y_data[i8];
      }

      /*  what is the point of adding 0 */
      i8 = psiEngKinOptVec->size[0];
      i9 = (int32_T)b_wayInx - 1;
      i10 = engKinOptInxVec->size[0];
      i11 = (int32_T)b_wayInx - 1;
      i10 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i11,
        1, i10, &de_emlrtBCI, sp) - 1];
      psiEngKinOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &be_emlrtBCI, sp) - 1] =
        psiEngKinVec_data[emlrtDynamicBoundsCheckFastR2012b(i10, 1, n,
        &ce_emlrtBCI, sp) - 1];

      /*  Potentialgrößen im ersten Punkt speichern */
      /*    save potetial variables in the first point/index */
    } else {
      /*  if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1) */
      st.site = &eb_emlrtRSI;
      b_st.site = &mb_emlrtRSI;
      if (((int32_T)optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + optPreInxTn3->size[0] * ((int32_T)staVec->data
              [(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->size[0] *
            optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] >= 1) &&
          ((int32_T)optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)
             b_wayInx - 1] + optPreInxTn3->size[0] * ((int32_T)staVec->data
              [(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->size[0] *
            optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] <= (int32_T)
           engKinNum * (int32_T)staNum)) {
        overflow = true;
      } else {
        overflow = false;
      }

      c_st.site = &nb_emlrtRSI;
      if (!overflow) {
        c_overflow = false;
      } else {
        c_overflow = true;
      }

      if (c_overflow) {
      } else {
        h_y = NULL;
        m4 = emlrtCreateCharArray(2, iv17);
        for (i = 0; i < 36; i++) {
          cv14[i] = cv20[i];
        }

        emlrtInitCharArrayR2013a(&c_st, 36, m4, cv14);
        emlrtAssign(&h_y, m4);
        d_st.site = &tb_emlrtRSI;
        error(&d_st, b_message(&d_st, h_y, &d_emlrtMCI), &d_emlrtMCI);
      }

      i8 = engKinOptInxVec->size[0];
      i9 = (int32_T)b_wayInx - 1;
      st.site = &ec_emlrtRSI;
      engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &yc_emlrtBCI, sp) - 1] = (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
        ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->
        size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] -
        div_s32(&st, (int32_T)optPreInxTn3->data[(((int32_T)
                  engKinOptInxVec->data[(int32_T)b_wayInx - 1] +
                  optPreInxTn3->size[0] * ((int32_T)staVec->data[(int32_T)
        b_wayInx - 2] - 1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] *
                 ((int32_T)b_wayInx - 1)) - 1] - 1, (int32_T)engKinNum) *
        (int32_T)engKinNum;
      i8 = fulEngDltOptVec->size[0];
      i9 = (int32_T)b_wayInx - 1;
      i10 = fulEngOptTn3->size[0];
      i11 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx;
      i11 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(n,
        1, i11, &cd_emlrtBCI, sp) - 1];
      n = fulEngOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 1;
      ix = (int32_T)staVec->data[emlrtDynamicBoundsCheckFastR2012b(iy, 1, ix,
        &ed_emlrtBCI, sp) - 1];
      iy = fulEngOptTn3->size[2];
      ixstart = (int32_T)b_wayInx;
      fulEngDltOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8,
        &ad_emlrtBCI, sp) - 1] = fulEngOptTn3->data
        [((emlrtDynamicBoundsCheckFastR2012b(i11, 1, i10, &bd_emlrtBCI, sp) +
           fulEngOptTn3->size[0] * (emlrtDynamicBoundsCheckFastR2012b(ix, 1, n,
             &dd_emlrtBCI, sp) - 1)) + fulEngOptTn3->size[0] *
          fulEngOptTn3->size[1] * (emlrtDynamicBoundsCheckFastR2012b(ixstart, 1,
            iy, &fd_emlrtBCI, sp) - 1)) - 1];
    }

    /*  optimale kinetische Energie im Vorgängerpunkt */
    /*    optimal KE from previous point / path_idx */
    i8 = engKinOptVec->size[0];
    i9 = (int32_T)b_wayInx - 1;
    i10 = engKinOptInxVec->size[0];
    i11 = (int32_T)b_wayInx - 1;
    i10 = (int32_T)engKinOptInxVec->data[emlrtDynamicBoundsCheckFastR2012b(i11,
      1, i10, &ge_emlrtBCI, sp) - 1];
    i11 = (int32_T)b_wayInx - 1;
    engKinOptVec->data[emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &ee_emlrtBCI,
      sp) - 1] = engKinMat_engKinInx_wayInx[(emlrtDynamicBoundsCheckFastR2012b
      (i10, 1, 11, &fe_emlrtBCI, sp) + 11 * (emlrtDynamicBoundsCheckFastR2012b
      (i11, 1, 800, &he_emlrtBCI, sp) - 1)) - 1];
    wayInx++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&b_fulEngOptTn3);
  emxFree_real_T(&r2);
  emxFree_real_T(&x);
  emxFree_real_T(&engKinOptInxVec);

  /*  end of path_idx loop */
  /*  end of function */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (clcOptTrj_port.c) */
