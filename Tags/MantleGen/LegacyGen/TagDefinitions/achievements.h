#pragma once

struct nicename("achievements") tag_group('achi') s_achievements_definition_legacy
{
	struct nicename("Achievement Information") s_achievement_information_definition_legacy
	{
		struct nicename("Achievement Unlock Information") s_achievement_unlock_information_definition_legacy
		{
			string_id_legacy nicename("Unlock Limitation") unlock_limitation;
		};

		string_id_legacy nicename("Achievement Name") achievement_name;
		int8_t nicename("Achievement Index") achievement_index;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		s_tag_block_legacy<s_achievement_unlock_information_definition_legacy> nicename("Achievement Unlock Information") achievement_unlock_information_block;
	};

	s_tag_block_legacy<s_achievement_information_definition_legacy> nicename("Achievement Information") achievement_information_block;
};

