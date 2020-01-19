#include "opusframework-private-pch.h"

ID3D11Device* GameRender::s_pDevice = nullptr;
ID3D11DeviceContext1* GameRender::s_pDeviceContext = nullptr;
IDXGISwapChain1* GameRender::s_pSwapChain = nullptr;
IDXGIFactory5* GameRender::s_pFactory = nullptr;
DEVMODE GameRender::s_deviceMode = {};
bool GameRender::s_directxCustomInit = false;

typedef struct CINTERFACE_IDXGIFactory5Vtbl
{
	BEGIN_INTERFACE

		HRESULT(STDMETHODCALLTYPE* QueryInterface)(
			IDXGIFactory5* This,
			/* [in] */ REFIID riid,
			/* [annotation][iid_is][out] */
			_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDXGIFactory5* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDXGIFactory5* This);

	HRESULT(STDMETHODCALLTYPE* SetPrivateData)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [in] */ UINT DataSize,
		/* [annotation][in] */
		_In_reads_bytes_(DataSize)  const void* pData);

	HRESULT(STDMETHODCALLTYPE* SetPrivateDataInterface)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][in] */
		_In_opt_  const IUnknown* pUnknown);

	HRESULT(STDMETHODCALLTYPE* GetPrivateData)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][out][in] */
		_Inout_  UINT* pDataSize,
		/* [annotation][out] */
		_Out_writes_bytes_(*pDataSize)  void* pData);

	HRESULT(STDMETHODCALLTYPE* GetParent)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][retval][out] */
		_COM_Outptr_  void** ppParent);

	HRESULT(STDMETHODCALLTYPE* EnumAdapters)(
		IDXGIFactory5* This,
		/* [in] */ UINT Adapter,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter** ppAdapter);

	HRESULT(STDMETHODCALLTYPE* MakeWindowAssociation)(
		IDXGIFactory5* This,
		HWND WindowHandle,
		UINT Flags);

	HRESULT(STDMETHODCALLTYPE* GetWindowAssociation)(
		IDXGIFactory5* This,
		/* [annotation][out] */
		_Out_  HWND* pWindowHandle);

	HRESULT(STDMETHODCALLTYPE* CreateSwapChain)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  IUnknown* pDevice,
		/* [annotation][in] */
		_In_  DXGI_SWAP_CHAIN_DESC* pDesc,
		/* [annotation][out] */
		_COM_Outptr_  IDXGISwapChain** ppSwapChain);

	HRESULT(STDMETHODCALLTYPE* CreateSoftwareAdapter)(
		IDXGIFactory5* This,
		/* [in] */ HMODULE Module,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter** ppAdapter);

	HRESULT(STDMETHODCALLTYPE* EnumAdapters1)(
		IDXGIFactory5* This,
		/* [in] */ UINT Adapter,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter1** ppAdapter);

	BOOL(STDMETHODCALLTYPE* IsCurrent)(
		IDXGIFactory5* This);

	BOOL(STDMETHODCALLTYPE* IsWindowedStereoEnabled)(
		IDXGIFactory5* This);

	HRESULT(STDMETHODCALLTYPE* CreateSwapChainForHwnd)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  IUnknown* pDevice,
		/* [annotation][in] */
		_In_  HWND hWnd,
		/* [annotation][in] */
		_In_  const DXGI_SWAP_CHAIN_DESC1* pDesc,
		/* [annotation][in] */
		_In_opt_  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
		/* [annotation][in] */
		_In_opt_  IDXGIOutput* pRestrictToOutput,
		/* [annotation][out] */
		_COM_Outptr_  IDXGISwapChain1** ppSwapChain);

	HRESULT(STDMETHODCALLTYPE* CreateSwapChainForCoreWindow)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  IUnknown* pDevice,
		/* [annotation][in] */
		_In_  IUnknown* pWindow,
		/* [annotation][in] */
		_In_  const DXGI_SWAP_CHAIN_DESC1* pDesc,
		/* [annotation][in] */
		_In_opt_  IDXGIOutput* pRestrictToOutput,
		/* [annotation][out] */
		_COM_Outptr_  IDXGISwapChain1** ppSwapChain);

	HRESULT(STDMETHODCALLTYPE* GetSharedResourceAdapterLuid)(
		IDXGIFactory5* This,
		/* [annotation] */
		_In_  HANDLE hResource,
		/* [annotation] */
		_Out_  LUID* pLuid);

	HRESULT(STDMETHODCALLTYPE* RegisterStereoStatusWindow)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  HWND WindowHandle,
		/* [annotation][in] */
		_In_  UINT wMsg,
		/* [annotation][out] */
		_Out_  DWORD* pdwCookie);

	HRESULT(STDMETHODCALLTYPE* RegisterStereoStatusEvent)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  HANDLE hEvent,
		/* [annotation][out] */
		_Out_  DWORD* pdwCookie);

	void (STDMETHODCALLTYPE* UnregisterStereoStatus)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  DWORD dwCookie);

	HRESULT(STDMETHODCALLTYPE* RegisterOcclusionStatusWindow)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  HWND WindowHandle,
		/* [annotation][in] */
		_In_  UINT wMsg,
		/* [annotation][out] */
		_Out_  DWORD* pdwCookie);

	HRESULT(STDMETHODCALLTYPE* RegisterOcclusionStatusEvent)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  HANDLE hEvent,
		/* [annotation][out] */
		_Out_  DWORD* pdwCookie);

	void (STDMETHODCALLTYPE* UnregisterOcclusionStatus)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  DWORD dwCookie);

	HRESULT(STDMETHODCALLTYPE* CreateSwapChainForComposition)(
		IDXGIFactory5* This,
		/* [annotation][in] */
		_In_  IUnknown* pDevice,
		/* [annotation][in] */
		_In_  const DXGI_SWAP_CHAIN_DESC1* pDesc,
		/* [annotation][in] */
		_In_opt_  IDXGIOutput* pRestrictToOutput,
		/* [annotation][out] */
		_COM_Outptr_  IDXGISwapChain1** ppSwapChain);

	UINT(STDMETHODCALLTYPE* GetCreationFlags)(
		IDXGIFactory5* This);

	HRESULT(STDMETHODCALLTYPE* EnumAdapterByLuid)(
		IDXGIFactory5* This,
		/* [annotation] */
		_In_  LUID AdapterLuid,
		/* [annotation] */
		_In_  REFIID riid,
		/* [annotation] */
		_COM_Outptr_  void** ppvAdapter);

	HRESULT(STDMETHODCALLTYPE* EnumWarpAdapter)(
		IDXGIFactory5* This,
		/* [annotation] */
		_In_  REFIID riid,
		/* [annotation] */
		_COM_Outptr_  void** ppvAdapter);

	HRESULT(STDMETHODCALLTYPE* CheckFeatureSupport)(
		IDXGIFactory5* This,
		DXGI_FEATURE Feature,
		/* [annotation] */
		_Inout_updates_bytes_(FeatureSupportDataSize)  void* pFeatureSupportData,
		UINT FeatureSupportDataSize);

	END_INTERFACE
} IDXGIFactory5Vtbl;

