#pragma once

namespace blofeld
{
	enum e_versioned_string_list_mode
	{
		_versioned_string_list_mode_new,
		_versioned_string_list_mode_append,
	};

	static constexpr uint32_t k_versioned_string_list_table_size = 1024;

	struct s_versioned_string_list_value
	{
		const char* string;

		// versioning info, copy pasta
		e_field _field_type;
		e_engine_type _engine_type;
		e_platform_type _platform_type;
		e_build _build;
		uint32_t _version_field_skip_count;

		s_versioned_string_list_value(const char* string) :
			string(string),
			_field_type(_field_string),
			_engine_type(_engine_type_not_set),
			_platform_type(_platform_type_not_set),
			_build(_build_not_set),
			_version_field_skip_count(0)
		{
			
		}

		s_versioned_string_list_value(
			e_field field_type,
			const char* filename,
			int32_t line,
			s_engine_type_and_platform_and_build engine_type_and_build,
			uint32_t version_field_skip_count = 1) :
			string(nullptr),
			_field_type(field_type),
			_engine_type(engine_type_and_build.engine_type),
			_platform_type(engine_type_and_build.platform_type),
			_build(engine_type_and_build.build),
			_version_field_skip_count(version_field_skip_count)
		{
			ASSERT(field_type > _field_type_non_standard);
		}
	};

	class c_versioned_string_list
	{
	public:
		c_versioned_string_list();
		c_versioned_string_list(const char** strings_list, size_t strings_list_count);
		c_versioned_string_list(std::initializer_list<s_versioned_string_list_value> init_list);
		c_versioned_string_list(std::initializer_list<const char*> init_list);
		c_versioned_string_list(std::initializer_list<std::tuple<e_engine_type, e_versioned_string_list_mode, std::initializer_list<const char*>>> init_lists);

		template<size_t count>
		c_versioned_string_list(const char* strings[count]) :
			c_versioned_string_list(strings, count)
		{

		}

		uint32_t counts[k_number_of_engine_types];
		const char* strings[k_number_of_engine_types][k_versioned_string_list_table_size];

		const char* (& get_strings(e_engine_type engine_type))[k_versioned_string_list_table_size]
		{
			  return strings[engine_type];
		}

		uint32_t get_count(e_engine_type engine_type) const
		{
			return counts[engine_type];
		}
	};

	struct s_string_list_definition
	{
		s_string_list_definition(const char* name, c_versioned_string_list& string_list, const char* const filename, int32_t const line) :
			name(name),
			string_list(string_list),
			filename(filename),
			line(line)
		{

		}

		inline uint32_t count(e_engine_type engine_type) const { return string_list.get_count(engine_type); }
		inline const char* (&strings(e_engine_type engine_type) const)[k_versioned_string_list_table_size]{ return string_list.get_strings(engine_type); }

		const char* name;
		//uint32_t count;
		//const char** strings;
		c_versioned_string_list& string_list;
		const char* const filename;
		int32_t const line;
	};
}
