#ifndef FFTGS_H
#define FFTGS_H

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

enum SIGN{
	FORWARD = 1,
	REVERSE = -1
};

void fftGS_General(double complex * x, int ncol, enum SIGN sig);
double complex * fftGS(double * vector, int ncol);
double * ifftGS(double complex * x, int ncol);

#endif

