#include "mandrilllib-private-pch.h"

using namespace blofeld;

c_high_level_cache_cluster_transplant::c_high_level_cache_cluster_transplant(c_halo4_cache_cluster& cache_cluster) :
	cache_cluster(cache_cluster)
{
	BCS_RESULT rs;

	if (BCS_FAILED(rs = init_tag_group_hierarchy()))
	{
		throw(rs);
	}

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
	////for (uint32_t group_index = 0; group_index < cache_file.get_tag_group_count(); group_index++)
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

	//auto transplant_high_level_tags = [this](uint32_t index)
	//{
	//	s_tag_pair& tag_pair = tags_and_interface[index];

	//	h_tag& high_level_tag = tag_pair.high_level_tag;
	//	c_tag_interface& tag_interface = tag_pair.tag_interface;

	//	const char* raw_tag_data = tag_interface.get_data();

	//	const blofeld::s_tag_group* tag_group = tag_interface.get_blofeld_reflection_data();
	//	DEBUG_ASSERT(tag_group != nullptr);
	//	const blofeld::s_tag_struct_definition& tag_struct_definition = tag_group->block_definition.struct_definition;

	//	transplant_data(high_level_tag, raw_tag_data, tag_struct_definition);
	//};
	////tbb::parallel_for(0u, static_cast<uint32_t>(tags_and_interface.size()), transplant_high_level_tags);
	//for (uint32_t i = 0; i < tags_and_interface.size(); i++) transplant_high_level_tags(i);
}

c_high_level_cache_cluster_transplant::~c_high_level_cache_cluster_transplant()
{

}

BCS_RESULT c_high_level_cache_cluster_transplant::init_transplant_entries()
{
	for (s_halo4_cache_cluster_entry& cluster_entry : cache_cluster.entries)
	{
		c_halo4_cache_file_reader& cache_reader = *cluster_entry.cache_reader;
		c_halo4_tag_reader* tag_reader = cluster_entry.tag_reader;

		s_cache_file_buffer_info tag_section_buffer;
		if (BCS_SUCCEEDED(cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer))) // skip cache files without tags
		{
			ASSERT(tag_reader != nullptr);
			transplant_entries.push_back(&cluster_entry);
		}
		else
		{
			debug_point;
		}
	}

	return BCS_S_OK;
}

BCS_RESULT c_high_level_cache_cluster_transplant::init_tag_group_hierarchy()
{
	for (s_halo4_tag_group_hierarchy** tag_group_hierarchy_iterator = halo4_tag_group_hierarchy; *tag_group_hierarchy_iterator; tag_group_hierarchy_iterator++) // load tag groups without parents first
	{
		s_halo4_tag_group_hierarchy& tag_group_hierarchy = **tag_group_hierarchy_iterator;
		init_tag_group_hierarchy_impl(tag_group_hierarchy);

		debug_point;
	}

	return BCS_S_OK;
}

