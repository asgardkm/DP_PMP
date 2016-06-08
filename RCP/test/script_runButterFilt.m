    Fs = 20000;
    % create 10000x1 input signal
    t = 0 : (1/Fs) : 0.5-(1/Fs);
    input_data = (cos(2*pi*1000*t) + sin(2*pi*500*t) + 0.2*randn(size(t)))';
    %filter data
    output_data = ButterFilt(input_data);