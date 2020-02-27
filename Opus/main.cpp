#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <OpusFramework\opusframework-private-pch.h>

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

const char* c_console::s_consoleExecutableName = "Opus";

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	register_platforms();

	c_console::Init();

	c_window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	SystemPatch::PatchEnumWindows();

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		c_render::BeginFrame(true, &clearColor.x);
		GameLauncher::OpusTick();
		c_render::EndFrame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	c_window::Init("Opus", "OpusConsole", "opus");
	c_render::Init(hInstance);
	c_mantle_gui::Init(true);
	GameLauncher::Init();

	c_window::RegisterUpdateCallback(UpdateCallback);
	c_window::RegisterDestroyCallback(DestroyCallback);
	//MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	c_console::Startup();

	while (s_running) c_window::Update();

	c_window::UnregisterUpdateCallback(UpdateCallback);
	c_window::UnregisterDestroyCallback(DestroyCallback);
	//MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	GameLauncher::Deinit();
	c_mantle_gui::Deinit();
	c_render::Deinit();
	c_window::Deinit();
	c_console::Deinit();

	return 0;
}