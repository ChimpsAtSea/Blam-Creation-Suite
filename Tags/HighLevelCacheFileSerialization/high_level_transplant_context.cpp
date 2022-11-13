#pragma once

#define SHITTY_ADDRESS_HACK(address) (address & 0xfffffff) 

using namespace blofeld;

template<typename t_value>
struct s_trivial_linear_heap_allocator
{
	size_t count;
	t_value* data;

	BCS_RESULT allocate(t_value*& value)
	{
		t_value* new_data = trivial_realloc(t_value, data, count + 1);
		if (new_data == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		data = new_data;
		value = data + count++;

		return BCS_S_OK;
	}

	BCS_RESULT emplace_back(t_value value, t_value** result = nullptr)
	{
		BCS_RESULT rs = BCS_S_OK;

		t_value* storage;
		if (BCS_FAILED(rs = allocate(storage)))
		{
			return rs;
		}

		*storage = value;

		if (result)
		{
			*result = storage;
		}

		return BCS_S_OK;
	}

	t_value* begin()
	{
		return data;
	}

	t_value* end()
	{
		return data + count;
	}
};

template<size_t max_count, typename t_value>
struct s_trivial_linear_fixed_allocator
{
	size_t count;
	t_value data[max_count];

	BCS_RESULT allocate(t_value*& value)
	{
		if (count >= max_count)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		value = data[count++];

		return BCS_S_OK;
	}

	BCS_RESULT emplace_back(t_value& value, t_value** result = nullptr)
	{
		BCS_RESULT rs = BCS_S_OK;

		t_value* storage;
		if (BCS_FAILED(rs = allocate(storage)))
		{
			return rs;
		}

		*storage = value;

		if (result)
		{
			*result = storage;
		}

		return BCS_S_OK;
	}

	t_value* begin()
	{
		return data;
	}

	t_value* end()
	{
		return data + count;
	}
};

struct s_cache_cluster_transplant_context
{
	s_trivial_linear_heap_allocator<c_cache_file_reader*> transplantable_cache_file_readers;
	s_trivial_linear_heap_allocator<h_group*> high_level_groups;
	s_trivial_linear_heap_allocator<h_tag*> high_level_instances;

