// source:	Ramp.h
// use:		Interface for Ramp class
// Author:	Anab Akanda
// Date:	09/16/2014

#ifndef RAMP_H
#define RAMP_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>



typedef double T;
using namespace std;


class Ramp
{

public:
	//Methods:
	Ramp();
	Ramp(T &R, T &F, T &to, T &yo); 
	~Ramp();
 	// Operator:
	Ramp &operator=(const Ramp &r);
	void SetParam(T &R, T &F, T &to, T &yo);  
	void GetParam(T &R, T &F, T &to, T &yo);

	// Ramp the y(t):
	T  ApplyRamp(T &t, T &u); 

	T R, F, rate;

private:
	// Data Members:
	// R->  Rising Slew Rate (Hz)
	// F->  Falling Slew Rate (Hz)
	// to-> IC
	// yo-> IC
	T to, yo;
};

#endif	// RAMP_H

