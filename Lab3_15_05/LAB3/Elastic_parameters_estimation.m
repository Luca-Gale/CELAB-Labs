% Beam Parameter Estimation Based on Displacement Signal
%
% This script performs system identification on the beam's displacement 
% data to estimate critical mechanical properties such as the damping ratio, 
% natural frequency, stiffness, and viscous friction coefficient. 
% The estimation is based on the peak values detected in the smoothed signal.
%
% Key Components:
% 1. Peak Value Extraction (Detects local maxima from the smoothed signal)
%    - Peaks are detected using the `detectPeaks` function.
% 2. Linear Regression (Fits a logarithmic model to the detected peaks)
%    - Regression is used to estimate the damping ratio and natural frequency.
% 3. Damping Ratio and Natural Frequency Estimation:
%    - Damping ratio (delta_hat) is derived from the linear regression parameters.
%    - Natural frequency (omega_n_hat) is estimated from the peak times and damping.
% 4. System Parameter Identification:
%    - Estimation of the beam's stiffness (`k_hat`) and viscous friction 
%      coefficient (`Bb_hat`) using the natural frequency and damping ratio.
%
% Assumptions:
% - The script assumes the peak values and corresponding times have already 
%   been extracted from the displacement signal.
% - The beam's moment of inertia (`Jb`) is a known constant.
%
% Inputs:
% - Smoothed signal (or directly processed signal from `beam_displacement_simulation.m`)
% - Time vector and detected peak values
%
% Outputs:
% - Estimated parameters: damping ratio, natural frequency, stiffness, 
%   viscous friction coefficient
%
% Plots:
% - The script generates plots comparing the original and smoothed signals,
%   as well as the estimated signal.
%

