// TLinkSession.h : CLinkSessionTable ������

#pragma once

// ���������� 2012��9��18��, 16:25

class CLinkSessionTableAccessor
{
public:
	LONG m_SessionID;
	LONG m_UserID;
	LONG m_RealRight;
	LONG m_OrginRight;
	DBTIMESTAMP m_AccessTime;
	TCHAR m_ConnectInfo[201];

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwSessionIDStatus;
	DBSTATUS m_dwUserIDStatus;
	DBSTATUS m_dwRealRightStatus;
	DBSTATUS m_dwOrginRightStatus;
	DBSTATUS m_dwAccessTimeStatus;
	DBSTATUS m_dwConnectInfoStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwSessionIDLength;
	DBLENGTH m_dwUserIDLength;
	DBLENGTH m_dwRealRightLength;
	DBLENGTH m_dwOrginRightLength;
	DBLENGTH m_dwAccessTimeLength;
	DBLENGTH m_dwConnectInfoLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
		hr = _db.OpenFromInitializationString(L"Provider=SQLNCLI10.1;Integrated Security=SSPI;Persist Security Info=False;User ID=\"\";Initial Catalog=MCS;Data Source=SDNY-PC\\AMHS;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=SDNY-PC;Initial File Name=\"\";Use Encryption for Data=False;Tag with column collation when possible=False;MARS Connection=False;DataTypeCompatibility=0;Trust Server Certificate=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(CLinkSessionTableAccessor, L" \
	SELECT \
		SessionID, \
		UserID, \
		RealRight, \
		OrginRight, \
		AccessTime, \
		ConnectInfo \
		FROM dbo.LinkSession")


	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CLinkSessionTableAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_SessionID, m_dwSessionIDLength, m_dwSessionIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_UserID, m_dwUserIDLength, m_dwUserIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_RealRight, m_dwRealRightLength, m_dwRealRightStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_OrginRight, m_dwOrginRightLength, m_dwOrginRightStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_AccessTime, m_dwAccessTimeLength, m_dwAccessTimeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_ConnectInfo, m_dwConnectInfoLength, m_dwConnectInfoStatus)
	END_COLUMN_MAP()
};

class CLinkSessionTable : public CCommand<CAccessor<CLinkSessionTableAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};


