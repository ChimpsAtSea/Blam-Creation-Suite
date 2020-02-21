#include "pch.h"

using namespace OpusUIPrototype;
using namespace Windows::Foundation;
using namespace Concurrency;
using namespace winrt::Windows::Foundation;

__forceinline HMODULE GetKernelModule()
{
	MEMORY_BASIC_INFORMATION mbi = { 0 };
	VirtualQuery(VirtualQuery, &mbi, sizeof(mbi));
	return reinterpret_cast<HMODULE>(mbi.AllocationBase);
}

// Loads and initializes application assets when the application is loaded.
OpusUIPrototypeMain::OpusUIPrototypeMain(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
	m_deviceResources(deviceResources), m_pointerLocationX(0.0f)
{
	// Register to be notified if the Device is lost or recreated
	m_deviceResources->RegisterDeviceNotify(this);

	// might have to hook into the present function to override behavior allowing us to call m_deviceResources->Present()
	// this would require a copy of the vftable to be created to leave the original present function in place

	

	static bool running = true;
	static std::thread thread = std::thread([=]()
		{
			static HMODULE kernelModule = GetKernelModule();
			typedef HMODULE(*LoadLibraryAFunc)(_In_ LPCSTR lpLibFileName);
			static LoadLibraryAFunc LoadLibraryA = reinterpret_cast<LoadLibraryAFunc>(GetProcAddress(kernelModule, "LoadLibraryA"));
			typedef HMODULE(*GetModuleHandleAFunc)(_In_opt_ LPCSTR lpModuleName);
			static GetModuleHandleAFunc GetModuleHandleA = reinterpret_cast<GetModuleHandleAFunc>(GetProcAddress(kernelModule, "GetModuleHandleA"));
			static HMODULE OpusXIGameInterface = GetModuleHandleA("OpusXIGameInterface.dll");

			typedef void(__cdecl* run_func)(ID3D11Device* pDevice, IDXGISwapChain* pSwapChain);
			static run_func run = reinterpret_cast<run_func>(GetProcAddress(OpusXIGameInterface, "run"));
			assert(run);

			run(m_deviceResources->GetD3DDevice(), m_deviceResources->GetSwapChain());

			//// Calculate the updated frame and render once per vertical blanking interval.
			//while (running)
			//{
			//	

			//	//// #TODO: Run game here

			//	//critical_section::scoped_lock lock(m_criticalSection);



			//	////Update();
			//	//if (Render())
			//	//{
			//	//	m_deviceResources->Present();
			//	//}
			//}

		});
}

OpusUIPrototypeMain::~OpusUIPrototypeMain()
{
	// Deregister device notification
	m_deviceResources->RegisterDeviceNotify(nullptr);
}

// Updates application state when the window size changes (e.g. device orientation change)
void OpusUIPrototypeMain::CreateWindowSizeDependentResources()
{
	// TODO: Replace this with the size-dependent initialization of your app's content.
}

// Updates the application state once per frame.
void OpusUIPrototypeMain::Update()
{
	ProcessInput();
}

// Process all input from the user before updating game state
void OpusUIPrototypeMain::ProcessInput()
{
	// TODO: Add per frame input handling here.
}

// Renders the current frame according to the current application state.
// Returns true if the frame was rendered and is ready to be displayed.
bool OpusUIPrototypeMain::Render()
{
	ID3D11DeviceContext3* pDeviceContext = m_deviceResources->GetD3DDeviceContext();

	// Reset the viewport to target the whole screen.
	const D3D11_VIEWPORT& rViewport = m_deviceResources->GetScreenViewport();
	pDeviceContext->RSSetViewports(1, &rViewport);

	// Reset render targets to the screen.
	ID3D11RenderTargetView* const targets[1] = { m_deviceResources->GetBackBufferRenderTargetView() };
	pDeviceContext->OMSetRenderTargets(1, targets, m_deviceResources->GetDepthStencilView());

	// Clear the back buffer and depth stencil view.
	pDeviceContext->ClearRenderTargetView(m_deviceResources->GetBackBufferRenderTargetView(), DirectX::Colors::CornflowerBlue);
	pDeviceContext->ClearDepthStencilView(m_deviceResources->GetDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	// Render the scene objects.
	// TODO: Replace this with your app's content rendering functions.

	return true;
}

// Notifies renderers that device resources need to be released.
void OpusUIPrototypeMain::OnDeviceLost()
{

}

// Notifies renderers that device resources may now be recreated.
void OpusUIPrototypeMain::OnDeviceRestored()
{
	CreateWindowSizeDependentResources();
}
