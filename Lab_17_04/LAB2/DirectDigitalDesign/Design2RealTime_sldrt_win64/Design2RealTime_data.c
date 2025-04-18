/*
 * Design2RealTime_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Design2RealTime".
 *
 * Model version              : 1.10
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 15:10:38 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Design2RealTime.h"

/* Block parameters (default storage) */
P_Design2RealTime_T Design2RealTime_P = {
  /* Variable: sens
   * Referenced by: '<S2>/pulse2deg'
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

  /* Variable: Ao
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  0.05,

  /* Variable: Bo
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 3.7032582005400094, -4.5849642728488584 },

  /* Variable: Co
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.0, 1.0 },

  /* Variable: K
   * Referenced by: '<Root>/Gain4'
   */
  { 8.4999761331454984, 0.12638909746078836 },

  /* Variable: Nr
   * Referenced by: '<Root>/Gain1'
   */
  8.4999761331454984,

  /* Mask Parameter: AnalogOutput2_FinalValue
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_InitialValue
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_InputFilter
   * Referenced by: '<S2>/Encoder Input1'
   */
  INFINITY,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<S2>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput2_MaxMissedTicks
   * Referenced by: '<S2>/Analog Output2'
   */
  10.0,

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<S2>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput2_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Output2'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<S2>/Encoder Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput2_Channels
   * Referenced by: '<S2>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogOutput2_RangeMode
   * Referenced by: '<S2>/Analog Output2'
   */
  0,

  /* Mask Parameter: AnalogOutput2_VoltRange
   * Referenced by: '<S2>/Analog Output2'
   */
  0,

  /* Expression: pi/180
   * Referenced by: '<S4>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.16186846506171354,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: zeros(2)
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space1'
   */
  0.0,

  /* Expression: Do(:, 2)
   * Referenced by: '<Root>/Gain5'
   */
  { 1.0, 4.8262781819461669 }
};
