% TODO : Complete the PROJECT STRUCTURE OVERVIEW

% IMPORTANT: add 'utilities' folder to path

%% Load datasheet into workspace
addpath("../utilities/")
datasheet;                            

%% Filters parameters
%delta_est = 1/sqrt(2);
%wc = 2*pi*20;

%% Estimated Parameters for black box model
load('black-box-estimation.mat');

%% PID design (using estimated params)
km = (drv.dcgain * mot.Kt) / (mot.Req * Beq + mot.Kt * mot.Ke);
Tm = (mot.Req * Jeq_hat) / (mot.Req * Beq + mot.Kt*mot.Ke);

ts    = 0.15;
alpha = 84;             % Anything Above 84 Works!!!
mp    = 0.1;

s = tf('s');
P = km/(Tm*s+1)*N;
[Kp, Ki, Kd, tl, wgc] = designPIDBode(P, ts, mp, alpha);

%save('../utilities/PID_gains_with_estimated_params', 'Kp', 'Kd', 'Ki', 'tl', 'wgc');

%% Anti windup 
% Uncomment to use the optimizer
% gainRange = linspace(0,0.1,10);
%tuneAntiwindupParallel(gainRange, 'Copy_of_PID_Validation.slx', 'antiwindup_results.mat');

Tw = ts/5;
Kw = 1/Tw*0.05;

%% Feedforward compensation parameters
% Parameters from prof
%Beq_p = 1.41e-6;
%Jeq_p = 6.54e-7;
%tau_sf_p = 7.02e-3;

% Load Beq, Jeq_hat, tau_sf
load('black-box-estimation.mat');

% Inertia comp
I_C = (gbox.N * mot.Req * Jeq_hat)/(drv.dcgain * mot.Kt);
% Friction comp
F_C = mot.Req/(drv.dcgain * mot.Kt * gbox.N);
% BEMF comp
B_C = (gbox.N * mot.Ke)/drv.dcgain;


%% High pass filter ("real derivative")
delta_h1 = 1 / sqrt(2);
wc = 2*pi*50;

%% State Space
Tm = (mot.Req * Jeq_hat) / (mot.Req*Beq + mot.Kt*mot.Ke);
km = (drv.dcgain * mot.Kt) / (mot.Req * Beq + mot.Kt * mot.Ke);
A = [0, 1;0, -1/Tm];
B = [0; km/gbox.N1/Tm];
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

%% Tune the antiwindup parameter
% gainRange = linspace(0,0.1,10);
% tuneAntiwindupParallel(gainRange, 'Copy_of_PID_Validation.slx', 'antiwindup_results.mat');
% 

