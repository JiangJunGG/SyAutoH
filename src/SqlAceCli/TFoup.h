// TFoup.h : CFoupTable 的声明

#pragma once

// 代码生成在 2012年9月14日, 14:43

class CTableFoupAccessor
{
public:
	LONG m_ID;
	LONG m_Local;
	BYTE m_Type;
	BYTE m_Status;
	TCHAR m_Lot[51];
	TCHAR m_FoupID[51];

	// 以下向导生成的数据成员包含
	//列映射中相应字段的状态值。
	// 可以使用这些值保存数据库返回的 NULL 值或在编译器返回
	// 错误时保存错误信息。有关如何使用
	//这些字段的详细信息，
	// 请参见 Visual C++ 文档中的
	//“向导生成的访问器中的字段状态数据成员”。
	// 注意: 在设置/插入数据前必须初始化这些字段!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwLocalStatus;
	DBSTATUS m_dwTypeStatus;
	DBSTATUS m_dwStatusStatus;
	DBSTATUS m_dwLotStatus;
	DBSTATUS m_dwFoupIDStatus;

	// 以下向导生成的数据成员包含
	//列映射中相应字段的长度值。
	// 注意: 对变长列，在设置/插入
	//       数据前必须初始化这些字段!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwLocalLength;
	DBLENGTH m_dwTypeLength;
	DBLENGTH m_dwStatusLength;
	DBLENGTH m_dwLotLength;
	DBLENGTH m_dwFoupIDLength;


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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
		Local, \
		Type, \
		Status, \
		Lot, \
		FoupID \
		FROM dbo.Foup")


	// 为解决某些提供程序的若干问题，以下代码可能以
	// 不同于提供程序所报告的顺序来绑定列

	BEGIN_COLUMN_MAP(CTableFoupAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Local, m_dwLocalLength, m_dwLocalStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_Type, m_dwTypeLength, m_dwTypeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Status, m_dwStatusLength, m_dwStatusStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_Lot, m_dwLotLength, m_dwLotStatus)
		COLUMN_ENTRY_LENGTH_STATUS(6, m_FoupID, m_dwFoupIDLength, m_dwFoupIDStatus)
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


