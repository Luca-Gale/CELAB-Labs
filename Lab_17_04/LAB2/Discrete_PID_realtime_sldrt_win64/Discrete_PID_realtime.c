/*
 * Discrete_PID_realtime.c
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
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>
#include "Discrete_PID_realtime_dt.h"

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
B_Discrete_PID_realtime_T Discrete_PID_realtime_B;

/* Block states (default storage) */
DW_Discrete_PID_realtime_T Discrete_PID_realtime_DW;

/* Real-time model */
static RT_MODEL_Discrete_PID_realtime_T Discrete_PID_realtime_M_;
RT_MODEL_Discrete_PID_realtime_T *const Discrete_PID_realtime_M =
  &Discrete_PID_realtime_M_;
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
  (Discrete_PID_realtime_M->Timing.TaskCounters.TID[1])++;
  if ((Discrete_PID_realtime_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.05s, 0.0s] */
    Discrete_PID_realtime_M->Timing.TaskCounters.TID[1] = 0;
  }

  Discrete_PID_realtime_M->Timing.sampleHits[1] =
    (Discrete_PID_realtime_M->Timing.TaskCounters.TID[1] == 0) ? 1 : 0;
  (Discrete_PID_realtime_M->Timing.TaskCounters.TID[2])++;
  if ((Discrete_PID_realtime_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.5s, 0.0s] */
    Discrete_PID_realtime_M->Timing.TaskCounters.TID[2] = 0;
  }

  Discrete_PID_realtime_M->Timing.sampleHits[2] =
    (Discrete_PID_realtime_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

/* Model output function */
void Discrete_PID_realtime_output(void)
{
  real_T tmp_1[2];
  real_T rtb_ExactmethodPID;
  real_T rtb_Kp;
  real_T rtb_Sum;
  real_T rtb_th_l_refdeg1;
  uint8_T rtb_Output_m;
  boolean_T tmp;
  boolean_T tmp_0;
  tmp = (Discrete_PID_realtime_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
    /* Gain: '<Root>/Gain3' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     */
    Discrete_PID_realtime_B.th_l_refdeg = Discrete_PID_realtime_P.rad2deg *
      Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE;

    /* Step: '<Root>/th_l_ref [deg]1' */
    if (Discrete_PID_realtime_M->Timing.t[1] <
        Discrete_PID_realtime_P.th_l_refdeg1_Time) {
      rtb_th_l_refdeg1 = Discrete_PID_realtime_P.th_l_refdeg1_Y0;
    } else {
      rtb_th_l_refdeg1 = Discrete_PID_realtime_P.th_l_refdeg1_YFinal;
    }

    /* End of Step: '<Root>/th_l_ref [deg]1' */

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (Discrete_PID_realtime_P.ManualSwitch3_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      Discrete_PID_realtime_B.output_ref = Discrete_PID_realtime_B.th_l_refdeg;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      Discrete_PID_realtime_B.output_ref = rtb_th_l_refdeg1;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */

    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = Discrete_PID_realtime_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &Discrete_PID_realtime_P.EncoderInput1_Channels, &rtb_Sum,
                     &parm);
    }

    /* Gain: '<Root>/pulse2deg1' */
    Discrete_PID_realtime_B.output_thl =
      Discrete_PID_realtime_P.sens.enc.pulse2deg * rtb_Sum;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    Discrete_PID_realtime_B.ZeroOrderHold = Discrete_PID_realtime_B.output_thl;

    /* Sum: '<Root>/Sum2' */
    Discrete_PID_realtime_B.Sum2 = Discrete_PID_realtime_B.output_ref -
      Discrete_PID_realtime_B.ZeroOrderHold;

    /* Gain: '<S1>/deg2rad' */
    rtb_Sum = Discrete_PID_realtime_P.deg2rad * Discrete_PID_realtime_B.Sum2;

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Gain: '<S1>/Kw'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    if (Discrete_PID_realtime_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Kp = 0.0;
    } else {
      rtb_Kp = Discrete_PID_realtime_P.Kw *
        Discrete_PID_realtime_DW.UnitDelay_DSTATE;
    }

    /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S1>/Ki'
     *  ManualSwitch: '<S1>/Manual Switch'
     *  Sum: '<S1>/Sum2'
     */
    Discrete_PID_realtime_B.DiscreteTimeIntegrator = (Discrete_PID_realtime_P.Ki
      * rtb_Sum - rtb_Kp) *
      Discrete_PID_realtime_P.DiscreteTimeIntegrator_gainval_g +
      Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE_g;
  }

  tmp_0 = (Discrete_PID_realtime_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp_0) {
    /* UnitDelay: '<S3>/Output' */
    rtb_Output_m = Discrete_PID_realtime_DW.Output_DSTATE;

    /* SignalConversion: '<S2>/Out' incorporates:
     *  Constant: '<S2>/Vector'
     *  MultiPortSwitch: '<S2>/Output'
     *  UnitDelay: '<S3>/Output'
     */
    Discrete_PID_realtime_B.Out =
      Discrete_PID_realtime_P.a_l_refrpms_OutValues[Discrete_PID_realtime_DW.Output_DSTATE];
  }

  if (tmp) {
    /* Gain: '<Root>/Gain8' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
     */
    Discrete_PID_realtime_B.w_l_refrads = Discrete_PID_realtime_P.rpm2rads *
      Discrete_PID_realtime_DW.DiscreteTimeIntegrator1_DSTATE;
  }

  if (tmp_0) {
    /* Gain: '<Root>/Inertia compensator' */
    Discrete_PID_realtime_B.Inertiacompensator = Discrete_PID_realtime_P.I_C *
      Discrete_PID_realtime_B.Out;
  }

  if (tmp) {
    /* Signum: '<Root>/Sign' */
    if (rtIsNaN(Discrete_PID_realtime_B.w_l_refrads)) {
      rtb_Kp = (rtNaN);
    } else if (Discrete_PID_realtime_B.w_l_refrads < 0.0) {
      rtb_Kp = -1.0;
    } else {
      rtb_Kp = (Discrete_PID_realtime_B.w_l_refrads > 0.0);
    }

    /* Sum: '<Root>/Sum11' incorporates:
     *  Gain: '<Root>/BEMF compensator'
     *  Gain: '<Root>/Friction compensator'
     *  Gain: '<Root>/Gain2'
     *  Gain: '<Root>/Gain6'
     *  Signum: '<Root>/Sign'
     *  Sum: '<Root>/Sum1'
     */
    Discrete_PID_realtime_B.Sum11 = ((196.0 * Discrete_PID_realtime_P.Beq *
      Discrete_PID_realtime_B.w_l_refrads + Discrete_PID_realtime_P.tau_sf *
      rtb_Kp) * Discrete_PID_realtime_P.F_C +
      Discrete_PID_realtime_B.Inertiacompensator) + Discrete_PID_realtime_P.B_C *
      Discrete_PID_realtime_B.w_l_refrads;

    /* ManualSwitch: '<Root>/Manual Switch2' */
    if (Discrete_PID_realtime_P.ManualSwitch2_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch2' */
      Discrete_PID_realtime_B.ManualSwitch2 = 0.0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch2' */
      Discrete_PID_realtime_B.ManualSwitch2 = Discrete_PID_realtime_B.Sum11;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* DiscreteTransferFcn: '<Root>/Tustin PID' */
    Discrete_PID_realtime_DW.TustinPID_tmp = ((Discrete_PID_realtime_B.Sum2 -
      Discrete_PID_realtime_DW.TustinPID_states[0] *
      Discrete_PID_realtime_P.den_T[1]) -
      Discrete_PID_realtime_DW.TustinPID_states[1] *
      Discrete_PID_realtime_P.den_T[2]) / Discrete_PID_realtime_P.den_T[0];

    /* Gain: '<S1>/Kp' */
    rtb_Kp = Discrete_PID_realtime_P.Kp * rtb_Sum;

    /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' incorporates:
     *  Gain: '<S1>/Kd'
     */
    Discrete_PID_realtime_DW.DiscreteTransferFcn_tmp =
      (Discrete_PID_realtime_P.Kd * rtb_Sum - Discrete_PID_realtime_P.den[1] *
       Discrete_PID_realtime_DW.DiscreteTransferFcn_states) /
      Discrete_PID_realtime_P.den[0];
    rtb_Sum = Discrete_PID_realtime_P.num[0] *
      Discrete_PID_realtime_DW.DiscreteTransferFcn_tmp;

    /* Sum: '<S1>/Sum' incorporates:
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
     */
    rtb_Sum = ((Discrete_PID_realtime_P.num[1] *
                Discrete_PID_realtime_DW.DiscreteTransferFcn_states + rtb_Sum) +
               rtb_Kp) + Discrete_PID_realtime_B.DiscreteTimeIntegrator;

    /* Saturate: '<S1>/+-10' */
    if (rtb_Sum > Discrete_PID_realtime_P.u0_UpperSat) {
      rtb_Kp = Discrete_PID_realtime_P.u0_UpperSat;
    } else if (rtb_Sum < Discrete_PID_realtime_P.u0_LowerSat) {
      rtb_Kp = Discrete_PID_realtime_P.u0_LowerSat;
    } else {
      rtb_Kp = rtb_Sum;
    }

    /* End of Saturate: '<S1>/+-10' */

    /* DiscreteTransferFcn: '<Root>/Forward Euler PID' incorporates:
     *  DiscreteTransferFcn: '<Root>/Exact method PID'
     */
    _mm_storeu_pd(&tmp_1[0], _mm_div_pd(_mm_sub_pd(_mm_sub_pd(_mm_set1_pd
      (Discrete_PID_realtime_B.Sum2), _mm_mul_pd(_mm_set_pd
      (Discrete_PID_realtime_DW.ExactmethodPID_states[0],
       Discrete_PID_realtime_DW.ForwardEulerPID_states[0]), _mm_set_pd
      (Discrete_PID_realtime_P.den_EX[1], Discrete_PID_realtime_P.den_FE[1]))),
      _mm_mul_pd(_mm_set_pd(Discrete_PID_realtime_DW.ExactmethodPID_states[1],
      Discrete_PID_realtime_DW.ForwardEulerPID_states[1]), _mm_set_pd
                 (Discrete_PID_realtime_P.den_EX[2],
                  Discrete_PID_realtime_P.den_FE[2]))), _mm_set_pd
      (Discrete_PID_realtime_P.den_EX[0], Discrete_PID_realtime_P.den_FE[0])));
    Discrete_PID_realtime_DW.ForwardEulerPID_tmp = tmp_1[0];

    /* DiscreteTransferFcn: '<Root>/Exact method PID' */
    Discrete_PID_realtime_DW.ExactmethodPID_tmp = tmp_1[1];
    rtb_ExactmethodPID = (Discrete_PID_realtime_P.num_EX[0] *
                          Discrete_PID_realtime_DW.ExactmethodPID_tmp +
                          Discrete_PID_realtime_DW.ExactmethodPID_states[0] *
                          Discrete_PID_realtime_P.num_EX[1]) +
      Discrete_PID_realtime_DW.ExactmethodPID_states[1] *
      Discrete_PID_realtime_P.num_EX[2];

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  DiscreteTransferFcn: '<Root>/Forward Euler PID'
     *  DiscreteTransferFcn: '<Root>/Tustin PID'
     */
    switch ((int32_T)Discrete_PID_realtime_P.Constant_Value) {
     case 1:
      rtb_ExactmethodPID = (Discrete_PID_realtime_P.num_T[0] *
                            Discrete_PID_realtime_DW.TustinPID_tmp +
                            Discrete_PID_realtime_DW.TustinPID_states[0] *
                            Discrete_PID_realtime_P.num_T[1]) +
        Discrete_PID_realtime_DW.TustinPID_states[1] *
        Discrete_PID_realtime_P.num_T[2];
      break;

     case 2:
      rtb_ExactmethodPID = rtb_Kp;
      break;

     case 3:
      rtb_ExactmethodPID = (Discrete_PID_realtime_P.num_FE[0] *
                            Discrete_PID_realtime_DW.ForwardEulerPID_tmp +
                            Discrete_PID_realtime_DW.ForwardEulerPID_states[0] *
                            Discrete_PID_realtime_P.num_FE[1]) +
        Discrete_PID_realtime_DW.ForwardEulerPID_states[1] *
        Discrete_PID_realtime_P.num_FE[2];
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* Sum: '<Root>/Sum4' */
    rtb_ExactmethodPID += Discrete_PID_realtime_B.ManualSwitch2;

    /* S-Function (sldrtao): '<Root>/Analog Output2' */
    /* S-Function Block: <Root>/Analog Output2 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) Discrete_PID_realtime_P.AnalogOutput2_RangeMode;
        parm.rangeidx = Discrete_PID_realtime_P.AnalogOutput2_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &Discrete_PID_realtime_P.AnalogOutput2_Channels, ((real_T*)
          (&rtb_ExactmethodPID)), &parm);
      }
    }

    /* Gain: '<Root>/Gain7' */
    Discrete_PID_realtime_B.u_perc = Discrete_PID_realtime_P.Gain7_Gain *
      rtb_th_l_refdeg1;

    /* Gain: '<Root>/Gain9' */
    Discrete_PID_realtime_B.u5_perc = Discrete_PID_realtime_P.Gain9_Gain *
      rtb_th_l_refdeg1;

    /* ToAsyncQueueBlock generated from: '<Root>/pulse2deg1' */
    {
      {
        double time = Discrete_PID_realtime_M->Timing.t[1];
        void *pData = (void *)&Discrete_PID_realtime_B.output_thl;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1582434859U, time, pData, size);
      }
    }

    /* Sum: '<S1>/Sum1' */
    Discrete_PID_realtime_B.Sum1 = rtb_Sum - rtb_Kp;
  }

  if (tmp_0) {
    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     */
    rtb_Output_m += Discrete_PID_realtime_P.FixPtConstant_Value;

    /* Switch: '<S5>/FixPt Switch' */
    if (rtb_Output_m > Discrete_PID_realtime_P.WrapToZero_Threshold) {
      /* Switch: '<S5>/FixPt Switch' incorporates:
       *  Constant: '<S5>/Constant'
       */
      Discrete_PID_realtime_B.FixPtSwitch =
        Discrete_PID_realtime_P.Constant_Value_g;
    } else {
      /* Switch: '<S5>/FixPt Switch' */
      Discrete_PID_realtime_B.FixPtSwitch = rtb_Output_m;
    }

    /* End of Switch: '<S5>/FixPt Switch' */
  }
}

/* Model update function */
void Discrete_PID_realtime_update(void)
{
  if (Discrete_PID_realtime_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE +=
      Discrete_PID_realtime_P.DiscreteTimeIntegrator_gainval *
      Discrete_PID_realtime_B.w_l_refrads;

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    Discrete_PID_realtime_DW.UnitDelay_DSTATE = Discrete_PID_realtime_B.Sum1;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE_g =
      Discrete_PID_realtime_B.DiscreteTimeIntegrator;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Discrete_PID_realtime_DW.DiscreteTimeIntegrator1_DSTATE +=
      Discrete_PID_realtime_P.DiscreteTimeIntegrator1_gainval *
      Discrete_PID_realtime_B.Out;

    /* Update for DiscreteTransferFcn: '<Root>/Tustin PID' */
    Discrete_PID_realtime_DW.TustinPID_states[1] =
      Discrete_PID_realtime_DW.TustinPID_states[0];
    Discrete_PID_realtime_DW.TustinPID_states[0] =
      Discrete_PID_realtime_DW.TustinPID_tmp;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
    Discrete_PID_realtime_DW.DiscreteTransferFcn_states =
      Discrete_PID_realtime_DW.DiscreteTransferFcn_tmp;

    /* Update for DiscreteTransferFcn: '<Root>/Forward Euler PID' */
    Discrete_PID_realtime_DW.ForwardEulerPID_states[1] =
      Discrete_PID_realtime_DW.ForwardEulerPID_states[0];
    Discrete_PID_realtime_DW.ForwardEulerPID_states[0] =
      Discrete_PID_realtime_DW.ForwardEulerPID_tmp;

    /* Update for DiscreteTransferFcn: '<Root>/Exact method PID' */
    Discrete_PID_realtime_DW.ExactmethodPID_states[1] =
      Discrete_PID_realtime_DW.ExactmethodPID_states[0];
    Discrete_PID_realtime_DW.ExactmethodPID_states[0] =
      Discrete_PID_realtime_DW.ExactmethodPID_tmp;
  }

  if (Discrete_PID_realtime_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S3>/Output' */
    Discrete_PID_realtime_DW.Output_DSTATE = Discrete_PID_realtime_B.FixPtSwitch;
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
  if (!(++Discrete_PID_realtime_M->Timing.clockTick0)) {
    ++Discrete_PID_realtime_M->Timing.clockTickH0;
  }

  Discrete_PID_realtime_M->Timing.t[0] =
    Discrete_PID_realtime_M->Timing.clockTick0 *
    Discrete_PID_realtime_M->Timing.stepSize0 +
    Discrete_PID_realtime_M->Timing.clockTickH0 *
    Discrete_PID_realtime_M->Timing.stepSize0 * 4294967296.0;
  if (Discrete_PID_realtime_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Discrete_PID_realtime_M->Timing.clockTick1)) {
      ++Discrete_PID_realtime_M->Timing.clockTickH1;
    }

    Discrete_PID_realtime_M->Timing.t[1] =
      Discrete_PID_realtime_M->Timing.clockTick1 *
      Discrete_PID_realtime_M->Timing.stepSize1 +
      Discrete_PID_realtime_M->Timing.clockTickH1 *
      Discrete_PID_realtime_M->Timing.stepSize1 * 4294967296.0;
  }

  if (Discrete_PID_realtime_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Discrete_PID_realtime_M->Timing.clockTick2)) {
      ++Discrete_PID_realtime_M->Timing.clockTickH2;
    }

    Discrete_PID_realtime_M->Timing.t[2] =
      Discrete_PID_realtime_M->Timing.clockTick2 *
      Discrete_PID_realtime_M->Timing.stepSize2 +
      Discrete_PID_realtime_M->Timing.clockTickH2 *
      Discrete_PID_realtime_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void Discrete_PID_realtime_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output2' */

  /* S-Function Block: <Root>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Discrete_PID_realtime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Discrete_PID_realtime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Discrete_PID_realtime_P.AnalogOutput2_Channels,
                     &Discrete_PID_realtime_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE =
    Discrete_PID_realtime_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = Discrete_PID_realtime_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &Discrete_PID_realtime_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  Discrete_PID_realtime_DW.UnitDelay_DSTATE =
    Discrete_PID_realtime_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE_g =
    Discrete_PID_realtime_P.DiscreteTimeIntegrator_IC_a;

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  Discrete_PID_realtime_DW.Output_DSTATE =
    Discrete_PID_realtime_P.Output_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Discrete_PID_realtime_DW.DiscreteTimeIntegrator1_DSTATE =
    Discrete_PID_realtime_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  Discrete_PID_realtime_DW.DiscreteTransferFcn_states =
    Discrete_PID_realtime_P.DiscreteTransferFcn_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Tustin PID' */
  Discrete_PID_realtime_DW.TustinPID_states[0] =
    Discrete_PID_realtime_P.TustinPID_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Forward Euler PID' */
  Discrete_PID_realtime_DW.ForwardEulerPID_states[0] =
    Discrete_PID_realtime_P.ForwardEulerPID_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Exact method PID' */
  Discrete_PID_realtime_DW.ExactmethodPID_states[0] =
    Discrete_PID_realtime_P.ExactmethodPID_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Tustin PID' */
  Discrete_PID_realtime_DW.TustinPID_states[1] =
    Discrete_PID_realtime_P.TustinPID_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Forward Euler PID' */
  Discrete_PID_realtime_DW.ForwardEulerPID_states[1] =
    Discrete_PID_realtime_P.ForwardEulerPID_InitialStates;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Exact method PID' */
  Discrete_PID_realtime_DW.ExactmethodPID_states[1] =
    Discrete_PID_realtime_P.ExactmethodPID_InitialStates;
}

