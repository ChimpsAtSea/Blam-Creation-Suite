#pragma once

struct nicename("player_grade_globals_definition") tag_group('pggd') s_player_grade_globals_definition_definition_legacy
{
	struct nicename("Ranks") s_ranks_definition_legacy
	{
		struct nicename("Grades") s_grades_definition_legacy
		{
			uint32_t nicename("Credits Required") credits_required;
			string_id_legacy nicename("Name") name;
			int16_t nicename("Icon Entry") icon_entry;
			int16_t __unknown0;
		};

		s_tag_block_legacy<s_grades_definition_legacy> nicename("Grades") grades_block;
	};

	s_tag_block_legacy<s_ranks_definition_legacy> nicename("Ranks") ranks_block;
};

