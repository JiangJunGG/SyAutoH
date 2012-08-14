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
// Generated from file `MesLink.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <stdafx.h>
#include <MesLink.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
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

static const ::std::string __MCS__MESLink__PlaceFoup_name = "PlaceFoup";

static const ::std::string __MCS__MESLink__PickFoup_name = "PickFoup";

::Ice::Object* IceInternal::upCast(::MCS::MESLink* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::MCS::MESLink* p) { return p; }

void
MCS::__read(::IceInternal::BasicStream* __is, ::MCS::MESLinkPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::MCS::MESLink;
        v->__copyFrom(proxy);
    }
}

::Ice::Int
IceProxy::MCS::MESLink::PlaceFoup(::Ice::Int FoupID, ::Ice::Int DevID, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__MCS__MESLink__PlaceFoup_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::MCS::MESLink* __del = dynamic_cast< ::IceDelegate::MCS::MESLink*>(__delBase.get());
            return __del->PlaceFoup(FoupID, DevID, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, true, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::MCS::MESLink::begin_PlaceFoup(::Ice::Int FoupID, ::Ice::Int DevID, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__MCS__MESLink__PlaceFoup_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __MCS__MESLink__PlaceFoup_name, __del, __cookie);
    try
    {
        __result->__prepare(__MCS__MESLink__PlaceFoup_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->__getOs();
        __os->write(FoupID);
        __os->write(DevID);
        __os->endWriteEncaps();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::Ice::Int
IceProxy::MCS::MESLink::end_PlaceFoup(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __MCS__MESLink__PlaceFoup_name);
    ::Ice::Int __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__getIs();
    __is->startReadEncaps();
    __is->read(__ret);
    __is->endReadEncaps();
    return __ret;
}

::Ice::Int
IceProxy::MCS::MESLink::PickFoup(::Ice::Int FoupId, ::Ice::Int DevID, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__MCS__MESLink__PickFoup_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::MCS::MESLink* __del = dynamic_cast< ::IceDelegate::MCS::MESLink*>(__delBase.get());
            return __del->PickFoup(FoupId, DevID, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, true, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::MCS::MESLink::begin_PickFoup(::Ice::Int FoupId, ::Ice::Int DevID, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__MCS__MESLink__PickFoup_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __MCS__MESLink__PickFoup_name, __del, __cookie);
    try
    {
        __result->__prepare(__MCS__MESLink__PickFoup_name, ::Ice::Idempotent, __ctx);
        ::IceInternal::BasicStream* __os = __result->__getOs();
        __os->write(FoupId);
        __os->write(DevID);
        __os->endWriteEncaps();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::Ice::Int
IceProxy::MCS::MESLink::end_PickFoup(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __MCS__MESLink__PickFoup_name);
    ::Ice::Int __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__getIs();
    __is->startReadEncaps();
    __is->read(__ret);
    __is->endReadEncaps();
    return __ret;
}

const ::std::string&
IceProxy::MCS::MESLink::ice_staticId()
{
    return ::MCS::MESLink::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::MCS::MESLink::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::MCS::MESLink);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::MCS::MESLink::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::MCS::MESLink);
}

::IceProxy::Ice::Object*
IceProxy::MCS::MESLink::__newInstance() const
{
    return new MESLink;
}

::Ice::Int
IceDelegateM::MCS::MESLink::PlaceFoup(::Ice::Int FoupID, ::Ice::Int DevID, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __MCS__MESLink__PlaceFoup_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(FoupID);
        __os->write(DevID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::MCS::MESLink::PickFoup(::Ice::Int FoupId, ::Ice::Int DevID, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __MCS__MESLink__PickFoup_name, ::Ice::Idempotent, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(FoupId);
        __os->write(DevID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateD::MCS::MESLink::PlaceFoup(::Ice::Int FoupID, ::Ice::Int DevID, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int FoupID, ::Ice::Int DevID, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_FoupID(FoupID),
            _m_DevID(DevID)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::MCS::MESLink* servant = dynamic_cast< ::MCS::MESLink*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->PlaceFoup(_m_FoupID, _m_DevID, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_FoupID;
        ::Ice::Int _m_DevID;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __MCS__MESLink__PlaceFoup_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, FoupID, DevID, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::Int
IceDelegateD::MCS::MESLink::PickFoup(::Ice::Int FoupId, ::Ice::Int DevID, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int FoupId, ::Ice::Int DevID, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_FoupId(FoupId),
            _m_DevID(DevID)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::MCS::MESLink* servant = dynamic_cast< ::MCS::MESLink*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->PickFoup(_m_FoupId, _m_DevID, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_FoupId;
        ::Ice::Int _m_DevID;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __MCS__MESLink__PickFoup_name, ::Ice::Idempotent, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, FoupId, DevID, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::ObjectPtr
MCS::MESLink::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __MCS__MESLink_ids[2] =
{
    "::Ice::Object",
    "::MCS::MESLink"
};

bool
MCS::MESLink::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__MCS__MESLink_ids, __MCS__MESLink_ids + 2, _s);
}

::std::vector< ::std::string>
MCS::MESLink::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__MCS__MESLink_ids[0], &__MCS__MESLink_ids[2]);
}

const ::std::string&
MCS::MESLink::ice_id(const ::Ice::Current&) const
{
    return __MCS__MESLink_ids[1];
}

const ::std::string&
MCS::MESLink::ice_staticId()
{
    return __MCS__MESLink_ids[1];
}

::Ice::DispatchStatus
MCS::MESLink::___PlaceFoup(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int FoupID;
    ::Ice::Int DevID;
    __is->read(FoupID);
    __is->read(DevID);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = PlaceFoup(FoupID, DevID, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

::Ice::DispatchStatus
MCS::MESLink::___PickFoup(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int FoupId;
    ::Ice::Int DevID;
    __is->read(FoupId);
    __is->read(DevID);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = PickFoup(FoupId, DevID, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

static ::std::string __MCS__MESLink_all[] =
{
    "PickFoup",
    "PlaceFoup",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
MCS::MESLink::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__MCS__MESLink_all, __MCS__MESLink_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __MCS__MESLink_all)
    {
        case 0:
        {
            return ___PickFoup(in, current);
        }
        case 1:
        {
            return ___PlaceFoup(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
MCS::MESLink::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
MCS::MESLink::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
void
MCS::MESLink::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type MCS::MESLink was not generated with stream support";
    throw ex;
}

void
MCS::MESLink::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type MCS::MESLink was not generated with stream support";
    throw ex;
}
#endif

void 
MCS::__patch__MESLinkPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::MCS::MESLinkPtr* p = static_cast< ::MCS::MESLinkPtr*>(__addr);
    assert(p);
    *p = ::MCS::MESLinkPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::MCS::MESLink::ice_staticId(), v->ice_id());
    }
}
