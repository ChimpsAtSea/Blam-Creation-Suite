#include "mandrilllib-private-pch.h"

static constexpr size_t y = sizeof(s_engine_platform_build);

c_high_level_tag_file_writer::c_high_level_tag_file_writer(s_engine_platform_build engine_platform_build, const char* _filepath, h_tag_instance& tag) :
	tag(tag),
	filepath(_strdup(_filepath)),
	engine_platform_build(engine_platform_build),
	header_chunk(),
	file_handle(),
	tag_group_layout_chunk(),
	tag_layout_chunk(),
	string_data_chunk(),
	string_offsets_chunk(),
	string_lists_chunk(),
	custom_block_index_search_names_chunk(),
	data_definition_name_chunk(),
	array_definitions_chunk(),
	field_types_chunk(),
	fields_chunk(),
	block_definitions_chunk(),
	resource_definitions_chunk(),
	interop_definitions_chunk(),
	structure_definitions_chunk(),
	binary_data_chunk()
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = filesystem_create_directory(_filepath, true)))
	{
		throw rs;
	}

	file_handle = fopen(_filepath, "wb");
	if (file_handle == nullptr)
	{
		throw BCS_E_FILE_NOT_FOUND;
	}

	init_chunks();

	blofeld::s_tag_group const& group_definition = tag.tag_group.blofeld_tag_group;
	uint32_t tag_group_block_index = enqueue_block_definition(group_definition.block_definition);
	serialize_tag_group(tag, *binary_data_chunk);

	tag_file_header.unknown0 = 0;
	tag_file_header.unknown4 = 0;
	tag_file_header.unknown8 = 0;
	tag_file_header.unknownC = 0;
	tag_file_header.unknown10 = 0;
	tag_file_header.unknown14 = 0;
	tag_file_header.unknown18 = 0;
	tag_file_header.unknown1C = 0;
	tag_file_header.unknown20 = 0;
	tag_file_header.unknown24 = 1;
	tag_file_header.unknown28 = 1;
	tag_file_header.unknown2C = ULONG_MAX;
	tag_file_header.group_tag = tag.tag_group.blofeld_tag_group.group_tag;
	tag_file_header.group_version = tag.tag_group.blofeld_tag_group.version;
	tag_file_header.crc32 = 0; // #TODO: Calculate this just before writing the data
	tag_file_header.blam = 'BLAM';

	tag_group_layout_chunk->metadata = 2;
	tag_layout_chunk->metadata = _tag_persist_layout_version_v3;
	binary_data_chunk->metadata = 1; // sounds?

	struct
	{
		s_tag_group_layout_header tag_group_layout_header = {};
		s_tag_persist_layout_header_v3 tag_persist_layout_header = {};
	} tag_group_layout_chunk_data;

	tag_group_layout_chunk_data.tag_group_layout_header.unknown = -1;
	memset(&tag_group_layout_chunk_data.tag_group_layout_header.guid, 0x34, sizeof(tag_group_layout_chunk_data.tag_group_layout_header.guid));
	tag_group_layout_chunk_data.tag_group_layout_header.layout_version = _tag_persist_layout_version_v3;

	tag_group_layout_chunk_data.tag_persist_layout_header.tag_group_block_index = tag_group_block_index;
	tag_group_layout_chunk_data.tag_persist_layout_header.string_data_size = string_data_chunk->chunk_size;
	tag_group_layout_chunk_data.tag_persist_layout_header.string_offset_count = string_offsets_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.string_list_count = string_lists_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.custom_block_index_search_names_count = custom_block_index_search_names_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.data_definition_name_count = data_definition_name_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.array_definition_count = array_definitions_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.field_type_count = field_types_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.field_count = fields_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.struct_definition_count = structure_definitions_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.block_definition_count = block_definitions_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.resource_definition_count = resource_definitions_chunk->entry_count;
	tag_group_layout_chunk_data.tag_persist_layout_header.interop_definition_count = interop_definitions_chunk->entry_count;

	tag_group_layout_chunk->set_data(&tag_group_layout_chunk_data, sizeof(tag_group_layout_chunk_data));

	write_file();

	fclose(file_handle);

	header_chunk->log(this);


}

c_high_level_tag_file_writer::~c_high_level_tag_file_writer()
{
	delete tag_group_layout_chunk;
	//untracked_free(filepath);
	//filepath = nullptr;
	debug_point;
}

const char* c_high_level_tag_file_writer::get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const
{
	return static_cast<const char*>(string_data_chunk->chunk_data) + string_character_index.offset;
}

void c_high_level_tag_file_writer::init_chunks()
{
	header_chunk = new() c_tag_header_chunk();
	{
		tag_group_layout_chunk = new() c_tag_group_layout_chunk(*header_chunk);
		header_chunk->add_child(*tag_group_layout_chunk);
		{
			tag_layout_chunk = new() c_tag_layout_v3_chunk(*tag_group_layout_chunk);
			tag_group_layout_chunk->add_child(*tag_layout_chunk);
			{
				string_data_chunk = new() c_string_data_chunk(*tag_layout_chunk);
				string_offsets_chunk = new() c_string_offsets_chunk(*tag_layout_chunk);
				string_lists_chunk = new() c_string_lists_chunk(*tag_layout_chunk);
				custom_block_index_search_names_chunk = new() c_custom_block_index_search_names_chunk(*tag_layout_chunk);
				data_definition_name_chunk = new() c_data_definition_name_chunk(*tag_layout_chunk);
				array_definitions_chunk = new() c_array_definitions_chunk(*tag_layout_chunk);
				field_types_chunk = new() c_field_types_chunk(*tag_layout_chunk);
				fields_chunk = new() c_fields_chunk(*tag_layout_chunk);
				block_definitions_chunk = new() c_block_definitions_chunk(*tag_layout_chunk);
				resource_definitions_chunk = new() c_resource_definitions_chunk(*tag_layout_chunk);
				interop_definitions_chunk = new() c_interop_definitions_chunk(*tag_layout_chunk);
				structure_definitions_chunk = new() c_structure_definitions_chunk(*tag_layout_chunk);

				tag_layout_chunk->add_child(*string_data_chunk);
				tag_layout_chunk->add_child(*string_offsets_chunk);
				tag_layout_chunk->add_child(*string_lists_chunk);
				tag_layout_chunk->add_child(*custom_block_index_search_names_chunk);
				tag_layout_chunk->add_child(*data_definition_name_chunk);
				tag_layout_chunk->add_child(*array_definitions_chunk);
				tag_layout_chunk->add_child(*field_types_chunk);
				tag_layout_chunk->add_child(*fields_chunk);
				tag_layout_chunk->add_child(*block_definitions_chunk);
				tag_layout_chunk->add_child(*resource_definitions_chunk);
				tag_layout_chunk->add_child(*interop_definitions_chunk);
				tag_layout_chunk->add_child(*structure_definitions_chunk);
			}
		}

		binary_data_chunk = new() c_binary_data_chunk(*header_chunk);
		header_chunk->add_child(*binary_data_chunk);
	}
}

