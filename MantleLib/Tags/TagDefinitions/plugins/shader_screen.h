#pragma once

struct s_shader_screen_definition
{
	struct s_unknown2_block_definition;
	struct s_shader_property_block_definition;
	struct s_unknown9_block_definition;

	TagReference base_render_method;
	TagReference unknown;
	s_tag_block_definition<s_unknown2_block_definition> unknown3;
	unsigned int unknown4;
	unsigned int unknown5;
	unsigned int unknown6;
	s_tag_block_definition<s_shader_property_block_definition> shader_properties;
	unsigned int unknown7;
	unsigned int unknown8;
	s_tag_block_definition<s_unknown9_block_definition> unknown10;
	signed char unknown11;
	signed char unknown12;
	signed char unknown13;
	signed char unknown14;
	unsigned int unknown15;
	signed int unknown16;
	signed int unknown17;
	signed short unknown18;
	signed short unknown19;

	struct s_unknown_definition
	{
		signed short unknown2;
	};

	struct s_shader_property_definition
	{
		struct s_shader_map_block_definition;
		struct s_argument_block_definition;
		struct s_unknown_block_definition;
		struct s_unknown4_block_definition;
		struct s_unknown6_block_definition;
		struct s_unknown8_block_definition;
		struct s_function_block_definition;

		TagReference template;
		s_tag_block_definition<s_shader_map_block_definition> shader_maps;
		s_tag_block_definition<s_argument_block_definition> arguments;
		s_tag_block_definition<s_unknown_block_definition> unknown2;
		unsigned int unknown3;
		s_tag_block_definition<s_unknown4_block_definition> unknown5;
		s_tag_block_definition<s_unknown6_block_definition> unknown7;
		s_tag_block_definition<s_unknown8_block_definition> unknown9;
		s_tag_block_definition<s_function_block_definition> functions;
		signed int unknown10;
		signed int unknown11;
		unsigned int unknown12;
		signed short unknown13;
		signed short unknown14;
		signed short unknown15;
		signed short unknown16;
		signed short unknown17;
		signed short unknown18;
		signed short unknown19;
		signed short unknown20;
		signed short unknown21;
		signed short unknown22;
		signed short unknown23;
		signed short unknown24;
		signed short unknown25;
		signed short unknown26;
		signed short unknown27;
		signed short unknown28;
		signed short unknown29;
		signed short unknown30;
		signed short unknown31;
		signed short unknown32;
		signed short unknown33;
		signed short unknown34;
		signed short unknown35;
		signed short unknown36;
		signed short unknown37;
		signed short unknown38;
		signed short unknown39;
		signed short unknown40;
		unsigned int zone_asset_datum;
		unsigned short easy_read_index;
		unsigned short easy_read_salt;
		signed int useless_padding;

		struct s_shader_map_definition
		{
			TagReference bitmap;
			signed char unknown;
			signed char bitmap_index;
			signed char unknown2;
			unsigned char bitmap_flags;
			signed char unknown_bitmap_index_enable;
			signed char uv_argument_index;
			signed char unknown3;
			signed char unknown4;
		};

		struct s_argument_definition
		{
			float arg_1;
			float arg_2;
			float arg_3;
			float arg_4;
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
		};

		struct s_unknown_definition
		{
			signed short unknown2;
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
			signed char unknown3;
			signed char unknown4;
		};

		struct s_unknown_definition
		{
			signed short unknown2;
			signed short unknown3;
		};

		struct s_function_definition
		{
			signed int unknown;
			string_id name;
			unsigned int unknown2;
			unsigned int unknown3;
			DataReference function2;
		};
	};

	struct s_unknown_definition
	{
		string_id unknown2;
		signed int unknown3;
		signed int unknown4;
	};
};
