#pragma once

struct nicename("ai_mission_dialogue") tag_group('mdlg') s_ai_mission_dialogue_definition_legacy
{
	struct nicename("Lines") s_lines_definition_legacy
	{
		struct nicename("Variants") s_variants_definition_legacy
		{
			string_id_legacy nicename("Variant Designation") variant_designation;
			s_tag_reference_legacy nicename("Sound") sound_reference;
			string_id_legacy nicename("Sound Effect") sound_effect;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_variants_definition_legacy> nicename("Variants") variants_block;
		string_id_legacy nicename("Default Sound Effect") default_sound_effect;
	};

	s_tag_block_legacy<s_lines_definition_legacy> nicename("Lines") lines_block;
};

