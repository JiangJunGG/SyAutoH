
// MesFuncSim.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMesFuncSimApp:
// �йش����ʵ�֣������ MesFuncSim.cpp
//

class CMesFuncSimApp : public CWinApp
{
public:
	CMesFuncSimApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMesFuncSimApp theApp;