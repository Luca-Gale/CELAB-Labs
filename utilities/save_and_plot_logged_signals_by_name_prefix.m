% =========================================================================
% AUTO SAVE AND PLOT TOOL FOR SIMULINK SIGNALS (VIA "TO WORKSPACE" BLOCKS)
%
% HOW TO USE:
% 1. In Simulink, connect a **To Workspace** block to each signal of interest.
%    - Set the block to save data in **Structure With Time** format.
%    - Use a unique variable name for each signal.
%
% 2. Set the **Label** of the signal arrow (not the variable name) using this format:
%       groupName__signalName[unit]
%
%    - groupName  : Shared name among signals meant to be plotted in the
%                   same image. Can be any word.
%    - signalName : Name shown in plot legends and saved struct fields.
%    - unit       : Optional measurement unit (e.g., [deg], [V]).
%
%    ➤ Signals with no double underscore ("__") are treated individually.
%
% 3. After simulation, run this script. It will:
%    - Scan all struct variables in the base workspace.
%    - Identify signals based on `.signals.label` and `.time`.
%    - Group, plot, and save the data accordingly.
%
% OUTPUT:
%    A folder named "logged_outputs_YYYYMMDD" is created in the current
%    directory, containing:
%      - PNG plots for each signal or group
%      - Corresponding .mat files with signal data
%
% NOTES:
% - This tool relies on the signal **label**, not the Simulink variable name.
% - The signal structs must contain `.time` and `.signals.label`.
% - The measurement unit is optional but improves plot labeling.
%
% =========================================================================

function save_and_plot_logged_signals_by_name_prefix()

% OUTDATED, realtime simulation doesn't log signals with logsout
% Get 'out' from base workspace
% if ~evalin('base', 'exist(''out'', ''var'')')
%     error('Variable ''out'' not found in base workspace.');
% end
% out = evalin('base', 'out');
%
% try
%     logsout = out.logsout;
% catch
%     error('The ''out'' object does not contain ''logsout''.');
% end

% Detect valid structs rom workspace
vars = evalin('base', 'whos');
validSignals = {};

for i = 1:length(vars)
    varName = vars(i).name;
    varClass = vars(i).class;

    if strcmp(varClass, 'struct')
        data = evalin('base', varName);
        if isfield(data, 'time') && isfield(data, 'signals')
            validSignals{end+1} = struct('Name', varName, 'Values', data); %#ok<AGROW>
        end
    end
end

% Group signals by prefix (before "__")
groupMap = containers.Map();  % groupName -> {signals}
soloSignals = {};             % no underscore → individual

for i = 1:length(validSignals)
    sig = validSignals{i};
    label = sig.Values.signals.label;

    [groupName, ~, ~] = parse_signal_name(label);

    if ~isempty(groupName)
        if isKey(groupMap, groupName)
            group = groupMap(groupName);
            group{end+1} = sig; %#ok<AGROW>
            groupMap(groupName) = group;
        else
            groupMap(groupName) = {sig};
        end
    else
        soloSignals{end+1} = sig; %#ok<AGROW>
    end
end

% Output directory
dateStr = datestr(now, 'yyyymmdd'); % Format: YYYYMMDD
outputFolder = fullfile(pwd, ['logged_outputs_' dateStr]);
if ~exist(outputFolder, 'dir')
    mkdir(outputFolder);
end

% === Process grouped signals ===
tags = keys(groupMap);
for k = 1:length(tags)
    tag = tags{k};
    signals = groupMap(tag);
    signalStruct = struct();

    % Extract unit from first signal
    [~, ~, unit] = parse_signal_name(signals{1}.Values.signals.label);
    if ~isempty(unit)
        signalStruct.unit = unit;
    end

    figure('Visible', 'off');
    hold on;

    for s = 1:length(signals)
        sig = signals{s};
        [~, functionName, ~] = parse_signal_name(sig.Values.signals.label);

        fieldName = functionName;
        time = sig.Values.time;
        data = sig.Values.signals.values;

        plot(time, data, 'DisplayName', functionName);
        signalStruct.(fieldName).time = time;
        signalStruct.(fieldName).data = data;
    end

    %title(sprintf('Group: %s', tag), 'Interpreter', 'none');
    xlabel('Time [s]');

    if ~isempty(unit)
        ylabel(['Value [' unit ']']);
    else
        ylabel('Value');
    end

    legend('show');
    grid on;

    saveas(gcf, fullfile(outputFolder, [tag '.png']));
    close(gcf);

    save(fullfile(outputFolder, [tag '.mat']), 'signalStruct');
end

% === Process ungrouped signals ===
for i = 1:length(soloSignals)
    sig = soloSignals{i};
    label = sig.Values.signals.label;
    [~, functionName, unit] = parse_signal_name(label);
    fieldName = functionName;
    time = sig.Values.time;
    data = sig.Values.signals.values;
    figure('Visible', 'off');
    plot(time, data);
    title(functionName, 'Interpreter', 'none');
    xlabel('Time (s)');

    signalStruct = struct();
    if ~isempty(unit)
        ylabel(['Value [' unit ']']);
        signalStruct.unit = unit;
    else
        ylabel('Value');
    end

    signalStruct.(fieldName).time = time;
    signalStruct.(fieldName).data = data;

    saveas(gcf, fullfile(outputFolder, [sanitize_filename(functionName) '.png']));
    close(gcf);

    signalStruct.time = time;
    signalStruct.data = data;
    save(fullfile(outputFolder, [sanitize_filename(functionName) '.mat']), 'signalStruct');
end

disp(['✅ Grouped signals saved to: ' outputFolder]);
end


function [group, functionName, unit] = parse_signal_name(signalName)
% Split at double underscore to separate group and remainder
parts = strsplit(signalName, '__');
if numel(parts) < 2
    group = '';
    remainder = signalName;
else
    group = parts{1};
    remainder = strjoin(parts(2:end), '__');
end

% Extract unit in square brackets
expr = '^(.*?)\s*\[(.*?)\]$';
tokens = regexp(remainder, expr, 'tokens');

if ~isempty(tokens)
    functionName = strtrim(tokens{1}{1});
    unit = strtrim(tokens{1}{2});
else
    functionName = strtrim(remainder);
    unit = '';
end
end

function safeName = sanitize_filename(name)
safeName = regexprep(name, '[^\w\d\-_]', '_');
end


% To manually create the out struct:
% out = struct();
% out.logsout = logsout;
% assignin('base', 'out', out);