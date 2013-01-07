// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SQLACECLI_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SQLACECLI_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SQLACECLI_EXPORTS
#define SQLACECLI_API __declspec(dllexport)
#else
#define SQLACECLI_API __declspec(dllimport)
#pragma comment(lib, "sqlAceCli.lib")
#endif

#pragma once
#include <windows.h>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

typedef struct  
{
	int nID;
	wstring strName;
	int nRight;
} UserData;

typedef list<UserData> UserDataList;
class SQLACECLI_API DBUserAce
{
public:
	DBUserAce(void);
	~DBUserAce(void);

public:
	int Login(const ::std::string& sName, const ::std::string& sHash);
	int Logout(int);
	int CreateUser(const ::std::string& sName, 
		const ::std::string& sPassWord, int nRight);
	int DeleteUser(int);
	int SetUserPW(int, const ::std::string&);
	int SetUserRight(int, int);
	int GetUserCount();
	UserDataList GetUserList(int, int);
	UserData GetUserDatabyName(const ::std::string& sName);
	UserData GetUserDatabyID(int nUserID);
};

typedef struct
{
	int nLocation;
	int nLocType;
	int nCarrier;
	int nPort;
}FoupLocation;
typedef struct 
{
	int nBarCode;
	int nLot;
	int nStatus;
	FoupLocation locFoup;
} FoupItem;
typedef std::vector<FoupItem> VEC_FOUP;

class SQLACECLI_API DBFoup
{
public:
	DBFoup(void);
	~DBFoup(void);
public:
	int AddFoup(int nBarCode, int nLot, const FoupLocation& location);
	int UpdateFoup(int nBarCode, int nLot, const FoupLocation& location);
	int FindFoup(int nBarCode);
	int SetFoupLocation(int nBarCode, const FoupLocation& location);
	int GetFoupLocation(int nBarCode, FoupLocation& location);
	VEC_FOUP GetFoupAllTable();
	VEC_FOUP GetFoupsInStocker(int nStockerID);
};

typedef map<int, int> Map_Int;
class SQLACECLI_API DBSession
{
public:
	DBSession(void);
	~DBSession(void);
public:
private:
	Map_Int* m_pmapRole;
public:
	int LoginOut(int nSession);
	int GetLoginSession(int nUserID, int nRight, 
		const string& strConnection, bool bLastLimit);
	int GetRealRight(int nSession);
	int SetRealRight(int nSession, int nRealRight);
};

typedef struct 
{
	wstring strName;
	UINT uPosition;
	WORD uType;//,[Type]
	WORD uSpeedRate;//,[SpeedRate]
	WORD uTeachMode;//,[TeachMode]
	WORD uOHT_ID;//,[OHT_ID]
	WORD uRail_ID;//,[Rail_ID]
	UINT uPrev;//,[Prev]
	UINT uNext;//,[Next]
} KeyPointItem;
typedef std::vector<KeyPointItem> VEC_KEYPOINT;
class SQLACECLI_API DBKeyPoints
{
public:
	DBKeyPoints(void);
	~DBKeyPoints(void);
	int SetKeyPointbyOHTTeach(int nOHT_ID, int nPOS, int nType, int nSpeedRate);
	VEC_KEYPOINT GetKeyPointsTable(vector<int> nTypes);
};

typedef struct  
{
	int nID;
	int nStart;
	int nEnd;
	int nPrevLane;
	int nNextLane;
	int nNextFork;
	int nLength;
	int nType;
	bool bEnable;
}ItemLane;
typedef std::vector<ItemLane> VEC_LANE;
class SQLACECLI_API DBLane
{
public:
	DBLane(void);
	~DBLane(void);

public:
	VEC_LANE GetLaneTable(int nMapID);
};

typedef struct
{
	int nFoupID;
	int nTarget;
}ItemTrans;
typedef std::vector<ItemTrans> VEC_TRANS;

class SQLACECLI_API DBTransfer
{
public:
	DBTransfer(void);
	~DBTransfer(void);
public:
	int AddTransfer(int nFoupID, int nTarget);
	VEC_TRANS GetTransfer();
};
