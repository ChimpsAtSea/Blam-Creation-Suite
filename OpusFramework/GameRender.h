#pragma once

class GameRender
{
public:
	static ID3D11Device* s_pDevice;
	static ID3D11DeviceContext* s_pDeviceContext;
	static IDXGISwapChain1* s_pSwapChain;
	static IDXGIFactory5* s_pFactory;
	static DEVMODE s_deviceMode;

	static void CreateSwapchain(IDXGISwapChain1*& s_pSwapChain);
	static void Init(HINSTANCE hInstance);
	static void Deinit();
};

