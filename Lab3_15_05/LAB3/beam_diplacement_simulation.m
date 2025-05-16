% Beam Displacement Signal Simulation and Preprocessing
%
% This script simulates the beam displacement data, which would typically 
% be obtained from a potentiometer in an experimental setup, and processes 
% the noisy signal. The signal is smoothed using the Savitzky-Golay filter 
% to aid in peak detection, which is essential for subsequent parameter 
% estimation.
%
% Key Components:
% 1. Signal Simulation (Using a Simulink model, "estimation_simulink.slx")
%    - The simulation generates displacement data (noisySignal) over time.
% 2. Signal Smoothing (Savitzky-Golay filter applied to noisy signal)
%    - The smoothing factor is defined by `interpFactor` to reduce noise.
% 3. Peak Detection (Local maxima are detected in the smoothed signal)
%    - Custom `detectPeaks` function identifies the peaks of the signal.
% 4. Peak Interpolation (Linear interpolation used to extend the peak 
%    sequence and fit a smooth curve through the peak values)
%
% Assumptions:
% - Simulink model (`estimation_simulink.slx`) is used to simulate the noisy 
%   displacement data. If experimental data is available, the simulation part 
%   can be skipped.
%
% Inputs:
% - Noisy signal from Simulink (time and displacement data)
% - Pre-defined parameters (such as natural frequency, damping ratio, etc.)
%
% Outputs:
% - Smoothed displacement signal
% - Peak values and times for further analysis
%

clear all;
close all;
clc;

% Add resources to workspace
addpath('..\..\CELAB-Labs\utilities\');
datasheet;
datasheet_resonant;

% Parameters
delta = 0.05;      % Damping ratio
omega_n = 24.4;      % Natural frequency [rad/s]
A = 30;            % Initial amplitude [deg]
phi = 0;           % Initial phase [rad]
%%
load_system("estimation_simulink.slx");
out = sim("estimation_simulink.slx");
close_system("estimation_simulink.slx", 0);
%%
% Define time array and signal values
t = out.out.time;
noisySignal = out.out.signals.values;

