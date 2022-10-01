#include "mandrilllib-private-pch.h"

#define make_64bit_persistent_id(persistent_identifier) (reinterpret_cast<const int64_t*>(&persistent_identifier)[0] ^ reinterpret_cast<const int64_t*>(&persistent_identifier)[1])

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
	interop_definitions_chunk(),
	structure_precomputed_info_by_index(),
	structure_precomputed_info_by_persistent_identifier(),
	field_type_to_blofeld_field_type_count(),
	field_type_to_blofeld_field_type(),
	string_by_string_character_index(),
	string_by_string_character_index_size(),
	custom_block_index_search_name_by_index(),
	custom_block_index_search_name_by_index_count(),
	data_definition_name_by_index(),
	data_definition_name_by_index_count(),
	block_definition_by_index(),
	block_definition_by_index_count(),
	struct_definition_count(),
	struct_definition_by_index(),
	struct_definition_by_index_count(),
	array_definition_by_index(),
	array_definition_by_index_count(),
	resource_definition_by_index(),
	resource_definition_by_index_count(),
	interop_definition_by_index(),
	interop_definition_by_index_count(),
	field_by_index(),
	field_by_index_count(),
	field_type_by_index(),
	field_type_by_index_count()

{
	const s_single_tag_file_header* src_header = static_cast<const s_single_tag_file_header*>(tag_file_data);
	root_chunk = new() c_tag_header_chunk();
	// #TODO: Combine c_single_tag_file_layout_reader and c_single_tag_file_reader together
	// then pass the first argument as [this]
	// then convert to a reference
	root_chunk->read_chunk(nullptr, next_contiguous_pointer(s_single_tag_file_header, src_header), true, true);

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

			aggregate_fixup.struct_definition.persistent_identifier = aggregate.persistent_identifier;
			aggregate_fixup.struct_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.struct_definition.fields_start_index = aggregate.fields_start_index;

			aggregate_fixup.block_definition.string_character_index = aggregate.string_character_index;
			aggregate_fixup.block_definition.max_count = aggregate.count;
			aggregate_fixup.block_definition.structure_entry_index = aggregate_index;
		}

		s_tag_persist_aggregate_prechunk& tag_group_aggregate = get_aggregate_by_index(0);

		const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag({ _engine_type_halo3 }, header.group_tag);
		//ASSERT(tag_group_aggregate.persistent_identifier == tag_group->block_definition.struct_definition.persistent_identifier);
		if (tag_group_aggregate.persistent_identifier == tag_group->block_definition.struct_definition.persistent_identifier)
		{
			console_write_line("ERROR> Prechunk Definition Tag Group Base Structure Persistent Identifier Not Found! Attempting crazyness!");
		}

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
		data_definition_name_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_data_definition_name_chunk>();
		block_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_block_definitions_chunk>();
		field_types_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_field_types_chunk>();
		fields_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_fields_chunk>();
		structure_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_structure_definitions_chunk>();
		resource_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_resource_definitions_chunk>();
		interop_definitions_chunk = tag_group_layout_chunk->get_child_by_type_unsafe<c_interop_definitions_chunk>();

		ASSERT(string_data_chunk != nullptr);
		ASSERT(array_definitions_chunk != nullptr);
		ASSERT(data_definition_name_chunk != nullptr);
		ASSERT(block_definitions_chunk != nullptr);
		ASSERT(field_types_chunk != nullptr);
		ASSERT(fields_chunk != nullptr);
		ASSERT(structure_definitions_chunk != nullptr);
	}

	init_string_by_string_character_index();
	init_custom_block_index_search_name_by_index();
	init_data_definition_name_by_index();
	init_block_definition_by_index();
	init_struct_definition_count();
	init_struct_definition_by_index();
	init_array_definition_by_index();
	init_resource_definition_by_index();
	init_interop_definition_by_index();
	init_field_by_index();
	init_field_type_by_index();

	init_structure_type_to_blofeld_type_lookup();
	calculate_structure_size_and_children();

	root_chunk->log(this);
}

c_single_tag_file_layout_reader::~c_single_tag_file_layout_reader()
{
	delete root_chunk;
	delete[] aggregate_entries;
	delete[] structure_precomputed_info_by_index;
	delete[] field_type_to_blofeld_field_type;
}

