#include "graphicslib-private-pch.h"

c_window_windows::c_window_windows(
	const char* window_title,
	const char* window_id,
	unsigned long init_width,
	unsigned long init_height,
	const char* debug_name) :
	window_handle(NULL),
	is_open(true)
{
	BCS_RESULT rs = BCS_S_OK;
	union
	{
		HINSTANCE instance_handle;
		void* process_module;
	};
	if (BCS_FAILED(rs = get_process_module(process_module)))
	{
		throw rs;
	}

	BCS_CHAR_TO_WIDECHAR_STACK(window_title, window_title_wc);
	BCS_CHAR_TO_WIDECHAR_STACK(window_id, window_id_wc);

	{
		WNDCLASS window_class{};
		window_class.lpfnWndProc = window_procedure_callback;
		window_class.hInstance = instance_handle;
		window_class.lpszClassName = window_id_wc;
		window_class.hbrBackground = CreateSolidBrush(0xFF000000); // solid black
		RegisterClass(&window_class);
	}

	if (init_width == ULONG_MAX)
	{
		init_width = CW_USEDEFAULT;
	}
	if (init_height == ULONG_MAX)
	{
		init_height = CW_USEDEFAULT;
	}

	SetProcessDPIAware();

	window_handle = CreateWindowEx(
		0,                              // Optional window styles.
		window_id_wc,					// Window class
		window_title_wc,				// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		CW_USEDEFAULT, CW_USEDEFAULT,	// Position
		init_width, init_height,		// Size
		NULL,							// Parent window    
		NULL,							// Menu
		instance_handle,				// r_instance handle
		NULL							// Additional application data
	);

	SetWindowLongPtr(window_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	ShowWindow(window_handle, SW_SHOW);

	RECT window_rectangle;
	if (GetClientRect(window_handle, &window_rectangle))
	{
		width = window_rectangle.right - window_rectangle.left;
		height = window_rectangle.bottom - window_rectangle.top;
	}
}

c_window_windows::~c_window_windows()
{
	
}

bool c_window_windows::update()
{
	MSG window_message = {};
	while (PeekMessage(&window_message, NULL, 0, 0, TRUE))
	{
		TranslateMessage(&window_message);
		DispatchMessage(&window_message);
	}
	return is_open;
}

LRESULT CALLBACK c_window_windows::window_procedure_callback(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam)
{
	LONG_PTR get_window_long_ptr_result = GetWindowLongPtr(window_handle, GWLP_USERDATA);
	c_window_windows* window = reinterpret_cast<c_window_windows*>(get_window_long_ptr_result);

	if (window != nullptr) // let the window instance handle the message
	{
		return window->window_procedure(window_handle, message, wparam, lparam);
	}
	return DefWindowProc(window_handle, message, wparam, lparam);
}

LRESULT c_window_windows::window_procedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam)
{
	on_window_procedure(window_handle, message, wparam, lparam);

	switch (message)
	{
	case WM_SIZE:
	{
		unsigned long new_width = LOWORD(lparam);
		unsigned long new_height = HIWORD(lparam);
		set_size(new_width, new_height);
	}
	break;
	case WM_CLOSE:
	{
		is_open = false;
		DestroyWindow(window_handle);
	}
	return 0;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;
	}

	return DefWindowProc(window_handle, message, wparam, lparam);
}

BCS_RESULT window_windows_create(
	const char* window_title,
	const char* window_id,
	unsigned long width,
	unsigned long height,
	c_window_windows*& window,
	const char* debug_name)
{
	try
	{
		window = new c_window_windows(
			window_title,
			window_id,
			width,
			height,
			debug_name);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT window_windows_destroy(c_window_windows* window)
{
	try
	{
		delete window;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
