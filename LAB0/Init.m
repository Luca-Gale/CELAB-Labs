% PROJECT STRUCTURE OVERVIEW
%
% MATLAB Scripts (.m files):
% - Init.m                 : Automatically loads at the start of each simulation.  
%                            Contains datasheet values and PID controller design.  
% - Parameters_Estimation.m : Computes parameter estimations.  
%                             Runs respective Simulink simulations and processes the output.  
% - Plotting.m             : Handles visualization and plotting of simulation results.  
% - window_average.m       : Implements a window averaging function for signal processing.  
%
% Simulink Models (.slx files):
% - PID_validation.slx      : Validates the PID controller and the homemade
%                             model of the motor.
% - Inertia_Estimation.slx  : Estimates system inertia.  
% - Friction_Estimation.slx : (TODO) Develop a model for friction estimation.  
% - RealTimeSimulation.slx  : Runs real-time simulation of the system in lab

% IMPORTANT: add 'utilities' folder to path
%% Load datasheet into workspace
datasheet;

%% Filters parameters
delta_est = 1/sqrt(2);
wc = 2*pi*20;

%% Controller Design

% TODO: implement a function to find the optimal alpha

% Simplified Model Params
beq = 0;
km = (drv.dcgain * mot.Kt) / ...
     (mot.Req*beq + mot.Kt*mot.Ke);
Tm = (mot.Req*mld.Jeq) / ...
     (mot.Req*beq + mot.Kt*mot.Ke);

% Controller Design Params
ts    = 0.15;
alpha = 84;             % Anything Above 84 Works!!!
mp    = 0.1;

[Kp, Ki, Kd, tl] = designPIDBode(km, Tm, gbox, ts, mp, alpha);

% When PID tuning is done, uncomment this line to save the gains in 
% 'utilities' folder and make them accessible across all labs

% save('../utilities/PID_gains', 'Kp', 'Kd', 'Ki', 'tl');

%% Analisys
if ~evalin('base', 'exist(''out'', ''var'')')
    warning('Variable ''out'' not found in base workspace.');
else
    out = evalin('base', 'out');

    try
        ref = out.ref;
        y = out.y;
    catch
        error('The ''out'' object does not contain ref and y.');
    end
   
        [riseTime, settlingTime, overshoot] = analyze_step_response(out.ref, out.y);
        fprintf('\n--- Step Response Analysis ---\n');
        fprintf('Rise Time     : %.4f s\n', riseTime);
        fprintf('Settling Time : %.4f s\n', settlingTime);
        fprintf('Overshoot     : %.2f %%\n', overshoot); 
        fprintf('-------------------------------\n\n');
end