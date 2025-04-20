clc;
clear;

T1=load('ali_newlambda_1ms.mat');
T10=load('ali_newlambda_10ms.mat');
T50ali=load('ali_newlambda_50ms.mat');
T50prof=load('ali_proflambda_50ms.mat');

figure;
plot(T1.ali_50ms.time,T1.ali_50ms.signals(1).values)

figure;
plot(T10.ali_50ms.time,T10.ali_50ms.signals(1).values)

figure;
plot(T50ali.ali_50ms.time,T50ali.ali_50ms.signals(1).values)

figure;
plot(T50prof.ali_50ms.time,T50prof.ali_50ms.signals(1).values)