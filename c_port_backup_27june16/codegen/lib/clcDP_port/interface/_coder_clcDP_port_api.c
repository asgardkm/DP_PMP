/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_clcDP_port_api.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_clcDP_port_api.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "clcDP_port",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *c_emlrt_marshallOut(const boolean_T u);
static struct1_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *testparams, const char_T *identifier);
static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *inputparams,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fahrparams,
  const char_T *identifier, struct2_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_array_struct, const char_T *identifier, struct3_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[800]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct4_T *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100]);
static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[100]
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[100])
{
  int32_T iv7[1];
  int32_T i8;
  iv7[0] = 100;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv7);
  for (i8 = 0; i8 < 100; i8++) {
    ret[i8] = (*(real_T (*)[100])mxGetData(src))[i8];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[12] = { "disFlg", "wayStp", "engKinBegInx",
    "batEngStp", "batEngBeg", "batPwrAux", "psiBatEng", "psiTim",
    "staChgPenCosVal", "wayInxBeg", "wayInxEnd", "staBeg" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 12, fieldNames, 0U, 0);
  thisId.fIdentifier = "disFlg";
  y->disFlg = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "disFlg")), &thisId);
  thisId.fIdentifier = "wayStp";
  y->wayStp = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayStp")), &thisId);
  thisId.fIdentifier = "engKinBegInx";
  y->engKinBegInx = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "engKinBegInx")), &thisId);
  thisId.fIdentifier = "batEngStp";
  y->batEngStp = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngStp")), &thisId);
  thisId.fIdentifier = "batEngBeg";
  y->batEngBeg = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngBeg")), &thisId);
  thisId.fIdentifier = "batPwrAux";
  y->batPwrAux = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrAux")), &thisId);
  thisId.fIdentifier = "psiBatEng";
  y->psiBatEng = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "psiBatEng")), &thisId);
  thisId.fIdentifier = "psiTim";
  y->psiTim = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "psiTim")), &thisId);
  thisId.fIdentifier = "staChgPenCosVal";
  y->staChgPenCosVal = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
    u, 0, "staChgPenCosVal")), &thisId);
  thisId.fIdentifier = "wayInxBeg";
  y->wayInxBeg = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayInxBeg")), &thisId);
  thisId.fIdentifier = "wayInxEnd";
  y->wayInxEnd = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayInxEnd")), &thisId);
  thisId.fIdentifier = "staBeg";
  y->staBeg = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staBeg")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const boolean_T u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *testparams
 *                const char_T *identifier
 * Return Type  : struct1_T
 */
