% Entry point for parameters estimation. 
% Just run this file, no need to run the simulations on simulink,
% everything is automatised.

clear all;
close all;
clc;

%% FRICTION ESTIMATOR
load_system("Friction_Estimation.slx");
% Positive velocity
set_param(['Friction_Estimation' '/Manual Switch'], 'sw', '1'); % Set first input
out = sim("Friction_Estimation.slx");
w_m_mean = window_average(out.w_m, 5, 9, [1, 4], [], 1);
tau_m_mean = window_average(out.tau_m, 5, 9, [1, 4], [], 1);
Phi_T = [w_m_mean (1/gbox.N)*sign(w_m_mean)];
Y = tau_m_mean;
thLS_hat = Phi_T\Y;
Beq_hat_pos = thLS_hat(1);
tau_sf_pos = thLS_hat(2);

% Negative velocity
set_param(['Friction_Estimation' '/Manual Switch'], 'sw', '0'); % Set first input
out = sim("Friction_Estimation.slx");
w_m_mean = window_average(out.w_m, 5, 9, [1, 4], [], 1);
tau_m_mean = window_average(out.tau_m, 5, 9, [1, 4], [], 1);
Phi_T = [w_m_mean (1/gbox.N)*sign(w_m_mean)];
Y = tau_m_mean;
thLS_hat = Phi_T\Y;
Beq_hat_neg = thLS_hat(1);
tau_sf_neg = thLS_hat(2);

close_system('Friction_Estimation', 0);

Beq = (Beq_hat_pos + Beq_hat_neg)/2
tau_sf = (abs(tau_sf_pos)+abs(tau_sf_neg))/2

%% Not revisioned
% V_theta_LS_acc = (Y_acc - Phi_T_acc * theta_hat_LS_acc)' * (Y_acc - Phi_T_acc * theta_hat_LS_acc);
% lambda_square_acc = (1/(9 + 2)) * V_theta_LS_acc;
% cov_theta_LS_acc = lambda_square_acc * inv(Phi_T_acc' * Phi_T_acc);
% 
% V_theta_LS_dec = (Y_dec - Phi_T_dec * theta_hat_LS_dec)' * (Y_dec - Phi_T_dec * theta_hat_LS_dec);
% lambda_square_dec = (1/(9 + 2)) * V_theta_LS_dec;
% cov_theta_LS_dec = lambda_square_dec * inv(Phi_T_dec' * Phi_T_dec);
% 
% var_Beq_acc = cov_theta_LS_acc(1, 1);
% var_tau_sf_acc = cov_theta_LS_acc(2, 2);
% 
% var_Beq_dec = cov_theta_LS_dec(1, 1);
% var_tau_sf_dec = cov_theta_LS_dec(2, 2);
% 
% c = 1.96;
% Beq_Interval_Dec = Beq + c * sqrt(var_Beq_dec)*[-1, 1]
% Beq_Interval_Acc = Beq + c * sqrt(var_Beq_acc)*[-1, 1]
% 
% Tau_sf_Interval_Dec = tau_sf + c * sqrt(var_tau_sf_dec)*[-1, 1]
% Tau_sf_Interval_Acc = tau_sf + c * sqrt(var_tau_sf_acc)*[-1, 1]

%% Inertia estimation
load_system("Inertia_Estimation.slx");
out = sim("Inertia_Estimation.slx");

% Computing averages on constant windows
a_m_mean = window_average(out.a_m, 2, 10, [0.4, 0.9], [1.4, 1.9], 1);
tau_i_mean = window_average(out.tau_i, 2, 10, [0.2, 0.8], [1.2, 1.8], 1);

% Computing estimated inertia
N_periods = 10;
avg = 0;
for k = 1:N_periods
    new = ( (tau_i_mean(k,1) - tau_i_mean(k,2)) / (a_m_mean(k,1) - a_m_mean(k,2)) );
    avg = avg + new;
end

Jeq_hat = avg/N_periods

close_system('Inertia_Estimation', 0);