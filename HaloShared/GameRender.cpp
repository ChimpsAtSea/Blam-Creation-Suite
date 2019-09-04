#include "haloshared-private-pch.h"

ID3D11Device* GameRender::s_pDevice = nullptr;
ID3D11DeviceContext* GameRender::s_pDeviceContext = nullptr;
IDXGISwapChain* GameRender::s_pSwapChain = nullptr;
DXGI_SWAP_CHAIN_DESC GameRender::s_SwapchainDescription = {};
IDXGIFactory1* GameRender::s_pFactory = nullptr;

typedef struct CINTERFACE_IDXGIFactory1Vtbl
{
	BEGIN_INTERFACE

		HRESULT(STDMETHODCALLTYPE* QueryInterface)(
			IDXGIFactory1* This,
			/* [in] */ REFIID riid,
			/* [annotation][iid_is][out] */
			_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		IDXGIFactory1* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		IDXGIFactory1* This);

	HRESULT(STDMETHODCALLTYPE* SetPrivateData)(
		IDXGIFactory1* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [in] */ UINT DataSize,
		/* [annotation][in] */
		_In_reads_bytes_(DataSize)  const void* pData);

	HRESULT(STDMETHODCALLTYPE* SetPrivateDataInterface)(
		IDXGIFactory1* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][in] */
		_In_opt_  const IUnknown* pUnknown);

	HRESULT(STDMETHODCALLTYPE* GetPrivateData)(
		IDXGIFactory1* This,
		/* [annotation][in] */
		_In_  REFGUID Name,
		/* [annotation][out][in] */
		_Inout_  UINT* pDataSize,
		/* [annotation][out] */
		_Out_writes_bytes_(*pDataSize)  void* pData);

	HRESULT(STDMETHODCALLTYPE* GetParent)(
		IDXGIFactory1* This,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][retval][out] */
		_COM_Outptr_  void** ppParent);

	HRESULT(STDMETHODCALLTYPE* EnumAdapters)(
		IDXGIFactory1* This,
		/* [in] */ UINT Adapter,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter** ppAdapter);

	HRESULT(STDMETHODCALLTYPE* MakeWindowAssociation)(
		IDXGIFactory1* This,
		HWND WindowHandle,
		UINT Flags);

	HRESULT(STDMETHODCALLTYPE* GetWindowAssociation)(
		IDXGIFactory1* This,
		/* [annotation][out] */
		_Out_  HWND* pWindowHandle);

	HRESULT(STDMETHODCALLTYPE* CreateSwapChain)(
		IDXGIFactory1* This,
		/* [annotation][in] */
		_In_  IUnknown* pDevice,
		/* [annotation][in] */
		_In_  DXGI_SWAP_CHAIN_DESC* pDesc,
		/* [annotation][out] */
		_COM_Outptr_  IDXGISwapChain** ppSwapChain);

	HRESULT(STDMETHODCALLTYPE* CreateSoftwareAdapter)(
		IDXGIFactory1* This,
		/* [in] */ HMODULE Module,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter** ppAdapter);

	HRESULT(STDMETHODCALLTYPE* EnumAdapters1)(
		IDXGIFactory1* This,
		/* [in] */ UINT Adapter,
		/* [annotation][out] */
		_COM_Outptr_  IDXGIAdapter1** ppAdapter);

	BOOL(STDMETHODCALLTYPE* IsCurrent)(
		IDXGIFactory1* This);

	END_INTERFACE
} IDXGIFactory1Vtbl;

interface CINTERFACE_IDXGIFactory1
{
	CONST_VTBL struct CINTERFACE_IDXGIFactory1Vtbl* lpVtbl;
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

	auto CreateRenderTargetViewResult = CreateRenderTargetViewPointer(_this, pResource, pDesc, ppRTView);
	assert(CreateRenderTargetViewResult != E_INVALIDARG);
	assert(CreateRenderTargetViewResult == S_OK);
	return CreateRenderTargetViewResult;
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
	auto CreateSwapChainResult = CreateSwapChainPointer(_this, pDevice, pDesc, ppSwapChain);
	assert(CreateSwapChainResult != E_INVALIDARG);
	assert(CreateSwapChainResult == S_OK);
	return CreateSwapChainResult;
}

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

	HRESULT CreateDXGIFactory1Result = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)(&s_pFactory));
	assert(CreateDXGIFactory1Result == S_OK);
	assert(s_pFactory != nullptr);

	// Factory Hooks
	{
		CINTERFACE_IDXGIFactory1* pFactory_CINTERFACE = (CINTERFACE_IDXGIFactory1*)s_pFactory;
		CreateSwapChainPointer = (CreateSwapChainFunction*)pFactory_CINTERFACE->lpVtbl->CreateSwapChain;
		void* detour = CreateSwapChainDetour;
		memcpy_virtual(&pFactory_CINTERFACE->lpVtbl->CreateSwapChain, &detour, 8);
	}

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

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
		&s_pDeviceContext);
	assert(D3D11CreateDeviceResult == S_OK);
	assert(s_pDevice != nullptr);
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
		s_SwapchainDescription = {};

		SIZE size = {};
		CustomWindow::GetWindowSize(size);

		s_SwapchainDescription.BufferDesc.Width = size.cx;
		s_SwapchainDescription.BufferDesc.Height = size.cy;
		s_SwapchainDescription.BufferDesc.RefreshRate.Numerator = 0;
		s_SwapchainDescription.BufferDesc.RefreshRate.Denominator = 0;
		s_SwapchainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		s_SwapchainDescription.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		s_SwapchainDescription.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		s_SwapchainDescription.SampleDesc.Count = 1;
		s_SwapchainDescription.SampleDesc.Quality = 0;
		s_SwapchainDescription.BufferUsage = DXGI_USAGE_SHADER_INPUT | DXGI_USAGE_RENDER_TARGET_OUTPUT;
		s_SwapchainDescription.BufferCount = 1;
		s_SwapchainDescription.OutputWindow = CustomWindow::GetWindowHandle();
		s_SwapchainDescription.Windowed = 1;
		s_SwapchainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		s_SwapchainDescription.Flags = 0;

		s_pFactory->CreateSwapChain(s_pDevice, &s_SwapchainDescription, &s_pSwapChain);
		assert(s_pSwapChain != nullptr);
	}

	DebugUI::Init(s_pSwapChain, s_pDevice, s_pDeviceContext);
	if (strstr(GetCommandLineA(), "-showui"))
	{
		DebugUI::Show();
	}
}

void GameRender::Deinit()
{
	DebugUI::Deinit();

	s_pSwapChain->SetFullscreenState(false, NULL);
	s_pDevice->Release();
	s_pDeviceContext->Release();
	s_pSwapChain->Release();
	s_pFactory->Release();

	s_pDevice = nullptr;
	s_pDeviceContext = nullptr;
	s_pSwapChain = nullptr;
	s_pFactory = nullptr;
	s_SwapchainDescription = {};
}
