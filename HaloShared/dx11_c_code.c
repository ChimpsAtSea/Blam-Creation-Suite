#include <windows.h>
#include <d3d11.h>

void* GetIDXGISwapChainPresent(IDXGISwapChain* pSwapchain)
{
	return pSwapchain->lpVtbl->Present;
}