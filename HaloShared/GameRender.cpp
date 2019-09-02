#include "haloshared-private-pch.h"

ID3D11Device* GameRender::s_pDevice = nullptr;
ID3D11DeviceContext* GameRender::s_pDeviceContext = nullptr;
IDXGISwapChain* GameRender::s_pSwapChain = nullptr;
DXGI_SWAP_CHAIN_DESC GameRender::s_SwapchainDescription = {};

void GameRender::Init()
{
	assert(s_pDevice == nullptr);
	assert(s_pDeviceContext == nullptr);
	assert(s_pSwapChain == nullptr);

	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0,
	};

	D3D_FEATURE_LEVEL FeatureLevel = {};

	bool createSwapchain = true;

	if (createSwapchain)
	{
		DXGI_MODE_DESC BufferDesc = {};
		BufferDesc.Width = 1920;
		BufferDesc.Height = 1080;
		BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		DXGI_SAMPLE_DESC SampleDesc = {};
		SampleDesc.Count = 1;
		SampleDesc.Quality = 0;

		s_SwapchainDescription.BufferCount = 1;
		s_SwapchainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		s_SwapchainDescription.OutputWindow = CustomWindow::GetWindowHandle();
		s_SwapchainDescription.Windowed = TRUE;
		s_SwapchainDescription.BufferDesc = BufferDesc;
		s_SwapchainDescription.SampleDesc = SampleDesc;

		HRESULT D3D11CreateDeviceAndSwapChainResult = D3D11CreateDeviceAndSwapChain(
			NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			0,
			pFeatureLevels,
			_countof(pFeatureLevels),
			D3D11_SDK_VERSION,
			&s_SwapchainDescription,
			&s_pSwapChain,
			&s_pDevice,
			&FeatureLevel,
			&s_pDeviceContext);

		assert(D3D11CreateDeviceAndSwapChainResult == S_OK);
		assert(s_pSwapChain != nullptr);
	}
	else
	{
		HRESULT D3D11CreateDeviceResult = D3D11CreateDevice(
			NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			0,
			pFeatureLevels,
			_countof(pFeatureLevels),
			D3D11_SDK_VERSION,
			&s_pDevice,
			&FeatureLevel,
			&s_pDeviceContext);
		assert(D3D11CreateDeviceResult == S_OK);
	}
	assert(s_pDevice != nullptr);
	assert(s_pDeviceContext != nullptr);

	
	


	//DebugUI::Init(s_pSwapChain, s_pDevice, s_pDeviceContext);
}

void GameRender::Deinit()
{
	s_pSwapChain->SetFullscreenState(false, NULL);
	s_pDevice->Release();
	s_pDeviceContext->Release();
	s_pSwapChain->Release();

	s_pDevice = nullptr;
	s_pDeviceContext = nullptr;
	s_pSwapChain = nullptr;
	s_SwapchainDescription = {};

	//DebugUI::Deinit();
}
