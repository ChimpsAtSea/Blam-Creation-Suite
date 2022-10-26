#include <mandrilllib-private-pch.h>

template<> void byteswap_inplace(s_single_tag_file_header_v1& value)
{
	byteswap_inplace(value.tag_id_unused);
	byteswap_inplace(value.tag_name_unused);
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.data_offset);
	byteswap_inplace(value.unused30);
	byteswap_inplace(value.unused34);
	byteswap_inplace(value.group_version);
	byteswap_inplace(value.unused3A);
	byteswap_inplace(value.unused3B);
	byteswap_inplace(value.signature);
}

static BCS_RESULT calculate_tag_struct_definition_size(
	const blofeld::s_tag_struct_definition& struct_definition,
	s_engine_platform_build engine_platform_build,
	uint32_t& tag_struct_definition_size)
{
	BCS_RESULT rs = BCS_S_OK;

	tag_struct_definition_size = 0;

	for (const blofeld::s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

		uint32_t field_size;
		switch (tag_field.field_type)
		{
		case blofeld::_field_struct:
			if (BCS_FAILED(rs = calculate_tag_struct_definition_size(*tag_field.struct_definition, engine_platform_build, field_size)))
			{
				return rs;
			}
			break;
		case blofeld::_field_array:
			if (BCS_FAILED(rs = calculate_tag_struct_definition_size(tag_field.array_definition->struct_definition, engine_platform_build, field_size)))
			{
				return rs;
			}
			field_size *= tag_field.array_definition->element_count(engine_platform_build);
			break;
		case blofeld::_field_pad:
			field_size = tag_field.padding;
			break;
		default:
			if (BCS_FAILED(rs = blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size)))
			{
				return rs;
			}
			break;
		}

		tag_struct_definition_size += field_size;
	}

	return rs;
}

static bool tag_struct_definition_has_external_data(
	const blofeld::s_tag_struct_definition& struct_definition,
	s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;

	for (const blofeld::s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

		uint32_t field_size;
		switch (tag_field.field_type)
		{
		case blofeld::_field_tag_reference:
		case blofeld::_field_block:
		case blofeld::_field_data:
			return true;
		}
	}
	return false;
}

c_gen1_tag_file_parse_context::c_gen1_tag_file_parse_context(
	const void* _tag_file_data, 
	uint64_t _tag_file_data_size, 
	s_engine_platform_build _engine_platform_build) :
	is_big_endian(),
	is_little_endian(),
	tag_file_data_start(),
	tag_file_structure_data_start(),
	tag_file_data_end(),
	engine_platform_build(),
	tag_file_header()
{
	const s_single_tag_file_header_v1 * tag_file_header_v1_pointer = static_cast<const s_single_tag_file_header_v1*>(_tag_file_data);
	is_big_endian = tag_file_header_v1_pointer->signature == ::byteswap(k_signature);
	is_little_endian = tag_file_header_v1_pointer->signature == k_signature;
	tag_file_header = byteswap(*tag_file_header_v1_pointer);

	tag_file_data_start = static_cast<const char*>(_tag_file_data);
	tag_file_structure_data_start = tag_file_data_start + tag_file_header.data_offset;
	tag_file_data_end = tag_file_data_start + _tag_file_data_size;
	engine_platform_build = _engine_platform_build;

	if (!is_little_endian && !is_big_endian)
	{
		throw BCS_E_FAIL;
	}
}

BCS_RESULT c_gen1_tag_file_parse_context::traverse(h_prototype& prototype) const
{
	const char* reader_data_position = tag_file_structure_data_start;

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = traverse_tag_struct_data(reader_data_position, prototype)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = traverse_tag_external_data(reader_data_position, prototype)))
	{
		return rs;
	}

	return rs;
}

tag c_gen1_tag_file_parse_context::get_group_tag() const
{
	return tag_file_header.group_tag;
}

BCS_RESULT c_gen1_tag_file_parse_context::traverse_tag_struct_data(const char*& global_data_position, h_prototype& prototype) const
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_struct_definition& struct_definition = prototype.get_blofeld_struct_definition();

