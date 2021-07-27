#ifndef __MODELPARAMS_H__
#define __MODELPARAMS_H__
#include <stdio.h>
#include <stdlib.h>
#include "tsygdata.h"
#endif
/***********************************************************************
 * This folder should contain the code to calculate, load and interpolate
 * the model parameters.
 * 
 * 
 * ********************************************************************/
extern TsygData *TData;


extern "C" {
	void InitParams(const char fname);
	
	void GetModelParams(int n, int *Date, float *ut, const char *Model,
							double *Vxin, double *Vyin, double *Vzin,
							double *Kpin, double *Pdynin, double *SymHin,
							double *Byin, double *Bzin, 
							double *G1in, double *G2in,
							double *W1in, double *W2in, double *W3in,
							double *W4in, double *W5in, double *W6in,			
							double *Vx, double *Vy, double *Vz,
							double *Kp, double *Pdyn, double *SymH,
							double *By, double *Bz, 
							double *G1, double *G2,
							double *W1, double *W2, double *W3,
							double *W4, double *W5, double *W6,
							int *iopt, double **parmod);
}
