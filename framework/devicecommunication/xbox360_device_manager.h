#pragma once

struct s_xbox360_device_entry
{
	char console_value_name_buffer_mb[256];
	wchar_t console_value_name_buffer_wc[256];
};

BCS_SHARED BCS_RESULT init_xbox360_device_manager();
BCS_SHARED BCS_RESULT deinit_xbox360_device_manager();
BCS_SHARED BCS_RESULT xbox360_device_manager_get_devices(s_xbox360_device_entry const*& devices, uint32_t& device_count);
