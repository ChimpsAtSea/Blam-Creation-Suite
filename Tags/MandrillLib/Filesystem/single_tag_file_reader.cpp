#include "mandrilllib-private-pch.h"

c_single_tag_file_reader::c_single_tag_file_reader(
	s_single_tag_file_header& header,
	s_engine_platform_build engine_platform_build,
	c_single_tag_file_layout_reader& layout_reader,
	c_binary_data_chunk& binary_data_chunk) :
	header(header),
	layout_reader(layout_reader),
	binary_data_chunk(binary_data_chunk),
	metadata_stack(),
	tag_struct_definitions(),
	struct_entries_data(),
	tag_struct_definitions_lookup_table(),
	engine_platform_build(engine_platform_build),
	blofeld_tag_group(),
	blofeld_tag_block_definition(),
	blofeld_tag_group_struct_definition()
{
	metadata_stack.push(layout_reader.tag_group_layout_chunk.tag_group_layout_header->tag_group_block_index);
	debug_point;

	binary_data_chunk.parse_children(this);

	blofeld_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build.engine_type, header.group_tag);
	ASSERT(blofeld_tag_group != nullptr);
	blofeld_tag_block_definition = &blofeld_tag_group->block_definition;
	blofeld_tag_group_struct_definition = &blofeld_tag_block_definition->struct_definition;

	const s_block_definition_entry* root_block_definition_entry = layout_reader.block_definitions_chunk->entries + layout_reader.tag_group_layout_chunk.tag_group_layout_header->tag_group_block_index;
	const char* root_block_definition_name = layout_reader.string_data_chunk->chunk_data_begin + root_block_definition_entry->name_string_offset;
	ASSERT(strcmp(root_block_definition_name, blofeld_tag_block_definition->name) == 0); // sanity check
	const s_struct_definition_entry* root_structure_definition_entry = layout_reader.structure_definitions_chunk->entries + root_block_definition_entry->structure_entry_index;
	ASSERT(root_structure_definition_entry->persistent_identifier == blofeld_tag_group->block_definition.struct_definition.persistent_identifier); // sanity check
	const char* root_struct_definition_name = layout_reader.string_data_chunk->chunk_data_begin + root_structure_definition_entry->name_string_offset;
	ASSERT(strcmp(root_struct_definition_name, blofeld_tag_group_struct_definition->name) == 0); // sanity check

	tag_struct_definitions = blofeld::get_tag_struct_definitions(engine_platform_build);
	ASSERT(tag_struct_definitions != nullptr);

	struct_entries_data = new s_single_tag_file_reader_structure_entry[layout_reader.structure_definitions_chunk->entry_count];

	for (
		const blofeld::s_tag_struct_definition** tag_struct_definition_iter = tag_struct_definitions;
		*tag_struct_definition_iter;
		tag_struct_definition_iter++)
	{
		const blofeld::s_tag_struct_definition& tag_struct_definition = **tag_struct_definition_iter;
		XXH64_hash_t hash = XXH64(&tag_struct_definition.persistent_identifier, sizeof(blofeld::s_tag_persistent_identifier), 0);
		tag_struct_definitions_lookup_table[hash] = &tag_struct_definition;
	}

	debug_point;

	for (unsigned long structure_entry_index = 0; structure_entry_index < layout_reader.structure_definitions_chunk->entry_count; structure_entry_index++)
	{
		s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];
		const s_struct_definition_entry& structure_entry = layout_reader.structure_definitions_chunk->entries[structure_entry_index];

		const char* structure_name = layout_reader.string_data_chunk->chunk_data_begin + structure_entry.name_string_offset;

		const blofeld::s_tag_struct_definition* tag_struct_definition;
		if (BCS_SUCCEEDED(get_tag_struct_definition_by_persistent_identifier(structure_entry.persistent_identifier, tag_struct_definition)))
		{
			reader_structure_entry.tag_struct_definition = tag_struct_definition;
			reader_structure_entry.struct_definition_entry = &structure_entry;
			reader_structure_entry.persistent_identifier = structure_entry.persistent_identifier;
		}
		else
		{
			memset(&reader_structure_entry, 0, sizeof(reader_structure_entry));
		}
		debug_point;
	}

	debug_point;
}

