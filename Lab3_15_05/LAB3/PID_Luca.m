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
s = tf('s');

D_tau_prime = mld.Jeq * mld.Jb * s^3 + (mld.Jeq * mld.Bb + mld.Jb * Beq) * s^2 + (Beq * mld.Bb + k * (mld.Jeq + (mld.Jb / N^2))) * s + k * (Beq + (mld.Bb / N^2));

P = (1 / (N * s)) * (k_drv * Kt * (mld.Jb * s^2 + mld.Bb * s + k)) / ((Req * D_tau_prime) + Kt * Ke * (mld.Jb * s^2 + mld.Bb * s + k));

t_s = 0.70;                         %settling time <=85s
M_p = 0.3;                          %overshoot <=30%
[Kp, Ki, Kd, ~, wgc] = designPIDBode(P, t_s, M_p, alpha);

% Assign outputs to workspace variables
assignin('base', 'Kp', Kp);
assignin('base', 'Ki', Ki);
assignin('base', 'Kd', Kd);
assignin('base', 'wgc', wgc);

tl = 1/(10*wgc);                   %cutoff frequency
T_w = t_s/5;
Kw = 1/T_w;

t0 = 0.2;
t1 = 0.7;

omegac=2*pi*50;
deltafil=2^(-0.5);
%%
%info = stepinfo(out.y.signals.values, out.y.time, out.ref.signals.values(end))