void c_high_level_tag_file_writer::write_file()
{
	fwrite(&tag_file_header, sizeof(tag_file_header), 1, file_handle);

	write_chunk(*header_chunk);
}

void c_high_level_tag_file_writer::write_chunk(c_chunk& chunk)
{
	uint32_t chunk_file_data_size = chunk.chunk_size;

	fwrite(&chunk.signature, sizeof(chunk.signature), 1, file_handle);
	fwrite(&chunk.metadata, sizeof(chunk.metadata), 1, file_handle);
	int32_t chunk_size_pos = ftell(file_handle);
	fwrite(&chunk_file_data_size, sizeof(chunk_file_data_size), 1, file_handle);

	write_chunk_data(chunk);
	write_child_chunks(chunk);

	int32_t current_pos = ftell(file_handle);
	chunk_file_data_size = current_pos - chunk_size_pos - 4;

	fseek(file_handle, chunk_size_pos, SEEK_SET);
	fwrite(&chunk_file_data_size, sizeof(chunk_file_data_size), 1, file_handle);
	fseek(file_handle, current_pos, SEEK_SET);
	fflush(file_handle);
}

void c_high_level_tag_file_writer::write_chunk_data(c_chunk& chunk)
{
	if (chunk.is_data_valid)
	{
		fwrite(chunk.chunk_data, chunk.chunk_size, 1, file_handle);
	}
}

void c_high_level_tag_file_writer::write_child_chunks(c_chunk& chunk)
{
	uint32_t num_children;
	c_chunk* const* children;
	chunk.get_children(children, num_children);
	for (uint32_t child_index = 0; child_index < num_children; child_index++)
	{
		c_chunk& child_chunk = *children[child_index];
		write_chunk(child_chunk);
	}
}

