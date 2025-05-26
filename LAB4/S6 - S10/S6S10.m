%% Create the matrix M & C & g & Fv1

%create the M matrix

M12=2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;

M11=2*wheel.Iyy + 2*gbox.N^2*mot.rot.Iyy + (body.m + 2*wheel.m+2*mot.rot.m)*wheel.r^2;
M22=body.Iyy+2*((1-gbox.N)^(2))*mot.rot.Iyy+body.m*(body.zb^2)+2*mot.rot.m*(mot.rot.zb)^2;

M21=M12;

M=[M11,M12;M21,M22];

%create C matrix
C11=0;
C21=C11;
C22=C21;
C12=-(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;
C=[C11,C12;C21,C22];

% Create vector g
g1=0;
g2=-g*(body.m*body.zb + 2*mot.rot.m*mot.rot.zb);
g_q=[0;g2];
%Create Matrix G
G=[0,0;0,g2];

% Create Fv1
b=gbox.N^2*mot.B+gbox.B;
Fv1_11=2*(gbox.B+wheel.B);
Fv1_12=-2*gbox.B;
Fv1_21=Fv1_12;
Fv1_22=2*gbox.B;

Fv1=[Fv1_11,Fv1_12;Fv1_21,Fv1_22];

Fv1_d=Fv1+(2*gbox.N^(2)*mot.Kt*mot.Ke/mot.R)*[1 -1;-1 1];
ua2tau=2*gbox.N*mot.Kt/mot.R*[1;-1];



numHom=[1,0,0,-1];
denHom=[1,0,0,0]*3*Ts*[1];
Hom = tf(numHom,denHom,Ts);


fc=0.35;
Tc=1/(fc*2*pi);


%% State space matrices

 % Matrix A
 A=[0,0,1,0;
    0,0,0,1;
    -(M^(-1))*G,-M^(-1)*Fv1_d];
 B=2*gbox.N*mot.Kt/mot.R*[0,0;0,0;M^(-1)]*[1;-1];
 C=[1,0,0,0];
 D=0;
 P_cont= ss(A,B,C,D);
 P_dis=c2d(P_cont,Ts,'zoh');
ro=100;
gamma_lim=pi/18;
theta_lim=pi/360;
u_lim=1;
vect_diag=[1/(gamma_lim)^2,1/(theta_lim^2),0,0];
Q=diag(vect_diag);
r=1/u_lim^2;
[K,S,e]=dlqr(P_dis.A,P_dis.B,Q,r*ro);

q11=0.2;
vect_diag2=[q11,1/(gamma_lim)^2,1/(theta_lim^2),0,0];
Q2=diag(vect_diag2);

integral.Phi=[1 C;
    zeros(4,1) P_dis.A];
integral.Gam=[0;
    P_dis.B];

integral.coeff=[integral.Phi-eye(size(integral.Phi)) integral.Gam ; C 0 0];
integral.serra=inv(integral.coeff)*[0; 0; 0; 0; 0; 1];
integral.Nx=[integral.serra(1:4)];
integral.Nu=integral.serra(6);

[integral.K,S,e]=dlqr(integral.Phi,integral.Gam,Q2,r*ro);
integral.Ki=integral.K(1);
integral.Ke=[integral.K(2),integral.K(3),integral.K(4),integral.K(5)];

% Feedforward gains
I=[1,0,0,0;
    0,1,0,0;
    0,0,1,0;
    0,0,0,1];
P_matdisN=[P_dis.A-I,P_dis.B;P_dis.C,P_dis.D];
f=[0;0;0;0;1];
N_disc= linsolve(P_matdisN,f);
N_x=[N_disc(1);N_disc(2);N_disc(3);N_disc(4)];
N_u=[N_disc(5)];

%%
CCC = Ts/(Tc+Ts);