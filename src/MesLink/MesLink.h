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

// �����Ǵ� MesLink.dll ������
class MESLINK_API CMesLink {
public:
	CMesLink(void);
	// TODO: �ڴ�������ķ�����
};

extern MESLINK_API int nMesLink;

MESLINK_API int fnMesLink(void);
