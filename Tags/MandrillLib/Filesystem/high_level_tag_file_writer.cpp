#include "mandrilllib-private-pch.h"

#include <HighLevel\high_level_halo3\highlevel-halo3-public-pch.h>
#include <TagCodegen\blamlib_string_parser.h>
#include <TagCodegen\blamlib_string_parser.inl>

static constexpr size_t y = sizeof(s_engine_platform_build);

c_high_level_tag_file_writer::c_high_level_tag_file_writer(s_engine_platform_build engine_platform_build, const char* _filepath, h_tag& tag) :
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
	file_handle = fopen(_filepath, "wb");

	init_chunks();

	const blofeld::s_tag_group& group_definition = tag.get_blofeld_group_definition();
	unsigned long tag_group_block_index = enqueue_block_definition(group_definition.block_definition);
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
	tag_file_header.group_tag = tag.group->tag_group.group_tag;
	//tag_file_header.group_version = tag.group->tag_group.version;
	tag_file_header.group_version = 7; // #TODO: How to handle this? This has been written specifically for the Bitmap group
	tag_file_header.group_version = 4; // #TODO: How to handle this? This has been written specifically for the Bitmap group
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

	tag_group_layout_chunk_data.tag_group_layout_header.unknown;
	tag_group_layout_chunk_data.tag_group_layout_header.guid;
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
	untracked_free(filepath);
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

	header_chunk->write_chunk(*this);
}

