#include "platform-private-pch.h"

static constexpr char k_settings_path[MAX_PATH] = ".\\Settings.ini";
static constexpr wchar_t k_settings_path_wide[MAX_PATH] = L".\\Settings.ini";

bool settings_read_bool(e_settings_section section, const char* name, bool defaultValue /*= false*/)
{
	const char* section_name = settings_get_section_name_string(section);
	return !!GetPrivateProfileIntA(section_name, name, defaultValue, k_settings_path);
}

int settings_read_integer(e_settings_section section, const char* name, int defaultValue /*= 0*/)
{
	const char* section_name = settings_get_section_name_string(section);
	return GetPrivateProfileIntA(section_name, name, defaultValue, k_settings_path);
}

float settings_read_float(e_settings_section section, const char* name, float defaultValue /*= 0.0*/)
{
	char floatBuffer[32] = {};
	uint32_t length = settings_read_string(section, name, floatBuffer, sizeof(floatBuffer), "");

	if (length)
	{
		float value = static_cast<float>(atof(floatBuffer));
		return value;
	}
	return defaultValue;
}

uint32_t settings_read_string(e_settings_section section, const char* name, char* buffer, uint32_t buffer_size, const char* default_value /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* section_name = settings_get_section_name_string(section);
		memset(buffer, 0, buffer_size);
		GetPrivateProfileStringA(section_name, name, default_value, buffer, buffer_size, k_settings_path);
		return static_cast<unsigned long>(strlen(buffer));
	}
	return 0;
}

uint32_t settings_read_wstring(e_settings_section section, const char* name, wchar_t* buffer, uint32_t buffer_size, const wchar_t* default_value /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* section_name = settings_get_section_name_string(section);
		memset(buffer, 0, buffer_size);

		size_t widecharNameBufferSize = (strlen(name) + 1) * sizeof(wchar_t);
		wchar_t* pWidecharNameBuffer = static_cast<wchar_t*>(alloca(widecharNameBufferSize));
		memset(pWidecharNameBuffer, 0, widecharNameBufferSize);
		_snwprintf(pWidecharNameBuffer, widecharNameBufferSize / sizeof(wchar_t), L"%S", name);

		size_t widecharSectionNameBufferSize = (strlen(section_name) + 1) * sizeof(wchar_t);
		wchar_t* pwidecharSectionNameBuffer = static_cast<wchar_t*>(alloca(widecharSectionNameBufferSize));
		memset(pwidecharSectionNameBuffer, 0, widecharSectionNameBufferSize);
		_snwprintf(pwidecharSectionNameBuffer, widecharSectionNameBufferSize / sizeof(wchar_t), L"%S", section_name);

		GetPrivateProfileStringW(pwidecharSectionNameBuffer, pWidecharNameBuffer, default_value, buffer, buffer_size, k_settings_path_wide);
		return static_cast<unsigned long>(wcslen(buffer));
	}
	return 0;
}

bool settings_write_bool(e_settings_section section, const char* name, bool value)
{
	const char* section_name = settings_get_section_name_string(section);
	return WritePrivateProfileStringA(section_name, name, value ? "1" : "0", k_settings_path);
}

bool settings_write_integer(e_settings_section section, const char* name, int value)
{
	const char* section_name = settings_get_section_name_string(section);
	size_t buffer_length = static_cast<int>(logl(UINT_MAX)) + 2;
	char* buffer = static_cast<char*>(alloca(buffer_length));
	memset(buffer, 0, buffer_length);
	_itoa(value, buffer, 10);
	return WritePrivateProfileStringA(section_name, name, buffer, k_settings_path);
}

bool settings_write_float(e_settings_section section, const char* name, float value)
{
	const char* section_name = settings_get_section_name_string(section);
	size_t buffer_length = value == 0.0f ? 16 : static_cast<int>(logf(abs(value))) + 16;
	char* buffer = static_cast<char*>(alloca(buffer_length));
	memset(buffer, 0, buffer_length);
	snprintf(buffer, buffer_length, "%f", value);
	return WritePrivateProfileStringA(section_name, name, buffer, k_settings_path);
}

bool settings_write_string(e_settings_section section, const char* name, const char* value)
{
	const char* section_name = settings_get_section_name_string(section);
	return WritePrivateProfileStringA(section_name, name, value, k_settings_path);
}

bool settings_write_wstring(e_settings_section section, const char* name, const wchar_t* value)
{
	const char* section_name = settings_get_section_name_string(section);

	BCS_CHAR_TO_WIDECHAR_STACK(section_name, section_name_wc);
	BCS_CHAR_TO_WIDECHAR_STACK(name, name_wc);

	return WritePrivateProfileStringW(section_name_wc, name_wc, value, k_settings_path_wide);
}

const char* settings_get_section_name_string(e_settings_section section)
{
	switch (section)
	{
	case _settings_section_game:
		return "Game";
	case _settings_section_camera:
		return "Camera";
	case _settings_section_player:
		return "Player";
	case _settings_section_player_configuration:
		return "PlayerConfiguration";
	case _settings_section_debug:
		return "Debug";
	case _settings_section_launch:
		return "Launch";
	case _settings_section_mandrill:
		return "Mandrill";
	case _settings_section_tool:
		return "Tool";
	default:
		FATAL_ERROR("unknown <e_settings_section>");
		return nullptr;
	}
}
