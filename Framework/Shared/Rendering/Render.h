#pragma once

class c_render
{
public:
	static ID3D11Device* s_pDevice;
	static ID3D11DeviceContext1* s_pDeviceContext;
	static IDXGISwapChain1* s_swap_chain;
	static IDXGIFactory5* s_pFactory;
	static DEVMODE s_deviceMode;
	static bool s_directxCustomInit;
	static ID3D11RenderTargetView* s_pRenderTargetView;
	static ID3D11Texture2D* s_pDepthStencilBuffer;
	static ID3D11DepthStencilView* s_pDepthStencilView;
	static bool s_resizeEnabled;
	static c_window* s_window;

	static DirectX::XMMATRIX viewMatrix;
	static DirectX::XMMATRIX perspectiveMatrix;
	static DirectX::XMMATRIX viewMatrixTransposed;
	static DirectX::XMMATRIX perspectiveMatrixTransposed;
	static bool g_allow_resize_at_beginning_of_frame;

	static void update_perspective(float fieldOfViewHorizontal, float aspectRatio);
	static void update_view(
		float forwardX,
		float forwardY,
		float forwardZ,
		float upX,
		float upY,
		float upZ,
		float positionX,
		float positionY,
		float positionZ
	);
	static void UpdateViewLookAt(
		float cameraPositionX,
		float cameraPositionY,
		float cameraPositionZ,
		float lookAtPositionX,
		float lookAtPositionY,
		float lookAtPositionZ,
		float upX,
		float upY,
		float upZ
	);
	static bool calculate_screen_coordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY);


	static void CreateSwapchain(IDXGISwapChain1*& s_swap_chain);
	static void init_render(c_window* window, HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* swap_chain, bool allow_resize_at_beginning_of_frame = false);
	static void init_render(c_window* window, HINSTANCE hInstance, bool allow_resize_at_beginning_of_frame = false);
	static void begin_frame(bool clear, float clearColor[4], bool setTargets = true);
	static void end_frame();
	static void RequestResize(uint32_t width, uint32_t height);
	static void ResizeBegin();
	static void ResizeEnd();
	static void deinit_render();
	static void ResizeWindow();
	static void set_resize_enabled(bool resizeEnabled) { s_resizeEnabled = resizeEnabled; }
	static bool IsResizeEnabled() { return s_resizeEnabled; }

private:
	static void InitDirectX();
};

