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
			e_field_legacy,
#ifndef __INTELLISENSE__
			e_field _field_type,
			const char* _filename,
#endif
			int _line,
			c_engine_platform_build _engine_platform_build,
			unsigned long _version_field_skip_count = 1);

		bool skip_tag_field_version(s_engine_platform_build _engine_platform_build, unsigned long& skip_count) const;

		e_string_entry_type type;
		union
		{
			struct
			{
				const char* string;
			};
			struct
			{
				e_field version_type;
				const char* filename;
				int line;
				c_engine_platform_build engine_platform_build;
				unsigned long version_field_skip_count;
			};
		};
	};

	struct s_string_list_definition
	{
	public:
		s_string_list_definition(const char* name, const char* filename, int line, s_string_entry* string_entries, unsigned long num_string_entries, long start_offset = 0, long end_offset = LONG_MAX);
		unsigned long get_count(s_engine_platform_build engine_platform_build) const;
		const char* get_string(const s_engine_platform_build& engine_platform_build, unsigned long index) const;

		const char* name;
		const char* filename;
		int line;
		s_string_entry* string_entries;
		unsigned long num_string_entries;
		long start_offset;
		long end_offset;
	};

#define empty_string_list nullptr
}