#define advance_read(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(global_data_position)); \
	global_data_position += sizeof(t_type)

	for (const blofeld::s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

		switch (tag_field.field_type)
		{
		case blofeld::_field_block:
		{
			h_block* tag_field_block_data = prototype.get_field_data<h_block>(tag_field);
			ASSERT(tag_field_block_data != nullptr);
			s_tag_block tag_block = advance_read(s_tag_block);

			tag_field_block_data->resize(tag_block.count);

			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			h_data* tag_field_data = prototype.get_field_data<h_data>(tag_field);
			ASSERT(tag_field_data != nullptr);
			s_tag_data tag_data = advance_read(s_tag_data);

			tag_field_data->resize(tag_data.size); // #WARN: preallocate, use ::size() later to get byte count
		}
		break;
		case blofeld::_field_tag_reference:
		{
			h_tag_reference* tag_field_tag_reference = prototype.get_field_data<h_tag_reference>(tag_field);
			ASSERT(tag_field_tag_reference != nullptr);

			tag_field_tag_reference->_set_unqualified_userdata('temp', const_cast<char*>(global_data_position)); // WARN: must go before read
			s_tag_reference tag_reference = advance_read(s_tag_reference);
		}
		break;
		case blofeld::_field_array:
		{
			h_enumerable* tag_field_array_data = prototype.get_field_data<h_enumerable>(tag_field);
			ASSERT(tag_field_array_data != nullptr);

			for (uint32_t array_index = 0; array_index < tag_field_array_data->size(); array_index++)
			{
				h_prototype& array_entry = tag_field_array_data->get(array_index);

				traverse_tag_struct_data(global_data_position, array_entry);
			}
		}
		break;
		case blofeld::_field_string:
		case blofeld::_field_long_string:
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
		{
			uint32_t field_size;
			if (BCS_FAILED(rs = blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size)))
			{
				return rs;
			}

			void* high_level_field_data = prototype.get_field_data_unsafe(tag_field);

			memcpy(high_level_field_data, global_data_position, field_size);
			if (is_big_endian)
			{
				blofeld::byteswap_field_data_inplace(tag_field.field_type, high_level_field_data, engine_platform_build);
			}

			global_data_position += field_size;

			debug_point;
		}
		break;
		case blofeld::_field_pad:
		{
			global_data_position += tag_field.padding;
		}
		break;
		case blofeld::_field_skip:
		{
			global_data_position += tag_field.length;
		}
		break;
		case blofeld::_field_custom:
		case blofeld::_field_explanation:
			break;
		default: FATAL_ERROR("Unsupported field type");
		}
	}
	debug_point;

	return rs;
#undef advance_read
}