/* Model terminate function */
void Discrete_PID_realtime_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output2' */

  /* S-Function Block: <Root>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Discrete_PID_realtime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Discrete_PID_realtime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Discrete_PID_realtime_P.AnalogOutput2_Channels,
                     &Discrete_PID_realtime_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Discrete_PID_realtime_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Discrete_PID_realtime_update();
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
  Discrete_PID_realtime_initialize();
}

void MdlTerminate(void)
{
  Discrete_PID_realtime_terminate();
}

/* Registration function */
RT_MODEL_Discrete_PID_realtime_T *Discrete_PID_realtime(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Discrete_PID_realtime_M, 0,
                sizeof(RT_MODEL_Discrete_PID_realtime_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Discrete_PID_realtime_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Discrete_PID_realtime_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Discrete_PID_realtime_M->Timing.sampleTimes =
      (&Discrete_PID_realtime_M->Timing.sampleTimesArray[0]);
    Discrete_PID_realtime_M->Timing.offsetTimes =
      (&Discrete_PID_realtime_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Discrete_PID_realtime_M->Timing.sampleTimes[0] = (0.001);
    Discrete_PID_realtime_M->Timing.sampleTimes[1] = (0.05);
    Discrete_PID_realtime_M->Timing.sampleTimes[2] = (0.5);

    /* task offsets */
    Discrete_PID_realtime_M->Timing.offsetTimes[0] = (0.0);
    Discrete_PID_realtime_M->Timing.offsetTimes[1] = (0.0);
    Discrete_PID_realtime_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Discrete_PID_realtime_M, &Discrete_PID_realtime_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Discrete_PID_realtime_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Discrete_PID_realtime_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Discrete_PID_realtime_M, 10.0);
  Discrete_PID_realtime_M->Timing.stepSize0 = 0.001;
  Discrete_PID_realtime_M->Timing.stepSize1 = 0.05;
  Discrete_PID_realtime_M->Timing.stepSize2 = 0.5;

  /* External mode info */
  Discrete_PID_realtime_M->Sizes.checksums[0] = (131830696U);
  Discrete_PID_realtime_M->Sizes.checksums[1] = (3035023542U);
  Discrete_PID_realtime_M->Sizes.checksums[2] = (1235585624U);
  Discrete_PID_realtime_M->Sizes.checksums[3] = (67701463U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Discrete_PID_realtime_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Discrete_PID_realtime_M->extModeInfo,
      &Discrete_PID_realtime_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Discrete_PID_realtime_M->extModeInfo,
                        Discrete_PID_realtime_M->Sizes.checksums);
    rteiSetTPtr(Discrete_PID_realtime_M->extModeInfo, rtmGetTPtr
                (Discrete_PID_realtime_M));
  }

  Discrete_PID_realtime_M->solverInfoPtr = (&Discrete_PID_realtime_M->solverInfo);
  Discrete_PID_realtime_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Discrete_PID_realtime_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Discrete_PID_realtime_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Discrete_PID_realtime_M->blockIO = ((void *) &Discrete_PID_realtime_B);
  (void) memset(((void *) &Discrete_PID_realtime_B), 0,
                sizeof(B_Discrete_PID_realtime_T));

  /* parameters */
  Discrete_PID_realtime_M->defaultParam = ((real_T *)&Discrete_PID_realtime_P);

  /* states (dwork) */
  Discrete_PID_realtime_M->dwork = ((void *) &Discrete_PID_realtime_DW);
  (void) memset((void *)&Discrete_PID_realtime_DW, 0,
                sizeof(DW_Discrete_PID_realtime_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Discrete_PID_realtime_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 29;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Discrete_PID_realtime_M->Sizes.numContStates = (0);/* Number of continuous states */
  Discrete_PID_realtime_M->Sizes.numY = (0);/* Number of model outputs */
  Discrete_PID_realtime_M->Sizes.numU = (0);/* Number of model inputs */
  Discrete_PID_realtime_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Discrete_PID_realtime_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Discrete_PID_realtime_M->Sizes.numBlocks = (59);/* Number of blocks */
  Discrete_PID_realtime_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  Discrete_PID_realtime_M->Sizes.numBlockPrms = (78);/* Sum of parameter "widths" */
  return Discrete_PID_realtime_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
