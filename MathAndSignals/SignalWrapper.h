/* source:	SignalWrapper.h
   use:		C Wrapper for SRamp & PCOMP class
   Author:	Anab Akanda
   Date:	10/27/2014
*/
#ifndef SIGNALWRAPPER_H
#define SIGNALWRAPPER_H

#ifndef T_DEFINED        // idempotency lock
	typedef double T;
#define T_DEFINED
#endif

typedef void CSRamp;
typedef void CPcomp;

#ifdef __cplusplus
extern "C" {
#endif

// SRamp Objects:
CSRamp *CSRampNew(int Nchanl, 
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

void   CSRampApply(const CSRamp *CR,
                   int   _ichanl, 
				   T     _RampUP, 
				   T     _RampDN,
				   T     _fo,
				   T     _tcur, 
				   T     _tauUP,
				   T     _tauDN,
				   T     _x,
				   T     *y);

void   CSRampDelete(CSRamp *CR);


// Pressure Compensation Controllers:
CSRamp *CPcompNew(int _Nchanl, 
	              int _Nfiltr, 
				  T   _Umin, 
				  T   _Umax,
				  T   _Ko,
				  T   _bo);

void   CPcompResetIntegrator(const CPcomp *CP, int _ichanl);

void   CPcompApply(const CPcomp *CP,
                   int   _ichanl, 
				   T     _Kpo, 
				   T     _Kio,
				   T     _Kdo,
				   T     _Tt, 
				   T     _b,
				   T     _t,
				   T     _Pref,
				   T     _Pfdbck,
				   T     *x);

void   CPcompDelete(CPcomp *CP);

#ifdef __cplusplus
}
#endif

#endif /* SIGNALWRAPPER_H */

