#include "stdafx.h"
#include "Utils.h"
#include "Header.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

// TODO(algernon@teknik.io): WHY DOES THIS NOT WORK FUCK(make this work)
DWORD Utils::IterateProcessMemory(HANDLE hProc, DWORD baseAddress, DWORD offsets[], int depth)
{
	DWORD aTemp;
	vector<DWORD> historicals;
	for (int i = 0; i <= depth; i++) {
		if (i == 0) {
			ReadProcessMemory(hProc, (LPVOID)0x016B6B00, &aTemp, sizeof(aTemp), NULL);
			historicals.push_back(aTemp);
		}
		ReadProcessMemory(hProc, (LPVOID)(DWORD)(historicals[i] + offsets[i]), &aTemp, sizeof(aTemp), NULL);
		historicals.push_back(aTemp);
		cout << offsets[i] << endl << historicals[i] << endl;
	}
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