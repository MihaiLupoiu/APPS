function y=fft2(x)

n=length(x); % n debe ser potencia de 2 
if n==1
    y=x;
else
    m=n/2;
    w=exp(-2*pi*i/n);
    omega=eye(m,m);
    for j=1:m
        omega(j,j)=w^((j-1));
    end
    
    zt=fft2(x(1:2:n)); 
    zb=omega*fft2(x(2:2:n));
    
    y=[zt+zb;zt-zb];
    
end

end