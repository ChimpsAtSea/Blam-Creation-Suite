#include "definitiontweaker-private-pch.h"

c_tag_field_serialization_context::c_tag_field_serialization_context(
	c_tag_struct_serialization_context& _parent_tag_struct_serialization_context,
	const char* _field_data,
	c_runtime_tag_field_definition& _runtime_tag_field_definition) :
	c_serialization_context(_parent_tag_struct_serialization_context),
	parent_tag_struct_serialization_context(_parent_tag_struct_serialization_context),
	field_data(_field_data),
	field_size(c_tag_field_serialization_context::calculate_field_size(*this, _runtime_tag_field_definition)),
	field_type(_runtime_tag_field_definition.field_type),
	name(_runtime_tag_field_definition.name),
	traverse_count(),
	runtime_tag_field_definition(_runtime_tag_field_definition),
	tag_struct_serialization_context(),
	tag_block_serialization_context()
{

}

c_tag_field_serialization_context::~c_tag_field_serialization_context()
{

}

BCS_RESULT c_tag_field_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_error)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	c_tag_serialization_context& tag_serialization_context = parent_tag_struct_serialization_context.tag_serialization_context;
	const char* read_position = static_cast<const char*>(field_data);

	if (read_position < tag_serialization_context.tag_data_start)
	{
		intptr_t bytes = tag_serialization_context.tag_data_end - read_position;
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_error,
			"field data read before tag data start (bytes:%zu)", bytes);
	}

	read_position += field_size;

	if (read_position > tag_serialization_context.tag_data_end)
	{
		intptr_t bytes = read_position - tag_serialization_context.tag_data_end;
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_error,
			"field data read after tag data start (bytes:%zd)", bytes);
	}
}

