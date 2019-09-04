#pragma once

class CustomWindow
{
public:

	static HICON GetIcon();
	static void SetIcon(HICON hIcon);
	static HWND GetWindowHandle();
	static bool IsWindowFocused();
	static void SetOnDestroyCallback(void(callback)());
	static void OnDestroyCallback();
	static void Init();
	static void Deinit();
	static void Update();


	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void SetPostMessageThreadId(HANDLE hThread);

private:

	static HICON	s_hIcon;
	static HWND		s_hWnd;
	static HWND		s_hFocusWnd;
	static HWND		s_hForegroundWnd;
	static HINSTANCE s_hInstance;
	static HANDLE s_hPostMessageThread;
	static DWORD s_hPostMessageThreadId;
	static void(*s_OnDestroyCallback)();
public:
	static void GetWindowSize(SIZE& rSize);
	static void SetWindowTitle(const char* pTitle);
	static void Show();
};

