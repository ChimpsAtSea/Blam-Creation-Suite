#include "tagfileserialization-private-pch.h"

#define make_64bit_persistent_id(persistent_identifier) (reinterpret_cast<const int64_t*>(&persistent_identifier)[0] ^ reinterpret_cast<const int64_t*>(&persistent_identifier)[1])

c_tag_file_reader::c_tag_file_reader(
	const void* _tag_file_data,
	c_monolithic_partition_view* _tag_partition_view,
	c_monolithic_partition_view* _resource_partition_view) :
	header(),
	metadata_stack(),
	tag_partition_view(_tag_partition_view),
	resource_partition_view(_resource_partition_view),
	root_chunk(),
	tag_group_layout_chunk(),
	binary_data_chunk(),
	tag_layout_prechunk_chunk(),
	aggregate_entries(),
	string_data_chunk(),
	custom_block_index_search_names_chunk(),
	array_definitions_chunk(),
	string_lists_chunk(),
	string_offsets_chunk(),
	data_definition_name_chunk(),
	block_definitions_chunk(),
	field_types_chunk(),
	fields_chunk(),
	structure_definitions_chunk(),
	resource_definitions_chunk(),
	interop_definitions_chunk(),
	structure_precomputed_info_by_index(),
	structure_precomputed_info_by_unique_identifier(),
	field_type_to_blofeld_field_type_count(),
	field_type_to_blofeld_field_type(),
	string_by_string_character_index(),
	string_by_string_character_index_size(),
	custom_block_index_search_name_by_index(),
	custom_block_index_search_name_by_index_count(),
	data_definition_by_index(),
	data_definition_by_index_count(),
	block_definition_by_index(),
	block_definition_by_index_count(),
	struct_definition_count(),
	struct_definition_by_index(),
	struct_definition_by_index_count(),
	array_definition_by_index(),
	array_definition_by_index_count(),
	string_list_by_index(),
	string_list_by_index_count(),
	string_offset_by_index(),
	string_offset_by_index_count(),
	resource_definition_by_index(),
	resource_definition_by_index_count(),
	interop_definition_by_index(),
	interop_definition_by_index_count(),
	field_by_index(),
	field_by_index_count(),
	field_type_by_index(),
	field_type_by_index_count()
{
	const s_tag_file_header* tag_file_header = static_cast<const s_tag_file_header*>(_tag_file_data);
	header = *tag_file_header;

	const void* root_chunk_data = next_contiguous_pointer(void, tag_file_header);

	static constexpr tag k_tag_file_root_data_stream_tag = 'tag!';
	tag root_node_tag = *reinterpret_cast<const tag*>(root_chunk_data);
	if (root_node_tag == k_tag_file_root_data_stream_tag)
	{
		is_big_endian = false;
	}
	else if (byteswap(root_node_tag) == k_tag_file_root_data_stream_tag)
	{
		is_big_endian = true;
	}
	else
	{
		throw BCS_E_UNSUPPORTED;
	}



	root_chunk = new() c_tag_header_chunk();
	// #TODO: Combine c_tag_file_reader and c_single_tag_file_reader together
	// then pass the first argument as [this]
	// then convert to a reference
	root_chunk->read_chunk(nullptr, root_chunk_data, true, true);

	tag_group_layout_chunk = root_chunk->get_child_by_type_unsafe<c_tag_group_layout_chunk>();

	binary_data_chunk = root_chunk->get_child_by_type_unsafe<c_binary_data_chunk>();

	ASSERT(tag_group_layout_chunk != nullptr);
	ASSERT(binary_data_chunk != nullptr);

	tag_layout_prechunk_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_tag_layout_prechunk_chunk>();

	if (tag_layout_prechunk_chunk != nullptr)
	{
		aggregate_entries = new() s_tag_persist_aggregate_fixup[tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count];

		for (uint32_t aggregate_index = 0; aggregate_index < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count; aggregate_index++)
		{
			s_tag_persist_aggregate_prechunk& aggregate = get_aggregate_by_index(aggregate_index);
			s_tag_persist_aggregate_fixup& aggregate_fixup = aggregate_entries[aggregate_index];

			aggregate_fixup.struct_definition.unique_identifier = aggregate.unique_identifier;
			aggregate_fixup.struct_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.struct_definition.fields_start_index = aggregate.fields_start_index;

			aggregate_fixup.block_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.block_definition.max_count = aggregate.count;
			aggregate_fixup.block_definition.structure_entry_index = aggregate_index;
		}

		s_tag_persist_aggregate_prechunk& tag_group_aggregate = get_aggregate_by_index(0);

		//blofeld::s_tag_group const* tag_group = blofeld::get_tag_group_by_group_tag({ _engine_type_halo3 }, header.group_tag);
		//if (tag_group_aggregate.unique_identifier != tag_group->block_definition.struct_definition.persistent_identifier)
		//{
		//	console_write_line(
		//		"Failed to find prechunk structure [0x%08X 0x%08X 0x%08X 0x%08X]",
		//		tag_group_aggregate.unique_identifier.identifier_part_0,
		//		tag_group_aggregate.unique_identifier.identifier_part_1,
		//		tag_group_aggregate.unique_identifier.identifier_part_2,
		//		tag_group_aggregate.unique_identifier.identifier_part_3);
		//}

		/*for (uint32_t i = 0; i < tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count; i++)
		{
			s_tag_persist_aggregate_prechunk& aggregate = get_aggregate_by_index(i);

			const char* structure_name = get_string_by_string_character_index(aggregate.string_character_index);

			console_write_line("%s", structure_name);

			for (uint32_t field_index = aggregate.fields_start_index;; field_index++)
			{
				s_tag_persist_field& field = get_field_by_index(field_index);
				const char* field_name = get_string_by_string_character_index(field.string_character_index);

				s_tag_persist_field_type& field_type = get_field_type_by_index(field.field_type_index);
				const char* field_type_name = get_string_by_string_character_index(field_type.string_character_index);

				console_write_line("\t%s %s %u", field_type_name, field_name, field.metadata);



				if (strcmp(field_type_name, "terminator X") == 0)
				{
					break;
				}
			}


		}*/
	}

	if (tag_layout_prechunk_chunk == nullptr)
	{
		string_data_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_string_data_chunk>();
		custom_block_index_search_names_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_custom_block_index_search_names_chunk>();
		array_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_array_definitions_chunk>();
		string_lists_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_string_lists_chunk>();
		string_offsets_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_string_offsets_chunk>();
		data_definition_name_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_data_definition_name_chunk>();
		block_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_block_definitions_chunk>();
		field_types_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_field_types_chunk>();
		fields_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_fields_chunk>();
		structure_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_structure_definitions_chunk>();
		resource_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_resource_definitions_chunk>();
		interop_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_interop_definitions_chunk>();

		ASSERT(string_data_chunk != nullptr);
		ASSERT(array_definitions_chunk != nullptr);
		ASSERT(string_lists_chunk != nullptr);
		ASSERT(string_offsets_chunk != nullptr);
		ASSERT(data_definition_name_chunk != nullptr);
		ASSERT(block_definitions_chunk != nullptr);
		ASSERT(field_types_chunk != nullptr);
		ASSERT(fields_chunk != nullptr);
		ASSERT(structure_definitions_chunk != nullptr);
	}

	init_string_by_string_character_index();
	init_custom_block_index_search_name_by_index();
	init_data_definition_by_index();
	init_block_definition_by_index();
	init_struct_definition_count();
	init_struct_definition_by_index();
	init_array_definition_by_index();
	init_string_list_by_index();
	init_string_offset_by_index();
	init_resource_definition_by_index();
	init_interop_definition_by_index();
	init_field_by_index();
	init_field_type_by_index();

	init_structure_type_to_blofeld_type_lookup();
	calculate_structure_size_and_children();

	root_chunk->log(this);

	uint32_t tag_group_block_index = tag_group_layout_chunk->get_tag_group_block_index();
	t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
	metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_block;
	metadata_entry.id = tag_group_block_index;

	binary_data_chunk->read_child_chunks(this, true);
}

