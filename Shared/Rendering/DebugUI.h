#pragma once
class DebugUI
{
public:

	typedef void(DebugUICallback)();

	static bool IsVisible();


	static void Init(HINSTANCE hInstance, IDXGIFactory1* pFactory, IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	static void Deinit();
	static void StartFrame();
	static void EndFrame();
	static void RenderFrame();
	static void ToggleUI();
	static void Show();
	static void Hide();
	static void WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void RegisterCallback(DebugUICallback* pDebugUICallback);
	static void UnregisterCallback(DebugUICallback* pDebugUICallback);
	static bool IsRendering();

private:
	typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

	static bool s_visible;
	static ID3D11DeviceContext* s_pContext;
	static ID3D11Device* s_pDevice;
	static IDXGISwapChain* s_pSwapChain;
	static DXGI_SWAP_CHAIN_DESC s_swapChainDescription;
	static ID3D11RenderTargetView* s_mainRenderTargetView;
	static IDXGISwapChainPresent s_IDXGISwapChainPresentPointer;
	static std::vector<DebugUICallback*> s_pCallbacks;
};

