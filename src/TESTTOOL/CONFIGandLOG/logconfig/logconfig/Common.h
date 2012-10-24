#ifndef SERVER_COMMON_H
#define SERVER_COMMON_H

/* Define these if you are creating a repack */

#ifdef WIN32
#pragma warning(disable:4996)
#pragma warning(disable:4251)		// dll-interface bullshit
#endif
#define snprintf _snprintf
#define ARCEMU_INLINE inline

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
#if defined( __WIN32__ ) || defined( WIN32 ) || defined( _WIN32 )
//#include <winsock2.h>
#include <ws2tcpip.h>
#endif
// current platform and compiler

#define PLATFORM_WIN32 0

#if defined( __WIN32__ ) || defined( WIN32 ) || defined( _WIN32 )
#define PLATFORM PLATFORM_WIN32
#endif

#define COMPILER_MICROSOFT 0
#define COMPILER_GNU	   1
#define COMPILER_BORLAND   2

#ifdef _MSC_VER
#define COMPILER COMPILER_MICROSOFT
#endif

#if PLATFORM == PLATFORM_WIN32
#define PLATFORM_TEXT "Win32"
#endif

#ifdef _DEBUG
#define CONFIG "Debug"
#else
#define CONFIG "Release"
#endif

#if PLATFORM == PLATFORM_WIN32
#define STRCASECMP stricmp
#else
#define STRCASECMP strcasecmp
#endif

#if PLATFORM == PLATFORM_WIN32
#define ASYNC_NET
#endif

#if COMPILER != COMPILER_GNU
typedef signed __int64 int64;
typedef signed __int32 int32;
typedef signed __int16 int16;
typedef signed __int8 int8;

typedef unsigned __int64 uint64;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;
typedef unsigned __int8 uint8;
#else
typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;
typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;
//typedef uint32_t DWORD;

#endif

#ifdef WIN32
#define SERVER_DECL __declspec(dllexport)
#endif

#endif
