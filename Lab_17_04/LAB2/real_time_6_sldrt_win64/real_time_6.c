/*
 * real_time_6.c
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
#include "rtwtypes.h"
#include <string.h>
#include "real_time_6_dt.h"

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
B_real_time_6_T real_time_6_B;

/* Block states (default storage) */
DW_real_time_6_T real_time_6_DW;

/* Real-time model */
static RT_MODEL_real_time_6_T real_time_6_M_;
RT_MODEL_real_time_6_T *const real_time_6_M = &real_time_6_M_;
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
  (real_time_6_M->Timing.TaskCounters.TID[1])++;
  if ((real_time_6_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    real_time_6_M->Timing.TaskCounters.TID[1] = 0;
  }

  real_time_6_M->Timing.sampleHits[1] = (real_time_6_M->Timing.TaskCounters.TID
    [1] == 0) ? 1 : 0;
}

/* Model output function */
void real_time_6_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_Gain1;
  real_T rtb_Saturation;
  real_T rtb_Sum2;
  real_T rtb_Sum_k_0;
  if (real_time_6_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_time_6_P.AnalogInput_RangeMode;
      parm.rangeidx = real_time_6_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     real_time_6_P.AnalogInput_Channels, &rtb_AnalogInput[0],
                     &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = real_time_6_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &real_time_6_P.EncoderInput_Channels, &rtb_Gain1, &parm);
    }

    /* Step: '<Root>/Step3' */
    if (real_time_6_M->Timing.t[1] < real_time_6_P.Step3_Time) {
      /* Step: '<Root>/Step3' */
      real_time_6_B.Step3 = real_time_6_P.Step3_Y0;
    } else {
      /* Step: '<Root>/Step3' */
      real_time_6_B.Step3 = real_time_6_P.Step3_YFinal;
    }

    /* End of Step: '<Root>/Step3' */

    /* Gain: '<S1>/deg2rad2' */
    rtb_Sum2 = real_time_6_P.deg2rad * real_time_6_B.Step3;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' incorporates:
     *  Gain: '<Root>/pulse2deg3'
     */
    real_time_6_B.ZeroOrderHold1 = real_time_6_P.pulse2deg3_Gain * rtb_Gain1;

    /* Gain: '<Root>/Gain1' */
    rtb_Gain1 = real_time_6_P.deg2rad * real_time_6_B.ZeroOrderHold1;

    /* Sum: '<Root>/Sum' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space2'
     *  Gain: '<Root>/Gain'
     */
    rtb_Sum_k_0 = real_time_6_P.CF[0] *
      real_time_6_DW.DiscreteStateSpace2_DSTATE + real_time_6_P.Gain_Gain[0] *
      rtb_Gain1;

    /* Gain: '<S1>/Gain' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space2'
     *  Gain: '<Root>/Gain'
     *  Gain: '<S1>/Gain1'
     *  Sum: '<Root>/Sum'
     *  Sum: '<S1>/Sum'
     */
    rtb_Saturation = (real_time_6_P.Nx[1] * rtb_Sum2 - (real_time_6_P.CF[1] *
      real_time_6_DW.DiscreteStateSpace2_DSTATE + real_time_6_P.Gain_Gain[1] *
      rtb_Gain1)) * real_time_6_P.K2[1] + (real_time_6_P.Nx[0] * rtb_Sum2 -
      rtb_Sum_k_0) * real_time_6_P.K2[0];

    /* Sum: '<S1>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
     *  Gain: '<S1>/Gain2'
     */
    rtb_Saturation = (real_time_6_P.Nu * rtb_Sum2 + rtb_Saturation) +
      real_time_6_DW.DiscreteTimeIntegrator_DSTATE;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Saturation > real_time_6_P.Saturation_UpperSat) {
      rtb_Saturation = real_time_6_P.Saturation_UpperSat;
    } else if (rtb_Saturation < real_time_6_P.Saturation_LowerSat) {
      rtb_Saturation = real_time_6_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) real_time_6_P.AnalogOutput_RangeMode;
        parm.rangeidx = real_time_6_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &real_time_6_P.AnalogOutput_Channels, ((real_T*)
          (&rtb_Saturation)), &parm);
      }
    }

    /* Gain: '<S1>/Gain3' incorporates:
     *  Sum: '<Root>/Sum'
     *  Sum: '<S1>/Sum2'
     */
    real_time_6_B.Gain3 = (rtb_Sum2 - rtb_Sum_k_0) * real_time_6_P.KI;

    /* SignalConversion generated from: '<Root>/Discrete State-Space2' */
    real_time_6_B.TmpSignalConversionAtDiscreteStateSpace2Inport1[0] =
      rtb_Saturation;
    real_time_6_B.TmpSignalConversionAtDiscreteStateSpace2Inport1[1] = rtb_Gain1;
  }
}

