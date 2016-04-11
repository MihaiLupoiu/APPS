clear;

N = 16;

F = ones(N,N);

W = exp(-i*2*pi/N); %Complejo, valor constante.

for i=1:N
    for j=1:N
        F(i,j)=W^((i-1)*(j-1));
    end
end

x=(1:16)';

F*x

fft(x)
