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

// �����Ǵ� GuiHub.dll ������
class GUIHUB_API CGuiHub {
public:
	CGuiHub(void);
	// TODO: �ڴ�������ķ�����
};

extern GUIHUB_API int nGuiHub;

GUIHUB_API int fnGuiHub(void);
