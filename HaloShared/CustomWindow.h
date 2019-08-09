#pragma once
class CustomWindow
{
public:
	static void	SetupHooks();
	static void Update();
	static HWND GetWindowHandle();

	static int inputDeltaX;
	static int inputDeltaY;

private:

	typedef ATOM(WINAPI* RegisterClassExA_Func)(_In_ CONST WNDCLASSEXA*);
	typedef HWND(WINAPI* CreateWindowExA_Func)(
		_In_ DWORD dwExStyle,
		_In_opt_ LPCSTR lpClassName,
		_In_opt_ LPCSTR lpWindowName,
		_In_ DWORD dwStyle,
		_In_ int X,
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,
		_In_opt_ HMENU hMenu,
		_In_opt_ HINSTANCE hInstance,
		_In_opt_ LPVOID lpParam);

	static CreateWindowExA_Func CreateWindowExA;
	static RegisterClassExA_Func RegisterClassExA;
	static HWND s_hwnd;

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static ATOM WINAPI CustomRegisterClassExA(_In_ WNDCLASSEXA* arg);
	static HWND WINAPI CustomCreateWindowExA(
		_In_ DWORD dwExStyle,
		_In_opt_ LPCSTR lpClassName,
		_In_opt_ LPCSTR lpWindowName,
		_In_ DWORD dwStyle,
		_In_ int X,
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,
		_In_opt_ HMENU hMenu,
		_In_opt_ HINSTANCE hInstance,
		_In_opt_ LPVOID lpParam);

};

