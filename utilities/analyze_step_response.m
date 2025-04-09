function [riseTime, settlingTime, overshoot] = analyze_step_response(reference, response)
    % Extract time and values
    t = response.Time;
    y = response.Data;
    r = reference.Data;

    % Use final reference value as target
    finalValue = r(end);

    % Normalize response relative to step target
    y_norm = y / finalValue;

    %% Rise Time (from 10% to 90%)
    idx10 = find(y_norm >= 0.1, 1, 'first');
    idx90 = find(y_norm >= 0.9, 1, 'first');
    riseTime = t(idx90) - t(idx10);

    %% Settling Time (within ±5% of final value)
    tol = 0.05;
    withinBounds = abs(y_norm - 1) <= tol;
    % Find the last time it goes outside the bounds
    lastOutOfBounds = find(~withinBounds, 1, 'last');
    if isempty(lastOutOfBounds)
        settlingTime = t(1); % already within bounds
    else
        % Settling time is first point after last violation
        settlingIdx = find(t > t(lastOutOfBounds) & withinBounds, 1, 'first');
        if isempty(settlingIdx)
            settlingTime = NaN; % never settles
        else
            settlingTime = t(settlingIdx);
        end
    end

    %% Overshoot (as % of final value)
    peakValue = max(y);
    overshoot = max(0, (peakValue - finalValue) / finalValue) * 100;
end
