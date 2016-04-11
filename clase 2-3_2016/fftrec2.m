function [ sal ] = fftrec2( x )
    n=size(x,1);
    W = exp(2*pi*i/n);

    v=mod(2:n,n);
    p=find(v==0,1)+1;

    if(p==n)
        A=MatPrimo(n);
        sal=A*x;
    else
        m=n/p;
        vecW=W.^(0:m-1)';
        %omega=diag(vec);
        for j=1:p
            z((j-1)*m+1:j*m)=diag(vecW.^(j-1)) *fftrec2(x(j:p:n));
        end
        
        for j=1:m
            sal(j:m:n)=fftrec2(z(j:m:n));
        end
    end
end