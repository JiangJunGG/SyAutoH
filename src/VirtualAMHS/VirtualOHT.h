#pragma once
#include "VirtualAMHSDevice.h"
class VirtualOHT : public VirtualAMHSDevice
{
public:
	VirtualOHT(void);
	virtual ~VirtualOHT(void);
	
public:
	int Auth( int nPos, int nHand);
	int UpdatePos(uint16 nPos);
	virtual void HandleCommand(AMHSPacket& packet);

private:
	void Handle_Auth(AMHSPacket& );
	void Handle_SetPosTime(AMHSPacket& );
	
private:
	typedef void (VirtualOHT::*CommandHander)(AMHSPacket& packet);
	typedef std::map<int, CommandHander> OPT_MAP;
	OPT_MAP m_optHanders;

public:
	int m_nHand;
	int m_nPos;
	int m_nPosUpdateTime;
	int m_nStatusUpdateTime;
	int m_nPosTimerID;
	void CreatePosTimer(void);
	void DestoryPosTimer(void);
	static void CALLBACK PosTimerHandler(UINT id, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2);
	void OnPosTimer(void);
};
