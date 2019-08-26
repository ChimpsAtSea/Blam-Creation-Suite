#pragma once
class DebugUI
{
public:
	static bool IsVisible();


	static void Init();
	static void RenderFrame();
	static HRESULT __fastcall DXGISwapChainPresentHook(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags);
	static void Setup(IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
	static void ToggleUI();
	static void WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

	static BOOL s_initialised;
	static bool s_visible;
	static ID3D11DeviceContext* s_pContext;
	static ID3D11Device* s_pDevice;
	static ID3D11RenderTargetView* mainRenderTargetView;
	static IDXGISwapChain* s_pSwapChain;
	static IDXGISwapChainPresent IDXGISwapChainPresentPointer;
};

