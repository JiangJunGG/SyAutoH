// SiaMCSYS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

#include "MMoveCtrlServer.h"
#include "Common.h"
#include <signal.h>

initialiseSingleton(MMoveCtrlServer);

int _tmain(int argc, _TCHAR* argv[])
{
	new MMoveCtrlServer;
	MMoveCtrlServer::getSingleton().Run(argc, argv);
	delete MMoveCtrlServer::getSingletonPtr();

	return 0;
}