unsigned long c_high_level_tag_file_writer::enqueue_block_definition(const blofeld::s_tag_block_definition& tag_block_definition)
{
	{
		unsigned long block_definition_count = block_definitions_chunk->entry_count;
		s_tag_persist_block_definition* block_definitions = block_definitions_chunk->entries;
		for (unsigned long block_definition_index = 0; block_definition_index < block_definition_count; block_definition_index++)
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

	unsigned long block_index = block_definitions_chunk->entry_count;
	block_definitions_chunk->append_data(&tag_persist_block_definition, sizeof(tag_persist_block_definition));

	return block_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_struct_definition(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	{
		unsigned long tag_persist_struct_count = structure_definitions_chunk->entry_count;
		s_tag_persist_struct_definition* tag_persist_struct_definitions = structure_definitions_chunk->entries;
		for (unsigned long tag_persist_struct_index = 0; tag_persist_struct_index < tag_persist_struct_count; tag_persist_struct_index++)
		{
			s_tag_persist_struct_definition& existing_tag_persist_struct_definition = tag_persist_struct_definitions[tag_persist_struct_index];

			if (existing_tag_persist_struct_definition.persistent_identifier == tag_struct_definition.persistent_identifier)
			{
				return tag_persist_struct_index;
			}
		}
	}

	// reserve this structure index
	s_tag_persist_struct_definition tag_persist_struct_definition_temp = {};
	unsigned long tag_persist_struct_index = structure_definitions_chunk->entry_count;
	structure_definitions_chunk->append_data(&tag_persist_struct_definition_temp, sizeof(tag_persist_struct_definition_temp));

	std::vector<s_tag_persist_field> tag_persist_fields;

	for (const blofeld::s_tag_field* current_field = tag_struct_definition.fields; /*current_field->field_type != blofeld::_field_terminator*/; current_field++)
	{
		unsigned long field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
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

	unsigned long fields_start_index = fields_chunk->entry_count;
	fields_chunk->append_data(tag_persist_fields.data(), static_cast<unsigned long>(sizeof(tag_persist_fields[0]) * tag_persist_fields.size()));


	s_tag_persist_struct_definition tag_persist_struct_definition;
	tag_persist_struct_definition.persistent_identifier = tag_struct_definition.persistent_identifier;
	tag_persist_struct_definition.fields_start_index = fields_start_index;
	tag_persist_struct_definition.string_character_index.offset = enqueue_string(tag_struct_definition.name);

	// kinda hacky
	s_tag_persist_struct_definition& tag_persist_struct_definition_entry = structure_definitions_chunk->entries[tag_persist_struct_index];
	s_tag_persist_struct_definition& tag_persist_struct_definition_data = reinterpret_cast<s_tag_persist_struct_definition*>(const_cast<void*>(structure_definitions_chunk->chunk_data))[tag_persist_struct_index];
	tag_persist_struct_definition_entry = tag_persist_struct_definition;
	tag_persist_struct_definition_data = tag_persist_struct_definition;

	return tag_persist_struct_index;
}

void c_high_level_tag_file_writer::enqueue_field(const blofeld::s_tag_field& field, s_tag_persist_field& tag_persist_field)
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
	case blofeld::_field_custom_char_block_index:
	case blofeld::_field_custom_short_block_index:
	case blofeld::_field_custom_long_block_index:
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
	case blofeld::_field_pageable:
		tag_persist_field.metadata = enqueue_resource_definition(*field.tag_resource_definition);
		break;
	case blofeld::_field_api_interop:
		tag_persist_field.metadata = enqueue_interop_definition(*field.tag_interop_definition);
		break;
	case blofeld::_field_char_enum:
	case blofeld::_field_enum:
	case blofeld::_field_long_enum:
	case blofeld::_field_byte_flags:
	case blofeld::_field_word_flags:
	case blofeld::_field_long_flags:
		tag_persist_field.metadata = enqueue_string_list_definition(*field.string_list_definition);
		break;
	case blofeld::_field_pad:
		tag_persist_field.metadata = field.padding;
		break;
	}
}

unsigned long c_high_level_tag_file_writer::enqueue_field_type(blofeld::e_field field_type)
{
	const char* tag_field_type;
	ASSERT(BCS_SUCCEEDED(blofeld::field_to_tag_field_type(field_type, tag_field_type)));

	{
		unsigned long tag_persist_field_type_count = field_types_chunk->entry_count;
		s_tag_persist_field_type* tag_persist_field_types = field_types_chunk->entries;
		for (unsigned long tag_persist_field_type_index = 0; tag_persist_field_type_index < tag_persist_field_type_count; tag_persist_field_type_index++)
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
	case blofeld::_field_pageable:
	case blofeld::_field_api_interop:
	case blofeld::_field_tag_reference:
	case blofeld::_field_string_id:
	case blofeld::_field_old_string_id:
		tag_persist_field_type.has_child_chunk = true;
		break;
	}

	unsigned long field_type_index = field_types_chunk->entry_count;
	field_types_chunk->append_data(&tag_persist_field_type, sizeof(tag_persist_field_type));

	return field_type_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_string_list_definition(const blofeld::s_string_list_definition& string_list_definition)
{
	{
		unsigned long string_list_count = string_lists_chunk->entry_count;
		s_tag_persist_string_list* string_lists = string_lists_chunk->entries;
		for (unsigned long string_list_index = 0; string_list_index < string_list_count; string_list_index++)
		{
			s_tag_persist_string_list& existing_string_list = string_lists[string_list_index];

			const char* string_list_name = static_cast<const char*>(string_data_chunk->chunk_data) + existing_string_list.string_character_index.offset;

			if (strcmp(string_list_name, string_list_definition.name) == 0)
			{
				return string_list_index;
			}
		}
	}

	unsigned long string_offset_start_index = string_offsets_chunk->entry_count;
	unsigned long num_strings = string_list_definition.get_count(engine_platform_build);
	for (unsigned long string_index = 0; string_index < num_strings; string_index++)
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

	unsigned long string_list_index = string_lists_chunk->entry_count;
	string_lists_chunk->append_data(&string_list_entry, sizeof(string_list_entry));

	return string_list_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_data_definition(const blofeld::s_tag_data_definition& tag_data_definition)
{
	{
		unsigned long data_definition_count = data_definition_name_chunk->entry_count;
		s_tag_persist_string_character_index* data_definitions = data_definition_name_chunk->offsets;
		for (unsigned long data_definition_index = 0; data_definition_index < data_definition_count; data_definition_index++)
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

	unsigned long data_definition_index = data_definition_name_chunk->entry_count;
	data_definition_name_chunk->append_data(&string_character_index, sizeof(string_character_index));

	return data_definition_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_resource_definition(const blofeld::s_tag_resource_definition& tag_resource_definition)
{
	{
		unsigned long resource_definition_count = resource_definitions_chunk->entry_count;
		s_tag_persist_resource_definition* resource_definitions = resource_definitions_chunk->entries;
		for (unsigned long resource_definition_index = 0; resource_definition_index < resource_definition_count; resource_definition_index++)
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

	unsigned long resource_definition_index = resource_definitions_chunk->entry_count;
	resource_definitions_chunk->append_data(&resource_definition, sizeof(resource_definition));

	return resource_definition_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_interop_definition(const blofeld::s_tag_interop_definition& tag_interop_definition)
{
	{
		unsigned long interop_definition_count = interop_definitions_chunk->entry_count;
		s_tag_persist_interop_definition* interop_definitions = interop_definitions_chunk->entries;
		for (unsigned long interop_definition_index = 0; interop_definition_index < interop_definition_count; interop_definition_index++)
		{
			s_tag_persist_interop_definition& existing_interop_definition = interop_definitions[interop_definition_index];

			if (existing_interop_definition.persistent_identifier == tag_interop_definition.persistent_identifier)
			{
				return interop_definition_index;
			}
		}
	}

	s_tag_persist_interop_definition interop_definition;
	interop_definition.structure_entry_index = enqueue_struct_definition(tag_interop_definition.struct_definition);
	//interop_definition.string_character_index.offset = enqueue_string(tag_interop_definition.name);
	interop_definition.string_character_index.offset = enqueue_string("blah"); // oh bungie you silly goose
	interop_definition.persistent_identifier = tag_interop_definition.persistent_identifier;

	unsigned long interop_definition_index = interop_definitions_chunk->entry_count;
	interop_definitions_chunk->append_data(&interop_definition, sizeof(interop_definition));

	return interop_definition_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_array_definition(const blofeld::s_tag_array_definition& tag_array_definition)
{
	{
		unsigned long array_definition_count = array_definitions_chunk->entry_count;
		s_tag_persist_array_definition* array_definitions = array_definitions_chunk->entries;
		for (unsigned long array_definition_index = 0; array_definition_index < array_definition_count; array_definition_index++)
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
	array_definition.count = tag_array_definition.count(engine_platform_build);
	array_definition.string_character_index.offset = enqueue_string(tag_array_definition.name);

	unsigned long array_definition_index = array_definitions_chunk->entry_count;
	array_definitions_chunk->append_data(&array_definition, sizeof(array_definition));

	return array_definition_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& tag_block_index_custom_search_definition)
{
	{
		unsigned long block_index_custom_search_definition_count = custom_block_index_search_names_chunk->entry_count;
		s_tag_persist_string_character_index* block_index_custom_search_definitions = custom_block_index_search_names_chunk->offsets;
		for (unsigned long block_index_custom_search_definition_index = 0; block_index_custom_search_definition_index < block_index_custom_search_definition_count; block_index_custom_search_definition_index++)
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

	unsigned long array_definition_index = custom_block_index_search_names_chunk->entry_count;
	custom_block_index_search_names_chunk->append_data(&block_index_custom_search_definition, sizeof(block_index_custom_search_definition));

	return array_definition_index;
}

unsigned long c_high_level_tag_file_writer::enqueue_string(const char* string)
{
	if (string == nullptr)
	{
		string = "";
	}

	BCS_RESULT rs = BCS_S_OK;

	unsigned long string_data_length = static_cast<unsigned long>(strlen(string) + 1);
	const void* existing_data = nullptr;
	unsigned long existing_data_size = 0;
	if (BCS_SUCCEEDED(rs = string_data_chunk->get_data(existing_data, existing_data_size)))
	{
		const char* existing_substring = (const char*)memmem(existing_data, existing_data_size, string, string_data_length);
		if (existing_substring)
		{
			unsigned long offset = static_cast<unsigned long>(existing_substring - static_cast<const char*>(existing_data));
			return offset;
		}
	}

	string_data_chunk->append_data(string, string_data_length);

	return existing_data_size;
}

void c_high_level_tag_file_writer::serialize_tag_group(const h_tag& tag, c_binary_data_chunk& parent_chunk)
{
	c_tag_block_chunk& tag_block_chunk = *new() c_tag_block_chunk(parent_chunk);
	parent_chunk.add_child(tag_block_chunk);

	const blofeld::s_tag_struct_definition& tag_struct_definition = tag.get_blofeld_struct_definition();

	s_tag_block_chunk_header& tag_block_chunk_header = tag_block_chunk.tag_block_chunk_header;
	tag_block_chunk_header.count = 1;
	tag_block_chunk_header.is_simple_data_type = !tag_struct_definition.runtime_flags.test(blofeld::_tag_field_set_unknown0_bit);

	tag_block_chunk.set_data(&tag_block_chunk_header, sizeof(tag_block_chunk_header));

	unsigned long structure_size = calculate_structure_size(tag_struct_definition);
	char* const structure_data = static_cast<char*>(tracked_malloc(structure_size));
	DEBUG_ONLY(memset(structure_data, 0xDD, structure_size));

	c_tag_struct_chunk* tag_struct_chunk = new() c_tag_struct_chunk(tag_block_chunk);
	tag_block_chunk.add_child(*tag_struct_chunk);

	serialize_tag_struct(tag, structure_data, tag_struct_chunk);

	tag_block_chunk.append_data(structure_data, structure_size);
	
}

void c_high_level_tag_file_writer::serialize_tag_block(const h_block& block, c_tag_struct_chunk& parent_chunk)
{
	unsigned long block_count = block.size();

	c_tag_block_chunk& tag_block_chunk = *new() c_tag_block_chunk(parent_chunk);
	parent_chunk.add_child(tag_block_chunk);

	const blofeld::s_tag_struct_definition& tag_struct_definition = block.get_tag_struct_definition();

	s_tag_block_chunk_header& tag_block_chunk_header = tag_block_chunk.tag_block_chunk_header;
	tag_block_chunk_header.count = block_count;
	tag_block_chunk_header.is_simple_data_type = !tag_struct_definition.runtime_flags.test(blofeld::_tag_field_set_unknown0_bit);

	tag_block_chunk.set_data(&tag_block_chunk_header, sizeof(tag_block_chunk_header));

	unsigned long structure_size = calculate_structure_size(tag_struct_definition);
	unsigned long block_data_size = structure_size * block_count;
	char* const block_data = static_cast<char*>(tracked_malloc(block_data_size));
	char* structure_data = block_data;

	for (unsigned long block_index = 0; block_index < block_count; block_index++, structure_data += structure_size)
	{
		DEBUG_ONLY(memset(structure_data, static_cast<char>(block_index + 0xDD), structure_size));
		const h_object& object = block[block_index];

		c_tag_struct_chunk* tag_struct_chunk = nullptr;
		if (!tag_block_chunk_header.is_simple_data_type)
		{
			tag_struct_chunk = new() c_tag_struct_chunk(tag_block_chunk);
			tag_block_chunk.add_child(*tag_struct_chunk);
		}

		serialize_tag_struct(object, structure_data, tag_struct_chunk);

		
	}

	tag_block_chunk.append_data(block_data, block_data_size);
}

void c_high_level_tag_file_writer::serialize_tag_struct(const h_object& object, char* const structure_data, c_tag_struct_chunk* tag_struct_chunk)
{
	char* dst_field_data = structure_data;
	unsigned long field_index = 0;
	for (const blofeld::s_tag_field* const* field_pointer = object.get_blofeld_field_list(); *field_pointer != nullptr; field_pointer++, field_index++)
	{
		const blofeld::s_tag_field& field = **field_pointer;

		const void* src_field_data = object.get_field_data(field);
		blofeld::e_field field_type = field.field_type;
		unsigned long field_size = ULONG_MAX;
		ASSERT(BCS_SUCCEEDED(blofeld::get_blofeld_tag_file_field_size(field_type, engine_platform_build, field_size)));

		switch (field.field_type)
		{
		case blofeld::_field_struct:
		{
			const h_object& object = *static_cast<const h_object*>(src_field_data);

			const blofeld::s_tag_struct_definition& struct_definition = *field.struct_definition;
			field_size = calculate_structure_size(struct_definition);

			ASSERT(tag_struct_chunk != nullptr);
			c_tag_struct_chunk* _tag_struct_chunk = new() c_tag_struct_chunk(*static_cast<c_chunk*>(tag_struct_chunk));
			tag_struct_chunk->add_child(*_tag_struct_chunk);

			serialize_tag_struct(object, dst_field_data, _tag_struct_chunk);

			
		}
		break;
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *field.array_definition;
			unsigned long structure_size = calculate_structure_size(array_definition.struct_definition);
			field_size = structure_size * array_definition.count(engine_platform_build);
		}
		break;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = field.padding;
			field_size = pad_size;
			memset(dst_field_data, 0, field_size);
		}
		break;
		case blofeld::_field_block:
		{
			const h_block& block = *static_cast<const h_block*>(src_field_data);
			ASSERT(tag_struct_chunk != nullptr);
			serialize_tag_block(block, *tag_struct_chunk);

			s_tag_block* tag_block = reinterpret_cast<s_tag_block*>(dst_field_data);
			DEBUG_ONLY(memset(tag_block, 0xBB, sizeof(*tag_block)));

			tag_block->count = block.size();
			tag_block->address = 0;
			tag_block->definition_address = 0;

			
		}
		break;
		case blofeld::_field_data:
		{
			const h_data& data = *static_cast<const h_data*>(src_field_data);
			ASSERT(tag_struct_chunk != nullptr);
			serialize_tag_data(data, *tag_struct_chunk);

			s_tag_data* tag_data = reinterpret_cast<s_tag_data*>(dst_field_data);
			DEBUG_ONLY(memset(tag_data, 0xCC, sizeof(*tag_data)));

			tag_data->size = static_cast<long>(data.size());
			tag_data->stream_flags = 0; // unused
			tag_data->stream_offset = 0; // unused
			tag_data->address = 0;
			tag_data->definition = 0; // unused
		}
		break;
		case blofeld::_field_old_string_id:
		case blofeld::_field_string_id:
		{
			const h_string_id& string_id = *static_cast<const h_string_id*>(src_field_data);
			ASSERT(tag_struct_chunk != nullptr);
			serialize_string_id(string_id, *tag_struct_chunk);
			memset(dst_field_data, 0, field_size);
		}
		break;
		case blofeld::_field_pageable:
		{
			const h_resource* const& resource = *static_cast<const h_resource* const*>(src_field_data);

			ASSERT(tag_struct_chunk != nullptr);
			ASSERT(field.tag_resource_definition != nullptr);

			serialize_tag_resource(resource, *field.tag_resource_definition, *tag_struct_chunk);

			memset(dst_field_data, 0, field_size);

			if (resource != nullptr)
			{
				s_tag_resource* tag_resource = reinterpret_cast<s_tag_resource*>(dst_field_data);
				tag_resource->resource_handle = 0;

				
			}
		}
		break;
		case blofeld::_field_api_interop:
		case blofeld::_field_tag_reference:
			throw; // not implemented
			break;
		default:
		{
			memcpy(dst_field_data, src_field_data, field_size);
		}
		break;
		}

		ASSERT(field_size != ULONG_MAX);
		dst_field_data += field_size;
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
	//if (resource != nullptr)
	if(const c_simple_resource_container* simple_resource_container = dynamic_cast<const c_simple_resource_container*>(resource))
	{
		c_tag_resource_exploded_chunk* tag_resource_exploded_chunk = new() c_tag_resource_exploded_chunk(parent_chunk);
		c_tag_resource_data_chunk* tag_resource_data_chunk = new() c_tag_resource_data_chunk(*tag_resource_exploded_chunk);
		c_tag_struct_chunk* tag_struct_chunk = new() c_tag_struct_chunk(*tag_resource_exploded_chunk);

		h_object* object = h_object::create_high_level_object(tag_resource_definition.struct_definition, engine_platform_build);
		if (blofeld::halo3::h_sound_resource_definition_struct* sound_resource_definition_struct = dynamic_cast<decltype(sound_resource_definition_struct)>(object))
		{
			sound_resource_definition_struct->sample_data.insert(
				sound_resource_definition_struct->sample_data.begin(), 
				static_cast<const char*>(simple_resource_container->data.data()), 
				static_cast<const char*>(simple_resource_container->data.data()) + simple_resource_container->data.size());
		}
		else 
		{
			throw; // not implemented
		}

		unsigned long structure_size = calculate_structure_size(tag_resource_definition.struct_definition);
		char* const structure_data = static_cast<char*>(tracked_malloc(structure_size));
		DEBUG_ONLY(memset(structure_data, 0xDD, structure_size));

		serialize_tag_struct(*object, structure_data, tag_struct_chunk);

		tag_resource_data_chunk->set_data(structure_data, structure_size);

		tag_resource_exploded_chunk->add_child(*tag_resource_data_chunk);
		tag_resource_exploded_chunk->add_child(*tag_struct_chunk);
		parent_chunk.add_child(*tag_resource_exploded_chunk);
	}
	else
	{
		c_tag_resource_null_chunk* tag_resource_null_chunk = new() c_tag_resource_null_chunk(parent_chunk);
		parent_chunk.add_child(*tag_resource_null_chunk);
	}
}

void c_high_level_tag_file_writer::serialize_string_id(const h_string_id& string_id, c_tag_struct_chunk& parent_chunk)
{
	c_tag_string_id_chunk& tag_string_id_chunk = *new() c_tag_string_id_chunk(parent_chunk);
	parent_chunk.add_child(tag_string_id_chunk);

	tag_string_id_chunk.set_string(string_id.c_str());

	
}

unsigned long c_high_level_tag_file_writer::calculate_structure_size(const h_object& object)
{
	unsigned long structure_size = 0;
	for (const blofeld::s_tag_field* const* field_pointer = object.get_blofeld_field_list(); *field_pointer != nullptr; field_pointer++)
	{
		const blofeld::s_tag_field* current_field = *field_pointer;

		unsigned long field_size = ULONG_MAX;
		blofeld::e_field field_type = current_field->field_type;

		switch (field_type)
		{
		case blofeld::_field_struct:
		{
			const blofeld::s_tag_struct_definition& struct_definition = *current_field->struct_definition;
			field_size = calculate_structure_size(struct_definition);
		}
		break;
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *current_field->array_definition;
			unsigned long structure_size = calculate_structure_size(array_definition.struct_definition);
			field_size = structure_size * array_definition.count(engine_platform_build);
		}
		break;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = current_field->padding;
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

unsigned long c_high_level_tag_file_writer::calculate_structure_size(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	unsigned long structure_size = 0;
	for (const blofeld::s_tag_field* current_field = tag_struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		unsigned long field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		unsigned long field_size = ULONG_MAX;
		blofeld::e_field field_type = current_field->field_type;

		switch (field_type)
		{
		case blofeld::_field_struct:
		{
			const blofeld::s_tag_struct_definition& struct_definition = *current_field->struct_definition;
			field_size = calculate_structure_size(struct_definition);
		}
		break;
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition& array_definition = *current_field->array_definition;
			unsigned long structure_size = calculate_structure_size(array_definition.struct_definition);
			field_size = structure_size * array_definition.count(engine_platform_build);
		}
		break;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = current_field->padding;
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



