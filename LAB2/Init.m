
%% Load datasheet into workspace
addpath("../utilities/")
datasheet; 

%% Sample time
Ts = 10e-3;

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

%% Antiwindup and feedforward

% Load previous antiwindup gain

% Temporary value
ts = 0.15;
Tw = ts/5;
Kw = 1/Tw*0.05;

% Inertia comp
I_C = (gbox.N * mot.Req * Jeq_hat)/(drv.dcgain * mot.Kt);
% Friction comp
F_C = mot.Req/(drv.dcgain * mot.Kt * gbox.N);
% BEMF comp
B_C = (gbox.N * mot.Ke)/drv.dcgain;

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

% Exact method
C_EX = c2d(C, Ts, 'zoh');
[num_EX, den_EX] = tfdata(C_EX, 'v');