#include "mantle-private-pch.h"


int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
	void(*UICallback)() = []()
	{
		SIZE size = {};
		CustomWindow::GetWindowSize(size);
		MantleGUI::Render(size.cx, size.cy);
	};

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		GameRender::BeginFrame(clearColor);
		GameRender::EndFrame();
	};
	CustomWindow::Init();
	GameRender::Init(NULL);
	DebugUI::Show();
	MantleGUI::Init();
	MantleGUI::RegisterOnCloseCallback([]() { s_running = false; });
	DebugUI::RegisterCallback(UICallback);
	CustomWindow::SetOnUpdateCallback(UpdateCallback);
	CustomWindow::SetOnDestroyCallback([]() { s_running = false; });
	while (s_running) CustomWindow::Update();
	DebugUI::UnregisterCallback(UICallback);
	MantleGUI::Deinit();
	GameRender::Deinit();
	CustomWindow::Deinit();

	return 0;
}