	c_cache_cluster* cache_cluster;
	s_engine_platform_build engine_platform_build;
};

template<typename t_type>
BCS_RESULT transplant_trivial(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	//*static_cast<t_type*>(target) = *reinterpret_cast<t_type const*>(tag_data_position);
	//memcpy(target, tag_data_position, sizeof(t_type));

	tag_data_position += sizeof(t_type);
	return BCS_S_OK;
}

BCS_RESULT transplant_noop(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	return BCS_S_OK;
}

BCS_RESULT transplant_string_id(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(string_id);
	return BCS_S_OK;
}

BCS_RESULT transplant_pad(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += tag_field.padding;
	return BCS_S_OK;
}

BCS_RESULT transplant_skip(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += tag_field.length;
	return BCS_S_OK;
}

BCS_RESULT transplant_struct(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	ASSERT(target);
	return transplant_prototype(tag_data_start, tag_data_position, *static_cast<h_prototype*>(target));
}

BCS_RESULT transplant_array(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_enumerable* enumerable = dynamic_cast<h_enumerable*>(target);
	ASSERT(enumerable);
	for (unsigned int array_index = 0; array_index < enumerable->size(); array_index++)
	{
		h_prototype& prototype = enumerable->operator[](array_index);
		if (BCS_FAILED(transplant_prototype(tag_data_start, tag_data_position, prototype)))
		{
			return BCS_E_FAIL;
		}
	}
	return BCS_S_OK;
}

BCS_RESULT transplant_block(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_block* block = dynamic_cast<h_block*>(target);
	ASSERT(block);
	s_tag_block const& tag_block = *reinterpret_cast<const s_tag_block*>(tag_data_position);
	if (tag_block.count > 0)
	{
		block->resize(tag_block.count);
		dword address = tag_block.address.get_storage();
		dword offset = address & 0xfffffff;
		char const* block_data_position = static_cast<char const*>(tag_data_start) + offset;

		for (unsigned int block_index = 0; block_index < block->size(); block_index++)
		{
			h_prototype& prototype = block->operator[](block_index);
			if (BCS_FAILED(transplant_prototype(tag_data_start, block_data_position, prototype)))
			{
				return BCS_E_FAIL;
			}
		}

		debug_point;
	}

	tag_data_position += sizeof(s_tag_block);
	return BCS_S_OK;
}

BCS_RESULT transplant_data(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(s_tag_data);
	return BCS_S_OK;
}

BCS_RESULT transplant_reference(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(s_tag_reference);
	return BCS_S_OK;
}

BCS_RESULT transplant_api_interop(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT transplant_pageable_resource(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT transplant_pointer(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(int);
	return BCS_S_OK;
}

typedef BCS_RESULT(*t_transplant_field)(void const* const tag_data_start, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field);

static constexpr t_transplant_field transplant_field[k_number_of_blofeld_field_types] =
{
	transplant_trivial<::c_static_string<32>>,							//_field_string
	transplant_trivial<::c_static_string<256>>,							//_field_long_string
	transplant_string_id,												//_field_string_id
	transplant_string_id,												//_field_old_string_id
	transplant_trivial<char>,											//_field_char_integer
	transplant_trivial<short>,											//_field_short_integer
	transplant_trivial<long>,											//_field_long_integer
	transplant_trivial<int64_t>,										//_field_int64_integer
	transplant_trivial<angle>,											//_field_angle
	transplant_trivial<tag>,											//_field_tag
	transplant_trivial<char>,											//_field_char_enum
	transplant_trivial<short>,											//_field_short_enum
	transplant_trivial<long>,											//_field_long_enum
	transplant_trivial<long>,											//_field_long_flags
	transplant_trivial<word>,											//_field_word_flags
	transplant_trivial<byte>,											//_field_byte_flags
	transplant_trivial<::s_point2d>,									//_field_point_2d
	transplant_trivial<::s_rectangle2d>,								//_field_rectangle_2d
	transplant_trivial<::pixel32>,										//_field_rgb_color
	transplant_trivial<::pixel32>,										//_field_argb_color
	transplant_trivial<::real>,											//_field_real
	transplant_trivial<::real>,											//_field_real_slider
	transplant_trivial<::real_fraction>,								//_field_real_fraction
	transplant_trivial<::real_point2d>,									//_field_real_point_2d
	transplant_trivial<::real_point3d>,									//_field_real_point_3d
	transplant_trivial<::real_vector2d>,								//_field_real_vector_2d
	transplant_trivial<::real_vector3d>,								//_field_real_vector_3d
	transplant_trivial<::real_quaternion>,								//_field_real_quaternion
	transplant_trivial<::real_euler_angles2d>,							//_field_real_euler_angles_2d
	transplant_trivial<::real_euler_angles3d>,							//_field_real_euler_angles_3d
	transplant_trivial<::real_plane2d>,									//_field_real_plane_2d
	transplant_trivial<::real_plane3d>,									//_field_real_plane_3d
	transplant_trivial<::rgb_color>,									//_field_real_rgb_color
	transplant_trivial<::argb_color>,									//_field_real_argb_color
	transplant_trivial<::real_hsv_color>,								//_field_real_hsv_color
	transplant_trivial<::real_ahsv_color>,								//_field_real_ahsv_color
	transplant_trivial<::short_bounds>,									//_field_short_integer_bounds
	transplant_trivial<::angle_bounds>,									//_field_angle_bounds
	transplant_trivial<::real_bounds>,									//_field_real_bounds
	transplant_trivial<::real_fraction_bounds>,							//_field_real_fraction_bounds
	transplant_reference,												//_field_tag_reference
	transplant_block,													//_field_block
	transplant_trivial<long>,											//_field_long_block_flags
	transplant_trivial<word>,											//_field_word_block_flags
	transplant_trivial<byte>,											//_field_byte_block_flags
	transplant_trivial<char>,											//_field_char_block_index
	transplant_trivial<char>,											//_field_char_block_index_custom_search
	transplant_trivial<short>,											//_field_short_block_index
	transplant_trivial<short>,											//_field_short_block_index_custom_search
	transplant_trivial<long>,											//_field_long_block_index
	transplant_trivial<long>,											//_field_long_block_index_custom_search
	transplant_data,													//_field_data
	transplant_trivial<::s_tag_d3d_vertex_buffer>,						//_field_vertex_buffer
	transplant_pad,														//_field_pad
	nullptr,															//_field_useless_pad
	transplant_skip,													//_field_skip
	nullptr,															//_field_non_cache_runtime_value
	nullptr,															//_field_explanation
	nullptr,															//_field_custom
	transplant_struct,													//_field_struct
	transplant_array,													//_field_array
	transplant_pageable_resource,										//_field_pageable_resource
	transplant_api_interop,												//_field_api_interop
	nullptr,															//_field_terminator
	transplant_trivial<byte>,											//_field_byte_integer
	transplant_trivial<word>,											//_field_word_integer
	transplant_trivial<dword>,											//_field_dword_integer
	transplant_trivial<qword>,											//_field_qword_integer
	nullptr,															//_field_data_path
	nullptr,															//_field_embedded_tag
	transplant_pointer,													//_field_pointer
	transplant_trivial<short>,											//_field_half
};
static_assert(transplant_field[_field_string] == transplant_trivial<::c_static_string<32>>);
static_assert(transplant_field[_field_long_string] == transplant_trivial<::c_static_string<256>>);
static_assert(transplant_field[_field_string_id] == transplant_string_id);
static_assert(transplant_field[_field_old_string_id] == transplant_string_id);
static_assert(transplant_field[_field_char_integer] == transplant_trivial<char>);
static_assert(transplant_field[_field_short_integer] == transplant_trivial<short>);
static_assert(transplant_field[_field_long_integer] == transplant_trivial<long>);
static_assert(transplant_field[_field_int64_integer] == transplant_trivial<int64_t>);
static_assert(transplant_field[_field_angle] == transplant_trivial<angle>);
static_assert(transplant_field[_field_tag] == transplant_trivial<tag>);
static_assert(transplant_field[_field_char_enum] == transplant_trivial<char>);
static_assert(transplant_field[_field_short_enum] == transplant_trivial<short>);
static_assert(transplant_field[_field_long_enum] == transplant_trivial<long>);
static_assert(transplant_field[_field_long_flags] == transplant_trivial<long>);
static_assert(transplant_field[_field_word_flags] == transplant_trivial<word>);
static_assert(transplant_field[_field_byte_flags] == transplant_trivial<byte>);
static_assert(transplant_field[_field_point_2d] == transplant_trivial<::s_point2d>);
static_assert(transplant_field[_field_rectangle_2d] == transplant_trivial<::s_rectangle2d>);
static_assert(transplant_field[_field_rgb_color] == transplant_trivial<::pixel32>);
static_assert(transplant_field[_field_argb_color] == transplant_trivial<::pixel32>);
static_assert(transplant_field[_field_real] == transplant_trivial<::real>);
static_assert(transplant_field[_field_real_slider] == transplant_trivial<::real>);
static_assert(transplant_field[_field_real_fraction] == transplant_trivial<::real_fraction>);
static_assert(transplant_field[_field_real_point_2d] == transplant_trivial<::real_point2d>);
static_assert(transplant_field[_field_real_point_3d] == transplant_trivial<::real_point3d>);
static_assert(transplant_field[_field_real_vector_2d] == transplant_trivial<::real_vector2d>);
static_assert(transplant_field[_field_real_vector_3d] == transplant_trivial<::real_vector3d>);
static_assert(transplant_field[_field_real_quaternion] == transplant_trivial<::real_quaternion>);
static_assert(transplant_field[_field_real_euler_angles_2d] == transplant_trivial<::real_euler_angles2d>);
static_assert(transplant_field[_field_real_euler_angles_3d] == transplant_trivial<::real_euler_angles3d>);
static_assert(transplant_field[_field_real_plane_2d] == transplant_trivial<::real_plane2d>);
static_assert(transplant_field[_field_real_plane_3d] == transplant_trivial<::real_plane3d>);
static_assert(transplant_field[_field_real_rgb_color] == transplant_trivial<::rgb_color>);
static_assert(transplant_field[_field_real_argb_color] == transplant_trivial<::argb_color>);
static_assert(transplant_field[_field_real_hsv_color] == transplant_trivial<::real_hsv_color>);
static_assert(transplant_field[_field_real_ahsv_color] == transplant_trivial<::real_ahsv_color>);
static_assert(transplant_field[_field_short_integer_bounds] == transplant_trivial<::short_bounds>);
static_assert(transplant_field[_field_angle_bounds] == transplant_trivial<::angle_bounds>);
static_assert(transplant_field[_field_real_bounds] == transplant_trivial<::real_bounds>);
static_assert(transplant_field[_field_real_fraction_bounds] == transplant_trivial<::real_fraction_bounds>);
static_assert(transplant_field[_field_tag_reference] == transplant_reference);
static_assert(transplant_field[_field_block] == transplant_block);
static_assert(transplant_field[_field_long_block_flags] == transplant_trivial<long>);
static_assert(transplant_field[_field_word_block_flags] == transplant_trivial<word>);
static_assert(transplant_field[_field_byte_block_flags] == transplant_trivial<byte>);
static_assert(transplant_field[_field_char_block_index] == transplant_trivial<char>);
static_assert(transplant_field[_field_char_block_index_custom_search] == transplant_trivial<char>);
static_assert(transplant_field[_field_short_block_index] == transplant_trivial<short>);
static_assert(transplant_field[_field_short_block_index_custom_search] == transplant_trivial<short>);
static_assert(transplant_field[_field_long_block_index] == transplant_trivial<long>);
static_assert(transplant_field[_field_long_block_index_custom_search] == transplant_trivial<long>);
static_assert(transplant_field[_field_data] == transplant_data);
static_assert(transplant_field[_field_vertex_buffer] == transplant_trivial<::s_tag_d3d_vertex_buffer>);
static_assert(transplant_field[_field_pad] == transplant_pad);
static_assert(transplant_field[_field_useless_pad] == nullptr);
static_assert(transplant_field[_field_skip] == transplant_skip);
static_assert(transplant_field[_field_non_cache_runtime_value] == nullptr);
static_assert(transplant_field[_field_explanation] == nullptr);
static_assert(transplant_field[_field_custom] == nullptr);
static_assert(transplant_field[_field_struct] == transplant_struct);
static_assert(transplant_field[_field_array] == transplant_array);
static_assert(transplant_field[_field_pageable_resource] == transplant_pageable_resource);
static_assert(transplant_field[_field_api_interop] == transplant_api_interop);
static_assert(transplant_field[_field_terminator] == nullptr);
static_assert(transplant_field[_field_byte_integer] == transplant_trivial<byte>);
static_assert(transplant_field[_field_word_integer] == transplant_trivial<word>);
static_assert(transplant_field[_field_dword_integer] == transplant_trivial<dword>);
static_assert(transplant_field[_field_qword_integer] == transplant_trivial<qword>);
static_assert(transplant_field[_field_data_path] == nullptr);
static_assert(transplant_field[_field_embedded_tag] == nullptr);
static_assert(transplant_field[_field_pointer] == transplant_pointer);
static_assert(transplant_field[_field_half] == transplant_trivial<short>);

BCS_RESULT transplant_prototype(void const* const tag_data_start, char const*& tag_data_position, h_prototype& prototype)
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_tag_field const* const* tag_field_iterator = prototype.get_blofeld_field_list(); *tag_field_iterator; tag_field_iterator++)
	{
		s_tag_field const& tag_field = **tag_field_iterator;
		h_type* field_data = prototype.get_field_data(tag_field);
		
		if (t_transplant_field transplant_field_proc = transplant_field[tag_field.field_type])
		{
			if (BCS_FAILED(rs = transplant_field_proc(tag_data_start, tag_data_position, field_data, tag_field)))
			{
				return rs;
			}
			debug_point;
		}
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_instances_initialize_v2(s_cache_cluster_transplant_context*& context)
{
	BCS_RESULT rs = BCS_S_OK;

	for (c_cache_file_reader* cache_file_reader : context->transplantable_cache_file_readers)
	{
		c_tag_reader* tag_reader;
		if (BCS_FAILED(rs = context->cache_cluster->get_tag_reader(*cache_file_reader, tag_reader)))
		{
			return rs;
		}

		c_tag_instance** tag_instances = nullptr;
		uint32_t tag_instance_count = 0;
		if (BCS_FAILED(rs = tag_reader->get_tag_instances(tag_instances, tag_instance_count)))
		{
			return rs;
		}

		for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
		{
			c_tag_instance& tag_instance = *tag_instances[tag_instance_index];

			const char* tag_instance_name = nullptr;
			if (BCS_FAILED(rs = tag_instance.get_instance_name(tag_instance_name)))
			{
				return rs;
			}

			c_tag_group* tag_group = nullptr;
			if (BCS_FAILED(rs = tag_instance.get_tag_group(tag_group)))
			{
				return rs;
			}

			s_tag_group const* blofeld_tag_group;
			if (BCS_FAILED(rs = tag_group->get_blofeld_tag_group(blofeld_tag_group)))
			{
				return rs;
			}

			h_group* high_level_group = nullptr;
			for (h_group* _high_level_group : context->high_level_groups)
			{
				if (&_high_level_group->tag_group == blofeld_tag_group)
				{
					high_level_group = _high_level_group;
					break;
				}
			}
			if (high_level_group == nullptr)
			{
				return BCS_E_NOT_FOUND;
			}

			// #TODO: Convert over to use BCS_RESULT
			h_tag& high_level_tag = high_level_group->create_tag_instance(tag_instance_name);

			context->high_level_instances.emplace_back(&high_level_tag);

			debug_point;
		}

		for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
		{
			c_tag_instance& tag_instance = *tag_instances[tag_instance_index];
			h_tag& high_level_tag = *context->high_level_instances.data[tag_instance_index];

			const void* tag_data_root;
			const void* tag_data_start;
			const void* tag_data_end;
			if (BCS_FAILED(rs = tag_instance.get_tag_data(tag_data_root, tag_data_start, tag_data_end)))
			{
				return rs;
			}

			if (tag_instance_index == 0x000027c4)
			{
				const char* tag_data_position = static_cast<const char*>(tag_data_root);
				if (BCS_FAILED(transplant_prototype(tag_data_start/*, tag_data_end*/, tag_data_position, high_level_tag)))
				{
					continue;
				}
			}



			debug_point;
		}
		debug_point;
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_create_v2(c_cache_cluster& cache_cluster, s_cache_cluster_transplant_context*& context)
{
	BCS_RESULT rs = BCS_S_OK;
	if (context = trivial_malloc(s_cache_cluster_transplant_context, 1))
	{
		memset(context, 0, sizeof(*context));

		context->transplantable_cache_file_readers;
		context->high_level_groups;
		context->cache_cluster = &cache_cluster;
		if (BCS_FAILED(rs = context->cache_cluster->get_engine_platform_build(context->engine_platform_build)))
		{
			return rs;
		}
	}
	else
	{
		return BCS_E_OUT_OF_MEMORY;
	}
	return rs;
}

BCS_RESULT high_level_transplant_context_execute_v2(s_cache_cluster_transplant_context* context)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = high_level_transplant_init_transplant_entries_v2(context)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = high_level_transplant_context_groups_initialize_v2(context)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = high_level_transplant_context_instances_initialize_v2(context)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = high_level_transplant_context_instances_initialize_v2(context)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT high_level_transplant_init_transplant_entries_v2(s_cache_cluster_transplant_context* context)
{
	BCS_VALIDATE_ARGUMENT(context);

	BCS_RESULT rs = BCS_S_OK;

	c_cache_file_reader* const* cache_readers;
	uint32_t cache_reader_count;
	if (BCS_FAILED(rs = context->cache_cluster->get_cache_readers(cache_readers, cache_reader_count)))
	{
		return rs;
	}

	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_cache_file_reader& cache_file_reader = *cache_readers[cache_reader_index];

		c_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(context->cache_cluster->get_tag_reader(cache_file_reader, tag_reader)))
		{
			if (BCS_FAILED(rs = context->transplantable_cache_file_readers.emplace_back(&cache_file_reader)))
			{
				return rs;
			}
		}
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_groups_initialize_v2(s_cache_cluster_transplant_context* context)
{
	BCS_VALIDATE_ARGUMENT(context);

	BCS_RESULT rs = BCS_S_OK;

	t_tag_group_collection tag_groups;
	if (BCS_FAILED(rs = context->cache_cluster->get_blofeld_tag_groups(tag_groups)))
	{
		return rs;
	}

	for (t_tag_group_collection tag_group = tag_groups; *tag_group; tag_group++)
	{
		h_group* high_level_group = new() h_group(context->engine_platform_build, **tag_group);
		if (high_level_group == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		if (BCS_FAILED(rs = context->high_level_groups.emplace_back(high_level_group)))
		{
			return rs;
		}
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_destroy_v2(s_cache_cluster_transplant_context* context)
{



	return BCS_S_OK;
}
