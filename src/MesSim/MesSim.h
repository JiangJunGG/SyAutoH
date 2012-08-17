// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MESSIM_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MESSIM_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MESSIM_EXPORTS
#define MESSIM_API __declspec(dllexport)
#else
#define MESSIM_API __declspec(dllimport)
#endif

class MesLinkClient;
// �����Ǵ� MesSim.dll ������
class MESSIM_API CMesSim {
public:
	CMesSim(void);
	~CMesSim();

private:
	MesLinkClient* m_pMesClient;

public:
	int Init();
	int PlaceFoup(int nFoupID, int nDevID);
	int PickFoup(int nFoupID, int nDevID);
};
