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
		s_string_entry(const char* string);
		s_string_entry(
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
		s_string_list_definition(const char* name, const char* filename, int line, s_string_entry* string_entries, uint32_t num_string_entries, int32_t start_offset = 0, int32_t end_offset = LONG_MAX);
		BCS_DEBUG_API uint32_t get_count(s_engine_platform_build engine_platform_build) const;
		BCS_DEBUG_API const char* get_string(const s_engine_platform_build& engine_platform_build, uint32_t index) const;

		const char* name;
		const char* filename;
		int line;
		s_string_entry* string_entries;
		uint32_t num_string_entries;
		int32_t start_offset;
		int32_t end_offset;
	};

#define empty_string_list nullptr
}
