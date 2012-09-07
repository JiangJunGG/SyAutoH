// SqlAceCli.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "SqlAceCli.h"
#include "SqlServerNCLI.h"
#include "DBFoup.h"

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
	Clean();
}

int CSqlAceCli::Connect(WCHAR* wServer, WCHAR* wDBName)
{
	if (NULL == m_pSqlClient)
	{
		m_pSqlClient = new SqlServerNCLI();
	}

	int nHR = m_pSqlClient->InitializeAndEstablishConnection(wServer, wDBName);

	//m_pSqlClient->TestMfcOleDB();

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
		//return m_pSqlClient->TProcessRecordSet();
	}

	return -1;
}


int CSqlAceCli::Clean(void)
{
	if (NULL != m_pSqlClient)
	{
		delete m_pSqlClient;
		m_pSqlClient = NULL;
	}

	return 0;
}


int CSqlAceCli::FindFoupLocation(WCHAR* sFoupID, int& nOHV, int& nStocker)
{
	nOHV = 0;
	nStocker = 0;

	CFoupCommander foupCmd;
	foupCmd.OpenDataSource();
	CString strFind = L"SELECT * From Foup where FoupID = '#@#'";
	strFind.Replace(L"#@#", sFoupID);
	HRESULT hr = foupCmd.Open(foupCmd.m_session, strFind);
	if (FAILED(hr))
	{
		cout << "Open Foup Failed." << endl;
		return -1;
	}

	if(foupCmd.MoveFirst() != DB_S_ENDOFROWSET)
	{
		//CString line;
		//line.Format(L"ID: %d | Lot: %s | OHV: %d | STOCKER: %d | Status: %s\r\n", 
		//	foupCmd.m_ID, foupCmd.m_Lot, foupCmd.m_OHV, 
		//	foupCmd.m_STOCKER, foupCmd.m_Status);
		//_tprintf(line);
		nOHV = foupCmd.m_OHV;
		nStocker = foupCmd.m_STOCKER;
	}

	foupCmd.CloseAll();

	return 0;
}
