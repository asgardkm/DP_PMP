#ifndef __c1_DP_PMP_MABX_2015a_h__
#define __c1_DP_PMP_MABX_2015a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_sL6LJlPlxhdTxZzXh5NTaQC

struct sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 /*struct_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_c1_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_c1_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct sL6LJlPlxhdTxZzXh5NTaQC c1_sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 /*typedef_c1_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef struct_s2ZbaXvEUNrYT7xzIq9i3vG
#define struct_s2ZbaXvEUNrYT7xzIq9i3vG

struct s2ZbaXvEUNrYT7xzIq9i3vG
{
  real_T vehVelMin;
  real_T vehVelMax;
  real_T vehAccMax;
  real_T vehAccMin;
  real_T drgCof;
  real_T vehMas;
  real_T whlRolResCof;
  real_T whlDrr;
  real_T batRstChr;
  real_T batRstDch;
  real_T batOcvCof_batEng[2];
  real_T batEngMax;
  real_T batPwrMax;
  real_T batPwrMin;
  real_T geaRat[6];
  real_T geaEfy;
  real_T iceSpdMgd[15000];
  real_T iceTrqMgd[15000];
  real_T fulDen;
  real_T fulLhv;
  real_T iceFulPwr_iceSpd_iceTrq[15000];
  real_T iceTrqMaxCof[3];
  real_T iceTrqMinCof[3];
  real_T emoSpdMgd[15000];
  real_T emoTrqMgd[15000];
  real_T emoPwr_emoSpd_emoTrq[15000];
  real_T emoTrqMin_emoSpd[100];
  real_T emoTrqMax_emoSpd[100];
  real_T emoPwrMgd[15000];
  real_T emoTrq_emoSpd_emoPwr[15000];
  real_T emoPwrMax_emoSpd[100];
  real_T emoPwrMin_emoSpd[100];
};

#endif                                 /*struct_s2ZbaXvEUNrYT7xzIq9i3vG*/

#ifndef typedef_c1_s2ZbaXvEUNrYT7xzIq9i3vG
#define typedef_c1_s2ZbaXvEUNrYT7xzIq9i3vG

typedef struct s2ZbaXvEUNrYT7xzIq9i3vG c1_s2ZbaXvEUNrYT7xzIq9i3vG;

#endif                                 /*typedef_c1_s2ZbaXvEUNrYT7xzIq9i3vG*/

#ifndef typedef_SFc1_DP_PMP_MABX_2015aInstanceStruct
#define typedef_SFc1_DP_PMP_MABX_2015aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_DP_PMP_MABX_2015a;
  real_T c1_engKinNum;
  real_T c1_staNum;
  real_T c1_wayNum;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_FZG;
  real_T c1_geaNum;
  boolean_T c1_geaNum_not_empty;
  real_T c1_vehMas;
  boolean_T c1_vehMas_not_empty;
  real_T c1_vehAccMin;
  boolean_T c1_vehAccMin_not_empty;
  real_T c1_vehAccMax;
  boolean_T c1_vehAccMax_not_empty;
  boolean_T c1_iceFlg;
  boolean_T c1_iceFlg_not_empty;
  real_T c1_crsSpdHybMax;
  boolean_T c1_crsSpdHybMax_not_empty;
  real_T c1_crsSpdHybMin;
  boolean_T c1_crsSpdHybMin_not_empty;
  real_T c1_crsSpdEmoMax;
  boolean_T c1_crsSpdEmoMax_not_empty;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_b_FZG;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_c_FZG;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_d_FZG;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_par;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_b_par;
  real_T c1_optPreInxTn3[52800];
  real_T c1_batFrcOptTn3[52800];
  real_T c1_fulEngOptTn3[52800];
  real_T c1_b_fulEngOptTn3[52800];
  real_T c1_b_batFrcOptTn3[52800];
  real_T c1_b_optPreInxTn3[52800];
  real_T c1_c_optPreInxTn3[52800];
  real_T c1_c_batFrcOptTn3[52800];
  real_T c1_c_fulEngOptTn3[52800];
  real_T c1_c_par[15000];
  real_T c1_d_par[15000];
  real_T c1_e_par[15000];
  real_T c1_f_par[15000];
  real_T c1_g_par[15000];
  real_T c1_h_par[15000];
  real_T c1_engKinMat_engKinInx_wayInx[8800];
  real_T c1_b_engKinMat_engKinInx_wayInx[8800];
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_u;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_y;
  c1_s2ZbaXvEUNrYT7xzIq9i3vG c1_r0;
  real_T c1_i_par[15000];
  real_T c1_j_par[15000];
  real_T c1_k_par[15000];
  real_T c1_l_par[15000];
  real_T c1_m_par[15000];
  real_T c1_n_par[15000];
  real_T c1_b_y[52800];
  real_T c1_dv12[52800];
  real_T c1_b_u[52800];
  real_T c1_c_y[15000];
  int8_T *c1_trigger_calculation;
  real_T *c1_disFlg;
  real_T *c1_wayStp;
  real_T *c1_batEngStp;
  real_T *c1_batEngBeg;
  real_T *c1_batPwrAux;
  real_T *c1_psiBatEng;
  real_T *c1_psiTim;
  real_T *c1_unused;
  real_T *c1_staChgPenCosVal;
  real_T *c1_wayInxBeg;
  real_T *c1_wayInxEnd;
  real_T *c1_staBeg;
  real_T (*c1_engKinNumVec_wayInx)[800];
  real_T (*c1_slpVec_wayInx)[800];
  real_T (*c1_c_engKinMat_engKinInx_wayInx)[8800];
  real_T (*c1_engKinOptVec)[800];
  real_T (*c1_batEngDltOptVec)[800];
  real_T (*c1_fulEngDltOptVec)[800];
  real_T (*c1_staVec)[800];
  real_T (*c1_psiEngKinOptVec)[800];
  real_T *c1_fulEngOpt;
  boolean_T *c1_resVld;
} SFc1_DP_PMP_MABX_2015aInstanceStruct;

#endif                                 /*typedef_SFc1_DP_PMP_MABX_2015aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_DP_PMP_MABX_2015a_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_DP_PMP_MABX_2015a_get_check_sum(mxArray *plhs[]);
extern void c1_DP_PMP_MABX_2015a_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
