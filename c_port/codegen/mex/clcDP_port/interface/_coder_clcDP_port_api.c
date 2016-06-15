/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_clcDP_port_api.c
 *
 * Code generation for function '_coder_clcDP_port_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "_coder_clcDP_port_api.h"
#include "clcDP_port_emxutil.h"
#include "fprintf.h"
#include "clcDP_port_mexutil.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, 1, "_coder_clcDP_port_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static const mxArray *c_emlrt_marshallOut(const boolean_T u);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv13[1] = { 0 };

  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateNumericArray(1, iv13, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m8, (void *)u->data);
  emlrtSetDimensions((mxArray *)m8, u->size, 1);
  emlrtAssign(&y, m8);
  return y;
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

void clcDP_port_api(clcDP_portStackData *SD, const mxArray * const prhs[11],
                    const mxArray *plhs[7])
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
  real_T staBeg;
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
  disFlg = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "disFlg");
  wayStp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "wayStp");
  batEngStp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "batEngStp");
  batEngBeg = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "batEngBeg");
  batPwrAux = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "batPwrAux");
  psiBatEng = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "psiBatEng");
  psiTim = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "psiTim");
  staChgPenCosVal = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]),
    "staChgPenCosVal");
  wayInxBeg = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "wayInxBeg");
  wayInxEnd = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "wayInxEnd");
  staBeg = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "staBeg");

  /* Invoke the target function */
  clcDP_port(SD, &st, disFlg, wayStp, batEngStp, batEngBeg, batPwrAux, psiBatEng,
             psiTim, staChgPenCosVal, wayInxBeg, wayInxEnd, staBeg, engKinOptVec,
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

/* End of code generation (_coder_clcDP_port_api.c) */
