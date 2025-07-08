/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller.c
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

#include "Controller.h"
#include <math.h>
#include "rtwtypes.h"
#include "math.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Return rtInf needed by the generated code. */
static real_T rtGetInf(void)
{
  return rtInf;
}

/* Get rtInfF needed by the generated code. */
static real32_T rtGetInfF(void)
{
  return rtInfF;
}

/* Return rtMinusInf needed by the generated code. */
static real_T rtGetMinusInf(void)
{
  return rtMinusInf;
}

/* Return rtMinusInfF needed by the generated code. */
static real32_T rtGetMinusInfF(void)
{
  return rtMinusInfF;
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Model step function */
void Controller_step(void)
{
  {
    real_T rtb_Add;
    real_T rtb_Cos;
    real_T rtb_Derivative;
    real_T rtb_Kd_ph;
    real_T rtb_Sum1_f;
    real_T rtb_Sum1_o;
    real_T tmp;
    real_T *lastU;

    /* Outputs for Atomic SubSystem: '<Root>/Controller' */
    /* Derivative: '<S3>/Derivative' incorporates:
     *  Derivative: '<S2>/Derivative'
     *  Derivative: '<S5>/Derivative'
     *  Derivative: '<S6>/Derivative'
     *  Derivative: '<S7>/Derivative'
     *  Derivative: '<S8>/Derivative'
     *  Inport: '<Root>/phi'
     */
    tmp = rtM->Timing.t[0];
    if ((rtDW.TimeStampA >= tmp) && (rtDW.TimeStampB >= tmp)) {
      rtb_Sum1_f = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA;
      lastU = &rtDW.LastUAtTimeA;
      if (rtDW.TimeStampA < rtDW.TimeStampB) {
        if (rtDW.TimeStampB < tmp) {
          rtb_Derivative = rtDW.TimeStampB;
          lastU = &rtDW.LastUAtTimeB;
        }
      } else if (rtDW.TimeStampA >= tmp) {
        rtb_Derivative = rtDW.TimeStampB;
        lastU = &rtDW.LastUAtTimeB;
      }

      rtb_Sum1_f = (rtU.phi - *lastU) / (tmp - rtb_Derivative);
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* Gain: '<S3>/Kd_ph' */
    rtb_Kd_ph = 15.0 * rtb_Sum1_f;

    /* Derivative: '<S7>/Derivative' incorporates:
     *  Inport: '<Root>/Y'
     */
    if ((rtDW.TimeStampA_e >= tmp) && (rtDW.TimeStampB_d >= tmp)) {
      rtb_Sum1_f = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA_e;
      lastU = &rtDW.LastUAtTimeA_c;
      if (rtDW.TimeStampA_e < rtDW.TimeStampB_d) {
        if (rtDW.TimeStampB_d < tmp) {
          rtb_Derivative = rtDW.TimeStampB_d;
          lastU = &rtDW.LastUAtTimeB_o;
        }
      } else if (rtDW.TimeStampA_e >= tmp) {
        rtb_Derivative = rtDW.TimeStampB_d;
        lastU = &rtDW.LastUAtTimeB_o;
      }

      rtb_Sum1_f = (rtU.Y - *lastU) / (tmp - rtb_Derivative);
    }

    /* Sum: '<S7>/Sum1' incorporates:
     *  Gain: '<S7>/Kd_y'
     *  Gain: '<S7>/Kp_y'
     *  Inport: '<Root>/Y'
     *  Inport: '<Root>/y_ref'
     *  Sum: '<S7>/Sum'
     */
    rtb_Sum1_f = (rtU.Y_ref - rtU.Y) * 0.025 - 0.08 * rtb_Sum1_f;

    /* Trigonometry: '<S4>/Cos' incorporates:
     *  Inport: '<Root>/yaw'
     */
    rtb_Cos = cos(rtU.yaw);

    /* Derivative: '<S6>/Derivative' incorporates:
     *  Inport: '<Root>/X'
     */
    if ((rtDW.TimeStampA_j >= tmp) && (rtDW.TimeStampB_f >= tmp)) {
      rtb_Sum1_o = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA_j;
      lastU = &rtDW.LastUAtTimeA_e;
      if (rtDW.TimeStampA_j < rtDW.TimeStampB_f) {
        if (rtDW.TimeStampB_f < tmp) {
          rtb_Derivative = rtDW.TimeStampB_f;
          lastU = &rtDW.LastUAtTimeB_i;
        }
      } else if (rtDW.TimeStampA_j >= tmp) {
        rtb_Derivative = rtDW.TimeStampB_f;
        lastU = &rtDW.LastUAtTimeB_i;
      }

      rtb_Sum1_o = (rtU.X_m - *lastU) / (tmp - rtb_Derivative);
    }

    /* Sum: '<S6>/Sum1' incorporates:
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Kp_X'
     *  Inport: '<Root>/X'
     *  Inport: '<Root>/x_ref'
     *  Sum: '<S6>/Sum'
     */
    rtb_Sum1_o = (rtU.X_m - rtU.X_ref) * 0.025 + 0.08 * rtb_Sum1_o;

    /* Trigonometry: '<S4>/Cos1' incorporates:
     *  Inport: '<Root>/yaw'
     */
    rtb_Derivative = sin(rtU.yaw);

    /* Sum: '<S4>/Add' incorporates:
     *  Product: '<S4>/Product'
     *  Product: '<S4>/Product1'
     */
    rtb_Add = rtb_Sum1_f * rtb_Cos + rtb_Sum1_o * rtb_Derivative;

    /* Sum: '<S4>/Add1' incorporates:
     *  Product: '<S4>/Product2'
     *  Product: '<S4>/Product3'
     */
    rtb_Sum1_f = rtb_Cos * rtb_Sum1_o - rtb_Sum1_f * rtb_Derivative;

    /* Derivative: '<S5>/Derivative' incorporates:
     *  Inport: '<Root>/theta'
     */
    if ((rtDW.TimeStampA_p >= tmp) && (rtDW.TimeStampB_c >= tmp)) {
      rtb_Derivative = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA_p;
      lastU = &rtDW.LastUAtTimeA_a;
      if (rtDW.TimeStampA_p < rtDW.TimeStampB_c) {
        if (rtDW.TimeStampB_c < tmp) {
          rtb_Derivative = rtDW.TimeStampB_c;
          lastU = &rtDW.LastUAtTimeB_n;
        }
      } else if (rtDW.TimeStampA_p >= tmp) {
        rtb_Derivative = rtDW.TimeStampB_c;
        lastU = &rtDW.LastUAtTimeB_n;
      }

      rtb_Derivative = (rtU.theta - *lastU) / (tmp - rtb_Derivative);
    }

    /* Gain: '<S5>/Kd_theta' */
    rtb_Cos = 15.0 * rtb_Derivative;

    /* Derivative: '<S8>/Derivative' incorporates:
     *  Inport: '<Root>/yaw'
     */
    if ((rtDW.TimeStampA_n >= tmp) && (rtDW.TimeStampB_k >= tmp)) {
      rtb_Derivative = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA_n;
      lastU = &rtDW.LastUAtTimeA_k;
      if (rtDW.TimeStampA_n < rtDW.TimeStampB_k) {
        if (rtDW.TimeStampB_k < tmp) {
          rtb_Derivative = rtDW.TimeStampB_k;
          lastU = &rtDW.LastUAtTimeB_l;
        }
      } else if (rtDW.TimeStampA_n >= tmp) {
        rtb_Derivative = rtDW.TimeStampB_k;
        lastU = &rtDW.LastUAtTimeB_l;
      }

      rtb_Derivative = (rtU.yaw - *lastU) / (tmp - rtb_Derivative);
    }

    /* Gain: '<S8>/Gain1' */
    rtb_Sum1_o = 322.8 * rtb_Derivative;

    /* Gain: '<S2>/Kd' incorporates:
     *  Inport: '<Root>/h'
     */
    rtDW.Kd = 89.0 * rtU.h;

    /* Derivative: '<S2>/Derivative' */
    if ((rtDW.TimeStampA_k >= tmp) && (rtDW.TimeStampB_n >= tmp)) {
      rtb_Derivative = 0.0;
    } else {
      rtb_Derivative = rtDW.TimeStampA_k;
      lastU = &rtDW.LastUAtTimeA_o;
      if (rtDW.TimeStampA_k < rtDW.TimeStampB_n) {
        if (rtDW.TimeStampB_n < tmp) {
          rtb_Derivative = rtDW.TimeStampB_n;
          lastU = &rtDW.LastUAtTimeB_h;
        }
      } else if (rtDW.TimeStampA_k >= tmp) {
        rtb_Derivative = rtDW.TimeStampB_n;
        lastU = &rtDW.LastUAtTimeB_h;
      }

      rtb_Derivative = (rtDW.Kd - *lastU) / (tmp - rtb_Derivative);
    }

    /* Outport: '<Root>/delta_roll' incorporates:
     *  Gain: '<S3>/Kp_phi'
     *  Inport: '<Root>/phi'
     *  Sum: '<S3>/Sum'
     *  Sum: '<S3>/Sum1'
     */
    rtY.delta_roll = (rtb_Add - rtU.phi) * 25.0 - rtb_Kd_ph;

    /* Outport: '<Root>/delta_pitch' incorporates:
     *  Gain: '<S5>/Kp_theta'
     *  Inport: '<Root>/theta'
     *  Sum: '<S5>/Sum'
     *  Sum: '<S5>/Sum1'
     */
    rtY.delta_pitch = (rtb_Sum1_f - rtU.theta) * 25.0 - rtb_Cos;

    /* Saturate: '<S1>/Saturation' incorporates:
     *  Inport: '<Root>/yaw_ref'
     */
    if (rtU.epsi_ref > 3.0) {
      tmp = 3.0;
    } else if (rtU.epsi_ref < -3.0) {
      tmp = -3.0;
    } else {
      tmp = rtU.epsi_ref;
    }

    /* Outport: '<Root>/delta_yaw' incorporates:
     *  Gain: '<S8>/Gain'
     *  Inport: '<Root>/yaw'
     *  Saturate: '<S1>/Saturation'
     *  Sum: '<S8>/Sum'
     *  Sum: '<S8>/Sum1'
     */
    rtY.delta_yaw = (tmp - rtU.yaw) * 304.0 - rtb_Sum1_o;

    /* Outport: '<Root>/delta_alt' incorporates:
     *  Gain: '<S2>/Kp'
     *  Inport: '<Root>/h'
     *  Inport: '<Root>/h_ref'
     *  Sum: '<S2>/Sum'
     *  Sum: '<S2>/Sum1'
     */
    rtY.delta_alt = (rtU.h_ref - rtU.h) * 30.0 - rtb_Derivative;

    /* End of Outputs for SubSystem: '<Root>/Controller' */

    /* Outport: '<Root>/Phi_body_command' */
    rtY.Phi_body_command = rtb_Add;

    /* Outport: '<Root>/Theta_body_command' */
    rtY.Theta_body_command = rtb_Sum1_f;
  }

  {
    real_T *lastU;

    /* Update for Atomic SubSystem: '<Root>/Controller' */
    /* Update for Derivative: '<S3>/Derivative' incorporates:
     *  Inport: '<Root>/phi'
     */
    if (rtDW.TimeStampA == (rtInf)) {
      rtDW.TimeStampA = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA;
    } else if (rtDW.TimeStampB == (rtInf)) {
      rtDW.TimeStampB = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB;
    } else if (rtDW.TimeStampA < rtDW.TimeStampB) {
      rtDW.TimeStampA = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA;
    } else {
      rtDW.TimeStampB = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB;
    }

    *lastU = rtU.phi;

    /* End of Update for Derivative: '<S3>/Derivative' */

    /* Update for Derivative: '<S7>/Derivative' incorporates:
     *  Inport: '<Root>/Y'
     */
    if (rtDW.TimeStampA_e == (rtInf)) {
      rtDW.TimeStampA_e = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_c;
    } else if (rtDW.TimeStampB_d == (rtInf)) {
      rtDW.TimeStampB_d = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_o;
    } else if (rtDW.TimeStampA_e < rtDW.TimeStampB_d) {
      rtDW.TimeStampA_e = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_c;
    } else {
      rtDW.TimeStampB_d = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_o;
    }

    *lastU = rtU.Y;

    /* End of Update for Derivative: '<S7>/Derivative' */

    /* Update for Derivative: '<S6>/Derivative' incorporates:
     *  Inport: '<Root>/X'
     */
    if (rtDW.TimeStampA_j == (rtInf)) {
      rtDW.TimeStampA_j = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_e;
    } else if (rtDW.TimeStampB_f == (rtInf)) {
      rtDW.TimeStampB_f = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_i;
    } else if (rtDW.TimeStampA_j < rtDW.TimeStampB_f) {
      rtDW.TimeStampA_j = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_e;
    } else {
      rtDW.TimeStampB_f = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_i;
    }

    *lastU = rtU.X_m;

    /* End of Update for Derivative: '<S6>/Derivative' */

    /* Update for Derivative: '<S5>/Derivative' incorporates:
     *  Inport: '<Root>/theta'
     */
    if (rtDW.TimeStampA_p == (rtInf)) {
      rtDW.TimeStampA_p = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_a;
    } else if (rtDW.TimeStampB_c == (rtInf)) {
      rtDW.TimeStampB_c = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_n;
    } else if (rtDW.TimeStampA_p < rtDW.TimeStampB_c) {
      rtDW.TimeStampA_p = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_a;
    } else {
      rtDW.TimeStampB_c = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_n;
    }

    *lastU = rtU.theta;

    /* End of Update for Derivative: '<S5>/Derivative' */

    /* Update for Derivative: '<S8>/Derivative' incorporates:
     *  Inport: '<Root>/yaw'
     */
    if (rtDW.TimeStampA_n == (rtInf)) {
      rtDW.TimeStampA_n = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_k;
    } else if (rtDW.TimeStampB_k == (rtInf)) {
      rtDW.TimeStampB_k = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_l;
    } else if (rtDW.TimeStampA_n < rtDW.TimeStampB_k) {
      rtDW.TimeStampA_n = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_k;
    } else {
      rtDW.TimeStampB_k = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_l;
    }

    *lastU = rtU.yaw;

    /* End of Update for Derivative: '<S8>/Derivative' */

    /* Update for Derivative: '<S2>/Derivative' */
    if (rtDW.TimeStampA_k == (rtInf)) {
      rtDW.TimeStampA_k = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_o;
    } else if (rtDW.TimeStampB_n == (rtInf)) {
      rtDW.TimeStampB_n = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_h;
    } else if (rtDW.TimeStampA_k < rtDW.TimeStampB_n) {
      rtDW.TimeStampA_k = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeA_o;
    } else {
      rtDW.TimeStampB_n = rtM->Timing.t[0];
      lastU = &rtDW.LastUAtTimeB_h;
    }

    *lastU = rtDW.Kd;

    /* End of Update for Derivative: '<S2>/Derivative' */
    /* End of Update for SubSystem: '<Root>/Controller' */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&rtM->solverInfo, false);
  rtsiSetIsContModeFrozen(&rtM->solverInfo, false);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 1.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Controller' */
  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  rtDW.TimeStampA = (rtInf);
  rtDW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S7>/Derivative' */
  rtDW.TimeStampA_e = (rtInf);
  rtDW.TimeStampB_d = (rtInf);

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  rtDW.TimeStampA_j = (rtInf);
  rtDW.TimeStampB_f = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  rtDW.TimeStampA_p = (rtInf);
  rtDW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Derivative: '<S8>/Derivative' */
  rtDW.TimeStampA_n = (rtInf);
  rtDW.TimeStampB_k = (rtInf);

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  rtDW.TimeStampA_k = (rtInf);
  rtDW.TimeStampB_n = (rtInf);

  /* End of SystemInitialize for SubSystem: '<Root>/Controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
