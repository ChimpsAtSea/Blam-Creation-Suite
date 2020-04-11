#pragma once

struct nicename("render_method_definition") tag_group('rmdf') s_render_method_definition_definition_legacy
{
	struct nicename("Unknown 0") s_unknown_0_definition_legacy
	{
		struct nicename("Unknown 1") s_unknown_1_definition_legacy
		{
			string_id_legacy __unknown0;
			s_tag_reference_legacy __unknown1;
			string_id_legacy __unknown2;
			string_id_legacy __unknown3;
		};

		string_id_legacy __unknown0;
		s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
		string_id_legacy __unknown1;
		string_id_legacy __unknown2;
	};

	struct nicename("Unknown 1") s_unknown_11_definition_legacy
	{
		struct nicename("Unknown 2") s_unknown_2_definition_legacy
		{
			struct nicename("Unknown 3") s_unknown_3_definition_legacy
			{
				s_undefined32_legacy __unknown0;
			};

			struct nicename("Unknown 4") s_unknown_4_definition_legacy
			{
				s_undefined32_legacy __unknown0;
			};

			s_undefined32_legacy __unknown0;
			s_tag_block_legacy<s_unknown_3_definition_legacy> nicename("Unknown 3") unknown_3_block;
			s_tag_block_legacy<s_unknown_4_definition_legacy> nicename("Unknown 4") unknown_4_block;
		};

		s_undefined32_legacy __unknown0;
		s_tag_block_legacy<s_unknown_2_definition_legacy> nicename("Unknown 2") unknown_2_block;
	};

	struct nicename("Unknown 2") s_unknown_21_definition_legacy
	{
		s_undefined32_legacy __unknown0;
	};

	s_tag_reference_legacy __unknown0;
	s_tag_block_legacy<s_unknown_0_definition_legacy> nicename("Unknown 0") unknown_0_block;
	s_tag_block_legacy<s_unknown_11_definition_legacy> nicename("Unknown 1") unknown_1_block;
	s_tag_block_legacy<s_unknown_21_definition_legacy> nicename("Unknown 2") unknown_2_block;
	s_tag_reference_legacy __unknown1;
	s_tag_reference_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	char nicename("Name") name[256];
};

