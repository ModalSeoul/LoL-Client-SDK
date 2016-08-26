#include "stdafx.h"
#include "Utils.h"
#include "Header.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

// TODO(algernon@teknik.io): WHY DOES THIS NOT WORK FUCK(make this work)
DWORD Utils::IterateProcessMemory(HANDLE hProc, DWORD baseAddress, DWORD offsets[])
{
	DWORD currentAddress = baseAddress;
	DWORD aTemp;
	std::vector<DWORD> historicals;
	std::cout << "BaseAddress: 0x" << std::hex << baseAddress << std::endl;
	for (int i = 0; i < sizeof(offsets); i++)
	{
		if (i == 0)
		{
			ReadProcessMemory(hProc, (LPVOID)currentAddress, &aTemp, sizeof(aTemp), NULL);
			historicals.push_back(aTemp);
			std::cout << "Points to: 0x" << std::hex << historicals[i] << std::endl;
			continue;
		}
		ReadProcessMemory(hProc, (LPVOID)(aTemp + offsets[i - 1]), &aTemp, sizeof(aTemp), NULL);
		historicals.push_back(aTemp);
		std::cout << "With offset 0x" << std::hex << offsets[i - 1] << std::endl << " -> Points to: 0x" << std::hex << historicals[i - 1] + offsets[i - 1] << std::endl;
	}
	std::cout << "Value pointed to by pointer chain: 0x" << std::hex << aTemp << std::endl;
	return aTemp;
}


HANDLE Utils::GetProcess() {
	HWND windowHandle = FindWindowA(0, "League of Legends (TM) Client");

	if (windowHandle == NULL)
	{
		MessageBoxA(0, "Game's not open? : ^(", "Error:(", MB_OK);
	}

	if (windowHandle != NULL)
	{
		DWORD pId;
		GetWindowThreadProcessId(windowHandle, &pId);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);

		if (!hProcess)
		{
			MessageBoxA(NULL, "Cannot open process!", "Error!", MB_OK + MB_ICONERROR);
			return NULL;
		}
		m_Utils.SetProcess(hProcess);
		return hProcess;
	}
	return NULL;
}