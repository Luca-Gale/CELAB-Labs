/*
 * PID_real_time.c
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
#include "rtwtypes.h"
#include "PID_real_time_private.h"
#include <string.h>
#include "PID_real_time_dt.h"

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
B_PID_real_time_T PID_real_time_B;

/* Continuous states */
X_PID_real_time_T PID_real_time_X;

/* Disabled State Vector */
XDis_PID_real_time_T PID_real_time_XDis;

/* Block states (default storage) */
DW_PID_real_time_T PID_real_time_DW;

/* Real-time model */
static RT_MODEL_PID_real_time_T PID_real_time_M_;
RT_MODEL_PID_real_time_T *const PID_real_time_M = &PID_real_time_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PID_real_time_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PID_real_time_output();
  PID_real_time_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PID_real_time_output();
  PID_real_time_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void PID_real_time_output(void)
{
  real_T rtb_deg2rad;
  real_T rtb_u0;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(PID_real_time_M)) {
    /* set solver stop time */
    if (!(PID_real_time_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_real_time_M->solverInfo,
                            ((PID_real_time_M->Timing.clockTickH0 + 1) *
        PID_real_time_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_real_time_M->solverInfo,
                            ((PID_real_time_M->Timing.clockTick0 + 1) *
        PID_real_time_M->Timing.stepSize0 + PID_real_time_M->Timing.clockTickH0 *
        PID_real_time_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_real_time_M)) {
    PID_real_time_M->Timing.t[0] = rtsiGetT(&PID_real_time_M->solverInfo);
  }

  /* Step: '<Root>/degree-input step' */
  if (PID_real_time_M->Timing.t[0] < PID_real_time_P.degreeinputstep_Time) {
    /* Step: '<Root>/degree-input step' */
    PID_real_time_B.refdeg = PID_real_time_P.degreeinputstep_Y0;
  } else {
    /* Step: '<Root>/degree-input step' */
    PID_real_time_B.refdeg = PID_real_time_P.degreeinputstep_YFinal;
  }

  /* End of Step: '<Root>/degree-input step' */

  /* S-Function (sldrtei): '<Root>/Encoder Input1' */
  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = PID_real_time_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &PID_real_time_P.EncoderInput1_Channels, &rtb_deg2rad, &parm);
  }

  /* Gain: '<Root>/pulse2deg1' */
  PID_real_time_B.th_l_bbdeg = PID_real_time_P.sens.enc.pulse2deg * rtb_deg2rad;
  tmp = rtmIsMajorTimeStep(PID_real_time_M);
  if (tmp) {
  }

  /* Gain: '<S1>/deg2rad' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  rtb_deg2rad = (PID_real_time_B.refdeg - PID_real_time_B.th_l_bbdeg) *
    PID_real_time_P.deg2rad;

  /* Gain: '<S1>/Kd' */
  PID_real_time_B.Kd = PID_real_time_P.Kd * rtb_deg2rad;

  /* TransferFcn: '<S1>/derivative' */
  rtb_u0 = PID_real_time_P.derivative_C * PID_real_time_X.derivative_CSTATE;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Kp'
   *  Integrator: '<S1>/Integrator'
   *  TransferFcn: '<S1>/derivative'
   */
  rtb_u0 = (PID_real_time_P.Kp * rtb_deg2rad + PID_real_time_X.Integrator_CSTATE)
    + (PID_real_time_P.derivative_D * PID_real_time_B.Kd + rtb_u0);

  /* Saturate: '<S1>/+-10' */
  if (rtb_u0 > PID_real_time_P.u0_UpperSat) {
    rtb_u0 = PID_real_time_P.u0_UpperSat;
  } else if (rtb_u0 < PID_real_time_P.u0_LowerSat) {
    rtb_u0 = PID_real_time_P.u0_LowerSat;
  }

  /* End of Saturate: '<S1>/+-10' */

  /* S-Function (sldrtao): '<Root>/Analog Output2' */
  /* S-Function Block: <Root>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PID_real_time_P.AnalogOutput2_RangeMode;
      parm.rangeidx = PID_real_time_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PID_real_time_P.AnalogOutput2_Channels, ((real_T*)
        (&rtb_u0)), &parm);
    }
  }

  if (tmp) {
    /* Constant: '<Root>/Constant1' */
    PID_real_time_B.Constant1 = PID_real_time_P.Constant1_Value;

    /* Constant: '<Root>/Constant2' */
    PID_real_time_B.Constant2 = PID_real_time_P.Constant2_Value;

    /* ToAsyncQueueBlock generated from: '<Root>/degree-input step' */
    if (rtmIsMajorTimeStep(PID_real_time_M)) {
      {
        double time = PID_real_time_M->Timing.t[1];
        void *pData = (void *)&PID_real_time_B.refdeg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3118447439U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/pulse2deg1' */
    if (rtmIsMajorTimeStep(PID_real_time_M)) {
      {
        double time = PID_real_time_M->Timing.t[1];
        void *pData = (void *)&PID_real_time_B.th_l_bbdeg;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(593390768U, time, pData, size);
      }
    }
  }

  /* Gain: '<S1>/Ki' */
  PID_real_time_B.Ki = PID_real_time_P.Ki * rtb_deg2rad;
}

/* Model update function */
void PID_real_time_update(void)
{
  if (rtmIsMajorTimeStep(PID_real_time_M)) {
    rt_ertODEUpdateContinuousStates(&PID_real_time_M->solverInfo);
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
  if (!(++PID_real_time_M->Timing.clockTick0)) {
    ++PID_real_time_M->Timing.clockTickH0;
  }

  PID_real_time_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PID_real_time_M->solverInfo);

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
    if (!(++PID_real_time_M->Timing.clockTick1)) {
      ++PID_real_time_M->Timing.clockTickH1;
    }

    PID_real_time_M->Timing.t[1] = PID_real_time_M->Timing.clockTick1 *
      PID_real_time_M->Timing.stepSize1 + PID_real_time_M->Timing.clockTickH1 *
      PID_real_time_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PID_real_time_derivatives(void)
{
  XDot_PID_real_time_T *_rtXdot;
  _rtXdot = ((XDot_PID_real_time_T *) PID_real_time_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = PID_real_time_B.Ki;

  /* Derivatives for TransferFcn: '<S1>/derivative' */
  _rtXdot->derivative_CSTATE = PID_real_time_P.derivative_A *
    PID_real_time_X.derivative_CSTATE;
  _rtXdot->derivative_CSTATE += PID_real_time_B.Kd;
}

/* Model initialize function */
void PID_real_time_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output2' */

  /* S-Function Block: <Root>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PID_real_time_P.AnalogOutput2_RangeMode;
      parm.rangeidx = PID_real_time_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PID_real_time_P.AnalogOutput2_Channels,
                     &PID_real_time_P.AnalogOutput2_InitialValue, &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = PID_real_time_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &PID_real_time_P.EncoderInput1_Channels, NULL, &parm);
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  PID_real_time_X.Integrator_CSTATE = PID_real_time_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S1>/derivative' */
  PID_real_time_X.derivative_CSTATE = 0.0;
}

/* Model terminate function */
void PID_real_time_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output2' */

  /* S-Function Block: <Root>/Analog Output2 */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PID_real_time_P.AnalogOutput2_RangeMode;
      parm.rangeidx = PID_real_time_P.AnalogOutput2_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &PID_real_time_P.AnalogOutput2_Channels,
                     &PID_real_time_P.AnalogOutput2_FinalValue, &parm);
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
  PID_real_time_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PID_real_time_update();
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
  PID_real_time_initialize();
}

