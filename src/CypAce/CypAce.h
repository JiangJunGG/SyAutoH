// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CYPACE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CYPACE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CYPACE_EXPORTS
#define CYPACE_API __declspec(dllexport)
#else
#define CYPACE_API __declspec(dllimport)
#endif

// �����Ǵ� CypAce.dll ������
class CYPACE_API CCypAce 
{
public:
	CCypAce(void);
	// TODO: �ڴ�������ķ�����
public:
	bool HashString(LPCTSTR strInput, LPTSTR strHash);
public:
	LPTSTR HashUserInfo(LPCTSTR strUserName, LPCTSTR strPassword, 
		LPCTSTR strHighMark, LPCTSTR strLowMark);
};
