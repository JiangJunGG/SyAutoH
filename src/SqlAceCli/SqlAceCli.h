// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SQLACECLI_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SQLACECLI_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SQLACECLI_EXPORTS
#define SQLACECLI_API __declspec(dllexport)
#else
#define SQLACECLI_API __declspec(dllimport)
#endif

// �����Ǵ� SqlAceCli.dll ������
class SQLACECLI_API CSqlAceCli {
public:
	CSqlAceCli(void);
	// TODO: �ڴ�������ķ�����

	int Connect(WCHAR* wServer, WCHAR* wDBName)
	{
		return 0;
	}
};

extern SQLACECLI_API int nSqlAceCli;

SQLACECLI_API int fnSqlAceCli(void);
