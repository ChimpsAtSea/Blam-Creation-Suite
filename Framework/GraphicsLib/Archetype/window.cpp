#include "graphicslib-private-pch.h"

c_window::c_window()
{

}

c_window::~c_window()
{

}

BCS_RESULT window_create(
	const char* window_title,
	const char* window_id,
	e_window_icon window_icon,
	uint32_t width,
	uint32_t height,
	float4 background_color,
	bool allow_adapter_recovery,
	c_window*& window,
	const char* debug_name)
{
#ifdef _WINDOWS_
	return window_windows_create(
		window_title,
		window_id,
		window_icon,
		width,
		height, 
		background_color,
		allow_adapter_recovery,
		*reinterpret_cast<c_window_windows**>(&window),
		debug_name);
	debug_point;
#endif
	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT window_destroy(c_window* window)
{
#ifdef _WINDOWS_
	if (c_window_windows* window_windows = dynamic_cast<c_window_windows*>(window))
	{
		return window_windows_destroy(window_windows);
	}
#endif
	return BCS_E_NOT_IMPLEMENTED;
}