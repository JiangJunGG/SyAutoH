// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MCSCORE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MCSCORE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MCSCORE_EXPORTS
#define MCSCORE_API __declspec(dllexport)
#else
#define MCSCORE_API __declspec(dllimport)
#endif

// �����Ǵ� mcscore.dll ������
class MCSCORE_API Cmcscore {
public:
	Cmcscore(void);
	// TODO: �ڴ�������ķ�����
};

extern MCSCORE_API int nmcscore;

MCSCORE_API int fnmcscore(void);
