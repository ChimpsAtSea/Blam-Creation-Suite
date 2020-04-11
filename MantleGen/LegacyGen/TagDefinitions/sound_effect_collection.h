#pragma once

struct nicename("sound_effect_collection") tag_group('sfx+') s_sound_effect_collection_definition_legacy
{
	struct nicename("Sound Effects") s_sound_effects_definition_legacy
	{
		struct nicename("Unknown 1") s_unknown_1_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
		};

		struct nicename("Components") s_components_definition_legacy
		{
			s_tag_reference_legacy nicename("Sound") sound_reference;
			s_undefined32_legacy nicename("Gain") gain;
			int32_t nicename("Flags") flags;
		};

		string_id_legacy nicename("Name") name;
		int32_t __unknown0;
		s_tag_reference_legacy nicename("Radio Settings") radio_settings_reference;
		s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
		s_tag_block_legacy<s_components_definition_legacy> nicename("Components") components_block;
	};

	s_tag_block_legacy<s_sound_effects_definition_legacy> nicename("Sound Effects") sound_effects_block;
};

