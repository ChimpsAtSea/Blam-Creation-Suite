#include "mandrilllib-private-pch.h"

using namespace blofeld;

c_high_level_cache_cluster_transplant::c_high_level_cache_cluster_transplant(c_cache_cluster& cache_cluster) :
	instance_transplant_entries(),
	instances(),
	groups(),
	transplant_entries(),
	cache_cluster(cache_cluster),
	engine_platform_build()
{
	BCS_RESULT rs;

	ASSERT(BCS_SUCCEEDED(cache_cluster.get_engine_platform_build(engine_platform_build)));

	if (BCS_FAILED(rs = init_transplant_entries()))
	{
		throw(rs);
	}

	if (BCS_FAILED(rs = init_tag_groups()))
	{
		throw(rs);
	}

	if (BCS_FAILED(rs = init_tag_instances()))
	{
		throw(rs);
	}

	if (BCS_FAILED(rs = transplant_instance_data()))
	{
		throw(rs);
	}


	//// #TODO: Fix this. See fixes below.
	////for (unsigned long group_index = 0; group_index < cache_file.get_tag_group_count(); group_index++)
	////{
	////	c_tag_group_interface* tag_group_interface = cache_file.get_tag_group_interface(group_index);

	////	get_or_create_group(*tag_group_interface);
	////}

	//for (c_tag_interface& tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	//{
	//	h_tag* high_level_tag = tag_interface_to_high_level(tag_interface);

	//	if (high_level_tag == nullptr)
	//	{
	//		continue;
	//	}

	//	s_tag_pair tag_pair = { tag_interface, *high_level_tag };
	//	tags_and_interface.emplace_back(tag_pair);
	//}

	//auto transplant_high_level_tags = [this](unsigned long index)
	//{
	//	s_tag_pair& tag_pair = tags_and_interface[index];

	//	h_tag& high_level_tag = tag_pair.high_level_tag;
	//	c_tag_interface& tag_interface = tag_pair.tag_interface;

	//	const char* raw_tag_data = tag_interface.get_tag_data();

	//	const blofeld::s_tag_group* tag_group = tag_interface.get_blofeld_reflection_data();
	//	DEBUG_ASSERT(tag_group != nullptr);
	//	const blofeld::s_tag_struct_definition& tag_struct_definition = tag_group->block_definition.struct_definition;

	//	transplant_cache_file_data(high_level_tag, raw_tag_data, tag_struct_definition);
	//};
	////tbb::parallel_for(0u, static_cast<unsigned long>(tags_and_interface.size()), transplant_high_level_tags);
	//for (unsigned long i = 0; i < tags_and_interface.size(); i++) transplant_high_level_tags(i);
}

c_high_level_cache_cluster_transplant::~c_high_level_cache_cluster_transplant()
{

}