uint32_t c_single_tag_file_layout_reader::get_structure_size_by_index(uint32_t structure_index)
{
	return structure_precomputed_info_by_index[structure_index].structure_size;
}

uint32_t c_single_tag_file_layout_reader::get_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	int64_t _64bit_id = make_64bit_persistent_id(structure_entry.persistent_identifier);
	const s_structure_precomputed_info* structure_precomputed_info;
	// #TODO: Investigate
	//bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
	bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&structure_entry.persistent_identifier, sizeof(structure_entry.persistent_identifier), structure_precomputed_info);
	ASSERT(success);
	return structure_precomputed_info->structure_size;
}

uint32_t c_single_tag_file_layout_reader::get_structure_expected_children_by_index(uint32_t structure_index)
{
	return structure_precomputed_info_by_index[structure_index].expected_children;
}

uint32_t c_single_tag_file_layout_reader::get_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry)
{
	int64_t _64bit_id = make_64bit_persistent_id(structure_entry.persistent_identifier);
	const s_structure_precomputed_info* structure_precomputed_info;
	// #TODO: Investigate
	//bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
	bool success = structure_precomputed_info_by_persistent_identifier.fetch_ref(&structure_entry.persistent_identifier, sizeof(structure_entry.persistent_identifier), structure_precomputed_info);
	ASSERT(success);
	return structure_precomputed_info->expected_children;
}

void c_single_tag_file_layout_reader::calculate_structure_size_and_children()
{
	uint32_t structure_count = get_struct_definition_count();
	structure_precomputed_info_by_index = new() s_structure_precomputed_info[structure_count];

	for (uint32_t structure_index = 0; structure_index < structure_count; structure_index++)
	{
		s_tag_persist_struct_definition& structure_entry = get_struct_definition_by_index(structure_index);

		uint32_t structure_size = _calculate_structure_size_by_index(structure_index);
		uint32_t expected_children = _calculate_structure_expected_children_by_index(structure_index);

		s_structure_precomputed_info& structure_precomputed_info = structure_precomputed_info_by_index[structure_index];
		structure_precomputed_info.structure_size = structure_size;
		structure_precomputed_info.expected_children = expected_children;

		// #TODO: Investigate
		//int64_t _64bit_id = make_64bit_persistent_id(structure_entry.persistent_identifier);
		//structure_precomputed_info_by_persistent_identifier.enqueue(&_64bit_id, sizeof(_64bit_id), structure_precomputed_info);
		structure_precomputed_info_by_persistent_identifier.enqueue(&structure_entry.persistent_identifier, sizeof(structure_entry.persistent_identifier), structure_precomputed_info);
	}
}

uint32_t c_single_tag_file_layout_reader::_calculate_structure_size_by_index(uint32_t structure_index) const
{
	s_tag_persist_struct_definition& struct_definition = get_struct_definition_by_index(structure_index);
	return _calculate_structure_size_by_entry(struct_definition);
}

uint32_t c_single_tag_file_layout_reader::_calculate_structure_expected_children_by_index(uint32_t structure_index) const
{
	s_tag_persist_struct_definition& struct_definition = get_struct_definition_by_index(structure_index);
	return _calculate_structure_expected_children_by_entry(struct_definition);
}