c_tag_file_reader::~c_tag_file_reader()
{
	delete root_chunk;
	delete[] aggregate_entries;
	delete[] structure_precomputed_info_by_index;
	delete[] field_type_to_blofeld_field_type;
}

void c_tag_file_reader::read_structure_metadata(
	s_tag_persist_struct_definition& structure_entry,
	t_tag_file_reader_metadata_stack& metadata_stack)
{
	// #NOTE: If this is required, shove the structure_entry_index into the functiona and lookup via that
	// lookup up via entry/persistent_id is expensive
	// uint32_t expected_children =get_structure_expected_children_by_entry(structure_entry);

	uint32_t metadata_child_index = 0;

	for (uint32_t field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_entry.field_type_index);
		blofeld::e_field blofeld_field_type = get_blofeld_type_by_field_type_index(field_entry.field_type_index);

		if (field_type.has_child_chunk)
		{
			switch (blofeld_field_type)
			{
			case blofeld::_field_struct:
			{
				uint32_t structure_entry_index = field_entry.metadata;
				s_tag_persist_struct_definition& structure_entry = get_struct_definition_by_index(structure_entry_index);
				read_structure_metadata(structure_entry, metadata_stack);
			}
			break;
			case blofeld::_field_pageable_resource:
			{
				uint32_t resource_entry_index = field_entry.metadata;
				s_tag_persist_resource_definition& resource_entry = get_resource_definition_by_index(resource_entry_index);
				DEBUG_ONLY(const char* resource_name = get_string_by_string_character_index(resource_entry.string_character_index));
				DEBUG_ONLY(const char* resource_field_name = get_string_by_string_character_index(field_entry.string_character_index));
				DEBUG_ONLY(const char* resource_type_name = get_string_by_string_character_index(field_type.string_character_index));
				t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
				metadata_entry.id = field_entry.metadata;
				metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_resource;
				DEBUG_ONLY(metadata_entry.resource_definition = &resource_entry);
				DEBUG_ONLY(metadata_entry.block_entry = nullptr);
				DEBUG_ONLY(metadata_entry.definition_name = resource_name);
			}
			break;
			case blofeld::_field_block:
			{
				s_tag_persist_block_definition& block_entry = get_block_definition_by_index(field_entry.metadata);
				DEBUG_ONLY(const char* block_name = get_string_by_string_character_index(block_entry.string_character_index));
				t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
				metadata_entry.id = field_entry.metadata;
				metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_block;
				DEBUG_ONLY(metadata_entry.resource_definition = nullptr);
				DEBUG_ONLY(metadata_entry.block_entry = &block_entry);
				DEBUG_ONLY(metadata_entry.definition_name = block_name);
			}
			break;
			}
		}
		else if (blofeld_field_type == blofeld::_field_terminator)
		{
			return;
		}
	}
}

