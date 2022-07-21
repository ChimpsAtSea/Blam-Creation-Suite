#pragma once

enum e_settings_section
{
	_settings_section_game,
	_settings_section_camera,
	_settings_section_player,
	_settings_section_player_configuration,
	_settings_section_debug,
	_settings_section_launch,
	_settings_section_mandrill
};

BCS_DEBUG_API bool settings_read_bool(e_settings_section section, const char* name, bool defaultValue = false);
BCS_DEBUG_API int settings_read_integer(e_settings_section section, const char* name, int defaultValue = 0);
BCS_DEBUG_API float settings_read_float(e_settings_section section, const char* name, float defaultValue = 0.0);
BCS_DEBUG_API uint32_t settings_read_string(e_settings_section section, const char* name, char* buffer, uint32_t buffer_size, const char* default_value = nullptr);
BCS_DEBUG_API uint32_t settings_read_wstring(e_settings_section section, const char* name, wchar_t* buffer, uint32_t buffer_size, const wchar_t* default_value = nullptr);

BCS_DEBUG_API bool settings_write_bool(e_settings_section section, const char* name, bool value);
BCS_DEBUG_API bool settings_write_integer(e_settings_section section, const char* name, int value);
BCS_DEBUG_API bool settings_write_float(e_settings_section section, const char* name, float value);
BCS_DEBUG_API bool settings_write_string(e_settings_section section, const char* name, const char* value);
BCS_DEBUG_API bool settings_write_wstring(e_settings_section section, const char* name, const wchar_t* value);

BCS_DEBUG_API const char* settings_get_section_name_string(e_settings_section section);
