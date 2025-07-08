# Quadcopter Modeling, Control, and Simulation
**Aerospace Engineering Senior Capstone Project**  
🚁 Complete Simulink-based quadcopter model with PD control, 3D visualization, and auto-generated C code

## Project Overview
This repository contains a comprehensive Model-Based Design (MBD) implementation of a quadcopter system developed in Simulink. Key features include:
- Pure Simulink implementation (no MATLAB functions)
- Moore-Penrose Pseudo Inverse allocation for optimal thrust distribution
- Custom PD controller tuned via MATLAB SISOTOOL
- UAV Toolbox 3D visualization and Aerospace Toolbox trajectory
- MIL/SIL tested C code generation
- images and video in the screenshots folder

## Technical Implementation
### 🧱 Model Architecture
```mermaid
graph LR
A[6DOF EOM] --> B[Moore-Penrose Allocation]
C[PD Controller] --> D[Motor Mixing]
D --> A
E[Trajectory Input] --> C
