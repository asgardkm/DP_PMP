/*
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "diff.h"
#include "clcDP_port_emxutil.h"
#include "clcOptTrj_port.h"
#include "eml_int_forloop_overflow_check.h"
#include "clcDP_port_mexutil.h"
#include "clcDP_port_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 108, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtRSInfo pb_emlrtRSI = { 106, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtMCInfo j_emlrtMCI = { 52, 9, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtMCInfo k_emlrtMCI = { 51, 19, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 1, 14, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 78, 1, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtRSInfo rb_emlrtRSI = { 51, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

static emlrtRSInfo ac_emlrtRSI = { 52, "diff",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"
};

/* Function Definitions */
void diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T i;
  boolean_T overflow;
  const mxArray *b_y;
  static const int32_T iv18[2] = { 1, 36 };

  const mxArray *m5;
  char_T cv23[36];
  static const char_T cv24[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  int32_T iyLead;
  real_T work_data_idx_0;
  int32_T m;
  real_T tmp1;
  real_T tmp2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  if (x->size[0] == 0) {
    i = y->size[0];
    y->size[0] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                      &l_emlrtRTEI);
  } else {
    i = x->size[0] - 1;
    if (muIntScalarMin_sint32(i, 1) < 1) {
      i = y->size[0];
      y->size[0] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                        &l_emlrtRTEI);
    } else {
      overflow = (x->size[0] != 1);
      if (overflow) {
      } else {
        b_y = NULL;
        m5 = emlrtCreateCharArray(2, iv18);
        for (i = 0; i < 36; i++) {
          cv23[i] = cv24[i];
        }

        emlrtInitCharArrayR2013a(sp, 36, m5, cv23);
        emlrtAssign(&b_y, m5);
        st.site = &rb_emlrtRSI;
        b_st.site = &ac_emlrtRSI;
        error(&st, b_message(&b_st, b_y, &j_emlrtMCI), &k_emlrtMCI);
      }

      i = y->size[0];
      y->size[0] = x->size[0] - 1;
      emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(real_T),
                        &m_emlrtRTEI);
      i = x->size[0] - 1;
      if (!(i == 0)) {
        i = 1;
        iyLead = 0;
        work_data_idx_0 = x->data[0];
        st.site = &pb_emlrtRSI;
        if (2 > x->size[0]) {
          overflow = false;
        } else {
          overflow = (x->size[0] > 2147483646);
        }

        if (overflow) {
          c_st.site = &v_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (m = 2; m <= x->size[0]; m++) {
          tmp1 = x->data[i];
          st.site = &ob_emlrtRSI;
          tmp2 = work_data_idx_0;
          work_data_idx_0 = tmp1;
          tmp1 -= tmp2;
          i++;
          y->data[iyLead] = tmp1;
          iyLead++;
        }
      }
    }
  }
}

/* End of code generation (diff.c) */