BCS_RESULT c_tag_field_serialization_context::traverse()
{
	unsigned int has_traversed = atomic_incu32(&traverse_count) > 1;
	ASSERT(!has_traversed);

	if (max_serialization_error_type >= _serialization_error_type_error)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	c_tag_serialization_context& tag_serialization_context = parent_tag_struct_serialization_context.tag_serialization_context;
	const char* field_string = "<bad>";
	blofeld::field_to_string(runtime_tag_field_definition.field_type, field_string);
	switch (runtime_tag_field_definition.field_type)
	{
		using namespace blofeld;
	case _field_string:
	{
		::c_static_string<32> const& string = *reinterpret_cast<decltype(&string)>(field_data);
		size_t length = string.length();
		size_t max_length = string.max_length();

		const char* string_buffer_start = string.get_buffer();
		const char* string_buffer_end = string_buffer_start + max_length;

		if (length >= max_length)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"string length %zu exceeded max_length %zu", length, max_length);
		}

		unsigned int bad_data_search_index = length + 1;
		for (const char* string_position = string_buffer_start + bad_data_search_index; string_position < string_buffer_end; string_position++, bad_data_search_index++)
		{
			if (*string_position)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_warning,
					"string contains non-zero character after terminator index:0x%08X", bad_data_search_index);
				break;
			}
		}
	}
	break;
	case _field_long_string:
	{
		::c_static_string<256> const& string = *reinterpret_cast<decltype(&string)>(field_data);
		size_t length = string.length();
		size_t max_length = string.max_length();

		const char* string_buffer_start = string.get_buffer();
		const char* string_buffer_end = string_buffer_start + max_length;

		if (length >= max_length)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"string length %zu exceeded max_length %zu", length, max_length);
		}

		unsigned int bad_data_search_index = length + 1;
		for (const char* string_position = string_buffer_start + bad_data_search_index; string_position < string_buffer_end; string_position++, bad_data_search_index++)
		{
			if (*string_position)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_warning,
					"string contains non-zero character after terminator index:0x%08X", bad_data_search_index);
				break;
			}
		}
	}
	break;
	case _field_string_id:
	case _field_old_string_id:
	{
		::string_id const& string_id = *reinterpret_cast<decltype(&string_id)>(field_data);



		debug_point;
	}
	break;
	case _field_char_integer:
	{

	}
	break;
	case _field_short_integer:
	{

	}
	break;
	case _field_long_integer:
	{

	}
	break;
	case _field_int64_integer:
	{

	}
	break;
	case _field_angle:
	{

	}
	break;
	case _field_tag:
	{

	}
	break;
	case _field_char_enum:
	{
		int enum_value = *reinterpret_cast<const char*>(field_data);
		validate_enum(enum_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_short_enum:
	{
		int enum_value = *reinterpret_cast<const short*>(field_data);
		validate_enum(enum_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_long_enum:
	{
		int enum_value = *reinterpret_cast<const int*>(field_data);
		validate_enum(enum_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_long_flags:
	{
		unsigned int flags_value = *reinterpret_cast<const unsigned int*>(field_data);
		validate_flags(flags_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_word_flags:
	{
		unsigned int flags_value = *reinterpret_cast<const unsigned short*>(field_data);
		validate_flags(flags_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_byte_flags:
	{
		unsigned int flags_value = *reinterpret_cast<const unsigned char*>(field_data);
		validate_flags(flags_value, runtime_tag_field_definition.string_list_definition);
	}
	break;
	case _field_point_2d:
	{

	}
	break;
	case _field_rectangle_2d:
	{

	}
	break;
	case _field_rgb_color:
	{

	}
	break;
	case _field_argb_color:
	{

	}
	break;
	case _field_real:
	case _field_real_slider:
	case _field_real_fraction:
	{
		::real const& real = *reinterpret_cast<decltype(&real)>(field_data);
		validate_float(real, nullptr);
	}
	break;
	case _field_real_point_2d:
	{
		::real_point2d const& real_point2d = *reinterpret_cast<decltype(&real_point2d)>(field_data);
		validate_float(real_point2d.x, "x");
		validate_float(real_point2d.y, "y");
	}
	break;
	case _field_real_point_3d:
	{
		::real_point3d const& real_point3d = *reinterpret_cast<decltype(&real_point3d)>(field_data);
		validate_float(real_point3d.x, "x");
		validate_float(real_point3d.y, "y");
		validate_float(real_point3d.z, "z");
	}
	break;
	case _field_real_vector_2d:
	{
		::real_vector2d const& real_vector2d = *reinterpret_cast<decltype(&real_vector2d)>(field_data);
		validate_float(real_vector2d.i, "i");
		validate_float(real_vector2d.j, "j");
	}
	break;
	case _field_real_vector_3d:
	{
		::real_vector3d const& real_vector3d = *reinterpret_cast<decltype(&real_vector3d)>(field_data);
		validate_float(real_vector3d.i, "i");
		validate_float(real_vector3d.j, "j");
		validate_float(real_vector3d.k, "k");
	}
	break;
	case _field_real_quaternion:
	{
		::real_quaternion const& real_quaternion = *reinterpret_cast<decltype(&real_quaternion)>(field_data);
		validate_float(real_quaternion.i, "i");
		validate_float(real_quaternion.j, "j");
		validate_float(real_quaternion.k, "k");
		validate_float(real_quaternion.w, "w");
	}
	break;
	case _field_real_euler_angles_2d:
	{

	}
	break;
	case _field_real_euler_angles_3d:
	{

	}
	break;
	case _field_real_plane_2d:
	{

	}
	break;
	case _field_real_plane_3d:
	{

	}
	break;
	case _field_real_rgb_color:
	{
		::rgb_color const& rgb_color = *reinterpret_cast<decltype(&rgb_color)>(field_data);
		validate_float(rgb_color.red, "red");
		validate_float(rgb_color.green, "green");
		validate_float(rgb_color.blue, "blue");
	}
	break;
	case _field_real_argb_color:
	{
		::argb_color const& argb_color = *reinterpret_cast<decltype(&argb_color)>(field_data);
		validate_float(argb_color.alpha, "alpha");
		validate_float(argb_color.red, "red");
		validate_float(argb_color.green, "green");
		validate_float(argb_color.blue, "blue");
	}
	break;
	case _field_real_hsv_color:
	{
		::real_hsv_color const& real_hsv_color = *reinterpret_cast<decltype(&real_hsv_color)>(field_data);
		validate_float(real_hsv_color.hue, "hue");
		validate_float(real_hsv_color.saturation, "saturation");
		validate_float(real_hsv_color.value, "value");
	}
	break;
	case _field_real_ahsv_color:
	{
		::real_ahsv_color const& real_ahsv_color = *reinterpret_cast<decltype(&real_ahsv_color)>(field_data);
		validate_float(real_ahsv_color.alpha, "alpha");
		validate_float(real_ahsv_color.hue, "hue");
		validate_float(real_ahsv_color.saturation, "saturation");
		validate_float(real_ahsv_color.value, "value");
	}
	break;
	case _field_short_integer_bounds:
	{

	}
	break;
	case _field_angle_bounds:
	{
		::angle_bounds const& angle_bounds = *reinterpret_cast<decltype(&angle_bounds)>(field_data);
		validate_float(angle_bounds.lower, "lower");
		validate_float(angle_bounds.upper, "upper");
	}
	break;
	case _field_real_bounds:
	{
		::real_bounds const& real_bounds = *reinterpret_cast<decltype(&real_bounds)>(field_data);
		validate_float(real_bounds.lower, "lower");
		validate_float(real_bounds.upper, "upper");
	}
	break;
	case _field_real_fraction_bounds:
	{
		::real_fraction_bounds const& real_fraction_bounds = *reinterpret_cast<decltype(&real_fraction_bounds)>(field_data);
		if (isnan(real_fraction_bounds.lower))
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"field %s %s lower is nan", field_string, runtime_tag_field_definition.name.c_str());
		}
		if (isnan(real_fraction_bounds.upper))
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"field %s %s upper is nan", field_string, runtime_tag_field_definition.name.c_str());
		}
	}
	break;
	case _field_tag_reference:
	{
		::s_tag_reference const& tag_reference = *reinterpret_cast<decltype(&tag_reference)>(field_data);

		if (tag_reference.group_tag == UINT32_MAX)
		{
			if (tag_reference.name != 0 && tag_reference.name != 0xCDCDCDCD)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_data_validation_error,
					"reference has no group but name is [0x%08X] [%i]", tag_reference.name, tag_reference.name);
			}
			if (tag_reference.name_length != 0 && tag_reference.name_length != 0xCDCDCDCD)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_data_validation_error,
					"reference has no group but name length is [0x%08X] [%i]", tag_reference.name_length, tag_reference.name_length);
			}
			if (tag_reference.datum_index != -1)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_data_validation_error,
					"reference has no group but datum index is [0x%08X] [%i]", tag_reference.datum_index, tag_reference.datum_index);
			}
		}
		else
		{
			// #TODO: Check if group exists
		}
		if (tag_reference.datum_index != -1)
		{
			// #TODO: Check if tag reference index is valid
		}
	}
	break;
	case _field_block:
	{
		::s_tag_block const& tag_block = *reinterpret_cast<decltype(&tag_block)>(field_data);

		if (c_runtime_tag_block_definition* block_definition = runtime_tag_field_definition.block_definition)
		{
			tag_block_serialization_context = new() c_tag_block_serialization_context(
				*this,
				tag_serialization_context,
				field_data,
				*block_definition);

			tag_block_serialization_context->read();
			tag_block_serialization_context->traverse();
		}
		else
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"field %s %s is missing runtime block definition", field_string, runtime_tag_field_definition.name.c_str());
		}
	}
	break;
	case _field_long_block_flags:
	{

	}
	break;
	case _field_word_block_flags:
	{

	}
	break;
	case _field_byte_block_flags:
	{

	}
	break;
	case _field_char_block_index:
	{

	}
	break;
	case _field_char_block_index_custom_search:
	{

	}
	break;
	case _field_short_block_index:
	{

	}
	break;
	case _field_short_block_index_custom_search:
	{

	}
	break;
	case _field_long_block_index:
	{

	}
	break;
	case _field_long_block_index_custom_search:
	{

	}
	break;
	case _field_data:
	{

	}
	break;
	case _field_vertex_buffer:
	{

	}
	break;
	case _field_useless_pad:
	{

	}
	break;
	case _field_pad:
	{
		for (unsigned int padding_index = 0; padding_index < runtime_tag_field_definition.padding; padding_index++)
		{
			int padding_value = static_cast<const char*>(field_data)[padding_index];
			if (padding_value != 0)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_data_validation_error,
					"padding is non zero %02X", padding_value);
				break;
			}
		}
	}
	break;
	case _field_skip:
	{
		for (unsigned int skip_index = 0; skip_index < runtime_tag_field_definition.length; skip_index++)
		{
			int skip_value = static_cast<const char*>(field_data)[skip_index];
			if (skip_value != 0)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_data_validation_error,
					"skip is non zero %02X", skip_index);
				break;
			}
		}
	}
	break;
	case _field_non_cache_runtime_value:
	{

	}
	break;
	case _field_explanation:
	{

	}
	break;
	case _field_custom:
	{

	}
	break;
	case _field_struct:
	{
		tag_struct_serialization_context = new() c_tag_struct_serialization_context(
			*this,
			parent_tag_struct_serialization_context.tag_serialization_context,
			static_cast<const char*>(field_data),
			*runtime_tag_field_definition.struct_definition);
		tag_struct_serialization_context->read();
		tag_struct_serialization_context->traverse();
	}
	break;
	case _field_array:
	{

	}
	break;
	case _field_pageable_resource:
	{
		::s_tag_resource const& tag_resource = *reinterpret_cast<decltype(&tag_resource)>(field_data);

		if (tag_resource.definition_address != 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"pageable resource definition address is non zero %08X", tag_resource.definition_address);
		}

		if (!tag_resource.resource_handle.valid())
		{
			unsigned short identifier = tag_resource.resource_handle.get_identifier();
			unsigned short absolute_index = tag_resource.resource_handle.get_absolute_index();
			int value = tag_resource.resource_handle.get_value();
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"pageable resource handle is invalid identifier:%08X absolute_index:%08X value:%08X", identifier, absolute_index, value);
		}

		// #TODO: Second round of validation to actually try and read the resource
	}
	break;
	case _field_api_interop:
	{
		::s_tag_interop const& tag_interop = *reinterpret_cast<decltype(&tag_interop)>(field_data);

		if (tag_interop.definition_address != 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"api interop definition address is non zero %08X", tag_interop.definition_address);
		}

		// #TODO
		// dword descriptor;
		// dword address;

	}
	break;
	case _field_terminator:
	{

	}
	break;
	case _field_byte_integer:
	{

	}
	break;
	case _field_word_integer:
	{

	}
	break;
	case _field_dword_integer:
	{

	}
	break;
	case _field_qword_integer:
	{

	}
	break;
	case _field_data_path:
	{

	}
	break;
	case _field_embedded_tag:
	{

	}
	break;
	case _field_pointer:
	{

	}
	break;
	case _field_half:
		break;
	}
}

