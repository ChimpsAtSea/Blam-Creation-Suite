#pragma once

namespace blofeld
{

	enum e_string_entry_type
	{
		_string_entry_type_string,
		_string_entry_type_version,
	};

	class s_string_entry
	{
	public:
		BCS_SHARED s_string_entry(const char* string);
		BCS_SHARED s_string_entry(
			e_version_mode version_mode,
#ifndef __INTELLISENSE__
			const char* _filename,
			int _line,
#endif
			c_engine_platform_build _engine_platform_build,
			uint32_t _version_field_skip_count = 1);

		union
		{
			const char* string;
			s_tag_field_versioning versioning;
		};
		const char* filename;
		int line;
		bool is_versioning_entry;
	};

	struct s_string_list_definition
	{
	public:
		BCS_SHARED s_string_list_definition(const char* name, const char* symbol_name, const char* filename, int line, s_string_entry* string_entries, uint32_t num_string_entries, int32_t start_offset = 0, int32_t end_offset = LONG_MAX);
		BCS_SHARED uint32_t get_count(s_engine_platform_build engine_platform_build) const;
		BCS_SHARED const char* get_string(const s_engine_platform_build& engine_platform_build, uint32_t index) const;

		const char* name;
		const char* symbol_name;
		const char* filename;
		int line;
		s_string_entry* string_entries;
		uint32_t num_string_entries;
		int32_t start_offset;
		int32_t end_offset;
	};

#define empty_string_list nullptr
}

#define STRINGS(name) \
blofeld::s_string_entry name##_strings[] = 

#define STRING_LIST(string_list_symbol, strings, count, ...) \
blofeld::s_string_list_definition string_list_symbol = { #string_list_symbol, #string_list_symbol, __FILE__, __LINE__, strings, count, __VA_ARGS__ }
