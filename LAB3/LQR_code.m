%% data
clear all

addpath('..\..\CELAB-Labs\utilities\');
datasheet;
datasheet_resonant;
load('..\utilities\black-box-estimation.mat');


k_sim=mld.k;
Req=sens.curr.Rs+mot.R;
ts=0.85;
Jeq=mot.J+ (mld.Jh)/((gbox.N)^(2));
Beq=mot.B+(mld.Bh)/((gbox.N)^2);
Mp=0.3;
delta= (log(1/Mp))/((pi^(2)+(log(1/Mp))^(2))^(0.5));
omegagc=3/(delta*ts);
beq=Beq;
%% State - Space
omegac=2*pi*50;
deltafil=2^(-0.5);
A=[0,0,1,0;
    0,0,0,1;
    -(k_sim)/(((gbox.N)^(2))*Jeq),(k_sim)/((gbox.N)^(2)*Jeq),(-Beq*Req-mot.Kt*mot.Ke)/(Jeq*Req),0;
 k_sim/mld.Jb,-k_sim/mld.Jb,0,-mld.Bb/mld.Jb];
 
 T=[1,0,0,0;
     1,1,0,0;
     0,0,1,0;
     0,0,1,1];

B=[0;0;(mot.Kt*drv.dcgain)/(gbox.N*Jeq*Req);0];
Bd=[0;0;-(1/((gbox.N)^2)*Jeq);0];
Aprime=(T^(-1))*A*T;
Bprime=T^(-1)*B;
Bdprime=T^(-1)*Bd;
BTOT=Bprime+Bdprime*tau_sf;
% BTOT=B+Bd*tau_sf;
arg=((1-delta^(2))^(0.5))/delta;
% phi=atan2(1,arg);
phi=atan(arg);
poles=[omegagc*exp(1i*(-pi+phi)),omegagc*exp(1i*(-pi-phi)),omegagc*exp(1i*(-pi+phi/2)),omegagc*exp(1i*(-pi-phi/2))];

% poles2 = [-15.1843+39.7205*1i, -15.1843-39.7205*1i,-9.6459+20.8460*1i, -9.6459-20.8460*1i]; % founded with rlocfind(sysG*sysGp)
% K=acker(Aprime,Bprime,poles);
K=acker(Aprime,Bprime,poles);
C=[1,0,0,0];
SYS=[Aprime,BTOT;C,0];
% SYS=[Aprime,Bprime;C,0];
f=[0;0;0;0;1];
N=linsolve(SYS,f);
Nx=[N(1);N(2);N(3);N(4)];
Nu=N(5);

%% LQR 2.4.1

sysG=ss(Aprime,Bprime,C,0);
sysGp=ss(-Aprime,-Bprime,C,0);
% r=0.00025;
% r =  0.000111;
% [r2, poles2] = rlocfind(sysG*sysGp);
% poles2 = [-15.1843 +39.7205i, -15.1843 -39.7205i,-9.6459 +20.8460i, -9.6459 -20.8460i];
r2=2.5899e-04;
% r2 = 0.000111;
% r2 = 2.4732e-06;
% Kfb=lqry(sysG,1,r);
Kfb=lqry(sysG,1,r2);

%% 2.4.3
thetahDEV=0.3*50*pi/180;
thetadDEV=pi/36;
uDEV=10;
vect=[1/(thetahDEV)^2,1/(thetadDEV)^2,0,0];
Q=diag(vect);
R=diag(1/(uDEV)^2);

Kfb2=lqr(sysG,Q,R);
t0=0.2;
t1=0.7;

