#include "mandrilllib-private-pch.h"

c_high_level_tag_file_reader::c_high_level_tag_file_reader(
	s_engine_platform_build engine_platform_build,
	const void* tag_file_data,
	c_monolithic_partition_view* tag_partition_view,
	c_monolithic_partition_view* resource_partition_view) :
	c_tag_file_reader(tag_file_data, tag_partition_view, resource_partition_view),
	blofeld_tag_group(nullptr),
	blofeld_tag_block_definition(nullptr),
	blofeld_tag_group_struct_definition(nullptr),
	engine_platform_build(engine_platform_build),
	tag_struct_definitions(nullptr),
	struct_entries_data(),
	structure_entries_data_count(),
	tag_structs_view(tag_structs_view_wrapper),
	tag_structs_view_wrapper()
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_group_by_engine_platform_build(engine_platform_build, header.group_tag, blofeld_tag_group)))
	{
		throw rs;
	}
	blofeld_tag_block_definition = &blofeld_tag_group->block_definition;
	blofeld_tag_group_struct_definition = &blofeld_tag_block_definition->struct_definition;

	new(&tag_structs_view) blofeld::c_tag_struct_definition_view(engine_platform_build, blofeld_tag_group);
	tag_struct_definitions = tag_structs_view.get_tag_struct_definitions();
	ASSERT(tag_struct_definitions != nullptr);

	uint32_t struct_definition_count = tag_group_layout_chunk->get_struct_definition_count();
	ASSERT(struct_definition_count > 0);
	struct_entries_data = new s_single_tag_file_reader_structure_entry[struct_definition_count];
	structure_entries_data_count = struct_definition_count;

	for (uint32_t structure_entry_index = 0; structure_entry_index < tag_group_layout_chunk->get_struct_definition_count(); structure_entry_index++)
	{
		s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];
		const s_tag_persist_struct_definition& structure_entry = get_struct_definition_by_index(structure_entry_index);

		const blofeld::s_tag_struct_definition* struct_definition = nullptr;

		blofeld::s_tag_persistent_identifier persistent_identifier;
		persistent_identifier.identifier_part_0 = structure_entry.unique_identifier.identifier_part_0;
		persistent_identifier.identifier_part_1 = structure_entry.unique_identifier.identifier_part_1;
		persistent_identifier.identifier_part_2 = structure_entry.unique_identifier.identifier_part_2;
		persistent_identifier.identifier_part_3 = structure_entry.unique_identifier.identifier_part_3;
		if (BCS_SUCCEEDED(get_tag_struct_definition_by_persistent_identifier(persistent_identifier, struct_definition)))
		{
			reader_structure_entry.tag_struct_definition = struct_definition;
			reader_structure_entry.struct_definition_entry = &structure_entry;
			reader_structure_entry.persistent_identifier = persistent_identifier;
		}
		else
		{
			const char* structure_name = get_string_by_string_character_index(structure_entry.string_character_index);

			console_write_line(
				"Failed to find structure '%s' [0x%08X 0x%08X 0x%08X 0x%08X]",
				structure_name,
				structure_entry.unique_identifier.identifier_part_0,
				structure_entry.unique_identifier.identifier_part_1,
				structure_entry.unique_identifier.identifier_part_2,
				structure_entry.unique_identifier.identifier_part_3);

			throw BCS_E_UNSUPPORTED;
		}
	}

	for (uint32_t structure_entry_index = 0; structure_entry_index < tag_group_layout_chunk->get_struct_definition_count(); structure_entry_index++)
	{
		s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];
		const s_tag_persist_struct_definition& structure_entry = get_struct_definition_by_index(structure_entry_index);

		uint32_t last_blofeld_field_index = 0;
		uint32_t next_blofeld_field_index = 0;

		if (console_is_verbose())
		{
			const char* structure_name = get_string_by_string_character_index(structure_entry.string_character_index);
			console_write_line_verbose("Prematching '%s' -> '%s'", structure_name, reader_structure_entry.tag_struct_definition->name);
		}

		reader_structure_entry.transpose_entries.reserve(256);
		for (uint32_t file_field_index = structure_entry.fields_start_index; ; file_field_index++)
		{
			s_blofeld_field_transpose_entry& transpose_entry = reader_structure_entry.transpose_entries.emplace_back();

			const s_tag_persist_field& file_field = get_field_by_index(file_field_index);
			const s_tag_persist_field_type& file_field_type = get_field_type_by_index(file_field.field_type_index);
			blofeld::e_field file_blofeld_field_type = get_blofeld_type_by_field_type_index(file_field.field_type_index);

			const char* file_field_name = get_string_by_string_character_index(file_field.string_character_index);
			//const char* file_field_type_name = get_string_by_string_character_index(file_field_type.string_character_index);

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

			blofeld::s_tag_field const* blofeld_field = nullptr;
			if (reader_structure_entry.tag_struct_definition)
			{
				for (uint32_t blofeld_field_index = next_blofeld_field_index; ; blofeld_field_index++)
				{
					blofeld::s_tag_field const& candidate_blofeld_field = reader_structure_entry.tag_struct_definition->fields[blofeld_field_index];

					if (candidate_blofeld_field.field_type == blofeld::_field_version)
					{

					}

					uint32_t field_skip_count;
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

c_high_level_tag_file_reader::~c_high_level_tag_file_reader()
{
	delete[] struct_entries_data;
}

BCS_RESULT c_high_level_tag_file_reader::get_tag_struct_definition_by_persistent_identifier(const blofeld::s_tag_persistent_identifier& persistent_identifier, const blofeld::s_tag_struct_definition*& struct_definition) const
{
	/*int64_t _64bit_id = make_64bit_persistent_id(persistent_identifier);
	bool success = tag_struct_definitions_lookup_table.fetch(&_64bit_id, sizeof(_64bit_id), struct_definition);
	if (!success) [[unlikely]]
	{
		for (const blofeld::s_tag_struct_definition** struct_definition_iter = tag_struct_definitions; *struct_definition_iter; struct_definition_iter++)
		{
			blofeld::s_tag_struct_definition const& current_struct_definition = **struct_definition_iter;
			if (current_struct_definition.persistent_identifier == persistent_identifier)
			{
				throw; // shouldn't reach here
			}
		}


		return BCS_E_FAIL;
	}
	return BCS_S_OK;*/

	for (const blofeld::s_tag_struct_definition** struct_definition_iter = tag_struct_definitions; *struct_definition_iter; struct_definition_iter++)
	{
		blofeld::s_tag_struct_definition const& current_struct_definition = **struct_definition_iter;
		if (current_struct_definition.persistent_identifier == persistent_identifier)
		{
			struct_definition = &current_struct_definition;
			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

blofeld::s_tag_struct_definition const& c_high_level_tag_file_reader::get_tag_struct_definition_by_index(uint32_t index) const
{
	ASSERT(index < structure_entries_data_count);
	const s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[index];
	ASSERT(reader_structure_entry.tag_struct_definition != nullptr);
	return *reader_structure_entry.tag_struct_definition;
}

BCS_RESULT c_high_level_tag_file_reader::read_tag_struct_to_high_level_object_ref(
	h_prototype& high_level_object,
	uint32_t structure_entry_index,
	s_tag_persist_struct_definition& structure_entry,
	const char* const structure_data_begin,
	c_tag_struct_chunk* structure_chunk)
{
	const char* structure_data_position = structure_data_begin;
	uint32_t structure_chunk_child_index = 0;

	s_single_tag_file_reader_structure_entry& reader_structure_entry = struct_entries_data[structure_entry_index];

	for (s_blofeld_field_transpose_entry& transpose : reader_structure_entry.transpose_entries)
	{
		uint32_t field_size = transpose.field_size;

		h_type* field_type = nullptr;
		if (transpose.can_transpose)
		{
			blofeld::s_tag_field const& blofeld_field = *transpose.blofeld_tag_field;
			ASSERT(transpose.serialization_info != nullptr);
			field_type = &(high_level_object.*transpose.serialization_info->pointer_to_member);
		}

		if (transpose.has_child_chunk)
		{
			c_chunk* source_chunk = nullptr;
			ASSERT(structure_chunk != nullptr);

			switch (transpose.field_type)
			{
			case blofeld::_field_block:
			{
				c_chunk* field_chunk = structure_chunk->get_child_unsafe(structure_chunk_child_index++);
				c_tag_block_chunk* field_tag_block_chunk = dynamic_cast<c_tag_block_chunk*>(field_chunk);
				ASSERT(field_tag_block_chunk != nullptr);

				if (transpose.can_transpose)
				{
					h_block* field_block = high_level_cast<h_block*>(field_type);
					ASSERT(field_block != nullptr);

					uint32_t block_count = field_tag_block_chunk->tag_block_chunk_header.count;
					field_block->clear();
					h_prototype** elements = field_block->create_elements(block_count);
					for (uint32_t block_index = 0; block_index < block_count; block_index++)
					{
						h_prototype& high_level_object = *elements[block_index];
						BCS_RESULT rs = read_tag_block_structure_to_high_level_object(*field_tag_block_chunk, block_index, high_level_object);
						ASSERT(BCS_SUCCEEDED(rs));


					}
				}
			}
			break;
			case blofeld::_field_struct:
			{
				uint32_t expected_children = get_structure_expected_children_by_index(transpose.field_metadata);

				c_tag_struct_chunk* field_tag_struct_chunk;
				uint32_t num_children;
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
					h_prototype* field_prototype = high_level_cast<h_prototype*>(field_type);
					ASSERT(field_prototype != nullptr);

					s_tag_persist_struct_definition& field_struct_entry = get_struct_definition_by_index(transpose.field_metadata);

					uint32_t structure_size = get_structure_size_by_index(transpose.field_metadata);
					field_size = structure_size;

					read_tag_struct_to_high_level_object_ref(*field_prototype, transpose.field_metadata, field_struct_entry, structure_data_position, field_tag_struct_chunk);

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
					blofeld::s_tag_field const& blofeld_field = *transpose.blofeld_tag_field;
					h_tag_reference* field_tag_reference = high_level_cast<h_tag_reference*>(field_type);
					ASSERT(field_tag_reference != nullptr);

					field_tag_reference_chunk->group_tag;
					field_tag_reference_chunk->tag_filepath_without_extension;

					if (field_tag_reference_chunk->group_tag == blofeld::INVALID_TAG)
					{
						field_tag_reference->clear();
					}
					else
					{
						field_tag_reference->set_unqualified_file_path_without_extension(
							field_tag_reference_chunk->group_tag,
							field_tag_reference_chunk->tag_filepath_without_extension);
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
					switch (transpose.blofeld_tag_field->field_type)
					{
					case blofeld::_field_old_string_id:
					case blofeld::_field_string_id:
					{
						h_string_id_field* field_string = high_level_cast<h_string_id_field*>(field_type);
						ASSERT(field_string != nullptr);

						field_string->set_string(field_tag_string_id_chunk->string);
					}
					break;
					case blofeld::_field_string:
					{
						h_typed_field<c_fixed_string_256>* field_string = high_level_cast<h_typed_field<c_fixed_string_256>*>(field_type);
						ASSERT(field_string != nullptr);
						c_fixed_string_32& string = *reinterpret_cast<c_fixed_string_32*>(field_string->get_data());

						string = field_tag_string_id_chunk->string;
					}
					break;
					case blofeld::_field_long_string:
					{
						h_typed_field<c_fixed_string_256>* field_string = high_level_cast<h_typed_field<c_fixed_string_256>*>(field_type);
						ASSERT(field_string != nullptr);
						c_fixed_string_256& string = *reinterpret_cast<c_fixed_string_256*>(field_string->get_data());

						string = field_tag_string_id_chunk->string;
					}
					break;
					}

					debug_point;
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

					h_data* field_data = high_level_cast<h_data*>(field_type);
					ASSERT(field_data != nullptr);

					const char* data_chunk_data_start = field_tag_data_chunk->get_chunk_data_start();
					const char* data_chunk_data_end = field_tag_data_chunk->get_chunk_data_end();

					unsigned int num_bytes = static_cast<unsigned int>(data_chunk_data_end - data_chunk_data_start);
					field_data->clear();
					char* elements = field_data->append_elements(data_chunk_data_start, num_bytes);
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
					h_resource_field* field_resource = high_level_cast<h_resource_field*>(field_type);
					ASSERT(field_resource != nullptr);

					const s_tag_resource& tag_resource = *reinterpret_cast<const s_tag_resource*>(structure_data_position);

					if (resource_exploded_chunk != nullptr)
					{
						c_tag_resource_data_chunk* data_chunk = resource_exploded_chunk->get_child_unsafe<c_tag_resource_data_chunk>(0);
						c_tag_struct_chunk* struct_chunk = resource_exploded_chunk->get_child_unsafe<c_tag_struct_chunk>(1);

						const void* data;
						uint32_t data_size;
						data_chunk->get_data(data, data_size);

						field_resource->set_resource(nullptr);

					}
					else if (resource_xsynced_chunk != nullptr)
					{
						if (resource_partition_view != nullptr)
						{
							c_monolithic_resource_handle* resource_handle = new() c_monolithic_resource_handle(*resource_partition_view, resource_xsynced_chunk->resource_xsync_state_v2);
							field_resource->set_resource(resource_handle);
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
						field_resource->set_resource(nullptr);
					}
					else
					{
						FATAL_ERROR("Unknown pageable resource type");
					}
				}
			}
			break;
			default: FATAL_ERROR("Unhandled field type");
			}
		}
		else if (transpose.can_transpose)
		{
			blofeld::s_tag_field const& blofeld_field = *transpose.blofeld_tag_field;

			switch (blofeld_field.field_type)
			{
			case blofeld::_field_skip:
			case blofeld::_field_pad:
			{
				uint32_t pad_size = transpose.field_metadata;
				//ASSERT(pad_size == blofeld_field.padding);
				field_size = pad_size;
			}
			break;
			case blofeld::_field_array:
			{
				s_tag_persist_array_definition& array_entry = get_array_definition_by_index(transpose.field_metadata);
				uint32_t array_structure_size = get_structure_size_by_index(array_entry.structure_entry_index);
				uint32_t array_size = array_structure_size * array_entry.count;
				field_size = array_size;
			}
			break;
			case blofeld::_field_old_string_id:
			case blofeld::_field_string_id:
			case blofeld::_field_string:
			case blofeld::_field_long_string:
			{
				// #TODO: Is this string null terminated? Making that assumption.
				ASSERT(strlen(structure_data_position) < field_size); 

				switch (transpose.blofeld_tag_field->field_type)
				{
				case blofeld::_field_old_string_id:
				case blofeld::_field_string_id:
				{
					h_string_id_field* field_string_id = high_level_cast<h_string_id_field*>(field_type);
					ASSERT(field_string_id != nullptr);

					field_string_id->set_string(structure_data_position);
				}
				break;
				case blofeld::_field_string:
				{
					h_typed_field<c_fixed_string_32>* field_string = high_level_cast<h_typed_field<c_fixed_string_32>*>(field_type);
					ASSERT(field_string != nullptr);

					c_fixed_string_32& string = *reinterpret_cast<c_fixed_string_32*>(field_string->get_data());
					
					string = structure_data_position;
				}
				break;
				case blofeld::_field_long_string:
				{
					h_typed_field<c_fixed_string_256>* field_string = high_level_cast<h_typed_field<c_fixed_string_256>*>(field_type);
					ASSERT(field_string != nullptr);

					c_fixed_string_256& string = *reinterpret_cast<c_fixed_string_256*>(field_string->get_data());

					string = structure_data_position;
				}
				break;
				}

				debug_point;
			}
			break;
			case blofeld::_field_char_integer:
			case blofeld::_field_short_integer:
			case blofeld::_field_long_integer:
			case blofeld::_field_int64_integer:
			case blofeld::_field_angle:
			case blofeld::_field_tag:
			case blofeld::_field_char_enum:
			case blofeld::_field_short_enum:
			case blofeld::_field_long_enum:
			case blofeld::_field_long_flags:
			case blofeld::_field_word_flags:
			case blofeld::_field_byte_flags:
			case blofeld::_field_point_2d:
			case blofeld::_field_rectangle_2d:
			case blofeld::_field_rgb_color:
			case blofeld::_field_argb_color:
			case blofeld::_field_real:
			case blofeld::_field_real_slider:
			case blofeld::_field_real_fraction:
			case blofeld::_field_real_point_2d:
			case blofeld::_field_real_point_3d:
			case blofeld::_field_real_vector_2d:
			case blofeld::_field_real_vector_3d:
			case blofeld::_field_real_quaternion:
			case blofeld::_field_real_euler_angles_2d:
			case blofeld::_field_real_euler_angles_3d:
			case blofeld::_field_real_plane_2d:
			case blofeld::_field_real_plane_3d:
			case blofeld::_field_real_rgb_color:
			case blofeld::_field_real_argb_color:
			case blofeld::_field_real_hsv_color:
			case blofeld::_field_real_ahsv_color:
			case blofeld::_field_short_integer_bounds:
			case blofeld::_field_angle_bounds:
			case blofeld::_field_real_bounds:
			case blofeld::_field_real_fraction_bounds:
			case blofeld::_field_long_block_flags:
			case blofeld::_field_word_block_flags:
			case blofeld::_field_byte_block_flags:
			case blofeld::_field_char_block_index:
			case blofeld::_field_char_block_index_custom_search:
			case blofeld::_field_short_block_index:
			case blofeld::_field_short_block_index_custom_search:
			case blofeld::_field_long_block_index:
			case blofeld::_field_long_block_index_custom_search:
			case blofeld::_field_byte_integer:
			case blofeld::_field_word_integer:
			case blofeld::_field_dword_integer:
			case blofeld::_field_qword_integer:
			{
				h_field* field = high_level_cast<h_field*>(field_type);
				ASSERT(field != nullptr);
				void* field_data = field->get_data();

				memcpy(field_data, structure_data_position, field_size);

				if (is_big_endian)
				{
					blofeld::byteswap_field_data_inplace(blofeld_field.field_type, field_data, engine_platform_build);
				}
			}
			break;
			default: FATAL_ERROR("Unhandled field type");
			}
		}

		structure_data_position += field_size;

	}
	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_file_reader::read_tag_block_structure_to_high_level_object(
	c_tag_block_chunk& tag_block_chunk,
	uint32_t tag_block_index,
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

BCS_RESULT c_high_level_tag_file_reader::parse_high_level_object(h_prototype*& out_prototype)
{
	BCS_RESULT rs = BCS_S_OK;

	c_tag_block_chunk* tag_group_block_chunk = binary_data_chunk->get_child_by_type_unsafe<c_tag_block_chunk>();
	ASSERT(tag_group_block_chunk != nullptr);
	ASSERT(tag_group_block_chunk->tag_block_chunk_header.count == 1);
	ASSERT(blofeld_tag_group_struct_definition->persistent_identifier == tag_group_block_chunk->structure_entry->unique_identifier);

	tag_group_block_chunk->log();

	blofeld::s_tag_struct_definition const& blofeld_struct_definition = get_tag_struct_definition_by_index(tag_group_block_chunk->structure_index);

	h_prototype* prototype = nullptr;
	try
	{
		if (BCS_FAILED(rs = high_level_registry_create_high_level_object(engine_platform_build, blofeld_struct_definition, prototype)))
		{
			return rs;
		}

		read_tag_block_structure_to_high_level_object(*tag_group_block_chunk, 0, *prototype);
	}
	catch (BCS_RESULT _rs)
	{
		rs = _rs;
	}
	catch (...)
	{
		rs = BCS_E_FATAL;
	}

	if (BCS_FAILED(rs))
	{
		delete prototype;
	}
	else
	{
		out_prototype = prototype;
	}

	return rs;
}
