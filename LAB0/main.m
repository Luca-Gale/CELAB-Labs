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
phim = atan(num2/den2);%* 180 / pi; % in degree

% Transfer function
num = km;
den = n*1i*wgc*(tm*1i*wgc+1);
p=num/den;

% 
deltak = 1/abs(p);
deltaphi = -pi + phim - angle(p);
abs_p = abs(p);
angle_p = angle(p);
Kp=deltak*cos(deltaphi);
Td = (tan(deltaphi)+(sqrt(tan(deltaphi)^2+(4/alpha)))) / (2*wgc);
Ti = alpha * Td;
Kd = Kp * Td;
Ki = Kp / Ti;

%cut_off = 0.4 * deltak;
tl = 1/(3*wgc); % proportional coefficient between 2-5. Chosen 3

%% PARAMETER ESTIMATION
delta_est = 1/sqrt(2);
wc=2*pi*20;

%% Inertia estimation
% Substitute these with the estimated values when available
Beq = 2.0e-6;
tau_sf = 1.0e-2;

% Computing averages on constant windows
a_m_mean = window_average(out.a_m, 2, 10, [0.4, 0.9], [1.4, 1.9], 0);
tau_i_mean = window_average(out.tau_i, 2, 10, [0.2, 0.8], [1.2, 1.8], 0);

% Computing estimated inertia
N_periods = 10;
avg = 0;
for k = 1:N_periods
    new = ( (tau_i_mean(k,1) - tau_i_mean(k,2)) / (a_m_mean(k,1) - a_m_mean(k,2)) );
    avg = avg + new;
    disp(new);J
end
Jeq_hat = avg/N_periods;



