#include "mantle-private-pch.h"

const char* c_console::s_consoleExecutableName = "Mantle";

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	c_console::Init();

	int argc = 0;
	LPWSTR* argv = CommandLineToArgvW(lpCmdLine, &argc);
	LPWSTR szLoadMapArgument = nullptr;
	if (lpCmdLine[0])
	{
		szLoadMapArgument = argv[0];
	}


	void(*UICallback)() = []()
	{
		c_mantle_gui::Render();
	};

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		c_render::BeginFrame(true, clearColor);
		c_render::EndFrame();
	};

	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};

	c_window::Init("Mantle", "Mantle Console", "mantle");
	c_render::Init(NULL);
	DebugUI::Show();
	c_mantle_gui::Init(false, szLoadMapArgument);
	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);

	c_window::RegisterUpdateCallback(UpdateCallback);
	c_window::RegisterDestroyCallback(DestroyCallback);
	c_mantle_gui::RegisterOnCloseCallback(DestroyCallback);

	c_console::Startup();

	while (s_running) c_window::Update();

	c_window::UnregisterUpdateCallback(UpdateCallback);
	c_window::UnregisterDestroyCallback(DestroyCallback);
	c_mantle_gui::UnregisterOnCloseCallback(DestroyCallback);

	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);
	c_mantle_gui::Deinit();
	c_render::Deinit();
	c_window::Deinit();
	c_console::Deinit();

	return 0;
}
