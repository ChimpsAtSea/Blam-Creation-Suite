#pragma once

struct nicename("Vertex Shader") group('vtsh') s_vertex_shader_definition
{
	struct s_unknown_0_block_definition;
	struct nicename("Vertex Shaders") s_vertex_shader2_block_definition;

	Undefined32 __unknown; 
	s_tag_block_definition<s_unknown_0_block_definition> __unknown_0_block; 
	Undefined32 __unknown2; 
	s_tag_block_definition<s_vertex_shader2_block_definition> nicename("Vertex Shaders") vertex_shaders_block; 

	struct s_unknown_0_block_definition
	{
		struct s_unknown_1_block_definition;

		s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 

		struct s_unknown_1_block_definition
		{
			int16_t __unknown; 
		};
	};

	struct nicename("vertex_shader2") s_vertex_shader2_block_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;

		Undefined32 __unknown; 
		DataReference __unknown2_data_reference; 
		DataReference __unknown3_data_reference; 
		DataReference __unknown4_data_reference; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 
		int32_t __unknown12; 
		Undefined32 __unknown13; 
		int32_t __unknown14; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown15_block; 
		int32_t __unknown16; 
		Undefined32 __unknown17; 
		int32_t __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 

		struct s_unknown_block_definition
		{
			string_id __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			int8_t __unknown5; 
		};

		struct s_unknown2_block_definition
		{
			string_id __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			int8_t __unknown5; 
		};
	};
};