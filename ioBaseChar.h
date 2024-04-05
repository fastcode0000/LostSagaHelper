#pragma once
#include "ioHashString.h"
#include "EncryptValue.h"
#include "CharacterInfo.h"
#include <map>
#include <vector>

class ioItem //1120전체크기
{
public:
	char Buffer1[45];

	int		m_iItemGroupIndex;
	DWORD	m_dwItemCode;

	char Buffer2[528];

	ioHashString m_OwnerName;

	DWORD m_dwSetItemCode;

	char Buf2[49];

	CEncrypt<float> m_fChangeSkillHPRate;
	CEncrypt<float> m_fChangeSkillExtendGauge;

	char Buffer3[76];

	int m_SkillGaugeType;
	CEncrypt<bool> m_bHasSkillGauge;
	CEncrypt<bool> m_bUpdateEnableSkillGauge;
	CEncrypt<float> m_fMaxSkillGauge;
	CEncrypt<float> m_fCurSkillGauge;
	CEncrypt<float> m_fRecoverSkillGauge;
	CEncrypt<float> m_fDefaultGauge;
};

class ioEquipSlot
{
public:
	ioItem* m_EquipItemSlot[9];
};

//2432
class ioBaseChar
{
public:
	char Buffer0[464];
	//좌표읽기
	DWORD m_pPosition;
	char Buffer1[260];
	DWORD m_dwIndex;
	int m_iLevel;
	int m_iClassLevel;
	ioHashString m_szName; //16 byte
	ioHashString m_szViewName;

	DWORD m_dwNPCIndex;
	DWORD m_dwUserIndex;

	int m_iCharState; //0x308 776
	int m_iPreCharState;
	int m_iNextCharState;

	char Buffer2[4];

	int m_iLandType;

	int m_iRaceType;

	bool m_bMale;

	int m_iSelectCharArray;

	char Buffer3[24];

	bool m_bJumpAttackEnable;

	//
	void* m_pCreator; //ioPlayStage
	ioEquipSlot* m_pEquipSlot; //ioEquipSlot 여기서 스킬

	char Buffer4[12];

	//CHARACTER
	CHARACTER m_CharInfo;

	char Buffer5[40];


	D3DXQUATERNION m_qtTargetRot;
	D3DXVECTOR3	   m_vMoveDir;
	D3DXVECTOR3	   m_vInputDir; //2432

	char Buffer6[3260];
	bool m_bOwnerChar;
	//0x163C,	5692

	char Buffer7[37];

	ioHashString m_LastAttackerName;
	ioHashString m_LastAttackerSkillName;
	int m_iLastAttackerTeam;
	DWORD m_dwLastAttackerItemCode;

public:

	int GetState(); //모션
	ioHashString GetPublicID();

	D3DXVECTOR3 GetPosition();

	bool IsOwnerChar();

	float GetSkillGauge(int iState);

public:
	ioBaseChar();
	~ioBaseChar();
};