/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * clcDP_port.c
 *
 * Code generation for function 'clcDP_port'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "clcDP_port_emxutil.h"
#include "fprintf.h"
#include "clcOptTrj_port.h"
#include "clcDP_olyHyb_port.h"
#include "clcDP_port_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 25, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo b_emlrtRSI = { 66, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo c_emlrtRSI = { 68, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo d_emlrtRSI = { 69, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo e_emlrtRSI = { 101, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo f_emlrtRSI = { 134, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtMCInfo emlrtMCI = { 28, 7, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtMCInfo b_emlrtMCI = { 36, 13, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRTEInfo emlrtRTEI = { 10, 5, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtDCInfo emlrtDCI = { 97, 24, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m", 1 };

static emlrtBCInfo emlrtBCI = { 1, 800, 97, 24, "engKinNumVec_wayInx",
  "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m", 0 };

static emlrtRSInfo tb_emlrtRSI = { 36, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

static emlrtRSInfo ub_emlrtRSI = { 28, "clcDP_port",
  "C:\\Users\\s0032360\\Documents\\GitHub\\DP_PMP\\c_port\\clcDP_port.m" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_load, const
  char_T *identifier, struct_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_load,
  const char_T *identifier, b_struct_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[800]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800]);
static const mxArray *load(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct_T *y)
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
  y->vehVelMin = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMin")), &thisId);
  thisId.fIdentifier = "vehVelMax";
  y->vehVelMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehVelMax")), &thisId);
  thisId.fIdentifier = "vehAccMax";
  y->vehAccMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehAccMax")), &thisId);
  thisId.fIdentifier = "vehAccMin";
  y->vehAccMin = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehAccMin")), &thisId);
  thisId.fIdentifier = "drgCof";
  y->drgCof = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "drgCof")), &thisId);
  thisId.fIdentifier = "vehMas";
  y->vehMas = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "vehMas")), &thisId);
  thisId.fIdentifier = "whlRolResCof";
  y->whlRolResCof = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "whlRolResCof")), &thisId);
  thisId.fIdentifier = "whlDrr";
  y->whlDrr = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "whlDrr")), &thisId);
  thisId.fIdentifier = "batRstChr";
  y->batRstChr = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstChr")), &thisId);
  thisId.fIdentifier = "batRstDch";
  y->batRstDch = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstDch")), &thisId);
  thisId.fIdentifier = "batOcvCof_batEng";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "batEngMax";
  y->batEngMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMax")), &thisId);
  thisId.fIdentifier = "batPwrMax";
  y->batPwrMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMax")), &thisId);
  thisId.fIdentifier = "batPwrMin";
  y->batPwrMin = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMin")), &thisId);
  thisId.fIdentifier = "geaRat";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "geaEfy";
  y->geaEfy = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaEfy")), &thisId);
  thisId.fIdentifier = "iceSpdMgd";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "fulDen";
  y->fulDen = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulDen")), &thisId);
  thisId.fIdentifier = "fulLhv";
  y->fulLhv = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulLhv")), &thisId);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMaxCof")),
                     &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMinCof")),
                     &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                     &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                     &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                     &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_load, const
  char_T *identifier, struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(b_load), &thisId, y);
  emlrtDestroyArray(&b_load);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_load,
  const char_T *identifier, b_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  j_emlrt_marshallIn(sp, emlrtAlias(b_load), &thisId, y);
  emlrtDestroyArray(&b_load);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, b_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[6] = { "staNum", "wayNum", "engKinNum",
    "slpVec_wayInx", "engKinMat_engKinInx_wayInx", "engKinNumVec_wayInx" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, 0);
  thisId.fIdentifier = "staNum";
  y->staNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staNum")), &thisId);
  thisId.fIdentifier = "wayNum";
  y->wayNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayNum")), &thisId);
  thisId.fIdentifier = "engKinNum";
  y->engKinNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinNum")), &thisId);
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
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *load(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m10;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 1, &pArray, "load", true, location);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv14[2];
  int32_T i58;
  for (i58 = 0; i58 < 2; i58++) {
    iv14[i58] = 1 + i58;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv14);
  for (i58 = 0; i58 < 2; i58++) {
    ret[i58] = (*(real_T (*)[2])mxGetData(src))[i58];
  }

  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv15[2];
  int32_T i59;
  for (i59 = 0; i59 < 2; i59++) {
    iv15[i59] = 1 + 5 * i59;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv15);
  for (i59 = 0; i59 < 6; i59++) {
    ret[i59] = (*(real_T (*)[6])mxGetData(src))[i59];
  }

  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000])
{
  int32_T iv16[2];
  int32_T i60;
  int32_T i61;
  for (i60 = 0; i60 < 2; i60++) {
    iv16[i60] = 150 + -50 * i60;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv16);
  for (i60 = 0; i60 < 100; i60++) {
    for (i61 = 0; i61 < 150; i61++) {
      ret[i61 + 150 * i60] = (*(real_T (*)[15000])mxGetData(src))[i61 + 150 *
        i60];
    }
  }

  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv17[2];
  int32_T i62;
  for (i62 = 0; i62 < 2; i62++) {
    iv17[i62] = 1 + (i62 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv17);
  for (i62 = 0; i62 < 3; i62++) {
    ret[i62] = (*(real_T (*)[3])mxGetData(src))[i62];
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100])
{
  int32_T iv18[1];
  int32_T i63;
  iv18[0] = 100;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv18);
  for (i63 = 0; i63 < 100; i63++) {
    ret[i63] = (*(real_T (*)[100])mxGetData(src))[i63];
  }

  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800])
{
  int32_T iv19[1];
  int32_T i64;
  iv19[0] = 800;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv19);
  for (i64 = 0; i64 < 800; i64++) {
    ret[i64] = (*(real_T (*)[800])mxGetData(src))[i64];
  }

  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800])
{
  int32_T iv20[2];
  int32_T i65;
  int32_T i66;
  for (i65 = 0; i65 < 2; i65++) {
    iv20[i65] = 11 + 789 * i65;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv20);
  for (i65 = 0; i65 < 800; i65++) {
    for (i66 = 0; i66 < 11; i66++) {
      ret[i66 + 11 * i65] = (*(real_T (*)[8800])mxGetData(src))[i66 + 11 * i65];
    }
  }

  emlrtDestroyArray(&src);
}

