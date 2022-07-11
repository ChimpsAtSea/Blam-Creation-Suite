#include "mandrilllib-private-pch.h"

#define make_64bit_persistent_id(persistent_identifier) (reinterpret_cast<const long long*>(&persistent_identifier)[0] ^ reinterpret_cast<const long long*>(&persistent_identifier)[1])

c_single_tag_file_reader::c_single_tag_file_reader(
	s_single_tag_file_header& header,
	s_engine_platform_build engine_platform_build,
	bool is_big_endian,
	c_single_tag_file_layout_reader& layout_reader,
	c_binary_data_chunk& binary_data_chunk,
	c_monolithic_partition_view* tag_partition_view,
	c_monolithic_partition_view* resource_partition_view) :
	header(header),
	layout_reader(layout_reader),
	binary_data_chunk(binary_data_chunk),
	is_big_endian(is_big_endian),
	metadata_stack(),
	tag_struct_definitions(),
	struct_entries_data(nullptr),
	structure_entries_data_count(0),
	tag_struct_definitions_lookup_table(),
	engine_platform_build(engine_platform_build),
	tag_structs_view(tag_structs_view_wrapper),
	tag_structs_view_wrapper(),
	blofeld_tag_group(),
	blofeld_tag_block_definition(),
	blofeld_tag_group_struct_definition(),
	tag_partition_view(tag_partition_view),
	resource_partition_view(resource_partition_view)
{
	unsigned long tag_group_block_index = layout_reader.tag_group_layout_chunk->get_tag_group_block_index();
	t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
	metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_block;
	metadata_entry.id = tag_group_block_index;



	binary_data_chunk.read_child_chunks(this, true);
	//binary_data_chunk.parse_children(this);

	blofeld_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, header.group_tag);
	ASSERT(blofeld_tag_group != nullptr);
	blofeld_tag_block_definition = &blofeld_tag_group->block_definition;
	blofeld_tag_group_struct_definition = &blofeld_tag_block_definition->struct_definition;

	////const s_tag_persist_block_definition* root_block_definition_entry = layout_reader.block_definitions_chunk->entries + tag_group_block_index;
	////const char* root_block_definition_name = layout_reader.get_string_by_string_character_index(root_block_definition_entry->string_character_index;
	//const s_tag_persist_block_definition& root_block_definition_entry = layout_reader.get_block_definition_by_index(tag_group_block_index);
	//const char* root_block_definition_name = layout_reader.get_string_by_string_character_index(root_block_definition_entry.string_character_index);
	//ASSERT(strcmp(root_block_definition_name, blofeld_tag_block_definition->name) == 0); // sanity check
	////const s_tag_persist_struct_definition* root_structure_definition_entry = layout_reader.structure_definitions_chunk->entries + root_block_definition_entry->structure_entry_index;
	//const s_tag_persist_struct_definition& root_structure_definition_entry = layout_reader.get_struct_definition_by_index(root_block_definition_entry.structure_entry_index);
	//ASSERT(root_structure_definition_entry.persistent_identifier == blofeld_tag_group->block_definition.struct_definition.persistent_identifier); // sanity check
	////const char* root_struct_definition_name = layout_reader.get_string_by_string_character_index(root_structure_definition_entry->string_character_index;
	//const char* root_struct_definition_name = layout_reader.get_string_by_string_character_index(root_structure_definition_entry.string_character_index);
	//ASSERT(strcmp(root_struct_definition_name, blofeld_tag_group_struct_definition->name) == 0); // sanity check

	new(&tag_structs_view) c_tag_struct_definition_view(engine_platform_build, blofeld_tag_group);
	tag_struct_definitions = tag_structs_view.get_tag_struct_definitions();
	ASSERT(tag_struct_definitions != nullptr);

	//struct_entries_data = new() s_single_tag_file_reader_structure_entry[layout_reader.tag_group_layout_chunk->get_struct_definition_count()];


	for (const blofeld::s_tag_struct_definition** struct_definition_iter = tag_struct_definitions; *struct_definition_iter; struct_definition_iter++)
	{
		const blofeld::s_tag_struct_definition& struct_definition = **struct_definition_iter;
		long long _64bit_id = make_64bit_persistent_id(struct_definition.persistent_identifier);
		tag_struct_definitions_lookup_table.enqueue(&_64bit_id, sizeof(_64bit_id), &struct_definition);
	}

	unsigned long struct_definition_count = layout_reader.tag_group_layout_chunk->get_struct_definition_count();
	ASSERT(struct_definition_count > 0);
	struct_entries_data = new s_single_tag_file_reader_structure_entry[struct_definition_count];
	structure_entries_data_count = struct_definition_count;

	unsigned long blofeld_structure_count = tag_structs_view.get_num_tag_struct_definitions();
	unsigned long tag_file_structure_count = layout_reader.structure_definitions_chunk->entry_count;
	ASSERT(blofeld_structure_count >= tag_file_structure_count);



	for (unsigned long structure_entry_index = 0; structure_entry_index < layout_reader.tag_group_layout_chunk->get_struct_definition_count(); structure_entry_index++)
	{
		s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];
		const s_tag_persist_struct_definition& structure_entry = layout_reader.get_struct_definition_by_index(structure_entry_index);

		//const char* structure_name = layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);

		const blofeld::s_tag_struct_definition* struct_definition = nullptr;

		if (BCS_SUCCEEDED(get_tag_struct_definition_by_persistent_identifier(structure_entry.persistent_identifier, struct_definition)))
		{
			reader_structure_entry.tag_struct_definition = struct_definition;
			reader_structure_entry.struct_definition_entry = &structure_entry;
			reader_structure_entry.persistent_identifier = structure_entry.persistent_identifier;
		}
		else if (structure_entry_index == 0 && layout_reader.tag_layout_prechunk_chunk != nullptr)
		{
			const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag({ _engine_type_halo3 }, header.group_tag);
			struct_definition = &tag_group->block_definition.struct_definition;
		}

		if (struct_definition != nullptr)
		{
			reader_structure_entry.tag_struct_definition = struct_definition;
			reader_structure_entry.struct_definition_entry = &structure_entry;
			reader_structure_entry.persistent_identifier = structure_entry.persistent_identifier;
		}
		else
		{
			memset(&reader_structure_entry, 0, sizeof(reader_structure_entry));
		}

	}

	for (unsigned long structure_entry_index = 0; structure_entry_index < layout_reader.tag_group_layout_chunk->get_struct_definition_count(); structure_entry_index++)
	{
		s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];
		const s_tag_persist_struct_definition& structure_entry = layout_reader.get_struct_definition_by_index(structure_entry_index);

		unsigned long last_blofeld_field_index = 0;
		unsigned long next_blofeld_field_index = 0;

		if (console_is_verbose())
		{
			const char* structure_name = layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);
			console_write_line_verbose("Prematching '%s' -> '%s'", structure_name, reader_structure_entry.tag_struct_definition->name);
		}

		reader_structure_entry.transpose_entries.reserve(256);
		for (unsigned long file_field_index = structure_entry.fields_start_index; ; file_field_index++)
		{
			s_blofeld_field_transpose_entry& transpose_entry = reader_structure_entry.transpose_entries.emplace_back();

			const s_tag_persist_field& file_field = layout_reader.get_field_by_index(file_field_index);
			const s_tag_persist_field_type& file_field_type = layout_reader.get_field_type_by_index(file_field.field_type_index);
			blofeld::e_field file_blofeld_field_type = layout_reader.get_blofeld_type_by_field_type_index(file_field.field_type_index);

			const char* file_field_name = layout_reader.get_string_by_string_character_index(file_field.string_character_index);
			//const char* file_field_type_name = layout_reader.get_string_by_string_character_index(file_field_type.string_character_index);

			transpose_entry.field_size = file_field_type.size;
			transpose_entry.blofeld_field_index = ULONG_MAX;
			transpose_entry.field_index = file_field_index;
			transpose_entry.can_transpose = false;
			transpose_entry.has_child_chunk = file_field_type.has_child_chunk;
			transpose_entry.field_metadata = file_field.metadata;
			transpose_entry.field_type = file_blofeld_field_type;
			transpose_entry.blofeld_tag_field = nullptr;
			//transpose_entry.tag_persist_field = &file_field;
			//transpose_entry.tag_persist_field_type = &file_field_type;
			//transpose_entry.tag_persist_field_name = file_field_name;
			//transpose_entry.tag_persist_field_type_name = file_field_type_name;

			if (file_blofeld_field_type == blofeld::_field_terminator)
			{
				break;
			}
			else switch (file_blofeld_field_type)
			{
			case blofeld::_field_custom:
			case blofeld::_field_explanation:
				continue;
			}

			const blofeld::s_tag_field* blofeld_field = nullptr;
			if (reader_structure_entry.tag_struct_definition)
			{
				for (unsigned long blofeld_field_index = next_blofeld_field_index; ; blofeld_field_index++)
				{
					const blofeld::s_tag_field& candidate_blofeld_field = reader_structure_entry.tag_struct_definition->fields[blofeld_field_index];

					if (candidate_blofeld_field.field_type == blofeld::_field_version)
					{

					}

					unsigned long field_skip_count;
					if (blofeld::execute_tag_field_versioning(candidate_blofeld_field, engine_platform_build, blofeld_tag_group->group_tag, tag_field_version_max, field_skip_count))
					{
						blofeld_field_index += field_skip_count;
						continue;
					}

					if (candidate_blofeld_field.field_type == blofeld::_field_terminator)
					{
						break;
					}
					else switch (candidate_blofeld_field.field_type)
					{
					case blofeld::_field_custom:
					case blofeld::_field_explanation:
					case blofeld::_field_useless_pad:
						continue;
					case blofeld::_field_version:
						throw;
					}

					if (strcmp(file_field_name, candidate_blofeld_field.name) == 0)
					{
						blofeld_field = &candidate_blofeld_field;
						last_blofeld_field_index = blofeld_field_index;
						next_blofeld_field_index = blofeld_field_index + 1;
					}
					else
					{
						for (const char** alt_name_iter = candidate_blofeld_field.old_names; alt_name_iter && *alt_name_iter; alt_name_iter++)
						{
							const char* alt_name = *alt_name_iter;

							if (strcmp(file_field_name, alt_name) == 0)
							{
								blofeld_field = &candidate_blofeld_field;
								last_blofeld_field_index = blofeld_field_index;
								next_blofeld_field_index = blofeld_field_index + 1;
								break;
							}
						}
					}

					if (blofeld_field == nullptr)
					{
						console_write_line_verbose("\tWARN> Failed to find blofeld field '%s' inside of file definition. Default will be used.", candidate_blofeld_field.name);
					}
					else break;
				}
			}
			if (blofeld_field == nullptr)
			{
				console_write_line_verbose("ERROR> Failed to find file field '%s' inside of blofeld definition. Data will be discarded.", file_field_name);
			}
			else
			{
				transpose_entry.can_transpose = true;
				transpose_entry.blofeld_field_index = last_blofeld_field_index;
				transpose_entry.blofeld_tag_field = blofeld_field;

				const char* blofeld_field_type_name;
				ASSERT(BCS_SUCCEEDED(blofeld::field_to_tagfile_field_type(blofeld_field->field_type, blofeld_field_type_name)));
				console_write_line_verbose("\tSuccessfully matched t[%s] b[%s] f[%s]", blofeld_field_type_name, blofeld_field->name, file_field_name);
			}
		}
	}
}

