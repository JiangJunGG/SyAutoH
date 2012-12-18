// PathFinder.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "PathFinder.h"
#include "PathProductor.h"
// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 PathFinder.h
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

	auto path = GetPath(400, 100);
}

void CPathFinder::Test(void)
{
	//sPathProductor.GetLaneData();
}
