function [y] = MatPrimo( n )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    w =exp(2*pi*j/n);
    vecW = w.^(0:n-1)';
    
    for i=0:n-1
        y(:,i+1)=vecW.^i
    end
end

