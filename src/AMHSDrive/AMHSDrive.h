// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� AMHSDRIVE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// AMHSDRIVE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef AMHSDRIVE_EXPORTS
#define AMHSDRIVE_API __declspec(dllexport)
#else
#define AMHSDRIVE_API __declspec(dllimport)
#endif

// �����Ǵ� AMHSDrive.dll ������
class AMHSDRIVE_API CAMHSDrive {
public:
	CAMHSDrive(void);
	~CAMHSDrive();

	// TODO: �ڴ�������ķ�����
	int Init();
	int Run();
	int Clean();
	int SetOHTLocation(int nPoint);
};
