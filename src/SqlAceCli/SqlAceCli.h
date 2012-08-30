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

class SqlServerNCLI;
// �����Ǵ� SqlAceCli.dll ������
class SQLACECLI_API CSqlAceCli {
public:
	CSqlAceCli(void);
	~CSqlAceCli();

private:
	SqlServerNCLI* m_pSqlClient;

public:
	int Connect(WCHAR* wServer, WCHAR* wDBName);
	int ExecuteSQL(WCHAR* wSqlCmd);
	int PutOutRecordSet(void);
};
