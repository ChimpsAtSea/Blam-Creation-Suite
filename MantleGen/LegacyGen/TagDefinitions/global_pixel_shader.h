#pragma once

struct nicename("global_pixel_shader") tag_group('glps') s_global_pixel_shader_definition_legacy
{
	struct nicename("Unknown") s_unknown_definition_legacy
	{
		struct nicename("Unknown") s_unknown1_definition_legacy
		{
			struct nicename("Unknown") s_unknown2_definition_legacy
			{
				uint32_t __unknown0;
			};

			uint32_t __unknown0;
			s_tag_block_legacy<s_unknown2_definition_legacy> __unknown1;
		};

		s_tag_block_legacy<s_unknown1_definition_legacy> __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Pixel Shaders") s_pixel_shaders_definition_legacy
	{
		struct nicename("Unknown") s_unknown3_definition_legacy
		{
			string_id_legacy __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		struct nicename("Unknown") s_unknown4_definition_legacy
		{
			string_id_legacy __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		s_undefined32_legacy __unknown0;
		s_data_reference_legacy __unknown1;
		s_data_reference_legacy __unknown2;
		s_data_reference_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_tag_block_legacy<s_unknown3_definition_legacy> __unknown10;
		int32_t __unknown11;
		s_undefined32_legacy __unknown12;
		int32_t __unknown13;
		s_tag_block_legacy<s_unknown4_definition_legacy> __unknown14;
		int32_t __unknown15;
		s_undefined32_legacy __unknown16;
		int32_t __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
	};

	s_tag_block_legacy<s_unknown_definition_legacy> __unknown0;
	s_undefined32_legacy __unknown1;
	s_tag_block_legacy<s_pixel_shaders_definition_legacy> nicename("Pixel Shaders") pixel_shaders_block;
};

