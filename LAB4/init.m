clear all;
close all;
clc;

%% Load datasheet
addpath('..\..\CELAB-Labs\utilities\');
datasheet_balancing;
%% utilities
ua2tau = 2*gbox.N*mot.Kt/mot.R;
M =@(q) [
   2 * wheel.Iyy + 2*gbox.N * mot.rot.Iyy + (body.m + 2*wheel.m + 2*mot.rot.m)*wheel.r^2 , 
   2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r*cos(q(2));
   2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r*cos(q(2)),
   body.Iyy+2*(1-gbox.N)^2*mot.rot.Iyy+body.m*body.zb^2+2*mot.rot.m*mot.rot.zb^2
   ];

C = @(q) [
    0,
    -(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r*sin(q(2))*q(4);
    0,
    0
    ];
Gq = @(q) [
    0;
    -(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*g*sin(q(2))
    ];
F = [
    2*(mot.B*wheel.B),
    -2*mot.B;
    -2*mot.B,
    2*mot.B
    ];