unsigned int c_tag_field_serialization_context::calculate_field_size(c_serialization_context& serialization_context, c_runtime_tag_field_definition& runtime_field)
{
#define field_size(_field, size) if(_field == runtime_field.field_type) { return (size); }

	field_size(blofeld::_field_string, sizeof(::c_static_string<32>));
	field_size(blofeld::_field_long_string, sizeof(::c_static_string<256>));
	field_size(blofeld::_field_string_id, sizeof(string_id));
	field_size(blofeld::_field_old_string_id, sizeof(::c_old_string_id));
	field_size(blofeld::_field_char_integer, sizeof(char));
	field_size(blofeld::_field_short_integer, sizeof(short));
	field_size(blofeld::_field_long_integer, sizeof(long));
	field_size(blofeld::_field_int64_integer, sizeof(int64_t));
	field_size(blofeld::_field_angle, sizeof(angle));
	field_size(blofeld::_field_tag, sizeof(tag));
	field_size(blofeld::_field_char_enum, sizeof(char));
	field_size(blofeld::_field_short_enum, sizeof(short));
	field_size(blofeld::_field_long_enum, sizeof(long));
	field_size(blofeld::_field_long_flags, sizeof(long));
	field_size(blofeld::_field_word_flags, sizeof(word));
	field_size(blofeld::_field_byte_flags, sizeof(byte));
	field_size(blofeld::_field_point_2d, sizeof(::s_point2d));
	field_size(blofeld::_field_rectangle_2d, sizeof(::s_rectangle2d));
	field_size(blofeld::_field_rgb_color, sizeof(::pixel32));
	field_size(blofeld::_field_argb_color, sizeof(::pixel32));
	field_size(blofeld::_field_real, sizeof(::real));
	field_size(blofeld::_field_real_slider, sizeof(::real));
	field_size(blofeld::_field_real_fraction, sizeof(::real_fraction));
	field_size(blofeld::_field_real_point_2d, sizeof(::real_point2d));
	field_size(blofeld::_field_real_point_3d, sizeof(::real_point3d));
	field_size(blofeld::_field_real_vector_2d, sizeof(::real_vector2d));
	field_size(blofeld::_field_real_vector_3d, sizeof(::real_vector3d));
	field_size(blofeld::_field_real_quaternion, sizeof(::real_quaternion));
	field_size(blofeld::_field_real_euler_angles_2d, sizeof(::real_euler_angles2d));
	field_size(blofeld::_field_real_euler_angles_3d, sizeof(::real_euler_angles3d));
	field_size(blofeld::_field_real_plane_2d, sizeof(::real_plane2d));
	field_size(blofeld::_field_real_plane_3d, sizeof(::real_plane3d));
	field_size(blofeld::_field_real_rgb_color, sizeof(::rgb_color));
	field_size(blofeld::_field_real_argb_color, sizeof(::argb_color));
	field_size(blofeld::_field_real_hsv_color, sizeof(::real_hsv_color));
	field_size(blofeld::_field_real_ahsv_color, sizeof(::real_ahsv_color));
	field_size(blofeld::_field_short_integer_bounds, sizeof(::short_bounds));
	field_size(blofeld::_field_angle_bounds, sizeof(::angle_bounds));
	field_size(blofeld::_field_real_bounds, sizeof(::real_bounds));
	field_size(blofeld::_field_real_fraction_bounds, sizeof(::real_fraction_bounds));
	field_size(blofeld::_field_tag_reference, sizeof(::s_tag_reference));
	field_size(blofeld::_field_block, sizeof(::s_tag_block));
	field_size(blofeld::_field_long_block_flags, sizeof(long));
	field_size(blofeld::_field_word_block_flags, sizeof(word));
	field_size(blofeld::_field_byte_block_flags, sizeof(byte));
	field_size(blofeld::_field_char_block_index, sizeof(char));
	field_size(blofeld::_field_char_block_index_custom_search, sizeof(char));
	field_size(blofeld::_field_short_block_index, sizeof(short));
	field_size(blofeld::_field_short_block_index_custom_search, sizeof(short));
	field_size(blofeld::_field_long_block_index, sizeof(long));
	field_size(blofeld::_field_long_block_index_custom_search, sizeof(long));
	field_size(blofeld::_field_data, sizeof(::s_tag_data));
	field_size(blofeld::_field_vertex_buffer, sizeof(::s_tag_d3d_vertex_buffer));
	field_size(blofeld::_field_pad, runtime_field.padding);
	//field_size(blofeld::_field_useless_pad, runtime_field.padding);
	field_size(blofeld::_field_useless_pad, 0);
	field_size(blofeld::_field_skip, runtime_field.length);
	field_size(blofeld::_field_non_cache_runtime_value, 0);
	field_size(blofeld::_field_explanation, 0);
	field_size(blofeld::_field_custom, 0);
	if (runtime_field.field_type == blofeld::_field_struct)
	{
		if (c_runtime_tag_struct_definition* struct_definition = runtime_field.struct_definition)
		{
			unsigned int field_struct_size = c_tag_struct_serialization_context::calculate_struct_size(serialization_context, *struct_definition);
			if (field_struct_size == 0)
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_warning,
					"field '%s' struct '%' has zero size",
					runtime_field.name.c_str(),
					struct_definition->name.c_str());
			}
			return field_struct_size;
		}
		else
		{
			serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_error,
				"field '%s' struct is null",
				runtime_field.name.c_str());
			return 0;
		}
	}
	if (runtime_field.field_type == blofeld::_field_array)
	{
		if (c_runtime_tag_array_definition* array_definition = runtime_field.array_definition)
		{
			if (c_runtime_tag_struct_definition* struct_definition = array_definition->struct_definition)
			{
				unsigned int field_struct_size = c_tag_struct_serialization_context::calculate_struct_size(serialization_context, *struct_definition);
				if (field_struct_size == 0)
				{
					serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
						_serialization_error_type_error,
						"field '%s' array struct '%' has zero size",
						runtime_field.name.c_str(),
						struct_definition->name.c_str());
				}
				unsigned int array_data_size = field_struct_size * array_definition->element_count;
				return array_data_size;
			}
			else
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_error,
					"field '%s' array struct is null",
					runtime_field.name.c_str());
				return 0;
			}
		}
		else
		{
			serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_error,
				"field '%s' array definition is null",
				runtime_field.name.c_str());
			return 0;
		}
	}
	field_size(blofeld::_field_pageable_resource, sizeof(::s_tag_resource));
	field_size(blofeld::_field_api_interop, sizeof(::s_tag_interop));
	field_size(blofeld::_field_terminator, 0);
	field_size(blofeld::_field_byte_integer, sizeof(byte));
	field_size(blofeld::_field_word_integer, sizeof(word));
	field_size(blofeld::_field_dword_integer, sizeof(dword));
	field_size(blofeld::_field_qword_integer, sizeof(qword));
	field_size(blofeld::_field_embedded_tag, sizeof(::s_tag_reference));
	field_size(blofeld::_field_data_path, sizeof(::c_static_string<256>));
	if (runtime_field.field_type == blofeld::_field_pointer)
	{
		unsigned int pointer_size = 0;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(serialization_context.engine_platform_build.platform_type, &pointer_size)));
		return pointer_size;
	};
	field_size(blofeld::_field_half, sizeof(word));

	FATAL_ERROR("Unsupported field type");