c_single_tag_file_reader::~c_single_tag_file_reader()
{
	delete[] struct_entries_data;
}

BCS_RESULT c_single_tag_file_reader::get_tag_struct_definition_by_persistent_identifier(const blofeld::s_tag_persistent_identifier& persistent_identifier, const blofeld::s_tag_struct_definition*& struct_definition) const
{
	long long _64bit_id = make_64bit_persistent_id(persistent_identifier);
	bool success = tag_struct_definitions_lookup_table.fetch(&_64bit_id, sizeof(_64bit_id), struct_definition);
	if (!success) [[unlikely]]
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

const blofeld::s_tag_struct_definition& c_single_tag_file_reader::get_tag_struct_definition_by_index(unsigned long index) const
{
	ASSERT(index < structure_entries_data_count);
	const s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[index];
	ASSERT(reader_structure_entry.tag_struct_definition != nullptr);
	return *reader_structure_entry.tag_struct_definition;
}

BCS_RESULT c_single_tag_file_reader::read_tag_struct_to_high_level_object_ref(
	h_prototype& high_level_object,
	unsigned long structure_entry_index,
	s_tag_persist_struct_definition& structure_entry,
	const char* const structure_data_begin,
	c_tag_struct_chunk* structure_chunk)
{
	const char* structure_data_position = structure_data_begin;
	unsigned long structure_chunk_child_index = 0;

	s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];

	for (s_blofeld_field_transpose_entry& transpose : reader_structure_entry.transpose_entries)
	{
		unsigned long field_size = transpose.field_size;
		if (transpose.has_child_chunk)
		{
			c_chunk* source_chunk = nullptr;
			ASSERT(structure_chunk != nullptr);

			void* high_level_field_data;
			if (transpose.can_transpose)
			{
				const blofeld::s_tag_field& blofeld_field = *transpose.blofeld_tag_field;
				high_level_field_data = high_level_object.get_field_data_unsafe(blofeld_field);
			}

			switch (transpose.field_type)
			{
			case blofeld::_field_block:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_block_chunk* field_tag_block_chunk = dynamic_cast<c_tag_block_chunk*>(field_chunk);
				ASSERT(field_tag_block_chunk != nullptr);

				if (transpose.can_transpose)
				{
					h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);

					unsigned long block_count = field_tag_block_chunk->tag_block_chunk_header.count;
					block_storage.reserve(block_count);
					for (unsigned long block_index = 0; block_index < block_count; block_index++)
					{
						h_prototype& high_level_object = block_storage.emplace_back();
						BCS_RESULT rs = read_tag_block_structure_to_high_level_object(*field_tag_block_chunk, block_index, high_level_object);
						ASSERT(BCS_SUCCEEDED(rs));


					}
				}
			}
			break;
			case blofeld::_field_struct:
			{
				unsigned long expected_children = layout_reader.get_structure_expected_children_by_index(transpose.field_metadata);

				c_tag_struct_chunk* field_tag_struct_chunk;
				unsigned long num_children;
				do
				{
					field_tag_struct_chunk = structure_chunk->get_child_unsafe<c_tag_struct_chunk>(structure_chunk_child_index++);
					num_children = field_tag_struct_chunk->num_children;
					if (num_children < expected_children && num_children == 0)
					{
						field_tag_struct_chunk = nullptr; // skip over to the next struct definition

					}
				} while (field_tag_struct_chunk == nullptr && structure_chunk->get_child_unsafe(structure_chunk_child_index));
				ASSERT(field_tag_struct_chunk != nullptr);
				ASSERT(num_children >= expected_children);

				if (transpose.can_transpose)
				{
					h_prototype& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);

					s_tag_persist_struct_definition& field_struct_entry = layout_reader.get_struct_definition_by_index(transpose.field_metadata);

					unsigned long structure_size = layout_reader.get_structure_size_by_index(transpose.field_metadata);
					field_size = structure_size;

					read_tag_struct_to_high_level_object_ref(struct_storage, transpose.field_metadata, field_struct_entry, structure_data_position, field_tag_struct_chunk);

				}
			}
			break;
			case blofeld::_field_tag_reference:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_reference_chunk* field_tag_reference_chunk = dynamic_cast<c_tag_reference_chunk*>(field_chunk);
				ASSERT(field_tag_reference_chunk != nullptr);

				if (transpose.can_transpose)
				{
					const blofeld::s_tag_field& blofeld_field = *transpose.blofeld_tag_field;
					h_tag_reference* tag_reference_storage = high_level_object.get_field_data<h_tag_reference>(blofeld_field);
					ASSERT(tag_reference_storage != nullptr);

					field_tag_reference_chunk->group_tag;
					field_tag_reference_chunk->tag_filepath_without_extension;

					if (field_tag_reference_chunk->group_tag == blofeld::INVALID_TAG)
					{
						tag_reference_storage->clear();
					}
					else
					{
						const blofeld::s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, field_tag_reference_chunk->group_tag);
						if (tag_group != nullptr)
						{
							c_fixed_string_512 tag_filepath;
							tag_filepath.format("%s.%s", field_tag_reference_chunk->tag_filepath_without_extension, tag_group->name);
							tag_reference_storage->set_unqualified_path(
								field_tag_reference_chunk->group_tag,
								tag_filepath);
						}
						else
						{
							tag_reference_storage->set_unqualified_path(
								field_tag_reference_chunk->group_tag,
								field_tag_reference_chunk->tag_filepath_without_extension);
						}
					}
				}
			}
			break;
			case blofeld::_field_old_string_id:
			case blofeld::_field_string_id:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_string_id_chunk* field_tag_string_id_chunk = dynamic_cast<c_tag_string_id_chunk*>(field_chunk);
				ASSERT(field_tag_string_id_chunk != nullptr);

				if (transpose.can_transpose)
				{
					h_string_id& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);
					string_id_storage = field_tag_string_id_chunk->string;
				}
			}
			break;
			case blofeld::_field_data:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_data_chunk* field_tag_data_chunk = dynamic_cast<c_tag_data_chunk*>(field_chunk);
				ASSERT(field_tag_data_chunk != nullptr);

				if (transpose.can_transpose)
				{
					// #TODO: is it worth abstracting this like resources?

					h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);
					const char* data_chunk_data_start = field_tag_data_chunk->get_chunk_data_start();
					const char* data_chunk_data_end = field_tag_data_chunk->get_chunk_data_end();
					data_storage.insert(data_storage.begin(), data_chunk_data_start, data_chunk_data_end);
				}
			}
			break;
			case blofeld::_field_pageable_resource:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_resource_exploded_chunk* resource_exploded_chunk = dynamic_cast<c_tag_resource_exploded_chunk*>(field_chunk);
				c_tag_resource_xsynced_chunk* resource_xsynced_chunk = dynamic_cast<c_tag_resource_xsynced_chunk*>(field_chunk);
				c_tag_resource_null_chunk* resource_null_chunk = dynamic_cast<c_tag_resource_null_chunk*>(field_chunk);
				ASSERT(resource_exploded_chunk != nullptr || resource_xsynced_chunk != nullptr || resource_null_chunk != nullptr);

				if (transpose.can_transpose)
				{
					h_resource*& tag_resource_storage = *reinterpret_cast<decltype(&tag_resource_storage)>(high_level_field_data);
					const s_tag_resource& tag_resource = *reinterpret_cast<const s_tag_resource*>(structure_data_position);

					if (resource_exploded_chunk != nullptr)
					{
						c_tag_resource_data_chunk* data_chunk = resource_exploded_chunk->get_child_unsafe<c_tag_resource_data_chunk>(0);
						c_tag_struct_chunk* struct_chunk = resource_exploded_chunk->get_child_unsafe<c_tag_struct_chunk>(1);

						const void* data;
						unsigned long data_size;
						data_chunk->get_data(data, data_size);

						tag_resource_storage = nullptr;

					}
					else if (resource_xsynced_chunk != nullptr)
					{
						if (resource_partition_view != nullptr)
						{
							c_monolithic_resource_handle* resource_handle = new() c_monolithic_resource_handle(*resource_partition_view, resource_xsynced_chunk->resource_xsync_state_v2);
							tag_resource_storage = resource_handle;
						}
						else
						{
							ASSERT(resource_xsynced_chunk->resource_xsync_state_v2.cache_location_size == 0);
						}

						//c_simple_resource_container* simple_resource_container = new() c_simple_resource_container();
						//tag_resource_storage = simple_resource_container;

						//if (resource_xsynced_chunk->resource_xsync_state_v2.cache_location_size > 0)
						//{
						//	const char* resource_data_start = monolithic_resource_data + resource_xsynced_chunk->resource_xsync_state_v2.cache_location_offset;
						//	const char* resource_data_end = resource_data_start + resource_xsynced_chunk->resource_xsync_state_v2.cache_location_size;

						//	simple_resource_container->data.insert(simple_resource_container->data.end(), resource_data_start, resource_data_end);
						//}
					}
					else if (resource_null_chunk != nullptr)
					{
						tag_resource_storage = nullptr;
					}
					else
					{
						FATAL_ERROR("Unknown pageable resource type");
					}
				}
			}
			break;
			}
		}
		else if (transpose.can_transpose)
		{
			const blofeld::s_tag_field& blofeld_field = *transpose.blofeld_tag_field;
			void* high_level_field_data = high_level_object.get_field_data_unsafe(blofeld_field);

			switch (blofeld_field.field_type)
			{
			case blofeld::_field_pad:
			{
				unsigned long pad_size = transpose.field_metadata;
				ASSERT(pad_size == blofeld_field.padding);
				field_size = pad_size;
			}
			break;
			case blofeld::_field_array:
			{
				s_tag_persist_array_definition& array_entry = layout_reader.get_array_definition_by_index(transpose.field_metadata);
				unsigned long array_structure_size = layout_reader.get_structure_size_by_index(array_entry.structure_entry_index);
				unsigned long array_size = array_structure_size * array_entry.count;
				field_size = array_size;
			}
			break;
			default:
			{
				memcpy(high_level_field_data, structure_data_position, field_size);
				if (is_big_endian)
				{
					blofeld::byteswap_field_data_inplace(blofeld_field.field_type, high_level_field_data, engine_platform_build);
				}
			}
			break;
			}
		}

		structure_data_position += field_size;

	}
	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::read_tag_block_structure_to_high_level_object(
	c_tag_block_chunk& tag_block_chunk,
	unsigned long tag_block_index,
	h_prototype& high_level_object)
{
	ASSERT(tag_block_index < tag_block_chunk.tag_block_chunk_header.count);


	const char* structure_data_begin = tag_block_chunk.get_sturcutre_data_by_index(tag_block_index);
	c_tag_struct_chunk* structure_chunk = tag_block_chunk.get_sturcutre_chunk_by_index(tag_block_index);

	read_tag_struct_to_high_level_object_ref(
		high_level_object,
		tag_block_chunk.block_entry->structure_entry_index,
		*tag_block_chunk.structure_entry,
		structure_data_begin,
		structure_chunk);

	return BCS_S_OK;
}

BCS_RESULT c_single_tag_file_reader::parse_high_level_object(h_tag*& out_high_level_tag)
{
	c_tag_block_chunk* tag_group_block_chunk = binary_data_chunk.get_child_by_type_unsafe<c_tag_block_chunk>();
	ASSERT(tag_group_block_chunk != nullptr);
	ASSERT(tag_group_block_chunk->tag_block_chunk_header.count == 1);
	ASSERT(blofeld_tag_group_struct_definition->persistent_identifier == tag_group_block_chunk->structure_entry->persistent_identifier);

	tag_group_block_chunk->log();

	const blofeld::s_tag_struct_definition& blofeld_struct_definition = get_tag_struct_definition_by_index(tag_group_block_chunk->structure_index);
	h_prototype* high_level_object = h_prototype::create_high_level_object(blofeld_struct_definition, engine_platform_build);
	ASSERT(high_level_object != nullptr);

	read_tag_block_structure_to_high_level_object(*tag_group_block_chunk, 0, *high_level_object);

	h_tag* high_level_tag = dynamic_cast<h_tag*>(high_level_object);
	ASSERT(high_level_tag != nullptr);



	out_high_level_tag = high_level_tag;
	return BCS_S_OK;
}