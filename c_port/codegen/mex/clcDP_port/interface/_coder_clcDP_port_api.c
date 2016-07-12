/*
 * _coder_clcDP_port_api.c
 *
 * Code generation for function '_coder_clcDP_port_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "_coder_clcDP_port_api.h"
#include "fprintf.h"
#include "clcDP_port_emxutil.h"
#include "clcDP_port_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 1, 1, "_coder_clcDP_port_api", "" };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *inputparams,
  const char_T *identifier, struct0_T *y);
static const mxArray *c_emlrt_marshallOut(const boolean_T u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *testparams, const char_T *identifier);
static struct1_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fahrparams,
  const char_T *identifier, struct2_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_array_struct, const char_T *identifier, struct3_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[800]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct4_T *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv27[2];
  int32_T i20;
  for (i20 = 0; i20 < 2; i20++) {
    iv27[i20] = 1 + (i20 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv27);
  for (i20 = 0; i20 < 3; i20++) {
    ret[i20] = (*(real_T (*)[3])mxGetData(src))[i20];
  }

  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv21[1] = { 0 };

  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateNumericArray(1, iv21, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m8, (void *)u->data);
  emlrtSetDimensions((mxArray *)m8, u->size, 1);
  emlrtAssign(&y, m8);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100])
{
  int32_T iv28[1];
  int32_T i21;
  iv28[0] = 100;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv28);
  for (i21 = 0; i21 < 100; i21++) {
    ret[i21] = (*(real_T (*)[100])mxGetData(src))[i21];
  }

  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *inputparams,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(inputparams), &thisId, y);
  emlrtDestroyArray(&inputparams);
}

static const mxArray *c_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m9;
  y = NULL;
  m9 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m9);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[12] = { "disFlg", "wayStp", "engKinBegInx",
    "batEngStp", "batEngBeg", "batPwrAux", "psiBatEng", "psiTim",
    "staChgPenCosVal", "wayInxBeg", "wayInxEnd", "staBeg" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 12, fieldNames, 0U, 0);
  thisId.fIdentifier = "disFlg";
  y->disFlg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "disFlg")), &thisId);
  thisId.fIdentifier = "wayStp";
  y->wayStp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayStp")), &thisId);
  thisId.fIdentifier = "engKinBegInx";
  y->engKinBegInx = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "engKinBegInx")), &thisId);
  thisId.fIdentifier = "batEngStp";
  y->batEngStp = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngStp")), &thisId);
  thisId.fIdentifier = "batEngBeg";
  y->batEngBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngBeg")), &thisId);
  thisId.fIdentifier = "batPwrAux";
  y->batPwrAux = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrAux")), &thisId);
  thisId.fIdentifier = "psiBatEng";
  y->psiBatEng = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "psiBatEng")), &thisId);
  thisId.fIdentifier = "psiTim";
  y->psiTim = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "psiTim")), &thisId);
  thisId.fIdentifier = "staChgPenCosVal";
  y->staChgPenCosVal = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "staChgPenCosVal")), &thisId);
  thisId.fIdentifier = "wayInxBeg";
  y->wayInxBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayInxBeg")), &thisId);
  thisId.fIdentifier = "wayInxEnd";
  y->wayInxEnd = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayInxEnd")), &thisId);
  thisId.fIdentifier = "staBeg";
  y->staBeg = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staBeg")), &thisId);
  emlrtDestroyArray(&u);
}

static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *testparams, const char_T *identifier)
{
  struct1_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(testparams), &thisId);
  emlrtDestroyArray(&testparams);
  return y;
}

static struct1_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct1_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "staNum", "wayNum", "engKinNum" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "staNum";
  y.staNum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staNum")), &thisId);
  thisId.fIdentifier = "wayNum";
  y.wayNum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayNum")), &thisId);
  thisId.fIdentifier = "engKinNum";
  y.engKinNum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinNum")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fahrparams,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(sp, emlrtAlias(fahrparams), &thisId, y);
  emlrtDestroyArray(&fahrparams);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[16] = { "vehVelMin", "vehVelMax", "vehAccMax",
    "vehAccMin", "drgCof", "vehMas", "whlRosResCof", "whlDrr", "batRstChr",
    "batRstDch", "batEngMax", "batPwrMax", "batPwrMin", "geaEfy", "fulDen",
    "fulLhv" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 16, fieldNames, 0U, 0);
  thisId.fIdentifier = "vehVelMin";
  y->vehVelMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMin")), &thisId);
  thisId.fIdentifier = "vehVelMax";
  y->vehVelMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMax")), &thisId);
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
  thisId.fIdentifier = "batEngMax";
  y->batEngMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMax")), &thisId);
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
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_array_struct, const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  j_emlrt_marshallIn(sp, emlrtAlias(tst_array_struct), &thisId, y);
  emlrtDestroyArray(&tst_array_struct);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "slpVec_wayInx",
    "engKinMat_engKinInx_wayInx", "engKinNumVec_wayInx" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "slpVec_wayInx";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slpVec_wayInx")), &thisId, y->slpVec_wayInx);
  thisId.fIdentifier = "engKinMat_engKinInx_wayInx";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinMat_engKinInx_wayInx")), &thisId, y->engKinMat_engKinInx_wayInx);
  thisId.fIdentifier = "engKinNumVec_wayInx";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinNumVec_wayInx")), &thisId, y->engKinNumVec_wayInx);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[800])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  n_emlrt_marshallIn(sp, emlrtAlias(fzg_array_struct), &thisId, y);
  emlrtDestroyArray(&fzg_array_struct);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[16] = { "batOcvCof_batEng", "geaRat",
    "iceSpdMgd", "iceTrqMgd", "iceFulPwr_iceSpd_iceTrq", "iceTrqMaxCof",
    "iceTrqMinCof", "emoSpdMgd", "emoTrqMgd", "emoPwr_emoSpd_emoTrq",
    "emoTrqMin_emoSpd", "emoTrqMax_emoSpd", "emoPwrMgd", "emoTrq_emoSpd_emoPwr",
    "emoPwrMax_emoSpd", "emoPwrMin_emoSpd" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 16, fieldNames, 0U, 0);
  thisId.fIdentifier = "batOcvCof_batEng";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "geaRat";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "iceSpdMgd";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMaxCof")),
                     &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMinCof")),
                     &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                     &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                     &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                     &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800])
{
  int32_T iv22[1];
  int32_T i13;
  iv22[0] = 800;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv22);
  for (i13 = 0; i13 < 800; i13++) {
    ret[i13] = (*(real_T (*)[800])mxGetData(src))[i13];
  }

  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800])
{
  int32_T iv23[2];
  int32_T i14;
  int32_T i15;
  for (i14 = 0; i14 < 2; i14++) {
    iv23[i14] = 11 + 789 * i14;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv23);
  for (i14 = 0; i14 < 800; i14++) {
    for (i15 = 0; i15 < 11; i15++) {
      ret[i15 + 11 * i14] = (*(real_T (*)[8800])mxGetData(src))[i15 + 11 * i14];
    }
  }

  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv24[2];
  int32_T i16;
  for (i16 = 0; i16 < 2; i16++) {
    iv24[i16] = 1 + i16;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv24);
  for (i16 = 0; i16 < 2; i16++) {
    ret[i16] = (*(real_T (*)[2])mxGetData(src))[i16];
  }

  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv25[2];
  int32_T i17;
  for (i17 = 0; i17 < 2; i17++) {
    iv25[i17] = 1 + 5 * i17;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv25);
  for (i17 = 0; i17 < 6; i17++) {
    ret[i17] = (*(real_T (*)[6])mxGetData(src))[i17];
  }

  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000])
{
  int32_T iv26[2];
  int32_T i18;
  int32_T i19;
  for (i18 = 0; i18 < 2; i18++) {
    iv26[i18] = 150 + -50 * i18;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv26);
  for (i18 = 0; i18 < 100; i18++) {
    for (i19 = 0; i19 < 150; i19++) {
      ret[i19 + 150 * i18] = (*(real_T (*)[15000])mxGetData(src))[i19 + 150 *
        i18];
    }
  }

  emlrtDestroyArray(&src);
}

void clcDP_port_api(clcDP_portStackData *SD, const mxArray * const prhs[5],
                    const mxArray *plhs[7])
{
  emxArray_real_T *engKinOptVec;
  emxArray_real_T *batEngDltOptVec;
  emxArray_real_T *fulEngDltOptVec;
  emxArray_real_T *staVec;
  emxArray_real_T *psiEngKinOptVec;
  struct0_T inputparams;
  struct1_T testparams;
  struct2_T fahrparams;
  struct3_T tst_array_struct;
  boolean_T resVld;
  real_T fulEngOpt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInit_real_T(&st, &engKinOptVec, 1, &n_emlrtRTEI, true);
  c_emxInit_real_T(&st, &batEngDltOptVec, 1, &n_emlrtRTEI, true);
  c_emxInit_real_T(&st, &fulEngDltOptVec, 1, &n_emlrtRTEI, true);
  c_emxInit_real_T(&st, &staVec, 1, &n_emlrtRTEI, true);
  c_emxInit_real_T(&st, &psiEngKinOptVec, 1, &n_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "inputparams", &inputparams);
  testparams = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "testparams");
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "fahrparams", &fahrparams);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tst_array_struct",
                     &tst_array_struct);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "fzg_array_struct",
                     &SD->f0.fzg_array_struct);

  /* Invoke the target function */
  clcDP_port(&st, &inputparams, &testparams, &fahrparams, &tst_array_struct,
             &SD->f0.fzg_array_struct, engKinOptVec, batEngDltOptVec,
             fulEngDltOptVec, staVec, psiEngKinOptVec, &fulEngOpt, &resVld);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(engKinOptVec);
  plhs[1] = b_emlrt_marshallOut(batEngDltOptVec);
  plhs[2] = b_emlrt_marshallOut(fulEngDltOptVec);
  plhs[3] = b_emlrt_marshallOut(staVec);
  plhs[4] = b_emlrt_marshallOut(psiEngKinOptVec);
  plhs[5] = emlrt_marshallOut(fulEngOpt);
  plhs[6] = c_emlrt_marshallOut(resVld);
  psiEngKinOptVec->canFreeData = false;
  emxFree_real_T(&psiEngKinOptVec);
  staVec->canFreeData = false;
  emxFree_real_T(&staVec);
  fulEngDltOptVec->canFreeData = false;
  emxFree_real_T(&fulEngDltOptVec);
  batEngDltOptVec->canFreeData = false;
  emxFree_real_T(&batEngDltOptVec);
  engKinOptVec->canFreeData = false;
  emxFree_real_T(&engKinOptVec);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_clcDP_port_api.c) */