#undef field_size
}

void c_tag_field_serialization_context::validate_enum(int enum_value, c_runtime_string_list_definition* string_list_definition)
{
	if (string_list_definition)
	{
		int option_count = static_cast<int>(string_list_definition->options.size());
		if (enum_value >= option_count)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"enum value of %i out of range %i", enum_value, option_count);
		}
		if (enum_value < 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"enum value of %i out of range %i", enum_value, option_count);
		}
	}
	else
	{
		const char* field_string = "<bad>";
		blofeld::field_to_string(runtime_tag_field_definition.field_type, field_string);
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"field %s %s is missing runtime string list definition", field_string, runtime_tag_field_definition.name.c_str());
	}
}

void c_tag_field_serialization_context::validate_flags(unsigned int flags_value, c_runtime_string_list_definition* string_list_definition)
{
	if (c_runtime_string_list_definition* string_list_definition = runtime_tag_field_definition.string_list_definition)
	{
		unsigned int option_count = static_cast<unsigned int>(string_list_definition->options.size());
		unsigned int invalid_option_mask = ~0u << option_count;
		if (option_count == 32)
		{
			invalid_option_mask = 0;
		}

		unsigned int invalid_bits = flags_value & invalid_option_mask;

		if (invalid_bits != 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"flags value of %i has invalid bits %08X", flags_value, invalid_bits);
		}

		debug_point;
	}
	else
	{
		const char* field_string = "<bad>";
		blofeld::field_to_string(runtime_tag_field_definition.field_type, field_string);
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"field %s %s is missing runtime string list definition", field_string, runtime_tag_field_definition.name.c_str());
	}
}

