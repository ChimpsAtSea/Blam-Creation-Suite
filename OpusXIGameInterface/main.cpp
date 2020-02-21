#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>

DirectX::XMFLOAT4 clearColor = { 0.01f, 0.011f, 0.03f, 1.0f };

const char* ResourcesManager::s_pModuleName = "OpusXIGameInterface.dll";

extern "C" __declspec(dllexport) void resize_viewport(int width, int height)
{
	Render::ResizeBegin();
}

extern "C" __declspec(dllexport) void run(ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain)
{
	 static HMODULE hInstance = GetModuleHandleA("OpusXIGameInterface.dll");

	 Window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	 SystemPatch::PatchEnumWindows();

	 static bool s_running = true;
	 void(*UpdateCallback)() = []()
	 {
		 Render::BeginFrame(true, &clearColor.x);
		 //GameLauncher::OpusTick();
		 Render::EndFrame();
	 };
	 //void(*DestroyCallback)() = []()
	 //{
		// s_running = false;
	 //};

	 //Window::Init("Opus", "OpusConsole", "opus");
	 Render::Init(hInstance, pDevice, pSwapChain);
	 //MantleGUI::Init(true);
	 //GameLauncher::Init();

	 Window::RegisterUpdateCallback(UpdateCallback);
	 //Window::RegisterDestroyCallback(DestroyCallback);
	 ////MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	 while (s_running) 
	 {
		 Window::OnUpdateCallback();
	 }

	 //while (s_running) Window::Update();

	 Window::UnregisterUpdateCallback(UpdateCallback);
	 //Window::UnregisterDestroyCallback(DestroyCallback);
	 ////MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	 //GameLauncher::Deinit();
	 //MantleGUI::Deinit();
	 Render::Deinit();
	 //Window::Deinit();
}
