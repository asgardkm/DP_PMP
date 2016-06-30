/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcDP_olyHyb_tmp_api.c
 *
 * Code generation for function '_coder_clcDP_olyHyb_tmp_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_olyHyb_tmp.h"
#include "_coder_clcDP_olyHyb_tmp_api.h"
#include "clcDP_olyHyb_tmp_emxutil.h"
#include "fprintf.h"
#include "clcDP_olyHyb_tmp_mexutil.h"
#include "clcDP_olyHyb_tmp_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo h_emlrtRTEI = { 1, 1, "_coder_clcDP_olyHyb_tmp_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *FZG, const
  char_T *identifier, struct0_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv5[2] = { 0, 0 };

  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u->data);
  emlrtSetDimensions((mxArray *)m2, u->size, 2);
  emlrtAssign(&y, m2);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(engKinNumVec_wayInx), &thisId, y);
  emlrtDestroyArray(&engKinNumVec_wayInx);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(sp, emlrtAlias(engKinMat_engKinInx_wayInx), &thisId, y);
  emlrtDestroyArray(&engKinMat_engKinInx_wayInx);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv4[3] = { 0, 0, 0 };

  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericArray(3, iv4, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u->data);
  emlrtSetDimensions((mxArray *)m1, u->size, 3);
  emlrtAssign(&y, m1);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *FZG, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(sp, emlrtAlias(FZG), &thisId, y);
  emlrtDestroyArray(&FZG);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[32] = { "vehVelMin", "vehVelMax", "vehAccMax",
    "vehAccMin", "drgCof", "vehMas", "whlRolResCof", "whlDrr", "batRstChr",
    "batRstDch", "batOcvCof_batEng", "batEngMax", "batPwrMax", "batPwrMin",
    "geaRat", "geaEfy", "iceSpdMgd", "iceTrqMgd", "fulDen", "fulLhv",
    "iceFulPwr_iceSpd_iceTrq", "iceTrqMaxCof", "iceTrqMinCof", "emoSpdMgd",
    "emoTrqMgd", "emoPwr_emoSpd_emoTrq", "emoTrqMin_emoSpd", "emoTrqMax_emoSpd",
    "emoPwrMgd", "emoTrq_emoSpd_emoPwr", "emoPwrMax_emoSpd", "emoPwrMin_emoSpd"
  };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 32, fieldNames, 0U, 0);
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
  thisId.fIdentifier = "whlRolResCof";
  y->whlRolResCof = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "whlRolResCof")), &thisId);
  thisId.fIdentifier = "whlDrr";
  y->whlDrr = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "whlDrr")), &thisId);
  thisId.fIdentifier = "batRstChr";
  y->batRstChr = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstChr")), &thisId);
  thisId.fIdentifier = "batRstDch";
  y->batRstDch = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstDch")), &thisId);
  thisId.fIdentifier = "batOcvCof_batEng";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "batEngMax";
  y->batEngMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMax")), &thisId);
  thisId.fIdentifier = "batPwrMax";
  y->batPwrMax = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMax")), &thisId);
  thisId.fIdentifier = "batPwrMin";
  y->batPwrMin = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMin")), &thisId);
  thisId.fIdentifier = "geaRat";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "geaEfy";
  y->geaEfy = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaEfy")), &thisId);
  thisId.fIdentifier = "iceSpdMgd";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "fulDen";
  y->fulDen = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulDen")), &thisId);
  thisId.fIdentifier = "fulLhv";
  y->fulLhv = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulLhv")), &thisId);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMaxCof")),
                     &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMinCof")),
                     &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                     &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                     &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                     &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv6[1];
  boolean_T bv0[1] = { true };

  static const int32_T iv7[1] = { -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv7, &bv0[0],
    iv6);
  ret->size[0] = iv6[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv8[2];
  int32_T i;
  int32_T iv9[2];
  boolean_T bv1[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv8[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv8, &bv1[0],
    iv9);
  ret->size[0] = iv9[0];
  ret->size[1] = iv9[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv10[2];
  int32_T i21;
  for (i21 = 0; i21 < 2; i21++) {
    iv10[i21] = 1 + i21;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv10);
  for (i21 = 0; i21 < 2; i21++) {
    ret[i21] = (*(real_T (*)[2])mxGetData(src))[i21];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv11[2];
  int32_T i22;
  int32_T iv12[2];
  boolean_T bv2[2] = { false, true };

  for (i22 = 0; i22 < 2; i22++) {
    iv11[i22] = 1 + -2 * i22;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv11, &bv2[0],
    iv12);
  i22 = ret->size[0] * ret->size[1];
  ret->size[0] = iv12[0];
  ret->size[1] = iv12[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i22, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000])
{
  int32_T iv13[2];
  int32_T i23;
  int32_T i24;
  for (i23 = 0; i23 < 2; i23++) {
    iv13[i23] = 150 + -50 * i23;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv13);
  for (i23 = 0; i23 < 100; i23++) {
    for (i24 = 0; i24 < 150; i24++) {
      ret[i24 + 150 * i23] = (*(real_T (*)[15000])mxGetData(src))[i24 + 150 *
        i23];
    }
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv14[2];
  int32_T i25;
  for (i25 = 0; i25 < 2; i25++) {
    iv14[i25] = 1 + (i25 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv14);
  for (i25 = 0; i25 < 3; i25++) {
    ret[i25] = (*(real_T (*)[3])mxGetData(src))[i25];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100])
{
  int32_T iv15[1];
  int32_T i26;
  iv15[0] = 100;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv15);
  for (i26 = 0; i26 < 100; i26++) {
    ret[i26] = (*(real_T (*)[100])mxGetData(src))[i26];
  }

  emlrtDestroyArray(&src);
}

void clcDP_olyHyb_tmp_api(clcDP_olyHyb_tmpStackData *SD, const mxArray * const
  prhs[19], const mxArray *plhs[4])
{
  emxArray_real_T *engKinNumVec_wayInx;
  emxArray_real_T *slpVec_wayInx;
  emxArray_real_T *engKinMat_engKinInx_wayInx;
  emxArray_real_T *optPreInxTn3;
  emxArray_real_T *batFrcOptTn3;
  emxArray_real_T *fulEngOptTn3;
  emxArray_real_T *cos2goActMat;
  real_T disFlg;
  real_T wayStp;
  real_T batEngStp;
  real_T batEngBeg;
  real_T batPwrAux;
  real_T psiBatEng;
  real_T psiTim;
  real_T staChgPenCosVal;
  real_T wayInxBeg;
  real_T wayInxEnd;
  real_T engKinBegInx;
  real_T engKinNum;
  real_T staNum;
  real_T wayNum;
  real_T staBeg;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_emxInit_real_T(&st, &engKinNumVec_wayInx, 1, &h_emlrtRTEI, true);
  b_emxInit_real_T(&st, &slpVec_wayInx, 1, &h_emlrtRTEI, true);
  emxInit_real_T(&st, &engKinMat_engKinInx_wayInx, 2, &h_emlrtRTEI, true);
  emxInitStruct_struct0_T(&st, &SD->f0.FZG, &h_emlrtRTEI, true);
  c_emxInit_real_T(&st, &optPreInxTn3, 3, &h_emlrtRTEI, true);
  c_emxInit_real_T(&st, &batFrcOptTn3, 3, &h_emlrtRTEI, true);
  c_emxInit_real_T(&st, &fulEngOptTn3, 3, &h_emlrtRTEI, true);
  emxInit_real_T(&st, &cos2goActMat, 2, &h_emlrtRTEI, true);

  /* Marshall function inputs */
  disFlg = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "disFlg");
  wayStp = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "wayStp");
  batEngStp = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "batEngStp");
  batEngBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "batEngBeg");
  batPwrAux = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "batPwrAux");
  psiBatEng = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "psiBatEng");
  psiTim = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "psiTim");
  staChgPenCosVal = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]),
    "staChgPenCosVal");
  wayInxBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "wayInxBeg");
  wayInxEnd = emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "wayInxEnd");
  engKinBegInx = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "engKinBegInx");
  engKinNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "engKinNum");
  staNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "staNum");
  wayNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "wayNum");
  staBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "staBeg");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "engKinNumVec_wayInx",
                     engKinNumVec_wayInx);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "slpVec_wayInx", slpVec_wayInx);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "engKinMat_engKinInx_wayInx",
                     engKinMat_engKinInx_wayInx);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "FZG", &SD->f0.FZG);

  /* Invoke the target function */
  clcDP_olyHyb_tmp(&st, disFlg, wayStp, batEngStp, batEngBeg, batPwrAux,
                   psiBatEng, psiTim, staChgPenCosVal, wayInxBeg, wayInxEnd,
                   engKinBegInx, engKinNum, staNum, wayNum, staBeg,
                   engKinNumVec_wayInx, slpVec_wayInx,
                   engKinMat_engKinInx_wayInx, &SD->f0.FZG, optPreInxTn3,
                   batFrcOptTn3, fulEngOptTn3, cos2goActMat);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(optPreInxTn3);
  plhs[1] = emlrt_marshallOut(batFrcOptTn3);
  plhs[2] = emlrt_marshallOut(fulEngOptTn3);
  plhs[3] = b_emlrt_marshallOut(cos2goActMat);
  cos2goActMat->canFreeData = false;
  emxFree_real_T(&cos2goActMat);
  fulEngOptTn3->canFreeData = false;
  emxFree_real_T(&fulEngOptTn3);
  batFrcOptTn3->canFreeData = false;
  emxFree_real_T(&batFrcOptTn3);
  optPreInxTn3->canFreeData = false;
  emxFree_real_T(&optPreInxTn3);
  emxFreeStruct_struct0_T(&SD->f0.FZG);
  engKinMat_engKinInx_wayInx->canFreeData = false;
  emxFree_real_T(&engKinMat_engKinInx_wayInx);
  slpVec_wayInx->canFreeData = false;
  emxFree_real_T(&slpVec_wayInx);
  engKinNumVec_wayInx->canFreeData = false;
  emxFree_real_T(&engKinNumVec_wayInx);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_clcDP_olyHyb_tmp_api.c) */
