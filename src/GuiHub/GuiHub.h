// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� GUIHUB_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// GUIHUB_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef GUIHUB_EXPORTS
#define GUIHUB_API __declspec(dllexport)
#else
#define GUIHUB_API __declspec(dllimport)
#endif

#pragma once
#include "../common/iConstDef.h"

class UserManagementServer;
class GuiDataHubServer;
class CAMHSDrive;
// �����Ǵ� GuiHub.dll ������
class GUIHUB_API CGuiHub {
public:
	CGuiHub(void);
	~CGuiHub();
private:
	UserManagementServer* m_pUserMgt;
	GuiDataHubServer*				m_pGuiDataHub;
public:

	int StartServer(CAMHSDrive* pDrive);
	void SetData(MCS::GuiHub::PushData nTag, const char* chVal);
};
