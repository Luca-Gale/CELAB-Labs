clear all
clc

%% load data
Init_ali
Jeq = 6.51e-07;
Beq = 1.223604206496999e-06;
wn = 3/(delta * ts);

%% State-Space
Tm = (mot.Req * Jeq)/(mot.Req*Beq + mot.Kt*mot.Ke);

A = [[0 1 ],
    [0 -1/Tm]];
B = [0,
    drv.dcgain*mot.Kt/(gbox.N1*mot.Req*Jeq)];
C = [1 0];
D = 0;
M = [[A B],
    [C D]];

M_inv = inv(M);
Ans = M_inv * [0;0;1];
Nx = Ans(1:2,1);
Nu = Ans(3,1);
pole1 =(-delta * wn) + 1j*wn*sqrt(1-delta^2);
pole2 = (-delta * wn) - 1j*wn*sqrt(1-delta^2);
poles = [pole1,pole2];
K = acker(A,B,poles);
Nr=Nu+K * Nx;
%% part 2 - Integral 
sigma = real ( pole1 );
omega_d = imag ( pole1 );
poles2 = [sigma+1i*omega_d sigma-1i*omega_d sigma ];
poles2 = sigma * ones (3 ,1);
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 2* sigma ];
%poles2 = [2*sigma+1i*omega_d 2*sigma-1i*omega_d 3*sigma ];
Ae =[0  ,C; zeros(2, 1), A ];
Be= [0 ; B];
Ce =[0 C]; 
De = 0;
K_robust  = acker (Ae , Be , poles2 );
KI = K_robust(1);
K2 = K_robust(2:3);
%% new OBSERVER NORMAL STATE SPACE OBSERVER

T_s=0.001*10;
%T_s = 5;
% T_s = 1ms , 10ms , 50ms
I=[1,0;0,1];
T_trsf=I;
A_prime=T_trsf^(-1)*A*T_trsf;


%lambda0=5*sigma;
lambdaeddi = -5 * abs(pole1);
lambdaali = (-delta * wn) + j*wn*sqrt(1-delta^2)*5;
lambda2 = -5*wn*delta;
lambdanew = (-delta * wn)*5 + j*wn*sqrt(1-delta^2);
A22_prime=A_prime(2,2);
A12_prime=A_prime(1,2);
L=acker(A22_prime,A12_prime,lambdanew);

A0=A22_prime-L*A12_prime;
%TM=-(A0+L)^(-1);

B_prime=T_trsf*B;
B0=[B_prime(2)-L*B_prime(1),A0*L+A_prime(2,1)-L*A_prime(1,1)];
C0=T_trsf*[0;1];
D0=T_trsf*[0,1;0,L];

%% Discrete regulator
REG_co= ss(A0,B0,C0,D0);
% FORWARD
% AF=1+A0*T_s;
% BF=B0*T_s;
% CF=C0;
% DF=D0;

REG_disc=c2d(REG_co,T_s,'forward');
AF=REG_disc.A;
BF=REG_disc.B;
CF=REG_disc.C;
DF=REG_disc.D;

% BACKWARD
AB = inv(eye(1) - A0*T_s);
BB = AB * B0 * T_s;
CB = C0*AB;
DB = D0 + C0*BB;
% TUSTIN
REG_disc=c2d(REG_co,T_s,'tustin');
AT=REG_disc.A;
BT=REG_disc.B;
CT=REG_disc.C;
DT=REG_disc.D;
% ZOH
REG_disc=c2d(REG_co,T_s,'zoh');
AZ=REG_disc.A;
BZ=REG_disc.B;
CZ=REG_disc.C;
DZ=REG_disc.D;

% REG_disc=c2d(REG_co,T_s,'backward');
% AB=REG_disc.A;
% BB=REG_disc.B;
% CB=REG_disc.C;
% DB=REG_disc.D;

% REG_disc = c2d_euler(REG_co,T_s,'backward');
% AB=REG_disc.A;
% BB=REG_disc.B;
% CB=REG_disc.C;
% DB=REG_disc.D;




%% Trash 
%REG_disc.B leggermente diverso da B0*T_s
%REG_disc.D diverso da D0
% %% new OBSERVER INTEGRAL STATE SPACE OBSERVER
% T_s=0.001*50;
% %T_s = 5;
% % T_s = 1ms , 10ms , 50ms
% I=[1,0;0,1];
% T_trsf=I;
% A_prime=T_trsf^(-1)*Ae*T_trsf;
% 
% % lambda0=-delta*5*omegaB+1i*5*omegaB*(1-(delta)^(2))^(0.5);
% %lambda0=5*sigma;
% lambda0 = (-delta * wn) + j*wn*sqrt(1-delta^2)*5;
% eig=lambda0;
% 
% A22_prime=A_prime(2,2);
% A12_prime=A_prime(1,2);
% L=acker(A22_prime,A12_prime,eig);
% 
% A1=A22_prime-L*A12_prime;
% TM=-(A1+L)^(-1);
% %B0=[k_m/(gbox.N*TM),(A0)*L];
% B_prime=T_trsf*Be;
% B1=[B_prime(2)-L*B_prime(1),A0*L+A_prime(2,1)-L*A_prime(1,1)];
% C1=T_trsf*[0;1];
% D1=T_trsf*[0,1;0,L];
% 
% %Discrete regulator
% REG_co= ss(A1,B1,C1,D1);
% 
% REG_disc=c2d(REG_co,T_s,'forward');
% PHI1=1+A1*T_s;
% GAMMA1=B1*T_s;
% H1=C1;
% J1=D1;
% %REG_disc.B leggermente diverso da B0*T_s
% %REG_disc.D diverso da D0
