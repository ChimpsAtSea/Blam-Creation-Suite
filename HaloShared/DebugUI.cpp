#include "haloshared-private-pch.h"

// dx11_c_code.c
extern "C" void* GetIDXGISwapChainPresent(IDXGISwapChain* pSwapchain);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL DebugUI::s_initialised = false;
bool DebugUI::s_visible = false;
ID3D11DeviceContext* DebugUI::s_pContext = nullptr;
ID3D11Device* DebugUI::s_pDevice = nullptr;
ID3D11RenderTargetView* DebugUI::mainRenderTargetView = nullptr;
IDXGISwapChain* DebugUI::s_pSwapChain = nullptr;
DXGI_SWAP_CHAIN_DESC  DebugUI::s_swapChainDescription = {};

DebugUI::IDXGISwapChainPresent DebugUI::IDXGISwapChainPresentPointer;

bool DebugUI::IsVisible()
{
	return s_visible;
}

void DebugUI::Init(IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	assert(s_initialised == false);
	s_initialised = true;

	WriteLineVerbose("DebugUI::Init");

	s_pSwapChain = pSwapChain;
	s_pDevice = pDevice;
	s_pContext = pContext;

	s_pSwapChain->GetDesc(&s_swapChainDescription);

	ImGui::CreateContext();
	ImGuiIO& rImguiIO = ImGui::GetIO(); (void)rImguiIO;
	rImguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableSetMousePos | ImGuiConfigFlags_NavEnableGamepad;

	ImGui_ImplWin32_Init(s_swapChainDescription.OutputWindow);
	ImGui_ImplDX11_Init(s_pDevice, s_pContext);

	ImGui::GetIO().ImeWindowHandle = s_swapChainDescription.OutputWindow;

	ID3D11Texture2D* pBackBuffer = nullptr;
	s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	assert(pBackBuffer);
	s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
	pBackBuffer->Release();

	s_initialised = true;
}

void DebugUI::Deinit()
{
	assert(s_initialised);

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();

	s_initialised = false;
	s_visible = false;
	s_pContext = nullptr;
	s_pDevice = nullptr;
	mainRenderTargetView = nullptr;
	s_pSwapChain = nullptr;
	s_swapChainDescription = {};
}

void DebugUI::RenderFrame()
{
	if (s_initialised == false)
	{
		return;
	}

	if (s_visible == false)
	{
		return;
	}

	// #TODO: Very inefficient
	ImGuiIO& rImguiIO = ImGui::GetIO();
	rImguiIO.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();

	//Menu is displayed when g_ShowMenu is TRUE
	if (s_visible)
	{
		bool bShow = true;
		ImGui::ShowDemoWindow(&bShow);
	}
	ImGui::EndFrame();
	ImGui::Render();

	s_pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void DebugUI::ToggleUI()
{
	s_visible = !s_visible;
}

void DebugUI::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (s_initialised)
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);

		switch (msg)
		{
		case WM_KEYUP:
			if (wParam == VK_HOME)
			{
				DebugUI::ToggleUI();
			}
			break;
		}
	}
}
