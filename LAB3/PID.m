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
D_tau_prime = mld.Jeq * mld.Jb * s^3 + (mld.Jeq * mld.Bb + mld.Jb * Beq) * s^2 + (Beq * mld.Bb + k * (mld.Jeq + (mld.Jb / N^2))) * s + k * (Beq + (mld.Bb / N^2));

P = (1 / (N * s)) * (k_drv * Kt * (mld.Jb * s^2 + mld.Bb * s + k)) / ((Req * D_tau_prime) + Kt * Ke * (mld.Jb * s^2 + mld.Bb * s + k));
ts = 0.7;   
mp = 0.3;
alpha = 4;
delta = log(1/mp) / sqrt(pi^2 + log(1/mp)^2);
wgc = 3 / (delta * ts);
[Kp, Ki, Kd, tl, wgc] = designPIDBode(P, ts, mp, alpha);
% TL = 1/(10* wgc);   
% TD = 0.1;               
% TI = alpha*TD;
% C_base = 1 + 1/(TI*s) + (TD*s)/(TL*s + 1);
% [magP, phaseP] = bode(P, wgc);
% [magC, phaseC] = bode(C_base, wgc);
% Kp = 1/(magP * magC);
% Ki = Kp / TI;          
% Kd = Kp * TD;
% C = Kp * (1 + 1/(TI*s) + (TD*s)/(TL*s + 1));
% L = C * P;


disp(['Kp: ', num2str(Kp)])
disp(['Ki: ', num2str(Ki)])
disp(['Kd: ', num2str(Kd)])

Tw = ts/5;
Kw = 1/Tw*0.05;