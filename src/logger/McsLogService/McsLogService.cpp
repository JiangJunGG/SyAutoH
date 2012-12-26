// McsLogService.cpp : WinMain ��ʵ��


#include "stdafx.h"
#include "resource.h"
#include "McsLogService_i.h"
#include "../LogServer/LogServer.h"

#include <stdio.h>

class CMcsLogServiceModule : public ATL::CAtlServiceModuleT< CMcsLogServiceModule, IDS_SERVICENAME >
	{
	private:
		CLogServer m_logServer;
public :
	DECLARE_LIBID(LIBID_McsLogServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MCSLOGSERVICE, "{C77C1787-EC6E-4058-966E-46EEA1CF6FA1}")
		HRESULT InitializeSecurity() throw()
	{
		// TODO : ���� CoInitializeSecurity ��Ϊ�����ṩ�ʵ��İ�ȫ����
		// ���� - PKT ����������֤��
		// RPC_C_IMP_LEVEL_IDENTIFY ��ģ�⼶��
		// �Լ��ʵ��ķ� null ��ȫ˵������

		return S_OK;
	}
		HRESULT PreMessageLoop(int nShowCmd) throw()
		{
			//m_status.dwControlsAccepted =m_status.dwControlsAccepted | SERVICE_ACCEPT_PAUSE_CONTINUE;
			HRESULT hr = __super::PreMessageLoop(nShowCmd);
			if (hr == S_FALSE) hr = S_OK; //Ҫ����������ȥ
			//pWork=new CWorkThread();
			m_logServer.Init();
			//MessageBox(NULL, L"Start Service", L"Error", MB_ICONEXCLAMATION | MB_OK);

			return hr;
		}

		void OnStop() throw()
		{
			m_logServer.End();
			//MessageBox(NULL, L"Stop Service", L"Error", MB_ICONEXCLAMATION | MB_OK);
			__super::OnStop();
		}
	};

CMcsLogServiceModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

