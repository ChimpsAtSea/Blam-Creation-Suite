#pragma once

struct nicename("achievements") tag_group('achi') s_achievements_definition
{
	struct nicename("Achievement Information") s_achievement_information_definition
	{
		struct nicename("Achievement Unlock Information") s_achievement_unlock_information_definition
		{
			string_id nicename("Unlock Limitation") unlock_limitation;
		};

		string_id nicename("Achievement Name") achievement_name;
		int8_t nicename("Achievement Index") achievement_index;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		s_tag_block_definition<s_achievement_unlock_information_definition> nicename("Achievement Unlock Information") achievement_unlock_information_block;
	};

	s_tag_block_definition<s_achievement_information_definition> nicename("Achievement Information") achievement_information_block;
};

