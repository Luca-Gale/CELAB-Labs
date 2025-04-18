/*
 * realtime_motor_types.h
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

#ifndef realtime_motor_types_h_
#define realtime_motor_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_
#define DEFINED_TYPEDEF_FOR_struct_vHPMdAr9HfDgWNbG6U3SfC_

typedef struct {
  real_T Rs;
} struct_vHPMdAr9HfDgWNbG6U3SfC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_
#define DEFINED_TYPEDEF_FOR_struct_nZqFUEOh71pPhzsMP64FWD_

typedef struct {
  real_T ppr;
  real_T pulse2deg;
  real_T pulse2rad;
  real_T deg2pulse;
  real_T rad2pulse;
} struct_nZqFUEOh71pPhzsMP64FWD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_
#define DEFINED_TYPEDEF_FOR_struct_DqRrFctOcoTwJhkxMXTGZG_

typedef struct {
  real_T R;
  real_T V;
  real_T th_deg;
  real_T th;
} struct_DqRrFctOcoTwJhkxMXTGZG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_
#define DEFINED_TYPEDEF_FOR_struct_t4jfYKvXkqvqbOrnXV9flF_

typedef struct {
  struct_DqRrFctOcoTwJhkxMXTGZG range;
  real_T deg2V;
  real_T rad2V;
  real_T V2deg;
  real_T V2rad;
} struct_t4jfYKvXkqvqbOrnXV9flF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_
#define DEFINED_TYPEDEF_FOR_struct_8LnTg2HasR61N4e63tMdJ_

typedef struct {
  struct_vHPMdAr9HfDgWNbG6U3SfC curr;
  struct_nZqFUEOh71pPhzsMP64FWD enc;
  struct_t4jfYKvXkqvqbOrnXV9flF pot1;
} struct_8LnTg2HasR61N4e63tMdJ;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_eFa2IcKK1O06MO9fwndwyD_
#define DEFINED_TYPEDEF_FOR_struct_eFa2IcKK1O06MO9fwndwyD_

typedef struct {
  real_T R;
  real_T L;
  real_T Kt;
  real_T Ke;
  real_T J;
  real_T B;
  real_T eta;
  real_T PN;
  real_T UN;
  real_T IN;
  real_T tauN;
  real_T taus;
  real_T w0;
  real_T Req;
} struct_eFa2IcKK1O06MO9fwndwyD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_
#define DEFINED_TYPEDEF_FOR_struct_tqEcQv8wI4rPb7WqAAnbuH_

typedef struct {
  real_T N1;
  real_T eta1;
  real_T N2;
  real_T J72;
  real_T eta2;
  real_T N;
  real_T eta;
  real_T J;
} struct_tqEcQv8wI4rPb7WqAAnbuH;

#endif

/* Parameters (default storage) */
typedef struct P_realtime_motor_T_ P_realtime_motor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_realtime_motor_T RT_MODEL_realtime_motor_T;

#endif                                 /* realtime_motor_types_h_ */
