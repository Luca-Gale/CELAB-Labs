/*
 * Discrete_PID_realtime_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Discrete_PID_realtime".
 *
 * Model version              : 1.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 16:22:08 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Discrete_PID_realtime.h"

/* Block parameters (default storage) */
P_Discrete_PID_realtime_T Discrete_PID_realtime_P = {
  /* Variable: sens
   * Referenced by: '<Root>/pulse2deg1'
   */
  {
    {
      0.5
    },

    {
      2000.0,
      0.18,
      0.0031415926535897933,
      5.5555555555555554,
      318.3098861837907
    },

    {
      {
        10000.0,
        5.0,
        345.0,
        6.0213859193804371
      },
      0.014492753623188406,
      0.83037361613162786,
      69.0,
      1.2042771838760873
    }
  },

  /* Variable: B_C
   * Referenced by: '<Root>/BEMF compensator'
   */
  0.17980342454697359,

  /* Variable: Beq
   * Referenced by: '<Root>/Gain2'
   */
  9.6790003551247452E-7,

  /* Variable: F_C
   * Referenced by: '<Root>/Friction compensator'
   */
  48.221704164501993,

  /* Variable: I_C
   * Referenced by: '<Root>/Inertia compensator'
   */
  0.0059312711874102463,

  /* Variable: Kd
   * Referenced by: '<S1>/Kd'
   */
  0.063675520404104458,

  /* Variable: Ki
   * Referenced by: '<S1>/Ki'
   */
  13.984745242771309,

  /* Variable: Kp
   * Referenced by: '<S1>/Kp'
   */
  8.6487466264420139,

  /* Variable: Kw
   * Referenced by: '<S1>/Kw'
   */
  1.666666666666667,

  /* Variable: deg2rad
   * Referenced by: '<S1>/deg2rad'
   */
  0.017453292519943295,

  /* Variable: den
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 0.051477887584497249, -0.001477887584497244 },

  /* Variable: den_EX
   * Referenced by: '<Root>/Exact method PID'
   */
  { 1.0, -1.000000000000002, 2.0272979169850774E-15 },

  /* Variable: den_FE
   * Referenced by: '<Root>/Forward Euler PID'
   */
  { 1.0, 31.83207256390159, -32.83207256390159 },

  /* Variable: den_T
   * Referenced by: '<Root>/Tustin PID'
   */
  { 1.0, -0.11163183466059812, -0.88836816533940233 },

  /* Variable: num
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },

  /* Variable: num_EX
   * Referenced by: '<Root>/Exact method PID'
   */
  { 51.734243163559178, -94.120502438537784, 43.085496537117166 },

  /* Variable: num_FE
   * Referenced by: '<Root>/Forward Euler PID'
   */
  { 51.734243163559178, 189.83577438760551, -217.91337175910886 },

  /* Variable: num_T
   * Referenced by: '<Root>/Tustin PID'
   */
  { 11.403221770361903, -5.1149797862048247, -4.9678245983155405 },

  /* Variable: rad2deg
   * Referenced by: '<Root>/Gain3'
   */
  57.295779513082323,

  /* Variable: rpm2rads
   * Referenced by: '<Root>/Gain8'
   */
  0.10471975511965977,

  /* Variable: tau_sf
   * Referenced by: '<Root>/Gain6'
   */
  0.0045408438233654862,

  /* Mask Parameter: AnalogOutput2_FinalValue
   * Referenced by: '<Root>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_InitialValue
   * Referenced by: '<Root>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_InputFilter
   * Referenced by: '<Root>/Encoder Input1'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput2_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output2'
   */
  10.0,

  /* Mask Parameter: a_l_refrpms_OutValues
   * Referenced by: '<S2>/Vector'
   */
  { 900.0, 0.0, -900.0, -900.0, 0.0, 900.0 },

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<Root>/Encoder Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_Channels
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogOutput2_RangeMode
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogOutput2_VoltRange
   * Referenced by: '<Root>/Analog Output2'
   */
  0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S5>/FixPt Switch'
   */
  5U,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/th_l_ref [deg]1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/th_l_ref [deg]1'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/th_l_ref [deg]1'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval_g
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0025000000000000005,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Tustin PID'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/+-10'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/+-10'
   */
  -10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Forward Euler PID'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Exact method PID'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/Gain7'
   */
  0.05,

  /* Expression: 0.95
   * Referenced by: '<Root>/Gain9'
   */
  0.95,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S5>/Constant'
   */
  0U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S3>/Output'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S4>/FixPt Constant'
   */
  1U
};
