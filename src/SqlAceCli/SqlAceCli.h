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
#endif

#pragma once
#include <windows.h>
#include <string>
#include <list>
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

class SQLACECLI_API DBFoup
{
public:
	DBFoup(void);
	~DBFoup(void);
public:
	int AddFoup(const WCHAR* sFoupID, const WCHAR* sLot, int nLocal, int nType);
	int FindFoup(const WCHAR* sFoupID);
	int SetFoupLocation(int nFoup, int nLocal, int nType);
	int GetFoupLocation(int nFoup, int &nLocal, int &nType);
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

class SQLACECLI_API DBKeyPoints
{
public:
	DBKeyPoints(void);
	~DBKeyPoints(void);
	int SetKeyPointbyOHTTeach(int nOHT_ID, int nPOS, int nType, int nSpeedRate);
};
