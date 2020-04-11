#pragma once

struct nicename("formation") tag_group('form') s_formation_definition_legacy
{
	struct nicename("Unknown") s_unknown_definition_legacy
	{
		struct nicename("Unknown") s_unknown1_definition_legacy
		{
			float __unknown0;
			float __unknown1;
		};

		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		s_tag_block_legacy<s_unknown1_definition_legacy> __unknown8;
	};

	string_id_legacy nicename("Name") name;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown0;
};

