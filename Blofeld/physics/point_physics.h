#pragma once

namespace blofeld
{

	constexpr unsigned long POINT_PHYSICS_TAG = 'pphy';

	extern s_tag_group point_physics_group;

	extern s_tag_block_definition point_physics_block_block;

	extern s_tag_struct_definition point_physics_struct_definition_struct_definition; // tag group

	extern const char* point_physics_definition_flags_strings[];
	extern s_string_list_definition point_physics_definition_flags;

	extern s_tag_reference_definition global_point_physics_reference;

} // namespace blofeld

