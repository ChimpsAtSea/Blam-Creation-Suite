#pragma once

namespace blofeld
{
	class c_versioned_string_list
	{
	public:
		c_versioned_string_list(const char** strings_list, size_t strings_list_count);
		c_versioned_string_list(std::initializer_list<const char*> init_list);
		c_versioned_string_list(std::initializer_list<std::pair<e_engine_type, std::initializer_list<const char*>>> init_list);

		template<size_t count>
		c_versioned_string_list(const char* strings[count]) :
			c_versioned_string_list(strings, count)
		{

		}

		uint32_t counts[k_number_of_engine_types];
		const char* strings[k_number_of_engine_types][64];

		const char* (& get_strings(e_engine_type engine_type))[64]
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
		inline const char* (&strings(e_engine_type engine_type) const)[64]{ return string_list.get_strings(engine_type); }

		const char* name;
		//uint32_t count;
		//const char** strings;
		c_versioned_string_list& string_list;
		const char* const filename;
		int32_t const line;
	};
}
