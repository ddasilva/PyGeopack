#ifndef __TRACEFOOTPRINTS_H__
#define __TRACEFOOTPRINTS_H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getmagequatorfp.h"
#include "latlonlt.h"


#endif
using namespace std;


void TraceFootprints(	int nstep, float ut, 
						double *x, double *y, double *z, 
						double *s, double *R, 
						double xfn, double yfn, double zfn, 
						double xfs, double yfs, double zfs, 
						double alt, double *FP, int MaxLen, int TraceDir);
