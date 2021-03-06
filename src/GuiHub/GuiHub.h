// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 GUIHUB_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// GUIHUB_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef GUIHUB_EXPORTS
#define GUIHUB_API __declspec(dllexport)
#else
#define GUIHUB_API __declspec(dllimport)
#endif

#pragma once
#include "../common/iConstDef.h"

class UserManagementServer;
class GuiDataHubServer;
class CAMHSDrive;
// 此类是从 GuiHub.dll 导出的
class GUIHUB_API CGuiHub {
public:
	CGuiHub(void);
	~CGuiHub();
private:
	UserManagementServer* m_pUserMgt;
	GuiDataHubServer*				m_pGuiDataHub;
public:

	int StartServer(CAMHSDrive* pDrive);
	void SetData(MCS::GuiHub::PushData nTag, const char* chVal);
};