BCS_RESULT c_high_level_cache_cluster_transplant::init_transplant_entries()
{
	BCS_RESULT rs = BCS_S_OK;

	c_cache_file_reader* const* cache_readers;
	unsigned long cache_reader_count;
	if (BCS_FAILED(rs = cache_cluster.get_cache_readers(cache_readers, cache_reader_count)))
	{
		return rs;
	}

	for (unsigned long cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_cache_file_reader& cache_file_reader = *cache_readers[cache_reader_index];

		c_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(cache_cluster.get_tag_reader(cache_file_reader, tag_reader)))
		{
			transplant_entries.push_back(&cache_file_reader);
		}
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_global_tag_by_low_level_tag_instance(c_tag_instance& tag_instance, h_tag*& tag)
{
	BCS_RESULT rs = BCS_S_OK;

	c_cache_file_reader* const* cache_file_readers;
	unsigned long cache_file_reader_count;
	if (BCS_FAILED(rs = cache_cluster.get_cache_readers(cache_file_readers, cache_file_reader_count)))
	{
		return rs;
	}

	for (unsigned long cache_file_reader_index = 0; cache_file_reader_index < cache_file_reader_count; cache_file_reader_index++)
	{
		c_cache_file_reader& cache_file_reader = *cache_file_readers[cache_file_reader_index];

		if (BCS_SUCCEEDED(rs = get_tag_by_low_level_tag_instance(cache_file_reader, tag_instance, tag)))
		{
			return rs;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_tag_by_low_level_tag_instance(c_cache_file_reader& cache_file_reader, c_tag_instance& tag_instance, h_tag*& tag)
{
	BCS_RESULT rs = BCS_S_OK;
	const t_transplant_instances* transplant_instances;
	if (BCS_FAILED(rs = get_cluster_transplant_instances(cache_file_reader, transplant_instances)))
	{
		return rs;
	}

	for (const s_tag_transplant_instance& transplant_instance : *transplant_instances)
	{
		if (transplant_instance.low_level == &tag_instance)
		{
			tag = transplant_instance.high_level;
			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_tag_by_group_and_filename(h_group& group, const char* filename, h_tag*& tag)
{
	return BCS_E_FAIL;
}

BCS_RESULT c_high_level_cache_cluster_transplant::init_tag_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_group** tag_groups;
	if (BCS_FAILED(rs = cache_cluster.get_blofeld_tag_groups(tag_groups)))
	{
		return rs;
	}

	for (const blofeld::s_tag_group** tag_group = tag_groups; *tag_group; tag_group++)
	{
		auto high_level_group = new() h_group(engine_platform_build, **tag_group);
		groups.push_back(high_level_group);
	}

	for (c_cache_file_reader* cache_file_reader : transplant_entries)
	{
		c_tag_reader* tag_reader;
		ASSERT(BCS_SUCCEEDED(cache_cluster.get_tag_reader(*cache_file_reader, tag_reader)));

		c_tag_group** tag_groups = nullptr;
		unsigned long tag_group_count = 0;
		ASSERT(BCS_SUCCEEDED(tag_reader->get_tag_groups(tag_groups, tag_group_count)));

		for (unsigned long group_index = 0; group_index < tag_group_count; group_index++)
		{
			c_tag_group& tag_group = *tag_groups[group_index];

			tag group_tag;
			ASSERT(BCS_SUCCEEDED(tag_group.get_group_tag(group_tag)));

			h_group* high_level_group;
			if (BCS_FAILED(rs = get_tag_group(group_tag, high_level_group)))
			{
				const char* tag_group_name = nullptr;
				ASSERT(BCS_SUCCEEDED(tag_group.get_group_name(tag_group_name)));

				console_write_line("missing referenced tag group '%s'", tag_group_name);
				// all groups should be initialized inside of init_tag_group_hierarchy_impl
				//return rs;
			}

			
		}
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::init_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	for (c_cache_file_reader* cache_file_reader : transplant_entries)
	{
		c_tag_reader* tag_reader;
		ASSERT(BCS_SUCCEEDED(cache_cluster.get_tag_reader(*cache_file_reader, tag_reader)));

		t_transplant_instances_keyval& instance_transplant_entry = instance_transplant_entries.emplace_back();
		instance_transplant_entry.first = cache_file_reader;
		t_transplant_instances& high_level_tag_instances = instance_transplant_entry.second;

		c_tag_instance** tag_instances = nullptr;
		unsigned long tag_instance_count = 0;
		ASSERT(BCS_SUCCEEDED(tag_reader->get_tag_instances(tag_instances, tag_instance_count)));

		for (unsigned long instance_index = 0; instance_index < tag_instance_count; instance_index++)
		{
			c_tag_instance& tag_instance = *tag_instances[instance_index];
			const char* tag_instance_name = nullptr;
			c_tag_group* tag_group = nullptr;
			tag group_tag;

			ASSERT(BCS_SUCCEEDED(tag_instance.get_instance_name(tag_instance_name)));
			ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_group(tag_group)));
			ASSERT(BCS_SUCCEEDED(tag_group->get_group_tag(group_tag)));

			h_group* group;
			if (BCS_FAILED(rs = get_tag_group(group_tag, group)))
			{
				const char* group_name = nullptr;
				ASSERT(BCS_SUCCEEDED(tag_group->get_group_name(group_name)));

				console_write_line("missing instance tag group '%s'", group_name);
				return rs;
			}

			h_tag& high_level_tag = group->create_tag_instance(tag_instance_name);

			s_tag_transplant_instance transplant_instance;
			transplant_instance.low_level = &tag_instance;
			transplant_instance.high_level = &high_level_tag;

			high_level_tag_instances.push_back(transplant_instance);
			instances.push_back(transplant_instance);

			
		}

		

		break;
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::transplant_instance_data()
{
	BCS_RESULT rs = BCS_S_OK;

	for (c_cache_file_reader* cache_file_reader : transplant_entries)
	{
		c_tag_reader* tag_reader;
		ASSERT(BCS_SUCCEEDED(cache_cluster.get_tag_reader(*cache_file_reader, tag_reader)));

		const t_transplant_instances* transplant_instances;
		if (BCS_FAILED(rs = get_cluster_transplant_instances(*cache_file_reader, transplant_instances)))
		{
			return rs;
		}

		for (const s_tag_transplant_instance& transplant_instance : *transplant_instances)
		{
			c_tag_instance& tag_instance = *transplant_instance.low_level;
			h_tag& high_level_tag = *transplant_instance.high_level;

			if (engine_platform_build.engine_type < _engine_type_halo5)
			{
				const void* tag_instance_data;
				if (BCS_FAILED(rs = tag_instance.get_tag_data(tag_instance_data)))
				{
					return rs;
				}

				if (!tag_instance_data || BCS_FAILED(rs = transplant_cache_file_data(high_level_tag, static_cast<const char*>(tag_instance_data), *cache_file_reader, high_level_tag.get_blofeld_struct_definition())))
				{
					console_write_line("failed to transplant tag '%s.%s'", high_level_tag.tag_filename, high_level_tag.group->tag_group.name);
					//return rs; //#TODO: enable this!
				}
			}
			else if (c_infinite_tag_instance* infinite_tag_instance = dynamic_cast<c_infinite_tag_instance*>(&tag_instance)) // #TODO: this is kinda nasty
			{
				if (BCS_FAILED(rs = tag_instance.map_data()))
				{
					return rs;
				}

				BCS_RESULT transplant_result = BCS_S_OK;
				{
					c_infinite_ucs_reader* ucs_reader;
					if (BCS_FAILED(transplant_result = infinite_tag_instance->get_ucs_reader(ucs_reader)))
					{
						return transplant_result;
					}

					if (BCS_FAILED(transplant_result = transplant_module_file_data(
						tag_instance,
						high_level_tag,
						ucs_reader,
						static_cast<const char*>(ucs_reader->tag_data), // #TODO: should this be an extra api call using get_tag_data on the tag instance?
						*cache_file_reader,
						high_level_tag.get_blofeld_struct_definition())))
					{
						console_write_line("failed to transplant tag '%s.%s'", high_level_tag.tag_filename, high_level_tag.group->tag_group.name);
						return transplant_result;
					}
				}

				if (BCS_FAILED(rs = tag_instance.unmap_data()))
				{
					return rs;
				}

				if (BCS_FAILED(transplant_result))
				{
					return transplant_result;
				}
			}

			
		}
		break;
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::transplant_cache_file_data(
	h_prototype& high_level,
	const char* const low_level_data,
	c_cache_file_reader& cache_file_reader,
	const blofeld::s_tag_struct_definition& struct_definition,
	const char** final_low_level_data_pos)
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

	const char* current_data_position = low_level_data;
	for (const s_tag_field* field = struct_definition.fields; field->field_type != _field_terminator; field++)
	{
		unsigned long field_skip_count;
		if (execute_tag_field_versioning(*field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
		{
			field += field_skip_count;
			continue;
		}

		//ptrdiff_t diff = current_data_position - low_level_data;
		//const char* field_type_str = field_to_string(field->field_type);
		//console_write_line("%X> %s::'%s' [%s]", static_cast<int>(diff), struct_definition.struct_name, field->name, field_type_str);

		void* high_level_field_data = high_level.get_field_data_unsafe(*field);

		unsigned long field_size = get_blofeld_field_size(*field, engine_platform_build);

		if (high_level_field_data != nullptr)
		{
			switch (field->field_type)
			{
			case _field_string:							basic_memory_read(::c_static_string<32>);
			case _field_long_string:					basic_memory_read(::c_static_string<256>);
			case _field_char_integer:					basic_memory_read(char);
			case _field_short_integer:					basic_memory_read(short);
			case _field_long_integer:					basic_memory_read(long);
			case _field_int64_integer:					basic_memory_read(long long);
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
			case _field_string_id:
			case _field_old_string_id:
			{
				c_debug_reader* debug_reader;
				if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_file_reader, debug_reader)))
				{
					return rs;
				}

				string_id string_id = *reinterpret_cast<const ::string_id*>(current_data_position);
				byteswap_helper_func(string_id);

				h_string_id& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);

				const char* string;
				BCS_RESULT string_id_result;
				if (BCS_SUCCEEDED(string_id_result = debug_reader->string_id_to_string(string_id, string)))
				{
					string_id_storage = string;
				}
				else
				{
					//console_write_line("warning: failed to find stringid 0x%08X [%s::%s]", string_id, struct_definition.name, field->name);

					c_fixed_string_128 buffer;
					buffer.format("unknown_string_id:0x%08X", string_id);

					string_id_storage = buffer;

					//return rs;
				}

			}
			break;
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
				long data = value;
				memcpy(high_level_field_data, &data, sizeof(data));
			}
			break;
			case _field_long_enum:
			{
				long data = *reinterpret_cast<const long*>(current_data_position);
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
			case _field_block:
			{
				const blofeld::s_tag_struct_definition& block_struct_definition = field->block_definition->struct_definition;
				s_tag_block tag_block = *reinterpret_cast<const s_tag_block*>(current_data_position);
				byteswap_helper_func(tag_block);

				h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);
				unsigned long const block_struct_size = calculate_struct_size(engine_platform_build, block_struct_definition);

				block_storage.clear();

				DEBUG_ASSERT(tag_block.count != 0xCDCDCDCD);
				if (tag_block.count > 0)
				{
					DEBUG_ASSERT(tag_block.address != 0xCDCDCDCD);
				}

				if (tag_block.address > 0x30000)
					if (tag_block.count > 0)
					{
						block_storage.reserve(tag_block.count);
						ASSERT(tag_block.definition_address == 0);

						const char* block_data;
						{ // #TODO: function abstraction for this?

							s_cache_file_buffer_info tag_section_buffer;
							if (BCS_FAILED(rs = cache_file_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
							{
								// #NOTE: this is expected to always succeed as we shouldn't have added any cache files without this
								// section to transplant_entries
								return rs;
							}

							long long virtual_address;
							if (BCS_FAILED(rs = cache_file_reader.page_offset_to_virtual_address(tag_block.address, virtual_address)))
							{
								return rs;
							}

							long relative_offset;
							if (BCS_FAILED(rs = cache_file_reader.virtual_address_to_relative_offset(virtual_address, relative_offset)))
							{
								return rs;
							}

							block_data = tag_section_buffer.begin + relative_offset;
						}

						//const char* const block_data = cache_file.get_tag_block_data(tag_block);

						//if (tag_block.count < 1024)
						{
							block_storage.reserve(tag_block.count);

							const char* current_block_data_position = block_data;
							for (unsigned long block_index = 0; block_index < tag_block.count; block_index++)
							{
								h_prototype& type = block_storage.emplace_back();
								transplant_cache_file_data(type, current_block_data_position, cache_file_reader, block_struct_definition);

								current_block_data_position += block_struct_size;
							}
						}
						//else
						//{
						//	block_storage.resize(tag_block.count);

						//	auto transplant_high_level_block = [this, &block_storage, block_data, block_struct_size, block_struct_definition](unsigned long index)
						//	{
						//		const void* current_block_data = block_data + block_struct_size * index;

						//		h_prototype& type = block_storage.get(index);
						//		transplant_cache_file_data(type, block_data, block_struct_definition);
						//	};
						//	tbb::parallel_for(0u, static_cast<unsigned long>(tag_block.count), transplant_high_level_block);
						//}

						
					}
				

			}
			break;
			case _field_pointer:
			{
				unsigned long pointer_size;
				ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(engine_platform_build.platform_type, &pointer_size)));
				switch (pointer_size)
				{
				case 4: basic_memory_read(dword);
				case 8: basic_memory_read(qword);
				default: FATAL_ERROR("Unknown pointer size");
				}
			}
			break;
			case _field_struct:
			{
				h_prototype& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
				transplant_cache_file_data(struct_storage, current_data_position, cache_file_reader, *field->struct_definition);
			}
			break;
			case _field_array:
			{
				h_enumerable& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_field_data);
				const char* raw_array_data_position = current_data_position;

				unsigned long const array_elements_count = field->array_definition->count(engine_platform_build);
				for (unsigned long array_index = 0; array_index < array_elements_count; array_index++)
				{
					h_prototype& array_element_storage = array_storage[array_index];

					transplant_cache_file_data(array_element_storage, raw_array_data_position, cache_file_reader, field->array_definition->struct_definition, &raw_array_data_position);
				}
			}
			break;
			case _field_embedded_tag:
			case _field_tag_reference:
			{
				s_tag_reference tag_reference = *reinterpret_cast<const s_tag_reference*>(current_data_position);
				byteswap_helper_func(tag_reference);

				h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);

				unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_reference.datum_index);

				c_tag_reader* tag_reader;
				if (BCS_FAILED(rs = cache_cluster.get_tag_reader(cache_file_reader, tag_reader)))
				{
					return rs;
				}

				c_tag_instance* tag_instance = nullptr;
				tag_reader->get_tag_instance_by_cache_file_tag_index(tag_index, tag_instance);


				//c_tag_interface* tag_reference_tag_interface = cache_file.get_tag_interface(tag_reference.index);
				//h_tag* tag_reference_high_level_tag = get_high_level_tag_by_tag_interface(tag_reference_tag_interface);

				h_tag* tag_reference_high_level_tag = nullptr;
				if (tag_instance != nullptr)
				{
					if (BCS_FAILED(rs = get_tag_by_low_level_tag_instance(cache_file_reader, *tag_instance, tag_reference_high_level_tag)))
					{
						return rs;
					}
				}

				tag_ref_storage = tag_reference_high_level_tag;
			}
			break;
			case _field_data:
			{
				const s_tag_data& tag_data = *reinterpret_cast<decltype(&tag_data)>(current_data_position);
				h_data& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);

				//#TODO
				//const char* tag_data_data = cache_file.get_tag_data(tag_data);
				//if (tag_data_data != nullptr)
				//{
				//	data_storage.clear();
				//	data_storage.insert(data_storage.begin(), tag_data_data, tag_data_data + tag_data.size);
				//}
			}
			break;
			case _field_pageable_resource:
			{
				s_tag_resource tag_resource = *reinterpret_cast<const s_tag_resource*>(current_data_position);
				byteswap_helper_func(tag_resource);

				h_resource*& resource_storage = *reinterpret_cast<decltype(&resource_storage)>(high_level_field_data);
				

				c_tag_reader* tag_reader;
				if (BCS_FAILED(rs = cache_cluster.get_tag_reader(cache_file_reader, tag_reader)))
				{
					return rs;
				}
				

				unsigned short resource_index = tag_resource.resource_handle.get_absolute_index();
				if (resource_index != USHRT_MAX)
				{
					if (c_halo3_cache_file_reader* reader = dynamic_cast<c_halo3_cache_file_reader*>(&cache_file_reader))
					{
						c_halo3_tag_reader* tag_reader;
						BCS_RESULT get_tag_reader_result = reader->cache_cluster->get_tag_reader(*reader, tag_reader);
						ASSERT(BCS_SUCCEEDED(get_tag_reader_result));

						// #TODO: create a copy of this, or register these resources?
						// #TODO: should a reference be accumulated on assignment?
						// #TODO: how does the message system handle this?
						resource_storage = tag_reader->high_level_resources[resource_index];
					}
				}
			}
			break;
			case _field_api_interop:
			{
				s_tag_interop tag_interop = *reinterpret_cast<const s_tag_interop*>(current_data_position);
				byteswap_helper_func(tag_interop);

				h_interop*& interop_storage = *reinterpret_cast<decltype(&interop_storage)>(high_level_field_data);
				

				c_tag_reader* tag_reader;
				if (BCS_FAILED(rs = cache_cluster.get_tag_reader(cache_file_reader, tag_reader)))
				{
					return rs;
				}

				/*if (c_halo4_tag_reader* halo4_tag_reader = dynamic_cast<c_halo4_tag_reader*>(tag_reader))
				{
					

					e_halo4_interop_type interop_type = k_num_halo4_interop_types;
					if (field->struct_definition == &blofeld::polyartVertexBufferDescriptorStruct)
					{
						interop_type = _halo4_polyart_vertex_buffer_interop;
					}
					else if (field->struct_definition == &blofeld::polyartIndexBufferDescriptorStruct)
					{
						interop_type = _halo4_polyart_index_buffer_interop;
					}
					else if (field->struct_definition == &blofeld::vectorartVertexBufferDescriptorStruct)
					{
						interop_type = _halo4_vectorart_vertex_buffer_interop;
					}
					ASSERT(interop_type != k_num_halo4_interop_types);

					c_halo4_interop_container* interop_container = nullptr;
					halo4_tag_reader->get_interop_container_by_type_and_descriptor(interop_type, tag_interop.descriptor, interop_container);

					interop_storage = interop_container;

					
				}*/
			}
			break;
			case _field_vertex_buffer:
			{
				throw; // currently unused
			}
			case _field_pad:
			case _field_useless_pad:
			case _field_skip:
			case _field_non_cache_runtime_value:
			case _field_explanation:
			case _field_custom:
			case _field_terminator:
			{

			}
			}
		}

		current_data_position += field_size;
	}

	if (final_low_level_data_pos)
	{
		*final_low_level_data_pos = current_data_position;
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_tag_group(tag group_tag, h_group*& tag_group)
{
	for (h_group* current_tag_group : groups)
	{
		if (current_tag_group->tag_group.group_tag == group_tag)
		{
			tag_group = current_tag_group;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_cluster_transplant_instances(c_cache_file_reader& cache_file_reader, const t_transplant_instances*& transplant_instances)
{
	for (auto& instance_transplant_entry : instance_transplant_entries)
	{
		if (instance_transplant_entry.first == &cache_file_reader)
		{
			transplant_instances = &instance_transplant_entry.second;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}

//const blofeld::s_tag_struct_definition* inf_get_tag_struct_definition_by_persistent_id(const s_tag_persistent_identifier& persistent_identifier)
//{
//	for (const s_tag_struct_definition** tag_struct_definitions = blofeld::get_tag_struct_definitions({ _engine_type_infinite }); *tag_struct_definitions; tag_struct_definitions++)
//	{
//		const s_tag_struct_definition& tag_struct_definition = **tag_struct_definitions;
//
//		if (tag_struct_definition.persistent_identifier == persistent_identifier)
//		{
//			return &tag_struct_definition;
//		}
//	}
//
//	return nullptr;
//}

class c_module_file_transplant
{
public:
	c_high_level_cache_cluster_transplant& high_level_cache_cluster_transplant;
	s_engine_platform_build engine_platform_build;
	c_infinite_ucs_reader& ucs_reader;
	c_tag_instance& tag_instance;
	h_tag& root_high_level;
	const blofeld::s_tag_struct_definition& root_struct_definition;
	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_file_reader;
	c_infinite_string_id_manager infinite_string_id_manager;

	unsigned long root_struct_size;

	BCS_RESULT transplant_module_file_data(
		h_prototype& high_level,
		long tag_block_index,
		const char* const tag_block_data,
		long nugget_index,
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
			unsigned long field_skip_count;
			if (execute_tag_field_versioning(*field, engine_platform_build, blofeld::ANY_TAG, field_skip_count))
			{
				field += field_skip_count;
				continue;
			}

			//ptrdiff_t diff = current_data_position - low_level_data;
			//const char* field_type_str = field_to_string(field->field_type);
			//console_write_line("%X> %s::'%s' [%s]", static_cast<int>(diff), struct_definition.struct_name, field->name, field_type_str);

			void* high_level_field_data = high_level.get_field_data_unsafe(*field);

			unsigned long field_size = cache_file_reader.get_field_size(*field);

			if (high_level_field_data != nullptr)
			{
				switch (field->field_type)
				{
				case _field_string:							basic_memory_read(::c_static_string<32>);
				case _field_long_string:					basic_memory_read(::c_static_string<256>);
				case _field_char_integer:					basic_memory_read(char);
				case _field_short_integer:					basic_memory_read(short);
				case _field_long_integer:					basic_memory_read(long);
				case _field_int64_integer:					basic_memory_read(long long);
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
					long data = value;
					memcpy(high_level_field_data, &data, sizeof(data));
				}
				break;
				case _field_long_enum:
				{
					long data = *reinterpret_cast<const long*>(current_data_position);
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

					unsigned long const block_struct_size = cache_file_reader.calculate_struct_size(field->array_definition->struct_definition);

					unsigned long const array_elements_count = field->array_definition->count(engine_platform_build);
					for (unsigned long array_index = 0; array_index < array_elements_count; array_index++)
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
						const blofeld::s_tag_struct_definition& block_struct_definition = field->block_definition->struct_definition;
						unsigned long const block_struct_size = cache_file_reader.calculate_struct_size(block_struct_definition);
						unsigned long const total_block_struct_storage_size = block_struct_size * ucs_block_field.count;

						ASSERT(current_data_position != nullptr);
						ASSERT(tag_block_data != nullptr);
						long offset = static_cast<long>(current_data_position - tag_block_data);

						const s_infinite_ucs_tag_block_data* _tag_block_data = nullptr;
						long _tag_block_index = 01;
						for (unsigned long block_index = 0; block_index < ucs_reader.ucs_header->tag_block_count; block_index++)
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
							for (long block_index = 0; block_index < ucs_block_field.count; (block_index++, block_data_position += block_struct_size))
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
						long offset = static_cast<long>(current_data_position - tag_block_data);

						const s_infinite_ucs_data_reference_list* ucs_data_reference = nullptr;
						for (unsigned long data_index = 0; data_index < ucs_reader.ucs_header->data_reference_count; data_index++)
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

					if (ucs_tag_reference_field.group_tag == blofeld::INVALID_TAG)
					{
						tag_reference_storage->clear();
					}
					else
					{
						c_tag_instance* tag_instance = nullptr;
						if (BCS_FAILED(rs = cache_cluster.get_tag_instance_by_global_tag_id_and_group_tag(ucs_tag_reference_field.global_id, ucs_tag_reference_field.group_tag, tag_instance)))
						{
							tag_reference_storage->set_unqualified_path(ucs_tag_reference_field.group_tag, root_high_level.tag_filepath);
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

							const blofeld::s_tag_resource_definition& pageable_resource_definition = *field->tag_resource_definition;
							const blofeld::s_tag_struct_definition& pageable_resource_struct_definition = pageable_resource_definition.struct_definition;
							unsigned long const pageable_resource_struct_size = cache_file_reader.calculate_struct_size(pageable_resource_struct_definition);
							unsigned long const total_block_struct_storage_size = pageable_resource_struct_size;

							// read resource data
							auto& resource_file_entry_block_maps = infinite_tag_instance->file_entry_block_map.resource_file_entry_block_maps;
							//ASSERT(resource_file_entry_block_maps.size() >= 1);

							const void* tag_resource_data;
							unsigned long tag_resource_data_size;
							infinite_tag_instance->get_resource_data(tag_resource_data, tag_resource_data_size);

							const void* tag_header_data;
							unsigned long tag_header_data_size;
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
							long _tag_block_index = -1;
							const s_infinite_ucs_tag_block_data* _tag_block_data = nullptr;
							{
								ASSERT(current_data_position != nullptr);
								ASSERT(tag_block_data != nullptr);
								long offset = static_cast<long>(current_data_position - tag_block_data);

								for (unsigned long block_index = 0; block_index < ucs_reader.ucs_header->tag_block_count; block_index++)
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
							string_id_storage = buffer;
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

	c_module_file_transplant(
		c_high_level_cache_cluster_transplant& high_level_cache_cluster_transplant,
		s_engine_platform_build engine_platform_build,
		c_tag_instance& tag_instance,
		h_tag& root_high_level,
		const blofeld::s_tag_struct_definition& struct_definition,
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

	~c_module_file_transplant()
	{

	}

};

BCS_RESULT c_high_level_cache_cluster_transplant::transplant_module_file_data(
	c_tag_instance& tag_instance,
	h_tag& high_level,
	c_infinite_ucs_reader* ucs_reader,
	const char* low_level_data,
	c_cache_file_reader& cache_file_reader,
	const blofeld::s_tag_struct_definition& struct_definition)
{
	try
	{
		c_module_file_transplant module_file_transplant = c_module_file_transplant(
			*this,
			engine_platform_build,
			tag_instance,
			high_level,
			struct_definition,
			*ucs_reader,
			*static_cast<c_infinite_cache_cluster*>(&cache_cluster),
			*static_cast<c_infinite_module_file_reader*>(&cache_file_reader));
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}
