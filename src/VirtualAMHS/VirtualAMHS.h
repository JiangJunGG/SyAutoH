// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� VIRUALAMHS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// VIRUALAMHS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef VIRUALAMHS_EXPORTS
#define VIRUALAMHS_API __declspec(dllexport)
#else
#define VIRUALAMHS_API __declspec(dllimport)
#endif

#pragma once

class VirtualOHT;
class VirtualStocker;
#include <map>
#include <list>
typedef std::map<int, VirtualOHT*> MAP_VOHT;
typedef std::map<int, VirtualStocker*> MAP_VSTK;

typedef struct
{
	int nID;
	int nPosition;
	int nHandStatus;
	int nOnline;
} ItemOHT;
typedef std::list<ItemOHT> LIST_OHT;
typedef std::map<int, ItemOHT*> MAP_ItemOHT;

typedef struct
{
	TCHAR FoupID[256];
	int nProcessStatus;
} ItemFoup;
typedef std::list<ItemFoup> LIST_FOUP;

class VIRUALAMHS_API CVirtualAMHS {
public:
	CVirtualAMHS(void);
	~CVirtualAMHS();

	// device auth
	int OHT_Auth(int nIndex, DWORD nPos = 0, int nHand = 0);
	int Stocker_Auth(int nIndex, const char* sIP);

	// for Stocker
	LIST_FOUP Stocker_GetFoupsStatus(int nStocker);
	int Stocker_ManualInputFoup(int nStocker, const TCHAR* sFoupID);
	int Stocker_ManualOutputFoup(int nStocker, const TCHAR* sFoupID);
	int STK_History(int nStocker);

	// for OHT
	LIST_OHT OHT_GetStatus();
	int SetTeachPosition(int nID, int nPos, int nType, int nSpeedRate);

private:
	MAP_VOHT* m_mapOHT;
	MAP_VSTK*	 m_mapSTK;
};
