// MesLink.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MesLink.h"
#include "IceMesLinkServerI.h"
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MesLink.h
CMesLink::CMesLink()
{
	m_pMesServer = NULL;
	return;
}

int CMesLink::Init()
{
	if (NULL == m_pMesServer)
	{
		m_pMesServer = new MesLinkServer();
		m_pMesServer->InitIce();
	}
	return 0;
}