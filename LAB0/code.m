close all;
clear all;
clc;
%% variables 
%S hunt resistance
rs = 0.5;
%  Voltage driver cut–off frequency
fc = 1200;
%  Voltage driver static gain
kdrv = 0.6;
%  Load viscous friction coefficient
% bl = to be estimated
%  Moment of inertia of extra disc
jd = 3*10^-5;
%  Moment of inertia of external 72–tooth gear
j72 = 1.4*10^-6;
% Gearbox ratio
n = 14;
%  Rotor viscous friction coefficient
% bm = not available 
%  Rotor inertia
jm = 3.90 * 10^ -7;
% Torque constant
kt = 7.68*10^-3;
%  Electric (BEMF) constant
ke = 7.68*10^-3;
% Armature inductance 
la = 180 * 10^-6;
% Armature resistance
ra = 2.6;
% load inertia
jl = jd + 3*j72 ;
jeq = jm + (jl / n^2) ;
% beq ?
beq = 0;
req = ra + rs ;
km = (kdrv * kt) / (req*beq + kt*ke) ;
tm = (req*jeq) / (req*beq + kt*ke) ;
deg2rad = pi/180;
ppr = 500*4;
pulse2deg = 360/ppr;
%% PID DESIGN
ts=0.15;
alpha = 4;
mp=0.1;
num1 = log(1/mp);
den1 = sqrt(pi^2 + (num1)^2);
delta = num1/den1;
wgc = 3/(delta * ts);
num2 = 2*delta;
den2 = sqrt(sqrt(1+4*delta^4) - 2 * delta^2);
phim = atan(num2/den2) ;%* 180 / pi; % in degree
%phim = num2/den2;
%% Transfer function
num = km;
den = n*i*wgc*(tm*i*wgc+1);
p=num/den;

%% 
deltak =1/abs(p);
deltaphi = -pi + phim - angle(p);
abs_p = abs (p) ;
angle_p = angle(p) ;
Kp=deltak*cos(deltaphi);
Td = (tan(deltaphi)+(sqrt(tan(deltaphi)^2 +(alpha/4)))) / (2*wgc) ;
Ti = alpha * Td;
Kd = Kp * Td;
Ki = Kp / Ti;

cut_off = 0.4 * deltak;
tl = 1/cut_off;
%% PARAMETER ESTIMATION
delta_est = 1/sqrt(2);
wc=2*pi*20;



