import numpy as np
from ._CFunctions import _CGSMtoGSEUT


def GSMtoGSE(Xin, Yin, Zin, Date, ut):
	'''
	Converts from Cartesian GSM to GSE coordinates.
	
	Inputs
	======
	Xin	: Array or scalar of x coordinates in R_E.
	Yin	: Array or scalar of y coordinates in R_E.
	Zin	: Array or scalar of z coordinates in R_E.
	Date	: Integer dat in format yyyymmdd.
	ut	: Time in hours (ut = hh + mm/60 + ss/3600).	
	
	Returns
	=======
	Xout,You,Zout	: x, y and z coordinates in R_E
	
	'''
	#Convert input variables to appropriate numpy dtype:
	_Xin = np.array([Xin]).flatten().astype("float32")
	_Yin = np.array([Yin]).flatten().astype("float32")
	_Zin = np.array([Zin]).flatten().astype("float32")
	_n = np.int32(_Xin.size)
	_date = np.int32(Date)
	_UT = np.float32(ut)
	_Xout = np.zeros(_n,dtype="float32")
	_Yout = np.zeros(_n,dtype="float32")
	_Zout = np.zeros(_n,dtype="float32")
	_CGSMtoGSEUT(_Xin, _Yin, _Zin, _n, _date, _UT, _Xout, _Yout, _Zout)

	return _Xout,_Yout,_Zout