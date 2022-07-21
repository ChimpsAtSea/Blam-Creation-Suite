#pragma once

BCS_DEBUG_API extern volatile uint32_t g_debug_point_value;
#define debug_point (void)(g_debug_point_value++)
#define debug_break __debugbreak()
