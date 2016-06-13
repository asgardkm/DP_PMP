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
#include "clcDP_tmp.h"
#include "clcOptTrj_tmp.h"
#include "clcDP_tmp_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "diff.h"
#include "clcDP_tmp_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 86, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo x_emlrtRSI = { 87, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo y_emlrtRSI = { 131, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo ab_emlrtRSI = { 143, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo bb_emlrtRSI = { 175, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo cb_emlrtRSI = { 176, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo db_emlrtRSI = { 183, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRSInfo eb_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo fb_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo gb_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo hb_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ib_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo jb_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo kb_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo lb_emlrtRSI = { 19, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtMCInfo b_emlrtMCI = { 20, 5, "error",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 10, 5, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRTEInfo j_emlrtRTEI = { 73, 1, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtRTEInfo v_emlrtRTEI = { 13, 15, "rdivide",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 38, 23, "ind2sub",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 81, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 38, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtBCInfo tb_emlrtBCI = { 1, 800, 176, 80, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { 1, 11, 176, 48, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 176, 48, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo vb_emlrtBCI = { 1, 800, 176, 50, "engKinNumVec_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 175, 90, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 175, 73, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 175, 41, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 175, 41, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { 1, 800, 175, 43, "engKinNumVec_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 128, 28, "optPreInxTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 128, 9, "optPreInxTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 127, 27, "optPreInxTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtRTEInfo ab_emlrtRTEI = { 123, 1, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m" };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 88, 20, "inx", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 87, 8, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 57, 23, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 1 };

