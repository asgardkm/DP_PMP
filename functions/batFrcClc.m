function [ batFrc ...   Skalar - Batteriekraft (E')
    ] = batFrcClc(...
    batEngAct,...       Skalar - Batterieenergie
    batPwr,...          Skalar - Batterieklemmleistung
    vel,...             Skalar - Geschwindigkeit im Intervall
    batRstDch,...       Skalar - Entladewiderstand
    batRstChr,...       Skalar - Ladewiderstand
    batOcvCof_batEng... Vektor - Koeffizienten für Ruhespannung der Battery
                    ...             %Coefficients for bat. open-circuit voltage
    )%#codegen
%BATFRCCLC Calculating losses in battery
%   Batteriekraft (E') aus Verlusten in der Batterie berechnen
%       Calucluate battery power losses (E')

% Version vom 25.05.2016: Zero-Order-Hold (keine mittlere Geschwindigkeit)
%                           Zero-Order-Hold (average velocity is NOT used)

%% Initialisieren der Ausgabe der Funktion
%   initializing the function output
batFrc = inf;

%% Initialisieren der allgemein benötigten Kenngrößen
%   initializing the commonly required parameters

% Batteriespannung aus Kennkurve berechnen
%   calculating battery voltage of characteristic curve - eq?--------------
%       if batOcvCof_batEng(1,1) is zero, then batOcv is just the 2nd val
batOcv = batEngAct*batOcvCof_batEng(1,1) + batOcvCof_batEng(1,2);

%% Berechnung der Verluste in der Batterie
%   calculating battery losses

% Berechnung der Batterieenergienderung im Wegschritt in externer Funktion
% Fallunterscheidung, ob Batterie geladen oder entladen wird
%   
%   calculate the change in battery energy along path_idx in exterior func,  
%   distinguished whether battery is charging or discharging.
%   Assining battery resistance value
if batPwr > 0
    batRst = batRstDch;
else
    batRst = batRstChr;
end

% Batterieenergieänderung über dem Weg berechnen. Herleitung der Formel
% kann zum Beispiel dem Paper mit Chalmers entnommen werden
%   calculate battery power charge for path_idx. Formula derivation can be 
%   found from other papers (for example, Chalmers paper)
batFrcCpl = batOcv^2 * ...
    ( sqrt( complex (1 - 4*batRst/batOcv^2*batPwr) ) - 1) / ...
    ( 2*batRst*vel );

% Sollte die physikalisch mögliche Batterieleistung überschritten werden,
% wird der Term unter der Wurzel negativ. In diesem Fall wird die Ausgabe
% ungültig geschrieben.
%   check to make sure that the battery capacity is not exceeded (when the
%   root becomes negative, the output is no longer valid) (Quadrants 3, 4)
if imag(batFrcCpl) ~= 0
    return;
end

batFrc = real(batFrcCpl);

end