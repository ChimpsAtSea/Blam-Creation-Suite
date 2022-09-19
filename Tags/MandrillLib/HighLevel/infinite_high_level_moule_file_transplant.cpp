#include "mandrilllib-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE

using namespace blofeld;

BCS_RESULT c_infinite_high_level_moule_file_transplant::transplant_module_file_data(
	h_prototype& high_level,
	int32_t tag_block_index,
	const char* const tag_block_data,
	int32_t nugget_index,
	const char* current_data_position,
	const s_tag_struct_definition& struct_definition)
{
	BCS_RESULT rs = BCS_S_OK;

#define use_byteswap_inplace() (engine_platform_build.platform_type == _platform_type_xbox_360)
#define byteswap_helper_func(value) if (use_byteswap_inplace()) byteswap_inplace(value)
#define basic_memory_read(type) \
		{ \
			type _value = *reinterpret_cast<const type*>(current_data_position); \
			byteswap_helper_func(_value); \
			*reinterpret_cast<type*>(high_level_field_data) = _value; \
			break; \
		}

	for (const s_tag_field* field = struct_definition.fields; field->field_type != _field_terminator; field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*field, engine_platform_build, ANY_TAG, tag_field_version_max, field_skip_count))
		{
			field += field_skip_count;
			continue;
		}

		//ptrdiff_t diff = current_data_position - low_level_data;
		//const char* field_type_str = field_to_string(field->field_type);
		//console_write_line("%X> %s::'%s' [%s]", static_cast<int>(diff), struct_definition.struct_name, field->name, field_type_str);

		void* high_level_field_data = high_level.get_field_data_unsafe(*field);

		uint32_t field_size = cache_file_reader.get_field_size(*field);

		if (high_level_field_data != nullptr)
		{
			switch (field->field_type)
			{
			case _field_string:							basic_memory_read(::c_static_string<32>);
			case _field_long_string:					basic_memory_read(::c_static_string<256>);
			case _field_char_integer:					basic_memory_read(char);
			case _field_short_integer:					basic_memory_read(short);
			case _field_long_integer:					basic_memory_read(long);
			case _field_int64_integer:					basic_memory_read(int64_t);
			case _field_angle:							basic_memory_read(angle);
			case _field_tag:							basic_memory_read(tag);
			case _field_point_2d:						basic_memory_read(::s_point2d);
			case _field_rectangle_2d:					basic_memory_read(::s_rectangle2d);
			case _field_rgb_color:						basic_memory_read(::pixel32);
			case _field_argb_color:						basic_memory_read(::pixel32);
			case _field_real:							basic_memory_read(::real);
			case _field_real_fraction:					basic_memory_read(::real_fraction);
			case _field_real_point_2d:					basic_memory_read(::real_point2d);
			case _field_real_point_3d:					basic_memory_read(::real_point3d);
			case _field_real_vector_2d:					basic_memory_read(::real_vector2d);
			case _field_real_vector_3d:					basic_memory_read(::real_vector3d);
			case _field_real_quaternion:				basic_memory_read(::real_quaternion);
			case _field_real_euler_angles_2d:			basic_memory_read(::real_euler_angles2d);
			case _field_real_euler_angles_3d:			basic_memory_read(::real_euler_angles3d);
			case _field_real_plane_2d:					basic_memory_read(::real_plane2d);
			case _field_real_plane_3d:					basic_memory_read(::real_plane3d);
			case _field_real_rgb_color:					basic_memory_read(::rgb_color);
			case _field_real_argb_color:				basic_memory_read(::argb_color);
			case _field_real_hsv_color:					basic_memory_read(::real_hsv_color);
			case _field_real_ahsv_color:				basic_memory_read(::real_ahsv_color);
			case _field_short_integer_bounds:					basic_memory_read(::short_bounds);
			case _field_angle_bounds:					basic_memory_read(::angle_bounds);
			case _field_real_bounds:					basic_memory_read(::real_bounds);
			case _field_real_fraction_bounds:			basic_memory_read(::real_fraction_bounds);
			case _field_long_block_flags:				basic_memory_read(long);
			case _field_word_block_flags:				basic_memory_read(word);
			case _field_byte_block_flags:				basic_memory_read(byte);
			case _field_char_block_index:				basic_memory_read(char);
			case _field_char_block_index_custom_search:		basic_memory_read(char);
			case _field_short_block_index:				basic_memory_read(short);
			case _field_short_block_index_custom_search:		basic_memory_read(short);
			case _field_long_block_index:				basic_memory_read(long);
			case _field_long_block_index_custom_search:		basic_memory_read(long);
			case _field_byte_integer:					basic_memory_read(byte);
			case _field_word_integer:					basic_memory_read(word);
			case _field_dword_integer:					basic_memory_read(dword);
			case _field_qword_integer:					basic_memory_read(qword);
			case _field_data_path:						basic_memory_read(::c_static_string<256>);
			case _field_char_enum:
			{
				char data = *reinterpret_cast<const char*>(current_data_position);
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_short_enum:
			{
				short value = *reinterpret_cast<const short*>(current_data_position);
				byteswap_helper_func(value);
				int32_t data = value;
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_long_enum:
			{
				int32_t data = *reinterpret_cast<const long*>(current_data_position);
				byteswap_helper_func(data);
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_long_flags:
			{
				dword data = *reinterpret_cast<const dword*>(current_data_position);
				byteswap_helper_func(data);
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_word_flags:
			{
				word value = *reinterpret_cast<const word*>(current_data_position);
				byteswap_helper_func(value);
				dword data = value;
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_byte_flags:
			{
				dword data = *reinterpret_cast<const byte*>(current_data_position);
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_struct:
			{
				h_prototype& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
				transplant_module_file_data(struct_storage, tag_block_index, tag_block_data, nugget_index, current_data_position, *field->struct_definition);
			}
			break;
			case _field_array:
			{
				h_enumerable& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_field_data);
				const char* raw_array_data_position = current_data_position;

				uint32_t const block_struct_size = cache_file_reader.calculate_struct_size(field->array_definition->struct_definition);

				uint32_t const array_elements_count = field->array_definition->count(engine_platform_build);
				for (uint32_t array_index = 0; array_index < array_elements_count; array_index++)
				{
					h_prototype& array_element_storage = array_storage[array_index];

					transplant_module_file_data(array_element_storage, tag_block_index, tag_block_data, nugget_index, raw_array_data_position, field->array_definition->struct_definition);

					raw_array_data_position += block_struct_size;
				}
			}
			break;
			case _field_block:
			{
				s_infinite_ucs_block_field ucs_block_field = *reinterpret_cast<const s_infinite_ucs_block_field*>(current_data_position);
				h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);
				block_storage.clear();

				DEBUG_ASSERT(ucs_block_field.elements == 0xBCBCBCBCBCBCBCBC);
				DEBUG_ASSERT(ucs_block_field.count != 0xBCBCBCBC);

				if (ucs_block_field.count > 0)
				{
					const s_tag_struct_definition& block_struct_definition = field->block_definition->struct_definition;
					uint32_t const block_struct_size = cache_file_reader.calculate_struct_size(block_struct_definition);
					uint32_t const total_block_struct_storage_size = block_struct_size * ucs_block_field.count;

					ASSERT(current_data_position != nullptr);
					ASSERT(tag_block_data != nullptr);
					int32_t offset = static_cast<long>(current_data_position - tag_block_data);

					const s_infinite_ucs_tag_block_data* _tag_block_data = nullptr;
					int32_t _tag_block_index = 01;
					for (uint32_t block_index = 0; block_index < ucs_reader.ucs_header->tag_block_count; block_index++)
					{
						const s_infinite_ucs_tag_block_data& current_tag_block_data = ucs_reader.tag_block_instances[block_index];
						const s_infinite_ucs_nugget& current_nugget = ucs_reader.nuggets[current_tag_block_data.nugget_index];

						if (current_tag_block_data.owner_block_index == nugget_index && current_tag_block_data.owner_block_offset == offset)
						{
							_tag_block_data = &current_tag_block_data;
							_tag_block_index = static_cast<long>(block_index);

							break;
						}


					}
					ASSERT(_tag_block_data != nullptr);

					if (_tag_block_data->nugget_index >= 0) // #TODO: this was an assert, why is this -1?
					{
						ASSERT(_tag_block_data->nugget_index >= 0);
						const s_infinite_ucs_nugget& nugget = ucs_reader.nuggets[_tag_block_data->nugget_index];
						ASSERT(nugget.size >= total_block_struct_storage_size);
						ASSERT(nugget.size == total_block_struct_storage_size);

						const char* const root_tag_data = static_cast<const char*>(ucs_reader.tag_data);
						const char* const block_data = root_tag_data + nugget.offset;

						block_storage.reserve(ucs_block_field.count);

						const char* block_data_position = block_data;
						for (int32_t block_index = 0; block_index < ucs_block_field.count; (block_index++, block_data_position += block_struct_size))
						{
							h_prototype& type = block_storage.emplace_back();

							transplant_module_file_data(
								type,
								_tag_block_index,
								block_data,
								_tag_block_data->nugget_index,
								block_data_position,
								block_struct_definition);
						}


					}

				}
			}
			break;
			case _field_data:
			{
				const s_infinite_ucs_data_reference_field& ucs_data_reference_field = *reinterpret_cast<const s_infinite_ucs_data_reference_field*>(current_data_position);
				if (ucs_data_reference_field.size > 0)
				{
					int32_t offset = static_cast<long>(current_data_position - tag_block_data);

					const s_infinite_ucs_data_reference_list* ucs_data_reference = nullptr;
					for (uint32_t data_index = 0; data_index < ucs_reader.ucs_header->data_reference_count; data_index++)
					{
						const s_infinite_ucs_data_reference_list& current_ucs_data_reference = ucs_reader.tag_data_instances[data_index];
						const s_infinite_ucs_nugget& current_nugget = ucs_reader.nuggets[current_ucs_data_reference.nugget_index];

						if (current_ucs_data_reference.parent_tag_block_index == tag_block_index && current_ucs_data_reference.owner_block_offset == offset)
						{
							ucs_data_reference = &current_ucs_data_reference;

						}


					}
					ASSERT(ucs_data_reference != nullptr);
					const s_infinite_ucs_nugget& nugget = ucs_reader.nuggets[ucs_data_reference->nugget_index];
					ASSERT(nugget.size >= ucs_data_reference_field.size);
					ASSERT(nugget.size == ucs_data_reference_field.size);

					const char* const root_tag_data = static_cast<const char*>(ucs_reader.tag_data);
					const char* const block_data = root_tag_data + nugget.offset;
					const char* const block_data_end = block_data + ucs_data_reference_field.size;

					h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);
					data_storage.insert(data_storage.begin(), block_data, block_data_end);


				}


			}
			break;
			case _field_tag_reference:
			{
				s_infinite_ucs_tag_reference_field ucs_tag_reference_field = *reinterpret_cast<const s_infinite_ucs_tag_reference_field*>(current_data_position);

				//ASSERT(ucs_tag_reference_field.type_info == 0xBCBCBCBCBCBCBCBC);
				//ASSERT(ucs_tag_reference_field.name_length != 0xBCBCBCBC);
				//ASSERT(ucs_tag_reference_field.global_id != 0xBCBCBCBC);
				//ASSERT(ucs_tag_reference_field.unknown != 0xBCBCBCBC);
				//ASSERT(ucs_tag_reference_field.group_tag != 0xBCBCBCBC);
				//ASSERT(ucs_tag_reference_field.local_handle == 0xBCBCBCBC);

				//h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);
				h_tag_reference* tag_reference_storage = high_level.get_field_data<h_tag_reference>(*field);
				ASSERT(tag_reference_storage != nullptr);

				if (ucs_tag_reference_field.group_tag == INVALID_TAG)
				{
					tag_reference_storage->clear();
				}
				else
				{
					c_tag_instance* tag_instance = nullptr;
					if (BCS_FAILED(rs = cache_cluster.get_tag_instance_by_global_tag_id_and_group_tag(ucs_tag_reference_field.global_id, ucs_tag_reference_field.group_tag, tag_instance)))
					{
						tag_reference_storage->set_unqualified_file_path_without_extension(ucs_tag_reference_field.group_tag, root_high_level.get_file_path_without_extension());
					}
					else
					{
						h_tag* tag_reference_high_level_tag = nullptr;
						if (BCS_FAILED(rs = high_level_cache_cluster_transplant.get_global_tag_by_low_level_tag_instance(*tag_instance, tag_reference_high_level_tag)))
						{
							return rs;
						}
						tag_reference_storage->set_tag(tag_reference_high_level_tag);
					}
				}
			}
			break;
			case _field_pageable_resource:
			{
				s_infinite_ucs_pageable_resource_field ucs_pageable_resource_field = *reinterpret_cast<const s_infinite_ucs_pageable_resource_field*>(current_data_position);

				h_resource*& resource_storage = *reinterpret_cast<decltype(&resource_storage)>(high_level_field_data);


				if (BCS_SUCCEEDED(command_line_has_argument("loadinfiniteresources")))
				{
					if (c_infinite_tag_instance* infinite_tag_instance = dynamic_cast<c_infinite_tag_instance*>(&tag_instance))
					{
						c_simple_resource_container* simple_resource_container = new() c_simple_resource_container();
						resource_storage = simple_resource_container;

						const s_tag_resource_definition& pageable_resource_definition = *field->tag_resource_definition;
						const s_tag_struct_definition& pageable_resource_struct_definition = pageable_resource_definition.struct_definition;
						uint32_t const pageable_resource_struct_size = cache_file_reader.calculate_struct_size(pageable_resource_struct_definition);
						uint32_t const total_block_struct_storage_size = pageable_resource_struct_size;

						// read resource data
						auto& resource_file_entry_block_maps = infinite_tag_instance->file_entry_block_map.resource_file_entry_block_maps;
						//ASSERT(resource_file_entry_block_maps.size() >= 1);

						const void* tag_resource_data;
						uint32_t tag_resource_data_size;
						infinite_tag_instance->get_resource_data(tag_resource_data, tag_resource_data_size);

						const void* tag_header_data;
						uint32_t tag_header_data_size;
						infinite_tag_instance->get_header_data(tag_header_data, tag_header_data_size);

						unsigned int index = 0;
						for (auto& resource_file_entry_block_map : resource_file_entry_block_maps)
						{
							void* external_resource_data;
							BCS_RESULT rst1 = resource_file_entry_block_map->map(external_resource_data);
							ASSERT(BCS_SUCCEEDED(rst1));

							if (external_resource_data)
							{

								char* data_start = static_cast<char*>(external_resource_data);
								char* data_end = data_start + resource_file_entry_block_map->file_entry.uncompressed_size;

								simple_resource_container->data.insert(simple_resource_container->data.end(), data_start, data_end);

								BCS_RESULT rst2 = resource_file_entry_block_map->unmap(external_resource_data);
								ASSERT(BCS_SUCCEEDED(rst2));
							}

							index++;


						}

						// read tag data
						int32_t _tag_block_index = -1;
						const s_infinite_ucs_tag_block_data* _tag_block_data = nullptr;
						{
							ASSERT(current_data_position != nullptr);
							ASSERT(tag_block_data != nullptr);
							int32_t offset = static_cast<long>(current_data_position - tag_block_data);

							for (uint32_t block_index = 0; block_index < ucs_reader.ucs_header->tag_block_count; block_index++)
							{
								const s_infinite_ucs_tag_block_data& current_tag_block_data = ucs_reader.tag_block_instances[block_index];
								const s_infinite_ucs_nugget& current_nugget = ucs_reader.nuggets[current_tag_block_data.nugget_index];

								if (current_tag_block_data.owner_block_index == nugget_index && current_tag_block_data.owner_block_offset == offset)
								{
									_tag_block_data = &current_tag_block_data;
									_tag_block_index = static_cast<long>(block_index);

									break;
								}


							}
							ASSERT(_tag_block_data != nullptr);
							ASSERT(_tag_block_data->persistent_identifier == pageable_resource_struct_definition.persistent_identifier);
						}

						if (_tag_block_data->type == _infinite_ucs_tag_block_type_resource)
						{
							if (ucs_pageable_resource_field.unknownC == 0)
							{
								ASSERT(ucs_pageable_resource_field.unknownC == 0);
								// standard resources have no tag data associated with them

								if (simple_resource_container->data.size() > 0)
								{
									ASSERT(simple_resource_container->data.size() > sizeof(s_infinite_ucs_header));
									s_infinite_ucs_header& resource_ucs_header = *reinterpret_cast<s_infinite_ucs_header*>(simple_resource_container->data.data());
									ASSERT(resource_ucs_header.magic == 'hscu');
									resource_ucs_header.magic;
									c_infinite_ucs_reader resource_ucs_reader = c_infinite_ucs_reader(&resource_ucs_header);



								}
							}
							else
							{
								// #TODO: some of these are 2, why?
							}

						}
						else if (_tag_block_data->type == _infinite_ucs_tag_block_type_custom)
						{
							ASSERT(ucs_pageable_resource_field.unknownC == 1);

							if (_tag_block_data->nugget_index >= 0)
							{
								ASSERT(_tag_block_data->nugget_index >= 0);

								const s_infinite_ucs_nugget& nugget = ucs_reader.nuggets[_tag_block_data->nugget_index];
								ASSERT(nugget.size == total_block_struct_storage_size);

								const char* const root_tag_data = static_cast<const char*>(ucs_reader.tag_data);
								const char* const pageable_resource_data = root_tag_data + nugget.offset;

								h_prototype* pageable_resource_object = h_prototype::create_high_level_object(pageable_resource_struct_definition, engine_platform_build);
								ASSERT(pageable_resource_object != nullptr);

								resource_storage->object = pageable_resource_object;

								transplant_module_file_data(
									*pageable_resource_object,
									_tag_block_index,
									pageable_resource_data,
									_tag_block_data->nugget_index,
									pageable_resource_data,
									pageable_resource_struct_definition);
							}
							else
							{
								// #TODO: why is this -1 sometimes?
							}
						}
						else
						{
							static std::map<std::string, int> x;
							if (x[field->struct_definition->name]++ == 0)
								console_write_line("Unsupported pageable resource '%s' [reason yet more bad assumptions]", field->struct_definition->name);
						}



					}

				}


			}
			break;
			case _field_string_id:
			{
				h_string_id& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);

				string_id stringid = *reinterpret_cast<const ::string_id*>(current_data_position);
				if (stringid != 0)
				{
					const char* string;
					if (BCS_SUCCEEDED(infinite_string_id_manager.find_string(stringid, string)))
					{
						string_id_storage = string;
					}
					else
					{
						c_fixed_string_128 buffer;
						buffer.format("hashed_string_id:0x%08X", stringid);
						string_id_storage.set_string(buffer);
					}
				}
			}
			break;
			default: throw;
			}
		}

		current_data_position += field_size;
	}

	return rs;
}

