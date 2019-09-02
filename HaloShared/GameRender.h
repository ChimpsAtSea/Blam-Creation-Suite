#pragma once

class GameRender
{
public:
	static ID3D11Device* s_pDevice;
	static ID3D11DeviceContext* s_pDeviceContext;
	static IDXGISwapChain* s_pSwapChain;
	static DXGI_SWAP_CHAIN_DESC s_SwapchainDescription;
	static IDXGIFactory1* s_pFactory;

	static void Init();
	static void Deinit();
};

