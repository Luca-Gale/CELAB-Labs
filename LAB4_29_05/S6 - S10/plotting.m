%% plotting
figure(1);
plot(out.final.time,out.final.signals.values)
% title('S8-1');
xlabel('Time');
ylabel('Degree');
ylim([-50 50]);
grid on;


figure(2);
plot(out.final.time,out.final.signals.values)
% title('S8-1');
xlabel('Time');
ylabel('Degree');
ylim([-15 15]);
grid on;
