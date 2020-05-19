#pragma once

extern volatile uint32_t g_debug_point_value;

#define debug_point _InterlockedIncrement(&g_debug_point_value)
