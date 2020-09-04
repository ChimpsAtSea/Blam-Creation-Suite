#include "gameframework-private-pch.h"

static std::wstring convert_bit_endian_wide_char_string(const wchar_t* string)
{
	size_t character_length = 0; // includes null character
	while (true)
	{
		if (string[character_length++] == 0)
		{
			break;
		}
	}

	wchar_t* little_endian_buffer = static_cast<wchar_t*>(alloca(sizeof(wchar_t) * character_length));
	for (size_t i = 0; i < character_length; i++)
	{
		little_endian_buffer[i] = bswap(string[i]);
	}

	return std::wstring(little_endian_buffer);
}

c_map_info::c_map_info(const std::filesystem::path& filepath, bool is_level_chunk_little_endian, const s_blamfile_level_chunk& level_chunk)
	: level_chunk(level_chunk)
	, is_level_chunk_little_endian(is_level_chunk_little_endian)
	, filesystem_path(filepath)
{
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> string_converter;

	std::wstring level_name = convert_bit_endian_wide_char_string(level_chunk.level_name[0]);
	if (!level_name.empty())
	{
		friendly_name = string_converter.to_bytes(level_name);
	}
	else
	{
		std::filesystem::path filesystem_name = filepath.filename();
		char level_name_buffer[MAX_PATH + 1] = {};
		snprintf(level_name_buffer, MAX_PATH, "<%S>", filesystem_name.c_str());
		level_name_buffer[MAX_PATH] = 0;

		friendly_name = level_name_buffer;
	}

	std::wstring level_description = convert_bit_endian_wide_char_string(level_chunk.level_description[0]);
	friendly_description = string_converter.to_bytes(level_description);

	static const std::string s = "|n";
	static const std::string t = "\n";
	std::string::size_type n = 0;
	while ((n = friendly_description.find(s, n)) != std::string::npos)
	{
		friendly_description.replace(n, s.size(), t);
		n += t.size();
	}
}

const char* c_map_info::get_friendly_name() const
{
	return friendly_name.c_str();
}

const char* c_map_info::get_friendly_description() const
{
	return friendly_description.c_str();
}

int c_map_info::get_map_id() const
{
	int map_id = bswap_auto_endian(is_level_chunk_little_endian, level_chunk.map_id);
	return map_id;
}
