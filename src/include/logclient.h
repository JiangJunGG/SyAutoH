// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LOGCLIENT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LOGCLIENT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LOGCLIENT_EXPORTS
#define LOGCLIENT_API __declspec(dllexport)
#else
#define LOGCLIENT_API __declspec(dllimport)

#pragma comment(lib, "logclientwin.lib")

#endif

#include "LogDef.h"

//LOGCLIENT_API void Log(unsigned long EventID, unsigned short wUnitID, unsigned short wStationID, unsigned short wParam1 = 0, unsigned short wParam2 = 0, unsigned long lParam1 = 0, unsigned long lParam2 = 0, unsigned long lParam3 = 0);
//LOGCLIENT_API void LogF(unsigned long EventID, unsigned short wUnitID, unsigned short wStationID, unsigned short wParam1 = 0, unsigned short wParam2 = 0, float lParam1 = 0.0, float lParam2 = 0.0);
//LOGCLIENT_API void LogS(unsigned long EventID, unsigned short wUnitID, unsigned short wStationID, const TCHAR * pStr);
//LOGCLIENT_API void LogS(unsigned long EventID, unsigned short wUnitID, unsigned short wStationID, unsigned short wParam1, unsigned short wParam2, const TCHAR * pStr);

// 
// Log sample : LogS(LID_SYS_ERR, LogType::Error, SYS_MODULE, "your message");
//

extern "C"
{
// log
LOGCLIENT_API void LogS(unsigned long EventID,  UCHAR type, const CHAR * pUnit, const CHAR * pStr);

// ȡ�ñ�����Ŀ. 
// �������ֵС��0,˵��û�����ӵ���־������. 
// ����ֵ���ڵ�0ʱ,���Ƿ���������ʵ�ı�����Ϣ��Ŀ. 0˵��û�б�����Ϣ.
LOGCLIENT_API int GetAlarmCount();

// ȡ�����һ����־��Ϣ�����. 
// �������ֵС��0,˵��û�����ӵ���־������. 
// ����ֵ����0ʱȡ�����һ����־�������Ϣ, �������LogDef.h.
LOGCLIENT_API int GetLastType();

// by zjh 2010.6.4
LOGCLIENT_API int __cdecl LogF(const char *format, ...);


};

