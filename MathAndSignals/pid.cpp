// source:	PID.h
// use:		Implemtation of PID class
// Author:	Anab Akanda
// Date:	10/26/2014

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>


// My Classes:
#include "PID.h"

typedef double T;

using namespace std;


PID::PID()
{
	to = 0.0;
	Io = 0.0;
	Do = 0.0;   
	yo = 0.0;
	N  = 10;     // Filter Coefficient for Derivative Gain 
	Umax =  1.0; // Saturation upper limit of PID output 
	Umin = -1.0; // Saturation lower limit of PID output
}

PID::PID(int &_N, T &_Umin, T &_Umax, T &_Ko, T &_bo)
{
	N  = _N;
	to = 0.0;
	Io = 0.0;
	Do = 0.0;
	yo = 0.0;
	Ko = _Ko;    
	bo = _bo;    
	Umax = _Umax; // Saturation upper limit of PID output 
	Umin = _Umin; // Saturation lower limit of PID output
}

PID::~PID()
{
// Do nothing
}

PID &PID::operator=(const PID &p)
{
	N  = p.N;
	Umin = p.Umin;
	Umax = p.Umax;
	Ko = p.Ko;
	bo = p.bo;
	Io = p.Io;
    Do = p.Do;
	to = p.to;
	yo = p.yo;
    return *this;
}

void PID::ResetIntegrator()
{
	Io = 0.0;
}

void PID::SetParam(int &_N, T &_Umin, T &_Umax, T &_Ko, T &_bo)
{
	N  = _N;
	Umin = _Umin;
	Umax = _Umax;
	to = 0.0;
	Io = 0.0;
	Do = 0.0;
	yo = 0.0;
	Ko = _Ko;    
	bo = _bo;    
}

void PID::GetParam(int &_N, T &_Umin, T &_Umax, T &_Ko, T &_bo)
{
	_N  = N;
	_Umin = Umin;
	_Umax = Umax;
	_Ko = Ko;
	_bo = bo;
}

T  PID::ApplyPID(T &Kp, T &Ki, T &Kd, T &Tt, T &b, T &t, T &r, T &y)
{
//
// PID alogrithm implemented as per KJ Astrom 2002
// Only difference is in the derivative gain calculation
//
// Features:
// 1. Set Point Weighting (TWO DOF PID)
// 2. Anti windup using Back Calculation and Tracking
// 3. Bumpless parameter change
// 4. Derivative gain with 1st order filter
//
// NOTE: PID Transfer Function is of the form:
//       U(s)/Y(s) = K*[1  +  1/(s*Ti) + s*Td]
//       This means:
//       (1) Kp = K;
//       (2) Ki = K/Ti;
//       (3) Kd = K*Td;
// Ki & Kd may be turn off by setting equal to zero
// but Tt CANNOT ZERO
// b must in the range (0 < b <= 1.0)
// 
	T u, v, dt, e, P, D, I, K, Td;

	K  = Kp;
	Td = Kd/Kp;

	// Sampling Time:
	dt = (t - to);

	// Proportional gain with Set Point Weighting:
	P = K*(b*r - y);

	// Derivative gain with 1st order filtering:
	D = (Kd > 0.0) ? ( Td/(Td + N*dt) )*( Do - K*N*(y - yo) ) : 0.0;

	// Error:
	e = (r - y);

	// Bumpless Parameter Change:
	Io = (Ki > 0.0) ? (Io + Ko*(bo*r - y) - K*(b*r - y)) : 0.0;

	// Temporary Output:
	v = P + Io + D;

	// PID output from saturation block:
	u = sat(v);

	// Update integral gain with Back Calculation & Tracking:
	I = (Ki > 0.0) ? (Io + Ki*dt*e + dt*(u-v)/Tt) : 0.0;

	/* Recursion */
	Ko = K;
	bo = b;
	Io = I;
    Do = D;
	to = t;
	yo = y;

	// Output:
	return u;
}

T PID::sat(T U)
{
	T u;
	if (U < Umin)
	{
		u = Umin;
	} else if (U > Umax) {
		u = Umax;
	} else {
		u = U;
	}
	return u;
}
// EOF
