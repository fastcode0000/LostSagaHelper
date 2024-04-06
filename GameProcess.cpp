#include "StdAfx.h"
#include "GameProcess.h"
#include "MemoryManager.h"
#include "ioBaseChar.h"
#include "Offset.h"

using namespace std;

template<> GameManager* Singleton<GameManager>::ms_Singleton = 0;

GameManager& GameManager::GetSingleton()
{
	return Singleton<GameManager>::GetSingleton();
}

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

bool GameManager::MemoryInit()
{
	//DWORD dwMemoryInitTime = GetTickCount();
	//while (true)
	//{
	//	DWORD dwAddress = 0;
	//	dwAddress = g_Memory.AobScan("8D 4E 20 88 5D FC E8 ?? ?? ?? ?? 89 1D ?? ?? ?? ?? 8B 4D F4 64 89 0D 00 00 00 00 59 5F 5E 5B", 0x01200000, 0x01500000) + 0xB;
	//	string szOperand = g_Memory.GetOperand(dwAddress, 0);
	//	m_dwApp = g_Memory.ParseOperand(szOperand);

	//	if (m_dwApp != 0)
	//	{
	//		break;
	//	}

	//	DWORD dwGapTime = GetTickCount() - dwMemoryInitTime;
	//	if (dwGapTime > 10000) //10초이상 값을 못찾을 경우
	//	{
	//		dwMemoryInitTime = GetTickCount();
	//		return false;
	//	}

	//	Sleep(100);
	//}

	return true;
}

void GameManager::GameProcess()
{
	while (true)
	{
		//if (GetAsyncKeyState(VK_INSERT) & 1)
		//{
		//	ioBaseChar* pOwner = GetOwnerChar();
		//	if (pOwner)
		//	{
		//		cout << "CurSkill : " << pOwner->GetCurSkillByIndex(EquipSlot::ES_WEAPON) << endl;
		//		cout << "MaxSkill : " << pOwner->GetMaxSkillByIndex(EquipSlot::ES_WEAPON) << endl;
		//	}
		//}

		ioBaseChar* pOwner = GetOwnerChar();
		if (pOwner)
		{
			if (pOwner->HasSkill(EquipSlot::ES_WEAPON)) printf("Has Weapon Skill");
			if (pOwner->HasSkill(EquipSlot::ES_ARMOR)) printf("Has Armor Skill");
			if (pOwner->HasSkill(EquipSlot::ES_HELMET)) printf("Has Helmet Skill");
			if (pOwner->HasSkill(EquipSlot::ES_CLOAK)) printf("Has Cloak Skill");

		}


		//for (int i = 0; i < 32; i++)
		//{
		//	ioBaseChar* pChar = GetBaseChar(i * 0x4);
		//	if (!pChar) //pChar 가 없다면, 마지막 번호이므로 종료
		//	{
		//		break;
		//	}

		//	if (pChar->GetState() == 7) //스킬을 사용중이다
		//	{
		//		cout << pChar->GetPublicID().c_str() << " 님이 스킬을 사용함." << endl;
		//		ioBaseChar* pOwner = GetOwnerChar();
		//		if (pOwner)
		//		{
		//			char szBuf[MAX_PATH];
		//			sprintf(szBuf, "내 스킬 게이지 : %f, %f, %f, %f", pOwner->GetSkillGauge(0), pOwner->GetSkillGauge(1), pOwner->GetSkillGauge(2), pOwner->GetSkillGauge(3));
		//			cout << szBuf << endl;
		//			//CHECK
		//		}
		//	}
		//}

		Sleep(100);
	}
}

ioBaseChar* GameManager::GetBaseChar(int iOffset)
{
	DWORD c_C = NULL;

	if (IsBadReadPtr((PDWORD)PlayerBase, DM_PROMPT) == NULL)
	{
		c_C = *(PDWORD)((DWORD)(PlayerBase)) + OFS_USERBASE_1;
		if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
		{
			c_C = *(PDWORD)((DWORD)(c_C)) + OFS_USERBASE_2;
			if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
			{
				c_C = *(PDWORD)((DWORD)(c_C)) + iOffset;
				if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
				{
					c_C = *(PDWORD)((DWORD)(c_C)) + OFS_USERBASE_4;
					if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
					{
						c_C = *(PDWORD)((DWORD)(c_C)) + OFS_USERBASE_5;
						if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
						{
							c_C = *(PDWORD)((DWORD)(c_C)) + 0;
							if (IsBadReadPtr((PDWORD)c_C, DM_PROMPT) == NULL)
							{
								return (ioBaseChar*)c_C;
							}
						}
					}
				}
			}
		}
	}

	return nullptr;
}

ioBaseChar* GameManager::GetOwnerChar()
{
	for (int i = 0; i < 32; i++)
	{
		ioBaseChar* pChar = GetBaseChar(i * 0x4);
		if (pChar->IsOwnerChar())
		{
			return pChar;
		}
	}
	return nullptr;
}

int GameManager::GetBaseCharSize()
{
	int iCnt = 0;

	ioBaseChar* pOwner = GetOwnerChar();
	if (pOwner)
	{
		ioPlayStage* pStage = pOwner->m_pCreator;
		if (pStage)
		{
			BaseCharList::iterator iter = pStage->m_BaseCharList.begin();

			for (; iter != pStage->m_BaseCharList.end(); ++iter)
			{
				iCnt++;
			}
		}

	}

	return iCnt;
}
