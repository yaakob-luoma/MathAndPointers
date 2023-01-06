// source:	SignalWrapper.cpp
// use:		Implements SignalWrapper
// Author:	Anab Akanda
// Date:	10/27/2014
// 


// Header Files:
#include "SignalWrapper.h"
#include "SRamp.h"
#include "pcomp.h"

extern "C" 
{

/* SRAMP OBJECTS */
CSRamp *CSRampNew(int Nchanl, 
		          T   RampUP, 
		          T   RampDN, 
		          T   to, 
		          T   xo, 
		          T   yo, 
		          T   h1o, 
		          T   h2o, 
		          T   K, 
		          T   fo, 
		          int buffer_size, 
		          T   MaxTau, 
		          T   dTmin)
{
	SRamp *CR = new SRamp(Nchanl, RampUP, RampDN, to, xo, yo, h1o, h2o, K, fo, buffer_size, MaxTau, dTmin);
	return (CSRamp *) CR;
}


void   CSRampApply(const CSRamp *CR,
                   int   _ichanl, 
				   T     _RampUP, 
				   T     _RampDN,
				   T     _fo,
				   T     _tcur, 
				   T     _tauUP,
				   T     _tauDN,
				   T     _x,
				   T     *y)
{
	int ichanl;
	T RampUP, RampDN, fo, tcur, tauUP, tauDN, x;
	ichanl = _ichanl;
	RampUP = _RampUP;
	RampDN = _RampDN;
	fo     = _fo;
	tcur   = _tcur;
	tauUP  = _tauUP;
	tauDN  = _tauDN;
	x      = _x;
	SRamp *r = (SRamp *) CR;
	(*y) = r->ApplySRamp(ichanl, RampUP, RampDN, fo, tcur, tauUP, tauDN, x);
}

void CSRampDelete(CSRamp *CR)
{
	SRamp *r = (SRamp *) CR;
	delete r;
}


/* PRESSURE COMPENSATOR OBJECTS */
CSRamp *CPcompNew(int Nchanl, 
	              int Nfiltr, 
				  T   Umin, 
				  T   Umax,
				  T   Ko,
				  T   bo)
{
	PCOMP *CP = new PCOMP(Nchanl, Nfiltr, Umin, Umax, Ko, bo);
	return (CPcomp *) CP;
}

void   CPcompResetIntegrator(const CPcomp *CP, int _ichanl)
{
	int ichanl;
	ichanl = _ichanl;
	PCOMP *p = (PCOMP *) CP;
	p->ResetIntegrator(ichanl);
}

void   CPcompApply(const CPcomp *CP,
                   int   _ichanl, 
				   T     _Kp, 
				   T     _Ki,
				   T     _Kd,
				   T     _Tt, 
				   T     _b,
				   T     _t,
				   T     _Pref,
				   T     _Pfdbck,
				   T     *x)
{
	int ichanl;
	T Kp, Ki, Kd, Tt, b, t, Pref, Pfdbck;
	ichanl = _ichanl;
	Kp    = _Kp;
	Ki    = _Ki;
	Kd    = _Kd;
	Tt     = _Tt;
	b      = _b;
	t      = _t;
	Pref   = _Pref;
	Pfdbck = _Pfdbck;
	PCOMP *p = (PCOMP *) CP;
	(*x) = p->ApplyPCOMP(ichanl, Kp, Ki, Kd, Tt, b, t, Pref, Pfdbck);
}


void   CPcompDelete(CPcomp *CP)
{
	PCOMP *p = (PCOMP *) CP;
	delete p;
}


}
// EOF
