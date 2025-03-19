close all;
clear all;
clc;

%%
data
ModelParams

%% PID design
ts=0.15;
alpha = 4;
mp=0.1;
num1 = log(1/mp);
den1 = sqrt(pi^2 + (num1)^2);
delta = num1/den1;
wgc = 3/(delta * ts);
num2 = 2*delta;
den2 = sqrt(sqrt(1+4*delta^4) - 2 * delta^2);
phim = atan(num2/den2) ;%* 180 / pi; % in degree
%phim = num2/den2;
%% Transfer function
num = km;
den = n*1i*wgc*(tm*1i*wgc+1);
p=num/den;

%% 
deltak =1/abs(p);
deltaphi = -pi + phim - angle(p);
abs_p = abs (p) ;
angle_p = angle(p) ;
Kp=deltak*cos(deltaphi);
Td = (tan(deltaphi)+(sqrt(tan(deltaphi)^2 +(alpha/4)))) / (2*wgc) ;
Ti = alpha * Td;
Kd = Kp * Td;
Ki = Kp / Ti;

cut_off = 0.4 * deltak;
tl = 1/cut_off;
%% PARAMETER ESTIMATION
delta_est = 1/sqrt(2);
wc=2*pi*20;

%% Inertia estimation

% Substitute these with the estimated values when available
Beq = 2.0e-6;
tau_sf = 1.0e-2;

% Computing averages on constant windows
T = 2;
N_periods = 10;
window1 = [0.4, 0.9];  % First window in seconds
window2 = [1.4, 1.9];  % Second window in seconds
avg_values = zeros(N_periods, 2); % Store average values for each period
signal = out.a_m.signals.values;
t=out.a_m.time;
for k = 1:N_periods
    % Define time limits for this period
    t_start = (k-1) * T;
    
    % Extract indices for the two windows in this period
    idx1 = (t >= t_start + window1(1)) & (t < t_start + window1(2));
    idx2 = (t >= t_start + window2(1)) & (t < t_start + window2(2));
    
    % Compute the mean in each window
    avg_values(k,1) = mean(out.a_m.signals.values(idx1));
    avg_values(k,2) = mean(out.a_m.signals.values(idx2));
end

% Display results
disp('Averages for each period:');
disp(array2table(avg_values, 'VariableNames', {'Window1', 'Window2'}));

% Plot signal with highlighted windows
figure;
plot(t, signal, 'k'); hold on;
for k = 1:N_periods
    t_start = (k-1) * T;
    fill([t_start+window1(1), t_start+window1(2), t_start+window1(2), t_start+window1(1)], ...
         [min(signal), min(signal), max(signal), max(signal)], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
    fill([t_start+window2(1), t_start+window2(2), t_start+window2(2), t_start+window2(1)], ...
         [min(signal), min(signal), max(signal), max(signal)], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
end
xlabel('Time (s)');
ylabel('Signal Value');
title('Periodic Signal with Averaging Windows');
legend({'Signal', 'Window 1', 'Window 2'});
grid on;

