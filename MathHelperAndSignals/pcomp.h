// source:	pcomp.h
// use:		Interface for PCOMP class
// Author:	Anab Akanda
// Date:	10/27/2014

#ifndef PCOMP_H
#define PCOMP_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>

#include "pid.h"

typedef double T;
using namespace std;



class PCOMP
{
public:
	//Methods:
	PCOMP();
	PCOMP(int Nchanl, int Nfiltr, T Umin, T Umax, T Ko, T bo); 
	~PCOMP();
	void ResetIntegrator(int &ichanl);
	// Apply PCOMP X_ichanl(t):
	T  ApplyPCOMP(int &ichanl, T &Kp, T &Ki, T &Kd, T &Tt, T &b, T &t, T &pref, T &pfdbck); 

private:
	int Nchanl;
	T   Umax, Umin, Ko, bo;
	PID   *P;
};

#endif	// PCOMP_H