h_group* c_high_level_cache_cluster_transplant::init_tag_group_hierarchy_impl(s_halo4_tag_group_hierarchy& tag_group_hierarchy)
{
	//c_halo4_tag_group* tag_group;
	//if (BCS_FAILED(get_tag_group(tag_group_hierarchy.group_tag, tag_group)))
	//{
	//	c_halo4_tag_group* super_parent = nullptr;
	//	if (tag_group_hierarchy.parents[1] != nullptr)
	//	{
	//		super_parent = init_tag_group_hierarchy_impl(*tag_group_hierarchy.parents[1]);
	//	}

	//	c_halo4_tag_group* parent = nullptr;
	//	if (tag_group_hierarchy.parents[0] != nullptr)
	//	{
	//		parent = init_tag_group_hierarchy_impl(*tag_group_hierarchy.parents[0]);
	//		DEBUG_ASSERT(parent->parent == super_parent); // sanity check
	//	}

	//	tag_group = new c_halo4_tag_group(cache_cluster, tag_group_hierarchy.group_tag, tag_group_hierarchy.group_name, parent);
	//	groups.push_back(tag_group);
	//}

	h_group* high_level_group;
	if (BCS_SUCCEEDED(get_tag_group(tag_group_hierarchy.group_tag, high_level_group)))
	{
		return high_level_group;
	}

	const blofeld::s_tag_group* blofeld_tag_group = blofeld::get_group_tag_by_group_tag(cache_cluster.engine_platform_build.engine_type, tag_group_hierarchy.group_tag);

	if (blofeld_tag_group != nullptr)
	{
		high_level_group = new h_group(cache_cluster.engine_platform_build, *blofeld_tag_group);
		groups.push_back(high_level_group);
	}
	else
	{
		c_console::write_line("warning: failed to find blofeld definition for group '%s'", tag_group_hierarchy.group_name);
	}

	debug_point;

	return high_level_group;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_tag_by_index(const s_halo4_cache_cluster_entry& cache_cluster_entry, unsigned long tag_index, h_tag*& tag)
{
	BCS_RESULT rs = BCS_S_OK;
	const t_transplant_instances* transplant_instances;
	if (BCS_FAILED(rs = get_cluster_transplant_instances(&cache_cluster_entry, transplant_instances)))
	{
		return rs;
	}

	if (tag_index == 0xFFFFu)
	{
		tag = nullptr;
	}
	else if (static_cast<size_t>(tag_index) < transplant_instances->size())
	{
		tag = (*transplant_instances)[tag_index];
	}
	else
	{
		rs = BCS_E_FAIL;
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::get_tag_by_group_and_filename(h_group& group, const char* filename, h_tag*& tag)
{
	return BCS_E_FAIL;
}

BCS_RESULT c_high_level_cache_cluster_transplant::init_tag_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_halo4_cache_cluster_entry* cluster_entry : transplant_entries)
	{
		c_halo4_tag_reader& tag_reader = *cluster_entry->tag_reader;

		for (unsigned long group_index = 0; group_index < tag_reader.group_count; group_index++)
		{
			s_halo4_tag_group_info& group_info = tag_reader.groups[group_index];

			h_group* high_level_group;
			if (BCS_FAILED(rs = get_tag_group(group_info.group.group_tags[0], high_level_group)))
			{
				c_console::write_line("missing referenced tag group '%s'", group_info.group_name);
				// all groups should be initialized inside of init_tag_group_hierarchy_impl
				//return rs;
			}

			debug_point;
		}
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::init_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_halo4_cache_cluster_entry* cluster_entry : transplant_entries)
	{
		c_halo4_tag_reader& tag_reader = *cluster_entry->tag_reader;

		std::pair<s_halo4_cache_cluster_entry*, std::vector<h_tag*>>& instance_transplant_entry = instance_transplant_entries.emplace_back();
		instance_transplant_entry.first = cluster_entry;
		std::vector<h_tag*>& tag_instances = instance_transplant_entry.second;

		for (unsigned long instance_index = 0; instance_index < tag_reader.instance_count; instance_index++)
		{
			s_halo4_tag_instance_info& tag_instance_info = tag_reader.instances[instance_index];
			h_group* group;
			if (BCS_FAILED(rs = get_tag_group(tag_instance_info.group_info->group.group_tags[0], group)))
			{
				c_console::write_line("missing instance tag group '%s'", tag_instance_info.group_info->group_name);
				return rs;
			}

			h_tag& high_level_tag = group->create_tag_instance(tag_instance_info.instance_name);

			tag_instances.push_back(&high_level_tag);
			instances.push_back(&high_level_tag);

			debug_point;
		}
		break; // only do the first map at the moment
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::transplant_instance_data()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_halo4_cache_cluster_entry* cluster_entry : transplant_entries)
	{
		c_halo4_cache_file_reader& cache_reader = *cluster_entry->cache_reader;
		c_halo4_tag_reader& tag_reader = *cluster_entry->tag_reader;

		s_cache_file_buffer_info tag_section_buffer;
		if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
		{
			// #NOTE: this is expected to always succeed as we shouldn't have added any cache files without this
			// section to transplant_entries
			return rs;
		}

		const t_transplant_instances* transplant_instances;
		if (BCS_FAILED(rs = get_cluster_transplant_instances(cluster_entry, transplant_instances)))
		{
			return rs;
		}

		for (unsigned long instance_index = 0; instance_index < tag_reader.instance_count; instance_index++)
		{
			s_halo4_tag_instance_info& tag_instance_info = tag_reader.instances[instance_index];

			h_tag& high_level_tag = *(*transplant_instances)[instance_index];

			int64_t virtual_address;
			if (BCS_FAILED(rs = cache_reader.page_offset_to_virtual_address(tag_instance_info.instance.address, virtual_address)))
			{
				return rs;
			}

			int32_t relative_offset;
			if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(virtual_address, relative_offset)))
			{
				return rs;
			}

			const char* data = tag_section_buffer.begin + relative_offset;

			if (BCS_FAILED(rs = transplant_data(high_level_tag, data, *cluster_entry, cache_reader, high_level_tag.get_blofeld_struct_definition())))
			{
				c_console::write_line("failed to transplant tag '%s.%s'", high_level_tag.tag_filename, high_level_tag.group->tag_group.name);
				//return rs; //#TODO: enable this!
			}

			debug_point;
		}
		break; // only do the first map at the moment
	}

	return rs;
}

