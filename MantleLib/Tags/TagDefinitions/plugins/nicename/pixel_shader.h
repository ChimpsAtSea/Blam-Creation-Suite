#pragma once

nicename("pixel_shader") struct s_pixel_shader_definition
{
	nicename("Unknown 0") struct s_unknown_0_block_definition;
	nicename("Pixel Shaders") struct s_pixel_shader2_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Unknown 0") s_tag_block_definition<s_unknown_0_block_definition> unknown_0_2;
	nicename("Unknown") unsigned int unknown2;
	nicename("Pixel Shaders") s_tag_block_definition<s_pixel_shader2_block_definition> pixel_shaders;

	nicename("Unknown 0") struct s_unknown_0_definition
	{
		nicename("Unknown") signed short unknown;
	};

	nicename("Pixel Shader") struct s_pixel_shader_definition
	{
		nicename("Unknown") struct s_unknown11_block_definition;
		nicename("Unknown") struct s_unknown16_block_definition;

		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") DataReference unknown2;
		nicename("Unknown") DataReference unknown3;
		nicename("Unknown") DataReference unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;
		nicename("Unknown") signed int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") signed int unknown15;
		nicename("Unknown") s_tag_block_definition<s_unknown16_block_definition> unknown17;
		nicename("Unknown") signed int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") signed int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") string_id unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") signed char unknown6;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") string_id unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") signed char unknown6;
		};
	};
};