uint32_t c_tag_file_reader::get_structure_size_by_index(uint32_t structure_index)
{
	return structure_precomputed_info_by_index[structure_index].structure_size;
}

uint32_t c_tag_file_reader::get_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	// #TODO: Investigate
	//int64_t _64bit_id = make_64bit_persistent_id(structure_entry.unique_identifier);
	const s_structure_precomputed_info* structure_precomputed_info;
	// #TODO: Investigate
	//bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
	bool success = structure_precomputed_info_by_unique_identifier.fetch_ref(&structure_entry.unique_identifier, sizeof(structure_entry.unique_identifier), structure_precomputed_info);
	ASSERT(success);
	return structure_precomputed_info->structure_size;
}

uint32_t c_tag_file_reader::get_structure_expected_children_by_index(uint32_t structure_index)
{
	return structure_precomputed_info_by_index[structure_index].expected_children;
}

uint32_t c_tag_file_reader::get_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	// #TODO: Investigate
	//int64_t _64bit_id = make_64bit_persistent_id(structure_entry.unique_identifier);
	const s_structure_precomputed_info* structure_precomputed_info;
	// #TODO: Investigate
	//bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
	bool success = structure_precomputed_info_by_unique_identifier.fetch_ref(&structure_entry.unique_identifier, sizeof(structure_entry.unique_identifier), structure_precomputed_info);
	ASSERT(success);
	return structure_precomputed_info->expected_children;
}

void c_tag_file_reader::calculate_structure_size_and_children()
{
	uint32_t structure_count = get_struct_definition_count();
	structure_precomputed_info_by_index = new() s_structure_precomputed_info[structure_count];

	for (uint32_t structure_index = 0; structure_index < structure_count; structure_index++)
	{
		s_tag_persist_struct_definition& structure_entry = get_struct_definition_by_index(structure_index);

		DEBUG_ONLY(const char* structure_name = get_string_by_string_character_index(structure_entry.string_character_index));

		uint32_t structure_size = _calculate_structure_size_by_index(structure_index);
		uint32_t expected_children = _calculate_structure_expected_children_by_index(structure_index);

		s_structure_precomputed_info& structure_precomputed_info = structure_precomputed_info_by_index[structure_index];
		DEBUG_ONLY(structure_precomputed_info.name = structure_name);
		structure_precomputed_info.structure_size = structure_size;
		structure_precomputed_info.expected_children = expected_children;

		// #TODO: Investigate
		//int64_t _64bit_id = make_64bit_persistent_id(structure_entry.persistent_identifier);
		//structure_precomputed_info_by_persistent_identifier.enqueue(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
		structure_precomputed_info_by_unique_identifier.enqueue(&structure_entry.unique_identifier, sizeof(structure_entry.unique_identifier), structure_precomputed_info);
	}
}

