/*
 * realtime_motor.c
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
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "realtime_motor_private.h"
#include <string.h>
#include "realtime_motor_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_realtime_motor_T realtime_motor_B;

/* Continuous states */
X_realtime_motor_T realtime_motor_X;

/* Disabled State Vector */
XDis_realtime_motor_T realtime_motor_XDis;

/* Block states (default storage) */
DW_realtime_motor_T realtime_motor_DW;

/* Real-time model */
static RT_MODEL_realtime_motor_T realtime_motor_M_;
RT_MODEL_realtime_motor_T *const realtime_motor_M = &realtime_motor_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (realtime_motor_M->Timing.TaskCounters.TID[2])++;
  if ((realtime_motor_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [5.0s, 0.0s] */
    realtime_motor_M->Timing.TaskCounters.TID[2] = 0;
  }

  realtime_motor_M->Timing.sampleHits[2] =
    (realtime_motor_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  realtime_motor_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  realtime_motor_output();
  realtime_motor_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  realtime_motor_output();
  realtime_motor_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  realtime_motor_output();
  realtime_motor_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  realtime_motor_output();
  realtime_motor_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  realtime_motor_output();
  realtime_motor_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void realtime_motor_output(void)
{
  real_T rtb_AnalogInput1[2];
  real_T rtb_deg2rad;
  real_T rtb_u0;
  real_T rtb_w_l_refrpm;
  uint8_T rtb_Output_i;
  uint8_T rtb_Output_k;
  boolean_T tmp;
  boolean_T tmp_0;
  if (rtmIsMajorTimeStep(realtime_motor_M)) {
    /* set solver stop time */
    if (!(realtime_motor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&realtime_motor_M->solverInfo,
                            ((realtime_motor_M->Timing.clockTickH0 + 1) *
        realtime_motor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&realtime_motor_M->solverInfo,
                            ((realtime_motor_M->Timing.clockTick0 + 1) *
        realtime_motor_M->Timing.stepSize0 +
        realtime_motor_M->Timing.clockTickH0 *
        realtime_motor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(realtime_motor_M)) {
    realtime_motor_M->Timing.t[0] = rtsiGetT(&realtime_motor_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator2' */
  rtb_deg2rad = realtime_motor_X.Integrator2_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  if (realtime_motor_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_u0 = realtime_motor_X.Integrator_CSTATE;
  } else {
    rtb_u0 = rtb_deg2rad;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* S-Function (sldrtei): '<Root>/Encoder Input2' */
  /* S-Function Block: <Root>/Encoder Input2 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime_motor_P.EncoderInput2_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &realtime_motor_P.EncoderInput2_Channels, &rtb_deg2rad, &parm);
  }

  /* S-Function (sldrtai): '<Root>/Analog Input1' */
  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) realtime_motor_P.AnalogInput1_RangeMode;
    parm.rangeidx = realtime_motor_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   realtime_motor_P.AnalogInput1_Channels, &rtb_AnalogInput1[0],
                   &parm);
  }

  /* Gain: '<Root>/Gain' */
  realtime_motor_B.th_l_measdeg = realtime_motor_P.sens.enc.pulse2deg *
    rtb_deg2rad;

  /* Gain: '<S2>/deg2rad' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_deg2rad = (rtb_u0 - realtime_motor_B.th_l_measdeg) *
    realtime_motor_P.deg2rad;

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Kp'
   *  Integrator: '<S2>/Integrator'
   *  TransferFcn: '<S2>/derivative'
   */
  rtb_u0 = (realtime_motor_P.Kp * rtb_deg2rad +
            realtime_motor_X.Integrator_CSTATE_n) +
    realtime_motor_P.derivative_C * realtime_motor_X.derivative_CSTATE;

  /* Saturate: '<S2>/+-10' */
  if (rtb_u0 > realtime_motor_P.u0_UpperSat) {
    rtb_u0 = realtime_motor_P.u0_UpperSat;
  } else if (rtb_u0 < realtime_motor_P.u0_LowerSat) {
    rtb_u0 = realtime_motor_P.u0_LowerSat;
  }

  /* End of Saturate: '<S2>/+-10' */

  /* S-Function (sldrtao): '<Root>/Analog Output1' */
  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime_motor_P.AnalogOutput1_RangeMode;
      parm.rangeidx = realtime_motor_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime_motor_P.AnalogOutput1_Channels, ((real_T*)
        (&rtb_u0)), &parm);
    }
  }

  /* Gain: '<S4>/N1' incorporates:
   *  Gain: '<S4>/ '
   *  TransferFcn: '<S4>/Filtering derivative'
   */
  rtb_w_l_refrpm = (realtime_motor_P.Filteringderivative_C[0] *
                    realtime_motor_X.Filteringderivative_CSTATE[0] +
                    realtime_motor_P.Filteringderivative_C[1] *
                    realtime_motor_X.Filteringderivative_CSTATE[1]) *
    realtime_motor_P.degs2rpm * realtime_motor_P.gbox.N;

  /* Gain: '<S4>/Gain8' */
  realtime_motor_B.Gain8 = realtime_motor_P.rpm2rads * rtb_w_l_refrpm;
  tmp = (rtmIsMajorTimeStep(realtime_motor_M) &&
         realtime_motor_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
  }

  /* TransferFcn: '<S3>/ Current filter' */
  realtime_motor_B.filterediaA = 0.0;
  realtime_motor_B.filterediaA += realtime_motor_P.Currentfilter_C[0] *
    realtime_motor_X.Currentfilter_CSTATE[0];
  realtime_motor_B.filterediaA += realtime_motor_P.Currentfilter_C[1] *
    realtime_motor_X.Currentfilter_CSTATE[1];
  if (tmp) {
  }

  /* TransferFcn: '<S4>/Filtering derivative 2' */
  realtime_motor_B.a_mradss = 0.0;
  realtime_motor_B.a_mradss += realtime_motor_P.Filteringderivative2_C[0] *
    realtime_motor_X.Filteringderivative2_CSTATE[0];
  realtime_motor_B.a_mradss += realtime_motor_P.Filteringderivative2_C[1] *
    realtime_motor_X.Filteringderivative2_CSTATE[1];
  if (tmp) {
  }

  /* Gain: '<S3>/Torque const' */
  realtime_motor_B.Torqueconst = realtime_motor_P.mot.Kt *
    realtime_motor_B.filterediaA;

  /* Signum: '<S5>/Sign1' */
  if (rtIsNaN(realtime_motor_B.Gain8)) {
    rtb_u0 = (rtNaN);
  } else if (realtime_motor_B.Gain8 < 0.0) {
    rtb_u0 = -1.0;
  } else {
    rtb_u0 = (realtime_motor_B.Gain8 > 0.0);
  }

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain6'
   *  Signum: '<S5>/Sign1'
   *  Sum: '<S5>/Sum3'
   */
  realtime_motor_B.tau_i_hat = realtime_motor_B.Torqueconst
    - (realtime_motor_P.tau_sf / realtime_motor_P.gbox.N * rtb_u0 +
       realtime_motor_P.Beq * realtime_motor_B.Gain8);
  if (tmp) {
  }

  /* Gain: '<S4>/1//k1' */
  realtime_motor_B.w_mkrpm = realtime_motor_P.uk1_Gain * rtb_w_l_refrpm;
  if (tmp) {
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Subtract1'
   */
  realtime_motor_B.ia = 1.0 / realtime_motor_P.sens.curr.Rs * (rtb_AnalogInput1
    [0] - rtb_AnalogInput1[1]);
  tmp_0 = (rtmIsMajorTimeStep(realtime_motor_M) &&
           realtime_motor_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp_0) {
    /* UnitDelay: '<S9>/Output' */
    rtb_Output_k = realtime_motor_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S7>/Output' incorporates:
     *  Constant: '<S7>/Vector'
     *  UnitDelay: '<S9>/Output'
     */
    rtb_u0 =
      realtime_motor_P.RepeatingSequenceStair_OutValues[realtime_motor_DW.Output_DSTATE];

    /* UnitDelay: '<S12>/Output' */
    rtb_Output_i = realtime_motor_DW.Output_DSTATE_m;

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<S8>/Vector'
     *  Gain: '<S6>/Gain2'
     *  MultiPortSwitch: '<S8>/Output'
     *  UnitDelay: '<S12>/Output'
     */
    if (realtime_motor_P.ManualSwitch_CurrentSetting != 1) {
      rtb_u0 = realtime_motor_P.Gain2_Gain *
        realtime_motor_P.RepeatingSequenceStair1_OutValues[realtime_motor_DW.Output_DSTATE_m];
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* Gain: '<Root>/Gain4' */
    realtime_motor_B.w_l_refdegs = realtime_motor_P.rpm2degs * rtb_u0;
  }

  /* Gain: '<Root>/Gain5' incorporates:
   *  Integrator: '<Root>/Integrator1'
   */
  realtime_motor_B.w_l_refdegs_i = realtime_motor_P.rpm2degs *
    realtime_motor_X.Integrator1_CSTATE;

  /* Gain: '<S2>/Kd' */
  realtime_motor_B.Kd = realtime_motor_P.Kd * rtb_deg2rad;

  /* Gain: '<S2>/Ki' */
  realtime_motor_B.Ki = realtime_motor_P.Ki * rtb_deg2rad;
  if (tmp) {
    /* DiscretePulseGenerator: '<S1>/Pulse Generator3' */
    if ((realtime_motor_DW.clockTickCounter <
         realtime_motor_P.PulseGenerator3_Duty) &&
        (realtime_motor_DW.clockTickCounter >= 0)) {
      rtb_u0 = realtime_motor_P.PulseGenerator3_Amp;
    } else {
      rtb_u0 = 0.0;
    }

    if (realtime_motor_DW.clockTickCounter >=
        realtime_motor_P.PulseGenerator3_Period - 1.0) {
      realtime_motor_DW.clockTickCounter = 0;
    } else {
      realtime_motor_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator3' */

    /* Gain: '<S1>/Gain5' */
    rtb_w_l_refrpm = realtime_motor_P.Gain5_Gain * rtb_u0;

    /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
    if ((realtime_motor_DW.clockTickCounter_n <
         realtime_motor_P.PulseGenerator2_Duty) &&
        (realtime_motor_DW.clockTickCounter_n >= 0)) {
      rtb_u0 = realtime_motor_P.PulseGenerator2_Amp;
    } else {
      rtb_u0 = 0.0;
    }

    if (realtime_motor_DW.clockTickCounter_n >=
        realtime_motor_P.PulseGenerator2_Period - 1.0) {
      realtime_motor_DW.clockTickCounter_n = 0;
    } else {
      realtime_motor_DW.clockTickCounter_n++;
    }

    /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

    /* Sum: '<S1>/Sum3' */
    realtime_motor_B.Sum3 = rtb_u0 + rtb_w_l_refrpm;
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Gain: '<S4>/1//k2'
   */
  realtime_motor_B.w_mrads = realtime_motor_P.uk2_Gain *
    realtime_motor_B.w_mkrpm * realtime_motor_P.rpm2rads;
  if (tmp_0) {
    /* Sum: '<S10>/FixPt Sum1' incorporates:
     *  Constant: '<S10>/FixPt Constant'
     */
    rtb_Output_k += realtime_motor_P.FixPtConstant_Value;

    /* Switch: '<S11>/FixPt Switch' */
    if (rtb_Output_k > realtime_motor_P.WrapToZero_Threshold) {
      /* Switch: '<S11>/FixPt Switch' incorporates:
       *  Constant: '<S11>/Constant'
       */
      realtime_motor_B.FixPtSwitch = realtime_motor_P.Constant_Value;
    } else {
      /* Switch: '<S11>/FixPt Switch' */
      realtime_motor_B.FixPtSwitch = rtb_Output_k;
    }

    /* End of Switch: '<S11>/FixPt Switch' */

    /* Sum: '<S13>/FixPt Sum1' incorporates:
     *  Constant: '<S13>/FixPt Constant'
     */
    rtb_Output_k = (uint8_T)(rtb_Output_i +
      realtime_motor_P.FixPtConstant_Value_m);

    /* Switch: '<S14>/FixPt Switch' */
    if (rtb_Output_k > realtime_motor_P.WrapToZero_Threshold_e) {
      /* Switch: '<S14>/FixPt Switch' incorporates:
       *  Constant: '<S14>/Constant'
       */
      realtime_motor_B.FixPtSwitch_g = realtime_motor_P.Constant_Value_h;
    } else {
      /* Switch: '<S14>/FixPt Switch' */
      realtime_motor_B.FixPtSwitch_g = rtb_Output_k;
    }

    /* End of Switch: '<S14>/FixPt Switch' */
  }
}

/* Model update function */
void realtime_motor_update(void)
{
  if (rtmIsMajorTimeStep(realtime_motor_M) &&
      realtime_motor_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S9>/Output' */
    realtime_motor_DW.Output_DSTATE = realtime_motor_B.FixPtSwitch;

    /* Update for UnitDelay: '<S12>/Output' */
    realtime_motor_DW.Output_DSTATE_m = realtime_motor_B.FixPtSwitch_g;
  }

  if (rtmIsMajorTimeStep(realtime_motor_M)) {
    rt_ertODEUpdateContinuousStates(&realtime_motor_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++realtime_motor_M->Timing.clockTick0)) {
    ++realtime_motor_M->Timing.clockTickH0;
  }

  realtime_motor_M->Timing.t[0] = rtsiGetSolverStopTime
    (&realtime_motor_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtime_motor_M->Timing.clockTick1)) {
      ++realtime_motor_M->Timing.clockTickH1;
    }

    realtime_motor_M->Timing.t[1] = realtime_motor_M->Timing.clockTick1 *
      realtime_motor_M->Timing.stepSize1 + realtime_motor_M->Timing.clockTickH1 *
      realtime_motor_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(realtime_motor_M) &&
      realtime_motor_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [5.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtime_motor_M->Timing.clockTick2)) {
      ++realtime_motor_M->Timing.clockTickH2;
    }

    realtime_motor_M->Timing.t[2] = realtime_motor_M->Timing.clockTick2 *
      realtime_motor_M->Timing.stepSize2 + realtime_motor_M->Timing.clockTickH2 *
      realtime_motor_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void realtime_motor_derivatives(void)
{
  XDot_realtime_motor_T *_rtXdot;
  _rtXdot = ((XDot_realtime_motor_T *) realtime_motor_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = realtime_motor_B.w_l_refdegs;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = realtime_motor_B.w_l_refdegs_i;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = realtime_motor_B.Ki;

  /* Derivatives for TransferFcn: '<S2>/derivative' */
  _rtXdot->derivative_CSTATE = realtime_motor_P.derivative_A *
    realtime_motor_X.derivative_CSTATE;
  _rtXdot->derivative_CSTATE += realtime_motor_B.Kd;

  /* Derivatives for TransferFcn: '<S4>/Filtering derivative' */
  _rtXdot->Filteringderivative_CSTATE[0] =
    realtime_motor_P.Filteringderivative_A[0] *
    realtime_motor_X.Filteringderivative_CSTATE[0];
  _rtXdot->Filteringderivative_CSTATE[0] +=
    realtime_motor_P.Filteringderivative_A[1] *
    realtime_motor_X.Filteringderivative_CSTATE[1];
  _rtXdot->Filteringderivative_CSTATE[1] =
    realtime_motor_X.Filteringderivative_CSTATE[0];
  _rtXdot->Filteringderivative_CSTATE[0] += realtime_motor_B.th_l_measdeg;

  /* Derivatives for TransferFcn: '<S3>/ Current filter' */
  _rtXdot->Currentfilter_CSTATE[0] = realtime_motor_P.Currentfilter_A[0] *
    realtime_motor_X.Currentfilter_CSTATE[0];
  _rtXdot->Currentfilter_CSTATE[0] += realtime_motor_P.Currentfilter_A[1] *
    realtime_motor_X.Currentfilter_CSTATE[1];
  _rtXdot->Currentfilter_CSTATE[1] = realtime_motor_X.Currentfilter_CSTATE[0];
  _rtXdot->Currentfilter_CSTATE[0] += realtime_motor_B.ia;

  /* Derivatives for TransferFcn: '<S4>/Filtering derivative 2' */
  _rtXdot->Filteringderivative2_CSTATE[0] =
    realtime_motor_P.Filteringderivative2_A[0] *
    realtime_motor_X.Filteringderivative2_CSTATE[0];
  _rtXdot->Filteringderivative2_CSTATE[0] +=
    realtime_motor_P.Filteringderivative2_A[1] *
    realtime_motor_X.Filteringderivative2_CSTATE[1];
  _rtXdot->Filteringderivative2_CSTATE[1] =
    realtime_motor_X.Filteringderivative2_CSTATE[0];
  _rtXdot->Filteringderivative2_CSTATE[0] += realtime_motor_B.w_mrads;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = realtime_motor_B.Sum3;
}

/* Model initialize function */
void realtime_motor_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime_motor_P.AnalogOutput1_RangeMode;
      parm.rangeidx = realtime_motor_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime_motor_P.AnalogOutput1_Channels,
                     &realtime_motor_P.AnalogOutput1_InitialValue, &parm);
    }
  }

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  realtime_motor_DW.clockTickCounter = -1000;

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  realtime_motor_DW.clockTickCounter_n = 0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  realtime_motor_X.Integrator_CSTATE = realtime_motor_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  realtime_motor_X.Integrator2_CSTATE = realtime_motor_P.Integrator2_IC;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input2' */

  /* S-Function Block: <Root>/Encoder Input2 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime_motor_P.EncoderInput2_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtime_motor_P.EncoderInput2_Channels, NULL, &parm);
  }

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  realtime_motor_X.Integrator_CSTATE_n = realtime_motor_P.Integrator_IC_p;

  /* InitializeConditions for TransferFcn: '<S2>/derivative' */
  realtime_motor_X.derivative_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Filtering derivative' */
  realtime_motor_X.Filteringderivative_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/ Current filter' */
  realtime_motor_X.Currentfilter_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Filtering derivative 2' */
  realtime_motor_X.Filteringderivative2_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Filtering derivative' */
  realtime_motor_X.Filteringderivative_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/ Current filter' */
  realtime_motor_X.Currentfilter_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Filtering derivative 2' */
  realtime_motor_X.Filteringderivative2_CSTATE[1] = 0.0;

  /* InitializeConditions for UnitDelay: '<S9>/Output' */
  realtime_motor_DW.Output_DSTATE = realtime_motor_P.Output_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S12>/Output' */
  realtime_motor_DW.Output_DSTATE_m = realtime_motor_P.Output_InitialCondition_d;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  realtime_motor_X.Integrator1_CSTATE = realtime_motor_P.Integrator1_IC;
}

/* Model terminate function */
void realtime_motor_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) realtime_motor_P.AnalogOutput1_RangeMode;
      parm.rangeidx = realtime_motor_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime_motor_P.AnalogOutput1_Channels,
                     &realtime_motor_P.AnalogOutput1_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  realtime_motor_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  realtime_motor_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  realtime_motor_initialize();
}

void MdlTerminate(void)
{
  realtime_motor_terminate();
}

/* Registration function */
RT_MODEL_realtime_motor_T *realtime_motor(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)realtime_motor_M, 0,
                sizeof(RT_MODEL_realtime_motor_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&realtime_motor_M->solverInfo,
                          &realtime_motor_M->Timing.simTimeStep);
    rtsiSetTPtr(&realtime_motor_M->solverInfo, &rtmGetTPtr(realtime_motor_M));
    rtsiSetStepSizePtr(&realtime_motor_M->solverInfo,
                       &realtime_motor_M->Timing.stepSize0);
    rtsiSetdXPtr(&realtime_motor_M->solverInfo, &realtime_motor_M->derivs);
    rtsiSetContStatesPtr(&realtime_motor_M->solverInfo, (real_T **)
                         &realtime_motor_M->contStates);
    rtsiSetNumContStatesPtr(&realtime_motor_M->solverInfo,
      &realtime_motor_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&realtime_motor_M->solverInfo,
      &realtime_motor_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&realtime_motor_M->solverInfo,
      &realtime_motor_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&realtime_motor_M->solverInfo,
      &realtime_motor_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&realtime_motor_M->solverInfo, (boolean_T**)
      &realtime_motor_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&realtime_motor_M->solverInfo, (&rtmGetErrorStatus
      (realtime_motor_M)));
    rtsiSetRTModelPtr(&realtime_motor_M->solverInfo, realtime_motor_M);
  }

  rtsiSetSimTimeStep(&realtime_motor_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&realtime_motor_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtime_motor_M->solverInfo, false);
  realtime_motor_M->intgData.y = realtime_motor_M->odeY;
  realtime_motor_M->intgData.f[0] = realtime_motor_M->odeF[0];
  realtime_motor_M->intgData.f[1] = realtime_motor_M->odeF[1];
  realtime_motor_M->intgData.f[2] = realtime_motor_M->odeF[2];
  realtime_motor_M->intgData.f[3] = realtime_motor_M->odeF[3];
  realtime_motor_M->intgData.f[4] = realtime_motor_M->odeF[4];
  realtime_motor_M->intgData.f[5] = realtime_motor_M->odeF[5];
  realtime_motor_M->contStates = ((real_T *) &realtime_motor_X);
  realtime_motor_M->contStateDisabled = ((boolean_T *) &realtime_motor_XDis);
  realtime_motor_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&realtime_motor_M->solverInfo, (void *)
                    &realtime_motor_M->intgData);
  rtsiSetSolverName(&realtime_motor_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = realtime_motor_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    realtime_motor_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtime_motor_M->Timing.sampleTimes =
      (&realtime_motor_M->Timing.sampleTimesArray[0]);
    realtime_motor_M->Timing.offsetTimes =
      (&realtime_motor_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtime_motor_M->Timing.sampleTimes[0] = (0.0);
    realtime_motor_M->Timing.sampleTimes[1] = (0.001);
    realtime_motor_M->Timing.sampleTimes[2] = (5.0);

    /* task offsets */
    realtime_motor_M->Timing.offsetTimes[0] = (0.0);
    realtime_motor_M->Timing.offsetTimes[1] = (0.0);
    realtime_motor_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(realtime_motor_M, &realtime_motor_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = realtime_motor_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    realtime_motor_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtime_motor_M, 20.0);
  realtime_motor_M->Timing.stepSize0 = 0.001;
  realtime_motor_M->Timing.stepSize1 = 0.001;
  realtime_motor_M->Timing.stepSize2 = 5.0;

  /* External mode info */
  realtime_motor_M->Sizes.checksums[0] = (2301158447U);
  realtime_motor_M->Sizes.checksums[1] = (953016269U);
  realtime_motor_M->Sizes.checksums[2] = (1953518815U);
  realtime_motor_M->Sizes.checksums[3] = (3720496040U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    realtime_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(realtime_motor_M->extModeInfo,
      &realtime_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(realtime_motor_M->extModeInfo,
                        realtime_motor_M->Sizes.checksums);
    rteiSetTPtr(realtime_motor_M->extModeInfo, rtmGetTPtr(realtime_motor_M));
  }

  realtime_motor_M->solverInfoPtr = (&realtime_motor_M->solverInfo);
  realtime_motor_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&realtime_motor_M->solverInfo, 0.001);
  rtsiSetSolverMode(&realtime_motor_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  realtime_motor_M->blockIO = ((void *) &realtime_motor_B);
  (void) memset(((void *) &realtime_motor_B), 0,
                sizeof(B_realtime_motor_T));

  /* parameters */
  realtime_motor_M->defaultParam = ((real_T *)&realtime_motor_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &realtime_motor_X;
    realtime_motor_M->contStates = (x);
    (void) memset((void *)&realtime_motor_X, 0,
                  sizeof(X_realtime_motor_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &realtime_motor_XDis;
    realtime_motor_M->contStateDisabled = (xdis);
    (void) memset((void *)&realtime_motor_XDis, 0,
                  sizeof(XDis_realtime_motor_T));
  }

  /* states (dwork) */
  realtime_motor_M->dwork = ((void *) &realtime_motor_DW);
  (void) memset((void *)&realtime_motor_DW, 0,
                sizeof(DW_realtime_motor_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    realtime_motor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 30;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtime_motor_M->Sizes.numContStates = (11);/* Number of continuous states */
  realtime_motor_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  realtime_motor_M->Sizes.numY = (0);  /* Number of model outputs */
  realtime_motor_M->Sizes.numU = (0);  /* Number of model inputs */
  realtime_motor_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtime_motor_M->Sizes.numSampTimes = (3);/* Number of sample times */
  realtime_motor_M->Sizes.numBlocks = (73);/* Number of blocks */
  realtime_motor_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  realtime_motor_M->Sizes.numBlockPrms = (91);/* Sum of parameter "widths" */
  return realtime_motor_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
