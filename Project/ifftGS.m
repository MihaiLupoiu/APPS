function [ x ] = ifftGS( x )
%UNTITLED2 Summary of this function goes here

n = size(x,2);
t = nextpow2(n);

for q = t:-1:1
    L = 2^q;
    r = n/L;
    L_ =L/2;
    for j = 1:L_
        w=cos(-2*pi*(j-1)/L)- sin(-2*pi*(j-1)/L)*1i;
        for k = 1:r
            tau = x((k-1)*L+L_+j);
            x((k-1)*L+j+L_) = w *(x((k-1)*L+j) - tau);
            x((k-1)*L+j)    =(x((k-1)*L+j) + tau);
        end
    end
end

 for k=1:n
    x(k)=x(k)/n;
end

%Algorithmo 1.5.1
for k =1:n
    % Algorithmo 1.5.2
    j=0; 
    m=k-1;
    for q=1:t
        s = floor(m/2);
        bq = m-2*s;
        j = 2*j+bq;
        m=s;
    end
    % Fin Algorithmo 1.5.2
    j=j+1;
    if j > k
        value = x(k);
        x(k) = x(j);
        x(j) = value;
    end
end


