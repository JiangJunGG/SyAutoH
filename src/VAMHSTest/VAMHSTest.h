
// VAMHSTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVAMHSTestApp:
// �йش����ʵ�֣������ VAMHSTest.cpp
//

class CVAMHSTestApp : public CWinApp
{
public:
	CVAMHSTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVAMHSTestApp theApp;