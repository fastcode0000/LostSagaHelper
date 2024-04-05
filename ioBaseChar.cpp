#include "StdAfx.h"
#include "ioBaseChar.h"
#include "MemoryManager.h"

ioBaseChar::ioBaseChar()
{

}

ioBaseChar::~ioBaseChar()
{

}

int ioBaseChar::GetState()
{
	return m_iCharState;
}

ioHashString ioBaseChar::GetPublicID()
{
	return m_szName;
}

D3DXVECTOR3 ioBaseChar::GetPosition()
{
	DWORD Buf = g_Memory.RPM<DWORD>((DWORD) & m_pPosition);
	Buf = g_Memory.RPM<DWORD>(Buf + 0x8);

	D3DXVECTOR3 k(g_Memory.RPM<float>(Buf + 0x3C), g_Memory.RPM<float>(Buf + 0x40), g_Memory.RPM<float>(Buf + 0x44));
	return k;
}

bool ioBaseChar::IsOwnerChar() const
{
	return m_bOwnerChar;
}

float ioBaseChar::GetSkillGauge(int iState)
{
	float fSkillGauge = 0.f;
	if (iState > 8)
	{
		return fSkillGauge;
	}

	const ioItem* pItem = m_pEquipSlot->m_EquipItemSlot[iState];
	if (pItem)
	{
		fSkillGauge = pItem->m_fCurSkillGauge;
	}

	return fSkillGauge;
}