BCS_RESULT c_single_tag_file_reader::get_tag_struct_definition_by_persistent_identifier(
	const blofeld::s_tag_persistent_identifier& persistent_identifier,
	const blofeld::s_tag_struct_definition*& tag_struct_definition) const
{
	XXH64_hash_t hash = XXH64(&persistent_identifier, sizeof(blofeld::s_tag_persistent_identifier), 0);
	t_tag_struct_definition_table::const_iterator search_iterator = tag_struct_definitions_lookup_table.find(hash);
	if (search_iterator == tag_struct_definitions_lookup_table.end())
	{
		return BCS_E_FAIL;
	}
	tag_struct_definition = search_iterator->second;
	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::get_tag_struct_definition_by_index(
	unsigned long index,
	const blofeld::s_tag_struct_definition*& tag_struct_definition) const
{
	if (index >= layout_reader.structure_definitions_chunk->entry_count)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[index];

	tag_struct_definition = reader_structure_entry.tag_struct_definition;

	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::read_tag_struct_to_high_level_object_ref(
	h_object& high_level_object,
	s_struct_definition_entry& structure_entry,
	char* const structure_data_begin,
	c_tag_struct_chunk* structure_chunk)
{
	char* structure_data_position = structure_data_begin;
	unsigned long structure_chunk_child_index = 0;

	unsigned long file_tag_field_index = structure_entry.fields_start_index;
	unsigned long blofeld_tag_field_index = 0;

	const char* struct_entry_name = layout_reader.string_data_chunk->chunk_data_begin + structure_entry.name_string_offset;

	const blofeld::s_tag_struct_definition* blofeld_struct_definition;
	BCS_FAIL_RETURN(get_tag_struct_definition_by_persistent_identifier(structure_entry.persistent_identifier, blofeld_struct_definition));

	ASSERT(strcmp(struct_entry_name, blofeld_struct_definition->name) == 0);

	// #TODO: Figure out versioning support


	while (true)
	{
		const blofeld::s_tag_field& blofeld_field = blofeld_struct_definition->fields[blofeld_tag_field_index];
		const char* blofeld_field_name = blofeld_field.name;

		switch (blofeld_field.field_type) // fields to skip
		{
			//case blofeld::_field_explanation:
			//	blofeld_tag_field_index++;
			//	continue;
		}

		const s_field_entry& field_entry = layout_reader.fields_chunk->entries[file_tag_field_index];
		const char* field_entry_name = layout_reader.string_data_chunk->chunk_data_begin + field_entry.name_string_offset;
		const s_tag_field_type_entry& field_type_entry = layout_reader.tag_field_types_chunk->entries[field_entry.tag_field_type_index];
		const char* field_type_entry_name = layout_reader.string_data_chunk->chunk_data_begin + field_type_entry.name_string_offset;

		console_write_line("%s %s", blofeld_field_name, field_entry_name);

		blofeld::e_field blofeld_field_type;
		ASSERT(BCS_SUCCEEDED(blofeld::tag_field_type_to_field(field_type_entry_name, blofeld_field_type)));

		bool is_valid = true;
		is_valid &= field_entry_name == blofeld_field_name || (*field_entry_name == 0 && blofeld_field_name == nullptr) || (blofeld_field_name && strcmp(field_entry_name, blofeld_field_name) == 0);
		is_valid &= blofeld_field_type == blofeld_field.field_type;
		is_valid |= blofeld_field.field_type == blofeld::_field_explanation && blofeld_field_type == blofeld::_field_custom;
		is_valid |= blofeld_field.field_type == blofeld::_field_terminator && blofeld_field_type == blofeld::_field_terminator;
		if (blofeld_field.field_type == blofeld::_field_terminator || blofeld_field_type == blofeld::_field_terminator)
		{
			break; // #TODO: merge
		}
		if (!is_valid)
		{
			file_tag_field_index++;
			blofeld_tag_field_index++;
			continue;
		}
		ASSERT(is_valid);

		ASSERT(!field_type_entry.metadata || structure_chunk != nullptr);

		unsigned long field_size = field_type_entry.size;
		void* high_level_field_data = high_level_object.get_field_data(blofeld_field);
		ASSERT(field_size == 0 || high_level_field_data != nullptr);

		switch (blofeld_field_type)
		{
		case blofeld::_field_terminator:
			goto end;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = field_entry.metadata;
			ASSERT(pad_size == blofeld_field.padding);
			field_size = pad_size;
		}
		break;
		case blofeld::_field_struct:
		{
			c_chunk* field_chunk = structure_chunk->children[structure_chunk_child_index++];
			c_tag_struct_chunk* field_tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(field_chunk);
			ASSERT(field_tag_struct_chunk != nullptr);

			s_struct_definition_entry& field_struct_entry = layout_reader.structure_definitions_chunk->entries[field_entry.metadata];

			unsigned long structure_size = layout_reader.calculate_structure_size_by_index(field_entry.metadata);
			field_size = structure_size;

			h_object& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);

			read_tag_struct_to_high_level_object_ref(struct_storage, field_struct_entry, structure_data_position, field_tag_struct_chunk);

			debug_point;
		}
		break;
		case blofeld::_field_array:
		{
			s_array_entry& array_entry = layout_reader.array_definitions_chunk->entries[field_entry.metadata];
			unsigned long array_structure_size = layout_reader.calculate_structure_size_by_index(array_entry.structure_index);
			unsigned long array_size = array_structure_size * array_entry.count;
			field_size = array_size;
		}
		break;
		case blofeld::_field_tag_reference:
		{
			c_chunk* field_chunk = structure_chunk->children[structure_chunk_child_index++];
			c_tag_reference_chunk* field_tag_reference_chunk = dynamic_cast<c_tag_reference_chunk*>(field_chunk);
			ASSERT(field_tag_reference_chunk != nullptr);

			h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);

			debug_point;
		}
		break;
		case blofeld::_field_old_string_id:
		case blofeld::_field_string_id:
		{
			c_chunk* field_chunk = structure_chunk->children[structure_chunk_child_index++];
			c_tag_string_id_chunk* field_tag_string_id_chunk = dynamic_cast<c_tag_string_id_chunk*>(field_chunk);
			ASSERT(field_tag_string_id_chunk != nullptr);

			h_string_id& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);

			string_id_storage = field_tag_string_id_chunk->string;

			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			c_chunk* field_chunk = structure_chunk->children[structure_chunk_child_index++];
			c_tag_data_chunk* field_tag_data_chunk = dynamic_cast<c_tag_data_chunk*>(field_chunk);
			ASSERT(field_tag_data_chunk != nullptr);

			h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);

			data_storage.insert(data_storage.begin(), field_tag_data_chunk->chunk_data_begin, field_tag_data_chunk->chunk_data_end);
			
			debug_point;
		}
		break;
		case blofeld::_field_block:
		{
			c_chunk* field_chunk = structure_chunk->children[structure_chunk_child_index++];
			c_tag_block_chunk* field_tag_block_chunk = dynamic_cast<c_tag_block_chunk*>(field_chunk);
			ASSERT(field_tag_block_chunk != nullptr);

			h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);

			for (unsigned long block_index = 0; block_index < field_tag_block_chunk->tag_block_chunk_header.count; block_index++)
			{
				h_object* high_level_object;
				BCS_RESULT rs = read_tag_block_structure_to_high_level_object(*field_tag_block_chunk, block_index, high_level_object);
				ASSERT(BCS_SUCCEEDED(rs));

				block_storage.emplace_back(*high_level_object);
				debug_point;
			}

			debug_point;
		}
		break;
		default:
		{
			memcpy(high_level_field_data, structure_data_position, field_size);
		}
		break;
		}

		structure_data_position += field_size;

		file_tag_field_index++;
		blofeld_tag_field_index++;
	}
