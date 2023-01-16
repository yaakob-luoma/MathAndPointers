// source:	pcomp.cpp
// use:		Implemtation of PCOMP class
// Author:	Anab Akanda
// Date:	10/27/2014

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>


// My Classes:
#include "pcomp.h"


typedef double T;
using namespace std;


PCOMP::PCOMP()
{
	P = NULL; 
	Nchanl = 0;
	Umax =  1.0;
	Umin = -1.0;
	Ko = 0.0;
	bo = 1.0;
}

PCOMP::PCOMP(int _Nchanl, 
	         int _Nfiltr, 
			 T   _Umin, 
			 T   _Umax,
			 T   _Ko,
			 T   _bo)
{
	int i, Nchanl, Nfiltr;
	T Umin, Umax;
	Nchanl = _Nchanl;
	Nfiltr = _Nfiltr;
	Umax = _Umax;
	Umin = _Umin;
	Ko   = _Ko;
	bo   = _bo;
    P = new PID [Nchanl];

	for (i=0; i<Nchanl; i++)
	{
		P[i].SetParam(Nfiltr, Umin, Umax, Ko, bo);
	}
}

PCOMP::~PCOMP()
{
	delete [] P;
}

void PCOMP::ResetIntegrator(int &ichanl)
{
		P[ichanl].ResetIntegrator();
}

T  PCOMP::ApplyPCOMP(int &ichanl, T &Kp, T &Ki, T &Kd, T &Tt, T &b, T &t, T &pref, T &pfdbck)
{
	T u;

	// pref(t)   -> Set Point Pressure
    // pfdbck(t) -> Feedback Pressure
	// Control Signal (0<u<1):
	u = P[ichanl].ApplyPID(Kp, Ki, Kd, Tt, b, t, pref, pfdbck);

	return u;
}

// EOF
