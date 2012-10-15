// AMHSDrive.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

#include "Common.h"
#include "../shared/Network.h"
#include "AMHS_Server.h"
#include "AMHSDrive.h"

#include "AMHSPacket.h"
#include "AMHSSocket.h"


// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� AMHSDrive.h
CAMHSDrive::CAMHSDrive()
{
	
}

CAMHSDrive::~CAMHSDrive()
{
	Clean();
}

int CAMHSDrive::Init()
{
	//// using socket
	//new SocketMgr;
	//new SocketGarbageCollector;
	//sSocketMgr.SpawnWorkerThreads();
	//string host = "127.0.0.1";
	//int wsport = 9999;
	//// Create listener
	//ListenSocket<AMHSSocket> * ls = new ListenSocket<AMHSSocket>(host.c_str(), wsport);
	//bool listnersockcreate = ls->IsOpen();
	//if(listnersockcreate)
	//	ThreadPool.ExecuteTask(ls);

	//ThreadPool.ShowStats();

	// using asio
	new AMHS_Server;
	sAmhsServer.Start(9999);

	return 0;
}

int CAMHSDrive::Check()
{
	/*while(1)
	{
	ThreadPool.ShowStats();
	Sleep(5000);
	}*/
	/*while(1)
	{
	sSocketMgr.ShowStatus();
	Sleep(1000);
	}*/
	int nCount = sAmhsServer.GetConnectedCount();
	printf("amhs dev connected: %d\n", nCount);

	return 0;
}

int CAMHSDrive::Clean()
{
	//sSocketMgr.ShutdownThreads();
	//sSocketMgr.CloseAll();
	//delete SocketMgr::getSingletonPtr();
	//delete SocketGarbageCollector::getSingletonPtr();

	//ThreadPool.Shutdown();
	delete AMHS_Server::getSingletonPtr();
	return 0;
}

int CAMHSDrive::SetOHTBackMessage(int nOHT, int ms)
{
	sAmhsServer.SetOHTBaceMesageTime(nOHT, ms);
	return 0;
}

int CAMHSDrive::SetOHTLocation(int nPoint)
{

	return 0;
}