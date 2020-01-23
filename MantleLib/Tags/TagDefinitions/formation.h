#pragma once

struct nicename("Formation") group('form') s_formation_definition
{
	struct s_unknown_block_definition;

	string_id nicename("Name") name; 
	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

	struct s_unknown_block_definition
	{
		struct s_unknown2_block_definition;

		int16_t __unknown; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown9_block; 

		struct s_unknown2_block_definition
		{
			float __unknown; 
			float __unknown2; 
		};
	};
};
