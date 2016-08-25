#include "stdafx.h"
#include "Player.h"
#include "Header.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	// Example
	while (1) {
		float _mana = m_Player.GetCurrentMana();
		float _health = m_Player.GetCurrentHealth();
		cout << "Current Health: " << _health << endl;
		cout << "Current Mana: " << _mana << endl;
		Sleep(500);
	}
}
