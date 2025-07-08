%% Lineraization data extraction from model linearlizer
clc
load linear_sys 
% linearized system:
Linsys_tr = minreal(tf(linsys1))

% transfer function for Z
z_per_delta = Linsys_tr(3,4);
h_per_delta = -z_per_delta;

% transfer function for roll
phi_per_delta_roll = Linsys_tr(4,1);

% transfer function for pitch
theta_per_delta_pitch = Linsys_tr(5,2);

% transfer function for yaw
exi_per_delta_yaw = Linsys_tr(6,3);