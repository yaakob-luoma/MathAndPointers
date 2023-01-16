// source:	Lag2.h
// use:		Implemtation of Lag2 class
// Author:	Anab Akanda
// Date:	09/16/2014

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>


// My Classes:
#include "Lag2.h"


typedef double T;
static T Pi = 4.0*atan(1.0);

using namespace std;


Lag2::Lag2()
{
	to = 0.0;
	K  = 1.0;   // Unity Gain
	fo = 10.0;  // 10Hz Default
	wo = 2.0*Pi*fo;
	to = 0.00;
	xo = 0.00;
	h1o= 0.00;
	h2o= 0.00;
}

Lag2::Lag2(T &_K, T &_fo, T &_to, T &_xo, T &_h1o, T &_h2o)
{
	K   = (_K  <= 0.0) ? 1.00 : _K;
	fo  = (_fo <= 0.0) ? 10.0 : _fo;
	wo = 2.0*Pi*fo;
	to  = _to;
	xo  = _xo;
	h1o = _h1o;
	h2o = _h2o;
}

Lag2::~Lag2()
{
// Do nothing
}

Lag2 &Lag2::operator=(const Lag2 &l)
{
	K   = l.K;
	fo  = l.fo;
	wo  = 2.0*Pi*fo;
	to  = l.to;
	xo  = l.xo;
	h1o = l.h1o;
	h2o = l.h2o;
    return *this;
}

void Lag2::SetParam(T &_K, T &_fo, T &_to, T &_xo, T &_h1o, T &_h2o)
{
	K   = (_K  <= 0.0) ? 1.00 : _K;
	fo  = (_fo <= 0.0) ? 10.0 : _fo;
	wo = 2.0*Pi*fo;
	to  = _to;
	xo  = _xo;
	h1o = _h1o;
	h2o = _h2o;
}

void Lag2::GetParam(T &_K, T &_fo, T &_to, T &_xo, T &_h1o, T &_h2o)
{
	_K   = K;
	_fo  = fo;
	_to  = to;
	_xo  = xo;
	_h1o = h1o;
	_h2o = h2o;
}

T  Lag2::ApplyLag2(T &t, T &x)
{
	/* CRITICALLY DAMPED 2ND ORDER LAG: 
		K  -> Gain
		wo -> Natural Frequency (radians/sec)
		to -> Previous time
		t  -> time t
		xo -> Previous Input
		h1 -> Recursion Sum1
		h2 -> Recursion Sum2
		x  -> Input
		y  -> Output
		Transfer Function in S-Domain:
		Y(s) = X(s)*K*wo^2/(s + wo)^2
	*/
	T y, dt, h1, h2;

	dt = t - to;
	/* Newton-Cotes */
	h1 = h1o*exp(-wo*dt) + 0.5*dt*( exp(-wo*dt)*xo + x );
	h2 = h2o*exp(-wo*dt) + 0.5*dt*( exp(-wo*dt)*to*xo + t*x );
	y  = K*(wo*wo)*(t*h1 - h2);
	/* Recursion */
	to = t;
    xo = x;
	h1o = h1;
	h2o = h2;
	return y;
}

// EOF
