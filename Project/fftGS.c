#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

double complex * fftGS(double * vector, int ncol){
	
	double complex * x =(double complex *)malloc(ncol*sizeof(double complex));

	for (int i = 0; i < ncol; ++i)
	{
		x[i] = vector[i];	
	}

	int t = sqrt(ncol); // next pow to 2

	for (int q = t; 1 <= q; --q)
	{
		int L = pow(2, q);
		int r = ncol/L;
		int L_ = L/2;

		for (int j = 0; j < L_; ++j)
		{
			double complex w = cos(2*M_PI*j/L) - sin(2*M_PI*j/L)*I;
			for (int k = 0; k < r; ++k)
			{
				int index = (k*L)+L_+j;
				double complex tau = x[k*L+L_+j];
				
				x[k*L+j+L_]=w*(x[k*L+j]-tau);
				x[k*L+j]=x[k*L+j]+tau;
			}
		}
	}

	return x;
	
}

int main(){
	double x[4] = {1,2,3,4};

	//double v = 3.0;
	//double complex b2=v;
	//printf("%f + %f",creal(b2),cimag(b2));

	
	double complex * X = fftGS(x, 4);
	
	for (int i = 0; i < 4; ++i)
	{
		printf("%f + %f \n",creal(X[i]),cimag(X[i]));		
	}

	return 0;
}