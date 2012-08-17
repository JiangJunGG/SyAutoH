// MesSim.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MesSim.h"
#include "MesLinkClient.h"
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MesSim.h
CMesSim::CMesSim()
{
	m_pMesClient = NULL;
}

CMesSim::~CMesSim()
{
	if (NULL != m_pMesClient)
	{
		delete m_pMesClient;
		m_pMesClient = NULL;
	}
}

int CMesSim::Init()
{
	if (NULL == m_pMesClient)
	{
		m_pMesClient = new MesLinkClient();
		m_pMesClient->InitIce();
	}
	return 0;
}
int CMesSim::PlaceFoup(int nFoupID, int nDevID)
{
	int nRet = 0;
	if (NULL != m_pMesClient)
	{
		nRet = m_pMesClient->PlaceFoup(nFoupID, nDevID);
	}
	return nRet;
}
int CMesSim::PickFoup(int nFoupID, int nDevID)
{
	int nRet = 0;
	if (NULL != m_pMesClient)
	{
		nRet = m_pMesClient->PickFoup(nFoupID, nDevID);
	}
	return nRet;
}