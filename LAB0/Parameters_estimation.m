%% 


%% FRICTION ESTIMATOR
% Computing averages on constant windows
w_m_acc_mean = friction_window_average(out.w_m_acc, 5, 0, 9, [1, 4], 1);
w_m_dec_mean = friction_window_average(out.w_m_dec, 5, 45, 9, [1, 4], 1);

tau_m_acc_mean = friction_window_average(out.tau_m_acc, 5, 0, 9, [1, 4], 1);
tau_m_dec_mean = friction_window_average(out.tau_m_dec, 5, 45, 9, [1, 4], 1);

Phi_T_acc = [w_m_acc_mean (1/n)*sign(w_m_acc_mean)];
Y_acc = [tau_m_acc_mean];

theta_hat_LS_acc = inv(Phi_T_acc' * Phi_T_acc) * Phi_T_acc' * Y_acc;

Phi_T_dec = [w_m_dec_mean (1/n)*sign(w_m_dec_mean)];
Y_dec = [tau_m_dec_mean];

theta_hat_LS_dec = inv(Phi_T_dec' * Phi_T_dec) * Phi_T_dec' * Y_dec;

%% Inertia estimation
% Substitute these with the estimated values when available
Beq = 2.0e-6;
tau_sf = 1.0e-2;

% Run simulation
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
    disp(new);
end
Jeq_hat = avg/N_periods;