void c_tag_field_serialization_context::validate_float(float float_value, const char* name)
{
	if (isnan(float_value))
	{
		const char* field_string = "<bad>";
		blofeld::field_to_string(runtime_tag_field_definition.field_type, field_string);
		if (name)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"field %s %s %s is nan", field_string, runtime_tag_field_definition.name.c_str(), name);
		}
		else
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"field %s %s is nan", field_string, runtime_tag_field_definition.name.c_str());
		}
	}
}

bool c_tag_field_serialization_context::render_enum_debug(ImGuiTreeNodeFlags flags, const char* field_name, const char* field_type_name, long enum_index)
{
	bool tree_node_result = false;
	if (c_runtime_tag_definitions* runtime_tag_definitions = parent_tag_struct_serialization_context.tag_serialization_context.definition_tweaker.runtime_tag_definitions)
	{
		if (runtime_tag_definitions->is_tag_field_definition_valid(&runtime_tag_field_definition))
		{
			if (runtime_tag_definitions->is_string_list_definition_valid(runtime_tag_field_definition.string_list_definition))
			{
				const char* enum_value = "<bad>";
				if (enum_index < runtime_tag_field_definition.string_list_definition->options.size())
				{
					enum_value = runtime_tag_field_definition.string_list_definition->options[enum_index].c_str();
				}

				tree_node_result = ImGui::TreeNodeEx(
					"##field",
					flags,
					"%s %s [%i] [0x%08X] [%s]",
					field_type_name,
					field_name,
					enum_index,
					enum_index,
					enum_value);

				return tree_node_result;
			}
		}
	}
	// fallback
	tree_node_result = ImGui::TreeNodeEx(
		"##field",
		flags,
		"%s %s [%i] [0x%08X]",
		field_type_name,
		field_name,
		enum_index,
		enum_index);

	return tree_node_result;
}

