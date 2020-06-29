#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	void iterate_structure_fields(
		e_engine_type engine_type,
		e_platform_type platform_type,
		e_build build,
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata)
	{
		for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			const char* field_string = field_to_string(current_field->field_type);
			const char* nice_field_string = field_string + 1;

			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			if (recursive)
			{
				const s_tag_struct_definition* next_struct_definition = nullptr;
				switch (current_field->field_type)
				{
				case _field_struct:
				{
					next_struct_definition = current_field->struct_definition;
					break;
				}
				case _field_array:
				{
					next_struct_definition = &current_field->array_definition->struct_definition;
					break;
				}
				case _field_block:
					if (recursive_block)
					{
						next_struct_definition = &current_field->block_definition->struct_definition;
						break;
					}
				}

				if (next_struct_definition != nullptr)
				{
					iterate_structure_fields(
						engine_type,
						platform_type,
						build,
						*next_struct_definition,
						recursive,
						recursive_block,
						callback,
						userdata);
				}
			}
		}
	}

	void iterate_structure_fields(
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata)
	{
		callback(struct_definition, userdata);

		for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			const char* field_string = field_to_string(current_field->field_type);
			const char* nice_field_string = field_string + 1;

			if (recursive)
			{
				const s_tag_struct_definition* next_struct_definition = nullptr;
				switch (current_field->field_type)
				{
				case _field_struct:
				{
					next_struct_definition = current_field->struct_definition;
					break;
				}
				case _field_array:
				{
					next_struct_definition = &current_field->array_definition->struct_definition;
					break;
				}
				case _field_block:
					if (recursive_block)
					{
						next_struct_definition = &current_field->block_definition->struct_definition;
						break;
					}
				}

				if (next_struct_definition != nullptr)
				{
					iterate_structure_fields(
						*next_struct_definition,
						recursive,
						recursive_block,
						callback,
						userdata);
				}
			}
		}
	}

	uint32_t calculate_struct_size(
		e_engine_type engine_type, 
		e_platform_type platform_type, 
		e_build build, 
		const s_tag_struct_definition& struct_definition, 
		e_validation_result* block_failed_validation)
	{
		uint32_t computed_size = 0;

		for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
		{
			const char* field_string = field_to_string(current_field->field_type);

			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			if (block_failed_validation)
			{
				// data validation
				switch (current_field->field_type)
				{
				case _field_char_enum:
				case _field_enum:
				case _field_long_enum:
				case _field_long_flags:
				case _field_word_flags:
				case _field_byte_flags:
					if (current_field->string_list_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V1000: '%s' '%s':'%s' failed validation. no string list specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						*block_failed_validation = _validation_result_field_missing_string_list;
					}
					else 
					{
						uint32_t string_count = current_field->string_list_definition->count(engine_type);
						if (string_count == k_versioned_string_list_table_size)
						{
							c_console::write_line_verbose("%s(%i): warning V1001: '%s' '%s':'%s' failed validation. string table reached limit!.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
							*block_failed_validation = _validation_result_string_list_limit_reached;
						}
					}
					break;
				case _field_struct:
					if (current_field->struct_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no struct specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						*block_failed_validation = _validation_result_field_missing_struct_definition;
						continue;
					}
					break;
				case _field_array:
					if (current_field->array_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V3000: '%s' '%s':'%s' failed validation. no array specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						*block_failed_validation = _validation_result_field_missing_array_definition;
						continue;
					}
					break;
				case _field_block:
					if (current_field->block_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V2000: '%s' '%s':'%s' failed validation. no block specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						*block_failed_validation = _validation_result_field_missing_block_definition;
						continue;
					}
					break;
				case _field_tag_reference:
					if (current_field->tag_reference_definition == nullptr)
					{
						c_console::write_line_verbose("%s(%i): warning V4000: '%s' '%s':'%s' failed validation. no tag reference specified.", current_field->filename, current_field->line, field_string, struct_definition.name, current_field->name);
						*block_failed_validation = _validation_result_field_missing_tag_reference;
						continue;
					}
					break;
				}

				//c_field_formatter field_formatter(current_field, current_field->name, nullptr);
				//if (field_formatter.is_pointer && current_field->field_type == _field_long_integer)
				//{
				//	c_console::write_line_verbose("%s(%i): warning V5000: '%s' '%s' failed validation. field type is not pointer.", current_field->filename, current_field->line, field_string, current_field->name);
				//}

			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_useless_pad:
				computed_size += current_field->padding;
				break;
			case _field_skip:
				computed_size += current_field->length;
				break;
			case _field_struct:
				computed_size += calculate_struct_size(engine_type, platform_type, build, *current_field->struct_definition, block_failed_validation);
				break;
			case _field_array:
			{
				const s_tag_array_definition& array_definition = *current_field->array_definition;
				REFERENCE_ASSERT(array_definition);
				const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
				REFERENCE_ASSERT(struct_definition);
				uint32_t struct_size = calculate_struct_size(engine_type, platform_type, build, struct_definition, block_failed_validation);
				uint32_t array_data_size = struct_size * array_definition.count(engine_type);
				computed_size += array_data_size;
				break;
			}
			default:
				computed_size += get_blofeld_field_size(platform_type, current_field->field_type);
				break;
			}
		}

		return computed_size;
	}

	bool validate_gen3_definitions()
	{
		bool any_block_failed_validation = false;
		uint32_t successful_validation_attempts = 0;
		for (s_tag_struct_validation_data& struct_validation_data : gen3_xbox360_tag_struct_validation_data)
		{
			e_validation_result block_failed_validation = _validation_result_ok;
			const s_tag_struct_definition& struct_definition = struct_validation_data.struct_definition;
			const char* const block_name = struct_definition.name;
			uint32_t const expected_size = struct_validation_data.size;

			uint32_t computed_size = calculate_struct_size(_engine_type_gen3_xbox360, _platform_type_xbox_360, _build_not_set, struct_definition, &block_failed_validation);

			if (computed_size != expected_size)
			{
				block_failed_validation = _validation_result_struct_invalid_size;
				c_console::write_line_verbose("%s(%i): warning V0002: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", struct_definition.filename, struct_definition.line, block_name, computed_size, expected_size);
			}

			if (block_failed_validation == _validation_result_ok)
			{
				successful_validation_attempts++;
			}
			else
			{
				any_block_failed_validation = true;
			}
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(_countof(gen3_xbox360_tag_struct_validation_data));
		if (percentage != 100.0f)
		{
			c_console::write_line_verbose("warning V0001: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

}
