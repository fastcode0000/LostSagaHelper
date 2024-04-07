#pragma once
#include "CPacket.h"

struct CHARACTER;
struct ControlKeys;

class SP2Packet : public CPacket
{
public:
	// >> ������ current_pos �̵�
	void  MovePointer(DWORD dwMoveBytes);
	DWORD StrToDwordIP(char* iip);
	void  DwordToStrIP(DWORD dwIP, char* iip);
	void  InitCurPos();

public:
	SP2Packet& operator = (SP2Packet& packet);
public:
	SP2Packet& operator << (BYTE arg);
	SP2Packet& operator << (bool arg);
	SP2Packet& operator << (int arg);
	SP2Packet& operator << (LONG arg);
	SP2Packet& operator << (WORD arg);
	SP2Packet& operator << (DWORD arg);
	SP2Packet& operator << (__int64 arg);
	SP2Packet& operator << (LPTSTR arg);
	SP2Packet& operator << (double arg);
	SP2Packet& operator << (float arg);
	SP2Packet& operator << (short arg);
	SP2Packet& operator << (const char* arg);

public:
	SP2Packet& operator >> (BYTE& arg);
	SP2Packet& operator >> (bool& arg);
	SP2Packet& operator >> (int& arg);
	SP2Packet& operator >> (LONG& arg);
	SP2Packet& operator >> (WORD& arg);
	SP2Packet& operator >> (DWORD& arg);
	SP2Packet& operator >> (__int64& arg);
	SP2Packet& operator >> (LPTSTR arg);
	SP2Packet& operator >> (double& arg);
	SP2Packet& operator >> (float& arg);
	SP2Packet& operator >> (short& arg);


public:
	SP2Packet();
	SP2Packet(SP2Packet& rhs);
	SP2Packet(DWORD dwID);
	SP2Packet(char* szBuf, int iSize);
	SP2Packet(char* szIP, DWORD dwPort, DWORD dwUserIndex, int iIndex, const SP2Packet& rhs);
	virtual ~SP2Packet();
};