#include "haloshared-private-pch.h"

// dx11_c_code.c
extern "C" void* GetIDXGISwapChainPresent(IDXGISwapChain* pSwapchain);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL DebugUI::s_initialised = false;
bool DebugUI::s_visible = false;
ID3D11DeviceContext* DebugUI::s_pContext = NULL;
ID3D11Device* DebugUI::s_pDevice = NULL;
ID3D11RenderTargetView* DebugUI::mainRenderTargetView;
IDXGISwapChain* DebugUI::s_pSwapChain = NULL;
DebugUI::IDXGISwapChainPresent DebugUI::IDXGISwapChainPresentPointer;

bool DebugUI::IsVisible()
{
	return s_visible;
}

void DebugUI::Init()
{
	return;
	if (s_initialised)
	{
		return;
	}

	WriteLineVerbose("Initializing DXGISwapChainPresentHook");

	DXGI_SWAP_CHAIN_DESC sd;
	s_pSwapChain->GetDesc(&sd);
	ImGui::CreateContext();
	ImGuiIO& rImguiIO = ImGui::GetIO(); (void)rImguiIO;
	rImguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableSetMousePos | ImGuiConfigFlags_NavEnableGamepad;

	//Set OriginalWndProcHandler to the Address of the Original WndProc function
	//OriginalWndProcHandler = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)hWndProc);

	ImGui_ImplWin32_Init(sd.OutputWindow);
	ImGui_ImplDX11_Init(s_pDevice, s_pContext);
	ImGui::GetIO().ImeWindowHandle = sd.OutputWindow;

	ID3D11Texture2D* pBackBuffer = nullptr;
	s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
	assert(pBackBuffer);
	s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
	pBackBuffer->Release();

	s_initialised = true;
}

void DebugUI::RenderFrame()
{
	return;

	if (s_visible)
	{
		// #TODO: Very inefficient
		if (s_initialised)
		{
			ImGuiIO& rImguiIO = ImGui::GetIO();
			rImguiIO.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON);
		}

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
}



HRESULT __fastcall DebugUI::DXGISwapChainPresentHook(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
{
	DebugUI::Init();
	DebugUI::RenderFrame();

	return IDXGISwapChainPresentPointer(pChain, SyncInterval, Flags);
}

void DebugUI::Setup(IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	return;

	s_pSwapChain = nullptr;
	s_pDevice = nullptr;
	s_pContext = nullptr;

	if (!(pSwapChain && pDevice && pContext))
	{
		return;
	}

	IDXGISwapChainPresentPointer = (IDXGISwapChainPresent)GetIDXGISwapChainPresent(pSwapChain);

	s_pSwapChain = pSwapChain;
	s_pDevice = pDevice;
	s_pContext = pContext;

	WriteLineVerbose("DebugUI::Setup");

	static bool IDXGISwapChainPatched = false;
	if (!IDXGISwapChainPatched)
	{
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());

		LONG detourAttachResult = DetourAttach(&(LPVOID&)IDXGISwapChainPresentPointer, (PBYTE)DXGISwapChainPresentHook);
		const char* pName = "IDXGISwapChain::Present";
		if (detourAttachResult)
		{
			const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
			WriteLineVerbose("Failed to hook %s. Reason: %s", pName, detourAttachResultStr);
		}
		else
		{
			WriteLineVerbose("Successfully hooked %s", pName);
		}

		DetourTransactionCommit();
	}
}

void DebugUI::ToggleUI()
{
	return;

	s_visible = !s_visible;
}

void DebugUI::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return;

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
