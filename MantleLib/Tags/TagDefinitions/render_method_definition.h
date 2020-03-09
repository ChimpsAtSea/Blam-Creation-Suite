#pragma once

struct nicename("render_method_definition") group('rmdf') s_render_method_definition_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		struct nicename("Unknown 1") s_unknown_1_definition
		{
			string_id __unknown0;
			TagReference __unknown1;
			string_id __unknown2;
			string_id __unknown3;
		};

		string_id __unknown0;
		s_tag_block_definition<s_unknown_1_definition> nicename("Unknown 1") unknown_1_block;
		string_id __unknown1;
		string_id __unknown2;
	};

	struct nicename("Unknown 1") s_unknown_11_definition
	{
		struct nicename("Unknown 2") s_unknown_2_definition
		{
			struct nicename("Unknown 3") s_unknown_3_definition
			{
				Undefined32 __unknown0;
			};

			struct nicename("Unknown 4") s_unknown_4_definition
			{
				Undefined32 __unknown0;
			};

			Undefined32 __unknown0;
			s_tag_block_definition<s_unknown_3_definition> nicename("Unknown 3") unknown_3_block;
			s_tag_block_definition<s_unknown_4_definition> nicename("Unknown 4") unknown_4_block;
		};

		Undefined32 __unknown0;
		s_tag_block_definition<s_unknown_2_definition> nicename("Unknown 2") unknown_2_block;
	};

	struct nicename("Unknown 2") s_unknown_21_definition
	{
		Undefined32 __unknown0;
	};

	TagReference __unknown0;
	s_tag_block_definition<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	s_tag_block_definition<s_unknown_11_definition> nicename("Unknown 1") unknown_1_block;
	s_tag_block_definition<s_unknown_21_definition> nicename("Unknown 2") unknown_2_block;
	TagReference __unknown1;
	TagReference __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	char nicename("Name") name[256];
};

