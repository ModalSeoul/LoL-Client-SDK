#include <Windows.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	DWORD l_dBase = 0x016B6B00;
	DWORD l_dDynamic;
	float GetMaxMana();
	float GetCurrentMana();
	float GetMaxHealth();
	float GetCurrentHealth();
	void SetDynamic(DWORD address) { l_dDynamic = address; }
	DWORD GetDynamic()			   { return l_dDynamic;	   }
};

#endif