end:;

	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::read_tag_block_structure_to_high_level_object(
	c_tag_block_chunk& tag_block_chunk,
	unsigned long tag_block_index,
	h_object*& out_high_level_object)
{
	ASSERT(tag_block_index < tag_block_chunk.tag_block_chunk_header.count);

	const blofeld::s_tag_struct_definition* blofeld_struct_definition;
	BCS_FAIL_RETURN(get_tag_struct_definition_by_persistent_identifier(tag_block_chunk.structure_entry->persistent_identifier, blofeld_struct_definition));

	h_object* high_level_object = h_object::create_high_level_object(*blofeld_struct_definition, engine_platform_build);
	ASSERT(high_level_object != nullptr);

	char* structure_data_begin = tag_block_chunk.get_sturcutre_data_by_index(tag_block_index);
	c_tag_struct_chunk* structure_chunk = tag_block_chunk.get_sturcutre_chunk_by_index(tag_block_index);

	read_tag_struct_to_high_level_object_ref(
		*high_level_object,
		*tag_block_chunk.structure_entry,
		structure_data_begin,
		structure_chunk);

	out_high_level_object = high_level_object;
	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::parse_high_level_object(h_tag*& out_high_level_tag)
{
	c_tag_block_chunk* tag_group_block_chunk = binary_data_chunk.find_first_chunk<c_tag_block_chunk>();
	ASSERT(tag_group_block_chunk != nullptr);
	ASSERT(tag_group_block_chunk->tag_block_chunk_header.count == 1);
	ASSERT(blofeld_tag_group_struct_definition->persistent_identifier == tag_group_block_chunk->structure_entry->persistent_identifier);

	h_object* high_level_object;
	read_tag_block_structure_to_high_level_object(*tag_group_block_chunk, 0, high_level_object);
	h_tag* high_level_tag = dynamic_cast<h_tag*>(high_level_object);
	ASSERT(high_level_tag != nullptr);

	debug_point;

	out_high_level_tag = high_level_tag;
	return BCS_S_OK;
}

c_single_tag_file_reader::~c_single_tag_file_reader()
{
	delete struct_entries_data;
}
