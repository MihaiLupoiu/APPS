#include "fftGS.h"

/* General FFT Using complex numbers.
   Parameters: Pointer to vector of complex numbers, 
   size of vector, FORWARD (FFT) or REVERSE (ifft).
   Return: double complex pointer to vector.
*/
void fftGS_General(double complex * x, int ncol, enum SIGN sig){

	int t = ceil(log(ncol)/log(2));

	for (int q = t; 1 <= q; --q)
	{
		int L = pow(2, q);
		int r = ncol/L;
		int L_ = L/2;

		for (int j = 0; j < L_; ++j)
		{
			double complex w = cos(2*M_PI*j/L) + ( sig * sin(2*M_PI*j/L)*I);
			for (int k = 0; k < r; ++k)
			{
				int index = (k*L)+L_+j;
				double complex tau = x[k*L+L_+j];
				
				x[k*L+j+L_]=w*(x[k*L+j]-tau);
				x[k*L+j]=x[k*L+j]+tau;
			}
		}
	}

	// Bit Reversal 
	// Algoritmo 1.5.1
	for (int k = 0; k < ncol; ++k)
	{
		// Algoritmo 1.5.2
		int j = 0;
		int m = k;
		for (int q = 0; q < t; ++q)
		{
			int s = floor(m/2);
			j=2*j+(m-2*s);
			m=s;
		}
		// End Algoritmo 1.5.2

		double complex temportal_swap;
		if (j>k){
			temportal_swap = x[k];
			x[k]=x[j];
			x[j]=temportal_swap;
		}
	}

}

double complex * fftGS(double * vector, int ncol){
	
	double complex * x =(double complex *)malloc(ncol*sizeof(double complex));

	for (int i = 0; i < ncol; ++i)
	{
		x[i] = vector[i];	
	}

	fftGS_General(x,ncol,FORWARD);

	return x;

}

double * ifftGS(double complex * x, int ncol){
	
	double * X = (double *)malloc(ncol*sizeof(double)); 

	fftGS_General(x,ncol,REVERSE);

	for (int i = 0; i < ncol; ++i)
	{
		X[i]=creal(x[i])/ncol;
	}

	return X;
}