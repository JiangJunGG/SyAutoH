// SqlDBTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../SqlAceCli/SqlAceCli.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CSqlAceCli sqlAce;
	int nHR = sqlAce.Connect(L"SDNY-PC\\AMHS", L"MCS");
	if (nHR != 0)
	{
		cout<<"Cannot open the database." << endl;
	}
	else
	{
		cout<<"Success to open the database." << endl;
	}

	return 0;
}

