#pragma once

class GameRender
{
public:
	static ID3D11Device* s_pDevice;
	static ID3D11DeviceContext1* s_pDeviceContext;
	static IDXGISwapChain1* s_pSwapChain;
	static IDXGIFactory5* s_pFactory;
	static DEVMODE s_deviceMode;
	static bool s_directxCustomInit;
	static ID3D11RenderTargetView* s_pRenderTargetView;
	static ID3D11Texture2D* s_pDepthStencilBuffer;
	static ID3D11DepthStencilView* s_pDepthStencilView ;

	static void CreateSwapchain(IDXGISwapChain1*& s_pSwapChain);
	static void Init(HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain);
	static void Init(HINSTANCE hInstance);
	static void BeginFrame(float clearColor[4]);
	static void EndFrame();
	static void Deinit();
	static void ResizeWindow();

private:
	static void InitDirectX();
};

