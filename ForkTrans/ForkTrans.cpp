// ForkTrans.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ForkTrans.h"


// ���ǵ���������һ��ʾ��
FORKTRANS_API int nForkTrans=0;

// ���ǵ���������һ��ʾ����
FORKTRANS_API int fnForkTrans(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ForkTrans.h
CForkTrans::CForkTrans()
{
	return;
}
