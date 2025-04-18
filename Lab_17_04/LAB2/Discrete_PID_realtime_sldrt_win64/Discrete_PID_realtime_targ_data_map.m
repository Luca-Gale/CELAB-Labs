    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Discrete_PID_realtime_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.sens
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 28;
            section.data(28)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.B_C
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_P.Beq
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_P.F_C
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_P.I_C
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_P.Kd
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_P.Ki
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% Discrete_PID_realtime_P.Kp
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% Discrete_PID_realtime_P.Kw
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% Discrete_PID_realtime_P.deg2rad
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% Discrete_PID_realtime_P.den
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% Discrete_PID_realtime_P.den_EX
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 11;

                    ;% Discrete_PID_realtime_P.den_FE
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 14;

                    ;% Discrete_PID_realtime_P.den_T
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 17;

                    ;% Discrete_PID_realtime_P.num
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 20;

                    ;% Discrete_PID_realtime_P.num_EX
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 22;

                    ;% Discrete_PID_realtime_P.num_FE
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 25;

                    ;% Discrete_PID_realtime_P.num_T
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 28;

                    ;% Discrete_PID_realtime_P.rad2deg
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 31;

                    ;% Discrete_PID_realtime_P.rpm2rads
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 32;

                    ;% Discrete_PID_realtime_P.tau_sf
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 33;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_FinalValue
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 34;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_InitialValue
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 35;

                    ;% Discrete_PID_realtime_P.EncoderInput1_InputFilter
                    section.data(23).logicalSrcIdx = 23;
                    section.data(23).dtTransOffset = 36;

                    ;% Discrete_PID_realtime_P.EncoderInput1_MaxMissedTicks
                    section.data(24).logicalSrcIdx = 24;
                    section.data(24).dtTransOffset = 37;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_MaxMissedTicks
                    section.data(25).logicalSrcIdx = 25;
                    section.data(25).dtTransOffset = 38;

                    ;% Discrete_PID_realtime_P.a_l_refrpms_OutValues
                    section.data(26).logicalSrcIdx = 26;
                    section.data(26).dtTransOffset = 39;

                    ;% Discrete_PID_realtime_P.EncoderInput1_YieldWhenWaiting
                    section.data(27).logicalSrcIdx = 27;
                    section.data(27).dtTransOffset = 45;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_YieldWhenWaiting
                    section.data(28).logicalSrcIdx = 28;
                    section.data(28).dtTransOffset = 46;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.EncoderInput1_Channels
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_Channels
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_RangeMode
                    section.data(3).logicalSrcIdx = 31;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_P.AnalogOutput2_VoltRange
                    section.data(4).logicalSrcIdx = 32;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.WrapToZero_Threshold
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator_gainval
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator_IC
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_P.th_l_refdeg1_Time
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_P.th_l_refdeg1_Y0
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_P.th_l_refdeg1_YFinal
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_P.UnitDelay_InitialCondition
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 5;

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator_gainval_g
                    section.data(7).logicalSrcIdx = 40;
                    section.data(7).dtTransOffset = 6;

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator_IC_a
                    section.data(8).logicalSrcIdx = 41;
                    section.data(8).dtTransOffset = 7;

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator1_gainval
                    section.data(9).logicalSrcIdx = 42;
                    section.data(9).dtTransOffset = 8;

                    ;% Discrete_PID_realtime_P.DiscreteTimeIntegrator1_IC
                    section.data(10).logicalSrcIdx = 43;
                    section.data(10).dtTransOffset = 9;

                    ;% Discrete_PID_realtime_P.Constant_Value
                    section.data(11).logicalSrcIdx = 44;
                    section.data(11).dtTransOffset = 10;

                    ;% Discrete_PID_realtime_P.TustinPID_InitialStates
                    section.data(12).logicalSrcIdx = 45;
                    section.data(12).dtTransOffset = 11;

                    ;% Discrete_PID_realtime_P.DiscreteTransferFcn_InitialStates
                    section.data(13).logicalSrcIdx = 46;
                    section.data(13).dtTransOffset = 12;

                    ;% Discrete_PID_realtime_P.u0_UpperSat
                    section.data(14).logicalSrcIdx = 47;
                    section.data(14).dtTransOffset = 13;

                    ;% Discrete_PID_realtime_P.u0_LowerSat
                    section.data(15).logicalSrcIdx = 48;
                    section.data(15).dtTransOffset = 14;

                    ;% Discrete_PID_realtime_P.ForwardEulerPID_InitialStates
                    section.data(16).logicalSrcIdx = 49;
                    section.data(16).dtTransOffset = 15;

                    ;% Discrete_PID_realtime_P.ExactmethodPID_InitialStates
                    section.data(17).logicalSrcIdx = 50;
                    section.data(17).dtTransOffset = 16;

                    ;% Discrete_PID_realtime_P.Gain7_Gain
                    section.data(18).logicalSrcIdx = 51;
                    section.data(18).dtTransOffset = 17;

                    ;% Discrete_PID_realtime_P.Gain9_Gain
                    section.data(19).logicalSrcIdx = 52;
                    section.data(19).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_P.Constant_Value_g
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_P.ManualSwitch3_CurrentSetting
                    section.data(2).logicalSrcIdx = 54;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_P.ManualSwitch_CurrentSetting
                    section.data(3).logicalSrcIdx = 55;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_P.Output_InitialCondition
                    section.data(4).logicalSrcIdx = 56;
                    section.data(4).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_P.ManualSwitch2_CurrentSetting
                    section.data(5).logicalSrcIdx = 57;
                    section.data(5).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_P.FixPtConstant_Value
                    section.data(6).logicalSrcIdx = 58;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Discrete_PID_realtime_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_B.th_l_refdeg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_B.output_ref
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_B.output_thl
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_B.ZeroOrderHold
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_B.Sum2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_B.DiscreteTimeIntegrator
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% Discrete_PID_realtime_B.Out
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% Discrete_PID_realtime_B.w_l_refrads
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% Discrete_PID_realtime_B.Inertiacompensator
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% Discrete_PID_realtime_B.Sum11
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% Discrete_PID_realtime_B.ManualSwitch2
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

                    ;% Discrete_PID_realtime_B.u_perc
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% Discrete_PID_realtime_B.u5_perc
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% Discrete_PID_realtime_B.Sum1
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_B.FixPtSwitch
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Discrete_PID_realtime_DW)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_DW.UnitDelay_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_DW.DiscreteTimeIntegrator_DSTATE_g
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Discrete_PID_realtime_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_DW.TustinPID_states
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_DW.DiscreteTransferFcn_states
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% Discrete_PID_realtime_DW.ForwardEulerPID_states
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% Discrete_PID_realtime_DW.ExactmethodPID_states
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% Discrete_PID_realtime_DW.TustinPID_tmp
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% Discrete_PID_realtime_DW.DiscreteTransferFcn_tmp
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% Discrete_PID_realtime_DW.ForwardEulerPID_tmp
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% Discrete_PID_realtime_DW.ExactmethodPID_tmp
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_DW.EncoderInput1_PWORK
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Discrete_PID_realtime_DW._PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% Discrete_PID_realtime_DW.a_l_refrpms_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 3;

                    ;% Discrete_PID_realtime_DW.th_l_refdeg_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 4;

                    ;% Discrete_PID_realtime_DW.w_l_refrads_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 5;

                    ;% Discrete_PID_realtime_DW.AnalogOutput2_PWORK
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 6;

                    ;% Discrete_PID_realtime_DW.ControllerTesting_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 7;

                    ;% Discrete_PID_realtime_DW.Scope7_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 10;

                    ;% Discrete_PID_realtime_DW.TAQSigLogging_InsertedFor_pulse2deg1_at_outport_0_PWORK.AQHandles
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 11;

                    ;% Discrete_PID_realtime_DW.ToWorkspace_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Discrete_PID_realtime_DW.Output_DSTATE
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 131830696;
    targMap.checksum1 = 3035023542;
    targMap.checksum2 = 1235585624;
    targMap.checksum3 = 67701463;

