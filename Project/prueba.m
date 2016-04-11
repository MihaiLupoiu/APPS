clear;

x=(1:4);
h=(1:2);
h(3:4)=0;

% Convolution of x and h
c1 = conv(x,h);
c1'

% Convolution of x and h using fft
x1 = [x zeros(1,4)];
h1 = [h zeros(1,4)];
fftx = fft(x1);
ffth= fft(h1);
 
c2 = ifft(fftx.*ffth);
c2'

% FFT Cgentleman-Sande

fftGS(x)'

fft(x)'