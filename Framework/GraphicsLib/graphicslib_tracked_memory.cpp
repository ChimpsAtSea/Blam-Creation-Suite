#include "graphicslib-private-pch.h"

s_tracked_memory_stats graphics_tracked_memory = { "graphicslib" };
s_tracked_memory_stats graphics_d3d11_tracked_memory = { "d3d11", &graphics_tracked_memory };
s_tracked_memory_stats graphics_d3d12_tracked_memory = { "d3d12", &graphics_tracked_memory };
s_tracked_memory_stats graphics_imgui_tracked_memory = { "imgui", &graphics_tracked_memory };
s_tracked_memory_stats graphics_windows_tracked_memory = { "windows", &graphics_tracked_memory };
s_tracked_memory_stats graphics_third_party_tracked_memory = { "third party", &graphics_tracked_memory };
s_tracked_memory_stats& _library_tracked_memory = graphics_tracked_memory;