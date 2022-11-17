#include "tagframework-private-pch.h"

static h_high_level_function_table* base_configuration_vtable[blofeld::k_number_of_blofeld_field_types] =
{
	nullptr, // _field_string,
	nullptr, // _field_long_string,
	nullptr, // _field_string_id,
	nullptr, // _field_old_string_id,
	nullptr, // _field_char_integer,
	nullptr, // _field_short_integer,
	nullptr, // _field_long_integer,
	nullptr, // _field_int64_integer,
	nullptr, // _field_angle,
	nullptr, // _field_tag,
	nullptr, // _field_char_enum,
	nullptr, // _field_short_enum,
	nullptr, // _field_long_enum,
	nullptr, // _field_long_flags,
	nullptr, // _field_word_flags,
	nullptr, // _field_byte_flags,
	nullptr, // _field_point_2d,
	nullptr, // _field_rectangle_2d,
	nullptr, // _field_rgb_color,
	nullptr, // _field_argb_color,
	nullptr, // _field_real,
	nullptr, // _field_real_slider,
	nullptr, // _field_real_fraction,
	nullptr, // _field_real_point_2d,
	nullptr, // _field_real_point_3d,
	nullptr, // _field_real_vector_2d,
	nullptr, // _field_real_vector_3d,
	nullptr, // _field_real_quaternion,
	nullptr, // _field_real_euler_angles_2d,
	nullptr, // _field_real_euler_angles_3d,
	nullptr, // _field_real_plane_2d,
	nullptr, // _field_real_plane_3d,
	nullptr, // _field_real_rgb_color,
	nullptr, // _field_real_argb_color,
	nullptr, // _field_real_hsv_color,
	nullptr, // _field_real_ahsv_color,
	nullptr, // _field_short_integer_bounds,
	nullptr, // _field_angle_bounds,
	nullptr, // _field_real_bounds,
	nullptr, // _field_real_fraction_bounds,
	nullptr, // _field_tag_reference,
	nullptr, // _field_block,
	nullptr, // _field_long_block_flags,
	nullptr, // _field_word_block_flags,
	nullptr, // _field_byte_block_flags,
	nullptr, // _field_char_block_index,
	nullptr, // _field_char_block_index_custom_search,
	nullptr, // _field_short_block_index,
	nullptr, // _field_short_block_index_custom_search,
	nullptr, // _field_long_block_index,
	nullptr, // _field_long_block_index_custom_search,
	nullptr, // _field_data,
	nullptr, // _field_vertex_buffer,
	nullptr, // _field_pad,
	nullptr, // _field_useless_pad,
	nullptr, // _field_skip,
	nullptr, // _field_non_cache_runtime_value,
	nullptr, // _field_explanation,
	nullptr, // _field_custom,
	nullptr, // _field_struct,
	nullptr, // _field_array,
	nullptr, // _field_pageable_resource,
	nullptr, // _field_api_interop,
	nullptr, // _field_terminator,
	nullptr, // _field_byte_integer,
	nullptr, // _field_word_integer,
	nullptr, // _field_dword_integer,
	nullptr, // _field_qword_integer,
	nullptr, // _field_data_path,
	nullptr, // _field_embedded_tag,
	nullptr, // _field_pointer,
	nullptr, // _field_half,
};

h_high_level_function_table** global_vtables[0x100] =
{
	base_configuration_vtable
};

static s_engine_platform_build global_vtable_engine_platform_build[0x100] =
{
	{ _engine_type_not_set, _platform_type_not_set, _build_not_set }
};

h_prototype* (*global_create_high_level_object[0x100])(const blofeld::s_tag_struct_definition& tag_struct_definition);

BCS_RESULT high_level_registry_init()
{
	return BCS_S_OK;
}

BCS_RESULT high_level_registry_deinit()
{
	return BCS_S_OK;
}

BCS_RESULT high_level_registry_register_global_vtable(
	unsigned int global_vftable_index,
	s_engine_platform_build engine_platform_build,
	h_high_level_function_table** global_vtable,
	h_prototype* (*create_high_level_object)(const blofeld::s_tag_struct_definition& tag_struct_definition))
{
	if (global_vftable_index == 0)
	{
		// index 0 is reserved for the base table
		return BCS_E_INVALID_ARGUMENT;
	}

	if (global_vtables[global_vftable_index])
	{
		// index already contains data
		return BCS_E_FAIL;
	}

	global_vtables[global_vftable_index] = global_vtable;
	global_vtable_engine_platform_build[global_vftable_index] = engine_platform_build;
	global_create_high_level_object[global_vftable_index] = create_high_level_object;

	return BCS_S_OK;
}

BCS_RESULT high_level_registry_unregister_global_vtable(
	unsigned int global_vftable_index,
	s_engine_platform_build engine_platform_build)
{
	if (global_vftable_index == 0)
	{
		// index 0 is reserved for the base table
		return BCS_E_INVALID_ARGUMENT;
	}

	if (global_vtables[global_vftable_index] = nullptr)
	{
		// index is missing data
		return BCS_E_FAIL;
	}

	// #TODO: Implement a global reference counter and make sure that all objects are destroyed before removing the vtable entry

	global_vtables[global_vftable_index] = nullptr;

	return BCS_S_OK;
}

BCS_RESULT high_level_registry_create_high_level_object(
	unsigned int global_vtables_index,
	unsigned int local_vtables_index,
	h_prototype*& prototype,
	h_extended_type* parent)
{
	if (h_high_level_function_table** global_vtable = global_vtables[global_vtables_index])
	{
		if (h_high_level_function_table* local_vtable = global_vtable[local_vtables_index])
		{
			if (local_vtable->high_level_vtable_type == _high_level_vtable_prototype)
			{
				h_prototype::h_prototype_function_table& function_table = *static_cast<h_prototype::h_prototype_function_table*>(local_vtable);

				prototype = function_table.prototype_constructor(parent);

				return BCS_S_OK;
			}
		}
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT high_level_registry_create_high_level_object(
	s_engine_platform_build engine_platform_build,
	const blofeld::s_tag_struct_definition& tag_struct_definition,
	h_prototype*& prototype)
{
	for (unsigned int global_vtables_index = 0; global_vtables_index < _countof(global_vtables); global_vtables_index++)
	{
		if (global_vtables[global_vtables_index] && global_vtable_engine_platform_build[global_vtables_index] == engine_platform_build)
		{
			prototype = global_create_high_level_object[global_vtables_index](tag_struct_definition);
			if (prototype == nullptr)
			{
				return BCS_E_NOT_FOUND;
			}
			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}
