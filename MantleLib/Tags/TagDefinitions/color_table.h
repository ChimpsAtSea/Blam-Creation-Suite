#pragma once

struct nicename("Color Table") group('colo') s_color_table_definition
{
	struct nicename("Color Table") s_color_table2_block_definition;

	s_tag_block_definition<s_color_table2_block_definition> nicename("Color Table") color_table_block; 

	struct nicename("color_table2") s_color_table2_block_definition
	{
		char nicename("String") string[32];
		float nicename("Color a") color_a; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};
};
