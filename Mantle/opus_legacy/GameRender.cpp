#include "mantle-private-pch.h"

ID3D11Device* GameRender::s_pDevice = nullptr;
ID3D11DeviceContext1* GameRender::s_pDeviceContext = nullptr;
IDXGISwapChain1* GameRender::s_pSwapChain = nullptr;
IDXGIFactory5* GameRender::s_pFactory = nullptr;
DEVMODE GameRender::s_deviceMode = {};
bool GameRender::s_directxCustomInit = false;
ID3D11RenderTargetView* GameRender::s_pRenderTargetView = nullptr;
ID3D11Texture2D* GameRender::s_pDepthStencilBuffer = nullptr;
ID3D11DepthStencilView* GameRender::s_pDepthStencilView = nullptr;

void GameRender::CreateSwapchain(IDXGISwapChain1*& rpSwapChain)
{
	SIZE size = {};
	CustomWindow::GetWindowSize(size);

	DXGI_SWAP_CHAIN_DESC1 s_SwapchainDescription = {};
	s_SwapchainDescription.Width = size.cx;
	s_SwapchainDescription.Height = size.cy;
	s_SwapchainDescription.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	s_SwapchainDescription.Stereo = false;
	s_SwapchainDescription.SampleDesc.Count = 1;
	s_SwapchainDescription.SampleDesc.Quality = 0;
	s_SwapchainDescription.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
	//s_SwapchainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT; // Enable GetFrameLatencyWaitableObject()
	s_SwapchainDescription.Flags = 0;
	s_SwapchainDescription.BufferUsage = DXGI_USAGE_SHADER_INPUT | DXGI_USAGE_RENDER_TARGET_OUTPUT;
	s_SwapchainDescription.BufferCount = 2; // Use double-buffering to minimize latency.
	s_SwapchainDescription.Scaling = DXGI_SCALING_STRETCH;
	s_SwapchainDescription.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

	static constexpr bool createCompositionSwapchain = false;
	if constexpr (createCompositionSwapchain)
	{
		HRESULT createSwapChainForCompositionResult = s_pFactory->CreateSwapChainForComposition(s_pDevice, &s_SwapchainDescription, NULL, &rpSwapChain);
		assert(SUCCEEDED(createSwapChainForCompositionResult));
	}
	else
	{
		HWND hWnd = CustomWindow::GetWindowHandle();
		HRESULT createSwapChainForHwndResult = s_pFactory->CreateSwapChainForHwnd(s_pDevice, hWnd, &s_SwapchainDescription, NULL, NULL, &rpSwapChain);
		assert(SUCCEEDED(createSwapChainForHwndResult));
	}
	assert(rpSwapChain != nullptr);
}

void GameRender::InitDirectX()
{
	assert(s_pDevice == nullptr);
	assert(s_pDeviceContext == nullptr);
	assert(s_pSwapChain == nullptr);

	EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &s_deviceMode);

	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0,
	};

	D3D_FEATURE_LEVEL FeatureLevel = {};

	bool createSwapchain = true;

	HRESULT CreateDXGIFactory1Result = CreateDXGIFactory2(0, __uuidof(IDXGIFactory5), (void**)(&s_pFactory));
	assert(CreateDXGIFactory1Result == S_OK);
	assert(s_pFactory != nullptr);

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	ID3D11DeviceContext* pDeviceContext = nullptr;
	HRESULT D3D11CreateDeviceResult = D3D11CreateDevice(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		createDeviceFlags,
		pFeatureLevels,
		_countof(pFeatureLevels),
		D3D11_SDK_VERSION,
		&s_pDevice,
		&FeatureLevel,
		&pDeviceContext);
	assert(D3D11CreateDeviceResult == S_OK);
	assert(s_pDevice != nullptr);
	assert(pDeviceContext != nullptr);

	// check that it supports our directx interface
	pDeviceContext->QueryInterface(&s_pDeviceContext);
	assert(s_pDeviceContext != nullptr);

	if (createSwapchain)
	{
		CreateSwapchain(s_pSwapChain);
	}
}

void GameRender::Init(HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain)
{
	if (hInstance == NULL)
		hInstance = GetModuleHandle(NULL);

	assert(s_pDevice == nullptr);
	assert(s_pDeviceContext == nullptr);
	assert(s_pSwapChain == nullptr);

	s_directxCustomInit = true;
	s_pDevice = pDevice;
	s_pSwapChain = pSwapChain;

	pDevice->GetImmediateContext(reinterpret_cast<ID3D11DeviceContext**>(&s_pDeviceContext));
	assert(s_pDeviceContext != nullptr);

	Init(hInstance);
}

void GameRender::Init(HINSTANCE hInstance)
{
	if (!s_directxCustomInit)
	{
		InitDirectX();
	}

	DebugUI::Init(hInstance, s_pFactory, s_pSwapChain, s_pDevice, s_pDeviceContext);
}

