#pragma once

struct nicename("Particle Physics") group('pmov') s_particle_physics_definition
{
	struct nicename("Movements") s_movement_block_definition;

	TagReference nicename("Template") template_reference; 
	int32_t nicename("Flags") flags; 
	s_tag_block_definition<s_movement_block_definition> nicename("Movements") movements_block; 
	TagReference __unknown_reference; 

	struct nicename("movement") s_movement_block_definition
	{
		struct nicename("Parameters") s_parameter_block_definition;

		int16_t nicename("Type") type; 
		int8_t __unknown; 
		int8_t __unknown2; 
		s_tag_block_definition<s_parameter_block_definition> nicename("Parameters") parameters_block; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		int32_t __unknown5; 

		struct nicename("parameter") s_parameter_block_definition
		{
			int32_t nicename("Parameter ID") parameter_id; 
			int16_t __unknown; 
			int16_t __unknown2; 
			DataReference nicename("Function") function_data_reference; 
			float __unknown3; 
			uint8_t __unknown4; 
			int8_t __unknown5; 
			int8_t __unknown6; 
			int8_t __unknown7; 
		};
	};
};
