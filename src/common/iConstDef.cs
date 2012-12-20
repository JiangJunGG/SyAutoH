// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `iConstDef.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


using _System = global::System;
using _Microsoft = global::Microsoft;

#pragma warning disable 1591

namespace MCS
{
    namespace GuiHub
    {
        [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
        public enum GuiCommand
        {
            OhtPosTime,
            OhtStatusTime,
            OhtGetPosTable,
            OhtFoupHanding,
            OhtSetPath,
            OhtMove,
            OhtPathTest,
            OhtMoveTest,
            OhtFoupTest,
            StkHandFoup,
            StkInquiryStatus,
            StkInquiryPlace,
            StkInquiryFoup,
            StkInquiryEntryStatus,
            StkFoupHistory,
            StkAlarmHistory,
            StkSetStatusBackTime,
            StkSetFoupInfoBackTime
        }

        [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
        public enum PushData
        {
            upOhtInfo,
            upOhtPos,
            upOhtPosTable,
            upOhtStatus,
            upStkInfo,
            upFoupsTable
        }
    }
}

namespace MCS
{
    namespace GuiHub
    {
    }
}

namespace MCS
{
    namespace GuiHub
    {
        [_System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.4.2")]
        public sealed class GuiPushDataListHelper
        {
            public static void write(IceInternal.BasicStream os__, MCS.GuiHub.PushData[] v__)
            {
                if(v__ == null)
                {
                    os__.writeSize(0);
                }
                else
                {
                    os__.writeSize(v__.Length);
                    for(int ix__ = 0; ix__ < v__.Length; ++ix__)
                    {
                        os__.writeByte((byte)v__[ix__], 6);
                    }
                }
            }

            public static MCS.GuiHub.PushData[] read(IceInternal.BasicStream is__)
            {
                MCS.GuiHub.PushData[] v__;
                {
                    int szx__ = is__.readAndCheckSeqSize(1);
                    v__ = new MCS.GuiHub.PushData[szx__];
                    for(int ix__ = 0; ix__ < szx__; ++ix__)
                    {
                        v__[ix__] = (MCS.GuiHub.PushData)is__.readByte(6);
                    }
                }
                return v__;
            }
        }
    }
}
