clear
close all
clc

% Load the Model and the Params
Init
addpath('../LAB0/')

%% Primary Parameter Declaration
% Estimated Parameters
Jeq_hat = 5.801020129074022e-07;      % Equivalent Inertia [kg.m^2]
Beq = 1.223604206496999e-06;          % Equivalent Viscous Friction [Nm/(mot.Rd/s)]
Tau_sf = 0.005709536387019;           % Static Friction [Nm]

% Recalculating Constants
a22 = (mot.Req * Beq + mot.Kt*mot.Ke) / (mot.Req * Jeq_hat);
b2 = (drv.dcgain * mot.Kt) / (gbox.N * mot.Req * Jeq_hat);

% State-Space Matrices
A = [0, 1; 0, a22];
B = [0, b2]';
C = [1, 0];
D = 0;

delta_est = 1/sqrt(2);
wc = 2*pi*50;

%% Design and Test
% Desired Second Order System Characteristics
Mp = 0.1;           % Over Shoot Percent
Ts = 0.15;          % Settling Time with 5 Percent

Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / Ts;

% Desired Poles
lamc1 = -Zeta * Wn + 1j * Wn * sqrt(1 - Zeta^2);
CtrlPoles = [lamc1, conj(lamc1)];

% lame1 = Wn * exp(1j*(-pi + pi/6));
% lame2 = Wn * exp(1j*(-pi + pi/12));
% lame3 = -Wn;
% lame4 = conj(lame2);
% lame5 = conj(lame1);
% ObsvPoles = [lame1, lame2, lame3, lame4, lame5];

lame1 = 2*Wn * exp(1j*(-pi + pi/12));
lame2 = -2*Wn;
lame3 = conj(lame1);
ObsvPoles = [lame1, lame2, lame3];

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
return

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