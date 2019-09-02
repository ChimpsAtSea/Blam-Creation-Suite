#include <windows.h>
#include <d3d11.h>

void* GetIDXGISwapChainPresent(IDXGISwapChain* pSwapchain)
{
	if (pSwapchain)
	{
		return pSwapchain->lpVtbl->Present;
	}
	return 0;
}