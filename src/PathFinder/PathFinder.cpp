// PathFinder.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "PathFinder.h"
#include "PathProductor.h"
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� PathFinder.h
CPathFinder::CPathFinder()
{
	return;
}

CPathFinder::~CPathFinder()
{
	delete CPathProductor::getSingletonPtr();
}

INT_LIST CPathFinder::GetPath(int nFrom, int nTo)
{
	INT_LIST list;
	return list;
}

void CPathFinder::Init()
{
	new CPathProductor;
	
	sPathProductor.GetLaneData();
}

void CPathFinder::Test(void)
{
	
}
