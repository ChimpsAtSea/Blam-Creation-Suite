#include "mantle-private-pch.h"

HICON CustomWindow::s_hIcon = NULL;
HWND CustomWindow::s_hWnd = NULL;
HWND CustomWindow::s_hFocusWnd = NULL;
HWND CustomWindow::s_hForegroundWnd = NULL;
HINSTANCE CustomWindow::s_hInstance = NULL;
HANDLE CustomWindow::s_hPostMessageThread = NULL;
DWORD CustomWindow::s_hPostMessageThreadId = NULL;

void(*CustomWindow::s_OnDestroyCallback)() = nullptr;
void(*CustomWindow::s_OnUpdateCallback)() = nullptr;

void CustomWindow::GetWindowSize(SIZE& rSize)
{
	RECT rect = {};
	GetClientRect(s_hWnd, &rect);
	rSize.cx = rect.right - rect.left;
	rSize.cy = rect.bottom - rect.top;
}

void CustomWindow::SetWindowTitle(const char* pTitle)
{
	::SetWindowTextA(s_hWnd, pTitle);
}

void CustomWindow::Show()
{
	ShowWindow(GetWindowHandle(), SW_SHOW);
	SetFocus(GetWindowHandle());
	SetForegroundWindow(GetWindowHandle());
}

void CustomWindow::SetPostMessageThreadId(HANDLE hThread)
{
	s_hPostMessageThread = hThread;
	s_hPostMessageThreadId = GetThreadId(s_hPostMessageThread);
}

HWND CustomWindow::GetWindowHandle()
{
	return s_hWnd;
}

bool CustomWindow::IsWindowFocused()
{
	return s_hWnd == s_hFocusWnd;
}

HICON CustomWindow::GetIcon()
{
	return s_hIcon;
}

void CustomWindow::SetIcon(HICON hIcon)
{
	s_hIcon = hIcon;
}

void CustomWindow::SetOnUpdateCallback(void(callback)())
{
	s_OnUpdateCallback = callback;
}

void CustomWindow::SetOnDestroyCallback(void(callback)())
{
	s_OnDestroyCallback = callback;
}

void CustomWindow::OnDestroyCallback()
{
	if (s_OnDestroyCallback)
	{
		s_OnDestroyCallback();
	}
}

void CustomWindow::OnUpdateCallback()
{
	if (s_OnUpdateCallback)
	{
		s_OnUpdateCallback();
	}
}

LRESULT CALLBACK CustomWindow::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	DebugUI::WndProc(hwnd, msg, wParam, lParam);
	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
		{
			return 0;
		}
		break;
	case WM_DESTROY:
		OnDestroyCallback();
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		GameRender::ResizeWindow();
		// #TODO: tell game to resize
		break;
	case WM_KILLFOCUS:
	case WM_SETFOCUS:
		s_hFocusWnd = GetFocus();
		s_hForegroundWnd = GetForegroundWindow();
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CustomWindow::Init()
{
	SetProcessDPIAware();

	s_hInstance = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASSEX windowClass = { };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = s_hInstance;
	windowClass.hIcon = CustomWindow::GetIcon();
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "mantle_window_class";
	windowClass.hCursor = NULL;
	ATOM registerClassExResult = RegisterClassEx(&windowClass);
	if (registerClassExResult == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR("Failed to register window class [%i]", err);
	}

	// Create the window.
	s_hWnd = CreateWindowEx(
		0,                              // Optional window styles.
		"mantle_window_class",                     // Window class
		"Mantle",    // Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT,
		GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),

		NULL,       // Parent window    
		NULL,       // Menu
		s_hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (s_hWnd == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR("Failed to create window [%i]", err);
	}

	ShowWindow(s_hWnd, SW_SHOW);
	SetFocus(s_hWnd);

	static RAWINPUTDEVICE mouseInputDevice = {};
	mouseInputDevice.usUsagePage = HID_USAGE_PAGE_GENERIC;
	mouseInputDevice.usUsage = HID_USAGE_GENERIC_MOUSE;
	mouseInputDevice.dwFlags = RIDEV_INPUTSINK;
	mouseInputDevice.hwndTarget = s_hWnd;
	static RAWINPUTDEVICE rawInputDevices[] = { mouseInputDevice };
	RegisterRawInputDevices(rawInputDevices, _countof(rawInputDevices), sizeof(rawInputDevices));
}

void CustomWindow::Deinit()
{
	CloseWindow(s_hWnd);
	UnregisterClassA("mantle_window_class", s_hInstance);
}

void CustomWindow::Update()
{
	MSG msg = {};

	while (PeekMessage(&msg, s_hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (GetAsyncKeyState(VK_F11))
	{
		OnDestroyCallback();
	}

	OnUpdateCallback();
}

