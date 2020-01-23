#pragma once

struct nicename("Achievements") group('achi') s_achievements_definition
{
	struct nicename("Achievement Information") s_achievement_information_block_definition;

	s_tag_block_definition<s_achievement_information_block_definition> nicename("Achievement Information") achievement_information_block; 

	struct nicename("achievement_information") s_achievement_information_block_definition
	{
		struct nicename("Achievement Unlock Information") s_achievement_unlock_information_block_definition;

		string_id nicename("Achievement Name") achievement_name; 
		int8_t nicename("Achievement Index") achievement_index; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		s_tag_block_definition<s_achievement_unlock_information_block_definition> nicename("Achievement Unlock Information") achievement_unlock_information_block; 

		struct nicename("achievement_unlock_information") s_achievement_unlock_information_block_definition
		{
			string_id nicename("Unlock Limitation") unlock_limitation; 
		};
	};
};
