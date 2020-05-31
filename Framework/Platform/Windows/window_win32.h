#pragma once

class c_window_win32
{
public:

	static HICON GetIcon();
	static void SetIcon(HICON hIcon);
	static HWND get_window_handle();
	static bool IsWindowFocused();
	static void OnDestroyCallback();
	static void OnUpdateCallback();
	static void init_window(const wchar_t* window_title, const wchar_t* console_title, const wchar_t* application_name);
	static void deinit_window();
	static void update_window();
	static void update_no_callbacks();

	inline static void register_window_procedure_callback(WNDPROC window_procedure_callback) { s_window_procedure_callbacks.push_back(window_procedure_callback); }
	inline static void unregister_window_procedure_callback(WNDPROC window_procedure_callback) { vector_erase_by_value_helper(s_window_procedure_callbacks, window_procedure_callback); }

	typedef void(*t_update_callback)();
	inline static void register_update_callback(t_update_callback update_callback) { s_update_callbacks.push_back(update_callback); }
	inline static void unregister_update_callback(t_update_callback update_callback) { vector_erase_by_value_helper(s_update_callbacks, update_callback); }

	typedef void(*t_destroy_callback)();
	inline static void register_destroy_callback(t_destroy_callback destroy_callback) { s_destroy_callbacks.push_back(destroy_callback); }
	inline static void unregister_destroy_callback(t_destroy_callback pDestroyCallback) { vector_erase_by_value_helper(s_destroy_callbacks, pDestroyCallback); }

	static LRESULT CALLBACK window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void set_post_message_thread_id(HANDLE hThread);

	static int get_width();																// #TODO Compute these values when the size changes and cache then. (Expensive WinAPI Calls)
	static int get_height();															// #TODO Compute these values when the size changes and cache then. (Expensive WinAPI Calls)
	static inline float get_width_float() { return static_cast<float>(get_width()); }	// #TODO Compute these values when the size changes and cache then. (Expensive WinAPI Calls)
	static inline float get_height_float() { return static_cast<float>(get_height()); }	// #TODO Compute these values when the size changes and cache then. (Expensive WinAPI Calls)
	static float get_aspect_ratio();													// #TODO Compute these values when the size changes and cache then. (Expensive WinAPI Calls x2)
	static void SetWindowTitle(const wchar_t* title);
	static void Show();
private:
	static void update_window_size(SIZE& rSize);

	static SIZE								s_size;
	static HICON							s_icon_handle;
	static HWND								s_window_handle;
	static HWND								s_focused_window_handle;
	static HWND								s_foreground_window_handle;
	static HINSTANCE						s_instance_handle;
	static HANDLE							s_post_message_thread_handle;
	static DWORD							s_post_message_thread_id;
	static std::vector<WNDPROC>				s_window_procedure_callbacks;
	static std::vector<t_update_callback>	s_update_callbacks;
	static std::vector<t_destroy_callback>	s_destroy_callbacks;
};

