#pragma once

namespace blofeld
{



	constexpr unsigned long SIMULATION_INTERPOLATION_TAG = 'siin';
	extern s_tag_group simulation_interpolation_group; // simulation_interpolation_block


	extern s_tag_block_definition simulation_interpolation_block;

	extern s_tag_struct_definition simulation_interpolation_struct_definition; // tag group
	extern s_tag_struct_definition single_domain_configuration_struct;
	extern s_tag_struct_definition single_domain_velocity_bumps_configuration_struct;
	extern s_tag_struct_definition single_domain_blending_configuration_struct;

	extern s_tag_reference_definition global_simulation_interpolation_reference;



} // namespace blofeld