uint32_t c_high_level_tag_file_writer::enqueue_block_definition(blofeld::s_tag_block_definition const& tag_block_definition)
{
	{
		uint32_t block_definition_count = block_definitions_chunk->entry_count;
		s_tag_persist_block_definition* block_definitions = block_definitions_chunk->entries;
		for (uint32_t block_definition_index = 0; block_definition_index < block_definition_count; block_definition_index++)
		{
			s_tag_persist_block_definition& existing_block_definition = block_definitions[block_definition_index];

			const char* block_definition_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_block_definition.string_character_index.offset;

			if (strcmp(block_definition_name, tag_block_definition.name) == 0)
			{
				return block_definition_index;
			}
		}
	}

	s_tag_persist_block_definition tag_persist_block_definition;
	tag_persist_block_definition.structure_entry_index = enqueue_struct_definition(tag_block_definition.struct_definition);
	tag_persist_block_definition.string_character_index.offset = enqueue_string(tag_block_definition.name);
	tag_persist_block_definition.max_count = tag_block_definition.max_count(engine_platform_build);

	uint32_t block_index = block_definitions_chunk->entry_count;
	block_definitions_chunk->append_data(&tag_persist_block_definition, sizeof(tag_persist_block_definition));

	return block_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_struct_definition(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	{
		uint32_t tag_persist_struct_count = structure_definitions_chunk->entry_count;
		s_tag_persist_struct_definition* tag_persist_struct_definitions = structure_definitions_chunk->entries;
		for (uint32_t tag_persist_struct_index = 0; tag_persist_struct_index < tag_persist_struct_count; tag_persist_struct_index++)
		{
			s_tag_persist_struct_definition& existing_tag_persist_struct_definition = tag_persist_struct_definitions[tag_persist_struct_index];

			if (existing_tag_persist_struct_definition.unique_identifier == tag_struct_definition.persistent_identifier)
			{
				return tag_persist_struct_index;
			}
		}
	}

	// reserve this structure index
	s_tag_persist_struct_definition tag_persist_struct_definition_temp = {};
	tag_persist_struct_definition_temp.unique_identifier.identifier_part_0 = tag_struct_definition.persistent_identifier.identifier_part_0;
	tag_persist_struct_definition_temp.unique_identifier.identifier_part_1 = tag_struct_definition.persistent_identifier.identifier_part_1;
	tag_persist_struct_definition_temp.unique_identifier.identifier_part_2 = tag_struct_definition.persistent_identifier.identifier_part_2;
	tag_persist_struct_definition_temp.unique_identifier.identifier_part_3 = tag_struct_definition.persistent_identifier.identifier_part_3;
	uint32_t tag_persist_struct_index = structure_definitions_chunk->entry_count;
	structure_definitions_chunk->append_data(&tag_persist_struct_definition_temp, sizeof(tag_persist_struct_definition_temp));

	std::vector<s_tag_persist_field> tag_persist_fields;

	for (blofeld::s_tag_field const* current_field = tag_struct_definition.fields; /*current_field->field_type != blofeld::_field_terminator*/; current_field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		s_tag_persist_field& tag_persist_field = tag_persist_fields.emplace_back();
		enqueue_field(*current_field, tag_persist_field);

		if (current_field->field_type == blofeld::_field_terminator)
		{
			break;
		}
	}

	uint32_t fields_start_index = fields_chunk->entry_count;
	fields_chunk->append_data(tag_persist_fields.data(), static_cast<unsigned long>(sizeof(tag_persist_fields[0]) * tag_persist_fields.size()));


	s_tag_persist_struct_definition tag_persist_struct_definition;
	tag_persist_struct_definition.unique_identifier.identifier_part_0 = tag_struct_definition.persistent_identifier.identifier_part_0;
	tag_persist_struct_definition.unique_identifier.identifier_part_1 = tag_struct_definition.persistent_identifier.identifier_part_1;
	tag_persist_struct_definition.unique_identifier.identifier_part_2 = tag_struct_definition.persistent_identifier.identifier_part_2;
	tag_persist_struct_definition.unique_identifier.identifier_part_3 = tag_struct_definition.persistent_identifier.identifier_part_3;
	tag_persist_struct_definition.fields_start_index = fields_start_index;
	tag_persist_struct_definition.string_character_index.offset = enqueue_string(tag_struct_definition.name);

	// kinda hacky
	s_tag_persist_struct_definition& tag_persist_struct_definition_entry = structure_definitions_chunk->entries[tag_persist_struct_index];
	s_tag_persist_struct_definition& tag_persist_struct_definition_data = reinterpret_cast<s_tag_persist_struct_definition*>(const_cast<void*>(structure_definitions_chunk->chunk_data))[tag_persist_struct_index];
	tag_persist_struct_definition_entry = tag_persist_struct_definition;
	tag_persist_struct_definition_data = tag_persist_struct_definition;

	return tag_persist_struct_index;
}

void c_high_level_tag_file_writer::enqueue_field(blofeld::s_tag_field const& field, s_tag_persist_field& tag_persist_field)
{
	blofeld::e_field field_type = field.field_type;

	const char* tag_field_name = field.name;
	switch (field_type)
	{
	case blofeld::_field_custom:
	case blofeld::_field_explanation:
		field_type = blofeld::_field_custom;
		tag_field_name = nullptr;
		break;
	}

	tag_persist_field.string_character_index.offset = enqueue_string(tag_field_name);
	tag_persist_field.field_type_index = enqueue_field_type(field_type);
	tag_persist_field.metadata = 0;

	switch (field_type)
	{
	case blofeld::_field_char_block_index_custom_search:
	case blofeld::_field_short_block_index_custom_search:
	case blofeld::_field_long_block_index_custom_search:
		tag_persist_field.metadata = enqueue_block_index_custom_search_definition(*field.block_index_custom_search_definition);
		break;
	case blofeld::_field_char_block_index:
	case blofeld::_field_short_block_index:
	case blofeld::_field_long_block_index:
	case blofeld::_field_block:
		tag_persist_field.metadata = enqueue_block_definition(*field.block_definition);
		break;
	case blofeld::_field_data:
		tag_persist_field.metadata = enqueue_data_definition(*field.tag_data_definition);
		break;
	case blofeld::_field_array:
		tag_persist_field.metadata = enqueue_array_definition(*field.array_definition);
		break;
	case blofeld::_field_struct:
		tag_persist_field.metadata = enqueue_struct_definition(*field.struct_definition);
		break;
	case blofeld::_field_pageable_resource:
		tag_persist_field.metadata = enqueue_resource_definition(*field.tag_resource_definition);
		break;
	case blofeld::_field_api_interop:
		tag_persist_field.metadata = enqueue_interop_definition(*field.tag_interop_definition);
		break;
	case blofeld::_field_char_enum:
	case blofeld::_field_short_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_byte_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_long_flags:
		tag_persist_field.metadata = enqueue_string_list_definition(*field.string_list_definition);
		break;
	case blofeld::_field_skip:
	case blofeld::_field_pad:
		tag_persist_field.metadata = field.padding;
		break;
	}
}

uint32_t c_high_level_tag_file_writer::enqueue_field_type(blofeld::e_field field_type)
{
	const char* tag_field_type;
	ASSERT(BCS_SUCCEEDED(blofeld::field_to_tagfile_field_type(field_type, tag_field_type)));

	{
		uint32_t tag_persist_field_type_count = field_types_chunk->entry_count;
		s_tag_persist_field_type* tag_persist_field_types = field_types_chunk->entries;
		for (uint32_t tag_persist_field_type_index = 0; tag_persist_field_type_index < tag_persist_field_type_count; tag_persist_field_type_index++)
		{
			s_tag_persist_field_type& existing_tag_persist_field_type = tag_persist_field_types[tag_persist_field_type_index];

			const char* existing_tag_field_type = static_cast<const char*>(string_data_chunk->chunk_data) + existing_tag_persist_field_type.string_character_index.offset;

			if (strcmp(existing_tag_field_type, tag_field_type) == 0)
			{
				return tag_persist_field_type_index;
			}
		}
	}

	s_tag_persist_field_type tag_persist_field_type = {};
	tag_persist_field_type.string_character_index.offset = enqueue_string(tag_field_type);
	ASSERT(BCS_SUCCEEDED(blofeld::get_blofeld_tag_file_field_size(field_type, engine_platform_build, tag_persist_field_type.size)));
	tag_persist_field_type.has_child_chunk = false;

	switch (field_type)
	{
	case blofeld::_field_struct:
	case blofeld::_field_block:
	case blofeld::_field_data:
	case blofeld::_field_pageable_resource:
	case blofeld::_field_api_interop:
	case blofeld::_field_tag_reference:
	case blofeld::_field_string_id:
	case blofeld::_field_old_string_id:
		tag_persist_field_type.has_child_chunk = true;
		break;
	}

	uint32_t field_type_index = field_types_chunk->entry_count;
	field_types_chunk->append_data(&tag_persist_field_type, sizeof(tag_persist_field_type));

	return field_type_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_string_list_definition(const blofeld::s_string_list_definition& string_list_definition)
{
	{
		uint32_t string_list_count = string_lists_chunk->entry_count;
		s_tag_persist_string_list* string_lists = string_lists_chunk->entries;
		for (uint32_t string_list_index = 0; string_list_index < string_list_count; string_list_index++)
		{
			s_tag_persist_string_list& existing_string_list = string_lists[string_list_index];

			const char* string_list_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_string_list.string_character_index.offset;

			if (strcmp(string_list_name, string_list_definition.name) == 0)
			{
				return string_list_index;
			}
		}
	}

	uint32_t string_offset_start_index = string_offsets_chunk->entry_count;
	uint32_t num_strings = string_list_definition.get_count(engine_platform_build);
	for (uint32_t string_index = 0; string_index < num_strings; string_index++)
	{
		const char* string = string_list_definition.get_string(engine_platform_build, string_index);

		c_blamlib_string_parser_v2 blamlib_string_parser(string);

		s_tag_persist_string_character_index string_character_index;
		string_character_index.offset = enqueue_string(blamlib_string_parser.tag_file_name);

		string_offsets_chunk->append_data(&string_character_index, sizeof(string_character_index));
	}

	s_tag_persist_string_list string_list_entry;
	string_list_entry.string_character_index.offset = enqueue_string(string_list_definition.name);
	string_list_entry.string_offset_count = num_strings;
	string_list_entry.string_offset_start_index = string_offset_start_index;

	uint32_t string_list_index = string_lists_chunk->entry_count;
	string_lists_chunk->append_data(&string_list_entry, sizeof(string_list_entry));

	return string_list_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_data_definition(const blofeld::s_tag_data_definition& tag_data_definition)
{
	{
		uint32_t data_definition_count = data_definition_name_chunk->entry_count;
		s_tag_persist_string_character_index* data_definitions = data_definition_name_chunk->offsets;
		for (uint32_t data_definition_index = 0; data_definition_index < data_definition_count; data_definition_index++)
		{
			s_tag_persist_string_character_index& existing_data_definition = data_definitions[data_definition_index];

			const char* data_definition_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_data_definition.offset;

			if (strcmp(data_definition_name, tag_data_definition.name) == 0)
			{
				return data_definition_index;
			}
		}
	}

	s_tag_persist_string_character_index string_character_index;
	string_character_index.offset = enqueue_string(tag_data_definition.name);

	uint32_t data_definition_index = data_definition_name_chunk->entry_count;
	data_definition_name_chunk->append_data(&string_character_index, sizeof(string_character_index));

	return data_definition_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_resource_definition(const blofeld::s_tag_resource_definition& tag_resource_definition)
{
	{
		uint32_t resource_definition_count = resource_definitions_chunk->entry_count;
		s_tag_persist_resource_definition* resource_definitions = resource_definitions_chunk->entries;
		for (uint32_t resource_definition_index = 0; resource_definition_index < resource_definition_count; resource_definition_index++)
		{
			s_tag_persist_resource_definition& existing_resource_definition = resource_definitions[resource_definition_index];

			const char* resource_definition_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_resource_definition.string_character_index.offset;

			if (strcmp(resource_definition_name, tag_resource_definition.name) == 0)
			{
				return resource_definition_index;
			}
		}
	}

	s_tag_persist_resource_definition resource_definition;
	resource_definition.structure_entry_index = enqueue_struct_definition(tag_resource_definition.struct_definition);
	resource_definition.string_character_index.offset = enqueue_string(tag_resource_definition.name);
	resource_definition.flags = 0;

	uint32_t resource_definition_index = resource_definitions_chunk->entry_count;
	resource_definitions_chunk->append_data(&resource_definition, sizeof(resource_definition));

	return resource_definition_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_interop_definition(const blofeld::s_tag_interop_definition& tag_interop_definition)
{
	{
		uint32_t interop_definition_count = interop_definitions_chunk->entry_count;
		s_tag_persist_interop_definition* interop_definitions = interop_definitions_chunk->entries;
		for (uint32_t interop_definition_index = 0; interop_definition_index < interop_definition_count; interop_definition_index++)
		{
			s_tag_persist_interop_definition& existing_interop_definition = interop_definitions[interop_definition_index];

			if (existing_interop_definition.unique_identifier == tag_interop_definition.persistent_identifier)
			{
				return interop_definition_index;
			}
		}
	}

	s_tag_persist_interop_definition interop_definition;
	interop_definition.structure_entry_index = enqueue_struct_definition(tag_interop_definition.struct_definition);
	//interop_definition.string_character_index.offset = enqueue_string(tag_interop_definition.name);
	interop_definition.string_character_index.offset = enqueue_string("blah"); // oh bungie you silly goose
	interop_definition.unique_identifier.identifier_part_0 = tag_interop_definition.persistent_identifier.identifier_part_0;
	interop_definition.unique_identifier.identifier_part_1 = tag_interop_definition.persistent_identifier.identifier_part_1;
	interop_definition.unique_identifier.identifier_part_2 = tag_interop_definition.persistent_identifier.identifier_part_2;
	interop_definition.unique_identifier.identifier_part_3 = tag_interop_definition.persistent_identifier.identifier_part_3;

	uint32_t interop_definition_index = interop_definitions_chunk->entry_count;
	interop_definitions_chunk->append_data(&interop_definition, sizeof(interop_definition));

	return interop_definition_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_array_definition(const blofeld::s_tag_array_definition& tag_array_definition)
{
	{
		uint32_t array_definition_count = array_definitions_chunk->entry_count;
		s_tag_persist_array_definition* array_definitions = array_definitions_chunk->entries;
		for (uint32_t array_definition_index = 0; array_definition_index < array_definition_count; array_definition_index++)
		{
			s_tag_persist_array_definition& existing_array_definition = array_definitions[array_definition_index];

			const char* array_definition_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_array_definition.string_character_index.offset;

			if (strcmp(array_definition_name, tag_array_definition.name) == 0)
			{
				return array_definition_index;
			}
		}
	}

	s_tag_persist_array_definition array_definition;
	array_definition.structure_entry_index = enqueue_struct_definition(tag_array_definition.struct_definition);
	array_definition.count = tag_array_definition.element_count(engine_platform_build);
	array_definition.string_character_index.offset = enqueue_string(tag_array_definition.name);

	uint32_t array_definition_index = array_definitions_chunk->entry_count;
	array_definitions_chunk->append_data(&array_definition, sizeof(array_definition));

	return array_definition_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& tag_block_index_custom_search_definition)
{
	{
		uint32_t block_index_custom_search_definition_count = custom_block_index_search_names_chunk->entry_count;
		s_tag_persist_string_character_index* block_index_custom_search_definitions = custom_block_index_search_names_chunk->offsets;
		for (uint32_t block_index_custom_search_definition_index = 0; block_index_custom_search_definition_index < block_index_custom_search_definition_count; block_index_custom_search_definition_index++)
		{
			s_tag_persist_string_character_index& existing_block_index_custom_search_definition = block_index_custom_search_definitions[block_index_custom_search_definition_index];

			const char* existing_block_index_custom_search_definition_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_block_index_custom_search_definition.offset;

			if (strcmp(existing_block_index_custom_search_definition_name, tag_block_index_custom_search_definition.name) == 0)
			{
				return block_index_custom_search_definition_index;
			}
		}
	}

	s_tag_persist_string_character_index block_index_custom_search_definition;
	block_index_custom_search_definition.offset = enqueue_string(tag_block_index_custom_search_definition.name);

	uint32_t array_definition_index = custom_block_index_search_names_chunk->entry_count;
	custom_block_index_search_names_chunk->append_data(&block_index_custom_search_definition, sizeof(block_index_custom_search_definition));

	return array_definition_index;
}

uint32_t c_high_level_tag_file_writer::enqueue_string(const char* string)
{
	if (string == nullptr)
	{
		string = "";
	}

	BCS_RESULT rs = BCS_S_OK;

	uint32_t string_data_length = static_cast<unsigned long>(strlen(string) + 1);
	const void* existing_data = nullptr;
	uint32_t existing_data_size = 0;
	if (BCS_SUCCEEDED(rs = string_data_chunk->get_data(existing_data, existing_data_size)))
	{
		const char* existing_substring = (const char*)memmem(existing_data, existing_data_size, string, string_data_length);
		if (existing_substring)
		{
			uint32_t offset = static_cast<unsigned long>(existing_substring - static_cast<const char*>(existing_data));
			return offset;
		}
	}

	string_data_chunk->append_data(string, string_data_length);

	return existing_data_size;
}

void c_high_level_tag_file_writer::serialize_tag_group(const h_tag_instance& tag, c_binary_data_chunk& parent_chunk)
{
	c_tag_block_chunk& tag_block_chunk = *new() c_tag_block_chunk(parent_chunk);
	parent_chunk.add_child(tag_block_chunk);

	blofeld::s_tag_struct_definition const& tag_struct_definition = tag.prototype.get_blofeld_struct_definition();

	s_tag_block_chunk_header& tag_block_chunk_header = tag_block_chunk.tag_block_chunk_header;
	tag_block_chunk_header.count = 1;
	tag_block_chunk_header.is_simple_data_type = !tag_struct_definition.runtime_flags.test(blofeld::_tag_field_set_unknown0_bit);

	tag_block_chunk.set_data(&tag_block_chunk_header, sizeof(tag_block_chunk_header));

	uint32_t structure_size = calculate_structure_size(tag_struct_definition);
	char* const structure_data = static_cast<char*>(tracked_malloc(structure_size));
	DEBUG_ONLY(memset(structure_data, 0xDD, structure_size));

	c_tag_struct_chunk* tag_struct_chunk = new() c_tag_struct_chunk(tag_block_chunk);
	tag_block_chunk.add_child(*tag_struct_chunk);

	serialize_tag_struct(tag.prototype, structure_data, tag_struct_chunk);

	tag_block_chunk.append_data(structure_data, structure_size);

}

void c_high_level_tag_file_writer::serialize_tag_block(const h_block& block, c_tag_struct_chunk& parent_chunk, blofeld::s_tag_block_definition const& tag_block_definition)
{
	uint32_t block_count = block.size();

	c_tag_block_chunk& tag_block_chunk = *new() c_tag_block_chunk(parent_chunk);
	parent_chunk.add_child(tag_block_chunk);

	blofeld::s_tag_struct_definition const& tag_struct_definition = tag_block_definition.struct_definition;

	s_tag_block_chunk_header& tag_block_chunk_header = tag_block_chunk.tag_block_chunk_header;
	tag_block_chunk_header.count = block_count;
	tag_block_chunk_header.is_simple_data_type = !tag_struct_definition.runtime_flags.test(blofeld::_tag_field_set_unknown0_bit);

	tag_block_chunk.set_data(&tag_block_chunk_header, sizeof(tag_block_chunk_header));

	uint32_t structure_size = calculate_structure_size(tag_struct_definition);
	uint32_t block_data_size = structure_size * block_count;
	char* const block_data = static_cast<char*>(tracked_malloc(block_data_size));
	char* structure_data = block_data;

	for (uint32_t block_index = 0; block_index < block_count; block_index++, structure_data += structure_size)
	{
		DEBUG_ONLY(memset(structure_data, static_cast<char>(block_index + 0xDD), structure_size));
		const h_prototype& object = block[block_index];

		c_tag_struct_chunk* tag_struct_chunk = nullptr;
		if (!tag_block_chunk_header.is_simple_data_type)
		{
			tag_struct_chunk = new() c_tag_struct_chunk(tag_block_chunk);
			tag_block_chunk.add_child(*tag_struct_chunk);
		}

		char* out_structure_data_position = structure_data + structure_size; // expected position
		serialize_tag_struct(object, structure_data, tag_struct_chunk, &out_structure_data_position);
		auto structure_size_written = out_structure_data_position - structure_data;
		ASSERT(structure_size_written == structure_size);
	}

	tag_block_chunk.append_data(block_data, block_data_size);
}

void c_high_level_tag_file_writer::serialize_tag_struct(const h_prototype& prototype, char* const structure_data, c_tag_struct_chunk* tag_struct_chunk, char** out_structure_data_position)
{
	char* structure_data_position = structure_data;
	uint32_t field_index = 0;

	h_prototype_serialization_info const& prototype_serialization_info = prototype.get_serialization_information();
	for (unsigned int field_serialization_index = 0; field_serialization_index < prototype_serialization_info.num_field_serialization_infos; field_serialization_index++)
	{
		h_field_serialization_info const& field_serialization_info = prototype_serialization_info.field_serialization_infos[field_serialization_index];
		blofeld::s_tag_field const& tag_field = prototype_serialization_info.tag_struct_definition.fields[field_serialization_info.blofeld_field_index];

		h_type const* field_type = prototype.get_member(field_serialization_info.pointer_to_member);

		const char* name = tag_field.name;

		uint32_t field_size = ULONG_MAX;
		BCS_RESULT get_blofeld_tag_file_field_size_result = blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size);
		ASSERT(BCS_SUCCEEDED(get_blofeld_tag_file_field_size_result)); // #TODO: Return BCS_RESULT

		switch (tag_field.field_type)
		{
		case blofeld::_field_struct:
		{
			h_prototype const* field_prototype = high_level_cast<h_prototype const*>(field_type);
			ASSERT(field_prototype != nullptr);

			blofeld::s_tag_struct_definition const& struct_definition = *tag_field.struct_definition;
			field_size = calculate_structure_size(struct_definition);

			ASSERT(tag_struct_chunk != nullptr);
			c_tag_struct_chunk* _tag_struct_chunk = new() c_tag_struct_chunk(*static_cast<c_chunk*>(tag_struct_chunk));
			tag_struct_chunk->add_child(*_tag_struct_chunk);

			serialize_tag_struct(*field_prototype, structure_data_position, _tag_struct_chunk);
		}
		break;
		case blofeld::_field_array:
		{
			h_enumerable const* field_enumerable = high_level_cast<h_enumerable const*>(field_type);
			ASSERT(field_enumerable != nullptr);

			const blofeld::s_tag_array_definition& array_definition = *tag_field.array_definition;
			uint32_t structure_size = calculate_structure_size(array_definition.struct_definition);

			unsigned int array_size = array_definition.element_count(engine_platform_build);

			ASSERT(tag_struct_chunk != nullptr);
			ASSERT(array_size == field_enumerable->size());

			char* dst_array_field_data = structure_data_position;
			for (unsigned int index = 0; index < array_size; index++)
			{
				const h_prototype& prototype = (*field_enumerable)[index];

				serialize_tag_struct(prototype, dst_array_field_data, tag_struct_chunk);

				dst_array_field_data += structure_size;
			}

			field_size = structure_size * array_size;

			debug_point;
		}
		break;
		case blofeld::_field_skip:
		case blofeld::_field_pad:
		{
			uint32_t pad_size = tag_field.padding;
			field_size = pad_size;
			memset(structure_data_position, 0, field_size);
		}
		break;
		case blofeld::_field_block:
		{
			h_block const* field_block = high_level_cast<h_block const*>(field_type);
			ASSERT(field_block != nullptr);

			ASSERT(tag_struct_chunk != nullptr);
			ASSERT(tag_field.block_definition != nullptr);
			serialize_tag_block(*field_block, *tag_struct_chunk, *tag_field.block_definition);

			s_tag_block* tag_block = reinterpret_cast<s_tag_block*>(structure_data_position);
			DEBUG_ONLY(memset(tag_block, 0xBB, sizeof(*tag_block)));

			tag_block->count = field_block->size();
			tag_block->address = 0;
			tag_block->definition_address = 0;


		}
		break;
		case blofeld::_field_data:
		{
			h_data const* field_data = high_level_cast<h_data const*>(field_type);
			ASSERT(field_data != nullptr);

			ASSERT(tag_struct_chunk != nullptr);
			serialize_tag_data(*field_data, *tag_struct_chunk);

			s_tag_data* tag_data = reinterpret_cast<s_tag_data*>(structure_data_position);
			DEBUG_ONLY(memset(tag_data, 0xCC, sizeof(*tag_data)));

			tag_data->size = static_cast<long>(field_data->size());
			tag_data->stream_flags = 0; // unused
			tag_data->stream_offset = 0; // unused
			tag_data->address = 0;
			tag_data->definition = 0; // unused
		}
		break;
		case blofeld::_field_old_string_id:
		case blofeld::_field_string_id:
		{
			h_string_id_field const* field_string_id = high_level_cast<h_string_id_field const*>(field_type);
			ASSERT(field_string_id != nullptr);

			ASSERT(tag_struct_chunk != nullptr);
			serialize_string_id(*field_string_id, *tag_struct_chunk);
			memset(structure_data_position, 0, field_size);
		}
		break;
		case blofeld::_field_pageable_resource:
		{
			h_resource_field const* field_resource = high_level_cast<h_resource_field const*>(field_type);
			ASSERT(field_resource != nullptr);

			h_resource* resource = field_resource->get_resource();

			ASSERT(tag_struct_chunk != nullptr);
			ASSERT(tag_field.tag_resource_definition != nullptr);

			serialize_tag_resource(resource, *tag_field.tag_resource_definition, *tag_struct_chunk);

			memset(structure_data_position, 0, field_size);

			if (resource != nullptr)
			{
				s_tag_resource* tag_resource = reinterpret_cast<s_tag_resource*>(structure_data_position);
				tag_resource->resource_handle = 0;


			}
		}
		break;
		case blofeld::_field_tag_reference:
		{
			h_tag_reference const* field_tag_reference = high_level_cast<h_tag_reference const*>(field_type);
			ASSERT(field_tag_reference != nullptr);

			ASSERT(tag_struct_chunk != nullptr);

			serialize_tag_reference(*field_tag_reference, *tag_field.tag_reference_definition, *tag_struct_chunk);

			s_tag_reference* tag_reference = reinterpret_cast<s_tag_reference*>(structure_data_position);
			DEBUG_ONLY(memset(tag_reference, 0xBB, sizeof(*tag_reference)));

			tag_reference->group_tag = 0;
			tag_reference->name = 0;
			tag_reference->name_length = 0;
			tag_reference->datum_index = 0;
		}
		break;
		case blofeld::_field_api_interop:
			s_tag_interop tag_interop;
			tag_interop.descriptor = 0;
			tag_interop.address = UINT_MAX;
			tag_interop.definition_address = 0;

			memcpy(structure_data_position, &tag_interop, field_size);
			break;
		default:
		{
			h_field const* field = high_level_cast<h_field const*>(field_type);
			ASSERT(field != nullptr);
			void const* field_data = field->get_data();

			memcpy(structure_data_position, field_data, field_size);
		}
		break;
		}

		ASSERT(field_size != ULONG_MAX);
		structure_data_position += field_size;
	}
	if (out_structure_data_position)
	{
		*out_structure_data_position = structure_data_position;
	}
}

void c_high_level_tag_file_writer::serialize_tag_data(const h_data& data, c_tag_struct_chunk& parent_chunk)
{
	c_tag_data_chunk& tag_data_chunk = *new() c_tag_data_chunk(parent_chunk);
	parent_chunk.add_child(tag_data_chunk);

	if (!data.empty())
	{
		tag_data_chunk.set_data(data.data(), static_cast<unsigned long>(data.size()));
	}
}

void c_high_level_tag_file_writer::serialize_tag_resource(const h_resource* resource, const blofeld::s_tag_resource_definition& tag_resource_definition, c_tag_struct_chunk& parent_chunk)
{
	c_chunk* resource_chunk = nullptr;


	//if (resource != nullptr)
	if (const c_simple_resource_container* simple_resource_container = dynamic_cast<const c_simple_resource_container*>(resource))
	{
		c_tag_resource_exploded_chunk* tag_resource_exploded_chunk = new() c_tag_resource_exploded_chunk(parent_chunk);
		c_tag_resource_data_chunk* tag_resource_data_chunk = new() c_tag_resource_data_chunk(*tag_resource_exploded_chunk);
		c_tag_struct_chunk* tag_struct_chunk = new() c_tag_struct_chunk(*tag_resource_exploded_chunk);

		h_prototype* prototype;
		BCS_RESULT create_high_level_object_result = high_level_registry_create_high_level_object(engine_platform_build, tag_resource_definition.struct_definition, prototype);
		ASSERT(BCS_SUCCEEDED(create_high_level_object_result));

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
		if (blofeld::halo3::pc64::h_sound_resource_definition_struct* sound_resource_definition_struct = high_level_cast<decltype(sound_resource_definition_struct)>(prototype))
		{
			char const* bytes = simple_resource_container->data.data();
			unsigned int num_bytes = static_cast<unsigned int>(simple_resource_container->data.size());

			sound_resource_definition_struct->sample_data.clear();
			char* elements = sound_resource_definition_struct->sample_data.append_elements(bytes, num_bytes);
		}
		else
#endif
		{
			throw; // not implemented
		}

		uint32_t structure_size = calculate_structure_size(tag_resource_definition.struct_definition);
		char* const structure_data = static_cast<char*>(tracked_malloc(structure_size));
		DEBUG_ONLY(memset(structure_data, 0xDD, structure_size));

		serialize_tag_struct(*prototype, structure_data, tag_struct_chunk);

		tag_resource_data_chunk->set_data(structure_data, structure_size);

		tag_resource_exploded_chunk->add_child(*tag_resource_data_chunk);
		tag_resource_exploded_chunk->add_child(*tag_struct_chunk);
		parent_chunk.add_child(*tag_resource_exploded_chunk);
	}
	else if (resource)
	{
		h_resource* _resource = const_cast<h_resource*>(resource);
		c_eldorado_resource_handle const* __resource = dynamic_cast<c_eldorado_resource_handle const*>(_resource);

		BCS_RESULT rs = BCS_S_OK;
		s_resource_details resource_details;
		if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, false)))
		{
			c_tag_resource_exploded_chunk* tag_resource_exploded_chunk = new() c_tag_resource_exploded_chunk(parent_chunk);
			c_tag_resource_data_chunk* tag_resource_data_chunk = new() c_tag_resource_data_chunk(*tag_resource_exploded_chunk);
			c_tag_struct_chunk* tag_struct_chunk = new() c_tag_struct_chunk(*tag_resource_exploded_chunk);

			resource_chunk = tag_resource_exploded_chunk;

			h_prototype* control_data_prototype = nullptr;

			h_prototype* prototype = nullptr;
			// #TODO: this is very bad and this data is requried for valid resoruces!!!!!
			BCS_RESULT create_high_level_object_result = high_level_registry_create_high_level_object(engine_platform_build, tag_resource_definition.struct_definition, prototype);
			ASSERT(BCS_SUCCEEDED(create_high_level_object_result));

			if (false) {}
#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO
			else if (blofeld::eldorado::pc32::h_sound_resource_definition_struct* sound = high_level_cast<decltype(sound)>(prototype))
			{
				
			}
			else if (blofeld::eldorado::pc32::h_model_animation_tag_resource_struct* model_animation_tag = high_level_cast<decltype(model_animation_tag)>(prototype))
			{
				if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, true)))
				{
					control_data_prototype = resource_details.prototype;
				}
			}
			else if (blofeld::eldorado::pc32::h_bitmap_texture_interop_resource_struct* bitmap_texture_interop = high_level_cast<decltype(bitmap_texture_interop)>(prototype))
			{
				if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, true)))
				{
					control_data_prototype = resource_details.prototype;
				}
			}
			else if (blofeld::eldorado::pc32::h_render_geometry_api_resource_definition_struct* render_geometry_api = high_level_cast<decltype(render_geometry_api)>(prototype))
			{
				if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, true)))
				{
					control_data_prototype = resource_details.prototype;
				}
			}
			else if (blofeld::eldorado::pc32::h_bink_resource_struct* bink = high_level_cast<decltype(bink)>(prototype))
			{
				debug_point;
			}
			else if (blofeld::eldorado::pc32::h_structure_bsp_tag_resources_struct* structure_bsp_tag = high_level_cast<decltype(structure_bsp_tag)>(prototype))
			{
				if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, true)))
				{
					control_data_prototype = resource_details.prototype;
				}
			}
			else if (blofeld::eldorado::pc32::h_structure_bsp_cache_file_tag_resources_struct* structure_bsp_cache_file_tag = high_level_cast<decltype(structure_bsp_cache_file_tag)>(prototype))
			{
				if (BCS_SUCCEEDED(rs = _resource->add_reference(resource_details, true)))
				{
					control_data_prototype = resource_details.prototype;
				}
			}
