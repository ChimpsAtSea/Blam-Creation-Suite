#pragma once

class Window
{
public:

	static HICON GetIcon();
	static void SetIcon(HICON hIcon);
	static HWND GetWindowHandle();
	static bool IsWindowFocused();
	static void SetOnUpdateCallback(void(callback)());
	static void SetOnDestroyCallback(void(callback)());
	static void OnDestroyCallback();
	static void OnUpdateCallback();
	static void Init(const char* pWindowTitle, const char* pConsoleTitle, const char* pApplicationName);
	static void Deinit();
	static void Update();
	static void UpdateNoCallbacks();

	inline static void RegisterWndProcCallback(WNDPROC pWndProcCallback) { m_WndProcCallbacks.push_back(pWndProcCallback); }
	inline static void UnregisterWndProcCallback(WNDPROC pWndProcCallback) { VectorEraseByValueHelper(m_WndProcCallbacks, pWndProcCallback); }
	static std::vector<WNDPROC> m_WndProcCallbacks;

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void SetPostMessageThreadId(HANDLE hThread);

private:

	static HICON		s_hIcon;
	static HWND			s_hWnd;
	static HWND			s_hFocusWnd;
	static HWND			s_hForegroundWnd;
	static HINSTANCE	s_hInstance;
	static HANDLE		s_hPostMessageThread;
	static DWORD		s_hPostMessageThreadId;
	static void(*s_OnDestroyCallback)();
	static void(*s_OnUpdateCallback)();
public:
	static void GetWindowSize(SIZE& rSize);
	static void SetWindowTitle(const char* pTitle);
	static void Show();
};

