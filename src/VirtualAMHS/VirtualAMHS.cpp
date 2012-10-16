// VirualAMHS.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "VirtualAMHS.h"
#include "VirtualOHT.h"
#include "VirtualStocker.h"

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� VirualAMHS.h
const int OHT_START_POS = 1000;


CVirtualAMHS::CVirtualAMHS()
{
	m_mapOHT = new MAP_OHT();
	m_mapSTK = new MAP_STK();
	return;
}

CVirtualAMHS::~CVirtualAMHS()
{
	MAP_OHT::iterator it;
	it = m_mapOHT->begin();
	while(it != m_mapOHT->end())
	{
		delete it->second;
		++it;
	}
	delete m_mapOHT;

	MAP_STK::iterator it_stk;
	it_stk = m_mapSTK->begin();
	while(it_stk != m_mapSTK->end())
	{
		delete it_stk->second;
		++it_stk;
	}
	delete m_mapSTK;
}

int CVirtualAMHS::AddStocker(int nIndex, const char* sIP)
{
	MAP_STK::iterator it;
	it = m_mapSTK->find(nIndex);
	if (it != m_mapSTK->end())
	{
		VirtualStocker* stocker = it->second;
		stocker->Auth( sIP);
	}
	else
	{
		VirtualStocker* stocker = new VirtualStocker();
		stocker->getID(nIndex);
		stocker->Connect("127.0.0.1", 9999);
		stocker->Auth( sIP);
		(*m_mapSTK)[nIndex] = stocker;
	}
	return 0;
}

int CVirtualAMHS::AddOHT(int nIndex)
{
	MAP_OHT::iterator it;
	it = m_mapOHT->find(nIndex);
	if (it != m_mapOHT->end())
	{
		VirtualOHT* oht = it->second;
		oht->Auth(OHT_START_POS, 0);
	}
	else
	{
		VirtualOHT* oht = new VirtualOHT();
		oht->getID(nIndex);

		oht->Connect("127.0.0.1", 9999);
		oht->Auth(OHT_START_POS, 0);
		(*m_mapOHT)[nIndex] = oht;
	}
	

	return 0;
}

LIST_FOUP CVirtualAMHS::GetFoupsStatus(int nStocker)
{
	LIST_FOUP list;
	return list;
}

LIST_OHT CVirtualAMHS::GetOHTStatus()
{
	LIST_OHT list;
	return list;
}

int CVirtualAMHS::ManualInputFoup(int nStocker, const TCHAR* sFoupID)
{
	MAP_STK::iterator it;
	it = m_mapSTK->find(nStocker);
	if (it != m_mapSTK->end())
	{
		VirtualStocker* stocker = it->second;
		stocker->ManualInputFoup(sFoupID);
	}
	else
	{
		return -1;
	}
	return 0;
}

int CVirtualAMHS::ManualOutputFoup(int nStocker, const TCHAR* sFoupID)
{
	MAP_STK::iterator it;
	it = m_mapSTK->find(nStocker);
	if (it != m_mapSTK->end())
	{
		VirtualStocker* stocker = it->second;
		stocker->ManualOutputFoup(sFoupID);
	}
	else
	{
		return -1;
	}
	return 0;
}