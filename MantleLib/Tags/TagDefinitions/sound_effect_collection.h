#pragma once

struct nicename("sound_effect_collection") tag_group('sfx+') s_sound_effect_collection_definition
{
	struct nicename("Sound Effects") s_sound_effects_definition
	{
		struct nicename("Unknown 1") s_unknown_1_definition
		{
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
		};

		struct nicename("Components") s_components_definition
		{
			TagReference nicename("Sound") sound_reference;
			Undefined32 nicename("Gain") gain;
			int32_t nicename("Flags") flags;
		};

		string_id nicename("Name") name;
		int32_t __unknown0;
		TagReference nicename("Radio Settings") radio_settings_reference;
		s_tag_block_definition<s_unknown_1_definition> nicename("Unknown 1") unknown_1_block;
		s_tag_block_definition<s_components_definition> nicename("Components") components_block;
	};

	s_tag_block_definition<s_sound_effects_definition> nicename("Sound Effects") sound_effects_block;
};

