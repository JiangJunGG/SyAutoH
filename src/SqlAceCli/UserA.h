// UserA.h : CUserA ������

#pragma once

// ���������� 2012��8��29��, 15:24

class CUserAAccessor
{
public:
	LONG m_id;
	TCHAR m_Name[31];
	TCHAR m_Password[37];
	LONG m_UserRight;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwidStatus;
	DBSTATUS m_dwNameStatus;
	DBSTATUS m_dwPasswordStatus;
	DBSTATUS m_dwUserRightStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwidLength;
	DBLENGTH m_dwNameLength;
	DBLENGTH m_dwPasswordLength;
	DBLENGTH m_dwUserRightLength;


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

	BEGIN_COLUMN_MAP(CUserAAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_id, m_dwidLength, m_dwidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Name, m_dwNameLength, m_dwNameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_Password, m_dwPasswordLength, m_dwPasswordStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_UserRight, m_dwUserRightLength, m_dwUserRightStatus)
	END_COLUMN_MAP()
};

class CUserA : public CTable<CAccessor<CUserAAccessor> >
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
		HRESULT hr = Open(m_session, L"dbo.McsUser", pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};


