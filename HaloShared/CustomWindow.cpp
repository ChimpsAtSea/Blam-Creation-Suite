#include "haloshared-private-pch.h"

CustomWindow::CreateWindowExA_Func CustomWindow::CreateWindowExA = nullptr;
CustomWindow::RegisterClassExA_Func CustomWindow::RegisterClassExA = nullptr;
HWND CustomWindow::s_hwnd;

void CustomWindow::SetupHooks()
{
	create_dll_hook("USER32.dll", "RegisterClassExA", CustomWindow::CustomRegisterClassExA, RegisterClassExA);
	create_dll_hook("USER32.dll", "CreateWindowExA", CustomWindow::CustomCreateWindowExA, CreateWindowExA);
}

void CustomWindow::Update()
{
	MSG msg = {};

	while (PeekMessage(&msg, s_hwnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (GetAsyncKeyState(VK_F11))
	{
		byte_183984DE4 = 1;
		g_gameManuallyKilled = true;
	}
}

HWND CustomWindow::GetWindowHandle()
{
	return s_hwnd;
}

LRESULT CALLBACK CustomWindow::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		byte_183984DE4 = 1;
		g_gameManuallyKilled = true;
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		// #TODO: tell game to resize
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

ATOM WINAPI CustomWindow::CustomRegisterClassExA(_In_ WNDCLASSEXA* arg)
{
	assert(arg->cbSize == sizeof(WNDCLASSEXA));

	HMODULE hHaloReachModule = GetModuleHandleA(GetHaloExecutableString(HaloGameID::HaloReach));
	assert(hHaloReachModule);

	arg->cbSize = sizeof(WNDCLASSEXA);
	arg->style = CS_HREDRAW | CS_VREDRAW;
	arg->lpfnWndProc = WndProc;
	arg->cbClsExtra = 0;
	arg->cbWndExtra = 0;
	arg->hInstance = hHaloReachModule;
	arg->hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	arg->hIcon = g_icon;

	// #NOTE: Use existing provided pointer as its memory inside the game itself
	//arg->lpszClassName = "HaloReach";
	memcpy(const_cast<LPSTR>(arg->lpszClassName), "HaloReach", sizeof("HaloReach"));

	return RegisterClassExA(arg);
}

HWND WINAPI CustomWindow::CustomCreateWindowExA(
	_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam)
{
	HWND result = CreateWindowExA(
		dwExStyle,
		lpClassName,
		"Halo Reach",
		dwStyle | WS_SIZEBOX,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		lpParam);

	// #TODO: MOVE THIS TO GAME CODE
	s_hwnd = result;

	return result;
}