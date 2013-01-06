// Foup.h : CFoup ������

#pragma once

// ���������� 2013��1��5��, 9:48

class CTableFoupAccessor
{
public:
	LONG m_ID;
	LONG m_Location;
	BYTE m_LocationType;
	BYTE m_Status;
	LONG m_Lot;
	LONG m_BarCode;
	LONG m_Carrier;
	LONG m_Port;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwLocationStatus;
	DBSTATUS m_dwLocationTypeStatus;
	DBSTATUS m_dwStatusStatus;
	DBSTATUS m_dwLotStatus;
	DBSTATUS m_dwBarCodeStatus;
	DBSTATUS m_dwCarrierStatus;
	DBSTATUS m_dwPortStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwLocationLength;
	DBLENGTH m_dwLocationTypeLength;
	DBLENGTH m_dwStatusLength;
	DBLENGTH m_dwLotLength;
	DBLENGTH m_dwBarCodeLength;
	DBLENGTH m_dwCarrierLength;
	DBLENGTH m_dwPortLength;


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

	DEFINE_COMMAND_EX(CTableFoupAccessor, L" \
	SELECT \
		ID, \
		Location, \
		LocationType, \
		Status, \
		Lot, \
		BarCode, \
		Carrier, \
		Port \
		FROM dbo.Foup")


	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CTableFoupAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Location, m_dwLocationLength, m_dwLocationStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_LocationType, m_dwLocationTypeLength, m_dwLocationTypeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Status, m_dwStatusLength, m_dwStatusStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_Lot, m_dwLotLength, m_dwLotStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_BarCode, m_dwBarCodeLength, m_dwBarCodeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_Carrier, m_dwCarrierLength, m_dwCarrierStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_Port, m_dwPortLength, m_dwPortStatus)
	END_COLUMN_MAP()
};

class CTableFoup : public CCommand<CAccessor<CTableFoupAccessor> >
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


