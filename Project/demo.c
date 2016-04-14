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
	
	
	double x[16] = {1,2,3,4,5,6,7,8,0,0,0,0,0,0,0,0};
    double h[16] = {1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0};

    int result_size = 11; //(8+4-1);
    //Result vector normal convolution 
    double *B = malloc( result_size*sizeof(double) );

    convNormalIndex(x,0,8,h,4,B);

	
	double complex * X = fftGS(x, 16);
    double complex * H = fftGS(h, 16);

    for (int i = 0; i < 16; ++i)
    {
        X[i] = X[i]*H[i];       
    }

    double * C = ifftGS(X,16);

    printf("   Conv  =  FFTGS \n");

    for (int i = 0; i < 11; ++i)
    {
        printf("%f = %f \n", B[i], C[i] );
    }

    return 0;
	
}