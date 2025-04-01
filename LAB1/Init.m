% TODO : Complete the PROJECT STRUCTURE OVERVIEW

%% Parameter Declaration
% conversion gains
rpm2rads = 2*pi/60;         % [rpm] -> [rad/s]
rads2rpm = 60/2/pi;         % [rad/s] -> [rpm]
rpm2degs = 360/60;          % [rpm] -> [deg/s]
degs2rpm = 60/360;          % [deg/s] -> [rpm]
deg2rad = pi/180;           % [deg] -> [rad]
rad2deg = 180/pi;           % [rad] -> [deg]
ozin2Nm = 0.706e-2;         % [oz*inch] -> [N*m]

% >>>>>>>> DC Motor Nominal Parameters
% brushed DC-motor Faulhaber 2338S006S
mot.R = 2.6;                        % armature resistance
mot.L = 180e-6;                     % armature inductance
mot.Kt = 1.088 * ozin2Nm;           % torque constant
mot.Ke = 0.804e-3 * rads2rpm;       % back-EMF constant
mot.J = 5.523e-5 * ozin2Nm;         % rotor inertia
mot.B = 0.0;                        % viscous friction coeff (n.a.)
mot.eta = 0.69;                     % motor efficiency
mot.PN = 3.23/mot.eta;              % nominal output power
mot.UN = 6;                         % nominal voltage
mot.IN = mot.PN/mot.UN;             % nominal current
mot.tauN = mot.Kt*mot.IN;           % nominal torque
mot.taus = 2.42 * ozin2Nm;          % stall torque
mot.w0 = 7200 * rpm2rads;           % no-load speed

% >>>>>>>> Gearbox nominal parameters
% planetary gearbox Micromotor SA 23/1
gbox.N1 = 14;           % 1st reduction ratio (planetary gearbox)
gbox.eta1 = 0.80;       % gearbox efficiency

% external transmission gears
gbox.N2 = 1;            % 2nd reduction ratio (external transmission gears)
gbox.J72 = 1.4e-6;      % inertia of a single external 72 tooth gear
gbox.eta2 = 1;          % external transmission efficiency (n.a.)

% overall gearbox data
gbox.N = gbox.N1*gbox.N2;           % total reduction ratio
gbox.eta = gbox.eta1*gbox.eta2;     % total efficiency
gbox.J = 3*gbox.J72;                % total inertia (at gearbox output)

% >>>>>>>> Mechanical Load Nominal Parameters
% inertia disc params
mld.JD = 3e-5;                  % load disc inertia
mld.BD = 0.0;                   % load viscous coeff (n.a.)
mld.Beq = 2e-6;                 % Total Viscous Friction

% Overall Mechanical Load Params
mld.J = mld.JD + gbox.J;        % total inertia
mld.B = 2.5e-4;                 % total viscous friction coeff (estimated)
mld.tausf = 1.0e-2;             % total static friction (estimated)
mld.Jm = 3.9e-7;                % Motor Inertia (?)

mld.Jeq = mld.Jm + mld.J / gbox.N^2;  % Total Inertia (?)

% >>>>>>>> Voltage driver nominal parameters

% Op-Amp circuit params
drv.R1 = 7.5e3;         % Op-Amp Input resistor (dac to non-inverting in)
drv.R2 = 1.6e3;         % Op-Amp Input resistor (non-inverting in to gnd)
drv.R3 = 1.2e3;         % Op-Amp feedback resistor (output to inverting in)
drv.R4 = 0.5e3;         % Op-Amp feedback resistor (inverting in to gnd)
drv.C1 = 100e-9;        % Op-Amp Input capacitor
drv.outmax = 12;        % Op-Amp max output voltage

% voltage driver dc-gain
drv.dcgain = drv.R2/(drv.R1+drv.R2) * (1 + drv.R3/drv.R4);

% voltage driver time constant
drv.Tc = drv.C1 * drv.R1*drv.R2/(drv.R1+drv.R2);

% >>>>>>>> Sensors data
% shunt resistor
sens.curr.Rs = 0.5;
mot.Req = sens.curr.Rs + mot.R;         % Equivalent Resistance

% Hewlett-Packard HEDS-5540#A06 optical encoder
sens.enc.ppr = 500*4;                   % Pulses per rotation
sens.enc.pulse2deg = 360/sens.enc.ppr;  % [Pulses] -> [deg]
sens.enc.pulse2rad = 2*pi/sens.enc.ppr; % [Pulses] -> [rad]
sens.enc.deg2pulse = sens.enc.ppr/360;  % [deg] -> [Pulses]
sens.enc.rad2pulse = sens.enc.ppr/2/pi; % [rad] -> [Pulses]

% Potentiometer 1 (Spectral 138-0-0-103)- installed on motor box
sens.pot1.range.R = 10e3;           % Ohmic value range
sens.pot1.range.V = 5;              % voltage range
sens.pot1.range.th_deg = 345;       % angle range [deg]
sens.pot1.range.th = sens.pot1.range.th_deg * deg2rad;          % angle range [rad]
sens.pot1.deg2V = sens.pot1.range.V / sens.pot1.range.th_deg;   % sensitivity [V/deg]
sens.pot1.rad2V = sens.pot1.range.V / sens.pot1.range.th;       % sensitivity [V/rad]
sens.pot1.V2deg = 1/sens.pot1.deg2V;                            % conversion gain [V] -> [deg]
sens.pot1.V2rad = 1/sens.pot1.rad2V;                            % conversion gain [V] -> [rad]

% >>>>>>>> Data acquisition board (daq) data
% NI PCI-6221 DAC data
daq.dac.bits = 16;                              % Resolution (bits)
daq.dac.fs = 10;                                % Full Scale
daq.dac.q = 2*daq.dac.fs/(2^daq.dac.bits-1);    % Quantization

% NI PCI-6221 ADC data
daq.adc.bits = 16;                              % Resolution (bits)
daq.adc.fs = 10;                                % Full Scale (as set in SLDRT Analog Input block)
daq.adc.q = 2*daq.adc.fs/(2^daq.adc.bits-1);    % Quantization

Ts = 0.001;                                     % Sampling Time

% State Estimation Filter parameters
delta_est = 1/sqrt(2);
wc = 2*pi*20;

%% Estimated Parameters
Jeq_hat = 5.801020129074022e-05;      % Equivalent Inertia [kg.m^2]
Beq = 1.223604206496999e-06;          % Equivalent Viscous Friction [Nm/(mot.Rd/s)]
Tau_sf = 0.005709536387019;           % Static Friction [Nm]

%% Recalculating Constants
Tm = (mot.Req * Beq + mot.Kt*mot.Ke) / (mot.Req * Jeq_hat);
km = (drv.dcgain * mot.Kt) / (gbox.N * mot.Req * Jeq_hat);

%% State-Space Matrices
A = [0, 1; 0, -1/Tm];
B = [0, km/(gbox.N*Tm)]';
C = [1, 0];
D = 0;

% % Transfer Function
% TFModel = tf(ss(A, B, C, D));
