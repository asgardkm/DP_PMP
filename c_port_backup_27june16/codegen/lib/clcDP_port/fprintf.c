/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fprintf.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jun-2016 17:44:08
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "clcDP_port.h"
#include "fprintf.h"
#include "fileManager.h"
#include <stdio.h>

/* Function Declarations */
static double c_fprintf(void);
static double e_fprintf(double varargin_1, double varargin_2);
static double g_fprintf(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
static double c_fprintf(void)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[24] = { '-', 'I', 'n', 'i', 't', 'i', 'a', 'l', 'i',
    'z', 'i', 'n', 'g', ' ', 'm', 'o', 'd', 'e', 'l', '.', '.', '.', '\x0a',
    '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt);
    fflush(filestar);
  }

  return nbytesint;
}

/*
 * Arguments    : double varargin_1
 *                double varargin_2
 * Return Type  : double
 */
static double e_fprintf(double varargin_1, double varargin_2)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[48] = { 'S', 'c', 'h', 'l', 'e', 'i', 'f', 'e', ' ',
    '%', '1', '.', '0', 'f', ' ', 'b', 'e', 'r', 'e', 'c', 'h', 'n', 'e', 't',
    '.', ' ', '%', '1', '.', '0', 'f', ' ', '%', '%', ' ', 'g', 'e', 's', 'c',
    'h', 'a', 'f', 'f', 't', '.', ' ', '\x0d', '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt, varargin_1, varargin_2);
    fflush(filestar);
  }

  return nbytesint;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double g_fprintf(void)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[9] = { '\x0a', '\x0a', 'd', 'o', 'n', 'e', '!', '\x0a',
    '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt);
    fflush(filestar);
  }

  return nbytesint;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void b_fprintf(void)
{
  c_fprintf();
}

/*
 * Arguments    : double formatSpec
 *                double varargin_1
 * Return Type  : void
 */
void d_fprintf(double formatSpec, double varargin_1)
{
  e_fprintf(formatSpec, varargin_1);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void f_fprintf(void)
{
  g_fprintf();
}

/*
 * File trailer for fprintf.c
 *
 * [EOF]
 */
