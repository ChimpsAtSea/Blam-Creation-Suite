#ifdef UNICODE
#undef UNICODE
#endif

#include <cstdio>
#include <windows.h>
#include <detours.h>

#define MCC_PATH "MCC\\Binaries\\Win64\\"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//char pOpusDLLPath[MAX_PATH] = {}; //opus.dll
	//{
	//	char pDirectoryPath[MAX_PATH] = {};
	//	GetCurrentDirectory(MAX_PATH, pDirectoryPath);
	//	sprintf_s(pOpusDLLPath, MAX_PATH, "opus.dll", pDirectoryPath);
	//}

	STARTUPINFO startupInfo = {};
	startupInfo.cb = sizeof(STARTUPINFO);

	PROCESS_INFORMATION processInformation = {};
	
	DetourCreateProcessWithDll(
		MCC_PATH "MCC-Win64-Shipping.exe",
		lpCmdLine,
		NULL,
		NULL,
		FALSE,
		CREATE_DEFAULT_ERROR_MODE, 
		NULL, 
		NULL,
		&startupInfo, 
		&processInformation, 
		"opus.dll",
		NULL);

	return 0;
}