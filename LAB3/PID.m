clear all;
close all;
clc;

%% Load datasheet
addpath('..\..\CELAB-Labs\utilities\');
datasheet;
datasheet_resonant;

%% Beq, Jeq_hat, tau_sf
load('..\utilities\black-box-estimation.mat');
%% PID
s = tf('s'); % Definizione della variabile di Laplace

% Calcolo diretto di Dτ(s)
% D_tau = (Jeq_hat*s^2 + Beq*s + k/N^2)*(Jb*s^2 + Bb*s + k) - (k/N^2);
% num = [Jb,Bb,k];
% den = D_tau;
% P = (1/N)*(Jb*s^2+Bb*s+k)/D_tau;
D_tau_prime = Jeq_hat*Jb*s^3+(Jeq_hat*Bb+Jb*Beq)*s^2+(Beq*Bb+k*(Jeq_hat+Jb/(N^2)))*s+k*(Beq+Bb/(N^2));
P = (k_drv*Kt*k)/(N*s*(Req*D_tau_prime+Kt*Ke*(Jb*s^2+Bb*s+k)));
ts = 0.85;   
mp = 0.3;
alpha = 4;
delta = log(1/mp) / sqrt(pi^2 + log(1/mp)^2);
wgc = 3 / (delta * ts);
% [Kp, Ki, Kd, tl, wgc] = designPIDBode(P, ts, mp, alpha);
TL = 1/(10* wgc);   
TD = 0.1;               
TI = alpha*TD;
C_base = 1 + 1/(TI*s) + (TD*s)/(TL*s + 1);
[magP, phaseP] = bode(P, wgc);
[magC, phaseC] = bode(C_base, wgc);
Kp = 1/(magP * magC);
Ki = Kp / TI;          
Kd = Kp * TD;
C = Kp * (1 + 1/(TI*s) + (TD*s)/(TL*s + 1));
L = C * P;


disp(['Kp: ', num2str(Kp)])
disp(['Ki: ', num2str(Ki)])
disp(['Kd: ', num2str(Kd)])

Tw = ts/5;
K_w = 1/Tw*0.05;