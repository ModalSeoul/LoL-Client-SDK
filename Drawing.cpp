#include "stdafx.h"
#include "Header.h"
#include <Windows.h>
#include <iostream>

int Drawing::DrawRect()
{
	std::cout << "shit" << std::endl;
	HWND leagueWindow = FindWindowA(0, "League of Legends (TM) Client");
	HDC hLeague = GetDC(leagueWindow);
	HBRUSH c_RED = CreateSolidBrush(RGB(255, 0, 0));
	RECT mainRect = { 100, 100, 200, 200 };
	FillRect(hLeague, &mainRect, c_RED);
	if (WM_ERASEBKGND) {
		return 1;
	}
}