static struct1_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *testparams, const char_T *identifier)
{
  struct1_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = e_emlrt_marshallIn(sp, emlrtAlias(testparams), &thisId);
  emlrtDestroyArray(&testparams);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : struct1_T
 */
static struct1_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct1_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "staNum", "wayNum", "engKinNum" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "staNum";
  y.staNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "staNum")), &thisId);
  thisId.fIdentifier = "wayNum";
  y.wayNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "wayNum")), &thisId);
  thisId.fIdentifier = "engKinNum";
  y.engKinNum = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinNum")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *inputparams
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *inputparams,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(inputparams), &thisId, y);
  emlrtDestroyArray(&inputparams);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *fahrparams
 *                const char_T *identifier
 *                struct2_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fahrparams,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  g_emlrt_marshallIn(sp, emlrtAlias(fahrparams), &thisId, y);
  emlrtDestroyArray(&fahrparams);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct2_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  thisId.fIdentifier = "whlRosResCof";
  y->whlRosResCof = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
    0, "whlRosResCof")), &thisId);
  thisId.fIdentifier = "whlDrr";
  y->whlDrr = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "whlDrr")), &thisId);
  thisId.fIdentifier = "batRstChr";
  y->batRstChr = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstChr")), &thisId);
  thisId.fIdentifier = "batRstDch";
  y->batRstDch = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batRstDch")), &thisId);
  thisId.fIdentifier = "batEngMax";
  y->batEngMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batEngMax")), &thisId);
  thisId.fIdentifier = "batPwrMax";
  y->batPwrMax = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMax")), &thisId);
  thisId.fIdentifier = "batPwrMin";
  y->batPwrMin = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batPwrMin")), &thisId);
  thisId.fIdentifier = "geaEfy";
  y->geaEfy = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "geaEfy")), &thisId);
  thisId.fIdentifier = "fulDen";
  y->fulDen = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulDen")), &thisId);
  thisId.fIdentifier = "fulLhv";
  y->fulLhv = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "fulLhv")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *tst_array_struct
 *                const char_T *identifier
 *                struct3_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tst_array_struct, const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  i_emlrt_marshallIn(sp, emlrtAlias(tst_array_struct), &thisId, y);
  emlrtDestroyArray(&tst_array_struct);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "slpVec_wayInx",
    "engKinMat_engKinInx_wayInx", "engKinNumVec_wayInx" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "slpVec_wayInx";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "slpVec_wayInx")), &thisId, y->slpVec_wayInx);
  thisId.fIdentifier = "engKinMat_engKinInx_wayInx";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinMat_engKinInx_wayInx")), &thisId, y->engKinMat_engKinInx_wayInx);
  thisId.fIdentifier = "engKinNumVec_wayInx";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "engKinNumVec_wayInx")), &thisId, y->engKinNumVec_wayInx);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[800]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[800])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[8800]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[8800])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *fzg_array_struct
 *                const char_T *identifier
 *                struct4_T *y
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *fzg_array_struct, const char_T *identifier, struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  m_emlrt_marshallIn(sp, emlrtAlias(fzg_array_struct), &thisId, y);
  emlrtDestroyArray(&fzg_array_struct);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct4_T *y
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
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
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "batOcvCof_batEng")), &thisId, y->batOcvCof_batEng);
  thisId.fIdentifier = "geaRat";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "geaRat")),
                     &thisId, y->geaRat);
  thisId.fIdentifier = "iceSpdMgd";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceSpdMgd")),
                     &thisId, y->iceSpdMgd);
  thisId.fIdentifier = "iceTrqMgd";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMgd")),
                     &thisId, y->iceTrqMgd);
  thisId.fIdentifier = "iceFulPwr_iceSpd_iceTrq";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "iceFulPwr_iceSpd_iceTrq")), &thisId, y->iceFulPwr_iceSpd_iceTrq);
  thisId.fIdentifier = "iceTrqMaxCof";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMaxCof")),
                     &thisId, y->iceTrqMaxCof);
  thisId.fIdentifier = "iceTrqMinCof";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "iceTrqMinCof")),
                     &thisId, y->iceTrqMinCof);
  thisId.fIdentifier = "emoSpdMgd";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoSpdMgd")),
                     &thisId, y->emoSpdMgd);
  thisId.fIdentifier = "emoTrqMgd";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoTrqMgd")),
                     &thisId, y->emoTrqMgd);
  thisId.fIdentifier = "emoPwr_emoSpd_emoTrq";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwr_emoSpd_emoTrq")), &thisId, y->emoPwr_emoSpd_emoTrq);
  thisId.fIdentifier = "emoTrqMin_emoSpd";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMin_emoSpd")), &thisId, y->emoTrqMin_emoSpd);
  thisId.fIdentifier = "emoTrqMax_emoSpd";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrqMax_emoSpd")), &thisId, y->emoTrqMax_emoSpd);
  thisId.fIdentifier = "emoPwrMgd";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "emoPwrMgd")),
                     &thisId, y->emoPwrMgd);
  thisId.fIdentifier = "emoTrq_emoSpd_emoPwr";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoTrq_emoSpd_emoPwr")), &thisId, y->emoTrq_emoSpd_emoPwr);
  thisId.fIdentifier = "emoPwrMax_emoSpd";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMax_emoSpd")), &thisId, y->emoPwrMax_emoSpd);
  thisId.fIdentifier = "emoPwrMin_emoSpd";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "emoPwrMin_emoSpd")), &thisId, y->emoPwrMin_emoSpd);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[2]
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[6]
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[15000]
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[15000])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[3]
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[100]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[100])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[800]
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[800])
{
  int32_T iv1[1];
  int32_T i0;
  iv1[0] = 800;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv1);
  for (i0 = 0; i0 < 800; i0++) {
    ret[i0] = (*(real_T (*)[800])mxGetData(src))[i0];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[8800]
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[8800])
{
  int32_T iv2[2];
  int32_T i1;
  int32_T i2;
  for (i1 = 0; i1 < 2; i1++) {
    iv2[i1] = 11 + 789 * i1;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv2);
  for (i1 = 0; i1 < 800; i1++) {
    for (i2 = 0; i2 < 11; i2++) {
      ret[i2 + 11 * i1] = (*(real_T (*)[8800])mxGetData(src))[i2 + 11 * i1];
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[2]
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  int32_T iv3[2];
  int32_T i3;
  for (i3 = 0; i3 < 2; i3++) {
    iv3[i3] = 1 + i3;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3);
  for (i3 = 0; i3 < 2; i3++) {
    ret[i3] = (*(real_T (*)[2])mxGetData(src))[i3];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[6]
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv4[2];
  int32_T i4;
  for (i4 = 0; i4 < 2; i4++) {
    iv4[i4] = 1 + 5 * i4;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv4);
  for (i4 = 0; i4 < 6; i4++) {
    ret[i4] = (*(real_T (*)[6])mxGetData(src))[i4];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[15000]
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[15000])
{
  int32_T iv5[2];
  int32_T i5;
  int32_T i6;
  for (i5 = 0; i5 < 2; i5++) {
    iv5[i5] = 150 + -50 * i5;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv5);
  for (i5 = 0; i5 < 100; i5++) {
    for (i6 = 0; i6 < 150; i6++) {
      ret[i6 + 150 * i5] = (*(real_T (*)[15000])mxGetData(src))[i6 + 150 * i5];
    }
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[3]
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  int32_T iv6[2];
  int32_T i7;
  for (i7 = 0; i7 < 2; i7++) {
    iv6[i7] = 1 + (i7 << 1);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv6);
  for (i7 = 0; i7 < 3; i7++) {
    ret[i7] = (*(real_T (*)[3])mxGetData(src))[i7];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                const mxArray *plhs[7]
 * Return Type  : void
 */
void clcDP_port_api(const mxArray * const prhs[5], const mxArray *plhs[7])
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
  static struct4_T fzg_array_struct;
  boolean_T resVld;
  real_T fulEngOpt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &engKinOptVec, 1, true);
  emxInit_real_T(&st, &batEngDltOptVec, 1, true);
  emxInit_real_T(&st, &fulEngDltOptVec, 1, true);
  emxInit_real_T(&st, &staVec, 1, true);
  emxInit_real_T(&st, &psiEngKinOptVec, 1, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "inputparams", &inputparams);
  testparams = d_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "testparams");
  f_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "fahrparams", &fahrparams);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tst_array_struct",
                     &tst_array_struct);
  l_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "fzg_array_struct",
                     &fzg_array_struct);

  /* Invoke the target function */
  clcDP_port(&inputparams, &testparams, &fahrparams, &tst_array_struct,
             &fzg_array_struct, engKinOptVec, batEngDltOptVec, fulEngDltOptVec,
             staVec, psiEngKinOptVec, &fulEngOpt, &resVld);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(engKinOptVec);
  plhs[1] = emlrt_marshallOut(batEngDltOptVec);
  plhs[2] = emlrt_marshallOut(fulEngDltOptVec);
  plhs[3] = emlrt_marshallOut(staVec);
  plhs[4] = emlrt_marshallOut(psiEngKinOptVec);
  plhs[5] = b_emlrt_marshallOut(fulEngOpt);
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

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcDP_port_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  clcDP_port_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcDP_port_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcDP_port_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_clcDP_port_api.c
 *
 * [EOF]
 */
