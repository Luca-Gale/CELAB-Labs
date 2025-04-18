/*
 * Design1RealTime.c
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
#include "rtwtypes.h"
#include <string.h>
#include "Design1RealTime_dt.h"

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
B_Design1RealTime_T Design1RealTime_B;

/* Block states (default storage) */
DW_Design1RealTime_T Design1RealTime_DW;

/* Real-time model */
static RT_MODEL_Design1RealTime_T Design1RealTime_M_;
RT_MODEL_Design1RealTime_T *const Design1RealTime_M = &Design1RealTime_M_;

/* Model output function */
void Design1RealTime_output(void)
{
  real_T rtb_Gain1_h;
  real_T rtb_Sum1;

  /* S-Function (sldrtei): '<S2>/Encoder Input1' */
  /* S-Function Block: <S2>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = Design1RealTime_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &Design1RealTime_P.EncoderInput1_Channels, &rtb_Gain1_h,
                   &parm);
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Gain: '<S2>/pulse2deg'
   */
  rtb_Gain1_h = Design1RealTime_P.sens.enc.pulse2deg * rtb_Gain1_h *
    Design1RealTime_P.Gain1_Gain;

  /* Gain: '<S3>/Gain' */
  Design1RealTime_B.Gain = Design1RealTime_P.Gain_Gain * rtb_Gain1_h;

  /* Constant: '<Root>/Constant1' */
  Design1RealTime_B.Constant1 = Design1RealTime_P.Constant1_Value;

  /* Gain: '<Root>/Gain3' incorporates:
   *  DiscreteStateSpace: '<Root>/Discrete State-Space3'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  rtb_Sum1 = (Design1RealTime_P.Co[0] *
              Design1RealTime_DW.DiscreteStateSpace3_DSTATE +
              Design1RealTime_P.Gain_Gain_m[0] * rtb_Gain1_h) *
    Design1RealTime_P.K[0] + (Design1RealTime_P.Co[1] *
    Design1RealTime_DW.DiscreteStateSpace3_DSTATE +
    Design1RealTime_P.Gain_Gain_m[1] * rtb_Gain1_h) * Design1RealTime_P.K[1];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Gain: '<S1>/Gain1'
   */
  rtb_Sum1 = Design1RealTime_P.Gain1_Gain_a * Design1RealTime_B.Constant1 *
    Design1RealTime_P.Nr - rtb_Sum1;

  /* S-Function (sldrtao): '<S2>/Analog Output2' */
  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Design1RealTime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Design1RealTime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Design1RealTime_P.AnalogOutput2_Channels, ((real_T*)
        (&rtb_Sum1)), &parm);
    }
  }

  /* SignalConversion generated from: '<Root>/Discrete State-Space3' */
  Design1RealTime_B.TmpSignalConversionAtDiscreteStateSpace3Inport1[0] =
    rtb_Sum1;
  Design1RealTime_B.TmpSignalConversionAtDiscreteStateSpace3Inport1[1] =
    rtb_Gain1_h;
}

/* Model update function */
void Design1RealTime_update(void)
{
  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space3' */
  Design1RealTime_DW.DiscreteStateSpace3_DSTATE = (Design1RealTime_P.Ao *
    Design1RealTime_DW.DiscreteStateSpace3_DSTATE + Design1RealTime_P.Bo[0] *
    Design1RealTime_B.TmpSignalConversionAtDiscreteStateSpace3Inport1[0]) +
    Design1RealTime_P.Bo[1] *
    Design1RealTime_B.TmpSignalConversionAtDiscreteStateSpace3Inport1[1];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Design1RealTime_M->Timing.clockTick0)) {
    ++Design1RealTime_M->Timing.clockTickH0;
  }

  Design1RealTime_M->Timing.t[0] = Design1RealTime_M->Timing.clockTick0 *
    Design1RealTime_M->Timing.stepSize0 + Design1RealTime_M->Timing.clockTickH0 *
    Design1RealTime_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Design1RealTime_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Design1RealTime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Design1RealTime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Design1RealTime_P.AnalogOutput2_Channels,
                     &Design1RealTime_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<S2>/Encoder Input1' */

  /* S-Function Block: <S2>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = Design1RealTime_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &Design1RealTime_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space3' */
  Design1RealTime_DW.DiscreteStateSpace3_DSTATE =
    Design1RealTime_P.DiscreteStateSpace3_InitialCondition;
}

/* Model terminate function */
void Design1RealTime_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output2' */

  /* S-Function Block: <S2>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Design1RealTime_P.AnalogOutput2_RangeMode;
      parm.rangeidx = Design1RealTime_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Design1RealTime_P.AnalogOutput2_Channels,
                     &Design1RealTime_P.AnalogOutput2_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Design1RealTime_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Design1RealTime_update();
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
  Design1RealTime_initialize();
}

void MdlTerminate(void)
{
  Design1RealTime_terminate();
}

/* Registration function */
RT_MODEL_Design1RealTime_T *Design1RealTime(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Design1RealTime_M, 0,
                sizeof(RT_MODEL_Design1RealTime_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Design1RealTime_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Design1RealTime_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Design1RealTime_M->Timing.sampleTimes =
      (&Design1RealTime_M->Timing.sampleTimesArray[0]);
    Design1RealTime_M->Timing.offsetTimes =
      (&Design1RealTime_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Design1RealTime_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Design1RealTime_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Design1RealTime_M, &Design1RealTime_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Design1RealTime_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Design1RealTime_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Design1RealTime_M, 5.0);
  Design1RealTime_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Design1RealTime_M->Sizes.checksums[0] = (1853761768U);
  Design1RealTime_M->Sizes.checksums[1] = (1637156994U);
  Design1RealTime_M->Sizes.checksums[2] = (3438819941U);
  Design1RealTime_M->Sizes.checksums[3] = (3787529067U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Design1RealTime_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Design1RealTime_M->extModeInfo,
      &Design1RealTime_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Design1RealTime_M->extModeInfo,
                        Design1RealTime_M->Sizes.checksums);
    rteiSetTPtr(Design1RealTime_M->extModeInfo, rtmGetTPtr(Design1RealTime_M));
  }

  Design1RealTime_M->solverInfoPtr = (&Design1RealTime_M->solverInfo);
  Design1RealTime_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Design1RealTime_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Design1RealTime_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Design1RealTime_M->blockIO = ((void *) &Design1RealTime_B);
  (void) memset(((void *) &Design1RealTime_B), 0,
                sizeof(B_Design1RealTime_T));

  /* parameters */
  Design1RealTime_M->defaultParam = ((real_T *)&Design1RealTime_P);

  /* states (dwork) */
  Design1RealTime_M->dwork = ((void *) &Design1RealTime_DW);
  (void) memset((void *)&Design1RealTime_DW, 0,
                sizeof(DW_Design1RealTime_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Design1RealTime_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Design1RealTime_M->Sizes.numContStates = (0);/* Number of continuous states */
  Design1RealTime_M->Sizes.numY = (0); /* Number of model outputs */
  Design1RealTime_M->Sizes.numU = (0); /* Number of model inputs */
  Design1RealTime_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Design1RealTime_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Design1RealTime_M->Sizes.numBlocks = (15);/* Number of blocks */
  Design1RealTime_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  Design1RealTime_M->Sizes.numBlockPrms = (31);/* Sum of parameter "widths" */
  return Design1RealTime_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
