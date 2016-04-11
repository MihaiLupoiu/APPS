function B = Bidiag( A )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    [m,n]=size(A);

    B=A;
    
    
    for i=1:min(n,n-1)
        
        [p,Q]=Anula(B(i:m,i));
        
        for j=i:n
            B(i:m,j)=Q*B(i:m,j);
        end
        
        if i<n-1
            [z,P]=Anula(B(i,i+1:n)');
            B(i,i+1:n)=z';
            for j=i+1:m
                B(j,i+1:n)=B(j,i+1:n)*P';
            end
        end
        
    end
    
end