void GameRender::BeginFrame(float clearColor[4])
{
	if (s_pRenderTargetView == nullptr)
	{
		ID3D11Texture2D* pBackBuffer = nullptr;

		// Get the pointer to the back buffer.
		HRESULT getBufferResult = s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		assert(SUCCEEDED(getBufferResult));

		HRESULT createRenderTargetViewResult = s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_pRenderTargetView);
		assert(SUCCEEDED(createRenderTargetViewResult));

		pBackBuffer->Release();

		assert(s_pRenderTargetView != nullptr);
	}

	//// Create the texture for the depth buffer using the filled out description.
	//if (s_pDepthStencilBuffer == nullptr)
	//{
	//	D3D11_TEXTURE2D_DESC depthBufferDesc = {};
	//	depthBufferDesc.Width = 500;
	//	depthBufferDesc.Height = 500;
	//	depthBufferDesc.MipLevels = 1;
	//	depthBufferDesc.ArraySize = 1;
	//	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	//	depthBufferDesc.SampleDesc.Count = 1;
	//	depthBufferDesc.SampleDesc.Quality = 0;
	//	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	//	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	//	depthBufferDesc.CPUAccessFlags = 0;
	//	depthBufferDesc.MiscFlags = 0;

	//	HRESULT createTexture2DResult = s_pDevice->CreateTexture2D(&depthBufferDesc, NULL, &s_pDepthStencilBuffer);
	//	assert(SUCCEEDED(createTexture2DResult));

	//	assert(s_pDepthStencilBuffer != nullptr);
	//}

	//if (s_pDepthStencilView == nullptr)
	//{
	//	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
	//	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	//	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	//	depthStencilViewDesc.Texture2D.MipSlice = 0;

	//	HRESULT createDepthStencilViewResult = s_pDevice->CreateDepthStencilView(s_pDepthStencilBuffer, &depthStencilViewDesc, &s_pDepthStencilView);
	//	assert(SUCCEEDED(createDepthStencilViewResult));

	//	assert(s_pDepthStencilView != nullptr);
	//}

	// Clear the back buffer.
	s_pDeviceContext->ClearRenderTargetView(s_pRenderTargetView, clearColor);

	//// Clear the depth buffer.
	//s_pDeviceContext->ClearDepthStencilView(s_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void GameRender::EndFrame()
{
	DebugUI::RenderFrame();
	s_pSwapChain->Present(1, 0);
}

void GameRender::ResizeWindow()
{
	SIZE size = {};
	CustomWindow::GetWindowSize(size);

	if (s_pSwapChain)
	{

		int width = size.cx;
		int height = size.cy;

		s_pDeviceContext->Flush();
		DebugUI::Deinit();

		s_pDeviceContext->OMSetRenderTargets(0, 0, 0);

		// Release all outstanding references to the swap chain's buffers.
		s_pRenderTargetView->Release();
		//s_pDepthStencilView->Release();

		// Preserve the existing buffer count and format.
		// Automatically choose the width and height to match the client rect for HWNDs.
		HRESULT resizeBuffersResult = s_pSwapChain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);
		assert(SUCCEEDED(resizeBuffersResult));

		// Get buffer and create a render-target-view.
		ID3D11Texture2D* pBuffer;
		HRESULT getBufferResult = s_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer);
		assert(SUCCEEDED(getBufferResult));

		HRESULT createRenderTargetViewResult = s_pDevice->CreateRenderTargetView(pBuffer, NULL, &s_pRenderTargetView);
		assert(SUCCEEDED(createRenderTargetViewResult));

		pBuffer->Release();

		s_pDeviceContext->OMSetRenderTargets(1, &s_pRenderTargetView, NULL);

		// Set up the viewport.
		D3D11_VIEWPORT vp;
		vp.Width = static_cast<float>(width);
		vp.Height = static_cast<float>(height);
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		s_pDeviceContext->RSSetViewports(1, &vp);

		bool isVisible = DebugUI::IsVisible();
		DebugUI::Init(GetModuleHandle(NULL), s_pFactory, s_pSwapChain, s_pDevice, s_pDeviceContext);
		if(isVisible) DebugUI::Show();
	}
}

void GameRender::Deinit()
{
	DebugUI::Deinit();

	if (!s_directxCustomInit)
	{
		s_pSwapChain->SetFullscreenState(false, NULL);
		s_pDevice->Release();
		s_pDeviceContext->Release();
		s_pSwapChain->Release();
		s_pFactory->Release();
	}

	s_pDevice = nullptr;
	s_pDeviceContext = nullptr;
	s_pSwapChain = nullptr;
	s_pFactory = nullptr;

	s_directxCustomInit = false;
}
