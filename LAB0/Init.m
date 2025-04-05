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

delta = log(1/mp) / ...
        sqrt(pi^2 + (log(1/mp))^2);

wgc = 3 / (delta * ts);

phim = atan2(2 * delta, ...
             sqrt(sqrt(1 + 4*delta^4) - 2*delta^2));

% Transfer function
P = km / ...
    (gbox.N*1i*wgc * (Tm*1i*wgc + 1));

% Controller Bode Gain
abs_P = abs(P);
deltak = 1/abs_P;
deltaphi = -pi + phim - angle(P);

% Controller Gains
Kp = deltak * cos(deltaphi);
tanphi = tan(deltaphi);
Td = (tanphi + sqrt(tanphi^2 + 4/alpha)) / ...
     (2*wgc);
Ti = alpha * Td;
Kd = Kp * Td;
Ki = Kp / Ti;

tl = 1/(3*wgc); % proportional coefficient between 2-5. Chosen 3

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