#pragma once

struct nicename("compute_shader") tag_group('cmps') s_compute_shader_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		s_undefined32_legacy __unknown0;
	};

	struct nicename("Unknown") s_unknown1_definition
	{
		struct nicename("Unknown") s_unknown2_definition
		{
			string_id_legacy __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			string_id_legacy __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		s_undefined32_legacy nicename("Compute Shaders") compute_shaders;
		s_data_reference_legacy __unknown0;
		s_data_reference_legacy __unknown1;
		s_data_reference_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_tag_block_legacy<s_unknown2_definition> __unknown9;
		int32_t __unknown10;
		s_undefined32_legacy __unknown11;
		int32_t __unknown12;
		s_tag_block_legacy<s_unknown3_definition> __unknown13;
		int32_t __unknown14;
		s_undefined32_legacy __unknown15;
		int32_t __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
	};

	s_tag_block_legacy<s_unknown_definition> __unknown0;
	s_undefined32_legacy __unknown1;
	s_tag_block_legacy<s_unknown1_definition> __unknown2;
};