BCS_RESULT c_gen1_tag_file_parse_context::traverse_tag_external_data(const char*& global_data_position, h_prototype& prototype) const
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_struct_definition& struct_definition = prototype.get_blofeld_struct_definition();

	for (const blofeld::s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

		switch (tag_field.field_type)
		{
		case blofeld::_field_block:
		{
			h_block* tag_field_block_data = prototype.get_field_data<h_block>(tag_field);
			ASSERT(tag_field_block_data != nullptr);

			for (uint32_t block_index = 0; block_index < tag_field_block_data->size(); block_index++)
			{
				h_prototype& block_entry = tag_field_block_data->get(block_index);
				traverse_tag_struct_data(global_data_position, block_entry);
			}
			// #TODO: get this from the definitions and make sure its correct with validation?
			bool has_external_data = tag_struct_definition_has_external_data(tag_field_block_data->get_tag_struct_definition(), engine_platform_build);
			if (has_external_data)
			{
				for (uint32_t block_index = 0; block_index < tag_field_block_data->size(); block_index++)
				{
					h_prototype& block_entry = tag_field_block_data->get(block_index);
					traverse_tag_external_data(global_data_position, block_entry);
				}
			}
			intptr_t data_offset = global_data_position - tag_file_data_start;
		}
		break;
		case blofeld::_field_data:
		{
			h_data* tag_field_data = prototype.get_field_data<h_data>(tag_field);
			ASSERT(tag_field_data != nullptr);

			memcpy(tag_field_data->data(), global_data_position, tag_field_data->size()); // overwrite blank contents
			global_data_position += tag_field_data->size();
		}
		break;
		case blofeld::_field_tag_reference:
		{
			h_tag_reference* tag_field_tag_reference = prototype.get_field_data<h_tag_reference>(tag_field);
			ASSERT(tag_field_tag_reference != nullptr);

			ASSERT(tag_field_tag_reference->get_group_tag() == 'temp'); // sanity

			s_tag_reference* tag_reference_pointer = static_cast<s_tag_reference*>(tag_field_tag_reference->_get_userdata());
			ASSERT(tag_reference_pointer);
			s_tag_reference tag_reference = byteswap(*tag_reference_pointer);

			const char* tag_reference_path = "";
			if (tag_reference.name_length > 0)
			{
				tag_reference_path = global_data_position;
				uint32_t tag_reference_file_path_bytes = strlen(global_data_position) + 1;
				ASSERT(tag_reference_file_path_bytes == (tag_reference.name_length + 1));
				global_data_position += tag_reference_file_path_bytes;
			}
			tag_field_tag_reference->set_unqualified_file_path_without_extension(tag_reference.group_tag, tag_reference_path);
		}
		break;
		case blofeld::_field_array:
		{
			h_enumerable* tag_field_array_data = prototype.get_field_data<h_enumerable>(tag_field);
			ASSERT(tag_field_array_data != nullptr);

			for (uint32_t array_index = 0; array_index < tag_field_array_data->size(); array_index++)
			{
				h_prototype& array_entry = tag_field_array_data->get(array_index);

				traverse_tag_external_data(global_data_position, array_entry);
			}

			debug_point;
		}
		break;
		case blofeld::_field_string:
		case blofeld::_field_long_string:
		case blofeld::_field_string_id:
		case blofeld::_field_old_string_id:
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
		case blofeld::_field_custom:
		case blofeld::_field_explanation:
		case blofeld::_field_pad:
		case blofeld::_field_skip:
			break;
		default: debug_break; throw;
		}
	}
	debug_point;

	return rs;
}

BCS_RESULT c_gen1_tag_file_parse_context::parse_gen1_tag_file_data(h_tag*& tag_prototype, const wchar_t* tag_file_path, s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;
	void* tag_file_data;
	uint64_t tag_file_data_size;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(tag_file_path, tag_file_data, tag_file_data_size)))
	{
		return rs;
	}

	rs = parse_gen1_tag_file_data(tag_prototype, tag_file_data, tag_file_data_size, engine_platform_build);

	tracked_free(tag_file_data);

	return rs;
}

BCS_RESULT c_gen1_tag_file_parse_context::parse_gen1_tag_file_data(h_tag*& tag_prototype, const void* tag_file_data, uint64_t tag_file_data_size, s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;

	try
	{
		c_gen1_tag_file_parse_context context = c_gen1_tag_file_parse_context(tag_file_data, tag_file_data_size, engine_platform_build);

		const blofeld::s_tag_group* blofeld_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, context.get_group_tag());
		h_prototype* object_prototype = h_prototype::create_high_level_object(blofeld_tag_group->block_definition.struct_definition, engine_platform_build);

		if (object_prototype == nullptr) // #TODO: correctly pipe a resullt from this
		{
			return BCS_E_FAIL;
		}

		tag_prototype = dynamic_cast<h_tag*>(object_prototype);
		if (tag_prototype == nullptr) // #TODO: correctly pipe a resullt from this
		{
			delete object_prototype;
			return BCS_E_FAIL;
		}

		if (BCS_FAILED(rs = context.traverse(*tag_prototype)))
		{
			return rs;
		}
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}

	return rs;
}
