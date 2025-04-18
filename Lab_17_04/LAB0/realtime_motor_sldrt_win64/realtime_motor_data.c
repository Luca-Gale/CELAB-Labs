/*
 * realtime_motor_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime_motor".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 12:55:15 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtime_motor.h"

/* Block parameters (default storage) */
P_realtime_motor_T realtime_motor_P = {
  /* Variable: sens
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain1'
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

  /* Variable: mot
   * Referenced by: '<S3>/Torque const'
   */
  {
    2.6,
    0.00018,
    0.0076812800000000013,
    0.0076776344547530321,
    3.899238e-7,
    0.0,
    0.69,
    4.6811594202898554,
    6.0,
    0.78019323671497587,
    0.0059928827053140109,
    0.017085200000000002,
    753.98223686155029,
    3.1
  },

  /* Variable: gbox
   * Referenced by:
   *   '<S4>/N1'
   *   '<S5>/Gain6'
   */
  {
    14.0,
    0.8,
    1.0,
    1.4e-6,
    1.0,
    14.0,
    0.8,
    4.2e-6
  },

  /* Variable: Beq
   * Referenced by: '<S5>/Gain5'
   */
  9.6790003551247452E-7,

  /* Variable: Kd
   * Referenced by: '<S2>/Kd'
   */
  0.070678415167156325,

  /* Variable: Ki
   * Referenced by: '<S2>/Ki'
   */
  11.811893312108744,

  /* Variable: Kp
   * Referenced by: '<S2>/Kp'
   */
  8.374189844490262,

  /* Variable: deg2rad
   * Referenced by: '<S2>/deg2rad'
   */
  0.017453292519943295,

  /* Variable: degs2rpm
   * Referenced by: '<S4>/ '
   */
  0.16666666666666666,

  /* Variable: rpm2degs
   * Referenced by:
   *   '<Root>/Gain4'
   *   '<Root>/Gain5'
   */
  6.0,

  /* Variable: rpm2rads
   * Referenced by:
   *   '<S4>/Gain1'
   *   '<S4>/Gain8'
   */
  0.10471975511965977,

  /* Variable: tau_sf
   * Referenced by: '<S5>/Gain6'
   */
  0.0045408438233654862,

  /* Mask Parameter: AnalogOutput1_FinalValue
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_InitialValue
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput2_InputFilter
   * Referenced by: '<Root>/Encoder Input2'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput2_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input2'
   */
  10.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: RepeatingSequenceStair_OutValues
   * Referenced by: '<S7>/Vector'
   */
  { 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 450.0 },

  /* Mask Parameter: RepeatingSequenceStair1_OutValues
   * Referenced by: '<S8>/Vector'
   */
  { 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 450.0 },

  /* Mask Parameter: EncoderInput2_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input2'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput2_Channels
   * Referenced by: '<Root>/Encoder Input2'
   */
  0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<Root>/Analog Input1'
   */
  { 0, 1 },

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S11>/FixPt Switch'
   */
  9U,

  /* Mask Parameter: WrapToZero_Threshold_e
   * Referenced by: '<S14>/FixPt Switch'
   */
  9U,

  /* Expression: -1
   * Referenced by: '<S6>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Computed Parameter: derivative_A
   * Referenced by: '<S2>/derivative'
   */
  -101.49621769170476,

  /* Computed Parameter: derivative_C
   * Referenced by: '<S2>/derivative'
   */
  101.49621769170476,

  /* Expression: 10
   * Referenced by: '<S2>/+-10'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2>/+-10'
   */
  -10.0,

  /* Computed Parameter: Filteringderivative_A
   * Referenced by: '<S4>/Filtering derivative'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: Filteringderivative_C
   * Referenced by: '<S4>/Filtering derivative'
   */
  { 15791.367041742973, 0.0 },

  /* Computed Parameter: Currentfilter_A
   * Referenced by: '<S3>/ Current filter'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: Currentfilter_C
   * Referenced by: '<S3>/ Current filter'
   */
  { 0.0, 15791.367041742973 },

  /* Computed Parameter: Filteringderivative2_A
   * Referenced by: '<S4>/Filtering derivative 2'
   */
  { -177.71531752633462, -15791.367041742973 },

  /* Computed Parameter: Filteringderivative2_C
   * Referenced by: '<S4>/Filtering derivative 2'
   */
  { 15791.367041742973, 0.0 },

  /* Expression: 1/1000
   * Referenced by: '<S4>/1//k1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 450
   * Referenced by: '<S1>/Pulse Generator3'
   */
  450.0,

  /* Computed Parameter: PulseGenerator3_Period
   * Referenced by: '<S1>/Pulse Generator3'
   */
  2000.0,

  /* Computed Parameter: PulseGenerator3_Duty
   * Referenced by: '<S1>/Pulse Generator3'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain5'
   */
  -1.0,

  /* Expression: 450
   * Referenced by: '<S1>/Pulse Generator2'
   */
  450.0,

  /* Computed Parameter: PulseGenerator2_Period
   * Referenced by: '<S1>/Pulse Generator2'
   */
  2000.0,

  /* Computed Parameter: PulseGenerator2_Duty
   * Referenced by: '<S1>/Pulse Generator2'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator2'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S4>/1//k2'
   */
  1000.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S11>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_d
   * Referenced by: '<S12>/Output'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S10>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_m
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U
};