%% Add resources to workspace (before blackbox simulation)
%clear all;
%close all;
%clc;
addpath('..\utilities\');
datasheet;
datasheet_resonant;
t0 = 0.2;
t1 = 0.7;

%%
%y = out.signals.values;
%% Run from this point if the beam displacement is already available in the workspace

% Define time array and signal values
% IMPORTANT: adapt these lines to realtime simulation output
%noisySignal = out.signals.values;
noisySignal = y;
%t = out.out.time;

% Since in a noisy signal it's hard to detect local maxima, use Savitzky-Golay filter to 
% smooth the entire signal 
interpFactor = 50; % Higher the factor, the more aggressive is the interpolation 
smoothSignal = smoothdata(noisySignal, 'sgolay', interpFactor);

% Threshold for consecutive peak differences in percentage
diffThreshold = 1;  % Percentage threshold

% Peak detection on the smoothed signal
[peakValues, peakTimes] = detectPeaks(abs(smoothSignal), t);

% Checks if at least a pick has been detected
if isempty(peakValues)
   error('No peak detected.');
else
    % This part is not necessary. But since I'm a phycopath I cannot accept
    % that the dotted line interpolating the maxima points is not arriving
    % at the end of the image.
    extendedTimes = [peakTimes; t(end)];
    extendedValues = [peakValues; peakValues(end)];
end

% Interpolating line for smoothed signal
interpValues = interp1(extendedTimes, extendedValues, t, 'linear');

% Limiting the peaks for parameter estimation based on percentage difference
M = length(peakValues);
if M > 1
    % Calculate percentage differences
    percentageDifferences = abs(diff(peakValues)) ./ peakValues(1:end-1) * 100;

    % Find the first index where the percentage difference is less than the threshold
    cutoffIndex = find(percentageDifferences < diffThreshold, 1, 'first');

    % If such a point is found, use only up to that point for estimation
    if ~isempty(cutoffIndex)
        % Include the first point, so the index range is 1:cutoffIndex
        selectedIndices = 1:cutoffIndex;
    else
        % If no cutoff is found, use all peaks
        selectedIndices = 1:M;
    end
else
    % Only one peak found, use it
    selectedIndices = 1;
end

% Redifine everything
peakValues = peakValues(selectedIndices);
peakTimes = peakTimes(selectedIndices);
M = length(peakValues);

%% Parameter estimation part
% Linear regression
Y = log(peakValues);
Phi = [-(0:M-1)', ones(M,1)];
theta_hat_ls = Phi \ Y;
espilon_hat = theta_hat_ls(1); 

% Damping factor estimation
delta_hat = espilon_hat/sqrt(pi^2 + espilon_hat^2)

% Natural frequency estimation
Tk = diff(peakTimes)
omega_k_hat = pi ./ Tk
omega_hat = mean(omega_k_hat);
omega_n_hat = omega_hat/sqrt(1-delta_hat^2)

% Nominal value for beam moment of inertia Jb
Jb = 1.4e-3; % [kg*m^2]

% Beam viscous friction coefficient estimation
Bb_hat = Jb*2*delta_hat*omega_n_hat

% Joint stiffness estimation
k_hat = Jb*omega_n_hat^2

%% Saving in .mat file the results
%save('..\utilities\black-box-resonat-load', "delta_hat", "omega_n_hat", "Bb_hat", "k_hat", "noisySignal", "t", "smoothSignal");

%% Plotting
figure;

% Plot noisy signal with smoothed signal
subplot(3, 1, 1);
plot(t, noisySignal, 'b', 'LineWidth', 1.2); 
hold on;
plot(t, smoothSignal, 'g', 'LineWidth', 1.2); 

xlabel('Time [s]');
ylabel('theta_d [deg]');
title('Original and Smoothed Beam Displacement');
legend('Original Signal', 'Smoothed Signal');
grid on;

% Plot the absolute value of the smoothed signal with extended interpolating line
subplot(3, 1, 2);
plot(t, abs(smoothSignal), 'b', 'LineWidth', 1.2); 
hold on;
plot(peakTimes, abs(peakValues), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r');
plot(t, interpValues, 'r--', 'LineWidth', 1);

xlabel('Time [s]');
ylabel('|theta_d| [deg]');
%ylim([0,smoothSignal(1)+5]);
title('Absolute Value with Interpolated Peaks');
grid on;

% Plot noisy signal with estimated signal
subplot(3, 1, 3);
plot(t, noisySignal, 'b', 'LineWidth', 1.2); 
hold on;

% Define the estimated signal using the calculated parameters
A_est = peakValues(1);  % Initial amplitude as the first detected peak
theta_d_est = A_est * exp(-delta_hat * omega_n_hat * t) .* ...
    cos(omega_n_hat * sqrt(1 - delta_hat^2) * t);

plot(t, theta_d_est, 'r--', 'LineWidth', 1.2);

xlabel('Time [s]');
ylabel('theta_d [deg]');
title('Original and Estimated Beam Displacement');
legend('Original Signal', 'Estimated Signal');
grid on;

%% Peak Detection Function
% "findpeaks" is an already implemented function to do exactly this. BUT it belong to the Signal 
% Processing Toolbox and I don't know if it's available in the lab.

function [peakValues, peakTimes] = detectPeaks(signal, time)
    % DETECTPEAKS - Detect peaks by comparing each point to its neighbors
    %
    % Inputs:
    %   - signal: Interpolated signal
    %   - time: Time vector for interpolated signal
    %
    % Outputs:
    %   - peakValues: Detected peak values
    %   - peakTimes: Time instants of detected peaks
    
    n = length(signal);
    
    % Add first value of the signal as the first peak
    peakValues = signal(1);
    peakTimes = time(1);
    
    for i = 2:n-1
        % Compare current point with its neighbors
        if signal(i) > signal(i-1) && signal(i) > signal(i+1)
            peakValues(end + 1) = signal(i);
            peakTimes(end + 1) = time(i);
        end
    end
    
    % Convert to column vectors
    peakValues = peakValues(:);
    peakTimes = peakTimes(:);
end
