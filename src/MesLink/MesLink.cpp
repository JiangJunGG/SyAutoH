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

CMesLink::~CMesLink()
{
	if (NULL != m_pMesServer)
	{
		delete m_pMesServer;
		m_pMesServer = NULL;
	}
}

int CMesLink::Init(MesMsgSource* pSrc)
{
	if (NULL == m_pMesServer)
	{
		m_pMesServer = new MesLinkServer();
		m_pMesServer->Source(pSrc);
		m_pMesServer->InitIce();
	}
	return 0;
}

int CMesLink::GetMesData(CMesData& data)
{

	return 0;
}