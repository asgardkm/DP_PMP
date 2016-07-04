/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jun-2016 09:35:30
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "clcOptTrj_tmp.h"
#include "main.h"
#include "clcOptTrj_tmp_terminate.h"
#include "clcOptTrj_tmp_emxAPI.h"
#include "clcOptTrj_tmp_initialize.h"

/* Function Declarations */
static void argInit_11x6_real_T(double result[66]);
static void argInit_11x6x800_real_T(double result[52800]);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static double argInit_real_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_clcOptTrj_tmp(void);

/* Function Definitions */

/*
 * Arguments    : double result[66]
 * Return Type  : void
 */
static void argInit_11x6_real_T(double result[66])
{
  int b_j0;
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 11; b_j0++) {
    for (b_j1 = 0; b_j1 < 6; b_j1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[b_j0 + 11 * b_j1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[52800]
 * Return Type  : void
 */
static void argInit_11x6x800_real_T(double result[52800])
{
  int b_j0;
  int b_j1;
  int j2;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 11; b_j0++) {
    for (b_j1 = 0; b_j1 < 6; b_j1++) {
      for (j2 = 0; j2 < 800; j2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result[(b_j0 + 11 * b_j1) + 66 * j2] = argInit_real_T();
      }
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int b_j0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv0);

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[b_j0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  static int iv1[2] = { 2, 2 };

  int b_j0;
  int b_j1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv1);

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[b_j0 + result->size[0] * b_j1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_clcOptTrj_tmp(void)
{
  emxArray_real_T *engKinOptVec;
  emxArray_real_T *batEngDltOptVec;
  emxArray_real_T *fulEngDltOptVec;
  emxArray_real_T *staVec;
  emxArray_real_T *psiEngKinOptVec;
  double disFlg;
  double wayStp;
  double wayNum;
  double wayInxBeg;
  double wayInxEnd;
  double staEnd;
  double engKinNum;
  double engKinEndInxVal;
  double staNum;
  emxArray_real_T *engKinNumVec_wayInx;
  emxArray_real_T *engKinMat_engKinInx_wayInx;
  static double dv0[52800];
  static double dv1[52800];
  static double dv2[52800];
  double dv3[66];
  double engKinEndInx;
  double fulEngOpt;
  emxInitArray_real_T(&engKinOptVec, 1);
  emxInitArray_real_T(&batEngDltOptVec, 1);
  emxInitArray_real_T(&fulEngDltOptVec, 1);
  emxInitArray_real_T(&staVec, 1);
  emxInitArray_real_T(&psiEngKinOptVec, 1);

  /* Initialize function 'clcOptTrj_tmp' input arguments. */
  disFlg = argInit_real_T();
  wayStp = argInit_real_T();
  wayNum = argInit_real_T();
  wayInxBeg = argInit_real_T();
  wayInxEnd = argInit_real_T();
  staEnd = argInit_real_T();
  engKinNum = argInit_real_T();
  engKinEndInxVal = argInit_real_T();
  staNum = argInit_real_T();

  /* Initialize function input argument 'engKinNumVec_wayInx'. */
  engKinNumVec_wayInx = argInit_Unboundedx1_real_T();

  /* Initialize function input argument 'engKinMat_engKinInx_wayInx'. */
  engKinMat_engKinInx_wayInx = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'optPreInxTn3'. */
  /* Initialize function input argument 'batFrcOptTn3'. */
  /* Initialize function input argument 'fulEngOptTn3'. */
  /* Initialize function input argument 'cos2goActMat'. */
  /* Call the entry-point 'clcOptTrj_tmp'. */
  argInit_11x6x800_real_T(dv0);
  argInit_11x6x800_real_T(dv1);
  argInit_11x6x800_real_T(dv2);
  argInit_11x6_real_T(dv3);
  clcOptTrj_tmp(disFlg, wayStp, wayNum, wayInxBeg, wayInxEnd, staEnd, engKinNum,
                engKinEndInxVal, staNum, engKinNumVec_wayInx,
                engKinMat_engKinInx_wayInx, dv0, dv1, dv2, dv3, engKinOptVec,
                batEngDltOptVec, fulEngDltOptVec, staVec, psiEngKinOptVec,
                &fulEngOpt, &engKinEndInx);
  emxDestroyArray_real_T(psiEngKinOptVec);
  emxDestroyArray_real_T(staVec);
  emxDestroyArray_real_T(fulEngDltOptVec);
  emxDestroyArray_real_T(batEngDltOptVec);
  emxDestroyArray_real_T(engKinOptVec);
  emxDestroyArray_real_T(engKinMat_engKinInx_wayInx);
  emxDestroyArray_real_T(engKinNumVec_wayInx);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  clcOptTrj_tmp_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_clcOptTrj_tmp();

  /* Terminate the application.
     You do not need to do this more than one time. */
  clcOptTrj_tmp_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
