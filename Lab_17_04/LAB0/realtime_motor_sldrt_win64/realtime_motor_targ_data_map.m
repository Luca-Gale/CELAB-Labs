    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
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
        ;% Auto data (realtime_motor_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime_motor_P.sens
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime_motor_P.mot
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% realtime_motor_P.gbox
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% realtime_motor_P.Beq
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_P.Kd
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_P.Ki
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime_motor_P.Kp
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime_motor_P.deg2rad
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime_motor_P.degs2rpm
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime_motor_P.rpm2degs
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime_motor_P.rpm2rads
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime_motor_P.tau_sf
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime_motor_P.AnalogOutput1_FinalValue
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime_motor_P.AnalogOutput1_InitialValue
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime_motor_P.EncoderInput2_InputFilter
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% realtime_motor_P.EncoderInput2_MaxMissedTicks
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% realtime_motor_P.AnalogInput1_MaxMissedTicks
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 13;

                    ;% realtime_motor_P.AnalogOutput1_MaxMissedTicks
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 14;

                    ;% realtime_motor_P.RepeatingSequenceStair_OutValues
                    section.data(16).logicalSrcIdx = 18;
                    section.data(16).dtTransOffset = 15;

                    ;% realtime_motor_P.RepeatingSequenceStair1_OutValues
                    section.data(17).logicalSrcIdx = 19;
                    section.data(17).dtTransOffset = 25;

                    ;% realtime_motor_P.EncoderInput2_YieldWhenWaiting
                    section.data(18).logicalSrcIdx = 20;
                    section.data(18).dtTransOffset = 35;

                    ;% realtime_motor_P.AnalogInput1_YieldWhenWaiting
                    section.data(19).logicalSrcIdx = 21;
                    section.data(19).dtTransOffset = 36;

                    ;% realtime_motor_P.AnalogOutput1_YieldWhenWaiting
                    section.data(20).logicalSrcIdx = 22;
                    section.data(20).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% realtime_motor_P.EncoderInput2_Channels
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_P.AnalogInput1_Channels
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_P.AnalogOutput1_Channels
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 3;

                    ;% realtime_motor_P.AnalogInput1_RangeMode
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 4;

                    ;% realtime_motor_P.AnalogOutput1_RangeMode
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 5;

                    ;% realtime_motor_P.AnalogInput1_VoltRange
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 6;

                    ;% realtime_motor_P.AnalogOutput1_VoltRange
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtime_motor_P.WrapToZero_Threshold
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_P.WrapToZero_Threshold_e
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 26;
            section.data(26)  = dumData; %prealloc

                    ;% realtime_motor_P.Gain2_Gain
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_P.Integrator_IC
                    section.data(2).logicalSrcIdx = 33;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_P.Integrator2_IC
                    section.data(3).logicalSrcIdx = 34;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime_motor_P.Integrator_IC_p
                    section.data(4).logicalSrcIdx = 35;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime_motor_P.derivative_A
                    section.data(5).logicalSrcIdx = 36;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime_motor_P.derivative_C
                    section.data(6).logicalSrcIdx = 37;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime_motor_P.u0_UpperSat
                    section.data(7).logicalSrcIdx = 38;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime_motor_P.u0_LowerSat
                    section.data(8).logicalSrcIdx = 39;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime_motor_P.Filteringderivative_A
                    section.data(9).logicalSrcIdx = 40;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime_motor_P.Filteringderivative_C
                    section.data(10).logicalSrcIdx = 41;
                    section.data(10).dtTransOffset = 10;

                    ;% realtime_motor_P.Currentfilter_A
                    section.data(11).logicalSrcIdx = 42;
                    section.data(11).dtTransOffset = 12;

                    ;% realtime_motor_P.Currentfilter_C
                    section.data(12).logicalSrcIdx = 43;
                    section.data(12).dtTransOffset = 14;

                    ;% realtime_motor_P.Filteringderivative2_A
                    section.data(13).logicalSrcIdx = 44;
                    section.data(13).dtTransOffset = 16;

                    ;% realtime_motor_P.Filteringderivative2_C
                    section.data(14).logicalSrcIdx = 45;
                    section.data(14).dtTransOffset = 18;

                    ;% realtime_motor_P.uk1_Gain
                    section.data(15).logicalSrcIdx = 46;
                    section.data(15).dtTransOffset = 20;

                    ;% realtime_motor_P.Integrator1_IC
                    section.data(16).logicalSrcIdx = 47;
                    section.data(16).dtTransOffset = 21;

                    ;% realtime_motor_P.PulseGenerator3_Amp
                    section.data(17).logicalSrcIdx = 48;
                    section.data(17).dtTransOffset = 22;

                    ;% realtime_motor_P.PulseGenerator3_Period
                    section.data(18).logicalSrcIdx = 49;
                    section.data(18).dtTransOffset = 23;

                    ;% realtime_motor_P.PulseGenerator3_Duty
                    section.data(19).logicalSrcIdx = 50;
                    section.data(19).dtTransOffset = 24;

                    ;% realtime_motor_P.PulseGenerator3_PhaseDelay
                    section.data(20).logicalSrcIdx = 51;
                    section.data(20).dtTransOffset = 25;

                    ;% realtime_motor_P.Gain5_Gain
                    section.data(21).logicalSrcIdx = 52;
                    section.data(21).dtTransOffset = 26;

                    ;% realtime_motor_P.PulseGenerator2_Amp
                    section.data(22).logicalSrcIdx = 53;
                    section.data(22).dtTransOffset = 27;

                    ;% realtime_motor_P.PulseGenerator2_Period
                    section.data(23).logicalSrcIdx = 54;
                    section.data(23).dtTransOffset = 28;

                    ;% realtime_motor_P.PulseGenerator2_Duty
                    section.data(24).logicalSrcIdx = 55;
                    section.data(24).dtTransOffset = 29;

                    ;% realtime_motor_P.PulseGenerator2_PhaseDelay
                    section.data(25).logicalSrcIdx = 56;
                    section.data(25).dtTransOffset = 30;

                    ;% realtime_motor_P.uk2_Gain
                    section.data(26).logicalSrcIdx = 57;
                    section.data(26).dtTransOffset = 31;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% realtime_motor_P.Constant_Value
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_P.Constant_Value_h
                    section.data(2).logicalSrcIdx = 59;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_P.ManualSwitch1_CurrentSetting
                    section.data(3).logicalSrcIdx = 60;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime_motor_P.Output_InitialCondition
                    section.data(4).logicalSrcIdx = 61;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime_motor_P.Output_InitialCondition_d
                    section.data(5).logicalSrcIdx = 62;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime_motor_P.ManualSwitch_CurrentSetting
                    section.data(6).logicalSrcIdx = 63;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime_motor_P.FixPtConstant_Value
                    section.data(7).logicalSrcIdx = 64;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime_motor_P.FixPtConstant_Value_m
                    section.data(8).logicalSrcIdx = 65;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
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
        ;% Auto data (realtime_motor_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% realtime_motor_B.th_l_measdeg
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_B.Gain8
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_B.filterediaA
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime_motor_B.a_mradss
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime_motor_B.Torqueconst
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime_motor_B.tau_i_hat
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime_motor_B.w_mkrpm
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime_motor_B.ia
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime_motor_B.w_l_refdegs
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime_motor_B.w_l_refdegs_i
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime_motor_B.Sum3
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime_motor_B.Kd
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% realtime_motor_B.Ki
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% realtime_motor_B.w_mrads
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtime_motor_B.FixPtSwitch
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_B.FixPtSwitch_g
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

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
        ;% Auto data (realtime_motor_DW)
        ;%
            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% realtime_motor_DW.EncoderInput2_PWORK
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_DW.AnalogInput1_PWORK
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% realtime_motor_DW.AnalogOutput1_PWORK
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% realtime_motor_DW.Scope_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% realtime_motor_DW.Scope1_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% realtime_motor_DW.Scope2_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% realtime_motor_DW.Scope3_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% realtime_motor_DW.Scope4_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% realtime_motor_DW.ToWorkspace_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% realtime_motor_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% realtime_motor_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% realtime_motor_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% realtime_motor_DW.ToWorkspace5_PWORK.LoggedData
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% realtime_motor_DW.filt_ia_PWORK.LoggedData
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% realtime_motor_DW.tau_m_PWORK.LoggedData
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% realtime_motor_DW._PWORK.LoggedData
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% realtime_motor_DW._PWORK_k.LoggedData
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtime_motor_DW.clockTickCounter
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_DW.clockTickCounter_n
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% realtime_motor_DW.Output_DSTATE
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% realtime_motor_DW.Output_DSTATE_m
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

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


    targMap.checksum0 = 2301158447;
    targMap.checksum1 = 953016269;
    targMap.checksum2 = 1953518815;
    targMap.checksum3 = 3720496040;

