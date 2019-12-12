#include <HaloReachLib\haloreachlib-private-pch.h>
#include <steam/steam_api.h>

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

extern void init_halo_reach(BuildVersion buildVersion);
extern void deinit_halo_reach(BuildVersion buildVersion);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	{
		FILE *pAppIDFile = fopen("steam_appid.txt", "w");
		assert(pAppIDFile);
		constexpr const char *pAppId = "976730";
		fwrite(pAppId, sizeof(char), strlen(pAppId), pAppIDFile);
		fclose(pAppIDFile);
	}

	bool steamAPIInitResult = SteamAPI_Init();
	if (!steamAPIInitResult)
	{
		MessageBox(NULL, "Fatal Error - Steam failed to initialize", "Fatal Error", MB_OK | MB_ICONWARNING);
		return 1;
	}

	EnsureBink2Win64IsLoaded("bink2w64.dll", "..\\MCC\\Binaries\\Win64");

	GameLauncher::RegisterGameLaunchCallback(BuildVersion::Build_1_887_0_0, init_halo_reach);
	GameLauncher::RegisterGameLaunchCallback(BuildVersion::Build_1_1035_0_0, init_halo_reach);
	GameLauncher::RegisterGameLaunchCallback(BuildVersion::Build_1_1186_0_0, init_halo_reach);
	GameLauncher::RegisterGameLaunchCallback(BuildVersion::Build_1_1211_0_0, init_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(BuildVersion::Build_1_887_0_0, deinit_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(BuildVersion::Build_1_1035_0_0, deinit_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(BuildVersion::Build_1_1186_0_0, deinit_halo_reach);
	GameLauncher::RegisterGameShutdownCallback(BuildVersion::Build_1_1211_0_0, deinit_halo_reach);

	CustomWindow::SetIcon(LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_ICON1)));

	GameInterface gameInterface = GameInterface("HaloReach\\haloreach.dll");
	int result = GameLauncher::Run(hInstance, lpCmdLine, gameInterface);
	return result;
}