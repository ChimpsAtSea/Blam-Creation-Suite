#include "mandrilllib-private-pch.h"

using namespace blofeld;

c_high_level_cache_file_transplant::c_high_level_cache_file_transplant(c_cache_cluster& cache_cluster, c_cache_file& cache_file) :
	cache_cluster(cache_cluster),
	cache_file(cache_file)
{
	// #TODO: Fix this. See fixes below.
	//for (uint32_t group_index = 0; group_index < cache_file.get_tag_group_count(); group_index++)
	//{
	//	c_tag_group_interface* tag_group_interface = cache_file.get_tag_group_interface(group_index);

	//	get_or_create_group(*tag_group_interface);
	//}

	for (c_tag_interface& tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	{
		h_tag* high_level_tag = tag_interface_to_high_level(tag_interface);

		if (high_level_tag == nullptr)
		{
			continue;
		}

		s_tag_pair tag_pair = { tag_interface, *high_level_tag };
		tags_and_interface.emplace_back(tag_pair);
	}

	auto transplant_high_level_tags = [this](uint32_t index)
	{
		s_tag_pair& tag_pair = tags_and_interface[index];

		h_tag& high_level_tag = tag_pair.high_level_tag;
		c_tag_interface& tag_interface = tag_pair.tag_interface;

		const char* raw_tag_data = tag_interface.get_data();

		const blofeld::s_tag_group* tag_group = tag_interface.get_blofeld_reflection_data();
		DEBUG_ASSERT(tag_group != nullptr);
		const blofeld::s_tag_struct_definition& tag_struct_definition = tag_group->block_definition.struct_definition;

		transplant_data(high_level_tag, raw_tag_data, tag_struct_definition);
	};
	//tbb::parallel_for(0u, static_cast<uint32_t>(tags_and_interface.size()), transplant_high_level_tags);
	for (uint32_t i = 0; i < tags_and_interface.size(); i++) transplant_high_level_tags(i);
}

c_high_level_cache_file_transplant::~c_high_level_cache_file_transplant()
{

}

void c_high_level_cache_file_transplant::transplant_data(h_object& high_level, const char* const low_level_data, const blofeld::s_tag_struct_definition& struct_definition)
{
	e_engine_type const engine_type = cache_file.get_engine_type();
	e_platform_type const platform_type = cache_file.get_platform_type();
	e_build const build = _build_not_set;

	const char* current_data_position = low_level_data;
	for (const s_tag_field* field = struct_definition.fields; field->field_type != _field_terminator; field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*field, engine_type, platform_type, build, field_skip_count))
		{
			field += field_skip_count;
			continue;
		}

		void* high_level_field_data = high_level.get_field_pointer(*field);

		uint32_t field_size = get_blofeld_field_size(*field, engine_type, platform_type, build);

		if (high_level_field_data != nullptr)
		{
			switch (field->field_type)
			{
			case _field_string:
			case _field_long_string:
			case _field_old_string_id:
			case _field_char_integer:
			case _field_short_integer:
			case _field_long_integer:
			case _field_int64_integer:
			case _field_angle:
			case _field_long_flags:
			case _field_word_flags:
			case _field_byte_flags:
			case _field_point_2d:
			case _field_rectangle_2d:
			case _field_rgb_color:
			case _field_argb_color:
			case _field_real:
			case _field_real_fraction:
			case _field_real_point_2d:
			case _field_real_point_3d:
			case _field_real_vector_2d:
			case _field_real_vector_3d:
			case _field_real_quaternion:
			case _field_real_euler_angles_2d:
			case _field_real_euler_angles_3d:
			case _field_real_plane_2d:
			case _field_real_plane_3d:
			case _field_real_rgb_color:
			case _field_real_argb_color:
			case _field_real_hsv_color:
			case _field_real_ahsv_color:
			case _field_short_bounds:
			case _field_angle_bounds:
			case _field_real_bounds:
			case _field_real_fraction_bounds:
			{
				memcpy(high_level_field_data, current_data_position, field_size);
				break;
			}			
			case _field_char_enum:
			{
				uint32_t data = *reinterpret_cast<const char*>(current_data_position);
				memcpy(high_level_field_data, &data, sizeof(data));
				break;
			}
			case _field_enum:
			{
				uint32_t data = *reinterpret_cast<const short*>(current_data_position);
				memcpy(high_level_field_data, &data, sizeof(data));
				break;
			}
			case _field_long_enum:
			{
				uint32_t data = *reinterpret_cast<const long*>(current_data_position);
				memcpy(high_level_field_data, &data, sizeof(data));
				break;
			}
			case _field_string_id:
			{
				if (const char* string_id_value = cache_file.get_string_id(*reinterpret_cast<const string_id*>(current_data_position)))
				{
					c_fixed_string_2048& string_id_storage = *reinterpret_cast<decltype(&string_id_storage)>(high_level_field_data);
					string_id_storage = string_id_value;
				}
				break;
			}
			case _field_block:
			{
				const blofeld::s_tag_struct_definition& block_struct_definition = field->block_definition->struct_definition;
				const s_tag_block& tag_block = *reinterpret_cast<decltype(&tag_block)>(current_data_position);

				h_block& block_storage = *reinterpret_cast<decltype(&block_storage)>(high_level_field_data);
				uint32_t const block_struct_size = calculate_struct_size(engine_type, platform_type, build, block_struct_definition);
				const char* const block_data = cache_file.get_tag_block_data(tag_block);

				if (tag_block.count < 1024)
				{
					block_storage.reserve(tag_block.count);

					const char* current_block_data_position = block_data;
					for (uint32_t block_index = 0; block_index < tag_block.count; block_index++)
					{
						h_object& type = block_storage.emplace_back();
						transplant_data(type, current_block_data_position, block_struct_definition);

						current_block_data_position += block_struct_size;
					}
				}
				else
				{
					block_storage.resize(tag_block.count);
					uint32_t high_level_block_type_size = block_storage.type_size();
					char* high_level_block_storage_data = reinterpret_cast<char*>(block_storage.data());

					auto transplant_high_level_block = [this, high_level_block_storage_data, high_level_block_type_size, block_data, block_struct_size, block_struct_definition](uint32_t index)
					{
						void* current_high_level_block_storage_data = high_level_block_storage_data + high_level_block_type_size * index;
						const void* current_block_data = block_data + block_struct_size * index;

						h_object& type = *static_cast<h_object*>(current_high_level_block_storage_data);
						transplant_data(type, block_data, block_struct_definition);
					};
					tbb::parallel_for(0u, static_cast<uint32_t>(tag_block.count), transplant_high_level_block);
				}

				break;
			}
			case _field_struct:
			{
				h_object& struct_storage = *reinterpret_cast<decltype(&struct_storage)>(high_level_field_data);
				transplant_data(struct_storage, current_data_position, *field->struct_definition);
				break;
			}
			case _field_array:
			{
				const char* raw_array_data_position = current_data_position;
				char* high_level_array_data_position = static_cast<char*>(high_level_field_data);

				uint32_t const array_elements_count = field->array_definition->count(engine_type);
				for (uint32_t array_index = 0; array_index < array_elements_count; array_index++)
				{
					h_object& array_storage = *reinterpret_cast<decltype(&array_storage)>(high_level_array_data_position);

					transplant_data(array_storage, raw_array_data_position, field->array_definition->struct_definition);

					high_level_array_data_position += array_storage.get_type_size();
					raw_array_data_position += field_size;
				}
				break;
			}
			case _field_tag_reference:
			{
				const s_tag_reference& tag_reference = *reinterpret_cast<decltype(&tag_reference)>(current_data_position);
				h_tag*& tag_ref_storage = *reinterpret_cast<decltype(&tag_ref_storage)>(high_level_field_data);

				c_tag_interface* tag_reference_tag_interface = cache_file.get_tag_interface(tag_reference.index);
				h_tag* tag_reference_high_level_tag = get_high_level_tag_by_tag_interface(tag_reference_tag_interface);

				tag_ref_storage = tag_reference_high_level_tag;
				break;
			}
			case _field_data:
			{
				const s_tag_data& tag_data = *reinterpret_cast<decltype(&tag_data)>(current_data_position);
				std::vector<char>& data_storage = *reinterpret_cast<decltype(&data_storage)>(high_level_field_data);
				
				const char* tag_data_data = cache_file.get_tag_data(tag_data);
				if (tag_data_data != nullptr)
				{
					data_storage.clear();
					data_storage.insert(data_storage.begin(), tag_data_data, tag_data_data + tag_data.size);
				}
				debug_point;
				break;
			}
			}
		}

		current_data_position += field_size;
	}
}

