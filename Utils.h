#include <Windows.h>

#ifndef UTILS_H
#define UTILS_H

class Utils {
public:	
	DWORD IterateProcessMemory(HANDLE hProc, DWORD baseAddress, DWORD offsets[], int depth);
	HANDLE Process;
	HANDLE GetProcess();
	void SetProcess(HANDLE hProcess) {
		Process = hProcess;
	}
	HANDLE ReturnProcess() {
		return Process;
	}
};

#endif