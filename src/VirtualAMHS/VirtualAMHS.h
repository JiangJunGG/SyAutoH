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
typedef std::map<int, VirtualOHT*> MAP_OHT;
typedef std::map<int, VirtualStocker*> MAP_STK;
// �����Ǵ� VirualAMHS.dll ������

class VIRUALAMHS_API CVirtualAMHS {
public:
	CVirtualAMHS(void);
	~CVirtualAMHS();
	// TODO: �ڴ�������ķ�����
	int AddOHT(int nIndex);
	int AddStocker(int nIndex, const char* sIP);

	// for Stocker
	int ManualInputFoup(int nStocker, const TCHAR* sFoupID);
	int ManualOutputFoup(int nStocker, const TCHAR* sFoupID);

	// for OHT

private:
	MAP_OHT* m_mapOHT;
	MAP_STK*	 m_mapSTK;
};
