% General parameters and conversion gains
% controller sampling time
Ts = 1e-2;

fc = 0.35;

% gravity acc [m/s^2]
g = 9.81;

% conversion gains
rpm2rads = 2*pi/60; % [rpm] -> [rad/s]
rads2rpm = 60/2/pi; % [rad/s] -> [rpm]
rpm2degs = 360/60; % [rpm] -> [deg/s]
degs2rpm = 60/360; % [deg/s] -> [rpm]
deg2rad = pi/180; % [deg] -> [rad]
rad2deg = 180/pi; % [rad] -> [deg]
g2ms2 = g; % [acc_g] -> [m/s^2]
ms22g = 1/g; % [m/s^2] -> [acc_g]
ozin2Nm = 0.706e-2; % [oz*inch] -> [N*m]

%% DC motor data

% motor id: brushed DC gearmotor Pololu 30:1 37Dx68L mm

% electromechanical params
mot.UN = 12; % nominal voltage
mot.taus = 110/30 * ozin2Nm; % stall torque @ nom voltage
mot.Is = 5; % stall current @ nom voltage
mot.w0 = 350 * 30 * rpm2rads; % no-load speed @ nom voltage
mot.I0 = 0.3; % no-load current @ nom voltage


mot.R = mot.UN/mot.Is; % armature resistance
mot.L = NaN; % armature inductance
mot.Kt = mot.taus/mot.Is; % torque constant
mot.Ke = (mot.UN - mot.R*mot.I0)/(mot.w0); % back-EMF constant
mot.eta = NaN; % motor efficiency
mot.PN = NaN; % nominal output power
mot.IN = NaN; % nominal current
mot.tauN = NaN; % nominal torque

% dimensions
mot.rot.h = 30.7e-3; % rotor height
mot.rot.r = 0.9 * 17e-3; % rotor radius

mot.stat.h = 68.1e-3; % stator height
mot.stat.r = 17e-3; % stator radius

% center of mass (CoM) position
mot.rot.xb = 0; % (left) rot CoM x-pos in body frame
mot.rot.yb = 42.7e-3; % (left) rot CoM y-pos in body frame
mot.rot.zb = -7e-3; % (left) rot CoM z-pos in body frame

mot.stat.xb = 0; % (left) stat CoM x-pos in body frame
mot.stat.yb = 52.1e-3; % (left) stat CoM y-pos in body frame
mot.stat.zb = -7e-3; % (left) stat CoM z-pos in body frame

% mass
mot.m = 0.215; % total motor mass
mot.rot.m = 0.35 * mot.m; % rotor mass
mot.stat.m = mot.m - mot.rot.m; % stator mass

% moment of inertias (MoI) wrt principal axes
mot.rot.Ixx = mot.rot.m/12 * (3*mot.rot.r^2 + mot.rot.h^2); % MoI along r dir
mot.rot.Iyy = mot.rot.m/2 * mot.rot.r^2; % MoI along h dim
mot.rot.Izz = mot.rot.Ixx; % MoI along r dir

mot.stat.Ixx = mot.stat.m/12 * (3*mot.stat.r^2 + mot.stat.h^2); % MoI along r dir
mot.stat.Iyy = mot.stat.m/2 * mot.stat.r^2; % MoI along h dir
mot.stat.Izz = mot.stat.Ixx; % MoI along r dir

% viscous friction coeff (motor side)
mot.B = mot.Kt*mot.I0/mot.w0;

%% Gearbox data

gbox.N = 30; % reduction ratio
gbox.B = 0.025; % viscous friction coeff (load side)

%% Battery data

% electrical data
batt.UN = 11.1; % nominal voltage

% dimensions
batt.w = 136e-3; % battery pack width
batt.h = 26e-3; % battery pack height
batt.d = 44e-3; % battery pack depth

% center of mass (CoM) position
batt.xb = 0; % CoM x-pos in body frame
batt.yb = 0; % CoM y-pos in body frame
batt.zb = 44e-3; % CoM z-pos in body frame

% mass
batt.m = 0.320;

% moment of inertias (MoI) wrt principal axes
batt.Ixx = batt.m/12 * (batt.w^2 + batt.h^2); % MoI along d dim
batt.Iyy = batt.m/12 * (batt.d^2 + batt.h^2); % MoI along w dim
batt.Izz = batt.m/12 * (batt.w^2 + batt.d^2); % MoI along h dim

%% H-bridge PWM voltage driver data

drv.Vbus = batt.UN; % H-bridge DC bus voltage
drv.pwm.bits = 8; % PWM resolution [bits]
drv.pwm.levels = 2^drv.pwm.bits; % PWM levels
drv.dutymax = drv.pwm.levels-1; % max duty cycle code
drv.duty2V = drv.Vbus/drv.dutymax; % duty cycle code (0-255) to voltage
drv.V2duty = drv.dutymax/drv.Vbus; % voltage to duty cycle code (0-255)

%% Wheel data

% dimensions
wheel.h = 26e-3; % wheel height
wheel.r = 68e-3/2; % wheel radius