void c_tag_field_serialization_context::render_tree()
{
	const char* field_name = name.c_str();

	ImGui::PushID(field_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (tag_struct_serialization_context == nullptr)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	const char* field_type_name = "<bad>";
	blofeld::field_to_tagfile_field_type(field_type, field_type_name);
	bool tree_node_result;
	if (max_serialization_error_type > _serialization_error_type_warning)
	{
		tree_node_result = ImGui::TreeNodeEx("##field", flags, "%s %s", field_type_name, field_name);
	}
	else switch (field_type)
	{
	case blofeld::_field_char_enum:
	{
		long enum_index = static_cast<long>(*(reinterpret_cast<const char*>(field_data)));
		tree_node_result = render_enum_debug(flags, field_name, field_type_name, enum_index);
	}
	break;
	case blofeld::_field_short_enum:
	{
		long enum_index = static_cast<long>(*(reinterpret_cast<const short*>(field_data)));
		tree_node_result = render_enum_debug(flags, field_name, field_type_name, enum_index);
	}
	break;
	case blofeld::_field_long_enum:
	{
		long enum_index = static_cast<long>(*(reinterpret_cast<const int*>(field_data)));
		tree_node_result = render_enum_debug(flags, field_name, field_type_name, enum_index);
	}
	break;
	case blofeld::_field_string:
	{
		::c_static_string<32> const& string = *reinterpret_cast<decltype(&string)>(field_data);
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%s]",
			field_type_name,
			field_name,
			string.get_string());
	}
	break;
	case blofeld::_field_long_string:
	{
		::c_static_string<256> const& string = *reinterpret_cast<decltype(&string)>(field_data);
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%s]",
			field_type_name,
			field_name,
			string.get_string());
	}
	break;
	case blofeld::_field_char_integer:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%i] [0x%08X]",
			field_type_name,
			field_name,
			static_cast<long>(*(reinterpret_cast<const char*>(field_data))),
			static_cast<long>(*(reinterpret_cast<const char*>(field_data))));
		break;
	case blofeld::_field_short_integer:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%i] [0x%08X]",
			field_type_name,
			field_name,
			static_cast<long>(*(reinterpret_cast<const short*>(field_data))),
			static_cast<long>(*(reinterpret_cast<const short*>(field_data))));
		break;
	case blofeld::_field_long_integer:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%i] [0x%08X]",
			field_type_name,
			field_name,
			static_cast<long>(*(reinterpret_cast<const int*>(field_data))),
			static_cast<long>(*(reinterpret_cast<const int*>(field_data))));
		break;
	case blofeld::_field_real:
	case blofeld::_field_angle:
	case blofeld::_field_real_slider:
	case blofeld::_field_real_fraction:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%f]",
			field_type_name,
			field_name,
			*(reinterpret_cast<const real*>(field_data)));
		break;
	case blofeld::_field_angle_bounds:
	case blofeld::_field_real_bounds:
	case blofeld::_field_real_fraction_bounds:
	case blofeld::_field_real_point_2d:
	case blofeld::_field_real_vector_2d:
	case blofeld::_field_real_euler_angles_2d:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%f, %f]",
			field_type_name,
			field_name,
			*(reinterpret_cast<const real*>(field_data) + 0),
			*(reinterpret_cast<const real*>(field_data) + 1));
		break;
	case blofeld::_field_real_point_3d:
	case blofeld::_field_real_vector_3d:
	case blofeld::_field_real_euler_angles_3d:
	case blofeld::_field_real_plane_2d:
	case blofeld::_field_real_rgb_color:
	case blofeld::_field_real_hsv_color:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%f, %f, %f]",
			field_type_name,
			field_name,
			*(reinterpret_cast<const real*>(field_data) + 0),
			*(reinterpret_cast<const real*>(field_data) + 1),
			*(reinterpret_cast<const real*>(field_data) + 2));
		break;
	case blofeld::_field_real_quaternion:
	case blofeld::_field_real_plane_3d:
	case blofeld::_field_real_argb_color:
	case blofeld::_field_real_ahsv_color:
		tree_node_result = ImGui::TreeNodeEx(
			"##field",
			flags,
			"%s %s [%f, %f, %f, %f]",
			field_type_name,
			field_name,
			*(reinterpret_cast<const real*>(field_data) + 0),
			*(reinterpret_cast<const real*>(field_data) + 1),
			*(reinterpret_cast<const real*>(field_data) + 2),
			*(reinterpret_cast<const real*>(field_data) + 3));
		break;
	default:
		tree_node_result = ImGui::TreeNodeEx("##field", flags, "%s %s", field_type_name, field_name);
	}
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	parent_tag_struct_serialization_context.tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_field_definition, &runtime_tag_field_definition);
	if (tree_node_result)
	{
		if (c_tag_struct_serialization_context* struct_serialization_context = tag_struct_serialization_context)
		{
			struct_serialization_context->render_tree();
		}
		if (c_tag_block_serialization_context* block_serialization_context = tag_block_serialization_context)
		{
			block_serialization_context->render_tree();
		}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}
