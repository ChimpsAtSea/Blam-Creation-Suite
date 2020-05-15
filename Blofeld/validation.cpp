#include "blofeld-private-pch.h"

namespace blofeld
{
	bool validate_halo4()
	{
		bool any_block_failed_validation = false;
		for (s_tag_block_validation_data& validation_data : halo4_tag_block_validation_data)
		{
			const s_tag_block& tag_block = validation_data.tag_block;
			const char* const block_name = tag_block.name;
			uint32_t const expected_size = validation_data.size;

			uint32_t computed_size = 0;

			const s_tag_field* current_field = tag_block.field_set.tag_fields;
			while (current_field->field_type != _field_terminator)
			{
				switch (current_field->field_type)
				{
				case blofeld::_field_pad:
				case blofeld::_field_useless_pad:
					computed_size += current_field->padding;
					break;
				case blofeld::_field_skip:
					computed_size += current_field->length;
					break;
				case blofeld::_field_struct:
					break;
				case blofeld::_field_array:
					throw;
				default:
					computed_size += get_blofeld_field_size(current_field->field_type);
					break;
				}
				current_field++;
			}


			bool block_failed_validation = computed_size != expected_size;
			if (block_failed_validation)
			{
				write_line_verbose("blofeld> warning block '%s' failed validation. size 0x%x expected 0x%x", block_name, computed_size, expected_size);
			}
			any_block_failed_validation |= block_failed_validation;
		}
		return any_block_failed_validation;
	}

}
