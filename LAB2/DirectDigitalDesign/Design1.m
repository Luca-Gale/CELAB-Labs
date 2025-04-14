clear
close all
clc

% Load the Model and the Params
addpath('../../LAB0/')
addpath('../../utilities/')
load black-box-estimation.mat
datasheet;

%% Primary Parameter Declaration
% System Model
Tm = (mot.Req * Jeq_hat)/(mot.Req*Beq + mot.Kt*mot.Ke);
A = [0, 1;0, -1/Tm];
B = [0; drv.dcgain * mot.Kt/(gbox.N1 * mot.Req * Jeq_hat)];
C = [1, 0];
D = 0;

% Desired Second Order System Characteristics
Mp = 0.1;                     % Over Shoot Percent
SettlingTime = 0.15;          % Settling Time with 5 Percent

Zeta = log(1/Mp) / sqrt(pi^2 + log(1/Mp)^2);
Wn = 3 / Zeta / SettlingTime;

Sigma = ss(A, B, C, D);

% Discretize the System
TsCand = [1, 10, 50] / 1000;

load_system("Part1.slx");

for i = 1:numel(TsCand)
    
    % Sampling Time
    Ts = TsCand(i);

    Sigma_d = c2d(Sigma, Ts, 'zoh');
    [F, G, H, J] = ssdata(Sigma_d);

    %% Reduced Order Observer Design
    DesiredEig = 0.05;
    L = (F(2, 2) - DesiredEig) / F(1, 2);

    Ao = F(2, 2) - L * F(1, 2);
    Bo = [G(2) - L * G(1), Ao * L + F(2, 1) - L * F(1, 1)];
    Co = [0; 1];
    Do = [0, 1; 0, L];

    %% Controller Design

    % Controller Gain Matrix
    % p = -Zeta * Wn + 1j * Wn * sqrt(1 - Zeta^2);
    p = Wn * exp(1j*(-pi + pi/3));
    DesiredPoles = [p, conj(p)];
    DesiredPoles = exp(DesiredPoles * Ts);

    K = place(F, G, DesiredPoles);

    % Feedforward Gains
    Coefs = [F - eye(2), G; H, 0] \ [0; 0; 1];
    Nx = Coefs(1:2);
    Nu = Coefs(end);

    Nr = Nu + K * Nx;

    %% Simulate the System and Plot the Results
    out = sim("Part1.slx");

    figure("Name", string(i), "Units", "normalized", "OuterPosition", [0, 0, 1, 1]);
    stairs(out.X.Time, out.X.Data, 'LineWidth', 2, 'DisplayName', 'Nominal Model Output'); hold on
    stairs(out.XBB.Time, out.XBB.Data, 'LineWidth', 2, 'DisplayName', 'Black Box Model Output');
    xlabel("Time [sec]")
    ylabel("Motor Position [degree]")
    title(['Discretizating with Ts = ' num2str(Ts)])
    grid on
    hold on
    legend
    
end
close_system("Part1.slx");