uint32_t c_tag_file_reader::_calculate_structure_size_by_index(uint32_t structure_index) const
{
	s_tag_persist_struct_definition& struct_definition = get_struct_definition_by_index(structure_index);
	return _calculate_structure_size_by_entry(struct_definition);
}

uint32_t c_tag_file_reader::_calculate_structure_expected_children_by_index(uint32_t structure_index) const
{
	s_tag_persist_struct_definition& struct_definition = get_struct_definition_by_index(structure_index);
	return _calculate_structure_expected_children_by_entry(struct_definition);
}

uint32_t c_tag_file_reader::_calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry) const
{
	uint32_t structure_size = 0;
	for (uint32_t field_index = structure_entry.fields_start_index;; field_index++)
	{

		s_tag_persist_field& field_entry = get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_entry.field_type_index);
		DEBUG_ONLY(const char* field_name = get_string_by_string_character_index(field_entry.string_character_index));
		DEBUG_ONLY(const char* field_type_name = get_string_by_string_character_index(field_type.string_character_index));
		uint32_t field_size = field_type.size;
		if (field_size == 0)
		{
			blofeld::e_field blofeld_field_type = get_blofeld_type_by_field_type_index(field_entry.field_type_index);

			if (blofeld_field_type == blofeld::_field_terminator)
			{
				goto end;
			}

			switch (blofeld_field_type)
			{
			case blofeld::_field_struct:
			{
				uint32_t structure_size = _calculate_structure_size_by_index(field_entry.metadata);
				field_size = structure_size;
			}
			break;
			case blofeld::_field_array:
			{
				s_tag_persist_array_definition& array_entry = get_array_definition_by_index(field_entry.metadata);
				//s_tag_persist_array_definition& array_entry = array_definitions_chunk->entries[field_entry.metadata];
				uint32_t array_structure_size = _calculate_structure_size_by_index(array_entry.structure_entry_index);
				uint32_t array_size = array_structure_size * array_entry.count;
				field_size = array_size;
			}
			break;
			case blofeld::_field_skip:
			case blofeld::_field_pad:
			{
				uint32_t pad_size = field_entry.metadata;
				field_size = pad_size;
			}
			break;
			}
		}

		structure_size += field_size;

		//console_write_line_verbose("0x%08lX 0x%08lX %s %s", field_size, structure_size, type_string, name_string);


	}
end:;
	return structure_size;
}

uint32_t c_tag_file_reader::_calculate_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry) const
{
	uint32_t child_entry_count = 0;
	for (uint32_t field_index = structure_entry.fields_start_index;; field_index++)
	{

		s_tag_persist_field& field_entry = get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_entry.field_type_index);

		if (field_type.has_child_chunk)
		{
			child_entry_count++;
		}
		else if (field_type.size == 0)
		{
			blofeld::e_field blofeld_field_type = get_blofeld_type_by_field_type_index(field_entry.field_type_index);
			if (blofeld_field_type == blofeld::_field_terminator)
			{
				goto end;
			}
		}
	}
end:;
	return child_entry_count;
}

void c_tag_file_reader::init_string_by_string_character_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		BCS_RESULT rs = BCS_S_OK;
		rs = string_data_chunk->get_data(*reinterpret_cast<const void**>(&string_by_string_character_index), string_by_string_character_index_size);
		ASSERT(BCS_SUCCEEDED(rs));
	}
	else
	{
		string_by_string_character_index = tag_layout_prechunk_chunk->string_data;
		string_by_string_character_index_size = tag_layout_prechunk_chunk->layout_header_prechunk.string_data_size;
	}
}

const char* c_tag_file_reader::get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const
{
	ASSERT(string_character_index.offset < string_by_string_character_index_size);
	return string_by_string_character_index + string_character_index.offset;
}

