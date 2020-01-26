#include "mantle-private-pch.h"

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,				/* [input] handle to current instance */
	_In_opt_ HINSTANCE hPrevInstance,		/* [input] handle to previous instance */
	_In_ LPWSTR lpCmdLine,					/* [input] pointer to command line */
	_In_ int nShowCmd						/* [input] show state of window */
)
{
	int argc = 0;
	LPWSTR* argv = CommandLineToArgvW(lpCmdLine, &argc);

	void(*UICallback)() = []()
	{
		MantleGUI::Render();
	};

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		Render::BeginFrame(clearColor);
		Render::EndFrame();
	};
	Window::Init("Mantle", "Mantle Console", "mantle");
	Render::Init(NULL);
	DebugUI::Show();
	MantleGUI::Init(false, argc > 0 ? argv[0] : nullptr);
	MantleGUI::RegisterOnCloseCallback([]() { s_running = false; });
	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);
	Window::SetOnUpdateCallback(UpdateCallback);
	Window::SetOnDestroyCallback([]() { s_running = false; });
	while (s_running) Window::Update();
	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);
	MantleGUI::Deinit();
	Render::Deinit();
	Window::Deinit();

	return 0;
}
