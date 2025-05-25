% This script is to automatize the parameters estimation on the actual
% motor, not on the blackbox model as we have done so far.

% Instructions: set up the realtime simulink as in RealTimeSimulation.slx
% Run the experiment with 1st input and run first subsection
% Repeat for 2nd and 3rd esperiments and subsections
% At the end in 'real-time-estimation.mat' the parameters estimated in the
% real motor will be saved.

%% Positive velocity friction estimation
w_m_mean = window_average(w_m, 5, 9, [1, 4], [], 1);
tau_m_mean = window_average(tau_m, 5, 9, [1, 4], [], 1);
Phi_T = [w_m_mean (1/gbox.N)*sign(w_m_mean)];
Y = tau_m_mean;
thLS_hat = Phi_T\Y;
Beq_hat_pos = thLS_hat(1);
tau_sf_pos = thLS_hat(2);
save('real-time-estimation', "Beq_hat_pos", "tau_sf_pos");

%% Negative velocity friction estimation
w_m_mean = window_average(w_m, 5, 9, [1, 4], [], 1);
tau_m_mean = window_average(tau_m, 5, 9, [1, 4], [], 1);
Phi_T = [w_m_mean (1/gbox.N)*sign(w_m_mean)];
Y = tau_m_mean;
thLS_hat = Phi_T\Y;
Beq_hat_neg = thLS_hat(1);
tau_sf_neg = thLS_hat(2);
save('real-time-estimation', "Beq_hat_neg", "tau_sf_neg", '-append');

%% Final friction computation
data = load('real-time-estimation.mat');
Beq = (data.Beq_hat_pos + data.Beq_hat_neg)/2;
tau_sf = (abs(data.tau_sf_pos)+abs(data.tau_sf_neg))/2;
save('real-time-estimation', "Beq", "tau_sf", '-append');

%% Inertia estimation
% a_m.signals.values = a_m.signals.values * 1000;
a_m_mean = window_average(a_m, 2, 10, [0.4, 0.9], [1.4, 1.9], 1);
tau_i_mean = window_average(tau_i, 2, 10, [0.2, 0.8], [1.2, 1.8], 1);

% Computing estimated inertia
N_periods = 10;
avg = 0;
for k = 1:N_periods
    new = ( (tau_i_mean(k,1) - tau_i_mean(k,2)) / (a_m_mean(k,1) - a_m_mean(k,2)) );
    avg = avg + new;
end

Jeq_hat = avg/N_periods;
save('real-time-estimation', "Jeq_hat", '-append');