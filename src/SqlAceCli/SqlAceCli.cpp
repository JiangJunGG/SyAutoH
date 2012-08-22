// SqlAceCli.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "SqlAceCli.h"
#include "SqlServerNCLI.h"

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� SqlAceCli.h
CSqlAceCli::CSqlAceCli()
{
	m_pSqlClient = NULL;
}

CSqlAceCli::~CSqlAceCli()
{
	if (NULL != m_pSqlClient)
	{
		delete m_pSqlClient;
		m_pSqlClient = NULL;
	}
}

int CSqlAceCli::Connect(WCHAR* wServer, WCHAR* wDBName)
{
	if (NULL == m_pSqlClient)
	{
		m_pSqlClient = new SqlServerNCLI();
	}

	int nHR = m_pSqlClient->InitializeAndEstablishConnection(wServer, wDBName);
	return nHR;
}