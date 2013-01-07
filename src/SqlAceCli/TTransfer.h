// TTransfer.h : CTableTransfer ������

#pragma once

// ���������� 2013��1��7��, 14:32

class CTableTransferAccessor
{
public:
	LONG m_id;
	LONG m_FoupID;
	LONG m_Source;
	LONG m_Destination;
	TCHAR m_Status[51];
	LONG m_Priority;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwidStatus;
	DBSTATUS m_dwFoupIDStatus;
	DBSTATUS m_dwSourceStatus;
	DBSTATUS m_dwDestinationStatus;
	DBSTATUS m_dwStatusStatus;
	DBSTATUS m_dwPriorityStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwidLength;
	DBLENGTH m_dwFoupIDLength;
	DBLENGTH m_dwSourceLength;
	DBLENGTH m_dwDestinationLength;
	DBLENGTH m_dwStatusLength;
	DBLENGTH m_dwPriorityLength;


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
		hr = _db.OpenFromInitializationString(DbConnectString);
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

	DEFINE_COMMAND_EX(CTableTransferAccessor, L" \
	SELECT \
		id, \
		FoupID, \
		Source, \
		Destination, \
		Status, \
		Priority \
		FROM dbo.Transfer")


	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CTableTransferAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_id, m_dwidLength, m_dwidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_FoupID, m_dwFoupIDLength, m_dwFoupIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_Source, m_dwSourceLength, m_dwSourceStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Destination, m_dwDestinationLength, m_dwDestinationStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_Status, m_dwStatusLength, m_dwStatusStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_Priority, m_dwPriorityLength, m_dwPriorityStatus)
	END_COLUMN_MAP()
};

class CTableTransfer : public CCommand<CAccessor<CTableTransferAccessor> >
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


