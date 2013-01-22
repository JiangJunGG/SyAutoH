// TKeyPoints.h : CTableKeyPoints ������

#pragma once

// ���������� 2013��1��22��, 11:18

class CTableKeyPointsAccessor
{
public:
	LONG m_Id;
	LONG m_Position;
	LONG m_Type;
	BYTE m_SpeedRate;
	BYTE m_TeachMode;
	BYTE m_OHT_ID;
	LONG m_Lane_ID;
	LONG m_Prev;
	LONG m_Next;
	TCHAR m_Name[51];
	double m_refX;
	double m_refY;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶε�״ֵ̬��
	// ����ʹ����Щֵ�������ݿⷵ�ص� NULL ֵ���ڱ���������
	// ����ʱ���������Ϣ���й����ʹ��
	//��Щ�ֶε���ϸ��Ϣ��
	// ��μ� Visual C++ �ĵ��е�
	//�������ɵķ������е��ֶ�״̬���ݳ�Ա����
	// ע��: ������/��������ǰ�����ʼ����Щ�ֶ�!

	DBSTATUS m_dwIdStatus;
	DBSTATUS m_dwPositionStatus;
	DBSTATUS m_dwTypeStatus;
	DBSTATUS m_dwSpeedRateStatus;
	DBSTATUS m_dwTeachModeStatus;
	DBSTATUS m_dwOHT_IDStatus;
	DBSTATUS m_dwLane_IDStatus;
	DBSTATUS m_dwPrevStatus;
	DBSTATUS m_dwNextStatus;
	DBSTATUS m_dwNameStatus;
	DBSTATUS m_dwrefXStatus;
	DBSTATUS m_dwrefYStatus;

	// ���������ɵ����ݳ�Ա����
	//��ӳ������Ӧ�ֶεĳ���ֵ��
	// ע��: �Ա䳤�У�������/����
	//       ����ǰ�����ʼ����Щ�ֶ�!

	DBLENGTH m_dwIdLength;
	DBLENGTH m_dwPositionLength;
	DBLENGTH m_dwTypeLength;
	DBLENGTH m_dwSpeedRateLength;
	DBLENGTH m_dwTeachModeLength;
	DBLENGTH m_dwOHT_IDLength;
	DBLENGTH m_dwLane_IDLength;
	DBLENGTH m_dwPrevLength;
	DBLENGTH m_dwNextLength;
	DBLENGTH m_dwNameLength;
	DBLENGTH m_dwrefXLength;
	DBLENGTH m_dwrefYLength;


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

	DEFINE_COMMAND_EX(CTableKeyPointsAccessor, L" \
	SELECT \
		Id, \
		Position, \
		Type, \
		SpeedRate, \
		TeachMode, \
		OHT_ID, \
		Lane_ID, \
		Prev, \
		Next, \
		Name, \
		refX, \
		refY \
		FROM dbo.KeyPoints")


	// Ϊ���ĳЩ�ṩ������������⣬���´��������
	// ��ͬ���ṩ�����������˳��������

	BEGIN_COLUMN_MAP(CTableKeyPointsAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_Id, m_dwIdLength, m_dwIdStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Position, m_dwPositionLength, m_dwPositionStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_Type, m_dwTypeLength, m_dwTypeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_SpeedRate, m_dwSpeedRateLength, m_dwSpeedRateStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_TeachMode, m_dwTeachModeLength, m_dwTeachModeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_OHT_ID, m_dwOHT_IDLength, m_dwOHT_IDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(7, m_Lane_ID, m_dwLane_IDLength, m_dwLane_IDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(8, m_Prev, m_dwPrevLength, m_dwPrevStatus)
		COLUMN_ENTRY_LENGTH_STATUS(9, m_Next, m_dwNextLength, m_dwNextStatus)
		COLUMN_ENTRY_LENGTH_STATUS(10, m_Name, m_dwNameLength, m_dwNameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(11, m_refX, m_dwrefXLength, m_dwrefXStatus)
		COLUMN_ENTRY_LENGTH_STATUS(12, m_refY, m_dwrefYLength, m_dwrefYStatus)
	END_COLUMN_MAP()
};

class CTableKeyPoints : public CCommand<CAccessor<CTableKeyPointsAccessor> >
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


