// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MESLINK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MESLINK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MESLINK_EXPORTS
#define MESLINK_API __declspec(dllexport)
#else
#define MESLINK_API __declspec(dllimport)
#endif

#pragma  once

class MESLINK_API CMesData
{
public:
	int nType;
	int nFoupID;
	int nEquID;
};

[event_source(native)]
class MesMsgSource 
{
public:
	__event void MESPickFoup(int nBarCode, int nDevID, int nDevType);
	__event void MESPlaceFoup(int nBarCode, int nDevID, int nDevType);
};

class MesLinkServer;
// �����Ǵ� MesLink.dll ������
class MESLINK_API CMesLink {
public:
	CMesLink(void);
	~CMesLink();
private:
	MesLinkServer* m_pMesServer;

public:
	int Init(MesMsgSource* src);
	int GetMesData(CMesData& data);
};

