#pragma once

class Window
{
public:

	static HICON GetIcon();
	static void SetIcon(HICON hIcon);
	static HWND GetWindowHandle();
	static bool IsWindowFocused();
	static void OnDestroyCallback();
	static void OnUpdateCallback();
	static void Init(const char* pWindowTitle, const char* pConsoleTitle, const char* pApplicationName);
	static void Deinit();
	static void Update();
	static void UpdateNoCallbacks();

	inline static void RegisterWndProcCallback(WNDPROC pWndProcCallback) { s_WndProcCallbacks.push_back(pWndProcCallback); }
	inline static void UnregisterWndProcCallback(WNDPROC pWndProcCallback) { VectorEraseByValueHelper(s_WndProcCallbacks, pWndProcCallback); }

	typedef void(*UpdateCallback)();
	inline static void RegisterUpdateCallback(UpdateCallback pUpdateCallback) { s_UpdateCallbacks.push_back(pUpdateCallback); }
	inline static void UnregisterUpdateCallback(UpdateCallback pUpdateCallback) { VectorEraseByValueHelper(s_UpdateCallbacks, pUpdateCallback); }

	typedef void(*DestroyCallback)();
	inline static void RegisterDestroyCallback(DestroyCallback pDestroyCallback) { s_DestroyCallbacks.push_back(pDestroyCallback); }
	inline static void UnregisterDestroyCallback(DestroyCallback pDestroyCallback) { VectorEraseByValueHelper(s_DestroyCallbacks, pDestroyCallback); }

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void SetPostMessageThreadId(HANDLE hThread);

	static int GetWindowWidth();
	static int GetWindowHeight();
	static void SetWindowTitle(const char* pTitle);
	static void Show();
private:
	static void getWindowSize(SIZE& rSize);

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

