#pragma once

nicename("shader_screen") struct s_shader_screen_definition
{
	nicename("Unknown") struct s_unknown2_block_definition;
	nicename("Shader Properties") struct s_shader_property_block_definition;
	nicename("Unknown") struct s_unknown9_block_definition;

	nicename("Base Render Method") TagReference base_render_method;
	nicename("Unknown") TagReference unknown;
	nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Shader Properties") s_tag_block_definition<s_shader_property_block_definition> shader_properties;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") s_tag_block_definition<s_unknown9_block_definition> unknown10;
	nicename("Unknown") signed char unknown11;
	nicename("Unknown") signed char unknown12;
	nicename("Unknown") signed char unknown13;
	nicename("Unknown") signed char unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") signed int unknown16;
	nicename("Unknown") signed int unknown17;
	nicename("Unknown") signed short unknown18;
	nicename("Unknown") signed short unknown19;

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") signed short unknown2;
	};

	nicename("Shader Property") struct s_shader_property_definition
	{
		nicename("Shader Maps") struct s_shader_map_block_definition;
		nicename("Arguments") struct s_argument_block_definition;
		nicename("Unknown") struct s_unknown_block_definition;
		nicename("Unknown") struct s_unknown4_block_definition;
		nicename("Unknown") struct s_unknown6_block_definition;
		nicename("Unknown") struct s_unknown8_block_definition;
		nicename("Functions") struct s_function_block_definition;

		nicename("Template") TagReference template;
		nicename("Shader Maps") s_tag_block_definition<s_shader_map_block_definition> shader_maps;
		nicename("Arguments") s_tag_block_definition<s_argument_block_definition> arguments;
		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;
		nicename("Unknown") s_tag_block_definition<s_unknown6_block_definition> unknown7;
		nicename("Unknown") s_tag_block_definition<s_unknown8_block_definition> unknown9;
		nicename("Functions") s_tag_block_definition<s_function_block_definition> functions;
		nicename("Unknown") signed int unknown10;
		nicename("Unknown") signed int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") signed short unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Unknown") signed short unknown15;
		nicename("Unknown") signed short unknown16;
		nicename("Unknown") signed short unknown17;
		nicename("Unknown") signed short unknown18;
		nicename("Unknown") signed short unknown19;
		nicename("Unknown") signed short unknown20;
		nicename("Unknown") signed short unknown21;
		nicename("Unknown") signed short unknown22;
		nicename("Unknown") signed short unknown23;
		nicename("Unknown") signed short unknown24;
		nicename("Unknown") signed short unknown25;
		nicename("Unknown") signed short unknown26;
		nicename("Unknown") signed short unknown27;
		nicename("Unknown") signed short unknown28;
		nicename("Unknown") signed short unknown29;
		nicename("Unknown") signed short unknown30;
		nicename("Unknown") signed short unknown31;
		nicename("Unknown") signed short unknown32;
		nicename("Unknown") signed short unknown33;
		nicename("Unknown") signed short unknown34;
		nicename("Unknown") signed short unknown35;
		nicename("Unknown") signed short unknown36;
		nicename("Unknown") signed short unknown37;
		nicename("Unknown") signed short unknown38;
		nicename("Unknown") signed short unknown39;
		nicename("Unknown") signed short unknown40;
		nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
		nicename("[easy read] Index") unsigned short easy_read_index;
		nicename("[easy read] Salt") unsigned short easy_read_salt;
		nicename("Useless Padding") signed int useless_padding;

		nicename("Shader Map") struct s_shader_map_definition
		{
			nicename("Bitmap") TagReference bitmap;
			nicename("Unknown") signed char unknown;
			nicename("Bitmap Index") signed char bitmap_index;
			nicename("Unknown") signed char unknown2;
			nicename("Bitmap Flags") unsigned char bitmap_flags;
			nicename("Unknown Bitmap Index Enable") signed char unknown_bitmap_index_enable;
			nicename("UV Argument Index") signed char uv_argument_index;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
		};

		nicename("Argument") struct s_argument_definition
		{
			nicename("Arg 1") float arg_1;
			nicename("Arg 2") float arg_2;
			nicename("Arg 3") float arg_3;
			nicename("Arg 4") float arg_4;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed short unknown2;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
		};

		nicename("Function") struct s_function_definition
		{
			nicename("Unknown") signed int unknown;
			nicename("Name") string_id name;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Function") DataReference function2;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") signed int unknown3;
		nicename("Unknown") signed int unknown4;
	};
};
