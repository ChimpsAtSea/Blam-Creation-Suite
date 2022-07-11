#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	//#TODO: String Entry Filename/Line
	s_string_entry::s_string_entry(const char* string) :
		string(string),
		filename("unknown"),
		line(),
		is_versioning_entry(false)
	{
	}

	s_string_entry::s_string_entry(
		e_version_mode version_mode,
#ifndef __INTELLISENSE__
		const char* filename,
		int line,
#endif
		c_engine_platform_build engine_platform_build,
		unsigned long version_field_skip_count) :
		string(string),
#ifndef __INTELLISENSE__
		filename(filename),
		line(line),
#endif
		is_versioning_entry(true)
	{
		versioning.group = nullptr;
		versioning.custom_version_callback = nullptr;
		versioning.version_field_skip_count = version_field_skip_count;
		versioning.engine_platform_build = engine_platform_build;
		versioning.mode = version_mode;
	}

	s_string_list_definition::s_string_list_definition(const char* name, const char* filename, int line, s_string_entry* string_entries, unsigned long num_string_entries, long start_offset, long end_offset) :
		name(name),
		filename(filename),
		line(line),
		string_entries(string_entries),
		num_string_entries(num_string_entries),
		start_offset(start_offset),
		end_offset(end_offset)
	{

	}

	unsigned long s_string_list_definition::get_count(s_engine_platform_build engine_platform_build) const
	{
		long string_index = 0;
		for (unsigned long entry_index = 0; entry_index < num_string_entries; entry_index++)
		{
			s_string_entry& string_entry = string_entries[entry_index];
			unsigned long skip_count;
			if (string_entry.is_versioning_entry && blofeld::execute_tag_field_versioning(string_entry.versioning, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max, skip_count))
			{
				entry_index += skip_count;
				continue;
			}
			string_index++;
		}

		long string_count_after_offset = __max(start_offset, string_index) - start_offset;
		long string_count = __min(string_count_after_offset, end_offset - start_offset);

		return static_cast<unsigned long>(string_count);
	}

	const char* s_string_list_definition::get_string(const s_engine_platform_build& engine_platform_build, unsigned long index) const
	{
		long requested_index = static_cast<long>(index) + start_offset;
		long string_index = 0;
		for (unsigned long entry_index = 0; entry_index < num_string_entries; entry_index++)
		{
			s_string_entry& string_entry = string_entries[entry_index];
			unsigned long skip_count;
			if (string_entry.is_versioning_entry && blofeld::execute_tag_field_versioning(string_entry.versioning, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max, skip_count))
			{
				entry_index += skip_count;
				continue;
			}
			if (string_index == requested_index)
			{
				return string_entry.string;
			}
			string_index++;
		}
		return nullptr;
	}
}

