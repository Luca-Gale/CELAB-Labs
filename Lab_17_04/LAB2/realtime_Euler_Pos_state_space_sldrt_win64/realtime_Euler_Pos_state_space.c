/*
 * realtime_Euler_Pos_state_space.c
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
#include "rtwtypes.h"
#include <emmintrin.h>
#include <string.h>
#include "realtime_Euler_Pos_state_space_dt.h"

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
B_realtime_Euler_Pos_state_space_T realtime_Euler_Pos_state_space_B;

/* Block states (default storage) */
DW_realtime_Euler_Pos_state_space_T realtime_Euler_Pos_state_space_DW;

/* Real-time model */
static RT_MODEL_realtime_Euler_Pos_state_space_T
  realtime_Euler_Pos_state_space_M_;
RT_MODEL_realtime_Euler_Pos_state_space_T *const
  realtime_Euler_Pos_state_space_M = &realtime_Euler_Pos_state_space_M_;
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
  (realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2])++;
  if ((realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.05s, 0.0s] */
    realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2] = 0;
  }

  realtime_Euler_Pos_state_space_M->Timing.sampleHits[2] =
    (realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

/* Model output function */
void realtime_Euler_Pos_state_space_output(void)
{
  real_T tmp_0[2];
  real_T rtb_Gain2;
  real_T rtb_Gain2_k;
  real_T rtb_Saturation;
  real_T tmp;

  /* Step: '<Root>/Step' */
  if (realtime_Euler_Pos_state_space_M->Timing.t[0] <
      realtime_Euler_Pos_state_space_P.Step_Time) {
    /* Step: '<Root>/Step' */
    realtime_Euler_Pos_state_space_B.Step =
      realtime_Euler_Pos_state_space_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    realtime_Euler_Pos_state_space_B.Step =
      realtime_Euler_Pos_state_space_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* ZeroOrderHold: '<Root>/Zero-Order Hold' incorporates:
   *  Gain: '<S1>/Gain1'
   */
  if (realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    realtime_Euler_Pos_state_space_B.ZeroOrderHold =
      realtime_Euler_Pos_state_space_B.Step;

    /* Gain: '<S1>/deg2rad2' */
    rtb_Gain2_k = realtime_Euler_Pos_state_space_P.deg2rad *
      realtime_Euler_Pos_state_space_B.ZeroOrderHold;

    /* Gain: '<S1>/Gain2' */
    rtb_Gain2 = realtime_Euler_Pos_state_space_P.Nu * rtb_Gain2_k;
    _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_loadu_pd
      (&realtime_Euler_Pos_state_space_P.Nx[0]), _mm_set1_pd(rtb_Gain2_k)));

    /* S-Function (sldrtei): '<Root>/Encoder Input2' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    /* S-Function Block: <Root>/Encoder Input2 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = realtime_Euler_Pos_state_space_P.EncoderInput2_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &realtime_Euler_Pos_state_space_P.EncoderInput2_Channels,
                     &rtb_Gain2_k, &parm);
    }

    /* Gain: '<Root>/Gain' */
    realtime_Euler_Pos_state_space_B.Gain =
      realtime_Euler_Pos_state_space_P.Gain_Gain * rtb_Gain2_k;

    /* Gain: '<Root>/Gain2' */
    rtb_Gain2_k = realtime_Euler_Pos_state_space_P.deg2rad *
      realtime_Euler_Pos_state_space_B.Gain;

    /* Sum: '<Root>/Sum' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space2'
     *  Gain: '<Root>/Gain1'
     */
    rtb_Saturation = realtime_Euler_Pos_state_space_P.Ho[0] *
      realtime_Euler_Pos_state_space_DW.DiscreteStateSpace2_DSTATE +
      realtime_Euler_Pos_state_space_P.Gain1_Gain[0] * rtb_Gain2_k;
    realtime_Euler_Pos_state_space_B.Sum[0] = rtb_Saturation;

    /* Gain: '<S1>/Gain' incorporates:
     *  Sum: '<S1>/Sum'
     */
    tmp = (tmp_0[0] - rtb_Saturation) * realtime_Euler_Pos_state_space_P.K[0];

    /* Sum: '<Root>/Sum' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space2'
     *  Gain: '<Root>/Gain1'
     */
    rtb_Saturation = realtime_Euler_Pos_state_space_P.Ho[1] *
      realtime_Euler_Pos_state_space_DW.DiscreteStateSpace2_DSTATE +
      realtime_Euler_Pos_state_space_P.Gain1_Gain[1] * rtb_Gain2_k;
    realtime_Euler_Pos_state_space_B.Sum[1] = rtb_Saturation;

    /* Sum: '<S1>/Sum1' incorporates:
     *  Gain: '<S1>/Gain'
     *  Sum: '<S1>/Sum'
     */
    rtb_Saturation = ((tmp_0[1] - rtb_Saturation) *
                      realtime_Euler_Pos_state_space_P.K[1] + tmp) + rtb_Gain2;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Saturation > realtime_Euler_Pos_state_space_P.Saturation_UpperSat) {
      rtb_Saturation = realtime_Euler_Pos_state_space_P.Saturation_UpperSat;
    } else if (rtb_Saturation <
               realtime_Euler_Pos_state_space_P.Saturation_LowerSat) {
      rtb_Saturation = realtime_Euler_Pos_state_space_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* S-Function (sldrtao): '<Root>/Analog Output1' */
    /* S-Function Block: <Root>/Analog Output1 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          realtime_Euler_Pos_state_space_P.AnalogOutput1_RangeMode;
        parm.rangeidx = realtime_Euler_Pos_state_space_P.AnalogOutput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &realtime_Euler_Pos_state_space_P.AnalogOutput1_Channels,
                       ((real_T*) (&rtb_Saturation)), &parm);
      }
    }

    /* SignalConversion generated from: '<Root>/Discrete State-Space2' */
    realtime_Euler_Pos_state_space_B.TmpSignalConversionAtDiscreteStateSpace2Inport1
      [0] = rtb_Saturation;
    realtime_Euler_Pos_state_space_B.TmpSignalConversionAtDiscreteStateSpace2Inport1
      [1] = rtb_Gain2_k;
  }

  /* End of ZeroOrderHold: '<Root>/Zero-Order Hold' */
}

