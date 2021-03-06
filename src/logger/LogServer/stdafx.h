#pragma once

// 以下宏定义要求的最低平台。要求的最低平台
// 是具有运行应用程序所需功能的 Windows、Internet Explorer 等产品的
// 最早版本。通过在指定版本及更低版本的平台上启用所有可用的功能，宏可以
// 正常工作。

// 如果必须要针对低于以下指定版本的平台，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER                          // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0600           // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT            // 指定要求的最低平台是 Windows Vista。
#define _WIN32_WINNT 0x0600     // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINDOWS          // 指定要求的最低平台是 Windows 98。
#define _WIN32_WINDOWS 0x0410 // 将此值更改为适当的值，以适用于 Windows Me 或更高版本。
#endif

#ifndef _WIN32_IE                       // 指定要求的最低平台是 Internet Explorer 7.0。
#define _WIN32_IE 0x0700        // 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif


//#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
//#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的
//
//#ifndef VC_EXTRALEAN
//#define VC_EXTRALEAN		// 从 Windows 头中排除极少使用的资料
//#endif
//
//#include <afx.h>
//#include <afxwin.h>         // MFC 核心组件和标准组件
//#include <afxext.h>         // MFC 扩展
//#ifndef _AFX_NO_OLE_SUPPORT
//#include <afxdtctl.h>		// MFC 对 Internet Explorer 4 公共控件的支持
//#endif
//#ifndef _AFX_NO_AFXCMN_SUPPORT
//#include <afxcmn.h>			// MFC 对 Windows 公共控件的支持
//#endif // _AFX_NO_AFXCMN_SUPPORT


#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件:
#include <windows.h>
#include <iostream>


// TODO: 在此处引用程序需要的其他头文件
# pragma warning (disable:4702)
# pragma warning (disable:4100)
# pragma warning (disable:4127)
# pragma warning (disable:4512)