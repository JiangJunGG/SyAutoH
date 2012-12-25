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

	{
		int nFrom = 50;
		int nTo = 1050;
		auto path = GetPath(nFrom, nTo);
		cout<< "Start: " << nFrom << " To: " << nTo << endl;
		cout << "Path: " << endl;
		auto it = path.cbegin();
		if (it != path.cend())
		{
			cout << *it;
			for (++it;
				it != path.cend(); ++it)
			{
				cout<< "->" << *it;
			}
			cout<< endl;
		}
	}

	{
		int nFrom = 1050;
		int nTo = 50;
		auto path = GetPath(nFrom, nTo);
		cout<< "Start: " << nFrom << " To: " << nTo << endl;
		cout << "Path: " << endl;
		auto it = path.cbegin();
		if (it != path.cend())
		{
			cout << *it;
			for (++it;
				it != path.cend(); ++it)
			{
				cout<< "->" << *it;
			}
			cout<< endl;
		}
	}
	
	
}

void CPathFinder::Test(void)
{
	//sPathProductor.GetLaneData();
}
