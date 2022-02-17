#include "mandrilllib-private-pch.h"

c_single_tag_file_layout_reader::c_single_tag_file_layout_reader(s_single_tag_file_header& header, const void* tag_file_data) :
	root_chunk(),
	tag_group_layout_chunk(),
	aggregate_entries(),
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
	const s_single_tag_file_header* src_header = static_cast<const s_single_tag_file_header*>(tag_file_data);
	root_chunk = new c_tag_header_chunk(next_contiguous_pointer(src_header));

	root_chunk->parse_children(this, nullptr, true);

	tag_group_layout_chunk = root_chunk->find_first_chunk<c_tag_group_layout_chunk>();

	binary_data_chunk = root_chunk->find_first_chunk<c_binary_data_chunk>();

	ASSERT(tag_group_layout_chunk != nullptr);
	ASSERT(binary_data_chunk != nullptr);

	tag_layout_prechunk_chunk = tag_group_layout_chunk->find_first_chunk<c_tag_layout_prechunk_chunk>();

	if (tag_layout_prechunk_chunk != nullptr)
	{
		aggregate_entries = new s_tag_persist_aggregate_fixup[tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count];

		for (unsigned long aggregate_index = 0; aggregate_index < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count; aggregate_index++)
		{
			s_tag_persist_aggregate_prechunk& aggregate = get_aggregate_by_index(aggregate_index);
			s_tag_persist_aggregate_fixup& aggregate_fixup = aggregate_entries[aggregate_index];

			aggregate_fixup.struct_definition.persistent_identifier = aggregate.persistent_identifier;
			aggregate_fixup.struct_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.struct_definition.fields_start_index = aggregate.fields_start_index;

			aggregate_fixup.block_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.block_definition.max_count = aggregate.count;
			aggregate_fixup.block_definition.structure_entry_index = aggregate_index;
		}

		s_tag_persist_aggregate_prechunk& tag_group_aggregate = get_aggregate_by_index(0);

		const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(_engine_type_halo3, header.group_tag);
		//ASSERT(tag_group_aggregate.persistent_identifier == tag_group->block_definition.struct_definition.persistent_identifier);
		if (tag_group_aggregate.persistent_identifier == tag_group->block_definition.struct_definition.persistent_identifier)
		{
			console_write_line("ERROR> Prechunk Definition Tag Group Base Structure Persistent Identifier Not Found! Attempting crazyness!");
		}

		for (unsigned long i = 0; i < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count; i++)
		{
			s_tag_persist_aggregate_prechunk& aggregate = get_aggregate_by_index(i);

			const char* structure_name = get_string_by_string_character_index(aggregate.string_character_index);

			console_write_line("%s", structure_name);

			for (unsigned long field_index = aggregate.fields_start_index;; field_index++)
			{
				s_tag_persist_field& field = get_field_by_index(field_index);
				const char* field_name = get_string_by_string_character_index(field.string_character_index);

				s_tag_persist_field_type& field_type = get_field_type_by_index(field.field_type_index);
				const char* field_type_name = get_string_by_string_character_index(field_type.string_character_index);

				console_write_line("\t%s %s %u", field_type_name, field_name, field.metadata);

				debug_point;

				if (strcmp(field_type_name, "terminator X") == 0)
				{
					break;
				}
			}

			debug_point;
		}

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

c_single_tag_file_layout_reader::~c_single_tag_file_layout_reader()
{
	delete[] aggregate_entries;
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_index(unsigned long structure_index)
{
	s_tag_persist_struct_definition& struct_definition = get_struct_definition_by_index(structure_index);
	return calculate_structure_size_by_entry(struct_definition);
}

unsigned long c_single_tag_file_layout_reader::calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	unsigned long structure_size = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{

		s_tag_persist_field& field_entry = get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_entry.field_type_index);

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
				s_tag_persist_array_definition& array_entry = get_array_definition_by_index(field_entry.metadata);
				//s_tag_persist_array_definition& array_entry = array_definitions_chunk->entries[field_entry.metadata];
				unsigned long array_structure_size = calculate_structure_size_by_index(array_entry.structure_entry_index);
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

const char* c_single_tag_file_layout_reader::get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const
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

const char* c_single_tag_file_layout_reader::get_custom_block_index_search_name_by_index(unsigned long custom_block_index_search_name_index) const
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

const char* c_single_tag_file_layout_reader::get_data_definition_name_by_index(unsigned long data_definition_index) const
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

s_tag_persist_block_definition& c_single_tag_file_layout_reader::get_block_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		ASSERT(index < block_definitions_chunk->entry_count);
		return block_definitions_chunk->entries[index];
	}
	else
	{
		ASSERT(index < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count);
		return aggregate_entries[index].block_definition;
	}
}

s_tag_persist_struct_definition& c_single_tag_file_layout_reader::get_struct_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		ASSERT(index < structure_definitions_chunk->entry_count);
		return structure_definitions_chunk->entries[index];
	}
	else
	{
		ASSERT(index < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count);
		return aggregate_entries[index].struct_definition;
	}
}

s_tag_persist_array_definition& c_single_tag_file_layout_reader::get_array_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		ASSERT(index < array_definitions_chunk->entry_count);
		return array_definitions_chunk->entries[index];
	}
	else
	{
		ASSERT(index < tag_layout_prechunk_chunk->layout_header_prechunk.array_definition_count);
		return tag_layout_prechunk_chunk->array_definitions[index];
	}
}

s_tag_persist_resource_definition& c_single_tag_file_layout_reader::get_resource_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return resource_definitions_chunk->entries[index];
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
	}
}

s_tag_persist_interop_definition& c_single_tag_file_layout_reader::get_interop_definition_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return interop_definitions_chunk->entries[index];
	}
	else
	{
		FATAL_ERROR("Not sure what to do here yet");
	}
}

s_tag_persist_aggregate_prechunk& c_single_tag_file_layout_reader::get_aggregate_by_index(unsigned long index) const
{
	ASSERT(tag_layout_prechunk_chunk != nullptr);
	return tag_layout_prechunk_chunk->aggregate_definitions[index];
}

s_tag_persist_field& c_single_tag_file_layout_reader::get_field_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		return fields_chunk->entries[index];
	}
	else
	{
		return tag_layout_prechunk_chunk->fields[index];
	}
}

s_tag_persist_field_type& c_single_tag_file_layout_reader::get_field_type_by_index(unsigned long index) const
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		ASSERT(index < field_types_chunk->entry_count);
		return field_types_chunk->entries[index];
	}
	else
	{
		ASSERT(index < tag_layout_prechunk_chunk->layout_header_prechunk.field_type_count);
		return tag_layout_prechunk_chunk->field_types[index];
	}
}
