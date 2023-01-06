// source:	VDelay.h
// use:		Implemtation of VDelay class
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
#include "VDelay.h"


typedef double T;
using namespace std;


VDelay::VDelay()
{
	xo          = 0.0;   
	dt          = 0.0;
	MaxTau      = 500.0e-3; // Default 500ms
	dTmin       = 1.000e-3; // Default 1ms
	buffer_size = 1024;     // Default BlockSize
	indxLast    = 0;
	t.clear(); 
	x.clear(); 
}

VDelay::VDelay(int &_buffer_size, T &_MaxTau, T &_dTmin, T &_to, T &_xo)
{
	buffer_size = _buffer_size;
	t.reserve(buffer_size);
	x.reserve(buffer_size);
	MaxTau = _MaxTau;
	dTmin = _dTmin;
	xo = _xo;
	to = _to;
	dt = 0.0;
}

VDelay::~VDelay()
{
	t.clear(); 
	x.clear(); 
}

VDelay &VDelay::operator=(const VDelay &d)
{
	buffer_size = d.buffer_size;
	t.clear();
	x.clear();
	t = d.t;
	x = d.x;
	MaxTau = d.MaxTau;
	dTmin = d.dTmin;
	indxLast = d.indxLast;
	xo = d.xo;
	to = d.to;
	dt = 0.0;
    return *this;
}

void VDelay::SetParam(int &_buffer_size, T &_MaxTau, T &_dTmin, T &_to, T &_xo)
{
	buffer_size = _buffer_size;
	t.clear();
	x.clear();
	t.reserve(buffer_size);
	x.reserve(buffer_size);
	MaxTau = _MaxTau;
	dTmin = _dTmin;
	xo = _xo;
	to = _to;
	dt = 0.0;
}


void VDelay::GetParam(int &_buffer_size, T &_MaxTau, T &_dTmin, T &_to, T &_xo)
{
	_buffer_size = buffer_size;
	_MaxTau = MaxTau;
	_dTmin = dTmin;
	_xo = xo;
	_to = to;
}


T  VDelay::ApplyVDelay(T &tcur, T &_tau, T &xcur)
{
    T  y, dy, tau, td;
	int N=0, polynomDegree=2;

	tau = (_tau > MaxTau) ? MaxTau : _tau;
	tau = (_tau <  dTmin) ?    0.0 : _tau;
	dt += tcur - to;

	if (dt >= dTmin) 
	{
		t.push_back(tcur); 
		x.push_back(xcur); 
		N = t.size();
		if (N > buffer_size)
		{
			t.erase(t.begin()+0);
			x.erase(x.begin()+0);
		} 
		dt = 0.0;
	}

	if (tau != 0.0)
	{
	    N = t.size(); 
	    td = tcur - tau;
		if (td <= dTmin)
		{
			y = xo;
		} else {
			y = InterExtraPolate(polynomDegree, indxLast, td, dy, N, t, x);
		}
	} else {
		y = xcur;
    }

	to = tcur;
	return y;

}


T VDelay::InterExtraPolate(int &m, int &j, T &x, T &dy, int &_n, vector<T> &X, vector<T> &Y)
{
	int i,k,n;
	T b,c,Yapprox;
	n = _n;
    T *xtmp = new T [m]; 
	T *ytmp = new T [m]; 
	hunt(n,X,x,j); 
	k = IMIN(IMAX(j+1-(m-1)/2,1),n+1-m) - 1;
	for (i=0;i<m;i++)
	{
		xtmp[i] = X[k];
		ytmp[i] = Y[k];
		k++;
	}
	polint(m,xtmp,ytmp,x,Yapprox,dy);	
	delete [] xtmp;
	delete [] ytmp;
	return Yapprox;
}


void VDelay::hunt(int _n, vector<T> &xx, T x, int &jlo)
{
	int jm,jhi,inc;
	bool ascnd;

	int n=_n;
	ascnd=(xx[n-1] >= xx[0]);
	if (jlo < 0 || jlo > n-1) {
		jlo=-1;
		jhi=n;
	} else {
		inc=1;
		if (x >= xx[jlo] == ascnd) {
			if (jlo == n-1) return;
			jhi=jlo+1;
			while (x >= xx[jhi] == ascnd) {
				jlo=jhi;
				inc += inc;
				jhi=jlo+inc;
				if (jhi > n-1) {
					jhi=n;
					break;
				}
			}
		} else {
			if (jlo == 0) {
				jlo=-1;
				return;
			}
			jhi=jlo--;
			while (x < xx[jlo] == ascnd) {
				jhi=jlo;
				inc <<= 1;
				if (inc >= jhi) {
					jlo=-1;
					break;
				}
				else jlo=jhi-inc;
			}
		}
	}
	while (jhi-jlo != 1) {
		jm=(jhi+jlo) >> 1;
		if (x >= xx[jm] == ascnd)
			jlo=jm;
		else
			jhi=jm;
	}
	if (x == xx[n-1]) jlo=n-2;
	if (x == xx[0]) jlo=0;
}


void VDelay::polint(int _n, T *xa, T *ya, T x, T &y, T &dy)
{
	int i,m,ns=0;
	T den,dif,dift,ho,hp,w;

	int n=_n;
	T *c = new T [n];
	T *d = new T [n];

	dif=fabs(x-xa[0]);
	for (i=0;i<n;i++) {
		if ((dift=fabs(x-xa[i])) < dif) {
			ns=i;
			dif=dift;
		}
		c[i]=ya[i];
		d[i]=ya[i];
	}
	y=ya[ns--];
	for (m=1;m<n;m++) {
		for (i=0;i<n-m;i++) {
			ho=xa[i]-x;
			hp=xa[i+m]-x;
			w=c[i+1]-d[i];
			if ((den=ho-hp) == 0.0) 
			{
				cout << "\n\nError in routine polint. Bailing out....\n\n";
				exit(EXIT_FAILURE);
			}
			den=w/den;
			d[i]=hp*den;
			c[i]=ho*den;
		}
		y += (dy=(2*(ns+1) < (n-m) ? c[ns+1] : d[ns--]));
	}
	delete [] c;
	delete [] d;
}
// EOF
