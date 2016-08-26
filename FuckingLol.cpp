#include "stdafx.h"
#include "Header.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Drawing m_Drawing;

int main()
{
	// Example
	while (1) {
		HANDLE hProcess = m_Utils.ReturnProcess();
		float _mana = m_Player.GetCurrentMana();
		float _health = m_Player.GetCurrentHealth();
		cout << "Current Health: " << _health << endl;
		cout << "Current Mana: " << _mana << endl;
		m_Drawing.DrawRect();
		//Sleep(1);
	}
	return 0;
}
