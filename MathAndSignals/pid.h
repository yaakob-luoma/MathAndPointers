// source:	pid.h
// use:		Interface for pid class
//
// This implementation follows KJ Astrom (2002) exactly
// It features the following:
// 1. Set Point weighting (2DOF PID)
// 2. First order filtering of feedback for derivative gain computation
// 3. Anti Windup using Back Calculation & Tracking
// 4. Bump Less Parameter Change
//
// Author:	Anab Akanda
// Date:	10/26/2014

#ifndef PID_H
#define PID_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>

typedef double T;
using namespace std;


class PID
{

public:
	//Methods:
	PID();
	PID(int &N, T &Umin, T &Umax, T &Ko, T &bo); 
	~PID();
 	// Operator:
	PID &operator=(const PID &p);
	void ResetIntegrator();
	void SetParam(int &N, T &Umin, T &Umax, T &Ko, T &bo); 
	void GetParam(int &N, T &Umin, T &Umax, T &Ko, T &bo); 

	// INVOKE THE CONTROLLER:
	// K  -> Propertional Gain
	// Ti -> Integration time constant
	// Td -> Differentiation time constant
	// Tt -> Tracking Gain
	// b  -> Set Point Weighting Constant (0<b<1)
	// t -> Current time
	// r -> Set Point Signal
	// y -> Actuator Feedback Signal
	// Note: Error = (r-y) 
	// Function returns control signal u(t):
	T  ApplyPID(T &Kp, T &Ki, T &Kd, T &Tt, T &b, T &t, T &r, T &y); 

	// N  -> 1st Order Feedback Signal Filter constant (8 < N < 20)
	// Umin/max -> Controller output Saturation Limits
	// NOTE: PID Transfer Function is of the form:
	//       U(s)/Y(s) = K*[1  +  1/(s*Ti) + s*Td]
	//       This means:
	//       (1) Kp = K;
	//       (2) Ki = K/Ti;
	//       (3) Kd = K*Td;
	//

private:
	// to  -> IC
	// Do  -> IC
	// yo  -> IC 
	int N;
	T Umin, Umax;
	T to, Io, Do, yo, Ko, bo; 

	// Utility function for saturation (Umin < U < Umax):
	T  sat(T U);
	
};

#endif	// PID_H

