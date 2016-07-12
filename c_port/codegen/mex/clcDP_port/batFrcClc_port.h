/*
 * batFrcClc_port.h
 *
 * Code generation for function 'batFrcClc_port'
 *
 */

#ifndef __BATFRCCLC_PORT_H__
#define __BATFRCCLC_PORT_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "clcDP_port_types.h"

/* Function Declarations */
extern real_T batFrcClc_port(real_T batPwr, real_T vel, real_T batRstDch, real_T
  batRstChr, real_T batOcv);

#ifdef __WATCOMC__

#pragma aux batFrcClc_port value [8087];

#endif
#endif

/* End of code generation (batFrcClc_port.h) */
