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
	list = sPathProductor.ProductPath(nFrom, nTo);
	return list;
}

void CPathFinder::Init()
{
	new CPathProductor;
	
	sPathProductor.GetLaneData();

	int nFrom = 400;
	int nTo = 100;
	auto path = GetPath(nFrom, nTo);
	cout<< "Start: " << nFrom << " To: " << nTo << endl;
	cout << "Path: " << endl;
	auto it = path.cbegin();
	cout << *it;
	for (++it;
		it != path.cend(); ++it)
	{
		cout<< "->" << *it;
	}
	cout<< endl;
}

void CPathFinder::Test(void)
{
	//sPathProductor.GetLaneData();
}
