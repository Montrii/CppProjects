#include <iostream>
#include <string>
#include <vector>

#include <windows.h>
#include <tlhelp32.h>

bool isNotepad(const PROCESSENTRY32W &entry) {
	return std::wstring(entry.szExeFile) == L"gta_sa.exe";
}

BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lParam) {
	const auto &pids = *reinterpret_cast<std::vector<DWORD>*>(lParam);

	DWORD winId;
	GetWindowThreadProcessId(hwnd, &winId);

	for (DWORD pid : pids) {
		if (winId == pid) {
			std::wstring title(GetWindowTextLength(hwnd) + 1, L'\0');
			GetWindowTextW(hwnd, &title[0], title.size()); //note: C++11 only

			std::cout << "Found window:\n";
			std::cout << "Process ID: " << pid << '\n';
			std::wcout << "Title: " << title << "\n\n";


			HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); 
			DWORD value = NULL;
			SIZE_T *v = NULL;
			ReadProcessMemory(handle, (LPVOID)(0xB7CE50 + 0x2680), &value, sizeof(value), v);


			std::cout << "PLAYER CASH: " << value << std::endl;

			DWORD isPlayMission = NULL;

			ReadProcessMemory(handle, (LPVOID)(0xBAA420 + 0x2680), &isPlayMission, sizeof(isPlayMission), v);

			std::cout << "IS PLAYER PLAYING MISSION " << isPlayMission << std::endl;
		}
	}

	return TRUE;
}

int main() {
	std::vector<DWORD> pids;

	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	// Do use a proper RAII type for this so it's robust against exceptions and code changes.
	auto cleanupSnap = [snap] { CloseHandle(snap); };

	PROCESSENTRY32W entry;
	entry.dwSize = sizeof entry;

	if (!Process32FirstW(snap, &entry)) {
		cleanupSnap();
		return 0;
	}

	do {
		if (isNotepad(entry)) {
			pids.emplace_back(entry.th32ProcessID);
		}
	} while (Process32NextW(snap, &entry));
	cleanupSnap();

	EnumWindows(enumWindowsProc, reinterpret_cast<LPARAM>(&pids));
}