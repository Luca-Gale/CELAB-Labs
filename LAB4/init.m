clear all;
close all;
clc;

%% Load datasheet
addpath('..\..\CELAB-Labs\utilities\');
datasheet_balancing;

param.mot = mot;
param.gbox = gbox;
param.wheel = wheel;
param.body = body;

%% utilities
ua2tau = 2*gbox.N*mot.Kt/mot.R;

F = [
    2*(mot.B*wheel.B), -2*mot.B;
    -2*mot.B, 2*mot.B
    ];