// source:	SRamp.h
// use:		Interface for SRamp class
// Author:	Anab Akanda
// Date:	10/16/2014

#ifndef SRAMP_H
#define SRAMP_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>

#include "Ramp.h"
#include "Lag2.h"
#include "VDelay.h"

typedef double T;
using namespace std;



class SRamp
{
public:
	//Methods:
	SRamp();
	SRamp(int Nchanl, 
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
		  T   dTmin); 
	~SRamp();


	// Apply SRamp X_ichanl(t):
	T  ApplySRamp(int &ichanl,
		          T   &RampUP,
				  T   &RampDN,
				  T   &fo,
				  T   &tcur, 
				  T   &tauUP, 
				  T   &tauDN,
				  T   &x); 

private:
	int    Nchanl;
	Ramp   *R;
	Lag2   *L;
	VDelay *D;
};

#endif	// SRAMP_H
