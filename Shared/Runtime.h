#pragma once
class Runtime
{
public:
	static HINSTANCE GetCurrentModule();
private:
	static HINSTANCE s_hInstance;
};

