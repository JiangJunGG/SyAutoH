// GuiHub.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "GuiHub.h"
#include "UserManagementServer.h"
#include "GuiDataHubServer.h"

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� GuiHub.h
CGuiHub::CGuiHub()
	: 
m_pUserMgt(NULL),
m_pGuiDataHub(NULL)
{
	return;
}
CGuiHub::~CGuiHub()
{
	if (NULL != m_pUserMgt)
	{
		delete m_pUserMgt;
		m_pUserMgt = NULL;
	}

	if (NULL != m_pGuiDataHub)
	{
		delete m_pGuiDataHub;
		m_pGuiDataHub = NULL;
	}
}

int CGuiHub::StartServer()
{
	if (NULL == m_pUserMgt)
	{
		m_pUserMgt = new UserManagementServer();
		m_pUserMgt->InitIce();
	}

	if (NULL == m_pGuiDataHub)
	{
		m_pGuiDataHub = new GuiDataHubServer();
		m_pGuiDataHub->InitIce();
	}

	return 0;
}