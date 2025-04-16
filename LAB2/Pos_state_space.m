%% Load datasheet into workspace
clear
close all
clc

addpath('../LAB0/')
addpath('../utilities/')
load black-box-estimation.mat
datasheet;
%% From part 1 to 4 of lab 1
Jl = mld .JD + 3* gbox .J72 ;
Jeq = mot.J + (Jl / gbox .N1 ^2);

Tm = (mot.Req * Jeq)/(mot.Req*Beq + mot.Kt*mot.Ke);
A = [0, 1;0, -1/Tm];
B = [0; drv.dcgain*mot.Kt/(gbox.N1*mot.Req*Jeq)];
C = [1, 0];
D = 0;

M = [A, B;C, D];
Ans = M \ [0; 0; 1];
Nu = Ans(3,1);
Nx = Ans(1:2,1);
Mp = 0.1; 
delta = -log(Mp) / sqrt(pi^2 + log(Mp)^2);
ts    = 0.15;
delta_est = 1/sqrt(2);
wn = 3/(delta * ts);

pole1 = (-delta * wn) + 1j*wn*sqrt(1-delta^2);
pole2 = (-delta * wn) - 1j*wn*sqrt(1-delta^2);
poles = [pole1,pole2];
K = acker(A,B,poles);
sigma = real(pole1);
poles2 = sigma * ones (3 ,1);
Be= [0 ; B];
Ae =[0  ,C; zeros(2, 1), A ];
K_robust  = acker (Ae , Be , poles2 );
KI = K_robust(1);
K2 = K_robust(2:3);
%% Lab 2 state space 1to4
Mp = 0.1;               % Desired overshoot (e.g., 10%)
delta = -log(Mp) / sqrt(pi^2 + log(Mp)^2);
C1 = -delta*wn + 1j*wn*sqrt(1-delta^2);
C2 = conj(C1);

% Observer design
%lambda_o = 5 * abs(C1); % Observer eigenvalue (5x controller bandwidth)
lambda_o = (-delta*wn)+j*wn*sqrt(1-delta^2)*5;
%lambda_o = -delta*wn*5;

%L = lambda_o - (1/Tm); 
L=acker(A(2,2), A(1,2), lambda_o);
%  reduced-order observer dynamics
Ao = -1/Tm - L;
Bo = [B(2), Ao*L];  % B(2) = drv.dcgain*mot.Kt/(gbox.N1*mot.Req*Jeq)
Co = [0; 1];
Do = [0, 1; 0, L];

% Verify stability
eig(Ao);

% Experimental sampling times
T = 0.001*50;  
% Discrete observer matrices
Phi_o = 1 + Ao * T;      
Gamma_o = Bo * T;
Ho = Co;
Jo = Do;