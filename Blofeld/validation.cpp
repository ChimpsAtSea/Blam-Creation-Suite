#include "blofeld-private-pch.h"

namespace blofeld
{
	uint32_t calculate_struct_size(const s_tag_struct& tag_struct, bool* block_failed_validation)
	{
		uint32_t computed_size = 0;


		for(const s_tag_field* current_field = tag_struct.tag_fields; current_field->field_type != _field_terminator; current_field++)
		{
			const char* field_string = field_to_string(current_field->field_type);
			const char* nice_field_string = field_string + 1;

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
					write_line_verbose("%s(%i): warning V5000: '%s' '%s':'%s' failed validation. no string list specified.", current_field->filename, current_field->line, nice_field_string, tag_struct.name, current_field->name);
					if (block_failed_validation) *block_failed_validation |= true;
				}
				break;
			case _field_struct:
				if (current_field->tag_struct == nullptr)
				{
					write_line_verbose("%s(%i): warning V4000: '%s' '%s':'%s' failed validation. array is not implemented!", current_field->filename, current_field->line, nice_field_string, tag_struct.name, current_field->name);
					if (block_failed_validation) *block_failed_validation |= true;
					continue;
				}
				break;
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
				computed_size += calculate_struct_size(*current_field->tag_struct, block_failed_validation);
				break;
			case _field_array:
				write_line_verbose("%s(%i): warning V3000: '%s' '%s':'%s' failed validation. array is not implemented!", current_field->filename, current_field->line, nice_field_string, tag_struct.name, current_field->name);
				break;
			default:
				computed_size += get_blofeld_field_size(current_field->field_type);
				break;
			}
		}

		return computed_size;
	}

	bool validate_halo4()
	{
		bool any_block_failed_validation = false;
		uint32_t successful_validation_attempts = 0;
		for (s_tag_struct_validation_data& validation_data : halo4_tag_struct_validation_data)
		{
			bool block_failed_validation = false;
			const s_tag_struct& tag_struct = validation_data.tag_struct;
			const char* const block_name = tag_struct.name;
			uint32_t const expected_size = validation_data.size;

			uint32_t computed_size = calculate_struct_size(tag_struct, &block_failed_validation);

			block_failed_validation |= computed_size != expected_size;
			if (block_failed_validation)
			{
				write_line_verbose("%s(%i): warning V2000: s_tag_struct '%s' failed validation. computed size 0x%x expected 0x%x", tag_struct.filename, tag_struct.line, block_name, computed_size, expected_size);
			}
			else
			{
				successful_validation_attempts++;
			}
			any_block_failed_validation |= block_failed_validation;
		}
		float percentage = 100.0f * float(successful_validation_attempts) / float(_countof(halo4_tag_struct_validation_data));
		if (percentage != 100.0f)
		{
			write_line_verbose("warning V1000: failed to validate all tags. success rate %.1f.", percentage);
		}
		return any_block_failed_validation;
	}

}
