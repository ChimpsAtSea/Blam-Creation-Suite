#include "mandrilllib-private-pch.h"

c_single_tag_file_layout_reader::c_single_tag_file_layout_reader(c_tag_group_layout_chunk& tag_group_layout_chunk) :
	tag_group_layout_chunk(tag_group_layout_chunk),
	string_data_chunk(),
	array_definitions_chunk(),
	data_definition_name_chunk(),
	block_definitions_chunk(),
	tag_field_types_chunk(),
	fields_chunk(),
	structure_definitions_chunk()
{
	tag_group_layout_chunk.parse_children(this, nullptr);

	string_data_chunk=tag_group_layout_chunk.find_first_chunk<c_string_data_chunk>();
	array_definitions_chunk = tag_group_layout_chunk.find_first_chunk<c_array_definitions_chunk>();
	data_definition_name_chunk = tag_group_layout_chunk.find_first_chunk<c_data_definition_name_chunk>();
	block_definitions_chunk = tag_group_layout_chunk.find_first_chunk<c_block_definitions_chunk>();
	tag_field_types_chunk = tag_group_layout_chunk.find_first_chunk<c_tag_field_types_chunk>();
	fields_chunk = tag_group_layout_chunk.find_first_chunk<c_fields_chunk>();
	structure_definitions_chunk = tag_group_layout_chunk.find_first_chunk<c_structure_definitions_chunk>();

	ASSERT(string_data_chunk != nullptr);
	ASSERT(array_definitions_chunk != nullptr);
	ASSERT(data_definition_name_chunk != nullptr);
	ASSERT(block_definitions_chunk != nullptr);
	ASSERT(tag_field_types_chunk != nullptr);
	ASSERT(fields_chunk != nullptr);
	ASSERT(structure_definitions_chunk != nullptr);
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_index(unsigned long structure_index)
{
	ASSERT(structure_index < structure_definitions_chunk->entry_count);
	return calculate_structure_size_by_entry(structure_definitions_chunk->entries[structure_index]);
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_entry(const s_struct_definition_entry& structure_entry)
{
	unsigned long structure_size = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_field_entry& field_entry = fields_chunk->entries[field_index];
		s_tag_field_type_entry& tag_field_type = tag_field_types_chunk->entries[field_entry.tag_field_type_index];

		const char* type_string = string_data_chunk->chunk_data_begin + tag_field_type.name_string_offset;
		const char* name_string = string_data_chunk->chunk_data_begin + field_entry.name_string_offset;

		blofeld::e_field field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, field_type);
		ASSERT(BCS_SUCCEEDED(rs));

		if (field_type == blofeld::_field_terminator)
		{
			goto end;
		}

		unsigned long field_size = tag_field_type.size;

		//if (tag_field_type.metadata)
		{
			switch (field_type)
			{
			case blofeld::_field_struct:
			{
				unsigned long structure_size = calculate_structure_size_by_index(field_entry.metadata);
				field_size = structure_size;
			}
			break;
			case blofeld::_field_array:
			{
				s_array_entry& array_entry = array_definitions_chunk->entries[field_entry.metadata];
				unsigned long array_structure_size = calculate_structure_size_by_index(array_entry.structure_index);
				unsigned long array_size = array_structure_size * array_entry.count;
				field_size = array_size;
			}
			break;
			case blofeld::_field_pad:
			{
				unsigned long pad_size = field_entry.metadata;
				field_size = pad_size;
			}
			break;
			}
		}


		structure_size += field_size;

		//console_write_line_verbose("0x%08lX 0x%08lX %s %s", field_size, structure_size, type_string, name_string);

		debug_point;
	}
end:;
	return structure_size;
}
