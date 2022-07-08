#pragma once

BCS_DEBUG_API extern volatile unsigned long g_debug_point_value;
#define debug_point (void)(g_debug_point_value++)
#define debug_break __debugbreak()
