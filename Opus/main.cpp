#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>

extern void init_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);
extern void deinit_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	Window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	SystemPatch::PatchEnumWindows();

	/* LEGACY */
	GameLauncher::RegisterGameStartupCallback(init_halo_reach);		// setup reach hooks and deinit them
	GameLauncher::RegisterGameShutdownCallback(deinit_halo_reach);	// setup reach hooks and deinit them

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		Render::BeginFrame(true, &clearColor.x);
		GameLauncher::OpusTick();
		Render::EndFrame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	Window::Init("Opus", "OpusConsole", "opus");
	Render::Init(hInstance);
	MantleGUI::Init(true);
	GameLauncher::Init();

	Window::RegisterUpdateCallback(UpdateCallback);
	Window::RegisterDestroyCallback(DestroyCallback);
	//MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	while (s_running) Window::Update();

	Window::UnregisterUpdateCallback(UpdateCallback);
	Window::UnregisterDestroyCallback(DestroyCallback);
	//MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	GameLauncher::Deinit();
	MantleGUI::Deinit();
	Render::Deinit();
	Window::Deinit();

	return 0;
}