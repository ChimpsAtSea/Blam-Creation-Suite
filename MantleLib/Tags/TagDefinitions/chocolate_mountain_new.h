#pragma once

struct nicename("Chocolate Mountain New") group('chmt') s_chocolate_mountain_new_definition
{
	struct nicename("Lighting Variables") s_lighting_variable_block_definition;

	// comment
	int8_t __unknown; 
	int8_t __unknown2; 
	int8_t __unknown3; 
	int8_t __unknown4; 
	s_tag_block_definition<s_lighting_variable_block_definition> nicename("Lighting Variables") lighting_variables_block; 

	struct nicename("lighting_variable") s_lighting_variable_block_definition
	{
		float nicename("Lightmap Brightness Offset") lightmap_brightness_offset; 
		float nicename("Lightmap Darkness Offset") lightmap_darkness_offset; 
		float __unknown; 
		float nicename("Dynamic Lightmap Brightness Offset") dynamic_lightmap_brightness_offset; 
		float nicename("Dynamic Lightmap Darkness Offset") dynamic_lightmap_darkness_offset; 
	};
};
