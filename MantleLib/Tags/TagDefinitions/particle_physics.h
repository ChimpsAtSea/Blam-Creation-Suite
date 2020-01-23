#pragma once

struct nicename("Particle Physics") group('pmov') s_particle_physics_definition
{
	struct nicename("Movements") s_movement_block_definition;

	TagReference nicename("Template") template_reference; 
	signed int nicename("Flags") flags; 
	s_tag_block_definition<s_movement_block_definition> nicename("Movements") movements_block; 
	TagReference __unknown_reference; 

	struct nicename("movement") s_movement_block_definition
	{
		struct nicename("Parameters") s_parameter_block_definition;

		signed short nicename("Type") type; 
		signed char __unknown; 
		signed char __unknown2; 
		s_tag_block_definition<s_parameter_block_definition> nicename("Parameters") parameters_block; 
		signed short __unknown3; 
		signed short __unknown4; 
		signed int __unknown5; 

		struct nicename("parameter") s_parameter_block_definition
		{
			signed int nicename("Parameter ID") parameter_id; 
			signed short __unknown; 
			signed short __unknown2; 
			DataReference nicename("Function") function_data_reference; 
			float __unknown3; 
			unsigned char __unknown4; 
			signed char __unknown5; 
			signed char __unknown6; 
			signed char __unknown7; 
		};
	};
};
