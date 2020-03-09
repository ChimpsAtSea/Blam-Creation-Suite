#pragma once

struct nicename("game_medal_globals") group('gmeg') s_game_medal_globals_definition
{
	struct nicename("Medals") s_medals_definition
	{
		string_id nicename("Name") name;
		string_id nicename("Description") description;
		float nicename("X Scale") x_scale;
		float nicename("Y Scale") y_scale;
		int8_t nicename("Icon") icon;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int32_t __unknown3;
	};

	s_tag_block_definition<s_medals_definition> nicename("Medals") medals_block;
};

