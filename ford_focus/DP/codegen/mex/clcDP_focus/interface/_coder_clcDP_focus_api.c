/*
 * _coder_clcDP_focus_api.c
 *
 * Code generation for function '_coder_clcDP_focus_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_focus.h"
#include "_coder_clcDP_focus_api.h"
#include "clcDP_focus_emxutil.h"
#include "fprintf.h"
#include "clcDP_focus_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, 1, "_coder_clcDP_focus_api", "" };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[146]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[66]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engStaVec_timInx, const char_T *identifier))[1181];
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4620]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1181];
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[22]);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *batOcv,
  const char_T *identifier))[693];
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[693];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *crsSpdMat, const char_T *identifier))[7086];
static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1181];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[7086];
static real_T (*hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[693];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *batPwrMinIdxTn3, const char_T *identifier))[4910598];
static real_T (*ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7086];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4910598];
static real_T (*jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4910598];
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_scalar_struct, const char_T *identifier, struct0_T *y);
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_scalar_struct, const char_T *identifier, struct1_T *y);
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct2_T *y);
static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[73]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[95]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6650]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[146]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[66]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4620]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[73]);
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[22]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[95]);
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6650]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[146])
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv28[3] = { 0, 0, 0 };

  const mxArray *m9;
  y = NULL;
  m9 = emlrtCreateNumericArray(3, iv28, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m9, (void *)u->data);
  emlrtSetDimensions((mxArray *)m9, u->size, 3);
  emlrtAssign(&y, m9);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[66])
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
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
  emlrtMsgIdentifier *parentId, real_T y[4620])
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[1181]
{
  real_T (*y)[1181];
  y = gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[22])
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
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
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv27[4] = { 0, 0, 0, 0 };

  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateNumericArray(4, iv27, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m8, (void *)u->data);
  emlrtSetDimensions((mxArray *)m8, u->size, 4);
  emlrtAssign(&y, m8);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[693]
{
  real_T (*y)[693];
  y = hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *crsSpdMat, const char_T *identifier))[7086]
{
  real_T (*y)[7086];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(crsSpdMat), &thisId);
  emlrtDestroyArray(&crsSpdMat);
  return y;
}

static real_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[1181]
{
  real_T (*ret)[1181];
  int32_T iv29[1];
  iv29[0] = 1181;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv29);
  ret = (real_T (*)[1181])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[7086]
{
  real_T (*y)[7086];
  y = ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[693]
{
  real_T (*ret)[693];
  int32_T iv30[2];
  int32_T i13;
  for (i13 = 0; i13 < 2; i13++) {
    iv30[i13] = 1 + 692 * i13;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv30);
  ret = (real_T (*)[693])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *batPwrMinIdxTn3, const char_T *identifier))[4910598]
{
  real_T (*y)[4910598];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = j_emlrt_marshallIn(sp, emlrtAlias(batPwrMinIdxTn3), &thisId);
  emlrtDestroyArray(&batPwrMinIdxTn3);
  return y;
}

static real_T (*ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7086]
{
  real_T (*ret)[7086];
  int32_T iv31[2];
  int32_T i14;
  for (i14 = 0; i14 < 2; i14++) {
    iv31[i14] = 1181 + -1175 * i14;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv31);
  ret = (real_T (*)[7086])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4910598]
{
  real_T (*y)[4910598];
  y = jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
  static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_scalar_struct, const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  l_emlrt_marshallIn(sp, emlrtAlias(tst_scalar_struct), &thisId, y);
  emlrtDestroyArray(&tst_scalar_struct);
}

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv34[2];
  int32_T i15;
  for (i15 = 0; i15 < 2; i15++) {
    iv34[i15] = 1 + i15;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv34);
  for (i15 = 0; i15 < 2; i15++) {
    ret[i15] = (*(real_T (*)[2])mxGetData(src))[i15];
  }

  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
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

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv35[1];
  int32_T i16;
  iv35[0] = 6;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv35);
  for (i16 = 0; i16 < 6; i16++) {
    ret[i16] = (*(real_T (*)[6])mxGetData(src))[i16];
  }

  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_scalar_struct, const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  n_emlrt_marshallIn(sp, emlrtAlias(fzg_scalar_struct), &thisId, y);
  emlrtDestroyArray(&fzg_scalar_struct);
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv36[2];
  boolean_T bv0[2];
  int32_T i17;
  static const boolean_T bv1[2] = { false, true };

  int32_T iv37[2];
  for (i17 = 0; i17 < 2; i17++) {
    iv36[i17] = 1 + -2 * i17;
    bv0[i17] = bv1[i17];
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv36, bv0, iv37);
  i17 = ret->size[0] * ret->size[1];
  ret->size[0] = iv37[0];
  ret->size[1] = iv37[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i17, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
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

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv38[1];
  boolean_T bv2[1];
  int32_T iv39[1];
  int32_T i18;
  iv38[0] = -1;
  bv2[0] = true;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv38, bv2, iv39);
  i18 = ret->size[0];
  ret->size[0] = iv39[0];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i18, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  p_emlrt_marshallIn(sp, emlrtAlias(fzg_array_struct), &thisId, y);
  emlrtDestroyArray(&fzg_array_struct);
}

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv40[2];
  boolean_T bv3[2];
  int32_T i;
  int32_T iv41[2];
  for (i = 0; i < 2; i++) {
    iv40[i] = -1;
    bv3[i] = true;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv40, bv3, iv41);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv41[0];
  ret->size[1] = iv41[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
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
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "geaRat";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "iceSpdMgd";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMaxCof")),
                     &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  v_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMinCof")),
                     &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  w_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                     &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  x_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                     &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  y_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  bb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                      &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  cb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  ab_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  thisId.fIdentifier = "SOC_vs_OCV";
  db_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "SOC_vs_OCV")),
                      &thisId, y->SOC_vs_OCV);
  thisId.fIdentifier = "geaEfy";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaEfy")),
                     &thisId, y->geaEfy);
  thisId.fIdentifier = "iceTrqMax_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMax_emoSpd")), &thisId, y->iceTrqMax_emoSpd);
  thisId.fIdentifier = "iceTrqMin_emoSpd";
  eb_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceTrqMin_emoSpd")), &thisId, y->iceTrqMin_emoSpd);
  emlrtDestroyArray(&u);
}

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv42[2];
  int32_T i19;
  for (i19 = 0; i19 < 2; i19++) {
    iv42[i19] = 1 + (i19 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv42);
  for (i19 = 0; i19 < 3; i19++) {
    ret[i19] = (*(real_T (*)[3])mxGetData(src))[i19];
  }

  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[73])
{
  int32_T iv43[2];
  int32_T i20;
  for (i20 = 0; i20 < 2; i20++) {
    iv43[i20] = 1 + 72 * i20;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv43);
  for (i20 = 0; i20 < 73; i20++) {
    ret[i20] = (*(real_T (*)[73])mxGetData(src))[i20];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[95])
{
  int32_T iv44[1];
  int32_T i21;
  iv44[0] = 95;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv44);
  for (i21 = 0; i21 < 95; i21++) {
    ret[i21] = (*(real_T (*)[95])mxGetData(src))[i21];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6650])
{
  int32_T iv45[2];
  int32_T i22;
  int32_T i23;
  for (i22 = 0; i22 < 2; i22++) {
    iv45[i22] = 95 + -25 * i22;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv45);
  for (i22 = 0; i22 < 70; i22++) {
    for (i23 = 0; i23 < 95; i23++) {
      ret[i23 + 95 * i22] = (*(real_T (*)[6650])mxGetData(src))[i23 + 95 * i22];
    }
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  nb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[146])
{
  int32_T iv46[2];
  int32_T i24;
  int32_T i25;
  for (i24 = 0; i24 < 2; i24++) {
    iv46[i24] = 73 + -71 * i24;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv46);
  for (i24 = 0; i24 < 2; i24++) {
    for (i25 = 0; i25 < 73; i25++) {
      ret[i25 + 73 * i24] = (*(real_T (*)[146])mxGetData(src))[i25 + 73 * i24];
    }
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[66])
{
  int32_T iv47[2];
  int32_T i26;
  for (i26 = 0; i26 < 2; i26++) {
    iv47[i26] = 1 + 65 * i26;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv47);
  for (i26 = 0; i26 < 66; i26++) {
    ret[i26] = (*(real_T (*)[66])mxGetData(src))[i26];
  }

  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4620])
{
  int32_T iv48[2];
  int32_T i27;
  int32_T i28;
  for (i27 = 0; i27 < 2; i27++) {
    iv48[i27] = 66 + (i27 << 2);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv48);
  for (i27 = 0; i27 < 70; i27++) {
    for (i28 = 0; i28 < 66; i28++) {
      ret[i28 + 66 * i27] = (*(real_T (*)[4620])mxGetData(src))[i28 + 66 * i27];
    }
  }

  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[73])
{
  qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[22])
{
  int32_T iv49[2];
  int32_T i29;
  int32_T i30;
  for (i29 = 0; i29 < 2; i29++) {
    iv49[i29] = 11 + -9 * i29;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv49);
  for (i29 = 0; i29 < 2; i29++) {
    for (i30 = 0; i30 < 11; i30++) {
      ret[i30 + 11 * i29] = (*(real_T (*)[22])mxGetData(src))[i30 + 11 * i29];
    }
  }

  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[95])
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv50[2];
  boolean_T bv4[2];
  int32_T i31;
  static const boolean_T bv5[2] = { true, false };

  int32_T iv51[2];
  for (i31 = 0; i31 < 2; i31++) {
    iv50[i31] = 3 * i31 - 1;
    bv4[i31] = bv5[i31];
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv50, bv4, iv51);
  i31 = ret->size[0] * ret->size[1];
  ret->size[0] = iv51[0];
  ret->size[1] = iv51[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i31, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6650])
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

void clcDP_focus_api(const mxArray * const prhs[29], const mxArray *plhs[4])
{
  struct2_T fzg_array_struct;
  emxArray_real_T *optPreInxTn4;
  emxArray_real_T *batPwrOptTn4;
  emxArray_real_T *fulEngOptTn4;
  emxArray_real_T *cos2goActTn3;
  real_T disFlg;
  real_T iceFlgBool;
  real_T brkBool;
  real_T timStp;
  real_T batEngBeg;
  real_T batPwrAux;
  real_T staChgPenCosVal;
  real_T timInxBeg;
  real_T timInxEnd;
  real_T timNum;
  real_T engBeg;
  real_T (*engStaVec_timInx)[1181];
  real_T staBeg;
  real_T (*batOcv)[693];
  real_T (*velVec)[1181];
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
  struct0_T tst_scalar_struct;
  struct1_T fzg_scalar_struct;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct2_T(&st, &fzg_array_struct, &l_emlrtRTEI, true);
  d_emxInit_real_T(&st, &optPreInxTn4, 4, &l_emlrtRTEI, true);
  d_emxInit_real_T(&st, &batPwrOptTn4, 4, &l_emlrtRTEI, true);
  d_emxInit_real_T(&st, &fulEngOptTn4, 4, &l_emlrtRTEI, true);
  emxInit_real_T(&st, &cos2goActTn3, 3, &l_emlrtRTEI, true);

  /* Marshall function inputs */
  disFlg = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "disFlg");
  iceFlgBool = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "iceFlgBool");
  brkBool = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "brkBool");
  timStp = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "timStp");
  batEngBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "batEngBeg");
  batPwrAux = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "batPwrAux");
  staChgPenCosVal = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]),
    "staChgPenCosVal");
  timInxBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "timInxBeg");
  timInxEnd = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "timInxEnd");
  timNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "timNum");
  engBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "engBeg");
  engStaVec_timInx = c_emlrt_marshallIn(&st, emlrtAlias(prhs[11]),
    "engStaVec_timInx");
  staBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "staBeg");
  batOcv = e_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "batOcv");
  velVec = c_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "velVec");
  crsSpdMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "crsSpdMat");
  crsTrqMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "crsTrqMat");
  emoTrqMinPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[17]),
    "emoTrqMinPosMat");
  emoTrqMaxPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[18]),
    "emoTrqMaxPosMat");
  emoPwrMinPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[19]),
    "emoPwrMinPosMat");
  emoPwrMaxPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[20]),
    "emoPwrMaxPosMat");
  iceTrqMinPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[21]),
    "iceTrqMinPosMat");
  iceTrqMaxPosMat = g_emlrt_marshallIn(&st, emlrtAlias(prhs[22]),
    "iceTrqMaxPosMat");
  batPwrMinIdxTn3 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[23]),
    "batPwrMinIdxTn3");
  batPwrMaxIdxTn3 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[24]),
    "batPwrMaxIdxTn3");
  batPwrDemIdxTn3 = i_emlrt_marshallIn(&st, emlrtAlias(prhs[25]),
    "batPwrDemIdxTn3");
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[26]), "tst_scalar_struct",
                     &tst_scalar_struct);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[27]), "fzg_scalar_struct",
                     &fzg_scalar_struct);
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs[28]), "fzg_array_struct",
                     &fzg_array_struct);

  /* Invoke the target function */
  clcDP_focus(&st, disFlg, iceFlgBool, brkBool, timStp, batEngBeg, batPwrAux,
              staChgPenCosVal, timInxBeg, timInxEnd, timNum, engBeg,
              *engStaVec_timInx, staBeg, *batOcv, *velVec, *crsSpdMat,
              *crsTrqMat, *emoTrqMinPosMat, *emoTrqMaxPosMat, *emoPwrMinPosMat, *
              emoPwrMaxPosMat, *iceTrqMinPosMat, *iceTrqMaxPosMat,
              *batPwrMinIdxTn3, *batPwrMaxIdxTn3, *batPwrDemIdxTn3,
              &tst_scalar_struct, &fzg_scalar_struct, &fzg_array_struct,
              optPreInxTn4, batPwrOptTn4, fulEngOptTn4, cos2goActTn3);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(optPreInxTn4);
  plhs[1] = emlrt_marshallOut(batPwrOptTn4);
  plhs[2] = emlrt_marshallOut(fulEngOptTn4);
  plhs[3] = b_emlrt_marshallOut(cos2goActTn3);
  cos2goActTn3->canFreeData = false;
  emxFree_real_T(&cos2goActTn3);
  fulEngOptTn4->canFreeData = false;
  emxFree_real_T(&fulEngOptTn4);
  batPwrOptTn4->canFreeData = false;
  emxFree_real_T(&batPwrOptTn4);
  optPreInxTn4->canFreeData = false;
  emxFree_real_T(&optPreInxTn4);
  emxFreeStruct_struct2_T(&fzg_array_struct);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_clcDP_focus_api.c) */