h_tag* c_high_level_cache_file_transplant::get_high_level_tag_by_tag_interface(c_tag_interface* tag_interface)
{
	if (tag_interface == nullptr)
	{
		return nullptr;
	}
	if (tag_interface->is_null())
	{
		return nullptr;
	}

	for (s_tag_pair& tag_pair : tags_and_interface)
	{
		if (tag_interface == &tag_pair.tag_interface)
		{
			return &tag_pair.high_level_tag;
		}
	}

	return nullptr;
}

h_tag* c_high_level_cache_file_transplant::tag_interface_to_high_level(c_tag_interface& tag_interface)
{
	if (tag_interface.is_null())
	{
		return nullptr;
	}

	// #TODO: Fix this, currently returns null.
	//c_tag_group_interface* group_interface = tag_interface.get_tag_group_interface();
	//DEBUG_ASSERT(group_interface != nullptr);

	c_virtual_tag_interface* virtual_tag_interface = tag_interface.get_virtual_tag_interface();
	DEBUG_ASSERT(virtual_tag_interface != nullptr);

	const blofeld::s_tag_group* tag_group = virtual_tag_interface->tag_interface.get_blofeld_reflection_data();
	DEBUG_ASSERT(tag_group != nullptr);

	h_group& group = get_or_create_group(*tag_group);

	const char* filepath = tag_interface.get_path_with_group_name_cstr();
	h_tag& high_level_tag = group.create_tag_instance(filepath);

	return &high_level_tag;
}

h_group& c_high_level_cache_file_transplant::get_or_create_group(/*c_tag_group_interface& group_interface*/ const blofeld::s_tag_group& tag_group)
{
	for (s_group_pair& group_pair : groups_and_interface)
	{
		if (&tag_group == &group_pair.tag_group)
		{
			return group_pair.high_level_group;
		}
	}

	// #TODO: Fix this, currently returns null.
	//const blofeld::s_tag_group* tag_group = group_interface.get_blofeld_tag_group();
	//DEBUG_ASSERT(tag_group != nullptr);

	e_engine_type const engine_type = cache_file.get_engine_type();
	e_platform_type const platform_type = cache_file.get_platform_type();
	e_build const build = _build_not_set;

	h_group* group = new h_group(engine_type, platform_type, build, tag_group);

	s_group_pair group_pair = { /*group_interface*/ tag_group, *group };
	groups_and_interface.emplace_back(group_pair);

	return *group;
}
