#include "shared-private-pch.h"

// dx11_c_code.c
extern "C" void* GetIDXGISwapChainPresent(IDXGISwapChain * pSwapchain);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

struct WndProcMessage
{
	HWND hwnd;
	UINT msg;
	WPARAM wParam;
	LPARAM lParam;
};
ThreadSafeQueue<WndProcMessage> windowQueue;


// #WIP Start Resize Synchronization Across Opus and Game Thread
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

bool c_debug_gui::s_visible = false;
ID3D11DeviceContext* c_debug_gui::s_pContext = nullptr;
ID3D11Device* c_debug_gui::s_pDevice = nullptr;
ID3D11RenderTargetView* c_debug_gui::s_mainRenderTargetView = nullptr;
IDXGISwapChain* c_debug_gui::s_swap_chain = nullptr;
DXGI_SWAP_CHAIN_DESC  c_debug_gui::s_swapChainDescription = {};
c_debug_gui::IDXGISwapChainPresent c_debug_gui::s_IDXGISwapChainPresentPointer;
std::vector<c_debug_gui::DebugUICallback> c_debug_gui::s_pToggleableCallbacks;
std::vector<c_debug_gui::DebugUICallback> c_debug_gui::s_pAlwaysRunCallbacks;

bool c_debug_gui::IsVisible()
{
	return s_visible;
}

void c_debug_gui::Init(HINSTANCE hInstance, IDXGIFactory1* pFactory, IDXGISwapChain* swap_chain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	DEBUG_ASSERT(swap_chain);
	DEBUG_ASSERT(pDevice);
	DEBUG_ASSERT(pContext);

	// #WIP Start Resize Synchronization Across Opus and Game Thread
	static uint32_t expectedValue = underlying_cast(DebugUIState::Uninitialized);
	while (!s_uiState.compare_exchange_strong(expectedValue, underlying_cast(DebugUIState::Initializing)));
	DEBUG_ASSERT(s_uiState == underlying_cast(DebugUIState::Initializing));
	s_mutex.lock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
	{
		write_line_verbose("DebugUI::Init");

		s_swap_chain = swap_chain;
		s_pDevice = pDevice;
		s_pContext = pContext;

		s_swap_chain->GetDesc(&s_swapChainDescription);

		ImGui::CreateContext();
		ImGuiIO& rImguiIO = ImGui::GetIO(); (void)rImguiIO;
		rImguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableSetMousePos | ImGuiConfigFlags_NavEnableGamepad;

		{
			float baseSize = 10.0f;
			if (c_render::s_deviceMode.dmPelsWidth < c_render::s_deviceMode.dmPelsHeight)
				baseSize *= static_cast<float>(c_render::s_deviceMode.dmPelsWidth) / (float)GetSystemMetrics(SM_CXSCREEN); // width is smallest, scale on width
			else
				baseSize *= static_cast<float>(c_render::s_deviceMode.dmPelsHeight) / (float)GetSystemMetrics(SM_CYSCREEN); // height is smallest, scale on height

			char* pFontData;
			size_t pFontSize;
			bool fontResourceFound = ResourcesManager::GetResource(ResourceType::ImGUIFont, &pFontData, &pFontSize);
			ASSERT(fontResourceFound);
			ASSERT(pFontSize < INT_MAX);
			rImguiIO.Fonts->AddFontFromMemoryTTF(pFontData, static_cast<int>(pFontSize), 20.0f, NULL, rImguiIO.Fonts->GetGlyphRangesDefault());
			//delete pFontData; // imgui owns this memory
		}

		ImGui_ImplWin32_Init(s_swapChainDescription.OutputWindow);
		ImGui_ImplDX11_Init(s_pDevice, s_pContext);

		ImGui::GetIO().ImeWindowHandle = s_swapChainDescription.OutputWindow;

		ID3D11Texture2D* pBackBuffer = nullptr;
		s_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		ASSERT(pBackBuffer);
		s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_mainRenderTargetView);
		pBackBuffer->Release();
	}
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_mutex.unlock();
	s_uiState.store(underlying_cast(DebugUIState::Initialized));
	// #WIP End Resize Synchronization Across Opus and Game Thread
}

