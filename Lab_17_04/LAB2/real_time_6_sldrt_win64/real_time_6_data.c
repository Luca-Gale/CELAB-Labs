/*
 * real_time_6_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "real_time_6".
 *
 * Model version              : 1.24
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 17 14:16:42 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_time_6.h"

/* Block parameters (default storage) */
P_real_time_6_T real_time_6_P = {
  /* Variable: AF
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  0.36787944117144233,

  /* Variable: BF
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.64941186106450732, -27.529958078527962 },

  /* Variable: CF
   * Referenced by: '<Root>/Discrete State-Space2'
   */
  { 0.0, 1.0 },

  /* Variable: K2
   * Referenced by: '<S1>/Gain'
   */
  { 7.3834758774885554, 0.17780553043566708 },

  /* Variable: KI
   * Referenced by: '<S1>/Gain3'
   */
  49.223172516590367,

  /* Variable: Nu
   * Referenced by: '<S1>/Gain2'
   */
  0.0,

  /* Variable: Nx
   * Referenced by: '<S1>/Gain1'
   */
  { 1.0, 0.0 },

  /* Variable: deg2rad
   * Referenced by:
   *   '<Root>/Gain1'
   *   '<S1>/deg2rad2'
   */
  0.017453292519943295,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  INFINITY,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 0
   * Referenced by: '<Root>/Step3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step3'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Step3'
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
   * Referenced by: '<Root>/pulse2deg3'
   */
  0.18,

  /* Expression: [DF(3);DF(4)]
   * Referenced by: '<Root>/Gain'
   */
  { 1.0, 43.551752421320273 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S1>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<S1>/Saturation'
   */
  -12.0
};
