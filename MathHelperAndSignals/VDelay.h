// source:	VDelay.h
// use:		Interface for VDelay class
// Author:	Anab Akanda
// Date:	09/16/2014

#ifndef VDELAY_H
#define VDELAY_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


typedef double T;
using namespace std;


class VDelay
{

public:
	//Methods:
	VDelay();
	VDelay(int &buffer_size, T &MaxTau, T &dTmin, T &to, T &xo); 
	~VDelay();
 	// Operator:
	VDelay &operator=(const VDelay &d);
	void SetParam(int &buffer_size, T &MaxTau, T &dTmin, T &to, T &xo);  
	void GetParam(int &buffer_size, T &MaxTau, T &dTmin, T &to, T &xo); 

	// VDelay the y(t):
	T  ApplyVDelay(T &tcur, T &tau, T &x); 

private:
	vector<T> t, x;
	int buffer_size, indxLast;
	T MaxTau, dTmin, xo, to, dt;
	void hunt(int _n, vector<T> &xx, T x, int &jlo);
	void polint(int _n, T *xa, T *ya, T x, T &y, T &dy);
	T InterExtraPolate(int &m, int &j, T &x, T &dy, int &_n, vector<T> &X, vector<T> &Y);
	inline int IMAX(int i, int j)
	{
		return (i >= j ? i : j);
	}
	inline int IMIN(int i, int j)
	{
		return (i <= j ? i : j);
	}	
};

#endif	// VDELAY_H

