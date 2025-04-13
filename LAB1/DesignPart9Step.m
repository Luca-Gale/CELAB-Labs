clear
close all
clc

% Load the Model and the Params
addpath('../LAB0/')
load black-box-estimation.mat
datasheet;

%% Primary Parameter Declaration
% System Model
Tm = (mot.Req * Jeq_hat)/(mot.Req*Beq + mot.Kt*mot.Ke);
A = [0, 1;0, -1/Tm];
B = [0; drv.dcgain * mot.Kt/(gbox.N1 * mot.Req * Jeq_hat)];
C = [1, 0];
D = 0;

% State Estimation
delta_est = 1/sqrt(2);
wc = 2*pi*50;

%% Design and Test
% Desired Second Order System Characteristics
Mp = 0.1;           % Over Shoot Percent
Ts = 0.15;          % Settling Time with 5 Percent

Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / Ts;

% Desired Poles
C1 = -Zeta * Wn + 1j * Wn * sqrt(1 - Zeta^2);
C2 = conj(C1);
CtrlPoles = [C1, C2];

L1 = 2*Wn * exp(1j*(-pi + pi/12));
L2 = -2*Wn;
L3 = conj(L1);
ObsvPoles = [L1, L2, L3];

%% Reference + Disturbance Exo-System
% Input Specifications
Cw1 = deg2rad * 1;        % Disturbance Step Gain
Cw2 = deg2rad * 40;       % Reference Step Gain

% Make the Simulation Ready
load_system("Part9Step.slx");

% Exo-System Creation
Arho = 0;
Brho = 0;
Crho = 1; %[Cw1+Cw2];
Drho = 0;

%% Create the Extended Plant Model
Ae = [...
    Arho, zeros(size(Arho, 1), size(A, 1)); ...
    B*Crho, A];
Be = [zeros(size(Arho, 1), 1); B];
Ce = [zeros(1, size(Arho, 1)), C];

% Pole Placement
K = place(  A,   B, CtrlPoles);
L = place(Ae', Ce', ObsvPoles)';

%K = real(K);
%L = real(L);

Krho = [Crho, K];

%%% Simulate the System and Plot Results
out = sim("Part9Step.slx");

% Extract Data
t    = out.tout;
Ref  = out.Ref.Data;
YBB  = out.YBB.Data;
YNom = out.YNominal.Data;

% Plotting
figure('Name', 'Part 9. with Step Input', ...
    'Units', 'normalized', ...
    'OuterPosition', [0, 0, 1, 1]);
subplot(1, 2, 1)
plot(t, YNom, t, Ref, '--', 'LineWidth', 2)
legend("Output", "Reference")
xlabel("t [s]")
ylabel("System Output")
grid on
title("Nominal System Controller Performance", "FontSize", 24)

subplot(1, 2, 2)
plot(t, YBB, t, Ref, '--', 'LineWidth', 2)
legend("Output", "Reference")
xlabel("t [s]")
ylabel("System Output")
grid on
title("Black-Box System Controller Performance", "FontSize", 24)

% Close System
close_system("Part9Step.slx");