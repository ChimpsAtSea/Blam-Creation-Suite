#pragma once

struct nicename("ai_mission_dialogue") tag_group('mdlg') s_ai_mission_dialogue_definition
{
	struct nicename("Lines") s_lines_definition
	{
		struct nicename("Variants") s_variants_definition
		{
			DEPRECATED_string_id nicename("Variant Designation") variant_designation;
			TagReference nicename("Sound") sound_reference;
			DEPRECATED_string_id nicename("Sound Effect") sound_effect;
		};

		DEPRECATED_string_id nicename("Name") name;
		s_tag_block_definition<s_variants_definition> nicename("Variants") variants_block;
		DEPRECATED_string_id nicename("Default Sound Effect") default_sound_effect;
	};

	s_tag_block_definition<s_lines_definition> nicename("Lines") lines_block;
};

