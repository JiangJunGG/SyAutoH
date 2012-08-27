// SqlAceCli.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "SqlAceCli.h"
#include "SqlServerNCLI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

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
	if (0 == nHR)
	{
		nHR = m_pSqlClient->CreationSession();
	}

	m_pSqlClient->TestMfcOleDB();

	return nHR;
}


int CSqlAceCli::ExecuteSQL(WCHAR* wSqlCmd)
{
	if (NULL != m_pSqlClient)
	{
		return m_pSqlClient->ExecuteSQL(wSqlCmd);
	}

	return -1;
}


int CSqlAceCli::PutOutRecordSet(void)
{
	if (NULL != m_pSqlClient)
	{
		return m_pSqlClient->TProcessRecordSet();
	}

	return -1;
}
