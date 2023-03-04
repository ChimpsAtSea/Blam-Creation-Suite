#include "devicecommunication-private-pch.h"

#include <vector>

static h_registry_key_handle xbox_shell_consoles_key;
static uint32_t num_consoles;
static s_xbox360_device_entry* consoles;

BCS_RESULT read_console_info(uint32_t index, wchar_t* console_value_name_buffer, uint32_t name_buffer_length)
{
	uint32_t value;
	return registry_read_enum_u32(xbox_shell_consoles_key, index + 1, console_value_name_buffer, name_buffer_length, value);
}

BCS_RESULT open_console_key()
{
	return registry_current_user_open_or_create(L"Software\\Microsoft\\XenonSDK\\xbshlext\\Consoles", xbox_shell_consoles_key);
}

BCS_RESULT read_num_consoles()
{
	return registry_read_u32(xbox_shell_consoles_key, num_consoles);
}

BCS_RESULT init_xbox360_device_manager()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = open_console_key()))
	{
		return rs;
	}

	if (BCS_FAILED(rs = read_num_consoles()))
	{
		return rs;
	}

	consoles = new() s_xbox360_device_entry[num_consoles];
	for (uint32_t console_index = 0; console_index < num_consoles; console_index++)
	{
		s_xbox360_device_entry& device_entry = consoles[console_index];

		if (BCS_FAILED(rs = read_console_info(console_index, device_entry.console_value_name_buffer_wc, _countof(device_entry.console_value_name_buffer_wc))))
		{
			return rs;
		}

		BCS_WIDECHAR_TO_CHAR_STACK(device_entry.console_value_name_buffer_wc, console_value_name_buffer_mb);
		strcpy_s(device_entry.console_value_name_buffer_mb, console_value_name_buffer_mb);

		debug_point;
	}

	return rs;
}

BCS_RESULT deinit_xbox360_device_manager()
{
	BCS_RESULT rs = BCS_S_OK;

	delete[] consoles;

	return rs;
}

BCS_RESULT xbox360_device_manager_get_devices(s_xbox360_device_entry const*& out_devices, uint32_t& device_count)
{
	out_devices = consoles;
	device_count = static_cast<unsigned long>(num_consoles);
	return BCS_S_OK;
}