% center of mass (CoM) position
wheel.xb = 0; % (left) wheel CoM x-pos in body frame
wheel.yb = 100e-3; % (left) wheel CoM y-pos in body frame
wheel.zb = 0; % (left) wheel CoM z-pos in body frame

% mass
wheel.m = 50e-3;

% moment of inertias (MoI) wrt principal axes
wheel.Ixx = wheel.m/12 * (3*wheel.r^2 + wheel.h^2); % MoI along r dim
wheel.Iyy = wheel.m/2 * wheel.r^2; % MoI along h dim
wheel.Izz = wheel.Ixx; % MoI along r dim

% viscous friction coeff
wheel.B = 0.0015;

%% Chassis data

% dimensions
chassis.w = 160e-3; % frame width
chassis.h = 119e-3; % frame height
chassis.d = 80e-3; % frame depth

% center of mass (CoM) position
chassis.xb = 0; % CoM x-pos in body frame
chassis.yb = 0; % CoM x-pos in body frame
chassis.zb = 80e-3; % CoM x-pos in body frame

% mass
chassis.m = 0.456;

% moment of inertias (MoI) wrt principal axes
chassis.Ixx = chassis.m/12 * (chassis.w^2 + chassis.h^2); % MoI along d dim
chassis.Iyy = chassis.m/12 * (chassis.d^2 + chassis.h^2); % MoI along w dim
chassis.Izz = chassis.m/12 * (chassis.w^2 + chassis.d^2); % MoI along h dim

%% Body data

% mass
body.m = chassis.m + batt.m + 2*mot.stat.m;

% center of mass (CoM) position
body.xb = 0; % CoM x-pos in body frame
body.yb = 0; % CoM y-pos in body frame
body.zb = (1/body.m) * (chassis.m*chassis.zb + ... % CoM z-pos in body frame
batt.m*batt.zb + 2*mot.stat.m*mot.stat.zb);

% moment of inertias (MoI) wrt principal axes
body.Ixx = chassis.Ixx + chassis.m*(body.zb - chassis.zb)^2 + ... % MoI along d dim
batt.Ixx + batt.m*(body.zb - batt.zb)^2 + ...
2*mot.stat.Ixx + ...
2*mot.stat.m*(mot.stat.yb^2 + (body.zb - mot.stat.zb)^2);

body.Iyy = chassis.Iyy + chassis.m*(body.zb - chassis.zb)^2 + ... % MoI along w dim
batt.Iyy + batt.m*(body.zb - batt.zb)^2 + ...
2*mot.stat.Iyy + ...
2*mot.stat.m*(body.zb - mot.stat.zb)^2;

body.Izz = chassis.Izz + batt.Izz + ... % MoI along h dim
2*mot.stat.Izz + 2*mot.stat.m*mot.stat.yb^2;

%% Sensors data - Hall-effect encoder

% Hall-effect encoder
sens.enc.ppr = 16*4; % pulses per rotation at motor side (w/ quadrature decoding)
sens.enc.pulse2deg = 360/sens.enc.ppr;
sens.enc.pulse2rad = 2*pi/sens.enc.ppr;
sens.enc.deg2pulse = sens.enc.ppr/360;
sens.enc.rad2pulse = sens.enc.ppr/2/pi;

%% Sensors data - MPU6050 (accelerometer + gyro)

% center of mass (CoM) position
sens.mpu.xb = 0;
sens.mpu.yb = 0;
sens.mpu.zb = 13.5e-3;

% MPU6050 embedded accelerometer specs
sens.mpu.acc.bits = 16;
sens.mpu.acc.fs_g = 16; % full-scale in "g" units
sens.mpu.acc.fs = sens.mpu.acc.fs_g * g2ms2; % full-scale in [m/s^2]
sens.mpu.acc.g2LSB = floor(2^(sens.mpu.acc.bits-1)/sens.mpu.acc.fs_g); % sensitivity [LSB/g]
sens.mpu.acc.ms22LSB = sens.mpu.acc.g2LSB * ms22g; % sensitvity [LSB/(m/s^2)]
sens.mpu.acc.LSB2g = sens.mpu.acc.fs_g/2^(sens.mpu.acc.bits-1); % out quantization [g/LSB]
sens.mpu.acc.LSB2ms2 = sens.mpu.acc.LSB2g * g2ms2; % out quantization [ms2/LSB]
sens.mpu.acc.bw = 94; % out low-pass filter BW [Hz]
sens.mpu.acc.noisestd = 400e-6*sqrt(100); % output noise std [g-rms]
sens.mpu.acc.noisevar = sens.mpu.acc.noisestd^2; % output noise var [g^2]

