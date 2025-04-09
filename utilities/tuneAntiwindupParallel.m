function tuneAntiwindupParallel(gainRange, modelName, saveFileName)

    % Preallocate result storage
    numGains = length(gainRange);
    overshootVec = zeros(numGains, 1);
    riseTimeVec = zeros(numGains, 1);

    for i = 1:numGains
        simInputs(i) = Simulink.SimulationInput(modelName);
        simInputs(i) = simInputs(i).setVariable('aw', gainRange(i));
    end

    % Run simulations in parallel
    simOut = parsim(simInputs, 'ShowProgress', true, 'TransferBaseWorkspaceVariables', 'on');

    % Analyze results
    for i = 1:numGains
        out = simOut(i).logsout{1}.Values;
        time = out.Time;
        data = out.Data;

        % Compute overshoot and rise time
        finalValue = data(end);
        peakValue = max(data);
        overshoot = ((peakValue - finalValue) / finalValue) * 100;

        % Rise time: time from 10% to 90% of final value
        t10 = find(data >= 0.1 * finalValue, 1, 'first');
        t90 = find(data >= 0.9 * finalValue, 1, 'first');

        if ~isempty(t10) && ~isempty(t90)
            riseTime = time(t90) - time(t10);
        else
            riseTime = NaN;  % if rise time can't be determined
        end

        overshootVec(i) = overshoot;
        riseTimeVec(i) = riseTime;
    end

    % Save results
    resultsTable = table(gainRange(:), overshootVec, riseTimeVec, ...
                         'VariableNames', {'Gain', 'Overshoot', 'RiseTime'});
    save(saveFileName, 'resultsTable');

    % Find best gain where overshoot <= 10%
    validIdx = find(overshootVec <= 10 & ~isnan(riseTimeVec));
    if ~isempty(validIdx)
        [minRiseTime, minIdxRel] = min(riseTimeVec(validIdx));
        bestIdx = validIdx(minIdxRel);
        bestGain = gainRange(bestIdx);
        bestOvershoot = overshootVec(bestIdx);
        fprintf('Best gain with overshoot ≤ 10%%: %.4f\n', bestGain);
        fprintf('Rise time: %.4f s | Overshoot: %.2f %%\n', ...
                minRiseTime, bestOvershoot);
    else
        fprintf('No configuration found with overshoot ≤ 10%%.\n');
    end

    fprintf('Done! Results saved in %s\n', saveFileName);
end
