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
	static void init_window(const char* pWindowTitle, const char* pConsoleTitle, const char* pApplicationName);
	static void deinit_window();
	static void update_window();
	static void update_no_callbacks();

	inline static void register_window_procedure_callback(WNDPROC pWndProcCallback) { s_WndProcCallbacks.push_back(pWndProcCallback); }
	inline static void unregister_window_procedure_callback(WNDPROC pWndProcCallback) { vector_erase_by_value_helper(s_WndProcCallbacks, pWndProcCallback); }

	typedef void(*UpdateCallback)();
	inline static void register_update_callback(UpdateCallback pUpdateCallback) { s_UpdateCallbacks.push_back(pUpdateCallback); }
	inline static void unregister_update_callback(UpdateCallback pUpdateCallback) { vector_erase_by_value_helper(s_UpdateCallbacks, pUpdateCallback); }

	typedef void(*DestroyCallback)();
	inline static void register_destroy_callback(DestroyCallback pDestroyCallback) { s_DestroyCallbacks.push_back(pDestroyCallback); }
	inline static void unregister_destroy_callback(DestroyCallback pDestroyCallback) { vector_erase_by_value_helper(s_DestroyCallbacks, pDestroyCallback); }

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void set_post_message_thread_id(HANDLE hThread);

	static int get_width();
	static int get_height();
	static inline float get_width_float() { return static_cast<float>(get_width()); }
	static inline float get_height_float() { return static_cast<float>(get_height()); }
	static float get_aspect_ratio();
	static void SetWindowTitle(const wchar_t* title);
	static void Show();
private:
	static void updateWindowSize(SIZE& rSize);

	static SIZE			s_size;
	static HICON		s_hIcon;
	static HWND			s_hWnd;
	static HWND			s_hFocusWnd;
	static HWND			s_hForegroundWnd;
	static HINSTANCE	s_hInstance;
	static HANDLE		s_hPostMessageThread;
	static DWORD		s_hPostMessageThreadId;
	static std::vector<WNDPROC> s_WndProcCallbacks;
	static std::vector<UpdateCallback> s_UpdateCallbacks;
	static std::vector<DestroyCallback> s_DestroyCallbacks;
};

