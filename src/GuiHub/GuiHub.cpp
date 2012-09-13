// GuiHub.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "GuiHub.h"
#include "UserManagementServer.h"

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� GuiHub.h
CGuiHub::CGuiHub()
{
	m_pUserMgt = NULL;
	return;
}
CGuiHub::~CGuiHub()
{
	if (NULL != m_pUserMgt)
	{
		delete m_pUserMgt;
		m_pUserMgt = NULL;
	}
}

int CGuiHub::StartUserManagement()
{
	if (NULL == m_pUserMgt)
	{
		m_pUserMgt = new UserManagementServer();
		m_pUserMgt->InitIce();
	}

	return 0;
}