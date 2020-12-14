#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	inline bool skip_string_list_value_version(const s_versioned_string_list_value& tag_field, e_engine_type engine_type, e_platform_type platform_type, e_build build, uint32_t& skip_count)
	{
		if (tag_field.string == nullptr)
		{
			bool skip_versioning_field = false;
			skip_count = tag_field._version_field_skip_count;

			switch (tag_field._field_type)
			{
			case _field_version_platform_include:
				if (tag_field._platform_type != _platform_type_not_set && platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field._platform_type & platform_type) != 0;
				}
				break;
			case _field_version_platform_exclude:
				if (tag_field._platform_type != _platform_type_not_set && platform_type != _platform_type_not_set)
				{
					skip_versioning_field = (tag_field._platform_type & platform_type) == 0;
				}
				break;
			case _field_version_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type == tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build == tag_field._build;
				break;
			case _field_version_not_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type != tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build != tag_field._build;
				break;
			case _field_version_less:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type < tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build < tag_field._build;
				break;
			case _field_version_greater:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type > tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build > tag_field._build;
				break;
			case _field_version_less_or_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type <= tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build <= tag_field._build;
				break;
			case _field_version_greater_or_equal:
				skip_versioning_field = tag_field._engine_type == _engine_type_not_set || engine_type >= tag_field._engine_type;
				skip_versioning_field &= tag_field._build == _build_not_set || build >= tag_field._build;
				break;
			//case _field_version_custom:
			//	ASSERT(tag_field._custom_version_callback);
			//	skip_versioning_field = tag_field._custom_version_callback(engine_type, build, skip_count);
			//	break;
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


	c_versioned_string_list::c_versioned_string_list() :
		counts(),
		strings()
	{

	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<s_versioned_string_list_value> init_list) :
		c_versioned_string_list()
	{
		for (uint32_t platform_index = 0; platform_index < k_number_of_platform_types; platform_index++)
		{
			for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
			{
				uint32_t current_string_index = 0;
				uint32_t skip_count = 0;
				for (const s_versioned_string_list_value& value : init_list)
				{
					if (skip_count > 0)
					{
						skip_count--;
						continue;
					}
					if (value.string == nullptr)
					{
						if (skip_string_list_value_version(value, static_cast<e_engine_type>(engine_index), static_cast<e_platform_type>(platform_index), _build_not_set, skip_count))
						{
							continue;
						}
					}

					if (current_string_index < k_versioned_string_list_table_size)
					{
						strings[platform_index][engine_index][current_string_index] = value.string;
					}
					current_string_index++;
				}

				counts[platform_index][engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
			}
		}
	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<const char*> init_list) :
		c_versioned_string_list()
	{
		for (uint32_t platform_index = 0; platform_index < k_number_of_platform_types; platform_index++)
		{
			for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
			{
				uint32_t current_string_index = 0;
				for (const char* string : init_list)
				{
					if (current_string_index < k_versioned_string_list_table_size)
					{
						strings[platform_index][engine_index][current_string_index] = string;
					}
					current_string_index++;
				}

				counts[platform_index][engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
			}
		}
	}

	c_versioned_string_list::c_versioned_string_list(std::initializer_list<std::tuple<e_engine_type, e_versioned_string_list_mode, std::initializer_list<const char*>>> init_lists) :
		c_versioned_string_list()
	{
		for (uint32_t platform_index = 0; platform_index < k_number_of_platform_types; platform_index++)
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
						current_string_index = counts[platform_index][engine_index];
					}

					for (const char* string : init_list)
					{
						if (current_string_index < k_versioned_string_list_table_size)
						{
							strings[platform_index][engine_index][current_string_index] = string;
						}
						current_string_index++;
					}

					counts[platform_index][engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
				}
			}
		}
	}

	c_versioned_string_list::c_versioned_string_list(const char** strings_list, size_t strings_list_count) :
		c_versioned_string_list()
	{
		for (uint32_t platform_index = 0; platform_index < k_number_of_platform_types; platform_index++)
		{
			for (uint32_t engine_index = 0; engine_index < k_number_of_engine_types; engine_index++)
			{
				uint32_t current_string_index = 0;
				for (const char* string : c_range_loop(strings_list, strings_list_count))
				{
					if (current_string_index < k_versioned_string_list_table_size)
					{
						strings[platform_index][engine_index][current_string_index] = string;
					}
					current_string_index++;
				}

				counts[platform_index][engine_index] = __min(current_string_index, k_versioned_string_list_table_size);
			}
		}
	}

}

