#include "shared-private-pch.h"

ID3D11Device* c_render::s_pDevice = nullptr;
ID3D11DeviceContext1* c_render::s_pDeviceContext = nullptr;
IDXGISwapChain1* c_render::s_swap_chain = nullptr;
IDXGIFactory5* c_render::s_pFactory = nullptr;
DEVMODE c_render::s_deviceMode = {};
bool c_render::s_directxCustomInit = false;
ID3D11RenderTargetView* c_render::s_pRenderTargetView = nullptr;
ID3D11Texture2D* c_render::s_pDepthStencilBuffer = nullptr;
ID3D11DepthStencilView* c_render::s_pDepthStencilView = nullptr;
bool c_render::s_resizeEnabled = true;
c_window* c_render::s_window = nullptr;

DirectX::XMMATRIX c_render::viewMatrix = {};
DirectX::XMMATRIX c_render::perspectiveMatrix = {};
DirectX::XMMATRIX c_render::viewMatrixTransposed = {};
DirectX::XMMATRIX c_render::perspectiveMatrixTransposed = {};

bool c_render::g_allow_resize_at_beginning_of_frame;

static float s_fieldOfViewHorizontal;
static float s_fieldOfViewVertical;
static float s_aspectRatio;
int resize_width = 0;
int resize_height = 0;
bool resize_requested = false;

void c_render::update_perspective(float fieldOfViewHorizontal, float aspectRatio)
{
	using namespace DirectX;

	bool isDifferent = s_fieldOfViewHorizontal != fieldOfViewHorizontal || s_aspectRatio != aspectRatio;
	if (!isDifferent) // avoid updating if we don't need to
	{
		return;
	}

	s_fieldOfViewHorizontal = fieldOfViewHorizontal;
	s_fieldOfViewVertical = atanf(tanf(fieldOfViewHorizontal / 2.0f) / aspectRatio) * 2.0f;
	s_aspectRatio = aspectRatio;

	perspectiveMatrix = XMMatrixPerspectiveFovRH(s_fieldOfViewVertical, aspectRatio, 0.01f, 10000.0f);
	perspectiveMatrixTransposed = XMMatrixTranspose(perspectiveMatrix);
}

void c_render::update_view(
	float forwardX,
	float forwardY,
	float forwardZ,
	float upX,
	float upY,
	float upZ,
	float positionX,
	float positionY,
	float positionZ
)
{
	using namespace DirectX;

	XMVECTOR vForward = { forwardX, forwardY, forwardZ };
	XMVECTOR vUp = { upX, upY, upZ };
	XMVECTOR vPosition = { positionX, positionY, positionZ };

	vUp = XMVector3Normalize(vUp);
	vForward = XMVector3Normalize(vForward);

	viewMatrix = XMMatrixLookAtRH(vPosition, vPosition + vForward, vUp);
	viewMatrixTransposed = XMMatrixTranspose(viewMatrix);
}

void c_render::UpdateViewLookAt(
	float cameraPositionX,
	float cameraPositionY,
	float cameraPositionZ,
	float lookAtPositionX,
	float lookAtPositionY,
	float lookAtPositionZ,
	float upX,
	float upY,
	float upZ
)
{
	using namespace DirectX;

	XMVECTOR vPosition = { cameraPositionX, cameraPositionY, cameraPositionZ };
	XMVECTOR vLookAt = { lookAtPositionX, lookAtPositionY, lookAtPositionZ };
	XMVECTOR vUp = { upX, upY, upZ };

	vUp = XMVector3Normalize(vUp);

	viewMatrix = XMMatrixLookAtRH(vPosition, vLookAt, vUp);
	viewMatrixTransposed = XMMatrixTranspose(viewMatrix);
}

bool c_render::calculate_screen_coordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY)
{
	using namespace DirectX;

	XMVECTOR pV = { positionX, positionY, positionZ, 1.0f };
	float Height = s_window->get_width_float();
	float Width = s_window->get_width_float();

	DirectX::XMMATRIX pWorld = DirectX::XMMatrixIdentity();
	DirectX::XMMATRIX pProjection = perspectiveMatrix;
	DirectX::XMMATRIX pView = viewMatrix;

	DirectX::XMVECTOR  pOut = XMVector3Project(pV, 0, 0, Width, Height, 0, 1, pProjection, pView, pWorld);
	DirectX::XMFLOAT3 pOut3d;
	DirectX::XMStoreFloat3(&pOut3d, pOut);

	if (pOut3d.z < 1.0f)
	{
		screenX = pOut3d.x;
		screenY = pOut3d.y;
		return true;
	}
	return false;
}

