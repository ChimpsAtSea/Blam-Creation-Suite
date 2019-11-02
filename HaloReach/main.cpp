#include "haloreach-private-pch.h"

void EnsureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir = "")
{
	HMODULE hModule = GetModuleHandleA(pLibName);
	if (!hModule)
	{
		hModule = LoadLibraryA(pLibName);

		// use fallback if 
		if (!hModule && pFallbackDir[0])
		{
			char fallbackPath[MAX_PATH] = {};
			sprintf(fallbackPath, "%s\\%s", pFallbackDir, pLibName);
			hModule = GetModuleHandleA(fallbackPath);
			if (!hModule)
			{
				hModule = LoadLibraryA(fallbackPath);
			}
		}
	}
	if (!hModule)
	{
		MessageBox(CustomWindow::GetWindowHandle(), pLibName, "failed to load library", MB_ICONERROR);
	}
	assert(hModule);
}

extern void init_halo_reach(HaloGameID gameID);
extern void deinit_halo_reach(HaloGameID gameID);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	EnsureBink2Win64IsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");

	GameLauncher::RegisterGameLaunchCallback(HaloGameID::HaloReach_2019_Jun_24, init_halo_reach);
	GameLauncher::RegisterGameLaunchCallback(HaloGameID::HaloReach_2019_Aug_20, init_halo_reach);
	GameLauncher::RegisterGameLaunchCallback(HaloGameID::HaloReach_2019_Oct_30, init_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(HaloGameID::HaloReach_2019_Jun_24, deinit_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(HaloGameID::HaloReach_2019_Aug_20, deinit_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(HaloGameID::HaloReach_2019_Oct_30, deinit_halo_reach);

	CustomWindow::SetIcon(LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1)));

	GameInterface gameInterface = GameInterface("haloreach.dll");
	int result = GameLauncher::Run(hInstance, lpCmdLine, gameInterface);
	return result;
}