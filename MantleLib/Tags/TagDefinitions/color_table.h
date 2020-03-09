#pragma once

struct nicename("color_table") group('colo') s_color_table_definition
{
	struct nicename("Color Table") s_color_table1_definition
	{
		char nicename("String") string[32];
		colorf nicename("Color") color;
	};

	s_tag_block_definition<s_color_table1_definition> nicename("Color Table") color_table_block;
};

