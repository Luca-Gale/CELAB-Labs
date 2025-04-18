/*
 * PID_real_time_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_real_time".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 13:30:04 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_real_time.h"

/* Block parameters (default storage) */
P_PID_real_time_T PID_real_time_P = {
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

  /* Variable: Kd
   * Referenced by: '<S1>/Kd'
   */
  0.070678415167156325,

  /* Variable: Ki
   * Referenced by: '<S1>/Ki'
   */
  11.811893312108744,

  /* Variable: Kp
   * Referenced by: '<S1>/Kp'
   */
  8.374189844490262,

  /* Variable: deg2rad
   * Referenced by: '<S1>/deg2rad'
   */
  0.017453292519943295,

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

  /* Expression: 1
   * Referenced by: '<Root>/degree-input step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/degree-input step'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/degree-input step'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Computed Parameter: derivative_A
   * Referenced by: '<S1>/derivative'
   */
  -101.49621769170476,

  /* Computed Parameter: derivative_C
   * Referenced by: '<S1>/derivative'
   */
  -10301.482205721923,

  /* Computed Parameter: derivative_D
   * Referenced by: '<S1>/derivative'
   */
  101.49621769170476,

  /* Expression: 10
   * Referenced by: '<S1>/+-10'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/+-10'
   */
  -10.0,

  /* Expression: 105
   * Referenced by: '<Root>/Constant1'
   */
  105.0,

  /* Expression: 95
   * Referenced by: '<Root>/Constant2'
   */
  95.0
};
