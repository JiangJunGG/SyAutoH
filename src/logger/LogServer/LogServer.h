// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LOGSERVER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LOGSERVER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LOGSERVER_EXPORTS
#define LOGSERVER_API __declspec(dllexport)
#else
#define LOGSERVER_API __declspec(dllimport)
#endif

// �����Ǵ� LogServer.dll ������
class LOGSERVER_API CLogServer {
public:
	CLogServer(void);
	// TODO: �ڴ�������ķ�����
	int Init(void);
	int End(void);
	void BindMsgHandle(HWND hwnd);

private:
	HWND m_hWnd;
	int InitICE(void);
	int InitDataStore(void);
};

extern LOGSERVER_API int nLogServer;

LOGSERVER_API int fnLogServer(void);
