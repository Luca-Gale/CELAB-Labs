% TODO : Complete the PROJECT STRUCTURE OVERVIEW

% IMPORTANT: add 'utilities' folder to path

%% Load datasheet into workspace
datasheet;                            

%% Filters parameters
delta_est = 1/sqrt(2);
wc = 2*pi*20;

% Estimated Parameters
Jeq_hat = 5.801020129074022e-05;      % Equivalent Inertia [kg.m^2]
Beq = 1.223604206496999e-06;          % Equivalent Viscous Friction [Nm/(mot.Rd/s)]
Tau_sf = 0.005709536387019;           % Static Friction [Nm]

% Recalculating Constants
Tm = (mot.Req * Beq + mot.Kt*mot.Ke) / (mot.Req * Jeq_hat);
km = (drv.dcgain * mot.Kt) / (gbox.N * mot.Req * Jeq_hat);

%% PID anti-windup parameters
ts = 0.15;
mp = 0.1;
alpha = 84;
delta = log(1/mp) / ...
        sqrt(pi^2 + (log(1/mp))^2);

wgc = 3 / (delta * ts);
phim = atan2(2 * delta, ...
             sqrt(sqrt(1 + 4*delta^4) - 2*delta^2));

Tw = ts/5;
Kw = 1/Tw;
% Transfer function
beq = 0;
km = (drv.dcgain * mot.Kt) / ...
     (mot.Req*beq + mot.Kt*mot.Ke);
Tm = (mot.Req*mld.Jeq) / ...
     (mot.Req*beq + mot.Kt*mot.Ke);
P = km / ...
    (gbox.N*1i*wgc * (Tm*1i*wgc + 1));

% Controller Bode Gain
abs_P = abs(P);
deltak = 1/abs_P;
deltaphi = -pi + phim - angle(P);
% Controller Gains
Kp = deltak * cos(deltaphi);
tanphi = tan(deltaphi);
Td = (tanphi + sqrt(tanphi^2 + 4/alpha)) / ...
     (2*wgc);
Ti = alpha * Td;
Kd = Kp * Td;
Ki = Kp / Ti;

tl = 1/(3*wgc);
%% feedforward compensation parameters
% Parameters from prof
Beq_p = 1.41e-6;
Jeq_p = 6.54e-7;
tau_sf_p = 7.02e-3;

k_drv = (1 + drv.R3/drv.R4) * drv.R2/(drv.R1 + drv.R2);
%inertia comp
I_C = (gbox.N * mot.Req * Jeq_p)/(k_drv  * mot.Kt);
%friction comp
F_C = mot.Req/(k_drv * mot.Kt * gbox.N);
%BEMF comp
B_C = (gbox.N * mot.Ke)/k_drv;
%% load data
Tau_sf = 0.005709536387019;
Jl = mld .JD + 3* gbox .J72 ;
Jeq = mot.J + (Jl / gbox .N1 ^2) ;
%Jeq = 5.801020129074022e-05;
Beq = 1.223604206496999e-06;

wn = 3/(delta_est * ts); % ERRORE
%delta2 = log(1/mp) / sqrt((pi*pi) +(log(1/mp)*log(1/mp)));

%% high pass ("real derivative")
delta_h1 = 1 / sqrt(2);
wc = 2*pi*50;

%% State Space
Tm = (mot.Req * Jeq)/(mot.Req*Beq + mot.Kt*mot.Ke);
A = [0, 1;0, -1/Tm];
B = [0; drv.dcgain*mot.Kt/(gbox.N1*mot.Req*Jeq)];
C = [1, 0];
D = 0;

M = [A, B;C, D];
Ans = M \ [0; 0; 1];
Nx = Ans(1:2,1);
Nu = Ans(3,1);
pole1 = (-delta_est * wn) + 1j*wn*sqrt(1-delta_est^2);
pole2 = (-delta_est * wn) - 1j*wn*sqrt(1-delta_est^2);
poles = [pole1,pole2];
K = acker(A,B,poles);
Nr = Nu + K*Nx;

%% part 2
sigma = real(pole1);
omega_d = imag(pole1);
% poles2 = [sigma+1i*omega_d sigma-1i*omega_d sigma ];
poles2 = sigma * ones (3 ,1);
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 2* sigma ];
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 3*sigma ];
Ae =[0  ,C; zeros(2, 1), A ];
Be= [0 ; B];
Ce =[0 C]; 

K_robust  = acker (Ae , Be , poles2 );
KI = K_robust(1);
K2 = K_robust(2:3);