void c_render::CreateSwapchain(IDXGISwapChain1*& swap_chain)
{
	DXGI_SWAP_CHAIN_DESC1 s_SwapchainDescription = {};
	s_SwapchainDescription.Width = s_window->get_width_integer();
	s_SwapchainDescription.Height = s_window->get_height_integer();
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

	constexpr bool createCompositionSwapchain = false;
	if constexpr (createCompositionSwapchain)
	{
		HRESULT createSwapChainForCompositionResult = s_pFactory->CreateSwapChainForComposition(s_pDevice, &s_SwapchainDescription, NULL, &swap_chain);
		ASSERT(SUCCEEDED(createSwapChainForCompositionResult));
	}
	else
	{
		HWND hWnd = s_window->get_window_handle();
		HRESULT createSwapChainForHwndResult = s_pFactory->CreateSwapChainForHwnd(s_pDevice, hWnd, &s_SwapchainDescription, NULL, NULL, &swap_chain);
		ASSERT(SUCCEEDED(createSwapChainForHwndResult));
	}
	ASSERT(swap_chain != nullptr);
}

void c_render::InitDirectX()
{
	DEBUG_ASSERT(s_pDevice == nullptr);
	DEBUG_ASSERT(s_pDeviceContext == nullptr);
	DEBUG_ASSERT(s_swap_chain == nullptr);

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
	ASSERT(CreateDXGIFactory1Result == S_OK);
	ASSERT(s_pFactory != nullptr);

	UINT createDeviceFlags = 0;
	if (c_command_line::has_command_line_arg("-d3ddebug"))
	{
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	}

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
	ASSERT(D3D11CreateDeviceResult == S_OK);
	ASSERT(s_pDevice != nullptr);
	ASSERT(pDeviceContext != nullptr);

	// check that it supports our directx interface
	pDeviceContext->QueryInterface(&s_pDeviceContext);
	ASSERT(s_pDeviceContext != nullptr);

	if (createSwapchain)
	{
		CreateSwapchain(s_swap_chain);
	}

}

void c_render::init_render(c_window* window, HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* swap_chain, bool allow_resize_at_beginning_of_frame)
{
	if (hInstance == NULL)
	{
		hInstance = c_runtime_util::get_current_module();
	}

	DEBUG_ASSERT(s_pDevice == nullptr);
	DEBUG_ASSERT(s_pDeviceContext == nullptr);
	DEBUG_ASSERT(s_swap_chain == nullptr);
	DEBUG_ASSERT(pDevice != nullptr);
	DEBUG_ASSERT(swap_chain != nullptr);

	s_window = window;
	s_directxCustomInit = true;
	s_pDevice = pDevice;
	s_swap_chain = swap_chain;

	pDevice->GetImmediateContext(reinterpret_cast<ID3D11DeviceContext**>(&s_pDeviceContext));
	ASSERT(s_pDeviceContext != nullptr);

	init_render(window, hInstance, allow_resize_at_beginning_of_frame);
}

void c_render::init_render(c_window* window, HINSTANCE hInstance, bool allow_resize_at_beginning_of_frame)
{
	s_window = window;
	g_allow_resize_at_beginning_of_frame = allow_resize_at_beginning_of_frame;
	s_window->on_resize.register_callback(RequestResize);

	if (!s_directxCustomInit)
	{
		InitDirectX();
	}

	c_debug_gui::Init(hInstance, s_pFactory, s_swap_chain, s_pDevice, s_pDeviceContext);
}

