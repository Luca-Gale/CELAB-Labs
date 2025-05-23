%% First order complementary filter (generic implementation)
fc = 0.35; %[Hz]
Tc = 1/(2*pi*fc);
% Forward Euler
z = tf('z', Ts);
s = (z-1)/Ts;
H_z = 1/(Tc*s+1);
comp_H_z = Tc*s/(Tc*s+1);
[numH, denH] = tfdata(H_z, 'v');

%% First order complementary filter (Backward Euler implementation)
C = Tc/(Tc+Ts);

%% Real derivative filter for speeds
N = 3;
H_w = (1-z^-N)/(N*Ts);
[numHw, denHW] = tfdata(H_w, 'v');
