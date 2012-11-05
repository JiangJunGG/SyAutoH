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

#pragma  once
// �����Ǵ� AMHSDrive.dll ������

typedef struct  sVec_OHT
{
	int nID;
	int nPOS;
	int nHand;
	int nStatusTime;
	int nPosTime;
	int nPathResult;
	int nMoveStatus;
	int nMoveAlarm;
	int nFoupOpt;
	int nBackStatusMode;
	int nBackStatusMark;
	int nBackStausAlarm;
	bool  bNeedPath;
} driveOHT;
#include <vector>
#include <map>
typedef std::vector<driveOHT> DR_OHT_LIST;

typedef struct sPathKeyPoint
{
	int nPos;
	int nType;
	int nSpeedRate;
} keyPoint;
typedef std::vector<keyPoint> PATH_POINT_LIST;

class AMHSPacket;
class AMHSDRIVE_API CAMHSDrive {
public:
	CAMHSDrive(void);
	~CAMHSDrive();

	int Init();
	int Check();
	int Clean();

	DR_OHT_LIST GetOhtList();
	void OHTStatusBackTime(int nID, int ms);
	void OHTPosBackTime(int nID, int ms);
	void OHTMove(int nID, int nControl);
	void OHTFoup(int nID, int nDevBuf, int nOperation);
	void OHTSetPath(int nID, int nType, int nStart, int nTarget, PATH_POINT_LIST& KeyPoints);

	int SetOHTLocation(int nPoint);
};
