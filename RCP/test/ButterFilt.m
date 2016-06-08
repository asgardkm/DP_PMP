function output_data = ButterFilt(input_data) %#codegen
    [b,a] = butter(4, 0.25);
    output_data = filter(b, a, input_data); 
end