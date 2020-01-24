#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>

extern void init_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);
extern void deinit_halo_reach(EngineVersion engineVersion, BuildVersion buildVersion);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	Window::SetIcon(LoadIconA(hInstance, MAKEINTRESOURCEA(IDI_ICON1)));
	SystemPatch::PatchEnumWindows();

	/* LEGACY */
	GameLauncher::RegisterGameStartupCallback(init_halo_reach);		// setup reach hooks and deinit them
	GameLauncher::RegisterGameShutdownCallback(deinit_halo_reach);	// setup reach hooks and deinit them
	
	void(*UICallback)() = []()
	{
		//SIZE size = {};
		//Window::GetWindowSize(size);
		MantleGUI::Render(1024, 768);
		GameLauncher::OpusUITick();
	};

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		Render::BeginFrame(clearColor);
		GameLauncher::OpusTick();
		Render::EndFrame();
	};
	
	Window::Init("Opus", "OpusConsole", "opus");
	Render::Init(hInstance);
	MantleGUI::Init(true);
	GameLauncher::Init();

	MantleGUI::RegisterOnCloseCallback([]() { s_running = false; });
	DebugUI::RegisterCallback(UICallback);
	Window::SetOnUpdateCallback(UpdateCallback);
	Window::SetOnDestroyCallback([]() { s_running = false; });

	DebugUI::Show();
	while (s_running) Window::Update();
	DebugUI::UnregisterCallback(UICallback);

	GameLauncher::Deinit();
	MantleGUI::Deinit();
	Render::Deinit();
	Window::Deinit();

	return 0;
}