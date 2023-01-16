// source:	Ramp.h
// use:		Implemtation of Ramp class
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
#include "Ramp.h"


typedef double T;
using namespace std;


Ramp::Ramp()
{
	R  = 5.0; // Default 200ms
	F  =-5.0; // Default 200ms
	to = 0.0;
	yo = 0.0;
	rate = 1.0;
}

Ramp::Ramp(T &_R, T &_F, T &_to, T &_yo)
{
	R  = (_R < 0.0) ? -_R : _R;
	F  = (_F > 0.0) ? -_F : _F;
	to = _to;
	yo = _yo;
	rate = 1.0;
}

Ramp::~Ramp()
{
// Do nothing
}

Ramp &Ramp::operator=(const Ramp &r)
{
	R  = r.R;
	F  = r.F;
	to = r.to;
	yo = r.yo;
	rate = r.rate;
    return *this;
}

void Ramp::SetParam(T &_R, T &_F, T &_to, T &_yo)
{
	R  = (_R < 0.0) ? -_R : _R;
	F  = (_F > 0.0) ? -_F : _F;
	to = _to;
	yo = _yo;
}

void Ramp::GetParam(T &_R, T &_F, T &_to, T &_yo)
{
	_R  = R;
	_F  = F;
	_to = to;
	_yo = yo;
}

T  Ramp::ApplyRamp(T &t, T &u)
{
	/* LINEAR DYNAMIC RAMP: 
		R -> Rising Slew Rate
		F -> Falling Slew Rate
		t -> Current time t
		u -> Input
		y -> Output
	*/

	/* Note: Following must be true (R > F) */
	T dt, y;

	dt = t - to;
	rate = (u - yo)/dt;
	if (rate > R)      		/* Rising Slew Rate: */
	{
		y = dt*R + yo;
	} else if (rate < F) {
		y = dt*F + yo;      /* Falling Slew Rate: */
	} else {
		y = u;
	}
	to = t;
	yo = y;
    return y;
}

// EOF
