#pragma once

struct s_vertex_shader_definition
{
	struct s_unknown_0_block_definition;
	struct s_vertex_shader2_block_definition;

	unsigned int unknown;
	s_tag_block_definition<s_unknown_0_block_definition> unknown_0_2;
	unsigned int unknown2;
	s_tag_block_definition<s_vertex_shader2_block_definition> vertex_shaders;

	struct s_unknown_0_definition
	{
		struct s_unknown_1_block_definition;

		s_tag_block_definition<s_unknown_1_block_definition> unknown_1_2;

		struct s_unknown_1_definition
		{
			signed short unknown;
		};
	};

	struct s_vertex_shader_definition
	{
		struct s_unknown11_block_definition;
		struct s_unknown16_block_definition;

		unsigned int unknown;
		DataReference unknown2;
		DataReference unknown3;
		DataReference unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		s_tag_block_definition<s_unknown11_block_definition> unknown12;
		signed int unknown13;
		unsigned int unknown14;
		signed int unknown15;
		s_tag_block_definition<s_unknown16_block_definition> unknown17;
		signed int unknown18;
		unsigned int unknown19;
		signed int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;

		struct s_unknown_definition
		{
			string_id unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			signed char unknown6;
		};

		struct s_unknown_definition
		{
			string_id unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			signed char unknown6;
		};
	};
};