% MPU6050 embdedded gyroscope specs
sens.mpu.gyro.bits = 16;
sens.mpu.gyro.fs_degs = 250; % full scale in [deg/s (dps)]
sens.mpu.gyro.fs = sens.mpu.gyro.fs_degs * deg2rad; % full scale in [rad/s]
sens.mpu.gyro.degs2LSB = floor(2^(sens.mpu.gyro.bits-1)/sens.mpu.gyro.fs_degs); % sensitivity [LSB/degs]
sens.mpu.gyro.rads2LSB = sens.mpu.gyro.degs2LSB * rad2deg; % sensitivity [LSB/rads]
sens.mpu.gyro.LSB2degs = sens.mpu.gyro.fs_degs/2^(sens.mpu.gyro.bits-1); % out quantization [degs/LSB]
sens.mpu.gyro.LSB2rads = sens.mpu.gyro.LSB2degs * deg2rad; % out quantization [rads/LSB]
sens.mpu.gyro.bw = 98; % out low-pass filter BW [Hz]
sens.mpu.gyro.noisestd = 5e-3*sqrt(100); % output noise std [degs-rms]
sens.mpu.gyro.noisevar = sens.mpu.acc.noisestd ^2; % output noise var [degs^2]

%% Compute
nlmodel.ua2tau = 2*gbox.N*mot.Kt/mot.R*[1;-1];
nlmodel.M11 = 2*wheel.Iyy + 2*gbox.N*gbox.N*mot.rot.Iyy + (body.m + 2*wheel.m + 2*mot.rot.m)*wheel.r*wheel.r;
nlmodel.M22 = body.Iyy + 2*(1-gbox.N)*(1-gbox.N)*mot.rot.Iyy+body.m*body.zb*body.zb+2*mot.rot.m*mot.rot.zb*mot.rot.zb;
nlmodel.Fv = [2*(gbox.B+wheel.B) -2*gbox.B; -2*gbox.B 2*gbox.B];
nlmodel.Fv_prime = nlmodel.Fv + 2*gbox.N*gbox.N*mot.Kt*mot.Ke/mot.R*[1 -1; -1 1];

nlmodel.C22_gain = -(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;
nlmodel.M12_gain = 2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;
nlmodel.g2_gain = -(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*g;

linmodel.M11 = nlmodel.M11;
linmodel.M12 = 2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;
linmodel.M22 = nlmodel.M22;
linmodel.M = [linmodel.M11 linmodel.M12; linmodel.M12 linmodel.M22];

linmodel.G = [0 0; 0 nlmodel.g2_gain];
z = tf('z', Ts);
Hz = Ts/(1/fc*z + Ts-1/fc);
[stvar_est.Hz_Num, stvar_est.Hz_Den] = tfdata(Hz);
stvar_est.Hz_Num = cell2mat(stvar_est.Hz_Num);
stvar_est.Hz_Den = cell2mat(stvar_est.Hz_Den);


state_space.A = [[0 0;0 0] eye(2); -linmodel.M\linmodel.G -linmodel.M\nlmodel.Fv_prime];
state_space.B = 2*gbox.N*mot.Kt/mot.R*[[0 0;0 0];inv(linmodel.M)]*[1;-1];
state_space.C = [1 0 0 0];
state_space.D = 0;

[state_space.Phi, state_space.Gamma, state_space.H] = ssdata(c2d(ss(state_space.A, state_space.B, state_space.C, state_space.D), Ts, 'zoh'));

X = linsolve([state_space.Phi-eye(4) state_space.Gamma; state_space.H 0], [0;0;0;0;1]);
Nx = X(1:4);
Nu = X(5);

lqr_nominal.gamma_bar = pi/36; 
lqr_nominal.theta_bar = pi/360;
lqr_nominal.u_bar = 1;
%according to the Bryson’s rule, the cost weights Q and r
lqr_nominal.Q = diag([1/lqr_nominal.gamma_bar^2 1/lqr_nominal.theta_bar^2 0 0]);
lqr_nominal.r = 1/lqr_nominal.u_bar^2;

lqr_nominal.rho = 50;
lqr_nominal.K = dlqr(state_space.Phi, state_space.Gamma, lqr_nominal.Q, lqr_nominal.r*lqr_nominal.rho); %feedback matrix

%% Integral Action
robust.Phi = [1 state_space.H; [0;0;0;0] state_space.Phi];
robust.Gamma = [0; state_space.Gamma];
lqr_integral.gamma_bar = pi/36; %check it 
lqr_integral.theta_bar = pi/360;
lqr_integral.u_bar = 1;

q11 = 0.1;
lqr_integral.Q = diag([q11 1/lqr_integral.gamma_bar^2 1/lqr_integral.theta_bar^2 0 0]);
lqr_integral.r = 1/lqr_integral.u_bar^2;

lqr_integral.rho = 5000;
lqr_integral.K = dlqr(robust.Phi, robust.Gamma, lqr_integral.Q, lqr_integral.r*lqr_integral.rho);
lqr_integral.K = lqr_integral.K(2:5);
lqr_integral.Ki = lqr_integral.K(1);

%% robot initial condition
x0 = [0, 0, 0, 0];
x01 =[ ...
 0, ...  % gam(0)
 5, ...  % th(0)
 0, ...  % dot_gam(0)
 0];     % dot_th(0)
x02 = [0 5*deg2rad 0 0];
%%
% clear X;
% clear z;
% clear Hz;
% clear q11;