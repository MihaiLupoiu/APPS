function [ x ] = fftGS( x )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

n = size(x,2);
t = sqrt(n);

for q = t:-1:1
    L = 2^q;
    r = n/L;
    L_ =L/2;
    for j = 1:L_
        w=cos(2*pi*(j-1)/L)-i*sin(2*pi*(j-1)/L);
        for k = 1:r
            tau = x((k-1)*L+L_+j);
            x((k-1)*L+j+L_) = w *(x((k-1)*L+j) - tau);
            x((k-1)*L+j)    = w *(x((k-1)*L+j) + tau);
        end
    end
end

