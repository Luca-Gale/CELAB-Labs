close all
clc
% 
% %% Plotting
% fig = figure("Name", "Plots", "Units","normalized", "OuterPosition", [0, 0, 1, 1]);
% 
% subplot(2, 2, 1)
% plot(w_m.time, w_m.signals.values, "LineWidth", 2)
% grid on
% xlabel("Time [s]")
% ylabel("\omega_m [krpm]")
% 
% 
% subplot(2, 2, 2)
% plot(a_m.time, a_m.signals.values, "LineWidth", 2)
% grid on
% xlabel("Time [s]")
% ylabel("a_m [krpm/s]")
% 
% 
% subplot(2, 2, 3)
% plot(i_a.time, i_a.signals.values, "LineWidth", 2)
% grid on
% xlabel("Time [s]")
% ylabel("i_m [A]")
% 
% 
% subplot(2, 2, 4)
% plot(tau_i.time, tau_i.signals.values, "LineWidth", 2)
% grid on
% xlabel("Time [s]")
% ylabel("\tau_i [Nm]")
% 
% sgtitle("Plots", "FontSize", 24)

%% Save Data
t = string(datetime('now','TimeZone','local','Format','yHHmmss'));
save("Data/Friction" + t + ".mat", "Voltage2Shunt", "ThPulses")