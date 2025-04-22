% clc;
% clear;

%% Real-time LAB2
% T1=load('ali_newlambda_1ms.mat');
% T10=load('ali_newlambda_10ms.mat');
% T50ali=load('ali_newlambda_50ms.mat');
% T50prof=load('ali_proflambda_50ms.mat');
% 
% idx = T1.ali_50ms.time < 2;
% idx1 = T10.ali_50ms.time < 2;
% idx2 = T50ali.ali_50ms.time < 2;
% idx3 = T50prof.ali_50ms.time < 2;
% 
% figure;
% stairs(T1.ali_50ms.time(idx),T1.ali_50ms.signals(1).values(idx))
% grid on;
% xlabel('Time');
% ylabel('Position');
% title('Ts = 1ms');
% 
% 
% figure;
% stairs(T10.ali_50ms.time(idx1),T10.ali_50ms.signals(1).values(idx1))
% grid on;
% xlabel('Time');
% ylabel('Position');
% title('Ts = 10ms');
% % legend();
% 
% 
% figure;
% stairs(T50ali.ali_50ms.time(idx2),T50ali.ali_50ms.signals(1).values(idx2))
% grid on;
% xlabel('Time');
% ylabel('Position');
% title('Ts = 50ms');
% % legend();
% 
% 
% figure;
% stairs(T50prof.ali_50ms.time(idx3),T50prof.ali_50ms.signals(1).values(idx3))
% grid on;
% xlabel('Time');
% ylabel('Position');
% title('Ts = 50ms');
% % legend();


%% simulation LAB2
figure;
% stairs(T50prof.ali_50ms.time(idx3),T50prof.ali_50ms.signals(1).values(idx3))
stairs(out.final3.time,out.final3.signals.values)
% xticks(0:0.2:5);    % Smaller spacing on x-axis
% yticks(0:10:150); 
grid on;
xlabel('Time');
ylabel('Position');
title('Discrete time, Ts = 10ms');
% % legend();