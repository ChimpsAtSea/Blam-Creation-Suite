#pragma once

namespace blofeld
{

	constexpr unsigned long COLLISION_DAMAGE_TAG = 'cddf';

	extern s_tag_group collision_damage_group;

	extern s_tag_block_definition collision_damage_block_block;

	extern s_tag_struct_definition collision_damage_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition collision_damage_function_struct_definition;

	extern c_versioned_string_list collisionDamageFlags_strings;
	extern s_string_list_definition collisionDamageFlags;


} // namespace blofeld

