/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_clcOptTrj_tmp_api.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 09:35:30
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_clcOptTrj_tmp_api.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "clcOptTrj_tmp",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static void b_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier, emxArray_real_T *y);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *disFlg,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *optPreInxTn3, const char_T *identifier))[52800];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[52800];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *cos2goActMat, const char_T *identifier))[66];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[66];
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[52800];
static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[66];

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
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
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void b_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
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
 *                const mxArray *engKinNumVec_wayInx
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinNumVec_wayInx, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(engKinNumVec_wayInx), &thisId, y);
  emlrtDestroyArray(&engKinNumVec_wayInx);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *engKinMat_engKinInx_wayInx
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *engKinMat_engKinInx_wayInx, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(sp, emlrtAlias(engKinMat_engKinInx_wayInx), &thisId, y);
  emlrtDestroyArray(&engKinMat_engKinInx_wayInx);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *disFlg
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *disFlg,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(disFlg), &thisId);
  emlrtDestroyArray(&disFlg);
  return y;
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
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *optPreInxTn3
 *                const char_T *identifier
 * Return Type  : real_T (*)[52800]
 */
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *optPreInxTn3, const char_T *identifier))[52800]
{
  real_T (*y)[52800];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(optPreInxTn3), &thisId);
  emlrtDestroyArray(&optPreInxTn3);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[52800]
 */
  static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[52800]
{
  real_T (*y)[52800];
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *cos2goActMat
 *                const char_T *identifier
 * Return Type  : real_T (*)[66]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *cos2goActMat, const char_T *identifier))[66]
{
  real_T (*y)[66];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = j_emlrt_marshallIn(sp, emlrtAlias(cos2goActMat), &thisId);
  emlrtDestroyArray(&cos2goActMat);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[66]
 */
  static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[66]
{
  real_T (*y)[66];
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv1[1];
  boolean_T bv0[1] = { true };

  static const int32_T iv2[1] = { -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv2, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv3[2];
  int32_T i;
  int32_T iv4[2];
  boolean_T bv1[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv3[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3, &bv1[0],
    iv4);
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[52800]
 */
static real_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[52800]
{
  real_T (*ret)[52800];
  int32_T iv5[3];
  int32_T i;
  static const int16_T iv6[3] = { 11, 6, 800 };

  for (i = 0; i < 3; i++) {
    iv5[i] = iv6[i];
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv5);
  ret = (real_T (*)[52800])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[66]
 */
  static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[66]
{
  real_T (*ret)[66];
  int32_T iv7[2];
  int32_T i0;
  for (i0 = 0; i0 < 2; i0++) {
    iv7[i0] = 11 + -5 * i0;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv7);
  ret = (real_T (*)[66])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray *prhs[15]
 *                const mxArray *plhs[7]
 * Return Type  : void
 */
void clcOptTrj_tmp_api(const mxArray *prhs[15], const mxArray *plhs[7])
{
  emxArray_real_T *engKinNumVec_wayInx;
  emxArray_real_T *engKinMat_engKinInx_wayInx;
  emxArray_real_T *engKinOptVec;
  emxArray_real_T *batEngDltOptVec;
  emxArray_real_T *fulEngDltOptVec;
  emxArray_real_T *staVec;
  emxArray_real_T *psiEngKinOptVec;
  real_T disFlg;
  real_T wayStp;
  real_T wayNum;
  real_T wayInxBeg;
  real_T wayInxEnd;
  real_T staEnd;
  real_T engKinNum;
  real_T engKinEndInxVal;
  real_T staNum;
  real_T (*optPreInxTn3)[52800];
  real_T (*batFrcOptTn3)[52800];
  real_T (*fulEngOptTn3)[52800];
  real_T (*cos2goActMat)[66];
  real_T engKinEndInx;
  real_T fulEngOpt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &engKinNumVec_wayInx, 1, true);
  b_emxInit_real_T(&st, &engKinMat_engKinInx_wayInx, 2, true);
  emxInit_real_T(&st, &engKinOptVec, 1, true);
  emxInit_real_T(&st, &batEngDltOptVec, 1, true);
  emxInit_real_T(&st, &fulEngDltOptVec, 1, true);
  emxInit_real_T(&st, &staVec, 1, true);
  emxInit_real_T(&st, &psiEngKinOptVec, 1, true);
  prhs[9] = emlrtProtectR2012b(prhs[9], 9, false, -1);
  prhs[10] = emlrtProtectR2012b(prhs[10], 10, false, -1);
  prhs[11] = emlrtProtectR2012b(prhs[11], 11, false, -1);
  prhs[12] = emlrtProtectR2012b(prhs[12], 12, false, -1);
  prhs[13] = emlrtProtectR2012b(prhs[13], 13, false, -1);
  prhs[14] = emlrtProtectR2012b(prhs[14], 14, false, -1);

  /* Marshall function inputs */
  disFlg = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "disFlg");
  wayStp = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "wayStp");
  wayNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "wayNum");
  wayInxBeg = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "wayInxBeg");
  wayInxEnd = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "wayInxEnd");
  staEnd = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "staEnd");
  engKinNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "engKinNum");
  engKinEndInxVal = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]),
    "engKinEndInxVal");
  staNum = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "staNum");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "engKinNumVec_wayInx",
                     engKinNumVec_wayInx);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "engKinMat_engKinInx_wayInx",
                     engKinMat_engKinInx_wayInx);
  optPreInxTn3 = g_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "optPreInxTn3");
  batFrcOptTn3 = g_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "batFrcOptTn3");
  fulEngOptTn3 = g_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "fulEngOptTn3");
  cos2goActMat = i_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "cos2goActMat");

  /* Invoke the target function */
  clcOptTrj_tmp(disFlg, wayStp, wayNum, wayInxBeg, wayInxEnd, staEnd, engKinNum,
                engKinEndInxVal, staNum, engKinNumVec_wayInx,
                engKinMat_engKinInx_wayInx, *optPreInxTn3, *batFrcOptTn3,
                *fulEngOptTn3, *cos2goActMat, engKinOptVec, batEngDltOptVec,
                fulEngDltOptVec, staVec, psiEngKinOptVec, &fulEngOpt,
                &engKinEndInx);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(engKinOptVec);
  plhs[1] = emlrt_marshallOut(batEngDltOptVec);
  plhs[2] = emlrt_marshallOut(fulEngDltOptVec);
  plhs[3] = emlrt_marshallOut(staVec);
  plhs[4] = emlrt_marshallOut(psiEngKinOptVec);
  plhs[5] = b_emlrt_marshallOut(fulEngOpt);
  plhs[6] = b_emlrt_marshallOut(engKinEndInx);
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
  engKinMat_engKinInx_wayInx->canFreeData = false;
  emxFree_real_T(&engKinMat_engKinInx_wayInx);
  engKinNumVec_wayInx->canFreeData = false;
  emxFree_real_T(&engKinNumVec_wayInx);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcOptTrj_tmp_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  clcOptTrj_tmp_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void clcOptTrj_tmp_initialize(void)
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
void clcOptTrj_tmp_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_clcOptTrj_tmp_api.c
 *
 * [EOF]
 */
