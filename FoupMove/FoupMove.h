
// FoupMove.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFoupMoveApp:
// �йش����ʵ�֣������ FoupMove.cpp
//

class CFoupMoveApp : public CWinApp
{
public:
	CFoupMoveApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFoupMoveApp theApp;