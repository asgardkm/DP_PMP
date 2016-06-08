rng(0, 'twister');
%white noise input
input_data = randn(512,1);

% compute autocorrelation with MEX-file
[C, Lags] = myxcorr(input_data, input_data);

% plot result
stem(Lags, C);
axis([-0.5 51 -1.1 1.1]);
xlabel('Lags');
ylabel('Autocorrelation Function');