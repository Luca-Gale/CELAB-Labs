%% Load datasheet into workspace
clear
close all
clc

addpath('../LAB0/')
addpath('../utilities/')
load black-box-estimation.mat
datasheet;
%% Parameters and matrices
Tm = (mot.Req * Jeq_hat) / (mot.Req * Beq + mot.Kt*mot.Ke);
Km = (drv.dcgain*mot.Kt) / (mot.Req * Jeq_hat);

% State-space matrices
A = [0    1;
     0 -1/Tm];
B = [0;
     Km/(gbox.N1*Tm)];
C = [1 0];
D = 0;

Mp = 0.1;           % Over Shoot Percent
Ts = 0.15;          % Settling Time with 5 Percent
Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / Ts;
C1 = -Zeta * Wn + 1j * Wn * sqrt(1 - Zeta^2);
C2 = conj(C1);
CtrlPoles = [C1, C2];
K = place(A, B, CtrlPoles);

% REDUCED ORDER OBSERVER DESIGN
lambda_o = 5 * abs(C1);  % 5x controller bandwidth

L = -lambda_o - (-1/Tm);% Observer gain  

% Observer matrices (for implementation)
Ao = -1/Tm - L;
Bo = [B(2), Ao*L];  
Co = [0; 1];        % Output matrix for observer
Do = [0 1; 0 L];    % Feedthrough matrices