BCS_RESULT c_high_level_cache_cluster_transplant::transplant_data(h_object& high_level, const char* const low_level_data, s_halo4_cache_cluster_entry& cluster_entry, c_halo4_cache_file_reader& cache_reader, const blofeld::s_tag_struct_definition& struct_definition)
{
	BCS_RESULT rs = BCS_S_OK;

#define use_byteswap() (cache_reader.engine_platform_build.platform_type == _platform_type_xbox_360)
#define byteswap_helper_func(value) if (use_byteswap()) byteswap(value)
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
		uint32_t field_skip_count;
		if (skip_tag_field_version(*field, cache_cluster.engine_platform_build, field_skip_count))
		{
			field += field_skip_count;
			continue;
		}

		//ptrdiff_t diff = current_data_position - low_level_data;
		//const char* field_type_str = field_to_string(field->field_type);
		//c_console::write_line("%X> %s::'%s' [%s]", static_cast<int>(diff), struct_definition.struct_name, field->name, field_type_str);

		void* high_level_field_data = high_level.get_field_data(*field);

		uint32_t field_size = get_blofeld_field_size(*field, cache_cluster.engine_platform_build);

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
			case _field_short_bounds:					basic_memory_read(::short_bounds);
			case _field_angle_bounds:					basic_memory_read(::angle_bounds);
			case _field_real_bounds:					basic_memory_read(::real_bounds);
			case _field_real_fraction_bounds:			basic_memory_read(::real_fraction_bounds);
			case _field_long_block_flags:				basic_memory_read(long);
			case _field_word_block_flags:				basic_memory_read(word);
			case _field_byte_block_flags:				basic_memory_read(byte);
			case _field_char_block_index:				basic_memory_read(char);
			case _field_custom_char_block_index:		basic_memory_read(char);
			case _field_short_block_index:				basic_memory_read(short);
			case _field_custom_short_block_index:		basic_memory_read(short);
			case _field_long_block_index:				basic_memory_read(long);
			case _field_custom_long_block_index:		basic_memory_read(long);
			case _field_byte_integer:					basic_memory_read(byte);
			case _field_word_integer:					basic_memory_read(word);
			case _field_dword_integer:					basic_memory_read(dword);
			case _field_qword_integer:					basic_memory_read(qword);
			case _field_string_id:
			case _field_old_string_id:
			{
				c_halo4_debug_reader* debug_reader;
				if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
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
					//c_console::write_line("warning: failed to find stringid 0x%08X [%s::%s]", string_id, struct_definition.name, field->name);

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
			case _field_enum:
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
				uint32_t const block_struct_size = calculate_struct_size(cache_reader.engine_platform_build, block_struct_definition);

				block_storage.clear();

				DEBUG_ASSERT(tag_block.count != 0xCDCDCDCD);
				if (tag_block.count > 0)
				{
					DEBUG_ASSERT(tag_block.address != 0xCDCDCDCD);
				}

				if (tag_block.count > 0)
				{
					block_storage.reserve(tag_block.count);

					const char* block_data;
					{ // #TODO: function abstraction for this?

						s_cache_file_buffer_info tag_section_buffer;
						if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
						{
							// #NOTE: this is expected to always succeed as we shouldn't have added any cache files without this
							// section to transplant_entries
							return rs;
						}

						int64_t virtual_address;
						if (BCS_FAILED(rs = cache_reader.page_offset_to_virtual_address(tag_block.address, virtual_address)))
						{
							return rs;
						}

						int32_t relative_offset;
						if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(virtual_address, relative_offset)))
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
						for (uint32_t block_index = 0; block_index < tag_block.count; block_index++)
						{
							h_object& type = block_storage.emplace_back();
							transplant_data(type, current_block_data_position, cluster_entry, cache_reader, block_struct_definition);

							current_block_data_position += block_struct_size;
						}
					}
					//else
					//{
					//	block_storage.resize(tag_block.count);

					//	auto transplant_high_level_block = [this, &block_storage, block_data, block_struct_size, block_struct_definition](uint32_t index)
					//	{
					//		const void* current_block_data = block_data + block_struct_size * index;

					//		h_object& type = block_storage.get(index);
					//		transplant_data(type, block_data, block_struct_definition);
					//	};
					//	tbb::parallel_for(0u, static_cast<uint32_t>(tag_block.count), transplant_high_level_block);
					//}

					debug_point;
				}
				debug_point;

			}
			break;
			case _field_pointer:
			{
				uint32_t pointer_size;
				ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(cache_reader.engine_platform_build.platform_type, &pointer_size)));
				switch (pointer_size)
				{
				case 4: basic_memory_read(dword);
				case 8: basic_memory_read(qword);
				default: FATAL_ERROR(L"Unknown pointer size");
				}
			}
			break;
			case _field_struct:
			{
				h_object& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
				transplant_data(struct_storage, current_data_position, cluster_entry, cache_reader, *field->struct_definition);
			}
			break;
			case _field_array:
			{
				h_enumerable& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_field_data);
				const char* raw_array_data_position = current_data_position;

				uint32_t const array_elements_count = field->array_definition->count(cache_cluster.engine_platform_build);
				for (uint32_t array_index = 0; array_index < array_elements_count; array_index++)
				{
					h_object& array_element_storage = array_storage[array_index];

					transplant_data(array_element_storage, raw_array_data_position, cluster_entry, cache_reader, field->array_definition->struct_definition);

					raw_array_data_position += array_element_storage.get_low_level_type_size();
				}
			}
			break;
			case _field_tag_reference:
			{
				s_tag_reference tag_reference = *reinterpret_cast<const s_tag_reference*>(current_data_position);
				byteswap_helper_func(tag_reference);

				h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);

				unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_reference.datum_index);

				//c_tag_interface* tag_reference_tag_interface = cache_file.get_tag_interface(tag_reference.index);
				//h_tag* tag_reference_high_level_tag = get_high_level_tag_by_tag_interface(tag_reference_tag_interface);

				h_tag* tag_reference_high_level_tag;
				if (BCS_FAILED(rs = get_tag_by_index(cluster_entry, tag_index, tag_reference_high_level_tag)))
				{
					return rs;
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
			case _field_pageable:
			{
				s_tag_resource tag_resource = *reinterpret_cast<const s_tag_resource*>(current_data_position);
				byteswap_helper_func(tag_resource);

				h_resource*& resource_storage = *reinterpret_cast<decltype(&resource_storage)>(high_level_field_data);
				debug_point;

				c_halo4_tag_reader* tag_reader;
				if (BCS_FAILED(rs = cache_cluster.get_tag_reader(cache_reader, tag_reader)))
				{
					return rs;
				}
				debug_point;

				h_resource* resource_container = nullptr;

				// #TODO

				resource_storage = resource_container;
			}
			break;
			case _field_api_interop:
			{
				s_tag_interop tag_interop = *reinterpret_cast<const s_tag_interop*>(current_data_position);
				byteswap_helper_func(tag_interop);

				h_interop*& interop_storage = *reinterpret_cast<decltype(&interop_storage)>(high_level_field_data);
				debug_point;

				c_halo4_tag_reader* tag_reader;
				if (BCS_FAILED(rs = cache_cluster.get_tag_reader(cache_reader, tag_reader)))
				{
					return rs;
				}
				debug_point;

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
				tag_reader->get_interop_container_by_type_and_descriptor(interop_type, tag_interop.descriptor, interop_container);

				interop_storage = interop_container;

				debug_point;
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

BCS_RESULT c_high_level_cache_cluster_transplant::get_cluster_transplant_instances(const s_halo4_cache_cluster_entry* cache_cluster_entry, const t_transplant_instances*& transplant_instances)
{
	for (auto& instance_transplant_entry : instance_transplant_entries)
	{
		if (instance_transplant_entry.first == cache_cluster_entry)
		{
			transplant_instances = &instance_transplant_entry.second;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}
