%% Load datasheet into workspace
addpath("../utilities/");
datasheet_balancing;
%% M matrix
M11 = 2*wheel.Iyy + 2*gbox.N^2*mot.rot.Iyy + (body.m + 2*wheel.m + 2*mot.rot.m)*wheel.r^2;
M22 = body.Iyy + 2*(1-gbox.N)^2*mot.rot.Iyy + body.m*body.zb^2 + 2*mot.rot.m*mot.rot.zb^2;

%% Fv Matrix
Fv = [2*(mot.B*wheel.B), -2*mot.B;-2*mot.B, 2*mot.B];