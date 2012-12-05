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

#include <stdafx.h>
#include <iConstDef.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 304
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

void
MCS::GuiHub::__write(::IceInternal::BasicStream* __os, ::MCS::GuiHub::GuiCommand v)
{
    __os->write(static_cast< ::Ice::Byte>(v), 10);
}

void
MCS::GuiHub::__read(::IceInternal::BasicStream* __is, ::MCS::GuiHub::GuiCommand& v)
{
    ::Ice::Byte val;
    __is->read(val, 10);
    v = static_cast< ::MCS::GuiHub::GuiCommand>(val);
}

void
MCS::GuiHub::__write(::IceInternal::BasicStream* __os, ::MCS::GuiHub::PushData v)
{
    __os->write(static_cast< ::Ice::Byte>(v), 4);
}

void
MCS::GuiHub::__read(::IceInternal::BasicStream* __is, ::MCS::GuiHub::PushData& v)
{
    ::Ice::Byte val;
    __is->read(val, 4);
    v = static_cast< ::MCS::GuiHub::PushData>(val);
}
