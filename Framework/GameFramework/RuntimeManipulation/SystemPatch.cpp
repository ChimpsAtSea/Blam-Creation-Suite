#include "gameframework-private-pch.h"

bool SystemPatch::s_patchedEnumWindows = false;

thread_local WNDENUMPROC s_lpEnumFunc = nullptr;
thread_local bool s_processedWindow = false;

BOOL CALLBACK EnumWindowsSort(HWND hWnd, LPARAM lParam)
{
	bool isExcluded = false;
	isExcluded |= hWnd == GetConsoleWindow();

	if (hWnd == c_window_win32::get_window_handle())
	{
		s_processedWindow = true;
	}

	if (isExcluded)
	{
		return TRUE;
	}

	return s_lpEnumFunc(hWnd, lParam);
}

typedef BOOL(EnumWindowsFunc)(WNDENUMPROC lpEnumFunc, LPARAM lParam);
EnumWindowsFunc* EnumWindowsPointer = nullptr;
BOOL EnumWindowsHook(
	WNDENUMPROC lpEnumFunc,
	LPARAM      lParam
)
{
	ASSERT(s_lpEnumFunc == nullptr);
	ASSERT(EnumWindowsPointer != nullptr);

	s_processedWindow = false;
	s_lpEnumFunc = lpEnumFunc;

	BOOL result = EnumWindowsPointer(EnumWindowsSort, lParam);
	s_lpEnumFunc = nullptr;
	return result;
}

void SystemPatch::PatchEnumWindows()
{
	if (!s_patchedEnumWindows)
	{
		s_patchedEnumWindows = true;

		init_detours();
		create_dll_hook("USER32.dll", "EnumWindows", EnumWindowsHook, EnumWindowsPointer);
		end_detours();
	}
}