void c_render::begin_frame(bool clear, float clearColor[4], bool settargetts)
{
	if (resize_requested && g_allow_resize_at_beginning_of_frame)
	{
		ResizeWindow();
		resize_requested = false;
	}

	if (s_pRenderTargetView == nullptr)
	{
		ID3D11Texture2D* pBackBuffer = nullptr;

		// Get the pointer to the back buffer.
		HRESULT getBufferResult = s_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		ASSERT(SUCCEEDED(getBufferResult));

		HRESULT createRenderTargetViewResult = s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_pRenderTargetView);
		ASSERT(SUCCEEDED(createRenderTargetViewResult));

		pBackBuffer->Release();

		ASSERT(s_pRenderTargetView != nullptr);
	}

	static ID3D11DepthStencilState* s_pDepthStencilState = nullptr;
	if(s_pDepthStencilState == nullptr)
	{
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};
		depthStencilDesc.DepthEnable = TRUE;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_GREATER;
		depthStencilDesc.StencilEnable = FALSE;
		depthStencilDesc.StencilReadMask = 0xFF;
		depthStencilDesc.StencilWriteMask = 0xFF;

		// Stencil operations if pixel is front-facing
		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Stencil operations if pixel is back-facing
		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
		HRESULT createDepthStencilStateResult = s_pDevice->CreateDepthStencilState(&depthStencilDesc, &s_pDepthStencilState);
		ASSERT(SUCCEEDED(createDepthStencilStateResult));

	}

	static ID3D11BlendState* m_pBlendState = nullptr;
	if (m_pBlendState == nullptr)
	{
		D3D11_BLEND_DESC blendStateDesc = {};
		blendStateDesc.AlphaToCoverageEnable = FALSE;
		blendStateDesc.IndependentBlendEnable = FALSE;
		blendStateDesc.RenderTarget[0].BlendEnable = TRUE;

		// dest.rgb = src.rgb * src.a + dest.rgb * (1 - src.a)
		blendStateDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendStateDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendStateDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

		// dest.a = 1 - (1 - src.a) * (1 - dest.a) [the math works out]
		blendStateDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_INV_DEST_ALPHA;
		blendStateDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
		blendStateDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

		blendStateDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;


		HRESULT createBlendStateResult = s_pDevice->CreateBlendState(&blendStateDesc, &m_pBlendState);
		ASSERT(SUCCEEDED(createBlendStateResult));
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

	if (settargetts)
	{
		s_pDeviceContext->OMSetRenderTargets(1, &s_pRenderTargetView, NULL);
	}
	s_pDeviceContext->OMSetDepthStencilState(s_pDepthStencilState, 0);
	s_pDeviceContext->OMSetBlendState(m_pBlendState, NULL, 0xffffffff);

	// Set up the viewport.
	D3D11_VIEWPORT vp;
	vp.Width = s_window->get_width_float();
	vp.Height = s_window->get_height_float();
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	s_pDeviceContext->RSSetViewports(1, &vp);

	if (clear)
	{
		// Clear the back buffer.
		s_pDeviceContext->ClearRenderTargetView(s_pRenderTargetView, clearColor);

		//// Clear the depth buffer.
		//s_pDeviceContext->ClearDepthStencilView(s_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	}
}

void c_render::end_frame()
{
	c_debug_gui::RenderFrame();
	s_swap_chain->Present(1, 0);
}

void c_render::RequestResize(uint32_t width, uint32_t height)
{
	resize_requested = true;
}

void c_render::ResizeBegin()
{
	s_pDeviceContext->Flush();
	c_debug_gui::Deinit();

	s_pDeviceContext->OMSetRenderTargets(0, 0, 0);
	s_pDeviceContext->ClearState();
	// Release all outstanding references to the swap chain's buffers.
	if(s_pRenderTargetView) s_pRenderTargetView->Release();
	//s_pDepthStencilView->Release();
}

void c_render::ResizeEnd()
{
	bool isVisible = c_debug_gui::IsVisible();
	c_debug_gui::Init(GetModuleHandle(NULL), s_pFactory, s_swap_chain, s_pDevice, s_pDeviceContext);
	if (isVisible) c_debug_gui::show_ui();
}

void c_render::ResizeWindow()
{
	if (s_swap_chain && s_resizeEnabled)
	{
		int width = resize_width;
		int height = resize_height;
		//int width = Window::GetWindowWidth();
		//int height = Window::GetWindowHeight();

		ResizeBegin();
		{
			// Preserve the existing buffer count and format.
			// Automatically choose the width and height to match the client rect for HWNDs.
			HRESULT resizeBuffersResult = s_swap_chain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);
			ASSERT(SUCCEEDED(resizeBuffersResult));

			// Get buffer and create a render-target-view.
			ID3D11Texture2D* buffer;
			HRESULT getBufferResult = s_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);
			ASSERT(SUCCEEDED(getBufferResult));

			HRESULT createRenderTargetViewResult = s_pDevice->CreateRenderTargetView(buffer, NULL, &s_pRenderTargetView);
			ASSERT(SUCCEEDED(createRenderTargetViewResult));

			buffer->Release();

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
		}
		ResizeEnd();
	}
}

void c_render::deinit_render()
{
	c_debug_gui::Deinit();

	if (!s_directxCustomInit)
	{
		s_swap_chain->SetFullscreenState(false, NULL);
		s_pDevice->Release();
		s_pDeviceContext->Release();
		s_swap_chain->Release();
		s_pFactory->Release();
	}

	s_window->on_resize.unregister_callback(RequestResize);

	s_pDevice = nullptr;
	s_pDeviceContext = nullptr;
	s_swap_chain = nullptr;
	s_pFactory = nullptr;

	s_directxCustomInit = false;
}