const char* c_tag_file_reader::get_string_by_string_offset_index(unsigned int string_offset_index) const
{
	ASSERT(string_offset_index < string_offset_by_index_count);
	s_tag_persist_string_character_index& string_character_index = string_offset_by_index[string_offset_index];
	return get_string_by_string_character_index(string_character_index);
}

void c_tag_file_reader::init_custom_block_index_search_name_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		custom_block_index_search_name_by_index = custom_block_index_search_names_chunk->offsets;
		custom_block_index_search_name_by_index_count = custom_block_index_search_names_chunk->entry_count;
	}
	else
	{
		custom_block_index_search_name_by_index = tag_layout_prechunk_chunk->custom_block_index_search_names;
		custom_block_index_search_name_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.custom_block_index_search_names_count;
	}
}


s_tag_persist_string_character_index& c_tag_file_reader::get_custom_block_index_search_by_index(uint32_t custom_block_index_search_name_index) const
{
	ASSERT(custom_block_index_search_name_index < custom_block_index_search_name_by_index_count);
	return custom_block_index_search_name_by_index[custom_block_index_search_name_index];
}

const char* c_tag_file_reader::get_custom_block_index_search_name_by_index(uint32_t custom_block_index_search_name_index) const
{
	s_tag_persist_string_character_index& custom_block_index_search_name = get_custom_block_index_search_by_index(custom_block_index_search_name_index);
	return get_string_by_string_character_index(custom_block_index_search_name);
}

void  c_tag_file_reader::init_data_definition_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		data_definition_by_index = data_definition_name_chunk->offsets;
		data_definition_by_index_count = data_definition_name_chunk->entry_count;
	}
	else
	{
		data_definition_by_index = tag_layout_prechunk_chunk->data_definition_names;
		data_definition_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.data_definition_name_count;
	}
}

s_tag_persist_string_character_index& c_tag_file_reader::get_data_definition_by_index(uint32_t data_definition_index) const
{
	ASSERT(data_definition_index < data_definition_by_index_count);
	return data_definition_by_index[data_definition_index];
}

const char* c_tag_file_reader::get_data_definition_name_by_index(uint32_t data_definition_index) const
{
	ASSERT(data_definition_index < data_definition_by_index_count);
	return get_string_by_string_character_index(data_definition_by_index[data_definition_index]);
}

void c_tag_file_reader::init_block_definition_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		block_definition_by_index = block_definitions_chunk->entries;
		block_definition_by_index_count = block_definitions_chunk->entry_count;
	}
	else
	{
		block_definition_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count;
		block_definition_by_index = trivial_malloc(s_tag_persist_block_definition, block_definition_by_index_count);

		for (uint32_t block_index = 0; block_index < block_definition_by_index_count; block_index++)
		{
			block_definition_by_index[block_index] = aggregate_entries[block_index].block_definition;
		}
	}
}

s_tag_persist_block_definition& c_tag_file_reader::get_block_definition_by_index(uint32_t index) const
{
	ASSERT(index < block_definition_by_index_count);
	return block_definition_by_index[index];
}

void c_tag_file_reader::init_struct_definition_count()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		struct_definition_count = structure_definitions_chunk->entry_count;
	}
	else
	{
		struct_definition_count = tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count;
	}
}

uint32_t c_tag_file_reader::get_struct_definition_count() const
{
	return struct_definition_count;
}

void c_tag_file_reader::init_struct_definition_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		struct_definition_by_index = structure_definitions_chunk->entries;
		struct_definition_by_index_count = structure_definitions_chunk->entry_count;
	}
	else
	{
		struct_definition_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.aggregate_definition_count;
		struct_definition_by_index = trivial_malloc(s_tag_persist_struct_definition, struct_definition_by_index_count);

		for (uint32_t struct_index = 0; struct_index < block_definition_by_index_count; struct_index++)
		{
			struct_definition_by_index[struct_index] = aggregate_entries[struct_index].struct_definition;
		}
	}
}

s_tag_persist_struct_definition& c_tag_file_reader::get_struct_definition_by_index(uint32_t index) const
{
	ASSERT(index < struct_definition_by_index_count);
	return struct_definition_by_index[index];
}

void c_tag_file_reader::init_array_definition_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		array_definition_by_index = array_definitions_chunk->entries;
		array_definition_by_index_count = array_definitions_chunk->entry_count;
	}
	else
	{
		array_definition_by_index = tag_layout_prechunk_chunk->array_definitions;
		array_definition_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.array_definition_count;
	}
}

