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
		Render::BeginFrame(true, clearColor);
		Render::EndFrame();
	};

	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};

	Window::Init("Mantle", "Mantle Console", "mantle");
	Render::Init(NULL);
	DebugUI::Show();
	MantleGUI::Init(false, argc > 0 ? argv[0] : nullptr);
	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);

	Window::RegisterUpdateCallback(UpdateCallback);
	Window::RegisterDestroyCallback(DestroyCallback);
	MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	while (s_running) Window::Update();

	Window::UnregisterUpdateCallback(UpdateCallback);
	Window::UnregisterDestroyCallback(DestroyCallback);
	MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	DebugUI::RegisterCallback(DebugUI::AlwaysRun, UICallback);
	MantleGUI::Deinit();
	Render::Deinit();
	Window::Deinit();

	return 0;
}
