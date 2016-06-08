function[C, Lags] = myxcorr(x,y) %#codegen
    [c, lags] = xcorr(x, y, 50, 'coeff');
    C    = c(51:end);
    Lags = lags(51:end);