interface CINTERFACE_IDXGIFactory5
{
	CONST_VTBL struct CINTERFACE_IDXGIFactory5Vtbl* lpVtbl;
};

struct ID3D11Device_vtbl
{
	void* QueryInterface;
	void* AddRef;
	void* Release;
	void* CreateBuffer;
	void* CreateTexture1D;
	void* CreateTexture2D;
	void* CreateTexture3D;
	void* CreateShaderResourceView;
	void* CreateUnorderedAccessView;
	void* CreateRenderTargetView;
	void* CreateDepthStencilView;
	void* CreateInputLayout;
	void* CreateVertexShader;
	void* CreateGeometryShader;
	void* CreateGeometryShaderWithStreamOutput;
	void* CreatePixelShader;
	void* CreateHullShader;
	void* CreateDomainShader;
	void* CreateComputeShader;
	void* CreateClassLinkage;
	void* CreateBlendState;
	void* CreateDepthStencilState;
	void* CreateRasterizerState;
	void* CreateSamplerState;
	void* CreateQuery;
	void* CreatePredicate;
	void* CreateCounter;
	void* CreateDeferredContext;
	void* OpenSharedResource;
	void* CheckFormatSupport;
	void* CheckMultisampleQualityLevels;
	void* CheckCounterInfo;
	void* CheckCounter;
	void* CheckFeatureSupport;
	void* GetPrivateData;
	void* SetPrivateData;
	void* SetPrivateDataInterface;
	void* GetFeatureLevel;
	void* GetCreationFlags;
	void* GetDeviceRemovedReason;
	void* GetImmediateContext;
	void* SetExceptionMode;
	void* GetExceptionMode;
};

