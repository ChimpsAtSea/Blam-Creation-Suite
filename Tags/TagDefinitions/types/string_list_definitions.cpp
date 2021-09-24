#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	s_string_entry::s_string_entry(const char* string) :
		type(_string_entry_type_string),
		string(string)
	{

	}

	s_string_entry::s_string_entry(
		e_field_legacy,
		e_field _field_type,
#ifndef __INTELLISENSE__
		const char* _filename,
		int _line,
#endif
		c_engine_platform_build _engine_platform_build,
		unsigned long _version_field_skip_count) :
		type(_string_entry_type_version),
		string(nullptr)
	{
		version_type = _field_type;
		filename = _filename;
		line = _line;
		engine_platform_build = _engine_platform_build;
		version_field_skip_count = _version_field_skip_count;
	}

	bool s_string_entry::skip_tag_field_version(s_engine_platform_build _engine_platform_build, unsigned long& skip_count) const
	{
		if (type != _string_entry_type_version)
		{
			return false;
		}
		if (version_type > _field_type_non_standard)
		{
			bool skip_versioning_field = false;
			skip_count = version_field_skip_count;

			/*if (field_type == _field_version_custom)
			{
				ASSERT(_custom_version_callback);
				skip_count = _custom_version_callback(engine_platform_build);
				skip_versioning_field = false;
			}
			else */
			if (version_type == _field_version_platform_include)
			{
				if (_engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (_engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
				}
			}
			else if (version_type == _field_version_platform_exclude)
			{
				if (_engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (_engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
				}
			}
			else
			{
				switch (version_type)
				{
				case _field_version_equal:
					skip_versioning_field = _engine_platform_build == engine_platform_build;
					break;
				case _field_version_not_equal:
					skip_versioning_field = _engine_platform_build != engine_platform_build;
					break;
				case _field_version_less:
					skip_versioning_field = _engine_platform_build < engine_platform_build;
					break;
				case _field_version_greater:
					skip_versioning_field = _engine_platform_build > engine_platform_build;
					break;
				case _field_version_less_or_equal:
					skip_versioning_field = _engine_platform_build <= engine_platform_build;
					break;
				case _field_version_greater_or_equal:
					skip_versioning_field = _engine_platform_build >= engine_platform_build;
					break;
				}
			}

			if (skip_versioning_field)
			{
				skip_count = 0;
			}

			return true;
		}
		skip_count = 0;
		return false;
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
			if (string_entry.type == _string_entry_type_version && string_entry.skip_tag_field_version(engine_platform_build, skip_count))
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
			if (string_entry.type == _string_entry_type_version && string_entry.skip_tag_field_version(engine_platform_build, skip_count))
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

