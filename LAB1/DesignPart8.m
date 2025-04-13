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

% Specify Poles
L1 = 2*Wn*exp(1j*(-pi + pi/4));
L2 = conj(L1);
L3 = 2*Wn*exp(1j*(-pi + pi/6));
L4 = conj(L3);
L5 = -2*Wn;

Lambda = [L1, L2, L5];

%% Design and Validate (Part 8)

% Load System
load_system("Part8.slx");

% Exo-System Creation
Ar = 0;
Br = 0;
Cr = 40;
Dr = 0;

% Create the Augmented System
Az = [Ar, C; zeros(2, 1), A];
Bz = [0; B];

% Controller Design
K = place(Az, Bz, Lambda);
K = real(K);

% Simulate the System
out = sim("Part8.slx");

% Extract Data
t      = out.tout;
Xtilde = out.Xtilde.Data;
Ytilde = out.Ytilde.Data;
X      = out.X.Data;
Y      = out.Y.Data;
Ref    = out.Ref.Data;

% Plot
fig = figure('Name', 'Part 8. Experiment', ...
             'Units', 'normalized', ...
             'OuterPosition', [0, 0, 1, 1]);
subplot(2, 2, 1);
plot(t, Xtilde, 'LineWidth', 2);
xlabel("t [s]")
ylabel("States")
title("State Space Model States")
grid on

subplot(2, 2, 2);
plot(t, Ytilde, 'LineWidth', 2, 'DisplayName', 'Output'); hold on
plot(t, Ref, '--', 'LineWidth', 2, 'DisplayName', 'Desired Output');
xlabel("t [s]")
title("State Space Model Output")
legend
grid on

subplot(2, 2, 3);
plot(t, X, 'LineWidth', 2);
xlabel("t [s]")
ylabel("States")
title("BB Model States")
grid on

subplot(2, 2, 4);
plot(t, Y, 'LineWidth', 2, 'DisplayName', 'Output'); hold on
plot(t, Ref, '--', 'LineWidth', 2, 'DisplayName', 'Desired Output');
xlabel("t [s]")
title("BB Model Output")
legend
grid on

sgtitle('Part 8. Step Signal', 'FontSize', 25, 'FontWeight', 'Bold')

% Close System
close_system("Part8.slx");