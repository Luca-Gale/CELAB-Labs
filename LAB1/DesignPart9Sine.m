clear
close all
clc

% Load the Model and the Params
Init
addpath('../LAB0/')

%% Primary Parameter Declaration
% Estimated Parameters
Jeq_hat = 5.801020129074022e-05;      % Equivalent Inertia [kg.m^2]
Beq = 1.223604206496999e-06;          % Equivalent Viscous Friction [Nm/(mot.Rd/s)]
Tau_sf = 0.005709536387019;           % Static Friction [Nm]

% Recalculating Constants
Tm = (mot.Req * Beq + mot.Kt*mot.Ke) / (mot.Req * Jeq_hat);
km = (drv.dcgain * mot.Kt) / (gbox.N * mot.Req * Jeq_hat);

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

% Desired Poles
CtrlPoles = -Zeta * Wn + 1j * Wn * sqrt(1 - Zeta^2) * [-1 1];
ObsvPoles = 2*Wn * exp(1j*(-pi + [pi/3, -pi/3, pi/6, -pi/6, 0]));

%% Reference + Disturbance Exo-System
% Input Specifications
TrCandidates = [0.15, 0.25, 1, 0.5];     % Sine Sig Period Candidates
AmpRef = 40;
Cw = 1;

% Make the Simulation Ready
load_system("Part9Sine.slx");


for i = 1:numel(TrCandidates)
    Tr = TrCandidates(i);   % Reference Period

    % Exo-System Creation
    W0 = 1/Tr;
    Arho = [0, 1, 0; 0, 0, 1; 0, -W0^2, 0];
    Brho = zeros(3, 1);
    Crho = [Cw, 0, 0];
    Drho = 0;

    %% Create the Extended Plant Model
    Ae = [Arho, zeros(size(Arho, 1), size(A, 1)); B*Crho, A];
    Be = [zeros(size(Arho, 1), 1); B];
    Ce = [zeros(1, size(Arho, 1)), C];

    % Pole Placement
    K = place(  A,   B, CtrlPoles);
    L = place(Ae', Ce', ObsvPoles)';

    K = real(K);
    L = real(L);

    Krho = [Crho, K];

    %%% Simulate the System and Plot Results
    out = sim("Part9Sine.slx");

    % Extract Data
    t    = out.tout;
    Ref  = out.Ref.Data;
    YBB  = out.YBB.Data;
    YNom = out.YNominal.Data;

    % Plotting
    figure('Name', ['Part 9. Experiment ' num2str(i)], ...
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
end

% Close System
close_system("Part9Sine.slx");