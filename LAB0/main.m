close all;
clear all;
clc;

%%
data

%% PID design
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



