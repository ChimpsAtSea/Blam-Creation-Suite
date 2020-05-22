#pragma once

class c_runtime_util
{
public:
	static HINSTANCE get_current_module();
private:
	static HINSTANCE s_hInstance;
};

