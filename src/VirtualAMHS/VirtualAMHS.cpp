// VirualAMHS.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "VirtualAMHS.h"
#include "VirtualOHT.h"

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� VirualAMHS.h


CVirtualAMHS::CVirtualAMHS()
{
	m_mapOHT = new MAP_OHT();
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
}

int CVirtualAMHS::AddOHT(int nIndex)
{
	MAP_OHT::iterator it;
	it = m_mapOHT->find(nIndex);
	if (it != m_mapOHT->end())
	{
		VirtualOHT* oht = it->second;
		oht->Auth(nIndex, 2001, 0);
	}
	else
	{
		VirtualOHT* oht = new VirtualOHT();
		oht->Init("127.0.0.1", 9999);
		oht->Auth(nIndex, 1001, 1);
		(*m_mapOHT)[nIndex] = oht;
	}
	

	return 0;
}
