clear
close all
clc

%% Load Data
load('first.mat');
load('second.mat');
load('third.mat');
load('fourth.mat');

%% Plotting with Different Plots
figure
title('40 Step')
plot(first.time,first.signals.values), hold on
plot(first.time,second.signals.values)
plot(first.time,third.signals.values)
plot(first.time,fourth.signals.values)
legend({'First', 'Second','Third','Fourth'}, 'Location', 'best');

figure;
title('40 Step Error')
plot(first.time,40-first.signals.values), hold on
plot(first.time,40-second.signals.values)
plot(first.time,40-third.signals.values)
plot(first.time,40-fourth.signals.values)
legend({'First', 'Second','Third','Fourth'}, 'Location', 'best');