struct __cppobj CINTERFACE_ID3D11Device
{
	ID3D11Device_vtbl* __vftable;
};

typedef HRESULT(CreateRenderTargetViewFunction)(
	CINTERFACE_ID3D11Device* _this,
	ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
	ID3D11RenderTargetView** ppRTView);
CreateRenderTargetViewFunction* CreateRenderTargetViewPointer = nullptr;
HRESULT CreateRenderTargetViewDetour(
	CINTERFACE_ID3D11Device* _this,
	ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
	ID3D11RenderTargetView** ppRTView
)
{
	// its important that we never fail to to run this function as the game does not correctly check this

	HRESULT createRenderTargetViewResult = CreateRenderTargetViewPointer(_this, pResource, pDesc, ppRTView);
	assert(createRenderTargetViewResult != E_INVALIDARG);
	assert(createRenderTargetViewResult == S_OK);
	return createRenderTargetViewResult;
}

typedef HRESULT(CreateSwapChainFunction)(IDXGIFactory1* _this, IUnknown* pDevice, DXGI_SWAP_CHAIN_DESC* pDesc, IDXGISwapChain** ppSwapChain);
CreateSwapChainFunction* CreateSwapChainPointer = nullptr;
HRESULT CreateSwapChainDetour(
	IDXGIFactory1* _this,
	IUnknown* pDevice,
	DXGI_SWAP_CHAIN_DESC* pDesc,
	IDXGISwapChain** ppSwapChain
)
{
	HRESULT createSwapChainResult = CreateSwapChainPointer(_this, pDevice, pDesc, ppSwapChain);
	assert(createSwapChainResult != E_INVALIDARG);
	assert(createSwapChainResult == S_OK);
	return createSwapChainResult;
}

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
	s_SwapchainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT; // Enable GetFrameLatencyWaitableObject()
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

	// Factory Hooks
	{
		CINTERFACE_IDXGIFactory5* pFactory_CINTERFACE = (CINTERFACE_IDXGIFactory5*)s_pFactory;
		CreateSwapChainPointer = (CreateSwapChainFunction*)pFactory_CINTERFACE->lpVtbl->CreateSwapChain;
		void* detour = CreateSwapChainDetour;
		memcpy_virtual(&pFactory_CINTERFACE->lpVtbl->CreateSwapChain, &detour, 8);
	}

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

	// Device Hooks
	{
		CINTERFACE_ID3D11Device* pDevice_CINTERFACE = (CINTERFACE_ID3D11Device*)GameRender::s_pDevice;
		CreateRenderTargetViewPointer = (CreateRenderTargetViewFunction*)pDevice_CINTERFACE->__vftable->CreateShaderResourceView;
		void* detour = CreateRenderTargetViewDetour;
		memcpy_virtual(&pDevice_CINTERFACE->__vftable->CreateShaderResourceView, &detour, 8);
	}

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
	if (GameLauncher::HasCommandLineArg("-showui"))
	{
		DebugUI::Show();
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
