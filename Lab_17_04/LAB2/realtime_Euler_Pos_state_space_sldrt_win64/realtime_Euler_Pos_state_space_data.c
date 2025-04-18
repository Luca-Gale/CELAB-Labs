/*
 * realtime_Euler_Pos_state_space_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "realtime_Euler_Pos_state_space".
 *
 * Model version              : 1.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 15:52:44 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "realtime_Euler_Pos_state_space.h"

/* Block parameters (default storage) */
P_realtime_Euler_Pos_state_space_T realtime_Euler_Pos_state_space_P = {
  /* Variable: Gamma_o
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 9.3728984532925246, -320.63246996055625 },

  /* Variable: Ho
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.0, 1.0 },

  /* Variable: K
   * Referenced by: '<S1>/Gain'
   */
  { 6.1059507881845381, 0.022012902479817738 },

  /* Variable: Nu
   * Referenced by: '<S1>/Gain2'
   */
  0.0,

  /* Variable: Nx
   * Referenced by: '<S1>/Gain1'
   */
  { 1.0, -0.0 },

  /* Variable: Phi_o
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  -4.0,

  /* Variable: deg2rad
   * Referenced by:
   *   '<Root>/Gain2'
   *   '<S1>/deg2rad2'
   */
  0.017453292519943295,

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

  /* Mask Parameter: AnalogOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output1'
   */
  10.0,

  /* Mask Parameter: EncoderInput2_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input2'
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

  /* Mask Parameter: AnalogOutput1_Channels
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_RangeMode
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Mask Parameter: AnalogOutput1_VoltRange
   * Referenced by: '<Root>/Analog Output1'
   */
  0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Step'
   */
  50.0,

  /* Expression: [0,0;0,0]
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  0.0,

  /* Expression: 0.18
   * Referenced by: '<Root>/Gain'
   */
  0.18,

  /* Expression: [Jo(1, 2);Jo(2, 2)]
   * Referenced by: '<Root>/Gain1'
   */
  { 1.0, 64.12649399211125 },

  /* Expression: 12
   * Referenced by: '<S1>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<S1>/Saturation'
   */
  -12.0
};
