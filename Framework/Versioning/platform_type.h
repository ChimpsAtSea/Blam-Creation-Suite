#pragma once

enum e_platform_type : uint8_t
{
	_platform_type_not_set = 0,
	_platform_type_xbox = 1 << 1,
	_platform_type_xbox_360 = 1 << 2,
	_platform_type_xbox_one = 1 << 3,
	_platform_type_pc = 1 << 4,
	_platform_type_pc_legacy = 1 << 5,
};

template<typename string_type, bool pretty_string>
inline string_type get_enum_string(e_platform_type platform_type)
{
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_not_set, "Not Set");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox, "Xbox");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox_360, "Xbox 360");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox_one, "Xbox One");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_pc, "PC");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_pc_legacy, "PC (Legacy)");
	return nullptr;
}
