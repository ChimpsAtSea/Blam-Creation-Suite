#include "blofeld-private-pch.h"

namespace blofeld
{
	uint32_t calculate_structure_size(const s_tag_struct& tag_struct, bool* block_failed_validation)
	{
		uint32_t computed_size = 0;

		for(const s_tag_field* current_field = tag_struct.tag_fields; current_field->field_type != _field_terminator; current_field++)
		{
			// data validation
			switch (current_field->field_type)
			{
			case _field_struct:
				if (current_field->tag_struct == nullptr)
				{
					write_line_verbose("blofeld> warning field '%s':'%s' [_field_struct] failed validation. no structure specified.", tag_struct.name, current_field->name);
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
				computed_size += calculate_structure_size(*current_field->tag_struct, block_failed_validation);
				break;
			case _field_array:
				throw;
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
		for (s_tag_block_definition_validation_data& validation_data : halo4_tag_block_validation_data)
		{
			bool block_failed_validation = false;
			const s_tag_block_definition& tag_block = validation_data.tag_block;
			const s_tag_struct& tag_struct = tag_block.tag_struct;
			const char* const block_name = tag_block.name;
			uint32_t const expected_size = validation_data.size;

			uint32_t computed_size = calculate_structure_size(tag_struct, &block_failed_validation);

			block_failed_validation |= computed_size != expected_size;
			if (block_failed_validation)
			{
				write_line_verbose("blofeld> warning block '%s' failed validation. size 0x%x expected 0x%x", block_name, computed_size, expected_size);
			}
			any_block_failed_validation |= block_failed_validation;
		}
		return any_block_failed_validation;
	}

}
