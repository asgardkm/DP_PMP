/*
 * _coder_clcDP_focus_useGeaVec_api.c
 *
 * Code generation for function '_coder_clcDP_focus_useGeaVec_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus_useGeaVec.h"
#include "_coder_clcDP_focus_useGeaVec_api.h"
#include "clcDP_focus_useGeaVec_emxutil.h"
#include "fprintf.h"
#include "clcDP_focus_useGeaVec_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo r_emlrtRTEI = { 1, 1, "_coder_clcDP_focus_useGeaVec_api", ""
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[66]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[73]);
static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4620]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engStaVec_timInx, const char_T *identifier))[1181];
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[95]);
static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[22]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1181];
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6650]);
static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[70]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *batOcv,
  const char_T *identifier))[693];
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[146]);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[693];
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[66]);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *geaStaVec, const char_T *identifier))[492477];
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4620]);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[492477];
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[22]);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *crsSpdMat, const char_T *identifier))[7086];
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[70]);
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7086];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *batPwrMinIdxTn3, const char_T *identifier))[4910598];
static real_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1181];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4910598];
static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[693];
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *inputparams,
  const char_T *identifier, struct0_T *y);
static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[492477];
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static real_T (*nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7086];
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_scalar_struct, const char_T *identifier, struct1_T *y);
static real_T (*ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4910598];
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_scalar_struct, const char_T *identifier, struct2_T *y);
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[35]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct3_T *y);
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[38]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1330]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[73]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[35]);
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[95]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[38]);
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6650]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1330]);
static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[146]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[66])
{
  int32_T iv44[2];
  int32_T i21;
  for (i21 = 0; i21 < 2; i21++) {
    iv44[i21] = 1 + 65 * i21;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv44);
  for (i21 = 0; i21 < 66; i21++) {
    ret[i21] = (*(real_T (*)[66])mxGetData(src))[i21];
  }

  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv27[2] = { 0, 0 };

  const mxArray *m9;
  y = NULL;
  m9 = emlrtCreateNumericArray(2, iv27, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m9, (void *)u->data);
  emlrtSetDimensions((mxArray *)m9, u->size, 2);
  emlrtAssign(&y, m9);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[73])
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4620])
{
  int32_T iv45[2];
  int32_T i22;
  int32_T i23;
  for (i22 = 0; i22 < 2; i22++) {
    iv45[i22] = 66 + (i22 << 2);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv45);
  for (i22 = 0; i22 < 70; i22++) {
    for (i23 = 0; i23 < 66; i23++) {
      ret[i23 + 66 * i22] = (*(real_T (*)[4620])mxGetData(src))[i23 + 66 * i22];
    }
  }

  emlrtDestroyArray(&src);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engStaVec_timInx, const char_T *identifier))[1181]
{
  real_T (*y)[1181];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(engStaVec_timInx), &thisId);
  emlrtDestroyArray(&engStaVec_timInx);
  return y;
}
  static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[95])
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[22])
{
  int32_T iv46[2];
  int32_T i24;
  int32_T i25;
  for (i24 = 0; i24 < 2; i24++) {
    iv46[i24] = 11 + -9 * i24;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv46);
  for (i24 = 0; i24 < 2; i24++) {
    for (i25 = 0; i25 < 11; i25++) {
      ret[i25 + 11 * i24] = (*(real_T (*)[22])mxGetData(src))[i25 + 11 * i24];
    }
  }

  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1181]
{
  real_T (*y)[1181];
  y = kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6650])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[70])
{
  int32_T iv47[2];
  int32_T i26;
  int32_T i27;
  for (i26 = 0; i26 < 2; i26++) {
    iv47[i26] = 35 + -33 * i26;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv47);
  for (i26 = 0; i26 < 2; i26++) {
    for (i27 = 0; i27 < 35; i27++) {
      ret[i27 + 35 * i26] = (*(real_T (*)[70])mxGetData(src))[i27 + 35 * i26];
    }
  }

  emlrtDestroyArray(&src);
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *batOcv,
  const char_T *identifier))[693]
{
  real_T (*y)[693];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(batOcv), &thisId);
  emlrtDestroyArray(&batOcv);
  return y;
}
  static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[146])
{
  yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv26[3] = { 0, 0, 0 };

  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateNumericArray(3, iv26, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m8, (void *)u->data);
  emlrtSetDimensions((mxArray *)m8, u->size, 3);
  emlrtAssign(&y, m8);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[693]
{
  real_T (*y)[693];
  y = lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[66])
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *geaStaVec, const char_T *identifier))[492477]
{
  real_T (*y)[492477];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(geaStaVec), &thisId);
  emlrtDestroyArray(&geaStaVec);
  return y;
}
  static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4620])
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[492477]
{
  real_T (*y)[492477];
  y = mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[22])
{
  cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *crsSpdMat, const char_T *identifier))[7086]
{
  real_T (*y)[7086];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = j_emlrt_marshallIn(sp, emlrtAlias(crsSpdMat), &thisId);
  emlrtDestroyArray(&crsSpdMat);
  return y;
}
  static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[70])
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7086]
{
  real_T (*y)[7086];
  y = nb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *batPwrMinIdxTn3, const char_T *identifier))[4910598]
{
  real_T (*y)[4910598];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = l_emlrt_marshallIn(sp, emlrtAlias(batPwrMinIdxTn3), &thisId);
  emlrtDestroyArray(&batPwrMinIdxTn3);
  return y;
}

static real_T (*kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1181]
{
  real_T (*ret)[1181];
  int32_T iv28[1];
  iv28[0] = 1181;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv28);
  ret = (real_T (*)[1181])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4910598]
{
  real_T (*y)[4910598];
  y = ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[693]
{
  real_T (*ret)[693];
  int32_T iv29[2];
  int32_T i5;
  for (i5 = 0; i5 < 2; i5++) {
    iv29[i5] = 1 + 692 * i5;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv29);
  ret = (real_T (*)[693])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *inputparams, const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  n_emlrt_marshallIn(sp, emlrtAlias(inputparams), &thisId, y);
  emlrtDestroyArray(&inputparams);
}

static real_T (*mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[492477]
{
  real_T (*ret)[492477];
  int32_T iv30[2];
  int32_T i6;
  for (i6 = 0; i6 < 2; i6++) {
    iv30[i6] = 1181 + -764 * i6;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv30);
  ret = (real_T (*)[492477])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[16] = { "disFlg", "iceFlgBool", "brkBool",
    "iceExtBool", "timStp", "batEngBegMinRat", "batEngBegMaxRat",
    "batEngEndMinRat", "batEngEndMaxRat", "batPwrAux", "staChgPenCosVal",
    "timInxBeg", "timInxEnd", "engBeg", "engEnd", "staBeg" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 16, fieldNames, 0U, 0);
  thisId.fIdentifier = "disFlg";
  y->disFlg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "disFlg")), &thisId);
  thisId.fIdentifier = "iceFlgBool";
  y->iceFlgBool = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFlgBool")), &thisId);
  thisId.fIdentifier = "brkBool";
  y->brkBool = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "brkBool")), &thisId);
  thisId.fIdentifier = "iceExtBool";
  y->iceExtBool = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceExtBool")), &thisId);
  thisId.fIdentifier = "timStp";
  y->timStp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "timStp")), &thisId);
  thisId.fIdentifier = "batEngBegMinRat";
  y->batEngBegMinRat = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "batEngBegMinRat")), &thisId);
  thisId.fIdentifier = "batEngBegMaxRat";
  y->batEngBegMaxRat = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "batEngBegMaxRat")), &thisId);
  thisId.fIdentifier = "batEngEndMinRat";
  y->batEngEndMinRat = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "batEngEndMinRat")), &thisId);
  thisId.fIdentifier = "batEngEndMaxRat";
  y->batEngEndMaxRat = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "batEngEndMaxRat")), &thisId);
  thisId.fIdentifier = "batPwrAux";
  y->batPwrAux = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrAux")), &thisId);
  thisId.fIdentifier = "staChgPenCosVal";
  y->staChgPenCosVal = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "staChgPenCosVal")), &thisId);
  thisId.fIdentifier = "timInxBeg";
  y->timInxBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "timInxBeg")), &thisId);
  thisId.fIdentifier = "timInxEnd";
  y->timInxEnd = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "timInxEnd")), &thisId);
  thisId.fIdentifier = "engBeg";
  y->engBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engBeg")), &thisId);
  thisId.fIdentifier = "engEnd";
  y->engEnd = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engEnd")), &thisId);
  thisId.fIdentifier = "staBeg";
  y->staBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staBeg")), &thisId);
  emlrtDestroyArray(&u);
}

static real_T (*nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7086]
{
  real_T (*ret)[7086];
  int32_T iv31[2];
  int32_T i7;
  for (i7 = 0; i7 < 2; i7++) {
    iv31[i7] = 1181 + -1175 * i7;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv31);
  ret = (real_T (*)[7086])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_scalar_struct, const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  p_emlrt_marshallIn(sp, emlrtAlias(tst_scalar_struct), &thisId, y);
  emlrtDestroyArray(&tst_scalar_struct);
}

static real_T (*ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4910598]
{
  real_T (*ret)[4910598];
  int32_T iv32[3];
  int32_T i;
  static const int16_T iv33[3] = { 1181, 693, 6 };

  for (i = 0; i < 3; i++) {
    iv32[i] = iv33[i];
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv32);
  ret = (real_T (*)[4910598])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[10] = { "useGeaSta", "staNum", "geaStaMin",
    "geaStaMax", "engStaNum", "engStaMin", "engStaMax", "batEngMin", "batEngStp",
    "batEngMax" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 10, fieldNames, 0U, 0);
  thisId.fIdentifier = "useGeaSta";
  y->useGeaSta = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "useGeaSta")), &thisId);
  thisId.fIdentifier = "staNum";
  y->staNum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staNum")), &thisId);
  thisId.fIdentifier = "geaStaMin";
  y->geaStaMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaStaMin")), &thisId);
  thisId.fIdentifier = "geaStaMax";
  y->geaStaMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaStaMax")), &thisId);
  thisId.fIdentifier = "engStaNum";
  y->engStaNum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engStaNum")), &thisId);
  thisId.fIdentifier = "engStaMin";
  y->engStaMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engStaMin")), &thisId);
  thisId.fIdentifier = "engStaMax";
  y->engStaMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engStaMax")), &thisId);
  thisId.fIdentifier = "batEngMin";
  y->batEngMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMin")), &thisId);
  thisId.fIdentifier = "batEngStp";
  y->batEngStp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngStp")), &thisId);
  thisId.fIdentifier = "batEngMax";
  y->batEngMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMax")), &thisId);
  emlrtDestroyArray(&u);
}

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv34[2];
  int32_T i8;
  for (i8 = 0; i8 < 2; i8++) {
    iv34[i8] = 1 + i8;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv34);
  for (i8 = 0; i8 < 2; i8++) {
    ret[i8] = (*(real_T (*)[2])mxGetData(src))[i8];
  }

  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_scalar_struct, const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  r_emlrt_marshallIn(sp, emlrtAlias(fzg_scalar_struct), &thisId, y);
  emlrtDestroyArray(&fzg_scalar_struct);
}

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv35[1];
  int32_T i9;
  iv35[0] = 6;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv35);
  for (i9 = 0; i9 < 6; i9++) {
    ret[i9] = (*(real_T (*)[6])mxGetData(src))[i9];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[18] = { "vehVelMin", "vehVelMax",
    "vehVelThresh", "vehAccMax", "vehAccMin", "drgCof", "vehMas", "whlRosResCof",
    "whlDrr", "batRstChr", "batRstDch", "batPwrMax", "batPwrMin", "geaEfy",
    "fulDen", "fulLhv", "fuel_density", "fuel_lower_heating_value" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 18, fieldNames, 0U, 0);
  thisId.fIdentifier = "vehVelMin";
  y->vehVelMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMin")), &thisId);
  thisId.fIdentifier = "vehVelMax";
  y->vehVelMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMax")), &thisId);
  thisId.fIdentifier = "vehVelThresh";
  y->vehVelThresh = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "vehVelThresh")), &thisId);
  thisId.fIdentifier = "vehAccMax";
  y->vehAccMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehAccMax")), &thisId);
  thisId.fIdentifier = "vehAccMin";
  y->vehAccMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehAccMin")), &thisId);
  thisId.fIdentifier = "drgCof";
  y->drgCof = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "drgCof")), &thisId);
  thisId.fIdentifier = "vehMas";
  y->vehMas = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehMas")), &thisId);
  thisId.fIdentifier = "whlRosResCof";
  y->whlRosResCof = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "whlRosResCof")), &thisId);
  thisId.fIdentifier = "whlDrr";
  y->whlDrr = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "whlDrr")), &thisId);
  thisId.fIdentifier = "batRstChr";
  y->batRstChr = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstChr")), &thisId);
  thisId.fIdentifier = "batRstDch";
  y->batRstDch = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstDch")), &thisId);
  thisId.fIdentifier = "batPwrMax";
  y->batPwrMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMax")), &thisId);
  thisId.fIdentifier = "batPwrMin";
  y->batPwrMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMin")), &thisId);
  thisId.fIdentifier = "geaEfy";
  y->geaEfy = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaEfy")), &thisId);
  thisId.fIdentifier = "fulDen";
  y->fulDen = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulDen")), &thisId);
  thisId.fIdentifier = "fulLhv";
  y->fulLhv = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulLhv")), &thisId);
  thisId.fIdentifier = "fuel_density";
  y->fuel_density = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "fuel_density")), &thisId);
  thisId.fIdentifier = "fuel_lower_heating_value";
  y->fuel_lower_heating_value = b_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2013a(sp, u, 0, "fuel_lower_heating_value")), &thisId);
  emlrtDestroyArray(&u);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[35])
{
  int32_T iv36[2];
  int32_T i10;
  for (i10 = 0; i10 < 2; i10++) {
    iv36[i10] = 1 + 34 * i10;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv36);
  for (i10 = 0; i10 < 35; i10++) {
    ret[i10] = (*(real_T (*)[35])mxGetData(src))[i10];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  t_emlrt_marshallIn(sp, emlrtAlias(fzg_array_struct), &thisId, y);
  emlrtDestroyArray(&fzg_array_struct);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[38])
{
  int32_T iv37[1];
  int32_T i11;
  iv37[0] = 38;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv37);
  for (i11 = 0; i11 < 38; i11++) {
    ret[i11] = (*(real_T (*)[38])mxGetData(src))[i11];
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[20] = { "batOcvCof_batEng", "geaRat",
    "iceSpdMgd", "iceTrqMgd", "iceFulPwr_iceSpd_iceTrq", "iceTrqMaxCof",
    "iceTrqMinCof", "emoSpdMgd", "emoTrqMgd", "emoPwr_emoSpd_emoTrq",
    "emoTrqMin_emoSpd", "emoTrqMax_emoSpd", "emoPwrMgd", "emoTrq_emoSpd_emoPwr",
    "emoPwrMax_emoSpd", "emoPwrMin_emoSpd", "SOC_vs_OCV", "geaEfy",
    "iceTrqMax_emoSpd", "iceTrqMin_emoSpd" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 20, fieldNames, 0U, 0);
  thisId.fIdentifier = "batOcvCof_batEng";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "geaRat";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "iceSpdMgd";
  w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  y_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMaxCof")), &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMinCof")), &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  bb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                      &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  cb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                      &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  db_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  fb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                      &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  gb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  thisId.fIdentifier = "SOC_vs_OCV";
  hb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "SOC_vs_OCV")),
                      &thisId, y->SOC_vs_OCV);
  thisId.fIdentifier = "geaEfy";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaEfy")),
                     &thisId, y->geaEfy);
  thisId.fIdentifier = "iceTrqMax_emoSpd";
  ib_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMax_emoSpd")), &thisId, y->iceTrqMax_emoSpd);
  thisId.fIdentifier = "iceTrqMin_emoSpd";
  ib_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMin_emoSpd")), &thisId, y->iceTrqMin_emoSpd);
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1330])
{
  int32_T iv38[2];
  int32_T i12;
  int32_T i13;
  for (i12 = 0; i12 < 2; i12++) {
    iv38[i12] = 38 + -3 * i12;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv38);
  for (i12 = 0; i12 < 35; i12++) {
    for (i13 = 0; i13 < 38; i13++) {
      ret[i13 + 38 * i12] = (*(real_T (*)[1330])mxGetData(src))[i13 + 38 * i12];
    }
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv39[2];
  int32_T i14;
  for (i14 = 0; i14 < 2; i14++) {
    iv39[i14] = 1 + (i14 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv39);
  for (i14 = 0; i14 < 3; i14++) {
    ret[i14] = (*(real_T (*)[3])mxGetData(src))[i14];
  }

  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[73])
{
  int32_T iv40[2];
  int32_T i15;
  for (i15 = 0; i15 < 2; i15++) {
    iv40[i15] = 1 + 72 * i15;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv40);
  for (i15 = 0; i15 < 73; i15++) {
    ret[i15] = (*(real_T (*)[73])mxGetData(src))[i15];
  }

  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[35])
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[95])
{
  int32_T iv41[1];
  int32_T i16;
  iv41[0] = 95;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv41);
  for (i16 = 0; i16 < 95; i16++) {
    ret[i16] = (*(real_T (*)[95])mxGetData(src))[i16];
  }

  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[38])
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6650])
{
  int32_T iv42[2];
  int32_T i17;
  int32_T i18;
  for (i17 = 0; i17 < 2; i17++) {
    iv42[i17] = 95 + -25 * i17;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv42);
  for (i17 = 0; i17 < 70; i17++) {
    for (i18 = 0; i18 < 95; i18++) {
      ret[i18 + 95 * i17] = (*(real_T (*)[6650])mxGetData(src))[i18 + 95 * i17];
    }
  }

  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1330])
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[146])
{
  int32_T iv43[2];
  int32_T i19;
  int32_T i20;
  for (i19 = 0; i19 < 2; i19++) {
    iv43[i19] = 73 + -71 * i19;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv43);
  for (i19 = 0; i19 < 2; i19++) {
    for (i20 = 0; i20 < 73; i20++) {
      ret[i20 + 73 * i19] = (*(real_T (*)[146])mxGetData(src))[i20 + 73 * i19];
    }
  }

  emlrtDestroyArray(&src);
}

void clcDP_focus_useGeaVec_api(const mxArray * const prhs[21], const mxArray
  *plhs[7])
{
  emxArray_real_T *optPreInxTn3;
  emxArray_real_T *batPwrOptTn3;
  emxArray_real_T *fulEngOptTn3;
  emxArray_real_T *emoTrqOptTn3;
  emxArray_real_T *iceTrqOptTn3;
  emxArray_real_T *brkTrqOptTn3;
  emxArray_real_T *cos2goActMat;
  real_T batEngBeg;
  real_T timNum;
  real_T (*engStaVec_timInx)[1181];
  real_T (*batOcv)[693];
  real_T (*velVec)[1181];
  real_T (*geaStaVec)[492477];
  real_T (*crsSpdMat)[7086];
  real_T (*crsTrqMat)[7086];
  real_T (*emoTrqMinPosMat)[7086];
  real_T (*emoTrqMaxPosMat)[7086];
  real_T (*emoPwrMinPosMat)[7086];
  real_T (*emoPwrMaxPosMat)[7086];
  real_T (*iceTrqMinPosMat)[7086];
  real_T (*iceTrqMaxPosMat)[7086];
  real_T (*batPwrMinIdxTn3)[4910598];
  real_T (*batPwrMaxIdxTn3)[4910598];
  real_T (*batPwrDemIdxTn3)[4910598];
  struct0_T inputparams;
  struct1_T tst_scalar_struct;
  struct2_T fzg_scalar_struct;
  struct3_T fzg_array_struct;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_real_T(&st, &optPreInxTn3, 3, &r_emlrtRTEI, true);
  b_emxInit_real_T(&st, &batPwrOptTn3, 3, &r_emlrtRTEI, true);
  b_emxInit_real_T(&st, &fulEngOptTn3, 3, &r_emlrtRTEI, true);
  b_emxInit_real_T(&st, &emoTrqOptTn3, 3, &r_emlrtRTEI, true);
  b_emxInit_real_T(&st, &iceTrqOptTn3, 3, &r_emlrtRTEI, true);
  b_emxInit_real_T(&st, &brkTrqOptTn3, 3, &r_emlrtRTEI, true);
  emxInit_real_T(&st, &cos2goActMat, 2, &r_emlrtRTEI, true);

  /* Marshall function inputs */
  batEngBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "batEngBeg");
  timNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "timNum");
  engStaVec_timInx = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]),
    "engStaVec_timInx");
  batOcv = e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "batOcv");
  velVec = c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "velVec");
  geaStaVec = g_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "geaStaVec");
  crsSpdMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "crsSpdMat");
  crsTrqMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "crsTrqMat");
  emoTrqMinPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[8]),
    "emoTrqMinPosMat");
  emoTrqMaxPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[9]),
    "emoTrqMaxPosMat");
  emoPwrMinPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[10]),
    "emoPwrMinPosMat");
  emoPwrMaxPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[11]),
    "emoPwrMaxPosMat");
  iceTrqMinPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[12]),
    "iceTrqMinPosMat");
  iceTrqMaxPosMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[13]),
    "iceTrqMaxPosMat");
  batPwrMinIdxTn3 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[14]),
    "batPwrMinIdxTn3");
  batPwrMaxIdxTn3 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[15]),
    "batPwrMaxIdxTn3");
  batPwrDemIdxTn3 = k_emlrt_marshallIn(&st, emlrtAlias(prhs[16]),
    "batPwrDemIdxTn3");
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "inputparams", &inputparams);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "tst_scalar_struct",
                     &tst_scalar_struct);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "fzg_scalar_struct",
                     &fzg_scalar_struct);
  s_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]), "fzg_array_struct",
                     &fzg_array_struct);

  /* Invoke the target function */
  clcDP_focus_useGeaVec(&st, batEngBeg, timNum, *engStaVec_timInx, *batOcv,
                        *velVec, *geaStaVec, *crsSpdMat, *crsTrqMat,
                        *emoTrqMinPosMat, *emoTrqMaxPosMat, *emoPwrMinPosMat,
                        *emoPwrMaxPosMat, *iceTrqMinPosMat, *iceTrqMaxPosMat,
                        *batPwrMinIdxTn3, *batPwrMaxIdxTn3, *batPwrDemIdxTn3,
                        &inputparams, &tst_scalar_struct, &fzg_scalar_struct,
                        &fzg_array_struct, optPreInxTn3, batPwrOptTn3,
                        fulEngOptTn3, emoTrqOptTn3, iceTrqOptTn3, brkTrqOptTn3,
                        cos2goActMat);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(optPreInxTn3);
  plhs[1] = emlrt_marshallOut(batPwrOptTn3);
  plhs[2] = emlrt_marshallOut(fulEngOptTn3);
  plhs[3] = emlrt_marshallOut(emoTrqOptTn3);
  plhs[4] = emlrt_marshallOut(iceTrqOptTn3);
  plhs[5] = emlrt_marshallOut(brkTrqOptTn3);
  plhs[6] = b_emlrt_marshallOut(cos2goActMat);
  cos2goActMat->canFreeData = false;
  emxFree_real_T(&cos2goActMat);
  brkTrqOptTn3->canFreeData = false;
  emxFree_real_T(&brkTrqOptTn3);
  iceTrqOptTn3->canFreeData = false;
  emxFree_real_T(&iceTrqOptTn3);
  emoTrqOptTn3->canFreeData = false;
  emxFree_real_T(&emoTrqOptTn3);
  fulEngOptTn3->canFreeData = false;
  emxFree_real_T(&fulEngOptTn3);
  batPwrOptTn3->canFreeData = false;
  emxFree_real_T(&batPwrOptTn3);
  optPreInxTn3->canFreeData = false;
  emxFree_real_T(&optPreInxTn3);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_clcDP_focus_useGeaVec_api.c) */
