function [y,Q] = Anula( x )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    n=size(x,1);
    
    v=x+sign(x(1))*norm(x)*eye(n,1);
    
    Q=eye(n)-((2*v*v')/(v'*v));
    
    y=Q*x;
        
end