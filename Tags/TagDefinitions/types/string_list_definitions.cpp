#include "tagdefinitions-private-pch.h"

namespace blofeld
{

	c_versioned_string_list::c_versioned_string_list() :
		counts(),
		strings()
	{

	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<const char*> init_list) :
		c_versioned_string_list()
	{
		for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
		{
			uint32_t current_string_index = 0;
			for (const char* string : init_list)
			{
				if (current_string_index < k_versioned_string_list_table_size)
				{
					strings[engine_index][current_string_index] = string;
				}
				current_string_index++;
			}

			counts[engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
		}
	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<std::tuple<e_engine_type, e_versioned_string_list_mode, std::initializer_list<const char*>>> init_lists) :
		c_versioned_string_list()
	{
		for (const std::tuple<e_engine_type, e_versioned_string_list_mode, std::initializer_list<const char*>>& engine_and_init_list : init_lists)
		{
			e_engine_type engine_type = std::get<0>(engine_and_init_list);
			e_versioned_string_list_mode string_list_mode = std::get<1>(engine_and_init_list);
			const std::initializer_list<const char*>& init_list = std::get<2>(engine_and_init_list);

			for (uint32_t engine_index = engine_type; engine_index < k_number_of_engine_types; engine_index++)
			{
				uint32_t current_string_index = 0;
				if (string_list_mode == _versioned_string_list_mode_append)
				{
					current_string_index = counts[engine_index];
				}

				for (const char* string : init_list)
				{
					if (current_string_index < k_versioned_string_list_table_size)
					{
						strings[engine_index][current_string_index] = string;
					}
					current_string_index++;
				}

				counts[engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
			}
		}
	}

	c_versioned_string_list::c_versioned_string_list(const char** strings_list, size_t strings_list_count) :
		c_versioned_string_list()
	{
		for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
		{
			uint32_t current_string_index = 0;
			for (const char* string : c_range_loop(strings_list, strings_list_count))
			{
				if (current_string_index < k_versioned_string_list_table_size)
				{
					strings[engine_index][current_string_index] = string;
				}
				current_string_index++;
			}

			counts[engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
		}
	}

}

