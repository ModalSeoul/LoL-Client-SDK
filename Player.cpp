#include "stdafx.h"
#include "Player.h"
#include "Utils.h"
#include <Windows.h>
#include <iostream>

Player m_Player;
Utils m_Utils;

using namespace std;

Player::Player()
{
	DWORD pTemp;
	HANDLE hProcess = m_Utils.GetProcess();
	ReadProcessMemory(hProcess, (LPVOID)0x016B6B00, &pTemp, sizeof(pTemp), NULL);
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(pTemp + 0x18), &pTemp, sizeof(pTemp), NULL);
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(pTemp + 0x4), &pTemp, sizeof(pTemp), NULL);
	cout << hex << pTemp << endl;
	this->SetDynamic(pTemp);
}

// TODO(algernon@teknik.io): Clean up this abysmal shit
float Player::GetCurrentMana()
{
	float mana;
	DWORD playerBase = this->GetDynamic();
	HANDLE hProcess = m_Utils.ReturnProcess();
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(playerBase + 0x54), &mana, sizeof(mana), NULL);
	return mana;
}

float Player::GetMaxMana()
{
	float mana;
	DWORD playerBase = this->GetDynamic();
	HANDLE hProcess = m_Utils.ReturnProcess();
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(playerBase + 0x58), &mana, sizeof(mana), NULL);
	return mana;
}

float Player::GetCurrentHealth()
{
	float health;
	DWORD playerBase = this->GetDynamic();
	HANDLE hProcess = m_Utils.ReturnProcess();
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(playerBase + 0x158), &health, sizeof(health), NULL);
	return health;
}

float Player::GetMaxHealth()
{
	float health;
	DWORD playerBase = this->GetDynamic();
	HANDLE hProcess = m_Utils.ReturnProcess();
	ReadProcessMemory(hProcess, (LPVOID)(DWORD)(playerBase + 0x15C), &health, sizeof(health), NULL);
	return health;
}