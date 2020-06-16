#pragma once

extern volatile uint32_t g_debug_point_value;

#define debug_point _InterlockedIncrement(&g_debug_point_value)

enum e_debug_log_mode
{
	_debug_log_mode_nothing,
	_debug_log_mode_verbose,
	_debug_log_mode_everything,
};
extern e_debug_log_mode g_debug_log_mode;

void write_stack_back_trace(LPCWSTR calling_function, DWORD depth = 0, DWORD size = 1024);
