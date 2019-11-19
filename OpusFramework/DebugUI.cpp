#include "opusframework-private-pch.h"

// dx11_c_code.c
extern "C" void* GetIDXGISwapChainPresent(IDXGISwapChain* pSwapchain);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL DebugUI::s_initialised = false;
bool DebugUI::s_visible = false;
ID3D11DeviceContext* DebugUI::s_pContext = nullptr;
ID3D11Device* DebugUI::s_pDevice = nullptr;
ID3D11RenderTargetView* DebugUI::s_mainRenderTargetView = nullptr;
IDXGISwapChain* DebugUI::s_pSwapChain = nullptr;
DXGI_SWAP_CHAIN_DESC  DebugUI::s_swapChainDescription = {};
DebugUI::IDXGISwapChainPresent DebugUI::s_IDXGISwapChainPresentPointer;
std::vector<DebugUI::DebugUICallback*> DebugUI::s_pCallbacks;

bool DebugUI::IsVisible()
{
	return s_visible;
}

void DebugUI::Init(HINSTANCE hInstance, IDXGIFactory1* pFactory, IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
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

	{
		HRSRC hResource = FindResource(hInstance, MAKEINTRESOURCE(IDR_FONT1), RT_RCDATA);
		assert(hResource);
		HGLOBAL hMemory = LoadResource(hInstance, hResource);
		assert(hMemory);
		DWORD dwSize = SizeofResource(hInstance, hResource);
		assert(dwSize > 0);
		LPVOID lpAddress = LockResource(hMemory);
		assert(lpAddress);

		char* bytes = static_cast<char*>(malloc(dwSize));
		assert(bytes != nullptr);
		memcpy(bytes, lpAddress, dwSize);

		float baseSize = 10.0f;
		if (GameRender::s_deviceMode.dmPelsWidth < GameRender::s_deviceMode.dmPelsHeight)
		{
			// width is smallest, scale on width
			baseSize *= static_cast<float>(GameRender::s_deviceMode.dmPelsWidth) / (float)GetSystemMetrics(SM_CXSCREEN);
		}
		else
		{
			// height is smallest, scale on height
			baseSize *= static_cast<float>(GameRender::s_deviceMode.dmPelsHeight) / (float)GetSystemMetrics(SM_CYSCREEN);
		}

		rImguiIO.Fonts->AddFontFromMemoryTTF(bytes, dwSize, 20.0f, NULL, rImguiIO.Fonts->GetGlyphRangesDefault());

		UnlockResource(lpAddress);
		BOOL freeResourceResult = FreeResource(hMemory);
		assert(freeResourceResult == 0);
	}

	ImGui_ImplWin32_Init(s_swapChainDescription.OutputWindow);
	ImGui_ImplDX11_Init(s_pDevice, s_pContext);

	ImGui::GetIO().ImeWindowHandle = s_swapChainDescription.OutputWindow;

	ID3D11Texture2D* pBackBuffer = nullptr;
	s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	assert(pBackBuffer);
	s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_mainRenderTargetView);
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
	s_mainRenderTargetView = nullptr;
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
		for (DebugUICallback* pCurrentCallback : s_pCallbacks)
		{
			pCurrentCallback();
		}
		//bool bShow = true;
		//ImGui::ShowDemoWindow(&bShow);
	}
	ImGui::EndFrame();
	ImGui::Render();

	s_pContext->OMSetRenderTargets(1, &s_mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void DebugUI::ToggleUI()
{
	s_visible = !s_visible;
}

void DebugUI::Show()
{
	s_visible = true;
}

void DebugUI::Hide()
{
	s_visible = false;
}

void DebugUI::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (s_initialised)
	{
		if (IsVisible())
		{
			ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
		}

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

void DebugUI::RegisterCallback(DebugUICallback* pDebugUICallback)
{
	for (DebugUICallback* pCurrentCallback : s_pCallbacks)
	{
		if (pCurrentCallback == pDebugUICallback)
		{
			return;
		}
	}
	s_pCallbacks.push_back(pDebugUICallback);
}

void DebugUI::UnregisterCallback(DebugUICallback* pDebugUICallback)
{
	auto callbacksNewEnd = std::remove(s_pCallbacks.begin(), s_pCallbacks.end(), pDebugUICallback);
	s_pCallbacks.erase(callbacksNewEnd, s_pCallbacks.end());
}
