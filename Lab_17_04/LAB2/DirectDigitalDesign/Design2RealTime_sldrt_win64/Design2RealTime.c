/*
 * Design2RealTime.c
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
#include "rtwtypes.h"
#include <string.h>
#include "Design2RealTime_dt.h"

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
B_Design2RealTime_T Design2RealTime_B;

/* Block states (default storage) */
DW_Design2RealTime_T Design2RealTime_DW;

/* Real-time model */
static RT_MODEL_Design2RealTime_T Design2RealTime_M_;
RT_MODEL_Design2RealTime_T *const Design2RealTime_M = &Design2RealTime_M_;
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
  (Design2RealTime_M->Timing.TaskCounters.TID[1])++;
  if ((Design2RealTime_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.05s, 0.0s] */
    Design2RealTime_M->Timing.TaskCounters.TID[1] = 0;
  }

  Design2RealTime_M->Timing.sampleHits[1] =
    (Design2RealTime_M->Timing.TaskCounters.TID[1] == 0) ? 1 : 0;
}

/* Model output function */
void Design2RealTime_output(void)
{
  real_T rtb_Gain1_c;
  real_T rtb_Gain1_h;
  real_T rtb_Sum2;
  if (Design2RealTime_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtei): '<S2>/Encoder Input1' */
    /* S-Function Block: <S2>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = Design2RealTime_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &Design2RealTime_P.EncoderInput1_Channels, &rtb_Gain1_h,
                     &parm);
    }

    /* Gain: '<S4>/Gain1' incorporates:
     *  Gain: '<S2>/pulse2deg'
     */
    rtb_Gain1_h = Design2RealTime_P.sens.enc.pulse2deg * rtb_Gain1_h *
      Design2RealTime_P.Gain1_Gain;

    /* Gain: '<S3>/Gain' */
    Design2RealTime_B.Gain = Design2RealTime_P.Gain_Gain * rtb_Gain1_h;

    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Design2RealTime_B.DiscreteTimeIntegrator1 =
      Design2RealTime_DW.DiscreteTimeIntegrator1_DSTATE;

    /* ToAsyncQueueBlock generated from: '<Root>/Radians to Degrees2' */
    {
      {
        double time = Design2RealTime_M->Timing.t[1];
        void *pData = (void *)&Design2RealTime_B.Gain;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(977684600U, time, pData, size);
      }
    }

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_Gain1_c = Design2RealTime_P.Gain1_Gain_m *
      Design2RealTime_P.Constant2_Value;

    /* Gain: '<Root>/Gain4' incorporates:
     *  DiscreteStateSpace: '<Root>/Discrete State-Space1'
     *  Gain: '<Root>/Gain5'
     *  Sum: '<Root>/Sum4'
     */
    rtb_Sum2 = (Design2RealTime_P.Co[0] *
                Design2RealTime_DW.DiscreteStateSpace1_DSTATE +
                Design2RealTime_P.Gain5_Gain[0] * rtb_Gain1_h) *
      Design2RealTime_P.K[0] + (Design2RealTime_P.Co[1] *
      Design2RealTime_DW.DiscreteStateSpace1_DSTATE +
      Design2RealTime_P.Gain5_Gain[1] * rtb_Gain1_h) * Design2RealTime_P.K[1];

    /* Sum: '<Root>/Sum2' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    rtb_Sum2 = (Design2RealTime_B.DiscreteTimeIntegrator1 - rtb_Sum2) +
      Design2RealTime_P.Nr * rtb_Gain1_c;

    /* S-Function (sldrtao): '<S2>/Analog Output2' */
    /* S-Function Block: <S2>/Analog Output2 */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) Design2RealTime_P.AnalogOutput2_RangeMode;
        parm.rangeidx = Design2RealTime_P.AnalogOutput2_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &Design2RealTime_P.AnalogOutput2_Channels, ((real_T*)
          (&rtb_Sum2)), &parm);
      }
    }

    /* Sum: '<Root>/Sum3' */
    Design2RealTime_B.Sum3 = rtb_Gain1_c - rtb_Gain1_h;

    /* SignalConversion generated from: '<Root>/Discrete State-Space1' */
    Design2RealTime_B.TmpSignalConversionAtDiscreteStateSpace1Inport1[0] =
      rtb_Sum2;
    Design2RealTime_B.TmpSignalConversionAtDiscreteStateSpace1Inport1[1] =
      rtb_Gain1_h;
  }
}

