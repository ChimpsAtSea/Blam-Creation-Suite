#include "shared-private-pch.h"

SIZE c_window::s_size = {};
HICON c_window::s_hIcon = NULL;
HWND c_window::s_hWnd = NULL;
HWND c_window::s_hFocusWnd = NULL;
HWND c_window::s_hForegroundWnd = NULL;
HINSTANCE c_window::s_hInstance = NULL;
HANDLE c_window::s_hPostMessageThread = NULL;
DWORD c_window::s_hPostMessageThreadId = NULL;
std::vector<WNDPROC>  c_window::s_WndProcCallbacks;
std::vector< c_window::UpdateCallback>  c_window::s_UpdateCallbacks;
std::vector< c_window::DestroyCallback>  c_window::s_DestroyCallbacks;

void c_window::updateWindowSize(SIZE& rSize)
{
	RECT rect = {};
	GetClientRect(s_hWnd, &rect);
	rSize.cx = rect.right - rect.left;
	rSize.cy = rect.bottom - rect.top;
}

void c_window::SetWindowTitle(const char* pTitle)
{
	::SetWindowTextA(s_hWnd, pTitle);
}

void c_window::Show()
{
	ShowWindow(GetWindowHandle(), SW_SHOW);
	SetFocus(GetWindowHandle());
	SetForegroundWindow(GetWindowHandle());
}

void c_window::SetPostMessageThreadId(HANDLE hThread)
{
	s_hPostMessageThread = hThread;
	s_hPostMessageThreadId = GetThreadId(s_hPostMessageThread);
}

int c_window::get_width()
{
	return __max(1l, s_size.cx);
}

int c_window::get_height()
{
	return __max(1l, s_size.cy);
}

float c_window::get_aspect_ratio()
{
	float aspectRatio = static_cast<float>(c_window::get_width()) / static_cast<float>(c_window::get_height());
	return aspectRatio;
}

HWND c_window::GetWindowHandle()
{
	return s_hWnd;
}

bool c_window::IsWindowFocused()
{
	return s_hWnd == s_hFocusWnd;
}

HICON c_window::GetIcon()
{
	return s_hIcon;
}

void c_window::SetIcon(HICON hIcon)
{
	s_hIcon = hIcon;
}

void c_window::OnDestroyCallback()
{
	for (DestroyCallback destroyCallback : s_DestroyCallbacks)
	{
		destroyCallback();
	}
}

void c_window::OnUpdateCallback()
{
	for(UpdateCallback updateCallback : s_UpdateCallbacks)
	{
		updateCallback();
	}
}

LRESULT CALLBACK c_window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	for (WNDPROC callback : s_WndProcCallbacks)
	{
		callback(hwnd, msg, wParam, lParam);
	}

	c_debug_gui::WndProc(hwnd, msg, wParam, lParam);
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
		updateWindowSize(s_size);
		c_render::RequestResize(c_window::get_width(), c_window::get_height());
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

void c_window::init_window(const char* pWindowTitle, const char* pConsoleTitle, const char* pApplicationName)
{
	SetProcessDPIAware();

#ifdef _DEBUG
	constexpr bool isDebug = true;
#else
	constexpr bool isDebug = false;
#endif
	if ((c_command_line::has_command_line_arg("-showconsole") || isDebug) && !c_command_line::has_command_line_arg("-hideconsole"))
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		ASSERT(pStdOut != nullptr);
		SetConsoleTitleA(pConsoleTitle);
	}

	s_hInstance = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASSEX windowClass = { };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = s_hInstance;
	windowClass.hIcon = c_window::GetIcon();
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = pApplicationName;
	windowClass.hCursor = NULL;
	ATOM registerClassExResult = RegisterClassEx(&windowClass);
	if (registerClassExResult == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR(L"Failed to register window class [%i]", err);
	}

	// Create the window.
	s_hWnd = CreateWindowEx(
		0,                              // Optional window styles.
		pApplicationName,               // Window class
		pWindowTitle,					// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT,
		GetSystemMetrics(SM_CXSCREEN) / 4 * 3, GetSystemMetrics(SM_CYSCREEN) / 4 * 3,

		NULL,							// Parent window    
		NULL,							// Menu
		s_hInstance,					// Instance handle
		NULL							// Additional application data
	);

	if (s_hWnd == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR(L"Failed to create window [%i]", err);
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

void c_window::deinit_window()
{
	CloseWindow(s_hWnd);
	UnregisterClassA("mantle_window_class", s_hInstance);
}

void c_window::UpdateNoCallbacks()
{
	c_console::Update();

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
}

void c_window::update_window()
{
	UpdateNoCallbacks();
	OnUpdateCallback();
}

