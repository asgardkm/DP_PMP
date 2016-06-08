/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 07-Jun-2016 10:39:18
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
#include "myMult.h"
#include "main.h"
#include "myMult_terminate.h"
#include "myMult_initialize.h"

/* Function Declarations */
static void argInit_3x4_real_T(double result[12]);
static void argInit_4x5_real_T(double result[20]);
static double argInit_real_T(void);
static void main_myMult(void);

/* Function Definitions */

/*
 * Arguments    : double result[12]
 * Return Type  : void
 */
static void argInit_3x4_real_T(double result[12])
{
  int b_j0;
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 3; b_j0++) {
    for (b_j1 = 0; b_j1 < 4; b_j1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[b_j0 + 3 * b_j1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[20]
 * Return Type  : void
 */
static void argInit_4x5_real_T(double result[20])
{
  int b_j0;
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 4; b_j0++) {
    for (b_j1 = 0; b_j1 < 5; b_j1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[b_j0 + (b_j1 << 2)] = argInit_real_T();
    }
  }
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
 * Return Type  : void
 */
static void main_myMult(void)
{
  double dv0[12];
  double dv1[20];
  double c[15];

  /* Initialize function 'myMult' input arguments. */
  /* Initialize function input argument 'a'. */
  /* Initialize function input argument 'b'. */
  /* Call the entry-point 'myMult'. */
  argInit_3x4_real_T(dv0);
  argInit_4x5_real_T(dv1);
  myMult(dv0, dv1, c);
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
  myMult_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_myMult();

  /* Terminate the application.
     You do not need to do this more than one time. */
  myMult_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
