// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� PATHFINDER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// PATHFINDER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef PATHFINDER_EXPORTS
#define PATHFINDER_API __declspec(dllexport)
#else
#define PATHFINDER_API __declspec(dllimport)
#pragma comment(lib, "pathfinder.lib")
#endif

#pragma once
#include <vector>
typedef std::vector<int> INT_LIST;

class CPathProductor;
// �����Ǵ� PathFinder.dll ������
class PATHFINDER_API CPathFinder 
{
public:
	CPathFinder(void);
	~CPathFinder();

	INT_LIST GetPath(int nFrom, int nTo);
	void Init();

private: 
	CPathProductor* m_pProductor;
public:
	void Test(void);
};
