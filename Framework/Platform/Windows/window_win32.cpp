#include "platform-private-pch.h"

SIZE c_window_win32::s_size = {};
HICON c_window_win32::s_icon_handle = NULL;
HWND c_window_win32::s_window_handle = NULL;
HWND c_window_win32::s_focused_window_handle = NULL;
HWND c_window_win32::s_foreground_window_handle = NULL;
HINSTANCE c_window_win32::s_instance_handle = NULL;
HANDLE c_window_win32::s_post_message_thread_handle = NULL;
DWORD c_window_win32::s_post_message_thread_id = NULL;
std::vector<WNDPROC>  c_window_win32::s_window_procedure_callbacks;
std::vector< c_window_win32::t_update_callback>  c_window_win32::s_update_callbacks;
std::vector< c_window_win32::t_destroy_callback>  c_window_win32::s_destroy_callbacks;

void c_window_win32::update_window_size(SIZE& rSize)
{
	RECT rect = {};
	GetClientRect(s_window_handle, &rect);
	rSize.cx = rect.right - rect.left;
	rSize.cy = rect.bottom - rect.top;
}

void c_window_win32::SetWindowTitle(const wchar_t* title)
{
	::SetWindowTextW(s_window_handle, title);
}

void c_window_win32::Show()
{
	ShowWindow(get_window_handle(), SW_SHOW);
	SetFocus(get_window_handle());
	SetForegroundWindow(get_window_handle());
}

void c_window_win32::set_post_message_thread_id(HANDLE hThread)
{
	s_post_message_thread_handle = hThread;
	s_post_message_thread_id = GetThreadId(s_post_message_thread_handle);
}

int c_window_win32::get_width()
{
	return __max(1l, s_size.cx);
}

int c_window_win32::get_height()
{
	return __max(1l, s_size.cy);
}

float c_window_win32::get_aspect_ratio()
{
	float aspectRatio = static_cast<float>(c_window_win32::get_width()) / static_cast<float>(c_window_win32::get_height());
	return aspectRatio;
}

HWND c_window_win32::get_window_handle()
{
	return s_window_handle;
}

bool c_window_win32::IsWindowFocused()
{
	return s_window_handle == s_focused_window_handle;
}

HICON c_window_win32::GetIcon()
{
	return s_icon_handle;
}

void c_window_win32::SetIcon(HICON hIcon)
{
	s_icon_handle = hIcon;
}

void c_window_win32::OnDestroyCallback()
{
	for (t_destroy_callback destroyCallback : s_destroy_callbacks)
	{
		destroyCallback();
	}
}

void c_window_win32::OnUpdateCallback()
{
	for(t_update_callback updateCallback : s_update_callbacks)
	{
		updateCallback();
	}
}

LRESULT CALLBACK c_window_win32::window_procedure(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
	for (WNDPROC window_procedure_callback : s_window_procedure_callbacks)
	{
		window_procedure_callback(hwnd, msg, w_param, l_param);
	}

	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((w_param & 0xfff0) == SC_KEYMENU)
		{
			return 0;
		}
		break;
	case WM_DESTROY:
		OnDestroyCallback();
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		update_window_size(s_size);
		// #BCSREFACTOR c_render::RequestResize(c_window_win32::get_width(), c_window_win32::get_height());
		// #TODO: tell game to resize
		break;
	case WM_KILLFOCUS:
	case WM_SETFOCUS:
		s_focused_window_handle = GetFocus();
		s_foreground_window_handle = GetForegroundWindow();
		break;
	}
	return DefWindowProc(hwnd, msg, w_param, l_param);
}

void c_window_win32::init_window(const wchar_t* window_title, const wchar_t* console_title, const wchar_t* application_name)
{
	SetProcessDPIAware();

	s_instance_handle = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASSEXW window_class = { };
	window_class.cbSize = sizeof(WNDCLASSEX);
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = window_procedure;
	window_class.cbClsExtra = 0;
	window_class.cbWndExtra = 0;
	window_class.hInstance = s_instance_handle;
	window_class.hIcon = c_window_win32::GetIcon();
	window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	window_class.lpszMenuName = NULL;
	window_class.lpszClassName = application_name;
	window_class.hCursor = NULL;
	ATOM register_class_ex_result = RegisterClassExW(&window_class);
	if (register_class_ex_result == NULL)
	{
		int last_error = GetLastError();
		FATAL_ERROR(L"Failed to register window class [%i]", last_error);
	}

	// Create the window.
	s_window_handle = CreateWindowExW(
		0,                              // Optional window styles.
		application_name,               // Window class
		window_title,					// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT,
		GetSystemMetrics(SM_CXSCREEN) / 4 * 3, GetSystemMetrics(SM_CYSCREEN) / 4 * 3,

		NULL,							// Parent window
		NULL,							// Menu
		s_instance_handle,					// Instance handle
		NULL							// Additional application data
	);

	if (s_window_handle == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR(L"Failed to create window [%i]", err);
	}

	ShowWindow(s_window_handle, SW_SHOW);
	SetFocus(s_window_handle);

	static RAWINPUTDEVICE raw_mouse_input_device = {};
	raw_mouse_input_device.usUsagePage = HID_USAGE_PAGE_GENERIC;
	raw_mouse_input_device.usUsage = HID_USAGE_GENERIC_MOUSE;
	raw_mouse_input_device.dwFlags = RIDEV_INPUTSINK;
	raw_mouse_input_device.hwndTarget = s_window_handle;
	static RAWINPUTDEVICE raw_input_devices[] = { raw_mouse_input_device };
	BOOL register_raw_input_devices_result = RegisterRawInputDevices(raw_input_devices, _countof(raw_input_devices), sizeof(raw_input_devices));
	ASSERT(register_raw_input_devices_result == TRUE);
}

void c_window_win32::deinit_window()
{
	CloseWindow(s_window_handle);
	UnregisterClassA("mandrill_window_class", s_instance_handle);
}

void c_window_win32::update_no_callbacks()
{
	c_console::Update();

	MSG msg = {};

	while (PeekMessage(&msg, s_window_handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (GetAsyncKeyState(VK_F11))
	{
		OnDestroyCallback();
	}
}

void c_window_win32::update_window()
{
	update_no_callbacks();
	OnUpdateCallback();
}
