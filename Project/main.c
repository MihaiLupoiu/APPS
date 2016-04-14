#include <stddef.h>
#include <stdio.h>

//exit(0), malloc, calloc
#include <stdlib.h>
//time
#include <time.h>

#include "./fftGS.h"


void convNormalIndex(double * x, size_t signalStart, size_t signalEnd, double *h, size_t lh, double y[])
{
    size_t i,j;
    size_t lx = signalEnd-signalStart;

    for(i=signalStart;i<signalEnd; i++){
        for(j=0;j<lh;j++){
             y[i+j]=y[i+j]+x[i]*h[j];
        }
    }
}

int main(){
	
	/*
	double x[8] = {1,2,3,4,5,6,7,8};

	//double v = 3.0;
	//double complex b2=v;
	//printf("%f + %f",creal(b2),cimag(b2));

	
	double complex * X = fftGS(x, 8);

	double * X2 = ifftGS(X,8);

	
	for (int i = 0; i < 8; ++i)
	{
		//printf("%f + %f \n",creal(X[i]),cimag(X[i]));		
		printf("%f\n",X2[i]);		
	}



	free(X);
	return 0;
	*/

	int max_size = 65536;

    struct timeval t0, t1;

    /* Generate H1 from 1 to lh*/
    int i;
    double* H1 __attribute__((aligned(16))) = malloc( max_size*sizeof(double) );
    for (i = 0; i < max_size; ++i) {
        H1[i] = (double)(i+1);
    }


    /* Generate lh from 1 to lh*/
    double* A __attribute__((aligned(16))) = malloc( max_size*sizeof(double) );
    for (i = 0; i < max_size; ++i) {
        A[i] = (double)(i+1);
    }

    int tamResultado = max_size+max_size;


    //Result vector normal convolution 
    double *B = malloc( tamResultado*sizeof(double) );


    // Result vector FFTGS
    double * C;

    // FFT vector H is constant
    double complex * H_FFT = fftGS(H1, max_size);

    int lx;
    int lh;
    int bs;

    for (int size = 8; size <= max_size; size=size+size)
    {
        lx = lh = bs = size;

        /*=============================================================================================================*/
        double elapsedTime;

        printf("\n%d;%d;",lx,lh);

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        gettimeofday (&t0, NULL);
        convNormalIndex(A,0,lx,H1,lh,B);
        gettimeofday (&t1, NULL);
        
        elapsedTime = (t1.tv_sec - t0.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (t1.tv_usec - t0.tv_usec) / 1000.0;   // us to ms
        printf("%.20f;", elapsedTime );

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        gettimeofday (&t0, NULL);

        double complex * A_FFT = fftGS(A, size);

        for (int i = 0; i < size; ++i)
        {
            A_FFT[i] = A_FFT[i]*H_FFT[i];       
        }

        C = ifftGS(A_FFT,size);
        
        gettimeofday (&t1, NULL);
        
        elapsedTime = (t1.tv_sec - t0.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (t1.tv_usec - t0.tv_usec) / 1000.0;   // us to ms
        printf("%.20f;", elapsedTime ); 
    }

    return 0;

}