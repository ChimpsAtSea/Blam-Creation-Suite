#pragma once

enum DebugUICallbackMode
{
	_callback_mode_toggleable,
	_callback_mode_always_run
};

class c_debug_gui
{
public:
	using DebugUICallback = std::function<void()>;

	static bool IsVisible();


	static void Init(HINSTANCE hInstance, IDXGIFactory1* pFactory, IDXGISwapChain* swap_chain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	static void Deinit();
	static void start_frame();
	static void end_frame();
	static void RenderFrame();
	static void ToggleUI();
	static void show_ui();
	static void Hide();
	static void ProcessWindowMessages();
	static void AddMessageBreak();
	static void WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void register_callback(DebugUICallbackMode callbackMode, DebugUICallback debug_ui_callback);
	static void unregister_callback(DebugUICallbackMode callbackMode, DebugUICallback debug_ui_callback);
	static bool is_rendering();

private:
	typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* swap_chain, UINT SyncInterval, UINT Flags);

	static bool s_visible;
	static ID3D11DeviceContext* s_pContext;
	static ID3D11Device* s_pDevice;
	static IDXGISwapChain* s_swap_chain;
	static DXGI_SWAP_CHAIN_DESC s_swapChainDescription;
	static ID3D11RenderTargetView* s_mainRenderTargetView;
	static IDXGISwapChainPresent s_IDXGISwapChainPresentPointer;
	static std::vector<DebugUICallback> s_pToggleableCallbacks;
	static std::vector<DebugUICallback> s_pAlwaysRunCallbacks;
};