void clcDP_port(clcDP_portStackData *SD, const emlrtStack *sp, real_T disFlg,
                real_T wayStp, real_T batEngStp, real_T batEngBeg, real_T
                batPwrAux, real_T psiBatEng, real_T psiTim, real_T
                staChgPenCosVal, real_T wayInxBeg, real_T wayInxEnd, real_T
                staBeg, emxArray_real_T *engKinOptVec, emxArray_real_T
                *batEngDltOptVec, emxArray_real_T *fulEngDltOptVec,
                emxArray_real_T *staVec, emxArray_real_T *psiEngKinOptVec,
                real_T *fulEngOpt, boolean_T *resVld)
{
  const mxArray *y;
  const mxArray *m0;
  const mxArray *b_y;
  real_T tstDat800_slpVec_wayInx[800];
  int32_T i;
  real_T c_tstDat800_engKinMat_engKinInx[8800];
  real_T tstDat800_engKinNumVec_wayInx[800];
  int32_T trueCount;
  boolean_T bv0[15000];
  boolean_T b0;
  int32_T partialTrueCount;
  int16_T tmp_data[15000];
  emxArray_real_T *optPreInxTn3;
  emxArray_real_T *batFrcOptTn3;
  emxArray_real_T *fulEngOptTn3;
  emxArray_real_T *cos2goActMat;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*             --- Ausgangsgrößen: */
  /*  Vektor - Trajektorie der optimalen kin. Energien */
  /*  Vektor - optimale Batterieenergieänderung */
  /*  Vektor - optimale Kraftstoffenergieänderung */
  /*  Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*  Vektor - costate für kinetische Energie */
  /*  Skalar - optimale Kraftstoffenergie */
  /* % Laden der Modelldaten */
  /*  cd('C:\Users\s0032360\Documents\GitHub\DP_PMP\c_port'); */
  st.site = &emlrtRSI;
  b_fprintf(&st);

  /*  saved structure data from './model data' */
  y = NULL;
  m0 = emlrtCreateString("vehMdl");
  emlrtAssign(&y, m0);
  st.site = &ub_emlrtRSI;
  emlrt_marshallIn(&st, load(&st, y, &emlrtMCI), "load", &SD->f0.FZG);

  /*  % Inhalt des Parameter-Structs par in den Workspace schreiben */
  /*   -- Inahlt = Content */
  /*  input dummy engKinBegInx value for function */
  b_y = NULL;
  m0 = emlrtCreateString("tstDat800");
  emlrtAssign(&b_y, m0);
  st.site = &tb_emlrtRSI;
  i_emlrt_marshallIn(&st, load(&st, b_y, &b_emlrtMCI), "load", &SD->f0.expl_temp);
  for (i = 0; i < 800; i++) {
    tstDat800_slpVec_wayInx[i] = SD->f0.expl_temp.slpVec_wayInx[i];
  }

  for (i = 0; i < 8800; i++) {
    c_tstDat800_engKinMat_engKinInx[i] =
      SD->f0.expl_temp.engKinMat_engKinInx_wayInx[i];
  }

  for (i = 0; i < 800; i++) {
    tstDat800_engKinNumVec_wayInx[i] = SD->f0.expl_temp.engKinNumVec_wayInx[i];
  }

  /*  Löschen von inf und NaN aus Modelldaten */
  /*  ^^ replace any infinities and Nans with zeros */
  /*  && löschen = delete */
  trueCount = 0;
  for (i = 0; i < 15000; i++) {
    b0 = muDoubleScalarIsInf(SD->f0.FZG.emoTrq_emoSpd_emoPwr[i]);
    if (b0) {
      trueCount++;
    }

    bv0[i] = b0;
  }

  partialTrueCount = 0;
  for (i = 0; i < 15000; i++) {
    if (bv0[i]) {
      tmp_data[partialTrueCount] = (int16_T)(i + 1);
      partialTrueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    SD->f0.FZG.emoTrq_emoSpd_emoPwr[tmp_data[i] - 1] = 0.0;
  }

  emxInit_real_T(sp, &optPreInxTn3, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &batFrcOptTn3, 3, &emlrtRTEI, true);
  emxInit_real_T(sp, &fulEngOptTn3, 3, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &cos2goActMat, 2, &emlrtRTEI, true);

  /*  % load in data from text file (if running model through matlab and are  */
  /*  % ignoring simulink (mainConfig.txt) */
  /*  inputparams = readConfig_port('mainConfig.txt'); */
  /*  inputparams = load('inputparams'); */
  /*  %  */
  /*  % % asign values from struct */
  /*  disFlg          = inputparams.disFlg; */
  /*  wayStp          = inputparams.wayStp; */
  /*  batEngStp       = inputparams.batEngStp; */
  /*  batEngBeg       = inputparams.batEngBeg; */
  /*  batPwrAux       = inputparams.batPwrAux; */
  /*  psiBatEng       = inputparams.psiBatEng; */
  /*  psiTim          = inputparams.psiTim; */
  /*  staChgPenCosVal = inputparams.staChgPenCosVal; */
  /*  wayInxBeg       = inputparams.wayInxBeg; */
  /*  wayInxEnd       = inputparams.wayInxEnd; */
  /*  staBeg          = inputparams.staBeg; */
  st.site = &b_emlrtRSI;
  d_fprintf(&st);

  /* % Calculating optimal predecessors with DP + PMP */
  st.site = &c_emlrtRSI;
  f_fprintf(&st);

  /*  --- Ausgangsgrößen: */
  /*    Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
  /*      FUNKTION */
  /*                --- Eingangsgrößen: */
  /*          Skalar - Flag für Ausgabe in das Commandwindow */
  /*           Skalar für die Wegschrittweite in m */
  /*        Skalar der Batteriediskretisierung in J */
  /*        Skalar für die Batterieenergie am Beginn in Ws */
  /*        Skalar für die Nebenverbrauchlast in W */
  /*        Skalar für den Co-State der Batterieenergie */
  /*           Skalar für den Co-State der Zeit */
  /*  Skalar für die Strafkosten beim Zustandswechsel */
  /*        Skalar für Anfangsindex in den Eingangsdaten */
  /*        Skalar für Endindex in den Eingangsdaten */
  /*     Skalar für den Index der Anfangsgeschwindigkeit */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*           Skalar für die max. Anzahl an Wegstützstellen */
  /*           Skalar für den Startzustand des Antriebsstrangs */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*    Vektor der Steigungen in rad */
  /*  Matrix der kinetischen Energien in J */
  /*               struct der Fahrzeugparameter */
  st.site = &d_emlrtRSI;
  clcDP_olyHyb_port(&st, disFlg, wayStp, batEngStp, batEngBeg, batPwrAux,
                    psiBatEng, psiTim, staChgPenCosVal, wayInxBeg, wayInxEnd,
                    SD->f0.expl_temp.wayNum, SD->f0.expl_temp.staNum,
                    SD->f0.expl_temp.wayNum, staBeg,
                    tstDat800_engKinNumVec_wayInx, tstDat800_slpVec_wayInx,
                    c_tstDat800_engKinMat_engKinInx, &SD->f0.FZG, optPreInxTn3,
                    batFrcOptTn3, fulEngOptTn3, cos2goActMat);
  if (wayInxEnd == (int32_T)muDoubleScalarFloor(wayInxEnd)) {
    i = (int32_T)wayInxEnd;
  } else {
    i = (int32_T)emlrtIntegerCheckR2012b(wayInxEnd, &emlrtDCI, sp);
  }

  emlrtDynamicBoundsCheckR2012b(i, 1, 800, &emlrtBCI, sp);

  /* % Calculating optimal trajectories for result of DP + PMP */
  /*        Vektor - Trajektorie der optimalen kin. Energien */
  /* Vektor - optimale Batterieenergieänderung */
  /*  Vektor - optimale Kraftstoffenergieänderung */
  /*           Vektor - Trajektorie des optimalen Antriebsstrangzustands */
  /*  Vektor - costate für kinetische Energie */
  /*        Skalar - optimale Kraftstoffenergie */
  /*         FUNKTION */
  /*           Flag, ob Zielzustand genutzt werden muss */
  /*           Skalar für die Wegschrittweite in m */
  /*           Skalar für die max. Anzahl an Wegstützstellen */
  /*        Skalar für Anfangsindex in den Eingangsdaten */
  /*        Skalar für Endindex in den Eingangsdaten */
  /*           Skalar für den finalen Zustand */
  /*        Skalar für die max. Anz. an engKin-Stützstellen */
  /*  Skalar für Zielindex der kinetischen Energie */
  /*           Skalar für die max. Anzahl an Zustandsstützstellen */
  /*  Vektor der Anzahl der kinetischen Energien */
  /*  Matrix der kinetischen Energien in J */
  /*     Tensor 3. Stufe für opt. Vorgängerkoordinaten */
  /*    Tensor 3. Stufe der Batteriekraft */
  /*    Tensor 3. Stufe für die Kraftstoffenergie */
  /*     Matrix der optimalen Kosten der Hamiltonfunktion */
  st.site = &e_emlrtRSI;
  clcOptTrj_port(&st, wayStp, SD->f0.expl_temp.wayNum, wayInxBeg, wayInxEnd,
                 SD->f0.expl_temp.wayNum, SD->f0.expl_temp.staNum,
                 tstDat800_engKinNumVec_wayInx, c_tstDat800_engKinMat_engKinInx,
                 optPreInxTn3, batFrcOptTn3, fulEngOptTn3, cos2goActMat,
                 engKinOptVec, batEngDltOptVec, fulEngDltOptVec, staVec,
                 psiEngKinOptVec, fulEngOpt);

  /*  engKinOptVec=0; */
  /*  batEngDltOptVec=0; */
  /*  fulEngDltOptVec=0; */
  /*  staVec=0; */
  /*  psiEngKinOptVec=0; */
  /*  fulEngOpt=0; */
  *resVld = true;
  st.site = &f_emlrtRSI;
  j_fprintf(&st);
  emxFree_real_T(&cos2goActMat);
  emxFree_real_T(&fulEngOptTn3);
  emxFree_real_T(&batFrcOptTn3);
  emxFree_real_T(&optPreInxTn3);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (clcDP_port.c) */
