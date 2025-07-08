clc
m = 1.1;            % Mass [kg]
ixx = 8.95e-03;     % Moment of inertia (x-axis) [kg.m^2]
iyy = 8.95e-03;     % Moment of inertia (y-axis) [kg.m^2]
izz = 0.0165;       % Moment of inertia (z-axis) [kg.m^2]
g = 9.81;           % Gravitational acceleration [m/s^2]
b = 9.60e-06;       % Thrust coefficient [Ns^2/rad^2]
d = 1.24e-07;       % Drag coefficient [Ns^2/rad^2]
L = 0.25;           % Arm length [m] (converted from 2.50E-01)
I = [ixx, 0, 0;
    0, iyy, 0;
    0, 0, izz];       % the stifness matrix
% Build B matrix
B = [0, -b*L, 0, b*L;
     b*L, 0, -b*L, 0;
     d, -d, d, -d;
     b, b, b, b];
% Compute pseudo-inverse
A0 = pinv(B);

% Scale columns by max absolute value
A_scaled = zeros(size(A0));
for j = 1:size(A0, 2)
    col = A0(:, j);
    max_abs = max(abs(col));
    A_scaled(:, j) = col / max_abs;
end

% Display results
disp('B Matrix:'); disp(B);
disp('Pseudo-Inverse (A0):'); disp(A0);
disp('Scaled Allocation Matrix:'); disp(A_scaled);
disp('B * A0 (should be identity):'); disp(round(B * A0, 10));