void c_tag_file_reader::init_string_list_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		string_list_by_index = string_lists_chunk->entries;
		string_list_by_index_count = string_lists_chunk->entry_count;
	}
	else
	{
		string_list_by_index = tag_layout_prechunk_chunk->string_lists;
		string_list_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.string_list_count;
	}
}

void c_tag_file_reader::init_string_offset_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		string_offset_by_index = string_offsets_chunk->offsets;
		string_offset_by_index_count = string_offsets_chunk->entry_count;
	}
	else
	{
		string_offset_by_index = tag_layout_prechunk_chunk->string_offsets;
		string_offset_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.string_offset_count;
	}
}

s_tag_persist_array_definition& c_tag_file_reader::get_array_definition_by_index(uint32_t index) const
{
	ASSERT(index < array_definition_by_index_count);
	return array_definition_by_index[index];
}

s_tag_persist_string_list& c_tag_file_reader::get_string_list_by_index(uint32_t index) const
{
	ASSERT(index < string_list_by_index_count);
	return string_list_by_index[index];
}

void c_tag_file_reader::init_resource_definition_by_index()
{
	if (tag_group_layout_chunk->layout_header_preinterop != nullptr)
	{
		resource_definition_by_index = resource_definitions_chunk->entries;
		resource_definition_by_index_count = resource_definitions_chunk->entry_count;
	}
}

s_tag_persist_resource_definition& c_tag_file_reader::get_resource_definition_by_index(uint32_t index) const
{
	ASSERT(index < resource_definition_by_index_count);
	return resource_definition_by_index[index];
}

void c_tag_file_reader::init_interop_definition_by_index()
{
	if (tag_group_layout_chunk->layout_header_v3 != nullptr)
	{
		interop_definition_by_index = interop_definitions_chunk->entries;
		interop_definition_by_index_count = interop_definitions_chunk->entry_count;
	}
}

s_tag_persist_interop_definition& c_tag_file_reader::get_interop_definition_by_index(uint32_t index) const
{
	ASSERT(index < interop_definition_by_index_count);
	return interop_definition_by_index[index];
}

s_tag_persist_aggregate_prechunk& c_tag_file_reader::get_aggregate_by_index(uint32_t index) const
{
	ASSERT(tag_layout_prechunk_chunk != nullptr);
	return tag_layout_prechunk_chunk->aggregate_definitions[index];
}

void c_tag_file_reader::init_field_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		field_by_index = fields_chunk->entries;
		field_by_index_count = fields_chunk->entry_count;
	}
	else
	{
		field_by_index = tag_layout_prechunk_chunk->fields;
		field_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.field_count;
	}
}

s_tag_persist_field& c_tag_file_reader::get_field_by_index(uint32_t index) const
{
	ASSERT(index < field_by_index_count);
	return field_by_index[index];
}

void c_tag_file_reader::init_field_type_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		field_type_by_index = field_types_chunk->entries;
		field_type_by_index_count = field_types_chunk->entry_count;
	}
	else
	{
		field_type_by_index = tag_layout_prechunk_chunk->field_types;
		field_type_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.field_type_count;
	}
}

s_tag_persist_field_type& c_tag_file_reader::get_field_type_by_index(uint32_t index) const
{
	ASSERT(index < field_type_by_index_count);
	return field_type_by_index[index];
}

blofeld::e_field c_tag_file_reader::get_blofeld_type_by_field_type_index(uint32_t field_type_index) const
{
	ASSERT(field_type_index < field_type_to_blofeld_field_type_count);
	blofeld::e_field field_type = field_type_to_blofeld_field_type[field_type_index];
	return field_type;
}

void c_tag_file_reader::init_structure_type_to_blofeld_type_lookup()
{
	field_type_to_blofeld_field_type_count = tag_group_layout_chunk->get_field_type_count();
	field_type_to_blofeld_field_type = new() blofeld::e_field[field_type_to_blofeld_field_type_count];
	for (uint32_t field_type_index = 0; field_type_index < field_type_to_blofeld_field_type_count; field_type_index++)
	{
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_type_index);

		const char* type_string = get_string_by_string_character_index(field_type.string_character_index);

		blofeld::e_field blofeld_field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, blofeld_field_type);
		ASSERT(BCS_SUCCEEDED(rs));

		field_type_to_blofeld_field_type[field_type_index] = blofeld_field_type;
	}
}
