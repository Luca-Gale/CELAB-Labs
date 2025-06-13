clear all
% clc

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
T1=75;
T2=75;
pole1 = (-delta * wn)-T1 + j*(wn*sqrt(1-delta^2)+T2);
pole2 = (-delta * wn)-T1 - j*(wn*sqrt(1-delta^2)+T2);
poles = [pole1,pole2];
K = acker(A,B,poles);
Nr=Nu+K * Nx;
%% part 2 - Integral 
sigma = real ( pole1 );
omega_d = imag ( pole1 );
poles2 = [sigma+ j*omega_d, sigma-j*omega_d, sigma ];
%poles2 = sigma * ones (3 ,1);

Ae =[0  ,C; zeros(2, 1), A ];
Be= [0 ; B];
Ce =[0 C]; 
De = 0;
K_robust  = acker (Ae , Be , poles2 );
KI = K_robust(1);
K2 = K_robust(2:3);
%% new OBSERVER NORMAL STATE SPACE OBSERVER

T_s=0.001*10;

% T_s = 1ms , 10ms , 50ms
I=[1,0;0,1];
T_trsf=I;
A_prime=T_trsf^(-1)*A*T_trsf;


%lambda0=5*sigma;
lambdaeddi = -5 * abs(pole1);
lambdaali = (-delta * wn) + j*wn*sqrt(1-delta^2)*5;
lambda2 = -5*wn*delta;
lambdanew = ((-delta * wn)-T1)*5 + j*(wn*sqrt(1-delta^2)+T2);
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


