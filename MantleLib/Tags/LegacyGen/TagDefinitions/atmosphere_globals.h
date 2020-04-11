#pragma once

struct nicename("atmosphere_globals") tag_group('atgf') s_atmosphere_globals_definition
{
	struct nicename("Colors") s_colors_definition
	{
		string_id_legacy nicename("Name") name;
		s_colorf_legacy nicename("Color") color;
	};

	s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	float nicename("Bitmap X") bitmap_x;
	float nicename("Bitmap Y") bitmap_y;
	float nicename("Bitmap Z") bitmap_z;
	float nicename("Black Opacity") black_opacity;
	float nicename("White Opacity") white_opacity;
	s_tag_block_legacy<s_colors_definition> nicename("Colors") colors_block;
};

