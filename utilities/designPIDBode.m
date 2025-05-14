function [Kp, Ki, Kd, tl, wgc] = designPIDBode(P, ts, mp, alpha)
% designPIDBode - PID Controller Design via Frequency-Domain Bode Method
%
% Inputs:
%   P      - Transfer function of the plant
%   ts     - Desired settling time (s)
%   mp     - Maximum overshoot (e.g., 0.1 for 10%)
%   alpha  - Ratio Ti/Td 
%   tl     - Constant for derivative filter
%
% Outputs:
%   Kp, Ki, Kd - PID controller gains
%   wgc    - Gain crossover frequency (rad/s)

    % Step 1: Calculate damping ratio from overshoot
    delta = log(1/mp) / sqrt(pi^2 + log(1/mp)^2);

    % Step 2: Desired gain crossover frequency (rad/s)
    wgc = 3 / (delta * ts);

    % Step 3: Desired phase margin (phim)
    phim = atan2(2 * delta, sqrt(sqrt(1 + 4*delta^4) - 2*delta^2));

    % Step 4: Compute plant transfer function at wgc
    s = 1i * wgc;
    Pwgc = evalfr(P, s);

    % Step 5: Gain and phase compensation
    abs_P = abs(Pwgc);
    deltak = 1 / abs_P;
    deltaphi = -pi + phim - angle(Pwgc);

    % Step 6: PID parameters from compensation
    Kp = deltak * cos(deltaphi);
    tanphi = tan(deltaphi);
    Td = (tanphi + sqrt(tanphi^2 + 4 / alpha)) / (2 * wgc);
    Ti = alpha * Td;
    Kd = Kp * Td;
    Ki = Kp / Ti;
    tl = 1/(3*wgc); % proportional coefficient between 2-5. Chosen 3

    

    % Optional: Display values
    fprintf('PID Gains:\n  Kp = %.4f\n  Ki = %.4f\n  Kd = %.4f\n tl = %.4f\n', Kp, Ki, Kd, tl);    
end
