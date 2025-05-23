/*
 * realtime_motor.h
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

#ifndef realtime_motor_h_
#define realtime_motor_h_
#ifndef realtime_motor_COMMON_INCLUDES_
#define realtime_motor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* realtime_motor_COMMON_INCLUDES_ */

#include "realtime_motor_types.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include <string.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetProxyFunctions
#define rtmGetProxyFunctions(rtm)      ()
#endif

#ifndef rtmSetProxyFunctions
#define rtmSetProxyFunctions(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStubFunctions
#define rtmGetStubFunctions(rtm)       ()
#endif

#ifndef rtmSetStubFunctions
#define rtmSetStubFunctions(rtm, val)  ()
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define realtime_motor_rtModel         RT_MODEL_realtime_motor_T

/* Block signals (default storage) */
typedef struct {
  real_T th_l_measdeg;                 /* '<Root>/Gain' */
  real_T Gain8;                        /* '<S4>/Gain8' */
  real_T filterediaA;                  /* '<S3>/ Current filter' */
  real_T a_mradss;                     /* '<S4>/Filtering derivative 2' */
  real_T Torqueconst;                  /* '<S3>/Torque const' */
  real_T tau_i_hat;                    /* '<S5>/Subtract1' */
  real_T w_mkrpm;                      /* '<S4>/1//k1' */
  real_T ia;                           /* '<Root>/Gain1' */
  real_T w_l_refdegs;                  /* '<Root>/Gain4' */
  real_T w_l_refdegs_i;                /* '<Root>/Gain5' */
  real_T Sum3;                         /* '<S1>/Sum3' */
  real_T Kd;                           /* '<S2>/Kd' */
  real_T Ki;                           /* '<S2>/Ki' */
  real_T w_mrads;                      /* '<S4>/Gain1' */
  uint8_T FixPtSwitch;                 /* '<S11>/FixPt Switch' */
  uint8_T FixPtSwitch_g;               /* '<S14>/FixPt Switch' */
} B_realtime_motor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  void *EncoderInput2_PWORK;           /* '<Root>/Encoder Input2' */
  void *AnalogInput1_PWORK;            /* '<Root>/Analog Input1' */
  void *AnalogOutput1_PWORK;           /* '<Root>/Analog Output1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<Root>/To Workspace4' */

  struct {
    void *LoggedData;
  } ToWorkspace5_PWORK;                /* '<Root>/To Workspace5' */

  struct {
    void *LoggedData;
  } filt_ia_PWORK;                     /* '<S3>/filt_ia' */

  struct {
    void *LoggedData;
  } tau_m_PWORK;                       /* '<S3>/tau_m' */

  struct {
    void *LoggedData;
  } _PWORK;                            /* '<S4>/  ' */

  struct {
    void *LoggedData;
  } _PWORK_k;                          /* '<S4>/    ' */

  int32_T clockTickCounter;            /* '<S1>/Pulse Generator3' */
  int32_T clockTickCounter_n;          /* '<S1>/Pulse Generator2' */
  uint8_T Output_DSTATE;               /* '<S9>/Output' */
  uint8_T Output_DSTATE_m;             /* '<S12>/Output' */
} DW_realtime_motor_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE_n;          /* '<S2>/Integrator' */
  real_T derivative_CSTATE;            /* '<S2>/derivative' */
  real_T Filteringderivative_CSTATE[2];/* '<S4>/Filtering derivative' */
  real_T Currentfilter_CSTATE[2];      /* '<S3>/ Current filter' */
  real_T Filteringderivative2_CSTATE[2];/* '<S4>/Filtering derivative 2' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} X_realtime_motor_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE_n;          /* '<S2>/Integrator' */
  real_T derivative_CSTATE;            /* '<S2>/derivative' */
  real_T Filteringderivative_CSTATE[2];/* '<S4>/Filtering derivative' */
  real_T Currentfilter_CSTATE[2];      /* '<S3>/ Current filter' */
  real_T Filteringderivative2_CSTATE[2];/* '<S4>/Filtering derivative 2' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} XDot_realtime_motor_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE_n;       /* '<S2>/Integrator' */
  boolean_T derivative_CSTATE;         /* '<S2>/derivative' */
  boolean_T Filteringderivative_CSTATE[2];/* '<S4>/Filtering derivative' */
  boolean_T Currentfilter_CSTATE[2];   /* '<S3>/ Current filter' */
  boolean_T Filteringderivative2_CSTATE[2];/* '<S4>/Filtering derivative 2' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
} XDis_realtime_motor_T;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            realtime_motor_B
#define BlockIO                        B_realtime_motor_T
#define rtX                            realtime_motor_X
#define ContinuousStates               X_realtime_motor_T
#define rtXdot                         realtime_motor_XDot
#define StateDerivatives               XDot_realtime_motor_T
#define tXdis                          realtime_motor_XDis
#define StateDisabled                  XDis_realtime_motor_T
#define rtP                            realtime_motor_P
#define Parameters                     P_realtime_motor_T
#define rtDWork                        realtime_motor_DW
#define D_Work                         DW_realtime_motor_T

/* Parameters (default storage) */
struct P_realtime_motor_T_ {
  struct_8LnTg2HasR61N4e63tMdJ sens;   /* Variable: sens
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain1'
                                        */
  struct_eFa2IcKK1O06MO9fwndwyD mot;   /* Variable: mot
                                        * Referenced by: '<S3>/Torque const'
                                        */
  struct_tqEcQv8wI4rPb7WqAAnbuH gbox;  /* Variable: gbox
                                        * Referenced by:
                                        *   '<S4>/N1'
                                        *   '<S5>/Gain6'
                                        */
  real_T Beq;                          /* Variable: Beq
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S2>/Kd'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S2>/Ki'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S2>/Kp'
                                        */
  real_T deg2rad;                      /* Variable: deg2rad
                                        * Referenced by: '<S2>/deg2rad'
                                        */
  real_T degs2rpm;                     /* Variable: degs2rpm
                                        * Referenced by: '<S4>/ '
                                        */
  real_T rpm2degs;                     /* Variable: rpm2degs
                                        * Referenced by:
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain5'
                                        */
  real_T rpm2rads;                     /* Variable: rpm2rads
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S4>/Gain8'
                                        */
  real_T tau_sf;                       /* Variable: tau_sf
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T AnalogOutput1_FinalValue;   /* Mask Parameter: AnalogOutput1_FinalValue
                                      * Referenced by: '<Root>/Analog Output1'
                                      */
  real_T AnalogOutput1_InitialValue;
                                   /* Mask Parameter: AnalogOutput1_InitialValue
                                    * Referenced by: '<Root>/Analog Output1'
                                    */
  real_T EncoderInput2_InputFilter; /* Mask Parameter: EncoderInput2_InputFilter
                                     * Referenced by: '<Root>/Encoder Input2'
                                     */
  real_T EncoderInput2_MaxMissedTicks;
                                 /* Mask Parameter: EncoderInput2_MaxMissedTicks
                                  * Referenced by: '<Root>/Encoder Input2'
                                  */
  real_T AnalogInput1_MaxMissedTicks;
                                  /* Mask Parameter: AnalogInput1_MaxMissedTicks
                                   * Referenced by: '<Root>/Analog Input1'
                                   */
  real_T AnalogOutput1_MaxMissedTicks;
                                 /* Mask Parameter: AnalogOutput1_MaxMissedTicks
                                  * Referenced by: '<Root>/Analog Output1'
                                  */
  real_T RepeatingSequenceStair_OutValues[10];
                             /* Mask Parameter: RepeatingSequenceStair_OutValues
                              * Referenced by: '<S7>/Vector'
                              */
  real_T RepeatingSequenceStair1_OutValues[10];
                            /* Mask Parameter: RepeatingSequenceStair1_OutValues
                             * Referenced by: '<S8>/Vector'
                             */
  real_T EncoderInput2_YieldWhenWaiting;
                               /* Mask Parameter: EncoderInput2_YieldWhenWaiting
                                * Referenced by: '<Root>/Encoder Input2'
                                */
  real_T AnalogInput1_YieldWhenWaiting;
                                /* Mask Parameter: AnalogInput1_YieldWhenWaiting
                                 * Referenced by: '<Root>/Analog Input1'
                                 */
  real_T AnalogOutput1_YieldWhenWaiting;
                               /* Mask Parameter: AnalogOutput1_YieldWhenWaiting
                                * Referenced by: '<Root>/Analog Output1'
                                */
  int32_T EncoderInput2_Channels;      /* Mask Parameter: EncoderInput2_Channels
                                        * Referenced by: '<Root>/Encoder Input2'
                                        */
  int32_T AnalogInput1_Channels[2];    /* Mask Parameter: AnalogInput1_Channels
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T AnalogOutput1_Channels;      /* Mask Parameter: AnalogOutput1_Channels
                                        * Referenced by: '<Root>/Analog Output1'
                                        */
  int32_T AnalogInput1_RangeMode;      /* Mask Parameter: AnalogInput1_RangeMode
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T AnalogOutput1_RangeMode;    /* Mask Parameter: AnalogOutput1_RangeMode
                                       * Referenced by: '<Root>/Analog Output1'
                                       */
  int32_T AnalogInput1_VoltRange;      /* Mask Parameter: AnalogInput1_VoltRange
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  int32_T AnalogOutput1_VoltRange;    /* Mask Parameter: AnalogOutput1_VoltRange
                                       * Referenced by: '<Root>/Analog Output1'
                                       */
  uint8_T WrapToZero_Threshold;        /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S11>/FixPt Switch'
                                        */
  uint8_T WrapToZero_Threshold_e;      /* Mask Parameter: WrapToZero_Threshold_e
                                        * Referenced by: '<S14>/FixPt Switch'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T derivative_A;                 /* Computed Parameter: derivative_A
                                        * Referenced by: '<S2>/derivative'
                                        */
  real_T derivative_C;                 /* Computed Parameter: derivative_C
                                        * Referenced by: '<S2>/derivative'
                                        */
  real_T u0_UpperSat;                  /* Expression: 10
                                        * Referenced by: '<S2>/+-10'
                                        */
  real_T u0_LowerSat;                  /* Expression: -10
                                        * Referenced by: '<S2>/+-10'
                                        */
  real_T Filteringderivative_A[2];  /* Computed Parameter: Filteringderivative_A
                                     * Referenced by: '<S4>/Filtering derivative'
                                     */
  real_T Filteringderivative_C[2];  /* Computed Parameter: Filteringderivative_C
                                     * Referenced by: '<S4>/Filtering derivative'
                                     */
  real_T Currentfilter_A[2];           /* Computed Parameter: Currentfilter_A
                                        * Referenced by: '<S3>/ Current filter'
                                        */
  real_T Currentfilter_C[2];           /* Computed Parameter: Currentfilter_C
                                        * Referenced by: '<S3>/ Current filter'
                                        */
  real_T Filteringderivative2_A[2];/* Computed Parameter: Filteringderivative2_A
                                    * Referenced by: '<S4>/Filtering derivative 2'
                                    */
  real_T Filteringderivative2_C[2];/* Computed Parameter: Filteringderivative2_C
                                    * Referenced by: '<S4>/Filtering derivative 2'
                                    */
  real_T uk1_Gain;                     /* Expression: 1/1000
                                        * Referenced by: '<S4>/1//k1'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T PulseGenerator3_Amp;          /* Expression: 450
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Period;   /* Computed Parameter: PulseGenerator3_Period
                                    * Referenced by: '<S1>/Pulse Generator3'
                                    */
  real_T PulseGenerator3_Duty;       /* Computed Parameter: PulseGenerator3_Duty
                                      * Referenced by: '<S1>/Pulse Generator3'
                                      */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator3'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 450
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;   /* Computed Parameter: PulseGenerator2_Period
                                    * Referenced by: '<S1>/Pulse Generator2'
                                    */
  real_T PulseGenerator2_Duty;       /* Computed Parameter: PulseGenerator2_Duty
                                      * Referenced by: '<S1>/Pulse Generator2'
                                      */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator2'
                                        */
  real_T uk2_Gain;                     /* Expression: 1000
                                        * Referenced by: '<S4>/1//k2'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S14>/Constant'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S9>/Output'
                                   */
  uint8_T Output_InitialCondition_d;
                                /* Computed Parameter: Output_InitialCondition_d
                                 * Referenced by: '<S12>/Output'
                                 */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S10>/FixPt Constant'
                                       */
  uint8_T FixPtConstant_Value_m;    /* Computed Parameter: FixPtConstant_Value_m
                                     * Referenced by: '<S13>/FixPt Constant'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_realtime_motor_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[11];
  real_T odeF[6][11];
  ODE5_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_realtime_motor_T realtime_motor_P;

/* Block signals (default storage) */
extern B_realtime_motor_T realtime_motor_B;

/* Continuous states (default storage) */
extern X_realtime_motor_T realtime_motor_X;

/* Disabled states (default storage) */
extern XDis_realtime_motor_T realtime_motor_XDis;

/* Block states (default storage) */
extern DW_realtime_motor_T realtime_motor_DW;

/* Model entry point functions */
extern void realtime_motor_initialize(void);
extern void realtime_motor_output(void);
extern void realtime_motor_update(void);
extern void realtime_motor_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern realtime_motor_rtModel *realtime_motor(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_realtime_motor_T *const realtime_motor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'realtime_motor'
 * '<S1>'   : 'realtime_motor/Inertia estimation reference'
 * '<S2>'   : 'realtime_motor/PID1'
 * '<S3>'   : 'realtime_motor/Subsystem'
 * '<S4>'   : 'realtime_motor/Subsystem1'
 * '<S5>'   : 'realtime_motor/Subsystem2'
 * '<S6>'   : 'realtime_motor/w_l_ref [rpm]'
 * '<S7>'   : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair'
 * '<S8>'   : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair1'
 * '<S9>'   : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair/LimitedCounter'
 * '<S10>'  : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S11>'  : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S12>'  : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair1/LimitedCounter'
 * '<S13>'  : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S14>'  : 'realtime_motor/w_l_ref [rpm]/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* realtime_motor_h_ */
