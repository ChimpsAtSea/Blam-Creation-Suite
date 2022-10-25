#include "definitiontweaker-private-pch.h"

c_tag_struct_serialization_context::c_tag_struct_serialization_context(
	c_tag_serialization_context& _serialization_context,
	c_runtime_tag_struct_definition& _struct_definition,
	unsigned int _expected_struct_size) :
	serialization_context(_serialization_context),
	expected_struct_size(_expected_struct_size),
	struct_size(),
	struct_definition(_struct_definition),
	field_serialization_contexts(),
	serialization_errors()
{
	if (struct_definition.fields.empty())
	{
		serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "struct '%' has no fields", struct_definition.name.c_str()));
	}
	else
	{
		struct_size = calculate_struct_size(serialization_context, struct_definition, serialization_errors);
	}
	debug_point;
}

c_tag_struct_serialization_context::~c_tag_struct_serialization_context()
{
	for (auto field_serialization_context : field_serialization_contexts)
	{
		delete field_serialization_context;
	}

	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}

unsigned int c_tag_struct_serialization_context::read()
{
	unsigned int num_errors = 0;

	debug_point;

	return num_errors;
}

unsigned int c_tag_struct_serialization_context::traverse()
{
	unsigned int num_errors = 0;

	debug_point;

	return num_errors;
}

static bool _execute_tag_field_versioning(
	blofeld::s_tag_field_versioning const& versioning,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	bool skip_versioning_field = false;
	skip_count = versioning.version_field_skip_count;

	constexpr tag group_tag = blofeld::ANY_TAG;

	switch (versioning.mode)
	{
	case blofeld::_version_mode_invalid:
		FATAL_ERROR("Invalid version mode");
		break;
	case blofeld::_version_mode_custom:
		ASSERT(versioning.custom_version_callback);
		skip_count = versioning.custom_version_callback(engine_platform_build);
		skip_versioning_field = false;
		break;
	case blofeld::_version_mode_platform_include:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_platform_exclude:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_equal:
		skip_versioning_field = engine_platform_build == versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_not_equal:
		skip_versioning_field = engine_platform_build != versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less:
		skip_versioning_field = engine_platform_build < versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater:
		skip_versioning_field = engine_platform_build > versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less_or_equal:
		skip_versioning_field = engine_platform_build <= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater_or_equal:
		skip_versioning_field = engine_platform_build >= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_tag_group_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag == group_tag;
		break;
	case blofeld::_version_mode_tag_group_not_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag != group_tag;
		break;
	case blofeld::_struct_version_mode_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version == versioning.struct_version;
		break;
	case blofeld::_struct_version_mode_greater_or_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version >= versioning.struct_version;
		break;
	}

	if (skip_versioning_field)
	{
		skip_count = 0;
	}

	return true;
}

static bool _execute_tag_field_versioning(
	c_runtime_tag_field& tag_field,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	if (tag_field.field_type != blofeld::_field_version)
	{
		skip_count = 0;
		return false;
	}

	return _execute_tag_field_versioning(tag_field.versioning, engine_platform_build, struct_version, skip_count);
}

static unsigned int _tag_field_iterator_versioning(c_runtime_tag_field& field, size_t& tag_field_index, s_engine_platform_build engine_platform_build, unsigned int struct_version)
{
	uint32_t _field_skip_count;
	if (_execute_tag_field_versioning(field, engine_platform_build, struct_version, _field_skip_count))
	{
		tag_field_index += _field_skip_count;
		return true;
	}
	return false;
}

unsigned int c_tag_struct_serialization_context::calculate_struct_size(
	c_tag_serialization_context& serialization_context,
	c_runtime_tag_struct_definition& struct_definition,
	std::vector<c_serialization_error*>& serialization_errors)
{
	unsigned int struct_size = 0;


	for(size_t field_index = 0; field_index < struct_definition.fields.size(); field_index++)
	{
		c_runtime_tag_field& field = *struct_definition.fields[field_index];

		c_runtime_tag_field& max_version_field = *struct_definition.fields.front();
		if (field.field_type == blofeld::_field_version && max_version_field.field_type != blofeld::_field_version)
		{
			serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "versioned struct '%' doesn't start with a versioned field. unable to determine max version", field.name.c_str()));
			return 0;
		}

		if (_tag_field_iterator_versioning(field, field_index, serialization_context.engine_platform_build, max_version_field.versioning.struct_version))
		{
			continue;
		}

#define field_size(_field, size) if(_field == field.field_type) { struct_size += (size); continue; }

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
		field_size(blofeld::_field_pad, field.padding);
		field_size(blofeld::_field_useless_pad, field.padding);
		field_size(blofeld::_field_skip, field.length);
		field_size(blofeld::_field_non_cache_runtime_value, 0);
		field_size(blofeld::_field_explanation, 0);
		field_size(blofeld::_field_custom, 0);
		if (field.field_type == blofeld::_field_struct)
		{
			if (c_runtime_tag_struct_definition * struct_definition = field.struct_definition)
			{
				unsigned int field_struct_size = calculate_struct_size(serialization_context, *struct_definition, serialization_errors);
				if (field_struct_size != 0)
				{
					struct_size += field_struct_size;
				}
				else
				{
					serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "field '%s' struct '%' has zero size", field.name.c_str(), struct_definition->name.c_str()));
				}
			}
			else
			{
				serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "field '%s' struct is null", field.name.c_str()));
			}
			continue;
		}
		if (field.field_type == blofeld::_field_array)
		{
			if (c_runtime_tag_array_definition* array_definition = field.array_definition)
			{
				if (c_runtime_tag_struct_definition* struct_definition = array_definition->struct_definition)
				{
					unsigned int field_struct_size = calculate_struct_size(serialization_context, *struct_definition, serialization_errors);
					if (field_struct_size != 0)
					{
						struct_size += field_struct_size;
					}
					else
					{
						serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "field '%s' array struct '%' has zero size", field.name.c_str(), struct_definition->name.c_str()));
					}
				}
				else
				{
					serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "field '%s' array struct is null", field.name.c_str()));
				}
			}
			else
			{
				serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "field '%s' array definition is null", field.name.c_str()));
			}
			continue;
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
		if (field.field_type == blofeld::_field_pointer)
		{
			unsigned int pointer_size = 0;
			ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(serialization_context.engine_platform_build.platform_type, &pointer_size)));
			struct_size += pointer_size;
			continue;
		};
		field_size(blofeld::_field_half, sizeof(word));

		FATAL_ERROR("Unsupported field type");

#undef field_size
	}

	return struct_size;
}
