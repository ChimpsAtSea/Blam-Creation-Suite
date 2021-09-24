#pragma once

namespace blofeld
{



	constexpr unsigned long PARTICLE_PHYSICS_TAG = 'pmov';
	extern s_tag_group particle_physics_group; // particle_physics_block


	extern s_tag_block_definition particle_physics_block;
	extern s_tag_block_definition particle_controller_block;
	extern s_tag_struct_definition particle_controller_block_struct_definition; // particle_controller_block
	extern s_tag_block_definition particle_controller_parameters_block;
	extern s_tag_struct_definition particle_controller_parameters_block_struct_definition; // particle_controller_parameters_block

	extern s_tag_struct_definition particle_physics_struct_definition; // tag group
	extern s_tag_struct_definition particle_physics_struct;

	extern s_string_list_definition particle_movement_flags;
	extern s_string_list_definition particle_movement_type;
	extern s_string_list_definition particle_controller_flags;

	extern s_tag_reference_definition particle_movement_definition;



} // namespace blofeld

