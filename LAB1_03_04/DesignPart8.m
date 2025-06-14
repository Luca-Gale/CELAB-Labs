clear
close all
clc

% Load the Model and the Params
Init
addpath('../LAB0/')

%% Primary Parameter Declaration
% State-Space Matrices
A = [0, 1; 0, -1/Tm];
B = [0, km/(gbox.N*Tm)]';
C = [1, 0];
D = 0;

%% Design and Test
% Desired Second Order System Characteristics
Mp = 0.1;           % Over Shoot Percent
Ts = 0.15;          % Settling Time with 5 Percent

Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / Ts;

% Specify Poles
Lambda = Wn * exp(1j*(-pi + [pi/4, -pi/4, pi/6, -pi/6, 0]));


%% Design and Validate (Part 8)

% Load System
load_system("Part8.slx");

% Exo-System Creation
Ar = 0;
Br = 0;
Cr = 90;
Dr = 0;

% Create the Augmented System
Az = [Ar, C; zeros(2, 1), A];
Bz = [0; B];

% Controller Design
K = place(Az, Bz, Lambda(1:end-2));
K = real(K);

% Simulate the System
out = sim("Part8.slx");

% Extract Data
t      = tout;
Xtilde = Xtilde.Data;
Ytilde = Ytilde.Data;
X      = X.Data;
Y      = Y.Data;
Ref    = Ref.Data;

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