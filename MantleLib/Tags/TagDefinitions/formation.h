#pragma once

struct nicename("formation") group('form') s_formation_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		struct nicename("Unknown") s_unknown1_definition
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
		s_tag_block_definition<s_unknown1_definition> __unknown8;
	};

	string_id nicename("Name") name;
	s_tag_block_definition<s_unknown_definition> __unknown0;
};

