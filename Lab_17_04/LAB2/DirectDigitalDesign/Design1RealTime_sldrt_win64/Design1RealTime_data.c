/*
 * Design1RealTime_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Design1RealTime".
 *
 * Model version              : 1.9
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 15:19:07 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Design1RealTime.h"

/* Block parameters (default storage) */
P_Design1RealTime_T Design1RealTime_P = {
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
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  0.050000000000000044,

  /* Variable: Bo
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.099720556527039025, -884.37081775485979 },

  /* Variable: Co
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.0, 1.0 },

  /* Variable: K
   * Referenced by: '<Root>/Gain3'
   */
  { 6.0003563087799572, -0.011012401793455282 },

  /* Variable: Nr
   * Referenced by: '<Root>/Gain2'
   */
  6.0003563087799572,

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

  /* Expression: 50
   * Referenced by: '<Root>/Constant1'
   */
  50.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: zeros(2)
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space3'
   */
  0.0,

  /* Expression: Do(:, 2)
   * Referenced by: '<Root>/Gain'
   */
  { 1.0, 930.91665026827354 }
};
