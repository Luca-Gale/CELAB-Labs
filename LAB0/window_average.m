function [avg_values] = window_average(signal, T, N_periods, window1, window2, showplot)

%   Function to define two temporal windows in which compute the average
%   of the values of a signal in each period.
%   Input:  - signal: struct with time from workspace in the form out.[name]
%           - T: period [s] of the signal
%           - N_periods: number of periods of the signal
%           - window1: first averaging window
%           - window2: second averaging window
%           - showplot: '1' to plot the windowed signal, '0' otherwise
%   Output: - avg_values: vector containing the averages in each window of each period  

avg_values = zeros(N_periods, 2); % Store average values for each period
values = signal.signals.values;
t=signal.time;
for k = 1:N_periods
    % Define time limits for this period
    t_start = (k-1) * T;
    
    % Extract indices for the two windows in this period
    idx1 = (t >= t_start + window1(1)) & (t < t_start + window1(2));
    idx2 = (t >= t_start + window2(1)) & (t < t_start + window2(2));
    
    % Compute the mean in each window
    avg_values(k,1) = mean(values(idx1));
    avg_values(k,2) = mean(values(idx2));
end
% Display results
disp('Averages for each period:');
disp(array2table(avg_values, 'VariableNames', {'Window1', 'Window2'}));

if showplot
    % Plot signal with highlighted windows
    figure;
    plot(t, values, 'k'); 
    hold on;
    for k = 1:N_periods
        t_start = (k-1) * T;
        fill([t_start+window1(1), t_start+window1(2), t_start+window1(2), t_start+window1(1)], ...
            [min(values), min(values), max(values), max(values)], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
        fill([t_start+window2(1), t_start+window2(2), t_start+window2(2), t_start+window2(1)], ...
            [min(values), min(values), max(values), max(values)], 'b', 'FaceAlpha', 0.2, 'EdgeColor', 'none');
    end
    xlabel('Time (s)');
    ylabel('Signal Value');
    title('Averaging Windows');
    legend({'Signal', 'Window 1', 'Window 2'});
    grid on;
end

end
