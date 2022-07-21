#include "graphicslib-private-pch.h"
//
//ID3D11Device* c_render::s_device = nullptr;
//ID3D11Device1* c_render::s_device1 = nullptr;
//ID3D11DeviceContext1* c_render::s_device_context = nullptr;
//IDXGISwapChain1* c_render::s_swap_chain = nullptr;
//D3D_FEATURE_LEVEL c_render::s_feature_level = {};
//IDXGIFactory3* c_render::s_dxgi_factory = nullptr;
//IDXGIFactory5* c_render::s_dxgi_factory_5 = nullptr;
//DEVMODE c_render::s_device_mode = {};
//bool c_render::is_directx_custom_init = false;
//ID3D11RenderTargetView* c_render::s_pRenderTargetView = nullptr;
//ID3D11Texture2D* c_render::s_pDepthStencilBuffer = nullptr;
//ID3D11DepthStencilView* c_render::s_pDepthStencilView = nullptr;
//bool c_render::s_resize_enabled = true;
//c_window* c_render::s_window = nullptr;
//
//DirectX::XMMATRIX c_render::view_matrix = {};
//DirectX::XMMATRIX c_render::perspective_matrix = {};
//DirectX::XMMATRIX c_render::view_matrix_transposed = {};
//DirectX::XMMATRIX c_render::perspective_matrix_transposed = {};
//
//bool c_render::g_allow_resize_at_beginning_of_frame;
//
//static float s_fieldOfViewHorizontal;
//static float s_fieldOfViewVertical;
//static float s_aspectRatio;
//int resize_width = 0;
//int resize_height = 0;
//bool resize_requested = false;
//
//void c_render::update_perspective(float fieldOfViewHorizontal, float aspectRatio)
//{
//	using namespace DirectX;
//
//	bool isDifferent = s_fieldOfViewHorizontal != fieldOfViewHorizontal || s_aspectRatio != aspectRatio;
//	if (!isDifferent) // avoid updating if we don't need to
//	{
//		return;
//	}
//
//	s_fieldOfViewHorizontal = fieldOfViewHorizontal;
//	s_fieldOfViewVertical = atanf(tanf(fieldOfViewHorizontal / 2.0f) / aspectRatio) * 2.0f;
//	s_aspectRatio = aspectRatio;
//
//	perspective_matrix = XMMatrixPerspectiveFovRH(s_fieldOfViewVertical, aspectRatio, 0.01f, 10000.0f);
//	perspective_matrix_transposed = XMMatrixTranspose(perspective_matrix);
//}
//
//void c_render::update_view(
//	float forward_x,
//	float forward_y,
//	float forward_z,
//	float up_x,
//	float up_y,
//	float up_z,
//	float position_x,
//	float position_y,
//	float position_z
//)
//{
//	using namespace DirectX;
//
//	XMVECTOR forward = { forward_x, forward_y, forward_z };
//	XMVECTOR up = { up_x, up_y, up_z };
//	XMVECTOR position = { position_x, position_y, position_z };
//
//	up = XMVector3Normalize(up);
//	forward = XMVector3Normalize(forward);
//
//	view_matrix = XMMatrixLookAtRH(position, position + forward, up);
//	view_matrix_transposed = XMMatrixTranspose(view_matrix);
//}
//
//void c_render::UpdateViewLookAt(
//	float cameraPositionX,
//	float cameraPositionY,
//	float cameraPositionZ,
//	float look_at_position_x,
//	float look_at_position_y,
//	float look_at_position_z,
//	float up_x,
//	float up_y,
//	float up_z
//)
//{
//	using namespace DirectX;
//
//	XMVECTOR position = { cameraPositionX, cameraPositionY, cameraPositionZ };
//	XMVECTOR look_at_position = { look_at_position_x, look_at_position_y, look_at_position_z };
//	XMVECTOR up = { up_x, up_y, up_z };
//
//	up = XMVector3Normalize(up);
//
//	view_matrix = XMMatrixLookAtRH(position, look_at_position, up);
//	view_matrix_transposed = XMMatrixTranspose(view_matrix);
//}
//
//bool c_render::calculate_screen_coordinates(float position_x, float position_y, float position_z, float& screen_x, float& screen_y)
//{
//	using namespace DirectX;
//
//	XMVECTOR pV = { position_x, position_y, position_z, 1.0f };
//	float Height = s_window->get_width_float();
//	float Width = s_window->get_width_float();
//
//	DirectX::XMMATRIX pWorld = DirectX::XMMatrixIdentity();
//	DirectX::XMMATRIX pProjection = perspective_matrix;
//	DirectX::XMMATRIX pView = view_matrix;
//
//	DirectX::XMVECTOR  pOut = XMVector3Project(pV, 0, 0, Width, Height, 0, 1, pProjection, pView, pWorld);
//	DirectX::XMFLOAT3 pOut3d;
//	DirectX::XMStoreFloat3(&pOut3d, pOut);
//
//	if (pOut3d.z < 1.0f)
//	{
//		screen_x = pOut3d.x;
//		screen_y = pOut3d.y;
//		return true;
//	}
//	return false;
//}
//
//void c_render::create_swapchain(IDXGISwapChain1*& swap_chain)
//{
//	DXGI_SWAP_CHAIN_DESC1 swapchain_desc = {};
//	swapchain_desc.Width = s_window->get_width_integer();
//	swapchain_desc.Height = s_window->get_height_integer();
//	swapchain_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	swapchain_desc.Stereo = false;
//	swapchain_desc.SampleDesc.Count = 1;
//	swapchain_desc.SampleDesc.Quality = 0;
//	swapchain_desc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
//	if (s_dxgi_factory_5)
//	{
//		//s_SwapchainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT; // Enable GetFrameLatencyWaitableObject()
//	}
//	swapchain_desc.Flags = 0;
//	swapchain_desc.BufferUsage = DXGI_USAGE_SHADER_INPUT | DXGI_USAGE_RENDER_TARGET_OUTPUT;
//	swapchain_desc.BufferCount = 2; // Use double-buffering to minimize latency.
//	swapchain_desc.Scaling = DXGI_SCALING_STRETCH;
//	swapchain_desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
//
//	constexpr bool createCompositionSwapchain = false;
//	if constexpr (createCompositionSwapchain)
//	{
//		HRESULT create_swap_chain_for_composition_result = s_dxgi_factory->CreateSwapChainForComposition(s_device, &swapchain_desc, NULL, &swap_chain);
//		ASSERT(SUCCEEDED(create_swap_chain_for_composition_result));
//	}
//	else
//	{
//		HWND hWnd = s_window->get_window_handle();
//		HRESULT create_swap_chain_for_hwnd_result = s_dxgi_factory->CreateSwapChainForHwnd(s_device, hWnd, &swapchain_desc, NULL, NULL, &swap_chain);
//		ASSERT(SUCCEEDED(create_swap_chain_for_hwnd_result));
//	}
//	ASSERT(swap_chain != nullptr);
//}
//
//void c_render::init_directx()
//{
//	DEBUG_ASSERT(s_device == nullptr);
//	DEBUG_ASSERT(s_device_context == nullptr);
//	DEBUG_ASSERT(s_swap_chain == nullptr);
//	
//	EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &s_device_mode);
//
//	D3D_FEATURE_LEVEL feature_level[] =
//	{
//		D3D_FEATURE_LEVEL_11_1
//	};
//
//	HRESULT create_dxgi_5_factory_result = CreateDXGIFactory2(0, __uuidof(IDXGIFactory5), (void**)(&s_dxgi_factory_5));
//	if (create_dxgi_5_factory_result == S_OK)
//	{
//		s_dxgi_factory = s_dxgi_factory_5;
//	}
//	else
//	{
//		s_dxgi_factory_5 = nullptr;
//		HRESULT create_dxgi_factory_result = CreateDXGIFactory2(0, __uuidof(IDXGIFactory3), (void**)(&s_dxgi_factory));
//		ASSERT(create_dxgi_factory_result == S_OK);
//	}
//	if (s_dxgi_factory == nullptr)
//	{
//		FATAL_ERROR("failed to create DXGIFactory. unsupported platform.");
//	}
//
//	UINT createDeviceFlags = 0;
//	if (BCS_SUCCEEDED(command_line_has_argument("d3ddebug")))
//	{
//		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
//	}
//
//	ID3D11DeviceContext* pDeviceContext = nullptr;
//	HRESULT D3D11CreateDeviceResult = D3D11CreateDevice(
//		NULL,
//		D3D_DRIVER_TYPE_HARDWARE,
//		NULL,
//		createDeviceFlags,
//		feature_level,
//		_countof(feature_level),
//		D3D11_SDK_VERSION,
//		&s_device,
//		&s_feature_level,
//		&pDeviceContext);
//	ASSERT(SUCCEEDED(D3D11CreateDeviceResult));
//	ASSERT(s_device != nullptr);
//	ASSERT(pDeviceContext != nullptr);
//
//	HRESULT device1_query_result = s_device->QueryInterface(IID_PPV_ARGS(&s_device1));
//	ASSERT(SUCCEEDED(device1_query_result));
//	ASSERT(s_device1 != nullptr);
//
//	// check that it supports our directx interface
//	pDeviceContext->QueryInterface(&s_device_context);
//	ASSERT(s_device_context != nullptr);
//
//	create_swapchain(s_swap_chain);
//}
//
//void c_render::init_render(c_window* window, HINSTANCE instance_handle, ID3D11Device* device, IDXGISwapChain1* swap_chain, bool allow_resize_at_beginning_of_frame)
//{
//	if (instance_handle == NULL)
//	{
//		instance_handle = GetModuleHandle(NULL);
//	}
//
//	DEBUG_ASSERT(s_device == nullptr);
//	DEBUG_ASSERT(s_device_context == nullptr);
//	DEBUG_ASSERT(s_swap_chain == nullptr);
//
//	DEBUG_ASSERT(device != nullptr);
//	DEBUG_ASSERT(swap_chain != nullptr);
//
//	s_window = window;
//	is_directx_custom_init = true;
//	s_device = device;
//	s_swap_chain = swap_chain;
//
//	device->GetImmediateContext(reinterpret_cast<ID3D11DeviceContext**>(&s_device_context));
//	ASSERT(s_device_context != nullptr);
//
//	init_render(window, instance_handle, allow_resize_at_beginning_of_frame);
//}
//
//void c_render::init_render(c_window* window, HINSTANCE hInstance, bool allow_resize_at_beginning_of_frame)
//{
//	s_window = window;
//	g_allow_resize_at_beginning_of_frame = allow_resize_at_beginning_of_frame;
//	s_window->on_resize.register_callback(RequestResize);
//
//	if (!is_directx_custom_init)
//	{
//		init_directx();
//	}
//
//	c_debug_gui::Init(hInstance, s_dxgi_factory_5, s_swap_chain, s_device, s_device_context);
//}
//
//void c_render::begin_frame(bool clear, float clearColor[4], bool settargetts)
//{
//	if (resize_requested && g_allow_resize_at_beginning_of_frame)
//	{
//		ResizeWindow();
//		resize_requested = false;
//	}
//
//	if (s_pRenderTargetView == nullptr)
//	{
//		ID3D11Texture2D* back_buffer = nullptr;
//
//		// Get the pointer to the back buffer.
//		HRESULT get_buffer_result = s_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&back_buffer);
//		ASSERT(SUCCEEDED(get_buffer_result));
//
//		HRESULT create_render_target_view_result = s_device->CreateRenderTargetView(back_buffer, NULL, &s_pRenderTargetView);
//		ASSERT(SUCCEEDED(create_render_target_view_result));
//
//		back_buffer->Release();
//
//		ASSERT(s_pRenderTargetView != nullptr);
//	}
//
//	static ID3D11DepthStencilState* s_pDepthStencilState = nullptr;
//	if(s_pDepthStencilState == nullptr)
//	{
//		D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};
//		depthStencilDesc.DepthEnable = TRUE;
//		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
//		depthStencilDesc.DepthFunc = D3D11_COMPARISON_GREATER;
//		depthStencilDesc.StencilEnable = FALSE;
//		depthStencilDesc.StencilReadMask = 0xFF;
//		depthStencilDesc.StencilWriteMask = 0xFF;
//
//		// Stencil operations if pixel is front-facing
//		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
//		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
//		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
//
//		// Stencil operations if pixel is back-facing
//		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
//		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
//		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
//		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
//		HRESULT createDepthStencilStateResult = s_device->CreateDepthStencilState(&depthStencilDesc, &s_pDepthStencilState);
//		ASSERT(SUCCEEDED(createDepthStencilStateResult));
//
//	}
//
//	static ID3D11BlendState* blend_state = nullptr;
//	if (blend_state == nullptr)
//	{
//		D3D11_BLEND_DESC blend_state_description = {};
//		blend_state_description.AlphaToCoverageEnable = FALSE;
//		blend_state_description.IndependentBlendEnable = FALSE;
//		blend_state_description.RenderTarget[0].BlendEnable = TRUE;
//
//		// dest.rgb = src.rgb * src.a + dest.rgb * (1 - src.a)
//		blend_state_description.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
//		blend_state_description.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
//		blend_state_description.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
//
//		// dest.a = 1 - (1 - src.a) * (1 - dest.a) [the math works out]
//		blend_state_description.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_INV_DEST_ALPHA;
//		blend_state_description.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
//		blend_state_description.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
//
//		blend_state_description.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
//
//
//		HRESULT create_blend_state_result = s_device->CreateBlendState(&blend_state_description, &blend_state);
//		ASSERT(SUCCEEDED(create_blend_state_result));
//	}
//
//	//// Create the texture for the depth buffer using the filled out description.
////if (s_pDepthStencilBuffer == nullptr)
////{
////	D3D11_TEXTURE2D_DESC depthBufferDesc = {};
////	depthBufferDesc.Width = 500;
////	depthBufferDesc.Height = 500;
////	depthBufferDesc.MipLevels = 1;
////	depthBufferDesc.ArraySize = 1;
////	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
////	depthBufferDesc.SampleDesc.Count = 1;
////	depthBufferDesc.SampleDesc.Quality = 0;
////	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
////	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
////	depthBufferDesc.CPUAccessFlags = 0;
////	depthBufferDesc.MiscFlags = 0;
//
////	HRESULT createTexture2DResult = s_pDevice->CreateTexture2D(&depthBufferDesc, NULL, &s_pDepthStencilBuffer);
////	assert(SUCCEEDED(createTexture2DResult));
//
////	assert(s_pDepthStencilBuffer != nullptr);
////}
//
////if (s_pDepthStencilView == nullptr)
////{
////	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
////	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
////	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
////	depthStencilViewDesc.Texture2D.MipSlice = 0;
//
////	HRESULT createDepthStencilViewResult = s_pDevice->CreateDepthStencilView(s_pDepthStencilBuffer, &depthStencilViewDesc, &s_pDepthStencilView);
////	assert(SUCCEEDED(createDepthStencilViewResult));
//
////	assert(s_pDepthStencilView != nullptr);
////}
//
//	if (settargetts)
//	{
//		s_device_context->OMSetRenderTargets(1, &s_pRenderTargetView, NULL);
//	}
//	s_device_context->OMSetDepthStencilState(s_pDepthStencilState, 0);
//	s_device_context->OMSetBlendState(blend_state, NULL, 0xffffffff);
//
//	// Set up the viewport.
//	D3D11_VIEWPORT vp;
//	vp.Width = s_window->get_width_float();
//	vp.Height = s_window->get_height_float();
//	vp.MinDepth = 0.0f;
//	vp.MaxDepth = 1.0f;
//	vp.TopLeftX = 0;
//	vp.TopLeftY = 0;
//	s_device_context->RSSetViewports(1, &vp);
//
//	if (clear)
//	{
//		// Clear the back buffer.
//		s_device_context->ClearRenderTargetView(s_pRenderTargetView, clearColor);
//
//		//// Clear the depth buffer.
//		//s_pDeviceContext->ClearDepthStencilView(s_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
//	}
//}
//
//void c_render::end_frame()
//{
//	c_debug_gui::RenderFrame();
//	s_swap_chain->Present(1, 0);
//}
//
//void c_render::RequestResize(uint32_t width, uint32_t height)
//{
//	resize_requested = true;
//}
//
//void c_render::ResizeBegin()
//{
//	s_device_context->Flush();
//	c_debug_gui::Deinit();
//
//	s_device_context->OMSetRenderTargets(0, 0, 0);
//	s_device_context->ClearState();
//	// Release all outstanding references to the swap chain's buffers.
//	if(s_pRenderTargetView) s_pRenderTargetView->Release();
//	//s_pDepthStencilView->Release();
//}
//
//void c_render::ResizeEnd()
//{
//	bool isVisible = c_debug_gui::IsVisible();
//	c_debug_gui::Init(GetModuleHandle(NULL), s_dxgi_factory_5, s_swap_chain, s_device, s_device_context);
//	if (isVisible) c_debug_gui::show_ui();
//}
//
//void c_render::ResizeWindow()
//{
//	if (s_swap_chain && s_resize_enabled)
//	{
//		int width = resize_width;
//		int height = resize_height;
//		//int width = Window::GetWindowWidth();
//		//int height = Window::GetWindowHeight();
//
//		ResizeBegin();
//		{
//			c_render::s_device_context->OMSetRenderTargets(0, 0, 0);
//
//			auto ref = s_swap_chain->AddRef() - 1;
//			s_swap_chain->Release();
//
//
//			// Preserve the existing buffer count and format.
//			// Automatically choose the width and height to match the client rect for HWNDs.
//			HRESULT resizeBuffersResult = s_swap_chain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);
//			ASSERT(SUCCEEDED(resizeBuffersResult));
//
//			// Get buffer and create a render-target-view.
//			ID3D11Texture2D* buffer;
//			HRESULT get_buffer_result = s_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);
//			ASSERT(SUCCEEDED(get_buffer_result));
//
//			HRESULT create_render_target_view_result = s_device->CreateRenderTargetView(buffer, NULL, &s_pRenderTargetView);
//			ASSERT(SUCCEEDED(create_render_target_view_result));
//
//			buffer->Release();
//
//			s_device_context->OMSetRenderTargets(1, &s_pRenderTargetView, NULL);
//
//			// Set up the viewport.
//			D3D11_VIEWPORT vp;
//			vp.Width = static_cast<float>(width);
//			vp.Height = static_cast<float>(height);
//			vp.MinDepth = 0.0f;
//			vp.MaxDepth = 1.0f;
//			vp.TopLeftX = 0;
//			vp.TopLeftY = 0;
//			s_device_context->RSSetViewports(1, &vp);
//		}
//		ResizeEnd();
//	}
//}
//
//void c_render::deinit_render()
//{
//	c_debug_gui::Deinit();
//
//	if (!is_directx_custom_init)
//	{
//		s_swap_chain->SetFullscreenState(false, NULL);
//		s_device->Release();
//		s_device_context->Release();
//		s_swap_chain->Release();
//		s_dxgi_factory->Release(); // #NOTE: same as s_dxgi_factory_5
//	}
//
//	s_window->on_resize.unregister_callback(RequestResize);
//
//	s_device = nullptr;
//	s_device_context = nullptr;
//	s_swap_chain = nullptr;
//	s_dxgi_factory = nullptr;
//	s_dxgi_factory_5 = nullptr;
//
//	is_directx_custom_init = false;
//}
