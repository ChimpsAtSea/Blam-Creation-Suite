#include "mandrilllib-private-pch.h"
#include "single_tag_file_layout_reader.h"

c_single_tag_file_layout_reader::c_single_tag_file_layout_reader(s_single_tag_file_header* header) :
	root_chunk(),
	tag_group_layout_chunk(),
	binary_data_chunk(),
	tag_layout_prechunk_chunk(),
	string_data_chunk(),
	custom_block_index_search_names_chunk(),
	array_definitions_chunk(),
	data_definition_name_chunk(),
	block_definitions_chunk(),
	field_types_chunk(),
	fields_chunk(),
	structure_definitions_chunk(),
	resource_definitions_chunk(),
	interop_definitions_chunk()
{
	root_chunk = new c_tag_header_chunk(header + 1);

	root_chunk->parse_children(this, nullptr, true);

	tag_group_layout_chunk = root_chunk->find_first_chunk<c_tag_group_layout_chunk>();

	binary_data_chunk = root_chunk->find_first_chunk<c_binary_data_chunk>();

	ASSERT(tag_group_layout_chunk != nullptr);
	ASSERT(binary_data_chunk != nullptr);

	tag_layout_prechunk_chunk = tag_group_layout_chunk->find_first_chunk<c_tag_layout_prechunk_chunk>();
	
	if (tag_layout_prechunk_chunk != nullptr)
	{
		s_tag_persist_aggregate_prechunk& a0 = tag_layout_prechunk_chunk->aggregate_definitions[0];
		s_tag_persist_aggregate_prechunk& a1 = tag_layout_prechunk_chunk->aggregate_definitions[1];

		const char* s0 = get_string_by_string_character_index(a0.string_character_index);
		const char* s1 = get_string_by_string_character_index(a1.string_character_index);

		const char* f0 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[0].string_character_index);
		const char* f1 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[1].string_character_index);
		const char* f2 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[2].string_character_index);
		const char* f3 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[3].string_character_index);
		const char* f4 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[4].string_character_index);
		const char* f5 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[5].string_character_index);
		const char* f6 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[6].string_character_index);
		const char* f7 = get_string_by_string_character_index(tag_layout_prechunk_chunk->fields[7].string_character_index);

		tag_layout_prechunk_chunk->fields[0].string_character_index;

		debug_point;
	}

	if (tag_layout_prechunk_chunk == nullptr)
	{
		string_data_chunk = tag_group_layout_chunk->find_first_chunk<c_string_data_chunk>();
		custom_block_index_search_names_chunk = tag_group_layout_chunk->find_first_chunk<c_custom_block_index_search_names_chunk>();
		array_definitions_chunk = tag_group_layout_chunk->find_first_chunk<c_array_definitions_chunk>();
		data_definition_name_chunk = tag_group_layout_chunk->find_first_chunk<c_data_definition_name_chunk>();
		block_definitions_chunk = tag_group_layout_chunk->find_first_chunk<c_block_definitions_chunk>();
		field_types_chunk = tag_group_layout_chunk->find_first_chunk<c_field_types_chunk>();
		fields_chunk = tag_group_layout_chunk->find_first_chunk<c_fields_chunk>();
		structure_definitions_chunk = tag_group_layout_chunk->find_first_chunk<c_structure_definitions_chunk>();
		resource_definitions_chunk = tag_group_layout_chunk->find_first_chunk<c_resource_definitions_chunk>();
		interop_definitions_chunk = tag_group_layout_chunk->find_first_chunk<c_interop_definitions_chunk>();

		ASSERT(string_data_chunk != nullptr);
		ASSERT(array_definitions_chunk != nullptr);
		ASSERT(data_definition_name_chunk != nullptr);
		ASSERT(block_definitions_chunk != nullptr);
		ASSERT(field_types_chunk != nullptr);
		ASSERT(fields_chunk != nullptr);
		ASSERT(structure_definitions_chunk != nullptr);
	}
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_index(unsigned long structure_index)
{
	ASSERT(structure_index < structure_definitions_chunk->entry_count);
	return calculate_structure_size_by_entry(structure_definitions_chunk->entries[structure_index]);
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	unsigned long structure_size = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = fields_chunk->entries[field_index];
		s_tag_persist_field_type& field_type = field_types_chunk->entries[field_entry.field_type_index];

		const char* type_string = get_string_by_string_character_index(field_type.string_character_index);
		const char* name_string = get_string_by_string_character_index(field_entry.string_character_index);

		blofeld::e_field blofeld_field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, blofeld_field_type);
		ASSERT(BCS_SUCCEEDED(rs));

		if (blofeld_field_type == blofeld::_field_terminator)
		{
			goto end;
		}

		unsigned long field_size = field_type.size;

		//if (field_type.metadata)
		{
			switch (blofeld_field_type)
			{
			case blofeld::_field_struct:
			{
				unsigned long structure_size = calculate_structure_size_by_index(field_entry.metadata);
				field_size = structure_size;
			}
			break;
			case blofeld::_field_array:
			{
				s_tag_persist_array_definition& array_entry = array_definitions_chunk->entries[field_entry.metadata];
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

char* c_single_tag_file_layout_reader::get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return string_data_chunk->chunk_data_begin + string_character_index.offset;
	}
	else
	{
		return tag_layout_prechunk_chunk->string_data + string_character_index.offset;
	}
}

char* c_single_tag_file_layout_reader::get_custom_block_index_search_name_by_index(unsigned long custom_block_index_search_name_index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return get_string_by_string_character_index(custom_block_index_search_names_chunk->offsets[custom_block_index_search_name_index]);
	}
	else
	{
		return get_string_by_string_character_index(tag_layout_prechunk_chunk->custom_block_index_search_names[custom_block_index_search_name_index]);
	}
}