uint32_t c_single_tag_file_layout_reader::_calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry) const
{
	uint32_t structure_size = 0;
	for (uint32_t field_index = structure_entry.fields_start_index;; field_index++)
	{

		s_tag_persist_field& field_entry = get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = get_field_type_by_index(field_entry.field_type_index);

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

uint32_t c_single_tag_file_layout_reader::_calculate_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry) const
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

void c_single_tag_file_layout_reader::init_string_by_string_character_index()
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

const char* c_single_tag_file_layout_reader::get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const
{
	ASSERT(string_character_index.offset < string_by_string_character_index_size);
	return string_by_string_character_index + string_character_index.offset;
}

void c_single_tag_file_layout_reader::init_custom_block_index_search_name_by_index()
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

const char* c_single_tag_file_layout_reader::get_custom_block_index_search_name_by_index(uint32_t custom_block_index_search_name_index) const
{
	ASSERT(custom_block_index_search_name_index < custom_block_index_search_name_by_index_count);
	return get_string_by_string_character_index(custom_block_index_search_name_by_index[custom_block_index_search_name_index]);
}

void  c_single_tag_file_layout_reader::init_data_definition_name_by_index()
{
	if (tag_layout_prechunk_chunk == nullptr)
	{
		data_definition_name_by_index = data_definition_name_chunk->offsets;
		data_definition_name_by_index_count = data_definition_name_chunk->entry_count;
	}
	else
	{
		data_definition_name_by_index = tag_layout_prechunk_chunk->data_definition_names;
		data_definition_name_by_index_count = tag_layout_prechunk_chunk->layout_header_prechunk.data_definition_name_count;
	}
}

const char* c_single_tag_file_layout_reader::get_data_definition_name_by_index(uint32_t data_definition_index) const
{
	ASSERT(data_definition_index < data_definition_name_by_index_count);
	return get_string_by_string_character_index(data_definition_name_by_index[data_definition_index]);
}

void c_single_tag_file_layout_reader::init_block_definition_by_index()
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

s_tag_persist_block_definition& c_single_tag_file_layout_reader::get_block_definition_by_index(uint32_t index) const
{
	ASSERT(index < block_definition_by_index_count);
	return block_definition_by_index[index];
}

void c_single_tag_file_layout_reader::init_struct_definition_count()
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

uint32_t c_single_tag_file_layout_reader::get_struct_definition_count() const
{
	return struct_definition_count;
}

void c_single_tag_file_layout_reader::init_struct_definition_by_index()
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

s_tag_persist_struct_definition& c_single_tag_file_layout_reader::get_struct_definition_by_index(uint32_t index) const
{
	ASSERT(index < struct_definition_by_index_count);
	return struct_definition_by_index[index];
}

void c_single_tag_file_layout_reader::init_array_definition_by_index()
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

s_tag_persist_array_definition& c_single_tag_file_layout_reader::get_array_definition_by_index(uint32_t index) const
{
	ASSERT(index < array_definition_by_index_count);
	return array_definition_by_index[index];
}

void c_single_tag_file_layout_reader::init_resource_definition_by_index()
{
	if (tag_group_layout_chunk->layout_header_preinterop != nullptr)
	{
		resource_definition_by_index = resource_definitions_chunk->entries;
		resource_definition_by_index_count = resource_definitions_chunk->entry_count;
	}
}

s_tag_persist_resource_definition& c_single_tag_file_layout_reader::get_resource_definition_by_index(uint32_t index) const
{
	ASSERT(index < resource_definition_by_index_count);
	return resource_definition_by_index[index];
}

void c_single_tag_file_layout_reader::init_interop_definition_by_index()
{
	if (tag_group_layout_chunk->layout_header_v3 != nullptr)
	{
		interop_definition_by_index = interop_definitions_chunk->entries;
		interop_definition_by_index_count = interop_definitions_chunk->entry_count;
	}
}

s_tag_persist_interop_definition& c_single_tag_file_layout_reader::get_interop_definition_by_index(uint32_t index) const
{
	ASSERT(index < interop_definition_by_index_count);
	return interop_definition_by_index[index];
}

s_tag_persist_aggregate_prechunk& c_single_tag_file_layout_reader::get_aggregate_by_index(uint32_t index) const
{
	ASSERT(tag_layout_prechunk_chunk != nullptr);
	return tag_layout_prechunk_chunk->aggregate_definitions[index];
}

void c_single_tag_file_layout_reader::init_field_by_index()
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

s_tag_persist_field& c_single_tag_file_layout_reader::get_field_by_index(uint32_t index) const
{
	ASSERT(index < field_by_index_count);
	return field_by_index[index];
}

void c_single_tag_file_layout_reader::init_field_type_by_index()
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

s_tag_persist_field_type& c_single_tag_file_layout_reader::get_field_type_by_index(uint32_t index) const
{
	ASSERT(index < field_type_by_index_count);
	return field_type_by_index[index];
}

blofeld::e_field c_single_tag_file_layout_reader::get_blofeld_type_by_field_type_index(uint32_t field_type_index) const
{
	ASSERT(field_type_index < field_type_to_blofeld_field_type_count);
	blofeld::e_field field_type = field_type_to_blofeld_field_type[field_type_index];
	return field_type;
}

void c_single_tag_file_layout_reader::init_structure_type_to_blofeld_type_lookup()
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