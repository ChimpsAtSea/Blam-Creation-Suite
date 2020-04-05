#pragma once

struct nicename("player_grade_globals_definition") tag_group('pggd') s_player_grade_globals_definition_definition
{
	struct nicename("Ranks") s_ranks_definition
	{
		struct nicename("Grades") s_grades_definition
		{
			uint32_t nicename("Credits Required") credits_required;
			string_id nicename("Name") name;
			int16_t nicename("Icon Entry") icon_entry;
			int16_t __unknown0;
		};

		s_tag_block_definition<s_grades_definition> nicename("Grades") grades_block;
	};

	s_tag_block_definition<s_ranks_definition> nicename("Ranks") ranks_block;
};

