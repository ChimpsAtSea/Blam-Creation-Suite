#pragma once

class CustomWindow
{
public:

	static HICON GetIcon();
	static void SetIcon(HICON hIcon);
	static HWND GetWindowHandle();
	static void SetOnDestroyCallback(void(callback)());
	static void OnDestroyCallback();
	static void Init();
	static void Deinit();
	static void Update();


	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:

	static HICON	s_hIcon;
	static HWND		s_hHWND;
	static HINSTANCE s_hInstance;
	static void(*s_OnDestroyCallback)();
};

