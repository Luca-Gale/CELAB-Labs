%% variables 

% Armature resistance
ra = 2.6;
% Armature inductance 
la = 180 * 10^-6;
% Electric (BEMF) constant
ke = 7.68*10^-3;
% Torque constant
kt = 7.68*10^-3;
% Rotor inertia
jm = 3.90 * 10^ -7;
% Rotor viscous friction coefficient
% bm = not available 
% Gearbox ratio
n = 14;
% Moment of inertia of external 72–tooth gear
j72 = 1.4*10^-6;
% Moment of inertia of extra disc
jd = 3.0*10^-5;
%  Load viscous friction coefficient
% bl = to be estimated
%  Voltage driver static gain
kdrv = 0.6;
%  Voltage driver cut–off frequency
fc = 1200;
% Shunt resistance
rs = 0.5;



% load inertia
jl = jd + 3*j72 ;
jeq = jm + (jl / n^2) ;
% beq ?
beq = 0;
req = ra + rs ;
km = (kdrv * kt) / (req*beq + kt*ke) ;
tm = (req*jeq) / (req*beq + kt*ke) ;

ppr = 500*4;
pulse2deg = 360/ppr;

%% Conversion gain
ra2deg = 180/pi;
deg2rad = pi/180;
rads2rpm = 60/2/pi;

%% Tentative values for the unknown parameters
Beq = 2.0*10^-6;
tau_sf = 1.0*10^-2;