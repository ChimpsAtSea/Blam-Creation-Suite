#include "shared-private-pch.h"

SIZE Window::s_size = {};
HICON Window::s_hIcon = NULL;
HWND Window::s_hWnd = NULL;
HWND Window::s_hFocusWnd = NULL;
HWND Window::s_hForegroundWnd = NULL;
HINSTANCE Window::s_hInstance = NULL;
HANDLE Window::s_hPostMessageThread = NULL;
DWORD Window::s_hPostMessageThreadId = NULL;
std::vector<WNDPROC> Window::m_WndProcCallbacks;

void(*Window::s_OnDestroyCallback)() = nullptr;
void(*Window::s_OnUpdateCallback)() = nullptr;

void Window::getWindowSize(SIZE& rSize)
{
	RECT rect = {};
	GetClientRect(s_hWnd, &rect);
	rSize.cx = rect.right - rect.left;
	rSize.cy = rect.bottom - rect.top;
}

void Window::SetWindowTitle(const char* pTitle)
{
	::SetWindowTextA(s_hWnd, pTitle);
}

void Window::Show()
{
	ShowWindow(GetWindowHandle(), SW_SHOW);
	SetFocus(GetWindowHandle());
	SetForegroundWindow(GetWindowHandle());
}

void Window::SetPostMessageThreadId(HANDLE hThread)
{
	s_hPostMessageThread = hThread;
	s_hPostMessageThreadId = GetThreadId(s_hPostMessageThread);
}

int Window::GetWindowWidth()
{
	return s_size.cx;
}

int Window::GetWindowHeight()
{
	return s_size.cy;
}

HWND Window::GetWindowHandle()
{
	return s_hWnd;
}

bool Window::IsWindowFocused()
{
	return s_hWnd == s_hFocusWnd;
}

HICON Window::GetIcon()
{
	return s_hIcon;
}

void Window::SetIcon(HICON hIcon)
{
	s_hIcon = hIcon;
}

void Window::SetOnUpdateCallback(void(callback)())
{
	s_OnUpdateCallback = callback;
}

void Window::SetOnDestroyCallback(void(callback)())
{
	s_OnDestroyCallback = callback;
}

void Window::OnDestroyCallback()
{
	if (s_OnDestroyCallback)
	{
		s_OnDestroyCallback();
	}
}

void Window::OnUpdateCallback()
{
	if (s_OnUpdateCallback)
	{
		s_OnUpdateCallback();
	}
}

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	for (WNDPROC callback : m_WndProcCallbacks)
	{
		callback(hwnd, msg, wParam, lParam);
	}

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
		getWindowSize(s_size);
		Render::ResizeWindow();
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

void Window::Init(const char* pWindowTitle, const char* pConsoleTitle, const char* pApplicationName)
{
	SetProcessDPIAware();

#ifdef _DEBUG
	constexpr bool isDebug = true;
#else
	constexpr bool isDebug = false;
#endif
	if ((CommandLine::HasCommandLineArg("-showconsole") || isDebug) && !CommandLine::HasCommandLineArg("-hideconsole"))
	{
		AllocConsole();
		FILE* pStdOut = freopen("CONOUT$", "w", stdout);
		assert(pStdOut);
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
	windowClass.hIcon = Window::GetIcon();
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = pApplicationName;
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

void Window::Deinit()
{
	CloseWindow(s_hWnd);
	UnregisterClassA("mantle_window_class", s_hInstance);
}

void Window::UpdateNoCallbacks()
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
}

void Window::Update()
{
	UpdateNoCallbacks();
	OnUpdateCallback();
}