#endif
#ifdef BCS_BUILD_HIGH_LEVEL_HALO3
			else if (blofeld::halo3::pc64::h_sound_resource_definition_struct* sound_resource_definition_struct = high_level_cast<decltype(sound_resource_definition_struct)>(prototype))
			{
				char const* bytes = simple_resource_container->data.data();
				unsigned int num_bytes = static_cast<unsigned int>(simple_resource_container->data.size());

				sound_resource_definition_struct->sample_data.clear();
				char* elements = sound_resource_definition_struct->sample_data.append_elements(bytes, num_bytes);
			}
#endif
			else
			{
				debug_point; // not implemented
			}

			uint32_t structure_size = calculate_structure_size(tag_resource_definition.struct_definition);
			char* const structure_data = static_cast<char*>(tracked_malloc(structure_size));
			DEBUG_ONLY(memset(structure_data, 0xDD, structure_size));

			h_prototype* serialize_prototype = control_data_prototype ? control_data_prototype : prototype;

			serialize_tag_struct(*serialize_prototype, structure_data, tag_struct_chunk);

			tag_resource_data_chunk->set_data(structure_data, structure_size);

			tag_resource_exploded_chunk->add_child(*tag_resource_data_chunk);
			tag_resource_exploded_chunk->add_child(*tag_struct_chunk);
			parent_chunk.add_child(*tag_resource_exploded_chunk);

			debug_point;

			if (control_data_prototype)
			{
				rs = _resource->remove_reference();
			}
			rs = _resource->remove_reference();

			delete prototype;
		}

		debug_point;
	}

	if (resource_chunk == nullptr)
	{
		c_tag_resource_null_chunk* tag_resource_null_chunk = new() c_tag_resource_null_chunk(parent_chunk);
		parent_chunk.add_child(*tag_resource_null_chunk);
	}
}

