% local function for plotting
function plotGrad(timVec, valuMat, batEndInxVec, titleString, xString, yString)
    bluVal = 1;
    redVal = 0;
    plot(timVec, valuMat(:, 1), 'Color', [redVal 0 bluVal]); 
    hold on;
    ax = gca; % current axes
    ax.YLim = [-1.2*min(min(valuMat)) 1.2*max(max(valuMat))];
    title(titleString);
    xlabel(xString);
    ylabel(yString);
    if length(batEndInxVec) > 1
        for valuMat_counter = 2 : length(batEndInxVec)
            scaVal = double(((valuMat_counter-1))) / double(length(batEndInxVec)-1);
            plot(timVec(1:end-1), valuMat(1:end-1, valuMat_counter), 'Color', [redVal+scaVal 0 bluVal-scaVal]); 
        end
    end

end