/* Model update function */
void realtime_Euler_Pos_state_space_update(void)
{
  if (realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
    realtime_Euler_Pos_state_space_DW.DiscreteStateSpace2_DSTATE =
      (realtime_Euler_Pos_state_space_P.Phi_o *
       realtime_Euler_Pos_state_space_DW.DiscreteStateSpace2_DSTATE +
       realtime_Euler_Pos_state_space_P.Gamma_o[0] *
       realtime_Euler_Pos_state_space_B.TmpSignalConversionAtDiscreteStateSpace2Inport1
       [0]) + realtime_Euler_Pos_state_space_P.Gamma_o[1] *
      realtime_Euler_Pos_state_space_B.TmpSignalConversionAtDiscreteStateSpace2Inport1
      [1];
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
  if (!(++realtime_Euler_Pos_state_space_M->Timing.clockTick0)) {
    ++realtime_Euler_Pos_state_space_M->Timing.clockTickH0;
  }

  realtime_Euler_Pos_state_space_M->Timing.t[0] =
    realtime_Euler_Pos_state_space_M->Timing.clockTick0 *
    realtime_Euler_Pos_state_space_M->Timing.stepSize0 +
    realtime_Euler_Pos_state_space_M->Timing.clockTickH0 *
    realtime_Euler_Pos_state_space_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++realtime_Euler_Pos_state_space_M->Timing.clockTick1)) {
      ++realtime_Euler_Pos_state_space_M->Timing.clockTickH1;
    }

    realtime_Euler_Pos_state_space_M->Timing.t[1] =
      realtime_Euler_Pos_state_space_M->Timing.clockTick1 *
      realtime_Euler_Pos_state_space_M->Timing.stepSize1 +
      realtime_Euler_Pos_state_space_M->Timing.clockTickH1 *
      realtime_Euler_Pos_state_space_M->Timing.stepSize1 * 4294967296.0;
  }

  if (realtime_Euler_Pos_state_space_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++realtime_Euler_Pos_state_space_M->Timing.clockTick2)) {
      ++realtime_Euler_Pos_state_space_M->Timing.clockTickH2;
    }

    realtime_Euler_Pos_state_space_M->Timing.t[2] =
      realtime_Euler_Pos_state_space_M->Timing.clockTick2 *
      realtime_Euler_Pos_state_space_M->Timing.stepSize2 +
      realtime_Euler_Pos_state_space_M->Timing.clockTickH2 *
      realtime_Euler_Pos_state_space_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void realtime_Euler_Pos_state_space_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        realtime_Euler_Pos_state_space_P.AnalogOutput1_RangeMode;
      parm.rangeidx = realtime_Euler_Pos_state_space_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime_Euler_Pos_state_space_P.AnalogOutput1_Channels,
                     &realtime_Euler_Pos_state_space_P.AnalogOutput1_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
  realtime_Euler_Pos_state_space_DW.DiscreteStateSpace2_DSTATE =
    realtime_Euler_Pos_state_space_P.DiscreteStateSpace2_InitialCondition;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input2' */

  /* S-Function Block: <Root>/Encoder Input2 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = realtime_Euler_Pos_state_space_P.EncoderInput2_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &realtime_Euler_Pos_state_space_P.EncoderInput2_Channels,
                   NULL, &parm);
  }
}

/* Model terminate function */
void realtime_Euler_Pos_state_space_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output1' */

  /* S-Function Block: <Root>/Analog Output1 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        realtime_Euler_Pos_state_space_P.AnalogOutput1_RangeMode;
      parm.rangeidx = realtime_Euler_Pos_state_space_P.AnalogOutput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &realtime_Euler_Pos_state_space_P.AnalogOutput1_Channels,
                     &realtime_Euler_Pos_state_space_P.AnalogOutput1_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  realtime_Euler_Pos_state_space_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  realtime_Euler_Pos_state_space_update();
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
  realtime_Euler_Pos_state_space_initialize();
}

void MdlTerminate(void)
{
  realtime_Euler_Pos_state_space_terminate();
}

/* Registration function */
RT_MODEL_realtime_Euler_Pos_state_space_T *realtime_Euler_Pos_state_space(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)realtime_Euler_Pos_state_space_M, 0,
                sizeof(RT_MODEL_realtime_Euler_Pos_state_space_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&realtime_Euler_Pos_state_space_M->solverInfo,
                          &realtime_Euler_Pos_state_space_M->Timing.simTimeStep);
    rtsiSetTPtr(&realtime_Euler_Pos_state_space_M->solverInfo, &rtmGetTPtr
                (realtime_Euler_Pos_state_space_M));
    rtsiSetStepSizePtr(&realtime_Euler_Pos_state_space_M->solverInfo,
                       &realtime_Euler_Pos_state_space_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&realtime_Euler_Pos_state_space_M->solverInfo,
                          (&rtmGetErrorStatus(realtime_Euler_Pos_state_space_M)));
    rtsiSetRTModelPtr(&realtime_Euler_Pos_state_space_M->solverInfo,
                      realtime_Euler_Pos_state_space_M);
  }

  rtsiSetSimTimeStep(&realtime_Euler_Pos_state_space_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&realtime_Euler_Pos_state_space_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&realtime_Euler_Pos_state_space_M->solverInfo, false);
  rtsiSetSolverName(&realtime_Euler_Pos_state_space_M->solverInfo,
                    "FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      realtime_Euler_Pos_state_space_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    realtime_Euler_Pos_state_space_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    realtime_Euler_Pos_state_space_M->Timing.sampleTimes =
      (&realtime_Euler_Pos_state_space_M->Timing.sampleTimesArray[0]);
    realtime_Euler_Pos_state_space_M->Timing.offsetTimes =
      (&realtime_Euler_Pos_state_space_M->Timing.offsetTimesArray[0]);

    /* task periods */
    realtime_Euler_Pos_state_space_M->Timing.sampleTimes[0] = (0.0);
    realtime_Euler_Pos_state_space_M->Timing.sampleTimes[1] = (0.001);
    realtime_Euler_Pos_state_space_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    realtime_Euler_Pos_state_space_M->Timing.offsetTimes[0] = (0.0);
    realtime_Euler_Pos_state_space_M->Timing.offsetTimes[1] = (0.0);
    realtime_Euler_Pos_state_space_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(realtime_Euler_Pos_state_space_M,
             &realtime_Euler_Pos_state_space_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      realtime_Euler_Pos_state_space_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    realtime_Euler_Pos_state_space_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(realtime_Euler_Pos_state_space_M, 10.0);
  realtime_Euler_Pos_state_space_M->Timing.stepSize0 = 0.001;
  realtime_Euler_Pos_state_space_M->Timing.stepSize1 = 0.001;
  realtime_Euler_Pos_state_space_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  realtime_Euler_Pos_state_space_M->Sizes.checksums[0] = (523763922U);
  realtime_Euler_Pos_state_space_M->Sizes.checksums[1] = (3120505666U);
  realtime_Euler_Pos_state_space_M->Sizes.checksums[2] = (2073494782U);
  realtime_Euler_Pos_state_space_M->Sizes.checksums[3] = (2142201688U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    realtime_Euler_Pos_state_space_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(realtime_Euler_Pos_state_space_M->extModeInfo,
      &realtime_Euler_Pos_state_space_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(realtime_Euler_Pos_state_space_M->extModeInfo,
                        realtime_Euler_Pos_state_space_M->Sizes.checksums);
    rteiSetTPtr(realtime_Euler_Pos_state_space_M->extModeInfo, rtmGetTPtr
                (realtime_Euler_Pos_state_space_M));
  }

  realtime_Euler_Pos_state_space_M->solverInfoPtr =
    (&realtime_Euler_Pos_state_space_M->solverInfo);
  realtime_Euler_Pos_state_space_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&realtime_Euler_Pos_state_space_M->solverInfo, 0.001);
  rtsiSetSolverMode(&realtime_Euler_Pos_state_space_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  realtime_Euler_Pos_state_space_M->blockIO = ((void *)
    &realtime_Euler_Pos_state_space_B);
  (void) memset(((void *) &realtime_Euler_Pos_state_space_B), 0,
                sizeof(B_realtime_Euler_Pos_state_space_T));

  /* parameters */
  realtime_Euler_Pos_state_space_M->defaultParam = ((real_T *)
    &realtime_Euler_Pos_state_space_P);

  /* states (dwork) */
  realtime_Euler_Pos_state_space_M->dwork = ((void *)
    &realtime_Euler_Pos_state_space_DW);
  (void) memset((void *)&realtime_Euler_Pos_state_space_DW, 0,
                sizeof(DW_realtime_Euler_Pos_state_space_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    realtime_Euler_Pos_state_space_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  realtime_Euler_Pos_state_space_M->Sizes.numContStates = (0);/* Number of continuous states */
  realtime_Euler_Pos_state_space_M->Sizes.numY = (0);/* Number of model outputs */
  realtime_Euler_Pos_state_space_M->Sizes.numU = (0);/* Number of model inputs */
  realtime_Euler_Pos_state_space_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  realtime_Euler_Pos_state_space_M->Sizes.numSampTimes = (3);/* Number of sample times */
  realtime_Euler_Pos_state_space_M->Sizes.numBlocks = (21);/* Number of blocks */
  realtime_Euler_Pos_state_space_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  realtime_Euler_Pos_state_space_M->Sizes.numBlockPrms = (35);/* Sum of parameter "widths" */
  return realtime_Euler_Pos_state_space_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