char* c_single_tag_file_layout_reader::get_data_definition_name_by_index(unsigned long data_definition_index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return get_string_by_string_character_index(data_definition_name_chunk->offsets[data_definition_index]);
	}
	else
	{
		return get_string_by_string_character_index(tag_layout_prechunk_chunk->data_definition_names[data_definition_index]);
	}
}

s_tag_persist_block_definition* c_single_tag_file_layout_reader::get_block_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return block_definitions_chunk->entries + index;
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
		//return tag_layout_prechunk_chunk->aggregate_definitions;
	}
}

s_tag_persist_struct_definition* c_single_tag_file_layout_reader::get_struct_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return structure_definitions_chunk->entries + index;
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
		//return tag_layout_prechunk_chunk->aggregate_definitions;
	}
}

s_tag_persist_array_definition* c_single_tag_file_layout_reader::get_array_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return array_definitions_chunk->entries + index;
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
		//return tag_layout_prechunk_chunk->aggregate_definitions;
	}
}

s_tag_persist_resource_definition* c_single_tag_file_layout_reader::get_resource_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return resource_definitions_chunk->entries + index;
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
		//return tag_layout_prechunk_chunk->aggregate_definitions;
	}
}

s_tag_persist_interop_definition* c_single_tag_file_layout_reader::get_interop_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return interop_definitions_chunk->entries + index;
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
		//return tag_layout_prechunk_chunk->aggregate_definitions;
	}
}

s_tag_persist_field* c_single_tag_file_layout_reader::get_field_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return fields_chunk->entries + index;
	}
	else
	{
		return tag_layout_prechunk_chunk->fields + index;
	}
}

s_tag_persist_field_type* c_single_tag_file_layout_reader::get_field_type_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return field_types_chunk->entries + index;
	}
	else
	{
		return tag_layout_prechunk_chunk->field_types + index;
	}
}

unsigned long c_single_tag_file_layout_reader::get_block_definition_count() const
{
	return 0;
}

unsigned long c_single_tag_file_layout_reader::get_struct_definition_count() const
{
	return 0;
}

unsigned long c_single_tag_file_layout_reader::get_array_definition_count() const
{
	return 0;
}

unsigned long c_single_tag_file_layout_reader::get_resource_definition_count() const
{
	return 0;
}

unsigned long c_single_tag_file_layout_reader::get_interop_definition_count() const
{
	return 0;
}
