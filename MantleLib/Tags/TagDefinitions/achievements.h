#pragma once

struct nicename("Achievements") group('achi') s_achievements_definition
{
	struct nicename("Achievement Information") s_achievement_information_block_definition;

	s_tag_block_definition<s_achievement_information_block_definition> nicename("Achievement Information") achievement_information_block; 

	struct nicename("achievement_information") s_achievement_information_block_definition
	{
		struct nicename("Achievement Unlock Information") s_achievement_unlock_information_block_definition;

		string_id nicename("Achievement Name") achievement_name; 
		signed char nicename("Achievement Index") achievement_index; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		s_tag_block_definition<s_achievement_unlock_information_block_definition> nicename("Achievement Unlock Information") achievement_unlock_information_block; 

		struct nicename("achievement_unlock_information") s_achievement_unlock_information_block_definition
		{
			string_id nicename("Unlock Limitation") unlock_limitation; 
		};
	};
};
