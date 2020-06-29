#include "tagdefinitions-private-pch.h"

namespace blofeld
{

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<const char*> init_list) :
		counts()//,
		//strings()
	{
		uint32_t string_count = 0;
		for (const char* string : init_list)
		{
			for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
			{
				//strings[engine_index][string_count] = string;
			}
			string_count++;
		}

		for (uint32_t i = 0; i < k_number_of_engine_types; i++)
		{
			counts[i] = string_count;
		}
	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<std::pair<e_engine_type, std::initializer_list<const char*>>> init_lists) :
		counts(),
		strings()
	{
		for (const std::pair<e_engine_type, std::initializer_list<const char*>>& engine_and_init_list : init_lists)
		{
			e_engine_type engine_type = engine_and_init_list.first;
			const std::initializer_list<const char*>& init_list = engine_and_init_list.second;

			uint32_t string_count = 0;
			for (const char* string : init_list)
			{
				for (uint32_t engine_index = engine_type; engine_index < k_number_of_engine_types; engine_index++)
				{
					strings[engine_index][string_count] = string;
				}
				string_count++;
			}

			for (uint32_t i = engine_type; i < k_number_of_engine_types; i++)
			{
				counts[i] = string_count;
			}
		}
	}

	c_versioned_string_list::c_versioned_string_list(const char** strings_list, size_t strings_list_count)
	{
		uint32_t string_count = 0;
		for(const char* string : c_range_loop(strings_list, strings_list_count))
		{
			for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
			{
				strings[engine_index][string_count] = string;
			}
			string_count++;
		}

		for (uint32_t i = 0; i < k_number_of_engine_types; i++)
		{
			counts[i] = string_count;
		}
	}
}

