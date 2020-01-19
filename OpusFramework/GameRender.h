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

	static void CreateSwapchain(IDXGISwapChain1*& s_pSwapChain);
	static void Init(HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain);
	static void Init(HINSTANCE hInstance);
	static void Deinit();

private:
	static void InitDirectX();
};

