#include "graphicslib-private-pch.h"

c_window_windows::c_window_windows(
	const char* window_title,
	const char* window_id,
	e_window_icon window_icon_type,
	unsigned long init_width,
	unsigned long init_height,
	float4 background_color,
	const char* debug_name) :
	window_handle(NULL),
	window_brush(NULL),
	window_icon(NULL),
	process_module(),
	window_class_name(),
	is_open(true)
{
	BCS_FAIL_THROW(get_process_module(process_module));

	BCS_CHAR_TO_WIDECHAR_STACK(window_title, window_title_wc);
	BCS_CHAR_TO_WIDECHAR_HEAP(window_id, window_id_wc);
	window_class_name = window_id_wc;

	unsigned char background_red = static_cast<unsigned char>(background_color.x * 255.0f);
	unsigned char background_green = static_cast<unsigned char>(background_color.y * 255.0f);
	unsigned char background_blue = static_cast<unsigned char>(background_color.z * 255.0f);
	unsigned char background_alpha = static_cast<unsigned char>(background_color.w * 255.0f);
	window_brush = CreateSolidBrush(RGB(background_red, background_green, background_blue));

	switch (window_icon_type)
	{
	case _window_icon_blam_creation_suite:
		resources_get_resource_icon_handle(_bcs_resource_type_icon_blam_creation_suite, window_icon);
		break;
	case _window_icon_mandrill:
		resources_get_resource_icon_handle(_bcs_resource_type_icon_mandrill, window_icon);
		break;
	case _window_icon_application:
	default:
		resources_get_resource_icon_handle(_bcs_resource_type_icon_application, window_icon);
		break;
	}

	{
		WNDCLASSW window_class = {};
		window_class.lpfnWndProc = window_procedure_callback;
		window_class.hInstance = instance_handle;
		window_class.lpszClassName = window_id_wc;
		window_class.hbrBackground = window_brush;
		window_class.hIcon = window_icon;
		RegisterClassW(&window_class);
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

	window_handle = CreateWindowExW(
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

	SetWindowLongPtrW(window_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

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
	if (window_handle != NULL)
	{
		DestroyWindow(window_handle);
	}

	ASSERT(window_handle == NULL);

	BOOL delete_brush_result = DeleteObject(window_brush);
	if (delete_brush_result == FALSE)
	{
		throw BCS_E_FAIL;
	}
	BOOL unregister_window_class_result = UnregisterClassW(window_class_name, instance_handle);
	if (unregister_window_class_result == FALSE)
	{
		throw BCS_E_FAIL;
	}
	tracked_free(const_cast<wchar_t*>(window_class_name));
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
	LONG_PTR get_window_long_ptr_result = GetWindowLongPtrW(window_handle, GWLP_USERDATA);
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
		if (this->window_handle == window_handle)
		{
			this->window_handle = NULL;
		}
		PostQuitMessage(0);
	}
	return 0;
	}

	return DefWindowProc(window_handle, message, wparam, lparam);
}

BCS_RESULT window_windows_create(
	const char* window_title,
	const char* window_id,
	e_window_icon window_icon,
	unsigned long width,
	unsigned long height,
	float4 background_color,
	c_window_windows*& window,
	const char* debug_name)
{
	try
	{
		window = new() c_window_windows(
			window_title,
			window_id,
			window_icon,
			width,
			height,
			background_color,
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
