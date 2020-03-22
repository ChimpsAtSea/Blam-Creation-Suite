#pragma once

enum DebugUICallbackMode
{
	_callback_mode_toggleable,
	_callback_mode_always_run
};

class c_debug_gui
{
public:
	typedef void(DebugUICallback)();

	static bool IsVisible();


	static void Init(HINSTANCE hInstance, IDXGIFactory1* pFactory, IDXGISwapChain* swap_chain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	static void Deinit();
	static void StartFrame();
	static void EndFrame();
	static void RenderFrame();
	static void ToggleUI();
	static void show_ui();
	static void Hide();
	static void ProcessWindowMessages();
	static void AddMessageBreak();
	static void WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void register_callback(DebugUICallbackMode callbackMode, DebugUICallback* pDebugUICallback);
	static void UnregisterCallback(DebugUICallbackMode callbackMode, DebugUICallback* pDebugUICallback);
	static bool IsRendering();

private:
	typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* swap_chain, UINT SyncInterval, UINT Flags);

	static bool s_visible;
	static ID3D11DeviceContext* s_pContext;
	static ID3D11Device* s_pDevice;
	static IDXGISwapChain* s_swap_chain;
	static DXGI_SWAP_CHAIN_DESC s_swapChainDescription;
	static ID3D11RenderTargetView* s_mainRenderTargetView;
	static IDXGISwapChainPresent s_IDXGISwapChainPresentPointer;
	static std::vector<DebugUICallback*> s_pToggleableCallbacks;
	static std::vector<DebugUICallback*> s_pAlwaysRunCallbacks;
};

