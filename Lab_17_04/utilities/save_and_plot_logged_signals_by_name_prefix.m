function save_and_plot_logged_signals_by_name_prefix()

    % HOW TO USE THIS AUTOMATIC SAVE AND PLOT TOOL
    % - In Simulink right click on the signal we are interested in -> Log
    % Selected Signal
    % - Name the signal arrow following this rule 'groupName__signalName
    % [UM]' where
    %   - groupName is an arbitrary word we put in all the signals we want
    %   to plot and save in the same file
    %   - signalName is the name that will be shown in the legenda and as
    %   file name
    %   - UM is the measurement unit
    %   IT'S CRUCIAL TO FOLLOW THE NOMENCLATURE
    % - Run the script and a folder with today's date will be created
    % containing all the plots and the .mat files for future use.

    % Get 'out' from base workspace
    if ~evalin('base', 'exist(''out'', ''var'')')
        error('Variable ''out'' not found in base workspace.');
    end
    out = evalin('base', 'out');

    try
        logsout = out.logsout;
    catch
        error('The ''out'' object does not contain ''logsout''.');
    end

    % Group signals by prefix (before "__")
    groupMap = containers.Map();  % groupName -> {signals}
    soloSignals = {};             % no underscore → individual

    for i = 1:logsout.numElements
        sig = logsout.getElement(i);
        name = sig.Name;

        [groupName, ~, ~] = parse_signal_name(name);
           
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
        [~, ~, unit] = parse_signal_name(signals{1}.Name);
        if ~isempty(unit)
            signalStruct.unit = unit;
        end

        figure('Visible', 'off');
        hold on;

        for s = 1:length(signals)
            sig = signals{s};
            [~, functionName, ~] = parse_signal_name(sig.Name);

            fieldName = functionName;
            time = sig.Values.Time;
            data = sig.Values.Data;

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
        name = sig.Name;
        [~, functionName, unit] = parse_signal_name(name);
        fieldName = functionName;
        time = sig.Values.Time;
        data = sig.Values.Data;

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

        saveas(gcf, fullfile(outputFolder, [name '.png']));
        close(gcf);

        signalStruct.time = time;
        signalStruct.data = data;
        save(fullfile(outputFolder, [name '.mat']), 'signalStruct');
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


% To manually create the out struct:
% out = struct();
% out.logsout = logsout;
% assignin('base', 'out', out);