#include "devicecommunication-private-pch.h"

#ifdef BCS_WIN32

#include <vector>

static HKEY xbox_shell_consoles_key;
static DWORD num_consoles;
static s_xbox360_device_entry* consoles;

BCS_RESULT read_console_info(uint32_t index, wchar_t* console_value_name_buffer, uint32_t name_buffer_length)
{
	DWORD console_value_type;
	DWORD console_value;
	DWORD console_value_size = sizeof(console_value);
	//wchar_t console_value_name_buffer[256];
	//DWORD console_value_name_buffer_length = _countof(console_value_name_buffer);
	DWORD console_value_name_buffer_length = name_buffer_length;
	LSTATUS enum_key_status = RegEnumValueW(
		xbox_shell_consoles_key,
		index + 1,
		console_value_name_buffer,
		&console_value_name_buffer_length,
		0,
		&console_value_type,
		reinterpret_cast<LPBYTE>(&console_value),
		&console_value_size);

	if (enum_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT open_console_key()
{
	LSTATUS open_key_status = RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\XenonSDK\\xbshlext\\Consoles", 0, KEY_WRITE | KEY_READ | KEY_SET_VALUE, &xbox_shell_consoles_key);
	if (open_key_status != ERROR_SUCCESS)
	{
		open_key_status = RegCreateKeyExA(
			HKEY_CURRENT_USER,
			"Software\\Microsoft\\XenonSDK\\xbshlext\\Consoles",
			0,
			NULL,
			0,
			KEY_WRITE | KEY_READ | KEY_SET_VALUE,
			NULL,
			&xbox_shell_consoles_key,
			NULL);
	}

	if (open_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT read_num_consoles()
{
	DWORD default_key_type;
	DWORD default_key_size = sizeof(num_consoles);
	LSTATUS query_default_key_status = RegQueryValueExA(
		xbox_shell_consoles_key,
		NULL,
		NULL,
		&default_key_type,
		reinterpret_cast<LPBYTE>(&num_consoles),
		&default_key_size);

	if (query_default_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
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

#else
BCS_RESULT init_xbox360_device_manager()
{
	return BCS_S_OK;
}

BCS_RESULT deinit_xbox360_device_manager()
{
	return BCS_S_OK;
}

BCS_RESULT xbox360_device_manager_get_devices(s_xbox360_device_entry const*& devices, uint32_t& device_count)
{
	return BCS_E_UNSUPPORTED;
}

#endif
