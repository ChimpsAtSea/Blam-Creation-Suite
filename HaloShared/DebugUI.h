#pragma once
class DebugUI
{
public:
	static bool IsVisible();


	static void Init(IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	static void Deinit();
	static void RenderFrame();
	static void ToggleUI();
	static void WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

	static BOOL s_initialised;
	static bool s_visible;
	static ID3D11DeviceContext* s_pContext;
	static ID3D11Device* s_pDevice;
	static IDXGISwapChain* s_pSwapChain;
	static DXGI_SWAP_CHAIN_DESC s_swapChainDescription;
	static ID3D11RenderTargetView* mainRenderTargetView;
	static IDXGISwapChainPresent IDXGISwapChainPresentPointer;
};

