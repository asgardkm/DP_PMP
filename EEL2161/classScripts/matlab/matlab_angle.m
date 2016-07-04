clc; clear all; close all

% make script that displays sine angles as rational nums
format rat;
sin(pi/2)
sin(pi/3)
sin(pi/4)

% define vectors
A = [1 2 3];
B = [4; 5; 6];

% determinant command
C = [1 2 3 4; 0 2 1 3; 0 0 3 2; 0 0 0 4];
det(C)
inv(C)

% concactenate
D  = [A B'];
D2 = [A; B'];

%%
clc; clear all; close all
% w/ complex nums
a = [j, 1+2j, 4];
fprintf('a:\n')
disp(a);
fprintf('a_nought:\n');
disp(a');

% dot and cross product
A = [1 4 7]
B = [2 -1 5];

dot(A,B)
cross(A,B)
A.*B

%%
clc; clear all; close all;

% indexing - vectors
A = [12, 17, -2, 0 , 4, 4, 11, 19, 27];
A(2)
A(8)
A(:)
A(1,4:6)

% indexing - matrices
A = [-1 6; 7 11];
B = [2 0 1; -1 7 4; 3 0 1];

A(2, 1)
B(:, 2)
B(3,:)
B(1:2, 1:2)

%%
clc; clear all; close all
format short
% find sol of simultaneous linear eq
A = [5 2 -9; -9 -2 2; 6 7 3];
B = [44; 11; 44];
X = A \ B;
X

%%
x=0:.1:10
y = sin(x)
plot(x,y)
xlabel('x-Degrees')
ylabel('Cosine of x')
title('Value of Cosine function from 0 to 360')
grid on

hold on
yy = cos(x)
plot(x, yy)

%%
A = (3+j*4) / (4+3*j);
abs_A = abs(A)
re_A  = real(A)
im_A  = imag(A)
conj_A= conj(A)

%%
syms x
int(-2*x / (1+x^2)^2)

syms z
int(x/(1+z^2), x)
% int(x/()


%%
clc; clear all; close all
i0 = 0;

for i = 1:2:101
    i0 = i0+ i;
end
i0