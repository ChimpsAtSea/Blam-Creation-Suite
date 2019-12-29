#pragma once

class SplashScreen
{
public:
	static void Create();
	static void Destroy();
	static bool IsAlive();
	static HWND GetWindowHandle();

#ifndef UWP_PLATFORM
private:
	static void WindowThreadProc();
	static constexpr const char WindowClassName[] = "HaloReachSplashScreen";
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static VOID OnPaint(HDC hdc);
	static void LoadBitmapFromPNG(UINT uResourceID, Gdiplus::Bitmap** ppBitmapOut, HINSTANCE hInstance /*= NULL*/);

	static HINSTANCE					s_hInstance;
	static HWND							s_hWnd;
	static MSG							s_msg;
	static WNDCLASS						s_wndClass;
	static Gdiplus::GdiplusStartupInput	s_gdiplusStartupInput;
	static ULONG_PTR					s_gdiplusToken;
	static std::thread					s_windowThread;
	static DWORD						s_threadID;
	static std::atomic<bool>			s_isAlive;
#endif
};