void MdlTerminate(void)
{
  PID_real_time_terminate();
}

/* Registration function */
RT_MODEL_PID_real_time_T *PID_real_time(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PID_real_time_M, 0,
                sizeof(RT_MODEL_PID_real_time_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_real_time_M->solverInfo,
                          &PID_real_time_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_real_time_M->solverInfo, &rtmGetTPtr(PID_real_time_M));
    rtsiSetStepSizePtr(&PID_real_time_M->solverInfo,
                       &PID_real_time_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_real_time_M->solverInfo, &PID_real_time_M->derivs);
    rtsiSetContStatesPtr(&PID_real_time_M->solverInfo, (real_T **)
                         &PID_real_time_M->contStates);
    rtsiSetNumContStatesPtr(&PID_real_time_M->solverInfo,
      &PID_real_time_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_real_time_M->solverInfo,
      &PID_real_time_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PID_real_time_M->solverInfo,
      &PID_real_time_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PID_real_time_M->solverInfo,
      &PID_real_time_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PID_real_time_M->solverInfo, (boolean_T**)
      &PID_real_time_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PID_real_time_M->solverInfo, (&rtmGetErrorStatus
      (PID_real_time_M)));
    rtsiSetRTModelPtr(&PID_real_time_M->solverInfo, PID_real_time_M);
  }

  rtsiSetSimTimeStep(&PID_real_time_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PID_real_time_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PID_real_time_M->solverInfo, false);
  PID_real_time_M->intgData.y = PID_real_time_M->odeY;
  PID_real_time_M->intgData.f[0] = PID_real_time_M->odeF[0];
  PID_real_time_M->intgData.f[1] = PID_real_time_M->odeF[1];
  PID_real_time_M->intgData.f[2] = PID_real_time_M->odeF[2];
  PID_real_time_M->contStates = ((real_T *) &PID_real_time_X);
  PID_real_time_M->contStateDisabled = ((boolean_T *) &PID_real_time_XDis);
  PID_real_time_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&PID_real_time_M->solverInfo, (void *)
                    &PID_real_time_M->intgData);
  rtsiSetSolverName(&PID_real_time_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PID_real_time_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PID_real_time_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PID_real_time_M->Timing.sampleTimes =
      (&PID_real_time_M->Timing.sampleTimesArray[0]);
    PID_real_time_M->Timing.offsetTimes =
      (&PID_real_time_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PID_real_time_M->Timing.sampleTimes[0] = (0.0);
    PID_real_time_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    PID_real_time_M->Timing.offsetTimes[0] = (0.0);
    PID_real_time_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PID_real_time_M, &PID_real_time_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PID_real_time_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PID_real_time_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PID_real_time_M, 5.0);
  PID_real_time_M->Timing.stepSize0 = 0.001;
  PID_real_time_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  PID_real_time_M->Sizes.checksums[0] = (3364025603U);
  PID_real_time_M->Sizes.checksums[1] = (2219348213U);
  PID_real_time_M->Sizes.checksums[2] = (64483537U);
  PID_real_time_M->Sizes.checksums[3] = (345369770U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PID_real_time_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PID_real_time_M->extModeInfo,
      &PID_real_time_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PID_real_time_M->extModeInfo,
                        PID_real_time_M->Sizes.checksums);
    rteiSetTPtr(PID_real_time_M->extModeInfo, rtmGetTPtr(PID_real_time_M));
  }

  PID_real_time_M->solverInfoPtr = (&PID_real_time_M->solverInfo);
  PID_real_time_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PID_real_time_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PID_real_time_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PID_real_time_M->blockIO = ((void *) &PID_real_time_B);
  (void) memset(((void *) &PID_real_time_B), 0,
                sizeof(B_PID_real_time_T));

  /* parameters */
  PID_real_time_M->defaultParam = ((real_T *)&PID_real_time_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PID_real_time_X;
    PID_real_time_M->contStates = (x);
    (void) memset((void *)&PID_real_time_X, 0,
                  sizeof(X_PID_real_time_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &PID_real_time_XDis;
    PID_real_time_M->contStateDisabled = (xdis);
    (void) memset((void *)&PID_real_time_XDis, 0,
                  sizeof(XDis_PID_real_time_T));
  }

  /* states (dwork) */
  PID_real_time_M->dwork = ((void *) &PID_real_time_DW);
  (void) memset((void *)&PID_real_time_DW, 0,
                sizeof(DW_PID_real_time_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PID_real_time_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PID_real_time_M->Sizes.numContStates = (2);/* Number of continuous states */
  PID_real_time_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PID_real_time_M->Sizes.numY = (0);   /* Number of model outputs */
  PID_real_time_M->Sizes.numU = (0);   /* Number of model inputs */
  PID_real_time_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PID_real_time_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PID_real_time_M->Sizes.numBlocks = (19);/* Number of blocks */
  PID_real_time_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  PID_real_time_M->Sizes.numBlockPrms = (27);/* Sum of parameter "widths" */
  return PID_real_time_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
