#pragma once

enum e_settings_section
{
	_settings_section_game,
	_settings_section_camera,
	_settings_section_player,
	_settings_section_debug,
	_settings_section_launch,
	_settings_section_controls,
	_settings_section_mandrill
};

class c_settings
{
public:
	static constexpr char k_settings_path[MAX_PATH] = ".\\Settings.ini";
	static constexpr wchar_t k_settings_path_wide[MAX_PATH] = L".\\Settings.ini";

	static bool read_boolean(e_settings_section section, const char* pName, bool defaultValue = false);
	static int read_integer(e_settings_section section, const char* pName, int defaultValue = 0);
	static float read_float(e_settings_section section, const char* pName, float defaultValue = 0.0);
	static uint32_t read_string(e_settings_section section, const char* pName, char* buffer, uint32_t buffer_size, const char* pDefaultValue = nullptr);
	static uint32_t read_wstring(e_settings_section section, const char* pName, wchar_t* buffer, uint32_t buffer_size, const wchar_t* pDefaultValue = nullptr);

	static bool write_boolean(e_settings_section section, const char* pName, bool value);
	static bool write_integer(e_settings_section section, const char* pName, int value);
	static bool write_string(e_settings_section section, const char* pName, const char* pValue);

	static const char* get_section_name_string(e_settings_section section);
};

