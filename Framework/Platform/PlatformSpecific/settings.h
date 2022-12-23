#pragma once

enum e_settings_section
{
	_settings_section_game,
	_settings_section_camera,
	_settings_section_player,
	_settings_section_player_configuration,
	_settings_section_debug,
	_settings_section_launch,
	_settings_section_mandrill,
	_settings_section_tool
};

BCS_SHARED bool settings_read_bool(e_settings_section section, const char* name, bool defaultValue = false);
BCS_SHARED int settings_read_integer(e_settings_section section, const char* name, int defaultValue = 0);
BCS_SHARED float settings_read_float(e_settings_section section, const char* name, float defaultValue = 0.0);
BCS_SHARED uint32_t settings_read_string(e_settings_section section, const char* name, char* buffer, uint32_t buffer_size, const char* default_value = nullptr);
BCS_SHARED uint32_t settings_read_wstring(e_settings_section section, const char* name, wchar_t* buffer, uint32_t buffer_size, const wchar_t* default_value = nullptr);

BCS_SHARED bool settings_write_bool(e_settings_section section, const char* name, bool value);
BCS_SHARED bool settings_write_integer(e_settings_section section, const char* name, int value);
BCS_SHARED bool settings_write_float(e_settings_section section, const char* name, float value);
BCS_SHARED bool settings_write_string(e_settings_section section, const char* name, const char* value);
BCS_SHARED bool settings_write_wstring(e_settings_section section, const char* name, const wchar_t* value);

BCS_SHARED const char* settings_get_section_name_string(e_settings_section section);

#define declare_setting(type, name) \
	protected: \
	static constexpr const char* k_##name = #name; \
	static type name; \
	public: \
	BCS_SHARED static type get_##name##_setting(); \
	BCS_SHARED static void set_##name##_setting(type name);

#define define_setting(parent_type, type, underlying_type, name, _settings_section, _default, settings_read, settings_write) \
type parent_type::name = (type)settings_read(_settings_section, parent_type::k_##name, _default); \
type parent_type::get_##name##_setting() { return name; } \
void parent_type::set_##name##_setting(type _##name) \
{ \
	parent_type::name = _##name; \
	settings_write(_settings_section, parent_type::k_##name, (underlying_type)parent_type::name); \
};

#define declare_bool_setting declare_setting
#define declare_integer_setting declare_setting
#define declare_float_setting declare_setting
//#define declare_string_setting declare_setting
//#define declare_wstring_setting declare_setting

#define define_bool_setting(parent_type, type, name, section, default_value) define_setting(parent_type, type, bool, name, section, default_value, settings_read_bool , settings_write_bool)
#define define_integer_setting(parent_type, type, name, section, default_value) define_setting(parent_type, type, int, name, section, default_value, settings_read_integer , settings_write_integer)
#define define_float_setting(parent_type, type, name, section, default_value) define_setting(parent_type, type, float, name, section, default_value, settings_read_float , settings_write_float)
//#define define_string_setting(parent_type, type, name, section, default_value) define_setting(parent_type, type, float, name, section, default_value, settings_read_string , settings_write_string)
//#define define_wstring_setting(parent_type, type, name, section, default_value) define_setting(parent_type, type, float, name, section, default_value, settings_read_wstring , settings_write_wstring)
