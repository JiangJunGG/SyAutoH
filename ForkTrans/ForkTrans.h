// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� FORKTRANS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// FORKTRANS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef FORKTRANS_EXPORTS
#define FORKTRANS_API __declspec(dllexport)
#else
#define FORKTRANS_API __declspec(dllimport)
#endif

// �����Ǵ� ForkTrans.dll ������
class FORKTRANS_API CForkTrans {
public:
	CForkTrans(void);
	// TODO: �ڴ�������ķ�����
};

extern FORKTRANS_API int nForkTrans;

FORKTRANS_API int fnForkTrans(void);
