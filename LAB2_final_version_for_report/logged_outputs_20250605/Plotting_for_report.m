% Assign here the signals to plot
pairs = {
    struct('t', pid.lab.be.ms1.t,   'y', pid.lab.be.ms1.r),  
    struct('t', pid.lab.be.ms1.t,   'y', pid.lab.be.ms1.y),  
    struct('t', pid.lab.be.ms10.t,  'y', pid.lab.be.ms10.y), 
    struct('t', pid.lab.be.ms50.t,  'y', pid.lab.be.ms50.y)  
};

% Configuration (change the highlighted parts)
cfg = struct( ...
    'labels', struct( ...
        'xlabel', 'Time [s]', ...
        'ylabel', 'Degrees [deg]', ...
        'title',  'PID Transient and Asymptotic Behaviour' ... % Adapt the title
    ), ...
    'legend', {'Ref', '1ms', '10ms', '50ms'}, ... % Adapt the legend
    'colors', {'k--', 'r', 'g', 'b'}, ...
    'lineWidth', 1.8, ...
    'fontSize', 12, ...
    'titleSize', 14, ...
    'axisLimits', struct('x', [0.9 2], 'y', [0 95]), ... % Adapt the zoom for transient
    'figureSize', [100 100 640 400], ...
    'zoomRange', [2.0 2.5], ... % Adapt the zoom for asymptotic
    'zoomYLim', [45 55], ... % Adapt yli for zoomed plot
    'insetPos', [0.59 0.19 0.3 0.2] ... % Change the ubplot position only if necessary, [x y width height] in normalized units
);

% Call the function
plot_with_inset(pairs, cfg);

% Save figure as PNG (change filename and format as needed)
saveas(gcf, 'my_plot.png');

function plot_with_inset(timeSignalPairs, config)
% PLOT_WITH_INSET - Plots multiple time-signal pairs with consistent formatting and an optional zoomed-in inset.
%
% Parameters:
%   timeSignalPairs - cell array of structs with fields:
%       .t: time vector
%       .y: signal vector
%
%   config - struct with fields:
%       .labels: struct with .xlabel, .ylabel, .title
%       .legend: cell array of legend entries
%       .colors: cell array of line style/colors (e.g., {'b--', '-', '-', '-'})
%       .lineWidth: line thickness (e.g., 1.8)
%       .fontSize: axis font size
%       .titleSize: title font size
%       .axisLimits: struct with .x and .y limits (e.g., [xmin xmax], [ymin ymax])
%       .figureSize: [x y width height]
%       .zoomRange: [xmin xmax] for inset
%       .zoomYLim: [ymin ymax] for inset
%       .insetPos: [x y width height] (normalized units)

%% Common interpolation time vector
t_common = 0:0.001:10;

% Interpolate all signals to t_common
interpolated = cell(size(timeSignalPairs));
for i = 1:length(timeSignalPairs)
    t = timeSignalPairs{i}.t;
    y = timeSignalPairs{i}.y;
    y_interp = interp1(t, y, t_common, 'spline');
    interpolated{i} = struct('t', t_common, 'y', y_interp);
end

% Prefilter t make sure all the signals are 0 before the step
zero_indices = (interpolated{1}.y == 0);

% Set all signals to zero at those time points
for i = 1:length(interpolated)
    y = interpolated{i}.y;
    y(zero_indices) = 0;
    interpolated{i}.y = y;
end

%% Main plot
figure;
hold on;

for i = 1:length(interpolated)
    plot(interpolated{i}.t, interpolated{i}.y, config(i).colors, 'LineWidth', config(1).lineWidth);
end

grid on;
box on;
set(gca, 'FontSize', config(1).fontSize, 'LineWidth', 1);
set(gcf, 'Color', 'w');

xlabel(config(1).labels.xlabel, 'FontSize', config(1).fontSize + 1);
ylabel(config(1).labels.ylabel, 'FontSize', config(1).fontSize + 1);
title(config(1).labels.title, 'FontSize', config(1).titleSize, 'FontWeight', 'bold');

legend(config.legend, 'FontSize', config(1).fontSize - 1, 'Location', 'best');

xlim(config(1).axisLimits.x);
ylim(config(1).axisLimits.y);
set(gcf, 'Position', config(1).figureSize);

%% Inset axes
inset = axes('Position', config(1).insetPos);
box on; grid on; hold on;

zoomStart = config(1).zoomRange(1);
zoomEnd = config(1).zoomRange(2);

for i = 1:length(interpolated)
    t = interpolated{i}.t;
    y = interpolated{i}.y;
    mask = (t >= zoomStart & t <= zoomEnd);
    plot(t(mask), y(mask), config(i).colors,  'LineWidth', config(1).lineWidth);
end

xlim(config(1).zoomRange);
ylim(config(1).zoomYLim);
set(gca, 'FontSize', config(1).fontSize - 2);
set(inset, 'LineWidth', 1);
uistack(inset, 'top');
end