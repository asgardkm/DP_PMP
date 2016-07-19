%#codegen
% zi = codegen_interp2(X,Y,Z,xi,yi) gives the same result as
% interp2(X,Y,Z,xi,yi)
% Unlike interp2, codegen_interp2 is compatible with code generation
% Only linear interpolation is available

% Usage restrictions
%   X and Y must have the same size as Z
%   e.g.,  [X,Y] = meshgrid(x,y);

function Zi = codegen_interp2(X,Y,Z,xi,yi)

ndx = 1/(X(1,2)-X(1,1));        ndy = 1/(Y(2,1)-Y(1,1));

idyi=(xi - X(1,1))*ndx+1;       idxi=(yi - Y(1,1))*ndy+1;

if idxi <= 1 || idyi <= 1 || idxi > length(Y(:,1)) || idyi > length(X(1,:)) ...
    || isnan(xi) || isnan(yi)
    Zi = inf;
    return;
end

if idxi/ceil(idxi)~=1&&idyi/ceil(idyi)~=1
    Z1=Z(ceil(idxi)-1,ceil(idyi)-1);
    Z2=Z(ceil(idxi)-1,ceil(idyi));
    Z3=Z(ceil(idxi),ceil(idyi)-1);
    Z4=Z(ceil(idxi),ceil(idyi));
    
    Zi= Z1*(ceil(idxi)-idxi)*(ceil(idyi)-idyi)+...
        Z2*(ceil(idxi)-idxi)*(1-(ceil(idyi)-idyi))+...
        Z3*(1-(ceil(idxi)-idxi))*(ceil(idyi)-idyi)+...
        Z4*(1-(ceil(idxi)-idxi))*(1-(ceil(idyi)-idyi));
    
elseif idxi/ceil(idxi)~=1&&idyi/ceil(idyi)==1
    Z1=Z(ceil(idxi)-1,idyi);
    Z2=Z(ceil(idxi),idyi);
    
    Zi=Z1*(ceil(idxi)-idxi)+Z2*(1-(ceil(idxi)-idxi));
    
elseif idxi/ceil(idxi)==1&&idyi/ceil(idyi)~=1    
    Z1=Z(idxi,ceil(idyi)-1);
    Z2=Z(idxi,ceil(idyi));
    
    Zi=Z1*(ceil(idyi)-idyi)+Z2*(1-(ceil(idyi)-idyi));
else
    Zi=Z(idxi,idyi);    
end
    
end