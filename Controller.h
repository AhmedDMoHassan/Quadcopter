/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  9 00:41:06 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef Controller_h_
#define Controller_h_
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Kd;                           /* '<S2>/Kd' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  real_T TimeStampA_e;                 /* '<S7>/Derivative' */
  real_T LastUAtTimeA_c;               /* '<S7>/Derivative' */
  real_T TimeStampB_d;                 /* '<S7>/Derivative' */
  real_T LastUAtTimeB_o;               /* '<S7>/Derivative' */
  real_T TimeStampA_j;                 /* '<S6>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S6>/Derivative' */
  real_T TimeStampB_f;                 /* '<S6>/Derivative' */
  real_T LastUAtTimeB_i;               /* '<S6>/Derivative' */
  real_T TimeStampA_p;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeA_a;               /* '<S5>/Derivative' */
  real_T TimeStampB_c;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeB_n;               /* '<S5>/Derivative' */
  real_T TimeStampA_n;                 /* '<S8>/Derivative' */
  real_T LastUAtTimeA_k;               /* '<S8>/Derivative' */
  real_T TimeStampB_k;                 /* '<S8>/Derivative' */
  real_T LastUAtTimeB_l;               /* '<S8>/Derivative' */
  real_T TimeStampA_k;                 /* '<S2>/Derivative' */
  real_T LastUAtTimeA_o;               /* '<S2>/Derivative' */
  real_T TimeStampB_n;                 /* '<S2>/Derivative' */
  real_T LastUAtTimeB_h;               /* '<S2>/Derivative' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Y;                            /* '<Root>/Y' */
  real_T phi;                          /* '<Root>/phi' */
  real_T Y_ref;                        /* '<Root>/y_ref' */
  real_T X_m;                          /* '<Root>/X' */
  real_T theta;                        /* '<Root>/theta' */
  real_T X_ref;                        /* '<Root>/x_ref' */
  real_T yaw;                          /* '<Root>/yaw' */
  real_T epsi_ref;                     /* '<Root>/yaw_ref' */
  real_T h;                            /* '<Root>/h' */
  real_T h_ref;                        /* '<Root>/h_ref' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T delta_roll;                   /* '<Root>/delta_roll' */
  real_T delta_pitch;                  /* '<Root>/delta_pitch' */
  real_T delta_yaw;                    /* '<Root>/delta_yaw' */
  real_T delta_alt;                    /* '<Root>/delta_alt' */
  real_T Phi_body_command;             /* '<Root>/Phi_body_command' */
  real_T Theta_body_command;           /* '<Root>/Theta_body_command' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[1];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Controller_initialize(void);
extern void Controller_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Quad_model/Controller')    - opens subsystem Quad_model/Controller
 * hilite_system('Quad_model/Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Quad_model'
 * '<S1>'   : 'Quad_model/Controller'
 * '<S2>'   : 'Quad_model/Controller/Altitude_control'
 * '<S3>'   : 'Quad_model/Controller/Phi_controller'
 * '<S4>'   : 'Quad_model/Controller/Theta&Phi_transformation'
 * '<S5>'   : 'Quad_model/Controller/Theta_controller'
 * '<S6>'   : 'Quad_model/Controller/X_controller'
 * '<S7>'   : 'Quad_model/Controller/Y_controller'
 * '<S8>'   : 'Quad_model/Controller/yaw_controller'
 */
#endif                                 /* Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
