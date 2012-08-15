// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ICECLIENTBASE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ICECLIENTBASE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ICECLIENTBASE_EXPORTS
#define ICECLIENTBASE_API __declspec(dllexport)
#else
#define ICECLIENTBASE_API __declspec(dllimport)


#ifdef _DEBUG
		#pragma comment(lib,"IceBase.lib")
		#pragma comment(lib,"Iced.lib")
		#pragma comment(lib,"Iceutild.lib")
#else
		#pragma comment(lib,"IceBase.lib")
		#pragma comment(lib,"Ice.lib")
		#pragma comment(lib,"Iceutil.lib")
	#endif
#endif

#pragma once

#include <string>
#include "ice/Ice.h"

using namespace std;

// �����Ǵ� IceClientBase.dll ������
string ICECLIENTBASE_API GetProcessPath();

class ICECLIENTBASE_API CIceClientBase 
{
public:
	CIceClientBase();
	virtual ~CIceClientBase(void);

	void InitIce(void);
	void EndIce(void);

public:
	Ice::CommunicatorPtr m_communicator;
	Ice::ObjectAdapterPtr m_adapter;

	string m_strConfigFileName;
	string m_strProxy;

protected:
	Ice::ObjectPrx m_objPrx;	
	
	virtual void GetProxy(void) = 0;
	
public:
	std::string ConfigFileName() const { return m_strConfigFileName; }
	void ConfigFileName(std::string val) { m_strConfigFileName = val; }
	
	std::string Proxy() const { return m_strProxy; }
	void Proxy(std::string val) { m_strProxy = val; }

};

class  ICECLIENTBASE_API CIceServerBase
{
public:
	CIceServerBase(void);
	virtual ~CIceServerBase(void);

	void InitIce(void);
	void EndIce(void);

public:
	Ice::CommunicatorPtr m_communicator;
	Ice::ObjectAdapterPtr m_adapter;

	string m_strConfigFileName;
	string m_strProxy;

protected:
	Ice::ObjectPtr m_objPtr;	

	virtual void GetProxy(void) = 0;

public:
	std::string ConfigFileName() const { return m_strConfigFileName; }
	void ConfigFileName(std::string val) { m_strConfigFileName = val; }

	std::string Proxy() const { return m_strProxy; }
	void Proxy(std::string val) { m_strProxy = val; }
};
