#pragma once

namespace blofeld
{
	enum e_versioned_string_list_mode
	{
		_versioned_string_list_mode_new,
		_versioned_string_list_mode_append,
	};

	static constexpr uint32_t k_versioned_string_list_table_size = 1024;

	class c_versioned_string_list
	{
	public:
		c_versioned_string_list();
		c_versioned_string_list(const char** strings_list, size_t strings_list_count);
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
