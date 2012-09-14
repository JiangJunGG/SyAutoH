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

using namespace std;

typedef list<string> strList;
class SQLACECLI_API DBUserAce
{
public:
	DBUserAce(void);
	~DBUserAce(void);

public:
	int Login(const ::std::string& sName, const ::std::string& sHash);
	int Logout(int);
	int CreateUser(const ::std::string& sName, const ::std::string& sPassWord, int nRight);
	int DeleteUser(int, int);
	int SetUserPW(int, const ::std::string&, int);
	int SetUserRight(int, int, int);
	int GetUserCount();
	strList GetUserList(int, int);
};

class SQLACECLI_API DBFoup
{
public:
	DBFoup(void);
	~DBFoup(void);
public:
	int AddFoup(WCHAR* sFoupID, WCHAR* sLot, int nLocal, int nType);
	int FindFoup(WCHAR* sFoupID);
	int SetFoupLocation(int nFoup, int nLocal, int nType);
	int GetFoupLocation(int nFoup, int &nLocal, int &nType);
};
