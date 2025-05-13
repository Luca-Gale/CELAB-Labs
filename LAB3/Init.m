clear all;
close all;
clc;

%% Load datasheet
addpath('..\..\CELAB-Labs\utilities\');
datasheet;
datasheet_resonant;

%% Beq, Jeq_hat, tau_sf
load('..\utilities\black-box-estimation.mat');

%% Define t1, t2 for bias computation
t0 = 0.2;
t1 = 0.7; % arbitrary values

