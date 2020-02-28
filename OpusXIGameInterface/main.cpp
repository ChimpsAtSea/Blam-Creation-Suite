#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

const char* c_console::g_console_executable_name = "OpusXI";

extern "C" __declspec(dllexport) void resize_viewport(int width, int height)
{
	c_render::ResizeBegin();
}

extern "C" __declspec(dllexport) void run(ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain)
{
	 static HMODULE hInstance = GetModuleHandleA("OpusXIGameInterface.dll");

	 c_window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	 SystemPatch::PatchEnumWindows();

	 static bool s_running = true;
	 void(*UpdateCallback)() = []()
	 {
		 c_render::begin_frame(true, &clearColor.x);
		 //GameLauncher::OpusTick();
		 c_render::end_frame();
	 };
	 //void(*DestroyCallback)() = []()
	 //{
		// s_running = false;
	 //};

	 //Window::Init("Opus", "OpusConsole", "opus");
	 c_render::init_render(hInstance, pDevice, pSwapChain);
	 //MantleGUI::Init(true);
	 //GameLauncher::Init();

	 c_window::register_update_callback(UpdateCallback);
	 //Window::RegisterDestroyCallback(DestroyCallback);
	 ////MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	 while (s_running) 
	 {
		 c_window::OnUpdateCallback();
	 }

	 //while (s_running) Window::Update();

	 c_window::unregister_update_callback(UpdateCallback);
	 //Window::UnregisterDestroyCallback(DestroyCallback);
	 ////MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	 //GameLauncher::Deinit();
	 //MantleGUI::Deinit();
	 c_render::deinit_render();
	 //Window::Deinit();
}
