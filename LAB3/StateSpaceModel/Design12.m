clear
close all
clc

addpath('..\..\utilities\');
datasheet;
datasheet_resonant;
load('black-box-estimation.mat');

%% Parameter Declaration
kt = mot.Kt;
ke = mot.Ke;
kdrv = drv.dcgain;
N = gbox.N;
Jeq = mld.Jeq;
Req = mot.R + sens.curr.Rs;

% % Heads up for the Quanser Hub (No clue whats going on...)
% Jb = 2e-3;
% Jh = 5.1e-4;

%% Initialization

% State Space Model of the System
A = zeros(4);
A(1:2, 3:4) = eye(2);
A(3:4, 1:2) = [k/N^2/Jeq * [-1, 1]; [1, -1] * k/Jb];
A(3:4, 3:4) = diag([-1/Jeq * (Beq + kt*ke/Req), -Bb/Jb]);

B = zeros(4, 1);
B(3) = kt * kdrv / N / Jeq / Req;

Bd = zeros(4, 1);
Bd(3) = -1 / N^2 / Jeq;

T = eye(4);
T(2, 1) = 1;
T(4, 3) = 1;

% Change of Basis
Aprime = T \ A * T;
Bprime = T \ B;
Bdprime = T \ Bd;
Cprime = [1, 0, 0, 0];


%% Controller Design

% Desired Control Performance Metrics
RiseTime = 0.85;      % Rise Time
Mp = 0.3;               % Overshoot Percentage

% Second Order System to Approximate
Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / RiseTime;

% Desired Poles
Phi = atan2(sqrt(1 - Zeta^2), Zeta);

L1 = Wn * exp(1j*(-pi + Phi));
L2 = conj(L1);
L3 = Wn * exp(1j*(-pi + Phi/2));
L4 = conj(L3);

LambdaC = [L1, L2, L3, L4];

% State Feedback Controller Design
K = place(Aprime, Bprime, LambdaC);
% K = [0.56, 56, 0.0331, -0.4866];

% Nominal Tracking Gain
TmpGain = [Aprime, Bprime; Cprime 0] \ [zeros(4, 1); 1];
Nx = TmpGain(1:4);
Nu = TmpGain(end);

Nr = Nu + K * Nx;

%% State Estimator Params
Estimator.Wc = 2*pi*50;
Estimator.Delta = 1/sqrt(2);
Estimator.num = [Estimator.Wc^2, 0];
Estimator.den = [1, 2*Estimator.Wc*Estimator.Delta, Estimator.Wc^2];

%% Bias Estimation Timing
t0 = 0.2;
t1 = 0.7;