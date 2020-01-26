#include "shared-private-pch.h"

// dx11_c_code.c
extern "C" void* GetIDXGISwapChainPresent(IDXGISwapChain * pSwapchain);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


// #WIP Start Resize Synchronization Across Opus and Game Thread
#undef auto
#include <shared_mutex>

enum class DebugUIState : uint32_t
{
	Uninitialized,
	Initializing,
	Initialized,
	Deinitializing,
	RenderingFrame
};

std::atomic<uint32_t> s_uiState = underlying_cast(DebugUIState::Uninitialized);
std::shared_mutex s_mutex;
// #WIP End Resize Synchronization Across Opus and Game Thread

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
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	static uint32_t expectedValue = underlying_cast(DebugUIState::Uninitialized);
	while (!s_uiState.compare_exchange_strong(expectedValue, underlying_cast(DebugUIState::Initializing)));
	assert(s_uiState == underlying_cast(DebugUIState::Initializing));
	s_mutex.lock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
	{
		WriteLineVerbose("DebugUI::Init");

		s_pSwapChain = pSwapChain;
		s_pDevice = pDevice;
		s_pContext = pContext;

		s_pSwapChain->GetDesc(&s_swapChainDescription);

		ImGui::CreateContext();
		ImGuiIO& rImguiIO = ImGui::GetIO(); (void)rImguiIO;
		rImguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableSetMousePos | ImGuiConfigFlags_NavEnableGamepad;

		{
			float baseSize = 10.0f;
			if (Render::s_deviceMode.dmPelsWidth < Render::s_deviceMode.dmPelsHeight)
				baseSize *= static_cast<float>(Render::s_deviceMode.dmPelsWidth) / (float)GetSystemMetrics(SM_CXSCREEN); // width is smallest, scale on width
			else
				baseSize *= static_cast<float>(Render::s_deviceMode.dmPelsHeight) / (float)GetSystemMetrics(SM_CYSCREEN); // height is smallest, scale on height

			char* pFontData;
			size_t pFontSize;
			bool fontResourceFound = ResourcesManager::GetResource(ResourceType::ImGUIFont, &pFontData, &pFontSize);
			assert(fontResourceFound);
			rImguiIO.Fonts->AddFontFromMemoryTTF(pFontData, pFontSize, 20.0f, NULL, rImguiIO.Fonts->GetGlyphRangesDefault());
			//delete pFontData; // imgui owns this memory
		}

		ImGui_ImplWin32_Init(s_swapChainDescription.OutputWindow);
		ImGui_ImplDX11_Init(s_pDevice, s_pContext);

		ImGui::GetIO().ImeWindowHandle = s_swapChainDescription.OutputWindow;

		ID3D11Texture2D* pBackBuffer = nullptr;
		s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		assert(pBackBuffer);
		s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_mainRenderTargetView);
		pBackBuffer->Release();
	}
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_mutex.unlock();
	s_uiState.store(underlying_cast(DebugUIState::Initialized));
	// #WIP End Resize Synchronization Across Opus and Game Thread
}

void DebugUI::Deinit()
{
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	static uint32_t expectedValue = underlying_cast(DebugUIState::Initialized);
	while (!s_uiState.compare_exchange_strong(expectedValue, underlying_cast(DebugUIState::Deinitializing)));
	assert(s_uiState == underlying_cast(DebugUIState::Deinitializing));
	s_mutex.lock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
	{
		WriteLineVerbose("DebugUI::Deinit");

		ImGui_ImplWin32_Shutdown();
		ImGui_ImplDX11_Shutdown();

		s_mainRenderTargetView->Release();

		s_pContext = nullptr;
		s_pDevice = nullptr;
		s_mainRenderTargetView = nullptr;
		s_pSwapChain = nullptr;
		s_swapChainDescription = {};
	}
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_uiState.store(underlying_cast(DebugUIState::Uninitialized));
	s_mutex.unlock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
}

bool DebugUI::IsRendering()
{
	bool isRendering = s_uiState == underlying_cast(DebugUIState::RenderingFrame);
	return isRendering;
}

void DebugUI::StartFrame()
{
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_mutex.lock();
	static uint32_t expectedValue = underlying_cast(DebugUIState::Initialized);
	bool allowRendering = s_uiState.compare_exchange_strong(expectedValue, underlying_cast(DebugUIState::RenderingFrame));
	if (!allowRendering)
	{
		return;
	}
	//assert(s_uiState == underlying_cast(DebugUIState::RenderingFrame));
	// #WIP End Resize Synchronization Across Opus and Game Thread

	// #TODO: Very inefficient
	ImGuiIO& rImguiIO = ImGui::GetIO();
	rImguiIO.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();
}

void DebugUI::EndFrame()
{
	//bool isRendering = s_uiState == underlying_cast(DebugUIState::RenderingFrame);
	//if (!isRendering) return;

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

	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_uiState.store(underlying_cast(DebugUIState::Initialized));
	s_mutex.unlock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
}

void DebugUI::RenderFrame()
{
	StartFrame();
	EndFrame();
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
	bool isInitialised = s_uiState == underlying_cast(DebugUIState::Initialized);
	if (isInitialised && Window::IsWindowFocused())
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
	std::vector<DebugUI::DebugUICallback*>::iterator itCallbacksEnd = std::remove(s_pCallbacks.begin(), s_pCallbacks.end(), pDebugUICallback);
	s_pCallbacks.erase(itCallbacksEnd, s_pCallbacks.end());
}
