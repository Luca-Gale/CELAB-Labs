%clc
%clear all

%% load data
Init

Tau_sf = 0.005709536387019;
Jl = mld .JD + 3* gbox .J72 ;
Jeq = mot.J + (Jl / gbox .N1 ^2) ;
%Jeq = 5.801020129074022e-05;
Jeq = 6.51e-07;
Beq = 1.223604206496999e-06;
wn = 3/(delta * ts);
%delta2 = log(1/mp) / sqrt((pi*pi) +(log(1/mp)*log(1/mp)));

%% high passs ("real derivative")
delta_h1 = 1/sqrt(2);
wc = 2*pi*50;

%% State Space
Tm = (mot.Req * Jeq)/(mot.Req*Beq + mot.Kt*mot.Ke);
A = [[0 1 ],
    [0 -1/Tm]];
B = [0,
    drv.dcgain*mot.Kt/(gbox.N1*mot.Req*Jeq)];
C = [1 0];
D = 0;

M = [[A B],
    [C D]];
M_inv = inv(M);
Ans = M_inv * [0;0;1];
Nx = Ans(1:2,1);
Nu = Ans(3,1);
pole1 =(-delta * wn) + j*wn*sqrt(1-delta^2);
pole2 = (-delta * wn) - j*wn*sqrt(1-delta^2);
poles = [pole1,pole2];
K = acker(A,B,poles);
Nr=Nu+K * Nx;

%% part 2
sigma = real ( pole1 );
omega_d = imag ( pole1 );
%poles2 = [sigma+1i*omega_d sigma-1i*omega_d sigma ];
poles2 = sigma * ones (3 ,1);
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 2* sigma ];
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 3*sigma ];
Ae =[0  ,C; zeros(2, 1), A ];
Be= [0 ; B];
Ce =[0 C]; 

K_robust  = acker (Ae , Be , poles2 );
KI = K_robust(1);
K2 = K_robust(2:3);
%% plotting with different poles
load('first.mat');
load('second.mat');
load('third.mat');
load('fourth.mat');
figure;
hold on;
title('40 Step');
plot(first.time,first.signals.values)
plot(first.time,second.signals.values)
plot(first.time,third.signals.values)
plot(first.time,fourth.signals.values)
legend({'First', 'Second','Third','Fourth'}, 'Location', 'best');
figure;
hold on;
title('40 Step Error');
plot(first.time,40-first.signals.values)
plot(first.time,40-second.signals.values)
plot(first.time,40-third.signals.values)
plot(first.time,40-fourth.signals.values)
legend({'First', 'Second','Third','Fourth'}, 'Location', 'best');