#pragma once

struct nicename("compute_shader") group('cmps') s_compute_shader_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		Undefined32 __unknown0;
	};

	struct nicename("Unknown") s_unknown1_definition
	{
		struct nicename("Unknown") s_unknown2_definition
		{
			string_id __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			string_id __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		Undefined32 nicename("Compute Shaders") compute_shaders;
		DataReference __unknown0;
		DataReference __unknown1;
		DataReference __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		s_tag_block_definition<s_unknown2_definition> __unknown9;
		int32_t __unknown10;
		Undefined32 __unknown11;
		int32_t __unknown12;
		s_tag_block_definition<s_unknown3_definition> __unknown13;
		int32_t __unknown14;
		Undefined32 __unknown15;
		int32_t __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
	};

	s_tag_block_definition<s_unknown_definition> __unknown0;
	Undefined32 __unknown1;
	s_tag_block_definition<s_unknown1_definition> __unknown2;
};