/* Model update function */
void real_time_6_update(void)
{
  if (real_time_6_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
    real_time_6_DW.DiscreteStateSpace2_DSTATE = (real_time_6_P.AF *
      real_time_6_DW.DiscreteStateSpace2_DSTATE + real_time_6_P.BF[0] *
      real_time_6_B.TmpSignalConversionAtDiscreteStateSpace2Inport1[0]) +
      real_time_6_P.BF[1] *
      real_time_6_B.TmpSignalConversionAtDiscreteStateSpace2Inport1[1];

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    real_time_6_DW.DiscreteTimeIntegrator_DSTATE +=
      real_time_6_P.DiscreteTimeIntegrator_gainval * real_time_6_B.Gain3;
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
  if (!(++real_time_6_M->Timing.clockTick0)) {
    ++real_time_6_M->Timing.clockTickH0;
  }

  real_time_6_M->Timing.t[0] = real_time_6_M->Timing.clockTick0 *
    real_time_6_M->Timing.stepSize0 + real_time_6_M->Timing.clockTickH0 *
    real_time_6_M->Timing.stepSize0 * 4294967296.0;
  if (real_time_6_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++real_time_6_M->Timing.clockTick1)) {
      ++real_time_6_M->Timing.clockTickH1;
    }

    real_time_6_M->Timing.t[1] = real_time_6_M->Timing.clockTick1 *
      real_time_6_M->Timing.stepSize1 + real_time_6_M->Timing.clockTickH1 *
      real_time_6_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void real_time_6_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_time_6_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_time_6_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_time_6_P.AnalogOutput_Channels,
                     &real_time_6_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = real_time_6_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &real_time_6_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space2' */
  real_time_6_DW.DiscreteStateSpace2_DSTATE =
    real_time_6_P.DiscreteStateSpace2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  real_time_6_DW.DiscreteTimeIntegrator_DSTATE =
    real_time_6_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void real_time_6_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_time_6_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_time_6_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_time_6_P.AnalogOutput_Channels,
                     &real_time_6_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  real_time_6_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  real_time_6_update();
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
  real_time_6_initialize();
}

void MdlTerminate(void)
{
  real_time_6_terminate();
}

/* Registration function */
RT_MODEL_real_time_6_T *real_time_6(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)real_time_6_M, 0,
                sizeof(RT_MODEL_real_time_6_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = real_time_6_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    real_time_6_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    real_time_6_M->Timing.sampleTimes = (&real_time_6_M->
      Timing.sampleTimesArray[0]);
    real_time_6_M->Timing.offsetTimes = (&real_time_6_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    real_time_6_M->Timing.sampleTimes[0] = (0.001);
    real_time_6_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    real_time_6_M->Timing.offsetTimes[0] = (0.0);
    real_time_6_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(real_time_6_M, &real_time_6_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = real_time_6_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    real_time_6_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(real_time_6_M, 5.0);
  real_time_6_M->Timing.stepSize0 = 0.001;
  real_time_6_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  real_time_6_M->Sizes.checksums[0] = (2503072674U);
  real_time_6_M->Sizes.checksums[1] = (1163002738U);
  real_time_6_M->Sizes.checksums[2] = (2541717657U);
  real_time_6_M->Sizes.checksums[3] = (1461226991U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    real_time_6_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(real_time_6_M->extModeInfo,
      &real_time_6_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(real_time_6_M->extModeInfo,
                        real_time_6_M->Sizes.checksums);
    rteiSetTPtr(real_time_6_M->extModeInfo, rtmGetTPtr(real_time_6_M));
  }

  real_time_6_M->solverInfoPtr = (&real_time_6_M->solverInfo);
  real_time_6_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&real_time_6_M->solverInfo, 0.001);
  rtsiSetSolverMode(&real_time_6_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  real_time_6_M->blockIO = ((void *) &real_time_6_B);
  (void) memset(((void *) &real_time_6_B), 0,
                sizeof(B_real_time_6_T));

  /* parameters */
  real_time_6_M->defaultParam = ((real_T *)&real_time_6_P);

  /* states (dwork) */
  real_time_6_M->dwork = ((void *) &real_time_6_DW);
  (void) memset((void *)&real_time_6_DW, 0,
                sizeof(DW_real_time_6_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    real_time_6_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  real_time_6_M->Sizes.numContStates = (0);/* Number of continuous states */
  real_time_6_M->Sizes.numY = (0);     /* Number of model outputs */
  real_time_6_M->Sizes.numU = (0);     /* Number of model inputs */
  real_time_6_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  real_time_6_M->Sizes.numSampTimes = (2);/* Number of sample times */
  real_time_6_M->Sizes.numBlocks = (23);/* Number of blocks */
  real_time_6_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  real_time_6_M->Sizes.numBlockPrms = (44);/* Sum of parameter "widths" */
  return real_time_6_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
