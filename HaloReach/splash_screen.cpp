#include "haloreach-private-pch.h"

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

HINSTANCE			splash_screen::s_hInstance = 0;
HWND                splash_screen::s_hWnd = 0;
MSG                 splash_screen::s_msg = {};
WNDCLASS            splash_screen::s_wndClass = {};
GdiplusStartupInput splash_screen::s_gdiplusStartupInput = {};
ULONG_PTR           splash_screen::s_gdiplusToken = 0;
std::thread			splash_screen::s_windowThread;
std::atomic<bool>	splash_screen::s_isAlive = false;
DWORD				splash_screen::s_threadID = -1;

void splash_screen::LoadBitmapFromPNG(UINT uResourceID, Bitmap** ppBitmapOut, HINSTANCE hInstance /*= NULL*/)
{
	HRSRC hResourceHandle = ::FindResource(hInstance, MAKEINTRESOURCE(uResourceID), "PNG");
	assert(hResourceHandle);

	DWORD nImageSize = ::SizeofResource(hInstance, hResourceHandle);
	assert(hResourceHandle);

	HGLOBAL hResourceInstance = ::LoadResource(hInstance, hResourceHandle);
	assert(hResourceHandle);

	const void* pResourceData = ::LockResource(hResourceInstance);
	assert(pResourceData);
	if (pResourceData == nullptr)
		FreeResource(hResourceInstance);

	HGLOBAL hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, nImageSize);
	assert(hBuffer);
	if (hBuffer == nullptr)
		FreeResource(hResourceInstance);

	void* pBuffer = ::GlobalLock(hBuffer);
	assert(pBuffer);
	if (pBuffer == nullptr)
		FreeResource(hResourceInstance);

	CopyMemory(pBuffer, pResourceData, nImageSize);
	IStream* pStream = 0;
	if (S_OK == ::CreateStreamOnHGlobal(hBuffer, FALSE, &pStream))
	{
		*ppBitmapOut = new Bitmap(pStream);
		pStream->Release();
	}
	::GlobalUnlock(hBuffer);
	::GlobalFree(hBuffer);

	UnlockResource(hResourceInstance);
	FreeResource(hResourceInstance);
}

LRESULT CALLBACK splash_screen::WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		HDC          hdc;
		PAINTSTRUCT  ps;
		hdc = BeginPaint(hWnd, &ps);
		OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_CLOSE:
		s_isAlive = false;
		DestroyWindow(hWnd);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

VOID splash_screen::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);

	Bitmap* pBitmap = nullptr;
	LoadBitmapFromPNG(IDB_PNG1, &pBitmap, s_hInstance);
	
	//Image image(L"splash_screen.png");
	UINT width = pBitmap->GetWidth();
	UINT height = pBitmap->GetHeight();
	Rect destinationRect(0, 0, width, height);
	graphics.DrawImage(pBitmap, destinationRect);

	delete pBitmap;
}

void splash_screen::Create()
{
	s_windowThread = std::thread(WindowThreadProc);
}

void splash_screen::Destroy()
{
	if (s_hWnd)
	{
		SendMessage(s_hWnd, WM_CLOSE, 0, 0);
		s_windowThread.join();
	}
}

bool splash_screen::IsAlive()
{
	return s_hWnd != 0;
}

void splash_screen::WindowThreadProc()
{
	SetProcessDPIAware();

	s_isAlive = true;
	s_threadID = GetThreadId(GetCurrentThread());

	s_hInstance = GetModuleHandle(NULL);

	// Initialize GDI+.
	GdiplusStartup(&s_gdiplusToken, &s_gdiplusStartupInput, NULL);

	s_wndClass.style = CS_HREDRAW | CS_VREDRAW;
	s_wndClass.lpfnWndProc = WndProc;
	s_wndClass.cbClsExtra = 0;
	s_wndClass.cbWndExtra = 0;
	s_wndClass.hInstance = s_hInstance;
	s_wndClass.hIcon = g_icon;
	s_wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	s_wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	s_wndClass.lpszMenuName = NULL;
	s_wndClass.lpszClassName = WindowClassName;

	RegisterClass(&s_wndClass);



	s_hWnd = CreateWindow(
		WindowClassName,			// window class name
		"Halo Reach",				// window caption
		WS_BORDER,		// window style
		CW_USEDEFAULT,				// initial x position
		CW_USEDEFAULT,				// initial y position
		1280,						// initial x size
		720,							// initial y size
		NULL,						// parent window handle
		NULL,						// window menu handle
		s_hInstance,					// program instance handle
		NULL);						// creation parameters
	SetWindowLong(s_hWnd, GWL_STYLE, 0);
	// center window
	{
		RECT windowRect;
		GetWindowRect(s_hWnd, &windowRect);
		int xPos = (GetSystemMetrics(SM_CXSCREEN) - windowRect.right) / 2;
		int yPos = (GetSystemMetrics(SM_CYSCREEN) - windowRect.bottom) / 2;
		SetWindowPos(s_hWnd, 0, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
	}
	ShowWindow(s_hWnd, SW_SHOW);
	UpdateWindow(s_hWnd);

	SetFocus(s_hWnd);

	do
	{
		MSG msg = {};
		while (PeekMessage(&msg, s_hWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	} while (s_isAlive);

	DestroyWindow(s_hWnd);
	UnregisterClass(WindowClassName, s_hInstance);
	GdiplusShutdown(s_gdiplusToken);

	s_hWnd = 0;
}