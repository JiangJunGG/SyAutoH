// AMHSDrive.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "AMHSDrive.h"


// ���ǵ���������һ��ʾ��
AMHSDRIVE_API int nAMHSDrive=0;

// ���ǵ���������һ��ʾ����
AMHSDRIVE_API int fnAMHSDrive(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� AMHSDrive.h
CAMHSDrive::CAMHSDrive()
{
	return;
}
