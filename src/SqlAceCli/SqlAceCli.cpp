// SqlAceCli.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "SqlAceCli.h"


// ���ǵ���������һ��ʾ��
SQLACECLI_API int nSqlAceCli=0;

// ���ǵ���������һ��ʾ����
SQLACECLI_API int fnSqlAceCli(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� SqlAceCli.h
CSqlAceCli::CSqlAceCli()
{
	return;
}