c_infinite_high_level_moule_file_transplant::c_infinite_high_level_moule_file_transplant(
	c_high_level_cache_cluster_transplant& high_level_cache_cluster_transplant,
	s_engine_platform_build engine_platform_build,
	c_tag_instance& tag_instance,
	h_tag& root_high_level,
	const s_tag_struct_definition& struct_definition,
	c_infinite_ucs_reader& ucs_reader,
	c_infinite_cache_cluster& cache_cluster,
	c_infinite_module_file_reader& cache_file_reader) :
	high_level_cache_cluster_transplant(high_level_cache_cluster_transplant),
	engine_platform_build(engine_platform_build),
	ucs_reader(ucs_reader),
	tag_instance(tag_instance),
	root_high_level(root_high_level),
	root_struct_definition(struct_definition),
	cache_cluster(cache_cluster),
	cache_file_reader(cache_file_reader),
	root_struct_size(cache_file_reader.calculate_struct_size(struct_definition))
{
	ASSERT(ucs_reader.root_nugget->size >= root_struct_size);
	transplant_module_file_data(
		root_high_level,
		ucs_reader.root_tag_block_entry_index,
		ucs_reader.root_tag_block_data,
		ucs_reader.tag_group_tag_block_entry->nugget_index,
		ucs_reader.root_tag_block_data,
		root_struct_definition);
}

c_infinite_high_level_moule_file_transplant::~c_infinite_high_level_moule_file_transplant()
{

}

#endif
