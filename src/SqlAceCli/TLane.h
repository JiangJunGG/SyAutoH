// TLane.h : CTableLane ������

#pragma once

// ���������� 2012��12��18��, 16:44

class CTableLaneAccessor
{
public:
	LONG m_id;
	LONG m_Start;
	LONG m_Finish;
	LONG m_Prev;
	LONG m_Next;
	LONG m_Next_Frok;
	LONG m_Length;
	LONG m_MapID;
	BYTE m_Type;
	VARIANT_BOOL m_Enable;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwidStatus;
	DBSTATUS m_dwStartStatus;
	DBSTATUS m_dwFinishStatus;
	DBSTATUS m_dwPrevStatus;
	DBSTATUS m_dwNextStatus;
	DBSTATUS m_dwNext_FrokStatus;
	DBSTATUS m_dwLengthStatus;
	DBSTATUS m_dwMapIDStatus;
	DBSTATUS m_dwTypeStatus;
	DBSTATUS m_dwEnableStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwidLength;
	DBLENGTH m_dwStartLength;
	DBLENGTH m_dwFinishLength;
	DBLENGTH m_dwPrevLength;
	DBLENGTH m_dwNextLength;
	DBLENGTH m_dwNext_FrokLength;
	DBLENGTH m_dwLengthLength;
	DBLENGTH m_dwMapIDLength;
	DBLENGTH m_dwTypeLength;
	DBLENGTH m_dwEnableLength;


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

	DEFINE_COMMAND_EX(CTableLaneAccessor, L" \
	SELECT \
		id, \
		Start, \
		Finish, \
		Prev, \
		Next, \
		Next_Frok, \
		Length, \
		MapID, \
		Type, \
		Enable \
		FROM dbo.Lane")


	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CTableLaneAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_id, m_dwidLength, m_dwidStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Start, m_dwStartLength, m_dwStartStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_Finish, m_dwFinishLength, m_dwFinishStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Prev, m_dwPrevLength, m_dwPrevStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_Next, m_dwNextLength, m_dwNextStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_Next_Frok, m_dwNext_FrokLength, m_dwNext_FrokStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_Length, m_dwLengthLength, m_dwLengthStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_MapID, m_dwMapIDLength, m_dwMapIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_Type, m_dwTypeLength, m_dwTypeStatus)
		_COLUMN_ENTRY_CODE(10, DBTYPE_BOOL, _SIZE_TYPE(m_Enable), 0, 0, offsetbuf(m_Enable), offsetbuf(m_dwEnableLength), offsetbuf(m_dwEnableStatus))
	END_COLUMN_MAP()
};

class CTableLane : public CCommand<CAccessor<CTableLaneAccessor> >
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


