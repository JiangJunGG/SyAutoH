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

// �����Ǵ� VirualAMHS.dll ������
class amhs_client;
class VIRUALAMHS_API CVirualAMHS {
public:
	CVirualAMHS(void);
	~CVirualAMHS();
	// TODO: �ڴ�������ķ�����
	int AddOHT(int nIndex);

private:
	amhs_client* pclient;
};