static emlrtDCInfo db_emlrtDCI = { 57, 23, "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 4 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 88, 24, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 91, 1, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 96, 14, "engKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { 1, 11, 97, 32, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 97, 48, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 101, 17, "batEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 102, 18, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 102, 18, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 102, 45, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 102, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 102, 65, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 108, 18, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 108, 18, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 108, 45, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 108, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 108, 65, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 127, 43, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 128, 16, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 183, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 186, 25, "fulEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 187, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 187, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 187, 50, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 187, 50, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 187, 67, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 143, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 143, 45, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 150, 25, "batEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 151, 26, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 151, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 152, 13, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 152, 13, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 152, 30, "batFrcOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 159, 25, "fulEngDltOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 160, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 160, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 160, 50, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 160, 50, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 160, 67, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 161, 26, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 161, 26, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 161, 52, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 161, 52, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 161, 69, "fulEngOptTn3",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 175, 73, "staVec", "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 178, 9, "psiEngKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 178, 37, "psiEngKinVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 178, 66, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 192, 18, "engKinOptVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { 1, 11, 193, 36, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 193, 52, "engKinOptInxVec",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtBCInfo he_emlrtBCI = { 1, 800, 193, 64, "engKinMat_engKinInx_wayInx",
  "clcOptTrj_tmp",
  "C:\\Users\\s0032360\\Documents\\4Kaleb\\RCP\\PMPDP\\clcOptTrj_tmp.m", 0 };

static emlrtRSInfo pb_emlrtRSI = { 18, "indexDivide",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\indexDivide.m"
};

static emlrtRSInfo qb_emlrtRSI = { 20, "error",
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

void clcOptTrj_tmp(const emlrtStack *sp, real_T wayStp, real_T wayNum, real_T
                   wayInxBeg, real_T wayInxEnd, real_T engKinNum, real_T staNum,
                   const real_T engKinNumVec_wayInx[800], const real_T
                   engKinMat_engKinInx_wayInx[8800], const emxArray_real_T
                   *optPreInxTn3, const emxArray_real_T *batFrcOptTn3, const
                   emxArray_real_T *fulEngOptTn3, const emxArray_real_T
                   *cos2goActMat, emxArray_real_T *engKinOptVec, emxArray_real_T
                   *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
                   emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
                   real_T *fulEngOpt)
{
  int32_T i17;
  real_T mtmp;
  int32_T loop_ub;
  emxArray_real_T *engKinOptInxVec;
  boolean_T overflow;
  int32_T outsz[2];
  emxArray_real_T *extremum;
  emxArray_int32_T *iindx;
  int32_T n;
  int32_T ix;
  int32_T iy;
  int32_T ixstart;
  int32_T ixstop;
  int32_T itmp;
  int32_T cindx;
  boolean_T b_ix;
  int32_T c_ix;
  boolean_T exitg3;
  boolean_T b_ixstart;
  emxArray_real_T *indx;
  boolean_T exitg2;
  int32_T i18;
  int32_T i19;
  int32_T i20;
  int32_T i21;
  int32_T i22;
  int32_T i23;
  int32_T i24;
  int32_T i25;
  int32_T i26;
  int32_T i27;
  int32_T i28;
  int32_T d_ix;
  int32_T i29;
  int32_T i30;
  int32_T b_n;
  int32_T b_iy;
  int32_T i31;
  int32_T i32;
  int32_T i33;
  int32_T i34;
  int32_T c_n;
  int32_T wayInx;
  emxArray_real_T *x;
  emxArray_real_T *r2;
  emxArray_real_T *b_fulEngOptTn3;
  real_T b_wayInx;
  int32_T i35;
  int32_T i36;
  static const char_T varargin_1[47] = { 'F', 'e', 'h', 'l', 'e', 'r', ' ', 'b',
    'e', 'i', 'm', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n', ' ', 'd',
    'e', 'r', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l', 'e', 'n', ' ', 'V', 'o',
    'r', 'g', 'a', 'e', 'n', 'g', 'e', 'r', '.' };

  char_T u[47];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 47 };

  const mxArray *m2;
  int32_T i37;
  int32_T i38;
  int32_T d_n;
  int32_T c_iy;
  int32_T i39;
  int32_T i40;
  int32_T e_ix;
  int32_T c_ixstart;
  int32_T e_n;
  int32_T d_iy;
  int32_T f_ix;
  int32_T b_itmp;
  int32_T i41;
  int32_T i42;
  int32_T i43;
  int32_T g_ix;
  int32_T d_ixstart;
  int32_T b_cindx;
  int32_T b_loop_ub;
  int32_T i44;
  int32_T i45;
  real_T engKinMat_engKinInx_wayInx_data[11];
  int32_T engKinMat_engKinInx_wayInx_size[1];
  emxArray_real_T b_engKinMat_engKinInx_wayInx_da;
  real_T y_data[10];
  int8_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  real_T psiEngKinVec_data[11];
  int32_T i46;
  int32_T i47;
  int32_T i48;
  int32_T i49;
  int32_T f_n;
  int32_T e_iy;
  int32_T i50;
  int32_T i51;
  int32_T h_ix;
  int32_T e_ixstart;
  int32_T i52;
  int32_T i53;
  int32_T i54;
  int32_T i55;
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
  i17 = engKinOptVec->size[0];
  if (wayNum >= 0.0) {
    mtmp = wayNum;
  } else {
    mtmp = emlrtNonNegativeCheckR2012b(wayNum, &db_emlrtDCI, sp);
  }

  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    engKinOptVec->size[0] = (int32_T)mtmp;
  } else {
    engKinOptVec->size[0] = (int32_T)emlrtIntegerCheckR2012b(mtmp, &cb_emlrtDCI,
      sp);
  }

  emxEnsureCapacity(sp, (emxArray__common *)engKinOptVec, i17, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  if (wayNum >= 0.0) {
    mtmp = wayNum;
  } else {
    mtmp = emlrtNonNegativeCheckR2012b(wayNum, &db_emlrtDCI, sp);
  }

  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    loop_ub = (int32_T)mtmp;
  } else {
    loop_ub = (int32_T)emlrtIntegerCheckR2012b(mtmp, &cb_emlrtDCI, sp);
  }

  for (i17 = 0; i17 < loop_ub; i17++) {
    engKinOptVec->data[i17] = rtInf;
  }

  /*  Trajektorie der optimalen Batterieenergieänderung im Intervall */
  /*    optimal battery energy change trajectories for the interval */
  i17 = batEngDltOptVec->size[0];
  batEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)batEngDltOptVec, i17, (int32_T)
                    sizeof(real_T), &i_emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i17 = 0; i17 < loop_ub; i17++) {
    batEngDltOptVec->data[i17] = rtInf;
  }

  /*  Trajektorie des optimalen Antriebsstrangzustands im Intervall */
  /*    optimal powertrain state trajectories for the interval */
  i17 = staVec->size[0];
  staVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)staVec, i17, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i17 = 0; i17 < loop_ub; i17++) {
    staVec->data[i17] = 0.0;
  }

  c_emxInit_real_T(sp, &engKinOptInxVec, 1, &j_emlrtRTEI, true);

  /* % Initialisieren des finalen Zustands */
  /*    intializing the final state */
  /*  Indexvektor der optimalen kinetischen Energien */
  /*    index vector for the optimal kinetic energies */
  i17 = engKinOptInxVec->size[0];
  engKinOptInxVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)engKinOptInxVec, i17, (int32_T)
                    sizeof(real_T), &i_emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i17 = 0; i17 < loop_ub; i17++) {
    engKinOptInxVec->data[i17] = 0.0;
  }

  /*  Suche des optimalen Gangs und der optimalen Geschwindigkeit, falls  */
  /*  Zielgang nicht festgelegt ist */
  /*    find the optimal gear and speed if the target gear isn't fixed */
  st.site = &w_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  if (((cos2goActMat->size[0] == 1) && (cos2goActMat->size[1] == 1)) ||
      (cos2goActMat->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (cos2goActMat->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &x_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (i17 = 0; i17 < 2; i17++) {
    outsz[i17] = cos2goActMat->size[i17];
  }

  b_emxInit_real_T(&c_st, &extremum, 2, &i_emlrtRTEI, true);
  b_emxInit_int32_T(&c_st, &iindx, 2, &i_emlrtRTEI, true);
  i17 = extremum->size[0] * extremum->size[1];
  extremum->size[0] = 1;
  extremum->size[1] = outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)extremum, i17, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  n = outsz[1];
  i17 = iindx->size[0] * iindx->size[1];
  iindx->size[0] = 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i17, (int32_T)sizeof
                    (int32_T), &i_emlrtRTEI);
  i17 = iindx->size[0] * iindx->size[1];
  iindx->size[1] = outsz[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)iindx, i17, (int32_T)sizeof
                    (int32_T), &i_emlrtRTEI);
  for (i17 = 0; i17 < n; i17++) {
    iindx->data[i17] = 1;
  }

  n = cos2goActMat->size[0];
  ix = 0;
  iy = -1;
  d_st.site = &gb_emlrtRSI;
  if (1 > cos2goActMat->size[1]) {
    overflow = false;
  } else {
    overflow = (cos2goActMat->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (loop_ub = 1; loop_ub <= cos2goActMat->size[1]; loop_ub++) {
    d_st.site = &hb_emlrtRSI;
    ixstart = ix;
    ixstop = ix + n;
    mtmp = cos2goActMat->data[ix];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(cos2goActMat->data[ix])) {
        e_st.site = &jb_emlrtRSI;
        if (ix + 2 > ixstop) {
          b_ix = false;
        } else {
          b_ix = (ixstop > 2147483646);
        }

        if (b_ix) {
          f_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&f_st);
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
        e_st.site = &ib_emlrtRSI;
        if (ixstart + 2 > ixstop) {
          b_ixstart = false;
        } else {
          b_ixstart = (ixstop > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &u_emlrtRSI;
          check_forloop_overflow_error(&f_st);
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
  i17 = indx->size[0] * indx->size[1];
  indx->size[0] = 1;
  indx->size[1] = iindx->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)indx, i17, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  loop_ub = iindx->size[0] * iindx->size[1];
  for (i17 = 0; i17 < loop_ub; i17++) {
    indx->data[i17] = iindx->data[i17];
  }

  emxFree_int32_T(&iindx);
  st.site = &x_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  if ((extremum->size[1] == 1) || (extremum->size[1] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (extremum->size[1] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &x_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  d_st.site = &kb_emlrtRSI;
  ixstart = 1;
  n = extremum->size[1];
  mtmp = extremum->data[0];
  itmp = 1;
  if (extremum->size[1] > 1) {
    if (muDoubleScalarIsNaN(extremum->data[0])) {
      e_st.site = &jb_emlrtRSI;
      overflow = (extremum->size[1] > 2147483646);
      if (overflow) {
        f_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&f_st);
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
      e_st.site = &ib_emlrtRSI;
      if (ixstart + 1 > extremum->size[1]) {
        overflow = false;
      } else {
        overflow = (extremum->size[1] > 2147483646);
      }

      if (overflow) {
        f_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&f_st);
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
  i17 = (int32_T)wayNum;
  i18 = (int32_T)(wayInxEnd - 1.0);
  if ((i18 >= 1) && (i18 < i17)) {
    i19 = i18;
  } else {
    i19 = emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &fc_emlrtBCI, sp);
  }

  staVec->data[i19 - 1] = itmp;
  i17 = indx->size[1];
  i18 = staVec->size[0];
  i20 = (int32_T)(wayInxEnd - 1.0);
  if ((i20 >= 1) && (i20 < i18)) {
    i21 = i20;
  } else {
    i21 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &gc_emlrtBCI, sp);
  }

  i18 = (int32_T)staVec->data[i21 - 1];
  emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &ec_emlrtBCI, sp);

  /*  assign the last value in the optimatal KE INDEX vector as the last KE idx */
  i17 = (int32_T)wayNum;
  i18 = (int32_T)wayInxEnd;
  if ((i18 >= 1) && (i18 < i17)) {
    i22 = i18;
  } else {
    i22 = emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &hc_emlrtBCI, sp);
  }

  engKinOptInxVec->data[i22 - 1] = indx->data[(int32_T)staVec->data[(int32_T)
    (wayInxEnd - 1.0) - 1] - 1];

  /*  Zielzustand des Ausgabevektors für optimale kinetische Energie */
  /*  beschreiben */
  /*    describe the target state of the output vector for the optimal KE */
  i17 = (int32_T)wayNum;
  i18 = (int32_T)wayInxEnd;
  i20 = engKinOptInxVec->size[0];
  i23 = (int32_T)wayInxEnd;
  if ((i23 >= 1) && (i23 < i20)) {
    i24 = i23;
  } else {
    i24 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &kc_emlrtBCI, sp);
  }

  i20 = (int32_T)engKinOptInxVec->data[i24 - 1];
  if ((i18 >= 1) && (i18 < i17)) {
    i25 = i18;
  } else {
    i25 = emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &ic_emlrtBCI, sp);
  }

  if ((i20 >= 1) && (i20 < 11)) {
    i26 = i20;
  } else {
    i26 = emlrtDynamicBoundsCheckR2012b(i20, 1, 11, &jc_emlrtBCI, sp);
  }

  engKinOptVec->data[i25 - 1] = engKinMat_engKinInx_wayInx[(i26 + 11 * ((int32_T)
    wayInxEnd - 1)) - 1];

  /*  Batterieenergieänderung im letzten Intervall initialisieren */
  /*    initialize battery engery change's last interval */
  i17 = (int32_T)wayNum;
  i18 = (int32_T)wayInxEnd - 1;
  i20 = batFrcOptTn3->size[0];
  i23 = engKinOptInxVec->size[0];
  i27 = (int32_T)wayInxEnd;
  if ((i27 >= 1) && (i27 < i23)) {
    i28 = i27;
  } else {
    i28 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &nc_emlrtBCI, sp);
  }

  i23 = (int32_T)engKinOptInxVec->data[i28 - 1];
  i27 = batFrcOptTn3->size[1];
  n = staVec->size[0];
  ix = (int32_T)wayInxEnd - 1;
  if ((ix >= 1) && (ix < n)) {
    d_ix = ix;
  } else {
    d_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, n, &pc_emlrtBCI, sp);
  }

  n = (int32_T)staVec->data[d_ix - 1];
  ix = batFrcOptTn3->size[2];
  iy = (int32_T)wayInxEnd - 1;
  if ((i18 >= 1) && (i18 < i17)) {
    i29 = i18;
  } else {
    i29 = emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &lc_emlrtBCI, sp);
  }

  if ((i23 >= 1) && (i23 < i20)) {
    i30 = i23;
  } else {
    i30 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &mc_emlrtBCI, sp);
  }

  if ((n >= 1) && (n < i27)) {
    b_n = n;
  } else {
    b_n = emlrtDynamicBoundsCheckR2012b(n, 1, i27, &oc_emlrtBCI, sp);
  }

  if ((iy >= 1) && (iy < ix)) {
    b_iy = iy;
  } else {
    b_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &qc_emlrtBCI, sp);
  }

  batEngDltOptVec->data[i29 - 1] = batFrcOptTn3->data[((i30 + batFrcOptTn3->
    size[0] * (b_n - 1)) + batFrcOptTn3->size[0] * batFrcOptTn3->size[1] * (b_iy
    - 1)) - 1] * wayStp;

  /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
  /*    writing the output for the optimal fuel energy */
  i17 = fulEngOptTn3->size[0];
  i18 = engKinOptInxVec->size[0];
  i20 = (int32_T)wayInxEnd;
  if ((i20 >= 1) && (i20 < i18)) {
    i31 = i20;
  } else {
    i31 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &sc_emlrtBCI, sp);
  }

  i18 = (int32_T)engKinOptInxVec->data[i31 - 1];
  i20 = fulEngOptTn3->size[1];
  i23 = staVec->size[0];
  i27 = (int32_T)wayInxEnd - 1;
  if ((i27 >= 1) && (i27 < i23)) {
    i32 = i27;
  } else {
    i32 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &uc_emlrtBCI, sp);
  }

  i23 = (int32_T)staVec->data[i32 - 1];
  i27 = fulEngOptTn3->size[2];
  n = (int32_T)wayInxEnd;
  if ((i18 >= 1) && (i18 < i17)) {
    i33 = i18;
  } else {
    i33 = emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &rc_emlrtBCI, sp);
  }

  if ((i23 >= 1) && (i23 < i20)) {
    i34 = i23;
  } else {
    i34 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &tc_emlrtBCI, sp);
  }

  if ((n >= 1) && (n < i27)) {
    c_n = n;
  } else {
    c_n = emlrtDynamicBoundsCheckR2012b(n, 1, i27, &vc_emlrtBCI, sp);
  }

  *fulEngOpt = fulEngOptTn3->data[((i33 + fulEngOptTn3->size[0] * (i34 - 1)) +
    fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * (c_n - 1)) - 1];

  /*  Initialisieren des Vektors der optimalen Kraftstoffenergieänderung */
  /*    intializing the optimum fuel energy change vector */
  i17 = fulEngDltOptVec->size[0];
  fulEngDltOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)fulEngDltOptVec, i17, (int32_T)
                    sizeof(real_T), &i_emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  emxFree_real_T(&indx);
  for (i17 = 0; i17 < loop_ub; i17++) {
    fulEngDltOptVec->data[i17] = 0.0;
  }

  /*  Costate für die kinetische Energie initialisieren */
  /*    intializing the kinetic energy's costate */
  i17 = psiEngKinOptVec->size[0];
  psiEngKinOptVec->size[0] = (int32_T)wayNum;
  emxEnsureCapacity(sp, (emxArray__common *)psiEngKinOptVec, i17, (int32_T)
                    sizeof(real_T), &i_emlrtRTEI);
  loop_ub = (int32_T)wayNum;
  for (i17 = 0; i17 < loop_ub; i17++) {
    psiEngKinOptVec->data[i17] = 0.0;
  }

  /* % Rückwärtsrechnung über alle Wegpunkte  */
  /*    reverse calculation of all the path indexes */
  /*  Rekonstruieren des optimalen Pfades aus */
  /*    rebuilding the optimale path */
  i17 = (int32_T)-((wayInxBeg + 1.0) + (-1.0 - wayInxEnd));
  emlrtForLoopVectorCheckR2012b(wayInxEnd, -1.0, wayInxBeg + 1.0, mxDOUBLE_CLASS,
    i17, &ab_emlrtRTEI, sp);
  wayInx = 0;
  c_emxInit_real_T(sp, &x, 1, &i_emlrtRTEI, true);
  c_emxInit_real_T(sp, &r2, 1, &i_emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_fulEngOptTn3, 1, &i_emlrtRTEI, true);
  while (wayInx <= i17 - 1) {
    b_wayInx = wayInxEnd + -(real_T)wayInx;

    /*  optimalen Vorgängerindex aus Tensor auslesen */
    /*    reading the tensor's optimum previous index  */
    i18 = optPreInxTn3->size[0];
    i20 = engKinOptInxVec->size[0];
    i23 = (int32_T)b_wayInx;
    if ((i23 >= 1) && (i23 < i20)) {
      i35 = i23;
    } else {
      i35 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &wc_emlrtBCI, sp);
    }

    i20 = (int32_T)engKinOptInxVec->data[i35 - 1];
    emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &dc_emlrtBCI, sp);
    i18 = optPreInxTn3->size[1];
    i20 = staVec->size[0];
    i23 = (int32_T)(b_wayInx - 1.0);
    if ((i23 >= 1) && (i23 < i20)) {
      i36 = i23;
    } else {
      i36 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &xc_emlrtBCI, sp);
    }

    i20 = (int32_T)staVec->data[i36 - 1];
    emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &cc_emlrtBCI, sp);
    i18 = optPreInxTn3->size[2];
    i20 = (int32_T)b_wayInx;
    emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &bc_emlrtBCI, sp);
    if (optPreInxTn3->data[(((int32_T)engKinOptInxVec->data[(int32_T)b_wayInx -
          1] + optPreInxTn3->size[0] * ((int32_T)staVec->data[(int32_T)b_wayInx
           - 2] - 1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] *
                            ((int32_T)b_wayInx - 1)) - 1] == 0.0) {
      /*  <- Vorgänger = predecessor */
      st.site = &y_emlrtRSI;
      for (i18 = 0; i18 < 47; i18++) {
        u[i18] = varargin_1[i18];
      }

      y = NULL;
      m2 = emlrtCreateCharArray(2, iv6);
      emlrtInitCharArrayR2013a(&st, 47, m2, &u[0]);
      emlrtAssign(&y, m2);
      b_st.site = &qb_emlrtRSI;
      error(&b_st, y, &b_emlrtMCI);
    }

    /*  optimalen Index dekodieren */
    /*    decoding the optimal index */
    if (b_wayInx > wayInxBeg + 1.0) {
      /*  what does this do? - assigns index values, that's for sure */
      /*  - its repopulating the vectors (previously assigned to 0) by */
      /*    looping through all the path states and selecting all the  */
      /*    optimum state variables in each of the mats based on the */
      /*    generated optimum indexes */
      st.site = &ab_emlrtRSI;
      b_st.site = &lb_emlrtRSI;
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

      if (!!overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI,
          "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      }

      c_st.site = &pb_emlrtRSI;
      n = div_s32(&c_st, (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
        ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->
        size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] - 1,
                  (int32_T)engKinNum);
      i18 = engKinOptInxVec->size[0];
      i20 = (int32_T)b_wayInx - 1;
      if ((i20 >= 1) && (i20 < i18)) {
        i37 = i20;
      } else {
        i37 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &gd_emlrtBCI, sp);
      }

      engKinOptInxVec->data[i37 - 1] = (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
        ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->
        size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] - n *
        (int32_T)engKinNum;
      i18 = staVec->size[0];
      i20 = (int32_T)b_wayInx - 2;
      if ((i20 >= 1) && (i20 < i18)) {
        i38 = i20;
      } else {
        i38 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &hd_emlrtBCI, sp);
      }

      staVec->data[i38 - 1] = n + 1;

      /*  Batterieenergieänderung für Vorgängerintervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*    storing the previous interval's battery energy change's flow */
      /*    amount */
      i18 = batEngDltOptVec->size[0];
      i20 = (int32_T)b_wayInx - 2;
      i23 = batFrcOptTn3->size[0];
      i27 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx - 1;
      if ((n >= 1) && (n < i27)) {
        d_n = n;
      } else {
        d_n = emlrtDynamicBoundsCheckR2012b(n, 1, i27, &kd_emlrtBCI, sp);
      }

      i27 = (int32_T)engKinOptInxVec->data[d_n - 1];
      n = batFrcOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 2;
      if ((iy >= 1) && (iy < ix)) {
        c_iy = iy;
      } else {
        c_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &md_emlrtBCI, sp);
      }

      ix = (int32_T)staVec->data[c_iy - 1];
      iy = batFrcOptTn3->size[2];
      ixstart = (int32_T)b_wayInx - 2;
      if ((i20 >= 1) && (i20 < i18)) {
        i39 = i20;
      } else {
        i39 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &id_emlrtBCI, sp);
      }

      if ((i27 >= 1) && (i27 < i23)) {
        i40 = i27;
      } else {
        i40 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &jd_emlrtBCI, sp);
      }

      if ((ix >= 1) && (ix < n)) {
        e_ix = ix;
      } else {
        e_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, n, &ld_emlrtBCI, sp);
      }

      if ((ixstart >= 1) && (ixstart < iy)) {
        c_ixstart = ixstart;
      } else {
        c_ixstart = emlrtDynamicBoundsCheckR2012b(ixstart, 1, iy, &nd_emlrtBCI,
          sp);
      }

      batEngDltOptVec->data[i39 - 1] = batFrcOptTn3->data[((i40 +
        batFrcOptTn3->size[0] * (e_ix - 1)) + batFrcOptTn3->size[0] *
        batFrcOptTn3->size[1] * (c_ixstart - 1)) - 1] * wayStp;

      /*  Krafstoffenergieänderung für Intervall speichern */
      /*  Flussgröße (gilt im Intervall) */
      /*  Beschreiben der Ausgabegröße der optimalen Kraftstoffenergie */
      /*    storing the interval's fuel energy change flow amount */
      /*    describing the output size of the optimal fuel energy */
      i18 = fulEngDltOptVec->size[0];
      i20 = (int32_T)b_wayInx - 1;
      i23 = fulEngOptTn3->size[0];
      i27 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx;
      if ((n >= 1) && (n < i27)) {
        e_n = n;
      } else {
        e_n = emlrtDynamicBoundsCheckR2012b(n, 1, i27, &qd_emlrtBCI, sp);
      }

      i27 = (int32_T)engKinOptInxVec->data[e_n - 1];
      n = fulEngOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 1;
      if ((iy >= 1) && (iy < ix)) {
        d_iy = iy;
      } else {
        d_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &sd_emlrtBCI, sp);
      }

      ix = (int32_T)staVec->data[d_iy - 1];
      iy = fulEngOptTn3->size[2];
      ixstart = (int32_T)b_wayInx;
      ixstop = fulEngOptTn3->size[0];
      cindx = engKinOptInxVec->size[0];
      c_ix = (int32_T)b_wayInx - 1;
      if ((c_ix >= 1) && (c_ix < cindx)) {
        f_ix = c_ix;
      } else {
        f_ix = emlrtDynamicBoundsCheckR2012b(c_ix, 1, cindx, &vd_emlrtBCI, sp);
      }

      cindx = (int32_T)engKinOptInxVec->data[f_ix - 1];
      c_ix = fulEngOptTn3->size[1];
      loop_ub = staVec->size[0];
      itmp = (int32_T)b_wayInx - 2;
      if ((itmp >= 1) && (itmp < loop_ub)) {
        b_itmp = itmp;
      } else {
        b_itmp = emlrtDynamicBoundsCheckR2012b(itmp, 1, loop_ub, &xd_emlrtBCI,
          sp);
      }

      loop_ub = (int32_T)staVec->data[b_itmp - 1];
      itmp = fulEngOptTn3->size[2];
      i41 = (int32_T)b_wayInx - 1;
      if ((i20 >= 1) && (i20 < i18)) {
        i42 = i20;
      } else {
        i42 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &od_emlrtBCI, sp);
      }

      if ((i27 >= 1) && (i27 < i23)) {
        i43 = i27;
      } else {
        i43 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &pd_emlrtBCI, sp);
      }

      if ((ix >= 1) && (ix < n)) {
        g_ix = ix;
      } else {
        g_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, n, &rd_emlrtBCI, sp);
      }

      if ((ixstart >= 1) && (ixstart < iy)) {
        d_ixstart = ixstart;
      } else {
        d_ixstart = emlrtDynamicBoundsCheckR2012b(ixstart, 1, iy, &td_emlrtBCI,
          sp);
      }

      if ((cindx >= 1) && (cindx < ixstop)) {
        b_cindx = cindx;
      } else {
        b_cindx = emlrtDynamicBoundsCheckR2012b(cindx, 1, ixstop, &ud_emlrtBCI,
          sp);
      }

      if ((loop_ub >= 1) && (loop_ub < c_ix)) {
        b_loop_ub = loop_ub;
      } else {
        b_loop_ub = emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_ix, &wd_emlrtBCI,
          sp);
      }

      if ((i41 >= 1) && (i41 < itmp)) {
        i44 = i41;
      } else {
        i44 = emlrtDynamicBoundsCheckR2012b(i41, 1, itmp, &yd_emlrtBCI, sp);
      }

      fulEngDltOptVec->data[i42 - 1] = fulEngOptTn3->data[((i43 +
        fulEngOptTn3->size[0] * (g_ix - 1)) + fulEngOptTn3->size[0] *
        fulEngOptTn3->size[1] * (d_ixstart - 1)) - 1] - fulEngOptTn3->data
        [((b_cindx + fulEngOptTn3->size[0] * (b_loop_ub - 1)) +
          fulEngOptTn3->size[0] * fulEngOptTn3->size[1] * (i44 - 1)) - 1];

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
      i18 = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckR2012b(i18, 1, 800, &ac_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx[(int32_T)b_wayInx - 2]) {
        loop_ub = 0;
      } else {
        i18 = fulEngOptTn3->size[0];
        emlrtDynamicBoundsCheckR2012b(1, 1, i18, &yb_emlrtBCI, sp);
        i18 = fulEngOptTn3->size[0];
        mtmp = engKinNumVec_wayInx[(int32_T)b_wayInx - 2];
        if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
          i20 = (int32_T)mtmp;
        } else {
          i20 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &bb_emlrtDCI, sp);
        }

        if ((i20 >= 1) && (i20 < i18)) {
          loop_ub = i20;
        } else {
          loop_ub = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &yb_emlrtBCI, sp);
        }
      }

      i18 = (int32_T)(b_wayInx - 1.0);
      emlrtDynamicBoundsCheckR2012b(i18, 1, 800, &vb_emlrtBCI, sp);
      if (1.0 > engKinNumVec_wayInx[(int32_T)b_wayInx - 2]) {
        ix = 0;
      } else {
        mtmp = engKinNumVec_wayInx[(int32_T)b_wayInx - 2];
        if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
          i18 = (int32_T)mtmp;
        } else {
          i18 = (int32_T)emlrtIntegerCheckR2012b(mtmp, &ab_emlrtDCI, sp);
        }

        if ((i18 >= 1) && (i18 < 11)) {
          ix = i18;
        } else {
          ix = emlrtDynamicBoundsCheckR2012b(i18, 1, 11, &ub_emlrtBCI, sp);
        }
      }

      i18 = fulEngOptTn3->size[2];
      i20 = (int32_T)b_wayInx - 1;
      if ((i20 >= 1) && (i20 < i18)) {
        iy = i20;
      } else {
        iy = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &wb_emlrtBCI, sp);
      }

      i18 = fulEngOptTn3->size[1];
      i20 = staVec->size[0];
      i23 = (int32_T)b_wayInx - 2;
      if ((i23 >= 1) && (i23 < i20)) {
        i45 = i23;
      } else {
        i45 = emlrtDynamicBoundsCheckR2012b(i23, 1, i20, &ae_emlrtBCI, sp);
      }

      i20 = (int32_T)staVec->data[i45 - 1];
      if ((i20 >= 1) && (i20 < i18)) {
        n = i20;
      } else {
        n = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &xb_emlrtBCI, sp);
      }

      i18 = b_fulEngOptTn3->size[0];
      b_fulEngOptTn3->size[0] = loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)b_fulEngOptTn3, i18, (int32_T)
                        sizeof(real_T), &i_emlrtRTEI);
      for (i18 = 0; i18 < loop_ub; i18++) {
        b_fulEngOptTn3->data[i18] = fulEngOptTn3->data[(i18 + fulEngOptTn3->
          size[0] * (n - 1)) + fulEngOptTn3->size[0] * fulEngOptTn3->size[1] *
          (iy - 1)];
      }

      st.site = &bb_emlrtRSI;
      diff(&st, b_fulEngOptTn3, x);
      i18 = (int32_T)b_wayInx - 1;
      if ((i18 >= 1) && (i18 < 800)) {
        iy = i18;
      } else {
        iy = emlrtDynamicBoundsCheckR2012b(i18, 1, 800, &tb_emlrtBCI, sp);
      }

      engKinMat_engKinInx_wayInx_size[0] = ix;
      for (i18 = 0; i18 < ix; i18++) {
        engKinMat_engKinInx_wayInx_data[i18] = engKinMat_engKinInx_wayInx[i18 +
          11 * (iy - 1)];
      }

      b_engKinMat_engKinInx_wayInx_da.data = (real_T *)
        &engKinMat_engKinInx_wayInx_data;
      b_engKinMat_engKinInx_wayInx_da.size = (int32_T *)
        &engKinMat_engKinInx_wayInx_size;
      b_engKinMat_engKinInx_wayInx_da.allocatedSize = 11;
      b_engKinMat_engKinInx_wayInx_da.numDimensions = 1;
      b_engKinMat_engKinInx_wayInx_da.canFreeData = false;
      st.site = &cb_emlrtRSI;
      diff(&st, &b_engKinMat_engKinInx_wayInx_da, r2);
      n = r2->size[0];
      loop_ub = r2->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        y_data[i18] = r2->data[i18];
      }

      st.site = &bb_emlrtRSI;
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
        emlrtErrorWithMessageIdR2012b(&st, &v_emlrtRTEI, "MATLAB:dimagree", 0);
      }

      /*  <-fast immer 5000; */
      n = 1 + x->size[0];
      psiEngKinVec_data[0] = 0.0;
      loop_ub = x->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        psiEngKinVec_data[i18 + 1] = x->data[i18] / y_data[i18];
      }

      /*  what is the point of adding 0 */
      i18 = psiEngKinOptVec->size[0];
      i20 = (int32_T)b_wayInx - 1;
      i23 = engKinOptInxVec->size[0];
      i27 = (int32_T)b_wayInx - 1;
      if ((i27 >= 1) && (i27 < i23)) {
        i46 = i27;
      } else {
        i46 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &de_emlrtBCI, sp);
      }

      i23 = (int32_T)engKinOptInxVec->data[i46 - 1];
      if ((i20 >= 1) && (i20 < i18)) {
        i47 = i20;
      } else {
        i47 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &be_emlrtBCI, sp);
      }

      if ((i23 >= 1) && (i23 < n)) {
        i48 = i23;
      } else {
        i48 = emlrtDynamicBoundsCheckR2012b(i23, 1, n, &ce_emlrtBCI, sp);
      }

      psiEngKinOptVec->data[i47 - 1] = psiEngKinVec_data[i48 - 1];

      /*  Potentialgrößen im ersten Punkt speichern */
      /*    save potetial variables in the first point/index */
    } else {
      /*  if wayInx == wayInxBeg ( == 1 if wayOInxBeg = 1) */
      st.site = &db_emlrtRSI;
      b_st.site = &lb_emlrtRSI;
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

      if (!!overflow) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &w_emlrtRTEI,
          "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      }

      i18 = engKinOptInxVec->size[0];
      i20 = (int32_T)b_wayInx - 1;
      if ((i20 >= 1) && (i20 < i18)) {
        i49 = i20;
      } else {
        i49 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &yc_emlrtBCI, sp);
      }

      st.site = &pb_emlrtRSI;
      engKinOptInxVec->data[i49 - 1] = (int32_T)optPreInxTn3->data[(((int32_T)
        engKinOptInxVec->data[(int32_T)b_wayInx - 1] + optPreInxTn3->size[0] *
        ((int32_T)staVec->data[(int32_T)b_wayInx - 2] - 1)) + optPreInxTn3->
        size[0] * optPreInxTn3->size[1] * ((int32_T)b_wayInx - 1)) - 1] -
        div_s32(&st, (int32_T)optPreInxTn3->data[(((int32_T)
                  engKinOptInxVec->data[(int32_T)b_wayInx - 1] +
                  optPreInxTn3->size[0] * ((int32_T)staVec->data[(int32_T)
        b_wayInx - 2] - 1)) + optPreInxTn3->size[0] * optPreInxTn3->size[1] *
                 ((int32_T)b_wayInx - 1)) - 1] - 1, (int32_T)engKinNum) *
        (int32_T)engKinNum;
      i18 = fulEngDltOptVec->size[0];
      i20 = (int32_T)b_wayInx - 1;
      i23 = fulEngOptTn3->size[0];
      i27 = engKinOptInxVec->size[0];
      n = (int32_T)b_wayInx;
      if ((n >= 1) && (n < i27)) {
        f_n = n;
      } else {
        f_n = emlrtDynamicBoundsCheckR2012b(n, 1, i27, &cd_emlrtBCI, sp);
      }

      i27 = (int32_T)engKinOptInxVec->data[f_n - 1];
      n = fulEngOptTn3->size[1];
      ix = staVec->size[0];
      iy = (int32_T)b_wayInx - 1;
      if ((iy >= 1) && (iy < ix)) {
        e_iy = iy;
      } else {
        e_iy = emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &ed_emlrtBCI, sp);
      }

      ix = (int32_T)staVec->data[e_iy - 1];
      iy = fulEngOptTn3->size[2];
      ixstart = (int32_T)b_wayInx;
      if ((i20 >= 1) && (i20 < i18)) {
        i50 = i20;
      } else {
        i50 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &ad_emlrtBCI, sp);
      }

      if ((i27 >= 1) && (i27 < i23)) {
        i51 = i27;
      } else {
        i51 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &bd_emlrtBCI, sp);
      }

      if ((ix >= 1) && (ix < n)) {
        h_ix = ix;
      } else {
        h_ix = emlrtDynamicBoundsCheckR2012b(ix, 1, n, &dd_emlrtBCI, sp);
      }

      if ((ixstart >= 1) && (ixstart < iy)) {
        e_ixstart = ixstart;
      } else {
        e_ixstart = emlrtDynamicBoundsCheckR2012b(ixstart, 1, iy, &fd_emlrtBCI,
          sp);
      }

      fulEngDltOptVec->data[i50 - 1] = fulEngOptTn3->data[((i51 +
        fulEngOptTn3->size[0] * (h_ix - 1)) + fulEngOptTn3->size[0] *
        fulEngOptTn3->size[1] * (e_ixstart - 1)) - 1];
    }

    /*  optimale kinetische Energie im Vorgängerpunkt */
    /*    optimal KE from previous point / path_idx */
    i18 = engKinOptVec->size[0];
    i20 = (int32_T)b_wayInx - 1;
    i23 = engKinOptInxVec->size[0];
    i27 = (int32_T)b_wayInx - 1;
    if ((i27 >= 1) && (i27 < i23)) {
      i52 = i27;
    } else {
      i52 = emlrtDynamicBoundsCheckR2012b(i27, 1, i23, &ge_emlrtBCI, sp);
    }

    i23 = (int32_T)engKinOptInxVec->data[i52 - 1];
    i27 = (int32_T)b_wayInx - 1;
    if ((i20 >= 1) && (i20 < i18)) {
      i53 = i20;
    } else {
      i53 = emlrtDynamicBoundsCheckR2012b(i20, 1, i18, &ee_emlrtBCI, sp);
    }

    if ((i23 >= 1) && (i23 < 11)) {
      i54 = i23;
    } else {
      i54 = emlrtDynamicBoundsCheckR2012b(i23, 1, 11, &fe_emlrtBCI, sp);
    }

    if ((i27 >= 1) && (i27 < 800)) {
      i55 = i27;
    } else {
      i55 = emlrtDynamicBoundsCheckR2012b(i27, 1, 800, &he_emlrtBCI, sp);
    }

    engKinOptVec->data[i53 - 1] = engKinMat_engKinInx_wayInx[(i54 + 11 * (i55 -
      1)) - 1];
    wayInx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_fulEngOptTn3);
  emxFree_real_T(&r2);
  emxFree_real_T(&x);
  emxFree_real_T(&engKinOptInxVec);

  /*  end of path_idx loop */
  /*  end of function */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (clcOptTrj_tmp.c) */