void c_debug_gui::Deinit()
{
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	static uint32_t expectedValue = underlying_cast(DebugUIState::Initialized);
	while (!s_uiState.compare_exchange_strong(expectedValue, underlying_cast(DebugUIState::Deinitializing)));
	DEBUG_ASSERT(s_uiState == underlying_cast(DebugUIState::Deinitializing));
	s_mutex.lock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
	{
		write_line_verbose("DebugUI::Deinit");

		ImGui_ImplWin32_Shutdown();
		ImGui_ImplDX11_Shutdown();

		s_mainRenderTargetView->Release();

		s_pContext = nullptr;
		s_pDevice = nullptr;
		s_mainRenderTargetView = nullptr;
		s_swap_chain = nullptr;
		s_swapChainDescription = {};
	}
	// #WIP Start Resize Synchronization Across Opus and Game Thread
	s_uiState.store(underlying_cast(DebugUIState::Uninitialized));
	s_mutex.unlock();
	// #WIP End Resize Synchronization Across Opus and Game Thread
}

bool c_debug_gui::IsRendering()
{
	bool isRendering = s_uiState == underlying_cast(DebugUIState::RenderingFrame);
	return isRendering;
}

void c_debug_gui::StartFrame()
{
	ProcessWindowMessages();

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

void c_debug_gui::EndFrame()
{
	//bool isRendering = s_uiState == underlying_cast(DebugUIState::RenderingFrame);
	//if (!isRendering) return;

	//Menu is displayed when g_ShowMenu is TRUE
	for (DebugUICallback& pCurrentCallback : s_pAlwaysRunCallbacks)
	{
		pCurrentCallback();
	}

	if (s_visible)
	{
		for (DebugUICallback& pCurrentCallback : s_pToggleableCallbacks)
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

void c_debug_gui::RenderFrame()
{
	StartFrame();
	EndFrame();
}

void c_debug_gui::ToggleUI()
{
	s_visible = !s_visible;
}

void c_debug_gui::show_ui()
{
	s_visible = true;
}

void c_debug_gui::Hide()
{
	s_visible = false;
}

void c_debug_gui::ProcessWindowMessages()
{
	WndProcMessage msg;
	while (windowQueue.Dequeue(msg))
	{
		switch (msg.msg)
		{
		case WM_KEYDOWN:
			if (msg.wParam == VK_HOME)
			{
				c_debug_gui::ToggleUI();
			}
			break;
		}

		bool isInitialised = s_uiState == underlying_cast(DebugUIState::Initialized);
		if (isInitialised)
		{
			ImGui_ImplWin32_WndProcHandler(msg.hwnd, msg.msg, msg.wParam, msg.lParam);
		}
	}
}

void c_debug_gui::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	windowQueue.Enqueue({ hwnd, msg, wParam, lParam }); // thread safe queue
}

void c_debug_gui::register_callback(DebugUICallbackMode callbackMode, DebugUICallback debug_ui_callback)
{
	std::vector<DebugUICallback>& rCallbacks = callbackMode == _callback_mode_toggleable ? s_pToggleableCallbacks : s_pAlwaysRunCallbacks;

	rCallbacks.push_back(debug_ui_callback);
}

void c_debug_gui::UnregisterCallback(DebugUICallbackMode callbackMode, DebugUICallback debug_ui_callback)
{
	std::vector<DebugUICallback>& rCallbacks = callbackMode == _callback_mode_toggleable ? s_pToggleableCallbacks : s_pAlwaysRunCallbacks;

	//std::vector<c_debug_gui::DebugUICallback>::iterator itCallbacksEnd = std::remove(rCallbacks.begin(), rCallbacks.end(), debug_ui_callback);
	//rCallbacks.erase(itCallbacksEnd, rCallbacks.end());
}
