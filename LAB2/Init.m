
%% Load datasheet into workspace
addpath("../utilities/")
datasheet; 

%% Sample time
Ts = 1e-3;

%% Max stepsize of solver (if fixed step is used)
Smax = 0.1e-3;

%% Discrete time PID design

% Load Kd, Kp, Ki, tl, wgc
load('PID_gains_with_estimated_params');

% Load Beq, Jeq_hat, tau_sf
load('black-box-estimation.mat');

% Real-derivative transfer function
TL = 1/(2*wgc*10); % Multiply for 10 seems to be working soo much better. Need more testing
num = [1 -1];
den = [(TL+Ts) -TL];

k_drv = (1 + drv.R3/drv.R4) * drv.R2/(drv.R1 + drv.R2);
%inertia comp
I_C = (gbox.N * mot.Req * Jeq_hat)/(k_drv  * mot.Kt);
%friction comp
F_C = mot.Req/(k_drv * mot.Kt * gbox.N);
%BEMF comp
B_C = (gbox.N * mot.Ke)/k_drv;

%% PID with different discretization methods
% CT transfer function
s = tf('s');
C = Kp+Ki/s+Kd*s/(1+TL*s);

% Variable of DT transfer function
z = tf('z', Ts);
% Tustin method
s = 2/Ts*(z-1)/(z+1);
C_T = minreal(Kp+Ki/s+Kd*s/(1+TL*s));
[num_T, den_T] = tfdata(C_T, 'v');

% Forward method
s = (z-1)/Ts;
C_FE = minreal(Kp+Ki/s+Kd*s/(1+TL*s));
[num_FE, den_FE] = tfdata(C_FE, 'v');