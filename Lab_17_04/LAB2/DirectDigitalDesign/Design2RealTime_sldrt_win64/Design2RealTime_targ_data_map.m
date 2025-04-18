    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
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
        ;% Auto data (Design2RealTime_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Design2RealTime_P.sens
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Design2RealTime_P.Ao
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_P.Bo
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% Design2RealTime_P.Co
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 3;

                    ;% Design2RealTime_P.K
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 5;

                    ;% Design2RealTime_P.Nr
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 7;

                    ;% Design2RealTime_P.AnalogOutput2_FinalValue
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 8;

                    ;% Design2RealTime_P.AnalogOutput2_InitialValue
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 9;

                    ;% Design2RealTime_P.EncoderInput1_InputFilter
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 10;

                    ;% Design2RealTime_P.EncoderInput1_MaxMissedTicks
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 11;

                    ;% Design2RealTime_P.AnalogOutput2_MaxMissedTicks
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 12;

                    ;% Design2RealTime_P.EncoderInput1_YieldWhenWaiting
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 13;

                    ;% Design2RealTime_P.AnalogOutput2_YieldWhenWaiting
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Design2RealTime_P.EncoderInput1_Channels
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_P.AnalogOutput2_Channels
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% Design2RealTime_P.AnalogOutput2_RangeMode
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

                    ;% Design2RealTime_P.AnalogOutput2_VoltRange
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Design2RealTime_P.Gain1_Gain
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_P.Gain_Gain
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% Design2RealTime_P.DiscreteTimeIntegrator1_gainval
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% Design2RealTime_P.DiscreteTimeIntegrator1_IC
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

                    ;% Design2RealTime_P.Constant2_Value
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 4;

                    ;% Design2RealTime_P.Gain1_Gain_m
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 5;

                    ;% Design2RealTime_P.DiscreteStateSpace1_D
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 6;

                    ;% Design2RealTime_P.DiscreteStateSpace1_InitialCondition
                    section.data(8).logicalSrcIdx = 24;
                    section.data(8).dtTransOffset = 10;

                    ;% Design2RealTime_P.Gain5_Gain
                    section.data(9).logicalSrcIdx = 25;
                    section.data(9).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
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
        nTotSects     = 1;
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
        ;% Auto data (Design2RealTime_B)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Design2RealTime_B.Gain
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_B.DiscreteTimeIntegrator1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Design2RealTime_B.Sum3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Design2RealTime_B.TmpSignalConversionAtDiscreteStateSpace1Inport1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
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
        nTotSects     = 2;
        sectIdxOffset = 1;

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
        ;% Auto data (Design2RealTime_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Design2RealTime_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_DW.DiscreteStateSpace1_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Design2RealTime_DW.EncoderInput1_PWORK
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% Design2RealTime_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% Design2RealTime_DW.Scope1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% Design2RealTime_DW.TAQSigLogging_InsertedFor_RadianstoDegrees2_at_outport_0_PWORK.AQHandles
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% Design2RealTime_DW.AnalogOutput2_PWORK
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
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


    targMap.checksum0 = 3953096644;
    targMap.checksum1 = 3055395222;
    targMap.checksum2 = 781637683;
    targMap.checksum3 = 354909189;

