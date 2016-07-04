/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcDP_tmp_api.c
 *
 * Code generation for function '_coder_clcDP_tmp_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_tmp.h"
#include "_coder_clcDP_tmp_api.h"
#include "fprintf.h"
#include "clcDP_tmp_emxutil.h"
#include "clcDP_tmp_mexutil.h"
#include "clcDP_tmp_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, 1, "_coder_clcDP_tmp_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier))[800];
static const mxArray *c_emlrt_marshallOut(const boolean_T u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[800];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier))[8800];
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8800];
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *FZG, const
  char_T *identifier, struct0_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100]);
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[800];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8800];
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
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
  static const int32_T iv9[1] = { 0 };

  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u->data);
  emlrtSetDimensions((mxArray *)m5, u->size, 1);
  emlrtAssign(&y, m5);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier))[800]
{
  real_T (*y)[800];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(engKinNumVec_wayInx), &thisId);
  emlrtDestroyArray(&engKinNumVec_wayInx);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m6;
  y = NULL;
  m6 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m6);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[800]
{
  real_T (*y)[800];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier))[8800]
{
  real_T (*y)[8800];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(engKinMat_engKinInx_wayInx), &thisId);
  emlrtDestroyArray(&engKinMat_engKinInx_wayInx);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8800]
{
  real_T (*y)[8800];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
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
  emlrtMsgIdentifier *parentId, real_T y[6])
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

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[800]
{
  real_T (*ret)[800];
  int32_T iv10[1];
  iv10[0] = 800;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv10);
  ret = (real_T (*)[800])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8800]
{
  real_T (*ret)[8800];
  int32_T iv11[2];
  int32_T i57;
  for (i57 = 0; i57 < 2; i57++) {
    iv11[i57] = 11 + 789 * i57;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv11);
  ret = (real_T (*)[8800])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv12[2];
  int32_T i58;
  for (i58 = 0; i58 < 2; i58++) {
    iv12[i58] = 1 + i58;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv12);
  for (i58 = 0; i58 < 2; i58++) {
    ret[i58] = (*(real_T (*)[2])mxGetData(src))[i58];
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv13[2];
  int32_T i59;
  for (i59 = 0; i59 < 2; i59++) {
    iv13[i59] = 1 + 5 * i59;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv13);
  for (i59 = 0; i59 < 6; i59++) {
    ret[i59] = (*(real_T (*)[6])mxGetData(src))[i59];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000])
{
  int32_T iv14[2];
  int32_T i60;
  int32_T i61;
  for (i60 = 0; i60 < 2; i60++) {
    iv14[i60] = 150 + -50 * i60;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv14);
  for (i60 = 0; i60 < 100; i60++) {
    for (i61 = 0; i61 < 150; i61++) {
      ret[i61 + 150 * i60] = (*(real_T (*)[15000])mxGetData(src))[i61 + 150 *
        i60];
    }
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv15[2];
  int32_T i62;
  for (i62 = 0; i62 < 2; i62++) {
    iv15[i62] = 1 + (i62 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv15);
  for (i62 = 0; i62 < 3; i62++) {
    ret[i62] = (*(real_T (*)[3])mxGetData(src))[i62];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100])
{
  int32_T iv16[1];
  int32_T i63;
  iv16[0] = 100;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv16);
  for (i63 = 0; i63 < 100; i63++) {
    ret[i63] = (*(real_T (*)[100])mxGetData(src))[i63];
  }

  emlrtDestroyArray(&src);
}

void clcDP_tmp_api(clcDP_tmpStackData *SD, const mxArray * const prhs[18], const
                   mxArray *plhs[7])
{
  emxArray_real_T *engKinOptVec;
  emxArray_real_T *batEngDltOptVec;
  emxArray_real_T *fulEngDltOptVec;
  emxArray_real_T *staVec;
  emxArray_real_T *psiEngKinOptVec;
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
  real_T engKinNum;
  real_T staNum;
  real_T wayNum;
  real_T staBeg;
  real_T (*engKinNumVec_wayInx)[800];
  real_T (*slpVec_wayInx)[800];
  real_T (*engKinMat_engKinInx_wayInx)[8800];
  boolean_T resVld;
  real_T fulEngOpt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInit_real_T(&st, &engKinOptVec, 1, &l_emlrtRTEI, true);
  c_emxInit_real_T(&st, &batEngDltOptVec, 1, &l_emlrtRTEI, true);
  c_emxInit_real_T(&st, &fulEngDltOptVec, 1, &l_emlrtRTEI, true);
  c_emxInit_real_T(&st, &staVec, 1, &l_emlrtRTEI, true);
  c_emxInit_real_T(&st, &psiEngKinOptVec, 1, &l_emlrtRTEI, true);

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
  engKinNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "engKinNum");
  staNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "staNum");
  wayNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "wayNum");
  staBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "staBeg");
  engKinNumVec_wayInx = c_emlrt_marshallIn(&st, emlrtAlias(prhs[14]),
    "engKinNumVec_wayInx");
  slpVec_wayInx = c_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "slpVec_wayInx");
  engKinMat_engKinInx_wayInx = e_emlrt_marshallIn(&st, emlrtAlias(prhs[16]),
    "engKinMat_engKinInx_wayInx");
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "FZG", &SD->f0.FZG);

  /* Invoke the target function */
  clcDP_tmp(&st, disFlg, wayStp, batEngStp, batEngBeg, batPwrAux, psiBatEng,
            psiTim, staChgPenCosVal, wayInxBeg, wayInxEnd, engKinNum, staNum,
            wayNum, staBeg, *engKinNumVec_wayInx, *slpVec_wayInx,
            *engKinMat_engKinInx_wayInx, &SD->f0.FZG, engKinOptVec,
            batEngDltOptVec, fulEngDltOptVec, staVec, psiEngKinOptVec,
            &fulEngOpt, &resVld);

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

/* End of code generation (_coder_clcDP_tmp_api.c) */
