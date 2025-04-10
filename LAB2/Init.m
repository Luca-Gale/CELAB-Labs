
%% Load datasheet into workspace
addpath("../utilities/")
datasheet; 

%% Sample time
Ts = 1e-3;

%% Max stepsize of solver (if fixed step is used)
Smax = 0.1e-3;

%% Discrete time PID design
load('PID_gains_with_estimated_params');
load('black-box-estimation.mat');
% Time constant for the real-derivative
TL = 1/(2*wgc);

k_drv = (1 + drv.R3/drv.R4) * drv.R2/(drv.R1 + drv.R2);
%inertia comp
I_C = (gbox.N * mot.Req * Jeq_hat)/(k_drv  * mot.Kt);
%friction comp
F_C = mot.Req/(k_drv * mot.Kt * gbox.N);
%BEMF comp
B_C = (gbox.N * mot.Ke)/k_drv;