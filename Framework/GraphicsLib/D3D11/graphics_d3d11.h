//#pragma once
//
//class c_render
//{
//public:
//	static ID3D11Device* s_device;
//	static ID3D11Device1* s_device1;
//	static ID3D11DeviceContext1* s_device_context;
//	static IDXGISwapChain1* s_swap_chain;
//	static D3D_FEATURE_LEVEL s_feature_level;
//	static IDXGIFactory3* s_dxgi_factory;
//	static IDXGIFactory5* s_dxgi_factory_5; // to support windows 10 features
//	static DEVMODE s_device_mode;
//	static bool is_directx_custom_init;
//	static ID3D11RenderTargetView* s_pRenderTargetView;
//	static ID3D11Texture2D* s_pDepthStencilBuffer;
//	static ID3D11DepthStencilView* s_pDepthStencilView;
//	static bool s_resize_enabled;
//	static c_window* s_window;
//
//	static DirectX::XMMATRIX view_matrix;
//	static DirectX::XMMATRIX perspective_matrix;
//	static DirectX::XMMATRIX view_matrix_transposed;
//	static DirectX::XMMATRIX perspective_matrix_transposed;
//	static bool g_allow_resize_at_beginning_of_frame;
//
//	static void update_perspective(float fieldOfViewHorizontal, float aspectRatio);
//	static void update_view(
//		float forward_x,
//		float forward_y,
//		float forward_z,
//		float up_x,
//		float up_y,
//		float up_z,
//		float position_x,
//		float position_y,
//		float position_z
//	);
//	static void UpdateViewLookAt(
//		float cameraPositionX,
//		float cameraPositionY,
//		float cameraPositionZ,
//		float look_at_position_x,
//		float look_at_position_y,
//		float look_at_position_z,
//		float up_x,
//		float up_y,
//		float up_z
//	);
//	static bool calculate_screen_coordinates(float position_x, float position_y, float position_z, float& screen_x, float& screen_y);
//
//
//	static void create_swapchain(IDXGISwapChain1*& s_swap_chain);
//	static void init_render(c_window* window, HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* swap_chain, bool allow_resize_at_beginning_of_frame = false);
//	static void init_render(c_window* window, HINSTANCE hInstance, bool allow_resize_at_beginning_of_frame = false);
//	static void begin_frame(bool clear, float clearColor[4], bool setTargets = true);
//	static void end_frame();
//	static void RequestResize(unsigned long width, unsigned long height);
//	static void ResizeBegin();
//	static void ResizeEnd();
//	static void deinit_render();
//	static void ResizeWindow();
//	static void set_resize_enabled(bool resizeEnabled) { s_resize_enabled = resizeEnabled; }
//	static bool IsResizeEnabled() { return s_resize_enabled; }
//
//private:
//	static void init_directx();
//};
//
