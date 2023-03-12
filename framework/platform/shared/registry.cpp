#include "platform-private-pch.h"

#ifdef BCS_WIN32

struct s_registry_key_handle
{
	HKEY key;
};

BCS_RESULT registry_current_user_open(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	BCS_VALIDATE_ARGUMENT(registry_key);

	HKEY key;
	LSTATUS open_key_status = RegOpenKeyExW(HKEY_CURRENT_USER, registry_key, 0, KEY_WRITE | KEY_READ | KEY_SET_VALUE, &key);
	if (open_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}

	registry_key_handle = trivial_malloc(s_registry_key_handle, 1);
	if (registry_key_handle == nullptr)
	{
		return BCS_E_OUT_OF_MEMORY;
	}

	registry_key_handle->key = key;

	return BCS_S_OK;
}

BCS_RESULT registry_current_user_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	BCS_VALIDATE_ARGUMENT(registry_key);

	HKEY key;
	LSTATUS open_key_status = RegCreateKeyExW(
		HKEY_CURRENT_USER,
		L"Software\\Microsoft\\XenonSDK\\xbshlext\\Consoles",
		0,
		NULL,
		0,
		KEY_WRITE | KEY_READ | KEY_SET_VALUE,
		NULL,
		&key,
		NULL);
	if (open_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}

	registry_key_handle = trivial_malloc(s_registry_key_handle, 1);
	if (registry_key_handle == nullptr)
	{
		return BCS_E_OUT_OF_MEMORY;
	}

	registry_key_handle->key = key;

	return BCS_S_OK;
}

BCS_RESULT registry_current_user_open_or_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	BCS_VALIDATE_ARGUMENT(registry_key);

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = registry_current_user_open(registry_key, registry_key_handle)))
	{
		if (BCS_FAILED(rs = registry_current_user_create(registry_key, registry_key_handle)))
		{
			return rs;
		}
	}

	return rs;
}

BCS_RESULT registry_close(h_registry_key_handle registry_key_handle)
{
	BCS_VALIDATE_ARGUMENT(registry_key_handle);

	if (registry_key_handle != nullptr)
	{
		LSTATUS close_key_result = RegCloseKey(registry_key_handle->key);

		trivial_free(registry_key_handle);

		if (close_key_result != ERROR_SUCCESS)
		{
			return BCS_E_FAIL;
		}
	}

	return BCS_S_OK;
}

BCS_RESULT registry_read_u32(h_registry_key_handle registry_key_handle, uint32_t& value)
{
	BCS_VALIDATE_ARGUMENT(registry_key_handle);

	DWORD default_key_type;
	DWORD default_key_size = sizeof(value);
	LSTATUS query_default_key_status = RegQueryValueExA(
		registry_key_handle->key,
		NULL,
		NULL,
		&default_key_type,
		reinterpret_cast<LPBYTE>(&value),
		&default_key_size);

	if (query_default_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT registry_read_enum_u32(h_registry_key_handle registry_key_handle, uint32_t index, wchar_t* buffer, uint32_t& buffer_length, uint32_t& value)
{
	BCS_VALIDATE_ARGUMENT(registry_key_handle);

	DWORD default_key_type;
	DWORD default_key_size = sizeof(value);
	DWORD _buffer_length = buffer_length;
	LSTATUS query_default_key_status = RegEnumValueW(
		registry_key_handle->key,
		index,
		buffer,
		&_buffer_length,
		0,
		&default_key_type,
		reinterpret_cast<LPBYTE>(&value),
		&default_key_size);

	if (query_default_key_status != ERROR_SUCCESS)
	{
		return BCS_E_FAIL;
	}

	buffer_length = static_cast<uint32_t>(_buffer_length);

	return BCS_S_OK;
}

#else

BCS_RESULT registry_current_user_open(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT registry_current_user_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT registry_current_user_open_or_create(const wchar_t* registry_key, h_registry_key_handle& registry_key_handle)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT registry_close(h_registry_key_handle registry_key_handle)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT registry_read_u32(h_registry_key_handle registry_key_handle, uint32_t& value)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT registry_read_enum_u32(h_registry_key_handle registry_key_handle, uint32_t index, wchar_t* buffer, uint32_t& buffer_length, uint32_t& value)
{
	return BCS_E_UNSUPPORTED;
}

#endif