/* Model update function */
void Design2RealTime_update(void)
{
  if (Design2RealTime_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Design2RealTime_DW.DiscreteTimeIntegrator1_DSTATE +=
      Design2RealTime_P.DiscreteTimeIntegrator1_gainval * Design2RealTime_B.Sum3;

    /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space1' */
    Design2RealTime_DW.DiscreteStateSpace1_DSTATE = (Design2RealTime_P.Ao *
      Design2RealTime_DW.DiscreteStateSpace1_DSTATE + Design2RealTime_P.Bo[0] *
      Design2RealTime_B.TmpSignalConversionAtDiscreteStateSpace1Inport1[0]) +
      Design2RealTime_P.Bo[1] *
      Design2RealTime_B.TmpSignalConversionAtDiscreteStateSpace1Inport1[1];
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
  if (!(++Design2RealTime_M->Timing.clockTick0)) {
    ++Design2RealTime_M->Timing.clockTickH0;
  }

  Design2RealTime_M->Timing.t[0] = Design2RealTime_M->Timing.clockTick0 *
    Design2RealTime_M->Timing.stepSize0 + Design2RealTime_M->Timing.clockTickH0 *
    Design2RealTime_M->Timing.stepSize0 * 4294967296.0;
  if (Design2RealTime_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Design2RealTime_M->Timing.clockTick1)) {
      ++Design2RealTime_M->Timing.clockTickH1;
    }

    Design2RealTime_M->Timing.t[1] = Design2RealTime_M->Timing.clockTick1 *
      Design2RealTime_M->Timing.stepSize1 +
      Design2RealTime_M->Timing.clockTickH1 *
      Design2RealTime_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void Design2RealTime_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Design2RealTime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Design2RealTime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Design2RealTime_P.AnalogOutput2_Channels,
                     &Design2RealTime_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<S2>/Encoder Input1' */

  /* S-Function Block: <S2>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = Design2RealTime_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &Design2RealTime_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Design2RealTime_DW.DiscreteTimeIntegrator1_DSTATE =
    Design2RealTime_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space1' */
  Design2RealTime_DW.DiscreteStateSpace1_DSTATE =
    Design2RealTime_P.DiscreteStateSpace1_InitialCondition;
}

/* Model terminate function */
void Design2RealTime_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Design2RealTime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Design2RealTime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Design2RealTime_P.AnalogOutput2_Channels,
                     &Design2RealTime_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Design2RealTime_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Design2RealTime_update();
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
  Design2RealTime_initialize();
}

void MdlTerminate(void)
{
  Design2RealTime_terminate();
}

/* Registration function */
RT_MODEL_Design2RealTime_T *Design2RealTime(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Design2RealTime_M, 0,
                sizeof(RT_MODEL_Design2RealTime_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Design2RealTime_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Design2RealTime_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Design2RealTime_M->Timing.sampleTimes =
      (&Design2RealTime_M->Timing.sampleTimesArray[0]);
    Design2RealTime_M->Timing.offsetTimes =
      (&Design2RealTime_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Design2RealTime_M->Timing.sampleTimes[0] = (0.001);
    Design2RealTime_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    Design2RealTime_M->Timing.offsetTimes[0] = (0.0);
    Design2RealTime_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Design2RealTime_M, &Design2RealTime_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Design2RealTime_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Design2RealTime_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Design2RealTime_M, 10.0);
  Design2RealTime_M->Timing.stepSize0 = 0.001;
  Design2RealTime_M->Timing.stepSize1 = 0.05;

  /* External mode info */
  Design2RealTime_M->Sizes.checksums[0] = (3953096644U);
  Design2RealTime_M->Sizes.checksums[1] = (3055395222U);
  Design2RealTime_M->Sizes.checksums[2] = (781637683U);
  Design2RealTime_M->Sizes.checksums[3] = (354909189U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Design2RealTime_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Design2RealTime_M->extModeInfo,
      &Design2RealTime_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Design2RealTime_M->extModeInfo,
                        Design2RealTime_M->Sizes.checksums);
    rteiSetTPtr(Design2RealTime_M->extModeInfo, rtmGetTPtr(Design2RealTime_M));
  }

  Design2RealTime_M->solverInfoPtr = (&Design2RealTime_M->solverInfo);
  Design2RealTime_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Design2RealTime_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Design2RealTime_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Design2RealTime_M->blockIO = ((void *) &Design2RealTime_B);
  (void) memset(((void *) &Design2RealTime_B), 0,
                sizeof(B_Design2RealTime_T));

  /* parameters */
  Design2RealTime_M->defaultParam = ((real_T *)&Design2RealTime_P);

  /* states (dwork) */
  Design2RealTime_M->dwork = ((void *) &Design2RealTime_DW);
  (void) memset((void *)&Design2RealTime_DW, 0,
                sizeof(DW_Design2RealTime_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Design2RealTime_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Design2RealTime_M->Sizes.numContStates = (0);/* Number of continuous states */
  Design2RealTime_M->Sizes.numY = (0); /* Number of model outputs */
  Design2RealTime_M->Sizes.numU = (0); /* Number of model inputs */
  Design2RealTime_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Design2RealTime_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Design2RealTime_M->Sizes.numBlocks = (19);/* Number of blocks */
  Design2RealTime_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  Design2RealTime_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return Design2RealTime_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
