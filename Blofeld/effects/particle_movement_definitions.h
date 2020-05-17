#pragma once

namespace blofeld
{

	extern const char* particle_movement_flags_strings[];
	extern s_string_list_definition particle_movement_flags;
	extern const char* particle_movement_type_strings[];
	extern s_string_list_definition particle_movement_type;
	extern const char* particle_controller_flags_strings[];
	extern s_string_list_definition particle_controller_flags;

	constexpr unsigned long PARTICLE_PHYSICS_TAG = 'pmov';

	extern s_tag_group particle_physics_group;

	extern s_tag_block_definition particle_physics_block_block;
	extern s_tag_struct particle_controller_block_struct;
	extern s_tag_block_definition particle_controller_block;
	extern s_tag_struct particle_controller_parameters_block_struct;
	extern s_tag_block_definition particle_controller_parameters_block;

	extern s_tag_struct particle_physics_struct_definition_struct_definition; // tag group
	extern s_tag_struct particle_physics_struct_struct_definition;

} // namespace blofeld

