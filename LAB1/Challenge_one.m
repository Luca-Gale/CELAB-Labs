%% Load datasheet into workspace
addpath("../utilities/")
datasheet; 

% Estimated Parameters
load('black-box-estimation.mat');

% Recalculating Constants
km = (drv.dcgain * mot.Kt) / (mot.Req * Beq + mot.Kt * mot.Ke);
Tm = (mot.Req * Jeq_hat) / (mot.Req * Beq + mot.Kt*mot.Ke);


%% PID anti-windup parameters
% Controller Design Params
ts    = 0.15;
alpha = 84;             % Anything Above 84 Works!!!
mp    = 0.1;

[Kp, Ki, Kd, tl] = designPIDBode(km, Tm, gbox, ts, mp, alpha);

%% Tune the antiwindup parameter
gainRange = linspace(4,8,20);
tuneAntiwindupParallel(gainRange, 'Simulink_challenge_one.slx', 'antiwindup_chllenge.mat');

% Best antiwindup gin found
%aw_best = 5.0408;
%% Analize step response

% if ~evalin('base', 'exist(''out'', ''var'')')
%     warning('Variable ''out'' not found in base workspace.');
% else
%     out = evalin('base', 'out');
% 
%     try
%         ref = out.logsout{2}.Values;
%         y = out.logsout{1}.Values;
%     catch
%         error('The ''out'' object does not contain ref and y.');
%     end
% 
%         [riseTime, settlingTime, overshoot] = analyze_step_response(ref, y);
%         fprintf('\n--- Step Response Analysis ---\n');
%         fprintf('Rise Time     : %.4f s\n', riseTime);
%         fprintf('Settling Time : %.4f s\n', settlingTime);
%         fprintf('Overshoot     : %.2f %%\n', overshoot); 
%         fprintf('-------------------------------\n\n');
% end