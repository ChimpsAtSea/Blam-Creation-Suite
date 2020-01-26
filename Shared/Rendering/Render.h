#pragma once

class Render
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
	static ID3D11DepthStencilView* s_pDepthStencilView;
	static bool s_resizeEnabled;

	static DirectX::XMMATRIX viewMatrix;
	static DirectX::XMMATRIX perspectiveMatrix;
	static DirectX::XMMATRIX viewMatrixTransposed;
	static DirectX::XMMATRIX perspectiveMatrixTransposed;

	static void UpdatePerspective(float fieldOfViewHorizontal, float aspectRatio);
	static void UpdateView(
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
	static bool CalculateScreenCoordinates(float positionX, float positionY, float positionZ, float& screenX, float& screenY);


	static void CreateSwapchain(IDXGISwapChain1*& s_pSwapChain);
	static void Init(HINSTANCE hInstance, ID3D11Device* pDevice, IDXGISwapChain1* pSwapChain);
	static void Init(HINSTANCE hInstance);
	static void BeginFrame(bool clear, float clearColor[4], bool setTargets = true);
	static void EndFrame();
	static void Deinit();
	static void ResizeWindow();
	static void SetResizeEnabled(bool resizeEnabled) { s_resizeEnabled = resizeEnabled; }
	static bool IsResizeEnabled() { return s_resizeEnabled; }

private:
	static void InitDirectX();
};

