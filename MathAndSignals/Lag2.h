// source:	Lag2.h
// use:		Interface for Lag2 class
// Author:	Anab Akanda
// Date:	09/16/2014

#ifndef LAG2_H
#define LAG2_H

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>   
#include <fstream>
#include <iostream>
#include <sstream>



typedef double T;
using namespace std;


class Lag2
{

public:
	//Methods:
	Lag2();
	Lag2(T &K, T &fo, T &to, T &xo, T &h1o, T &h2o); 
	~Lag2();
 	// Operator:
	Lag2 &operator=(const Lag2 &l);
	void SetParam(T &K, T &f, T &to, T &xo, T &h1o, T &h2o);  
	void GetParam(T &K, T &f, T &to, T &xo, T &h1o, T &h2o);

	// Lag2 the y(t):
	T  ApplyLag2(T &t, T &x); 

	T K, fo;


private:
	// Data Members:
	// K   -> Gain
	// fo  -> Natural Frequency (Hz)
	// to  -> IC
	// xo  -> IC
	// h1o -> IC partial sum
	// h2o -> IC partial sum
	T wo, to, xo, h1o, h2o;
};

#endif	// LAG2_H

