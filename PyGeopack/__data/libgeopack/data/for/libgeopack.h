#ifndef __libgeopack_h__
#define __libgeopack_h__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DateTimeTools.h"
#include <math.h>

typedef struct {
	int n;
	int *Date;
	float *ut;
	int *Year;
	int *DayNo;
	int *Hr;
	int *Mn;
	float *Bx;
	float *By;
	float *Bz;
	float *Vx;
	float *Vy;
	float *Vz;
	float *Den;
	float *Temp;
	float *SymH;
	int *IMFFlag;
	int *ISWFlag;
	float *Tilt;
	float *Pdyn;
	float *W1;
	float *W2;
	float *W3;
	float *W4;
	float *W5;
	float *W6;
	float *G1;
	float *G2;
	float *Kp;
	int *MonthInds;
	int nMonth;
	int minYr;
	int minMn;
} TSD;

extern TSD TSData;

typedef struct {
	float iopt;
	float parmod[10];
	float tilt;
	float Vx, Vy, Vz;
} CustParam;

CustParam CustP;

typedef void (*ModelFuncPtr)(int*,float*,float*,float*,float*,float*,float*,float*,float*);
typedef void (*InternalFuncPtr) (float*,float*,float*,float*,float*,float*);


extern const float Re;

char DataFile[256];

#endif


//CtypeStart
void LoadTSData();
void FreeTSData();
//PyFunc iiiiii
void SetCustParam(int iopt, float *parmod, float tilt, float Vx, float Vy, float Vz);
//PyFunc iiioooooo
void GetModelParams(int Date, float ut, const char *Model, int *iopt, float *parmod, float *tilt, float *Vx, float *Vy, float *Vz);
//PyFunc i
void Init(const char *filename);
//CtypeStop
void GetGeopackParams(float *gp0, float *gp1);

void PopulateMonthInds();
int MonthStartInd(int Date);
float InterpParam(float *x, int Date, float ut);
void DummyFunc(int *iopt, float *parmod, float *ps, float *x, float *y, float *z, float *bx, float *by, float *bz);

extern void geomag_08_(float *xgeo, float *ygeo, float *zgeo, float *xmag, float *ymag, float *zmag, int *j);
extern void gswgse_08_(float *xgsw, float *ygsw, float *zgsw, float *xgse, float *ygse, float *zgse, int *j);
extern void smgsw_08_(float *xsm, float *ysm, float *zsm, float *xgsw, float *ygsw, float *zgsw, int *j);
extern void magsm_08_(float *xmag, float *ymag, float *zmag, float *xsm, float *ysm, float *zsm, int *j);
extern void geogsw_08_(float *xgeo, float *ygeo, float *zgeo, float *xgsw, float *ygsw, float *zgsw, int *j);
extern void recalc_08_(int *iyear, int *iday, int *ihour, int *min, int *isec, float *vgsex, float *vgsey, float *vgsez);
extern void trace_08_(float *xi, float *yi, float *zi, float *dir, float *dsmax, float *err, float *rlim, float *r0, int *iopt, float *parmod, ModelFuncPtr ModelFunc, InternalFuncPtr IntFunc, float *xf, float *yf, float *zf, float *xx, float *yy, float *zz, int *L, int *Lmax);
extern void igrf_gsw_08_(float *xgsw, float *ygsw, float *zgsw, float *hxgsw, float *hygsw, float *hzgsw);
extern float getpsi_();
extern void t89c_(int *iopt, float *parmod, float *ps, float *x, float *y, float *z, float *bx, float *by, float *bz);
extern void t96_(int *iopt, float *parmod, float *ps, float *x, float *y, float *z, float *bx, float *by, float *bz);
extern void t01_01_(int *iopt, float *parmod, float *ps, float *x, float *y, float *z, float *bx, float *by, float *bz);
extern void t04_s_(int *iopt, float *parmod, float *ps, float *x, float *y, float *z, float *bx, float *by, float *bz);
extern void getgeopackparams_(float *gp0, float *gp1);
