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

	BCS_RESULT allocate_many(size_t _count, t_value** values)
	{
		t_value* new_data = trivial_realloc(t_value, data, count + _count);
		if (new_data == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		data = new_data;
		if (values)
		{
			*values = data + count;
		}
		count += _count;

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

	BCS_RESULT resize(size_t _count)
	{
		count += _count;

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
	volatile unsigned int barrier;
	volatile unsigned int transplant_tag_instance_index;

	s_trivial_linear_heap_allocator<c_cache_file_reader*> transplantable_cache_file_readers;
	s_trivial_linear_heap_allocator<h_tag_group*> high_level_tag_groups;
	s_trivial_linear_heap_allocator<h_tag_instance*> high_level_tag_instances;
	s_trivial_linear_heap_allocator<c_tag_instance*> low_level_tag_instances;

	c_cache_cluster* cache_cluster;
	s_engine_platform_build engine_platform_build;

	BCS_RESULT volatile bcs_result;
};

BCS_RESULT high_level_transplant_context_get_transplantable_cache_file_readers(
	s_cache_cluster_transplant_context& context,
	c_cache_file_reader**& cache_file_readers,
	unsigned int& num_cache_file_readers)
{
	cache_file_readers = context.transplantable_cache_file_readers.data;
	num_cache_file_readers = context.transplantable_cache_file_readers.count;

	return BCS_S_OK;
}

BCS_RESULT high_level_transplant_context_get_high_level_tag_groups(
	s_cache_cluster_transplant_context& context,
	h_tag_group**& tag_groups,
	unsigned int& num_tag_groups)
{
	tag_groups = context.high_level_tag_groups.data;
	num_tag_groups = context.high_level_tag_groups.count;

	return BCS_S_OK;
}

BCS_RESULT high_level_transplant_context_get_high_level_tag_instances(
	s_cache_cluster_transplant_context& context,
	h_tag_instance**& tag_instances,
	unsigned int& num_tag_instances)
{
	tag_instances = context.high_level_tag_instances.data;
	num_tag_instances = context.high_level_tag_instances.count;

	return BCS_S_OK;
}

BCS_RESULT high_level_transplant_context_get_global_tag_by_low_level_tag_instance(
	s_cache_cluster_transplant_context& context,
	c_tag_instance& low_level_tag_instance,
	h_tag_instance*& out_high_level_tag_instance)
{
	ASSERT(context.high_level_tag_instances.count == context.low_level_tag_instances.count); // validation

	unsigned int tag_instance_count = context.high_level_tag_instances.count;
	for (unsigned int tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
	{
		if (&low_level_tag_instance == context.low_level_tag_instances.data[tag_instance_index])
		{
			out_high_level_tag_instance = context.high_level_tag_instances.data[tag_instance_index];

			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

template<typename t_type>
BCS_RESULT transplant_trivial(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_field* field = high_level_cast<h_field*>(target);
	ASSERT(field != nullptr);
	void* field_data = field->get_data();
	ASSERT(field_data != nullptr);
	memcpy(field_data, tag_data_position, sizeof(t_type));

	tag_data_position += sizeof(t_type);
	return BCS_S_OK;
}

BCS_RESULT transplant_noop(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	return BCS_S_OK;
}

BCS_RESULT transplant_string_id(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	BCS_RESULT rs = BCS_S_OK;

	string_id const& string_identifier = *reinterpret_cast<const string_id*>(tag_data_position);

	h_string_id_field* high_level_string_id = high_level_cast<h_string_id_field*>(target);
	ASSERT(high_level_string_id != nullptr);

	c_tag_reader* tag_reader;
	if (BCS_SUCCEEDED(rs = tag_instance.get_tag_file_reader(tag_reader)))
	{
		c_cache_cluster* cache_cluster;
		if (BCS_SUCCEEDED(rs = tag_reader->get_cache_cluster(cache_cluster)))
		{
			c_cache_file_reader* cache_file_reader;
			if (BCS_SUCCEEDED(rs = tag_reader->get_cache_file_reader(cache_file_reader)))
			{
				c_debug_reader* debug_reader;
				if (BCS_SUCCEEDED(rs = cache_cluster->get_debug_reader(*cache_file_reader, debug_reader)))
				{
					const char* string;
					if (BCS_SUCCEEDED(rs = debug_reader->string_id_to_string(string_identifier, string)))
					{
						high_level_string_id->set_string(string);
					}
				}
			}
		}
	}
	
	tag_data_position += sizeof(string_id);
	return rs;
}

BCS_RESULT transplant_pad(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += tag_field.padding;
	return BCS_S_OK;
}

BCS_RESULT transplant_skip(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += tag_field.length;
	return BCS_S_OK;
}

BCS_RESULT transplant_struct(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_prototype* prototype = high_level_cast<h_prototype*>(target);
	ASSERT(prototype != nullptr);// #TODO: Remove this, replace with `static_cast`
	return transplant_prototype(tag_instance, tag_data_position, *prototype);
}

BCS_RESULT transplant_array(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_array* high_level_array = high_level_cast<h_array*>(target);
	ASSERT(high_level_array != nullptr);

	unsigned int const array_size = high_level_array->get_count();
	for (unsigned int array_index = 0; array_index < array_size; array_index++)
	{
		h_prototype& prototype = high_level_array->operator[](array_index);
		if (BCS_FAILED(transplant_prototype(tag_instance, tag_data_position, prototype)))
		{
			return BCS_E_FAIL;
		}
	}

	return BCS_S_OK;
}

BCS_RESULT transplant_block(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_block* high_level_block = high_level_cast<h_block*>(target);
	ASSERT(high_level_block != nullptr);

	s_tag_block const& tag_block = *reinterpret_cast<const s_tag_block*>(tag_data_position);
	if (tag_block.count > 0)
	{
		unsigned address_segment = tag_block.address.get_storage() >> 28;
		ASSERT(address_segment == 4);

		const void* tag_data_root;
		const void* tag_data_start;
		const void* tag_data_end;
		ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_data(tag_data_root, tag_data_start, tag_data_end)));

		high_level_block->clear();
		h_prototype** elements = high_level_block->create_elements(tag_block.count);
		dword address = tag_block.address.get_storage();
		dword offset = address & 0xfffffff;
		char const* block_data_position = static_cast<char const*>(tag_data_start) + offset;

		for (unsigned int block_index = 0; block_index < tag_block.count; block_index++)
		{
			h_prototype& prototype = *elements[block_index];
			if (BCS_FAILED(transplant_prototype(tag_instance, block_data_position, prototype)))
			{
				return BCS_E_FAIL;
			}
		}
	}

	tag_data_position += sizeof(s_tag_block);
	return BCS_S_OK;
}

BCS_RESULT transplant_data(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	h_data* high_level_data = high_level_cast<h_data*>(target);
	ASSERT(high_level_data != nullptr);

	s_tag_data const& tag_data = *reinterpret_cast<const s_tag_data*>(tag_data_position);

	high_level_data->clear();
	if (tag_data.size > 0)
	{
		const void* tag_data_root;
		const void* tag_data_start;
		const void* tag_data_end;
		ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_data(tag_data_root, tag_data_start, tag_data_end)));

		dword address = tag_data.address.get_storage();
		dword offset = address & 0xfffffff;

		char const* source_data = static_cast<char const*>(tag_data_start) + offset;
		char* destination_data = high_level_data->append_elements(source_data, tag_data.size);
	}

	tag_data_position += sizeof(s_tag_data);
	return BCS_S_OK;
}

BCS_RESULT transplant_reference(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(s_tag_reference);
	return BCS_S_OK;
}

BCS_RESULT transplant_api_interop(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT transplant_pageable_resource(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	s_tag_resource const& tag_resource = *reinterpret_cast<const s_tag_resource*>(tag_data_position);

	unsigned int address = tag_resource.resource_handle.get_value();
	unsigned int address_segment = address >> 28;

	const void* tag_data_root;
	const void* tag_data_start;
	const void* tag_data_end;
	ASSERT(BCS_SUCCEEDED(tag_instance.get_tag_data(tag_data_root, tag_data_start, tag_data_end)));

	dword offset = address & 0xfffffff;
	char const* resource_data_position = static_cast<char const*>(tag_data_start) + offset;

	c_eldorado_resource_handle* eldorado_resource_handle = new c_eldorado_resource_handle();
	transplant_prototype(tag_instance, resource_data_position, eldorado_resource_handle->resource_location);
	transplant_prototype(tag_instance, resource_data_position, eldorado_resource_handle->resource_data);

	h_resource_field* resource_field = high_level_cast<h_resource_field*>(target);
	ASSERT(resource_field != nullptr);
	resource_field->set_resource(eldorado_resource_handle);

	tag_data_position += sizeof(::s_tag_resource);
	return BCS_S_OK;
}

BCS_RESULT transplant_pointer(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field)
{
	tag_data_position += sizeof(int);
	return BCS_S_OK;
}

typedef BCS_RESULT(*t_transplant_field)(c_tag_instance& tag_instance, char const*& tag_data_position, h_type* target, s_tag_field const& tag_field);

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


BCS_RESULT transplant_prototype(c_tag_instance& tag_instance, char const*& tag_data_position, h_prototype& prototype)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int serialization_count;
	h_serialization_info const* serialization_infos = prototype.get_serialization_information(serialization_count);
	for (unsigned int serialization_index = 0; serialization_index < serialization_count; serialization_index++)
	{
		h_serialization_info const& serialization_info = serialization_infos[serialization_index];
		s_tag_field const& tag_field = serialization_info.tag_field;

		if (t_transplant_field transplant_field_proc = transplant_field[tag_field.field_type])
		{
			h_type* field_data = serialization_info.pointer_to_member ? &(prototype.*serialization_info.pointer_to_member) : nullptr;
			if (BCS_FAILED(rs = transplant_field_proc(tag_instance, tag_data_position, field_data, tag_field)))
			{
				return rs;
			}

		}
	}

	//for (s_tag_field const* const* tag_field_iterator = prototype.get_blofeld_field_list(); *tag_field_iterator; tag_field_iterator++)
	//{
	//	s_tag_field const& tag_field = **tag_field_iterator;
	//	h_type* field_data = prototype.get_field_data(tag_field);
	//	
	//	if (t_transplant_field transplant_field_proc = transplant_field[tag_field.field_type])
	//	{
	//		if (BCS_FAILED(rs = transplant_field_proc(tag_data_start, tag_data_position, field_data, tag_field)))
	//		{
	//			return rs;
	//		}
	//		
	//	}
	//}

	return rs;
}

BCS_RESULT high_level_transplant_context_instances_initialize_v2(s_cache_cluster_transplant_context*& context, unsigned int thread_index, unsigned int thread_count)
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
		unsigned int tag_instance_count = 0;
		if (BCS_FAILED(rs = tag_reader->get_tag_instances(tag_instances, tag_instance_count)))
		{
			return rs;
		}

		h_tag_instance** _high_level_tag_instances = nullptr;
		c_tag_instance** _low_level_tag_instances = nullptr;
		if (thread_index == 0)
		{
			context->high_level_tag_instances.allocate_many(tag_instance_count, &_high_level_tag_instances);
			context->low_level_tag_instances.allocate_many(tag_instance_count, &_low_level_tag_instances);
			context->transplant_tag_instance_index = 0;
		}

		barrier(thread_index, thread_count, context->barrier);

		h_tag_instance** high_level_tag_instances = context->high_level_tag_instances.data + context->high_level_tag_instances.count - tag_instance_count;
		ASSERT(!_high_level_tag_instances || _high_level_tag_instances == high_level_tag_instances); // validation

		c_tag_instance** low_level_tag_instances = context->low_level_tag_instances.data + context->low_level_tag_instances.count - tag_instance_count;
		ASSERT(!_low_level_tag_instances || _low_level_tag_instances == low_level_tag_instances); // validation

		for (
			unsigned int tag_instance_index = atomic_incu32(&context->transplant_tag_instance_index);
			tag_instance_index < tag_instance_count;
			tag_instance_index = atomic_incu32(&context->transplant_tag_instance_index))
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

			h_tag_group* high_level_tag_group = nullptr;
			for (h_tag_group* _high_level_tag_group : context->high_level_tag_groups)
			{
				if (&_high_level_tag_group->blofeld_tag_group == blofeld_tag_group)
				{
					high_level_tag_group = _high_level_tag_group;
					break;
				}
			}
			if (high_level_tag_group == nullptr)
			{
				return BCS_E_NOT_FOUND;
			}

			// #TODO: Convert over to use BCS_RESULT
			h_tag_instance* high_level_tag_instance;
			if (BCS_FAILED(rs = high_level_tag_group->create_tag_instance(tag_instance_name, high_level_tag_instance)))
			{
				return rs;
			}

			high_level_tag_instances[tag_instance_index] = high_level_tag_instance;
			low_level_tag_instances[tag_instance_index] = &tag_instance;
			//context->high_level_tag_instances.emplace_back(high_level_tag_instance);


		}


		barrier(thread_index, thread_count, context->barrier);
		if (thread_index == 0)
		{
			context->transplant_tag_instance_index = 0;
		}
		barrier(thread_index, thread_count, context->barrier);

		for (
			unsigned int tag_instance_index = atomic_incu32(&context->transplant_tag_instance_index);
			tag_instance_index < tag_instance_count;
			tag_instance_index = atomic_incu32(&context->transplant_tag_instance_index))
		{
			c_tag_instance& tag_instance = *tag_instances[tag_instance_index];
			h_tag_instance& high_level_tag_instance = *context->high_level_tag_instances.data[tag_instance_index];
			h_prototype& high_level_prototype = high_level_tag_instance.prototype;

			const void* tag_data_root;
			const void* tag_data_start;
			const void* tag_data_end;
			if (BCS_FAILED(rs = tag_instance.get_tag_data(tag_data_root, tag_data_start, tag_data_end)))
			{
				return rs;
			}

			const char* tag_data_position = static_cast<const char*>(tag_data_root);
			if (BCS_FAILED(transplant_prototype(tag_instance, tag_data_position, high_level_prototype)))
			{
				continue;
			}

		}


		barrier(thread_index, thread_count, context->barrier);
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_create_v2(c_cache_cluster& cache_cluster, s_cache_cluster_transplant_context*& context)
{
	if (context = trivial_malloc(s_cache_cluster_transplant_context, 1))
	{
		memset(context, 0, sizeof(*context));

		context->transplantable_cache_file_readers;
		context->high_level_tag_groups;
		context->cache_cluster = &cache_cluster;
		context->bcs_result = BCS_S_OK;

		BCS_RESULT volatile& rs = context->bcs_result;
		if (BCS_FAILED(rs = context->cache_cluster->get_engine_platform_build(context->engine_platform_build)))
		{
			return rs;
		}

		return BCS_S_OK;
	}
	else
	{
		return BCS_E_OUT_OF_MEMORY;
	}
}

void high_level_transplant_context_execute_v2(void* userdata, unsigned int thread_index, unsigned int thread_count)
{
#define write_bcs_error(_error) atomic_cmpxchg32(reinterpret_cast<underlying(BCS_RESULT) volatile*>(&rs), underlying_cast(_error), underlying_cast(BCS_S_OK));
	s_cache_cluster_transplant_context* context = static_cast<s_cache_cluster_transplant_context*>(userdata);
	BCS_RESULT volatile& rs = context->bcs_result;

	BCS_RESULT transplant_entries_result = BCS_S_OK;
	if (BCS_SUCCEEDED(rs) && BCS_FAILED(transplant_entries_result = high_level_transplant_init_transplant_entries_v2(context, thread_index, thread_count)))
	{
		write_bcs_error(transplant_entries_result);
		//return transplant_entries_result;
	}

	barrier(thread_index, thread_count, context->barrier);

	BCS_RESULT transplant_context_groups_result = BCS_S_OK;
	if (BCS_SUCCEEDED(rs) && BCS_FAILED(transplant_context_groups_result = high_level_transplant_context_groups_initialize_v2(context, thread_index, thread_count)))
	{
		write_bcs_error(transplant_context_groups_result);
		//return transplant_context_groups_result;
	}

	barrier(thread_index, thread_count, context->barrier);

	BCS_RESULT transplant_context_instances_result = BCS_S_OK;
	if (BCS_SUCCEEDED(rs) && BCS_FAILED(transplant_context_instances_result = high_level_transplant_context_instances_initialize_v2(context, thread_index, thread_count)))
	{
		write_bcs_error(transplant_context_instances_result);
		//return transplant_context_instances_result;
	}

	barrier(thread_index, thread_count, context->barrier);
}

BCS_RESULT high_level_transplant_context_execute_v2(s_cache_cluster_transplant_context* context)
{
	parallel_invoke_thread_count(high_level_transplant_context_execute_v2, context);
	return context->bcs_result;
}

BCS_RESULT high_level_transplant_init_transplant_entries_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count)
{
	BCS_VALIDATE_ARGUMENT(context);

	BCS_RESULT rs = BCS_S_OK;

	if (thread_index == 0)
	{
		c_cache_file_reader* const* cache_readers;
		unsigned int cache_reader_count;
		if (BCS_FAILED(rs = context->cache_cluster->get_cache_readers(cache_readers, cache_reader_count)))
		{
			return rs;
		}

		for (unsigned int cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
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
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_groups_initialize_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count)
{
	BCS_VALIDATE_ARGUMENT(context);

	BCS_RESULT rs = BCS_S_OK;

	if (thread_index == 0)
	{
		t_tag_group_collection tag_groups;
		if (BCS_FAILED(rs = context->cache_cluster->get_blofeld_tag_groups(tag_groups)))
		{
			return rs;
		}

		for (t_tag_group_collection tag_group = tag_groups; *tag_group; tag_group++)
		{
			h_tag_group* high_level_tag_group = new() h_tag_group(context->engine_platform_build, **tag_group);
			if (high_level_tag_group == nullptr)
			{
				return BCS_E_OUT_OF_MEMORY;
			}

			if (BCS_FAILED(rs = context->high_level_tag_groups.emplace_back(high_level_tag_group)))
			{
				return rs;
			}
		}
	}

	return rs;
}

BCS_RESULT high_level_transplant_context_destroy_v2(s_cache_cluster_transplant_context* context, bool destroy_children)
{
	if (destroy_children)
	{
		console_write_line("#TODO high_level_transplant_context_destroy_v2::destroy_children not implemented");
		return BCS_E_NOT_IMPLEMENTED;
	}

	return BCS_S_OK;
}
