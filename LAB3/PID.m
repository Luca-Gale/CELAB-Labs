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
alpha = 4;
km = (drv.dcgain * mot.Kt) / (mot.Req * Beq + mot.Kt * mot.Ke);
Tm = (mot.Req * Jeq_hat) / (mot.Req * Beq + mot.Kt*mot.Ke);
t_s = 0.85;                         %settling time <=85s
M_p = 0.3;                          %overshoot <=30%
[Kp, Ki, Kd, tl, wgc] = designPIDBode(km, Tm, gbox, t_s, M_p, alpha);
T_l = 1/(10*wgc);                   %cutoff frequency
T_w = t_s/5;
K_w = 1/T_w;