void c_high_level_tag_file_writer::serialize_string_id(const h_string_id_field& string_id, c_tag_struct_chunk& parent_chunk)
{
	c_tag_string_id_chunk& tag_string_id_chunk = *new() c_tag_string_id_chunk(parent_chunk);
	parent_chunk.add_child(tag_string_id_chunk);

	tag_string_id_chunk.set_string(string_id.get_string());


}

void c_high_level_tag_file_writer::serialize_tag_reference(const h_tag_reference& reference, const blofeld::s_tag_reference_definition& tag_reference_definition, c_tag_struct_chunk& parent_chunk)
{
	c_tag_reference_chunk& tag_reference_chunk = *new() c_tag_reference_chunk(parent_chunk);
	parent_chunk.add_child(tag_reference_chunk);

	if (!reference.is_null())
	{
		const char* tag_path = reference.get_file_path_without_extension();
		tag_reference_chunk.set_reference(reference.get_group_tag(), tag_path);
	}
	else
	{
		tag_reference_chunk.set_reference(blofeld::INVALID_TAG, "");
	}
}

uint32_t c_high_level_tag_file_writer::calculate_structure_size(const h_prototype& prototype)
{
	uint32_t structure_size = 0;
	h_prototype_serialization_info const& prototype_serialization_info = prototype.get_serialization_information();
	for (unsigned int field_serialization_index = 0; field_serialization_index < prototype_serialization_info.num_field_serialization_infos; field_serialization_index++)
	{
		h_field_serialization_info const& field_serialization_info = prototype_serialization_info.field_serialization_infos[field_serialization_index];
		blofeld::s_tag_field const& tag_field = prototype_serialization_info.tag_struct_definition.fields[field_serialization_info.blofeld_field_index];

		uint32_t field_size = ULONG_MAX;

		switch (tag_field.field_type)
		{
		case blofeld::_field_struct:
		{
			blofeld::s_tag_struct_definition const& struct_definition = *tag_field.struct_definition;
			field_size = calculate_structure_size(struct_definition);
		}
		break;
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *tag_field.array_definition;
			uint32_t structure_size = calculate_structure_size(array_definition.struct_definition);
			field_size = structure_size * array_definition.element_count(engine_platform_build);
		}
		break;
		case blofeld::_field_pad:
		{
			uint32_t pad_size = tag_field.padding;
			field_size = pad_size;
		}
		break;
		default:
		{
			ASSERT(BCS_SUCCEEDED(blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size)));
		}
		break;
		}

		ASSERT(field_size != ULONG_MAX);

		structure_size += field_size;
	}

	return structure_size;
}

uint32_t c_high_level_tag_file_writer::calculate_structure_size(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	uint32_t structure_size = 0;
	for (blofeld::s_tag_field const* current_field = tag_struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = ULONG_MAX;
		blofeld::e_field field_type = current_field->field_type;

		switch (field_type)
		{
		case blofeld::_field_struct:
		{
			blofeld::s_tag_struct_definition const& struct_definition = *current_field->struct_definition;
			field_size = calculate_structure_size(struct_definition);
		}
		break;
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *current_field->array_definition;
			uint32_t structure_size = calculate_structure_size(array_definition.struct_definition);
			field_size = structure_size * array_definition.element_count(engine_platform_build);
		}
		break;
		case blofeld::_field_skip:
		case blofeld::_field_pad:
		{
			uint32_t pad_size = current_field->padding;
			field_size = pad_size;
		}
		break;
		default:
		{
			ASSERT(BCS_SUCCEEDED(blofeld::get_blofeld_tag_file_field_size(field_type, engine_platform_build, field_size)));
		}
		break;
		}

		ASSERT(field_size != ULONG_MAX);

		structure_size += field_size;
	}

	return structure_size;
}



