
// AMHSDeviceTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAMHSDeviceTestApp:
// �йش����ʵ�֣������ AMHSDeviceTest.cpp
//

class CAMHSDeviceTestApp : public CWinApp
{
public:
	CAMHSDeviceTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAMHSDeviceTestApp theApp;