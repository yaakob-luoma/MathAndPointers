// source:	SRamp.cpp
// use:		Implemtation of SRamp class
// Author:	Anab Akanda
// Date:	10/16/2014

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>


// My Classes:
#include "SRamp.h"


typedef double T;
using namespace std;


SRamp::SRamp()
{
	R = NULL; 
	L = NULL;
	D = NULL;
	Nchanl = 0;
}

SRamp::SRamp(int _Nchanl, 
		     T   _RampUP, 
		     T   _RampDN, 
		     T   _to, 
		     T   _xo, 
		     T   _yo, 
		     T   _h1o, 
		     T   _h2o, 
		     T   _K, 
		     T   _fo, 
		     int _buffer_size, 
		     T   _MaxTau, 
		     T   _dTmin)
{
	int i, buffer_size;
	T RampUP, RampDN, to, xo, yo, h1o, h2o, K, fo, MaxTau, dTmin;
	Nchanl = _Nchanl;
	RampUP = _RampUP;
	RampDN = _RampDN;
	to     = _to;
	xo     = _xo;
	yo     = _yo;
	h1o    = _h1o;
	h2o    = _h2o;
	K      = _K;
	fo     = _fo;
	MaxTau = _MaxTau;
	dTmin  = _dTmin;
	buffer_size  = _buffer_size;
    R = new Ramp [Nchanl];
	L = new Lag2 [Nchanl];
	D = new VDelay[Nchanl];

	for (i=0; i<Nchanl; i++)
	{
		R[i].SetParam(RampUP, RampDN, to, yo);
		L[i].SetParam(K, fo, to, xo, h1o, h2o);
		D[i].SetParam(buffer_size, MaxTau, dTmin, to, xo);
	}

}

SRamp::~SRamp()
{
	delete [] R;
	delete [] L;
	delete [] D;
}


T  SRamp::ApplySRamp(int &ichanl, 
	                 T   &RampUP,
					 T   &RampDN,
					 T   &_fo,
				     T   &tcur, 
				     T   &tauUP, 
					 T   &tauDN,
				     T   &x)
{
	T y, ylag, fo, tauTmp;
	R[ichanl].R  = RampUP;
	R[ichanl].F  = RampDN;
	y = R[ichanl].ApplyRamp(tcur, x);

	fo = (_fo > 0.0) ? _fo : 100.0;
	L[ichanl].fo = fo;
	ylag = L[ichanl].ApplyLag2(tcur, y);
	if (_fo > 0.0) y = ylag;

	if (R[ichanl].rate > 0.0)
	{
		y = D[ichanl].ApplyVDelay(tcur, tauUP, y);
	} else if (R[ichanl].rate < 0.0) {
		y = D[ichanl].ApplyVDelay(tcur, tauDN, y);
	} else {
		tauTmp = 0.0;
		y = D[ichanl].ApplyVDelay(tcur, tauTmp, y);
	}
	return y;
}

// EOF
